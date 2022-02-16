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

std::string severe_wx_date;
std::string severe_wx_time;
std::string severe_wx_zone;
bool  severe_wx_exact;
bool  severe_wx_not_exact;

std::string severe_wx_city;
std::string severe_wx_state;
std::string severe_wx_county;

bool  severe_wx_tornado;
bool  severe_wx_funnel_cloud;
bool  severe_wx_wall_cloud;
bool  severe_wx_hail;
std::string severe_wx_hail_size;

bool  severe_wx_high_wind;
std::string severe_wx_wind_speed;
bool  severe_wx_measured;
bool  severe_wx_estimated;

bool  severe_wx_flood;
bool  severe_wx_flash_flood;
bool  severe_wx_other;

bool  severe_wx_dmg_yes;
bool  severe_wx_dmg_no;
bool  severe_wx_inj_yes;
bool  severe_wx_inj_no;

std::string severe_wx_narrative;

// could not use real names ... WIN32 barfs
enum SWX_QTYPE { B, D, S, M, T, I, F, C, O, E }; 
// bool, std::string, multi-line std::string, text, int, float, character, cOmbo, empty

struct SWX_QUAD { 
	SWX_QTYPE  qtype;  // type of field
	std::string html_fld;
	void   *ptr;
	Fl_Widget *widget; };

SWX_QUAD severe_wx_QUAD[] = {
{ D,	":date:",			&severe_wx_date,			w_severe_wx_date },			// 0
{ S,	":time:",			&severe_wx_time,			w_severe_wx_time },			// 1
{ O,	":zone:",			&severe_wx_zone,			w_severe_wx_zone },			// 2
{ O,	":state:",			&severe_wx_state,			w_severe_wx_state },		// 3
{ O,	":county:",			&severe_wx_county,			w_severe_wx_county },		// 4
{ S,	":city:",			&severe_wx_city,			w_severe_wx_city },			// 5
{ S,	":speed:",			&severe_wx_wind_speed,		w_severe_wx_wind_speed },	// 6
{ T,	":narrative:",		&severe_wx_narrative,		w_severe_wx_narrative },	// 7
{ O,	":hail_size:",		&severe_wx_hail_size,		w_severe_wx_hail_size},		// 8
{ B,	":exact:",			&severe_wx_exact,			w_severe_wx_exact },		// 9
{ B,	":not_exact:",		&severe_wx_not_exact,		w_severe_wx_not_exact },	// 10
{ B,	":tornado:",		&severe_wx_tornado,			w_severe_wx_tornado },		// 11
{ B,	":funnel_cloud:",	&severe_wx_funnel_cloud,	w_severe_wx_funnel_cloud },	// 12
{ B,	":wall_cloud:",		&severe_wx_wall_cloud,		w_severe_wx_wall_cloud },	// 13
{ B,	":hail:",			&severe_wx_hail,			w_severe_wx_hail },			// 14
{ B,	":high_wind:",		&severe_wx_high_wind,		w_severe_wx_high_wind },	// 15
{ B,	":measured:",		&severe_wx_measured,		w_severe_wx_measured },		// 16
{ B,	":estimated:",		&severe_wx_estimated,		w_severe_wx_estimated },	// 17
{ B,	":flood:",			&severe_wx_flood,			w_severe_wx_flood },		// 18
{ B,	":flash_flood:",	&severe_wx_flash_flood,		w_severe_wx_flash_flood },	// 19
{ B,	":other:",			&severe_wx_other,			w_severe_wx_other },		// 20
{ B,	":dmg_yes:",		&severe_wx_dmg_yes,			w_severe_wx_dmg_yes },		// 21
{ B,	":dmg_no:",			&severe_wx_dmg_no,			w_severe_wx_dmg_no },		// 22
{ B,	":inj_yes:",		&severe_wx_inj_yes,			w_severe_wx_inj_yes },		// 23
{ B,	":inj_no:",			&severe_wx_inj_no,			w_severe_wx_inj_no },		// 24
{ E,	"",					NULL,						NULL }
};

std::string buffsevere_wx;
std::string def_severe_wx_filename = "";
std::string base_severe_wx_filename = "";
std::string def_severe_wx_TemplateName = "";

bool using_severe_wx_template = false;
static bool fields_initialized = false;

// required to initialize the control pointers in the QUAD array

static void init_widgets()
{
	severe_wx_QUAD[0].widget  = w_severe_wx_date;
	severe_wx_QUAD[1].widget  = w_severe_wx_time;
	severe_wx_QUAD[2].widget  = w_severe_wx_zone;
	severe_wx_QUAD[3].widget  = w_severe_wx_state;
	severe_wx_QUAD[4].widget  = w_severe_wx_county;
	severe_wx_QUAD[5].widget  = w_severe_wx_city;
	severe_wx_QUAD[6].widget  = w_severe_wx_wind_speed;
	severe_wx_QUAD[7].widget  = w_severe_wx_narrative;
	severe_wx_QUAD[8].widget  = w_severe_wx_hail_size;
	severe_wx_QUAD[9].widget  = w_severe_wx_exact;
	severe_wx_QUAD[10].widget = w_severe_wx_not_exact;
	severe_wx_QUAD[11].widget = w_severe_wx_tornado;
	severe_wx_QUAD[12].widget = w_severe_wx_funnel_cloud;
	severe_wx_QUAD[13].widget = w_severe_wx_wall_cloud;
	severe_wx_QUAD[14].widget = w_severe_wx_hail;
	severe_wx_QUAD[15].widget = w_severe_wx_high_wind;
	severe_wx_QUAD[16].widget = w_severe_wx_measured;
	severe_wx_QUAD[17].widget = w_severe_wx_estimated;
	severe_wx_QUAD[18].widget = w_severe_wx_flood;
	severe_wx_QUAD[19].widget = w_severe_wx_flash_flood;
	severe_wx_QUAD[20].widget = w_severe_wx_other;
	severe_wx_QUAD[21].widget = w_severe_wx_dmg_yes;
	severe_wx_QUAD[22].widget = w_severe_wx_dmg_no;
	severe_wx_QUAD[23].widget = w_severe_wx_inj_yes;
	severe_wx_QUAD[24].widget = w_severe_wx_inj_no;

	fields_initialized = true;
}

//enum SWX_QTYPE { B, S, T, I, F, C, E }; 
// bool, std::string, text, int, float, character, empty

static void clearQUAD(SWX_QUAD *p)
{
	SWX_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B : (*(bool *)(p->ptr)) = false; break;
			case S :
			case D :
			case M : ((std::string *)(p->ptr))->clear(); break;
			case T : ((std::string *)(p->ptr))->clear(); break;
			case C : (*(char *)(p->ptr)) = ' '; break;
			case I : (*(int *)(p->ptr)) = 0; break;
			case F : (*(float *)(p->ptr)) = 0.0; break;
			case O : break;
			case E : return;
		}
		p++;
	}
}

void clear_severe_wxfields()
{
	if (!fields_initialized) init_widgets();
	clearQUAD(severe_wx_QUAD);
}

static bool checkQUAD(SWX_QUAD *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	SWX_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		if (p->widget == NULL) return false;
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) != ((Fl_Check_Button *)p->widget)->value())
					return true;
				break;
			case S:
			case M:
				if (*((std::string *)(p->ptr)) != ((Fl_Input2 *)p->widget)->value())
					return true;
				break;
			case D:
				if (*((std::string *)(p->ptr)) != ((Fl_DateInput *)p->widget)->value())
					return true;
				break;
			case T:
				if (*((std::string *)(p->ptr)) != ((FTextEdit *)p->widget)->buffer()->text())
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
				if (((Fl_ListBox *)p->widget)->index() == 0) break;
				if (*((std::string *)(p->ptr)) != ((Fl_ListBox *)p->widget)->value())
					return true;
				break;
			case E:
			default: return false;
		}
		p++;
	}
	return false;
}

bool check_severe_wxfields()
{
	return checkQUAD(severe_wx_QUAD);
}

static void updateQUAD(SWX_QUAD *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	SWX_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = ((Fl_Check_Button *)p->widget)->value();
				break;
			case S:
			case M:
				*((std::string *)(p->ptr)) = ((Fl_Input2 *)p->widget)->value();
				break;
			case D:
				*((std::string *)(p->ptr)) = ((Fl_DateInput *)p->widget)->value();
				break;
			case O:
				{	std::string s = ((Fl_ListBox *)p->widget)->value();
					if (s.find("--") == 0)
						((std::string *)(p->ptr))->clear();
					else
						*((std::string *)(p->ptr)) = ((Fl_ListBox *)p->widget)->value();
				}
				break;
			case T:
				*((std::string *)(p->ptr)) = ((FTextEdit *)p->widget)->buffer()->text();
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

void update_severe_wxfields()
{
	if (!fields_initialized) init_widgets();
	updateQUAD(severe_wx_QUAD);
	if (w_severe_wx_hail->value())
		w_severe_wx_hail_size->activate();
	else
		w_severe_wx_hail_size->deactivate();
}

void set_severe_wx_counties(int n) {
	if (n > (numstates - 1)) return;

	std::string st_letters = states[n].substr(0,3);
	size_t p1 = counties.find(st_letters);
	size_t p2 = counties.rfind(st_letters);
	if (p1 == std::string::npos || p2 == std::string::npos) {
		printf("not found\n");
		return;
	}
	std::string state_counties = counties.substr(p1 + 3, p2 - p1 - 3);
	size_t p4 = 0, p5 = 0;
	w_severe_wx_county->clear();
	while ((p5 = state_counties.find(',',p4)) != std::string::npos) {
		w_severe_wx_county->add(state_counties.substr(p4, p5-p4).c_str());
		p4 = p5 + 1;
	}
	w_severe_wx_county->index(0);
}

void set_severe_wx_combos() {
	w_severe_wx_state->clear();
	for (int n = 0; n < numstates; n++) {
		if (n == 0)
			w_severe_wx_state->add("State/Province");
		else
			w_severe_wx_state->add(states[n].c_str());
	}
	w_severe_wx_state->index(0);
	set_severe_wx_counties(0);

	w_severe_wx_hail_size->clear();
	for (int n = 0; n < num_hail_size; n++ )
		w_severe_wx_hail_size->add(hail_size[n].c_str());

	w_severe_wx_hail_size->index(0);
}

static void updateFORM(SWX_QUAD *p)
{
	char val[20];
	SWX_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				((Fl_Check_Button *)p->widget)->value(*((bool *)(p->ptr)));
				break;
			case S:
			case M:
				((Fl_Input2 *)p->widget)->value(((std::string *)(p->ptr))->c_str());
				break;
			case D:
				((Fl_DateInput *)p->widget)->value(((std::string *)(p->ptr))->c_str());
				break;
			case O:
				((Fl_ListBox *)p->widget)->put_value(((std::string *)(p->ptr))->c_str());
				break;
			case T:
				((FTextEdit *)p->widget)->clear();
				((FTextEdit *)p->widget)->add(((std::string *)(p->ptr))->c_str());
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

void update_severe_wxform()
{
	if (!fields_initialized) init_widgets();
	updateFORM(severe_wx_QUAD);
}

void clear_severe_wx_form()
{
	clear_severe_wxfields();
	update_severe_wxform();
// combo initializers
	w_severe_wx_state->index(0);
	set_severe_wx_counties(0);
	w_severe_wx_county->index(0);
	w_severe_wx_city->index(0);
	w_severe_wx_zone->index(0);
	w_severe_wx_hail_size->index(0);
// boolean initializers
	w_severe_wx_dmg_no->value(1);
	w_severe_wx_inj_no->value(1);
	w_severe_wx_estimated->value(1);
	w_severe_wx_not_exact->value(1);
}

static std::string mbuff;

static void make_buffQUAD(SWX_QUAD *p)
{
	std::string one = "1"; std::string zero = "0";
	std::string sval = " ";
	char szval[20];
	SWX_QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) == true)
					mbuff.append( lineout( p->html_fld, *((bool *)(p->ptr)) ? one : zero));
				break;
			case O: case S: case D: case M:
				if (((std::string *)(p->ptr))->length())
					mbuff.append( lineout( p->html_fld, *((std::string *)(p->ptr))));
				break;
			case T:
				mbuff.append( lineout( p->html_fld, *((std::string *)(p->ptr))));
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

void make_buff_severe_wx(bool compress = false)
{
	mbuff.clear();
	make_buffQUAD(severe_wx_QUAD);
	if (compress) compress_maybe(mbuff);
	buffsevere_wx.append(mbuff);
}

static void readQUAD(std::string data, SWX_QUAD *p)
{
	int i = 0;
	float f;
	SWX_QTYPE qt = p->qtype;
	while (qt != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = (findstr( data, p->html_fld ) == "1");
				break;
			case D: case O: case S: case M:
				*((std::string *)(p->ptr)) = findstr( data, p->html_fld );
				break;
			case T:
				*((std::string *)(p->ptr)) = findstr( data, p->html_fld );
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

void read_severe_wx_buffer(std::string data)
{
	clear_severe_wxfields();
	read_header(data);

	readQUAD (data, severe_wx_QUAD);
	update_severe_wxform();
	int idx = w_severe_wx_state->index();
	set_severe_wx_counties(idx);
	w_severe_wx_county->value( ((std::string *)(severe_wx_QUAD[4].ptr))->c_str() );
}

void cb_severe_wx_new()
{
	if (check_severe_wxfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_severe_wx_save();
		}
	}
	clear_severe_wx_form();
	clear_header();
	def_severe_wx_filename = ICS_msg_dir;
	def_severe_wx_filename.append("new").append(FSWX_EXT);
	show_filename(def_severe_wx_filename);
	using_severe_wx_template = false;
}

void cb_severe_wx_import()
{
	fl_alert2("Not implemented");
}

void cb_severe_wx_export()
{
	fl_alert2("Not implemented");
}

void cb_severe_wx_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_severe_wx_form();
	read_severe_wx_buffer(inpbuffer);
	def_severe_wx_filename = ICS_msg_dir;
	def_severe_wx_filename.append(wrapfilename);
	show_filename(def_severe_wx_filename);
	using_severe_wx_template = false;
}

int eval_severe_wx_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_severe_wx_filename).append("]");
	update_severe_wxfields();
	update_header(FROM);
	evalstr.append(header("<severe_wx>"));
	buffsevere_wx.clear();
	make_buff_severe_wx(true);
	if (buffsevere_wx.empty()) return 0;
	compress_maybe( buffsevere_wx );
	evalstr.append( buffsevere_wx );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_severe_wx_wrap_export()
{
	if (check_severe_wxfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_severe_wxfields();

	if (base_severe_wx_filename == std::string("new").append(FSWX_EXT) ||
		base_severe_wx_filename == std::string("default").append(FSWX_EXT) )
		if (!cb_severe_wx_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_severe_wx_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffsevere_wx.assign(header("<severe_wx>"));
		make_buff_severe_wx(true);
		export_wrapfile(base_severe_wx_filename, wrapfilename, buffsevere_wx, pext != ".wrap");

		buffsevere_wx.assign(header("<severe_wx>"));
		make_buff_severe_wx(false);
		write_severe_wx(def_severe_wx_filename);
	}
}

void cb_severe_wx_wrap_autosend()
{
	if (check_severe_wxfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_severe_wxfields();

	if (base_severe_wx_filename == std::string("new").append(FSWX_EXT) ||
		base_severe_wx_filename == std::string("default").append(FSWX_EXT) )
		if (!cb_severe_wx_save_as()) return;

	update_header(FROM);
	buffsevere_wx.assign(header("<severe_wx>"));
	make_buff_severe_wx(true);
	xfr_via_socket(base_severe_wx_filename, buffsevere_wx);

	buffsevere_wx.assign(header("<severe_wx>"));
	make_buff_severe_wx(false);
	write_severe_wx(def_severe_wx_filename);
}

void cb_severe_wx_load_template()
{
	std::string def_severe_wx_filename = def_severe_wx_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TSWX_EXT).c_str(),
			def_severe_wx_filename.c_str());
	if (p) {
		clear_severe_wx_form();
		read_data_file(p);
		def_severe_wx_TemplateName = p;
		show_filename(def_severe_wx_TemplateName);
		using_severe_wx_template = true;
	}
}

void cb_severe_wx_save_template()
{
	if (!using_severe_wx_template) {
		cb_severe_wx_save_as_template();
		return;
	}
	std::string def_severe_wx_filename = def_severe_wx_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TSWX_EXT).c_str(),
			def_severe_wx_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_severe_wxfields();
		buffsevere_wx.assign(header("<severe_wx>"));
		make_buff_severe_wx();
		write_severe_wx(p);
	}
}

void cb_severe_wx_save_as_template()
{
	std::string def_severe_wx_filename = def_severe_wx_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TSWX_EXT).c_str(),
			def_severe_wx_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_severe_wx_TemplateName = p;
		if (strlen(pext) == 0) def_severe_wx_TemplateName.append(TSWX_EXT);
		remove_spaces_from_filename(def_severe_wx_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_severe_wxfields();
		buffsevere_wx.assign(header("<severe_wx>"));
		make_buff_severe_wx();
		write_severe_wx(def_severe_wx_TemplateName);

		show_filename(def_severe_wx_TemplateName);
		using_severe_wx_template = true;
	}
}

void cb_severe_wx_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-severe_wx\t*").append(FSWX_EXT).c_str(),
			def_severe_wx_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_severe_wx_form();
	read_data_file(p);
	using_severe_wx_template = false;
	def_severe_wx_filename = p;
	show_filename(def_severe_wx_filename);
}

void write_severe_wx(std::string s)
{
	FILE *filesevere_wx = fopen(s.c_str(), "w");
	if (!filesevere_wx) return;

	fwrite(buffsevere_wx.c_str(), buffsevere_wx.length(), 1, filesevere_wx);
	fclose(filesevere_wx);
}


bool cb_severe_wx_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(FSWX_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_severe_wx_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-severe_wx\t*").append(FSWX_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_severe_wx_filename = p;
	if (strlen(pext) == 0) def_severe_wx_filename.append(FSWX_EXT);

	remove_spaces_from_filename(def_severe_wx_filename);

	update_header(NEW);
	update_severe_wxfields();
	buffsevere_wx.assign(header("<severe_wx>"));
	make_buff_severe_wx();
	write_severe_wx(def_severe_wx_filename);

	using_severe_wx_template = false;
	show_filename(def_severe_wx_filename);
	return true;
}

void cb_severe_wx_save()
{
	if (base_severe_wx_filename == std::string("new").append(FSWX_EXT) || 
		base_severe_wx_filename == std::string("default").append(FSWX_EXT) ||
		using_severe_wx_template == true) {
		cb_severe_wx_save_as();
		return;
	}

	if (check_severe_wxfields()) update_header(CHANGED);
	update_severe_wxfields();
	buffsevere_wx.assign(header("<severe_wx>"));
	make_buff_severe_wx();
	write_severe_wx(def_severe_wx_filename);

	using_severe_wx_template = false;
}

static void quad_to_html( std::string &target, SWX_QUAD *p)
{
	std::string X = "x"; std::string SP = "_";
	std::string sval = " ";
	std::string del = "";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B)
			replacestr(target, p->html_fld, *((bool *)(p->ptr)) ? X : SP);
		else if (p->qtype == S || p->qtype == O || p->qtype == D) {
			std::string s = *((std::string *)(p->ptr));
			if (p->html_fld == ":state:") {
				if (s.length() > 1) s.erase(2);
				replacestr(target, p->html_fld, s);
			} else if (p->html_fld == ":zone") {
				size_t cp = s.find(',');
				s.erase(cp);
				replacestr(target, p->html_fld, s);
			} else if (s.find("--") == 0) {
				replacestr(target, p->html_fld, del);
			} else {
				replacestr(target, p->html_fld, *((std::string *)(p->ptr)));
			}
		} else if (p->qtype == M) {
			sval = *((std::string *)(p->ptr));
			size_t np = std::string::npos;
			while ( (np = sval.find("\n")) != std::string::npos)
				sval.replace(np, 1, "<br>");
			replacestr(target, p->html_fld, sval);
		} else if (p->qtype == T)
			replacestr(target, p->html_fld, *((std::string *)(p->ptr)));
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

void cb_severe_wx_html()
{
	std::string name_name = fl_filename_name(def_severe_wx_filename.c_str());
	size_t p = name_name.rfind('.');
	if (p != std::string::npos) name_name.erase(p);

	std::string severe_wx_rptsta = ICS_dir;
	severe_wx_rptsta.append(name_name);
	severe_wx_rptsta.append(".html");

	update_severe_wxfields();
	std::string formsevere_wx = severe_wx_html_template;

	replacestr(formsevere_wx, TITLE, name_name);

	quad_to_html (formsevere_wx, severe_wx_QUAD);

	FILE *filesevere_wx = fopen(severe_wx_rptsta.c_str(), "w");
	fprintf(filesevere_wx,"%s", formsevere_wx.c_str());
	fclose(filesevere_wx);

	open_url(severe_wx_rptsta.c_str());
}

static void quad_to_text( std::string &target, SWX_QUAD *p)
{
	std::string X = "X"; std::string SP = " ";
	std::string sval = " ";
	std::string del = "";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B) {
			bool b = *((bool *)(p->ptr));
			if (b) replacestr(target, p->html_fld, X);
			else replacestr(target, p->html_fld, SP);
		} else if (p->qtype == S || p->qtype == M || 
					p->qtype == O || p->qtype == D) {
			std::string s = *((std::string *)(p->ptr));
			if (p->html_fld == ":state:") {
				if (s.length() > 1) s.erase(2);
				replacestr(target, p->html_fld, s);
			} else if (p->html_fld == ":zone") {
				size_t cp = s.find(',');
				s.erase(cp);
				replacestr(target, p->html_fld, s);
			} else if (s.find("--") == 0) {
				replacestr(target, p->html_fld, del);
			} else {
				if (((std::string *)(p->ptr))->length())
					replacestr(target, p->html_fld, *((std::string *)(p->ptr)));
				else replacestr(target, p->html_fld, del);
			}
		} else if (p->qtype == T) {
			if (((std::string *)(p->ptr))->length())
				replacestr(target, p->html_fld, *((std::string *)(p->ptr)));
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

void cb_severe_wx_textout()
{
	std::string severe_wx_rptsta = ICS_dir;
	severe_wx_rptsta.append("severe_wx.txt");

	update_severe_wxfields();
	std::string formsevere_wx = severe_wx_text_template;

	quad_to_text (formsevere_wx, severe_wx_QUAD);

	FILE *filesevere_wx = fopen(severe_wx_rptsta.c_str(), "w");
	fprintf(filesevere_wx,"%s", formsevere_wx.c_str());
	fclose(filesevere_wx);

	open_url(severe_wx_rptsta.c_str());
}

