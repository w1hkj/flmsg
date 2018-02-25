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

#include "flmsg_strings.h"

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
#include "icons.h"

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

// blankform fields

string blankbuffer;
string def_blank_filename = "";
string base_blank_filename = "";
string def_blank_TemplateName = "";

string blank_msg = ":mg:";
string ablank_msg = "<mg:";
string blank_field;

bool using_blank_template = false;

void clear_blankfields()
{
	blank_field.clear();
}

bool check_blankfields()
{
	return (blank_field != txt_blank_msg->buffer()->text());
}

void update_blankfields()
{
	blank_field = txt_blank_msg->buffer()->text();
}

void clear_blank_form()
{
	clear_blankfields();
	txt_blank_msg->clear();
}

void update_blankform()
{
	txt_blank_msg->clear();
	txt_blank_msg->add(blank_field.c_str());
}

void read_blankbuffer(string data)
{
	clear_blankfields();
	read_header(data);
	blank_field = findstr(data, blank_msg);
	if (blank_field.empty())
		blank_field = findstr(data, ablank_msg); // test for old style data file
	update_blankform();
}

void cb_blank_new()
{
	if (check_blankfields()) {
		if (fl_choice2(xMODIFIED, xNO, xYES, NULL) == 1) {
			update_header(CHANGED);
			cb_blank_save();
		}
	}
	clear_blank_form();
	clear_header();
	def_blank_filename = ICS_msg_dir;
	def_blank_filename.append(xNEW).append(BLANKFILE_EXT);
	show_filename(def_blank_filename);
	using_blank_template = false;
}

void cb_blank_import()
{
	fl_alert2("Not implemented");
}

void cb_blank_export()
{
	fl_alert2("Not implemented");
}

void cb_blank_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_blank_form();
	read_blankbuffer(inpbuffer);
	def_blank_filename = ICS_msg_dir;
	def_blank_filename.append(wrapfilename);
	show_filename(def_blank_filename);
	using_blank_template = false;
}

int eval_blank_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_blank_filename).append("]");
	update_blankfields();
	update_header(FROM);
	evalstr.append(header("<blankform>"));
	string outbuf = lineout( blank_msg, blank_field );
	if (outbuf.empty()) return 0;
	compress_maybe( outbuf );
	evalstr.append( outbuf );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_blank_wrap_export()
{
	if (check_blankfields()) {
		if (fl_choice2(xMODIFIED, xNO, xYES, NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_blankfields();
	if (blank_field.empty()) return;

	if (base_blank_filename == string(xNEW).append(BLANKFILE_EXT) || 
		base_blank_filename == string(xDEFAULT).append(BLANKFILE_EXT) )
		if (!cb_blank_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_blank_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			xSAVEASWRAP,
			xWRAPFILE,
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		blankbuffer.assign(header("<blankform>"));
		string outbuf = lineout( blank_msg, blank_field );
		compress_maybe( outbuf );
		blankbuffer.append( outbuf );
		export_wrapfile(base_blank_filename, wrapfilename, blankbuffer, pext != WRAP_EXT);

		blankbuffer.assign(header("<blankform>")).append(lineout( blank_msg, blank_field ));
		write_blank(def_blank_filename);
	}
}

void cb_blank_wrap_autosend()
{
	if (check_blankfields()) {
		if (fl_choice2(xMODIFIED, xNO, xYES, NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_blankfields();
	if (blank_field.empty()) return;

	if (base_blank_filename == string(xNEW).append(BLANKFILE_EXT) || 
		base_blank_filename == string(xDEFAULT).append(BLANKFILE_EXT) )
		if (!cb_blank_save_as()) return;

	update_header(FROM);
	blankbuffer.assign(header("<blankform>"));
	string outbuf = lineout( blank_msg, blank_field );
	compress_maybe( outbuf );
	blankbuffer.append( outbuf );
	xfr_via_socket(base_blank_filename, blankbuffer);

	blankbuffer.assign(header("<blankform>")).append(lineout( blank_msg, blank_field ));
	write_blank(def_blank_filename);
}

void cb_blank_load_template()
{
	string def_blank_filename = def_blank_TemplateName;
	const char *p = FSEL::select(
			xOPENTEMPLATE,
			string(xTEMPLATEFILE).append(BLANKTEMP_EXT).c_str(),
			def_blank_filename.c_str());
	if (p) {
		clear_blank_form();
		read_data_file(p);
		def_blank_TemplateName = p;
		show_filename(def_blank_TemplateName);
		using_blank_template = true;
	}
}

void cb_blank_save_template()
{
	if (!using_blank_template) {
		cb_blank_save_as_template();
		return;
	}
	string def_blank_filename = def_blank_TemplateName;
	const char *p = FSEL::saveas(
			xSAVEASTEMPLATE,
			string(xTEMPLATEFILE).append(BLANKTEMP_EXT).c_str(),
			def_blank_filename.c_str());
	if (p) {
		update_header(CHANGED);
		write_blank(p);
	}
}

void cb_blank_save_as_template()
{
	string def_blank_filename = def_blank_TemplateName;
	const char *p = FSEL::saveas(
			xSAVEASTEMPLATE,
			string(xTEMPLATEFILE).append(BLANKTEMP_EXT).c_str(),
			def_blank_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_blank_TemplateName = p;
		if (strlen(pext) == 0) def_blank_TemplateName.append(BLANKTEMP_EXT);
		remove_spaces_from_filename(def_blank_TemplateName);
		clear_header();
		update_header(CHANGED);
		write_blank(def_blank_TemplateName);
		show_filename(def_blank_TemplateName);
		using_blank_template = true;
	}
}

void cb_blank_open()
{
	const char *p = FSEL::select(xOPENDATAFILE, "blank form\t*.b2s",
					def_blank_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_blank_form();
	read_data_file(p);
	using_blank_template = false;
	def_blank_filename = p;
	show_filename(def_blank_filename);
}

void write_blank(string s)
{
	FILE *blankfile = fopen(s.c_str(), "w");
	if (!blankfile) return;
	fwrite(blankbuffer.c_str(), blankbuffer.length(), 1, blankfile);
	fclose(blankfile);
}

bool cb_blank_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(".b2s");
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_blank_filename;

	p = FSEL::saveas(xSAVEDATAFILE, "blank form\t*.b2s",
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_blank_filename = p;
	if (strlen(pext) == 0) def_blank_filename.append(".b2s");

	remove_spaces_from_filename(def_blank_filename);
	update_header(NEW);
	update_blankfields();
	blankbuffer.assign(header("<blankform>"));
	blankbuffer.append( lineout( blank_msg, blank_field ) );
	write_blank(def_blank_filename);

	using_blank_template = false;
	show_filename(def_blank_filename);
	return true;
}

void cb_blank_save()
{
	if (base_blank_filename == string(xNEW).append(BLANKFILE_EXT) || 
		base_blank_filename == string(xDEFAULT).append(BLANKFILE_EXT) ||
		using_blank_template == true) {
		cb_blank_save_as();
		return;
	}
	if (check_blankfields()) update_header(CHANGED);
	update_blankfields();
	blankbuffer.assign(header("<blankform>"));
	blankbuffer.append( lineout( blank_msg, blank_field ) );
	write_blank(def_blank_filename);
	using_blank_template = false;
}

void cb_blank_msg_type()
{
	if (tabs_msg_type->value() == tab_blank ) {
		show_filename(def_blank_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_blank_html()
{
	update_blankfields();
//	if (blank_field.empty()) return;

	string fname_name = fl_filename_name(def_blank_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);
	string blank_name = ICS_dir;
	string html_text = "";
	blank_name.append(fname_name);
	blank_name.append(".html");

	string blankform = blank_html_template;

	html_text = "<pre><big style= font-family: \"Consolas\", \"Monospace\", \"Courier\";\">";
	if (progStatus.autowordwrap)
		html_text.append(wordwrap(blank_field, progStatus.charcount));
	else
		html_text.append(blank_field);
	html_text.append("</big></pre>");
	replacestr(blankform, blank_msg, html_text);

	FILE *blankfile = fopen(blank_name.c_str(), "w");
	fprintf(blankfile,"%s", blankform.c_str());
	fclose(blankfile);

	open_url(blank_name.c_str());
}

void cb_blank_textout()
{
	string blank_name = ICS_dir;
	blank_name.append("blankform.txt");

	update_blankfields();
	string blankform = blank_txt_template;

	replacestr(blankform, blank_msg, blank_field);

	FILE *blankfile = fopen(blank_name.c_str(), "w");
	fprintf(blankfile,"%s", blankform.c_str());
	fclose(blankfile);

	open_url(blank_name.c_str());
}
