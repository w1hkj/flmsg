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

// ---------------------------------------------------------------------
// ics 110 field variables and template variables
// ---------------------------------------------------------------------

std::string cap110_mission_nbr			= ":mnbr:";
std::string cap110_station				= ":sta:";
std::string cap110_date					= ":date:";
std::string cap110_ds_a					= ":ds_a:";
std::string cap110_ds_b					= ":ds_b:";
std::string cap110_ds_c					= ":ds_c:";
std::string cap110_ds_d					= ":ds_d:";
std::string cap110_ds_e					= ":ds_e:";
std::string cap110_ds_f					= ":ds_f:";

std::string cap110_comm_time				= ":time[n]:";	// 23
std::string cap110_comm_chref			= ":chref[n]:";	// 23
std::string cap110_comm_call				= ":call[n]:";	// 23
std::string cap110_comm_rem				= ":rem[n]:";	// 23

std::string s110_mission_nbr;
std::string s110_station;
std::string s110_date;
std::string s110_ds_a;
std::string s110_ds_b;
std::string s110_ds_c;
std::string s110_ds_d;
std::string s110_ds_e;
std::string s110_ds_f;

std::string s110_comm_time[23];
std::string s110_comm_call[23];
std::string s110_comm_chref[23];
std::string s110_comm_rem[23];

// =====================================================================

std::string	buff_c110;
std::string	cap110_def_filename= "";
std::string	cap110_base_filename = "";
std::string	cap110_def_template_name = "";
bool	using_cap110_template = false;

void cap110_set_date()
{
	std::string date = szCAPDateTime();
	date.erase(2,6);
	txt_110_date->value(date.c_str());
}

void clear_110fields()
{
	s110_mission_nbr.clear();
	s110_station.clear();
	s110_date.clear();
	s110_ds_a.clear();
	s110_ds_b.clear();
	s110_ds_c.clear();
	s110_ds_d.clear();
	s110_ds_e.clear();
	s110_ds_f.clear();

	for (int i = 0; i < 23; i++) {
		s110_comm_time[i].clear();
		s110_comm_call[i].clear();
		s110_comm_chref[i].clear();
		s110_comm_rem[i].clear();
	}
}

bool check_110fields()
{
	if (s110_mission_nbr != txt_110_mission_nbr->value())
		return true;
	if (s110_station != txt_110_station->value())
		return true;
	if (s110_date != txt_110_date->value())
		return true;
	if (s110_ds_a != txt_110_ds_a->value())
		return true;
	if (s110_ds_b != txt_110_ds_b->value())
		return true;
	if (s110_ds_c != txt_110_ds_c->value())
		return true;
	if (s110_ds_d != txt_110_ds_d->value())
		return true;
	if (s110_ds_e != txt_110_ds_e->value())
		return true;
	if (s110_ds_f != txt_110_ds_f->value())
		return true;
	for (int i = 0; i < 23; i++) {
		if (s110_comm_time[i] != txt_110_comm_time[i]->value())
			return true;
		if (s110_comm_call[i] != txt_110_comm_call[i]->value())
			return true;
		if (s110_comm_chref[i] != txt_110_comm_chref[i]->value())
			return true;
		if (s110_comm_rem[i] != txt_110_comm_rem[i]->value())
			return true;
	}
	return false;
}

void update_110fields()
{
	s110_mission_nbr = txt_110_mission_nbr->value();
	s110_station = txt_110_station->value();
	s110_date = txt_110_date->value();
	s110_ds_a = txt_110_ds_a->value();
	s110_ds_b = txt_110_ds_b->value();
	s110_ds_c = txt_110_ds_c->value();
	s110_ds_d = txt_110_ds_d->value();
	s110_ds_e = txt_110_ds_e->value();
	s110_ds_f = txt_110_ds_f->value();
	for (int i = 0; i < 23; i++) {
		s110_comm_time[i] = txt_110_comm_time[i]->value();
		s110_comm_call[i] = txt_110_comm_call[i]->value();
		s110_comm_chref[i] = txt_110_comm_chref[i]->value();
		s110_comm_rem[i] = txt_110_comm_rem[i]->value();
	}
}

void update_110form()
{
	txt_110_mission_nbr->value(s110_mission_nbr.c_str());
	txt_110_station->value(s110_station.c_str());
	txt_110_date->value(s110_date.c_str());
	txt_110_ds_a->value(s110_ds_a.c_str());
	txt_110_ds_b->value(s110_ds_b.c_str());
	txt_110_ds_c->value(s110_ds_c.c_str());
	txt_110_ds_d->value(s110_ds_d.c_str());
	txt_110_ds_e->value(s110_ds_e.c_str());
	txt_110_ds_f->value(s110_ds_f.c_str());

	for (int i = 0; i < 23; i++) {
		txt_110_comm_time[i]->value(s110_comm_time[i].c_str());
		txt_110_comm_call[i]->value(s110_comm_call[i].c_str());
		txt_110_comm_chref[i]->value(s110_comm_chref[i].c_str());
		txt_110_comm_rem[i]->value(s110_comm_rem[i].c_str());
	}
}

void clear_110_form()
{
	clear_110fields();
	update_110form();
}

std::string &cap110_nn(std::string & subst, int n)
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
		ics[pos] = n > 19 ? '2' : '1';
		ics[pos+1] = '0' + n % 10;
		ics[pos+2] = ']';
		ics += ':';
	}
	return ics;
}

void make_buff_c110(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( cap110_mission_nbr, s110_mission_nbr ) );
	mbuff.append( lineout( cap110_station, s110_station ) );
	mbuff.append( lineout( cap110_date, s110_date ) );
	mbuff.append( lineout( cap110_ds_a, s110_ds_a ) );
	mbuff.append( lineout( cap110_ds_b, s110_ds_b ) );
	mbuff.append( lineout( cap110_ds_c, s110_ds_c ) );
	mbuff.append( lineout( cap110_ds_d, s110_ds_d ) );
	mbuff.append( lineout( cap110_ds_e, s110_ds_e ) );
	mbuff.append( lineout( cap110_ds_f, s110_ds_f ) );

	for (int i = 0; i < 23; i++) {
		mbuff.append( lineout( cap110_nn( cap110_comm_time, i ), s110_comm_time[i] ) );
		mbuff.append( lineout( cap110_nn( cap110_comm_call, i ),     s110_comm_call[i] ) );
		mbuff.append( lineout( cap110_nn( cap110_comm_chref, i ),     s110_comm_chref[i] ) );
		mbuff.append( lineout( cap110_nn( cap110_comm_rem, i ), s110_comm_rem[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	buff_c110.append(mbuff);
}

void read_c110_buffer(std::string data)
{
	clear_110fields();
	read_header(data);

	s110_mission_nbr = findstr( data, cap110_mission_nbr );
	s110_station = findstr( data, cap110_station );
	s110_date = findstr( data, cap110_date );
	s110_ds_a = findstr( data, cap110_ds_a );
	s110_ds_b = findstr( data, cap110_ds_b );
	s110_ds_c = findstr( data, cap110_ds_c );
	s110_ds_d = findstr( data, cap110_ds_d );
	s110_ds_e = findstr( data, cap110_ds_e );
	s110_ds_f = findstr( data, cap110_ds_f );

	for (int i = 0; i < 23; i++) {
		s110_comm_time[i]  = findstr( data, cap110_nn( cap110_comm_time, i ) );
		s110_comm_call[i]  = findstr( data, cap110_nn( cap110_comm_call, i ) );
		s110_comm_chref[i] = findstr( data, cap110_nn( cap110_comm_chref, i ) );
		s110_comm_rem[i]   = findstr( data, cap110_nn( cap110_comm_rem, i ) );
	}

	update_110form();

}

void cap110_cb_load_template(std::string data)
{
	clear_110fields();
	read_header(data);

	s110_mission_nbr = findstr( data, cap110_mission_nbr );
	s110_station = findstr( data, cap110_station );
	s110_date = findstr( data, cap110_date );
	s110_ds_a = findstr( data, cap110_ds_a );
	s110_ds_b = findstr( data, cap110_ds_b );
	s110_ds_c = findstr( data, cap110_ds_c );
	s110_ds_d = findstr( data, cap110_ds_d );
	s110_ds_e = findstr( data, cap110_ds_e );
	s110_ds_f = findstr( data, cap110_ds_f );

	for (int i = 0; i < 23; i++) {
		s110_comm_time[i]  = findstr( data, cap110_nn( cap110_comm_time, i ) );
		s110_comm_call[i]  = findstr( data, cap110_nn( cap110_comm_call, i ) );
		s110_comm_chref[i] = findstr( data, cap110_nn( cap110_comm_chref, i ) );
		s110_comm_rem[i]   = findstr( data, cap110_nn( cap110_comm_rem, i ) );
	}

	update_110form();
}

void cap110_cb_new()
{
	if (check_110fields()) {
		if (fl_choice2(xMODIFIED, "No", xMODIFIED, NULL) == 1) {
			update_header(CHANGED);
			cap110_cb_save();
		}
	}
	clear_110_form();
	clear_header();
	cap110_def_filename= ICS_msg_dir;
	cap110_def_filename.append(xNEW).append(CAP110_FILE_EXT);
	show_filename(cap110_def_filename);
	using_cap110_template = false;
}

void cap110_cb_import()
{
	fl_alert2(xNOTIMPLEMENTED);
}

void cap110_cb_export()
{
	fl_alert2(xNOTIMPLEMENTED);
}

void cap110_cb_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_110_form();
	cap110_cb_load_template(inpbuffer);
	cap110_def_filename= ICS_msg_dir;
	cap110_def_filename.append(wrapfilename);
	show_filename(cap110_def_filename);
	using_cap110_template = false;
}

int eval_cap110_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(cap110_base_filename).append("]");
	update_110fields();
	update_header(FROM);
	evalstr.append(header("<cap110>"));
	buff_c110.clear();
	make_buff_c110(true);
	if (buff_c110.empty()) return 0;
	compress_maybe( buff_c110 );
	evalstr.append( buff_c110 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cap110_cb_wrap_export()
{
	if (check_110fields()) {
		if (fl_choice2(xMODIFIED, "No", xMODIFIED, NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_110fields();

	if (cap110_base_filename == std::string(xNEW).append(CAP110_FILE_EXT) ||
		cap110_base_filename == std::string(xDEFAULT).append(CAP110_FILE_EXT) )
		if (!cap110_cb_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(cap110_base_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			xSAVEASWRAP,
			xWRAPFILE,
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff_c110.assign(header("<cap110>"));
		make_buff_c110(true);
		export_wrapfile(cap110_base_filename, wrapfilename, buff_c110, pext != ".wrap");
		write_110(cap110_def_filename);
	}
}

void cap110_cb_wrap_autosend()
{
	if (check_110fields()) {
		if (fl_choice2(xMODIFIED, "No", xMODIFIED, NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_110fields();

	if (cap110_base_filename == std::string(xNEW).append(CAP110_FILE_EXT) ||
		cap110_base_filename == std::string(xDEFAULT).append(CAP110_FILE_EXT) )
		cap110_cb_save_as();

	update_header(FROM);
	buff_c110.assign(header("<cap110>"));
	make_buff_c110(true);

	xfr_via_socket(cap110_base_filename, buff_c110);
	write_110(cap110_def_filename);
}

void cap110_cb_load_template()
{
	std::string cap110_def_filename= cap110_def_template_name;
	const char *p = FSEL::select(
			xOPENTEMPLATE,
			std::string(xTEMPLATEFILE).append(CAP110_TEMP_EXT).c_str(),
			cap110_def_filename.c_str());
	if (p) {
		clear_110_form();
		read_data_file(p);
		cap110_def_template_name = p;
		show_filename(cap110_def_template_name);
		using_cap110_template = true;
	}
}

void cap110_cb_save_template()
{
	if (!using_cap110_template) {
		cap110_cb_save_as_template();
		return;
	}
	std::string cap110_def_filename= cap110_def_template_name;
	const char *p = FSEL::saveas(
			xSAVEASTEMPLATE,
			std::string(xTEMPLATEFILE).append(CAP110_TEMP_EXT).c_str(),
			cap110_def_filename.c_str());
	if (p) {
		update_header(CHANGED);
		buff_c110.assign(header("<cap110>"));
		make_buff_c110();
		write_110(p);
	}
}

void cap110_cb_save_as_template()
{
	std::string cap110_def_filename= cap110_def_template_name;
	const char *p = FSEL::saveas(
			xSAVEASTEMPLATE,
			std::string(xTEMPLATEFILE).append(CAP110_TEMP_EXT).c_str(),
			cap110_def_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		cap110_def_template_name = p;
		if (strlen(pext) == 0) cap110_def_template_name.append(CAP110_TEMP_EXT);
		remove_spaces_from_filename(cap110_def_template_name);
		clear_header();
		update_header(CHANGED);
		buff_c110.assign(header("<cap110>"));
		make_buff_c110();
		write_110(cap110_def_template_name);
		show_filename(cap110_def_template_name);
		using_cap110_template = true;
	}
}

void cap110_cb_open()
{
	const char *p = FSEL::select(
			_(xOPENDATAFILE),
			std::string("CAP-110\t*").append(CAP110_FILE_EXT).c_str(),
			cap110_def_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_110_form();
	read_data_file(p);
	using_cap110_template = false;
	cap110_def_filename= p;
	show_filename(cap110_def_filename);
}

void write_110(std::string s)
{
	FILE *file110 = fopen(s.c_str(), "w");
	if (!file110) return;

	fwrite(buff_c110.c_str(), buff_c110.length(), 1, file110);
	fclose(file110);
}

bool cap110_cb_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(CAP110_FILE_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = cap110_def_filename;

	p = FSEL::saveas(
			_(xSAVEDATAFILE),
			std::string("CAP-110\t*").append(CAP110_FILE_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	cap110_def_filename= p;
	if (strlen(pext) == 0) cap110_def_filename.append(CAP110_FILE_EXT);

	remove_spaces_from_filename(cap110_def_filename);
	update_110fields();
	update_header(NEW);
	buff_c110.assign(header("<cap110>"));
	make_buff_c110();
	write_110(cap110_def_filename);

	using_cap110_template = false;
	show_filename(cap110_def_filename);
	return true;
}

void cap110_cb_save()
{
	if (cap110_base_filename == std::string(xNEW).append(CAP110_FILE_EXT) || 
		cap110_base_filename == std::string(xDEFAULT).append(CAP110_FILE_EXT) ||
		using_cap110_template == true) {
		cap110_cb_save_as();
		return;
	}
	if (check_110fields()) update_header(CHANGED);
	update_110fields();
	buff_c110.assign(header("<cap110>"));
	make_buff_c110();
	write_110(cap110_def_filename);
	using_cap110_template = false;
}

void cap110_cb_html()
{
	std::string fname_name = fl_filename_name(cap110_def_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string cap110_fname = ICS_dir;
	cap110_fname.append(fname_name);
	cap110_fname.append(".html");

	std::string html_text = "";
	std::string empty = "<br>";

	update_110fields();
	std::string form110 = cap110_html_template;

	replacestr(form110, TITLE, fname_name);
	replacestr(form110, cap110_mission_nbr, s110_mission_nbr );
	replacestr(form110, cap110_station, s110_station );
	replacestr(form110, cap110_date, s110_date );
	replacestr(form110, cap110_ds_a, s110_ds_a );
	replacestr(form110, cap110_ds_b, s110_ds_b );
	replacestr(form110, cap110_ds_c, s110_ds_c );
	replacestr(form110, cap110_ds_d, s110_ds_d );
	replacestr(form110, cap110_ds_e, s110_ds_e );
	replacestr(form110, cap110_ds_f, s110_ds_f );

	for (int i = 0; i < 23; i++) {
		replacestr(form110, cap110_nn( cap110_comm_time, i ),
			s110_comm_time[i].empty() ? empty : s110_comm_time[i] );
		replacestr(form110, cap110_nn( cap110_comm_call, i ), 
			s110_comm_call[i].empty() ? empty : s110_comm_call[i] );
		replacestr(form110, cap110_nn( cap110_comm_chref, i ), 
			s110_comm_chref[i].empty() ? empty : s110_comm_chref[i] );
		replacestr(form110, cap110_nn( cap110_comm_rem, i ), 
			s110_comm_rem[i].empty() ? empty : s110_comm_rem[i] );
	}

	FILE *file110 = fopen(cap110_fname.c_str(), "w");
	fprintf(file110,"%s", form110.c_str());
	fclose(file110);

	open_url(cap110_fname.c_str());
}

void cap110_cb_msg_type()
{
	if (tabs_msg_type->value() == tab_cap110 )
		show_filename(cap110_def_filename);
}

void cap110_cb_textout()
{
	std::string cap110_fname = ICS_dir;
	cap110_fname.append("cap110.txt");

	update_110fields();
	std::string form110 = cap110_text_template;

	replacestr(form110, cap110_mission_nbr, s110_mission_nbr );
	replacestr(form110, cap110_station, s110_station );
	replacestr(form110, cap110_date, s110_date );
	replacestr(form110, cap110_ds_a, s110_ds_a );
	replacestr(form110, cap110_ds_b, s110_ds_b );
	replacestr(form110, cap110_ds_c, s110_ds_c );
	replacestr(form110, cap110_ds_d, s110_ds_d );
	replacestr(form110, cap110_ds_e, s110_ds_e );
	replacestr(form110, cap110_ds_f, s110_ds_f );

	std::string logdata;
	std::string lgdata = xLOGDATA;
	const char *fmt = "%-7s|%-12s|%-15s|%s\n";
	char tempstr[200];
	snprintf(tempstr, sizeof(tempstr), fmt, "TIME", "CALL", "CH REF", "REMARKS");

	logdata = tempstr;
	for (int i = 0; i < 23; i++) {
		if (!s110_comm_time[i].empty() ||
			!s110_comm_call[i].empty() ||
			!s110_comm_chref[i].empty() ||
			!s110_comm_rem[i].empty() ) {
			snprintf(tempstr, sizeof(tempstr), fmt,
				s110_comm_time[i].c_str(),
				s110_comm_call[i].c_str(),
				s110_comm_chref[i].c_str(),
				s110_comm_rem[i].c_str());
			logdata.append(tempstr);
		}
	}
	replacestr(form110, lgdata, logdata);

	FILE *file110 = fopen(cap110_fname.c_str(), "w");
	fprintf(file110,"%s", form110.c_str());
	fclose(file110);

	open_url(cap110_fname.c_str());
}

