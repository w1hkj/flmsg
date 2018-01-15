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

// plaintext fields

// compatibility fields required to read older data files

string apt_title	= "<tt:";
string apt_to		= "<to:";
string apt_fm		= "<fm:";
string apt_subj		= "<sb:";
string apt_dt		= "<dt:";
string apt_tm		= "<tm:";
string apt_msg		= "<mg:";

FIELD aptfields[] = {
{ apt_title,	"", (void **)&txt_pt_title,	't' },
{ apt_to,		"", (void **)&txt_pt_to,		't' },
{ apt_fm,		"", (void **)&txt_pt_fm,		't' },
{ apt_dt,		"", (void **)&txt_pt_date,		'd' },
{ apt_tm,		"", (void **)&txt_pt_time,		't' },
{ apt_subj,		"", (void **)&txt_pt_subj,		't' },
{ apt_msg,		"", (void **)&txt_pt_msg,		'e' } };

// new string tags & fields
string pt_title	= ":tt:";
string pt_to	= ":to:";
string pt_fm	= ":fm:";
string pt_subj	= ":sb:";
string pt_dt	= ":dt:";
string pt_tm	= ":tm:";
string pt_msg	= ":mg:";

FIELD ptfields[] = {
{ pt_title,	"", (void **)&txt_pt_title,	't' },
{ pt_to,	"", (void **)&txt_pt_to,		't' },
{ pt_fm,	"", (void **)&txt_pt_fm,		't' },
{ pt_dt,	"", (void **)&txt_pt_date,		'd' },
{ pt_tm,	"", (void **)&txt_pt_time,		't' },
{ pt_subj,	"", (void **)&txt_pt_subj,		't' },
{ pt_msg,	"", (void **)&txt_pt_msg,		'e' } };

string ptbuffer;
string def_pt_filename = "";
string base_pt_filename = "";
string def_pt_TemplateName = "";

bool using_pt_template = false;

int num_ptfields = sizeof(ptfields) / sizeof(FIELD);

void cb_set_pt_date()
{
	txt_pt_date->value(szDate(progStatus.dtformat));
}

void cb_set_pt_time()
{
	txt_pt_time->value(szTime(progStatus.UTC));
}

void clear_ptfields()
{
	for (int i = 0; i < num_ptfields; i++)
		ptfields[i].f_data.clear();
}

bool check_ptfields()
{
	for (int i = 0; i < num_ptfields; i++) {
		if (ptfields[i].w_type == 'd') {
			if (ptfields[i].f_data != ((Fl_DateInput *)(*ptfields[i].w))->value()) return true;
		} else if (ptfields[i].w_type == 't') {
			if (ptfields[i].f_data != ((Fl_Input2 *)(*ptfields[i].w))->value()) return true;
		} else if (ptfields[i].w_type == 'e') {
			if (ptfields[i].f_data != ((FTextEdit *)(*ptfields[i].w))->buffer()->text()) return true;
		}
	}
	return false;
}

void update_ptfields()
{
	for (int i = 0; i < num_ptfields; i++) {
		if (ptfields[i].w_type == 'd')
			ptfields[i].f_data = ((Fl_DateInput *)(*ptfields[i].w))->value();
		else if (ptfields[i].w_type == 't')
			ptfields[i].f_data = ((Fl_Input2 *)(*ptfields[i].w))->value();
		else if (ptfields[i].w_type == 'e') {
			ptfields[i].f_data = ((FTextEdit *)(*ptfields[i].w))->buffer()->text();
		}
	}
}

void clear_pt_form()
{
	clear_ptfields();
	ptfields[0].f_data = "General Message";
	txt_pt_title->value(ptfields[0].f_data.c_str());
	txt_pt_to->value("");
	txt_pt_fm->value("");
	txt_pt_subj->value("");
	txt_pt_date->value("");
	txt_pt_time->value("");
	txt_pt_msg->clear();
	update_ptfields();
}

void update_pt_form()
{
	for (int i = 0; i < num_ptfields; i++) {
		if (ptfields[i].w_type == 'd')
			((Fl_DateInput *)(*ptfields[i].w))->value(ptfields[i].f_data.c_str());
		else if (ptfields[i].w_type == 't')
			((Fl_Input2 *)(*ptfields[i].w))->value(ptfields[i].f_data.c_str());
		else {
			((FTextEdit *)(*ptfields[i].w))->clear();
			((FTextEdit *)(*ptfields[i].w))->add(ptfields[i].f_data.c_str());
		}
	}
}

void make_ptbuffer(bool compress = false)
{
	string mbuff;
	mbuff.clear();
	for (int i = 0; i < num_ptfields; i++)
		mbuff.append( lineout( ptfields[i].f_type, ptfields[i].f_data ) );
	if (compress) compress_maybe(mbuff);
	ptbuffer.append(mbuff);
}

void read_ptbuffer(string data)
{
	bool data_ok = false;
	clear_ptfields();
	read_header(data);

	for (int i = 0; i < num_ptfields; i++) {
		ptfields[i].f_data = findstr(data, ptfields[i].f_type);
		if (!ptfields[i].f_data.empty()) data_ok = true;
	}
	if (!data_ok)
		for (int i = 0; i < num_ptfields; i++)
			ptfields[i].f_data = findstr(data, aptfields[i].f_type);
	update_pt_form();

}

void cb_pt_new()
{
	if (check_ptfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_pt_save();
		}
	}
	clear_pt_form();
	clear_header();
	def_pt_filename = ICS_msg_dir;
	def_pt_filename.append("new").append(PTFILE_EXT);
	show_filename(def_pt_filename);
	using_pt_template = false;
}

void cb_pt_import()
{
	fl_alert2("Not implemented");
}

void cb_pt_export()
{
	fl_alert2("Not implemented");
}

void cb_pt_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_pt_form();
	read_ptbuffer(inpbuffer);
	def_pt_filename = ICS_msg_dir;
	def_pt_filename.append(wrapfilename);
	show_filename(def_pt_filename);
	using_pt_template = false;
}

int eval_pt_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_pt_filename).append("]");
	update_ptfields();
	update_header(FROM);
	evalstr.append(header("<plaintext>"));
	ptbuffer.clear();
	make_ptbuffer(true);
	if (ptbuffer.empty()) return 0;
	compress_maybe( ptbuffer );
	evalstr.append( ptbuffer );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_pt_wrap_export()
{
	if (check_ptfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_ptfields();

	if (base_pt_filename == string("new").append(PTFILE_EXT) ||
		base_pt_filename == string("default").append(PTFILE_EXT) )
		if (!cb_pt_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_pt_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		ptbuffer.assign(header("<plaintext>"));
		make_ptbuffer(true);
		export_wrapfile(base_pt_filename, wrapfilename, ptbuffer, pext != WRAP_EXT);

		ptbuffer.assign(header("<plaintext>"));
		make_ptbuffer(false);
		write_pt(def_pt_filename);
	}
}

void cb_pt_wrap_autosend()
{
	if (check_ptfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_ptfields();

	if (base_pt_filename == string("new").append(PTFILE_EXT) ||
		base_pt_filename == string("default").append(PTFILE_EXT) )
		if (!cb_pt_save_as()) return;

	update_header(FROM);
	ptbuffer.assign(header("<plaintext>"));
	make_ptbuffer(true);
	xfr_via_socket(base_pt_filename, ptbuffer);

	ptbuffer.assign(header("<plaintext>"));
	make_ptbuffer(false);
	write_pt(def_pt_filename);
}

void cb_pt_load_template()
{
	string def_pt_filename = def_pt_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			string("Template file\t*").append(PTTEMP_EXT).c_str(),
			def_pt_filename.c_str());
	if (p) {
		clear_pt_form();
		read_data_file(p);
		def_pt_TemplateName = p;
		show_filename(def_pt_TemplateName);
		using_pt_template = true;
	}
}

void cb_pt_save_template()
{
	if (!using_pt_template) {
		cb_pt_save_as_template();
		return;
	}
	string def_pt_filename = def_pt_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			string("Template file\t*").append(PTTEMP_EXT).c_str(),
			def_pt_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_ptfields();
		ptbuffer.assign(header("<plaintext>"));
		make_ptbuffer();
		write_pt(p);
	}
}

void cb_pt_save_as_template()
{
	string def_pt_filename = def_pt_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			string("Template file\t*").append(PTTEMP_EXT).c_str(),
			def_pt_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_pt_TemplateName = p;
		if (strlen(pext) == 0) def_pt_TemplateName.append(PTTEMP_EXT);
		remove_spaces_from_filename(def_pt_TemplateName);

		clear_header();
		update_header(CHANGED);
		ptbuffer.assign(header("<plaintext>"));
		make_ptbuffer();
		write_pt(def_pt_TemplateName);

		show_filename(def_pt_TemplateName);
		using_pt_template = true;
	}
}

void cb_pt_open()
{
	const char *p = FSEL::select(_("Open data file"), "plain_text\t*.p2s",
					def_pt_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_pt_form();
	read_data_file(p);
	using_pt_template = false;
	def_pt_filename = p;
	show_filename(def_pt_filename);
}

void write_pt(string s)
{
	FILE *ptfile = fopen(s.c_str(), "w");
	if (!ptfile) return;

	fwrite(ptbuffer.c_str(), ptbuffer.length(), 1, ptfile);
	fclose(ptfile);
}

bool cb_pt_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(".p2s");
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_pt_filename;

	p = FSEL::saveas(_("Save data file"), "plain_text\t*.p2s",
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_pt_filename = p;
	if (strlen(pext) == 0) def_pt_filename.append(".p2s");

	remove_spaces_from_filename(def_pt_filename);

	update_header(NEW);
	update_ptfields();
	ptbuffer.assign(header("<plaintext>"));
	make_ptbuffer();
	write_pt(def_pt_filename);

	using_pt_template = false;
	show_filename(def_pt_filename);
	return true;
}

void cb_pt_save()
{
	if (base_pt_filename == "new.p2s" || 
		base_pt_filename == "default.p2s" ||
		using_pt_template == true) {
		cb_pt_save_as();
		return;
	}

	if (check_ptfields()) update_header(CHANGED);
	update_ptfields();
	ptbuffer.assign(header("<plaintext>"));
	make_ptbuffer();
	write_pt(def_pt_filename);

	using_pt_template = false;
}

void cb_pt_html()
{
	string pt_name = ICS_dir;
	string html_text = "";
	pt_name.append("plaintext_doc.html");

	update_ptfields();
	string ptform = pt_html_template;

	for (int i = 0; i < num_ptfields; i++) {
		if (ptfields[i].w_type != 'e')
			replacestr( ptform, ptfields[i].f_type, ptfields[i].f_data );
		else {
			html_text = "<pre><big style= font-family: \"Consolas\", \"Monospace\", \"Courier\";\">";
			if (progStatus.autowordwrap)
				html_text.append(wordwrap(ptfields[i].f_data, progStatus.charcount));
			else
				html_text.append(ptfields[i].f_data);
			html_text.append("</big></pre>");
			replacestr( ptform, ptfields[i].f_type, html_text );
		}
	}

	FILE *ptfile = fopen(pt_name.c_str(), "w");
	fprintf(ptfile,"%s", ptform.c_str());
	fclose(ptfile);

	open_url(pt_name.c_str());
}

void cb_pt_msg_type()
{
	if (tabs_msg_type->value() == tab_plaintext ) {
		show_filename(def_pt_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_pt_textout()
{
	string pt_name = ICS_dir;
	pt_name.append("plaintext.txt");

	update_ptfields();
	string ptform = pt_txt_template;

	for (int i = 0; i < num_ptfields; i++)
		replacestr( ptform, ptfields[i].f_type, ptfields[i].f_data);

	FILE *ptfile = fopen(pt_name.c_str(), "w");
	fprintf(ptfile,"%s", ptform.c_str());
	fclose(ptfile);

	open_url(pt_name.c_str());
}
