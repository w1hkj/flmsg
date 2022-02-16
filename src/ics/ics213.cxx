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

// ICS213 fields
// compatibility fields required to read older data files

std::string a_213_inc	= "<inc:";
std::string a_213_to		= "<to:";
std::string a_213_fm		= "<fm:";
std::string a_213_p1		= "<p1:";
std::string a_213_p2		= "<p2:";
std::string a_213_subj	= "<sb:";
std::string a_213_d1		= "<d1:";
std::string a_213_t1		= "<t1:";
std::string a_213_msg	= "<mg:";
std::string a_213_s1		= "<s1:";
std::string a_213_p3		= "<p3:";
std::string a_213_reply	= "<rp:";
std::string a_213_d2		= "<d2:";
std::string a_213_t2		= "<t2:";
std::string a_213_s2		= "<s2:";
std::string a_213_p4		= "<p4:";

FIELD afields[] = {
{ a_213_inc,	"", (void **)&txt_213_inc,		't' },
{ a_213_to,		"", (void **)&txt_213_to,		't' },
{ a_213_p1,		"", (void **)&txt_213_p1,		't' },
{ a_213_fm,		"", (void **)&txt_213_fm,		't' },
{ a_213_p2,		"", (void **)&txt_213_p2,		't' },
{ a_213_d1,		"", (void **)&txt_213_d1,		'd' },
{ a_213_t1,		"", (void **)&txt_213_t1,		't' },
{ a_213_subj,	"", (void **)&txt_213_subj,		't' },
{ a_213_s1,		"", (void **)&txt_213_s1,		't' },
{ a_213_p3,		"", (void **)&txt_213_p3,		't' },
{ a_213_s2,		"", (void **)&txt_213_s2,		't' },
{ a_213_p4,		"", (void **)&txt_213_p4,		't' },
{ a_213_d2,		"", (void **)&txt_213_d2,		'd' },
{ a_213_t2,		"", (void **)&txt_213_t2,		't' },
{ a_213_msg,	"", (void **)&txt_213_msg,		'e' },
{ a_213_reply,	"", (void **)&txt_213_reply,	'e' } };

std::string _213_inc = ":inc:";
std::string _213_to = ":to:";
std::string _213_fm = ":fm:";
std::string _213_p1 = ":p1:";
std::string _213_p2 = ":p2:";
std::string _213_subj = ":sb:";
std::string _213_d1 = ":d1:";
std::string _213_t1 = ":t1:";
std::string _213_msg = ":mg:";
std::string _213_s1 = ":s1:";
std::string _213_p3 = ":p3:";
std::string _213_reply = ":rp:";
std::string _213_d2 = ":d2:";
std::string _213_t2 = ":t2:";
std::string _213_s2 = ":s2:";
std::string _213_p4 = ":p4:";

std::string ICS_213_msg = "";
std::string ICS_213_reply = "";
std::string buffer;

FIELD fields[] = {
{ _213_inc,		"", (void **)&txt_213_inc,		't' },
{ _213_to,		"", (void **)&txt_213_to,		't' },
{ _213_p1,		"", (void **)&txt_213_p1,		't' },
{ _213_fm,		"", (void **)&txt_213_fm,		't' },
{ _213_p2,		"", (void **)&txt_213_p2,		't' },
{ _213_d1,		"", (void **)&txt_213_d1,		'd' },
{ _213_t1,		"", (void **)&txt_213_t1,		't' },
{ _213_subj,	"", (void **)&txt_213_subj,		't' },
{ _213_s1,		"", (void **)&txt_213_s1,		't' },
{ _213_p3,		"", (void **)&txt_213_p3,		't' },
{ _213_s2,		"", (void **)&txt_213_s2,		't' },
{ _213_p4,		"", (void **)&txt_213_p4,		't' },
{ _213_d2,		"", (void **)&txt_213_d2,		'd' },
{ _213_t2,		"", (void **)&txt_213_t2,		't' },
{ _213_msg,		"", (void **)&txt_213_msg,		'e' },
{ _213_reply,	"", (void **)&txt_213_reply,	'e' } };

bool using_213Template = false;

std::string base_213_filename = "";
std::string def_213_filename = "";
std::string def_213_TemplateName = "";

int numfields = sizeof(fields) / sizeof(FIELD);

void cb_SetDate1()
{
	txt_213_d1->value(szDate(progStatus.dtformat));
}

void cb_SetDate2()
{
	txt_213_d2->value(szDate(progStatus.dtformat));
}

void cb_SetTime1()
{
	txt_213_t1->value(szTime(progStatus.UTC));
}

void cb_SetTime2()
{
	txt_213_t2->value(szTime(progStatus.UTC));
}

void clear_fields()
{
	for (int i = 0; i < numfields; i++)
		fields[i].f_data.clear();
}

bool check_fields()
{
	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type == 'd') {
			if (fields[i].f_data != ((Fl_DateInput *)(*fields[i].w))->value())
				return true;
		} else if (fields[i].w_type == 't') {
			if (fields[i].f_data != ((Fl_Input2 *)(*fields[i].w))->value())
				return true;
		} else if (fields[i].w_type == 'e') {
			if (fields[i].f_data!= ((FTextEdit *)(*fields[i].w))->buffer()->text())
				return true;
		}
	}
	return false;
}

void update_fields()
{
	bool changed = false;
	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type == 'd') {
			if (fields[i].f_data != ((Fl_DateInput *)(*fields[i].w))->value()) {
				changed = true;;
				fields[i].f_data = ((Fl_DateInput *)(*fields[i].w))->value();
			}
		} else if (fields[i].w_type == 't') {
			if (fields[i].f_data != ((Fl_Input2 *)(*fields[i].w))->value()) {
				changed = true;;
				fields[i].f_data = ((Fl_Input2 *)(*fields[i].w))->value();
			}
		} else if (fields[i].w_type == 'e') {
			if (fields[i].f_data!= ((FTextEdit *)(*fields[i].w))->buffer()->text()) {
				changed = true;;
				fields[i].f_data = ((FTextEdit *)(*fields[i].w))->buffer()->text();
			}
		}
	}
	if (changed) update_header(CHANGED);
}

void clear_213_form()
{
	clear_fields();
	txt_213_inc->value("");
	txt_213_to->value("");
	txt_213_p1->value("");
	txt_213_fm->value("");
	txt_213_p2->value("");
	txt_213_subj->value("");
	txt_213_d1->value("");
	txt_213_t1->value("");
	txt_213_msg->clear();
	txt_213_s1->value("");
	txt_213_p3->value("");
	txt_213_reply->clear();
	txt_213_s2->value("");
	txt_213_d2->value("");
	txt_213_t2->value("");
	txt_213_p4->value("");
	update_fields();
}

void update_form213()
{
	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type == 'd')
			((Fl_DateInput *)(*fields[i].w))->value(fields[i].f_data.c_str());
		else if (fields[i].w_type == 't')
			((Fl_Input2 *)(*fields[i].w))->value(fields[i].f_data.c_str());
		else if (fields[i].w_type == 'e') {
			((FTextEdit *)(*fields[i].w))->clear();
			((FTextEdit *)(*fields[i].w))->add(fields[i].f_data.c_str());
		}
	}
}

void make_buffer(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	for (int i = 0; i < numfields; i++)
		mbuff.append( lineout( fields[i].f_type, fields[i].f_data ) );
	if (compress) compress_maybe(mbuff);
	buffer.append(mbuff);
}

void read_213_buffer(std::string data)
{
	bool data_ok = false;
	clear_fields();
	read_header(data);
	for (int i = 0; i < numfields; i++) {
		fields[i].f_data = findstr(data, fields[i].f_type);
		if (!fields[i].f_data.empty()) data_ok = true;
	}
	if (!data_ok)
		for (int i = 0; i < numfields; i++)
			fields[i].f_data = findstr(data, afields[i].f_type);

	update_form213();
}

void cb_213_new()
{
	if (check_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_213_save();
		}
	}
	clear_213_form();
	clear_header();
	def_213_filename = ICS_msg_dir;
	def_213_filename.append("new").append(F213_EXT);
	using_213Template = false;
	show_filename(def_213_filename);
}

void cb_213_import()
{
	std::string def_213_filename = ICS_dir;
	def_213_filename.append("DEFAULT.XML");
	const char *p = FSEL::select(
		"Open Qforms xml file",
		"Qforms xml\t*.{xml,XML}",
		def_213_filename.c_str());
	if (p){
		clear_213_form();
		clear_header();
		qform_ics_import(p);
		using_213Template = false;
	}
}

void cb_213_export()
{
	std::string def_213_filename = ICS_dir;
	def_213_filename.append(base_213_filename);
	def_213_filename.append(".XML");
	const char *p = FSEL::saveas(
			"Open Qforms xml file",
			"Qforms xml\t*.{xml,XML}",
			def_213_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_213_filename = p;
		update_fields();
		if (strlen(pext) == 0) def_213_filename.append(".XML");
		qform_ics_export(def_213_filename);
	}
}

void cb_213_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_213_form();
	read_213_buffer(inpbuffer);
	def_213_filename = ICS_msg_dir;
	def_213_filename.append(wrapfilename);
	using_213Template = false;
	show_filename(def_213_filename);
}

int eval_213_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_213_filename).append("]");
	update_fields();
	update_header(FROM);
	evalstr.append(header("<ics213>"));
	buffer.clear();
	make_buffer(true);
	if (buffer.empty()) return 0;
	compress_maybe( buffer );
	evalstr.append( buffer );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_213_wrap_export()
{
	if (check_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}

	if (base_213_filename == std::string("new").append(F213_EXT) ||
		base_213_filename == std::string("default").append(F213_EXT) )
		if (!cb_213_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_213_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		update_fields();
		buffer.assign(header("<ics213>"));
		make_buffer(true);
		export_wrapfile(base_213_filename, wrapfilename, buffer, pext != WRAP_EXT);

		buffer.assign(header("<ics213>"));
		make_buffer(false);
		write_213(def_213_filename);
	}
}

void cb_213_wrap_autosend()
{
	if (check_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}

	if (base_213_filename == std::string("new").append(F213_EXT) ||
		base_213_filename == std::string("default").append(F213_EXT) )
		if (!cb_213_save_as()) return;

	update_header(FROM);
	update_fields();
	buffer.assign(header("<ics213>"));
	make_buffer(true);
	xfr_via_socket(base_213_filename, buffer);

	buffer.assign(header("<ics213>"));
	make_buffer(false);
	write_213(def_213_filename);
}

void cb_213_load_template()
{
	std::string def_213_filename = def_213_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(T213_EXT).c_str(),
			def_213_filename.c_str());
	if (p) {
		clear_213_form();
		read_data_file(p);
		def_213_TemplateName = p;
		show_filename(def_213_TemplateName);
		using_213Template = true;
	}
}

void cb_213_save_template()
{
	if (!using_213Template) {
		cb_save_as_template();
		return;
	}
	std::string def_213_filename = def_213_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(T213_EXT).c_str(),
			def_213_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_fields();
		buffer.assign(header("<ics213>"));
		make_buffer();
		write_213(p);
	}
}

void cb_213_save_as_template()
{
	std::string def_213_filename = def_213_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(T213_EXT).c_str(),
			def_213_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_213_TemplateName = p;
		if (strlen(pext) == 0) def_213_TemplateName.append(T213_EXT);
		remove_spaces_from_filename(def_213_TemplateName);
		clear_header();
		update_header(CHANGED);
		update_fields();
		buffer.assign(header("<ics213>"));
		make_buffer();
		write_213(def_213_TemplateName);
		show_filename(def_213_TemplateName);
		using_213Template = true;
	}
}

void cb_213_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-213\t*.{213,f2s}",
					def_213_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_213_form();
	read_data_file(p);
	using_213Template = false;
	def_213_filename = p;
	show_filename(def_213_filename);
}

void write_213(std::string s)
{
	FILE *icsfile = fopen(s.c_str(), "w");
	if (!icsfile) return;

	fwrite(buffer.c_str(), buffer.length(), 1, icsfile);
	fclose(icsfile);
}

bool cb_213_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
	name.append(F213_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_213_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-213\t*.{213T,f2t}",
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_213_filename = p;
	if (strlen(pext) == 0) def_213_filename.append(F213_EXT);

	remove_spaces_from_filename(def_213_filename);
	update_header(NEW);
	update_fields();
	buffer.assign(header("<ics213>"));
	make_buffer();
	write_213(def_213_filename);

	using_213Template = false;
	show_filename(def_213_filename);
	return true;
}

void cb_213_save()
{
	if (base_213_filename == std::string("new").append(F213_EXT) || 
		base_213_filename == std::string("default").append(F213_EXT) ||
		using_213Template == true) {
		cb_213_save_as();
		return;
	}
	if (check_fields()) update_header(CHANGED);
	update_fields();
	buffer.assign(header("<ics213>"));
	make_buffer();
	write_213(def_213_filename);
	using_213Template = false;
}

void cb_213_html()
{
	std::string fname_name = fl_filename_name(def_213_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string icsname = ICS_dir;
	icsname.append(fname_name);
	icsname.append(".html");

	std::string html_text = "";

	update_fields();
	std::string form = ics213_html_template;

	replacestr(form, TITLE, fname_name);
	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type != 'e')
			replacestr( form, fields[i].f_type, fields[i].f_data );
		else {
			std::string ww = wordwrap(fields[i].f_data, progStatus.charcount);
			int lfcount = 0;
			size_t pos = 0;
			while ((pos = ww.find("\n", pos)) != std::string::npos){
				lfcount++; pos++;
			}
			if (lfcount < 10) for (int i = 0; i < (10 - lfcount); i++) ww.append("\n");
			html_text.assign("<pre>");
			html_text.append(ww);
			html_text.append("</pre>");
			replacestr( form, fields[i].f_type, html_text );
		}
	}

	for (int i = 0; i < numfields; i++)
		replacestr( form, fields[i].f_type, fields[i].f_data );

	FILE *icsfile = fopen(icsname.c_str(), "w");
	fprintf(icsfile,"%s", form.c_str());
	fclose(icsfile);

	open_url(icsname.c_str());
}

void cb_213_textout()
{
	std::string icsname = ICS_dir;
	icsname.append("ics213.txt");

	update_fields();
	std::string form = ics213_text_template;

	for (int i = 0; i < numfields; i++)
		replacestr( form, fields[i].f_type, fields[i].f_data);

	FILE *icsfile = fopen(icsname.c_str(), "w");
	fprintf(icsfile,"%s", form.c_str());
	fclose(icsfile);

	open_url(icsname.c_str());
}
