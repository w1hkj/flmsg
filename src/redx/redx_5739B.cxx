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

string s_redx_5739B_nbr;
string s_redx_5739B_name;
string s_redx_5739B_state;
string s_redx_5739B_cnty;
string s_redx_5739B_city;
string s_redx_5739B_date;
string s_redx_5739B_georef;
string s_redx_5739B_north;
string s_redx_5739B_east;
string s_redx_5739B_south;
string s_redx_5739B_west;

string s_redx_5739B_dwell;
string s_redx_5739B_ds;
string s_redx_5739B_mj;
string s_redx_5739B_mn;
string s_redx_5739B_af;
string s_redx_5739B_in;
string s_redx_5739B_un;
string s_redx_5739B_bs;
string s_redx_5739B_gi;

// could not use real names ... WIN32 barfs
enum QTYPE_5739B { B, S, M, T, I, F, C, E }; 
// bool, string, multi-line string, text, int, float, character, empty

struct QUAD_5739B { 
	QTYPE_5739B  qtype;  // type of field
	string htmnbr;
	void   *ptr;
	Fl_Widget *widget; };

// singular entries in form
QUAD_5739B redx_QUAD_5739B[] = {
{ S,	":drnbr:",		&s_redx_5739B_nbr,			rdx_5739B_nbr },		// 0
{ S,	":drnam:",		&s_redx_5739B_name,			rdx_5739B_name },		// 1
{ S,	":state:",		&s_redx_5739B_state,		rdx_5739B_state },		// 2
{ S,	":cnty:",		&s_redx_5739B_cnty,			rdx_5739B_cnty },		// 3
{ S,	":city:",		&s_redx_5739B_city,			rdx_5739B_city },		// 4
{ S,	":date:",		&s_redx_5739B_date,			rdx_5739B_date },		// 5
{ S,	":georef:",		&s_redx_5739B_georef,		rdx_5739B_georef },		// 6
{ S,	":nbr:",		&s_redx_5739B_dwell,		rdx_5739B_dwell },		// 7
{ S,	":d:",			&s_redx_5739B_ds,			rdx_5739B_ds },			// 8
{ S,	":j:",			&s_redx_5739B_mj,			rdx_5739B_mj },			// 9
{ S,	":n:",			&s_redx_5739B_mn,			rdx_5739B_mn },			// 10
{ S,	":a:",			&s_redx_5739B_af,			rdx_5739B_af },			// 11
{ S,	":i:",			&s_redx_5739B_in,			rdx_5739B_in },			// 12
{ S,	":u:",			&s_redx_5739B_un,			rdx_5739B_un },			// 13
{ S,	":b:",			&s_redx_5739B_bs,			rdx_5739B_bs },			// 14
{ S,	":nb:",			&s_redx_5739B_north,		rdx_5739B_north },		// 15
{ S,	":eb:",			&s_redx_5739B_east,			rdx_5739B_east },		// 16
{ S,	":sb:",			&s_redx_5739B_south,		rdx_5739B_south },		// 17
{ S,	":wb:",			&s_redx_5739B_west,			rdx_5739B_west },		// 18
{ M,	":gi:",			&s_redx_5739B_gi,			rdx_5739B_gi },			// 19
{ E,	"",				NULL,							NULL }
};

string buffredx_5739B;
string def_redx_5739B_filename = "";
string base_redx_5739B_filename = "";
string def_redx_5739B_TemplateName = "";

bool using_redx_5739B_template = false;
static bool fields_initialized = false;

// required to initialize the control pointers in the QUAD_5739B array

static void init_widgets_5739B()
{
	redx_QUAD_5739B[0].widget  = rdx_5739B_nbr;
	redx_QUAD_5739B[1].widget  = rdx_5739B_name;
	redx_QUAD_5739B[2].widget  = rdx_5739B_state;
	redx_QUAD_5739B[3].widget  = rdx_5739B_cnty;
	redx_QUAD_5739B[4].widget  = rdx_5739B_city;
	redx_QUAD_5739B[5].widget  = rdx_5739B_date;
	redx_QUAD_5739B[6].widget  = rdx_5739B_georef;

	redx_QUAD_5739B[7].widget  = rdx_5739B_dwell;
	redx_QUAD_5739B[8].widget  = rdx_5739B_ds;
	redx_QUAD_5739B[9].widget  = rdx_5739B_mj;
	redx_QUAD_5739B[10].widget = rdx_5739B_mn;
	redx_QUAD_5739B[11].widget = rdx_5739B_af;
	redx_QUAD_5739B[12].widget = rdx_5739B_in;
	redx_QUAD_5739B[13].widget = rdx_5739B_un;
	redx_QUAD_5739B[14].widget = rdx_5739B_bs;

	redx_QUAD_5739B[15].widget = rdx_5739B_north;
	redx_QUAD_5739B[16].widget = rdx_5739B_east;
	redx_QUAD_5739B[17].widget = rdx_5739B_south;
	redx_QUAD_5739B[18].widget = rdx_5739B_west;

	redx_QUAD_5739B[19].widget = rdx_5739B_gi;

	fields_initialized = true;
}

//enum QTYPE_5739B { B, S, T, I, F, C, E }; 
// bool, string, text, int, float, character, empty

void clearQUAD_5739B(QUAD_5739B *p)
{
	QTYPE_5739B qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B : (*(bool *)(p->ptr)) = false; break;
			case S :
			case M : ((string *)(p->ptr))->clear(); break;
			case T : ((string *)(p->ptr))->clear(); break;
			case C : (*(char *)(p->ptr)) = ' '; break;
			case I : (*(int *)(p->ptr)) = 0; break;
			case F : (*(float *)(p->ptr)) = 0.0; break;
			case E : return;
		}
		p++;
	}
}

void clear_redx_5739Bfields()
{
	if (!fields_initialized) init_widgets_5739B();
	clearQUAD_5739B(redx_QUAD_5739B);
}

bool checkQUAD_5739B(QUAD_5739B *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	QTYPE_5739B qt = E;
	while ((qt = p->qtype) != E) {
		if (p->widget == NULL) return false;
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) != ((Fl_Check_Button *)p->widget)->value())
					return true;
				break;
			case S:
			case M:
				if (*((string *)(p->ptr)) != ((Fl_Input2 *)p->widget)->value())
					return true;
				break;
			case T:
				if (*((string *)(p->ptr)) != ((FTextEdit *)p->widget)->buffer()->text())
					return true;
				break;
			case C:
				c = ' ';
				if (((Fl_Input2 *)p->widget)->value()[0])
					c = ((Fl_Input2 *)p->widget)->value()[0];
				if (*((char *)(p->ptr)) != c)
					return true;
				break;
			case I:
				i = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%d", &i);
				if (*((int *)(p->ptr)) != i)
					return true;
				break;
			case F:
				f = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%f", &f);
				if (*((float *)(p->ptr)) != f)
					return true;
				break;
			case E:
			default: return false;
		}
		p++;
	}
	return false;
}

bool check_redx_5739Bfields()
{
	return checkQUAD_5739B(redx_QUAD_5739B);
}

void updateQUAD_5739B(QUAD_5739B *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	QTYPE_5739B qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = ((Fl_Check_Button *)p->widget)->value();
				break;
			case S:
			case M:
				*((string *)(p->ptr)) = ((Fl_Input2 *)p->widget)->value();
				break;
			case T:
				*((string *)(p->ptr)) = ((FTextEdit *)p->widget)->buffer()->text();
				break;
			case C:
				c = ' ';
				if (((Fl_Input2 *)p->widget)->value()[0])
					c = ((Fl_Input2 *)p->widget)->value()[0];
				*((char *)(p->ptr)) = c;
				break;
			case I:
				i = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%d", &i);
				*((int *)(p->ptr)) = i;
				break;
			case F:
				f = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%f", &f);
				*((float *)(p->ptr)) = f;
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void update_redx_5739Bfields()
{
	if (!fields_initialized) init_widgets_5739B();
	updateQUAD_5739B(redx_QUAD_5739B);
}

void updateFORM_5739B(QUAD_5739B *p)
{
	char val[20];
	QTYPE_5739B qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				((Fl_Check_Button *)p->widget)->value(*((bool *)(p->ptr)));
				break;
			case S:
			case M:
				((Fl_Input2 *)p->widget)->value(((string *)(p->ptr))->c_str());
				break;
			case T:
				((FTextEdit *)p->widget)->clear();
				((FTextEdit *)p->widget)->add(((string *)(p->ptr))->c_str());
				break;
			case C:
				val[0] = *((char *)(p->ptr));
				val[1] = 0;
				((Fl_Input2 *)p->widget)->value(val);
				break;
			case I:
				if (*((int *)(p->ptr)) == 0)
					((Fl_Input2 *)p->widget)->value("");
				else {
					snprintf(val, sizeof(val), "%d", *((int *)(p->ptr)));
					((Fl_Input2 *)p->widget)->value(val);
				}
				break;
			case F:
				snprintf(val, sizeof(val), "%f", *((float *)(p->ptr)));
				((Fl_Input2 *)p->widget)->value(val);
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void update_redx_5739Bform()
{
	if (!fields_initialized) init_widgets_5739B();
	updateFORM_5739B(redx_QUAD_5739B);
}

void clear_redx_5739B_form()
{
	clear_redx_5739Bfields();
	update_redx_5739Bform();
}

static string mbuff;

void make_buffQUAD_5739B(QUAD_5739B *p)
{
	string one = "1"; string zero = "0";
	string sval = " ";
	char szval[20];
	QTYPE_5739B qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) == true)
					mbuff.append( lineout( p->htmnbr, *((bool *)(p->ptr)) ? one : zero));
				break;
			case S:
			case M:
				if (((string *)(p->ptr))->length())
					mbuff.append( lineout( p->htmnbr, *((string *)(p->ptr))));
				break;
			case T:
				mbuff.append( lineout( p->htmnbr, *((string *)(p->ptr))));
				break;
			case C:
				if ((*(char *)(p->ptr)) != 0 && *((char *)(p->ptr)) != ' ') {
					sval = " ";
					sval[0] = *((char *)(p->ptr));
					mbuff.append( lineout( p->htmnbr, sval));
				}
				break;
			case I:
				if (*((int*)(p->ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
					sval = szval;
					mbuff.append( lineout( p->htmnbr, sval) );
				}
				break;
			case F:
				if (*((float *)(p->ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
					sval = szval;
					mbuff.append( lineout( p->htmnbr, sval) );
				}
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void make_buffredx_5739B(bool compress = false)
{
	mbuff.clear();
	make_buffQUAD_5739B(redx_QUAD_5739B);
	if (compress) compress_maybe(mbuff);
	buffredx_5739B.append(mbuff);
}

void readQUAD_5739B(string data, QUAD_5739B *p)
{
	int i = 0;
	float f;
	QTYPE_5739B qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = (findstr( data, p->htmnbr ) == "1");
				break;
			case S:
			case M:
				*((string *)(p->ptr)) = findstr( data, p->htmnbr );
				break;
			case T:
				*((string *)(p->ptr)) = findstr( data, p->htmnbr );
				break;
			case C:
				*((char *)(p->ptr)) = findstr( data, p->htmnbr )[0];
				break;
			case I:
				i = 0;
				sscanf( findstr( data, p->htmnbr ).c_str(), "%d", &i);
				*((int *)(p->ptr)) = i;
				break;
			case F:
				f = 0;
				sscanf( findstr( data, p->htmnbr ).c_str(), "%f", &f);
				*((float *)(p->ptr)) = f;
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void read_redx_5739B_buffer(string data)
{
	clear_redx_5739Bfields();
	read_header(data);

	readQUAD_5739B (data, redx_QUAD_5739B);
	update_redx_5739Bform();
}

void cb_redx_5739B_new()
{
	if (check_redx_5739Bfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_redx_5739B_save();
		}
	}
	clear_redx_5739B_form();
	clear_header();
	def_redx_5739B_filename = ICS_msg_dir;
	def_redx_5739B_filename.append("new"FREDX5739B_EXT);
	show_filename(def_redx_5739B_filename);
	using_redx_5739B_template = false;
}

void cb_redx_5739B_import()
{
	fl_alert2("Not implemented");
}

void cb_redx_5739B_export()
{
	fl_alert2("Not implemented");
}

void cb_redx_5739B_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_redx_5739B_form();
	read_redx_5739B_buffer(inpbuffer);
	def_redx_5739B_filename = ICS_msg_dir;
	def_redx_5739B_filename.append(wrapfilename);
	show_filename(def_redx_5739B_filename);
	using_redx_5739B_template = false;
}

int eval_redx_5739B_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_redx_5739B_filename).append("]");
	update_redx_5739Bfields();
	update_header(FROM);
	evalstr.append(header("<redx_5739B>"));
	buffredx_5739B.clear();
	make_buffredx_5739B(true);
	if (buffredx_5739B.empty()) return 0;
	compress_maybe( buffredx_5739B );
	evalstr.append( buffredx_5739B );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_redx_5739B_wrap_export()
{
	if (check_redx_5739Bfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_5739Bfields();

	if (base_redx_5739B_filename == "new"FREDX5739B_EXT || base_redx_5739B_filename == "default"FREDX5739B_EXT)
		if (!cb_redx_5739B_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_redx_5739B_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffredx_5739B.assign(header("<redx_5739B>"));
		make_buffredx_5739B(true);
		export_wrapfile(base_redx_5739B_filename, wrapfilename, buffredx_5739B, pext != ".wrap");

		buffredx_5739B.assign(header("<redx_5739B>"));
		make_buffredx_5739B(false);
		write_redx_5739B(def_redx_5739B_filename);
	}
}

void cb_redx_5739B_wrap_autosend()
{
	if (check_redx_5739Bfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_5739Bfields();

	if (base_redx_5739B_filename == "new"FREDX5739B_EXT || base_redx_5739B_filename == "default"FREDX5739B_EXT)
		if (!cb_redx_5739B_save_as()) return;

	update_header(FROM);
	buffredx_5739B.assign(header("<redx_5739B>"));
	make_buffredx_5739B(true);
	xfr_via_socket(base_redx_5739B_filename, buffredx_5739B);

	buffredx_5739B.assign(header("<redx_5739B>"));
	make_buffredx_5739B(false);
	write_redx_5739B(def_redx_5739B_filename);
}

void cb_redx_5739B_load_template()
{
	string def_redx_5739B_filename = def_redx_5739B_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"TREDX5739B_EXT,
			def_redx_5739B_filename.c_str());
	if (p) {
		clear_redx_5739B_form();
		read_data_file(p);
		def_redx_5739B_TemplateName = p;
		show_filename(def_redx_5739B_TemplateName);
		using_redx_5739B_template = true;
	}
}

void cb_redx_5739B_save_template()
{
	if (!using_redx_5739B_template) {
		cb_redx_5739B_save_as_template();
		return;
	}
	string def_redx_5739B_filename = def_redx_5739B_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"TREDX5739B_EXT,
			def_redx_5739B_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_redx_5739Bfields();
		buffredx_5739B.assign(header("<redx_5739B>"));
		make_buffredx_5739B();
		write_redx_5739B(p);
	}
}

void cb_redx_5739B_save_as_template()
{
	string def_redx_5739B_filename = def_redx_5739B_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"TREDX5739B_EXT,
			def_redx_5739B_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_redx_5739B_TemplateName = p;
		if (strlen(pext) == 0) def_redx_5739B_TemplateName.append(TREDX5739B_EXT);
		remove_spaces_from_filename(def_redx_5739B_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_redx_5739Bfields();
		buffredx_5739B.assign(header("<redx_5739B>"));
		make_buffredx_5739B();
		write_redx_5739B(def_redx_5739B_TemplateName);

		show_filename(def_redx_5739B_TemplateName);
		using_redx_5739B_template = true;
	}
}

void cb_redx_5739B_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-redx_5739B\t*"FREDX5739B_EXT,
					def_redx_5739B_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_redx_5739B_form();
	read_data_file(p);
	using_redx_5739B_template = false;
	def_redx_5739B_filename = p;
	show_filename(def_redx_5739B_filename);
}

void write_redx_5739B(string s)
{
	FILE *fileredx_5739B = fopen(s.c_str(), "w");
	if (!fileredx_5739B) return;

	fwrite(buffredx_5739B.c_str(), buffredx_5739B.length(), 1, fileredx_5739B);
	fclose(fileredx_5739B);
}


bool cb_redx_5739B_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FREDX5739B_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_redx_5739B_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-redx_5739B\t*"FREDX5739B_EXT,
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) {
		string haystack = p;
		if (haystack.find(newfilename) != string::npos) {
			int n = atoi(progStatus.sernbr.c_str());
			n++;
			char szn[10];
			snprintf(szn, sizeof(szn), "%d", n);
			progStatus.sernbr = szn;
			txt_sernbr->value(szn);
			txt_sernbr->redraw();
		}
	}

	const char *pext = fl_filename_ext(p);
	def_redx_5739B_filename = p;
	if (strlen(pext) == 0) def_redx_5739B_filename.append(FREDX5739B_EXT);

	remove_spaces_from_filename(def_redx_5739B_filename);

	update_header(NEW);
	update_redx_5739Bfields();
	buffredx_5739B.assign(header("<redx_5739B>"));
	make_buffredx_5739B();
	write_redx_5739B(def_redx_5739B_filename);

	using_redx_5739B_template = false;
	show_filename(def_redx_5739B_filename);
	return true;
}

void cb_redx_5739B_save()
{
	if (base_redx_5739B_filename == "new"FREDX5739B_EXT || 
		base_redx_5739B_filename == "default"FREDX5739B_EXT ||
		using_redx_5739B_template == true) {
		cb_redx_5739B_save_as();
		return;
	}

	if (check_redx_5739Bfields()) update_header(CHANGED);
	update_redx_5739Bfields();
	buffredx_5739B.assign(header("<redx_5739B>"));
	make_buffredx_5739B();
	write_redx_5739B(def_redx_5739B_filename);

	using_redx_5739B_template = false;
}

void quad_to_html_5739B( string &target, QUAD_5739B *p)
{
	string X = "X"; string SP = " ";
	string sval = " ";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B)
			replacestr(target, p->htmnbr, *((bool *)(p->ptr)) ? X : SP);
		else if (p->qtype == S)
			replacestr(target, p->htmnbr, *((string *)(p->ptr)));
		else if (p->qtype == M) {
			sval = *((string *)(p->ptr));
			size_t np = string::npos;
			while ( (np = sval.find("\n")) != string::npos)
				sval.replace(np, 1, "<br>");
			replacestr(target, p->htmnbr, sval);
		} else if (p->qtype == T)
			replacestr(target, p->htmnbr, *((string *)(p->ptr)));
		else if (p->qtype == C) {
			sval = " ";
			sval[0] = *((char *)(p->ptr));
			replacestr(target, p->htmnbr, sval);
		}
		else if (p->qtype == I) {
			if (*((int *)(p->ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
				sval = szval;
			} else sval.clear();
				replacestr(target, p->htmnbr, sval);
		}
		else if (p->qtype == F) {
			if (*((float *)(p->ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
				sval = szval;
			} else sval.clear();
			replacestr(target, p->htmnbr, sval);
		}
		p++;
	}
}

void cb_redx_5739B_html()
{
	string name_name = fl_filename_name(def_redx_5739B_filename.c_str());
	size_t p = name_name.rfind('.');
	if (p != string::npos) name_name.erase(p);

	string redx_5739B_name = ICS_dir;
	redx_5739B_name.append(name_name);
	redx_5739B_name.append(".html");

	update_redx_5739Bfields();
	string formredx_5739B = redx_5739B_html_template;

	replacestr(formredx_5739B, TITLE, name_name);

	quad_to_html_5739B (formredx_5739B, redx_QUAD_5739B);

	FILE *fileredx_5739B = fopen(redx_5739B_name.c_str(), "w");
	fprintf(fileredx_5739B,"%s", formredx_5739B.c_str());
	fclose(fileredx_5739B);

	open_url(redx_5739B_name.c_str());
}

void cb_5739B_msg_type()
{
	if (selected_form == REDX5739B ) {
		show_filename(def_redx_5739B_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void quad_to_text( string &target, QUAD_5739B *p)
{
	string X = "X"; string SP = " ";
	string sval = " ";
	string del = "DELETE";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B) {
			bool b = *((bool *)(p->ptr));
			if (b) replacestr(target, p->htmnbr, X);
			else replacestr(target, p->htmnbr, del);
		} else if (p->qtype == S || p->qtype == M) {
			if (((string *)(p->ptr))->length())
				replacestr(target, p->htmnbr, *((string *)(p->ptr)));
			else replacestr(target, p->htmnbr, del);
		} else if (p->qtype == T) {
			if (((string *)(p->ptr))->length())
				replacestr(target, p->htmnbr, *((string *)(p->ptr)));
			else replacestr(target, p->htmnbr, del);
		} else if (p->qtype == C) {
			sval = " ";
			sval[0] = *((char *)(p->ptr));
			if (sval[0] != 0 && sval[0] != ' ')
				replacestr(target, p->htmnbr, sval);
			else replacestr(target, p->htmnbr, del);
		}
		else if (p->qtype == I) {
			if (*((int *)(p->ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
				sval = szval;
				replacestr(target, p->htmnbr, sval);
			} else replacestr(target, p->htmnbr, del);
		}
		else if (p->qtype == F) {
			if (*((float *)(p->ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
				sval = szval;
				replacestr(target, p->htmnbr, sval);
			} else replacestr(target, p->htmnbr, del);
		}
		p++;
	}
}

void strip_text_5739B( string &target )
{
	size_t p = 0, p1, p2;
	while ((p = target.find ("DELETE"), p) != string::npos) {
		p1 = target.rfind ("\n", p);
		p2 = target.find ("\n", p);
		if (p1 != string::npos && p2 != string::npos)
			target.erase( p1, p2 - p1 );
		p++;
	}
}

void cb_redx_5739B_textout()
{
	string redx_5739B_name = ICS_dir;
	redx_5739B_name.append("redx_5739B.txt");

	update_redx_5739Bfields();
	string formredx_5739B = redx_5739B_text_template;

	quad_to_text (formredx_5739B, redx_QUAD_5739B);

	strip_text_5739B (formredx_5739B);

	FILE *fileredx_5739B = fopen(redx_5739B_name.c_str(), "w");
	fprintf(fileredx_5739B,"%s", formredx_5739B.c_str());
	fclose(fileredx_5739B);

	open_url(redx_5739B_name.c_str());
}

