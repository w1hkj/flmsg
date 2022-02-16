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
// ics 205a field variables and template variables
// ---------------------------------------------------------------------

std::string ics205a_incident					= ":inc:";
std::string ics205a_date_fm					= ":dfm:";
std::string ics205a_time_fm					= ":tfm:";
std::string ics205a_date_to					= ":dto:";
std::string ics205a_time_to					= ":tto:";
std::string ics205a_prepared_by				= ":pre:";
std::string ics205a_preparer_position		= ":pos:";
std::string ics205a_preparer_date_time		= ":dtm:";

std::string ics205a_comm_position			= ":asg[n]:"; // 32
std::string ics205a_comm_name				= ":nam[n]:"; // 32
std::string ics205a_comm_info				= ":inf[n]:"; // 32

std::string s205a_incident;
std::string s205a_date_fm;
std::string s205a_time_fm;
std::string s205a_date_to;
std::string s205a_time_to;
std::string s205a_prepared_by;
std::string s205a_preparer_position;
std::string s205a_preparer_date_time;

std::string s205a_comm_position[32];
std::string s205a_comm_name[32];
std::string s205a_comm_info[32];

// =====================================================================

std::string buff205a;
std::string def_205a_filename = "";
std::string base_205a_filename = "";
std::string def_205a_TemplateName = "";
bool using_ics205a_template = false;

void cb_205a_set_date_fm()
{
	txt_205a_date_fm->value(szDate(progStatus.dtformat));
}

void cb_205a_set_time_fm()
{
	txt_205a_time_fm->value(szTime(progStatus.UTC));
}

void cb_205a_set_date_to()
{
	txt_205a_date_to->value(szDate(progStatus.dtformat));
}

void cb_205a_set_time_to()
{
	txt_205a_time_to->value(szTime(progStatus.UTC));
}

void clear_205afields()
{
	s205a_incident.clear();
	s205a_date_fm.clear();
	s205a_time_fm.clear();
	s205a_date_to.clear();
	s205a_time_to.clear();
	s205a_prepared_by.clear();
	s205a_preparer_position.clear();
	s205a_preparer_date_time.clear();

	for (int i = 0; i < 32; i++) {
		s205a_comm_position[i].clear();
		s205a_comm_name[i].clear();
		s205a_comm_info[i].clear();
	}
}

bool check_205afields()
{
	if (s205a_incident != txt_205a_incident->value())
		return true;
	if (s205a_date_fm != txt_205a_date_fm->value())
		return true;
	if (s205a_time_fm != txt_205a_time_fm->value())
		return true;
	if (s205a_date_to != txt_205a_date_to->value())
		return true;
	if (s205a_time_to != txt_205a_time_to->value())
		return true;
	if (s205a_prepared_by != txt_205a_prepared_by->value())
		return true;
	if (s205a_preparer_position != txt_205a_preparer_position->value())
		return true;
	if (s205a_preparer_date_time != txt_205a_preparer_date_time->value())
		return true;
	for (int i = 0; i < 32; i++) {
		if (s205a_comm_position[i] != txt_205a_comm_position[i]->value())
			return true;
		if (s205a_comm_name[i] != txt_205a_comm_name[i]->value())
			return true;
		if (s205a_comm_info[i] != txt_205a_comm_info[i]->value())
			return true;
	}
	return false;
}

void update_205afields()
{
	s205a_incident = txt_205a_incident->value();
	s205a_date_fm = txt_205a_date_fm->value();
	s205a_time_fm = txt_205a_time_fm->value();
	s205a_date_to = txt_205a_date_to->value();
	s205a_time_to = txt_205a_time_to->value();
	s205a_prepared_by = txt_205a_prepared_by->value();
	s205a_preparer_position = txt_205a_preparer_position->value();
	s205a_preparer_date_time = txt_205a_preparer_date_time->value();
	for (int i = 0; i < 32; i++) {
		s205a_comm_position[i] = txt_205a_comm_position[i]->value();
		s205a_comm_name[i] = txt_205a_comm_name[i]->value();
		s205a_comm_info[i] = txt_205a_comm_info[i]->value();
	}
}

void update_205aform()
{
	txt_205a_incident->value(s205a_incident.c_str());
	txt_205a_date_fm->value(s205a_date_fm.c_str());
	txt_205a_time_fm->value(s205a_time_fm.c_str());
	txt_205a_date_to->value(s205a_date_to.c_str());
	txt_205a_time_to->value(s205a_time_to.c_str());
	txt_205a_prepared_by->value(s205a_prepared_by.c_str());
	txt_205a_preparer_position->value(s205a_preparer_position.c_str());
	txt_205a_preparer_date_time->value(s205a_preparer_date_time.c_str());

	for (int i = 0; i < 32; i++) {
		txt_205a_comm_position[i]->value(s205a_comm_position[i].c_str());
		txt_205a_comm_name[i]->value(s205a_comm_name[i].c_str());
		txt_205a_comm_info[i]->value(s205a_comm_info[i].c_str());
	}
}

void clear_205a_form()
{
	clear_205afields();
	update_205aform();
}

std::string &ics205a_nn(std::string & subst, int n)
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
		ics[pos] = n > 29 ? '3' : n > 19 ? '2' : '1';
		ics[pos+1] = '0' + n % 10;
		ics[pos+2] = ']';
		ics += ':';
	}
	return ics;
}

void make_buff205a(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( ics205a_incident, s205a_incident ) );
	mbuff.append( lineout( ics205a_date_fm, s205a_date_fm ) );
	mbuff.append( lineout( ics205a_time_fm, s205a_time_fm ) );
	mbuff.append( lineout( ics205a_date_to, s205a_date_to ) );
	mbuff.append( lineout( ics205a_time_to, s205a_time_to ) );
	mbuff.append( lineout( ics205a_prepared_by, s205a_prepared_by ) );
	mbuff.append( lineout( ics205a_preparer_position, s205a_preparer_position ) );
	mbuff.append( lineout( ics205a_preparer_date_time, s205a_preparer_date_time ) );

	for (int i = 0; i < 32; i++) {
		mbuff.append( lineout( ics205a_nn( ics205a_comm_position, i ), s205a_comm_position[i] ) );
		mbuff.append( lineout( ics205a_nn( ics205a_comm_name, i ),     s205a_comm_name[i] ) );
		mbuff.append( lineout( ics205a_nn( ics205a_comm_info, i ),     s205a_comm_info[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	buff205a.append(mbuff);
}

void read_205a_buffer(std::string data)
{
	clear_205afields();
	read_header(data);

	s205a_incident = findstr( data, ics205a_incident );
	s205a_date_fm = findstr( data, ics205a_date_fm );
	s205a_time_fm  = findstr( data, ics205a_time_fm );
	s205a_date_to = findstr( data, ics205a_date_to );
	s205a_time_to  = findstr( data, ics205a_time_to );
	s205a_prepared_by = findstr( data, ics205a_prepared_by );
	s205a_preparer_position  = findstr( data, ics205a_preparer_position );
	s205a_preparer_date_time = findstr( data, ics205a_preparer_date_time );

	for (int i = 0; i < 32; i++) {
		s205a_comm_position[i] = findstr( data, ics205a_nn( ics205a_comm_position, i ) );
		s205a_comm_name[i]     = findstr( data, ics205a_nn( ics205a_comm_name, i ) );
		s205a_comm_info[i]     = findstr( data, ics205a_nn( ics205a_comm_info, i ) );
	}

	update_205aform();
}

void cb_205a_new()
{
	if (check_205afields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_205a_save();
		}
	}
	clear_205a_form();
	clear_header();
	def_205a_filename = ICS_msg_dir;
	def_205a_filename.append("new").append(F205A_EXT);
	show_filename(def_205a_filename);
	using_ics205a_template = false;
}

void cb_205a_import()
{
	fl_alert2("Not implemented");
}

void cb_205a_export()
{
	fl_alert2("Not implemented");
}

void cb_205a_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_205a_form();
	read_205a_buffer(inpbuffer);
	def_205a_filename = ICS_msg_dir;
	def_205a_filename.append(wrapfilename);
	show_filename(def_205a_filename);
	using_ics205a_template = false;
}

int eval_205a_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_205a_filename).append("]");
	update_205afields();
	update_header(FROM);
	evalstr.append(header("<ics205a>"));
	buff205a.clear();
	make_buff205a(true);
	if (buff205a.empty()) return 0;
	compress_maybe( buff205a );
	evalstr.append( buff205a );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_205a_wrap_export()
{
	if (check_205afields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_205afields();

	if (base_205a_filename == std::string("new").append(F205A_EXT) ||
		base_205a_filename == std::string("default").append(F205A_EXT) )
		if (!cb_205a_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_205a_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff205a.assign(header("<ics205a>"));
		make_buff205a(true);
		export_wrapfile(base_205a_filename, wrapfilename, buff205a, pext != ".wrap");
		write_205a(def_205a_filename);
	}
}

void cb_205a_wrap_autosend()
{
	if (check_205afields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_205afields();

	if (base_205a_filename == std::string("new").append(F205A_EXT) ||
		base_205a_filename == std::string("default").append(F205A_EXT) )
		cb_205a_save_as();

	update_header(FROM);
	buff205a.assign(header("<ics205a>"));
	make_buff205a(true);

	xfr_via_socket(base_205a_filename, buff205a);
	write_205a(def_205a_filename);
}

void cb_205a_load_template()
{
	std::string def_205a_filename = def_205a_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(F205A_EXT).c_str(),
			def_205a_filename.c_str());
	if (p) {
		clear_205a_form();
		read_data_file(p);
		def_205a_TemplateName = p;
		show_filename(def_205a_TemplateName);
		using_ics205a_template = true;
	}
}

void cb_205a_save_template()
{
	if (!using_ics205a_template) {
		cb_205a_save_as_template();
		return;
	}
	std::string def_205a_filename = def_205a_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(T205A_EXT).c_str(),
			def_205a_filename.c_str());
	if (p) {
		clear_header();
		make_buff205a();
		write_205a(p);
	}
}

void cb_205a_save_as_template()
{
	std::string def_205a_filename = def_205a_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(T205A_EXT).c_str(),
			def_205a_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_205a_TemplateName = p;
		if (strlen(pext) == 0) def_205a_TemplateName.append(T205A_EXT);
		remove_spaces_from_filename(def_205a_TemplateName);
		clear_header();
		make_buff205a();
		write_205a(def_205a_TemplateName);
		show_filename(def_205a_TemplateName);
		using_ics205a_template = true;
	}
}

void cb_205a_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-205a\t*").append(F205A_EXT).c_str(),
			def_205a_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_205a_form();
	read_data_file(p);
	using_ics205a_template = false;
	def_205a_filename = p;
	show_filename(def_205a_filename);
}

void write_205a(std::string s)
{
	FILE *file205a = fopen(s.c_str(), "w");
	if (!file205a) return;

	fwrite(buff205a.c_str(), buff205a.length(), 1, file205a);
	fclose(file205a);
}

bool cb_205a_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(F205A_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_205a_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-205a\t*").append(F205A_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_205a_filename = p;
	if (strlen(pext) == 0) def_205a_filename.append(F205A_EXT);

	remove_spaces_from_filename(def_205a_filename);
	update_205afields();
	update_header(NEW);
	buff205a.assign(header("<ics205a>"));
	make_buff205a();
	write_205a(def_205a_filename);

	using_ics205a_template = false;
	show_filename(def_205a_filename);
	return true;
}

void cb_205a_save()
{
	if (base_205a_filename == std::string("new").append(F205A_EXT) || 
		base_205a_filename == std::string("default").append(F205A_EXT) ||
		using_ics205a_template == true) {
		cb_205a_save_as();
		return;
	}
	if (check_205afields()) update_header(CHANGED);
	update_205afields();
	buff205a.assign(header("<ics205a>"));
	make_buff205a();
	write_205a(def_205a_filename);
	using_ics205a_template = false;
}

void cb_205a_html()
{
	std::string fname_name = fl_filename_name(def_205a_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string ics205a_fname = ICS_dir;
	ics205a_fname.append(fname_name);
	ics205a_fname.append(".html");

	std::string html_text = "";
	std::string empty = "<br>";

	update_205afields();
	std::string form205a = ics205a_html_template;

	replacestr(form205a, TITLE, fname_name);
	replacestr(form205a, ics205a_incident, s205a_incident );
	replacestr(form205a, ics205a_date_fm, s205a_date_fm );
	replacestr(form205a, ics205a_time_fm, s205a_time_fm );
	replacestr(form205a, ics205a_date_to, s205a_date_to );
	replacestr(form205a, ics205a_time_to, s205a_time_to );
	replacestr(form205a, ics205a_prepared_by, s205a_prepared_by );
	replacestr(form205a, ics205a_preparer_position, s205a_preparer_position );
	replacestr(form205a, ics205a_preparer_date_time, s205a_preparer_date_time );

	for (int i = 0; i < 32; i++) {
		replacestr(form205a, ics205a_nn( ics205a_comm_position, i ), 
			s205a_comm_position[i].empty() ? empty : s205a_comm_position[i] );
		replacestr(form205a, ics205a_nn( ics205a_comm_name, i ), 
			s205a_comm_name[i].empty() ? empty : s205a_comm_name[i] );
		replacestr(form205a, ics205a_nn( ics205a_comm_info, i ), 
			s205a_comm_info[i].empty() ? empty : s205a_comm_info[i] );
	}

	FILE *file205a = fopen(ics205a_fname.c_str(), "w");
	fprintf(file205a,"%s", form205a.c_str());
	fclose(file205a);

	open_url(ics205a_fname.c_str());
}

void cb_205a_msg_type()
{
	if (tabs_msg_type->value() == tab_ics205a ) {
		tab_ics205a_type->value(tab_205a_1);
		show_filename(def_205a_filename);
	}
}

void cb_205a_textout()
{
	std::string ics205a_fname = ICS_dir;
	ics205a_fname.append("ics205a.txt");

	update_205afields();
	std::string form205a = ics205a_text_template;

	replacestr(form205a, ics205a_incident, s205a_incident );
	replacestr(form205a, ics205a_date_fm, s205a_date_fm );
	replacestr(form205a, ics205a_time_fm, s205a_time_fm );
	replacestr(form205a, ics205a_date_to, s205a_date_to );
	replacestr(form205a, ics205a_time_to, s205a_time_to );
	replacestr(form205a, ics205a_prepared_by, s205a_prepared_by );
	replacestr(form205a, ics205a_preparer_position, s205a_preparer_position );
	replacestr(form205a, ics205a_preparer_date_time, s205a_preparer_date_time );

	for (int i = 0; i < 32; i++) {
		replacestr(form205a, ics205a_nn( ics205a_comm_position, i ), s205a_comm_position[i] );
		replacestr(form205a, ics205a_nn( ics205a_comm_name, i ), s205a_comm_name[i] );
		replacestr(form205a, ics205a_nn( ics205a_comm_info, i ), s205a_comm_info[i] );
	}

	FILE *file205a = fopen(ics205a_fname.c_str(), "w");
	fprintf(file205a,"%s", form205a.c_str());
	fclose(file205a);

	open_url(ics205a_fname.c_str());
}
