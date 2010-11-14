// =====================================================================
//
// ics216.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2010
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  It is
// copyright under the GNU General Public License.
//
// You should have received a copy of the GNU General Public License
// along with the program; if not, write to the Free Software
// Foundation, Inc.
// 59 Temple Place, Suite 330
// Boston, MA  02111-1307 USA
//
// =====================================================================

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
#ifdef __MINGW32__
#  undef dirent
#endif
#include <dirent.h>

#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Image.H>

using namespace std;

// ---------------------------------------------------------------------
// ics 216 field variables and template variables
// ---------------------------------------------------------------------

string ics216_incident					= ":inc:";
string ics216_date						= ":dat:";
string ics216_time						= ":tim:";
string ics216_branch					= ":br:";
string ics216_agc						= ":agc:";
string ics216_op_period					= ":opp:";
string ics216_tac_freq					= ":tfr:";

string ics216_div_grp					= ":div[n]:";
string ics216_agency					= ":agy[n]:";

string ics216_ag						= ":ag[n]:";
string ics216_id						= ":id[n]:";
string ics216_rr						= ":rr[n]:";

string ics216_prepared_by				= ":pre:";

string s216_incident;
string s216_date;
string s216_time;
string s216_branch;
string s216_agc;
string s216_op_period;
string s216_tac_freq;

string s216_div_grp[4];
string s216_agency[4];
string s216_ag[36];
string s216_id[36];
string s216_rr[36];

string s216_prepared_by;

// =====================================================================

string buff216;
string def_216_filename = "";
string base_216_filename = "";
string def_216_TemplateName = "";
bool using_ics216_template = false;

void cb_216_set_date()
{
	txt_216_date->value(szDate());
}

void cb_216_set_time()
{
	txt_216_time->value(szTime());
}

void clear_216fields()
{
	s216_incident.clear();
	s216_date.clear();
	s216_time.clear();
	s216_branch.clear();
	s216_agc.clear();
	s216_op_period.clear();
	s216_tac_freq.clear();
	s216_prepared_by.clear();

	for (int i = 0; i < 4; i++) {
		s216_div_grp[i].clear();
		s216_agency[i].clear();
	}
	for (int i = 0; i < 36; i++) {
		s216_ag[i].clear();
		s216_id[i].clear();
		s216_rr[i].clear();
	}
}

void update_216fields()
{
	s216_incident = txt_216_incident->value();
	s216_date = txt_216_date->value();
	s216_time = txt_216_time->value();
	s216_branch = txt_216_branch->value();
	s216_agc = txt_216_agc->value();
	s216_op_period = txt_216_op_period->value();
	s216_tac_freq = txt_216_tac_freq->value();
	s216_prepared_by = txt_216_prepared_by->value();

	for (int i = 0; i < 4; i++) {
		s216_div_grp[i] = txt_216_div_grp[i]->value();
		s216_agency[i] = txt_216_agency[i]->value();
	}
	for (int i = 0; i < 36; i++) {
		s216_ag[i] = txt_216_ag[i]->value();
		s216_id[i] = txt_216_id[i]->value();
		s216_rr[i] = txt_216_rr[i]->value();
	}
}

void update_216form()
{
	txt_216_incident->value(s216_incident.c_str());
	txt_216_date->value(s216_date.c_str());
	txt_216_time->value(s216_time.c_str());
	txt_216_branch->value(s216_branch.c_str());
	txt_216_agc->value(s216_agc.c_str());
	txt_216_op_period->value(s216_op_period.c_str());
	txt_216_tac_freq->value(s216_tac_freq.c_str());
	txt_216_prepared_by->value(s216_prepared_by.c_str());

	for (int i = 0; i < 4; i++) {
		txt_216_div_grp[i]->value(s216_div_grp[i].c_str());
		txt_216_agency[i]->value(s216_agency[i].c_str());
	}
	for (int i = 0; i < 36; i++) {
		txt_216_ag[i]->value(s216_ag[i].c_str());
		txt_216_id[i]->value(s216_id[i].c_str());
		txt_216_rr[i]->value(s216_rr[i].c_str());
	}
}

void clear_216_form()
{
	clear_216fields();
	update_216form();
}

string &ics_216_nn(string & subst, int n)
{
	static string garbage = "#$^*!";
	static string ics;
	ics.clear();
	ics = subst;
	size_t pos = ics.find("[");
	if (pos == string::npos) return garbage;
	pos++;
	if (n < 10)
		ics[pos] = '0' + n;
	else {
		if (n < 20)
			ics[pos] = '1';
		else if ( n < 30)
			ics[pos] = '2';
		else if (n < 40)
			ics[pos] = '3';
		ics[pos+1] = '0' + n % 10;
		ics[pos+2] = ']';
		ics += ':';
	}
	return ics;
}

void make_buff216()
{
	update_216fields();
	buff216.clear();

	buff216 = header("<ics216>");

	buff216.append( lineout( ics216_incident, s216_incident ) );
	buff216.append( lineout( ics216_date, s216_date ) );
	buff216.append( lineout( ics216_time, s216_time ) );
	buff216.append( lineout( ics216_branch, s216_branch ) );
	buff216.append( lineout( ics216_agc, s216_agc ) );
	buff216.append( lineout( ics216_op_period, s216_op_period ) );
	buff216.append( lineout( ics216_tac_freq, s216_tac_freq ) );
	buff216.append( lineout( ics216_prepared_by, s216_prepared_by ) );

	for (int i = 0; i < 4; i++) {
		buff216.append( lineout( ics_216_nn( ics216_div_grp, i), s216_div_grp[i] ) );
		buff216.append( lineout( ics_216_nn( ics216_agency, i), s216_agency[i] ) );
	}
	for (int i = 0; i < 36; i++) {
		buff216.append( lineout( ics_216_nn( ics216_ag, i), s216_ag[i] ) );
		buff216.append( lineout( ics_216_nn( ics216_id, i), s216_id[i] ) );
		buff216.append( lineout( ics_216_nn( ics216_rr, i), s216_rr[i] ) );
	}
}

void read_216_buffer(string data)
{
	clear_216fields();

	s216_incident = findstr( data, ics216_incident );
	s216_date = findstr( data, ics216_date );
	s216_time = findstr( data, ics216_time );
	s216_branch = findstr( data, ics216_branch );
	s216_agc = findstr( data, ics216_agc );
	s216_op_period = findstr( data, ics216_op_period );
	s216_tac_freq = findstr( data, ics216_tac_freq );
	s216_prepared_by = findstr( data, ics216_prepared_by );

	for (int i = 0; i < 4; i++) {
		s216_div_grp[i] = findstr( data, ics_216_nn( ics216_div_grp, i ) );
		s216_agency[i] = findstr( data, ics_216_nn( ics216_agency, i ) );
	}
	for (int i = 0; i < 36; i++) {
		s216_ag[i] = findstr( data, ics_216_nn( ics216_ag, i ) );
		s216_id[i] = findstr( data, ics_216_nn( ics216_id, i ) );
		s216_rr[i] = findstr( data, ics_216_nn( ics216_rr, i ) );
	}

	update_216form();
}

void cb_216_new()
{
	clear_216_form();
	def_216_filename = ICS_msg_dir;
	def_216_filename.append("new"F216_EXT);
	show_filename(def_216_filename);
	using_ics216_template = false;
}

void cb_216_import()
{
	fl_alert2("Not implemented");
}

void cb_216_export()
{
	fl_alert2("Not implemented");
}

void cb_216_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_216_form();
	read_216_buffer(inpbuffer);
	def_216_filename = ICS_msg_dir;
	def_216_filename.append(wrapfilename);
	show_filename(def_216_filename);
	using_ics216_template = false;
}

void cb_216_wrap_export()
{
	if (base_216_filename == "new"F216_EXT || base_216_filename == "default"F216_EXT)
		cb_216_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_216_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_buff216();
		export_wrapfile(base_216_filename, wrapfilename, buff216, pext != ".wrap");
	}
}

void cb_216_wrap_autosend()
{
	if (base_216_filename == "new"F216_EXT || 
		base_216_filename == "default"F216_EXT ||
		using_ics216_template == true)
		cb_216_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buff216();
	export_wrapfile(base_216_filename, wrapfilename, buff216, false);
}

void cb_216_load_template()
{
	string def_216_filename = def_216_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"T216_EXT,
			def_216_filename.c_str());
	if (p) {
		clear_216_form();
		read_data_file(p);
		def_216_TemplateName = p;
		show_filename(def_216_TemplateName);
		using_ics216_template = true;
	}
}

void cb_216_save_template()
{
	if (!using_ics216_template) {
		cb_216_save_as_template();
		return;
	}
	string def_216_filename = def_216_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"T216_EXT,
			def_216_filename.c_str());
	if (p)
		write_216(p);
}

void cb_216_save_as_template()
{
	string def_216_filename = def_216_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"T216_EXT,
			def_216_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_216_TemplateName = p;
		if (strlen(pext) == 0) def_216_TemplateName.append(T216_EXT);
		remove_spaces_from_filename(def_216_TemplateName);
		write_216(def_216_TemplateName);
		show_filename(def_216_TemplateName);
		using_ics216_template = true;
	}
}

void cb_216_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-216\t*"F216_EXT,
					def_216_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_216_form();
	read_data_file(p);
	using_ics216_template = false;
	def_216_filename = p;
	show_filename(def_216_filename);
}

void write_216(string s)
{
	FILE *file216 = fopen(s.c_str(), "w");
	if (!file216) return;
	make_buff216();
	fwrite(buff216.c_str(), buff216.length(), 1, file216);
	fclose(file216);
}

void cb_216_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(F216_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_216_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-216\t*"F216_EXT,
					newfilename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	if (progStatus.sernbr_fname) {
		string haystack = p;
		if (haystack.find(newfilename) != string::npos) {
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
	def_216_filename = p;
	if (strlen(pext) == 0) def_216_filename.append(F216_EXT);

	remove_spaces_from_filename(def_216_filename);
	write_216(def_216_filename);

	using_ics216_template = false;
	show_filename(def_216_filename);
}

void cb_216_save()
{
	if (base_216_filename == "new"F216_EXT || 
		base_216_filename == "default"F216_EXT ||
		using_ics216_template == true) {
		cb_216_save_as();
		return;
	}
	write_216(def_216_filename);
	using_ics216_template = false;
}

void cb_216_html()
{
	string ics216_fname = ICS_dir;
	string html_text = "";
	ics216_fname.append("ics216_doc.html");

	update_216fields();
	string form216 = ics216_html_template;

	replacestr(form216, ics216_incident, s216_incident );
	replacestr(form216, ics216_date, s216_date );
	replacestr(form216, ics216_time, s216_time );
	replacestr(form216, ics216_branch, s216_branch );
	replacestr(form216, ics216_agc, s216_agc );
	replacestr(form216, ics216_op_period, s216_op_period );
	replacestr(form216, ics216_tac_freq, s216_tac_freq );
	replacestr(form216, ics216_prepared_by, s216_prepared_by );

	for (int i = 0; i < 4; i++) {
		replacestr(form216, ics_216_nn( ics216_div_grp, i), s216_div_grp[i] );
		replacestr(form216, ics_216_nn( ics216_agency, i), s216_agency[i] );
	}
	for (int i = 0; i < 36; i++) {
		replacestr(form216, ics_216_nn( ics216_ag, i), s216_ag[i] );
		replacestr(form216, ics_216_nn( ics216_id, i), s216_id[i] );
		replacestr(form216, ics_216_nn( ics216_rr, i), s216_rr[i] );
	}

	FILE *file216 = fopen(ics216_fname.c_str(), "w");
	fprintf(file216,"%s", form216.c_str());
	fclose(file216);

	open_url(ics216_fname.c_str());
}

void cb_216_msg_type()
{
	if (tabs_msg_type->value() == tab_ics216 ) {
		tab_ics216_type->value(tab_216_1);
		show_filename(def_216_filename);
	}
}

void cb_216_textout()
{
	string ics216_fname = ICS_dir;
	ics216_fname.append("ics216.txt");

	update_216fields();
	string form216 = ics216_text_template;

	replacestr(form216, ics216_incident, s216_incident );
	replacestr(form216, ics216_date, s216_date );
	replacestr(form216, ics216_time, s216_time );
	replacestr(form216, ics216_branch, s216_branch );
	replacestr(form216, ics216_agc, s216_agc );
	replacestr(form216, ics216_op_period, s216_op_period );
	replacestr(form216, ics216_tac_freq, s216_tac_freq );
	replacestr(form216, ics216_prepared_by, s216_prepared_by );

	for (int i = 0; i < 4; i++) {
		replacestr(form216, ics_216_nn( ics216_div_grp, i), s216_div_grp[i] );
		replacestr(form216, ics_216_nn( ics216_agency, i), s216_agency[i] );
	}
	for (int i = 0; i < 36; i++) {
		replacestr(form216, ics_216_nn( ics216_ag, i), s216_ag[i] );
		replacestr(form216, ics_216_nn( ics216_id, i), s216_id[i] );
		replacestr(form216, ics_216_nn( ics216_rr, i), s216_rr[i] );
	}

	FILE *file216 = fopen(ics216_fname.c_str(), "w");
	fprintf(file216,"%s", form216.c_str());
	fclose(file216);

	open_url(ics216_fname.c_str());
}
