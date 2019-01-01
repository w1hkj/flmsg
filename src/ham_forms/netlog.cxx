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

// ---------------------------------------------------------------------
// netlog field variables and template variables
// ---------------------------------------------------------------------

string netlog_event				= ":inc:";
string netlog_date_fm				= ":dfm:";
string netlog_time_fm				= ":tfm:";
string netlog_date_to				= ":dto:";
string netlog_time_to				= ":tto:";
string netlog_prepared_by			= ":pre:";
string netlog_preparer_date_time	= ":dtm:";
string netlog_radio_net				= ":net:";
string netlog_radio_operator		= ":opr:";

string netlog_comm_msg				= ":msg[n]:"; // 60
string netlog_comm_to				= ":to[n]:"; // 60
string netlog_comm_from				= ":fm[n]:"; // 60
string netlog_comm_time				= ":tm[n]:"; // 60

string snetlog_event;
string snetlog_date_fm;
string snetlog_time_fm;
string snetlog_date_to;
string snetlog_time_to;
string snetlog_prepared_by;
string snetlog_preparer_date_time;
string snetlog_radio_net;
string snetlog_radio_operator;

string snetlog_comm_time[60];
string snetlog_comm_from[60];
string snetlog_comm_msg[60];
string snetlog_comm_to[60];

// =====================================================================

string buffnetlog;
string def_netlog_filename = "";
string base_netlog_filename = "";
string def_netlog_TemplateName = "";
bool using_netlog_template = false;

void cb_netlog_set_date_fm()
{
	txt_netlog_date_fm->value(szDate(progStatus.dtformat));
}

void cb_netlog_set_time_fm()
{
	txt_netlog_time_fm->value(szTime(progStatus.UTC));
}

void cb_netlog_set_date_to()
{
	txt_netlog_date_to->value(szDate(progStatus.dtformat));
}

void cb_netlog_set_time_to()
{
	txt_netlog_time_to->value(szTime(progStatus.UTC));
}

void cb_netlog_set_date_time()
{
	string dt = szDate(progStatus.dtformat);
	dt.append(", ").append(szTime(progStatus.UTC));
	txt_netlog_preparer_date_time->value(dt.c_str());
}

void clear_netlogfields()
{
	snetlog_event.clear();
	snetlog_date_fm.clear();
	snetlog_time_fm.clear();
	snetlog_date_to.clear();
	snetlog_time_to.clear();
	snetlog_prepared_by.clear();
	snetlog_preparer_date_time.clear();
	snetlog_radio_net.clear();
	snetlog_radio_operator.clear();

	for (int i = 0; i < 60; i++) {
		snetlog_comm_msg[i].clear();
		snetlog_comm_to[i].clear();
		snetlog_comm_from[i].clear();
	}
}

bool check_netlogfields()
{
	if (snetlog_event != txt_netlog_event->value())
		return true;
	if (snetlog_date_fm != txt_netlog_date_fm->value())
		return true;
	if (snetlog_time_fm != txt_netlog_time_fm->value())
		return true;
	if (snetlog_date_to != txt_netlog_date_to->value())
		return true;
	if (snetlog_time_to != txt_netlog_time_to->value())
		return true;
	if (snetlog_prepared_by != txt_netlog_prepared_by->value())
		return true;
	if (snetlog_radio_net != txt_netlog_radio_net->value())
		return true;
	if (snetlog_radio_operator != txt_netlog_radio_operator->value())
		return true;
	if (snetlog_preparer_date_time != txt_netlog_preparer_date_time->value())
		return true;
	for (int i = 0; i < 60; i++) {
		if (snetlog_comm_time[i] != txt_netlog_comm_time[i]->value())
			return true;
		if (snetlog_comm_msg[i] != txt_netlog_comm_msg[i]->value())
			return true;
		if (snetlog_comm_to[i] != txt_netlog_comm_to[i]->value())
			return true;
		if (snetlog_comm_from[i] != txt_netlog_comm_from[i]->value())
			return true;
	}
	return false;
}

void update_netlogfields()
{
	snetlog_event = txt_netlog_event->value();
	snetlog_date_fm = txt_netlog_date_fm->value();
	snetlog_time_fm = txt_netlog_time_fm->value();
	snetlog_date_to = txt_netlog_date_to->value();
	snetlog_time_to = txt_netlog_time_to->value();
	snetlog_prepared_by = txt_netlog_prepared_by->value();
	snetlog_radio_net = txt_netlog_radio_net->value();
	snetlog_radio_operator = txt_netlog_radio_operator->value();
	snetlog_preparer_date_time = txt_netlog_preparer_date_time->value();
	for (int i = 0; i < 60; i++) {
		snetlog_comm_time[i] = txt_netlog_comm_time[i]->value();
		snetlog_comm_from[i] = txt_netlog_comm_from[i]->value();
		snetlog_comm_to[i] = txt_netlog_comm_to[i]->value();
		snetlog_comm_msg[i] = txt_netlog_comm_msg[i]->value();
	}
}

void update_netlogform()
{
	txt_netlog_event->value(snetlog_event.c_str());
	txt_netlog_date_fm->value(snetlog_date_fm.c_str());
	txt_netlog_time_fm->value(snetlog_time_fm.c_str());
	txt_netlog_date_to->value(snetlog_date_to.c_str());
	txt_netlog_time_to->value(snetlog_time_to.c_str());
	txt_netlog_prepared_by->value(snetlog_prepared_by.c_str());
	txt_netlog_radio_net->value(snetlog_radio_net.c_str());
	txt_netlog_radio_operator->value(snetlog_radio_operator.c_str());
	txt_netlog_preparer_date_time->value(snetlog_preparer_date_time.c_str());

	for (int i = 0; i < 60; i++) {
		txt_netlog_comm_time[i]->value(snetlog_comm_time[i].c_str());
		txt_netlog_comm_to[i]->value(snetlog_comm_to[i].c_str());
		txt_netlog_comm_from[i]->value(snetlog_comm_from[i].c_str());
		txt_netlog_comm_msg[i]->value(snetlog_comm_msg[i].c_str());
	}
}

void clear_netlog_form()
{
	clear_netlogfields();
	update_netlogform();
}

string &netlog_nn(string & subst, int n)
{
	static string garbage = "#$^*!";
	static string nlog;
	nlog.clear();
	nlog = subst;
	size_t pos = nlog.find("[");
	if (pos == string::npos) return garbage;
	pos++;

	nlog[pos] =	n > 49 ? '5' :
				n > 39 ? '4' :
				n > 29 ? '3' :
				n > 19 ? '2' :
				n > 9  ? '1' : '0';
	nlog[pos+1] = '0' + n % 10;
	nlog[pos+2] = ']';
	nlog += ':';

	return nlog;
}

void make_buffnetlog(bool compress = false)
{
	string mbuff;
	mbuff.clear();
	mbuff.append( lineout( netlog_event, snetlog_event ) );
	mbuff.append( lineout( netlog_date_fm, snetlog_date_fm ) );
	mbuff.append( lineout( netlog_time_fm, snetlog_time_fm ) );
	mbuff.append( lineout( netlog_date_to, snetlog_date_to ) );
	mbuff.append( lineout( netlog_time_to, snetlog_time_to ) );
	mbuff.append( lineout( netlog_prepared_by, snetlog_prepared_by ) );
	mbuff.append( lineout( netlog_preparer_date_time, snetlog_preparer_date_time ) );
	mbuff.append( lineout( netlog_radio_net, snetlog_radio_net ) );
	mbuff.append( lineout( netlog_radio_operator, snetlog_radio_operator ) );

	for (int i = 0; i < 60; i++) {
		mbuff.append( lineout( netlog_nn( netlog_comm_time, i ), snetlog_comm_time[i] ) );
		mbuff.append( lineout( netlog_nn( netlog_comm_to, i ),     snetlog_comm_to[i] ) );
		mbuff.append( lineout( netlog_nn( netlog_comm_from, i ),     snetlog_comm_from[i] ) );
		mbuff.append( lineout( netlog_nn( netlog_comm_msg, i ), snetlog_comm_msg[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	buffnetlog.append(mbuff);
}

void read_netlog_buffer(string data)
{
	clear_netlogfields();
	read_header(data);

	snetlog_event = findstr( data, netlog_event );
	snetlog_date_fm = findstr( data, netlog_date_fm );
	snetlog_time_fm  = findstr( data, netlog_time_fm );
	snetlog_date_to = findstr( data, netlog_date_to );
	snetlog_time_to  = findstr( data, netlog_time_to );
	snetlog_prepared_by = findstr( data, netlog_prepared_by );
	snetlog_preparer_date_time = findstr( data, netlog_preparer_date_time );
	snetlog_radio_net = findstr( data, netlog_radio_net );
	snetlog_radio_operator  = findstr( data, netlog_radio_operator );

	for (int i = 0; i < 60; i++) {
		snetlog_comm_time[i]    = findstr( data, netlog_nn( netlog_comm_time, i ) );
		snetlog_comm_to[i]      = findstr( data, netlog_nn( netlog_comm_to, i ) );
		snetlog_comm_from[i]    = findstr( data, netlog_nn( netlog_comm_from, i ) );
		snetlog_comm_msg[i] = findstr( data, netlog_nn( netlog_comm_msg, i ) );
	}

	update_netlogform();
}

void cb_netlog_new()
{
	if (check_netlogfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_netlog_save();
		}
	}
	clear_netlog_form();
	clear_header();
	def_netlog_filename = ICS_msg_dir;
	def_netlog_filename.append("new").append(FNET_EXT);
	show_filename(def_netlog_filename);
	using_netlog_template = false;
}

void cb_netlog_import()
{
	fl_alert2("Not implemented");
}

void cb_netlog_export()
{
	fl_alert2("Not implemented");
}

void cb_netlog_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_netlog_form();
	read_netlog_buffer(inpbuffer);
	def_netlog_filename = ICS_msg_dir;
	def_netlog_filename.append(wrapfilename);
	show_filename(def_netlog_filename);
	using_netlog_template = false;
}

int eval_netlog_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_netlog_filename).append("]");
	update_netlogfields();
	update_header(FROM);
	evalstr.append(header("<netlog>"));
	buffnetlog.clear();
	make_buffnetlog(true);
	if (buffnetlog.empty()) return 0;
	compress_maybe( buffnetlog );
	evalstr.append( buffnetlog );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_netlog_wrap_export()
{
	if (check_netlogfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_netlogfields();

	if (base_netlog_filename == string("new").append(FNET_EXT) ||
		base_netlog_filename == string("default").append(FNET_EXT) )
		if (!cb_netlog_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_netlog_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buffnetlog.assign(header("<netlog>"));
		make_buffnetlog(true);
		export_wrapfile(base_netlog_filename, wrapfilename, buffnetlog, pext != ".wrap");
		write_netlog(def_netlog_filename);
	}
}

void cb_netlog_wrap_autosend()
{
	if (check_netlogfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_netlogfields();

	if (base_netlog_filename == string("new").append(FNET_EXT) ||
		base_netlog_filename == string("default").append(FNET_EXT) )
		cb_netlog_save_as();

	update_header(FROM);
	buffnetlog.assign(header("<netlog>"));
	make_buffnetlog(true);

	xfr_via_socket(base_netlog_filename, buffnetlog);
	write_netlog(def_netlog_filename);
}

void cb_netlog_load_template()
{
	string def_netlog_filename = def_netlog_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TNET_EXT).c_str(),
			def_netlog_filename.c_str());
	if (p) {
		clear_netlog_form();
		read_data_file(p);
		def_netlog_TemplateName = p;
		show_filename(def_netlog_TemplateName);
		using_netlog_template = true;
	}
}

void cb_netlog_save_template()
{
	if (!using_netlog_template) {
		cb_netlog_save_as_template();
		return;
	}
	string def_netlog_filename = def_netlog_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TNET_EXT).c_str(),
			def_netlog_filename.c_str());
	if (p) {
		update_header(CHANGED);
		buffnetlog.assign(header("<netlog>"));
		make_buffnetlog();
		write_netlog(p);
	}
}

void cb_netlog_save_as_template()
{
	string def_netlog_filename = def_netlog_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TNET_EXT).c_str(),
			def_netlog_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_netlog_TemplateName = p;
		if (strlen(pext) == 0) def_netlog_TemplateName.append(TNET_EXT);
		remove_spaces_from_filename(def_netlog_TemplateName);
		clear_header();
		update_header(CHANGED);
		buffnetlog.assign(header("<netlog>"));
		make_buffnetlog();
		write_netlog(def_netlog_TemplateName);
		show_filename(def_netlog_TemplateName);
		using_netlog_template = true;
	}
}

void cb_netlog_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			string("ICS-netlog\t*").append(FNET_EXT).c_str(),
			def_netlog_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_netlog_form();
	read_data_file(p);
	using_netlog_template = false;
	def_netlog_filename = p;
	show_filename(def_netlog_filename);
}

void write_netlog(string s)
{
	FILE *filenetlog = fopen(s.c_str(), "w");
	if (!filenetlog) return;

	fwrite(buffnetlog.c_str(), buffnetlog.length(), 1, filenetlog);
	fclose(filenetlog);
}

bool cb_netlog_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FNET_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_netlog_filename;

	p = FSEL::saveas(
			_("Save data file"),
			string("ICS-netlog\t*").append(FNET_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_netlog_filename = p;
	if (strlen(pext) == 0) def_netlog_filename.append(FNET_EXT);

	remove_spaces_from_filename(def_netlog_filename);
	update_netlogfields();
	update_header(NEW);
	buffnetlog.assign(header("<netlog>"));
	make_buffnetlog();
	write_netlog(def_netlog_filename);

	using_netlog_template = false;
	show_filename(def_netlog_filename);
	return true;
}

void cb_netlog_save()
{
	if (base_netlog_filename == string("new").append(FNET_EXT) || 
		base_netlog_filename == string("default").append(FNET_EXT) ||
		using_netlog_template == true) {
		cb_netlog_save_as();
		return;
	}
	if (check_netlogfields()) update_header(CHANGED);
	update_netlogfields();
	buffnetlog.assign(header("<netlog>"));
	make_buffnetlog();
	write_netlog(def_netlog_filename);
	using_netlog_template = false;
}

void cb_netlog_html()
{
	string fname_name = fl_filename_name(def_netlog_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string netlog_fname = ICS_dir;
	netlog_fname.append(fname_name);
	netlog_fname.append(".html");

	string html_text = "";
	string empty = "<br>";

	update_netlogfields();
	string formnetlog = netlog_html_template;

	replacestr(formnetlog, TITLE, fname_name);
	replacestr(formnetlog, netlog_event, snetlog_event );
	replacestr(formnetlog, netlog_date_fm, snetlog_date_fm );
	replacestr(formnetlog, netlog_time_fm, snetlog_time_fm );
	replacestr(formnetlog, netlog_date_to, snetlog_date_to );
	replacestr(formnetlog, netlog_time_to, snetlog_time_to );
	replacestr(formnetlog, netlog_prepared_by, snetlog_prepared_by );
	replacestr(formnetlog, netlog_preparer_date_time, snetlog_preparer_date_time );
	replacestr(formnetlog, netlog_radio_net, snetlog_radio_net );
	replacestr(formnetlog, netlog_radio_operator, snetlog_radio_operator );

	for (int i = 0; i < 60; i++) {
		replacestr(formnetlog, netlog_nn( netlog_comm_time, i ),
			snetlog_comm_time[i].empty() ? empty : snetlog_comm_time[i] );
		replacestr(formnetlog, netlog_nn( netlog_comm_to, i ), 
			snetlog_comm_to[i].empty() ? empty : snetlog_comm_to[i] );
		replacestr(formnetlog, netlog_nn( netlog_comm_from, i ), 
			snetlog_comm_from[i].empty() ? empty : snetlog_comm_from[i] );
		replacestr(formnetlog, netlog_nn( netlog_comm_msg, i ), 
			snetlog_comm_msg[i].empty() ? empty : snetlog_comm_msg[i] );
	}

	FILE *filenetlog = fopen(netlog_fname.c_str(), "w");
	fprintf(filenetlog,"%s", formnetlog.c_str());
	fclose(filenetlog);

	open_url(netlog_fname.c_str());
}

void cb_netlog_msg_type()
{
	if (tabs_msg_type->value() == tab_netlog ) {
		tab_netlog_type->value(tab_netlog_1);
		show_filename(def_netlog_filename);
	}
}

void cb_netlog_textout()
{
	string netlog_fname = ICS_dir;
	netlog_fname.append("netlog.txt");

	update_netlogfields();
	string formnetlog = netlog_text_template;

	replacestr(formnetlog, netlog_event, snetlog_event );
	replacestr(formnetlog, netlog_date_fm, snetlog_date_fm );
	replacestr(formnetlog, netlog_time_fm, snetlog_time_fm );
	replacestr(formnetlog, netlog_date_to, snetlog_date_to );
	replacestr(formnetlog, netlog_time_to, snetlog_time_to );
	replacestr(formnetlog, netlog_prepared_by, snetlog_prepared_by );
	replacestr(formnetlog, netlog_preparer_date_time, snetlog_preparer_date_time );
	replacestr(formnetlog, netlog_radio_net, snetlog_radio_net );
	replacestr(formnetlog, netlog_radio_operator, snetlog_radio_operator );

	for (int i = 0; i < 60; i++) {
		replacestr(formnetlog, netlog_nn( netlog_comm_time, i ), snetlog_comm_time[i] );
		replacestr(formnetlog, netlog_nn( netlog_comm_msg, i ), snetlog_comm_msg[i] );
		replacestr(formnetlog, netlog_nn( netlog_comm_to, i ), snetlog_comm_to[i] );
		replacestr(formnetlog, netlog_nn( netlog_comm_from, i ), snetlog_comm_from[i] );
	}

	FILE *filenetlog = fopen(netlog_fname.c_str(), "w");
	fprintf(filenetlog,"%s", formnetlog.c_str());
	fclose(filenetlog);

	open_url(netlog_fname.c_str());
}

void netlog_csv(Fl_Widget *w, void *d)
{
	string csv_fname = ICS_dir;
	csv_fname.append("netlog.csv");

	const char *p;

	p = FSEL::saveas(_("Save csv file"), "netlog\t*.csv",
					csv_fname.c_str());

	if (!p) return;
	if (strlen(p) == 0) return;

	csv_fname = p;

	update_netlogfields();

	string cvs_text;
	cvs_text.assign("Event,Start_Date,Start_Time,End_Date,End_Time,Preparer,Prepared_Date,Radio_Net,Radio_operator\n");
	cvs_text.append("\"").append(snetlog_event).append("\",");
	cvs_text.append("\"").append(snetlog_date_fm).append("\",");
	cvs_text.append("\"").append(snetlog_time_fm).append("\",");
	cvs_text.append("\"").append(snetlog_date_to).append("\",");
	cvs_text.append("\"").append(snetlog_time_to).append("\",");
	cvs_text.append("\"").append(snetlog_prepared_by).append("\",");
	cvs_text.append("\"").append(snetlog_preparer_date_time).append("\",");
	cvs_text.append("\"").append(snetlog_radio_net).append("\",");
	cvs_text.append("\"").append(snetlog_radio_operator).append("\"\n");
	cvs_text.append("\n");
	cvs_text.append("COMM_TIME,COMM_TO,COMM_FM,COMM_MSG\n");
	
	for (int i = 0; i < 60; i++) {
		cvs_text.append("\"").append(snetlog_comm_time[i]).append("\",");
		cvs_text.append("\"").append(snetlog_comm_to[i]).append("\",");
		cvs_text.append("\"").append(snetlog_comm_from[i]).append("\",");
		cvs_text.append("\"").append(snetlog_comm_msg[i]).append("\"\n");
	}

	FILE *csv_file = fopen(csv_fname.c_str(), "w");
	if (!csv_file) return;
	fprintf(csv_file,"%s", cvs_text.c_str());
	fclose(csv_file);
}
