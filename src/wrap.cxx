// WRAP - wrap.cxx
//
// Author: Dave Freese, W1HKJ
//         Stelios Bounanos, M0GLD
//
// Modified from original wrap program source
// removed all image, binary - base64 conversions
// This modified wrap is specifically aimed at wrapping an ICS-213
// text file!
//
// wrap surrounds critical text with markers and adds a checksum to the
// resulting file.  It unwraps a file that has been previously wrapped.  The
// wrap/unwrap is automatic and the user only need to process the file with
// wrap and it will determine whether a wrap or unwrap is needed.  The wrapped
// file can be transmitted via a noisy channel and then tested at the end site
// for file integrity.  It reports on the success or failure with a small
// dialog box.
//
// wrap is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// WRAP is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with the program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

// $Id: main.c 141 2008-07-19 15:59:57Z jessekornblum $


#include "config.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/fl_ask.H>

#ifdef WIN32
#  include <FL/x.H>
#  include <winsock2.h>
#else
#  include <arpa/inet.h>
#endif
#include <FL/filename.H>

#include "base64.h"
#include "crc16.h"
#include "lzma/LzmaLib.h"

using namespace std;

const char *wrap_beg = "[WRAP:beg]";
const char *wrap_end = "[WRAP:end]";
const char *wrap_crlf = "[WRAP:crlf]";
const char *wrap_lf = "[WRAP:lf]";
const char *wrap_chksum = "[WRAP:chksum ";

const char *b64_start = "[b64:start]";
const char *b64_end = "[b64:end]";
const char *wrap_fn = "[WRAP:fn ";

const char *dashes = "\n====================\n";

//const char *binaryfile[] = {
//	".jpg", ".jpeg", ".png", ".gif", ".bmp", ".ico", ".zip", ".gz", ".tgz", ".bz2", 0 };

Ccrc16 chksum;
base64 b64(1); // insert lf for ease of viewing

string inptext = "";
string wtext = "";
string check = "";
string wrap_outfilename = "";
string wrap_inpfilename = "";
string wrap_inpshortname = "";
string wrap_outshortname = "";
string wrap_foldername = "";

string errtext = "";

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
	char *p = strcasestr(s1, s2);
#endif
	return (p != 0);
}

void base64encode()
{
	string outtext;
	outtext = b64.encode(inptext);
	inptext = b64_start;
	inptext.append(outtext);
	inptext.append(b64_end);
}

void convert2crlf(string &s)
{
	if (s.find('\r') != string::npos) return;
	size_t p = s.find('\n');
	while (p != string::npos) {
		s.replace(p, 1, "\r\n");
		p = s.find('\n', p + 2);
	}
}

void convert2lf(string &s)
{
	size_t p = s.find("\r\n");

	while (p != string::npos) {
		s.replace(p, 2, "\n");
		p = s.find("\r\n");
	}
}

#define LZMA_STR "\1LZMA"

void compress_maybe(string& input, bool& binary)
{
	// allocate 105% of the original size for the output buffer
	size_t outlen = (size_t)ceil(input.length() * 1.05);
	unsigned char* buf = new unsigned char[outlen];

	size_t plen = LZMA_PROPS_SIZE;
	unsigned char outprops[LZMA_PROPS_SIZE];
	uint32_t origlen = htonl(input.length());

	int r;
	if ((r = LzmaCompress(buf, &outlen, (const unsigned char*)input.data(), input.length(),
			      outprops, &plen, 9, 0, -1, -1, -1, -1, -1)) != SZ_OK)
		;
//		cerr << "E: LzmaCompress failed with error code " << r << '\n';
	else if ((binary && outlen < input.length()) || (!binary && outlen * 1.37 < input.length())) {
//		cerr << "I: compress: in=" << input.length() << " out=" << outlen << '\n';
		binary = true;
		// write LZMA_STR + original size (in network byte order) + props + data
		input.reserve(strlen(LZMA_STR) + sizeof(origlen) + sizeof(outprops) + outlen);
		input.assign(LZMA_STR);
		input.append((const char*)&origlen, sizeof(origlen));
		input.append((const char*)&outprops, sizeof(outprops));
		input.append((const char*)buf, outlen);
	}

	delete [] buf;
}

void decompress_maybe(string& input)
{
	// input is LZMA_STR + original size (in network byte order) + props + data
	if (input.find(LZMA_STR))
		return;

	const char* in = input.data();
	size_t outlen = ntohl(*reinterpret_cast<const uint32_t*>(in + strlen(LZMA_STR)));
	// if (outlen > 1 << 25) {
	// 	cerr << "W: refusing to decompress data (> 32MiB)\n";
	// 	return;
	// }
	unsigned char* buf = new unsigned char[outlen];

	unsigned char inprops[LZMA_PROPS_SIZE];
	memcpy(inprops, in + strlen(LZMA_STR) + sizeof(uint32_t), LZMA_PROPS_SIZE);

	size_t inlen = input.length() - strlen(LZMA_STR) - sizeof(uint32_t) - LZMA_PROPS_SIZE;

	int r;
	if ((r = LzmaUncompress(buf, &outlen, (const unsigned char*)in + input.length() - inlen, &inlen,
				inprops, LZMA_PROPS_SIZE)) != SZ_OK)
		;
//		cerr << "E: LzmaUncompress failed with error code " << r << '\n';
	else {
//		cerr << "I: decompress: in=" << inlen << " out=" << outlen << '\n';
		input.reserve(outlen);
		input.assign((const char*)buf, outlen);
	}

	delete [] buf;
}

bool wrapfile()//bool isbinary)
{
	bool iscrlf = false;
	bool isbinary = false;
	wrap_outfilename.append(".wrap");
	wrap_outshortname = fl_filename_name(wrap_outfilename.c_str());

	compress_maybe(inptext, isbinary);
	if (isbinary)
		base64encode();
	else {
		if (inptext.find("\r\n") != string::npos) {
			iscrlf = true;
			convert2lf(inptext); // checksum & data transfer always based on Unix end-of-line char
		}
	}

	string originalfilename = wrap_fn;
	originalfilename.append(wrap_inpshortname);
	originalfilename += ']';
		
	inptext.insert(0, originalfilename);
	
	check = chksum.scrc16(inptext);		

	ofstream wrapstream(wrap_outfilename.c_str(), ios::binary);
	if (wrapstream) {
		wrapstream << wrap_beg << (iscrlf ? wrap_crlf : wrap_lf) << inptext << wrap_chksum << check << ']' << wrap_end;
		wrapstream.close();
	} else {
		errtext = "Cannot open output file";
		return false;
	}
	return true;
}


// all of this crlf checking is necessary because the original file may have had crlf pairs
// or the OS save may have inserted them into the text (MSDOS) har!

bool unwrapfile()
{
	size_t p1, p2, p3, p4;
	string testsum;
	string inpsum;
	bool iscrlf = false;
	
	p1 = inptext.find(wrap_beg);
	if (p1 == string::npos) {
		errtext = "Not a wrap file";
		return false;
	}
	p1 = inptext.find(wrap_crlf);
	if (p1 != string::npos) { // original text had crlf pairs
		iscrlf = true;
		p1 += strlen(wrap_crlf);
	} else {
		p1 = inptext.find(wrap_lf);
		if (p1 == string::npos) {
			errtext = "Invalid file";
			return false;
		}
		p1 += strlen(wrap_lf);
	}

	p2 = inptext.find(wrap_chksum, p1);
	if (p2 == string::npos) return false;
	wtext = inptext.substr(p1, p2-p1); // this is the original document
	
	p3 = p2 + strlen(wrap_chksum);
	p4 = inptext.find(']', p3);
	if (p4 == string::npos) {
		errtext = "Cannot find checksum in file";
		return false;
	}
	inpsum = inptext.substr(p3, p4-p3);
	p4 = inptext.find(wrap_end, p4);
	if (p4 == string::npos) {
		errtext = "No end tag in file";
		return false;
	}
		
	if (wtext.find("\r\n") != string::npos)
		convert2lf(wtext);
		
	testsum = chksum.scrc16(wtext);
		
	if (inpsum != testsum) {
		errtext = "Checksum failed\n";
		errtext.append(inpsum);
		errtext.append(" in file\n");
		errtext.append(testsum);
		errtext.append(" computed");
		return false;
	}

	if (wtext.find(wrap_fn) == 0) {
		size_t p = wtext.find(']');
		wrap_outshortname = wtext.substr(0, p);
		wrap_outshortname.erase(0, strlen(wrap_fn));
		wtext.erase(0,p+1);
		wrap_outfilename = wrap_foldername;
		wrap_outfilename.append(wrap_outshortname);
	} else {
		p1 = wrap_outfilename.find(".wrap");
		if (p1 != string::npos)
			wrap_outfilename.erase(p1);
	}
	
	if (iscrlf)
		convert2crlf(wtext);
		
	p1 = wtext.find(b64_start);
	if (p1 != string::npos) {
		p1 += strlen(b64_start);
		p2 = wtext.find(b64_end, p1);
		if (p2 == string::npos) {
			errtext = "Base 64 decode failed";
			return false;
		}
		wtext = b64.decode(wtext.substr(p1, p2-p1));
		decompress_maybe(wtext);
	}
		
	ofstream tfile(wrap_outfilename.c_str(), ios::binary);
	if (tfile) {
		tfile << wtext;
		tfile.close();
	} else {
		errtext = "Cannot open output file";
		return false;
	}
	return true;
}

bool readfile()
{

	char cin;
	ifstream textfile;
	textfile.open(wrap_inpfilename.c_str(), ios::binary);
	if (textfile) {
		inptext.erase();
		while (textfile.get(cin))
			inptext += cin;
			textfile.close();
		}

	return true;
}

bool import_wrapfile(	string src_fname,
						string &extracted_fname,
						string &extracted_text)
{
	wrap_inpfilename = src_fname;
	if (readfile())
		if (unwrapfile()) {
			extracted_fname = wrap_outshortname;
			extracted_text = wtext;
			return true;
		}
	extracted_fname.clear();
	extracted_text.clear();
	return false;
}

void export_wrapfile(string basename, string fname, string data_text)
{
	wrap_inpshortname = basename;
	wrap_outfilename = fname;
	inptext = data_text;
	wrapfile();
}
