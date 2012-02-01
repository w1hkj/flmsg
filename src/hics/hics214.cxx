// =====================================================================
//
// hics214.cxx
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
#include "dirent-check.h"

#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Image.H>

using namespace std;

// ---------------------------------------------------------------------
// hics 214 field variables and template variables
// ---------------------------------------------------------------------

string hics214_tag_incident			= ":1:";
string hics214_tag_date				= ":2:";
string hics214_tag_time				= ":2a:";
string hics214_tag_op_period		= ":3:";
string hics214_tag_sec_brch			= ":4:";
string hics214_tag_position			= ":5:";
string hics214_tag_activity_time	= ":T[n]:"; // 30
string hics214_tag_activity_event	= ":E[n]:";
string hics214_tag_prepared_by		= ":7:";
string hics214_tag_facility			= ":8:"; // new field

string hics214_incident;
string hics214_date;
string hics214_time;
string hics214_op_period;
string hics214_sec_brch;
string hics214_position;
string hics214_activity_time[30];
string hics214_activity_event[30];
string hics214_prepared_by;
string hics214_facility;

// =====================================================================

string hics214_buff;
string hics214_def_filename = "";
string hics214_base_filename = "";
string hics214_template_name = "";
bool hics214_using_template = false;

void hics214_cb_set_date()
{
	hics214_txt_date->value(szDate());
}

void hics214_cb_set_time()
{
	hics214_txt_time->value(szTime());
}

void hics214_clear_fields()
{
	hics214_incident.clear();
	hics214_date.clear();
	hics214_time.clear();
	hics214_op_period.clear();
	hics214_sec_brch.clear();
	hics214_position.clear();
	hics214_prepared_by.clear();
	hics214_facility.clear();

	for (int i = 0; i < 30; i++) {
		hics214_activity_time[i].clear();
		hics214_activity_event[i].clear();
	}
}

void hics214_update_fields()
{
	hics214_incident = hics214_txt_incident->value();
	hics214_date = hics214_txt_date->value();
	hics214_time = hics214_txt_time->value();
	hics214_op_period = hics214_txt_op_period->value();
	hics214_sec_brch = hics214_txt_sec_brch->value();
	hics214_position = hics214_txt_position->value();
	hics214_prepared_by = hics214_txt_prepared_by->value();
	hics214_facility = hics214_txt_facility->value();

	for (int i = 0; i < 30; i++) {
		hics214_activity_time[i] = hics214_txt_activity_time[i]->value();
		hics214_activity_event[i] = hics214_txt_activity_event[i]->value();
	}
}

void hics214_update_form()
{
	hics214_txt_incident->value(hics214_incident.c_str());
	hics214_txt_date->value(hics214_date.c_str());
	hics214_txt_time->value(hics214_time.c_str());
	hics214_txt_op_period->value(hics214_op_period.c_str());
	hics214_txt_sec_brch->value(hics214_sec_brch.c_str());
	hics214_txt_position->value(hics214_position.c_str());
	hics214_txt_prepared_by->value(hics214_prepared_by.c_str());
	hics214_txt_facility->value(hics214_facility.c_str());

	for (int i = 0; i < 30; i++) {
		hics214_txt_activity_time[i]->value(hics214_activity_time[i].c_str());
		hics214_txt_activity_event[i]->value(hics214_activity_event[i].c_str());
	}
}

void hics214_clear_form()
{
	hics214_clear_fields();
	hics214_update_form();
}

static string &hics_nn(string & subst, int n)
{
	static string garbage = "#$^*!";
	static string hics;
	hics.clear();
	hics = subst;
	size_t pos = hics.find("[");
	if (pos == string::npos) return garbage;
	pos++;
	hics[pos] = '0' + (n/10 % 10);
	hics[pos+1] = '0' + n % 10;
	hics[pos+2] = ']';
	hics += ':';
	return hics;
}

void hics214_make_buff()
{
	hics214_update_fields();
	hics214_buff.clear();

	hics214_buff = header("<hics214>");

	hics214_buff.append( lineout( hics214_tag_incident, hics214_incident ) );
	hics214_buff.append( lineout( hics214_tag_date, hics214_date ) );
	hics214_buff.append( lineout( hics214_tag_time, hics214_time ) );
	hics214_buff.append( lineout( hics214_tag_op_period, hics214_op_period ) );
	hics214_buff.append( lineout( hics214_tag_sec_brch, hics214_sec_brch) );
	hics214_buff.append( lineout( hics214_tag_position, hics214_position) );
	hics214_buff.append( lineout( hics214_tag_prepared_by, hics214_prepared_by ) );
	hics214_buff.append( lineout( hics214_tag_facility, hics214_facility ) );

	for (int i = 0; i < 30; i++) {
		hics214_buff.append( lineout( hics_nn( hics214_tag_activity_time, i ), hics214_activity_time[i] ) );
		hics214_buff.append( lineout( hics_nn( hics214_tag_activity_event, i ), hics214_activity_event[i] ) );
	}
}

void hics214_read_buffer(string data)
{
	hics214_clear_fields();

	hics214_incident = findstr(data, hics214_tag_incident);
	hics214_date = findstr(data, hics214_tag_date);
	hics214_time = findstr(data, hics214_tag_time);
	hics214_op_period = findstr(data, hics214_tag_op_period);
	hics214_sec_brch = findstr(data, hics214_tag_sec_brch);
	hics214_position = findstr(data, hics214_tag_position);
	hics214_prepared_by = findstr(data, hics214_tag_prepared_by);
	hics214_facility = findstr(data, hics214_tag_facility);

	for (int i = 0; i < 30; i++) {
		hics214_activity_time[i]    = findstr(data, hics_nn( hics214_tag_activity_time, i ) );
		hics214_activity_event[i]   = findstr(data, hics_nn( hics214_tag_activity_event, i ) );
	}

	hics214_update_form();
}

void hics214_cb_new()
{
	hics214_clear_form();
	hics214_def_filename = ICS_msg_dir;
	hics214_def_filename.append("new"HF214_EXT);
	show_filename(hics214_def_filename);
	hics214_using_template = false;
}

void hics214_cb_import()
{
	fl_alert2("Not implemented");
}

void hics214_cb_export()
{
	fl_alert2("Not implemented");
}

void hics214_cb_wrap_import(string wrapfilename, string inpbuffer)
{
	hics214_clear_form();
	hics214_read_buffer(inpbuffer);
	hics214_def_filename = ICS_msg_dir;
	hics214_def_filename.append(wrapfilename);
	show_filename(hics214_def_filename);
	hics214_using_template = false;
}

void hics214_cb_wrap_export()
{
	if (hics214_base_filename == "new"HF214_EXT || hics214_base_filename == "default"HF214_EXT)
		hics214_cb_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(hics214_base_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		hics214_make_buff();
		export_wrapfile(hics214_base_filename, wrapfilename, hics214_buff, pext != ".wrap");
	}
}

void hics214_cb_wrap_autosend()
{
	if (hics214_base_filename == "new"HF214_EXT || 
		hics214_base_filename == "default"HF214_EXT ||
		hics214_using_template == true)
		hics214_cb_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	hics214_make_buff();
	export_wrapfile(hics214_base_filename, wrapfilename, hics214_buff, false);
}

void hics214_cb_load_template()
{
	string hics214_def_filename = hics214_template_name;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"HT214_EXT,
			hics214_def_filename.c_str());
	if (p) {
		hics214_clear_form();
		read_data_file(p);
		hics214_template_name = p;
		show_filename(hics214_template_name);
		hics214_using_template = true;
	}
}

void hics214_cb_save_template()
{
	if (!hics214_using_template) {
		hics214_cb_save_as_template();
		return;
	}
	string hics214_def_filename = hics214_template_name;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"HT214_EXT,
			hics214_def_filename.c_str());
	if (p)
		hics214_write(p);
}

void hics214_cb_save_as_template()
{
	string hics214_def_filename = hics214_template_name;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"HT214_EXT,
			hics214_def_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		hics214_template_name = p;
		if (strlen(pext) == 0) hics214_template_name.append(HT214_EXT);
		remove_spaces_from_filename(hics214_template_name);
		hics214_write(hics214_template_name);
		show_filename(hics214_template_name);
		hics214_using_template = true;
	}
}

void hics214_cb_open()
{
	const char *p = FSEL::select(_("Open data file"), "HICS-214\t*"HF214_EXT,
					hics214_def_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	hics214_clear_form();
	read_data_file(p);
	hics214_using_template = false;
	hics214_def_filename = p;
	show_filename(hics214_def_filename);
}

void hics214_write(string s)
{
	FILE *file214 = fopen(s.c_str(), "w");
	if (!file214) return;
	hics214_make_buff();
	fwrite(hics214_buff.c_str(), hics214_buff.length(), 1, file214);
	fclose(file214);
}

void hics214_cb_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(HF214_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = hics214_def_filename;

	p = FSEL::saveas(_("Save data file"), "HICS-214\t*"HF214_EXT,
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
	hics214_def_filename = p;
	if (strlen(pext) == 0) hics214_def_filename.append(HF214_EXT);

	remove_spaces_from_filename(hics214_def_filename);
	hics214_write(hics214_def_filename);

	hics214_using_template = false;
	show_filename(hics214_def_filename);
}

void hics214_cb_save()
{
	if (hics214_base_filename == "new"HF214_EXT || 
		hics214_base_filename == "default"HF214_EXT ||
		hics214_using_template == true) {
		hics214_cb_save_as();
		return;
	}
	hics214_write(hics214_def_filename);
	hics214_using_template = false;
}

void hics214_cb_html()
{
	string fname_name = fl_filename_name(hics214_def_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string hics214_fname = ICS_dir;
	hics214_fname.append(fname_name);
	hics214_fname.append(".html");

	string html_text = "";

	hics214_update_fields();
	string form214 = hics214_html_template;

	replacestr(form214, TITLE, fname_name);
	replacestr(form214, hics214_tag_incident, hics214_incident );
	replacestr(form214, hics214_tag_date, hics214_date );
	replacestr(form214, hics214_tag_time, hics214_time );
	replacestr(form214, hics214_tag_op_period, hics214_op_period );
	replacestr(form214, hics214_tag_sec_brch, hics214_sec_brch );
	replacestr(form214, hics214_tag_position, hics214_position );
	replacestr(form214, hics214_tag_prepared_by, hics214_prepared_by );
	replacestr(form214, hics214_tag_facility, hics214_facility );

	for (int i = 0; i < 30; i++) {
		replacestr(form214, hics_nn( hics214_tag_activity_time, i ), hics214_activity_time[i] );
		replacestr(form214, hics_nn( hics214_tag_activity_event, i ), hics214_activity_event[i] );
	}

	FILE *file214 = fopen(hics214_fname.c_str(), "w");
	fprintf(file214,"%s", form214.c_str());
	fclose(file214);

	open_url(hics214_fname.c_str());
}

void hics214_cb_msg_type()
{
	if (tabs_msg_type->value() == hics214_tab ) {
		hics214_tab_type->value(hics214_tab_1);
		show_filename(hics214_def_filename);
	}
}

void hics214_cb_textout()
{
	string hics214_fname = ICS_dir;
	hics214_fname.append("hics214.txt");

	hics214_update_fields();
	string form214 = hics214_text_template;

	replacestr(form214, hics214_tag_incident, hics214_incident );
	replacestr(form214, hics214_tag_date, hics214_date );
	replacestr(form214, hics214_tag_time, hics214_time );
	replacestr(form214, hics214_tag_op_period, hics214_op_period );
	replacestr(form214, hics214_tag_sec_brch, hics214_sec_brch );
	replacestr(form214, hics214_tag_position, hics214_position );
	replacestr(form214, hics214_tag_prepared_by, hics214_prepared_by );
	replacestr(form214, hics214_tag_facility, hics214_facility );

	for (int i = 0; i < 30; i++) {
		replacestr(form214, hics_nn( hics214_tag_activity_time, i ), hics214_activity_time[i] );
		replacestr(form214, hics_nn( hics214_tag_activity_event, i ), hics214_activity_event[i] );
	}

	FILE *file214 = fopen(hics214_fname.c_str(), "w");
	fprintf(file214,"%s", form214.c_str());
	fclose(file214);

	open_url(hics214_fname.c_str());
}