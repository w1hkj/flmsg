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
#include <string>
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

#include "wx_strings.h"

std::string buffstorm;
std::string def_storm_filename = "";
std::string base_storm_filename = "";
std::string def_storm_TemplateName = "";

std::string	storm_date;
std::string	storm_time;
std::string	storm_zone;
std::string	storm_state;
std::string	storm_county;
std::string	storm_location;
bool	storm_tornado;
std::string	storm_tornado_cat;
bool	storm_hail;
std::string	storm_hail_size;
bool	storm_wind;
std::string	storm_wind_cat;
bool	storm_flood;
std::string	storm_flood_cat;
bool	storm_damage;
std::string	storm_damage_cat;
bool	storm_snow;
std::string	storm_snow_tot;
std::string	storm_snow_dur;
bool	storm_f_rain;
std::string	storm_f_rain_tot;
std::string	storm_f_rain_dur;
bool	storm_h_rain;
std::string	storm_h_rain_tot;
std::string	storm_h_rain_dur;
std::string	storm_o_name;
std::string	storm_o_email;
std::string	storm_o_tele;
std::string	storm_o_profile;
std::string 	storm_details;

// could not use real names ... WIN32 barfs
enum STORM_QTYPE { B, D, S, M, T, I, F, C, O, E }; 
// bool, std::string, multi-line std::string, text, int, float, character, cOmbo, empty

struct STORM_QUAD { 
	STORM_QTYPE  qtype;  // type of field
	std::string html_fld;
	void   *ptr;
	Fl_Widget *widget; };

STORM_QUAD sQ[] = {
{ D,	":date:",			&storm_date,			w_storm_date },
{ S,	":time:",			&storm_time,			w_storm_time },
{ O,	":zone:",			&storm_zone,			w_storm_zone },
{ O,	":state:",			&storm_state,			w_storm_state },
{ O,	":county:",			&storm_county,			w_storm_county },
{ S,	":location:",		&storm_location,		w_storm_location },
{ B,	":tornado:",		&storm_tornado,			w_storm_tornado },
{ O,	":tornado_cat:",	&storm_tornado_cat,		w_storm_tornado_cat },
{ B,	":hail:",			&storm_hail,			w_storm_hail },
{ O,	":hail_size:",		&storm_hail_size,		w_storm_hail_size },
{ B,	":high_wind:",		&storm_wind,			w_storm_wind },
{ O,	":speed:",			&storm_wind_cat,		w_storm_wind_cat },
{ B,	":flood:",			&storm_flood,			w_storm_flood },
{ O,	":flood_cat:",		&storm_flood_cat,		w_storm_flood_cat },
{ B,	":damage:",			&storm_damage,			w_storm_damage },
{ O,	":damage_cat:",		&storm_damage_cat,		w_storm_damage_cat },
{ B,	":snow:",			&storm_snow,			w_storm_snow },
{ O,	":snow_tot:",		&storm_snow_tot,		w_storm_snow_tot },
{ O,	":snow_dur:",		&storm_snow_dur,		w_storm_snow_dur },
{ B,	":f_rain:",			&storm_f_rain,			w_storm_f_rain },
{ O,	":f_rain_tot:",		&storm_f_rain_tot,		w_storm_f_rain_tot },
{ O,	":f_rain_dur:",		&storm_f_rain_dur,		w_storm_f_rain_dur },
{ B,	":h_rain:",			&storm_h_rain,			w_storm_h_rain },
{ O,	":h_rain_tot:",		&storm_h_rain_tot,		w_storm_h_rain_tot },
{ O,	":h_rain_dur:",		&storm_h_rain_dur,		w_storm_h_rain_dur },
{ S,	":o_name:",			&storm_o_name,			w_storm_o_name },
{ S,	":o_email:",		&storm_o_email,			w_storm_o_email },
{ S,	":o_tele:",			&storm_o_tele,			w_storm_o_tele },
{ O,	":o_profile:",		&storm_o_profile,		w_storm_o_profile },
{ T,	":details:",		&storm_details,			w_storm_details }
};

int num_quads = (int)(sizeof(sQ) / sizeof(STORM_QUAD));

bool using_storm_template = false;

//------------------------------------------------------------------------------
// required to initialize the control pointers in the QUAD array
//------------------------------------------------------------------------------
static bool fields_initialized = false;

static void init_widget(std::string s, Fl_Widget * w)
{
	for (int i = 0; i < num_quads; i++) {
		if (sQ[i].html_fld == s) {
			sQ[i].widget = w;
			break;
		}
	}
}

static void init_widgets()
{
	init_widget(":date:", (Fl_Widget *)w_storm_date);
	init_widget(":time:", (Fl_Widget *)w_storm_time);
	init_widget(":zone:", (Fl_Widget *)w_storm_zone);
	init_widget(":state:", (Fl_Widget *)w_storm_state);
	init_widget(":county:", (Fl_Widget *)w_storm_county);
	init_widget(":location:", (Fl_Widget *)w_storm_location);
	init_widget(":flood:", (Fl_Widget *)w_storm_flood);
	init_widget(":flood_cat:", (Fl_Widget *)w_storm_flood_cat);
	init_widget(":hail:", (Fl_Widget *)w_storm_hail);
	init_widget(":hail_size:", (Fl_Widget *)w_storm_hail_size);
	init_widget(":high_wind:", (Fl_Widget *)w_storm_wind);
	init_widget(":speed:", (Fl_Widget *)w_storm_wind_cat);
	init_widget(":tornado:", (Fl_Widget *)w_storm_tornado);
	init_widget(":tornado_cat:", (Fl_Widget *)w_storm_tornado_cat);
	init_widget(":damage:", (Fl_Widget *)w_storm_damage);
	init_widget(":damage_cat:", (Fl_Widget *)w_storm_damage_cat);
	init_widget(":snow:", (Fl_Widget *)w_storm_snow);
	init_widget(":snow_tot:", (Fl_Widget *)w_storm_snow_tot);
	init_widget(":snow_dur:", (Fl_Widget *)w_storm_snow_dur);
	init_widget(":f_rain:", (Fl_Widget *)w_storm_f_rain);
	init_widget(":f_rain_tot:", (Fl_Widget *)w_storm_f_rain_tot);
	init_widget(":f_rain_dur:", (Fl_Widget *)w_storm_f_rain_dur);
	init_widget(":h_rain:", (Fl_Widget *)w_storm_h_rain);
	init_widget(":h_rain_tot:", (Fl_Widget *)w_storm_h_rain_tot);
	init_widget(":h_rain_dur:", (Fl_Widget *)w_storm_h_rain_dur);
	init_widget(":o_name:", (Fl_Widget *)w_storm_o_name);
	init_widget(":o_email:", (Fl_Widget *)w_storm_o_email);
	init_widget(":o_tele:", (Fl_Widget *)w_storm_o_tele);
	init_widget(":o_profile:", (Fl_Widget *)w_storm_o_profile);
	init_widget(":details:", (Fl_Widget *)w_storm_details);

	fields_initialized = true;
}
//------------------------------------------------------------------------------

// bool, std::string, multi-line std::string, text, int, float, character, cOmbo, empty
//enum STORM_QTYPE { B, D, S, M, T, I, F, C, O, E }; 

static void clearQUAD()
{
	for (int i = 0; i < num_quads; i++) {
		switch (sQ[i].qtype) {
			case B : (*(bool *)(sQ[i].ptr)) = false; break;
			case S :
			case D :
			case M : ((std::string *)(sQ[i].ptr))->clear(); break;
			case T : ((std::string *)(sQ[i].ptr))->clear(); break;
			case C : (*(char *)(sQ[i].ptr)) = ' ';    break;
			case I : (*(int *)(sQ[i].ptr)) = 0;       break;
			case F : (*(float *)(sQ[i].ptr)) = 0.0;   break;
			case O : ((std::string *)(sQ[i].ptr))->clear(); break;
			case E : return;
		}
	}
}

void clear_stormfields()
{
	if (!fields_initialized) init_widgets();
	clearQUAD();
}

static bool checkQUAD()
{
	float f = 0;
	char c = ' ';
	for (int i = 0; i < num_quads; i++) {
		switch (sQ[i].qtype) {
			case B:
				if (*((bool *)(sQ[i].ptr)) != ((Fl_Check_Button *)sQ[i].widget)->value()){
					return true;
				}
				break;
			case S:
			case M:
				if (*((std::string *)(sQ[i].ptr)) != ((Fl_Input2 *)sQ[i].widget)->value()){
					return true;
				}
				break;
			case D:
				if (*((std::string *)(sQ[i].ptr)) != ((Fl_DateInput *)sQ[i].widget)->value()){
					return true;
				}
				break;
			case T:
				if (*((std::string *)(sQ[i].ptr)) != ((FTextEdit *)sQ[i].widget)->buffer()->text()){
					return true;
				}
				break;
			case C:
				c = ' ';
				if (((Fl_Input2 *)sQ[i].widget)->value()[0])
					c = ((Fl_Input2 *)sQ[i].widget)->value()[0];
				if (*((char *)(sQ[i].ptr)) != c){
					return true;
				}
				break;
			case I:
				i = 0;
				if (((Fl_Input2 *)sQ[i].widget)->value()[0])
					sscanf( ((Fl_Input2 *)sQ[i].widget)->value(), "%d", &i);
				if (*((int *)(sQ[i].ptr)) != i){
					return true;
				}
				break;
			case F:
				f = 0;
				if (((Fl_Input2 *)sQ[i].widget)->value()[0])
					sscanf( ((Fl_Input2 *)sQ[i].widget)->value(), "%f", &f);
				if (*((float *)(sQ[i].ptr)) != f) {
					return true;
				}
				break;
			case O:
				if (((Fl_ListBox *)sQ[i].widget)->index() == 0) break;
				if (*((std::string *)(sQ[i].ptr)) != ((Fl_ListBox *)sQ[i].widget)->value()) {
					return true;
				}
				break;
			case E:
			default: return false;
		}
	}
	return false;
}

bool check_stormfields()
{
	return checkQUAD();
}

static void updateQUAD()
{
	float f = 0;
	char c = ' ';
	for (int i = 0; i < num_quads; i++) {
		switch (sQ[i].qtype) {
			case B:
				*((bool *)(sQ[i].ptr)) = ((Fl_Check_Button *)sQ[i].widget)->value();
				break;
			case S:
			case M:
				*((std::string *)(sQ[i].ptr)) = ((Fl_Input2 *)sQ[i].widget)->value();
				break;
			case D:
				*((std::string *)(sQ[i].ptr)) = ((Fl_DateInput *)sQ[i].widget)->value();
				break;
			case O:
				{	std::string s = ((Fl_ListBox *)sQ[i].widget)->value();
					if (s.find("--") == 0)
						((std::string *)(sQ[i].ptr))->clear();
					else
						*((std::string *)(sQ[i].ptr)) = ((Fl_ListBox *)sQ[i].widget)->value();
				}
				break;
			case T:
				*((std::string *)(sQ[i].ptr)) = ((FTextEdit *)sQ[i].widget)->buffer()->text();
				break;
			case C:
				c = ' ';
				if (((Fl_Input2 *)sQ[i].widget)->value()[0])
					c = ((Fl_Input2 *)sQ[i].widget)->value()[0];
				*((char *)(sQ[i].ptr)) = c;
				break;
			case I:
				i = 0;
				if (((Fl_Input2 *)sQ[i].widget)->value()[0])
					sscanf( ((Fl_Input2 *)sQ[i].widget)->value(), "%d", &i);
				*((int *)(sQ[i].ptr)) = i;
				break;
			case F:
				f = 0;
				if (((Fl_Input2 *)sQ[i].widget)->value()[0])
					sscanf( ((Fl_Input2 *)sQ[i].widget)->value(), "%f", &f);
				*((float *)(sQ[i].ptr)) = f;
				break;
			case E:
			default: return;
		}
	}
}

void update_stormfields()
{
	if (!fields_initialized) init_widgets();
	updateQUAD();
}

static void activate_listbox()
{
	if (w_storm_flood->value())
		w_storm_flood_cat->activate();
	else
		w_storm_flood_cat->deactivate();
	if (w_storm_hail->value())
		w_storm_hail_size->activate();
	else
		w_storm_hail_size->deactivate();
	if (w_storm_wind->value())
		w_storm_wind_cat->activate();
	else
		w_storm_wind_cat->deactivate();
	if (w_storm_tornado->value())
		w_storm_tornado_cat->activate();
	else
		w_storm_tornado_cat->deactivate();
	if (w_storm_damage->value())
		w_storm_damage_cat->activate();
	else
		w_storm_damage_cat->deactivate();
	if (w_storm_snow->value()) {
		w_storm_snow_tot->activate();
		w_storm_snow_dur->activate();
	} else {
		w_storm_snow_tot->deactivate();
		w_storm_snow_dur->deactivate();
	}
	if (w_storm_f_rain->value()) {
		w_storm_f_rain_tot->activate();
		w_storm_f_rain_dur->activate();
	} else {
		w_storm_f_rain_tot->deactivate();
		w_storm_f_rain_dur->deactivate();
	}
	if (w_storm_h_rain->value()) {
		w_storm_h_rain_tot->activate();
		w_storm_h_rain_dur->activate();
	} else {
		w_storm_h_rain_tot->deactivate();
		w_storm_h_rain_dur->deactivate();
	}
}

static void updateFORM()
{
	char val[20];
	for (int i = 0; i < num_quads; i++ ) {
		switch (sQ[i].qtype) {
			case B:
				((Fl_Check_Button *)sQ[i].widget)->value(*((bool *)(sQ[i].ptr)));
				break;
			case S:
			case M:
				((Fl_Input2 *)sQ[i].widget)->value(((std::string *)(sQ[i].ptr))->c_str());
				break;
			case D:
				((Fl_DateInput *)sQ[i].widget)->value(((std::string *)(sQ[i].ptr))->c_str());
				break;
			case O:
				if (((std::string *)(sQ[i].ptr))->empty())
					((Fl_ListBox *)sQ[i].widget)->index(0);
				else
					((Fl_ListBox *)sQ[i].widget)->put_value(((std::string *)(sQ[i].ptr))->c_str());
				break;
			case T:
				((FTextEdit *)sQ[i].widget)->clear();
				((FTextEdit *)sQ[i].widget)->add(((std::string *)(sQ[i].ptr))->c_str());
				break;
			case C:
				val[0] = *((char *)(sQ[i].ptr));
				val[1] = 0;
				((Fl_Input2 *)sQ[i].widget)->value(val);
				break;
			case I:
				if (*((int *)(sQ[i].ptr)) == 0)
					((Fl_Input2 *)sQ[i].widget)->value("");
				else {
					snprintf(val, sizeof(val), "%d", *((int *)(sQ[i].ptr)));
					((Fl_Input2 *)sQ[i].widget)->value(val);
				}
				break;
			case F:
				snprintf(val, sizeof(val), "%f", *((float *)(sQ[i].ptr)));
				((Fl_Input2 *)sQ[i].widget)->value(val);
				break;
			case E:
			default: return;
		}
	}
}

void update_stormform()
{
	if (!fields_initialized) init_widgets();
	updateFORM();
	activate_listbox();
}

void clear_storm_form()
{
	clear_stormfields();
	update_stormform();
	w_storm_state->index(0);
	set_storm_counties(0);
	w_storm_o_profile->index(0);
	w_storm_location->index(0);
	w_storm_zone->index(0);
}

static std::string mbuff;

static void make_buffQUAD()
{
	std::string one = "1"; std::string zero = "0";
	std::string sval = " ";
	char szval[20];
	for (int i = 0; i < num_quads; i++) {
		switch (sQ[i].qtype) {
			case B:
				if (*((bool *)(sQ[i].ptr)) == true)
					mbuff.append( lineout( sQ[i].html_fld, *((bool *)(sQ[i].ptr)) ? one : zero));
				break;
			case O: case S: case D: case M:
				if (((std::string *)(sQ[i].ptr))->length())
					mbuff.append( lineout( sQ[i].html_fld, *((std::string *)(sQ[i].ptr))));
				break;
			case T:
				mbuff.append( lineout( sQ[i].html_fld, *((std::string *)(sQ[i].ptr))));
				break;
			case C:
				if ((*(char *)(sQ[i].ptr)) != 0 && *((char *)(sQ[i].ptr)) != ' ') {
					sval = " ";
					sval[0] = *((char *)(sQ[i].ptr));
					mbuff.append( lineout( sQ[i].html_fld, sval));
				}
				break;
			case I:
				if (*((int*)(sQ[i].ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%d", *((int *)(sQ[i].ptr)) );
					sval = szval;
					mbuff.append( lineout( sQ[i].html_fld, sval) );
				}
				break;
			case F:
				if (*((float *)(sQ[i].ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%f", *((float *)(sQ[i].ptr)));
					sval = szval;
					mbuff.append( lineout( sQ[i].html_fld, sval) );
				}
				break;
			case E:
			default: return;
		}
	}
}

void make_buff_storm(bool compress = false)
{
	mbuff.clear();
	make_buffQUAD();
	if (compress) compress_maybe(mbuff);
	buffstorm.append(mbuff);
}

static void readQUAD(std::string data)
{
	float f;
	for (int i = 0; i < num_quads; i++) {
		switch (sQ[i].qtype) {
			case B:
				*((bool *)(sQ[i].ptr)) = (findstr( data, sQ[i].html_fld ) == "1");
				break;
			case D: case O: case S: case M:
				*((std::string *)(sQ[i].ptr)) = findstr( data, sQ[i].html_fld );
				break;
			case T:
				*((std::string *)(sQ[i].ptr)) = findstr( data, sQ[i].html_fld );
				break;
			case C:
				*((char *)(sQ[i].ptr)) = findstr( data, sQ[i].html_fld )[0];
				break;
			case I:
				i = 0;
				sscanf( findstr( data, sQ[i].html_fld ).c_str(), "%d", &i);
				*((int *)(sQ[i].ptr)) = i;
				break;
			case F:
				f = 0;
				sscanf( findstr( data, sQ[i].html_fld ).c_str(), "%f", &f);
				*((float *)(sQ[i].ptr)) = f;
				break;
			case E:
			default: return;
		}
	}
}

void read_storm_buffer(std::string data)
{
	clear_stormfields();
	read_header(data);

	readQUAD (data);
	update_stormform();
	int idx = w_storm_state->index();
	set_storm_counties(idx);
	w_storm_county->value( ((std::string *)(sQ[4].ptr))->c_str() );
}

void cb_storm_new()
{
	if (check_stormfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_storm_save();
		}
	}
	clear_storm_form();
	clear_header();
	def_storm_filename = ICS_msg_dir;
	def_storm_filename.append("new").append(FSTRM_EXT);
	show_filename(def_storm_filename);
	using_storm_template = false;
}

void cb_storm_import()
{
	fl_alert2("Not implemented");
}

void cb_storm_export()
{
	fl_alert2("Not implemented");
}

void cb_storm_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_storm_form();
	read_storm_buffer(inpbuffer);
	def_storm_filename = ICS_msg_dir;
	def_storm_filename.append(wrapfilename);
	show_filename(def_storm_filename);
	using_storm_template = false;
}

int eval_storm_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_storm_filename).append("]");
	update_stormfields();
	update_header(FROM);
	evalstr.append(header("<storm_wx>"));
	buffstorm.clear();
	make_buff_storm(true);
	if (buffstorm.empty()) return 0;
	compress_maybe( buffstorm );
	evalstr.append( buffstorm );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_storm_wrap_export()
{
	if (check_stormfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_stormfields();

	if (base_storm_filename == std::string("new").append(FSTRM_EXT) ||
		base_storm_filename == std::string("default").append(FSTRM_EXT) )
		if (!cb_storm_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_storm_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffstorm.assign(header("<storm_wx>"));
		make_buff_storm(true);
		export_wrapfile(base_storm_filename, wrapfilename, buffstorm, pext != ".wrap");

		buffstorm.assign(header("<storm_wx>"));
		make_buff_storm(false);
		write_storm(def_storm_filename);
	}
}

void cb_storm_wrap_autosend()
{
	if (check_stormfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_stormfields();

	if (base_storm_filename == std::string("new").append(FSTRM_EXT) ||
		base_storm_filename == std::string("default").append(FSTRM_EXT) )
		if (!cb_storm_save_as()) return;

	update_header(FROM);
	buffstorm.assign(header("<storm_wx>"));
	make_buff_storm(true);
	xfr_via_socket(base_storm_filename, buffstorm);

	buffstorm.assign(header("<storm_wx>"));
	make_buff_storm(false);
	write_storm(def_storm_filename);
}

void cb_storm_load_template()
{
	std::string def_storm_filename = def_storm_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TSTRM_EXT).c_str(),
			def_storm_filename.c_str());
	if (p) {
		clear_storm_form();
		read_data_file(p);
		def_storm_TemplateName = p;
		show_filename(def_storm_TemplateName);
		using_storm_template = true;
	}
}

void cb_storm_save_template()
{
	if (!using_storm_template) {
		cb_storm_save_as_template();
		return;
	}
	std::string def_storm_filename = def_storm_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TSTRM_EXT).c_str(),
			def_storm_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_stormfields();
		buffstorm.assign(header("<storm_wx>"));
		make_buff_storm();
		write_storm(p);
	}
}

void cb_storm_save_as_template()
{
	std::string def_storm_filename = def_storm_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TSTRM_EXT).c_str(),
			def_storm_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_storm_TemplateName = p;
		if (strlen(pext) == 0) def_storm_TemplateName.append(TSTRM_EXT);
		remove_spaces_from_filename(def_storm_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_stormfields();
		buffstorm.assign(header("<storm_wx>"));
		make_buff_storm();
		write_storm(def_storm_TemplateName);

		show_filename(def_storm_TemplateName);
		using_storm_template = true;
	}
}

void cb_storm_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-storm\t*").append(FSTRM_EXT).c_str(),
			def_storm_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_storm_form();
	read_data_file(p);
	using_storm_template = false;
	def_storm_filename = p;
	show_filename(def_storm_filename);
}

void write_storm(std::string s)
{
	FILE *filestorm = fopen(s.c_str(), "w");
	if (!filestorm) return;

	fwrite(buffstorm.c_str(), buffstorm.length(), 1, filestorm);
	fclose(filestorm);
}


bool cb_storm_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(FSTRM_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_storm_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-storm\t*").append(FSTRM_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_storm_filename = p;
	if (strlen(pext) == 0) def_storm_filename.append(FSTRM_EXT);

	remove_spaces_from_filename(def_storm_filename);

	update_header(NEW);
	update_stormfields();
	buffstorm.assign(header("<storm_wx>"));
	make_buff_storm();
	write_storm(def_storm_filename);

	using_storm_template = false;
	show_filename(def_storm_filename);
	return true;
}

void cb_storm_save()
{
	if (base_storm_filename == std::string("new").append(FSTRM_EXT) || 
		base_storm_filename == std::string("default").append(FSTRM_EXT) ||
		using_storm_template == true) {
		cb_storm_save_as();
		return;
	}

	if (check_stormfields()) update_header(CHANGED);
	update_stormfields();
	buffstorm.assign(header("<storm_wx>"));
	make_buff_storm();
	write_storm(def_storm_filename);

	using_storm_template = false;
}

static std::string X = "x"; std::string SP = "_";
static std::string sval = " ";
static std::string del = "";

static void quad_to_html(std::string &target)
{
	char szval[20];
	for (int i = 0; i < num_quads; i++) {
		if (sQ[i].qtype == B)
			replacestr(target, sQ[i].html_fld, *((bool *)(sQ[i].ptr)) ? X : SP);
		else if (sQ[i].qtype == O ) {
			std::string s = *((std::string *)(sQ[i].ptr));
			if (sQ[i].html_fld == ":state:") {
				if (s.length() > 1) s.erase(2);
				replacestr(target, sQ[i].html_fld, s);
			} else if (sQ[i].html_fld == ":zone") {
				size_t cp = s.find(',');
				s.erase(cp);
				replacestr(target, sQ[i].html_fld, s);
			} else if (s.find("--") == 0) {
				replacestr(target, sQ[i].html_fld, del);
			} else {
				if (s.length())
					replacestr(target, sQ[i].html_fld, s);
				else replacestr(target, sQ[i].html_fld, del);
			}
		} else if (sQ[i].qtype == S || sQ[i].qtype == M || sQ[i].qtype == D) {
			if (((std::string *)(sQ[i].ptr))->length())
				replacestr(target, sQ[i].html_fld, *((std::string *)(sQ[i].ptr)));
			else replacestr(target, sQ[i].html_fld, del);
		} else if (sQ[i].qtype == M) {
			sval = *((std::string *)(sQ[i].ptr));
			size_t np = std::string::npos;
			while ( (np = sval.find("\n")) != std::string::npos)
				sval.replace(np, 1, "<br>");
			replacestr(target, sQ[i].html_fld, sval);
		} else if (sQ[i].qtype == T)
			replacestr(target, sQ[i].html_fld, *((std::string *)(sQ[i].ptr)));
		else if (sQ[i].qtype == C) {
			sval = " ";
			sval[0] = *((char *)(sQ[i].ptr));
			replacestr(target, sQ[i].html_fld, sval);
		}
		else if (sQ[i].qtype == I) {
			if (*((int *)(sQ[i].ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(sQ[i].ptr)) );
				sval = szval;
			} else sval.clear();
				replacestr(target, sQ[i].html_fld, sval);
		}
		else if (sQ[i].qtype == F) {
			if (*((float *)(sQ[i].ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(sQ[i].ptr)));
				sval = szval;
			} else sval.clear();
			replacestr(target, sQ[i].html_fld, sval);
		}
	}
}

void cb_storm_html()
{
	std::string name_name = fl_filename_name(def_storm_filename.c_str());
	size_t p = name_name.rfind('.');
	if (p != std::string::npos) name_name.erase(p);

	std::string storm_rptsta = ICS_dir;
	storm_rptsta.append(name_name);
	storm_rptsta.append(".html");

	update_stormfields();
	std::string formstorm = storm_html_template;

	replacestr(formstorm, TITLE, name_name);

	quad_to_html (formstorm);

	FILE *filestorm = fopen(storm_rptsta.c_str(), "w");
	fprintf(filestorm,"%s", formstorm.c_str());
	fclose(filestorm);

	open_url(storm_rptsta.c_str());
}

static void quad_to_text( std::string &target)
{
	char szval[20];
	for (int i = 0; i < num_quads; i++) {
		if (sQ[i].qtype == B)
			replacestr(target, sQ[i].html_fld, *((bool *)(sQ[i].ptr)) ? X : del);
		else if (sQ[i].qtype == O ) {
			std::string s = *((std::string *)(sQ[i].ptr));
			if (sQ[i].html_fld == ":state:") {
				if (s.length() > 1) s.erase(2);
				replacestr(target, sQ[i].html_fld, s);
			} else if (sQ[i].html_fld == ":zone") {
				size_t cp = s.find(',');
				s.erase(cp);
				replacestr(target, sQ[i].html_fld, s);
			} else if (s.find("--") == 0) {
				replacestr(target, sQ[i].html_fld, del);
			} else {
				if (s.length())
					replacestr(target, sQ[i].html_fld, s);
				else replacestr(target, sQ[i].html_fld, del);
			}
		} else if (sQ[i].qtype == S || sQ[i].qtype == M || sQ[i].qtype == D) {
			if (((std::string *)(sQ[i].ptr))->length())
				replacestr(target, sQ[i].html_fld, *((std::string *)(sQ[i].ptr)));
			else replacestr(target, sQ[i].html_fld, del);
		} else if (sQ[i].qtype == T) {
			if (((std::string *)(sQ[i].ptr))->length())
				replacestr(target, sQ[i].html_fld, *((std::string *)(sQ[i].ptr)));
			else replacestr(target, sQ[i].html_fld, del);
		} else if (sQ[i].qtype == C) {
			sval = " ";
			sval[0] = *((char *)(sQ[i].ptr));
			if (sval[0] != 0 && sval[0] != ' ')
				replacestr(target, sQ[i].html_fld, sval);
			else replacestr(target, sQ[i].html_fld, del);
		}
		else if (sQ[i].qtype == I) {
			if (*((int *)(sQ[i].ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(sQ[i].ptr)) );
				sval = szval;
				replacestr(target, sQ[i].html_fld, sval);
			} else replacestr(target, sQ[i].html_fld, del);
		}
		else if (sQ[i].qtype == F) {
			if (*((float *)(sQ[i].ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(sQ[i].ptr)));
				sval = szval;
				replacestr(target, sQ[i].html_fld, sval);
			} else replacestr(target, sQ[i].html_fld, del);
		}
	}
}

void cb_storm_textout()
{
	std::string storm_rptsta = ICS_dir;
	storm_rptsta.append("storm.txt");

	update_stormfields();
	std::string formstorm = storm_text_template;

	quad_to_text (formstorm);

	FILE *filestorm = fopen(storm_rptsta.c_str(), "w");
	fprintf(filestorm,"%s", formstorm.c_str());
	fclose(filestorm);

	open_url(storm_rptsta.c_str());
}

