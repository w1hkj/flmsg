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
#include "combo.h"
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

string wxhc_rptsta;
string wxhc_email;
string wxhc_phone;
string wxhc_addr;
string wxhc_city;
string wxhc_state;
string wxhc_country;
string wxhc_lat;
string wxhc_long;
string wxhc_date;
string wxhc_time;

bool wxhc_meas;
bool wxhc_est;
string wxhc_wind_speed;
string wxhc_wind_speed_units;
string wxhc_wind_gusts;
string wxhc_wind_gusts_units;
string wxhc_wind_dir;
string wxhc_wind_degrees;
string wxhc_baro_press;
string wxhc_baro_units;

string wxhc_comments;

const char *s_wsu_units[] = { "MPH", "KNOTS", "KPH", NULL };
const char *s_wdu_units[] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW", NULL };
const char *s_baro_units[] = { "Inches", "Millibars", NULL };

// could not use real names ... WIN32 barfs
enum NHC_QTYPE { B, S, M, T, I, F, C, O, E }; 
// bool, string, multi-line string, text, int, float, character, cOmbo, empty

struct NHC_QUAD { 
	NHC_QTYPE  qtype;  // type of field
	string html_fld;
	void   *ptr;
	Fl_Widget *widget; };

NHC_QUAD wxhc_QUAD[] = {
{ S,	":rptsta:",		&wxhc_rptsta,			w_wxhc_rptsta },			// 0
{ S,	":email:",		&wxhc_email,			w_wxhc_email },				// 1
{ S,	":phone:",		&wxhc_phone,			w_wxhc_phone },				// 2
{ S,	":addr:",		&wxhc_addr,				w_wxhc_addr },				// 3
{ S,	":city:",		&wxhc_city,				w_wxhc_city },				// 4
{ S,	":state:",		&wxhc_state,			w_wxhc_state },				// 5
{ S,	":country:",	&wxhc_country,			w_wxhc_country },			// 6
{ S,	":lat:",		&wxhc_lat,				w_wxhc_lat },				// 7
{ S,	":long:",		&wxhc_long,				w_wxhc_long },				// 8
{ S,	":date:",		&wxhc_date,				w_wxhc_date },				// 9
{ S,	":time:",		&wxhc_time,				w_wxhc_time },				// 10

{ B,	":meas:",		&wxhc_meas,				w_wxhc_meas },				// 11
{ B,	":est:",		&wxhc_est,				w_wxhc_est },				// 12
{ S,	":wspd:",		&wxhc_wind_speed,		w_wxhc_wind_speed },		// 13
{ O,	":wsunits:",	&wxhc_wind_speed_units,	w_wxhc_wind_speed_units},	// 14
{ S,	":wgst:",		&wxhc_wind_gusts,		w_wxhc_wind_gusts },		// 15
{ O,	":wgunits:",	&wxhc_wind_gusts_units,	w_wxhc_wind_gusts_units },	// 16
{ O,	":wdir:",		&wxhc_wind_dir,			w_wxhc_wind_dir },			// 17
{ S,	":wdeg:",		&wxhc_wind_degrees,		w_wxhc_wind_degrees },		// 18
{ S,	":baro:",		&wxhc_baro_press,		w_wxhc_baro_press },		// 19
{ O,	":bunits:",		&wxhc_baro_units,		w_wxhc_baro_units },		// 20

{ T,	":cmmts:",		&wxhc_comments,			w_wxhc_comments },			// 21

{ E,	"",				NULL,					NULL }
};

string buffwxhc;
string def_wxhc_filename = "";
string base_wxhc_filename = "";
string def_wxhc_TemplateName = "";

bool using_wxhc_template = false;
static bool fields_initialized = false;

// required to initialize the control pointers in the QUAD array

static void init_widgets()
{
	wxhc_QUAD[0].widget  = w_wxhc_rptsta;
	wxhc_QUAD[1].widget  = w_wxhc_email;
	wxhc_QUAD[2].widget  = w_wxhc_phone;
	wxhc_QUAD[3].widget  = w_wxhc_addr;
	wxhc_QUAD[4].widget  = w_wxhc_city;
	wxhc_QUAD[5].widget  = w_wxhc_state;
	wxhc_QUAD[6].widget  = w_wxhc_country;
	wxhc_QUAD[7].widget  = w_wxhc_lat;
	wxhc_QUAD[8].widget  = w_wxhc_long;
	wxhc_QUAD[9].widget  = w_wxhc_date;
	wxhc_QUAD[10].widget = w_wxhc_time;
	wxhc_QUAD[11].widget = w_wxhc_meas;
	wxhc_QUAD[12].widget = w_wxhc_est;
	wxhc_QUAD[13].widget = w_wxhc_wind_speed;
	wxhc_QUAD[14].widget = w_wxhc_wind_speed_units;
	wxhc_QUAD[15].widget = w_wxhc_wind_gusts;
	wxhc_QUAD[16].widget = w_wxhc_wind_gusts_units;
	wxhc_QUAD[17].widget = w_wxhc_wind_dir;
	wxhc_QUAD[18].widget = w_wxhc_wind_degrees;
	wxhc_QUAD[19].widget = w_wxhc_baro_press;
	wxhc_QUAD[20].widget = w_wxhc_baro_units;
	wxhc_QUAD[21].widget = w_wxhc_comments;

	fields_initialized = true;
}

//enum NHC_QTYPE { B, S, T, I, F, C, E }; 
// bool, string, text, int, float, character, empty

static void clearQUAD(NHC_QUAD *p)
{
	NHC_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B : (*(bool *)(p->ptr)) = false; break;
			case S :
			case M : ((string *)(p->ptr))->clear(); break;
			case T : ((string *)(p->ptr))->clear(); break;
			case C : (*(char *)(p->ptr)) = ' '; break;
			case I : (*(int *)(p->ptr)) = 0; break;
			case F : (*(float *)(p->ptr)) = 0.0; break;
			case O : break;
			case E : return;
		}
		p++;
	}
	wxhc_est = true;
	wxhc_wind_speed_units = s_wsu_units[0];
	wxhc_wind_gusts_units = s_wsu_units[0];
	wxhc_wind_dir = s_wdu_units[0];
	wxhc_baro_units = s_baro_units[0];
}

void clear_wxhcfields()
{
	if (!fields_initialized) init_widgets();
	clearQUAD(wxhc_QUAD);
}

static bool checkQUAD(NHC_QUAD *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	NHC_QTYPE qt = E;
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
			case O:
				if (*((string *)(p->ptr)) != ((Fl_ListBox *)p->widget)->value())
					return true;
				break;
			case E:
			default: return false;
		}
		p++;
	}
	return false;
}

bool check_wxhcfields()
{
	return checkQUAD(wxhc_QUAD);
}

static void updateQUAD(NHC_QUAD *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	NHC_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = ((Fl_Check_Button *)p->widget)->value();
				break;
			case S:
			case M:
				*((string *)(p->ptr)) = ((Fl_Input2 *)p->widget)->value();
				break;
			case O:
				*((string *)(p->ptr)) = ((Fl_ListBox *)p->widget)->value();
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

void update_wxhcfields()
{
	if (!fields_initialized) init_widgets();
	updateQUAD(wxhc_QUAD);
}

void set_nhc_wx_combos() {
	const char **s = s_wsu_units;
	int i = 0;
	w_wxhc_wind_speed_units->clear();
	while (s[i]) { w_wxhc_wind_speed_units->add(s[i]); 
	i++;}

	s = s_wsu_units;
	i = 0;
	w_wxhc_wind_gusts_units->clear();
	while (s[i]) { w_wxhc_wind_gusts_units->add(s[i]); i++; }

	s = s_wdu_units;
	i = 0;
	w_wxhc_wind_dir->clear();
	while (s[i]) { w_wxhc_wind_dir->add(s[i]); i++; }

	s = s_baro_units;
	i = 0;
	w_wxhc_baro_units->clear();
	while (s[i]) { w_wxhc_baro_units->add(s[i]); i++; }

}

static void updateFORM(NHC_QUAD *p)
{
	char val[20];
	NHC_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				((Fl_Check_Button *)p->widget)->value(*((bool *)(p->ptr)));
				break;
			case S:
			case M:
				((Fl_Input2 *)p->widget)->value(((string *)(p->ptr))->c_str());
				break;
			case O:
				((Fl_ListBox *)p->widget)->put_value(((string *)(p->ptr))->c_str());
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

void update_wxhcform()
{
	if (!fields_initialized) init_widgets();
	updateFORM(wxhc_QUAD);
}

void clear_wxhc_form()
{
	clear_wxhcfields();
	update_wxhcform();
}

static string mbuff;

static void make_buffQUAD(NHC_QUAD *p)
{
	string one = "1"; string zero = "0";
	string sval = " ";
	char szval[20];
	NHC_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) == true)
					mbuff.append( lineout( p->html_fld, *((bool *)(p->ptr)) ? one : zero));
				break;
			case O:
			case S:
			case M:
				if (((string *)(p->ptr))->length())
					mbuff.append( lineout( p->html_fld, *((string *)(p->ptr))));
				break;
			case T:
				mbuff.append( lineout( p->html_fld, *((string *)(p->ptr))));
				break;
			case C:
				if ((*(char *)(p->ptr)) != 0 && *((char *)(p->ptr)) != ' ') {
					sval = " ";
					sval[0] = *((char *)(p->ptr));
					mbuff.append( lineout( p->html_fld, sval));
				}
				break;
			case I:
				if (*((int*)(p->ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
					sval = szval;
					mbuff.append( lineout( p->html_fld, sval) );
				}
				break;
			case F:
				if (*((float *)(p->ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
					sval = szval;
					mbuff.append( lineout( p->html_fld, sval) );
				}
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void make_buffwxhc(bool compress = false)
{
	mbuff.clear();
	make_buffQUAD(wxhc_QUAD);
	if (compress) compress_maybe(mbuff);
	buffwxhc.append(mbuff);
}

static void readQUAD(string data, NHC_QUAD *p)
{
	int i = 0;
	float f;
	NHC_QTYPE qt = p->qtype;
	while (qt != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = (findstr( data, p->html_fld ) == "1");
				break;
			case O:
			case S:
			case M:
				*((string *)(p->ptr)) = findstr( data, p->html_fld );
				break;
			case T:
				*((string *)(p->ptr)) = findstr( data, p->html_fld );
				break;
			case C:
				*((char *)(p->ptr)) = findstr( data, p->html_fld )[0];
				break;
			case I:
				i = 0;
				sscanf( findstr( data, p->html_fld ).c_str(), "%d", &i);
				*((int *)(p->ptr)) = i;
				break;
			case F:
				f = 0;
				sscanf( findstr( data, p->html_fld ).c_str(), "%f", &f);
				*((float *)(p->ptr)) = f;
				break;
			case E:
			default: return;
		}
		p++;
		qt = p->qtype;
	}
}

void read_wxhc_buffer(string data)
{
	clear_wxhcfields();
	read_header(data);

	readQUAD (data, wxhc_QUAD);
	update_wxhcform();
}

void cb_wxhc_new()
{
	if (check_wxhcfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_wxhc_save();
		}
	}
	clear_wxhc_form();
	clear_header();
	def_wxhc_filename = ICS_msg_dir;
	def_wxhc_filename.append("new").append(FWXHC_EXT);
	show_filename(def_wxhc_filename);
	using_wxhc_template = false;
}

void cb_wxhc_import()
{
	fl_alert2("Not implemented");
}

void cb_wxhc_export()
{
	fl_alert2("Not implemented");
}

void cb_wxhc_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_wxhc_form();
	read_wxhc_buffer(inpbuffer);
	def_wxhc_filename = ICS_msg_dir;
	def_wxhc_filename.append(wrapfilename);
	show_filename(def_wxhc_filename);
	using_wxhc_template = false;
}

int eval_wxhc_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_wxhc_filename).append("]");
	update_wxhcfields();
	update_header(FROM);
	evalstr.append(header("<nhc_wx>"));
	buffwxhc.clear();
	make_buffwxhc(true);
	if (buffwxhc.empty()) return 0;
	compress_maybe( buffwxhc );
	evalstr.append( buffwxhc );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_wxhc_wrap_export()
{
	if (check_wxhcfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_wxhcfields();

	if (base_wxhc_filename == string("new").append(FWXHC_EXT) ||
		base_wxhc_filename == string("default").append(FWXHC_EXT) )
		if (!cb_wxhc_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_wxhc_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffwxhc.assign(header("<nhc_wx>"));
		make_buffwxhc(true);
		export_wrapfile(base_wxhc_filename, wrapfilename, buffwxhc, pext != ".wrap");

		buffwxhc.assign(header("<nhc_wx>"));
		make_buffwxhc(false);
		write_wxhc(def_wxhc_filename);
	}
}

void cb_wxhc_wrap_autosend()
{
	if (check_wxhcfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_wxhcfields();

	if (base_wxhc_filename == string("new").append(FWXHC_EXT) ||
		base_wxhc_filename == string("default").append(FWXHC_EXT) )
		if (!cb_wxhc_save_as()) return;

	update_header(FROM);
	buffwxhc.assign(header("<nhc_wx>"));
	make_buffwxhc(true);
	xfr_via_socket(base_wxhc_filename, buffwxhc);

	buffwxhc.assign(header("<nhc_wx>"));
	make_buffwxhc(false);
	write_wxhc(def_wxhc_filename);
}

void cb_wxhc_load_template()
{
	string def_wxhc_filename = def_wxhc_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			string("Template file\t*").append(TWXHC_EXT).c_str(),
			def_wxhc_filename.c_str());
	if (p) {
		clear_wxhc_form();
		read_data_file(p);
		def_wxhc_TemplateName = p;
		show_filename(def_wxhc_TemplateName);
		using_wxhc_template = true;
	}
}

void cb_wxhc_save_template()
{
	if (!using_wxhc_template) {
		cb_wxhc_save_as_template();
		return;
	}
	string def_wxhc_filename = def_wxhc_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			string("Template file\t*").append(TWXHC_EXT).c_str(),
			def_wxhc_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_wxhcfields();
		buffwxhc.assign(header("<nhc_wx>"));
		make_buffwxhc();
		write_wxhc(p);
	}
}

void cb_wxhc_save_as_template()
{
	string def_wxhc_filename = def_wxhc_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			string("Template file\t*").append(TWXHC_EXT).c_str(),
			def_wxhc_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_wxhc_TemplateName = p;
		if (strlen(pext) == 0) def_wxhc_TemplateName.append(TWXHC_EXT);
		remove_spaces_from_filename(def_wxhc_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_wxhcfields();
		buffwxhc.assign(header("<nhc_wx>"));
		make_buffwxhc();
		write_wxhc(def_wxhc_TemplateName);

		show_filename(def_wxhc_TemplateName);
		using_wxhc_template = true;
	}
}

void cb_wxhc_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			string("ICS-wxhc\t*").append(FWXHC_EXT).c_str(),
			def_wxhc_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_wxhc_form();
	read_data_file(p);
	using_wxhc_template = false;
	def_wxhc_filename = p;
	show_filename(def_wxhc_filename);
}

void write_wxhc(string s)
{
	FILE *filewxhc = fopen(s.c_str(), "w");
	if (!filewxhc) return;

	fwrite(buffwxhc.c_str(), buffwxhc.length(), 1, filewxhc);
	fclose(filewxhc);
}


bool cb_wxhc_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FWXHC_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_wxhc_filename;

	p = FSEL::saveas(
			_("Save data file"),
			string("ICS-wxhc\t*").append(FWXHC_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_wxhc_filename = p;
	if (strlen(pext) == 0) def_wxhc_filename.append(FWXHC_EXT);

	remove_spaces_from_filename(def_wxhc_filename);

	update_header(NEW);
	update_wxhcfields();
	buffwxhc.assign(header("<nhc_wx>"));
	make_buffwxhc();
	write_wxhc(def_wxhc_filename);

	using_wxhc_template = false;
	show_filename(def_wxhc_filename);
	return true;
}

void cb_wxhc_save()
{
	if (base_wxhc_filename == string("new").append(FWXHC_EXT) || 
		base_wxhc_filename == string("default").append(FWXHC_EXT) ||
		using_wxhc_template == true) {
		cb_wxhc_save_as();
		return;
	}

	if (check_wxhcfields()) update_header(CHANGED);
	update_wxhcfields();
	buffwxhc.assign(header("<nhc_wx>"));
	make_buffwxhc();
	write_wxhc(def_wxhc_filename);

	using_wxhc_template = false;
}

static void quad_to_html( string &target, NHC_QUAD *p)
{
	string X = "X"; string SP = " ";
	string sval = " ";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B)
			replacestr(target, p->html_fld, *((bool *)(p->ptr)) ? X : SP);
		else if (p->qtype == S || p->qtype == O)
			replacestr(target, p->html_fld, *((string *)(p->ptr)));
		else if (p->qtype == M) {
			sval = *((string *)(p->ptr));
			size_t np = string::npos;
			while ( (np = sval.find("\n")) != string::npos)
				sval.replace(np, 1, "<br>");
			replacestr(target, p->html_fld, sval);
		} else if (p->qtype == T)
			replacestr(target, p->html_fld, *((string *)(p->ptr)));
		else if (p->qtype == C) {
			sval = " ";
			sval[0] = *((char *)(p->ptr));
			replacestr(target, p->html_fld, sval);
		}
		else if (p->qtype == I) {
			if (*((int *)(p->ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
				sval = szval;
			} else sval.clear();
				replacestr(target, p->html_fld, sval);
		}
		else if (p->qtype == F) {
			if (*((float *)(p->ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
				sval = szval;
			} else sval.clear();
			replacestr(target, p->html_fld, sval);
		}
		p++;
	}
}

void cb_wxhc_html()
{
	string name_name = fl_filename_name(def_wxhc_filename.c_str());
	size_t p = name_name.rfind('.');
	if (p != string::npos) name_name.erase(p);

	string wxhc_rptsta = ICS_dir;
	wxhc_rptsta.append(name_name);
	wxhc_rptsta.append(".html");

	update_wxhcfields();
	string formwxhc = wxhc_html_template;

	replacestr(formwxhc, TITLE, name_name);

	quad_to_html (formwxhc, wxhc_QUAD);

	FILE *filewxhc = fopen(wxhc_rptsta.c_str(), "w");
	fprintf(filewxhc,"%s", formwxhc.c_str());
	fclose(filewxhc);

	open_url(wxhc_rptsta.c_str());
}

static void quad_to_text( string &target, NHC_QUAD *p)
{
	string X = "X"; string SP = " ";
	string sval = " ";
	string del = "DELETE";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B) {
			bool b = *((bool *)(p->ptr));
			if (b) replacestr(target, p->html_fld, X);
			else replacestr(target, p->html_fld, SP);
		} else if (p->qtype == S || p->qtype == M || p->qtype == O) {
			if (((string *)(p->ptr))->length())
				replacestr(target, p->html_fld, *((string *)(p->ptr)));
			else replacestr(target, p->html_fld, del);
		} else if (p->qtype == T) {
			if (((string *)(p->ptr))->length())
				replacestr(target, p->html_fld, *((string *)(p->ptr)));
			else replacestr(target, p->html_fld, del);
		} else if (p->qtype == C) {
			sval = " ";
			sval[0] = *((char *)(p->ptr));
			if (sval[0] != 0 && sval[0] != ' ')
				replacestr(target, p->html_fld, sval);
			else replacestr(target, p->html_fld, del);
		}
		else if (p->qtype == I) {
			if (*((int *)(p->ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
				sval = szval;
				replacestr(target, p->html_fld, sval);
			} else replacestr(target, p->html_fld, del);
		}
		else if (p->qtype == F) {
			if (*((float *)(p->ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
				sval = szval;
				replacestr(target, p->html_fld, sval);
			} else replacestr(target, p->html_fld, del);
		}
		p++;
	}
}

static void strip_text( string &target )
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

void cb_wxhc_textout()
{
	string wxhc_rptsta = ICS_dir;
	wxhc_rptsta.append("wxhc.txt");

	update_wxhcfields();
	string formwxhc = wxhc_text_template;

	quad_to_text (formwxhc, wxhc_QUAD);

	strip_text (formwxhc);

	FILE *filewxhc = fopen(wxhc_rptsta.c_str(), "w");
	fprintf(filewxhc,"%s", formwxhc.c_str());
	fclose(filewxhc);

	open_url(wxhc_rptsta.c_str());
}

