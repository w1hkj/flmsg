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

std::string h213_buffer;
std::string h213_base_filename = "";
std::string h213_def_filename = "";
std::string h213_def_template_name = "";

bool h213_using_template = false;

std::string h213_tag_fm			= ":1:";
std::string h213_tag_to			= ":2:";
std::string h213_tag_date		= ":3:";
std::string h213_tag_time		= ":4:";
std::string h213_tag_via_phone	= ":5a:";
std::string h213_tag_via_radio	= ":5b:";
std::string h213_tag_via_other	= ":5c:";
std::string h213_tag_reply_yes	= ":6a:";
std::string h213_tag_reply_no	= ":6b:";
std::string h213_tag_reply_to	= ":6c:";
std::string h213_tag_priority	= ":7:";
std::string h213_tag_high		= ":7a:";
std::string h213_tag_medium		= ":7b:";
std::string h213_tag_low			= ":7c:";
std::string h213_tag_msg			= ":8:";
std::string h213_tag_action		= ":9:";
std::string h213_tag_rcvd_by		= ":10:";
std::string h213_tag_time_rcvd	= ":11:";
std::string h213_tag_fwd_to		= ":12:";
std::string h213_tag_comments	= ":13:";
std::string h213_tag_rcvd_by2	= ":14:";
std::string h213_tag_time_rcvd2	= ":15:";
std::string h213_tag_fwd_to2		= ":16:";
std::string h213_tag_comments2	= ":17:";
std::string h213_tag_facility	= ":18:";

FIELD h213_fields[] = {
{ h213_tag_to,			"", (void **)&h213_txt_to,			't' },
{ h213_tag_fm,			"", (void **)&h213_txt_fm,			't' },
{ h213_tag_date,		"", (void **)&h213_txt_date,		'd' },
{ h213_tag_time,		"", (void **)&h213_txt_time,		't' },
{ h213_tag_via_phone,	"", (void **)&h213_btn_phone,		'b' },
{ h213_tag_via_radio,	"", (void **)&h213_btn_radio,		'b' },
{ h213_tag_via_other,	"", (void **)&h213_btn_other,		'b' },
{ h213_tag_reply_yes,	"", (void **)&h213_btn_yes,			'b' },
{ h213_tag_reply_no,	"", (void **)&h213_btn_no,			'b' },
{ h213_tag_reply_to,	"", (void **)&h213_txt_reply_to,	't' },
{ h213_tag_high,		"", (void **)&h213_btn_high,		'b' },
{ h213_tag_medium,		"", (void **)&h213_btn_medium,		'b' },
{ h213_tag_low,			"", (void **)&h213_btn_low,			'b' },
{ h213_tag_msg,			"", (void **)&h213_txt_msg,			'e' },
{ h213_tag_action,		"", (void **)&h213_txt_action,		'e' },
{ h213_tag_rcvd_by,		"", (void **)&h213_txt_rcvd_by,		't' },
{ h213_tag_time_rcvd,	"", (void **)&h213_txt_time_rcvd,	't' },
{ h213_tag_fwd_to,		"", (void **)&h213_txt_fwd_to,		't' },
{ h213_tag_comments,	"", (void **)&h213_txt_comments,	'e' },
{ h213_tag_rcvd_by2,	"", (void **)&h213_txt_rcvd_by2,	't' },
{ h213_tag_time_rcvd2,	"", (void **)&h213_txt_time_rcvd2,	't' },
{ h213_tag_fwd_to2,		"", (void **)&h213_txt_fwd_to2,		't' },
{ h213_tag_comments2,	"", (void **)&h213_txt_comments2,	'e' },
{ h213_tag_facility,	"", (void **)&h213_txt_facility,	't' } };

int h213_numfields = sizeof(h213_fields) / sizeof(FIELD);

void h213_cb_set_date()
{
	h213_txt_date->value(szDate(progStatus.dtformat));
}

void h213_cb_set_time0()
{
	h213_txt_time->value(szTime(progStatus.UTC));
}

void h213_cb_set_time1()
{
	h213_txt_time_rcvd->value(szTime(progStatus.UTC));
}

void h213_cb_set_time2()
{
	h213_txt_time_rcvd2->value(szTime(progStatus.UTC));
}

void h213_clear_fields()
{
	for (int i = 0; i < h213_numfields; i++)
		h213_fields[i].f_data.clear();
}

bool check_hics213fields()
{
	for (int i = 0; i < h213_numfields; i++) {
		if (h213_fields[i].w_type == 'd') {
			if (h213_fields[i].f_data != ((Fl_DateInput *)(*h213_fields[i].w))->value())
				return true;
		} else if (h213_fields[i].w_type == 't') {
			if (h213_fields[i].f_data != ((Fl_Input2 *)(*h213_fields[i].w))->value())
				return true;
		} else if (h213_fields[i].w_type == 'e') {
			if (h213_fields[i].f_data != ((FTextEdit *)(*h213_fields[i].w))->buffer()->text())
				return true;
		} else if (h213_fields[i].w_type == 'b') {
			std::string val = ((Fl_Check_Button *)(*h213_fields[i].w))->value() ? "X" : "";
			if (h213_fields[i].f_data != val)
				return true;
		}
	}
	return false;
}

void h213_update_fields()
{
	for (int i = 0; i < h213_numfields; i++) {
		if (h213_fields[i].w_type == 'd') {
			h213_fields[i].f_data = ((Fl_DateInput *)(*h213_fields[i].w))->value();
		} else if (h213_fields[i].w_type == 't') {
			h213_fields[i].f_data = ((Fl_Input2 *)(*h213_fields[i].w))->value();
		} else if (h213_fields[i].w_type == 'e') {
			h213_fields[i].f_data = ((FTextEdit *)(*h213_fields[i].w))->buffer()->text();
		} else if (h213_fields[i].w_type == 'b') {
			std::string val = ((Fl_Check_Button *)(*h213_fields[i].w))->value() ? "X" : "";
			h213_fields[i].f_data = val;
		}
	}
}

void h213_clear_form()
{
	h213_clear_fields();
	for (int i = 0; i < h213_numfields; i++) {
		if (h213_fields[i].w_type == 'd')
			((Fl_DateInput *)(*h213_fields[i].w))->value("");
		else if (h213_fields[i].w_type == 'b')
			((Fl_Check_Button *)(*h213_fields[i].w))->value(0);
		else if (h213_fields[i].w_type == 't')
			((Fl_Input2 *)(*h213_fields[i].w))->value("");
		else if (h213_fields[i].w_type == 'e')
			((FTextEdit *)(*h213_fields[i].w))->clear();
	}
	h213_update_fields();
}

void h213_update_form()
{
	for (int i = 0; i < h213_numfields; i++) {
		if (h213_fields[i].w_type == 'd')
			((Fl_DateInput *)(*h213_fields[i].w))->value(h213_fields[i].f_data.c_str());
		else if (h213_fields[i].w_type == 'b')
			((Fl_Check_Button *)(*h213_fields[i].w))->value(h213_fields[i].f_data == "X");
		else if (h213_fields[i].w_type == 't')
			((Fl_Input2 *)(*h213_fields[i].w))->value(h213_fields[i].f_data.c_str());
		else if (h213_fields[i].w_type == 'e') {
			((FTextEdit *)(*h213_fields[i].w))->clear();
			((FTextEdit *)(*h213_fields[i].w))->add(h213_fields[i].f_data.c_str());
		}
	}
}

void h213_make_buffer(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	for (int i = 0; i < h213_numfields; i++)
		mbuff.append( lineout( h213_fields[i].f_type, h213_fields[i].f_data ) );
	if (compress) compress_maybe(mbuff);
	h213_buffer.append(mbuff);
}

void h213_read_buffer(std::string data)
{
	h213_clear_fields();
	read_header(data);
	for (int i = 0; i < h213_numfields; i++)
		h213_fields[i].f_data = findstr(data, h213_fields[i].f_type);
	h213_update_form();
}

void h213_cb_new()
{
	if (check_hics213fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			h213_cb_save();
		}
	}
	h213_clear_form();
	clear_header();
	h213_def_filename = ICS_msg_dir;
	h213_def_filename.append("new").append(HF213_EXT);
	h213_using_template = false;
	show_filename(h213_def_filename);
}

void h213_cb_import()
{
	fl_alert2("Not implemented");
}

void h213_cb_export()
{
	fl_alert2("Not implemented");
}

void h213_cb_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	h213_clear_form();
	h213_read_buffer(inpbuffer);
	h213_def_filename = ICS_msg_dir;
	h213_def_filename.append(wrapfilename);
	show_filename(h213_def_filename);
	h213_using_template = false;
}

int eval_h213_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(h213_base_filename).append("]");
	h213_update_fields();
	update_header(FROM);
	evalstr.append(header("<hics213>"));
	h213_buffer.clear();
	h213_make_buffer(true);
	if (h213_buffer.empty()) return 0;
	compress_maybe( h213_buffer );
	evalstr.append( h213_buffer );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void h213_cb_wrap_export()
{
	if (check_hics213fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	h213_update_fields();

	if (h213_base_filename == std::string("new").append(HF213_EXT) ||
		h213_base_filename == std::string("default").append(HF213_EXT) )
		if (!h213_cb_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(h213_base_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		h213_buffer.assign(header("<hics213>"));
		h213_make_buffer(true);
		export_wrapfile(h213_base_filename, wrapfilename, h213_buffer, pext != WRAP_EXT);

		h213_buffer.assign(header("<hics213>"));
		h213_make_buffer(false);
		h213_write(h213_def_filename);
	}
}

void h213_cb_wrap_autosend()
{
	if (check_hics213fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	h213_update_fields();

	if (h213_base_filename == std::string("new").append(HF213_EXT) ||
		h213_base_filename == std::string("default").append(HF213_EXT) )
		if (!h213_cb_save_as()) return;

	update_header(FROM);
	h213_buffer.assign(header("<hics213>"));
	h213_make_buffer(true);
	xfr_via_socket(h213_base_filename, h213_buffer);

	h213_buffer.assign(header("<hics213>"));
	h213_make_buffer(false);
	h213_write(h213_def_filename);
}

void h213_cb_load_template()
{
	std::string h213_def_filename = h213_def_template_name;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(HT213_EXT).c_str(),
			h213_def_filename.c_str());
	if (p) {
		h213_clear_form();
		read_data_file(p);
		h213_def_template_name = p;
		show_filename(h213_def_template_name);
		h213_using_template = true;
	}
}

void h213_cb_save_template()
{
	if (!h213_using_template) {
		cb_save_as_template();
		return;
	}
	std::string h213_def_filename = h213_def_template_name;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(HT213_EXT).c_str(),
			h213_def_filename.c_str());
	if (p) {
		update_header(CHANGED);
		h213_update_fields();
		h213_buffer.assign(header("<hics213>"));
		h213_make_buffer();
		h213_write(p);
	}
}

void h213_cb_save_as_template()
{
	std::string h213_def_filename = h213_def_template_name;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(HT213_EXT).c_str(),
			h213_def_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		h213_def_template_name = p;
		if (strlen(pext) == 0) h213_def_template_name.append(HT213_EXT);
		remove_spaces_from_filename(h213_def_template_name);
		clear_header();
		update_header(CHANGED);
		h213_update_fields();
		h213_buffer.assign(header("<hics213>"));
		h213_make_buffer();
		h213_write(h213_def_template_name);
		show_filename(h213_def_template_name);
		h213_using_template = true;
	}
}

void h213_cb_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			"HICS-213\t*.{H213}",
			h213_def_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	h213_clear_form();
	read_data_file(p);
	h213_using_template = false;
	h213_def_filename = p;
	show_filename(h213_def_filename);
}

void h213_write(std::string s)
{
	FILE *hicsfile = fopen(s.c_str(), "w");
	if (!hicsfile) return;

	fwrite(h213_buffer.c_str(), h213_buffer.length(), 1, hicsfile);
	fclose(hicsfile);
}

bool h213_cb_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
	name.append(HF213_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = h213_def_filename;

	p = FSEL::saveas(_("Save data file"), "HICS-213\t*.{H213}",
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	h213_def_filename = p;
	if (strlen(pext) == 0) h213_def_filename.append(HF213_EXT);

	remove_spaces_from_filename(h213_def_filename);
	h213_update_fields();
	update_header(NEW);
	h213_buffer.assign(header("<hics213>"));
	h213_make_buffer();
	h213_write(h213_def_filename);

	h213_using_template = false;
	show_filename(h213_def_filename);
	return true;
}

void h213_cb_save()
{
	if (h213_base_filename == std::string("new").append(HF213_EXT) ||
		h213_base_filename == std::string("default").append(HF213_EXT) ||
		h213_using_template == true) {
		h213_cb_save_as();
		return;
	}
	if (check_hics213fields()) update_header(CHANGED);
	h213_buffer.assign(header("<hics213>"));
	h213_update_fields();
	h213_make_buffer();
	h213_write(h213_def_filename);
	h213_using_template = false;
}

void h213_cb_html()
{
	std::string fname_name = fl_filename_name(h213_def_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string hicsname = ICS_dir;
	hicsname.append(fname_name);
	hicsname.append(".html");

	std::string html_text = "";

	h213_update_fields();
	std::string form = hics213_html_template;

	std::string temp, temp2;
	for (int i = 0; i < h213_numfields; i++) {
		temp = h213_fields[i].f_type;
		if (temp == h213_tag_msg || temp == h213_tag_action ||
			temp == h213_tag_comments || temp == h213_tag_comments2 ) {
			temp2 = h213_fields[i].f_data;
			if (progStatus.autowordwrap)
				temp2 = wordwrap(h213_fields[i].f_data, progStatus.charcount);
			replacestr( form, h213_fields[i].f_type, temp2 );
		} else
			replacestr( form, h213_fields[i].f_type, h213_fields[i].f_data );
	}

	FILE *hicsfile = fopen(hicsname.c_str(), "w");
	fprintf(hicsfile,"%s", form.c_str());
	fclose(hicsfile);

	open_url(hicsname.c_str());
}

void h213_cb_textout()
{
	std::string hicsname = ICS_dir;
	hicsname.append("hics213.txt");

	h213_update_fields();
	std::string form = hics213_text_template;

	for (int i = 0; i < h213_numfields; i++)
		replacestr( form, h213_fields[i].f_type, h213_fields[i].f_data);

	FILE *hicsfile = fopen(hicsname.c_str(), "w");
	fprintf(hicsfile,"%s", form.c_str());
	fclose(hicsfile);

	open_url(hicsname.c_str());
}
