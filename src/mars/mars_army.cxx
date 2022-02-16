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

const char army_precedent[] = "RPOZM";

std::string mars_army_de		= ":de:";
std::string mars_army_nbr	= ":nbr:";

std::string mars_army_prec	= ":pre:";
std::string mars_army_dtg	= ":dtg:";
std::string mars_army_fm		= ":fm:";
std::string mars_army_to		= ":to:";
std::string mars_army_info	= ":info:";
std::string mars_army_subj	= ":subj:";
std::string mars_army_text	= ":text:";

std::string s_mars_army_de;
std::string s_mars_army_nbr;
std::string s_mars_army_prec = "R";
std::string s_mars_army_dtg;
std::string s_mars_army_fm;
std::string s_mars_army_to;
std::string s_mars_army_subj;
std::string s_mars_army_info;
std::string s_mars_army_text;

std::string buffmars_army;
std::string def_mars_army_filename = "";
std::string base_mars_army_filename = "";
std::string def_mars_army_TemplateName = "";

bool using_mars_army_template = false;

void clear_mars_armyfields()
{
	s_mars_army_prec = "R";
	s_mars_army_dtg.clear();
	s_mars_army_fm.clear();
	s_mars_army_de.clear();
	s_mars_army_nbr.clear();
	s_mars_army_to.clear();
	s_mars_army_subj.clear();
	s_mars_army_info.clear();
	s_mars_army_text.clear();
}

bool check_mars_armyfields()
{
	std::string temp;
	temp = army_precedent[sel_mars_army_prec->index()];
	if (s_mars_army_prec != temp) return true;
	if (s_mars_army_dtg != txt_mars_army_dtg->value()) return true;
	if (s_mars_army_fm != txt_mars_army_fm->value()) return true;
	if (s_mars_army_de != txt_mars_army_de->value()) return true;
	if (s_mars_army_nbr != txt_mars_army_nbr->value()) return true;
	if (s_mars_army_to != txt_mars_army_to->buffer()->text()) return true;
	if (s_mars_army_info != txt_mars_army_info->buffer()->text()) return true;
	if (s_mars_army_subj != txt_mars_army_subj->value()) return true;
	if (s_mars_army_text != txt_mars_army_text->buffer()->text()) return true;
	return false;
}

void update_mars_armyfields()
{
	s_mars_army_prec.clear();
	s_mars_army_prec = army_precedent[sel_mars_army_prec->index()];
	s_mars_army_dtg = txt_mars_army_dtg->value();
	s_mars_army_fm = txt_mars_army_fm->value();
	s_mars_army_de = txt_mars_army_de->value();
	s_mars_army_nbr = txt_mars_army_nbr->value();
	s_mars_army_to = txt_mars_army_to->buffer()->text();
	s_mars_army_info = txt_mars_army_info->buffer()->text();
	s_mars_army_subj = txt_mars_army_subj->value();
	s_mars_army_text = txt_mars_army_text->buffer()->text();
	striplf (s_mars_army_dtg);
	striplf (s_mars_army_de);
	striplf (s_mars_army_fm);
	striplf (s_mars_army_nbr);
	striplf (s_mars_army_to);
	striplf (s_mars_army_info);
	striplf (s_mars_army_subj);
	striplf (s_mars_army_text);
}

void update_mars_armyform()
{
	size_t n = strchr(army_precedent, s_mars_army_prec[0]) - army_precedent;
	if (n < 0) n = 0;
	if (n > 4) n = 4;
	sel_mars_army_prec->index(n);

	txt_mars_army_dtg->value(s_mars_army_dtg.c_str());
	txt_mars_army_fm->value(s_mars_army_fm.c_str());
	txt_mars_army_de->value(s_mars_army_de.c_str());
	txt_mars_army_nbr->value(s_mars_army_nbr.c_str());
	txt_mars_army_to->add(s_mars_army_to.c_str());
	txt_mars_army_info->add(s_mars_army_info.c_str());
	txt_mars_army_subj->value(s_mars_army_subj.c_str());
	txt_mars_army_text->add(s_mars_army_text.c_str());

}

void clear_mars_army_form()
{
	clear_mars_armyfields();
	sel_mars_army_prec->index(0);
	txt_mars_army_dtg->value("");
	txt_mars_army_fm->value("");
	txt_mars_army_de->value("");
	txt_mars_army_nbr->value("");

	txt_mars_army_to->clear();
	txt_mars_army_info->clear();
	txt_mars_army_subj->value("");
	txt_mars_army_text->clear();
}

void make_buffmars_army(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( mars_army_prec,		s_mars_army_prec ) );
	mbuff.append( lineout( mars_army_dtg,		s_mars_army_dtg ) );
	mbuff.append( lineout( mars_army_fm,		s_mars_army_fm ) );
	mbuff.append( lineout( mars_army_de,		s_mars_army_de ) );
	mbuff.append( lineout( mars_army_nbr,		s_mars_army_nbr ) );
	mbuff.append( lineout( mars_army_to,		s_mars_army_to ) );
	mbuff.append( lineout( mars_army_info,		s_mars_army_info ) );
	mbuff.append( lineout( mars_army_subj,		s_mars_army_subj ) );
	mbuff.append( lineout( mars_army_text,		s_mars_army_text ) );
	if (compress) compress_maybe(mbuff);
	buffmars_army.append(mbuff);
}

void read_mars_army_buffer(std::string data)
{
	clear_mars_armyfields();
// search the file buffer for each of the mars_army fields
	s_mars_army_prec = findstr( data, mars_army_prec );
	s_mars_army_dtg = findstr( data, mars_army_dtg );
	s_mars_army_fm = findstr( data, mars_army_fm );
	s_mars_army_de = findstr( data, mars_army_de );
	s_mars_army_nbr = findstr( data, mars_army_nbr );
	s_mars_army_to = findstr( data, mars_army_to );
	s_mars_army_info = findstr( data, mars_army_info );
	s_mars_army_subj = findstr( data, mars_army_subj );
	s_mars_army_text = findstr( data, mars_army_text );

	update_mars_armyform();
}

void cb_mars_army_new()
{
	if (check_mars_armyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_mars_army_save();
		}
	}
	clear_mars_army_form();
	def_mars_army_filename = ICS_msg_dir;
	def_mars_army_filename.append("new").append(FMARSARMY_EXT);
	show_filename(def_mars_army_filename);
	using_mars_army_template = false;
}

void cb_mars_army_import()
{
	fl_alert2("Not implemented");
}

void cb_mars_army_export()
{
	fl_alert2("Not implemented");
}

void cb_mars_army_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_mars_army_form();
	read_mars_army_buffer(inpbuffer);
	def_mars_army_filename = ICS_msg_dir;
	def_mars_army_filename.append(wrapfilename);
	show_filename(def_mars_army_filename);
	using_mars_army_template = false;
}

int eval_mars_army_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_mars_army_filename).append("]");
	update_mars_armyfields();
	update_header(FROM);
	evalstr.append(header("<mars_army>"));
	buffmars_army.clear();
	make_buffmars_army(true);
	if (buffmars_army.empty()) return 0;
	compress_maybe( buffmars_army );
	evalstr.append( buffmars_army );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_mars_army_wrap_export()
{
	if (check_mars_armyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_armyfields();

	if (base_mars_army_filename == std::string("new").append(FMARSARMY_EXT) ||
		base_mars_army_filename == std::string("default").append(FMARSARMY_EXT) )
		if (!cb_mars_army_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_army_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffmars_army.assign(header("<mars_army>"));
		make_buffmars_army(true);
		export_wrapfile(base_mars_army_filename, wrapfilename, buffmars_army, pext != ".wrap");

		buffmars_army.assign(header("<mars_army>"));
		make_buffmars_army(false);
		write_mars_army(def_mars_army_filename);
	}
}

void cb_mars_army_wrap_autosend()
{
	if (check_mars_armyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_armyfields();

	if (base_mars_army_filename == std::string("new").append(FMARSARMY_EXT) ||
		base_mars_army_filename == std::string("default").append(FMARSARMY_EXT) )
		if (!cb_mars_army_save_as()) return;

	update_header(FROM);
	buffmars_army.assign(header("<mars_army>"));
	make_buffmars_army(true);
	xfr_via_socket(base_mars_army_filename, buffmars_army);

	buffmars_army.assign(header("<mars_army>"));
	make_buffmars_army(false);
	write_mars_army(def_mars_army_filename);
}

void cb_mars_army_load_template()
{
	std::string def_mars_army_filename = def_mars_army_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TMARSARMY_EXT).c_str(),
			def_mars_army_filename.c_str());
	if (p) {
		clear_mars_army_form();
		read_data_file(p);
		def_mars_army_TemplateName = p;
		show_filename(def_mars_army_TemplateName);
		using_mars_army_template = true;
	}
}

void cb_mars_army_save_template()
{
	if (!using_mars_army_template) {
		cb_mars_army_save_as_template();
		return;
	}
	std::string def_mars_army_filename = def_mars_army_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TMARSARMY_EXT).c_str(),
			def_mars_army_filename.c_str());
	if (p)
		write_mars_army(p);
	if (p) {
		update_header(CHANGED);
		update_mars_armyfields();
		buffmars_army.assign(header("<mars_army>"));
		make_buffmars_army();
		write_mars_army(p);
	}
}

void cb_mars_army_save_as_template()
{
	std::string def_mars_army_filename = def_mars_army_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TMARSARMY_EXT).c_str(),
			def_mars_army_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_army_TemplateName = p;
		if (strlen(pext) == 0) def_mars_army_TemplateName.append(TMARSARMY_EXT);
		remove_spaces_from_filename(def_mars_army_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_mars_armyfields();
		buffmars_army.assign(header("<mars_army>"));
		make_buffmars_army();
		write_mars_army(def_mars_army_TemplateName);

		show_filename(def_mars_army_TemplateName);
		using_mars_army_template = true;
	}
}

void cb_mars_army_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-mars_army\t*").append(FMARSARMY_EXT).c_str(),
			def_mars_army_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_army_form();
	read_data_file(p);
	using_mars_army_template = false;
	def_mars_army_filename = p;
	show_filename(def_mars_army_filename);
}

void write_mars_army(std::string s)
{
	FILE *filemars_army = fopen(s.c_str(), "w");
	if (!filemars_army) return;
	make_buffmars_army();
	fwrite(buffmars_army.c_str(), buffmars_army.length(), 1, filemars_army);
	fclose(filemars_army);
}

bool cb_mars_army_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(FMARSARMY_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_army_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-mars_army\t*").append(FMARSARMY_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_mars_army_filename = p;
	if (strlen(pext) == 0) def_mars_army_filename.append(FMARSARMY_EXT);

	remove_spaces_from_filename(def_mars_army_filename);

	update_header(NEW);
	update_mars_armyfields();
	buffmars_army.assign(header("<mars_army>"));
	make_buffmars_army();
	write_mars_army(def_mars_army_filename);

	using_mars_army_template = false;
	show_filename(def_mars_army_filename);
	return true;
}

void cb_mars_army_save()
{
	if (base_mars_army_filename == std::string("new").append(FMARSARMY_EXT) || 
		base_mars_army_filename == std::string("default").append(FMARSARMY_EXT) ||
		using_mars_army_template == true) {
		cb_mars_army_save_as();
		return;
	}

	if (check_mars_armyfields()) update_header(CHANGED);
	update_mars_armyfields();
	buffmars_army.assign(header("<mars_army>"));
	make_buffmars_army();
	write_mars_army(def_mars_army_filename);

	using_mars_army_template = false;
}

void cb_mars_army_html()
{
	std::string fname_name = fl_filename_name(def_mars_army_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string mars_army_fname = ICS_dir;
	mars_army_fname.append(fname_name);
	mars_army_fname.append(".html");

	update_mars_armyfields();
	std::string formmars_army = mars_army_html_template;

	replacestr(formmars_army, TITLE, fname_name);

	replacestr(formmars_army, mars_army_prec, s_mars_army_prec );
	replacestr(formmars_army, mars_army_dtg, s_mars_army_dtg );
	replacestr(formmars_army, mars_army_fm, s_mars_army_fm );
	replacestr(formmars_army, mars_army_de, s_mars_army_de );
	replacestr(formmars_army, mars_army_nbr, s_mars_army_nbr );
	replacestr(formmars_army, mars_army_to, s_mars_army_to );

	if (s_mars_army_info.empty())  {
		size_t p = formmars_army.find("INFO");
		size_t p2 = formmars_army.find('\n', p);
		formmars_army.erase(p, p2 - p + 1);
	} else
		replacestr(formmars_army, mars_army_info, s_mars_army_info );

	std::string text = "";
	std::string temp = "";
	if (!s_mars_army_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_army_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_army_text, 69);
	text.append(temp);

	replacestr(formmars_army, mars_army_text, text );

	FILE *filemars_army = fopen(mars_army_fname.c_str(), "w");
	fprintf(filemars_army,"%s", formmars_army.c_str());
	fclose(filemars_army);

	open_url(mars_army_fname.c_str());
}

void cb_mars_army_msg_type()
{
	if (tabs_msg_type->value() == tab_mars_army ) {
		show_filename(def_mars_army_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_mars_army_textout()
{
	std::string mars_army_fname = ICS_dir;
	mars_army_fname.append("mars_army.txt");

	update_mars_armyfields();
	std::string formmars_army = mars_army_text_template;

	replacestr(formmars_army, mars_army_prec, s_mars_army_prec );
	replacestr(formmars_army, mars_army_dtg, s_mars_army_dtg );
	replacestr(formmars_army, mars_army_fm, s_mars_army_fm );
	replacestr(formmars_army, mars_army_de, s_mars_army_de );
	replacestr(formmars_army, mars_army_nbr, s_mars_army_nbr );
	replacestr(formmars_army, mars_army_to, s_mars_army_to );

	if (s_mars_army_info.empty())  {
		size_t p = formmars_army.find("INFO");
		size_t p2 = formmars_army.find('\n', p);
		formmars_army.erase(p, p2 - p + 1);
	} else
		replacestr(formmars_army, mars_army_info, s_mars_army_info );

	std::string text = "";
	std::string temp = "";
	if (!s_mars_army_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_army_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_army_text, 69);
	text.append(temp);

	replacestr(formmars_army, mars_army_text, text );

	FILE *filemars_army = fopen(mars_army_fname.c_str(), "w");
	fprintf(filemars_army,"%s", formmars_army.c_str());
	fclose(filemars_army);

	open_url(mars_army_fname.c_str());
}

