//########################################################################
//
//  Qforms import / export
//
//  copywrite David Freese, w1hkj@w1hkj.com
//
//########################################################################

#include "config.h"
#include "flics_config.h"

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
#include "ics213_dialog.h"
#include "ics213.h"
#include "config.h"

using namespace std;

//======================================================================
// import
//======================================================================

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

string strXML;

TAGS XML_tags[] = {
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
string xml_to;
string xml_p1;
//sender
string xml_fm;
string xml_p2;
//subject date time
string xml_subj;
string xml_d1;
string xml_t1;
//message body
string xml_msg;
//preparer
string xml_s1;
string xml_p3;
//reply
string xml_reply;
string xml_d2;
string xml_t2;
string xml_s2;
string xml_p4;

enum PARSE_MODE {TO, FM, RECIP, SENDER, SUBJ, MSG, PREP, REPLY} pmode;

//=====================================================================

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

void parse_ics_name(size_t &p0, string xml)
{
string contents = get_element(p0, xml).c_str();
	switch (pmode) {
		case TO:
		case RECIP: xml_to = contents; break;
		case FM:
		case SENDER: xml_fm = contents; break;
		case MSG: xml_s1 = contents; break;
		case REPLY: xml_s2 = contents; break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}


void parse_ics_position(size_t &p0, string xml)
{
string contents = get_element(p0, xml).c_str();
	switch (pmode) {
		case TO:
		case RECIP: xml_p1 = contents; break;
		case FM:
		case SENDER: xml_p2 = contents; break;
		case MSG: xml_p3 = contents; break;
		case REPLY: xml_p4 = contents; break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_subject(size_t &p0, string xml)
{
	xml_subj = get_element(p0, xml).c_str();
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_para(size_t &p0, string xml)
{
string contents = get_element(p0, xml).c_str();
	switch (pmode) {
		case MSG:
			xml_msg.append(contents);
			xml_msg.append("\n");
			break;
		case REPLY:
			xml_reply.append(contents);
			xml_reply.append("\n");
			break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_date(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (pmode) {
		case TO:
		case FM:
		case SENDER:
		case MSG:
		case RECIP: xml_d1 = contents; break;
		case REPLY: xml_d2 =contents; break;
		default : ;
	}
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_time(size_t &p0, string xml)
{
	string contents = get_element(p0, xml).c_str();
	switch (pmode) {
		case TO:
		case FM:
		case SENDER:
		case RECIP: xml_t1 = contents; break;
		case REPLY: xml_t2 =contents; break;
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
	pmode = RECIP;
	string recip = get_element(p0, xml);
	parse_xml(recip);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_sender(size_t &p0, string xml)
{
	pmode = SENDER;
	string sender = get_element(p0, xml);
	parse_xml(sender);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_signature(size_t &p0, string xml)
{
	string sign = get_element(p0, xml);
	parse_xml(sign);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_body(size_t &p0, string xml)
{
	if (pmode == TO || pmode == FM || pmode == RECIP || pmode == SENDER)
		pmode = MSG;
	string body = get_element(p0, xml);
	parse_xml(body);
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
	pmode = REPLY;
string reply = get_element(p0, xml);
	parse_xml(reply);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_ics_message(size_t &p0, string xml)
{
	pmode = TO;
	string message;
	message = get_element(p0, xml);
	parse_xml(message);
	p0 = tag_end(p0, xml);
	p0 = next_tag(p0 + 1, xml);
}

void parse_discard(size_t &p0, string xml)
{
	size_t pend = tag_end(p0, xml);
	if (pend != string::npos) p0 = pend + 1;
	else p0 = pend;
}

void parse_ics_header(size_t &p0, string xml)
{
	p0 = next_tag(p0 + 1, xml);
}

// recursive parser
void parse_xml( string xml )
{
	size_t p0;
	TAGS *pValid;

	p0 = next_tag(0, xml); // find the 1st tag
	while (p0 != string::npos) {
		pValid = XML_tags;
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

void clear_xml()
{
//recipient
	xml_to.clear();
	xml_p1.clear();
//sender
	xml_fm.clear();
	xml_p2.clear();
//subject date time
	xml_subj.clear();
	xml_d1.clear();
	xml_t1.clear();
//message body
	xml_msg.clear();
//preparer
	xml_s1.clear();
	xml_p3.clear();
//reply
	xml_reply.clear();
	xml_d2.clear();
	xml_t2.clear();
	xml_s2.clear();
	xml_p4.clear();
}

void transfer_fields()
{
	clear_fields();
	txt_To->value(xml_to.c_str());
	txt_P1->value(xml_p1.c_str());
	txt_Fm->value(xml_fm.c_str());
	txt_P2->value(xml_p2.c_str());
	txt_Subj->value(xml_subj.c_str());
	txt_D1->value(xml_d1.c_str());
	txt_T1->value(xml_t1.c_str());
	txt_Msg->addstr(xml_msg.c_str());
	txt_S1->value(xml_s1.c_str());
	txt_P3->value(xml_p3.c_str());
	txt_Reply->addstr(xml_reply.c_str());
	txt_S2->value(xml_s2.c_str());
	txt_D2->value(xml_d2.c_str());
	txt_T2->value(xml_t2.c_str());
	txt_P4->value(xml_p4.c_str());
	update_fields();
	defFileName = ICS_msg_dir;
	defFileName.append("qform");
	defFileName.append(DATAFILE_EXT);
	show_filename(defFileName);
}

bool qform_import(string fname)
{
	char *buff;
	FILE *xmlfile;
	size_t filesize;
	int retval;

//#ifdef __WIN32__
//	xmlfile = fopen (fname.c_str(), "rb");
//#else
	xmlfile = fopen (fname.c_str(), "r");
//#endif
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

	pmode = TO;
	clear_xml();

	parse_xml(buff);
	transfer_fields();

	delete [] buff;
	return true;
}

//======================================================================
// export
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
<body>\
?MG?</body>\
<signature>\
<name>?S3?</name>\
<position>?P3?</position>\
</signature>\
<reply>\
<id></id>\
<date>?D2?</date>\
<time>?T2?</time>\
<body>\
?RP?</body>\
<signature>\
<name>?S4?</name>\
<position>?P4?</position>\
</signature>\
</reply>\
</message>\
";

const char *export_line = "<para>LINE</para>";

void qform_export(string fname)
{
	FILE *xmlfile;
	size_t pos = 0;
	string qexport = export_template;
	string lines;

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
	qexport.replace( qexport.find("?MG?"), 4, lines);

	lines = "<para>";
	lines.append(fields[14].f_data);
	lines.append("</para>");
	while ((pos = lines.find("\n")) != string::npos)
		lines.replace(pos, 1, "</para><para>");
	qexport.replace( qexport.find("?RP?"), 4, lines);

	xmlfile = fopen(fname.c_str(), "w");
	if (!xmlfile) return;
	fwrite( qexport.c_str(), qexport.length(), 1, xmlfile );
	fclose(xmlfile);
}
