// ----------------------------------------------------------------------------
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
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/x.H>
#include <FL/Fl_Help_Dialog.H>
#include <FL/Fl_Menu_Item.H>

// this tests depends on a modified FL/filename.H in the Fltk-1.3.0
// change
//#  if defined(WIN32) && !defined(__CYGWIN__) && !defined(__WATCOMC__)
// to
//#  if defined(WIN32) && !defined(__CYGWIN__) && !defined(__WATCOMC__) && !defined(__WOE32__)

#include <FL/filename.H>

#ifdef __MINGW32__
#	include "compat.h"
#endif

#include <dirent.h>

#include "fileselect.h"

#include "socket.h"

#include <dirent.h>

#include "flmsg.h"
#include "flmsg_dialog.h"
#include "flmsg_arq.h"
#include "xml_io.h"

#include "threads.h"
#include "flmsg_arq.h"
#include "flmisc.h"
#include "stacktrace.h"
#include "icons.h"
#include "arq.h"

#include "base64.h"
#include "gettext.h"
#include "status.h"
#include "wrap.h"
#include "time_table.h"

bool SHOWDEBUG = true;

Fl_Double_Window *dlgconfig = (Fl_Double_Window *)0;

using namespace std;

arq  flmsg_arq;

bool traffic = false;
int  arqstate = 0;

string RX;
string TX;

string MyCall;
string UrCall;

#if !defined(__APPLE__) && !defined(__WOE32__) && USE_X
Pixmap flarq_icon_pixmap;
#endif

string rxbuffer;

size_t  bufsize = 0;

int    blocksSent = 0;

float  vers = 0;
float  version;

extern std::string arqstates[];

const char *ASCII[32] = {
	"<NUL>", "<SOH>", "<STX>", "<ETX>", // 0x00 - 0x03
	"<EOT>", "<ENQ>", "<ACK>", "<BEL>", // 0x04 - 0x07
	"<BX>",  "<TAB>", "<LF>",  "<VT>",  // 0x08 - 0x0B
	"<FF>",  "<CR>",  "<SO>",  "<SI>",  // 0x0C - 0x0F
	"<DLE>", "<DC1>", "<DC2>", "<DC3>", // 0x10 - 0x13
	"<DC4>", "<NAK>", "<SYN>", "<ETB>", // 0x14 - 0x17
	"<CAN>", "<EM>",  "<SUB>", "<ESC>", // 0x18 - 0x1B
	"<FS>",  "<GS>",  "<RS>",  "<US>"   // 0x1C - 0x1F
};

static pthread_mutex_t nocr_mutex = PTHREAD_MUTEX_INITIALIZER;
string noCR(string s)
{
	guard_lock lock(&nocr_mutex);
	string text = s;
	size_t p;
	while ((p = text.find('\r')) != string::npos)
		text.erase(p,1);
	return text;
}

static pthread_mutex_t noctl_mutex = PTHREAD_MUTEX_INITIALIZER;
string noCTL(string s)
{
	guard_lock lock(&noctl_mutex);
	string text;
	int c;
	for (size_t n = 0; n < s.length(); n++) {
		c = s[n];
		if ((c >= 0) && (c < 0x20))
			text.append(ASCII[c]);
		else
			text += c;
	}
	return text;
}

string incomingText = "";
string txtarqload = "";
string rxfname = "";
string arqstart = "ARQ::STX\n";
string arqend   = "ARQ::ETX\n";
string arqfile = "ARQ:FILE::";
string arqbase64 = "ARQ:ENCODING::BASE64\n";
string arqsizespec = "ARQ:SIZE::";
size_t startpos = string::npos;
size_t endpos = string::npos;
size_t fnamepos = string::npos;
size_t indx = string::npos;
size_t sizepos = string::npos;
size_t lfpos = string::npos;
size_t arqPayloadSize = 0;
bool rxARQfile = false;
bool rxARQhavesize = false;
bool rxTextReady = false;

time_t StartTime_t;
time_t EndTime_t;
time_t TransferTime_t;
double TransferTime;

char statemsg[80];

void dispState()
{
	switch (flmsg_arq.state()) {
		case arq::ARQ_CONNECTING :
			txtSTATE->value("CONNECTING");
			txtSTATE->redraw();
			btnSEND->label("Wait");
			btnSEND->redraw_label();
			break;
		case arq::ARQ_CONNECTED :
			txtSTATE->value("CONNECTED");
			txtSTATE->redraw();
			txtSENDTO->value( flmsg_arq.urCall().c_str() );
			btnSEND->label("End");
			btnSEND->redraw_label();
			break;
		case arq::ARQ_DISCONNECT:
			txtSTATE->value("ARQ_DISCONNECT");
			txtSTATE->redraw();
			btnSEND->label("Wait");
			btnSEND->redraw_label();
			break;
		case arq::ARQ_DISCONNECTING:
			txtSTATE->value("ARQ_DISCONNECTING");
			txtSTATE->redraw();
			btnSEND->label("Wait");
			btnSEND->redraw_label();
			break;
		case arq::ARQ_DOWN :
		default :
			txtSTATE->value("NOT CONNECTED");
			txtSTATE->redraw();
			btnSEND->label("Send");
			btnSEND->redraw_label();
	}
}

void client_transmit(const string& s )
{
	MilliSleep(50);
	try {
		if (!s.empty()) {
			xml_send_tx_chars(s);
		}
	}
	catch (const SocketException& e) {
		cerr << e.what() << '\n';
	}
}

size_t rxbuffer_len = 0;
size_t rxbuffer_ptr = 0;

bool client_receive(char &c)
{
	if (rxbuffer_len && (rxbuffer_ptr < rxbuffer_len)) {
		c = rxbuffer[rxbuffer_ptr];
		rxbuffer_ptr++;
		return true;
	}
	rxbuffer.clear();
	rxbuffer_len = rxbuffer_ptr = 0;
	string rxstr = xml_get_rx_chars();
	if (!rxstr.empty()) {
		rxbuffer = rxstr;
		rxbuffer_len = rxbuffer.length();
	}

	return false;
}

void restrt(void *)
{
	prgSTATE->value(0.0);
	prgSTATE->label("");
	prgSTATE->redraw_label();
	prgSTATE->redraw();
	rxARQfile = false;
	incomingText.clear();
}

void restart()
{
	Fl::awake(restrt);
}

void arqSEND()
{
	int state = Fl::event_state();
	if ((state & FL_CTRL) == FL_CTRL) {
		flmsg_arq.reset_arq();
		txtSENDTO->value("");
		Fl::awake(restrt);
		return;
	}
	if (progStatus.my_call.empty()) return;

	if (strlen(txtSENDTO->value()) == 0) return;

	int arqstate = flmsg_arq.state();

	if (arqstate == arq::ARQ_DOWN) {
		flmsg_arq.myCall(progStatus.my_call.c_str());
		cb_wrap_autosend();
	} else {
		flmsg_arq.disconnect();
		txtSENDTO->value("");
		Fl::awake(restrt);
	}
}

pthread_mutex_t payload_mutex = PTHREAD_MUTEX_INITIALIZER;

void save_this_file_as(string fname, string txt)
{
	if (txt.find("<transfer>") != string::npos) {
		cb_transfer_wrap_import(fname, txt);
		select_form(TRANSFER);
		return;
	}

	string fnam = fname;
	string outfname;
	string tst_name;
	string tst_ext = "";

// write to file with name(s) such as
// test.b2s, test-01.txt, test-02.txt etc.  up to 999
	size_t pos = fnam.find(".");
	if (pos != string::npos) {
		tst_name = fnam.substr(0, pos);
		tst_ext = fnam.substr(pos);
	} else
		tst_name = fnam;

	char fnum[8]="";
	int num = 0;
	outfname.assign(ICS_msg_dir).append(tst_name).append(tst_ext);

	ifstream tstfile;
	tstfile.open(outfname.c_str());
	while (tstfile) {
		tstfile.close();
		snprintf(fnum, sizeof(fnum), "-%03d", (++num % 1000));
		outfname.assign(ICS_msg_dir).append(tst_name).append(fnum).append(tst_ext);
		tstfile.open(outfname.c_str());
	}

// decompress_maybe returns 0 on failure
	decompress_maybe(txt);

	ofstream ofile(outfname.c_str(), ios::binary);
	if (ofile) ofile << txt;
	ofile.close();

	add_rcvd_msg(tst_name.append(fnum).append(tst_ext));

	return;

}

void display_payloadtext(string fname, string txt)
{
	save_this_file_as(fname, txt);
}

// process an AutoSend data stream

void direct_payload(string txt)
{
LOG_INFO("%s", txt.substr(0, 50).c_str());

	size_t pos = txt.find("WRAP:fn ");
	if (pos == string::npos) return;
	txt.erase(0, pos + 8);
	pos = txt.find("]");
	if (pos == string::npos) return;

	string fname = txt.substr(0,pos);
	txt.erase(0,pos + 1);
	pos = txt.find("[WRAP:chk");
	if (pos == string::npos) return;
	txt.erase(pos);

	save_this_file_as(fname, txt);
}

// process an ARQ data stream

void payloadtext(void *)
{
	guard_lock payload(&payload_mutex);

	if ((startpos = incomingText.find(arqstart)) != string::npos) {
		startpos += arqstart.length();
		time(&StartTime_t);
	} else
		return;

	if ((endpos = incomingText.find(arqend)) != string::npos) {
		fnamepos = incomingText.find(arqfile);
		fnamepos += arqfile.length();
		indx = incomingText.find('\n', fnamepos);
		rxfname = incomingText.substr(fnamepos, indx - fnamepos);
		txtarqload = incomingText.substr(startpos, endpos - startpos);
		if (incomingText.find(arqbase64) != string::npos) {
			base64 b64;
			txtarqload = b64.decode(txtarqload);
		}
		startpos = string::npos;
		endpos = string::npos;
		fnamepos = string::npos;
		indx = string::npos;
		sizepos = string::npos;
		lfpos = string::npos;
		arqPayloadSize = 0;
		rxARQfile = false;
		rxARQhavesize = false;
		rxTextReady = true;
		if (incomingText.find("FLMSG_XFR") != std::string::npos) {
			string outfname;
			string arqstr = "[ARQ:fn ";
			size_t p = txtarqload.find(arqstr);
			if (p != string::npos) {
				txtarqload.erase(0, p + arqstr.length());
				p = txtarqload.find("]");
				if (p != string::npos) {

					outfname = txtarqload.substr(0, p);
					txtarqload.erase(0, p + 1);
					display_payloadtext(outfname, txtarqload);

				}
			}
		}
		incomingText = "";
	}
}

void payloadText(string s)
{
	guard_lock payload(&payload_mutex);
	incomingText.assign (s);
	Fl::awake(payloadtext);
}

void abted(void *)
{
	notify_dialog* alert_window = new notify_dialog;
	alert_window->set_non_modal();
	alert_window->notify(_("Transfer aborted"), 0, true);
	restart();
}

void abortedTransfer()
{
	Fl::awake(abted);
}

static string arqascii = "ARQ:ENCODING::ASCII\n";

void send_xml_text(std::string txt)
{
	size_t txtsize;
	char sizemsg[40];

	if (!txt.empty()) {
		TX.erase();
		TX.append(arqfile);
		TX.append("FLMSG_XFR");
		TX.append("\n");
		TX.append(arqascii);
		txtsize = txt.length();
		arqPayloadSize = txtsize;
		blocksSent = 0;
		snprintf(sizemsg, sizeof(sizemsg), "ARQ:SIZE::%d\n",
			static_cast<int>(txtsize));
		TX.append(sizemsg);
		TX.append(arqstart);
		TX.append(txt);
		TX.append(arqend);
	}
	traffic = true;
}

static float update_val;
static char szPercent[8];
void updateQuality(void *)
{
	prgSTATE->value( update_val );
	snprintf(szPercent, sizeof(szPercent), "%0.f %%", update_val*100.0 + 0.5);
	prgSTATE->label(szPercent);
}

void showQuality(float val)
{
	update_val = val;
	Fl::awake(updateQuality);
}

void mainloop(void *)
{

	if (traffic) {
		flmsg_arq.sendtext(txtSENDTO->value(), TX);
		traffic = false;
		time(&StartTime_t);
	}
	dispState();
	Fl::repeat_timeout(0.1, mainloop);
}

static string str_status;
//static double dtime;
pthread_mutex_t protect_status = PTHREAD_MUTEX_INITIALIZER;

void print_status(void *data)
{
	if (!btext) return;

	guard_lock protect(&protect_status);
	if (str_status.empty()) return;

	size_t pos;
	pos = str_status.find("\n");
	while (pos != string::npos) {
		btext->add(str_status.substr(0, pos).c_str());
		str_status.erase(0, pos + 1);
		pos = str_status.find("\n");
	}
	btext->redraw();
	btext->bottomline(btext->size());
	str_status.clear();
}

static string notify_string;

void notify_(void *)
{
	notify_dialog* alert_window = new notify_dialog;
	alert_window->notify(notify_string.c_str(), progStatus.arq_notify_timeout, true);
}

std::string sXfrd = _("Transferred ");
std::string sRcvd = _("Received ");
std::string sRtry = _("Retries failed: ");
std::string sTout = _("Timed out:");
std::string sTo = _(" to ");
std::string sFm = _(" from ");
std::string sColon = _(" : ");

void STATUSprint(string s)
{
	size_t p = 0;

	if ( s.find(sXfrd) != std::string::npos) { // transferred
		notify_string = s;
		p = notify_string.find(sXfrd);
		if (p != std::string::npos) notify_string[p + sXfrd.length() - 1] = '\n';
		p = notify_string.find(sTo);
		if (p != std::string::npos) notify_string[p] = '\n';
		Fl::awake(notify_);
	}
	else if (s.find(sRcvd) != std::string::npos && progStatus.notify_receipt) { // received
		notify_string = s;
		p = notify_string.find(sRcvd);
		if (p != std::string::npos) notify_string[p + sRcvd.length() - 1] = '\n';
		p = notify_string.find(sFm);
		if (p != std::string::npos) notify_string[p] = '\n';
		Fl::awake(notify_);
	}
	else if (s.find(sRtry) != std::string::npos) { // retries
		notify_string = s;
		p = notify_string.find(">");
		if (p != std::string::npos)
			notify_string.insert(p+1, "\n");
		p = notify_string.find(sColon);
		while (p != std::string::npos) {
			notify_string.replace(p, sColon.length(), "\n");
			p = notify_string.find(sColon);
		}
		Fl::awake(notify_);
	}
	else if (s.find(sTout) != std::string::npos) { // timed
		notify_string = s;
		p = notify_string.find(sTout);
		notify_string[p + sTout.length() -1] = '\n';
		p = notify_string.find(sColon);
		while (p != std::string::npos) {
			notify_string.replace(p, sColon.length(), "\n");
			p = notify_string.find(sColon);
		}
		Fl::awake(notify_);
	}
}

void arqlog(string nom, string s)
{
	char szGMT[80];
	tm *now;
	time_t tm;

	if (nom.empty() && s.empty()) return;

	time(&tm);
	now = localtime( &tm );
	memset(szGMT, 0, 80);
	strftime(szGMT, sizeof(szGMT), "[%X] ", now);

	string txtout;
	txtout.assign(szGMT).append(nom).append(" ").append(noCTL(s));

	STATUSprint(txtout);

	string logname = FLMSG_log_dir;
	logname.append("flmsg.log");
	ofstream logfile(logname.c_str(), ios::app);
	if (logfile){
		logfile << txtout;
		if (s[s.length()-1] != '\n') logfile << endl;
	}
	logfile.close();

	if (txtout.length() > 60) txtout.erase(60);

	if (txtout.length() == 0) return;

	Fl_Color color = FL_BLACK;
	if (s.find(sTout) != std::string::npos) // timed
		color = FL_RED;
	else if (s.find(sXfrd) != std::string::npos) // transferred
		color = FL_BLUE;
	else if (s.find(sRtry) != std::string::npos) // retries
		color = FL_RED;
	else if (nom == "<TX>")
		color = FL_DARK_RED;
	else if (nom == "<RX>")
		color = FL_DARK_GREEN;

	char clr[12];
	snprintf( clr, sizeof(clr),"@C%d@.", color);

	txtout.insert(0, clr);
	txtout.append("\n");

	guard_lock protect(&protect_status);
	str_status.append(txtout);
	Fl::awake(print_status);

}

static string txecho_s;
static void txecho(void *)
{
	string style;
	blocksSent += txecho_s.length();
	string text = noCR(txecho_s);
	txecho_s.clear();
}

void TXecho(string s)
{
	txecho_s = s;
	Fl::awake(txecho);
}

static string rxurcall_s;
static void rxurcall(void *)
{
	txtSENDTO->value(rxurcall_s.c_str());
	rxurcall_s.clear();
}

void rxUrCall(string s)
{
	rxurcall_s = s;
	Fl::awake(rxurcall);
}

string flmsg_trx()
{
	return xml_fldigi_trx();
}

float flmsg_xmt_time(string s)
{
	float xfr_time = 0, overhead;
	float rsid_time = 3.0;

	if (s.empty()) return rsid_time;

	xfr_time = seconds_from_c_string(cbo_modes->value(), s.c_str(), s.size(), &overhead);
	xfr_time += overhead;
	xfr_time += rsid_time;
	return xfr_time;
}

void init_flmsg_arq()
{
// the following sequence of assigning callback functions is mandatory
// for the arq class to function

	flmsg_arq.setRetries(progStatus.retries);
	flmsg_arq.setExponent(progStatus.exponent);

	flmsg_arq.setSendFunc (client_transmit);
	flmsg_arq.setGetCFunc (client_receive);
	flmsg_arq.setDisconnected(restart);
	flmsg_arq.setrxUrCall (rxUrCall);
	flmsg_arq.setOK_to_transmit (fldigi_OK_to_transmit);

	flmsg_arq.setPrintRX (payloadText);
	flmsg_arq.setPrintSTATUS (STATUSprint);
	flmsg_arq.setPrintLOG (arqlog);

	flmsg_arq.setQualityValue(showQuality);

	flmsg_arq.setTRX (flmsg_trx);

	flmsg_arq.setTransmitTime (flmsg_xmt_time);

	flmsg_arq.myCall(progStatus.my_call);

	flmsg_arq.start_arq();

	Fl::add_timeout(0.1, mainloop);
}

