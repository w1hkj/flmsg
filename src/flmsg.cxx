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
#include <sstream>
#include <cstring>
#include <ctime>
#include <sys/types.h>
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

#include "config.h"
#include "flmsg_config.h"

#include "flmsg.h"
#include "flmsg_arq.h"

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
#include "threads.h"
#include "xml_io.h"

#include "socket.h"

#include "mongoose.h"

#include "timeops.h"

#include "arq.h"

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

using namespace std;

//----------------------------------------------------------------------
// Mongoose web server
struct mg_server *server = (mg_server *)NULL;
void *poll_server(void *);
int  start_web_server();
void close_server();
char *mongoose_msg;
string mongoose_msgs;

int srvr_portnbr = 8080;
char sz_srvr_portnbr[6];

//----------------------------------------------------------------------
// log files
void rotate_log(std::string filename);
//----------------------------------------------------------------------

const char *options[] = {\
"flmsg unique options",
"--help",
"--version",
"--server-port\tstarting port number for forms web server [8080]",
"--flmsg-dir\tfull-path-name-of-folder for all FLMSG folders",
"--auto-dir\tfull-path-name-of-folder for autosend files",
"\tauto-dir, flmsg-dir can be separate and unique",
"--p FILENAME\tprint and exit",
"--b FILENAME\tprint and stay open",
"Fltk UI options",
"-bg\t-background [COLOR]",
"-bg2\t-background2 [COLOR]",
"-di\t-display [host:n.n]",
"-dn\t-dnd : enable drag and drop",
"-nodn\t-nodnd : disable drag and drop",
"-fg\t-foreground [COLOR]",
"-g\t-geometry [WxH+X+Y]",
"-i\t-iconic",
"-k\t-kbd : enable keyboard focus:",
"-nok\t-nokbd : en/disable keyboard focus",
"-na\t-name [CLASSNAME]",
"-s\t-scheme [none | base | gtk+ | plastic | gleam], default = gtk+",
"-ti\t[WINDOWTITLE]",
"-to\t-tooltips : enable tooltips",
"-not\t-notooltips : disable tooltips\n",
0
};

Fl_Double_Window *mainwindow = (Fl_Double_Window *)0;
Fl_Double_Window *expert_dialog = (Fl_Double_Window *)0;
Fl_Double_Window *tyro_dialog = (Fl_Double_Window *)0;
Fl_Double_Window *optionswindow = (Fl_Double_Window *)0;
Fl_Double_Window *arlwindow = (Fl_Double_Window *)0;
Fl_Double_Window *config_dialog = (Fl_Double_Window *)0;
Fl_Double_Window *hxwindow = (Fl_Double_Window *)0;
Fl_Double_Window *header_window = (Fl_Double_Window *)0;

pthread_t *xmlrpc_thread = 0;
pthread_mutex_t mutex_xmlrpc = PTHREAD_MUTEX_INITIALIZER;

bool printme = false;
bool exit_after_print = false;
int  selected_form = NONE;

string title;

string errtext;

// fldigi, flmsg share a common files directory structure

#ifdef __WIN32__
	string FLMSG_dir_default = "$USERPROFILE/NBEMS.files/";
#else
	string FLMSG_dir_default = "$HOME/.nbems/";
#endif

string FLMSG_dir = "";
string ARQ_dir = "";
string ARQ_files_dir = "";
string ARQ_recv_dir = "";
string ARQ_send_dir = "";
string WRAP_dir = "";
string WRAP_recv_dir = "";
string WRAP_send_dir = "";
//string WRAP_auto_dir = "";
string ICS_dir = "";
string ICS_msg_dir = "";
string ICS_tmp_dir = "";
string CSV_dir = "";
string CUSTOM_dir = "";
string XFR_dir = "";
string FLMSG_temp_dir = "";
string FLMSG_log_dir = "";
string FLMSG_custom_dir = "";

string cmd_fname = "";

string TITLE = ":TITLE:";

string evalstr = "";

string parse_info = "";

//======================================================================
// custom edit/view only program use

bool update_custom = false;

//======================================================================

//string defRTFname = "";

// utility functions

//----------------------------------------------------------------------
// header fields
//----------------------------------------------------------------------

string hdr_from = "";
string hdr_edit = "";
static string szFrom = ":hdr_fm:";
static string szEdit = ":hdr_ed:";

bool check_mycall()
{
	if (mainwindow == tyro_dialog)
		return true;

	if (!progStatus.my_call.empty())
		return true;

	if (!config_dialog->visible())
		cb_config_personal();

	return false;
}

// create flmsg line output for string data
string lineout(string &field, string &data)
{
	static string sout;
	static char sznum[80];
	if (data.empty()) return "";
	snprintf(sznum, sizeof(sznum), "%0d", (int)data.length());
	sout.assign(field);
	sout.append(sznum).append(" ").append(data).append("\n");
	return sout;
}
// create flmsg line output for binary data
string binout( string &field, bool &data)
{
	static string sout;
	if (!data) return "";
	sout = field;
	sout.append(" ").append( data ? "T" : "F").append("\n");
	return sout;
}

//----------------------------------------------------------------------
// header for flmsg output file
//----------------------------------------------------------------------
void clear_header()
{
	hdr_from.clear();
	hdr_edit.clear();
}

string header(const char *msgtype )
{
	string hdr;
	hdr.assign("<flmsg>").append (PACKAGE_VERSION).append("\n");
	hdr.append(lineout(szFrom, hdr_from));
	hdr.append(lineout(szEdit, hdr_edit));
	hdr.append(msgtype).append("\n");
	return hdr;
}

void read_header(string &str)
{
	clear_header();
	hdr_from = findstr(str, szFrom);
	hdr_edit = findstr(str, szEdit);
}

void update_header(hdr_reason reason)
{
	if (progStatus.my_call.empty()) return;

	static string dt;
	int utc = progStatus.UTC;
	int dtf = progStatus.dtformat;
	progStatus.UTC = 2;
	progStatus.dtformat = 4;
	dt.assign(szDate()).append(szTime(6));
	progStatus.UTC = utc;
	progStatus.dtformat = dtf;

	switch (reason) {
	case NEW :
		clear_header();
		hdr_edit.assign("\n").append(progStatus.my_call).append(" ").append(dt);
		break;
	case CHANGED:
		if (!hdr_edit.empty()) {
			size_t p1 = string::npos, p2 = string::npos;
			while( (p1 = hdr_edit.find(progStatus.my_call)) != string::npos) {
				p2 = hdr_edit.find("\n", p1);
				if (p2 != string::npos)
					hdr_edit.erase(p1, p2 - p1 + 1);
				else
					hdr_edit.erase(p1);
			}
		}
		hdr_edit.append("\n").append(progStatus.my_call).append(" ").append(dt);
		break;
	case FROM:
		if (!hdr_from.empty()) {
			size_t p1 = string::npos, p2 = string::npos;
			while( (p1 = hdr_from.find(progStatus.my_call)) != string::npos) {
				p2 = hdr_from.find("\n", p1);
				if (p2 != string::npos)
					hdr_from.erase(p1, p2 - p1 + 1);
				else
					hdr_from.erase(p1);
			}
		}
		hdr_from.append("\n").append(progStatus.my_call).append(" ").append(dt);
		break;
		default: ;
	}
	size_t p;
	p = hdr_from.find("\n\n");
	while(hdr_from.find("\n\n") != string::npos) {
		hdr_from.replace(p, 2, "\n");
		p = hdr_from.find("\n\n");
	}
	p = hdr_edit.find("\n\n");
	while(hdr_edit.find("\n\n") != string::npos) {
		hdr_edit.replace(p, 2, "\n");
		p = hdr_edit.find("\n\n");
	}
}

// find string data associated with a field specifier
string findstr(string &haystack, string &needle)
{
	size_t p = haystack.find(needle, 0);
	if (p == string::npos) return "";
	p += needle.length();
	int nchar;
	sscanf(&haystack[p], "%d", &nchar);
	if (nchar) {
		p = haystack.find(' ', p);
		p++;
		return haystack.substr(p, nchar);
	}
	return "";
}

// find boolean data associated with a field specifier
bool findbin(string &haystack, string &needle)
{
	size_t p = haystack.find(needle, 0);
	if (p == string::npos) return false;
	p += needle.length() + 1;
	if (haystack.find("F", p) == p) return false;
	if (haystack.find("T", p) == p) return true;
	return false;
}

// replace string
void replacestr(string &form, string &where, string &what)
{
	size_t p = form.find(where);
	while (p != string::npos) {
		form.replace(p, where.length(), what);
		p = form.find(where);
	}
}

void replacelf(string &form, int n)
{
	size_t p = 0;
	int i = 0;
	while ( (p = form.find("\n", p)) != string::npos) {
		form.insert(p, "<br>");
		p += 5;
		i++;
	}
	if (n)
		for (int j = i; j < n; j++)
			form.append("<br>\n");
}

void substitutestr(string &form, string &where, string &what)
{
	size_t p = 0;
	p = form.find(where, p);
	while (p != string::npos) {
		form.replace(p, where.length(), what);
		p++;
		p = form.find(where, p);
	}
}

void striplf(string &what)
{
	while (*what.rbegin() == '\n') what.erase(what.end()-1);
}

void strip_html(string &buffer)
{
	string amp = "&";		string amprep = "&#38;";
	string quote = "\"";	string quoterep = "&#34;";
	string less = "<";		string lessrep = "&#60;";
	string more = ">";		string morerep = "&#62;";
	substitutestr(buffer, amp, amprep);
	substitutestr(buffer, quote, quoterep);
	substitutestr(buffer, less, lessrep);
	substitutestr(buffer, more, morerep);
}

void remove_cr(string &buffer)
{
	size_t p = string::npos;
	while ((p = buffer.find('\r')) != string::npos) buffer.erase(p,1);
}

//----------------------------------------------------------------------
void remove_spaces_from_filename(string &fname)
{
	size_t n = fname.length();
	char szfname[n + 1];
	char *p;
	memset(szfname, 0, n + 1);
	strcpy(szfname, fname.c_str());
	p = (char *)fl_filename_name(szfname);
	while (*p) {
		if (*p == ' ') *p = '_';
		p++;
	}
	fname = szfname;
}

char *szTime(int typ)
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	switch (typ) {
		case 0:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H%ML", &sTime);
			break;
		case 1:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H:%ML", &sTime);
			break;
		case 2:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H%MZ", &sTime);
			break;
		case 3:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H:%MZ", &sTime);
			break;
		case 4:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H%M UTC", &sTime);
			break;
		case 5:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H:%M UTC", &sTime);
			break;
		case 6:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H%M%S", &sTime);
			break;
		case 7:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H%M", &sTime);
			break;
		default:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H%ML", &sTime);
	}
	return szDt;
}

char *szDate(int df)
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (progStatus.UTC > 1) {
		gmtime_r (&tmptr, &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
	}
	switch (df > -1 ? df: progStatus.dtformat) {
		case 0: strftime(szDt, 79, "%Y-%m-%d", &sTime); break;
		case 1: strftime(szDt, 79, "%m/%d/%y", &sTime); break;
		case 2: strftime(szDt, 79, "%d/%m/%y", &sTime); break;
		case 3: strftime(szDt, 79, "%Y-%d-%m", &sTime); break;
		case 4: strftime(szDt, 79, "%Y%d%m", &sTime); break;
		default: strftime(szDt, 79, "%Y-%m-%d", &sTime);
	}
	return szDt;
}

char *szAbbrevDate()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (progStatus.UTC) {
		gmtime_r (&tmptr, &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
	}
	strftime(szDt, 79, "%b %d", &sTime);
	for (int i = 0; i < 3; i++) szDt[i] = toupper(szDt[i]);
	return szDt;
}

char *szDateTime()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (progStatus.UTC) {
		gmtime_r (&tmptr, &sTime);
		strftime(szDt, 79, "%d%H%MZ %b %Y", &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
		strftime(szDt, 79, "%d%H%ML %b %Y", &sTime);
	}
	for (size_t i = 0; i < strlen(szDt); i++) szDt[i] = toupper(szDt[i]);
	return szDt;
}

char *szMarsDateTime()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	gmtime_r (&tmptr, &sTime);
	strftime(szDt, 79, "%d%H%MZ %b %Y", &sTime);
	for (size_t i = 0; i < strlen(szDt); i++) szDt[i] = toupper(szDt[i]);
	return szDt;
}

char *szCAPDateTime()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (progStatus.caplocal) {
		localtime_r(&tmptr, &sTime);
		strftime(szDt, 79, "%d %H%ML %b %y", &sTime);
	} else {
		gmtime_r (&tmptr, &sTime);
		strftime(szDt, 79, "%d %H%MZ %b %y", &sTime);
	}
	for (size_t i = 0; i < strlen(szDt); i++) szDt[i] = toupper(szDt[i]);
	return szDt;
}

char *named_file()
{
	static char szfname[400];
	static char szDt[80];
	szfname[0] = 0;
	if (!progStatus.call_fname && !progStatus.dt_fname && !progStatus.sernbr_fname)
		return szfname;

	time_t tmptr;
	tm sTime;
	time (&tmptr);
	switch (progStatus.dt_fname) {
		case 1 :
			localtime_r (&tmptr, &sTime);
			strftime(szDt, sizeof(szDt), "%Y%m%d-%H%M%SL", &sTime);
			break;
		case 2 :
			localtime_r (&tmptr, &sTime);
			strftime(szDt, sizeof(szDt), "%Y%m%d-%H%M%S%Z", &sTime);
			break;
		case 3 :
			localtime_r (&tmptr, &sTime);
			strftime(szDt, sizeof(szDt), "%Y%m%d-%H%M%S%z", &sTime);
			break;
		case 4 :
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, sizeof(szDt), "%Y%m%d-%H%M%SZ", &sTime);
			break;
		case 0 :
		default :
			szDt[0] = 0;
	}

	if (progStatus.call_fname) strcat(szfname, progStatus.my_call.c_str());

	if (selected_form == RADIOGRAM  && progStatus.rgnbr_fname) {
		if (szfname[0]) strcat(szfname, "-");
		strcat(szfname, progStatus.rgnbr.c_str());
	} else {
		if (szDt[0]) {
			if (szfname[0]) strcat(szfname, "-");
			strcat(szfname, szDt);
		}
		if (progStatus.sernbr_fname) {
			if (szfname[0]) strcat(szfname, "-");
			strcat(szfname, progStatus.sernbr.c_str());
		}
	}
	return szfname;
}

void update_sernbr ()
{
string dfname = FLMSG_dir;
dfname.append("flmsg.sernbrs");
FILE *debug_file = fl_fopen(dfname.c_str(), "a");
	int n = atoi(progStatus.sernbr.c_str());
	n++;
	char szn[12];
	snprintf(szn, sizeof(szn), "%d", n);
	progStatus.sernbr = szn;
	txt_sernbr->value(szn);
	txt_sernbr->redraw();
fprintf(debug_file, "New ser # %s\n" , szn);
fclose(debug_file);
}

void extract_text(string &buffer, const char *fname)
{
	remove_cr(buffer);

	if (buffer.find("<radiogram>") != string::npos) {
		selected_form = RADIOGRAM;
		read_rg_buffer(buffer);
		if (fname) def_rg_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<iaru>") != string::npos) {
		selected_form = IARU;
		iaru_read_buffer(buffer);
		if (fname) iaru_def_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<cap105>") != string::npos) {
		selected_form = CAP105;
		cap105_read_buffer(buffer);
		if (fname) cap105_def_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<cap110>") != string::npos) {
		selected_form = CAP110;
		read_c110_buffer(buffer);
		if (fname) cap110_def_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<mars_daily>") != string::npos) {
		selected_form = MARSDAILY;
		read_mars_daily_buffer(buffer);
		if (fname) def_mars_daily_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<mars_ineei>") != string::npos) {
		selected_form = MARSINEEI;
		read_mars_ineei_buffer(buffer);
		if (fname) def_mars_ineei_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<mars_net>") != string::npos) {
		selected_form = MARSNET;
		read_mars_net_buffer(buffer);
		if (fname) def_mars_net_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<mars_army>") != string::npos) {
		selected_form = MARSARMY;
		read_mars_army_buffer(buffer);
		if (fname) def_mars_army_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<nhc_wx>") != string::npos) {
		selected_form = WXHC;
		read_wxhc_buffer(buffer);
		if (fname) def_wxhc_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<severe_wx>") != string::npos) {
		selected_form = SEVEREWX;
		read_severe_wx_buffer(buffer);
		if (fname) def_severe_wx_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<storm_wx>") != string::npos) {
		selected_form = STORMREP;
		read_storm_buffer(buffer);
		if (fname) def_storm_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<hics203>") != string::npos) {
		selected_form = HICS203;
		read_hics203_buffer(buffer);
		if (fname) def_hics203_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<hics206>") != string::npos) {
		selected_form = HICS206;
		h206_read_buffer(buffer);
		if (fname) h206_def_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<hics213>") != string::npos) {
		selected_form = HICS213;
		h213_read_buffer(buffer);
		if (fname) h213_def_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<hics214>") != string::npos) {
		selected_form = HICS214;
		hics214_read_buffer(buffer);
		if (fname) hics214_def_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<ics203>") != string::npos) {
		selected_form = ICS203;
		read_203_buffer(buffer);
		if (fname) def_203_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<ics205>") != string::npos) {
		selected_form = ICS205;
		read_205_buffer(buffer);
		if (fname) def_205_filename= fname;
		select_form(selected_form);
	} else if (buffer.find("<ics205a>") != string::npos) {
		selected_form = ICS205A;
		read_205a_buffer(buffer);
		if (fname) def_205a_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<ics206>") != string::npos) {
		selected_form = ICS206;
		read_206_buffer(buffer);
		if (fname) def_206_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<ics213>") != string::npos) {
		selected_form = ICS213;
		read_213_buffer(buffer);
		if (fname) def_213_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<ics214>") != string::npos) {
		selected_form = ICS214;
		read_214_buffer(buffer);
		if (fname) def_214_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<ics216>") != string::npos) {
		selected_form = ICS216;
		read_216_buffer(buffer);
		if (fname) def_216_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<ics309>") != string::npos) {
		selected_form = ICS309;
		read_309_buffer(buffer);
		if (fname) def_309_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<netlog>") != string::npos) {
		selected_form = NETLOG;
		read_netlog_buffer(buffer);
		if (fname) def_netlog_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<plaintext>") != string::npos) {
		selected_form = PLAINTEXT;
		read_ptbuffer(buffer);
		if (fname) def_pt_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<blankform>") != string::npos) {
		selected_form = BLANK;
		read_blankbuffer(buffer);
		if (fname) def_blank_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<csvform>") != string::npos) {
		selected_form = CSV;
		read_csvbuffer(buffer);
		if (fname) def_csv_filename = fname;
		select_form(selected_form);
	} else if (buffer.find("<customform>") != string::npos) {
		selected_form = CUSTOM;
		read_custombuffer(buffer);
		if (fname) def_custom_filename = fname;
		select_form(selected_form);
	} else if (!exit_after_print){
extern string blank_field;
extern void update_blankform();
		selected_form = BLANK;
		cb_blank_new();
		if (fname) def_blank_filename = fname;
		select_form(selected_form);
		blank_field = buffer;
		update_blankform();
	}
}

//
void read_data_file(string s)
{
	long filesize = 0;
//	char *buff, *buffend;
	int retval;
	FILE *icsfile;

	icsfile = fopen (s.c_str(), "rb");// "r");
	if (!icsfile)
		return;
// determine its size for buffer creation
	fseek (icsfile, 0, SEEK_END);
	filesize = ftell (icsfile);
// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
        fclose (icsfile);
		return;
	}

// read the entire file into the buffer
	string buffer;
	buffer.resize(filesize);
	fseek(icsfile, 0, SEEK_SET);
	retval = fread( (void*)buffer.c_str(), 1, filesize, icsfile);
	fclose(icsfile);
	if (retval != filesize) {
		fl_alert2(_("Read error"));
		return;
	}

	extract_text(buffer, s.c_str());
}

int eval_transfer_size()
{
	switch (selected_form) {
		case ICS203:	return eval_203_fsize();
		case ICS205:	return eval_205_fsize();
		case ICS205A:	return eval_205a_fsize();
		case ICS206:	return eval_206_fsize();
		case ICS213:	return eval_213_fsize();
		case ICS214:	return eval_214_fsize();
		case ICS216:	return eval_216_fsize();
		case ICS309:	return eval_309_fsize();
		case NETLOG:	return eval_netlog_fsize();
		case HICS203:	return eval_hics203_fsize();
		case HICS206:	return eval_h206_fsize();
		case HICS213:	return eval_h213_fsize();
		case HICS214:	return eval_hics214_fsize();
		case RADIOGRAM:	return eval_rg_fsize();
		case IARU:		return eval_iaru_fsize();
		case CAP105:	return eval_cap105_fsize();
		case CAP110:	return eval_cap110_fsize();
		case PLAINTEXT:	return eval_pt_fsize();
		case BLANK:		return eval_blank_fsize();
		case CSV:		return eval_csv_fsize();
		case CUSTOM:	return eval_custom_fsize();
		case TRANSFER:	return eval_transfer_fsize();
		case CUSTOM_TRANSFER: return eval_transfer_custom_form_fsize();
		case MARSDAILY:	return eval_mars_daily_fsize();
		case MARSINEEI:	return eval_mars_ineei_fsize();
		case MARSNET:	return eval_mars_net_fsize();
		case MARSARMY:	return eval_mars_army_fsize();
		case WXHC:		return eval_wxhc_fsize();
		case SEVEREWX:	return eval_severe_wx_fsize();
		case STORMREP:	return eval_storm_fsize();
		default : ;
	}
	return 0;
}

void cb_new()
{
	switch (selected_form) {
		case ICS203: cb_203_new(); break;
		case ICS205: cb_205_new(); break;
		case ICS205A: cb_205a_new(); break;
		case ICS206: cb_206_new(); break;
		case ICS213: cb_213_new(); break;
		case ICS214: cb_214_new(); break;
		case ICS216: cb_216_new(); break;
		case ICS309: cb_309_new(); break;
		case NETLOG: cb_netlog_new(); break;
		case HICS203: cb_hics203_new(); break;
		case HICS206: h206_cb_new(); break;
		case HICS213: h213_cb_new(); break;
		case HICS214: hics214_cb_new(); break;
		case RADIOGRAM: cb_rg_new(); break;
		case IARU: iaru_cb_new(); break;
		case CAP105: cap105_cb_new(); break;
		case CAP110: cap110_cb_new(); break;
		case PLAINTEXT: cb_pt_new(); break;
		case BLANK: cb_blank_new(); break;
		case TRANSFER: cb_transfer_new(); break;
		case CSV: cb_csv_new(); break;
		case CUSTOM: cb_custom_new(); break;
		case MARSDAILY: cb_mars_daily_new(); break;
		case MARSINEEI: cb_mars_ineei_new(); break;
		case MARSNET: cb_mars_net_new(); break;
		case MARSARMY: cb_mars_army_new(); break;
		case WXHC: cb_wxhc_new(); break;
		case SEVEREWX: cb_severe_wx_new(); break;
		case STORMREP: cb_storm_new(); break;
		default : return;
	}
	clear_estimate();
}

void cb_import()
{
	switch (selected_form) {
		case ICS203: cb_203_import(); break;
		case ICS205: cb_205_import(); break;
		case ICS205A: cb_205a_import(); break;
		case ICS206: cb_206_import(); break;
		case ICS213: cb_213_import(); break;
		case ICS214: cb_214_import(); break;
		case ICS216: cb_216_import(); break;
		case ICS309: cb_309_import(); break;
		case NETLOG: cb_netlog_import(); break;
		case HICS203: cb_hics203_import(); break;
		case HICS206: h206_cb_import(); break;
		case HICS213: h213_cb_import(); break;
		case HICS214: hics214_cb_import(); break;
		case RADIOGRAM: cb_rg_import(); break;
		case IARU: iaru_cb_import(); break;
		case CAP105: cap105_cb_import(); break;
		case CAP110: cap110_cb_import(); break;
		case PLAINTEXT:
		case BLANK:
		case CSV:
		case CUSTOM:
		case MARSDAILY:
		case MARSINEEI:
		case MARSNET:
		case MARSARMY:
		case WXHC:
		case SEVEREWX:
		case STORMREP:
		default:
			fl_alert2("Not implemented");
	}
	estimate();
}

void cb_export()
{
	switch (selected_form) {
		case ICS203: cb_203_export(); break;
		case ICS205: cb_205_export(); break;
		case ICS205A: cb_205a_export(); break;
		case ICS206: cb_206_export(); break;
		case ICS213: cb_213_export(); break;
		case ICS214: cb_214_export(); break;
		case ICS216: cb_216_export(); break;
		case ICS309: cb_309_export(); break;
		case NETLOG: cb_netlog_export(); break;
		case HICS203: cb_hics203_export(); break;
		case HICS206: h206_cb_export(); break;
		case HICS213: h213_cb_export(); break;
		case HICS214: hics214_cb_export(); break;
		case RADIOGRAM: cb_rg_export(); break;
		case IARU: iaru_cb_export(); break;
		case CAP105: cap105_cb_export(); break;
		case CAP110: cap110_cb_export(); break;
		case PLAINTEXT:
		case BLANK:
		case CSV:
		case CUSTOM:
		case MARSDAILY:
		case MARSINEEI:
		case MARSNET:
		case MARSARMY:
		case WXHC:
		case SEVEREWX:
		case STORMREP:
		default:
			fl_alert2("Not implemented");
	}
}

void wrap_import(const char *fname)
{
	string filename;
	string inpbuffer;

	bool isok = import_wrapfile(fname, filename, inpbuffer);

	if (!isok && !exit_after_print) {
		isok = !fl_choice2(_("Checksum failed\n\nIgnore errors?"), "yes", "no", NULL);
	}

	if (inpbuffer.find("<transfer") != string::npos) {
		save_this_file_as(filename, inpbuffer);
		return;
	}

	if (isok) {
		if (!(inpbuffer.find("<transfer>") != string::npos &&
			inpbuffer.find("<html_file>") != string::npos) )
			remove_cr( inpbuffer );
		if (inpbuffer.find("<flics") != string::npos ||
			inpbuffer.find("<flmsg") != string::npos) {
			if (inpbuffer.find("<ics203>") != string::npos) {
				selected_form = ICS203;
				cb_203_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<hics203>") != string::npos) {
				selected_form = HICS203;
				cb_hics203_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<hics206>") != string::npos) {
				selected_form = HICS206;
				h206_cb_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<hics213>") != string::npos) {
				selected_form = HICS213;
				h213_cb_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<hics214>") != string::npos) {
				selected_form = HICS214;
				hics214_cb_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics205>") != string::npos) {
				selected_form = ICS205;
				cb_205_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics205a>") != string::npos) {
				selected_form = ICS205A;
				cb_205a_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics206>") != string::npos) {
				selected_form = ICS206;
				cb_206_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics213>") != string::npos) {
				selected_form = ICS213;
				cb_213_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics214>") != string::npos) {
				selected_form = ICS214;
				cb_214_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics216>") != string::npos) {
				selected_form = ICS216;
				cb_216_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics309>") != string::npos) {
				selected_form = ICS309;
				cb_309_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<netlog>") != string::npos) {
				selected_form = NETLOG;
				cb_netlog_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<radiogram>") != string::npos) {
				selected_form = RADIOGRAM;
				cb_rg_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<iaru>") != string::npos) {
				selected_form = IARU;
				iaru_cb_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<cap105>") != string::npos) {
				selected_form = CAP105;
				cap105_cb_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<cap110>") != string::npos) {
				selected_form = CAP110;
				cap110_cb_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<plaintext>") != string::npos) {
				selected_form = PLAINTEXT;
				cb_pt_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<blankform>") != string::npos) {
				selected_form = BLANK;
				cb_blank_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<csvform>") != string::npos) {
				selected_form = CSV;
				cb_csv_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<customform>") != string::npos) {
				selected_form = CUSTOM;
				cb_custom_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<mars_daily>") != string::npos) {
				selected_form = MARSDAILY;
				cb_mars_daily_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<mars_ineei>") != string::npos) {
				selected_form = MARSINEEI;
				cb_mars_ineei_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<mars_net>") != string::npos) {
				selected_form = MARSNET;
				cb_mars_net_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<mars_army>") != string::npos) {
				selected_form = MARSARMY;
				cb_mars_army_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<nhc_wx>") != string::npos) {
				selected_form = WXHC;
				cb_wxhc_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<severe_wx>") != string::npos) {
				selected_form = SEVEREWX;
				cb_severe_wx_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<storm_wx>") != string::npos) {
				selected_form = STORMREP;
				cb_storm_wrap_import(filename, inpbuffer);;
			} else if (inpbuffer.find("<transfer>") != string::npos) {
				selected_form = TRANSFER;
				cb_transfer_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<html_form>") != string::npos) {
				selected_form = CUSTOM_TRANSFER;
				cb_custom_form_wrap_import(filename, inpbuffer);
			} else if (!exit_after_print) {
				selected_form = NONE;
				if (!fl_choice2(_("Cannot identify file type\n\nOpen as text file?"), "yes", "no", NULL)) {
					filename = fname;
					filename.append(".txt");
					FILE *badfile = fopen(filename.c_str(), "w");
					fwrite(inpbuffer.c_str(), inpbuffer.length(), 1, badfile);
					fclose(badfile);
					open_url(filename.c_str());
				}
			}
		}
		select_form(selected_form);
		estimate();
		return;
	}

	if (printme) {
		string badform = baddata_html_template;
		string mgstr = "<txt:";

		string badfile_name = ICS_dir;
		badfile_name.append("err.");
		badfile_name.append(fl_filename_name(fname));
		badfile_name.append(".html");

		string badbuffer = "Error in file: ";
		badbuffer.append(fname).append("\n\n");
		badbuffer.append(errtext);
		replacelf(badbuffer);

		string title = "Err:";
		title.append(fl_filename_name(fname));
		size_t p = title.rfind('.');
		if (p != string::npos) title.erase(p);

		replacestr(badform, TITLE, title);
		replacestr(badform, mgstr, badbuffer);

		FILE *badfile = fopen(badfile_name.c_str(), "w");
		fprintf(badfile,"%s", badform.c_str());
		fclose(badfile);
		open_url(badfile_name.c_str());
		if (exit_after_print)
			return;
		estimate();
	}

	if (!fl_choice2(_("Open as text file?"), "yes", "no", NULL)) {
		filename = fname;
		filename.append(".txt");
		FILE *badfile = fopen(filename.c_str(), "w");
		fwrite(inpbuffer.c_str(), inpbuffer.length(), 1, badfile);
		fclose(badfile);
		open_url(filename.c_str());
	}

}

void cb_wrap_import()
{
	string wrapfilename = WRAP_recv_dir;
	wrapfilename.append("default").append(WRAP_EXT);
	const char *p = FSEL::select(
		"Import wrapped flmsg file",
		"Wrap file\t*.{wrap,WRAP}",
		wrapfilename.c_str());
	if (p)
		wrap_import(p);
}

void cb_wrap_export()
{
	switch (selected_form) {
		case ICS203: cb_203_wrap_export(); break;
		case ICS205: cb_205_wrap_export(); break;
		case ICS205A: cb_205a_wrap_export(); break;
		case ICS206: cb_206_wrap_export(); break;
		case ICS213: cb_213_wrap_export(); break;
		case ICS214: cb_214_wrap_export(); break;
		case ICS216: cb_216_wrap_export(); break;
		case ICS309: cb_309_wrap_export(); break;
		case NETLOG: cb_netlog_wrap_export(); break;
		case HICS203: cb_hics203_wrap_export(); break;
		case HICS206: h206_cb_wrap_export(); break;
		case HICS213: h213_cb_wrap_export(); break;
		case HICS214: hics214_cb_wrap_export(); break;
		case RADIOGRAM: cb_rg_wrap_export(); break;
		case IARU: iaru_cb_wrap_export(); break;
		case CAP105: cap105_cb_wrap_export(); break;
		case CAP110: cap110_cb_wrap_export(); break;
		case PLAINTEXT: cb_pt_wrap_export(); break;
		case BLANK: cb_blank_wrap_export(); break;
		case CSV: cb_csv_wrap_export(); break;
		case CUSTOM: cb_custom_wrap_export(); break;
		case TRANSFER: break;//cb_transfer_wrap_export(); break;
		case MARSDAILY: cb_mars_daily_wrap_export(); break;
		case MARSINEEI: cb_mars_ineei_wrap_export(); break;
		case MARSNET: cb_mars_net_wrap_export(); break;
		case MARSARMY: cb_mars_army_wrap_export(); break;
		case WXHC: cb_wxhc_wrap_export(); break;
		case SEVEREWX: cb_severe_wx_wrap_export(); break;
		case STORMREP: cb_storm_wrap_export(); break;
		default: return;
	}

	if (!progStatus.open_on_export)
		return;

	string location = wrap_outfilename;
	size_t p = location.rfind('/');
	if (p != string::npos)
		location.erase(p+1);
	open_url(location.c_str());
}

void cb_wrap_autosend()
{
	if (progStatus.change_modem_with_autosend)
		send_new_modem();
	switch (selected_form) {
		case ICS203: cb_203_wrap_autosend(); break;
		case ICS205: cb_205_wrap_autosend(); break;
		case ICS205A: cb_205a_wrap_autosend(); break;
		case ICS206: cb_206_wrap_autosend(); break;
		case ICS213: cb_213_wrap_autosend(); break;
		case ICS214: cb_214_wrap_autosend(); break;
		case ICS216: cb_216_wrap_autosend(); break;
		case ICS309: cb_309_wrap_autosend(); break;
		case NETLOG: cb_netlog_wrap_autosend(); break;
		case HICS203: cb_hics203_wrap_autosend(); break;
		case HICS206: h206_cb_wrap_autosend(); break;
		case HICS213: h213_cb_wrap_autosend(); break;
		case HICS214: hics214_cb_wrap_autosend(); break;
		case RADIOGRAM: cb_rg_wrap_autosend(); break;
		case IARU: iaru_cb_wrap_autosend(); break;
		case CAP105: cap105_cb_wrap_autosend(); break;
		case CAP110: cap110_cb_wrap_autosend(); break;
		case PLAINTEXT: cb_pt_wrap_autosend(); break;
		case BLANK: cb_blank_wrap_autosend(); break;
		case CSV: cb_csv_wrap_autosend(); break;
		case CUSTOM: cb_custom_wrap_autosend(); break;
		case TRANSFER: cb_transfer_wrap_autosend(); break;
		case CUSTOM_TRANSFER: cb_transfer_custom_html(); break;
		case MARSDAILY: cb_mars_daily_wrap_autosend(); break;
		case MARSINEEI: cb_mars_ineei_wrap_autosend(); break;
		case MARSNET: cb_mars_net_wrap_autosend(); break;
		case MARSARMY: cb_mars_army_wrap_autosend(); break;
		case WXHC: cb_wxhc_wrap_autosend(); break;
		case SEVEREWX: cb_severe_wx_wrap_autosend(); break;
		case STORMREP: cb_storm_wrap_autosend(); break;
		default: return;
	}
}

void cb_load_template()
{
	switch (selected_form) {
		case ICS203: cb_203_load_template(); break;
		case ICS205: cb_205_load_template(); break;
		case ICS205A: cb_205a_load_template(); break;
		case ICS206: cb_206_load_template(); break;
		case ICS213: cb_213_load_template(); break;
		case ICS214: cb_214_load_template(); break;
		case ICS216: cb_216_load_template(); break;
		case ICS309: cb_309_load_template(); break;
		case NETLOG: cb_netlog_load_template(); break;
		case HICS203: cb_hics203_load_template(); break;
		case HICS206: h206_cb_load_template(); break;
		case HICS213: h213_cb_load_template(); break;
		case HICS214: hics214_cb_load_template(); break;
		case RADIOGRAM: cb_rg_load_template(); break;
		case IARU: iaru_cb_load_template(); break;
		case CAP105: cap105_cb_load_template(); break;
		case CAP110: cap110_cb_load_template(); break;
		case PLAINTEXT: cb_pt_load_template(); break;
		case BLANK: cb_blank_load_template(); break;
		case CSV: cb_csv_load_template(); break;
		case CUSTOM: cb_custom_load_template(); break;
		case MARSDAILY: cb_mars_daily_load_template(); break;
		case MARSINEEI: cb_mars_ineei_load_template(); break;
		case MARSNET: cb_mars_net_load_template(); break;
		case MARSARMY: cb_mars_army_load_template(); break;
		case WXHC: cb_wxhc_load_template(); break;
		case SEVEREWX: cb_severe_wx_load_template(); break;
		case STORMREP: cb_storm_load_template(); break;
		default: return;
	}
	estimate();
}

void cb_save_template()
{
	switch (selected_form) {
		case ICS203: cb_203_save_template(); break;
		case ICS205: cb_205_save_template(); break;
		case ICS205A: cb_205a_save_template(); break;
		case ICS206: cb_206_save_template(); break;
		case ICS213: cb_213_save_template(); break;
		case ICS214: cb_214_save_template(); break;
		case ICS216: cb_216_save_template(); break;
		case ICS309: cb_309_save_template(); break;
		case NETLOG: cb_netlog_save_template(); break;
		case HICS203: cb_hics203_save_template(); break;
		case HICS206: h206_cb_save_template(); break;
		case HICS213: h213_cb_save_template(); break;
		case HICS214: hics214_cb_save_template(); break;
		case RADIOGRAM: cb_rg_save_template(); break;
		case IARU: iaru_cb_save_template(); break;
		case CAP105: cap105_cb_save_template(); break;
		case CAP110: cap110_cb_save_template(); break;
		case PLAINTEXT: cb_pt_save_template(); break;
		case BLANK: cb_blank_save_template(); break;
		case CSV: cb_csv_save_template(); break;
		case CUSTOM: cb_custom_save_template(); break;
		case MARSDAILY: cb_mars_daily_save_template(); break;
		case MARSINEEI: cb_mars_ineei_save_template(); break;
		case MARSNET: cb_mars_net_save_template(); break;
		case MARSARMY: cb_mars_army_save_template(); break;
		case WXHC: cb_wxhc_save_template(); break;
		case SEVEREWX: cb_severe_wx_save_template(); break;
		case STORMREP: cb_storm_save_template(); break;
		default: return;
	}
}

void cb_save_as_template()
{
	switch (selected_form) {
		case ICS203: cb_203_save_as_template(); break;
		case ICS205: cb_205_save_as_template(); break;
		case ICS205A: cb_205a_save_as_template(); break;
		case ICS206: cb_206_save_as_template(); break;
		case ICS213: cb_213_save_as_template(); break;
		case ICS214: cb_214_save_as_template(); break;
		case ICS216: cb_216_save_as_template(); break;
		case ICS309: cb_309_save_as_template(); break;
		case NETLOG: cb_netlog_save_as_template(); break;
		case HICS203: cb_hics203_save_as_template(); break;
		case HICS206: h206_cb_save_as_template(); break;
		case HICS213: h213_cb_save_as_template(); break;
		case HICS214: hics214_cb_save_as_template(); break;
		case RADIOGRAM: cb_rg_save_as_template(); break;
		case IARU: iaru_cb_save_as_template(); break;
		case CAP105: cap105_cb_save_as_template(); break;
		case CAP110: cap110_cb_save_as_template(); break;
		case PLAINTEXT: cb_pt_save_as_template(); break;
		case BLANK: cb_blank_save_as_template(); break;
		case CSV: cb_csv_save_as_template(); break;
		case CUSTOM: cb_custom_save_as_template(); break;
		case MARSDAILY: cb_mars_daily_save_as_template(); break;
		case MARSINEEI: cb_mars_ineei_save_as_template(); break;
		case MARSNET: cb_mars_net_save_as_template(); break;
		case MARSARMY: cb_mars_army_save_as_template(); break;
		case WXHC: cb_wxhc_save_as_template(); break;
		case SEVEREWX: cb_severe_wx_save_as_template(); break;
		case STORMREP: cb_storm_save_as_template(); break;
		default: return;
	}
}

void cb_open()
{
	switch (selected_form) {
		case ICS203: cb_203_open(); break;
		case ICS205: cb_205_open(); break;
		case ICS205A: cb_205a_open(); break;
		case ICS206: cb_206_open(); break;
		case ICS213: cb_213_open(); break;
		case ICS214: cb_214_open(); break;
		case ICS216: cb_216_open(); break;
		case ICS309: cb_309_open(); break;
		case NETLOG: cb_netlog_open(); break;
		case HICS203: cb_hics203_open(); break;
		case HICS206: h206_cb_open(); break;
		case HICS213: h213_cb_open(); break;
		case HICS214: hics214_cb_open(); break;
		case RADIOGRAM: cb_rg_open(); break;
		case IARU: iaru_cb_open(); break;
		case CAP105: cap105_cb_open(); break;
		case CAP110: cap110_cb_open(); break;
		case PLAINTEXT: cb_pt_open(); break;
		case BLANK: cb_blank_open(); break;
		case CSV: cb_csv_open(); break;
		case CUSTOM: cb_custom_open(); break;
		case MARSDAILY: cb_mars_daily_open(); break;
		case MARSINEEI: cb_mars_ineei_open(); break;
		case MARSNET: cb_mars_net_open(); break;
		case MARSARMY: cb_mars_army_open(); break;
		case WXHC: cb_wxhc_open(); break;
		case SEVEREWX: cb_severe_wx_open(); break;
		case STORMREP: cb_storm_open(); break;
		default : return;
	}
	estimate();
}

void cb_save_as()
{
	switch (selected_form) {
		case ICS203: cb_203_save_as(); break;
		case ICS205: cb_205_save_as(); break;
		case ICS205A: cb_205a_save_as(); break;
		case ICS206: cb_206_save_as(); break;
		case ICS213: cb_213_save_as(); break;
		case ICS214: cb_214_save_as(); break;
		case ICS216: cb_216_save_as(); break;
		case ICS309: cb_309_save_as(); break;
		case NETLOG: cb_netlog_save_as(); break;
		case HICS203: cb_hics203_save_as(); break;
		case HICS206: h206_cb_save_as(); break;
		case HICS213: h213_cb_save_as(); break;
		case HICS214: hics214_cb_save_as(); break;
		case RADIOGRAM: cb_rg_save_as(); break;
		case IARU: iaru_cb_save_as(); break;
		case CAP105: cap105_cb_save_as(); break;
		case CAP110: cap110_cb_save_as(); break;
		case PLAINTEXT: cb_pt_save_as(); break;
		case MARSDAILY: cb_mars_daily_save_as(); break;
		case MARSINEEI: cb_mars_ineei_save_as(); break;
		case MARSNET: cb_mars_net_save_as(); break;
		case MARSARMY: cb_mars_army_save_as(); break;
		case WXHC: cb_wxhc_save_as(); break;
		case SEVEREWX: cb_severe_wx_save_as(); break;
		case STORMREP: cb_storm_save_as(); break;
		case BLANK: cb_blank_save_as(); break;
		case CSV: cb_csv_save_as(); break;
		case CUSTOM: cb_custom_save_as(); break;
		default: return;
	}
}

void cb_save()
{
	switch (selected_form) {
		case ICS203: cb_203_save(); break;
		case ICS205: cb_205_save(); break;
		case ICS205A: cb_205a_save(); break;
		case ICS206: cb_206_save(); break;
		case ICS213: cb_213_save(); break;
		case ICS214: cb_214_save(); break;
		case ICS216: cb_216_save(); break;
		case ICS309: cb_309_save(); break;
		case NETLOG: cb_netlog_save(); break;
		case HICS203: cb_hics203_save(); break;
		case HICS206: h206_cb_save(); break;
		case HICS213: h213_cb_save(); break;
		case HICS214: hics214_cb_save(); break;
		case RADIOGRAM: cb_rg_save(); break;
		case IARU: iaru_cb_save(); break;
		case CAP105: cap105_cb_save(); break;
		case CAP110: cap110_cb_save(); break;
		case PLAINTEXT: cb_pt_save(); break;
		case MARSDAILY: cb_mars_daily_save(); break;
		case MARSINEEI: cb_mars_ineei_save(); break;
		case MARSNET: cb_mars_net_save(); break;
		case MARSARMY: cb_mars_army_save(); break;
		case WXHC: cb_wxhc_save(); break;
		case SEVEREWX: cb_severe_wx_save(); break;
		case STORMREP: cb_storm_save(); break;
		case BLANK: cb_blank_save(); break;
		case CSV: cb_csv_save(); break;
		case CUSTOM: cb_custom_save(); break;
		default: return;
	}
}

void cb_html()
{
	switch (selected_form) {
		case ICS203: cb_203_html(); break;
		case ICS205: cb_205_html(); break;
		case ICS205A: cb_205a_html(); break;
		case ICS206: cb_206_html(); break;
		case ICS213: cb_213_html(); break;
		case ICS214: cb_214_html(); break;
		case ICS216: cb_216_html(); break;
		case ICS309: cb_309_html(); break;
		case NETLOG: cb_netlog_html(); break;
		case HICS203: cb_hics203_html(); break;
		case HICS206: h206_cb_html(); break;
		case HICS213: h213_cb_html(); break;
		case HICS214: hics214_cb_html(); break;
		case RADIOGRAM: cb_rg_html(); break;
		case IARU : iaru_cb_html(); break;
		case CAP105: cap105_cb_html(); break;
		case CAP110: cap110_cb_html(); break;
		case PLAINTEXT: cb_pt_html(); break;
		case MARSDAILY: cb_mars_daily_html(); break;
		case MARSINEEI: cb_mars_ineei_html(); break;
		case MARSNET: cb_mars_net_html(); break;
		case MARSARMY: cb_mars_army_html(); break;
		case WXHC: cb_wxhc_html(); break;
		case SEVEREWX: cb_severe_wx_html(); break;
		case STORMREP: cb_storm_html(); break;
		case BLANK: cb_blank_html(); break;
		case CSV: cb_csv_html(); break;
		case CUSTOM: cb_custom_html(false); break;
		default: return;
	}
}

void cb_html_fcopy()
{
	switch (selected_form) {
		case ICS203: cb_203_html(); break;
		case ICS205: cb_205_html(); break;
		case ICS205A: cb_205a_html(); break;
		case ICS206: cb_206_html(); break;
		case ICS213: cb_213_html(); break;
		case ICS214: cb_214_html(); break;
		case ICS216: cb_216_html(); break;
		case ICS309: cb_309_html(); break;
		case NETLOG: cb_netlog_html(); break;
		case HICS203: cb_hics203_html(); break;
		case HICS206: h206_cb_html(); break;
		case HICS213: h213_cb_html(); break;
		case HICS214: hics214_cb_html(); break;
		case RADIOGRAM: cb_rg_html_fcopy(); break;
		default:
			fl_alert2("Not implemented for this form type");
	}
}

void cb_text()
{
	switch (selected_form) {
		case ICS203: cb_203_textout(); break;
		case ICS205: cb_205_textout(); break;
		case ICS205A: cb_205a_textout(); break;
		case ICS206: cb_206_textout(); break;
		case ICS213: cb_213_textout(); break;
		case ICS214: cb_214_textout(); break;
		case ICS216: cb_216_textout(); break;
		case ICS309: cb_309_textout(); break;
		case NETLOG: cb_netlog_textout(); break;
		case HICS203: cb_hics203_textout(); break;
		case HICS206: h206_cb_textout(); break;
		case HICS213: h213_cb_textout(); break;
		case HICS214: hics214_cb_textout(); break;
		case RADIOGRAM: cb_rg_textout(); break;
		case IARU: iaru_cb_textout(); break;
		case CAP105: cap105_cb_textout(); break;
		case CAP110: cap110_cb_textout(); break;
		case PLAINTEXT: cb_pt_textout(); break;
		case MARSDAILY: cb_mars_daily_textout(); break;
		case MARSINEEI: cb_mars_ineei_textout(); break;
		case MARSNET: cb_mars_net_textout(); break;
		case MARSARMY: cb_mars_army_textout(); break;
		case WXHC: cb_wxhc_textout(); break;
		case SEVEREWX: cb_severe_wx_textout(); break;
		case STORMREP: cb_storm_textout(); break;
		case CSV: cb_csv_textout(); break;
		case CUSTOM: cb_custom_textout(); break;
		case BLANK: cb_blank_textout(); break;
		default : return;
	}
}

//extern void disconnect_from_fldigi();

void cb_exit()
{
	progStatus.saveLastState();
	FSEL::destroy();

	Fl::remove_timeout(mainloop);

	if (progStatus.ID_restore) restore_id();

	close_xmlrpc();
	close_server();

	debug::stop();

	if (expert_dialog) delete expert_dialog;
	if (tyro_dialog) delete tyro_dialog;

	exit(0);
}

void exit_main(Fl_Widget *w)
{
	if (Fl::event_key() == FL_Escape)
		return;
	cb_exit();
}

void cb_About()
{
	std::string strver = _("Version ");
	strver.append(PACKAGE_VERSION);
	fl_alert2("%s", strver.c_str());
}

void cb_folders()
{
	open_url(FLMSG_dir.c_str(), 1);
}

void show_filename(string p)
{
	switch (selected_form) {
		case ICS203:
			base_203_filename = fl_filename_name(p.c_str());
			break;
		case ICS205:
			base_205_filename = fl_filename_name(p.c_str());
			break;
		case ICS205A:
			base_205a_filename = fl_filename_name(p.c_str());
			break;
		case ICS206:
			base_206_filename = fl_filename_name(p.c_str());
			break;
		case ICS213:
			base_213_filename = fl_filename_name(p.c_str());
			break;
		case ICS214:
			base_214_filename = fl_filename_name(p.c_str());
			break;
		case ICS216:
			base_216_filename = fl_filename_name(p.c_str());
			break;
		case ICS309:
			base_309_filename = fl_filename_name(p.c_str());
			break;
		case NETLOG:
			base_netlog_filename = fl_filename_name(p.c_str());
			break;
		case HICS203:
			base_hics203_filename = fl_filename_name(p.c_str());
			break;
		case HICS206:
			h206_base_filename = fl_filename_name(p.c_str());
			break;
		case HICS213:
			h213_base_filename = fl_filename_name(p.c_str());
			break;
		case HICS214:
			hics214_base_filename = fl_filename_name(p.c_str());
			break;
		case RADIOGRAM:
			base_rg_filename = fl_filename_name(p.c_str());
			break;
		case IARU:
			iaru_base_filename = fl_filename_name(p.c_str());
			break;
		case CAP105:
			cap105_base_filename = fl_filename_name(p.c_str());
			break;
		case CAP110:
			cap110_base_filename = fl_filename_name(p.c_str());
			break;
		case PLAINTEXT:
			base_pt_filename = fl_filename_name(p.c_str());
			break;
		case MARSDAILY:
			base_mars_daily_filename = fl_filename_name(p.c_str());
			break;
		case MARSINEEI:
			base_mars_ineei_filename = fl_filename_name(p.c_str());
			break;
		case MARSNET:
			base_mars_net_filename = fl_filename_name(p.c_str());
			break;
		case MARSARMY:
			base_mars_army_filename = fl_filename_name(p.c_str());
			break;
		case WXHC:
			base_wxhc_filename = fl_filename_name(p.c_str());
			break;
		case SEVEREWX:
			base_severe_wx_filename = fl_filename_name(p.c_str());
			break;
		case STORMREP:
			base_storm_filename = fl_filename_name(p.c_str());
			break;
		case BLANK:
			base_blank_filename = fl_filename_name(p.c_str());
			break;
		case CSV:
			base_csv_filename = fl_filename_name(p.c_str());
			break;
		case CUSTOM:
			base_custom_filename = fl_filename_name(p.c_str());
			break;
		case TRANSFER:
			base_transfer_filename = fl_filename_name(p.c_str());
			break;
		case CUSTOM_TRANSFER:
			break;
		default:
			return;
	}
	txt_filename->value(fl_filename_name(p.c_str()));
	txt_filename->redraw();
}

#define KNAME "fllog"

#if !defined(__APPLE__) && !defined(__WOE32__) && USE_X
Pixmap  flmsg_icon_pixmap;

void make_pixmap(Pixmap *xpm, const char **data)
{
	Fl_Window w(0,0, KNAME);
	w.xclass(KNAME);
	w.show();
	w.make_current();
	Fl_Pixmap icon(data);
	int maxd = (icon.w() > icon.h()) ? icon.w() : icon.h();
	*xpm = fl_create_offscreen(maxd, maxd);
	fl_begin_offscreen(*xpm);
	fl_color(FL_BACKGROUND_COLOR);
	fl_rectf(0, 0, maxd, maxd);
	icon.draw(maxd - icon.w(), maxd - icon.h());
	fl_end_offscreen();
}

#endif


void default_form()
{
	selected_form = progStatus.tab;
	select_form(selected_form);
	cb_new();
}

#if FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR == 3
int default_handler(int event)
{
	if (event != FL_SHORTCUT)
		return 0;

	else if (Fl::event_ctrl())  {
		Fl_Widget* w = Fl::focus();
		return w->handle(FL_KEYBOARD);
	}

	return 0;
}
#endif

#ifdef __APPLE__
// registered file drop call back to operating system
void open_callback(const char *param)
{
	string pathname = param;
	if (pathname.find(WRAP_EXT) != string::npos)
		wrap_import(pathname.c_str());
	else {
		read_data_file(pathname);
		show_filename(pathname);
	}
}
#endif

void after_start(void *)
{
	check_mycall();

	def_203_filename = ICS_msg_dir;
	def_203_filename.append("default").append(F203_EXT);
	def_203_TemplateName = ICS_tmp_dir;
	def_203_TemplateName.append("default").append(T203_EXT);

	def_205_filename = ICS_msg_dir;
	def_205_filename.append("default").append(F205_EXT);
	def_205_TemplateName = ICS_tmp_dir;
	def_205_TemplateName.append("default").append(T205_EXT);

	def_205a_filename = ICS_msg_dir;
	def_205a_filename.append("default").append(F205A_EXT);
	def_205a_TemplateName = ICS_tmp_dir;
	def_205a_TemplateName.append("default").append(T205A_EXT);

	def_206_filename = ICS_msg_dir;
	def_206_filename.append("default").append(F206_EXT);
	def_206_TemplateName = ICS_tmp_dir;
	def_206_TemplateName.append("default").append(T206_EXT);

	def_213_filename = ICS_msg_dir;
	def_213_filename.append("default").append(F213_EXT);
	def_213_TemplateName = ICS_tmp_dir;
	def_213_TemplateName.append("default").append(T213_EXT);

	def_214_filename = ICS_msg_dir;
	def_214_filename.append("default").append(F214_EXT);
	def_214_TemplateName = ICS_tmp_dir;
	def_214_TemplateName.append("default").append(T214_EXT);

	def_216_filename = ICS_msg_dir;
	def_216_filename.append("default").append(F216_EXT);
	def_216_TemplateName = ICS_tmp_dir;
	def_216_TemplateName.append("default").append(T216_EXT);

	def_309_filename = ICS_msg_dir;
	def_309_filename.append("default").append(F309_EXT);
	def_309_TemplateName = ICS_tmp_dir;
	def_309_TemplateName.append("default").append(T309_EXT);

	def_netlog_filename = ICS_msg_dir;
	def_netlog_filename.append("default").append(FNET_EXT);
	def_netlog_TemplateName = ICS_tmp_dir;
	def_netlog_TemplateName.append("default").append(TNET_EXT);

	def_hics203_filename = ICS_msg_dir;
	def_hics203_filename.append("default").append(HF203_EXT);
	def_hics203_TemplateName = ICS_tmp_dir;
	def_hics203_TemplateName.append("default").append(HT203_EXT);

	h206_def_filename = ICS_msg_dir;
	h206_def_filename.append("default").append(HF206_EXT);
	h206_def_template_name = ICS_tmp_dir;
	h206_def_template_name.append("default").append(HT206_EXT);

	h213_def_filename = ICS_msg_dir;
	h213_def_filename.append("default").append(HF213_EXT);
	h213_def_template_name = ICS_tmp_dir;
	h213_def_template_name.append("default").append(HT213_EXT);

	hics214_def_filename = ICS_msg_dir;
	hics214_def_filename.append("default").append(HF214_EXT);
	hics214_template_name = ICS_tmp_dir;
	hics214_template_name.append("default").append(HT214_EXT);

	def_rg_filename = ICS_msg_dir;
	def_rg_filename.append("default").append(RGFILE_EXT);
	def_rg_TemplateName = ICS_tmp_dir;
	def_rg_TemplateName.append("default").append(RGTEMP_EXT);

	iaru_def_filename = ICS_msg_dir;
	iaru_def_filename.append("default").append(IARU_FILE_EXT);
	iaru_def_template_name = ICS_tmp_dir;
	iaru_def_template_name.append("default").append(IARU_TEMP_EXT);

	cap105_def_filename = ICS_msg_dir;
	cap105_def_filename.append("default").append(CAP105_FILE_EXT);
	cap105_def_template_name = ICS_tmp_dir;
	cap105_def_template_name.append("default").append(CAP105_TEMP_EXT);
	cap105_set_choices();

	cap110_def_filename = ICS_msg_dir;
	cap110_def_filename.append("default").append(CAP105_FILE_EXT);
	cap110_def_template_name = ICS_tmp_dir;
	cap110_def_template_name.append("default").append(CAP105_TEMP_EXT);

	def_pt_filename = ICS_msg_dir;
	def_pt_filename.append("default").append(PTFILE_EXT);
	def_pt_TemplateName = ICS_tmp_dir;
	def_pt_TemplateName.append("default").append(PTTEMP_EXT);

	def_blank_filename = ICS_msg_dir;
	def_blank_filename.append("default").append(BLANKFILE_EXT);
	def_blank_TemplateName = ICS_tmp_dir;
	def_blank_TemplateName.append("default").append(BLANKTEMP_EXT);

	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append("default").append(CSVFILE_EXT);
	def_csv_TemplateName = ICS_tmp_dir;
	def_csv_TemplateName.append("default").append(CSVTEMP_EXT);

	def_custom_filename = ICS_msg_dir;
	def_custom_filename.append("default").append(CUSTOMFILE_EXT);
	def_custom_TemplateName = ICS_tmp_dir;
	def_custom_TemplateName.append("default").append(CUSTOMTEMP_EXT);

	def_mars_daily_filename = ICS_msg_dir;
	def_mars_daily_filename.append("default").append(FMARSDAILY_EXT);
	def_mars_daily_TemplateName = ICS_tmp_dir;
	def_mars_daily_TemplateName.append("default").append(TMARSDAILY_EXT);

	def_mars_ineei_filename = ICS_msg_dir;
	def_mars_ineei_filename.append("default").append(FMARSINEEI_EXT);
	def_mars_ineei_TemplateName = ICS_tmp_dir;
	def_mars_ineei_TemplateName.append("default").append(TMARSINEEI_EXT);

	def_mars_net_filename = ICS_msg_dir;
	def_mars_net_filename.append("default").append(FMARSNET_EXT);
	def_mars_net_TemplateName = ICS_tmp_dir;
	def_mars_net_TemplateName.append("default").append(TMARSNET_EXT);

	def_mars_army_filename = ICS_msg_dir;
	def_mars_army_filename.append("default").append(FMARSARMY_EXT);
	def_mars_army_TemplateName = ICS_tmp_dir;
	def_mars_army_TemplateName.append("default").append(TMARSARMY_EXT);

	def_wxhc_filename = ICS_msg_dir;
	def_wxhc_filename.append("default").append(FWXHC_EXT);
	def_wxhc_TemplateName = ICS_tmp_dir;
	def_wxhc_TemplateName.append("default").append(TWXHC_EXT);

	def_severe_wx_filename = ICS_msg_dir;
	def_severe_wx_filename.append("default").append(FSWX_EXT);
	def_severe_wx_TemplateName = ICS_tmp_dir;
	def_severe_wx_TemplateName.append("default").append(TSWX_EXT);

	def_storm_filename = ICS_msg_dir;
	def_storm_filename.append("default").append(FSTRM_EXT);
	def_storm_TemplateName = ICS_tmp_dir;
	def_storm_TemplateName.append("default").append(TSTRM_EXT);

	{
		if (!cmd_fname.empty()) {
			if (cmd_fname.find(WRAP_EXT) != string::npos)
				wrap_import(cmd_fname.c_str());
			else {
				read_data_file(cmd_fname);
				show_filename(cmd_fname);
			}
			estimate();
		} else
			default_form();
	// Check to see what io mode FLDIGI is in.
		std::string io_mode = get_io_mode();
		int flag = 0;
		if(!io_mode.empty()) {
			flag = strncmp(io_mode.c_str(), "ARQ", 3);
			if(flag != 0) {
				flag = fl_choice2(_("KISS interface active! Switch FLDIGI to ARQ?"),
					_("No"), _("Yes"), NULL);
				if(flag == 1)
					enable_arq();
			}
		}
	}

#ifdef __APPLE__
	fl_open_callback(open_callback);
#endif

	init_flmsg_arq();

}

int main(int argc, char *argv[])
{
	bool have_title = false;
	if (argc > 1) {
		if (strcasecmp("--help", argv[1]) == 0) {
			int i = 0;
			while (options[i] != NULL) {
				printf("%s\n", options[i]);
				i++;
			}
			return 0;
		}
		if (strcasecmp("--version", argv[1]) == 0) {
			printf("Version: %s\n", VERSION);
			return 0;
		}
		for (int i = 0; i < argc; i++)
			if (strcasecmp("-ti", argv[i]) == 0) have_title = true;
	}

	Fl::lock();

	Fl::scheme("gtk+");

	int arg_idx;

	FLMSG_dir.clear();

	if (Fl::args(argc, argv, arg_idx, parse_args) != argc)
		showoptions();

	size_t p;
	string appdir = argv[0];;

#ifdef __WOE32__
	if (FLMSG_dir.empty()) {
		p = appdir.find("FL_APPS\\");
		if (p == string::npos)
			p = appdir.find("FL_APPS/");
		if (p != string::npos) {
			FLMSG_dir.assign(appdir.substr(0, p + 8));
			FLMSG_dir.append("NBEMS.files\\");
		} else {
			char dirbuf[FL_PATH_MAX + 1];
			fl_filename_expand(dirbuf, sizeof(dirbuf) -1, "$USERPROFILE\\");
			FLMSG_dir.assign(dirbuf);
			FLMSG_dir.append("NBEMS.files/\\");
		}
	}
#else
	char dirbuf[FL_PATH_MAX + 1];
	fl_filename_absolute(dirbuf, FL_PATH_MAX, argv[0]);
	appdir.assign(dirbuf);
	p = appdir.rfind("flmsg");
	if (p != string::npos)
		appdir.erase(p);
	p = appdir.find("FL_APPS/");
	if (p == string::npos) p = appdir.find("ARC_MSG/");
	if (p != string::npos) {
		FLMSG_dir.assign(appdir.substr(0, p + 8));
		FLMSG_dir.append("NBEMS.files/");
	} else if (FLMSG_dir.empty()) {
		fl_filename_expand(dirbuf, FL_PATH_MAX, "$HOME/");
		FLMSG_dir = dirbuf;
		FLMSG_dir.append(".nbems/");
	}
#endif

	progStatus.loadLastState();

	expert_dialog = flmsg_dialog();
	tyro_dialog = edit_view_dialog();

	if (!progStatus.UI_default) {
		int answer = fl_choice(
			"FLMSG: Select Default User Interface\n\n\n",
			"Communicator / Expert",
			"Service Agency / Simple",
			NULL );
		progStatus.UI_default = 1;
		progStatus.UI_expert = !answer;
	}

	if (progStatus.UI_expert)
		mainwindow = expert_dialog;
	else
		mainwindow = tyro_dialog;

	mainwindow->callback(exit_main);
	set_rg_choices();
	iaru_set_choices();
	set_datetime_widgets();

#if FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR == 3
	Fl::add_handler(default_handler);
#endif

	config_dialog = create_config_dialog();

	header_window = headers_dialog();

	btn_utc_format0->value(progStatus.UTC == 0);
	btn_utc_format1->value(progStatus.UTC == 1);
	btn_utc_format2->value(progStatus.UTC == 2);
	btn_utc_format3->value(progStatus.UTC == 3);
	btn_utc_format4->value(progStatus.UTC == 4);
	btn_utc_format5->value(progStatus.UTC == 5);

	btn_dtformat0->value(progStatus.dtformat == 0);
	btn_dtformat1->value(progStatus.dtformat == 1);
	btn_dtformat2->value(progStatus.dtformat == 2);
	btn_dtformat3->value(progStatus.dtformat == 3);

	cnt_wpl->value(progStatus.wpl);

	Fl_File_Icon::load_system_icons();
	FSEL::create();

	checkdirectories();

	string logname = FLMSG_log_dir;
	logname.append("flmsg.log");
	rotate_log(logname);

	load_custom_menu();

	string debug_file = FLMSG_dir;
	debug_file.append("debug_log_").append(sz_srvr_portnbr).append(".txt");
	debug::start(debug_file.c_str());

	LOG_INFO("FLMSG_dir        %s", FLMSG_dir.c_str());
	LOG_INFO("ARQ_dir          %s", ARQ_dir.c_str());
	LOG_INFO("ARQ_files_dir    %s", ARQ_files_dir.c_str());
	LOG_INFO("ARQ_recv_dir     %s", ARQ_recv_dir.c_str());
	LOG_INFO("ARQ_send_dir     %s", ARQ_send_dir.c_str());
	LOG_INFO("WRAP_dir         %s", WRAP_dir.c_str());
	LOG_INFO("WRAP_recv_dir    %s", WRAP_recv_dir.c_str());
	LOG_INFO("WRAP_send_dir    %s", WRAP_send_dir.c_str());
//	LOG_INFO("WRAP_auto_dir    %s", WRAP_auto_dir.c_str());
	LOG_INFO("ICS_dir          %s", ICS_dir.c_str());
	LOG_INFO("ICS_msg_dir      %s", ICS_msg_dir.c_str());
	LOG_INFO("ICS_tmp_dir      %s", ICS_tmp_dir.c_str());
	LOG_INFO("CSV_dir          %s", CSV_dir.c_str());
	LOG_INFO("CUSTOM_dir       %s", CUSTOM_dir.c_str());
	LOG_INFO("Transfer dir     %s", XFR_dir.c_str());
	LOG_INFO("FLMSG_temp_dir   %s", FLMSG_temp_dir.c_str());
	LOG_INFO("FLMSG_log_dir    %s", FLMSG_log_dir.c_str());

	if (!parse_info.empty())
		LOG_INFO("%s", parse_info.c_str());

	start_web_server();

	if (!mongoose_msgs.empty())
		LOG_INFO("%s", mongoose_msgs.c_str());

	if (printme) {
#ifdef __APPLE_
		fl_open_display();
#endif
		print_and_exit();
		if (exit_after_print) {
			if (server) mg_destroy_server(&server);
			return 0;
		}
	}

	open_xmlrpc();
	xmlrpc_thread = new pthread_t;
	if (pthread_create(xmlrpc_thread, NULL, xmlrpc_loop, NULL)) {
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	expert_dialog->size_range(570, 492);
	expert_dialog->resize(
		progStatus.mainX, progStatus.mainY,
		progStatus.expertW, progStatus.expertH);

	tyro_dialog->resize( progStatus.mainX, progStatus.mainY, tyro_dialog->w(), tyro_dialog->h());
	
#if defined(__WOE32__)
#  ifndef IDI_ICON
#    define IDI_ICON 101
#  endif
	mainwindow->icon((char*)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));
	mainwindow->show (argc, argv);
#elif !defined(__APPLE__)
	make_pixmap(&flmsg_icon_pixmap, flmsg_icon);
	mainwindow->icon((char *)flmsg_icon_pixmap);
	mainwindow->show(argc, argv);
#else
	mainwindow->show(argc, argv);
#endif

	if (!have_title) {
		string main_label;
		main_label = PACKAGE_NAME;
		main_label.append(": ").append(PACKAGE_VERSION);
		expert_dialog->label(main_label.c_str());
		tyro_dialog->label(main_label.c_str());
	}

	Fl::add_timeout(0.10, after_start);

	int result = Fl::run();

	if (server) mg_destroy_server(&server);

	return result;
}

void print_and_exit()
{
	if (!cmd_fname.empty()) {
		if (cmd_fname.find(WRAP_EXT) != string::npos) {
			wrap_import(cmd_fname.c_str());
		} else {
			read_data_file(cmd_fname);
		}

		switch (selected_form) {
		case ICS203 :
			cb_203_save();
			cb_203_html();
			break;
		case ICS205 :
			cb_205_save();
			cb_205_html();
			break;
		case ICS205A :
			cb_205a_save();
			cb_205a_html();
			break;
		case ICS206 :
			cb_206_save();
			cb_206_html();
			break;
		case ICS213 :
			cb_213_save();
			cb_213_html();
			break;
		case ICS214 :
			cb_214_save();
			cb_214_html();
			break;
		case ICS216 :
			cb_216_save();
			cb_216_html();
			break;
		case ICS309 :
			cb_309_save();
			cb_309_html();
			break;
		case NETLOG :
			cb_netlog_save();
			cb_netlog_html();
			break;
		case HICS203 :
			cb_hics203_save();
			cb_hics203_html();
			break;
		case HICS206 :
			h206_cb_save();
			h206_cb_html();
			break;
		case HICS213 :
			h213_cb_save();
			h213_cb_html();
			break;
		case HICS214 :
			hics214_cb_save();
			hics214_cb_html();
			break;
		case RADIOGRAM :
			cb_rg_save();
			cb_rg_html();
			break;
		case PLAINTEXT :
			cb_pt_save();
			cb_pt_html();
			break;
		case BLANK :
			cb_blank_save();
			cb_blank_html();
			break;
		case CSV :
			cb_csv_save();
			cb_csv_html();
			break;
		case CUSTOM :
			cb_custom_save();
			cb_custom_html(true);
			break;
		case MARSDAILY :
			cb_mars_daily_save();
			cb_mars_daily_html();
			break;
		case MARSINEEI :
			cb_mars_ineei_save();
			cb_mars_ineei_html();
			break;
		case MARSNET :
			cb_mars_net_save();
			cb_mars_net_html();
			break;
		case MARSARMY :
			cb_mars_army_save();
			cb_mars_army_html();
			break;
		case WXHC :
			cb_wxhc_save();
			cb_wxhc_html();
			break;
		case SEVEREWX :
			cb_severe_wx_save();
			cb_severe_wx_html();
			break;
		case STORMREP :
			cb_storm_save();
			cb_storm_html();
			break;
		}
	}
}

void drop_box_changed()
{
	string 	buffer = drop_box->value();
	size_t n;
	drop_box->value("");
	drop_box->redraw();
	if ((n = buffer.find("file:///")) != string::npos)
		buffer.erase(0, n + 7);
	if ((buffer.find(":\\")) != string::npos || (buffer.find("/") == 0)) {
		while ((n = buffer.find('\n')) != string::npos)
			buffer.erase(n, 1);
		while ((n = buffer.find('\r')) != string::npos)
			buffer.erase(n, 1);
		if (buffer.find(WRAP_EXT) != string::npos)
			wrap_import(buffer.c_str());
		else
			read_data_file(buffer.c_str());
	} else // try to extract as a text buffer
		extract_text(buffer, NULL);
	estimate();
}

void drop_file_changed()
{
	string 	buffer = drop_file->value();
	size_t n;
	drop_file->value("");
	drop_file->redraw();
	if ((n = buffer.find("file:///")) != string::npos)
		buffer.erase(0, n + 7);
	if ((buffer.find(":\\")) != string::npos || (buffer.find("/") == 0)) {
		while ((n = buffer.find('\n')) != string::npos)
			buffer.erase(n, 1);
		while ((n = buffer.find('\r')) != string::npos)
			buffer.erase(n, 1);
		if (buffer.find(WRAP_EXT) != string::npos)
			wrap_import(buffer.c_str());
		else
			read_data_file(buffer.c_str());
	} else // try to extract as a text buffer
		extract_text(buffer, NULL);
	estimate();
}

void checkdirectories(void)
{
	struct DIRS {
		string& dir;
		const char* suffix;
		void (*new_dir_func)(void);
	};
#ifdef __WIN32__
	DIRS FLMSG_dirs[] = {
		{ FLMSG_dir,      0, 0 },
		{ ARQ_dir,        "ARQ", 0 },
		{ ARQ_files_dir,  "ARQ\\files", 0 },
		{ ARQ_recv_dir,   "ARQ\\recv", 0 },
		{ ARQ_send_dir,   "ARQ\\send", 0 },
		{ WRAP_dir,       "WRAP", 0 },
		{ WRAP_recv_dir,  "WRAP\\recv", 0 },
		{ WRAP_send_dir,  "WRAP\\send", 0 },
		{ ICS_dir,        "ICS", 0 },
		{ ICS_msg_dir,    "ICS\\messages", 0 },
		{ ICS_tmp_dir,    "ICS\\templates", 0 },
		{ CSV_dir,        "CSV", 0},
		{ CUSTOM_dir,     "CUSTOM", 0},
		{ XFR_dir,        "TRANSFERS", 0},
		{ FLMSG_temp_dir, "temp_files", 0 },
		{ FLMSG_log_dir,  "log_files", 0 }
	};
#else
	DIRS FLMSG_dirs[] = {
		{ FLMSG_dir,      0, 0 },
		{ ARQ_dir,        "ARQ", 0 },
		{ ARQ_files_dir,  "ARQ/files", 0 },
		{ ARQ_recv_dir,   "ARQ/recv", 0 },
		{ ARQ_send_dir,   "ARQ/send", 0 },
		{ WRAP_dir,       "WRAP", 0 },
		{ WRAP_recv_dir,  "WRAP/recv", 0 },
		{ WRAP_send_dir,  "WRAP/send", 0 },
		{ ICS_dir,        "ICS", 0 },
		{ ICS_msg_dir,    "ICS/messages", 0 },
		{ ICS_tmp_dir,    "ICS/templates", 0 },
		{ CSV_dir,        "CSV", 0},
		{ CUSTOM_dir,     "CUSTOM", 0},
		{ XFR_dir,        "TRANSFERS", 0},
		{ FLMSG_temp_dir, "temp_files", 0 },
		{ FLMSG_log_dir,  "log_files", 0 }
	};
#endif
	int r;

	for (size_t i = 0; i < sizeof(FLMSG_dirs)/sizeof(*FLMSG_dirs); i++) {
		if (FLMSG_dirs[i].dir.empty() && FLMSG_dirs[i].suffix)
			FLMSG_dirs[i].dir.assign(FLMSG_dir).append(FLMSG_dirs[i].suffix).append(PATH_SEP);

		if ((r = mkdir(FLMSG_dirs[i].dir.c_str(), 0777)) == -1 && errno != EEXIST) {
			cerr << _("Could not make directory") << ' ' << FLMSG_dirs[i].dir
			     << ": " << strerror(errno) << '\n';
			exit(EXIT_FAILURE);
		}
		else if (r == 0 && FLMSG_dirs[i].new_dir_func)
			FLMSG_dirs[i].new_dir_func();
	}

	if (FLMSG_dir.find("FL_APPS") != std::string::npos) {
		ICS_dir = FLMSG_dir;
#if __WIN32__
		ICS_dir.append("..\\..\\");
#else
		ICS_dir.append("../../");
#endif
		ICS_msg_dir.clear();
		ICS_tmp_dir.clear();
		CUSTOM_dir.clear();
		DIRS MSG_dirs[] = {
			{ ICS_msg_dir, "flmsg.messages", 0},
			{ ICS_tmp_dir, "flmsg.templates", 0},
			{ CUSTOM_dir,  "flmsg.forms", 0},
		};
		for (size_t i = 0; i < sizeof(MSG_dirs) / sizeof(*MSG_dirs); i++) {
			if (MSG_dirs[i].dir.empty() && MSG_dirs[i].suffix)
				MSG_dirs[i].dir.assign(ICS_dir).append(MSG_dirs[i].suffix).append(PATH_SEP);

			r = mkdir(MSG_dirs[i].dir.c_str(), 0777);
			if (r == -1 && errno != EEXIST) {
				cerr << _("Could not make directory") << ' ' << MSG_dirs[i].dir
					<< ": " << strerror(errno) << '\n';
				exit(EXIT_FAILURE);
			}
			else if (r == 0 && MSG_dirs[i].new_dir_func)
				MSG_dirs[i].new_dir_func();
		}
	}

}

void showoptions()
{
	if (!optionswindow) {
		optionswindow = optionsdialog();
		for (int i = 0; options[i] != 0; i++)
			brwsOptions->add(options[i]);
	}
	optionswindow->show();
}

void closeoptions()
{
	optionswindow->hide();
}
//extern Fl_Group	*tab_headers;

void set_config_values()
{
	btn_dtformat0->value(progStatus.dtformat == 0);
	btn_dtformat1->value(progStatus.dtformat == 1);
	btn_dtformat2->value(progStatus.dtformat == 2);

	btn_utc_format0->value(progStatus.UTC == 0);
	btn_utc_format1->value(progStatus.UTC == 1);
	btn_utc_format2->value(progStatus.UTC == 2);
	btn_utc_format3->value(progStatus.UTC == 3);
	btn_utc_format4->value(progStatus.UTC == 4);
	btn_utc_format5->value(progStatus.UTC == 5);

	txt_my_call->value(progStatus.my_call.c_str());
	txt_my_name->value(progStatus.my_name.c_str());
	txt_my_addr->value(progStatus.my_addr.c_str());
	txt_my_city->value(progStatus.my_city.c_str());
	txt_my_tel->value(progStatus.my_tel.c_str());

	cnt_wpl->value(progStatus.wpl);

	txt_rgnbr->value(progStatus.rgnbr.c_str());
	btn_rgnbr_fname->value(progStatus.rgnbr_fname);

	btn_open_on_export->value(progStatus.open_on_export);
	btn_use_compression->value(progStatus.use_compression);
	txt_sernbr->value(progStatus.sernbr.c_str());
	btn_sernbr_fname->value(progStatus.sernbr_fname);
	btn_call_fname->value(progStatus.call_fname);
	cbo_dt_fname->index(progStatus.dt_fname);

	txt_mars_roster_file->value(progStatus.mars_roster_file.c_str());

	txt_socket_addr->value(progStatus.xmlrpc_addr.c_str());
	txt_socket_port->value(progStatus.xmlrpc_port.c_str());

}

void cb_config_date_time()
{
	set_config_values();
	tabs_config->value(tab_date_time);
	config_dialog->show();
}

void cb_config_personal()
{
	set_config_values();
	tabs_config->value(tab_personal);
	config_dialog->show();
}

void cb_config_radiogram()
{
	set_config_values();
	tabs_config->value(tab_config_radiogram);
	config_dialog->show();
}

void cb_config_files()
{
	set_config_values();
	tabs_config->value(tab_files);
	config_dialog->show();
}

//void cb_config_socket()
//{
//	set_config_values();
//	tabs_config->value(tab_socket);
//	config_dialog->show();
//}

void cb_config_arq()
{
	set_config_values();
	tabs_config->value(tab_arq);
	config_dialog->show();
}

void cb_config_UI()
{
	set_config_values();
	tabs_config->value(tab_UI);
	config_dialog->show();
}

void show_help()
{
	open_url("http://www.w1hkj.com/flmsg-help/index.html");
}

void custom_download()
{
	open_url("https://sourceforge.net/projects/fldigi/files/flmsg/");
}

int parse_args(int argc, char **argv, int& idx)
{
	if (strstr(argv[idx], "--p")) {
		printme = true;
		exit_after_print = true;
		idx++;
		parse_info.append("parsed --p\n");
		return 1;
	}

	if (strstr(argv[idx], "--b")) {
		printme = true;
		idx++;
		parse_info.append("parsed --b\n");
		return 1;
	}

	if (strstr(argv[idx], "--flmsg-dir")) {
		idx++;
		string tmp = argv[idx];
		if (!tmp.empty()) FLMSG_dir_default = tmp;
		size_t p = string::npos;
		while ( (p = FLMSG_dir_default.find("\\")) != string::npos)
			FLMSG_dir_default[p] = '/';
		if (FLMSG_dir_default[FLMSG_dir_default.length() - 1] != '/')
			FLMSG_dir_default += '/';
		FLMSG_dir = FLMSG_dir_default;
		parse_info.append("parsed --flmsg-dir ");
		parse_info.append(FLMSG_dir).append("\n");
		idx++;
		return 2;
	}

	if (strstr(argv[idx], "--server-port")) {
		idx++;
		int port = 0;
		if (sscanf(argv[idx], "%d", &port) == 1)
			srvr_portnbr = port;
		idx++;
		return 2;
	}
/*
	if (strstr(argv[idx], "--auto-dir")) {
		idx++;
		string tmp = argv[idx];
		if (!tmp.empty()) WRAP_auto_dir = tmp;
		size_t p = string::npos;
		while ( (p = WRAP_auto_dir.find("\\")) != string::npos)
			WRAP_auto_dir[p] = '/';
		parse_info.append("parsed --autodir ");
		parse_info.append(WRAP_auto_dir).append("\n");
		idx++;
		return 2;
	}
*/

	if ( argv[idx][0] == '-' ) {
		return 0;
	}

	parse_info.append("parsed filename: ").append(argv[idx]).append("\n");

	string fname = argv[idx];
	if (fname.find(DATAFILE_EXT) != string::npos ||
		fname.find(DATATEMP_EXT) != string::npos ||

		fname.find(F203_EXT) != string::npos ||
		fname.find(T203_EXT) != string::npos ||

		fname.find(F205_EXT) != string::npos ||
		fname.find(T205_EXT) != string::npos ||

		fname.find(F205A_EXT) != string::npos ||
		fname.find(T205A_EXT) != string::npos ||

		fname.find(F206_EXT) != string::npos ||
		fname.find(T206_EXT) != string::npos ||

		fname.find(F213_EXT) != string::npos ||
		fname.find(T213_EXT) != string::npos ||

		fname.find(F214_EXT) != string::npos ||
		fname.find(T214_EXT) != string::npos ||

		fname.find(F216_EXT) != string::npos ||
		fname.find(T216_EXT) != string::npos ||

		fname.find(F309_EXT) != string::npos ||
		fname.find(T309_EXT) != string::npos ||

		fname.find(FNET_EXT) != string::npos ||
		fname.find(TNET_EXT) != string::npos ||

		fname.find(HF203_EXT) != string::npos ||
		fname.find(HT203_EXT) != string::npos ||

		fname.find(HF206_EXT) != string::npos ||
		fname.find(HT206_EXT) != string::npos ||

		fname.find(HF213_EXT) != string::npos ||
		fname.find(HT213_EXT) != string::npos ||

		fname.find(HF214_EXT) != string::npos ||
		fname.find(HT214_EXT) != string::npos ||

		fname.find(RGFILE_EXT) != string::npos ||
		fname.find(RGTEMP_EXT) != string::npos ||

		fname.find(PTFILE_EXT) != string::npos ||
		fname.find(PTTEMP_EXT) != string::npos ||

		fname.find(BLANKFILE_EXT) != string::npos ||
		fname.find(BLANKTEMP_EXT) != string::npos ||

		fname.find(CSVFILE_EXT) != string::npos ||
		fname.find(CSVTEMP_EXT) != string::npos ||

		fname.find(CUSTOMFILE_EXT) != string::npos ||
		fname.find(CUSTOMTEMP_EXT) != string::npos ||

		fname.find(FMARSDAILY_EXT) != string::npos ||
		fname.find(TMARSDAILY_EXT) != string::npos ||

		fname.find(FMARSINEEI_EXT) != string::npos ||
		fname.find(TMARSINEEI_EXT) != string::npos ||

		fname.find(FMARSNET_EXT) != string::npos ||
		fname.find(TMARSNET_EXT) != string::npos ||

		fname.find(FMARSARMY_EXT) != string::npos ||
		fname.find(TMARSARMY_EXT) != string::npos ||

		fname.find(FWXHC_EXT) != string::npos ||
		fname.find(TWXHC_EXT) != string::npos ||

		fname.find(FSWX_EXT) != string::npos ||
		fname.find(TSWX_EXT) != string::npos ||

		fname.find(IARU_FILE_EXT) != string::npos ||
		fname.find(IARU_TEMP_EXT) != string::npos ||

		fname.find(CAP105_FILE_EXT) != string::npos ||
		fname.find(CAP105_TEMP_EXT) != string::npos ||

		fname.find(CAP110_FILE_EXT) != string::npos ||
		fname.find(CAP110_TEMP_EXT) != string::npos ||

		fname.find(TRANSFER_EXT) != string::npos ||

		fname.find(WRAP_EXT) != string::npos ) {
		cmd_fname = fname;
	}
	idx++;
	return 1;
}

void open_url(const char* url, int folder)
{
//LOG_INFO("%s", url);
#ifndef __WOE32__

	const char *folders[] = {
#  ifdef __APPLE__
		"open"                    // OS X
#  else
		"fl-xdg-open",            // Puppy Linux
		"xdg-open"                // all other Linux/Unix
#endif
	};

	const char* browsers[] = {
#  ifdef __APPLE__
		getenv("FLMSG_BROWSER"),  // valid for any OS - set by user
		getenv("BROWSER"),        // valid for any OS - set by user
		"open"                    // OS X
#  else
		"fl-xdg-open",            // Puppy Linux
		getenv("FLMSG_BROWSER"),  // force use of spec'd browser
		getenv("BROWSER"),        // most Linux distributions
		"chromium-browser",       // preferred browser for HTML-5
		"firefox",                // nice, but incomplete HTML-5
		"mozilla",                // nice, but incomplete HTML-5
		"xdg-open",               // let OS determine browser
		"sensible-browser"        // must be something out there!

#  endif
	};
	switch (fork()) {
	case 0:
#  ifndef NDEBUG
		unsetenv("MALLOC_CHECK_");
		unsetenv("MALLOC_PERTURB_");
#  endif

		if (folder) {
			for (size_t i = 0; i < sizeof(folders)/sizeof(folders[0]); i++) {
				if (folders[i])
					execlp(folders[i], folders[i], url, (char*)0);
			}
		} else {
			for (size_t i = 0; i < sizeof(browsers)/sizeof(browsers[0]); i++) {
				if (browsers[i])
					execlp(browsers[i], browsers[i], url, (char*)0);
			}
		}
		exit(EXIT_FAILURE);

	case -1:
		fl_alert2(_("Could not run a web browser:\n%s\n\n"
			 "Open this URL manually:\n%s"),
			 strerror(errno), url);
	}
#else
	if ((int)ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL) <= 32)
		fl_alert2(_("Could not open url:\n%s\n"), url);
#endif
}

//------------------------------------------------------------------------------
// mongoose server support
//------------------------------------------------------------------------------
bool exit_server = false;
pthread_t *web_server_thread = 0;
pthread_mutex_t mutex_web_server = PTHREAD_MUTEX_INITIALIZER;

int handle_type = HANDLE_WAITING;

static const char *html_waiting =
  "<html><body>\n\
	Custom form not posted<br>\n\
	</html>";

//void load_custom(void *)
//{
//	load_custom_menu();
//}

void * poll_server(void *d)
{
//	int n = 10;
	exit_server = false;

	while(!exit_server) {
		pthread_mutex_lock(&mutex_web_server);
			mg_poll_server(server, 200);
		pthread_mutex_unlock(&mutex_web_server);
//		n--;
//		if (!n) {
//			if (!progStatus.UI_expert) //flmsg_editor)
//				Fl::awake(load_custom, 0);
//			n = 30;
//		}
		MilliSleep(10);
	}
	return NULL;
}

void close_server()
{
	pthread_mutex_lock(&mutex_web_server);
	exit_server = true;
	pthread_mutex_unlock(&mutex_web_server);
	MilliSleep(200);
}

void update_form(void *)
{
	cb_custom_save_as();
	update_custom = false;
}

extern void get_html_vars(struct mg_connection *conn);
static int web_handler(struct mg_connection *conn)
{
	if (strcmp(conn->uri, "/handle_post_request") == 0) {
		get_html_vars(conn);
		custom_viewer(conn);
		if (update_custom) Fl::awake(update_form);
	} else {
		if (handle_type == HANDLE_EDIT) {
			custom_editor(conn);
		}
		else if (handle_type == HANDLE_VIEW) {
			custom_viewer(conn);
		}
		else if (handle_type == HANDLE_WAITING)
// Show HTML waiting
			mg_send_data(conn, html_waiting, strlen(html_waiting));
	}
	handle_type = HANDLE_NONE;

	return MG_REQUEST_PROCESSED;
}

extern char *mg_open_msg;
int start_web_server()
{
	if ((server = mg_create_server(NULL)) == NULL) {
		fl_alert2("%s", "Failed to start web server");
		exit(EXIT_FAILURE);
		return 0;
	}

	mongoose_msgs.clear();
	char retmsg[500];
	int ret = mg_set_option(server, "document_root", CUSTOM_dir.c_str(), retmsg);

	if (ret) {
		fl_alert2("%s", "Failed to set file server root directory");
		exit(EXIT_FAILURE);
		return 0;
	}

	int last_portnbr = srvr_portnbr + 100;
	int test_portnbr = srvr_portnbr;
	while (test_portnbr < last_portnbr) {
		snprintf(sz_srvr_portnbr, sizeof(sz_srvr_portnbr),
				"%d", test_portnbr);
		ret = mg_set_option(server, "listening_port", sz_srvr_portnbr, retmsg);

		if (ret == 0) break;
		mongoose_msgs.append(retmsg).append(" ")
					 .append(sz_srvr_portnbr);

		test_portnbr++;
		Fl::awake();
	}
	if (test_portnbr == last_portnbr) {
		LOG_ERROR("%s", mongoose_msgs.c_str());
		fl_alert2(
"Web server port bind failed.\n\
Range %d - %d", srvr_portnbr, last_portnbr - 1);
		exit(EXIT_FAILURE);
		return 0;
	}
	else {
		if (!mongoose_msgs.empty()) mongoose_msgs.append("\n");
		mongoose_msgs.append("Listening on port ").
					  append(sz_srvr_portnbr);
	}
	
	mg_set_request_handler(server, web_handler);

	web_server_thread = new pthread_t;
	if (pthread_create(web_server_thread, NULL, poll_server, NULL)) {
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

    return 1;
}

void rotate_log(std::string filename)
{
	const int n = 5; // rename existing log files to keep up to 5 old versions
	ostringstream oldfn, newfn;
	std::streampos p;

	oldfn << filename << '.';
	newfn << filename << '.';
	p = oldfn.tellp();

	for (int i = n - 1; i > 0; i--) {
		oldfn.seekp(p);
		newfn.seekp(p);
		oldfn << i;
		newfn << i + 1;
		rename(oldfn.str().c_str(), newfn.str().c_str());
	}
	rename(filename.c_str(), oldfn.str().c_str());
}


