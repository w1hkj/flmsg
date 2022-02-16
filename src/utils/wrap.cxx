// WRAP - wrap.cxx
//
// Author: Dave Freese, W1HKJ
//         Stelios Bounanos, M0GLD
//
// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/x.H>
#include <FL/Fl_Help_Dialog.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_File_Icon.H>
#include <math.h>

#include "config.h"
#include "flmsg_config.h"

#include "flmsg.h"

#include "templates.h"
#include "debug.h"
#include "util.h"
#include "gettext.h"
#include "flmsg_dialog.h"
#include "flinput2.h"
#include "date.h"
#include "calendar.h"
#include "icons.h"
#include "fileselect.h"
#include "wrap.h"
#include "status.h"
#include "pixmaps.h"

#include "base64.h"
#include "base128.h"
#include "base256.h"
#include "lzma/LzmaLib.h"
#include "status.h"
#include "flmsg_config.h"

#include "flmsg_arq.h"

#include "timeops.h"

//#include "socket.h"
#include "xml_io.h"

#ifdef WIN32
#  include "flmsgrc.h"
#  include "compat.h"
#  define dirent fl_dirent_no_thanks
#endif

#include <FL/filename.H>
#include "dirent-check.h"

#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Image.H>

#ifdef WIN32
#  include <winsock2.h>
#else
#  include <arpa/inet.h>
#endif

const char *wrap_beg = "[WRAP:beg]";
const char *wrap_end = "[WRAP:end]";
const char *wrap_crlf = "[WRAP:crlf]";
const char *wrap_lf = "[WRAP:lf]";
const char *wrap_chksum = "[WRAP:chksum ";

const char *b64_start = "[b64:start]";
const char *b64_end = "[b64:end]";
const char *b128_start = "[b128:start]\n";
const char *b128_end = "\n[b128:end]";
const char *b256_start = "[b256:start]\n";
const char *b256_end = "\n[b256:end]";

const char *wrap_fn = "[WRAP:fn ";

const char *dashes = "\n====================\n";

//const char *binaryfile[] = {
//	".jpg", ".jpeg", ".png", ".gif", ".bmp", ".ico", ".zip", ".gz", ".tgz", ".bz2", 0 };

std::string test_version = "1.1.23A";
bool old_version = false;

bool b_autosend = false;

Ccrc16 chksum;
base64 b64(1); // insert lf for ease of viewing
base128 b128;
base256 b256;

std::string inptext = "";
std::string wtext = "";
std::string check = "";
std::string wrap_outfilename = "";
std::string wrap_inpfilename = "";
std::string wrap_inpshortname = "";
std::string wrap_outshortname = "";
std::string wrap_foldername = "";

bool isExtension(const char *s1, const char *s2)
{
#ifdef WIN32
	char *sz1 = new char[strlen(s1) + 1];
	char *sz2 = new char[strlen(s2) + 1];
	char *p = 0;
	strcpy(sz1, s1);
	strcpy(sz2, s2);
	for (size_t i = 0; i < strlen(sz1); i++) sz1[i] = toupper(sz1[i]);
	for (size_t i = 0; i < strlen(sz2); i++) sz2[i] = toupper(sz2[i]);
	p = strstr(sz1, sz2);
	delete [] sz1;
	delete [] sz2;
	return (p != 0);
#else
	const char *p = strcasestr(s1, s2);
#endif
	return (p != 0);
}

void base64encode(std::string &inptext)
{
	std::string outtext;
	outtext = b64.encode(inptext);
	inptext = b64_start;
	inptext.append(outtext);
	inptext.append(b64_end);
}

void base128encode(std::string &inptext)
{
	std::string outtext;
	outtext = b128.encode(inptext);
	inptext = b128_start;
	inptext.append(outtext);
	inptext.append(b128_end);
}

void base256encode(std::string &inptext)
{
	std::string outtext = b256.encode(inptext);
	inptext = b256_start;
	inptext.append(outtext);
	inptext.append(b256_end);
}

// escape chars that cause transmission problems
// compabible with flwrap

void dress(std::string &str)
{
	std::string s = "";
	if (str.empty()) return;
	size_t p = 0;
	std::string rpl = "";
	unsigned char ch;
	for (p = 0; p < str.length(); p++) {
		ch = str[p] & 0xFF;
		rpl = ch;
		if (ch == ' ') rpl = "  ";
		else if ( ch == '|')
			rpl = "||";
		else if (ch >= 0x80 && ch < 0xC0) {
			rpl = "|-"; rpl += (ch - 0x60);
		}
		else if (ch >= 0xC0) {
			rpl = "|"; rpl += (ch - 0xA0);
		}
		else if (ch < ' ') {
			rpl = " "; rpl += (ch + '0');
		}
		s.append(rpl);
	}
	str = s;
}

void strip(std::string &s)
{
	if (s.empty()) return;
	size_t p = 0;
	unsigned char ch;
	std::string str = "";
	for (p = 0; p < s.length(); p++) {
		ch = s[p] & 0xFF;
		if (s.find("|+", p) == p) {
			ch = (s[p+2] & 0xFF) - 0x20;
			p += 2;
		}
		if (s.find("|-", p) == p) {
			ch = (s[p+2] & 0xFF) + 0x60;
			p += 2;
		}
		if (s.find("|_", p) == p) {
			ch = (s[p+2] & 0xFF) + 0xA0;
			p += 2;
		}
		if (s.find("||", p) == p) {
			ch = '|';
			p++;
		}
		str += ch;
	}
	s = str;
}

void convert2crlf(std::string &s)
{
	size_t p = s.find('\n', 0);

	while (p != std::string::npos) {
		s.replace(p, 1, "\r\n");
		p = s.find('\n', p + 2);
	}
}

bool convert2lf(std::string &s)
{
	bool converted = false;
	size_t p = s.find("\r\n", 0);

	while (p != std::string::npos) {
		s.replace(p, 2, "\n");
		p = s.find("\r\n", p + 1);
		converted = true;
	}
	return converted;
}

#define LZMA_STR "\1LZMA"

void compress_maybe(std::string& input, bool file_transfer)
{
	if (!progStatus.use_compression && !file_transfer) return;

	// allocate 110% of the original size for the output buffer
	size_t outlen = (size_t)ceil(input.length() * 1.1);
	unsigned char* buf = new unsigned char[outlen];

	size_t plen = LZMA_PROPS_SIZE;
	unsigned char outprops[LZMA_PROPS_SIZE];
	uint32_t origlen = htonl(input.length());

	std::string bufstr;

	int r;
	bufstr.assign(LZMA_STR);
	if ((r = LzmaCompress(
				buf, &outlen,
				(const unsigned char*)input.data(), input.length(),
				outprops, &plen, 4, 0, -1, -1, -1, -1, -1) ) == SZ_OK) {
		bufstr.append((const char*)&origlen, sizeof(origlen));
		bufstr.append((const char*)&outprops, sizeof(outprops));
		bufstr.append((const char*)buf, outlen);
	} else {
		LOG_ERROR("Lzma Compress failed: %s", LZMA_ERRORS[r]);
		bufstr.assign(input);
	}
	base64encode(bufstr);
	input = bufstr;

	LOG_INFO("Input size %d, Compressed size %d",
		(int)input.length(), (int)bufstr.length());

	delete [] buf;

	return;
}

// returns 0 on failure, 1 on success

int decompress_maybe(std::string& input)
{
// input is LZMA_STR + original size (in network byte order) + props + data
//	if (input.find(LZMA_STR) == std::string::npos)
//		return;

	int encode = BASE64;
	size_t	p0 = std::string::npos,
			p1 = std::string::npos,
			p2 = std::string::npos,
			p3 = std::string::npos;
	if ((p0 = p1 = input.find(b64_start)) != std::string::npos) {
		p1 += strlen(b64_start);
		p2 = input.find(b64_end, p1);
	} else if ((p0 = p1 = input.find(b128_start)) != std::string::npos) {
		p1 += strlen(b128_start);
		p2 = input.find(b128_end, p1);
		encode = BASE128;
	} else if ((p0 = p1 = input.find(b256_start)) != std::string::npos) {
		p1 += strlen(b256_start);
		p2 = input.find(b256_end, p1);
		encode = BASE256;
	} else
		return 1; // not a compressed file

	if (p2 == std::string::npos) {
		if (encode == BASE256)
			LOG_ERROR("%s", "Base 256 decode failed");
		else if (encode == BASE128)
			LOG_ERROR("%s", "Base 128 decode failed");
		else if (encode == BASE64)
			LOG_ERROR("%s", "Base 64 decode failed");
		return 0;
	}
	switch (encode) {
		case BASE128 :
			p3 = p2 + strlen(b128_end); break;
		case BASE256 :
			p3 = p2 + strlen(b256_end); break;
		case BASE64 :
		default :
			p3 = p2 + strlen(b64_end);
	}

	std::string cmpstr = input.substr(p1, p2-p1);

	switch (encode) {
		case BASE128 :
			cmpstr = b128.decode(cmpstr); break;
		case BASE256 :
			cmpstr = b256.decode(cmpstr); break;
		case BASE64 :
		default:
			cmpstr = b64.decode(cmpstr);
	}

	if (cmpstr.find("ERROR") != std::string::npos) {
		LOG_ERROR("%s", cmpstr.c_str());
		return 0;
	}

	if (cmpstr.find(LZMA_STR) == std::string::npos) {
		input.replace(p0, p3 - p0, cmpstr);
		return 0;
	}

	const char* in = cmpstr.data();
	size_t outlen = ntohl(*reinterpret_cast<const uint32_t*>(in + strlen(LZMA_STR)));
	if (outlen > 1 << 25) {
		LOG_ERROR("%s", "Refusing to decompress data (> 32 MiB)");
		return 0;
	}
	unsigned char* buf = new unsigned char[outlen];
	unsigned char inprops[LZMA_PROPS_SIZE];
	memcpy(inprops, in + strlen(LZMA_STR) + sizeof(uint32_t), LZMA_PROPS_SIZE);
	size_t inlen = cmpstr.length() - strlen(LZMA_STR) - sizeof(uint32_t) - LZMA_PROPS_SIZE;

	int r;
	if ((r = LzmaUncompress(buf, &outlen, (const unsigned char*)in + cmpstr.length() - inlen, &inlen,
			inprops, LZMA_PROPS_SIZE)) != SZ_OK)
		LOG_ERROR("Lzma Uncompress failed: %s", LZMA_ERRORS[r]);
	else {
		LOG_INFO("Decompress: in = %ld, out = %ld", (long int)inlen, (long int)outlen);
		cmpstr.assign((const char*)buf, outlen);
		input.replace(p0, p3 - p0, cmpstr);
	}
	delete [] buf;
	return 1;
}

bool wrapfile(bool with_ext)
{
	bool iscrlf = false;
	if (with_ext)
		wrap_outfilename.append(WRAP_EXT);
	wrap_outshortname = fl_filename_name(wrap_outfilename.c_str());


// checksum & data transfer always based on Unix end-of-line char
	iscrlf = convert2lf(inptext);

	std::string originalfilename = wrap_fn;
	originalfilename.append(wrap_inpshortname);
	originalfilename += ']';

	inptext.insert(0, originalfilename);

	check = chksum.scrc16(inptext);

	std::string ostr(wrap_beg);
	ostr.append(iscrlf ? wrap_crlf : wrap_lf);
	ostr.append(inptext).append(wrap_chksum).append(check).append("]");
	ostr.append(wrap_end);

	std::ofstream wrapstream(wrap_outfilename.c_str(), std::ios::binary);
	if (wrapstream) {
		LOG_INFO("Writing wrapfile: %s", wrap_outfilename.c_str());
		wrapstream << ostr;
		wrapstream.close();
	} else {
		LOG_INFO("Cannot write to: %s", wrap_outfilename.c_str());
		errtext = "Cannot open output file";
		return false;
	}

	return true;
}


// all of this crlf checking is necessary because the original file may have had crlf pairs
// or the OS save may have inserted them into the text (MSDOS) har!

bool unwrapfile()
{
	size_t p, p1, p2, p3, p4;
	std::string testsum;
	std::string inpsum;
	bool iscrlf = false;

	p1 = inptext.find(wrap_beg);
	if (p1 == std::string::npos) {
		errtext = "Not a wrap file";
		LOG_INFO("%s", errtext.c_str());
		return false;
	}

	p1 = inptext.find(wrap_crlf);
	if (p1 != std::string::npos) { // original text had crlf pairs
		iscrlf = true;
		p1 += strlen(wrap_crlf);
	} else {
		p1 = inptext.find(wrap_lf);
		if (p1 == std::string::npos) {
			errtext = "Invalid file";
			LOG_INFO("%s", errtext.c_str());
			return false;
		}
		p1 += strlen(wrap_lf);
	}

	p2 = inptext.find(wrap_chksum, p1);
	if (p2 == std::string::npos) return false;
	wtext = inptext.substr(p1, p2-p1); // this is the original document

	p3 = p2 + strlen(wrap_chksum);
	p4 = inptext.find(']', p3);
	if (p4 == std::string::npos) {
		errtext = "Cannot find checksum in file";
		LOG_INFO("%s", errtext.c_str());
		return false;
	}
	inpsum = inptext.substr(p3, p4-p3);
	p4 = inptext.find(wrap_end, p4);
	if (p4 == std::string::npos) {
		errtext = "No end tag in file";
		LOG_INFO("%s", errtext.c_str());
		return false;
	}

	testsum = chksum.scrc16(wtext);

// if failure see if there are CRLF's in the file
	if (testsum != inpsum) {
		LOG_ERROR("%s", "Test for CRLF corrupted file!\n");

		p = inptext.find("\r\n");
		while (p != std::string::npos) {
			inptext.erase(p, 1);
			p = inptext.find("\r\n");
		}

		p1 = inptext.find(wrap_beg);
		if (p1 == std::string::npos) {
			errtext = "Not a wrap file";
			LOG_INFO("%s", errtext.c_str());
			return false;
		}
		p1 = inptext.find(wrap_crlf);
		if (p1 != std::string::npos) { // original text had crlf pairs
			iscrlf = true;
			p1 += strlen(wrap_crlf);
		} else {
			p1 = inptext.find(wrap_lf);
			if (p1 == std::string::npos) {
				errtext = "Invalid file";
				LOG_INFO("%s", errtext.c_str());
				return false;
			}
			p1 += strlen(wrap_lf);
		}

		p2 = inptext.find(wrap_chksum, p1);
		if (p2 == std::string::npos) return false;
		wtext = inptext.substr(p1, p2-p1); // this is the original document

		p3 = p2 + strlen(wrap_chksum);
		p4 = inptext.find(']', p3);
		if (p4 == std::string::npos) {
			errtext = "Cannot find checksum in file";
			LOG_INFO("%s", errtext.c_str());
			return false;
		}
		inpsum = inptext.substr(p3, p4-p3);
		p4 = inptext.find(wrap_end, p4);
		if (p4 == std::string::npos) {
			errtext = "No end tag in file";
			LOG_INFO("%s", errtext.c_str());
			return false;
		}

		testsum = chksum.scrc16(wtext);
	}

	if (inpsum != testsum) {
		errtext = "Checksum failed\n";
		errtext.append(inpsum);
		errtext.append(" in file\n");
		errtext.append(testsum);
		errtext.append(" computed\nFile contents:\n");
		errtext.append(wtext);
		LOG_INFO("%s", errtext.c_str());
		return false;
	}

	size_t p5 = wtext.find(wrap_fn);
	if (p5 != std::string::npos) { //== 0) {
		size_t p = wtext.find("]", p5);
		wrap_outshortname = wtext.substr(p5, p - p5);
		wrap_outshortname.erase(0, strlen(wrap_fn));
		wtext.erase(0,p+1);
// check for protocol abuse
		bool t1 = (wrap_outshortname.find('/') != std::string::npos);
		bool t2 = (wrap_outshortname.find('\\') != std::string::npos);
		bool t3 = (wrap_outshortname == ".");
		bool t4 = (wrap_outshortname == "..");
		bool t5 = (wrap_outshortname.find(":") != std::string::npos);
		bool t6 = wrap_outshortname.empty();
		if (t1 || t2 || t3 || t4 || t5 || t6) {
			errtext = "Filename corrupt, possible protocol abuse\n";
			if (t1) errtext.append("Filename contains '/' character\n");
			if (t2) errtext.append("Filename contains '\\' character\n");
			if (t3) errtext.append("Filename contains leading '.' character\n");
			if (t4) errtext.append("Filename contains leading '..' std::string\n");
			if (t5) errtext.append("Filename contains MS directory specifier\n");
			if (t6) errtext.append("Filename is empty\n");
			LOG_INFO("%s", errtext.c_str());
			return false;
		}
		wrap_outfilename = wrap_foldername;
		wrap_outfilename.append(wrap_outshortname);
	} else {
		p1 = wrap_outfilename.find(WRAP_EXT);
		if (p1 != std::string::npos)
			wrap_outfilename.erase(p1);
	}

	if (iscrlf)
		convert2crlf(wtext);

	if (!decompress_maybe(wtext)) return false;

	if (old_version) strip(wtext);

	return true;
}

void check_version()
{
	size_t p = inptext.find("<flmsg>");
	if (p == std::string::npos) return;
	p += 7;
	size_t p1 = inptext.find("\n", p);
	if (p1 == std::string::npos) return;
	if (inptext.substr(p, p1 - p) < test_version) old_version = true;
}

bool readfile()
{
	old_version = false;
	char cin;
	std::ifstream textfile;
	textfile.open(wrap_inpfilename.c_str(), std::ios::binary);
	if (textfile) {
		inptext.erase();
		while (textfile.get(cin))
			inptext += cin;
		textfile.close();
		check_version();
		return true;
	}
	return false;
}

bool import_wrapfile(	std::string src_fname,
						std::string &extracted_fname,
						std::string &extracted_text)
{
	wrap_inpfilename = src_fname;
	if (readfile())
		if (unwrapfile()) {
			extracted_fname = wrap_outshortname;
			extracted_text = wtext;
			return true;
		}
	extracted_fname = "badfile";
	extracted_text = inptext;
	return false;
}

void xfr_via_arq(std::string basename, std::string inptext)
{
	std::string autosend;
	autosend.assign("[ARQ:fn ").append(basename).append("]").append(inptext);
	send_xml_text(autosend);

	LOG_INFO("Sent %s", basename.c_str());
	static char szDt[200];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	gmtime_r (&tmptr, &sTime);
	if (strftime(szDt, sizeof(szDt), "%Y-%m-%d,%H%M", &sTime) == 0) {
		LOG_ERROR("%s", "strftime conversion error");
		return;
	}
	std::string xfrstr = basename;
	xfrstr.append(",").append(szDt);
	LOG_INFO("transfered %s", xfrstr.c_str());

	std::string xfrs = ICS_dir;
	xfrs.append("auto_sent.csv");
	std::ofstream xfr_rec_file(xfrs.c_str(), std::ios::app);
	if (xfr_rec_file.fail()) {
		LOG_ERROR("Could not open %s", xfrs.c_str());
		return;
	}
	long fsize = xfr_rec_file.tellp();
	if (fsize == 0)
		xfr_rec_file << "FILE_NAME,DATE,GMT" << "\n";
	xfr_rec_file << xfrstr << "\n";
	xfr_rec_file.close();

	return;
}

void xfr_via_socket(std::string basename, std::string inptext)
{
	if (!b_autosend) return xfr_via_arq(basename, inptext);

	bool iscrlf = false;

// checksum & data transfer always based on Unix end-of-line char
	iscrlf = convert2lf(inptext);

	std::string payload = wrap_fn;
	payload.assign(wrap_fn).append(basename).append("]");
	payload.append(inptext);

	check = chksum.scrc16(payload);

// xmlrpc send interface
	std::string autosend;
	autosend.assign("\n\n\n... start\n").append(wrap_beg);
	autosend.append(iscrlf ? wrap_crlf : wrap_lf);
	autosend.append(payload);
	autosend.append(wrap_chksum).append(check).append("]");
	autosend.append(wrap_end).append("\n... end\n\n\n");

	xfr_via_xmlrpc(autosend);
	b_autosend = false;

	LOG_INFO("Sent %s", basename.c_str());
	static char szDt[200];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	gmtime_r (&tmptr, &sTime);
	if (strftime(szDt, sizeof(szDt), "%Y-%m-%d,%H%M", &sTime) == 0) {
		LOG_ERROR("%s", "strftime conversion error");
		return;
	}
	std::string xfrstr = basename;
	xfrstr.append(",").append(szDt);
	LOG_INFO("transfered %s", xfrstr.c_str());

	std::string xfrs = ICS_dir;
	xfrs.append("auto_sent.csv");
	std::ofstream xfr_rec_file(xfrs.c_str(), std::ios::app);
	if (xfr_rec_file.fail()) {
		LOG_ERROR("Could not open %s", xfrs.c_str());
		return;
	}
	long fsize = xfr_rec_file.tellp();
	if (fsize == 0)
		xfr_rec_file << "FILE_NAME,DATE,GMT" << "\n";
	xfr_rec_file << xfrstr << "\n";
	xfr_rec_file.close();

	return;
}

void export_wrapfile(std::string basename, std::string fname, std::string data_text, bool with_ext)
{
	wrap_inpshortname = basename;
	wrap_outfilename = fname;
	inptext = data_text;
	wrapfile(with_ext);
}

