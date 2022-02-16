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
// ics 216 field variables and template variables
// ---------------------------------------------------------------------

std::string ics216_incident					= ":inc:";
std::string ics216_date						= ":dat:";
std::string ics216_time						= ":tim:";
std::string ics216_branch					= ":br:";
std::string ics216_agc						= ":agc:";
std::string ics216_op_period					= ":opp:";
std::string ics216_tac_freq					= ":tfr:";

std::string ics216_div_grp					= ":div[n]:";
std::string ics216_agency					= ":agy[n]:";

std::string ics216_ag						= ":ag[n]:";
std::string ics216_id						= ":id[n]:";
std::string ics216_rr						= ":rr[n]:";

std::string ics216_prepared_by				= ":pre:";

std::string s216_incident;
std::string s216_date;
std::string s216_time;
std::string s216_branch;
std::string s216_agc;
std::string s216_op_period;
std::string s216_tac_freq;

std::string s216_div_grp[4];
std::string s216_agency[4];
std::string s216_ag[36];
std::string s216_id[36];
std::string s216_rr[36];

std::string s216_prepared_by;

// =====================================================================

std::string buff216;
std::string def_216_filename = "";
std::string base_216_filename = "";
std::string def_216_TemplateName = "";
bool using_ics216_template = false;

void cb_216_set_date()
{
	txt_216_date->value(szDate(progStatus.dtformat));
}

void cb_216_set_time()
{
	txt_216_time->value(szTime(progStatus.UTC));
}

void clear_216fields()
{
	s216_incident.clear();
	s216_date.clear();
	s216_time.clear();
	s216_branch.clear();
	s216_agc.clear();
	s216_op_period.clear();
	s216_tac_freq.clear();
	s216_prepared_by.clear();

	for (int i = 0; i < 4; i++) {
		s216_div_grp[i].clear();
		s216_agency[i].clear();
	}
	for (int i = 0; i < 36; i++) {
		s216_ag[i].clear();
		s216_id[i].clear();
		s216_rr[i].clear();
	}
}

bool check_216fields()
{
	if (s216_incident != txt_216_incident->value())
		return true;
	if (s216_date != txt_216_date->value())
		return true;
	if (s216_time != txt_216_time->value())
		return true;
	if (s216_branch != txt_216_branch->value())
		return true;
	if (s216_agc != txt_216_agc->value())
		return true;
	if (s216_op_period != txt_216_op_period->value())
		return true;
	if (s216_tac_freq != txt_216_tac_freq->value())
		return true;
	if (s216_prepared_by != txt_216_prepared_by->value())
		return true;

	for (int i = 0; i < 4; i++) {
		if (s216_div_grp[i] != txt_216_div_grp[i]->value())
			return true;
		if (s216_agency[i] != txt_216_agency[i]->value())
			return true;
	}

	for (int i = 0; i < 36; i++) {
		if (s216_ag[i] != txt_216_ag[i]->value())
			return true;
		if (s216_id[i] != txt_216_id[i]->value())
			return true;
		if (s216_rr[i] != txt_216_rr[i]->value())
			return true;
	}
	return false;
}

void update_216fields()
{
	s216_incident = txt_216_incident->value();
	s216_date = txt_216_date->value();
	s216_time = txt_216_time->value();
	s216_branch = txt_216_branch->value();
	s216_agc = txt_216_agc->value();
	s216_op_period = txt_216_op_period->value();
	s216_tac_freq = txt_216_tac_freq->value();
	s216_prepared_by = txt_216_prepared_by->value();

	for (int i = 0; i < 4; i++) {
		s216_div_grp[i] = txt_216_div_grp[i]->value();
		s216_agency[i] = txt_216_agency[i]->value();
	}

	for (int i = 0; i < 36; i++) {
		s216_ag[i] = txt_216_ag[i]->value();
		s216_id[i] = txt_216_id[i]->value();
		s216_rr[i] = txt_216_rr[i]->value();
	}
}

void update_216form()
{
	txt_216_incident->value(s216_incident.c_str());
	txt_216_date->value(s216_date.c_str());
	txt_216_time->value(s216_time.c_str());
	txt_216_branch->value(s216_branch.c_str());
	txt_216_agc->value(s216_agc.c_str());
	txt_216_op_period->value(s216_op_period.c_str());
	txt_216_tac_freq->value(s216_tac_freq.c_str());
	txt_216_prepared_by->value(s216_prepared_by.c_str());

	for (int i = 0; i < 4; i++) {
		txt_216_div_grp[i]->value(s216_div_grp[i].c_str());
		txt_216_agency[i]->value(s216_agency[i].c_str());
	}
	for (int i = 0; i < 36; i++) {
		txt_216_ag[i]->value(s216_ag[i].c_str());
		txt_216_id[i]->value(s216_id[i].c_str());
		txt_216_rr[i]->value(s216_rr[i].c_str());
	}
}

void clear_216_form()
{
	clear_216fields();
	update_216form();
}

std::string &ics_216_nn(std::string & subst, int n)
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
		if (n < 20)
			ics[pos] = '1';
		else if ( n < 30)
			ics[pos] = '2';
		else if (n < 40)
			ics[pos] = '3';
		ics[pos+1] = '0' + n % 10;
		ics[pos+2] = ']';
		ics += ':';
	}
	return ics;
}

void make_buff216(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( ics216_incident, s216_incident ) );
	mbuff.append( lineout( ics216_date, s216_date ) );
	mbuff.append( lineout( ics216_time, s216_time ) );
	mbuff.append( lineout( ics216_branch, s216_branch ) );
	mbuff.append( lineout( ics216_agc, s216_agc ) );
	mbuff.append( lineout( ics216_op_period, s216_op_period ) );
	mbuff.append( lineout( ics216_tac_freq, s216_tac_freq ) );
	mbuff.append( lineout( ics216_prepared_by, s216_prepared_by ) );

	for (int i = 0; i < 4; i++) {
		mbuff.append( lineout( ics_216_nn( ics216_div_grp, i), s216_div_grp[i] ) );
		mbuff.append( lineout( ics_216_nn( ics216_agency, i), s216_agency[i] ) );
	}
	for (int i = 0; i < 36; i++) {
		mbuff.append( lineout( ics_216_nn( ics216_ag, i), s216_ag[i] ) );
		mbuff.append( lineout( ics_216_nn( ics216_id, i), s216_id[i] ) );
		mbuff.append( lineout( ics_216_nn( ics216_rr, i), s216_rr[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	buff216.append(mbuff);
}

void read_216_buffer(std::string data)
{
	clear_216fields();
	read_header(data);

	s216_incident = findstr( data, ics216_incident );
	s216_date = findstr( data, ics216_date );
	s216_time = findstr( data, ics216_time );
	s216_branch = findstr( data, ics216_branch );
	s216_agc = findstr( data, ics216_agc );
	s216_op_period = findstr( data, ics216_op_period );
	s216_tac_freq = findstr( data, ics216_tac_freq );
	s216_prepared_by = findstr( data, ics216_prepared_by );

	for (int i = 0; i < 4; i++) {
		s216_div_grp[i] = findstr( data, ics_216_nn( ics216_div_grp, i ) );
		s216_agency[i] = findstr( data, ics_216_nn( ics216_agency, i ) );
	}
	for (int i = 0; i < 36; i++) {
		s216_ag[i] = findstr( data, ics_216_nn( ics216_ag, i ) );
		s216_id[i] = findstr( data, ics_216_nn( ics216_id, i ) );
		s216_rr[i] = findstr( data, ics_216_nn( ics216_rr, i ) );
	}

	update_216form();
}

void cb_216_new()
{
	if (check_216fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_216_save();
		}
	}
	clear_216_form();
	clear_header();
	def_216_filename = ICS_msg_dir;
	def_216_filename.append("new").append(F216_EXT);
	show_filename(def_216_filename);
	using_ics216_template = false;
}

void cb_216_import()
{
	fl_alert2("Not implemented");
}

void cb_216_export()
{
	fl_alert2("Not implemented");
}

void cb_216_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_216_form();
	read_216_buffer(inpbuffer);
	def_216_filename = ICS_msg_dir;
	def_216_filename.append(wrapfilename);
	show_filename(def_216_filename);
	using_ics216_template = false;
}

int eval_216_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_216_filename).append("]");
	update_216fields();
	update_header(FROM);
	evalstr.append(header("<ics216>"));
	buff216.clear();
	make_buff216(true);
	if (buff216.empty()) return 0;
	compress_maybe( buff216 );
	evalstr.append( buff216 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_216_wrap_export()
{
	if (check_216fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_216fields();

	if (base_216_filename == std::string("new").append(F216_EXT) ||
		base_216_filename == std::string("default").append(F216_EXT) )
		if (!cb_216_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_216_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff216.assign(header("<ics216>"));
		make_buff216(true);
		export_wrapfile(base_216_filename, wrapfilename, buff216, pext != ".wrap");

		buff216.assign(header("<ics216>"));
		make_buff216(false);
		write_216(def_216_filename);
	}
}

void cb_216_wrap_autosend()
{
	if (check_216fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_216fields();

	if (base_216_filename == std::string("new").append(F216_EXT) ||
		base_216_filename == std::string("default").append(F216_EXT) )
		if (!cb_216_save_as()) return;

	update_header(FROM);
	buff216.assign(header("<ics216>"));
	make_buff216(true);
	xfr_via_socket(base_216_filename, buff216);

	buff216.assign(header("<ics216>"));
	make_buff216(false);
	write_216(def_216_filename);
}

void cb_216_load_template()
{
	std::string def_216_filename = def_216_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(T216_EXT).c_str(),
			def_216_filename.c_str());
	if (p) {
		clear_216_form();
		read_data_file(p);
		def_216_TemplateName = p;
		show_filename(def_216_TemplateName);
		using_ics216_template = true;
	}
}

void cb_216_save_template()
{
	if (!using_ics216_template) {
		cb_216_save_as_template();
		return;
	}
	std::string def_216_filename = def_216_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(T216_EXT).c_str(),
			def_216_filename.c_str());
	if (p) {
		update_header(CHANGED);
		buff216.assign(header("<ics216>"));
		make_buff216();
		write_216(p);
	}
}

void cb_216_save_as_template()
{
	std::string def_216_filename = def_216_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(T216_EXT).c_str(),
			def_216_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_216_TemplateName = p;
		if (strlen(pext) == 0) def_216_TemplateName.append(T216_EXT);
		remove_spaces_from_filename(def_216_TemplateName);
		clear_header();
		update_header(CHANGED);
		buff216.assign(header("<ics216>"));
		make_buff216();
		write_216(def_216_TemplateName);
		show_filename(def_216_TemplateName);
		using_ics216_template = true;
	}
}

void cb_216_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-216\t*").append(F216_EXT).c_str(),
			def_216_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_216_form();
	read_data_file(p);
	using_ics216_template = false;
	def_216_filename = p;
	show_filename(def_216_filename);
}

void write_216(std::string s)
{
	FILE *file216 = fopen(s.c_str(), "w");
	if (!file216) return;

	fwrite(buff216.c_str(), buff216.length(), 1, file216);
	fclose(file216);
}

bool cb_216_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(F216_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_216_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-216\t*").append(F216_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_216_filename = p;
	if (strlen(pext) == 0) def_216_filename.append(F216_EXT);

	remove_spaces_from_filename(def_216_filename);
	update_216fields();
	update_header(NEW);
	buff216.assign(header("<ics216>"));
	make_buff216();
	write_216(def_216_filename);

	using_ics216_template = false;
	show_filename(def_216_filename);
	return true;
}

void cb_216_save()
{
	if (base_216_filename == std::string("new").append(F216_EXT) || 
		base_216_filename == std::string("default").append(F216_EXT) ||
		using_ics216_template == true) {
		cb_216_save_as();
		return;
	}
	if (check_216fields()) update_header(CHANGED);
	update_216fields();
	buff216.assign(header("<ics216>"));
	make_buff216();
	write_216(def_216_filename);
	using_ics216_template = false;
}

void cb_216_html()
{
	std::string fname_name = fl_filename_name(def_216_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string ics216_fname = ICS_dir;
	ics216_fname.append(fname_name);
	ics216_fname.append(".html");

	std::string html_text = "";

	update_216fields();
	std::string form216 = ics216_html_template;

	replacestr(form216, TITLE, fname_name);
	replacestr(form216, ics216_incident, s216_incident );
	replacestr(form216, ics216_date, s216_date );
	replacestr(form216, ics216_time, s216_time );
	replacestr(form216, ics216_branch, s216_branch );
	replacestr(form216, ics216_agc, s216_agc );
	replacestr(form216, ics216_op_period, s216_op_period );
	replacestr(form216, ics216_tac_freq, s216_tac_freq );
	replacestr(form216, ics216_prepared_by, s216_prepared_by );

	for (int i = 0; i < 4; i++) {
		replacestr(form216, ics_216_nn( ics216_div_grp, i), s216_div_grp[i] );
		replacestr(form216, ics_216_nn( ics216_agency, i), s216_agency[i] );
	}
	for (int i = 0; i < 36; i++) {
		replacestr(form216, ics_216_nn( ics216_ag, i), s216_ag[i] );
		replacestr(form216, ics_216_nn( ics216_id, i), s216_id[i] );
		replacestr(form216, ics_216_nn( ics216_rr, i), s216_rr[i] );
	}

	FILE *file216 = fopen(ics216_fname.c_str(), "w");
	fprintf(file216,"%s", form216.c_str());
	fclose(file216);

	open_url(ics216_fname.c_str());
}

void cb_216_msg_type()
{
	if (tabs_msg_type->value() == tab_ics216 ) {
		tab_ics216_type->value(tab_216_1);
		show_filename(def_216_filename);
	}
}

void cb_216_textout()
{
	std::string ics216_fname = ICS_dir;
	ics216_fname.append("ics216.txt");

	update_216fields();
	std::string form216 = ics216_text_template;

	replacestr(form216, ics216_incident, s216_incident );
	replacestr(form216, ics216_date, s216_date );
	replacestr(form216, ics216_time, s216_time );
	replacestr(form216, ics216_branch, s216_branch );
	replacestr(form216, ics216_agc, s216_agc );
	replacestr(form216, ics216_op_period, s216_op_period );
	replacestr(form216, ics216_tac_freq, s216_tac_freq );
	replacestr(form216, ics216_prepared_by, s216_prepared_by );

	for (int i = 0; i < 4; i++) {
		replacestr(form216, ics_216_nn( ics216_div_grp, i), s216_div_grp[i] );
		replacestr(form216, ics_216_nn( ics216_agency, i), s216_agency[i] );
	}
	for (int i = 0; i < 36; i++) {
		replacestr(form216, ics_216_nn( ics216_ag, i), s216_ag[i] );
		replacestr(form216, ics_216_nn( ics216_id, i), s216_id[i] );
		replacestr(form216, ics_216_nn( ics216_rr, i), s216_rr[i] );
	}

	FILE *file216 = fopen(ics216_fname.c_str(), "w");
	fprintf(file216,"%s", form216.c_str());
	fclose(file216);

	open_url(ics216_fname.c_str());
}
