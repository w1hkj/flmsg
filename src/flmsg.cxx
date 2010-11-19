// =====================================================================
//
// flmsg.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2010
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

#include <stdlib.h>
#include <iostream>
#include <fstream>
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

#ifdef WIN32
#  include "flmsgrc.h"
#  include "compat.h"
#  define dirent fl_dirent_no_thanks
#endif

#include <FL/filename.H>
#ifdef __MINGW32__
#  undef dirent
#endif
#include <dirent.h>

#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Image.H>

using namespace std;

Fl_Double_Window *mainwindow = 0;
Fl_Double_Window *optionswindow = 0;
Fl_Double_Window *arlwindow = 0;
Fl_Double_Window *configwindow = 0;
Fl_Double_Window *hxwindow = 0;

string title;
string flmsgHomeDir;

// flarq, fldigi, flmsg, flwrap share a common NBEMS directory

string NBEMS_dir;
string ARQ_dir;
string ARQ_files_dir;
string ARQ_recv_dir;
string ARQ_send;
string WRAP_dir;
string WRAP_recv_dir;
string WRAP_send_dir;
string WRAP_auto_dir;
string ICS_dir;
string ICS_msg_dir;
string ICS_tmp_dir;

string cmd_fname = "";

//string defRTFname = "";

// utility functions

// create header for flmsg data file
string header( const char *msgtype )
{
	static string sout;
	sout = "<flmsg>";
	sout.append (PACKAGE_VERSION).append("\n").append(msgtype).append("\n");
	return sout;
}

// create flmsg line output for string data
string lineout(string &field, string &data)
{
	static string sout;
	static char sznum[80];
	if (data.empty()) return "";
	snprintf(sznum, sizeof(sznum), "%0d", data.length());
	sout = field;
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
	if (p != string::npos)
		form.replace(p, where.length(), what);
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
		default:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H%ML", &sTime);
	}
	return szDt;
}

char *szDate()
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
	switch (progStatus.dtformat) {
		case 1: strftime(szDt, 79, "%m/%d/%y", &sTime); break;
		case 2: strftime(szDt, 79, "%d/%m/%y", &sTime); break;
		case 0:
		default:
			strftime(szDt, 79, "%Y-%m-%d", &sTime);
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


char *named_file()
{
	static char szfname[200];
	static char szDt[80];
	szfname[0] = 0;
	if (!progStatus.call_fname && !progStatus.dt_fname && !progStatus.sernbr_fname)
		return szfname;
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	gmtime_r (&tmptr, &sTime);
	strftime(szDt, 79, "%Y%m%d-%H%M%SZ", &sTime);
	szfname[0] = 0;
	if (progStatus.call_fname) strcat(szfname, progStatus.my_call.c_str());
	if ((tabs_msg_type->value() == tab_radiogram) && progStatus.rgnbr_fname) {
		if (szfname[0]) strcat(szfname, "-");
		strcat(szfname, progStatus.rgnbr.c_str());
	} else {
		if (progStatus.dt_fname) {
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

void extract_text(string &buffer)
{
	remove_cr(buffer);
	if (buffer.find("<radiogram>") != string::npos) {
		read_rg_buffer(buffer);
		tabs_msg_type->value(tab_radiogram);
		tabs_msg_type->redraw();
	} else if (buffer.find("<ics203>") != string::npos) {
		read_203_buffer(buffer);
		tabs_msg_type->value(tab_ics);
		tab_ics_type->value(tab_ics203);
		tabs_msg_type->redraw();
	} else if (buffer.find("<ics205>") != string::npos) {
		read_205_buffer(buffer);
		tabs_msg_type->value(tab_ics);
		tab_ics_type->value(tab_ics205);
		tabs_msg_type->redraw();
	} else if (buffer.find("<ics206>") != string::npos) {
		read_206_buffer(buffer);
		tabs_msg_type->value(tab_ics);
		tab_ics_type->value(tab_ics206);
		tab_ics206_type->value(tab_206_med_plan);
		tabs_msg_type->redraw();
	} else if (buffer.find("<ics213>") != string::npos) {
		read_213_buffer(buffer);
		tabs_msg_type->value(tab_ics);
		tab_ics_type->value(tab_ics213);
		tab_ics213_type->value(tab_213_originator);
		tabs_msg_type->redraw();
	} else if (buffer.find("<ics214>") != string::npos) {
		read_214_buffer(buffer);
		tabs_msg_type->value(tab_ics);
		tab_ics_type->value(tab_ics214);
		tab_ics214_type->value(tab_214_1);
		tabs_msg_type->redraw();
	} else if (buffer.find("<ics216>") != string::npos) {
		read_216_buffer(buffer);
		tabs_msg_type->value(tab_ics);
		tab_ics_type->value(tab_ics216);
		tab_ics216_type->value(tab_216_1);
		tabs_msg_type->redraw();
	} else if (buffer.find("<plaintext>") != string::npos) {
		read_ptbuffer(buffer);
		tabs_msg_type->value(tab_plaintext);
		tabs_msg_type->redraw();
	} else if (buffer.find("<blankform>") != string::npos) {
		read_blankbuffer(buffer);
		tabs_msg_type->value(tab_blank);
		tabs_msg_type->redraw();
	} //else
		//fl_alert2(_("Not an flmsg data file"));
}

//
void read_data_file(string s)
{
	long filesize = 0;
	char *buff, *buffend;
	int retval;
	FILE *icsfile;

	icsfile = fopen (s.c_str(), "r");
	if (!icsfile)
		return;
// determine its size for buffer creation
	fseek (icsfile, 0, SEEK_END);
	filesize = ftell (icsfile);
// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
		return;
	}

	buff = new char[filesize + 1];
	memset(buff, 0, filesize + 1);
// read the entire file into the buffer
	fseek (icsfile, 0, SEEK_SET);
	retval = fread (buff, filesize, 1, icsfile);
	fclose (icsfile);
	buffend = buff + filesize;

	string buffer = buff;
	delete [] buff;

	extract_text(buffer);
}

void cb_msg_type()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			show_filename(def_203_filename);
		else if (tab_ics_type->value() == tab_ics205)
			show_filename(def_205_filename);
		else if (tab_ics_type->value() == tab_ics206)
			show_filename(def_206_filename);
		else if (tab_ics_type->value() == tab_ics213)
			show_filename(def_213_filename);
		else if (tab_ics_type->value() == tab_ics214)
			show_filename(def_214_filename);
		else if (tab_ics_type->value() == tab_ics216)
			show_filename(def_216_filename);
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		show_filename(def_rg_filename);
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		show_filename(def_pt_filename);
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		show_filename(def_blank_filename);
		return;
	}
}

void cb_new()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_new();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_new();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_new();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_new();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_new();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_new();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_new();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_new();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_new();
		return;
	}
}

void cb_import()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_import();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_import();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_import();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_import();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_import();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_import();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_import();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext ||
		tabs_msg_type->value() == tab_blank) {
		fl_alert2("Not implemented");
		return;
	}
}

void cb_export()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_export();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_export();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_export();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_export();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_export();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_export();
	}
	else if (tabs_msg_type->value() == tab_radiogram)
		cb_rg_export();
	else if (tabs_msg_type->value() == tab_plaintext ||
		tabs_msg_type->value() == tab_blank)
		fl_alert2("Not implemented");
	return;
}

void wrap_import(const char *fname)
{
	string filename;
	string inpbuffer;
	bool isok = import_wrapfile(fname, filename, inpbuffer);
	if (!isok) {
		isok = !fl_choice2(_("Checksum failed\n\nIgnore errors?"), "yes", "no", NULL);
	}
	if (isok) {
		remove_cr( inpbuffer );
		if (inpbuffer.find("<flics") != string::npos ||
			inpbuffer.find("<flmsg") != string::npos) {
			if (inpbuffer.find("<ics203>") != string::npos) {
				tabs_msg_type->value(tab_ics);
				tab_ics_type->value(tab_ics203);
				cb_203_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics205>") != string::npos) {
				tabs_msg_type->value(tab_ics);
				tab_ics_type->value(tab_ics205);
				cb_205_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics206>") != string::npos) {
				tabs_msg_type->value(tab_ics);
				tab_ics_type->value(tab_ics206);
				cb_206_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics213>") != string::npos) {
				tabs_msg_type->value(tab_ics);
				tab_ics_type->value(tab_ics213);
				cb_213_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics214>") != string::npos) {
				tabs_msg_type->value(tab_ics);
				tab_ics_type->value(tab_ics214);
				cb_214_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<ics216>") != string::npos) {
				tabs_msg_type->value(tab_ics);
				tab_ics_type->value(tab_ics216);
				cb_216_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<radiogram>") != string::npos) {
				tabs_msg_type->value(tab_radiogram);
				cb_rg_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<plaintext>") != string::npos) {
				tabs_msg_type->value(tab_plaintext);
				cb_pt_wrap_import(filename, inpbuffer);
			} else if (inpbuffer.find("<blankform>") != string::npos) {
				tabs_msg_type->value(tab_blank);
				cb_blank_wrap_import(filename, inpbuffer);
			} else {
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
	} else {
		if (!fl_choice2(_("Open as text file?"), "yes", "no", NULL)) {
			filename = fname;
			filename.append(".txt");
			FILE *badfile = fopen(filename.c_str(), "w");
			fwrite(inpbuffer.c_str(), inpbuffer.length(), 1, badfile);
			fclose(badfile);
			open_url(filename.c_str());
		}
	}
}

void cb_wrap_import()
{
	string wrapfilename = WRAP_recv_dir;
	wrapfilename.append("default"WRAP_EXT);
	const char *p = FSEL::select(
		"Import wrapped flmsg file",
		"Wrap file\t*.{wrap,WRAP}",
		wrapfilename.c_str());
	if (p)
		wrap_import(p);
}

void cb_wrap_export()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_wrap_export();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_wrap_export();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_wrap_export();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_wrap_export();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_wrap_export();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_wrap_export();
	} else if (tabs_msg_type->value() == tab_radiogram)
		cb_rg_wrap_export();
	else if (tabs_msg_type->value() == tab_plaintext)
		cb_pt_wrap_export();
	else if (tabs_msg_type->value() == tab_blank)
		cb_blank_wrap_export();
	else
		return;
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
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_wrap_autosend();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_wrap_autosend();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_wrap_autosend();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_wrap_autosend();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_wrap_autosend();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_wrap_autosend();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_wrap_autosend();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_wrap_autosend();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_wrap_autosend();
		return;
	}
}

void cb_load_template()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_load_template();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_load_template();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_load_template();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_load_template();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_load_template();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_load_template();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_load_template();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_load_template();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_load_template();
		return;
	}
}

void cb_save_template()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_save_template();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_save_template();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_save_template();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_save_template();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_save_template();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_save_template();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_save_template();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_save_template();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_save_template();
		return;
	}
}

void cb_save_as_template()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_save_as_template();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_save_as_template();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_save_as_template();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_save_as_template();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_save_as_template();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_save_as_template();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_save_as_template();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_save_as_template();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_save_as_template();
		return;
	}
}

void cb_open()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_open();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_open();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_open();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_open();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_open();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_open();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_open();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_open();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_open();
		return;
	}
}

void cb_save_as()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_save_as();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_save_as();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_save_as();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_save_as();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_save_as();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_save_as();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_save_as();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_save_as();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_save_as();
		return;
	}
}

void cb_save()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_save();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_save();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_save();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_save();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_save();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_save();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_save();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_save();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_save();
		return;
	}
}

void cb_html()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_html();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_html();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_html();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_html();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_html();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_html();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_html();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_html();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_html();
		return;
	}
}

void cb_html_fcopy()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_html();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_html();
		else if (tab_ics_type->value() == tab_ics206)
			cb_205_html();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_html();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_html();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_html();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram)
		cb_rg_html_fcopy();
	else
		fl_alert2("Not implemented for this form type");
}

void cb_text()
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203)
			cb_203_textout();
		else if (tab_ics_type->value() == tab_ics205)
			cb_205_textout();
		else if (tab_ics_type->value() == tab_ics206)
			cb_206_textout();
		else if (tab_ics_type->value() == tab_ics213)
			cb_213_textout();
		else if (tab_ics_type->value() == tab_ics214)
			cb_214_textout();
		else if (tab_ics_type->value() == tab_ics216)
			cb_216_textout();
		return;
	}
	if (tabs_msg_type->value() == tab_radiogram) {
		cb_rg_textout();
		return;
	}
	if (tabs_msg_type->value() == tab_plaintext) {
		cb_pt_textout();
		return;
	}
	if (tabs_msg_type->value() == tab_blank) {
		cb_blank_textout();
		return;
	}
}

void cb_exit()
{
	progStatus.saveLastState();
	FSEL::destroy();
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
	fl_alert2(_("Version "PACKAGE_VERSION));
}

void cb_folders()
{
	open_url(NBEMS_dir.c_str());
}

void show_filename(string p)
{
	if (tabs_msg_type->value() == tab_ics) {
		if (tab_ics_type->value() == tab_ics203 ) {
			base_203_filename = fl_filename_name(p.c_str());
			txt_filename->value(base_203_filename.c_str());
		} else if (tab_ics_type->value() == tab_ics205 ) {
			base_205_filename = fl_filename_name(p.c_str());
			txt_filename->value(base_205_filename.c_str());
		} else if (tab_ics_type->value() == tab_ics206 ) {
			base_206_filename = fl_filename_name(p.c_str());
			txt_filename->value(base_206_filename.c_str());
		} else if (tab_ics_type->value() == tab_ics213 ) {
			base_213_filename = fl_filename_name(p.c_str());
			txt_filename->value(base_213_filename.c_str());
		} else if (tab_ics_type->value() == tab_ics214 ) {
			base_214_filename = fl_filename_name(p.c_str());
			txt_filename->value(base_214_filename.c_str());
		} else if (tab_ics_type->value() == tab_ics216 ) {
			base_216_filename = fl_filename_name(p.c_str());
			txt_filename->value(base_216_filename.c_str());
		}
	} else if (tabs_msg_type->value() == tab_radiogram) {
		base_rg_filename = fl_filename_name(p.c_str());
		txt_filename->value(base_rg_filename.c_str());
	} else if (tabs_msg_type->value() == tab_plaintext) {
		base_pt_filename = fl_filename_name(p.c_str());
		txt_filename->value(base_pt_filename.c_str());
	} else if (tabs_msg_type->value() == tab_blank) {
		base_blank_filename = fl_filename_name(p.c_str());
		txt_filename->value(base_blank_filename.c_str());
	}
	txt_filename->redraw();
}

void set_main_label()
{
	string main_label = PACKAGE_NAME;
	main_label.append(": ").append(PACKAGE_VERSION);
	mainwindow->label(main_label.c_str());
}


#define KNAME "fllog"
#if !defined(__WIN32__) && !defined(__APPLE__)
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

void default_tab()
{
	switch (progStatus.tab) {
		case tb_plaintext:
			tabs_msg_type->value(tab_plaintext);
			tabs_msg_type->redraw();
			show_filename(def_pt_filename);
			break;
		case tb_blank:
			tabs_msg_type->value(tab_blank);
			tabs_msg_type->redraw();
			show_filename(def_blank_filename);
			break;
		case tb_ics203:
			tabs_msg_type->value(tab_ics);
			tab_ics_type->value(tab_ics203);
			tabs_msg_type->redraw();
			show_filename(def_203_filename);
			break;
		case tb_ics205:
			tabs_msg_type->value(tab_ics);
			tab_ics_type->value(tab_ics205);
			tabs_msg_type->redraw();
			show_filename(def_205_filename);
			break;
		case tb_ics206:
			tabs_msg_type->value(tab_ics);
			tab_ics_type->value(tab_ics206);
			tab_ics206_type->value(tab_206_med_plan);
			tabs_msg_type->redraw();
			show_filename(def_206_filename);
			break;
		case tb_ics213:
			tabs_msg_type->value(tab_ics);
			tab_ics_type->value(tab_ics213);
			tab_ics213_type->value(tab_213_originator);
			tabs_msg_type->redraw();
			show_filename(def_213_filename);
			break;
		case tb_ics214:
			tabs_msg_type->value(tab_ics);
			tab_ics_type->value(tab_ics214);
			tab_ics214_type->value(tab_214_1);
			tabs_msg_type->redraw();
			show_filename(def_214_filename);
			break;
		case tb_ics216:
			tabs_msg_type->value(tab_ics);
			tab_ics_type->value(tab_ics216);
			tab_ics216_type->value(tab_216_1);
			tabs_msg_type->redraw();
			show_filename(def_216_filename);
			break;
		case tb_radiogram:
		default:
			tabs_msg_type->value(tab_radiogram);
			tabs_msg_type->redraw();
			show_filename(def_rg_filename);
	}
}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		if (strcasecmp("--help", argv[1]) == 0) {
			printf("\
  --help this help text\n\
  --version\n\
\n\
  Usage: flmsg\n");
			return 0;
		} 
		if (strcasecmp("--version", argv[1]) == 0) {
			printf("Version: "VERSION"\n");
			return 0;
		}
	}

	mainwindow = ics_dialog();
	mainwindow->callback(exit_main);

	configwindow = config_dialog();

char dirbuf[FL_PATH_MAX + 1];
#ifdef __WIN32__
	fl_filename_expand(dirbuf, sizeof(dirbuf) - 1, "$USERPROFILE/NBEMS.files/");
#else
	fl_filename_expand(dirbuf, sizeof(dirbuf) - 1, "$HOME/.nbems/");
#endif
	NBEMS_dir = dirbuf;
	checkdirectories();

	def_203_filename = ICS_msg_dir;
	def_203_filename.append("default"F203_EXT);
	def_203_TemplateName = ICS_tmp_dir;
	def_203_TemplateName.append("default"T203_EXT);

	def_205_filename = ICS_msg_dir;
	def_205_filename.append("default"F205_EXT);
	def_205_TemplateName = ICS_tmp_dir;
	def_205_TemplateName.append("default"T205_EXT);

	def_206_filename = ICS_msg_dir;
	def_206_filename.append("default"F206_EXT);
	def_206_TemplateName = ICS_tmp_dir;
	def_206_TemplateName.append("default"T206_EXT);

	def_213_filename = ICS_msg_dir;
	def_213_filename.append("default"F213_EXT);
	def_213_TemplateName = ICS_tmp_dir;
	def_213_TemplateName.append("default"T213_EXT);

	def_214_filename = ICS_msg_dir;
	def_214_filename.append("default"F214_EXT);
	def_214_TemplateName = ICS_tmp_dir;
	def_214_TemplateName.append("default"T214_EXT);

	def_216_filename = ICS_msg_dir;
	def_216_filename.append("default"F216_EXT);
	def_216_TemplateName = ICS_tmp_dir;
	def_216_TemplateName.append("default"T216_EXT);

	def_rg_filename = ICS_msg_dir;
	def_rg_filename.append("default"RGFILE_EXT);
	def_rg_TemplateName = ICS_tmp_dir;
	def_rg_TemplateName.append("default"RGTEMP_EXT);
	set_rg_choices();

	def_pt_filename = ICS_msg_dir;
	def_pt_filename.append("default"PTFILE_EXT);
	def_pt_TemplateName = ICS_tmp_dir;
	def_pt_TemplateName.append("default"PTTEMP_EXT);

	def_blank_filename = ICS_msg_dir;
	def_blank_filename.append("default"BLANKFILE_EXT);
	def_blank_TemplateName = ICS_tmp_dir;
	def_blank_TemplateName.append("default"BLANKTEMP_EXT);

	Fl_File_Icon::load_system_icons();
	FSEL::create();

	int arg_idx;
	if (Fl::args(argc, argv, arg_idx, parse_args) != argc)
		showoptions();

	progStatus.loadLastState();

	mainwindow->resize( progStatus.mainX, progStatus.mainY, mainwindow->w(), mainwindow->h());

	tab_ics213->show();

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

	set_main_label();

	if (!cmd_fname.empty()) {
		if (cmd_fname.find(WRAP_EXT) != string::npos)
			wrap_import(cmd_fname.c_str());
		else {
			read_data_file(cmd_fname);
		}
		show_filename(cmd_fname);
	} else
		default_tab();

	return Fl::run();
}

void drop_box_changed()
{
	string 	buffer = drop_box->value();
	size_t n;
	if ((n = buffer.find("file:///")) != string::npos) {
		buffer.erase(n, 7);
		while ((n = buffer.find('\n')) != string::npos)
			buffer.erase(n, 1);
		while ((n = buffer.find('\r')) != string::npos)
			buffer.erase(n, 1);
		if (buffer.find(WRAP_EXT) != string::npos)
			wrap_import(buffer.c_str());
		else 
			read_data_file(buffer.c_str());
	} else if ((n = buffer.find(":\\")) != string::npos) {
		while ((n = buffer.find('\n')) != string::npos)
			buffer.erase(n, 1);
		while ((n = buffer.find('\r')) != string::npos)
			buffer.erase(n, 1);
		if (buffer.find(WRAP_EXT) != string::npos)
			wrap_import(buffer.c_str());
		else 
			read_data_file(buffer.c_str());
	} else // try to extract as a text buffer
		extract_text(buffer);
	drop_box->value("");
	drop_box->redraw();
}

void checkdirectories(void)
{
	struct DIRS {
		string& dir;
		const char* suffix;
		void (*new_dir_func)(void);
	};
	DIRS NBEMS_dirs[] = {
		{ NBEMS_dir,     0, 0 },
		{ ARQ_dir,       "ARQ", 0 },
		{ ARQ_files_dir, "ARQ/files", 0 },
		{ ARQ_recv_dir,  "ARQ/recv", 0 },
		{ ARQ_send,      "ARQ/send", 0 },
		{ WRAP_dir,      "WRAP", 0 },
		{ WRAP_recv_dir, "WRAP/recv", 0 },
		{ WRAP_send_dir, "WRAP/send", 0 },
		{ WRAP_auto_dir, "WRAP/auto", 0 },
		{ ICS_dir,       "ICS", 0 },
		{ ICS_msg_dir,   "ICS/messages", 0 },
		{ ICS_tmp_dir,   "ICS/templates", 0 },
	};

	int r;

	for (size_t i = 0; i < sizeof(NBEMS_dirs)/sizeof(*NBEMS_dirs); i++) {
		if (NBEMS_dirs[i].suffix)
			NBEMS_dirs[i].dir.assign(NBEMS_dir).append(NBEMS_dirs[i].suffix).append(PATH_SEP);

		if ((r = mkdir(NBEMS_dirs[i].dir.c_str(), 0777)) == -1 && errno != EEXIST) {
			cerr << _("Could not make directory") << ' ' << NBEMS_dirs[i].dir
			     << ": " << strerror(errno) << '\n';
			exit(EXIT_FAILURE);
		}
		else if (r == 0 && NBEMS_dirs[i].new_dir_func)
			NBEMS_dirs[i].new_dir_func();
	}
}

const char *options[] = {\
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
"-s\t-scheme [plastic | gtk+]",
"-ti\t-title [WINDOWTITLE]",
"-to\t-tooltips : enable tooltips",
"-not\t-notooltips : disable tooltips\n",
0
};

const int widths[] = {60, 0};

void showoptions()
{
	if (!optionswindow) {
		optionswindow = optionsdialog();
		brwsOptions->column_widths(widths);
		for (int i = 0; options[i] != 0; i++)
			brwsOptions->add(options[i]);
	}
	optionswindow->show();
}

void closeoptions()
{
	optionswindow->hide();
}

void cb_config()
{
	btn_open_on_export->value(progStatus.open_on_export);

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

	txt_sernbr->value(progStatus.sernbr.c_str());
	btn_sernbr_fname->value(progStatus.sernbr_fname);

	txt_rgnbr->value(progStatus.rgnbr.c_str());
	btn_rgnbr_fname->value(progStatus.rgnbr_fname);

	btn_call_fname->value(progStatus.call_fname);
	btn_dt_fname->value(progStatus.dt_fname);

	configwindow->show();
}

void cb_close_config()
{
	configwindow->hide();
}

void show_help()
{
	open_url("http://www.w1hkj.com/flmsg-help/index.html");
}

int parse_args(int argc, char **argv, int& idx)
{
// Only handle a filename option
	if ( argv[idx][0] == '-' )
		return 0;

string fname = argv[idx];
	if (fname.find(DATAFILE_EXT) != string::npos ||
		fname.find(DATATEMP_EXT) != string::npos ||

		fname.find(F203_EXT) != string::npos ||
		fname.find(T203_EXT) != string::npos ||

		fname.find(F205_EXT) != string::npos ||
		fname.find(T205_EXT) != string::npos ||

		fname.find(F205_EXT) != string::npos ||
		fname.find(T205_EXT) != string::npos ||

		fname.find(F206_EXT) != string::npos ||
		fname.find(T206_EXT) != string::npos ||

		fname.find(F213_EXT) != string::npos ||
		fname.find(T213_EXT) != string::npos ||

		fname.find(F214_EXT) != string::npos ||
		fname.find(T214_EXT) != string::npos ||

		fname.find(F216_EXT) != string::npos ||
		fname.find(T216_EXT) != string::npos ||

		fname.find(RGFILE_EXT) != string::npos ||
		fname.find(RGTEMP_EXT) != string::npos ||

		fname.find(PTFILE_EXT) != string::npos ||
		fname.find(PTTEMP_EXT) != string::npos ||

		fname.find(BLANKFILE_EXT) != string::npos ||
		fname.find(BLANKTEMP_EXT) != string::npos ||

		fname.find(WRAP_EXT) != string::npos ) {
		cmd_fname = fname;
	}
	idx++;
	return 1;
}

void open_url(const char* url)
{
#ifndef __WOE32__
	const char* browsers[] = {
#  ifdef __APPLE__
		getenv("FLDIGI_BROWSER"), // valid for any OS - set by user
		"open"                    // OS X
#  else
		"fl-xdg-open",            // Puppy Linux
		"xdg-open",               // other Unix-Linux distros
		getenv("FLDIGI_BROWSER"), // force use of spec'd browser
		getenv("BROWSER"),        // most Linux distributions
		"sensible-browser",
		"firefox",
		"mozilla"                 // must be something out there!
#  endif
	};
	switch (fork()) {
	case 0:
#  ifndef NDEBUG
		unsetenv("MALLOC_CHECK_");
		unsetenv("MALLOC_PERTURB_");
#  endif
		for (size_t i = 0; i < sizeof(browsers)/sizeof(browsers[0]); i++)
			if (browsers[i])
				execlp(browsers[i], browsers[i], url, (char*)0);
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
