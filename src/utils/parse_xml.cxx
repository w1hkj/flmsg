// =====================================================================
//
// parse_xml.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2010
//
// Qforms import / export
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  It is
// copyright under the GNU General Public License.
//
// You should have received a copy of the GNU General Public License
// along with the program; if not, write to the Free Software
// Foundation, Inc.
// 59 Temple Place, Suite 330
// Boston, MA  02111-1307 USA
//
// =====================================================================

//########################################################################
//
//  Qforms import / export
//
//  copywrite David Freese, w1hkj@w1hkj.com
//
//########################################################################

#include "config.h"
#include "flmsg_config.h"

#include <fstream>
#include <string>
#include <list>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

#include <FL/filename.H>

#include "parse_xml.h"
#include "fileselect.h"
#include "flmsg_dialog.h"
#include "flmsg.h"
#include "config.h"
#include "status.h"

using namespace std;

//======================================================================

string strXML;

//======================================================================

void trim (string &s)
{
	size_t end = s.length();
	while (end && (s[end-1] == ' ' || s[end-1] == '\n')) {
		s.erase(end-1, 1);
		end = s.length();
	}
	while (s.length() && (s[0] == ' ' || s[0] == '\n')) {
		s.erase(0,1);
	}
}

struct xmlspec { const char *c; const char *str; };

xmlspec xmlspecial[] = {
{"&",  "&amp;" }, // must be first substitution
{"\'", "&apos;"},
{"\"", "&quot;"},
{ 0, 0 }};

void to_xml(string &s)
{
	size_t pos;
	for (int i = 0; i < 3; i++) {
		pos = 0;
		while ((pos = s.find(xmlspecial[i].c, pos)) != string::npos) {
			s.replace(pos, 1, xmlspecial[i].str);
			pos += strlen(xmlspecial[i].str);
		}
	}
}

void fm_xml(string &s)
{
	size_t pos = 0;
	for (int i = 0; i < 3; i++) {
		pos = 0;
		while ((pos = s.find(xmlspecial[i].str, pos)) != string::npos) {
			s.replace(pos, strlen(xmlspecial[i].str), xmlspecial[i].c);
			pos += strlen(xmlspecial[i].c);
		}
	}
}

xmlspec htmlspecial[] = {
{"&",  "&amp;" }, // must be first substitution
{"\"", "&quot;"},
{ 0, 0 }};

void to_html(string &s)
{
	size_t pos;
	for (int i = 0; i < 2; i++) {
		pos = 0;
		while ((pos = s.find(htmlspecial[i].c, pos)) != string::npos) {
			s.replace(pos, 1, htmlspecial[i].str);
			pos += strlen(htmlspecial[i].str);
		}
	}
}

void fm_html(string &s)
{
	size_t pos = 0;
	for (int i = 0; i < 2; i++) {
		pos = 0;
		while ((pos = s.find(htmlspecial[i].str, pos)) != string::npos) {
			s.replace(pos, strlen(htmlspecial[i].str), htmlspecial[i].c);
			pos += strlen(htmlspecial[i].c);
		}
	}
}

//=====================================================================
//generic xml tag parse functions

size_t tag_end(size_t p0, string xml)
{
	size_t p1, p2, p3;
	p1 = p0;
	string strtag = "</";
	p2 = xml.find(">", p0);
	p3 = xml.find(" ", p0);
	if (p2 == string::npos) {
		return p2;
	}
	if (p3 < p2)
		p2 = p3;
	strtag.append(xml.substr(p1 + 1, p2 - p1 - 1));
	strtag.append(">");
	p3 = xml.find(strtag, p1);
	return p3;
}

size_t next_tag(size_t p0, string xml)
{
	p0 = xml.find("<", p0);
	return p0;
}

string get_element(size_t p0, string xml)
{
	size_t p1 = xml.find(">",p0),
		   p2 = tag_end(p0, xml);
	if (p1 == string::npos || p2 == string::npos)
		return "";
	p1++; p2--;
	while (p1 < p2 && xml[p1] == ' ') p1++; // skip leading spaces
	while (p1 < p2 && xml[p2] == ' ') p2--; // skip trailing spaces
	return xml.substr(p1, p2 - p1 + 1);
}

int get_int(size_t p0, string xml)
{
	string stemp = get_element(p0, xml);
	if (stemp.length() == 0)
		return 0;
	return atoi(stemp.c_str());
}

float get_float(size_t p0, string xml)
{
	string stemp = get_element(p0, xml);
	if (stemp.length() == 0)
		return 0;
	return atof(stemp.c_str());
}

bool get_bool( size_t p0, string xml)
{
	string stemp = get_element(p0, xml);
	if (stemp.length() == 0)
		return false;
	if (strcasecmp(stemp.c_str(), "true") == 0)
		return true;
	return false;
}

char get_byte(size_t p0, string xml)
{
	unsigned int val;
	if (sscanf( get_element(p0, xml).c_str(), "%x", &val ) != 1)
		return 0;
	return (val & 0xFF);
}

string get_bytes(size_t p0, string xml)
{
	unsigned int val;
	size_t space;
	string stemp = get_element(p0, xml);
	string s;
	while ( stemp.length() ) {
		if (sscanf( stemp.c_str(), "%x", &val) != 1) {
			s = "";
			return s;
		}
		s += (char)(val & 0xFF);
		space = stemp.find(" ");
		if (space == string::npos) break;
		stemp.erase(0, space + 1);
	}
	return s;
}

bool is_int(size_t p0, int &i, string xml)
{
	if (xml.find("<INT", p0) != p0)
		return false;
	i = get_int(p0, xml);
	return true;
}

bool is_byte(size_t p0, char &ch, string xml)
{
	if (xml.find("<BYTE", p0) != p0)
		return false;
	ch = get_byte(p0, xml);
	return true;
}

bool is_bytes( size_t p0, string &s, string xml )
{
	if (xml.find ("<BYTES", p0) != p0)
		return false;
	s = get_bytes(p0, xml);
	return true;
}

bool is_string( size_t p0, string &s, string xml )
{
	if (xml.find("<STRING", p0) != p0)
		return false;
	s = get_element(p0, xml);
	return true;
}

bool is_symbol( size_t p0, string &s, string xml)
{
	if (xml.find("<SYMBOL", p0) != p0)
		return false;
	s = get_element(p0, xml);
	return true;
}

bool tag_is(size_t &p0, string tag, string xml)
{
	return (xml.find(tag, p0) == p0);
}

//======================================================================
// ICS213 xml import/export

void parse_ics_message(size_t &, string);
void parse_ics_version(size_t &, string);
void parse_ics_id(size_t &, string);
void parse_ics_date(size_t &, string);
void parse_ics_name(size_t &, string);
void parse_ics_time(size_t &, string);
void parse_ics_exercise(size_t &, string);
void parse_ics_recipient(size_t &, string);
void parse_ics_sender(size_t &, string);
void parse_ics_position(size_t &, string);
void parse_ics_subject(size_t &, string);
void parse_ics_body(size_t &, string);
void parse_ics_para(size_t &, string);
void parse_ics_reply(size_t &, string);
void parse_ics_sender(size_t &, string);
void parse_ics_signature(size_t &, string);
void parse_ics_header(size_t &, string);

TAGS ICS_tags[] = {
	{"<message",	parse_ics_message},
	{"<version", 	parse_ics_version},
	{"<id",			parse_ics_id},
	{"<date",		parse_ics_date},
	{"<time",		parse_ics_time},
	{"<exercise",	parse_ics_exercise},
	{"<recipient",	parse_ics_recipient},
	{"<sender",		parse_ics_sender},
	{"<name",		parse_ics_name},
	{"<position",	parse_ics_position},
	{"<subject", 	parse_ics_subject},
	{"<body",		parse_ics_body},
	{"<para",		parse_ics_para},
	{"<reply",		parse_ics_reply},
	{"<signature",	parse_ics_signature},
	{"<?",			parse_ics_header},
	{0, 0}
};

//recipient
string ics_xml_to;
string ics_xml_p1;
//sender
string ics_xml_fm;
string ics_xml_p2;
//subject date time
string ics_xml_subj;
string ics_xml_d1;
string ics_xml_t1;
//message body
string ics_xml_msg;
//preparer
string xml_s1;
string xml_p3;
//reply
string xml_reply;
string ics_xml_d2;
string ics_xml_t2;
string ics_xml_s2;
string ics_xml_p4;

enum PARSE_ICS_MODE {HICS_TO, HICS_FM, HICS_RECIP, HICS_SENDER, HICS_SUBJ, HICS_MSG, HICS_PREP, HICS_REPLY} ics_pmode;


void parse_ics_name(size_t &p0, string xml)
{
string contents = get_element(p0, xml).c_str();
	switch (ics_pmode) {
		case HICS_TO:
		case HICS_RECIP: ics_xml_to = contents; break;
		case HICS_FM:
		case HICS_SENDER: ics_xml_fm = contents; break;
		case HICS_MSG: xml_s1 = contents; break;
		case HICS_REPLY: ics_xml_s2 = contents; break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}


void parse_ics_position(size_t &p0, string xml)
{
string contents = get_element(p0, xml).c_str();
	switch (ics_pmode) {
		case HICS_TO:
		case HICS_RECIP: ics_xml_p1 = contents; break;
		case HICS_FM:
		case HICS_SENDER: ics_xml_p2 = contents; break;
		case HICS_MSG: xml_p3 = contents; break;
		case HICS_REPLY: ics_xml_p4 = contents; break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_subject(size_t &p0, string xml)
{
	ics_xml_subj = get_element(p0, xml).c_str();
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_para(size_t &p0, string xml)
{
string contents = get_element(p0, xml).c_str();
	switch (ics_pmode) {
		case HICS_MSG:
			fm_xml(contents);
			ics_xml_msg.append(contents).append("\n");
			break;
		case HICS_REPLY:
			fm_xml(contents);
			xml_reply.append(contents).append("\n");
			break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_date(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (ics_pmode) {
		case HICS_TO:
		case HICS_FM:
		case HICS_SENDER:
		case HICS_MSG:
		case HICS_RECIP: ics_xml_d1 = contents; break;
		case HICS_REPLY: ics_xml_d2 =contents; break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_time(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (ics_pmode) {
		case HICS_TO:
		case HICS_FM:
		case HICS_SENDER:
		case HICS_RECIP: ics_xml_t1 = contents; break;
		case HICS_REPLY: ics_xml_t2 =contents; break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_exercise(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_recipient(size_t &p0, string xml)
{
	ics_pmode = HICS_RECIP;
	string recip = get_element(p0, xml);
	parse_ics(recip);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_sender(size_t &p0, string xml)
{
	ics_pmode = HICS_SENDER;
	string sender = get_element(p0, xml);
	parse_ics(sender);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_signature(size_t &p0, string xml)
{
	string sign = get_element(p0, xml);
	parse_ics(sign);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_body(size_t &p0, string xml)
{
	if (ics_pmode == HICS_TO || ics_pmode == HICS_FM || ics_pmode == HICS_RECIP || ics_pmode == HICS_SENDER)
		ics_pmode = HICS_MSG;
	string body = get_element(p0, xml);
	parse_ics(body);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_version(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_id(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_reply(size_t &p0, string xml)
{
	ics_pmode = HICS_REPLY;
	string reply = get_element(p0, xml);
	parse_ics(reply);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_message(size_t &p0, string xml)
{
	ics_pmode = HICS_TO;
	string message;
	message = get_element(p0, xml);
	parse_ics(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_discard(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_header(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

// recursive parser
void parse_ics( string xml )
{
	size_t p0;
	TAGS *pValid;

	p0 = next_tag(0, xml); // find the 1st tag
	while (p0 != string::npos) {
		pValid = ICS_tags;
		while (pValid->tag) {
			if (xml.find(pValid->tag, p0) == p0) {
					break;
			}
				pValid++;
		}
		if (pValid->fp)
			(pValid->fp)(p0, xml);
		else
			p0 = next_tag(p0 + 1, xml); // find the next tag
	}
}

void clear_ics_xml()
{
//recipient
	ics_xml_to.clear();
	ics_xml_p1.clear();
//sender
	ics_xml_fm.clear();
	ics_xml_p2.clear();
//subject date time
	ics_xml_subj.clear();
	ics_xml_d1.clear();
	ics_xml_t1.clear();
//message body
	ics_xml_msg.clear();
//preparer
	xml_s1.clear();
	xml_p3.clear();
//reply
	xml_reply.clear();
	ics_xml_d2.clear();
	ics_xml_t2.clear();
	ics_xml_s2.clear();
	ics_xml_p4.clear();
}

void transfer_ics_fields()
{
	clear_fields();
	txt_213_to->value(ics_xml_to.c_str());
	txt_213_p1->value(ics_xml_p1.c_str());
	txt_213_fm->value(ics_xml_fm.c_str());
	txt_213_p2->value(ics_xml_p2.c_str());
	txt_213_subj->value(ics_xml_subj.c_str());
	txt_213_d1->value(ics_xml_d1.c_str());
	txt_213_t1->value(ics_xml_t1.c_str());
	txt_213_msg->addstr(ics_xml_msg.c_str());
	txt_213_s1->value(xml_s1.c_str());
	txt_213_p3->value(xml_p3.c_str());
	txt_213_reply->addstr(xml_reply.c_str());
	txt_213_s2->value(ics_xml_s2.c_str());
	txt_213_d2->value(ics_xml_d2.c_str());
	txt_213_t2->value(ics_xml_t2.c_str());
	txt_213_p4->value(ics_xml_p4.c_str());
	update_fields();
	def_213_filename = ICS_msg_dir;
	def_213_filename.append("qform");
	def_213_filename.append(DATAFILE_EXT);
	show_filename(def_213_filename);
}

bool qform_ics_import(string fname)
{
	char *buff;
	FILE *xmlfile;
	size_t filesize;
	int retval;

	xmlfile = fopen (fname.c_str(), "r");
	if (!xmlfile)
		return false;
// determine its size for buffer creation
	fseek (xmlfile, 0, SEEK_END);
	filesize = ftell (xmlfile);
	buff = new char[filesize + 1];
	memset(buff, 0, filesize + 1);
// read the entire file into the buffer
	fseek (xmlfile, 0, SEEK_SET);
	retval = fread (buff, filesize, 1, xmlfile);
	fclose (xmlfile);

	ics_pmode = HICS_TO;
	clear_ics_xml();

	parse_ics(buff);
	transfer_ics_fields();

	delete [] buff;
	return true;
}

//======================================================================
// export ics
//======================================================================

const char *export_template = "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\
<?xml-stylesheet type=\"text/xsl\" href=\"ICS213.XSL\"?>\
<message>\
<form>ICS-213</form>\
<version></version>\
<id></id>\
<date>?D1?</date>\
<time>?T1?</time>\
<exercise>no</exercise>\
<recipient>\
<name>?S1?</name>\
<position>?P1?</position>\
</recipient>\
<sender>\
<name>?S2?</name>\
<position>?P2?</position>\
</sender>\
<subject>?SB?</subject>\
<body>?MG?</body>\
<signature>\
<name>?S3?</name>\
<position>?P3?</position>\
</signature>\
<reply>\
<id></id>\
<date>?D2?</date>\
<time>?T2?</time>\
<body>?RP?</body>\
<signature>\
<name>?S4?</name>\
<position>?P4?</position>\
</signature>\
</reply>\
</message>\
";

const char *export_line = "<para>LINE</para>";

void qform_ics_export(string fname)
{
	FILE *xmlfile;
	size_t pos = 0;
	string qexport = export_template;
	string lines;

	update_fields();
	qexport.replace( qexport.find("?S1?"), 4, fields[0].f_data);
	qexport.replace( qexport.find("?P1?"), 4, fields[1].f_data);
	qexport.replace( qexport.find("?S2?"), 4, fields[2].f_data);
	qexport.replace( qexport.find("?P2?"), 4, fields[3].f_data);
	qexport.replace( qexport.find("?D1?"), 4, fields[4].f_data);
	qexport.replace( qexport.find("?T1?"), 4, fields[5].f_data);
	qexport.replace( qexport.find("?SB?"), 4, fields[6].f_data);
	qexport.replace( qexport.find("?S3?"), 4, fields[7].f_data);
	qexport.replace( qexport.find("?P3?"), 4, fields[8].f_data);
	qexport.replace( qexport.find("?S4?"), 4, fields[9].f_data);
	qexport.replace( qexport.find("?P4?"), 4, fields[10].f_data);
	qexport.replace( qexport.find("?D2?"), 4, fields[11].f_data);
	qexport.replace( qexport.find("?T2?"), 4, fields[12].f_data);

	lines = "<para>";
	lines.append(fields[13].f_data);
	lines.append("</para>");
	while ((pos = lines.find("\n")) != string::npos)
		lines.replace(pos, 1, "</para><para>");
	to_xml(lines);
	qexport.replace( qexport.find("?MG?"), 4, lines);

	lines = "<para>";
	lines.append(fields[14].f_data);
	lines.append("</para>");
	while ((pos = lines.find("\n")) != string::npos)
		lines.replace(pos, 1, "</para><para>");
	to_xml(lines);
	qexport.replace( qexport.find("?RP?"), 4, lines);

	xmlfile = fopen(fname.c_str(), "w");
	if (!xmlfile) return;
	fwrite( qexport.c_str(), qexport.length(), 1, xmlfile );
	fclose(xmlfile);
}

//======================================================================
// Radiogram xml import

void parse_rg_header(size_t &, string);
void parse_rg_message(size_t &, string);
void parse_rg_version(size_t &, string);
void parse_rg_id(size_t &, string);
void parse_rg_date(size_t &, string);
void parse_rg_time(size_t &, string);
void parse_rg_name(size_t &, string);
void parse_rg_exercise(size_t &, string);
void parse_rg_precedance(size_t &, string);
void parse_rg_handling(size_t &, string);
void parse_rg_arl(size_t &, string);
void parse_rg_check(size_t &, string);
void parse_rg_filed(size_t &, string);
void parse_rg_origin(size_t &, string);
void parse_rg_station(size_t &, string);
void parse_rg_place(size_t &, string);
void parse_rg_phone(size_t &, string);
void parse_rg_address(size_t &, string);
void parse_rg_line(size_t &, string);
void parse_rg_receivedat(size_t &, string);
void parse_rg_body(size_t &, string);
void parse_rg_para(size_t &, string);
void parse_rg_receivedfrom(size_t &, string);
void parse_rg_sentto(size_t &, string);
 
TAGS RG_tags[] = {
	{"<?",			parse_rg_header},
	{"<message",	parse_rg_message},
	{"<version", 	parse_rg_version},
	{"<id",			parse_rg_id},
	{"<exercise",	parse_rg_exercise},
	{"<precedance",	parse_rg_precedance},
	{"<handling",	parse_rg_handling},
	{"<arl",		parse_rg_arl},
	{"<check",		parse_rg_check},
	{"<filed",		parse_rg_filed},
	{"<date",		parse_rg_date},
	{"<time",		parse_rg_time},
	{"<origin",		parse_rg_origin},
	{"<station",	parse_rg_station},
	{"<place",		parse_rg_place},
	{"<phone",		parse_rg_phone},
	{"<address",	parse_rg_address},
	{"<line",		parse_rg_line},
	{"<receivedat",	parse_rg_receivedat},
	{"<body",		parse_rg_body},
	{"<para",		parse_rg_para},
	{"<receivedfrom",parse_rg_receivedfrom},
	{"<name",		parse_rg_name},
	{"<sentto",		parse_rg_sentto},
	{0, 0}
};

string rg_xml_nbr;
string rg_xml_prec;
string rg_xml_exer;
string rg_xml_hx;
string rg_xml_d1;
string rg_xml_t1;
string rg_xml_dt2;
string rg_xml_dt3;
string rg_xml_to;
string rg_xml_rx;
string rg_xml_phone;
string rg_xml_msg;
string rg_xml_station;
string rg_xml_place;
string rg_xml_signed;
string rg_xml_sent_to;
string rg_xml_check;
string rg_xml_arl;

enum PARSE_RG_MODE {FILED, ORIGIN, ADDRESS, RECEIVEDAT, BODY, RECEIVEDFROM, SENTO} rg_pmode;

void parse_rg_header(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_message(size_t &p0, string xml)
{
	rg_pmode = FILED;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_version(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_id(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	rg_xml_nbr = contents;
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_date(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (rg_pmode) {
		case FILED:
			rg_xml_d1 = contents;
			break;
		case RECEIVEDFROM:
			rg_xml_dt2 = contents;
			break;
		case SENTO:
			rg_xml_dt3 = contents;
			break;
		default : 
			break;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_time(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (rg_pmode) {
		case FILED:
			rg_xml_t1 = contents;
			break;
		default : 
			break;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_name(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (rg_pmode) {
		case RECEIVEDFROM:
			rg_xml_signed = contents;
			break;
		case SENTO:
			rg_xml_sent_to = contents;
			break;
		case FILED:
		case ORIGIN:
		case ADDRESS:
		case BODY:
		default : 
			break;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_exercise(size_t &p0, string xml)
{
	rg_xml_exer = get_element(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_precedance(size_t &p0, string xml)
{
	rg_xml_prec = get_element(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_handling(size_t &p0, string xml)
{
	rg_xml_hx = get_element(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_arl(size_t &p0, string xml)
{
	rg_xml_arl = get_element(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_check(size_t &p0, string xml)
{
	rg_xml_check = get_element(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_filed(size_t &p0, string xml)
{
	rg_pmode = FILED;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_origin(size_t &p0, string xml)
{
	rg_pmode = ORIGIN;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_station(size_t &p0, string xml)
{
	rg_xml_station = get_element(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_place(size_t &p0, string xml)
{
	rg_xml_place = get_element(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_phone(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	rg_xml_phone = contents;
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_address(size_t &p0, string xml)
{
	rg_pmode = ADDRESS;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_line(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (rg_pmode) {
		case RECEIVEDAT:
			fm_xml(contents);
			rg_xml_rx.append(contents).append("\n");
			break;
		case ADDRESS:
			fm_xml(contents);
			rg_xml_to.append(contents).append("\n");
			break;
		case BODY:
			fm_xml(contents);
			rg_xml_msg.append(contents).append("\n");
			break;
		case FILED:
		case RECEIVEDFROM:
		case SENTO:
		case ORIGIN:
		default : 
			break;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_receivedat(size_t &p0, string xml)
{
	rg_pmode = RECEIVEDAT;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_body(size_t &p0, string xml)
{
	rg_pmode = BODY;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_para(size_t &p0, string xml)
{
	string contents = get_element(p0, xml);
	switch (rg_pmode) {
		case RECEIVEDAT:
			fm_xml(contents);
			rg_xml_rx.append(contents).append("\n");
			break;
		case ADDRESS:
			fm_xml(contents);
			rg_xml_to.append(contents).append("\n");
			break;
		case BODY:
			fm_xml(contents);
			rg_xml_msg.append(contents).append("\n");
			break;
		case FILED:
		case RECEIVEDFROM:
		case SENTO:
		case ORIGIN:
		default : 
			break;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_receivedfrom(size_t &p0, string xml)
{
	rg_pmode = RECEIVEDFROM;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_rg_sentto(size_t &p0, string xml)
{
	rg_pmode = SENTO;
	string message;
	message = get_element(p0, xml);
	parse_rg(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void clear_rg_xml()
{
	rg_xml_nbr.clear();
	rg_xml_prec.clear();
	rg_xml_exer.clear();
	rg_xml_hx.clear();
	rg_xml_d1.clear();
	rg_xml_t1.clear();
	rg_xml_dt2.clear();
	rg_xml_dt3.clear();
	rg_xml_to.clear();
	rg_xml_rx.clear();
	rg_xml_phone.clear();
	rg_xml_msg.clear();
	rg_xml_station.clear();
	rg_xml_place.clear();
	rg_xml_signed.clear();
	rg_xml_sent_to.clear();
	rg_xml_check.clear();
	rg_xml_arl.clear();
}

void transfer_rgfields()
{
	clear_rgfields();

	txt_rg_nbr->value(rg_xml_nbr.c_str());

	txt_rg_hx->value(rg_xml_hx.c_str());
	txt_rg_d1->value(rg_xml_d1.c_str());
	txt_rg_t1->value(rg_xml_t1.c_str());
	txt_rg_dt2->value(rg_xml_dt2.c_str());
	txt_rg_dt3->value(rg_xml_dt3.c_str());

	trim(rg_xml_to);
	txt_rg_to->value(rg_xml_to.c_str());
	txt_rg_phone->value(rg_xml_phone.c_str());

	txt_rg_msg->clear();
	trim(rg_xml_msg);
	txt_rg_msg->addstr(rg_xml_msg.c_str());

	txt_rg_station->value(rg_xml_station.c_str());
	txt_rg_place->value(rg_xml_place.c_str());
	txt_rg_sig->value(rg_xml_signed.c_str());
	txt_rg_sent_to->value(rg_xml_sent_to.c_str());
	if (rg_xml_arl.empty())
		txt_rg_check->value(rg_xml_check.c_str());
	else {
		string ck = "ARL ";
		ck.append(rg_xml_check);
		txt_rg_check->value(ck.c_str());
	}

	if (rg_xml_exer == "yes") {
		if (rg_xml_prec.find("ROUTINE") != string::npos) sel_rg_prec->value(4);
		else if (rg_xml_prec.find("WELFARE") != string::npos) sel_rg_prec->value(5);
		else if (rg_xml_prec.find("PRIORITY") != string::npos) sel_rg_prec->value(6);
		else if (rg_xml_prec.find("EMERGENCY") != string::npos) sel_rg_prec->value(7);
		else sel_rg_prec->value(0);
	} else {
		if (rg_xml_prec.find("ROUTINE") != string::npos) sel_rg_prec->value(0);
		else if (rg_xml_prec.find("WELFARE") != string::npos) sel_rg_prec->value(1);
		else if (rg_xml_prec.find("PRIORITY") != string::npos) sel_rg_prec->value(2);
		else if (rg_xml_prec.find("EMERGENCY") != string::npos) sel_rg_prec->value(3);
		else sel_rg_prec->value(0);
	}
	
	update_fields();
	def_213_filename = ICS_msg_dir;
	def_213_filename.append("qform");
	def_213_filename.append(RGFILE_EXT);
	show_filename(def_213_filename);
}

void parse_rg(string xml)
{
	size_t p0;
	TAGS *pValid;

	p0 = next_tag(0, xml); // find the 1st tag
	while (p0 != string::npos) {
		pValid = RG_tags;
		while (pValid->tag) {
			if (xml.find(pValid->tag, p0) == p0) {
					break;
			}
				pValid++;
		}
		if (pValid->fp)
			(pValid->fp)(p0, xml);
		else
			p0 = next_tag(p0 + 1, xml); // find the next tag
	}
}

bool qform_rg_import(string fname)
{
	char *buff;
	FILE *xmlfile;
	size_t filesize;
	int retval;

	xmlfile = fopen (fname.c_str(), "r");
	if (!xmlfile)
		return false;
// determine its size for buffer creation
	fseek (xmlfile, 0, SEEK_END);
	filesize = ftell (xmlfile);
	buff = new char[filesize + 1];
	memset(buff, 0, filesize + 1);
// read the entire file into the buffer
	fseek (xmlfile, 0, SEEK_SET);
	retval = fread (buff, filesize, 1, xmlfile);
	fclose (xmlfile);

	rg_pmode = FILED;
	clear_rg_xml();

	parse_rg(buff);
	transfer_rgfields();

	delete [] buff;
	return true;
}

// export Radiogram

const char rg_export_template[] =
"\
<?xml version=\"1.0\" encoding=\"UTF-8\"?><?xml-stylesheet type=\"text/xsl\" href=\"Radiogram.XSL\"?>\n\
<message>\n\
<form>Radiogram</form>\n\
<version>1.5.1.0</version>\n\
<exercise>?TEST?</exercise>\n\
<id>?ID?</id>\n\
<precedance>?PR?</precedance>\n\
<handling>?HX?</handling>\n\
<arl>?ARL?</arl>\n\
<check>?CK?</check>\n\
<filed>\n\
<date>?D1?</date>\n\
<time>?T1?</time>\n\
</filed>\n\
<origin>\n\
<station>\n\
?STA?\n\
</station>\n\
<place>\n\
?PL?\n\
</place>\n\
</origin>\n\
<phone>?PH?</phone>\n\
<address>\n\
?AD?\n\
</address>\n\
<receivedat>\n\
?RA?\n\
</receivedat>\n\
<body>\n\
?BD?\n\
</body>\n\
<receivedfrom>\n\
<name>?NM?</name>\n\
<date>?D2?</date>\n\
<time>?T2?</time>\n\
</receivedfrom>\n\
<sentto>\n\
<name>\n\
?ST?\n\
</name>\n\
<date>?D3?</date>\n\
<time>?T3?</time>\n\
</sentto>\n\
</message>\n";

void xml_lines(string &s, const char *ln)
{
	string sln = "</";
	sln.append(ln).append(">\n<").append(ln).append(">");
	s = string("<").append(ln).append(">").append(s).append("</").append(ln).append(">");
	size_t pos = 0;
	while ((pos = s.find("\n", pos)) != string::npos) {
		s.replace(pos, 1, sln);
		pos += 14;
	}
}

void qform_rg_export(string fname)
{
	FILE *xmlfile;
	string qexport = rg_export_template;
	string lines;
	int nbr;

	update_rgfields();

	qexport.replace( qexport.find("?ID?"), 4, rgfields[0].f_data);
	sscanf(rgfields[1].f_data.c_str(), "%d", &nbr);
	lines = s_prec[nbr];
	if (lines.find("TEST ") != string::npos) {
		qexport.replace( qexport.find("?TEST?"), 6, "yes");
		lines.erase(0, 5);
	} else
		qexport.replace( qexport.find("?TEST?"), 6, "no");
	qexport.replace( qexport.find("?PR?"), 4, lines);

	qexport.replace( qexport.find("?HX?"), 4, rgfields[2].f_data);
	qexport.replace( qexport.find("?D1?"), 4, rgfields[3].f_data);
	qexport.replace( qexport.find("?T1?"), 4, rgfields[4].f_data);

	lines = rgfields[5].f_data;
	string tm = "";
	string dt = "";
	if (lines.length() > 10) {
		tm = lines.substr(2,5);
		dt = lines.substr(0,2).append(lines.substr(7,4));
	}
	qexport.replace( qexport.find("?D2?"), 4, dt);
	qexport.replace( qexport.find("?T2?"), 4, tm);

	lines = rgfields[5].f_data;
	tm = ""; dt = "";
	if (lines.length() > 10) {
		tm = lines.substr(2,5);
		dt = lines.substr(0,2).append(lines.substr(7,4));
	}
	qexport.replace( qexport.find("?D3?"), 4, dt);
	qexport.replace( qexport.find("?T3?"), 4, tm);

	if (rgfields[7].f_data.empty()) lines = "";
	else {
		lines = rgfields[7].f_data;
		xml_lines(lines, "line");
		to_xml(lines);
	}
	qexport.replace( qexport.find("?AD?"), 4, lines);
	qexport.replace( qexport.find("?PH?"), 4, rgfields[8].f_data);

// message contents
	if (rgfields[10].f_data.empty()) lines = "";
	else {
		lines = rgfields[10].f_data;
		xml_lines(lines, "para");
		to_xml(lines);
	}
	qexport.replace( qexport.find("?BD?"), 4, lines);

	lines.clear();
	lines.append("<line>").append(progStatus.my_call).append("</line>\n");
	lines.append("<line>").append(progStatus.my_name).append("</line>\n");
	lines.append("<line>").append(progStatus.my_addr).append("</line>\n");
	lines.append("<line>").append(progStatus.my_city).append("</line>\n");
	lines.append("<line>").append(progStatus.my_tel).append("</line>");
	to_xml(lines);
	qexport.replace( qexport.find("?RA?"), 4, lines);

	qexport.replace( qexport.find("?NM?"), 4, rgfields[11].f_data);
	qexport.replace( qexport.find("?STA?"), 5, rgfields[14].f_data);
	qexport.replace( qexport.find("?PL?"), 4, rgfields[15].f_data);

	lines = rgfields[18].f_data;
	xml_lines( lines, "line");
	qexport.replace( qexport.find("?ST?"), 4, lines);

	lines = rgfields[13].f_data; // ck
	if (lines.find("ARL ") != string::npos) {
		qexport.replace( qexport.find("?ARL?"), 5, "yes");
		lines.erase(0, 4);
	} else
		qexport.replace( qexport.find("?ARL?"), 5, "no");
	qexport.replace( qexport.find("?CK?"), 4, lines);

	xmlfile = fopen(fname.c_str(), "w");
	if (!xmlfile) return;
	fwrite( qexport.c_str(), qexport.length(), 1, xmlfile );
	fclose(xmlfile);
}

