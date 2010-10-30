// =====================================================================
//
// ics206.cxx
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

// ics206 fields

string ics206_name                 = "<nam:";
string ics206_period               = "<opp:";
string ics206_date_prepared        = "<dat:";
string ics206_time_prepared        = "<tim:";
string ics206_procedure            = "<proc:";
string ics206_preparer             = "<prep:";
string ics206_reviewer             = "<rvwr:";

string ics206_medaid_sta           = "<msta0:"; // array of 5
string ics206_medaid_loc           = "<mloc0:"; // ...
string ics206_medaid_paramedics    = "<mpar0:"; // bool

string ics206_transport_name       = "<tname0:"; // array of 5
string ics206_transport_address    = "<taddr0:"; // ...
string ics206_transport_phone      = "<tphon0:";
string ics206_transport_paramedics = "<tpara0:"; // bool

string ics206_ambulance_name       = "<aname0:"; // array of 5
string ics206_ambulance_loc        = "<aloca0:"; // ...
string ics206_ambulance_paramedics = "<apara0:"; // bool

string ics206_hosp_name            = "<hname0:"; // array of 5
string ics206_hosp_address         = "<haddr0:"; // ...
string ics206_hosp_phone           = "<hphon0:";
string ics206_hosp_airtime         = "<hatim0:";
string ics206_hosp_gndtime         = "<hgtim0:";
string ics206_hosp_helipad         = "<hheli0:"; // bool (5)
string ics206_hosp_burn_center     = "<hburn0:"; // ...

string s206_name;
string s206_period;
string s206_date_prepared;
string s206_time_prepared;
string s206_procedure;
string s206_preparer;
string s206_reviewer;

string s206_medaid_sta[5];
string s206_medaid_loc[5];
bool   b206_medaid_paramedics[5];
string s206_transport_name[5];
string s206_transport_address[5];
string s206_transport_phone[5];
bool   b206_transport_paramedics[5];
string s206_ambulance_name[5];
string s206_ambulance_loc[5];
bool   b206_ambulance_paramedics[5];
string s206_hosp_name[5];
string s206_hosp_address[5];
string s206_hosp_phone[5];
string s206_hosp_airtime[5];
string s206_hosp_gndtime[5];
bool   b206_hosp_helipad[5];
bool   b206_hosp_burn_center[5];

string buff206;
string def_206_filename = "";
string base_206_filename = "";
string def_206_TemplateName = "";
bool using_ics206_template = false;

void cb_206_setdate()
{
	txt_206_date_prepared->value(szDate());
}

void cb_206_settime()
{
	txt_206_time_prepared->value(szTime());
}

void clear_206fields()
{
	s206_name.clear();
	s206_period.clear();
	s206_date_prepared.clear();
	s206_time_prepared.clear();
	s206_procedure.clear();
	s206_preparer.clear();
	s206_reviewer.clear();

	for (int i = 0; i < 5; i++) {
		s206_medaid_sta[i].clear();
		s206_medaid_loc[i].clear();
		s206_transport_name[i].clear();
		s206_transport_address[i].clear();
		s206_transport_phone[i].clear();
		s206_ambulance_name[i].clear();
		s206_ambulance_loc[i].clear();
		s206_hosp_name[i].clear();
		s206_hosp_address[i].clear();
		s206_hosp_phone[i].clear();
		s206_hosp_airtime[i].clear();
		s206_hosp_gndtime[i].clear();

		b206_medaid_paramedics[i] = false;
		b206_transport_paramedics[i] = false;
		b206_ambulance_paramedics[i] = false;
		b206_hosp_helipad[i] = false;
		b206_hosp_burn_center[i] = false;
	}
}

void update_206fields()
{
	s206_name = txt_206_name->value();
	s206_period = txt_206_op_period->value();
	s206_date_prepared = txt_206_date_prepared->value();
	s206_time_prepared = txt_206_time_prepared->value();
	s206_procedure = txt_206_procedure->buffer()->text();
	s206_preparer = txt_206_preparer->value();
	s206_reviewer = txt_206_reviewer->value();

	for (int i = 0; i < 5; i++) {
		s206_medaid_sta[i] = txt_206_medaid_sta[i]->value();
		s206_medaid_loc[i] = txt_206_medaid_loc[i]->value();
		s206_transport_name[i] = txt_206_transport_name[i]->value();
		s206_transport_address[i] = txt_206_transport_address[i]->value();
		s206_transport_phone[i] = txt_206_transport_phone[i]->value();
		s206_ambulance_name[i] = txt_206_ambulance_name[i]->value();
		s206_ambulance_loc[i] = txt_206_ambulance_loc[i]->value();
		s206_hosp_name[i] = txt_206_hosp_name[i]->value();
		s206_hosp_address[i] = txt_206_hosp_address[i]->value();
		s206_hosp_phone[i] = txt_206_hosp_phone[i]->value();
		s206_hosp_airtime[i] = txt_206_hosp_airtime[i]->value();
		s206_hosp_gndtime[i] = txt_206_hosp_gndtime[i]->value();

		b206_medaid_paramedics[i] = btn_206_medaid_paramedics[i]->value();
		b206_transport_paramedics[i] = btn_206_transport_paramedics[i]->value();
		b206_ambulance_paramedics[i] = btn_206_ambulance_paramedics[i]->value();
		b206_hosp_helipad[i] = btn_206_hosp_helipad[i]->value();
		b206_hosp_burn_center[i] = btn_206_hosp_burn_center[i]->value();
	}
}

void update_206form()
{
	txt_206_name->value(s206_name.c_str());
	txt_206_op_period->value(s206_period.c_str());
	txt_206_date_prepared->value(s206_date_prepared.c_str());
	txt_206_time_prepared->value(s206_time_prepared.c_str());
	txt_206_procedure->addstr(s206_procedure.c_str());
	txt_206_preparer->value(s206_preparer.c_str());
	txt_206_reviewer->value(s206_reviewer.c_str());

	for (int i = 0; i < 5; i++) {
		txt_206_medaid_sta[i]->value(s206_medaid_sta[i].c_str());
		txt_206_medaid_loc[i]->value(s206_medaid_loc[i].c_str());
		txt_206_transport_name[i]->value(s206_transport_name[i].c_str());
		txt_206_transport_address[i]->value(s206_transport_address[i].c_str());
		txt_206_transport_phone[i]->value(s206_transport_phone[i].c_str());
		txt_206_ambulance_name[i]->value(s206_ambulance_name[i].c_str());
		txt_206_ambulance_loc[i]->value(s206_ambulance_loc[i].c_str());
		txt_206_hosp_name[i]->value(s206_hosp_name[i].c_str());
		txt_206_hosp_address[i]->value(s206_hosp_address[i].c_str());
		txt_206_hosp_phone[i]->value(s206_hosp_phone[i].c_str());
		txt_206_hosp_airtime[i]->value(s206_hosp_airtime[i].c_str());
		txt_206_hosp_gndtime[i]->value(s206_hosp_gndtime[i].c_str());

		btn_206_medaid_paramedics[i]->value(b206_medaid_paramedics[i]);
		btn_206_transport_paramedics[i]->value(b206_transport_paramedics[i]);
		btn_206_ambulance_paramedics[i]->value(b206_ambulance_paramedics[i]);
		btn_206_hosp_helipad[i]->value(b206_hosp_helipad[i]);
		btn_206_hosp_burn_center[i]->value(b206_hosp_burn_center[i]);
	}
}

void clear_206_form()
{
	clear_206fields();

	txt_206_name->value("");
	txt_206_op_period->value("");
	txt_206_date_prepared->value("");
	txt_206_time_prepared->value("");
	txt_206_procedure->clear();
	txt_206_preparer->value("");
	txt_206_reviewer->value("");

	for (int i = 0; i < 5; i++) {
		txt_206_medaid_sta[i]->value("");
		txt_206_medaid_loc[i]->value("");
		txt_206_transport_name[i]->value("");
		txt_206_transport_address[i]->value("");
		txt_206_transport_phone[i]->value("");
		txt_206_ambulance_name[i]->value("");
		txt_206_ambulance_loc[i]->value("");
		txt_206_hosp_name[i]->value("");
		txt_206_hosp_address[i]->value("");
		txt_206_hosp_phone[i]->value("");
		txt_206_hosp_airtime[i]->value("");
		txt_206_hosp_gndtime[i]->value("");

		btn_206_medaid_paramedics[i]->value(false);
		btn_206_transport_paramedics[i]->value(false);
		btn_206_ambulance_paramedics[i]->value(false);
		btn_206_hosp_helipad[i]->value(false);
		btn_206_hosp_burn_center[i]->value(false);
	}
}

void make_buff206()
{
	update_206fields();
	buff206.clear();

	buff206 = header("<ics206>");

	buff206.append( lineout( ics206_name, s206_name ) );
	buff206.append( lineout( ics206_period, s206_period ) );
	buff206.append( lineout( ics206_date_prepared, s206_date_prepared ) );
	buff206.append( lineout( ics206_time_prepared, s206_time_prepared ) );
	buff206.append( lineout( ics206_procedure, s206_procedure ) );
	buff206.append( lineout( ics206_preparer, s206_preparer ) );
	buff206.append( lineout( ics206_reviewer, s206_reviewer ) );

	for (int i = 0; i < 5; i++) {
		ics206_medaid_sta[5] = ics206_medaid_loc[5] = ics206_medaid_paramedics[5] =
		ics206_transport_address[6] = ics206_transport_name[6] =
		ics206_transport_phone[6] = ics206_transport_paramedics[6] =
		ics206_ambulance_loc[6] = ics206_ambulance_name[6] = ics206_ambulance_paramedics[6] =
		ics206_hosp_address[6] = ics206_hosp_name[6] =
		ics206_hosp_airtime[6] = ics206_hosp_gndtime[6] =
		ics206_hosp_phone[6] = ics206_hosp_helipad[6] =
		ics206_hosp_burn_center[6] = '0' + i;

		buff206.append( lineout( ics206_medaid_sta, s206_medaid_sta[i] ) );
		buff206.append( lineout( ics206_medaid_loc, s206_medaid_loc[i] ) );
		buff206.append( binout( ics206_medaid_paramedics, b206_medaid_paramedics[i] ) );

		buff206.append( lineout( ics206_transport_address, s206_transport_address[i] ) );
		buff206.append( lineout( ics206_transport_name, s206_transport_name[i] ) );
		buff206.append( lineout( ics206_transport_phone, s206_transport_phone[i] ) );
		buff206.append( binout( ics206_transport_paramedics, b206_transport_paramedics[i] ) );

		buff206.append( lineout( ics206_ambulance_loc, s206_ambulance_loc[i] ) );
		buff206.append( lineout( ics206_ambulance_name, s206_ambulance_name[i] ) );
		buff206.append( binout( ics206_ambulance_paramedics, b206_ambulance_paramedics[i] ) );

		buff206.append( lineout( ics206_hosp_name, s206_hosp_name[i] ) );
		buff206.append( lineout( ics206_hosp_address, s206_hosp_address[i] ) );
		buff206.append( lineout( ics206_hosp_phone, s206_hosp_phone[i] ) );
		buff206.append( lineout( ics206_hosp_airtime, s206_hosp_airtime[i] ) );
		buff206.append( lineout( ics206_hosp_gndtime, s206_hosp_gndtime[i] ) );
		buff206.append( binout( ics206_hosp_helipad, b206_hosp_helipad[i] ) );
		buff206.append( binout( ics206_hosp_burn_center, b206_hosp_burn_center[i] ) );
	}

}

void read_206_buffer(string data)
{
	clear_206fields();

	s206_name = findstr(data, ics206_name);
	s206_period = findstr(data, ics206_period);
	s206_date_prepared = findstr(data, ics206_date_prepared);
	s206_time_prepared = findstr(data, ics206_time_prepared);
	s206_procedure = findstr(data, ics206_procedure);
	s206_preparer = findstr(data, ics206_preparer);
	s206_reviewer = findstr(data, ics206_reviewer);

	for (int i = 0; i < 5; i++) {
		ics206_medaid_sta[5] = ics206_medaid_loc[5] = ics206_medaid_paramedics[5] =
		ics206_transport_address[6] = ics206_transport_name[6] =
		ics206_transport_phone[6] = ics206_transport_paramedics[6] =
		ics206_ambulance_loc[6] = ics206_ambulance_name[6] = ics206_ambulance_paramedics[6] =
		ics206_hosp_address[6] = ics206_hosp_name[6] =
		ics206_hosp_airtime[6] = ics206_hosp_gndtime[6] =
		ics206_hosp_phone[6] = ics206_hosp_helipad[6] =
		ics206_hosp_burn_center[6] = '0' + i;

		s206_medaid_sta[i] = findstr(data, ics206_medaid_sta);
		s206_medaid_loc[i] = findstr(data, ics206_medaid_loc);
		b206_medaid_paramedics[i] = findbin(data, ics206_medaid_paramedics);

		s206_transport_address[i] = findstr(data, ics206_transport_address);
		s206_transport_name[i] = findstr(data, ics206_transport_name);
		s206_transport_phone[i] = findstr(data, ics206_transport_phone);
		b206_transport_paramedics[i] = findbin(data, ics206_transport_paramedics);

		s206_ambulance_loc[i] = findstr(data, ics206_ambulance_loc);
		s206_ambulance_name[i] = findstr(data, ics206_ambulance_name);
		b206_ambulance_paramedics[i] = findbin(data, ics206_ambulance_paramedics);

		s206_hosp_name[i] = findstr(data, ics206_hosp_name);
		s206_hosp_address[i] = findstr(data, ics206_hosp_address);
		s206_hosp_phone[i] = findstr(data, ics206_hosp_phone);
		s206_hosp_airtime[i] = findstr(data, ics206_hosp_airtime);
		s206_hosp_gndtime[i] = findstr(data, ics206_hosp_gndtime);
		b206_hosp_helipad[i] = findbin(data, ics206_hosp_helipad);
		b206_hosp_burn_center[i] = findbin(data, ics206_hosp_burn_center);
	}
	update_206form();
}

void cb_206_new()
{
	clear_206_form();
	def_206_filename = ICS_msg_dir;
	def_206_filename.append("new"F206_EXT);
	show_filename(def_206_filename);
	using_ics206_template = false;
}

void cb_206_import()
{
	fl_alert2("Not implemented");
}

void cb_206_export()
{
	fl_alert2("Not implemented");
}

void cb_206_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_206_form();
	read_206_buffer(inpbuffer);
	def_206_filename = ICS_msg_dir;
	def_206_filename.append(wrapfilename);
	show_filename(def_206_filename);
	using_ics206_template = false;
}

void cb_206_wrap_export()
{
	if (base_206_filename == "new"F206_EXT || base_206_filename == "default"F206_EXT)
		cb_206_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_206_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_buff206();
		export_wrapfile(base_206_filename, wrapfilename, buff206, pext != ".wrap");
	}
}

void cb_206_wrap_autosend()
{
	if (base_206_filename == "new"F206_EXT || 
		base_206_filename == "default"F206_EXT ||
		using_ics206_template == true)
		cb_206_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buff206();
	export_wrapfile(base_206_filename, wrapfilename, buff206, false);
}

void cb_206_load_template()
{
	string def_206_filename = def_206_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"T206_EXT,
			def_206_filename.c_str());
	if (p) {
		clear_206_form();
		read_data_file(p);
		def_206_TemplateName = p;
		show_filename(def_206_TemplateName);
		using_ics206_template = true;
	}
}

void cb_206_save_template()
{
	if (!using_ics206_template) {
		cb_206_save_as_template();
		return;
	}
	string def_206_filename = def_206_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"T206_EXT,
			def_206_filename.c_str());
	if (p)
		write_206(p);
}

void cb_206_save_as_template()
{
	string def_206_filename = def_206_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"T206_EXT,
			def_206_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_206_TemplateName = p;
		if (strlen(pext) == 0) def_206_TemplateName.append(T206_EXT);
		remove_spaces_from_filename(def_206_TemplateName);
		write_206(def_206_TemplateName);
		show_filename(def_206_TemplateName);
		using_ics206_template = true;
	}
}

void cb_206_open()
{
	const char *p = FSEL::select(_("Open data file"), "206\t*"F206_EXT,
					def_206_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_206_form();
	read_data_file(p);
	using_ics206_template = false;
	def_206_filename = p;
	show_filename(def_206_filename);
}

void write_206(string s)
{
	FILE *file206 = fopen(s.c_str(), "w");
	if (!file206) return;
	make_buff206();
	fwrite(buff206.c_str(), buff206.length(), 1, file206);
	fclose(file206);
}

void cb_206_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(F206_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_206_filename;

	p = FSEL::saveas(_("Save data file"), "206\t*"F206_EXT,
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
	def_206_filename = p;
	if (strlen(pext) == 0) def_206_filename.append(F206_EXT);

	remove_spaces_from_filename(def_206_filename);
	write_206(def_206_filename);

	using_ics206_template = false;
	show_filename(def_206_filename);
}

void cb_206_save()
{
	if (base_206_filename == "new"F206_EXT || 
		base_206_filename == "default"F206_EXT ||
		using_ics206_template == true) {
		cb_206_save_as();
		return;
	}
	write_206(def_206_filename);
	using_ics206_template = false;
}

string yes = "YES";
string no =  "";

void cb_206_html()
{
	string ics206_fname = ICS_dir;
	string html_text = "";
	ics206_fname.append("ics206_doc.html");

	update_206fields();
	string form206 = ics206_html_template;

	replacestr(form206, ics206_name, s206_name);
	replacestr(form206, ics206_period, s206_period);
	replacestr(form206, ics206_date_prepared, s206_date_prepared);
	replacestr(form206, ics206_time_prepared, s206_time_prepared);
	for (int i = 0; i < 5; i++) {
		ics206_medaid_sta[5] = ics206_medaid_loc[5] = ics206_medaid_paramedics[5] =
		ics206_transport_address[6] = ics206_transport_name[6] =
		ics206_transport_phone[6] = ics206_transport_paramedics[6] =
		ics206_ambulance_loc[6] = ics206_ambulance_name[6] = ics206_ambulance_paramedics[6] =
		ics206_hosp_address[6] = ics206_hosp_name[6] =
		ics206_hosp_airtime[6] = ics206_hosp_gndtime[6] =
		ics206_hosp_phone[6] = ics206_hosp_helipad[6] =
		ics206_hosp_burn_center[6] = '0' + i;
		replacestr(form206, ics206_medaid_sta, s206_medaid_sta[i]);
		replacestr(form206, ics206_medaid_loc, s206_medaid_loc[i]);
		replacestr(form206, ics206_medaid_paramedics, b206_medaid_paramedics[i] ? yes : no);
		replacestr(form206, ics206_transport_name, s206_transport_name[i]);
		replacestr(form206, ics206_transport_address, s206_transport_address[i]);
		replacestr(form206, ics206_transport_phone, s206_transport_phone[i]);
		replacestr(form206, ics206_transport_paramedics, b206_transport_paramedics[i] ? yes : no);
		replacestr(form206, ics206_ambulance_name, s206_ambulance_name[i]);
		replacestr(form206, ics206_ambulance_loc, s206_ambulance_loc[i]);
		replacestr(form206, ics206_ambulance_paramedics, b206_ambulance_paramedics[i] ? yes : no);
		replacestr(form206, ics206_hosp_name, s206_hosp_name[i]);
		replacestr(form206, ics206_hosp_address, s206_hosp_address[i]);
		replacestr(form206, ics206_hosp_phone, s206_hosp_phone[i]);
		replacestr(form206, ics206_hosp_airtime, s206_hosp_airtime[i]);
		replacestr(form206, ics206_hosp_gndtime, s206_hosp_gndtime[i]);
		replacestr(form206, ics206_hosp_helipad, b206_hosp_helipad[i] ? yes : no);
		replacestr(form206, ics206_hosp_burn_center, b206_hosp_burn_center[i] ? yes : no);
	}
	replacestr(form206, ics206_procedure, s206_procedure);
	replacestr(form206, ics206_preparer, s206_preparer);
	replacestr(form206, ics206_reviewer, s206_reviewer);

	FILE *file206 = fopen(ics206_fname.c_str(), "w");
	fprintf(file206,"%s", form206.c_str());
	fclose(file206);

	open_url(ics206_fname.c_str());
}

void cb_206_msg_type()
{
	if (tabs_msg_type->value() == tab_ics206 ) {
		tab_ics206_type->value(tab_206_med_plan);
		show_filename(def_206_filename);
	}
}

void cb_206_textout()
{
	string ics206_fname = ICS_dir;
	ics206_fname.append("ics206.txt");

	update_206fields();
	string form206 = ics206_text_template;

	replacestr(form206, ics206_name, s206_name);
	replacestr(form206, ics206_period, s206_period);
	replacestr(form206, ics206_date_prepared, s206_date_prepared);
	replacestr(form206, ics206_time_prepared, s206_time_prepared);
	for (int i = 0; i < 5; i++) {
		ics206_medaid_sta[5] = ics206_medaid_loc[5] = ics206_medaid_paramedics[5] =
		ics206_transport_address[6] = ics206_transport_name[6] =
		ics206_transport_phone[6] = ics206_transport_paramedics[6] =
		ics206_ambulance_loc[6] = ics206_ambulance_name[6] = ics206_ambulance_paramedics[6] =
		ics206_hosp_address[6] = ics206_hosp_name[6] =
		ics206_hosp_airtime[6] = ics206_hosp_gndtime[6] =
		ics206_hosp_phone[6] = ics206_hosp_helipad[6] =
		ics206_hosp_burn_center[6] = '0' + i;
		replacestr(form206, ics206_medaid_sta, s206_medaid_sta[i]);
		replacestr(form206, ics206_medaid_loc, s206_medaid_loc[i]);
		replacestr(form206, ics206_medaid_paramedics, b206_medaid_paramedics[i] ? yes : no);
		replacestr(form206, ics206_transport_name, s206_transport_name[i]);
		replacestr(form206, ics206_transport_address, s206_transport_address[i]);
		replacestr(form206, ics206_transport_phone, s206_transport_phone[i]);
		replacestr(form206, ics206_transport_paramedics, b206_transport_paramedics[i] ? yes : no);
		replacestr(form206, ics206_ambulance_name, s206_ambulance_name[i]);
		replacestr(form206, ics206_ambulance_loc, s206_ambulance_loc[i]);
		replacestr(form206, ics206_ambulance_paramedics, b206_ambulance_paramedics[i] ? yes : no);
		replacestr(form206, ics206_hosp_name, s206_hosp_name[i]);
		replacestr(form206, ics206_hosp_address, s206_hosp_address[i]);
		replacestr(form206, ics206_hosp_phone, s206_hosp_phone[i]);
		replacestr(form206, ics206_hosp_airtime, s206_hosp_airtime[i]);
		replacestr(form206, ics206_hosp_gndtime, s206_hosp_gndtime[i]);
		replacestr(form206, ics206_hosp_helipad, b206_hosp_helipad[i] ? yes : no);
		replacestr(form206, ics206_hosp_burn_center, b206_hosp_burn_center[i] ? yes : no);
	}
	string temp = s206_procedure;
	replacelf(temp); to_html(temp);
	replacestr(form206, ics206_procedure, temp);
	replacestr(form206, ics206_preparer, s206_preparer);
	replacestr(form206, ics206_reviewer, s206_reviewer);

	FILE *file206 = fopen(ics206_fname.c_str(), "w");
	fprintf(file206,"%s", form206.c_str());
	fclose(file206);

	open_url(ics206_fname.c_str());
}
