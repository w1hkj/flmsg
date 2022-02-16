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

// ics205 fields

// compatibility fields required to read older data files

std::string ics205_name		= ":nam:";
std::string ics205_dt1		= ":dt1:";
std::string ics205_dt2		= ":dt2:";
std::string ics205_dt3		= ":dt3:";
std::string ics205_func		= ":func";
std::string ics205_chan		= ":chan";
std::string ics205_asgn		= ":asgn";
std::string ics205_rx_freq	= ":rxfq";
std::string ics205_rx_tone	= ":rxtn";
std::string ics205_tx_freq	= ":txfq";
std::string ics205_tx_tone	= ":txtn";
std::string ics205_mode_adm	= ":mode";
std::string ics205_rem		= ":rmrk";
std::string ics205_prep		= ":prp:";
std::string ics205_county	= ":cnty:";
std::string ics205_state		= ":stat:";
std::string ics205_latitude	= ":lat:";
std::string ics205_longitude	= ":lon:";


const char *nbr[] = {
"00:", "01:", "02:", "03:", "04:", "05:", "06:", "07:", "08:", "09:",
"10:", "11:", "12:", "13:", "14:", "15:", "16:", "17:", "18:", "19:" };

std::string s205_name;
std::string s205_dt_prepared;
std::string s205_dt_op_from;
std::string s205_dt_op_to;
std::string s205_func[20];
std::string s205_channel[20];
std::string s205_asgn[20];
std::string s205_rx_freq[20];
std::string s205_rx_tone[20];
std::string s205_tx_freq[20];
std::string s205_tx_tone[20];
std::string s205_mode_adm[20];
std::string s205_remarks[20];
std::string s205_preparer;
std::string s205_county;
std::string s205_state;
std::string s205_latitude;
std::string s205_longitude;

std::string buff205;
std::string def_205_filename = "";
std::string base_205_filename = "";
std::string def_205_TemplateName = "";
bool using_ics205_template = false;

void cb_205_SetDateTime1()
{
	txt_205_dt_prepared->value(szDateTime());
}

void cb_205_SetDateTime2()
{
	txt_205_dt_op_from->value(szDateTime());
}

void cb_205_SetDateTime3()
{
	txt_205_dt_op_to->value(szDateTime());
}

void clear_205fields()
{
	s205_name.clear();
	s205_dt_prepared.clear();
	s205_dt_op_from.clear();
	for (int i = 0; i < 20; i++) {
		s205_func[i].clear();
		s205_channel[i].clear();
		s205_asgn[i].clear();
		s205_rx_freq[i].clear();
		s205_rx_tone[i].clear();
		s205_tx_freq[i].clear();
		s205_tx_tone[i].clear();
		s205_mode_adm[i].clear();
		s205_remarks[i].clear();
	}
	s205_preparer.clear();
	s205_county.clear();
	s205_state.clear();
	s205_latitude.clear();
	s205_longitude.clear();
}

bool check_205fields()
{
	if (s205_name != txt_205_name->value())
		return true;
	if (s205_dt_prepared != txt_205_dt_prepared->value())
		return true;
	if (s205_dt_op_from != txt_205_dt_op_from->value())
		return true;
	if (s205_dt_op_to != txt_205_dt_op_to->value())
		return true;
	for (int i = 0; i < 20; i++) {
		if (s205_func[i] != txt_205_func[i]->value())
			return true;
		if (s205_channel[i] != txt_205_channel[i]->value())
			return true;
		if (s205_asgn[i] != txt_205_assign[i]->value())
			return true;
		if (s205_rx_freq[i] != txt_205_rx_freq[i]->value())
			return true;
		if (s205_rx_tone[i] != txt_205_rx_tone[i]->value())
			return true;
		if (s205_tx_freq[i] != txt_205_tx_freq[i]->value())
			return true;
		if (s205_tx_tone[i] != txt_205_tx_tone[i]->value())
			return true;
		if (s205_mode_adm[i] != txt_205_mode_adm[i]->value())
			return true;
		if (s205_remarks[i] != txt_205_remarks[i]->value())
			return true;
	}
	if (s205_preparer != txt_205_preparer->value())
		return true;
	if (s205_county != txt_205_county->value())
		return true;
	if (s205_state != txt_205_state->value())
		return true;
	if (s205_latitude != txt_205_latitude->value())
		return true;
	if (s205_longitude != txt_205_longitude->value())
		return true;

	return false;
}

void update_205fields()
{
	s205_name = txt_205_name->value();
	s205_dt_prepared = txt_205_dt_prepared->value();
	s205_dt_op_from = txt_205_dt_op_from->value();
	s205_dt_op_to = txt_205_dt_op_to->value();
	for (int i = 0; i < 20; i++) {
		s205_func[i] = txt_205_func[i]->value();
		s205_channel[i] = txt_205_channel[i]->value();
		s205_asgn[i] = txt_205_assign[i]->value();
		s205_rx_freq[i] = txt_205_rx_freq[i]->value();
		s205_rx_tone[i] = txt_205_rx_tone[i]->value();
		s205_tx_freq[i] = txt_205_tx_freq[i]->value();
		s205_tx_tone[i] = txt_205_tx_tone[i]->value();
		s205_mode_adm[i] = txt_205_mode_adm[i]->value();
		s205_remarks[i] = txt_205_remarks[i]->value();
	}
	s205_preparer = txt_205_preparer->value();
	s205_county = txt_205_county->value();
	s205_state = txt_205_state->value();
	s205_latitude = txt_205_latitude->value();
	s205_longitude = txt_205_longitude->value();
}

void update_205form()
{
	txt_205_name->value(s205_name.c_str());
	txt_205_dt_prepared->value(s205_dt_prepared.c_str());
	txt_205_dt_op_from->value(s205_dt_op_from.c_str());
	txt_205_dt_op_to->value(s205_dt_op_to.c_str());
	for (int i = 0; i < 20; i++) {
		txt_205_func[i]->value(s205_func[i].c_str());
		txt_205_channel[i]->value(s205_channel[i].c_str());
		txt_205_assign[i]->value(s205_asgn[i].c_str());
		txt_205_rx_freq[i]->value(s205_rx_freq[i].c_str());
		txt_205_rx_tone[i]->value(s205_rx_tone[i].c_str());
		txt_205_tx_freq[i]->value(s205_tx_freq[i].c_str());
		txt_205_tx_tone[i]->value(s205_tx_tone[i].c_str());
		txt_205_mode_adm[i]->value(s205_mode_adm[i].c_str());
		txt_205_remarks[i]->value(s205_remarks[i].c_str());
	}
	txt_205_preparer->value(s205_preparer.c_str());
	txt_205_county->value(s205_county.c_str());
	txt_205_state->value(s205_state.c_str());
	txt_205_latitude->value(s205_latitude.c_str());
	txt_205_longitude->value(s205_longitude.c_str());
}

void clear_205_form()
{
	clear_205fields();
	txt_205_name->value("");
	txt_205_dt_prepared->value("");
	txt_205_dt_op_from->value("");
	txt_205_dt_op_to->value("");
	for (int i = 0; i < 20; i++) {
		txt_205_func[i]->value("");
		txt_205_channel[i]->value("");
		txt_205_assign[i]->value("");
		txt_205_rx_freq[i]->value("");
		txt_205_rx_tone[i]->value("");
		txt_205_tx_freq[i]->value("");
		txt_205_tx_tone[i]->value("");
		txt_205_mode_adm[i]->value("");
		txt_205_remarks[i]->value("");
	}
	txt_205_preparer->value("");
	txt_205_county->value("");
	txt_205_state->value("");
	txt_205_latitude->value("");
	txt_205_longitude->value("");
}

void make_buff205(bool compress = false)
{
	std::string mbuff;
	std::string temp;
	mbuff.clear();
	mbuff.append( lineout( ics205_name, s205_name ) );
	mbuff.append( lineout( ics205_dt1, s205_dt_prepared ) );
	mbuff.append( lineout( ics205_dt2, s205_dt_op_from ) );
	mbuff.append( lineout( ics205_dt3, s205_dt_op_to ) );

	for (int i = 0; i < 20; i++) {
		temp = ics205_func; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_func[i] ) );

		temp = ics205_chan; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_channel[i] ) );

		temp = ics205_asgn; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_asgn[i] ) );

		temp = ics205_rx_freq; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_rx_freq[i] ) );

		temp = ics205_rx_tone; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_rx_tone[i] ) );

		temp = ics205_tx_freq; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_tx_freq[i] ) );

		temp = ics205_tx_tone; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_tx_tone[i] ) );

		temp = ics205_mode_adm; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_mode_adm[i] ) );

		temp = ics205_rem; temp.append(nbr[i]);
		mbuff.append( lineout ( temp, s205_remarks[i] ) );
	}
	mbuff.append( lineout ( ics205_prep, s205_preparer ) );
	mbuff.append( lineout ( ics205_county, s205_county ) );
	mbuff.append( lineout ( ics205_state, s205_state ) );
	mbuff.append( lineout ( ics205_latitude, s205_latitude ) );
	mbuff.append( lineout ( ics205_longitude, s205_longitude ) );

	if (compress) compress_maybe(mbuff);
	buff205.append(mbuff);
}

void read_205_buffer(std::string data)
{
	std::string temp;
	clear_205fields();
	read_header(data);

	s205_name = findstr(data, ics205_name);
	s205_dt_prepared = findstr(data, ics205_dt1);
	s205_dt_op_from = findstr(data, ics205_dt2);
	s205_dt_op_to = findstr(data, ics205_dt3);
	for (int i = 0; i < 20; i++) {
		temp = ics205_func; temp.append(nbr[i]);
		s205_func[i] = findstr(data, temp);

		temp = ics205_chan; temp.append(nbr[i]);
		s205_channel[i] = findstr(data, temp);

		temp = ics205_asgn; temp.append(nbr[i]);
		s205_asgn[i] = findstr(data, temp);

		temp = ics205_rx_freq; temp.append(nbr[i]);
		s205_rx_freq[i] = findstr(data, temp);

		temp = ics205_rx_tone; temp.append(nbr[i]);
		s205_rx_tone[i] = findstr(data, temp);

		temp = ics205_tx_freq; temp.append(nbr[i]);
		s205_tx_freq[i] = findstr(data, temp);

		temp = ics205_tx_tone; temp.append(nbr[i]);
		s205_tx_tone[i] = findstr(data, temp);

		temp = ics205_mode_adm; temp.append(nbr[i]);
		s205_mode_adm[i] = findstr(data, temp);

		temp = ics205_rem; temp.append(nbr[i]);
		s205_remarks[i] = findstr(data, temp);
	}
	s205_preparer = findstr(data, ics205_prep);
	s205_county = findstr(data, ics205_county);
	s205_state = findstr(data, ics205_state);
	s205_latitude = findstr(data, ics205_latitude);
	s205_longitude = findstr(data, ics205_longitude);

	update_205form();
}

void cb_205_new()
{
	if (check_205fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_205_save();
		}
	}
	clear_205_form();
	clear_header();
	def_205_filename = ICS_msg_dir;
	def_205_filename.append("new").append(F205_EXT);
	show_filename(def_205_filename);
	using_ics205_template = false;
}

void cb_205_import()
{
	fl_alert2("Not implemented");
}

void cb_205_export()
{
	fl_alert2("Not implemented");
}

void cb_205_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_205_form();
	read_205_buffer(inpbuffer);
	def_205_filename = ICS_msg_dir;
	def_205_filename.append(wrapfilename);
	show_filename(def_205_filename);
	using_ics205_template = false;
}

int eval_205_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_205_filename).append("]");
	update_205fields();
	update_header(FROM);
	evalstr.append(header("<ics205>"));
	buff205.clear();
	make_buff205(true);
	if (buff205.empty()) return 0;
	compress_maybe( buff205 );
	evalstr.append( buff205 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_205_wrap_export()
{
	if (check_205fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_205fields();

	if (base_205_filename == std::string("new").append(F205_EXT) ||
		base_205_filename == std::string("default").append(F205_EXT) )
		if (!cb_205_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_205_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff205.assign(header("<ics205>"));
		make_buff205(true);
		export_wrapfile(base_205_filename, wrapfilename, buff205, pext != ".wrap");

		buff205.assign(header("<ics205>"));
		make_buff205(false);
		write_205(def_205_filename);
	}
}

void cb_205_wrap_autosend()
{
	if (check_205fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_205fields();

	if (base_205_filename == std::string("new").append(F205_EXT) ||
		base_205_filename == std::string("default").append(F205_EXT) )
		if (!cb_205_save_as()) return;

	update_header(FROM);
	buff205.assign(header("<ics205>"));
	make_buff205(true);
	xfr_via_socket(base_205_filename, buff205);

	buff205.assign(header("<ics205>"));
	make_buff205(false);
	write_205(def_205_filename);
}

void cb_205_load_template()
{
	std::string def_205_filename = def_205_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(T205_EXT).c_str(),
			def_205_filename.c_str());
	if (p) {
		clear_205_form();
		read_data_file(p);
		def_205_TemplateName = p;
		show_filename(def_205_TemplateName);
		using_ics205_template = true;
	}
}

void cb_205_save_template()
{
	if (!using_ics205_template) {
		cb_205_save_as_template();
		return;
	}
	std::string def_205_filename = def_205_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(T205_EXT).c_str(),
			def_205_filename.c_str());
	if (p) {
		update_header(CHANGED);
		buff205.assign(header("<ics205>"));
		make_buff205();
		write_205(p);
	}
}

void cb_205_save_as_template()
{
	std::string def_205_filename = def_205_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(T205_EXT).c_str(),
			def_205_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_205_TemplateName = p;
		if (strlen(pext) == 0) def_205_TemplateName.append(T205_EXT);
		remove_spaces_from_filename(def_205_TemplateName);
		clear_header();
		update_header(CHANGED);
		buff205.assign(header("<ics205>"));
		make_buff205();
		write_205(def_205_TemplateName);
		show_filename(def_205_TemplateName);
		using_ics205_template = true;
	}
}

void cb_205_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-205\t*").append(F205_EXT).c_str(),
			def_205_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_205_form();
	read_data_file(p);
	using_ics205_template = false;
	def_205_filename = p;
	show_filename(def_205_filename);
}

void write_205(std::string s)
{
	FILE *file205 = fopen(s.c_str(), "w");
	if (!file205) return;

	fwrite(buff205.c_str(), buff205.length(), 1, file205);
	fclose(file205);
}

bool cb_205_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(F205_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_205_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-205\t*").append(F205_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_205_filename = p;
	if (strlen(pext) == 0) def_205_filename.append(F205_EXT);

	remove_spaces_from_filename(def_205_filename);
	update_205fields();
	clear_header();
	update_header(CHANGED);
	buff205.assign(header("<ics205>"));
	make_buff205();
	write_205(def_205_filename);

	using_ics205_template = false;
	show_filename(def_205_filename);
	return true;
}

void cb_205_save()
{
	if (base_205_filename == std::string("new").append(F205_EXT) || 
		base_205_filename == std::string("default").append(F205_EXT) ||
		using_ics205_template == true) {
		cb_205_save_as();
		return;
	}
	if (check_205fields()) update_header(CHANGED);
	update_205fields();
	buff205.assign(header("<ics205>"));
	make_buff205();
	write_205(def_205_filename);
	using_ics205_template = false;
}

void cb_205_html()
{
	std::string temp;
	std::string fname_name = fl_filename_name(def_205_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string ics205_fname = ICS_dir;
	ics205_fname.append(fname_name);
	ics205_fname.append(".html");

	std::string html_text = "";

	update_205fields();
	std::string form205 = ics205_html_template;

	replacestr(form205, TITLE, fname_name);
	replacestr(form205, ics205_name, s205_name);
	replacestr(form205, ics205_dt1, s205_dt_prepared);
	replacestr(form205, ics205_dt2, s205_dt_op_from);
	replacestr(form205, ics205_dt3, s205_dt_op_to);
	for (int i = 0; i < 20; i++) {
		temp = ics205_func; temp.append(nbr[i]); replacestr(form205, temp, s205_func[i]);
		temp = ics205_chan; temp.append(nbr[i]); replacestr(form205, temp, s205_channel[i]);
		temp = ics205_asgn; temp.append(nbr[i]); replacestr(form205, temp, s205_asgn[i]);
		temp = ics205_rx_freq; temp.append(nbr[i]); replacestr(form205, temp, s205_rx_freq[i]);
		temp = ics205_rx_tone; temp.append(nbr[i]); replacestr(form205, temp, s205_rx_tone[i]);
		temp = ics205_tx_freq; temp.append(nbr[i]); replacestr(form205, temp, s205_tx_freq[i]);
		temp = ics205_tx_tone; temp.append(nbr[i]); replacestr(form205, temp, s205_tx_tone[i]);
		temp = ics205_mode_adm;  temp.append(nbr[i]); replacestr(form205, temp, s205_mode_adm[i]);
		temp = ics205_rem;  temp.append(nbr[i]); replacestr(form205, temp, s205_remarks[i]);
	}
	replacestr(form205, ics205_prep, s205_preparer);
	replacestr(form205, ics205_county, s205_county);
	replacestr(form205, ics205_state, s205_state);
	replacestr(form205, ics205_latitude, s205_latitude);
	replacestr(form205, ics205_longitude, s205_longitude);

	FILE *file205 = fopen(ics205_fname.c_str(), "w");
	fprintf(file205,"%s", form205.c_str());
	fclose(file205);

	open_url(ics205_fname.c_str());
}

void cb_205_msg_type()
{
	if (tabs_msg_type->value() == tab_ics205 ) {
		show_filename(def_205_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_205_textout()
{
	std::string fld = "";
	std::string temp = "";
	std::string ics205_fname = ICS_dir;
	ics205_fname.append("ics205.txt");

	update_205fields();
	std::string form205 = ics205_text_template;

	replacestr(form205, ics205_name, s205_name);
	replacestr(form205, ics205_dt1, s205_dt_prepared);
	replacestr(form205, ics205_dt2, s205_dt_op_from);
	replacestr(form205, ics205_dt3, s205_dt_op_to);
	for (int i = 0; i < 20; i++) {
		fld = ics205_func; fld.append(nbr[i]); replacestr(form205, fld, s205_func[i]);
		fld = ics205_chan; fld.append(nbr[i]); replacestr(form205, fld, s205_channel[i]);
		fld = ics205_asgn; fld.append(nbr[i]); replacestr(form205, fld, s205_asgn[i]);
		fld = ics205_rx_freq; fld.append(nbr[i]); replacestr(form205, fld, s205_rx_freq[i]);
		fld = ics205_rx_tone; fld.append(nbr[i]); replacestr(form205, fld, s205_rx_tone[i]);
		fld = ics205_tx_freq; fld.append(nbr[i]); replacestr(form205, fld, s205_tx_freq[i]);
		fld = ics205_tx_tone; fld.append(nbr[i]); replacestr(form205, fld, s205_tx_tone[i]);
		fld = ics205_mode_adm;  fld.append(nbr[i]); replacestr(form205, fld, s205_mode_adm[i]);
		fld = ics205_rem;  fld.append(nbr[i]); temp = s205_remarks[i];
		replacelf(temp);   replacestr(form205, fld, temp);
	}
	replacestr(form205, ics205_prep, s205_preparer);
	replacestr(form205, ics205_county, s205_county);
	replacestr(form205, ics205_state, s205_state);
	replacestr(form205, ics205_latitude, s205_latitude);
	replacestr(form205, ics205_longitude, s205_longitude);

	FILE *file205 = fopen(ics205_fname.c_str(), "w");
	fprintf(file205,"%s", form205.c_str());
	fclose(file205);

	open_url(ics205_fname.c_str());
}
