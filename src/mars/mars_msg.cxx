// ----------------------------------------------------------------------------
// Copyright (C) 2021
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

const char msg_precedent[] = "RPIF";

std::string mars_msg_de     = ":de:";
std::string mars_msg_serno  = ":serno:";
std::string mars_msg_prec	= ":pre:";
std::string mars_msg_dtg	= ":dtg:";
std::string mars_msg_fm		= ":fm:";
std::string mars_msg_to		= ":to:";
std::string mars_msg_info	= ":info:";
std::string mars_msg_subj	= ":subj:";
std::string mars_msg_text	= ":text:";

std::string s_mars_msg_de;
std::string s_mars_msg_serno;
std::string s_mars_msg_prec = "R";
std::string s_mars_msg_dtg;
std::string s_mars_msg_fm;
std::string s_mars_msg_to;
std::string s_mars_msg_subj;
std::string s_mars_msg_info;
std::string s_mars_msg_text;

std::string buffmars_msg;
std::string def_mars_msg_filename = "";
std::string base_mars_msg_filename = "";
std::string def_mars_msg_TemplateName = "";

bool using_mars_msg_template = false;

void clear_mars_msgfields()
{
	s_mars_msg_de.clear();
	s_mars_msg_serno.clear();

	s_mars_msg_prec = "R";
	s_mars_msg_dtg.clear();
	s_mars_msg_fm.clear();
	s_mars_msg_to.clear();
	s_mars_msg_subj.clear();
	s_mars_msg_info.clear();
	s_mars_msg_text.clear();
}

bool check_mars_msgfields()
{
	std::string temp;
	temp = msg_precedent[sel_mars_msg_prec->index()];
	if (s_mars_msg_prec != temp) return true;

	if (s_mars_msg_de != txt_mars_msg_de->value()) return true;
	if (s_mars_msg_serno != txt_mars_msg_serno->value()) return true;

	if (s_mars_msg_dtg != txt_mars_msg_dtg->value()) return true;
	if (s_mars_msg_fm != txt_mars_msg_fm->value()) return true;
	if (s_mars_msg_serno != txt_mars_msg_serno->value()) return true;
	if (s_mars_msg_to != txt_mars_msg_to->buffer()->text()) return true;
	if (s_mars_msg_info != txt_mars_msg_info->buffer()->text()) return true;
	if (s_mars_msg_subj != txt_mars_msg_subj->value()) return true;
	if (s_mars_msg_text != txt_mars_msg_text->buffer()->text()) return true;
	return false;
}

void update_mars_msgfields()
{
	s_mars_msg_de = txt_mars_msg_de->value();
	s_mars_msg_serno = txt_mars_msg_serno->value();

	s_mars_msg_prec.clear();
	s_mars_msg_prec = msg_precedent[sel_mars_msg_prec->index()];
	s_mars_msg_dtg = txt_mars_msg_dtg->value();
	s_mars_msg_fm = txt_mars_msg_fm->value();
	s_mars_msg_to = txt_mars_msg_to->buffer()->text();
	s_mars_msg_info = txt_mars_msg_info->buffer()->text();
	s_mars_msg_subj = txt_mars_msg_subj->value();
	s_mars_msg_text = txt_mars_msg_text->buffer()->text();
}

void update_mars_msgform()
{
	size_t n = strchr(msg_precedent, s_mars_msg_prec[0]) - msg_precedent;
	if (n < 0) n = 0;
	if (n > 4) n = 4;
	sel_mars_msg_prec->index(n);

	txt_mars_msg_de->value(s_mars_msg_de.c_str());
	txt_mars_msg_serno->value(s_mars_msg_serno.c_str());

	txt_mars_msg_dtg->value(s_mars_msg_dtg.c_str());
	txt_mars_msg_fm->value(s_mars_msg_fm.c_str());
	txt_mars_msg_to->add(s_mars_msg_to.c_str());
	txt_mars_msg_info->add(s_mars_msg_info.c_str());
	txt_mars_msg_subj->value(s_mars_msg_subj.c_str());
	txt_mars_msg_text->add(s_mars_msg_text.c_str());

}

void clear_mars_msg_form()
{
	clear_mars_msgfields();

	txt_mars_msg_de->value("");
	txt_mars_msg_serno->value("");

	sel_mars_msg_prec->index(0);
	txt_mars_msg_dtg->value("");
	txt_mars_msg_fm->value("");

	txt_mars_msg_to->clear();
	txt_mars_msg_info->clear();
	txt_mars_msg_subj->value("");
	txt_mars_msg_text->clear();
}

void make_buffmars_msg(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( mars_msg_de,		s_mars_msg_de ) );
	mbuff.append( lineout( mars_msg_serno,		s_mars_msg_serno ) );
	mbuff.append( lineout( mars_msg_prec,		s_mars_msg_prec ) );
	mbuff.append( lineout( mars_msg_dtg,		s_mars_msg_dtg ) );
	mbuff.append( lineout( mars_msg_fm,		s_mars_msg_fm ) );
	mbuff.append( lineout( mars_msg_to,		s_mars_msg_to ) );
	mbuff.append( lineout( mars_msg_info,		s_mars_msg_info ) );
	mbuff.append( lineout( mars_msg_subj,		s_mars_msg_subj ) );
	mbuff.append( lineout( mars_msg_text,		s_mars_msg_text ) );
	if (compress) compress_maybe(mbuff);
	buffmars_msg.append(mbuff);
}

void read_mars_msg_buffer(std::string data)
{
	clear_mars_msgfields();

	s_mars_msg_de = findstr( data, mars_msg_de );
	s_mars_msg_serno = findstr( data, mars_msg_serno );
	s_mars_msg_prec = findstr( data, mars_msg_prec );
	s_mars_msg_dtg = findstr( data, mars_msg_dtg );
	s_mars_msg_fm = findstr( data, mars_msg_fm );
	s_mars_msg_to = findstr( data, mars_msg_to );
	s_mars_msg_info = findstr( data, mars_msg_info );
	s_mars_msg_subj = findstr( data, mars_msg_subj );
	s_mars_msg_text = findstr( data, mars_msg_text );
	update_mars_msgform();
}

void cb_mars_msg_new()
{
	if (check_mars_msgfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_mars_msg_save();
		}
	}
	clear_mars_msg_form();
	def_mars_msg_filename = ICS_msg_dir;
	def_mars_msg_filename.append("new").append(FMARSMSG_EXT);
	show_filename(def_mars_msg_filename);
	using_mars_msg_template = false;
}

void cb_mars_msg_import()
{
	fl_alert2("Not implemented");
}

void cb_mars_msg_export()
{
	fl_alert2("Not implemented");
}

void cb_mars_msg_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_mars_msg_form();
	read_mars_msg_buffer(inpbuffer);
	def_mars_msg_filename = ICS_msg_dir;
	def_mars_msg_filename.append(wrapfilename);
	show_filename(def_mars_msg_filename);
	using_mars_msg_template = false;
}

int eval_mars_msg_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_mars_msg_filename).append("]");
	update_mars_msgfields();
	update_header(FROM);
	evalstr.append(header("<mars_msg>"));
	buffmars_msg.clear();
	make_buffmars_msg(true);
	if (buffmars_msg.empty()) return 0;
	compress_maybe( buffmars_msg );
	evalstr.append( buffmars_msg );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_mars_msg_wrap_export()
{
	if (check_mars_msgfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_msgfields();

	if (base_mars_msg_filename == std::string("new").append(FMARSMSG_EXT) || 
		base_mars_msg_filename == std::string("default").append(FMARSMSG_EXT))
		if (!cb_mars_msg_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_msg_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buffmars_msg.assign(header("<mars_msg>"));
		make_buffmars_msg(true);
		export_wrapfile(base_mars_msg_filename, wrapfilename, buffmars_msg, pext != ".wrap");

		buffmars_msg.assign(header("<mars_msg>"));
		make_buffmars_msg(false);
		write_mars_msg(def_mars_msg_filename);
	}
}

void cb_mars_msg_wrap_autosend()
{
	if (check_mars_msgfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_msgfields();

	if (base_mars_msg_filename == std::string("new").append(FMARSMSG_EXT) ||
		base_mars_msg_filename == std::string("default").append(FMARSMSG_EXT) )
		cb_mars_msg_save_as();

	update_header(FROM);
	buffmars_msg.assign(header("<mars_msg>"));
	make_buffmars_msg(true);
	xfr_via_socket(base_mars_msg_filename, buffmars_msg);

	buffmars_msg.assign(header("<mars_msg>"));
	make_buffmars_msg(false);
	write_mars_msg(def_mars_msg_filename);
}

void cb_mars_msg_load_template()
{
	std::string def_mars_msg_filename = def_mars_msg_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TMARSMSG_EXT).c_str(),
			def_mars_msg_filename.c_str());
	if (p) {
		clear_mars_msg_form();
		read_data_file(p);
		def_mars_msg_TemplateName = p;
		show_filename(def_mars_msg_TemplateName);
		using_mars_msg_template = true;
	}
}

void cb_mars_msg_save_template()
{
	if (!using_mars_msg_template) {
		cb_mars_msg_save_as_template();
		return;
	}
	std::string def_mars_msg_filename = def_mars_msg_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TMARSMSG_EXT).c_str(),
			def_mars_msg_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_mars_msgfields();
		buffmars_msg.assign(header("<mars_msg>"));
		make_buffmars_msg();
		write_mars_msg(p);
	}
}

void cb_mars_msg_save_as_template()
{
	std::string def_mars_msg_filename = def_mars_msg_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TMARSMSG_EXT).c_str(),
			def_mars_msg_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_msg_TemplateName = p;
		if (strlen(pext) == 0) def_mars_msg_TemplateName.append(TMARSMSG_EXT);
		remove_spaces_from_filename(def_mars_msg_TemplateName);
	
		clear_header();
		update_header(CHANGED);
		buffmars_msg.assign(header("<mars_msg>"));
		make_buffmars_msg();
		write_mars_msg(def_mars_msg_TemplateName);

		show_filename(def_mars_msg_TemplateName);
		using_mars_msg_template = true;
	}
}

void cb_mars_msg_open()
{
	const char *p = FSEL::select(
					_("Open data file"),
					std::string("ICS-mars_msg\t*").append(FMARSMSG_EXT).c_str(),
					def_mars_msg_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_msg_form();
	read_data_file(p);
	using_mars_msg_template = false;
	def_mars_msg_filename = p;
	show_filename(def_mars_msg_filename);
}

void write_mars_msg(std::string s)
{
	FILE *filemars_msg = fopen(s.c_str(), "w");
	if (!filemars_msg) return;

	fwrite(buffmars_msg.c_str(), buffmars_msg.length(), 1, filemars_msg);
	fclose(filemars_msg);
}

bool cb_mars_msg_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(FMARSMSG_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_msg_filename;

	p = FSEL::saveas(_("Save data file"),
					std::string("ICS-mars_msg\t*").append(FMARSMSG_EXT).c_str(),
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) {
		std::string haystack = p;
		if (haystack.find(newfilename) != std::string::npos) {
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
	def_mars_msg_filename = p;
	if (strlen(pext) == 0) def_mars_msg_filename.append(FMARSMSG_EXT);

	remove_spaces_from_filename(def_mars_msg_filename);

	update_header(NEW);
	update_mars_msgfields();
	buffmars_msg.assign(header("<mars_msg>"));
	make_buffmars_msg();
	write_mars_msg(def_mars_msg_filename);

	using_mars_msg_template = false;
	show_filename(def_mars_msg_filename);
	return true;
}

void cb_mars_msg_save()
{
	if (base_mars_msg_filename == std::string("new").append(FMARSMSG_EXT) || 
		base_mars_msg_filename == std::string("default").append(FMARSMSG_EXT) ||
		using_mars_msg_template == true) {
		cb_mars_msg_save_as();
		return;
	}

	if (check_mars_msgfields()) update_header(CHANGED);
	update_mars_msgfields();
	buffmars_msg.assign(header("<mars_msg>"));
	make_buffmars_msg();
	write_mars_msg(def_mars_msg_filename);

	using_mars_msg_template = false;
}

void cb_mars_msg_html()
{
	std::string fname_name = fl_filename_name(def_mars_msg_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string mars_msg_fname = ICS_dir;
	mars_msg_fname.append(fname_name);
	mars_msg_fname.append(".html");

	update_mars_msgfields();
	std::string formmars_msg = mars_msg_html_template;

	replacestr(formmars_msg, TITLE, fname_name);

	std::string temp = s_mars_msg_prec;
	if (!s_mars_msg_de.empty()) {
		temp.assign("DE ").append(s_mars_msg_de).append(" ");
		if (!s_mars_msg_serno.empty()) {
			if (s_mars_msg_serno.length() < 4)
				temp.append(4-s_mars_msg_serno.length(),'0');
			temp.append(s_mars_msg_serno);
		}
		temp.append("\n");
		temp.append(s_mars_msg_prec);
	}
	replacestr(formmars_msg, mars_msg_prec, temp );
	replacestr(formmars_msg, mars_msg_dtg, s_mars_msg_dtg );
	replacestr(formmars_msg, mars_msg_fm, s_mars_msg_fm );
	temp = s_mars_msg_to;
	if (!s_mars_msg_info.empty())
		temp.append("\nINFO ").append(s_mars_msg_info);
	replacestr(formmars_msg, mars_msg_to, temp );

	std::string text = "";
	temp = "";
	if (!s_mars_msg_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_msg_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_msg_text, 69);
	text.append(temp);

	replacestr(formmars_msg, mars_msg_text, text );

	FILE *filemars_msg = fopen(mars_msg_fname.c_str(), "w");
	fprintf(filemars_msg,"%s", formmars_msg.c_str());
	fclose(filemars_msg);

	open_url(mars_msg_fname.c_str());
}

void cb_mars_msg_msg_type()
{
	if (tabs_msg_type->value() == tab_mars_msg ) {
		show_filename(def_mars_msg_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_mars_msg_textout()
{
	std::string mars_msg_fname = ICS_dir;
	mars_msg_fname.append("mars_msg.txt");

	update_mars_msgfields();
	std::string formmars_msg = mars_msg_text_template;

	std::string temp = s_mars_msg_prec;
	if (!s_mars_msg_de.empty()) {
		temp.assign("DE ").append(s_mars_msg_de).append(" ");
		if (!s_mars_msg_serno.empty()) {
			if (s_mars_msg_serno.length() < 4)
				temp.append(4-s_mars_msg_serno.length(),'0');
			temp.append(s_mars_msg_serno);
		}
		temp.append("\n");
		temp.append(s_mars_msg_prec);
	}
	replacestr(formmars_msg, mars_msg_prec, temp );
	replacestr(formmars_msg, mars_msg_dtg, s_mars_msg_dtg );
	replacestr(formmars_msg, mars_msg_fm, s_mars_msg_fm );
	temp = s_mars_msg_to;
	if (!s_mars_msg_info.empty())
		temp.append("\nINFO ").append(s_mars_msg_info);
	replacestr(formmars_msg, mars_msg_to, temp );

	std::string text = "";
	temp = "";
	if (!s_mars_msg_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_msg_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_msg_text, 69);
	text.append(temp);

	replacestr(formmars_msg, mars_msg_text, text );

	FILE *filemars_msg = fopen(mars_msg_fname.c_str(), "w");
	fprintf(filemars_msg,"%s", formmars_msg.c_str());
	fclose(filemars_msg);

	open_url(mars_msg_fname.c_str());
}

