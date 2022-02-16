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
// ics 309 field variables and template variables
// ---------------------------------------------------------------------

std::string ics309_incident				= ":inc:";
std::string ics309_date_fm				= ":dfm:";
std::string ics309_time_fm				= ":tfm:";
std::string ics309_date_to				= ":dto:";
std::string ics309_time_to				= ":tto:";
std::string ics309_prepared_by			= ":pre:";
std::string ics309_preparer_date_time	= ":dtm:";
std::string ics309_radio_net				= ":net:";
std::string ics309_radio_operator		= ":opr:";

std::string ics309_comm_msg				= ":msg[n]:"; // 34
std::string ics309_comm_to				= ":to[n]:"; // 34
std::string ics309_comm_from				= ":fm[n]:"; // 34
std::string ics309_comm_time				= ":tm[n]:"; // 34

std::string s309_incident;
std::string s309_date_fm;
std::string s309_time_fm;
std::string s309_date_to;
std::string s309_time_to;
std::string s309_prepared_by;
std::string s309_preparer_date_time;
std::string s309_radio_net;
std::string s309_radio_operator;

std::string s309_comm_time[34];
std::string s309_comm_from[34];
std::string s309_comm_msg[34];
std::string s309_comm_to[34];

// =====================================================================

std::string buff309;
std::string def_309_filename = "";
std::string base_309_filename = "";
std::string def_309_TemplateName = "";
bool using_ics309_template = false;

void cb_309_set_date_fm()
{
	txt_309_date_fm->value(szDate(progStatus.dtformat));
}

void cb_309_set_time_fm()
{
	txt_309_time_fm->value(szTime(progStatus.UTC));
}

void cb_309_set_date_to()
{
	txt_309_date_to->value(szDate(progStatus.dtformat));
}

void cb_309_set_time_to()
{
	txt_309_time_to->value(szTime(progStatus.UTC));
}

void cb_309_set_date_time()
{
	std::string dt = szDate(progStatus.dtformat);
	dt.append(", ").append(szTime(progStatus.UTC));
	txt_309_preparer_date_time->value(dt.c_str());
}

void clear_309fields()
{
	s309_incident.clear();
	s309_date_fm.clear();
	s309_time_fm.clear();
	s309_date_to.clear();
	s309_time_to.clear();
	s309_prepared_by.clear();
	s309_preparer_date_time.clear();
	s309_radio_net.clear();
	s309_radio_operator.clear();

	for (int i = 0; i < 34; i++) {
		s309_comm_msg[i].clear();
		s309_comm_to[i].clear();
		s309_comm_from[i].clear();
	}
}

bool check_309fields()
{
	if (s309_incident != txt_309_incident->value())
		return true;
	if (s309_date_fm != txt_309_date_fm->value())
		return true;
	if (s309_time_fm != txt_309_time_fm->value())
		return true;
	if (s309_date_to != txt_309_date_to->value())
		return true;
	if (s309_time_to != txt_309_time_to->value())
		return true;
	if (s309_prepared_by != txt_309_prepared_by->value())
		return true;
	if (s309_radio_net != txt_309_radio_net->value())
		return true;
	if (s309_radio_operator != txt_309_radio_operator->value())
		return true;
	if (s309_preparer_date_time != txt_309_preparer_date_time->value())
		return true;
	for (int i = 0; i < 34; i++) {
		if (s309_comm_time[i] != txt_309_comm_time[i]->value())
			return true;
		if (s309_comm_msg[i] != txt_309_comm_msg[i]->value())
			return true;
		if (s309_comm_to[i] != txt_309_comm_to[i]->value())
			return true;
		if (s309_comm_from[i] != txt_309_comm_from[i]->value())
			return true;
	}
	return false;
}

void update_309fields()
{
	s309_incident = txt_309_incident->value();
	s309_date_fm = txt_309_date_fm->value();
	s309_time_fm = txt_309_time_fm->value();
	s309_date_to = txt_309_date_to->value();
	s309_time_to = txt_309_time_to->value();
	s309_prepared_by = txt_309_prepared_by->value();
	s309_radio_net = txt_309_radio_net->value();
	s309_radio_operator = txt_309_radio_operator->value();
	s309_preparer_date_time = txt_309_preparer_date_time->value();
	for (int i = 0; i < 34; i++) {
		s309_comm_time[i] = txt_309_comm_time[i]->value();
		s309_comm_from[i] = txt_309_comm_from[i]->value();
		s309_comm_to[i] = txt_309_comm_to[i]->value();
		s309_comm_msg[i] = txt_309_comm_msg[i]->value();
	}
}

void update_309form()
{
	txt_309_incident->value(s309_incident.c_str());
	txt_309_date_fm->value(s309_date_fm.c_str());
	txt_309_time_fm->value(s309_time_fm.c_str());
	txt_309_date_to->value(s309_date_to.c_str());
	txt_309_time_to->value(s309_time_to.c_str());
	txt_309_prepared_by->value(s309_prepared_by.c_str());
	txt_309_radio_net->value(s309_radio_net.c_str());
	txt_309_radio_operator->value(s309_radio_operator.c_str());
	txt_309_preparer_date_time->value(s309_preparer_date_time.c_str());

	for (int i = 0; i < 34; i++) {
		txt_309_comm_time[i]->value(s309_comm_time[i].c_str());
		txt_309_comm_to[i]->value(s309_comm_to[i].c_str());
		txt_309_comm_from[i]->value(s309_comm_from[i].c_str());
		txt_309_comm_msg[i]->value(s309_comm_msg[i].c_str());
	}
}

void clear_309_form()
{
	clear_309fields();
	update_309form();
}

std::string &ics309_nn(std::string & subst, int n)
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

void make_buff309(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( ics309_incident, s309_incident ) );
	mbuff.append( lineout( ics309_date_fm, s309_date_fm ) );
	mbuff.append( lineout( ics309_time_fm, s309_time_fm ) );
	mbuff.append( lineout( ics309_date_to, s309_date_to ) );
	mbuff.append( lineout( ics309_time_to, s309_time_to ) );
	mbuff.append( lineout( ics309_prepared_by, s309_prepared_by ) );
	mbuff.append( lineout( ics309_preparer_date_time, s309_preparer_date_time ) );
	mbuff.append( lineout( ics309_radio_net, s309_radio_net ) );
	mbuff.append( lineout( ics309_radio_operator, s309_radio_operator ) );

	for (int i = 0; i < 34; i++) {
		mbuff.append( lineout( ics309_nn( ics309_comm_time, i ), s309_comm_time[i] ) );
		mbuff.append( lineout( ics309_nn( ics309_comm_to, i ),     s309_comm_to[i] ) );
		mbuff.append( lineout( ics309_nn( ics309_comm_from, i ),     s309_comm_from[i] ) );
		mbuff.append( lineout( ics309_nn( ics309_comm_msg, i ), s309_comm_msg[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	buff309.append(mbuff);
}

void read_309_buffer(std::string data)
{
	clear_309fields();
	read_header(data);

	s309_incident = findstr( data, ics309_incident );
	s309_date_fm = findstr( data, ics309_date_fm );
	s309_time_fm  = findstr( data, ics309_time_fm );
	s309_date_to = findstr( data, ics309_date_to );
	s309_time_to  = findstr( data, ics309_time_to );
	s309_prepared_by = findstr( data, ics309_prepared_by );
	s309_preparer_date_time = findstr( data, ics309_preparer_date_time );
	s309_radio_net = findstr( data, ics309_radio_net );
	s309_radio_operator  = findstr( data, ics309_radio_operator );

	for (int i = 0; i < 34; i++) {
		s309_comm_time[i]    = findstr( data, ics309_nn( ics309_comm_time, i ) );
		s309_comm_to[i]      = findstr( data, ics309_nn( ics309_comm_to, i ) );
		s309_comm_from[i]    = findstr( data, ics309_nn( ics309_comm_from, i ) );
		s309_comm_msg[i] = findstr( data, ics309_nn( ics309_comm_msg, i ) );
	}

	update_309form();
}

void cb_309_new()
{
	if (check_309fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_309_save();
		}
	}
	clear_309_form();
	clear_header();
	def_309_filename = ICS_msg_dir;
	def_309_filename.append("new").append(F309_EXT);
	show_filename(def_309_filename);
	using_ics309_template = false;
}

void cb_309_import()
{
	fl_alert2("Not implemented");
}

void cb_309_export()
{
	fl_alert2("Not implemented");
}

void cb_309_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_309_form();
	read_309_buffer(inpbuffer);
	def_309_filename = ICS_msg_dir;
	def_309_filename.append(wrapfilename);
	show_filename(def_309_filename);
	using_ics309_template = false;
}

int eval_309_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_309_filename).append("]");
	update_309fields();
	update_header(FROM);
	evalstr.append(header("<ics309>"));
	buff309.clear();
	make_buff309(true);
	if (buff309.empty()) return 0;
	compress_maybe( buff309 );
	evalstr.append( buff309 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_309_wrap_export()
{
	if (check_309fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_309fields();

	if (base_309_filename == std::string("new").append(F309_EXT) ||
		base_309_filename == std::string("default").append(F309_EXT) )
		if (!cb_309_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_309_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff309.assign(header("<ics309>"));
		make_buff309(true);
		export_wrapfile(base_309_filename, wrapfilename, buff309, pext != ".wrap");
		write_309(def_309_filename);
	}
}

void cb_309_wrap_autosend()
{
	if (check_309fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_309fields();

	if (base_309_filename == std::string("new").append(F309_EXT) ||
		base_309_filename == std::string("default").append(F309_EXT) )
		cb_309_save_as();

	update_header(FROM);
	buff309.assign(header("<ics309>"));
	make_buff309(true);

	xfr_via_socket(base_309_filename, buff309);
	write_309(def_309_filename);
}

void cb_309_load_template()
{
	std::string def_309_filename = def_309_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(T309_EXT).c_str(),
			def_309_filename.c_str());
	if (p) {
		clear_309_form();
		read_data_file(p);
		def_309_TemplateName = p;
		show_filename(def_309_TemplateName);
		using_ics309_template = true;
	}
}

void cb_309_save_template()
{
	if (!using_ics309_template) {
		cb_309_save_as_template();
		return;
	}
	std::string def_309_filename = def_309_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(T309_EXT).c_str(),
			def_309_filename.c_str());
	if (p) {
		update_header(CHANGED);
		buff309.assign(header("<ics309>"));
		make_buff309();
		write_309(p);
	}
}

void cb_309_save_as_template()
{
	std::string def_309_filename = def_309_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(T309_EXT).c_str(),
			def_309_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_309_TemplateName = p;
		if (strlen(pext) == 0) def_309_TemplateName.append(T309_EXT);
		remove_spaces_from_filename(def_309_TemplateName);
		clear_header();
		update_header(CHANGED);
		buff309.assign(header("<ics309>"));
		make_buff309();
		write_309(def_309_TemplateName);
		show_filename(def_309_TemplateName);
		using_ics309_template = true;
	}
}

void cb_309_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-309\t*").append(F309_EXT).c_str(),
			def_309_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_309_form();
	read_data_file(p);
	using_ics309_template = false;
	def_309_filename = p;
	show_filename(def_309_filename);
}

void write_309(std::string s)
{
	FILE *file309 = fopen(s.c_str(), "w");
	if (!file309) return;

	fwrite(buff309.c_str(), buff309.length(), 1, file309);
	fclose(file309);
}

bool cb_309_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(F309_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_309_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-309\t*").append(F309_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_309_filename = p;
	if (strlen(pext) == 0) def_309_filename.append(F309_EXT);

	remove_spaces_from_filename(def_309_filename);
	update_309fields();
	update_header(NEW);
	buff309.assign(header("<ics309>"));
	make_buff309();
	write_309(def_309_filename);

	using_ics309_template = false;
	show_filename(def_309_filename);
	return true;
}

void cb_309_save()
{
	if (base_309_filename == std::string("new").append(F309_EXT) || 
		base_309_filename == std::string("default").append(F309_EXT) ||
		using_ics309_template == true) {
		cb_309_save_as();
		return;
	}
	if (check_309fields()) update_header(CHANGED);
	update_309fields();
	buff309.assign(header("<ics309>"));
	make_buff309();
	write_309(def_309_filename);
	using_ics309_template = false;
}

void cb_309_html()
{
	std::string fname_name = fl_filename_name(def_309_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string ics309_fname = ICS_dir;
	ics309_fname.append(fname_name);
	ics309_fname.append(".html");

	std::string html_text = "";
	std::string empty = "<br>";

	update_309fields();
	std::string form309 = ics309_html_template;

	replacestr(form309, TITLE, fname_name);
	replacestr(form309, ics309_incident, s309_incident );
	replacestr(form309, ics309_date_fm, s309_date_fm );
	replacestr(form309, ics309_time_fm, s309_time_fm );
	replacestr(form309, ics309_date_to, s309_date_to );
	replacestr(form309, ics309_time_to, s309_time_to );
	replacestr(form309, ics309_prepared_by, s309_prepared_by );
	replacestr(form309, ics309_preparer_date_time, s309_preparer_date_time );
	replacestr(form309, ics309_radio_net, s309_radio_net );
	replacestr(form309, ics309_radio_operator, s309_radio_operator );

	for (int i = 0; i < 34; i++) {
		replacestr(form309, ics309_nn( ics309_comm_time, i ),
			s309_comm_time[i].empty() ? empty : s309_comm_time[i] );
		replacestr(form309, ics309_nn( ics309_comm_to, i ), 
			s309_comm_to[i].empty() ? empty : s309_comm_to[i] );
		replacestr(form309, ics309_nn( ics309_comm_from, i ), 
			s309_comm_from[i].empty() ? empty : s309_comm_from[i] );
		replacestr(form309, ics309_nn( ics309_comm_msg, i ), 
			s309_comm_msg[i].empty() ? empty : s309_comm_msg[i] );
	}

	FILE *file309 = fopen(ics309_fname.c_str(), "w");
	fprintf(file309,"%s", form309.c_str());
	fclose(file309);

	open_url(ics309_fname.c_str());
}

void cb_309_msg_type()
{
	if (tabs_msg_type->value() == tab_ics309 ) {
		tab_ics309_type->value(tab_309_1);
		show_filename(def_309_filename);
	}
}

void cb_309_textout()
{
	std::string ics309_fname = ICS_dir;
	ics309_fname.append("ics309.txt");

	update_309fields();
	std::string form309 = ics309_text_template;

	replacestr(form309, ics309_incident, s309_incident );
	replacestr(form309, ics309_date_fm, s309_date_fm );
	replacestr(form309, ics309_time_fm, s309_time_fm );
	replacestr(form309, ics309_date_to, s309_date_to );
	replacestr(form309, ics309_time_to, s309_time_to );
	replacestr(form309, ics309_prepared_by, s309_prepared_by );
	replacestr(form309, ics309_preparer_date_time, s309_preparer_date_time );
	replacestr(form309, ics309_radio_net, s309_radio_net );
	replacestr(form309, ics309_radio_operator, s309_radio_operator );

	for (int i = 0; i < 34; i++) {
		replacestr(form309, ics309_nn( ics309_comm_time, i ), s309_comm_time[i] );
		replacestr(form309, ics309_nn( ics309_comm_msg, i ), s309_comm_msg[i] );
		replacestr(form309, ics309_nn( ics309_comm_to, i ), s309_comm_to[i] );
		replacestr(form309, ics309_nn( ics309_comm_from, i ), s309_comm_from[i] );
	}

	FILE *file309 = fopen(ics309_fname.c_str(), "w");
	fprintf(file309,"%s", form309.c_str());
	fclose(file309);

	open_url(ics309_fname.c_str());
}

void ics309_csv(Fl_Widget *w, void *d)
{
	std::string csv_fname = ICS_dir;
	csv_fname.append("ics309.csv");

	const char *p;

	p = FSEL::saveas(_("Save csv file"), "ICS-309\t*.csv",
					csv_fname.c_str());

	if (!p) return;
	if (strlen(p) == 0) return;

	csv_fname = p;

	update_309fields();

	std::string cvs_text;
	cvs_text.assign("Incident,Start_Date,Start_Time,End_Date,End_Time,Preparer,Prepared_Date,Radio_Net,Radio_operator\n");
	cvs_text.append("\"").append(s309_incident).append("\",");
	cvs_text.append("\"").append(s309_date_fm).append("\",");
	cvs_text.append("\"").append(s309_time_fm).append("\",");
	cvs_text.append("\"").append(s309_date_to).append("\",");
	cvs_text.append("\"").append(s309_time_to).append("\",");
	cvs_text.append("\"").append(s309_prepared_by).append("\",");
	cvs_text.append("\"").append(s309_preparer_date_time).append("\",");
	cvs_text.append("\"").append(s309_radio_net).append("\",");
	cvs_text.append("\"").append(s309_radio_operator).append("\"\n");
	cvs_text.append("\n");
	cvs_text.append("COMM_TIME,COMM_TO,COMM_FM,COMM_MSG\n");
	
	for (int i = 0; i < 34; i++) {
		cvs_text.append("\"").append(s309_comm_time[i]).append("\",");
		cvs_text.append("\"").append(s309_comm_to[i]).append("\",");
		cvs_text.append("\"").append(s309_comm_from[i]).append("\",");
		cvs_text.append("\"").append(s309_comm_msg[i]).append("\"\n");
	}

	FILE *csv_file = fopen(csv_fname.c_str(), "w");
	if (!csv_file) return;
	fprintf(csv_file,"%s", cvs_text.c_str());
	fclose(csv_file);
}
