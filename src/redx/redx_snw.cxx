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
#include "parse_xml.h"

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

string s_redx_snw_lname;
string s_redx_snw_fname;
string s_redx_snw_area1;
string s_redx_snw_xchg1;
string s_redx_snw_suffix1;
string s_redx_snw_area2;
string s_redx_snw_xchg2;
string s_redx_snw_suffix2;
string s_redx_snw_area3;
string s_redx_snw_xchg3;
string s_redx_snw_suffix3;
string s_redx_snw_pdline1;
string s_redx_snw_pdline2;
string s_redx_snw_pdcity;
string s_redx_snw_pdst;
string s_redx_snw_pdzip;
string s_redx_snw_haline1;
string s_redx_snw_haline2;
string s_redx_snw_hacity;
string s_redx_snw_hast;
string s_redx_snw_hazip;
string s_redx_snw_cmsg;

bool   b_redx_snw_nophone;
bool   b_snw_m1;
bool   b_snw_m2;
bool   b_snw_m3;
bool   b_snw_m4;
bool   b_snw_m5;
bool   b_snw_m6;
bool   b_snw_m7;
bool   b_snw_m8;
bool   b_snw_m9;
bool   b_snw_m10;
bool   b_snw_m11;
bool   b_snw_m12;
bool   b_snw_m13;
bool   b_snw_m14;
bool   b_snw_m15;

// could not use real names ... WIN32 barfs
enum FTYPE { B, S, T, E }; // bool, string, text, empty

struct TRIAD { 
	FTYPE ftype;
	string htmlname;
	string *ps;
	bool   *pb;
	Fl_Widget *control; };

TRIAD redx_triad[] = {
{ S,	":lname:",		&s_redx_snw_lname,		NULL,					snw_lname },
{ S,	":fname:",		&s_redx_snw_fname,		NULL,					snw_fname },
{ B,	":nophone:",	NULL,					&b_redx_snw_nophone,	snw_nophone },
{ S,	":area1:",		&s_redx_snw_area1,		NULL,					snw_area1 },
{ S,	":xchg1:",		&s_redx_snw_xchg1,		NULL,					snw_xchg1 },
{ S,	":suffix1:",	&s_redx_snw_suffix1,	NULL,					snw_suffix1 },
{ S,	":area2:",		&s_redx_snw_area2,		NULL,					snw_area2 },
{ S,	":xchg2:",		&s_redx_snw_xchg2,		NULL,					snw_xchg2 },
{ S,	":suffix2:",	&s_redx_snw_suffix2,	NULL,					snw_suffix2 },
{ S,	":area3:",		&s_redx_snw_area3,		NULL,					snw_area3 },
{ S,	":xchg3:",		&s_redx_snw_xchg3,		NULL,					snw_xchg3 },
{ S,	":suffix3:",	&s_redx_snw_suffix3,	NULL,					snw_suffix3 },
{ S,	":pdline1:",	&s_redx_snw_pdline1,	NULL,					snw_pdline1 },
{ S,	":pdline2:",	&s_redx_snw_pdline2,	NULL,					snw_pdline2 },
{ S,	":pdcity:",		&s_redx_snw_pdcity,		NULL,					snw_pdcity },
{ S,	":pdst:",		&s_redx_snw_pdst,		NULL,					snw_pdst },
{ S,	":pdzip:",		&s_redx_snw_pdzip,		NULL,					snw_pdzip },
{ S,	":haline1:",	&s_redx_snw_haline1,	NULL,					snw_haline1 },
{ S,	":haline2:",	&s_redx_snw_haline2,	NULL,					snw_haline2 },
{ S,	":hacity:",		&s_redx_snw_hacity,		NULL,					snw_hacity },
{ S,	":hast:",		&s_redx_snw_hast,		NULL,					snw_hast },
{ S,	":hazip:",		&s_redx_snw_hazip,		NULL,					snw_hazip },
{ B,	":m1:",			NULL,					&b_snw_m1,				snw_m1 },
{ B,	":m2:",			NULL,					&b_snw_m2,				snw_m2 },
{ B,	":m3:",			NULL,					&b_snw_m3,				snw_m3 },
{ B,	":m4:",			NULL,					&b_snw_m4,				snw_m4 },
{ B,	":m5:",			NULL,					&b_snw_m5,				snw_m5 },
{ B,	":m6:",			NULL,					&b_snw_m6,				snw_m6 },
{ B,	":m7:",			NULL,					&b_snw_m7,				snw_m7 },
{ B,	":m8:",			NULL,					&b_snw_m8,				snw_m8 },
{ B,	":m9:",			NULL,					&b_snw_m9,				snw_m9 },
{ B,	":m10:",		NULL,					&b_snw_m10,				snw_m10 },
{ B,	":m11:",		NULL,					&b_snw_m11,				snw_m11 },
{ B,	":m12:",		NULL,					&b_snw_m12,				snw_m12 },
{ B,	":m13:",		NULL,					&b_snw_m13,				snw_m13 },
{ B,	":m14:",		NULL,					&b_snw_m14,				snw_m14 },
{ B,	":m15:",		NULL,					&b_snw_m15,				snw_m15 },
{ T,	":cmsg:",		&s_redx_snw_cmsg,		NULL,					snw_cmsg },
{ E,	"",				NULL,					NULL,					NULL }
};

string buffredx_snw;
string def_redx_snw_filename = "";
string base_redx_snw_filename = "";
string def_redx_snw_TemplateName = "";

bool using_redx_snw_template = false;

static bool fields_initialized = false;

static void init_fields()
{
	redx_triad[0].control = snw_lname;
	redx_triad[1].control = snw_fname;
	redx_triad[2].control = snw_nophone;
	redx_triad[3].control = snw_area1;
	redx_triad[4].control = snw_xchg1;
	redx_triad[5].control = snw_suffix1;
	redx_triad[6].control = snw_area2;
	redx_triad[7].control = snw_xchg2;
	redx_triad[8].control = snw_suffix2;
	redx_triad[9].control = snw_area3;
	redx_triad[10].control = snw_xchg3;
	redx_triad[11].control = snw_suffix3;
	redx_triad[12].control = snw_pdline1;
	redx_triad[13].control = snw_pdline2;
	redx_triad[14].control = snw_pdcity;
	redx_triad[15].control = snw_pdst;
	redx_triad[16].control = snw_pdzip;
	redx_triad[17].control = snw_haline1;
	redx_triad[18].control = snw_haline2;
	redx_triad[19].control = snw_hacity;
	redx_triad[20].control = snw_hast;
	redx_triad[21].control = snw_hazip;
	redx_triad[22].control = snw_m1;
	redx_triad[23].control = snw_m2;
	redx_triad[24].control = snw_m3;
	redx_triad[25].control = snw_m4;
	redx_triad[26].control = snw_m5;
	redx_triad[27].control = snw_m6;
	redx_triad[28].control = snw_m7;
	redx_triad[29].control = snw_m8;
	redx_triad[30].control = snw_m9;
	redx_triad[31].control = snw_m10;
	redx_triad[32].control = snw_m11;
	redx_triad[33].control = snw_m12;
	redx_triad[34].control = snw_m13;
	redx_triad[35].control = snw_m14;
	redx_triad[36].control = snw_m15;
	redx_triad[37].control = snw_cmsg;

	fields_initialized = true;
}

void clear_redx_snwfields()
{
	if (!fields_initialized) init_fields();
	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->ftype == B) *(ptriad->pb) = false;
		else if (ptriad->ftype == S) (ptriad->ps)->clear();
		else if (ptriad->ftype == T) (ptriad->ps)->clear();
		ptriad++;
	}
}

bool check_redx_snwfields()
{
	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->control == NULL) return false;
		if (ptriad->ftype == B) {
			if (*(ptriad->pb) != ((Fl_Check_Button *)ptriad->control)->value())
				return true;
		} else if (ptriad->ftype == S) {
			if (*(ptriad->ps) != ((Fl_Input2 *)ptriad->control)->value())
				return true;
		} else if (ptriad->ftype == T){
			if (*(ptriad->ps) != ((FTextEdit *)ptriad->control)->buffer()->text())
				return true;
		}
		ptriad++;
	}
	return false;
}

void update_redx_snwfields()
{
	if (!fields_initialized) init_fields();
	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->ftype == B)
			*(ptriad->pb) = ((Fl_Check_Button *)ptriad->control)->value();
		else if (ptriad->ftype == S)
			*(ptriad->ps) = ((Fl_Input2 *)ptriad->control)->value();
		else if (ptriad->ftype == T)
			*(ptriad->ps) = ((FTextEdit *)ptriad->control)->buffer()->text();
		ptriad++;
	}
}

void update_redx_snwform()
{
	if (!fields_initialized) init_fields();
	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->ftype == B)
			((Fl_Check_Button *)ptriad->control)->value(*(ptriad->pb));
		else if (ptriad->ftype == S)
			((Fl_Input2 *)ptriad->control)->value((ptriad->ps)->c_str());
		else if (ptriad->ftype == T) {
			((FTextEdit *)ptriad->control)->clear();
			((FTextEdit *)ptriad->control)->add((ptriad->ps)->c_str());
		}
		ptriad++;
	}
}

void clear_redx_snw_form()
{
	clear_redx_snwfields();
	update_redx_snwform();
}

void make_buffredx_snw(bool compress = false)
{
	string one = "1"; string zero = "0";
	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->ftype == B)
			buffredx_snw.append( lineout( ptriad->htmlname, (*(ptriad->pb) ? one : zero)));
		else if (ptriad->ftype == S)
			buffredx_snw.append( lineout( ptriad->htmlname,	*(ptriad->ps)));
		else if (ptriad->ftype == T)
			buffredx_snw.append( lineout( ptriad->htmlname,	*(ptriad->ps)));
		ptriad++;
	}
	if (compress) compress_maybe(buffredx_snw);
}

void read_redx_snw_buffer(string data)
{
	clear_redx_snwfields();
	read_header(data);

	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->ftype == B)
			*(ptriad->pb) = (findstr( data, ptriad->htmlname ) == "1");
		else if (ptriad->ftype == S)
			*(ptriad->ps) = findstr( data, ptriad->htmlname );
		else if (ptriad->ftype == T)
			*(ptriad->ps) = findstr( data, ptriad->htmlname );
		ptriad++;
	}
	update_redx_snwform();
}

void cb_redx_snw_new()
{
	if (check_redx_snwfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_redx_snw_save();
		}
	}
	clear_redx_snw_form();
	clear_header();
	def_redx_snw_filename = ICS_msg_dir;
	def_redx_snw_filename.append("new" FREDXSNW_EXT);
	show_filename(def_redx_snw_filename);
	using_redx_snw_template = false;
}

void cb_redx_snw_import()
{
	fl_alert2("Not implemented");
}

void cb_redx_snw_export()
{
	fl_alert2("Not implemented");
}

void cb_redx_snw_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_redx_snw_form();
	read_redx_snw_buffer(inpbuffer);
	def_redx_snw_filename = ICS_msg_dir;
	def_redx_snw_filename.append(wrapfilename);
	show_filename(def_redx_snw_filename);
	using_redx_snw_template = false;
}

int eval_redx_snw_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_redx_snw_filename).append("]");
	update_redx_snwfields();
	update_header(FROM);
	evalstr.append(header("<redx_snw>"));
	buffredx_snw.clear();
	make_buffredx_snw(true);
	if (buffredx_snw.empty()) return 0;
	compress_maybe( buffredx_snw );
	evalstr.append( buffredx_snw );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_redx_snw_wrap_export()
{
	if (check_redx_snwfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_snwfields();

	if (base_redx_snw_filename == "new" FREDXSNW_EXT || base_redx_snw_filename == "default"  FREDXSNW_EXT)
		if (!cb_redx_snw_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_redx_snw_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffredx_snw.assign(header("<redx_snw>"));
		make_buffredx_snw(true);
		export_wrapfile(base_redx_snw_filename, wrapfilename, buffredx_snw, pext != ".wrap");

		buffredx_snw.assign(header("<redx_snw>"));
		make_buffredx_snw(false);
		write_redx_snw(def_redx_snw_filename);
	}
}

void cb_redx_snw_wrap_autosend()
{
	if (check_redx_snwfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_snwfields();

	if (base_redx_snw_filename == "new" FREDXSNW_EXT || base_redx_snw_filename == "default"  FREDXSNW_EXT)
		if (!cb_redx_snw_save_as()) return;

	update_header(FROM);
	buffredx_snw.assign(header("<redx_snw>"));
	make_buffredx_snw(true);
	xfr_via_socket(base_redx_snw_filename, buffredx_snw);

	buffredx_snw.assign(header("<redx_snw>"));
	make_buffredx_snw(false);
	write_redx_snw(def_redx_snw_filename);
}

void cb_redx_snw_load_template()
{
	string def_redx_snw_filename = def_redx_snw_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*" TREDXSNW_EXT,
			def_redx_snw_filename.c_str());
	if (p) {
		clear_redx_snw_form();
		read_data_file(p);
		def_redx_snw_TemplateName = p;
		show_filename(def_redx_snw_TemplateName);
		using_redx_snw_template = true;
	}
}

void cb_redx_snw_save_template()
{
	if (!using_redx_snw_template) {
		cb_redx_snw_save_as_template();
		return;
	}
	string def_redx_snw_filename = def_redx_snw_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*" TREDXSNW_EXT,
			def_redx_snw_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_redx_snwfields();
		buffredx_snw.assign(header("<redx_snw>"));
		make_buffredx_snw();
		write_redx_snw(p);
	}
}

void cb_redx_snw_save_as_template()
{
	string def_redx_snw_filename = def_redx_snw_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*" TREDXSNW_EXT,
			def_redx_snw_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_redx_snw_TemplateName = p;
		if (strlen(pext) == 0) def_redx_snw_TemplateName.append(TREDXSNW_EXT);
		remove_spaces_from_filename(def_redx_snw_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_redx_snwfields();
		buffredx_snw.assign(header("<redx_snw>"));
		make_buffredx_snw();
		write_redx_snw(def_redx_snw_TemplateName);

		show_filename(def_redx_snw_TemplateName);
		using_redx_snw_template = true;
	}
}

void cb_redx_snw_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-redx_snw\t*" FREDXSNW_EXT,
					def_redx_snw_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_redx_snw_form();
	read_data_file(p);
	using_redx_snw_template = false;
	def_redx_snw_filename = p;
	show_filename(def_redx_snw_filename);
}

void write_redx_snw(string s)
{
	FILE *fileredx_snw = fopen(s.c_str(), "w");
	if (!fileredx_snw) return;

	fwrite(buffredx_snw.c_str(), buffredx_snw.length(), 1, fileredx_snw);
	fclose(fileredx_snw);
}

bool cb_redx_snw_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FREDXSNW_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_redx_snw_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-redx_snw\t*" FREDXSNW_EXT,
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_redx_snw_filename = p;
	if (strlen(pext) == 0) def_redx_snw_filename.append(FREDXSNW_EXT);

	remove_spaces_from_filename(def_redx_snw_filename);

	update_header(NEW);
	update_redx_snwfields();
	buffredx_snw.assign(header("<redx_snw>"));
	make_buffredx_snw();
	write_redx_snw(def_redx_snw_filename);

	using_redx_snw_template = false;
	show_filename(def_redx_snw_filename);
	return true;
}

void cb_redx_snw_save()
{
	if (base_redx_snw_filename == "new" FREDXSNW_EXT || 
		base_redx_snw_filename == "default"  FREDXSNW_EXT ||
		using_redx_snw_template == true) {
		cb_redx_snw_save_as();
		return;
	}

	if (check_redx_snwfields()) update_header(CHANGED);
	update_redx_snwfields();
	buffredx_snw.assign(header("<redx_snw>"));
	make_buffredx_snw();
	write_redx_snw(def_redx_snw_filename);

	using_redx_snw_template = false;
}

void cb_redx_snw_html()
{
	string fname_name = fl_filename_name(def_redx_snw_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string redx_snw_fname = ICS_dir;
	redx_snw_fname.append(fname_name);
	redx_snw_fname.append(".html");

	update_redx_snwfields();
	string formredx_snw = redx_snw_html_template;

	replacestr(formredx_snw, TITLE, fname_name);

	string X = "X"; string SP = " ";
	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->ftype == S)
			replacestr(formredx_snw, ptriad->htmlname, *(ptriad->ps) );
		else if (ptriad->ftype == T) {
// change if <pre> ... </pre> is ever used for this field
//			string temp = *(ptriad->ps);
//			if (progStatus.autowordwrap)
//				temp = wordwrap(temp, progStatus.charcount);
//			replacestr(formredx_snw, ptriad->htmlname, temp);
			replacestr(formredx_snw, ptriad->htmlname, *(ptriad->ps) );
		} else if (ptriad->ftype == B)
			replacestr(formredx_snw, ptriad->htmlname, (*(ptriad->pb) ? X : SP));
		ptriad++;
	}

	FILE *fileredx_snw = fopen(redx_snw_fname.c_str(), "w");
	fprintf(fileredx_snw,"%s", formredx_snw.c_str());
	fclose(fileredx_snw);

	open_url(redx_snw_fname.c_str());
}

void cb_snw_msg_type()
{
	if (tabs_msg_type->value() == tab_redx_snw ) {
		show_filename(def_redx_snw_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_redx_snw_textout()
{
	string redx_snw_fname = ICS_dir;
	redx_snw_fname.append("redx_snw.txt");

	update_redx_snwfields();
	string formredx_snw = redx_snw_text_template;

	string X = "X"; string SP = " ";
	TRIAD *ptriad = redx_triad;
	while (ptriad->ftype != E) {
		if (ptriad->ftype == S || ptriad->ftype == T)
			replacestr(formredx_snw, ptriad->htmlname, *(ptriad->ps) );
		else if (ptriad->ftype == B)
			replacestr(formredx_snw, ptriad->htmlname, (*(ptriad->pb) ? X : SP));
		ptriad++;
	}

	FILE *fileredx_snw = fopen(redx_snw_fname.c_str(), "w");
	fprintf(fileredx_snw,"%s", formredx_snw.c_str());
	fclose(fileredx_snw);

	open_url(redx_snw_fname.c_str());
}

