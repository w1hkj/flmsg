// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flmsg is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flmsg is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include <config.h>

#include <sys/time.h>

#include <iostream>
#include <sstream>
#include <cmath>

#include "arq.h"
#include "status.h"
#include "xml_io.h"
#include "flmsg_arq.h"
#include "gettext.h"

static pthread_t arq_thread;
static pthread_mutex_t arq_mutex = PTHREAD_MUTEX_INITIALIZER;
static arq *inst = NULL;

static bool first_rtry = true;

std::string arqstates[] = {
	"ARQ_DOWN", "TIMEDOUT", "ABORT", "ARQ_CONNECTING", "ARQ_CONNECTED",
	"WAITING", "WAITFORACK", "ARQ_DISCONNECT", "ARQ_DISCONNECTING",
	"ABORTING", "STOPPED"};

std::string arq::upcase(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
	return s;
}

arq::arq()
{
	do_sendfnc = NULL;
	do_getc1 = NULL;
	do_rcvfnc = NULL;
	do_printRX = NULL;
	do_printTX = NULL;
	do_printLOG = NULL;
	do_printTALK = NULL;
	do_abortfnc = NULL;
	do_disconnectfnc = NULL;
	do_rxUrCall = NULL;
	do_qualityfnc = NULL;
	do_printSTATUS = NULL;

	UrCall.erase();
	MyCall.erase();

// queues //
	TxTextQueue.clear();
	RxTextQueue.clear();

	exponent = EXPONENT;

// static status

	LinkState = ARQ_DOWN;				// ARQ link is initially down
	sender = false;

	retries = getRetries();

	loopcount = 0;
	xfrsize = 0;
	str_xfrsize = "";
	lastblock = ' ';
	timeout = -1;
	retrytime = rtry();

	arq_running = false;
	arq_exit    = false;
	arqreset   = false;

}

void arq::resetTx()
{
	TxTextQueue.clear();
}

void arq::resetRx()
{
	RxTextQueue.clear();
}

void arq::reset()
{
	resetTx();
	resetRx();
	blknbr = 0;
	timeout = -1;
	LinkState = ARQ_DOWN;
	sender = false;
	disconnectfnc();
	str_blknbr = "000";
	retrytime = rtry();
}

// Checksum of std::string s
std::string arq::checksum(std::string &s)
{
	framecrc.reset();
	return framecrc.scrc16(s);
}

void arq::addToTxQue(std::string s)
{
	if (s.empty()) return;
	TxTextQueue.assign(s);
}

std::string arq::calls()
{
	std::string s;
	s.assign(MyCall);
	s.append(ARQ_DLE);
	s.append(UrCall);
	s.append(ARQ_DLE);
	return s;
}

// Connect
// e.g.: '~1cW1HKJ;KH6TY;12345;XXXX~4'
//
void arq::connectFrame()
{
	reset();
	std::string Frame;
	Frame.append(ARQ_SOF);
	Frame += CONREQ;
	Frame.append(calls());
	Frame.append(str_xfrsize);
	Frame.append(ARQ_DLE);
	Frame.append(checksum(Frame));

	Frame.append(ARQ_EOF);

	LinkState = ARQ_CONNECTING;
	sender = true;

	printLOG("send CONREQ", "");

	addToTxQue(Frame);
	lastblock = CONREQ;
}


// Connect acknowledge
// e.g: '~1CKH6TY;W1HKJ;XXXX~4'
//
void arq::conackFrame ()
{
	reset();

	if (progStatus.ID_off) {
		set_fldigi_rxid(0);
		set_fldigi_txid(0);
	}

	std::string Frame;
	Frame.append(ARQ_SOF);
	Frame += CONACK;

	Frame.append(calls());

	Frame.append(checksum(Frame));
	Frame.append(ARQ_EOF);

	printLOG("send CONACK", "");

	addToTxQue(Frame);
	lastblock = CONACK;
}

void arq::ackFrame()
{
	std::string Frame;
	Frame.append(ARQ_SOF);
	Frame += ACK;

	Frame.append(calls());
	Frame.append(str_blknbr);

	Frame.append(ARQ_DLE);

	Frame.append(checksum(Frame));
	Frame.append(ARQ_EOF);

	printLOG("send ACK", "");

	addToTxQue(Frame);
	lastblock = ACK;
}

void arq::nakFrame()
{
	std::string Frame;
	Frame.append(ARQ_SOF);
	Frame += NAK;

	Frame.append(calls());
	Frame.append(checksum(Frame));
	Frame.append(ARQ_EOF);

	printLOG("send NAK", "");

	addToTxQue(Frame);
	lastblock = NAK;
}

// Disconnect session

void arq::disconnectFrame()
{
	std::string Frame;
	Frame.append(ARQ_SOF);
	Frame += DISREQ;

	Frame.append(calls());
	Frame.append(checksum(Frame));
	Frame.append(ARQ_EOF);

	printLOG("send DISCON", "");

	addToTxQue(Frame);

	lastblock = DISREQ;

	sender = true;
}

void sked_reset(void *)
{
	inst->exec_arqreset();
}

void arq::disackFrame()
{
	std::string Frame;
	Frame.append(ARQ_SOF);
	Frame += DISACK;

	Frame.append(calls());
	Frame.append(checksum(Frame));
	Frame.append(ARQ_EOF);

	printLOG("send DISACK", "");

	addToTxQue(Frame);

	lastblock = DISACK;

}

// poll
void arq::pollFrame()
{
	std::string Frame;
	Frame.append(ARQ_SOF);
	Frame += POLL;

	Frame.append(calls());
	Frame.append(checksum(Frame));
	Frame.append(ARQ_EOF);

	printLOG("send POLL", "");

	addToTxQue(Frame);
	lastblock = POLL;
}

// Text frame
static std::string lastframe;

void arq::dataFrame()
{
	char msg[200] = "send DATA";
	std::string Frame;
	static char szbknbr[12];
	payload = xmttext.substr(0, buffer_length);
	last_buffer_length = buffer_length;

	Frame.append(ARQ_SOF);
	Frame += DATA;

	Frame.append(calls());
	blknbr++;
	snprintf(szbknbr, sizeof(szbknbr), "%03d", blknbr);
	str_blknbr = szbknbr;
	Frame.append(szbknbr);
	Frame.append(ARQ_DLE);
	Frame.append(payload);

	Frame.append(checksum(Frame));
	Frame.append(ARQ_EOF);

	if (xfrsize) {
		qualityfnc( 1.0 * (xfrsize - xmttext.length()) / xfrsize);
		snprintf(msg, sizeof(msg),"send DATA %0.1f %%", 100.0 * (xfrsize - xmttext.length()) / xfrsize);
	}
	printLOG(msg, "");

	lastframe = Frame;
	lastblock = DATA;

	addToTxQue(Frame);
}

//=====================================================================

bool arq::rightCALLS()
{
// test call signs
// requesting stations callsign
	std::string testcall;
	size_t p1 = 1, p2 = rcvPayLoad.find(ARQ_DLE, p1);
	if (p2 != std::string::npos) {
		testcall = upcase(rcvPayLoad.substr(p1, p2 - p1));
		if (UrCall != testcall) {
			printLOG("Wrong call", "");
			return false;
		}
		p1 = p2+1;
		p2 = rcvPayLoad.find(ARQ_DLE, p1);
		if (p2 != std::string::npos) {
			testcall = upcase(rcvPayLoad.substr(p1, p2 - p1));
			if (testcall != MyCall) {
				printLOG("Not my call", "");
				return false;
			}
		} else
			return false;
	} else
		return false;

	rcvPayLoad.erase(0, p2+1);

	return true;
}

void arq::parseCONREQ()
{
	size_t p1 = 1, p2 = rcvPayLoad.find(ARQ_DLE);
	if (p2 == std::string::npos) {
		printLOG("CONREQ no calls", "");
		return;
	}
	std::string testcall = upcase(rcvPayLoad.substr(p1, p2 - p1));

	if ((LinkState == ARQ_CONNECTED) && (UrCall != testcall) )
		return; // disallow multiple connects

// requesting stations callsign
	UrCall = testcall;

	p1 = p2 + 1;
	p2 = rcvPayLoad.find(ARQ_DLE, p1);
	testcall = upcase(rcvPayLoad.substr(p1, p2 - p1));
	if (testcall != MyCall) {
		printLOG("CONREQ not my call", "");
		UrCall.clear();
		rxUrCall(UrCall);
		return;
	}

	rxUrCall(UrCall);

	p2++;
	int sz;
	sscanf(rcvPayLoad.substr(p2).c_str(), "%d", &sz);
	xfrsize = sz;

	TxTextQueue.clear();
	RxTextQueue.clear();
	arqfname.clear();

	printLOG("received CONREQ", "");

	conackFrame();

	LinkState = ARQ_CONNECTED;
}

void arq::parseCONACK()
{
	if (!rightCALLS()) return;

	if (progStatus.ID_off) {
		set_fldigi_rxid(0);
		set_fldigi_txid(0);
	}

	RxTextQueue.clear();

	printLOG("received CONACK", "");

	dataFrame();

	LinkState = ARQ_CONNECTED;
}

void arq::parseDISREQ()
{
	if (!rightCALLS() || (LinkState != ARQ_CONNECTED)) return;

	TxTextQueue.clear();

	printLOG("received DISREQ", "");

	disackFrame();
}

void arq::parseDISACK()
{
	if (!rightCALLS()) return;
	printLOG("received DISACK", "");
	exec_arqreset();
}

void arq::parsePOLL()
{
	if (!rightCALLS() || (LinkState != ARQ_CONNECTED)) return;

	printLOG("received POLL", "");

	ackFrame();
}

void arq::parseDATA()
{
	if (!rightCALLS() || (LinkState != ARQ_CONNECTED)) return;

	char msg[200] = "received DATA";

	size_t pos = rcvPayLoad.find(ARQ_DLE);
	if (pos == std::string::npos) return;
	std::string str_test = rcvPayLoad.substr(0, pos);
	if (str_test != str_blknbr) {
		str_blknbr = str_test;
		rcvPayLoad.erase(0, pos + 1);
		RxTextQueue.append(rcvPayLoad);
		if (xfrsize) {
			qualityfnc( 1.0 * RxTextQueue.length() / xfrsize);
			snprintf(msg, sizeof(msg),"received DATA %0.1f %%", 100.0 * RxTextQueue.length() / xfrsize);
		}
		if (xfrsize == RxTextQueue.length()) {
			qualityfnc(1.0);
			std::string fname = "message";
			size_t p = std::string::npos;
			if ((p = RxTextQueue.find("[ARQ:fn ")) != std::string::npos) {
				p += 8;
				size_t p2 = RxTextQueue.find("]", p);
				if (p2 != std::string::npos)
					fname = RxTextQueue.substr(p, p2 - p);
			}
			snprintf(msg, sizeof(msg), 
				"%s\"%s\" from %s",
				sRcvd.c_str(),
				fname.c_str(),
				UrCall.c_str());
			escape(false, RxTextQueue);
			printRX(RxTextQueue);
			RxTextQueue.clear();
		}
	}
	printLOG(msg, "");

	ackFrame();
}

void arq::parseACK()
{
	if (!rightCALLS() || (LinkState != ARQ_CONNECTED)) return;

	printLOG("received ACK", "");

	size_t pos = rcvPayLoad.find(ARQ_DLE);
	if (pos == std::string::npos) return;

	if (str_blknbr == rcvPayLoad.substr(0, pos)) {
		xmttext.erase(0, last_buffer_length);
		if (!xmttext.empty())
			dataFrame();
		else {
			qualityfnc(1.0);
			std::string msg = "Transferred \"";
			msg.append(arqfname).append("\" to ").append(UrCall);
			printLOG(msg, "");
			disconnect();
		}
	} else {
		addToTxQue(lastframe);
	}
}

void arq::parseNAK()
{
	if (!rightCALLS() || (LinkState != ARQ_CONNECTED)) return;

	printLOG("received NAK", "");
	printLOG("resend DATA FRAME", "");

	addToTxQue(lastframe);
}

void arq::parseFrame(std::string txt)
{
	txt = noCR(txt);

	Ccrc16 testcrc;
	size_t len = txt.length();

	if (len < 15) return;

	rcvPayLoad = txt.substr(0, len - strlen(ARQ_EOF) - 4);

	std::string sRcvdCRC = testcrc.scrc16( rcvPayLoad );

	std::string rxCRC = txt.substr(len - strlen(ARQ_EOF) - 4, 4);

	if (sRcvdCRC != rxCRC ) { // failed CRC test
		retrytime = rtry();
		timeout = getRetries() * retrytime;
		printLOG("failed CRC test", "");
		if (!sender && (LinkState == ARQ_CONNECTED))
			nakFrame();
		return;
	}

	rcvPayLoad.erase(0, strlen(ARQ_SOF));

	switch (rcvPayLoad[0]) {
		case CONREQ :
			printLOG("<RX>", txt);
			parseCONREQ();
			break;
		case CONACK :
			printLOG("<RX>", txt);
			parseCONACK();
			break;
		case DISREQ :
			if (LinkState >= ARQ_CONNECTED)
				printLOG("<RX>", txt);
			parseDISREQ();
			break;
		case DISACK :
			if (LinkState >= ARQ_CONNECTED)
				printLOG("<RX>", txt);
			parseDISACK();
			break;
		case POLL :
			if (LinkState == ARQ_CONNECTED)
				printLOG("<RX>", txt);
			parsePOLL();
			break;
		case ACK:
			if (LinkState == ARQ_CONNECTED)
				printLOG("<RX>", txt);
			parseACK();
			break;
		case NAK:
			if (LinkState == ARQ_CONNECTED)
				printLOG("<RX>", txt);
			parseNAK();
			break;
		case DATA :
			if (LinkState == ARQ_CONNECTED)
				printLOG("<RX>", txt);
			parseDATA();
			break;
		default :
			nakFrame();
	}
	retrytime = rtry();
	timeout = getRetries() * retrytime;
}


//=====================================================================
void arq::setbuffer_length()
{
	if (exponent == 4) buffer_length = 16;
	else if (exponent == 5) buffer_length = 32;
	else if (exponent == 6) buffer_length = 64;
	else if (exponent == 7) buffer_length = 128;
	else if (exponent == 8) buffer_length = 256;
	else if (exponent == 9) buffer_length = 512;
	else if (exponent == 10) buffer_length = 1024;
	else buffer_length = 128;
}

void arq::connect()
{
	for (size_t i = 0; i < UrCall.length(); i++)
		UrCall[i] = toupper(UrCall[i]);

	rxUrCall(UrCall);

	first_rtry = true;
	TxTextQueue.clear();
	connectFrame();
	retries = getRetries();
	LinkState = ARQ_CONNECTING;

}

void arq::disconnect()
{
	disconnectFrame();
	retries = getRetries();
	LinkState = ARQ_DISCONNECT;
}

void arq::escape(bool encode, std::string &s)
{
	if (encode) {
		size_t p = s.find(ESC_CHR);
		while (p != std::string::npos) {
			p++;
			s.insert(p, 1, ESC_CHR);
			p = s.find(ESC_CHR, p+1);
		}
	} else {
		std::string dblesc;
		dblesc += ESC_CHR; dblesc += ESC_CHR;
		size_t p = s.find(dblesc);
		while (p != std::string::npos) {
			s.erase(p,1);
			p = s.find(dblesc, p+1);
		}
	}
}

void arq::sendtext(std::string call, std::string s)
{
	char s_xfrsize[20];

	if (LinkState != ARQ_DOWN) return;
	xmttext = s;
	escape(true, xmttext);
	xfrsize = xmttext.length();
	snprintf(s_xfrsize, sizeof(s_xfrsize), "%d", (int)xfrsize);
	str_xfrsize = s_xfrsize;
	UrCall = call;
	if (progStatus.ID_on) {
		set_fldigi_rxid(1);
		set_fldigi_txid(1);
	}

	arqfname.clear();
	size_t p = std::string::npos;
	if ((p = s.find("[ARQ:fn ")) != std::string::npos) {
		p += 8;
		size_t p2 = s.find("]", p);
		if (p2 != std::string::npos)
			arqfname = s.substr(p, p2 - p);
	}

	connect();
}

// received a NAK resend the last frame
// add retry countdown etc.

void arq::resendFrame()
{
	addToTxQue(lastframe);

	printLOG("received NAK", "");
}

extern void arqlog(std::string, std::string);

int arq::rtry()
{
	nomFrame.clear();
	nomFrame.append(ARQ_SOF);
	nomFrame += 'A';
	nomFrame.append (MyCall);
	nomFrame.append(ARQ_DLE);
	nomFrame.append("AA9AAA/8");
	nomFrame.append(ARQ_DLE);
	nomFrame.append(std::string(16,'B'));
	nomFrame.append("1234");
	nomFrame.append(ARQ_EOF);

	float response_delay = transmit_time(nomFrame);
	if (response_delay < 5.0) response_delay = 5.0;
	response_delay *= 1000.0; // in milliseconds
	response_delay *= (1.0 + (0.5 * rand() / RAND_MAX));
	int idelay = floorf(response_delay/ ARQLOOPTIME);

	if (first_rtry) {
		std::stringstream str;
		str << "Wait " << idelay * ARQLOOPTIME / 1000.0 << " sec's before retry";
		printLOG(str.str(), "");
		first_rtry = false;
	}

	return idelay;
}

void arq::exec_arqreset()
{
	MilliSleep(1000);

	LinkState	= ARQ_DOWN;
	retries		= getRetries();
	retrytime	= rtry();
	timeout		= -1;
	xfrsize		= 0;
	xfrsize		= 0;
	sender		= false;

	RxTextQueue.clear();
	TxTextQueue.clear();

	printLOG("DISCONNECTED","");
	rxUrCall("");
	qualityfnc(0);

	if (progStatus.ID_on) {
		set_fldigi_rxid(1);
		set_fldigi_txid(1);
	}
	disconnectfnc();
}

static std::string rxbuf = "  ";
static char chkchar = ' ';
void arq::rcv_chars()
{
	char c;
	while (getc1(c) == true) {
		chkchar = rxbuf[0];
		rxbuf[0] = rxbuf[1];
		rxbuf[1] = c;
		if ((rxbuf == ARQ_SOF) && (chkchar != ESC_CHR)) {
			RxFrameQueue.clear();
			RxFrameQueue.append(rxbuf);
		} else if (RxFrameQueue.find(ARQ_SOF) == 0) {
			retrytime = rtry();
			timeout = getRetries() * retrytime;
			if ((rxbuf == ARQ_EOF) && (chkchar != ESC_CHR)) {
				RxFrameQueue += c;
				parseFrame(RxFrameQueue);
				RxFrameQueue.clear();
				goto retfunc;
			} else
				RxFrameQueue += c;
		} else if ((rxbuf == ARQ_EOF) && (chkchar != ESC_CHR)) {
			RxFrameQueue.clear();
		}
		if (RxFrameQueue.length() > 1200)
			exec_arqreset();
	}
retfunc:
	if (trx()) return;
	//!OK_to_transmit()) return;

	if (LinkState != ARQ_DOWN) {
		--timeout;
		if (timeout == 0) {
			std::string fname = "";
			std::string msg = sTout;
			size_t p = std::string::npos;
			fname = arqfname;
			if (fname.empty()) {
				if ((p = RxTextQueue.find("[ARQ:fn ")) != std::string::npos) {
					p += 8;
					size_t p2 = RxTextQueue.find("]", p);
					if (p2 != std::string::npos)
					fname = RxTextQueue.substr(p, p2 - p);
				}
			}
			if (fname.empty()) fname.assign(_("Filename not known"));
			msg.append(fname);
			msg.append(sColon).append(UrCall);
			printLOG(msg, "");
			exec_arqreset();
		}
	}
}

void arq::sendchars()
{
	if (!OK_to_transmit()) {
		return;
	}
	if (RxFrameQueue.find(ARQ_SOF) == 0) {
		return;
	}

// test for non response if this is the sending station
	if (LinkState != arq::ARQ_DOWN) {
		if (sender) {
			retrytime--;
			if (retrytime == 0) {
				retries--;
				if (retries == 0) {
					std::string failtext = sRtry;
					failtext.append(UrCall);
					failtext.append(sColon);
					failtext.append(arqfname);
					failtext.append(sColon);
					switch (lastblock) {
						case DATA: failtext.append("DATA block"); break;
						case POLL: failtext.append("POLL block"); break;
						case CONREQ: failtext.append("CONREQ block"); break;
						case DISREQ: failtext.append("DISREQ block"); break;
					}
					printLOG("<TX>", failtext);
					exec_arqreset();
					return;
				}

				std::stringstream s;
				s << "Resend " << retries;
				printLOG("<TX>", s.str());
				retrytime = rtry();

				if (lastblock == DATA) pollFrame();
				if (lastblock == POLL) pollFrame();
				else if (lastblock == CONREQ) connectFrame();
				else if (lastblock == DISREQ) disconnectFrame();

				printLOG("<TX>", TxTextQueue);

				sendfnc(TxTextQueue.insert(0,"   \n"));

				TxTextQueue.clear();

				return;
			}
		}
	}

//	transmit new data

	if (TxTextQueue.empty() )
		return;

	printLOG("<TX>", TxTextQueue);

	sendfnc(TxTextQueue.insert(0,"   \n"));

	retrytime = rtry();

	if (lastblock == DISACK) exec_arqreset();

	TxTextQueue.clear();

	return;
}

//----------------------------------------------------------------------
// friend process of arq class
// operates in a separate thread
// all called by reference functions must use Fl::wait(fn,...)
// to isolate the UI thread from the arq thread
//----------------------------------------------------------------------

void * arqloop(void *)
{
	int  looptime = ARQLOOPTIME;

	while (1) {
		MilliSleep(
			inst->LinkState == arq::ARQ_DOWN ? looptime * 10 : looptime);
		if (inst->arq_exit) break;
		{
			guard_lock arqlock( &arq_mutex );
			if (inst->arqreset) {
				inst->exec_arqreset();
				inst->arqreset = false;
			}
			inst->rcv_chars();
			inst->sendchars();
		}
	}
	return NULL;
}

void arq::start_arq()
{
	if (arq_running) return;  // ONLY ONE instance allowed
	inst = this;

	if (pthread_create(&arq_thread, NULL, arqloop, NULL) < 0) {
		LOG_ERROR("arq init: pthread_create failed");
		arq_running = false;
		inst = NULL;
		return;
	}
	if (progStatus.ID_on) {
		set_fldigi_rxid(1);
		set_fldigi_txid(1);
	}
	arq_running = true;
}

void arq::reset_arq() {
	arqreset = true;
}

void arq::exit_arq() {
	if (arq_running == false) return;
	{
		guard_lock arqlock( &arq_mutex );
		arq_exit = true;
	}
	pthread_join(arq_thread, NULL);
	arq_running = false;

}
//---------------------------------------------------------------------
