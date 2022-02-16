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
#include "flmsg_strings.h"

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

std::string cap105_base_filename = "";
std::string cap105_def_filename = "";
std::string cap105_def_template_name = "";

static std::string cap105_buffer;

// cap105 cap105_fields

const char *cap105_s_prec[] = {"ROUTINE","PRIORITY","IMMEDIATE","FLASH"};
const char cap105_prec_items[] = "ROUTINE|PRIORITY|IMMEDIATE|FLASH";

std::string cap105_nbr      = ":msg nbr:";
std::string cap105_prec     = ":prec:";
std::string cap105_dtm      = ":dtm:";
std::string cap105_from     = ":from:";
std::string cap105_to       = ":to:";
std::string cap105_info     = ":info:";
std::string cap105_subj     = ":subj:";
std::string cap105_grpcnt   = ":grpcnt:";
std::string cap105_msg      = ":msgtxt:";
std::string cap105_rcvd_fm  = ":rcvd_fm:";
std::string cap105_sent_to  = ":sent_to:";
std::string cap105_rcvd_dtm = ":rcvd_dtm:";
std::string cap105_sent_dtm = ":sent_dtm:";
std::string cap105_rcvop    = ":rcvop:";
std::string cap105_sendop   = ":sendop:";

//struct FIELD { std::string f_type; std::string f_data; void **w; char w_type; };
FIELD cap105_fields[] = {
{ cap105_nbr,		"", (void **)&cap105_txt_nbr,		't' },	// 0
{ cap105_prec,		"", (void **)&cap105_sel_prec,		's' },	// 1
{ cap105_dtm,		"", (void **)&cap105_txt_dtm,		't' },	// 2
{ cap105_from,		"", (void **)&cap105_txt_from,		't' },	// 3
{ cap105_to,		"", (void **)&cap105_txt_to,		't' },	// 4
{ cap105_info,		"", (void **)&cap105_txt_info,		't' },	// 5
{ cap105_subj,		"", (void **)&cap105_txt_subj,		't' },	// 6
{ cap105_grpcnt,	"", (void **)&cap105_txt_grpcnt,	't' },	// 7
{ cap105_msg,		"", (void **)&cap105_txt_msg,		'e' },	// 8
{ cap105_rcvd_fm,	"", (void **)&cap105_txt_rcvd_fm,	't' },	// 9
{ cap105_sent_to,	"", (void **)&cap105_txt_sent_to,	't' },	// 10
{ cap105_rcvd_dtm,	"", (void **)&cap105_txt_rcvd_dtm,	't' },	// 11
{ cap105_sent_dtm,	"", (void **)&cap105_txt_sent_dtm,	't' },	// 12
{ cap105_rcvop,		"", (void **)&cap105_txt_rcvop,		't' },	// 13
{ cap105_sendop,	"", (void **)&cap105_txt_sendop,	't' },	// 14
};

bool cap105_using_template = false;

int cap105_num_fields = sizeof(cap105_fields) / sizeof(FIELD);

//======================================================================

void cap105_cb_set_dtm()
{
	cap105_txt_dtm->value(szCAPDateTime());
}

void cap105_cb_set_rcvd_dtm()
{
	cap105_txt_rcvd_dtm->value(szCAPDateTime());
}

void cap105_cb_set_sent_dtm()
{
	cap105_txt_sent_dtm->value(szCAPDateTime());
}

void cap105_cb_nbr(Fl_Widget *wdg)
{
	Fl_Input2 *inp = (Fl_Input2 *)wdg;
	std::string s = inp->value();
	for (size_t n = 0; n < s.length(); n++)
		if (!isdigit(s[n])) s.erase(n,1);
	strip_leading_zeros(s);
	inp->value(s.c_str());
}

static char valid_input[] = "0123456789/,; ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

void cap105_cb_filter_input(Fl_Widget *wdg)
{
	Fl_Input2 *inp = (Fl_Input2 *)wdg;
	std::string s = inp->value();
	ucase(s);
	for (size_t n = 0; n < s.length(); n++)
		if (strchr(valid_input, s[n]) == NULL)
			s.erase(n,1);
	inp->value(s.c_str());
}

void cap105_clear_fields()
{
	for (int i = 0; i < cap105_num_fields; i++)
		cap105_fields[i].f_data.clear();
}

static std::string numeric(int n)
{
	static char snum[12];
	snprintf(snum, sizeof(snum), "%d", n);
	return snum;
}

void cap105_set_choices() {
	cap105_sel_prec->clear();
	cap105_sel_prec->add(cap105_prec_items);
	cap105_sel_prec->index(0);
}

bool cap105_check_fields()
{
	for (int i = 0; i < cap105_num_fields; i++) {
		if (cap105_fields[i].w_type == 'd') {
			if (cap105_fields[i].f_data != ((Fl_DateInput *)(*cap105_fields[i].w))->value())
				return true;
		} else if (cap105_fields[i].w_type == 't') {
			if (cap105_fields[i].f_data != ((Fl_Input2 *)(*cap105_fields[i].w))->value())
				return true;
		} else if (cap105_fields[i].w_type == 's') {
			int choice = ((Fl_ListBox *)(*cap105_fields[i].w))->index();
			if (choice >= 0) {
				if (cap105_fields[i].f_data != numeric(choice))
					return true;
			}
		} else if (cap105_fields[i].w_type == 'e') {
			if (cap105_fields[i].f_data != ((FTextEdit *)(*cap105_fields[i].w))->buffer()->text())
				return true;
		} else if (cap105_fields[i].w_type == 'b') {
			std::string val = ((Fl_Button *)(*cap105_fields[i].w))->value() ? "T" : "F";
			if (cap105_fields[i].f_data != val)
				return true;
		}
	}
	return false;
}

void cap105_update_fields()
{
	for (int i = 0; i < cap105_num_fields; i++) {
		if (cap105_fields[i].w_type == 'd') {
			cap105_fields[i].f_data = ((Fl_DateInput *)(*cap105_fields[i].w))->value();
		} else if (cap105_fields[i].w_type == 't') {
			cap105_fields[i].f_data = ((Fl_Input2 *)(*cap105_fields[i].w))->value();
		} else if (cap105_fields[i].w_type == 's') {
			int choice = ((Fl_ListBox *)(*cap105_fields[i].w))->index();
			if (choice >= 0) {
				cap105_fields[i].f_data = numeric(choice);
			}
		} else if (cap105_fields[i].w_type == 'e') {
			cap105_fields[i].f_data = ((FTextEdit *)(*cap105_fields[i].w))->buffer()->text();
		} else if (cap105_fields[i].w_type == 'b') {
			std::string val = ((Fl_Button *)(*cap105_fields[i].w))->value() ? "T" : "F";
			cap105_fields[i].f_data = val;
		}
	}
}

void cap105_clear_form()
{
	cap105_clear_fields();

	if (progStatus.rgnbr_fname)
		cap105_txt_nbr->value(progStatus.rgnbr.c_str());
	else
		cap105_txt_nbr->value("");

	for (int i = 1; i < cap105_num_fields; i++)
		if (cap105_fields[i].w_type == 'd')
			((Fl_DateInput *)(*cap105_fields[i].w))->value("");
		else if (cap105_fields[i].w_type == 't')
			((Fl_Input2 *)(*cap105_fields[i].w))->value("");
		else if (cap105_fields[i].w_type == 's')
			((Fl_ListBox *)(*cap105_fields[i].w))->index(0);
		else if (cap105_fields[i].w_type == 'e')
			((FTextEdit *)(*cap105_fields[i].w))->clear();
		else if (cap105_fields[i].w_type == 'b')
			((Fl_Button *)(*cap105_fields[i].w))->value(0);
	cap105_update_fields();
}

void cap105_update_form()
{
	for (int i = 0; i < cap105_num_fields; i++) {
		if (cap105_fields[i].w_type == 'd')
			((Fl_DateInput *)(*cap105_fields[i].w))->value(cap105_fields[i].f_data.c_str());
		else if (cap105_fields[i].w_type == 't')
			((Fl_Input2 *)(*cap105_fields[i].w))->value(cap105_fields[i].f_data.c_str());
		else if (cap105_fields[i].w_type == 's')
			((Fl_ListBox *)(*cap105_fields[i].w))->index(atoi(cap105_fields[i].f_data.c_str()));
		else if (cap105_fields[i].w_type == 'e') {
			((FTextEdit *)(*cap105_fields[i].w))->clear();
			((FTextEdit *)(*cap105_fields[i].w))->add(cap105_fields[i].f_data.c_str());
		} else if (cap105_fields[i].w_type == 'b')
			((Fl_Button *)(*cap105_fields[i].w))->value(cap105_fields[i].f_data == "T" ? 1 : 0);
	}
}

void cap105_make_buffer(bool compress)
{
	std::string mbuff;
	mbuff.clear();
	for (int i = 0; i < cap105_num_fields; i++)
		mbuff.append( lineout( cap105_fields[i].f_type, cap105_fields[i].f_data ) );
	if (compress) compress_maybe(mbuff);
	cap105_buffer.append(mbuff);
}

void cap105_read_buffer(std::string data)
{
	clear_fields();
	read_header(data);

	for (int i = 0; i < cap105_num_fields; i++)
		cap105_fields[i].f_data = findstr(data, cap105_fields[i].f_type);

	cap105_update_form();
}

void cap105_cb_new()
{
	if (cap105_check_fields()) {
		if (fl_choice2(xMODIFIED, xNO, xYES, NULL) == 1) {
			update_header(CHANGED);
			cap105_cb_save();
		}
	}
	cap105_update_fields();
	cap105_clear_form();
	clear_header();
	cap105_def_filename = ICS_msg_dir;
	cap105_def_filename.append(xNEW).append(CAP105_FILE_EXT);
	cap105_using_template = false;
	show_filename(cap105_def_filename);
}

void cap105_cb_import()
{
	fl_alert2(xNOTIMPLEMENTED);
}

void cap105_cb_export()
{
	fl_alert2(xNOTIMPLEMENTED);
}

void cap105_cb_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	cap105_clear_form();
	cap105_read_buffer(inpbuffer);
	cap105_def_filename = ICS_msg_dir;
	cap105_def_filename.append(wrapfilename);
	show_filename(cap105_def_filename);
	cap105_using_template = false;
}

int eval_cap105_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(cap105_base_filename).append("]");
	cap105_update_fields();
	update_header(FROM);
	evalstr.append(header("<cap105>"));
	cap105_buffer.clear();
	cap105_make_buffer(true);
	if (cap105_buffer.empty()) return 0;
	evalstr.append( cap105_buffer );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cap105_cb_wrap_export()
{
	if (cap105_check_fields()) {
		if (fl_choice2(xMODIFIED, xNO, xYES, NULL) == 0)
			return;
		update_header(CHANGED);
	}
	cap105_update_fields();

	if (cap105_base_filename == std::string(xNEW).append(CAP105_FILE_EXT) || 
		cap105_base_filename == std::string(xDEFAULT).append(CAP105_FILE_EXT) )
		if (!cap105_cb_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(cap105_base_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			xSAVEASWRAP,
			xWRAPFILE,
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		cap105_buffer.assign(header("<cap105>"));
		cap105_make_buffer(true);
		export_wrapfile(cap105_base_filename, wrapfilename, cap105_buffer, pext != WRAP_EXT);

		cap105_buffer.assign(header("<cap105>"));
		cap105_make_buffer(false);
		cap105_write(cap105_def_filename);
	}
}

void cap105_cb_wrap_autosend()
{
	if (cap105_check_fields()) {
		if (fl_choice2(xMODIFIED, xNO, xYES, NULL) == 0)
			return;
		update_header(CHANGED);
	}
	cap105_update_fields();

	if (cap105_base_filename == std::string(xNEW).append(CAP105_FILE_EXT) || 
		cap105_base_filename == std::string(xDEFAULT).append(CAP105_FILE_EXT) )
		if (!cap105_cb_save_as()) return;

	update_header(FROM);
	cap105_buffer.assign(header("<cap105>"));
	cap105_make_buffer(true);
	xfr_via_socket(cap105_base_filename, cap105_buffer);

	cap105_buffer.assign(header("<cap105>"));
	cap105_make_buffer(false);
	cap105_write(cap105_def_filename);
}

void cap105_cb_load_template()
{
	std::string cap105_def_filename = cap105_def_template_name;
	const char *p = FSEL::select(
			xOPENTEMPLATE,
			std::string(xTEMPLATEFILE).append(CAP105_TEMP_EXT).c_str(),
			cap105_def_filename.c_str());
	if (p) {
		cap105_clear_form();
		read_data_file(p);
		cap105_def_template_name = p;
		show_filename(cap105_def_template_name);
		cap105_using_template = true;
	}
}

void cap105_cb_save_template()
{
	if (!cap105_using_template) {
		cap105_cb_save_as_template();
		return;
	}
	std::string cap105_def_filename = cap105_def_template_name;
	const char *p = FSEL::saveas(
			xSAVEASTEMPLATE,
			std::string(xTEMPLATEFILE).append(CAP105_TEMP_EXT).c_str(),
			cap105_def_filename.c_str());
	if (p) {
		update_header(CHANGED);
		cap105_update_fields();
		cap105_buffer.assign(header("<cap105>"));
		cap105_make_buffer();
		cap105_write(p);
	}
}

void cap105_cb_save_as_template()
{
	std::string cap105_def_filename = cap105_def_template_name;
	const char *p = FSEL::saveas(
			xSAVEASTEMPLATE,
			std::string(xTEMPLATEFILE).append(CAP105_TEMP_EXT).c_str(),
			cap105_def_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		cap105_def_template_name = p;
		if (strlen(pext) == 0) cap105_def_template_name.append(CAP105_TEMP_EXT);
		remove_spaces_from_filename(cap105_def_template_name);

		clear_header();
		update_header(CHANGED);
		cap105_update_fields();
		cap105_buffer.assign(header("<cap105>"));
		cap105_make_buffer();
		cap105_write(cap105_def_template_name);

		show_filename(cap105_def_template_name);
		cap105_using_template = true;
	}
}

void cap105_cb_open()
{
	const char *p = FSEL::select(
			_(xOPENDATAFILE), 
			std::string("cap105\t*").append(CAP105_FILE_EXT).c_str(),
			cap105_def_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	cap105_clear_form();
	read_data_file(p);
	cap105_using_template = false;
	cap105_def_filename = p;
	show_filename(cap105_def_filename);
}

void cap105_write(std::string s)
{
	FILE *cap105_file = fopen(s.c_str(), "w");
	if (!cap105_file) return;

	fwrite(cap105_buffer.c_str(), cap105_buffer.length(), 1, cap105_file);
	fclose(cap105_file);
}

bool cap105_cb_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(CAP105_FILE_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = cap105_def_filename;

	p = FSEL::saveas(_(xSAVEDATAFILE), 
				std::string("cap105\t*").append(CAP105_FILE_EXT).c_str(),
				newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.rgnbr_fname) {
		int n = atoi(progStatus.rgnbr.c_str());
		n++;
		char szn[12];
		snprintf(szn, sizeof(szn), "%d", n);
		progStatus.rgnbr = szn;
		txt_rgnbr->value(szn);
		txt_rgnbr->redraw();
	} else if (progStatus.sernbr_fname)
		update_sernbr();

	const char *pext = fl_filename_ext(p);
	cap105_def_filename = p;
	if (strlen(pext) == 0) cap105_def_filename.append(CAP105_FILE_EXT);

	remove_spaces_from_filename(cap105_def_filename);

	update_header(NEW);
	cap105_update_fields();
	cap105_buffer.assign(header("<cap105>"));
	cap105_make_buffer();
	cap105_write(cap105_def_filename);

	cap105_using_template = false;
	show_filename(cap105_def_filename);
	return true;
}

void cap105_cb_save()
{
	if (cap105_base_filename == std::string(xNEW).append(CAP105_FILE_EXT) || 
		cap105_base_filename == std::string(xDEFAULT).append(CAP105_FILE_EXT) ||
		cap105_using_template == true) {
		cap105_cb_save_as();
		return;
	}

	if (cap105_check_fields()) update_header(CHANGED);
	cap105_update_fields();
	cap105_buffer.assign(header("<cap105>"));
	cap105_make_buffer();
	cap105_write(cap105_def_filename);

	cap105_using_template = false;
}

/*
const char *cap105_punctuation[] = {
". ", " X ",
",", " COMMA ",
"?", " QUERY ",
"\\", " BACKSLASH ",
"://", " COLON SLASH SLASH ",
"~", " TILDE ",
"_", " UNDERSCORE ",
"@", " AT ",
"#", " POUNDSIGN ",
"\"", " QUOTE ",
"\'", "",
 0, 0 };
*/

void cap105_cb_check()
{
	std::string temp = cap105_txt_msg->buffer()->text();
	if (temp.empty()) {
		cap105_txt_grpcnt->value("");
		cap105_btn_check->labelcolor(FL_BLACK);
		cap105_btn_check->redraw_label();
		return;
	}

	// convert to uppercase
	for (size_t n = 0; n < temp.length(); n++)
		temp[n] = toupper(temp[n]);
	// convert tabs to 5 spaces
	size_t pos = std::string::npos;
	while ((pos = temp.find("\t")) != std::string::npos)
		temp.replace(pos, 1, "     ");
	// return converted text to editor
	cap105_txt_msg->clear();
	cap105_txt_msg->addstr(temp.c_str());

// compute word count
// remove any user inserted end-of-lines
	while ((pos = temp.find('\n')) != std::string::npos) temp[pos] = ' ';
// only single spaces no trailing spaces, no leading spaces
	while ((pos = temp.find("  ")) != std::string::npos) temp.erase(pos,1);
	while (temp[temp.length() -1] == ' ') temp.erase(temp.length()-1, 1);
	if (temp[0] == ' ') temp.erase(0,1);
// count number of words in textcap105_def_filename
	int numwords = 0;
	if (temp.length()) {
		pos = 0;
		numwords = 1;
		while ((pos = temp.find(" ", pos + 1)) != std::string::npos) numwords++;
	}

/*
	// no more than 5 words to a line
	if (numwords > progStatus.wpl) {
		int wc = numwords;
		size_t pos = 0;
		while (wc > progStatus.wpl) {
			for (int i = 0; i < progStatus.wpl; i++) pos = temp.find(' ', pos + 1);
			temp[pos] = '\n';
			wc -= progStatus.wpl;
		}
	}
*/

	char snum[15];
	snprintf(snum, sizeof(snum), "%d", numwords);
	cap105_grpcnt = snum;
	cap105_txt_grpcnt->value(snum);
	cap105_update_fields();
	cap105_btn_check->labelcolor(FL_BLACK);
	cap105_btn_check->redraw_label();
}

void cap105_cb_html()
{
	std::string cap105_name;
	std::string html_text;
	unsigned int nbr;
	cap105_name = ICS_dir;
	cap105_name.append("cap105.html");

	cap105_update_fields();
	cap105_cb_check();
	std::string form = cap105_html_template;

std::string pg = ":pg:";
std::string pgnr = ":npgs:";
std::string pgone = "1";
	replacestr( form, pg, pgone);
	replacestr( form, pgnr, pgone);
	for (int i = 0; i < cap105_num_fields; i++) {
		if (cap105_fields[i].f_type == cap105_prec) {
			sscanf(cap105_fields[i].f_data.c_str(), "%u", &nbr);
			if (nbr >= 0 && nbr < (sizeof(cap105_s_prec) / sizeof(*cap105_s_prec)))
				html_text = cap105_s_prec[nbr];
			else
				html_text = "";
			replacestr( form, cap105_fields[i].f_type, html_text );
		} else if (cap105_fields[i].w_type == 'b') {
			replacestr( form, cap105_fields[i].f_type, cap105_fields[i].f_data == "T" ? yes : no);
		} else if (cap105_fields[i].w_type == 'e') {
			std::string temp = cap105_fields[i].f_data;
			size_t p = 0;
			while ( (p = temp.find("\n")) != std::string::npos)
				temp.replace(p, 1, "<br>");
			replacestr( form, cap105_fields[i].f_type, temp);
		} else
			replacestr( form, cap105_fields[i].f_type, cap105_fields[i].f_data );
	}

	std::string rxstr = "";
	rxstr.append(progStatus.my_call).append(" ").append(progStatus.my_tel);
	rxstr.append("<br>").append(progStatus.my_name);
	rxstr.append("<br>").append(progStatus.my_addr);
	rxstr.append("<br>").append(progStatus.my_city);
	html_text = ":rx:";
	replacestr( form, html_text, rxstr);

	html_text = ":exp:";
	std::string arlmsgs = "";
	if (progStatus.arl_desc)
		arlmsgs = expand_arl(cap105_fields[10].f_data);
	replacestr( form, html_text, arlmsgs);

	FILE *cap105_file = fopen(cap105_name.c_str(), "w");
	fprintf(cap105_file,"%s", form.c_str());
	fclose(cap105_file);

	open_url(cap105_name.c_str());
}

void cap105_cb_textout()
{
	std::string cap105_name;
	std::string lines;
	std::string str;
	int nbr = 0;//, fn;
	cap105_name = ICS_dir;
	cap105_name.append("cap105.txt");

	cap105_update_fields();
	cap105_cb_check();

	std::string form = cap105_txt_template;

	for (int i = 0; i < cap105_num_fields; i++) {
		str.clear();
		if (cap105_fields[i].f_type == cap105_prec) {
			sscanf(cap105_fields[i].f_data.c_str(), "%d", &nbr);
			str = cap105_s_prec[nbr];
			if (str.find("EMERGENCY") == std::string::npos)
				str = str[0];
			replacestr( form, cap105_fields[i].f_type, str);
		} else {
			str = cap105_fields[i].f_data;
//			strip_lfs(str);
			replacestr( form, cap105_fields[i].f_type, str);
		}
	}

	FILE *cap105_file = fopen(cap105_name.c_str(), "w");
	fprintf(cap105_file,"%s", form.c_str());
	fclose(cap105_file);
	open_url(cap105_name.c_str());
}

