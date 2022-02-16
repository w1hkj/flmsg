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

// ---------------------------------------------------------------------
// ics 214 field variables and template variables
// ---------------------------------------------------------------------

std::string ics214_incident					= ":inc:";
std::string ics214_date						= ":dat:";
std::string ics214_time						= ":tim:";
std::string ics214_op_period					= ":opp:";
std::string ics214_unit_name					= ":und:";
std::string ics214_unit_leader				= ":unl:";

std::string ics214_roster_name				= ":nam[n]:"; // 14
std::string ics214_roster_position			= ":pos[n]:";
std::string ics214_roster_home_base			= ":hom[n]:";

std::string ics214_activity_time				= ":at[n]:"; // 16
std::string ics214_activity_event			= ":ev[n]:";

std::string ics214_prepared_by				= ":pre:";

std::string s214_incident;
std::string s214_date;
std::string s214_time;
std::string s214_op_period;
std::string s214_unit_name;
std::string s214_unit_leader;

std::string s214_roster_name[16];
std::string s214_roster_position[16];
std::string s214_roster_home_base[16];
std::string s214_activity_time[16];
std::string s214_activity_event[16];

std::string s214_prepared_by;

// =====================================================================

std::string buff214;
std::string def_214_filename = "";
std::string base_214_filename = "";
std::string def_214_TemplateName = "";

bool using_ics214_template = false;

void cb_214_set_date()
{
	txt_214_date->value(szDate(progStatus.dtformat));
}

void cb_214_set_time()
{
	txt_214_time->value(szTime(progStatus.UTC));
}

void clear_214fields()
{
	s214_incident.clear();
	s214_date.clear();
	s214_time.clear();
	s214_op_period.clear();
	s214_unit_name.clear();
	s214_unit_leader.clear();
	s214_prepared_by.clear();

	for (int i = 0; i < 16; i++) {
		s214_roster_name[i].clear();
		s214_roster_position[i].clear();
		s214_roster_home_base[i].clear();
		s214_activity_time[i].clear();
		s214_activity_event[i].clear();
	}
}

bool check_214fields()
{
	if (s214_incident != txt_214_incident->value())
		return true;
	if (s214_date != txt_214_date->value())
		return true;
	if (s214_time != txt_214_time->value())
		return true;
	if (s214_op_period != txt_214_op_period->value())
		return true;
	if (s214_unit_name != txt_214_unit_name->value())
		return true;
	if (s214_unit_leader != txt_214_unit_leader->value())
		return true;
	if (s214_prepared_by != txt_214_prepared_by->value())
		return true;

	for (int i = 0; i < 16; i++) {
		if (s214_roster_name[i] != txt_214_roster_name[i]->value())
			return true;
		if (s214_roster_position[i] != txt_214_roster_position[i]->value())
			return true;
		if (s214_roster_home_base[i] != txt_214_roster_home_base[i]->value())
			return true;
		if (s214_activity_time[i] != txt_214_activity_time[i]->value())
			return true;
		if (s214_activity_event[i] != txt_214_activity_event[i]->value())
			return true;
	}
	return false;
}

void update_214fields()
{
	s214_incident = txt_214_incident->value();
	s214_date = txt_214_date->value();
	s214_time = txt_214_time->value();
	s214_op_period = txt_214_op_period->value();
	s214_unit_name = txt_214_unit_name->value();
	s214_unit_leader = txt_214_unit_leader->value();
	s214_prepared_by = txt_214_prepared_by->value();

	for (int i = 0; i < 16; i++) {
		s214_roster_name[i] = txt_214_roster_name[i]->value();
		s214_roster_position[i] = txt_214_roster_position[i]->value();
		s214_roster_home_base[i] = txt_214_roster_home_base[i]->value();
		s214_activity_time[i] = txt_214_activity_time[i]->value();
		s214_activity_event[i] = txt_214_activity_event[i]->value();
	}
}

void update_214form()
{
	txt_214_incident->value(s214_incident.c_str());
	txt_214_date->value(s214_date.c_str());
	txt_214_time->value(s214_time.c_str());
	txt_214_op_period->value(s214_op_period.c_str());
	txt_214_unit_name->value(s214_unit_name.c_str());
	txt_214_unit_leader->value(s214_unit_leader.c_str());
	txt_214_prepared_by->value(s214_prepared_by.c_str());

	for (int i = 0; i < 16; i++) {
		txt_214_roster_name[i]->value(s214_roster_name[i].c_str());
		txt_214_roster_position[i]->value(s214_roster_position[i].c_str());
		txt_214_roster_home_base[i]->value(s214_roster_home_base[i].c_str());
		txt_214_activity_time[i]->value(s214_activity_time[i].c_str());
		txt_214_activity_event[i]->value(s214_activity_event[i].c_str());
	}
}

void clear_214_form()
{
	clear_214fields();
	update_214form();
}

std::string &ics_nn(std::string & subst, int n)
{
	static std::string garbage = "#$^*!";
	static std::string ics;
	ics.clear();
	ics = subst;
	size_t pos = ics.find("[");
	if (pos == std::string::npos) return garbage;
	pos++;
	if (n < 10)
		ics[pos] = '0' + n;
	else {
		ics[pos] = '1';
		ics[pos+1] = '0' + n % 10;
		ics[pos+2] = ']';
		ics += ':';
	}
	return ics;
}

void make_buff214(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( ics214_incident, s214_incident ) );
	mbuff.append( lineout( ics214_date, s214_date ) );
	mbuff.append( lineout( ics214_time, s214_time ) );
	mbuff.append( lineout( ics214_op_period, s214_op_period ) );
	mbuff.append( lineout( ics214_unit_name, s214_unit_name) );
	mbuff.append( lineout( ics214_unit_leader, s214_unit_leader) );

	mbuff.append( lineout( ics214_prepared_by, s214_prepared_by ) );

	for (int i = 0; i < 16; i++) {
		mbuff.append( lineout( ics_nn( ics214_roster_name, i ), s214_roster_name[i] ) );
		mbuff.append( lineout( ics_nn( ics214_roster_position, i ), s214_roster_position[i] ) );
		mbuff.append( lineout( ics_nn( ics214_roster_home_base, i ), s214_roster_home_base[i] ) );
		mbuff.append( lineout( ics_nn( ics214_activity_time, i ), s214_activity_time[i] ) );
		mbuff.append( lineout( ics_nn( ics214_activity_event, i ), s214_activity_event[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	buff214.append(mbuff);
}

void read_214_buffer(std::string data)
{
	clear_214fields();
	read_header(data);

	s214_incident = findstr(data, ics214_incident);
	s214_date = findstr(data, ics214_date);
	s214_time = findstr(data, ics214_time);
	s214_op_period = findstr(data, ics214_op_period);
	s214_unit_name = findstr(data, ics214_unit_name);
	s214_unit_leader = findstr(data, ics214_unit_leader);
	s214_prepared_by = findstr(data, ics214_prepared_by);

	for (int i = 0; i < 16; i++) {
		s214_roster_name[i]      = findstr(data, ics_nn( ics214_roster_name, i ) );
		s214_roster_position[i]  = findstr(data, ics_nn( ics214_roster_position, i ) );
		s214_roster_home_base[i] = findstr(data, ics_nn( ics214_roster_home_base, i ) );
		s214_activity_time[i]    = findstr(data, ics_nn( ics214_activity_time, i ) );
		s214_activity_event[i]   = findstr(data, ics_nn( ics214_activity_event, i ) );
	}

	update_214form();
}

void cb_214_new()
{
	if (check_214fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_214_save();
		}
	}
	clear_214_form();
	clear_header();
	def_214_filename = ICS_msg_dir;
	def_214_filename.append("new").append(F214_EXT);
	show_filename(def_214_filename);
	using_ics214_template = false;
}

void cb_214_import()
{
	fl_alert2("Not implemented");
}

void cb_214_export()
{
	fl_alert2("Not implemented");
}

void cb_214_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_214_form();
	read_214_buffer(inpbuffer);
	def_214_filename = ICS_msg_dir;
	def_214_filename.append(wrapfilename);
	show_filename(def_214_filename);
	using_ics214_template = false;
}

int eval_214_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_214_filename).append("]");
	update_214fields();
	update_header(FROM);
	evalstr.append(header("<ics214>"));
	buff214.clear();
	make_buff214(true);
	if (buff214.empty()) return 0;
	compress_maybe( buff214 );
	evalstr.append( buff214 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_214_wrap_export()
{
	if (check_214fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_214fields();

	if (base_214_filename == std::string("new").append(F214_EXT) ||
		base_214_filename == std::string("default").append(F214_EXT) )
		if (!cb_214_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_214_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff214.assign(header("<ics214>"));
		make_buff214(true);
		export_wrapfile(base_214_filename, wrapfilename, buff214, pext != ".wrap");

		buff214.assign(header("<ics214>"));
		make_buff214(false);
		write_214(def_214_filename);
	}
}

void cb_214_wrap_autosend()
{
	if (check_214fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_214fields();

	if (base_214_filename == std::string("new").append(F214_EXT) ||
		base_214_filename == std::string("default").append(F214_EXT) )
		if (!cb_214_save_as()) return;

	update_header(FROM);
	buff214.assign(header("<ics214>"));
	make_buff214(true);
	xfr_via_socket(base_214_filename, buff214);

	buff214.assign(header("<ics214>"));
	make_buff214(false);
	write_214(def_214_filename);
}

void cb_214_load_template()
{
	std::string def_214_filename = def_214_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(T214_EXT).c_str(),
			def_214_filename.c_str());
	if (p) {
		clear_214_form();
		read_data_file(p);
		def_214_TemplateName = p;
		show_filename(def_214_TemplateName);
		using_ics214_template = true;
	}
}

void cb_214_save_template()
{
	if (!using_ics214_template) {
		cb_214_save_as_template();
		return;
	}
	std::string def_214_filename = def_214_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(T214_EXT).c_str(),
			def_214_filename.c_str());
	if (p) {
		update_header(CHANGED);
		buff214.assign(header("<ics214>"));
		make_buff214();
		write_214(p);
	}
}

void cb_214_save_as_template()
{
	std::string def_214_filename = def_214_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(T214_EXT).c_str(),
			def_214_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_214_TemplateName = p;
		if (strlen(pext) == 0) def_214_TemplateName.append(T214_EXT);
		remove_spaces_from_filename(def_214_TemplateName);
		clear_header();
		update_header(CHANGED);
		buff214.assign(header("<ics214>"));
		make_buff214();
		write_214(def_214_TemplateName);
		show_filename(def_214_TemplateName);
		using_ics214_template = true;
	}
}

void cb_214_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-214\t*").append(F214_EXT).c_str(),
			def_214_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_214_form();
	read_data_file(p);
	using_ics214_template = false;
	def_214_filename = p;
	show_filename(def_214_filename);
}

void write_214(std::string s)
{
	FILE *file214 = fopen(s.c_str(), "w");
	if (!file214) return;

	fwrite(buff214.c_str(), buff214.length(), 1, file214);
	fclose(file214);
}

bool cb_214_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(F214_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_214_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-214\t*").append(F214_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_214_filename = p;
	if (strlen(pext) == 0) def_214_filename.append(F214_EXT);

	remove_spaces_from_filename(def_214_filename);
	update_214fields();
	update_header(NEW);
	buff214.assign(header("<ics214>"));
	make_buff214();
	write_214(def_214_filename);

	using_ics214_template = false;
	show_filename(def_214_filename);
	return true;
}

void cb_214_save()
{
	if (base_214_filename == std::string("new").append(F214_EXT) || 
		base_214_filename == std::string("default").append(F214_EXT) ||
		using_ics214_template == true) {
		cb_214_save_as();
		return;
	}
	if (check_214fields()) update_header(CHANGED);
	update_214fields();
	buff214.assign(header("<ics214>"));
	make_buff214();
	write_214(def_214_filename);
	using_ics214_template = false;
}

void cb_214_html()
{
	std::string fname_name = fl_filename_name(def_214_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string ics214_fname = ICS_dir;
	ics214_fname.append(fname_name);
	ics214_fname.append(".html");

	std::string html_text = "";

	update_214fields();
	std::string form214 = ics214_html_template;

	replacestr(form214, TITLE, fname_name);
	replacestr(form214, ics214_incident, s214_incident );
	replacestr(form214, ics214_date, s214_date );
	replacestr(form214, ics214_time, s214_time );
	replacestr(form214, ics214_op_period, s214_op_period );
	replacestr(form214, ics214_unit_name, s214_unit_name );
	replacestr(form214, ics214_unit_leader, s214_unit_leader );
	replacestr(form214, ics214_prepared_by, s214_prepared_by );

	for (int i = 0; i < 16; i++) {
		replacestr(form214, ics_nn( ics214_roster_name, i ), s214_roster_name[i] );
		replacestr(form214, ics_nn( ics214_roster_position, i ), s214_roster_position[i] );
		replacestr(form214, ics_nn( ics214_roster_home_base, i ), s214_roster_home_base[i] );
		replacestr(form214, ics_nn( ics214_activity_time, i ), s214_activity_time[i] );
		replacestr(form214, ics_nn( ics214_activity_event, i ), s214_activity_event[i] );
	}

	FILE *file214 = fopen(ics214_fname.c_str(), "w");
	fprintf(file214,"%s", form214.c_str());
	fclose(file214);

	open_url(ics214_fname.c_str());
}

void cb_214_msg_type()
{
	if (tabs_msg_type->value() == tab_ics214 ) {
		tab_ics214_type->value(tab_214_1);
		show_filename(def_214_filename);
	}
}

void cb_214_textout()
{
	std::string ics214_fname = ICS_dir;
	ics214_fname.append("ics214.txt");

	update_214fields();
	std::string form214 = ics214_text_template;

	replacestr(form214, ics214_incident, s214_incident );
	replacestr(form214, ics214_date, s214_date );
	replacestr(form214, ics214_time, s214_time );
	replacestr(form214, ics214_op_period, s214_op_period );
	replacestr(form214, ics214_unit_name, s214_unit_name );
	replacestr(form214, ics214_unit_leader, s214_unit_leader );
	replacestr(form214, ics214_prepared_by, s214_prepared_by );

	for (int i = 0; i < 16; i++) {
		replacestr(form214, ics_nn( ics214_roster_name, i ), s214_roster_name[i] );
		replacestr(form214, ics_nn( ics214_roster_position, i ), s214_roster_position[i] );
		replacestr(form214, ics_nn( ics214_roster_home_base, i ), s214_roster_home_base[i] );
		replacestr(form214, ics_nn( ics214_activity_time, i ), s214_activity_time[i] );
		replacestr(form214, ics_nn( ics214_activity_event, i ), s214_activity_event[i] );
	}

	FILE *file214 = fopen(ics214_fname.c_str(), "w");
	fprintf(file214,"%s", form214.c_str());
	fclose(file214);

	open_url(ics214_fname.c_str());
}
