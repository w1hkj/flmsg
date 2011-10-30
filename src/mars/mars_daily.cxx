// =====================================================================
//
// mars_daily.cxx
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

const char mars_precedent[] = "RPIFM";
const char mars_e_x[] = "EX";

string mars_daily_incident		= ":md_inc:";
string mars_daily_de			= ":md_de_:";
string mars_daily_nbr			= ":md_nbr:";
string mars_daily_prec			= ":md_pre:";
string mars_daily_dtg			= ":md_dtg:";
string mars_daily_fm_name		= ":md_fnm:";
string mars_daily_fm_call		= ":md_fcl:";
string mars_daily_fm_state		= ":md_fst:";
string mars_daily_to_pos		= ":md_tps:";
string mars_daily_to_call		= ":md_tcl:";
string mars_daily_to_state		= ":md_tst:";
string mars_daily_pos1			= ":md_ps1:";
string mars_daily_call1			= ":md_cl1:";
string mars_daily_state1		= ":md_st1:";
string mars_daily_pos2			= ":md_ps2:";
string mars_daily_call2			= ":md_cl2:";
string mars_daily_state2		= ":md_st2:";
string mars_daily_pos3			= ":md_ps3:";
string mars_daily_call3			= ":md_cl3:";
string mars_daily_state3		= ":md_st3:";
string mars_daily_sitrep_id		= ":md_sid:";
string mars_daily_sitrep_loc	= ":md_slo:";
string mars_daily_24hr			= ":md_22h:";
string mars_daily_netcall		= ":md_ncl:";
string mars_daily_e_x			= ":md_e_x:";
string mars_daily_dtg_active	= ":md_dta:";
string mars_daily_dtg_deactive	= ":md_dtd:";
string mars_daily_nbr_stations	= ":md_nst:";
string mars_daily_details		= ":md_det:";
string mars_daily_activations	= ":md_acs:";
string mars_daily_agencies		= ":md_agy:";
string mars_daily_remarks		= ":md_rem:";

string s_mars_daily_incident;
string s_mars_daily_de;
string s_mars_daily_nbr;
string s_mars_daily_prec;
string s_mars_daily_dtg;
string s_mars_daily_fm_name;
string s_mars_daily_fm_call;
string s_mars_daily_fm_state;
string s_mars_daily_to_pos;
string s_mars_daily_to_call;
string s_mars_daily_to_state;
string s_mars_daily_pos1;
string s_mars_daily_call1;
string s_mars_daily_state1;
string s_mars_daily_pos2;
string s_mars_daily_call2;
string s_mars_daily_state2;
string s_mars_daily_pos3;
string s_mars_daily_call3;
string s_mars_daily_state3;
string s_mars_daily_sitrep_id;
string s_mars_daily_sitrep_loc;
string s_mars_daily_24hr;
string s_mars_daily_netcall;
string s_mars_daily_e_x;
string s_mars_daily_dtg_active;
string s_mars_daily_dtg_deactive;
string s_mars_daily_nbr_stations;
string s_mars_daily_details;
string s_mars_daily_activations;
string s_mars_daily_agencies;
string s_mars_daily_remarks;

string buffmars_daily;
string def_mars_daily_filename = "";
string base_mars_daily_filename = "";
string def_mars_daily_TemplateName = "";

bool using_mars_daily_template = false;

void clear_mars_dailyfields()
{
	s_mars_daily_incident.clear();
	s_mars_daily_de.clear();
	s_mars_daily_nbr.clear();
	s_mars_daily_prec = "M";
	s_mars_daily_dtg.clear();
	s_mars_daily_fm_name.clear();
	s_mars_daily_fm_call.clear();
	s_mars_daily_fm_state.clear();
	s_mars_daily_to_pos.clear();
	s_mars_daily_to_call.clear();
	s_mars_daily_to_state.clear();
	s_mars_daily_pos1.clear();
	s_mars_daily_call1.clear();
	s_mars_daily_state1.clear();
	s_mars_daily_pos2.clear();
	s_mars_daily_call2.clear();
	s_mars_daily_state2.clear();
	s_mars_daily_pos3.clear();
	s_mars_daily_call3.clear();
	s_mars_daily_state3.clear();
	s_mars_daily_sitrep_id.clear();
	s_mars_daily_sitrep_loc.clear();
	s_mars_daily_24hr.clear();
	s_mars_daily_netcall.clear();
	s_mars_daily_e_x = "X";
	s_mars_daily_dtg_active.clear();
	s_mars_daily_dtg_deactive.clear();
	s_mars_daily_nbr_stations.clear();
	s_mars_daily_details.clear();
	s_mars_daily_activations.clear();
	s_mars_daily_agencies.clear();
	s_mars_daily_remarks.clear();
}

void update_mars_dailyfields()
{
	s_mars_daily_incident = txt_mars_daily_incident->value();
	s_mars_daily_de = txt_mars_daily_de->value();
	s_mars_daily_nbr = txt_mars_daily_nbr->value();
	s_mars_daily_prec.clear();
	s_mars_daily_prec = mars_precedent[sel_mars_daily_prec->value()];
	s_mars_daily_dtg = txt_mars_daily_dtg->value();
	s_mars_daily_fm_name = txt_mars_daily_fm_name->value();
	s_mars_daily_fm_call = txt_mars_daily_fm_call->value();
	s_mars_daily_fm_state = txt_mars_daily_fm_state->value();
	s_mars_daily_to_pos = txt_mars_daily_to_pos->value();
	s_mars_daily_to_call = txt_mars_daily_to_call->value();
	s_mars_daily_to_state = txt_mars_daily_to_state->value();
	s_mars_daily_pos1 = txt_mars_daily_pos1->value();
	s_mars_daily_call1 = txt_mars_daily_call1->value();
	s_mars_daily_state1 = txt_mars_daily_state1->value();
	s_mars_daily_pos2 = txt_mars_daily_pos2->value();
	s_mars_daily_call2 = txt_mars_daily_call2->value();
	s_mars_daily_state2 = txt_mars_daily_state2->value();
	s_mars_daily_pos3 = txt_mars_daily_pos3->value();
	s_mars_daily_call3 = txt_mars_daily_call3->value();
	s_mars_daily_state3 = txt_mars_daily_state3->value();
	s_mars_daily_sitrep_id = txt_mars_daily_sitrep_id->value();
	s_mars_daily_sitrep_loc = txt_mars_daily_sitrep_loc->value();
	s_mars_daily_24hr = txt_mars_daily_dtg_24hr->value();
	s_mars_daily_netcall = txt_mars_daily_netcall->value();
	s_mars_daily_e_x = mars_e_x[sel_mars_daily_e_x->value()];
	s_mars_daily_dtg_active = txt_mars_daily_dtg_active->value();
	s_mars_daily_dtg_deactive = txt_mars_daily_dtg_deactive->value();
	s_mars_daily_nbr_stations = txt_mars_daily_nbr_stations->value();
	s_mars_daily_details = txt_mars_daily_details->value();
	s_mars_daily_activations = txt_mars_daily_activations->value();
	s_mars_daily_agencies = txt_mars_daily_agencies->value();
	s_mars_daily_remarks = txt_mars_daily_remarks->value();
}

void update_mars_dailyform()
{
	txt_mars_daily_incident->value(s_mars_daily_incident.c_str());
	txt_mars_daily_de->value(s_mars_daily_de.c_str());
	txt_mars_daily_nbr->value(s_mars_daily_nbr.c_str());

	size_t n = strchr(mars_precedent, s_mars_daily_prec[0]) - mars_precedent;
	if (n < 0) n = 0;
	if (n > 4) n = 4;
	sel_mars_daily_prec->value(n);

	txt_mars_daily_dtg->value(s_mars_daily_dtg.c_str());
	txt_mars_daily_fm_name->value(s_mars_daily_fm_name.c_str());
	txt_mars_daily_fm_call->value(s_mars_daily_fm_call.c_str());
	txt_mars_daily_fm_state->value(s_mars_daily_fm_state.c_str());
	txt_mars_daily_to_pos->value(s_mars_daily_to_pos.c_str());
	txt_mars_daily_to_call->value(s_mars_daily_to_call.c_str());
	txt_mars_daily_to_state->value(s_mars_daily_to_state.c_str());
	txt_mars_daily_pos1->value(s_mars_daily_pos1.c_str());
	txt_mars_daily_call1->value(s_mars_daily_call1.c_str());
	txt_mars_daily_state1->value(s_mars_daily_state1.c_str());
	txt_mars_daily_pos2->value(s_mars_daily_pos2.c_str());
	txt_mars_daily_call2->value(s_mars_daily_call2.c_str());
	txt_mars_daily_state2->value(s_mars_daily_state2.c_str());
	txt_mars_daily_pos3->value(s_mars_daily_pos3.c_str());
	txt_mars_daily_call3->value(s_mars_daily_call3.c_str());
	txt_mars_daily_state3->value(s_mars_daily_state3.c_str());
	txt_mars_daily_sitrep_id->value(s_mars_daily_sitrep_id.c_str());
	txt_mars_daily_sitrep_loc->value(s_mars_daily_sitrep_loc.c_str());
	txt_mars_daily_dtg_24hr->value(s_mars_daily_24hr.c_str());
	txt_mars_daily_netcall->value(s_mars_daily_netcall.c_str());

	n = strchr(mars_e_x, s_mars_daily_e_x[0]) - mars_e_x;
	if (n < 0) n = 0;
	if (n > 1) n = 1;
	sel_mars_daily_e_x->value(n);

	txt_mars_daily_dtg_active->value(s_mars_daily_dtg_active.c_str());
	txt_mars_daily_dtg_deactive->value(s_mars_daily_dtg_deactive.c_str());
	txt_mars_daily_nbr_stations->value(s_mars_daily_nbr_stations.c_str());
	txt_mars_daily_details->value(s_mars_daily_details.c_str());
	txt_mars_daily_activations->value(s_mars_daily_activations.c_str());
	txt_mars_daily_agencies->value(s_mars_daily_agencies.c_str());
	txt_mars_daily_remarks->value(s_mars_daily_remarks.c_str());
}

void clear_mars_daily_form()
{
	clear_mars_dailyfields();
	txt_mars_daily_incident->value("");
	txt_mars_daily_de->value("");
	txt_mars_daily_nbr->value("");
	sel_mars_daily_prec->value(4);
	txt_mars_daily_dtg->value("");
	txt_mars_daily_fm_name->value("");
	txt_mars_daily_fm_call->value("");
	txt_mars_daily_fm_state->value("");
	txt_mars_daily_to_pos->value("");
	txt_mars_daily_to_call->value("");
	txt_mars_daily_to_state->value("");
	txt_mars_daily_pos1->value("");
	txt_mars_daily_call1->value("");
	txt_mars_daily_state1->value("");
	txt_mars_daily_pos2->value("");
	txt_mars_daily_call2->value("");
	txt_mars_daily_state2->value("");
	txt_mars_daily_pos3->value("");
	txt_mars_daily_call3->value("");
	txt_mars_daily_state3->value("");
	txt_mars_daily_sitrep_id->value("");
	txt_mars_daily_sitrep_loc->value("");
	txt_mars_daily_dtg_24hr->value("");
	txt_mars_daily_netcall->value("");
	sel_mars_daily_e_x->value(1);
	txt_mars_daily_dtg_active->value("");
	txt_mars_daily_dtg_deactive->value("");
	txt_mars_daily_nbr_stations->value("");
	txt_mars_daily_details->value("");
	txt_mars_daily_activations->value("");
	txt_mars_daily_agencies->value("");
	txt_mars_daily_remarks->value("");
}

void make_buffmars_daily()
{
	update_mars_dailyfields();
	buffmars_daily = header("<mars_daily>");

	buffmars_daily.append( lineout( mars_daily_incident,	s_mars_daily_incident ) );
	buffmars_daily.append( lineout( mars_daily_de,			s_mars_daily_de ) );
	buffmars_daily.append( lineout( mars_daily_nbr,			s_mars_daily_nbr ) );
	buffmars_daily.append( lineout( mars_daily_prec,		s_mars_daily_prec ) );
	buffmars_daily.append( lineout( mars_daily_dtg,			s_mars_daily_dtg ) );
	buffmars_daily.append( lineout( mars_daily_fm_name,		s_mars_daily_fm_name ) );
	buffmars_daily.append( lineout( mars_daily_fm_call,		s_mars_daily_fm_call ) );
	buffmars_daily.append( lineout( mars_daily_fm_state,	s_mars_daily_fm_state ) );
	buffmars_daily.append( lineout( mars_daily_to_pos,		s_mars_daily_to_pos ) );
	buffmars_daily.append( lineout( mars_daily_to_call,		s_mars_daily_to_call ) );
	buffmars_daily.append( lineout( mars_daily_to_state,	s_mars_daily_to_state ) );
	buffmars_daily.append( lineout( mars_daily_pos1,		s_mars_daily_pos1 ) );
	buffmars_daily.append( lineout( mars_daily_call1,		s_mars_daily_call1 ) );
	buffmars_daily.append( lineout( mars_daily_state1,		s_mars_daily_state1 ) );
	buffmars_daily.append( lineout( mars_daily_pos2,		s_mars_daily_pos2 ) );
	buffmars_daily.append( lineout( mars_daily_call2,		s_mars_daily_call2 ) );
	buffmars_daily.append( lineout( mars_daily_state2,		s_mars_daily_state2 ) );
	buffmars_daily.append( lineout( mars_daily_pos3,		s_mars_daily_pos3 ) );
	buffmars_daily.append( lineout( mars_daily_call3,		s_mars_daily_call3 ) );
	buffmars_daily.append( lineout( mars_daily_state3,		s_mars_daily_state3 ) );
	buffmars_daily.append( lineout( mars_daily_sitrep_id,	s_mars_daily_sitrep_id ) );
	buffmars_daily.append( lineout( mars_daily_sitrep_loc,	s_mars_daily_sitrep_loc ) );
	buffmars_daily.append( lineout( mars_daily_24hr,		s_mars_daily_24hr ) );
	buffmars_daily.append( lineout( mars_daily_netcall,		s_mars_daily_netcall ) );
	buffmars_daily.append( lineout( mars_daily_e_x,			s_mars_daily_e_x ) );
	buffmars_daily.append( lineout( mars_daily_dtg_active,	s_mars_daily_dtg_active ) );
	buffmars_daily.append( lineout( mars_daily_dtg_deactive,s_mars_daily_dtg_deactive ) );
	buffmars_daily.append( lineout( mars_daily_nbr_stations,s_mars_daily_nbr_stations ) );
	buffmars_daily.append( lineout( mars_daily_details,		s_mars_daily_details ) );
	buffmars_daily.append( lineout( mars_daily_activations,	s_mars_daily_activations ) );
	buffmars_daily.append( lineout( mars_daily_agencies,	s_mars_daily_agencies ) );
	buffmars_daily.append( lineout( mars_daily_remarks,		s_mars_daily_remarks ) );
}

void read_mars_daily_buffer(string data)
{
	clear_mars_dailyfields();
// search the file buffer for each of the mars_daily fields
	s_mars_daily_incident = findstr( data, mars_daily_incident );
	s_mars_daily_de = findstr( data, mars_daily_de );
	s_mars_daily_nbr = findstr( data, mars_daily_nbr );
	s_mars_daily_prec = findstr( data, mars_daily_prec );
	s_mars_daily_dtg = findstr( data, mars_daily_dtg );
	s_mars_daily_fm_name = findstr( data, mars_daily_fm_name );
	s_mars_daily_fm_call = findstr( data, mars_daily_fm_call );
	s_mars_daily_fm_state = findstr( data, mars_daily_fm_state );
	s_mars_daily_to_pos = findstr( data, mars_daily_to_pos );
	s_mars_daily_to_call = findstr( data, mars_daily_to_call );
	s_mars_daily_to_state = findstr( data, mars_daily_to_state );
	s_mars_daily_pos1 = findstr( data, mars_daily_pos1 );
	s_mars_daily_call1 = findstr( data, mars_daily_call1 );
	s_mars_daily_state1 = findstr( data, mars_daily_state1 );
	s_mars_daily_pos2 = findstr( data, mars_daily_pos2 );
	s_mars_daily_call2 = findstr( data, mars_daily_call2 );
	s_mars_daily_state2 = findstr( data, mars_daily_state2 );
	s_mars_daily_pos3 = findstr( data, mars_daily_pos3 );
	s_mars_daily_call3 = findstr( data, mars_daily_call3 );
	s_mars_daily_state3 = findstr( data, mars_daily_state3 );
	s_mars_daily_sitrep_id = findstr( data, mars_daily_sitrep_id );
	s_mars_daily_sitrep_loc = findstr( data, mars_daily_sitrep_loc );
	s_mars_daily_24hr = findstr( data, mars_daily_24hr );
	s_mars_daily_netcall = findstr( data, mars_daily_netcall );
	s_mars_daily_e_x = findstr( data, mars_daily_e_x );
	s_mars_daily_dtg_active = findstr( data, mars_daily_dtg_active );
	s_mars_daily_dtg_deactive = findstr( data, mars_daily_dtg_deactive );
	s_mars_daily_nbr_stations = findstr( data, mars_daily_nbr_stations );
	s_mars_daily_details = findstr( data, mars_daily_details );
	s_mars_daily_activations = findstr( data, mars_daily_activations );
	s_mars_daily_agencies = findstr( data, mars_daily_agencies );
	s_mars_daily_remarks = findstr( data, mars_daily_remarks );

	update_mars_dailyform();
}

void cb_mars_daily_new()
{
	clear_mars_daily_form();
	def_mars_daily_filename = ICS_msg_dir;
	def_mars_daily_filename.append("new"FMARSDAILY_EXT);
	show_filename(def_mars_daily_filename);
	using_mars_daily_template = false;
}

void cb_mars_daily_import()
{
	fl_alert2("Not implemented");
}

void cb_mars_daily_export()
{
	fl_alert2("Not implemented");
}

void cb_mars_daily_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_mars_daily_form();
	read_mars_daily_buffer(inpbuffer);
	def_mars_daily_filename = ICS_msg_dir;
	def_mars_daily_filename.append(wrapfilename);
	show_filename(def_mars_daily_filename);
	using_mars_daily_template = false;
}

void cb_mars_daily_wrap_export()
{
	if (base_mars_daily_filename == "new"FMARSDAILY_EXT || base_mars_daily_filename == "default"FMARSDAILY_EXT)
		cb_mars_daily_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_daily_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_buffmars_daily();
		export_wrapfile(base_mars_daily_filename, wrapfilename, buffmars_daily, pext != ".wrap");
	}
}

void cb_mars_daily_wrap_autosend()
{
	if (base_mars_daily_filename == "new"FMARSDAILY_EXT || 
		base_mars_daily_filename == "default"FMARSDAILY_EXT ||
		using_mars_daily_template == true)
		cb_mars_daily_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buffmars_daily();
	export_wrapfile(base_mars_daily_filename, wrapfilename, buffmars_daily, false);
}

void cb_mars_daily_load_template()
{
	string def_mars_daily_filename = def_mars_daily_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"TMARSDAILY_EXT,
			def_mars_daily_filename.c_str());
	if (p) {
		clear_mars_daily_form();
		read_data_file(p);
		def_mars_daily_TemplateName = p;
		show_filename(def_mars_daily_TemplateName);
		using_mars_daily_template = true;
	}
}

void cb_mars_daily_save_template()
{
	if (!using_mars_daily_template) {
		cb_mars_daily_save_as_template();
		return;
	}
	string def_mars_daily_filename = def_mars_daily_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"TMARSDAILY_EXT,
			def_mars_daily_filename.c_str());
	if (p)
		write_mars_daily(p);
}

void cb_mars_daily_save_as_template()
{
	string def_mars_daily_filename = def_mars_daily_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"TMARSDAILY_EXT,
			def_mars_daily_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_daily_TemplateName = p;
		if (strlen(pext) == 0) def_mars_daily_TemplateName.append(TMARSDAILY_EXT);
		remove_spaces_from_filename(def_mars_daily_TemplateName);
		write_mars_daily(def_mars_daily_TemplateName);
		show_filename(def_mars_daily_TemplateName);
		using_mars_daily_template = true;
	}
}

void cb_mars_daily_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-mars_daily\t*"FMARSDAILY_EXT,
					def_mars_daily_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_daily_form();
	read_data_file(p);
	using_mars_daily_template = false;
	def_mars_daily_filename = p;
	show_filename(def_mars_daily_filename);
}

void write_mars_daily(string s)
{
	FILE *filemars_daily = fopen(s.c_str(), "w");
	if (!filemars_daily) return;
	make_buffmars_daily();
	fwrite(buffmars_daily.c_str(), buffmars_daily.length(), 1, filemars_daily);
	fclose(filemars_daily);
}

void cb_mars_daily_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FMARSDAILY_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_daily_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-mars_daily\t*"FMARSDAILY_EXT,
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
	def_mars_daily_filename = p;
	if (strlen(pext) == 0) def_mars_daily_filename.append(FMARSDAILY_EXT);

	remove_spaces_from_filename(def_mars_daily_filename);
	write_mars_daily(def_mars_daily_filename);

	using_mars_daily_template = false;
	show_filename(def_mars_daily_filename);
}

void cb_mars_daily_save()
{
	if (base_mars_daily_filename == "new"FMARSDAILY_EXT || 
		base_mars_daily_filename == "default"FMARSDAILY_EXT ||
		using_mars_daily_template == true) {
		cb_mars_daily_save_as();
		return;
	}
	write_mars_daily(def_mars_daily_filename);
	using_mars_daily_template = false;
}

void cb_mars_daily_html()
{
	string fname_name = fl_filename_name(def_mars_daily_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string mars_daily_fname = ICS_dir;
	mars_daily_fname.append(fname_name);
	mars_daily_fname.append(".html");

	string html_text = "";

	update_mars_dailyfields();
	string formmars_daily = mars_daily_html_template;

	replacestr(formmars_daily, TITLE, fname_name);

	replacestr(formmars_daily, mars_daily_incident, s_mars_daily_incident );
	replacestr(formmars_daily, mars_daily_incident, s_mars_daily_incident );
	replacestr(formmars_daily, mars_daily_de, s_mars_daily_de );
	replacestr(formmars_daily, mars_daily_nbr, s_mars_daily_nbr );
	replacestr(formmars_daily, mars_daily_prec, s_mars_daily_prec );
	replacestr(formmars_daily, mars_daily_dtg, s_mars_daily_dtg );
	replacestr(formmars_daily, mars_daily_fm_name, s_mars_daily_fm_name );
	replacestr(formmars_daily, mars_daily_fm_call, s_mars_daily_fm_call );
	replacestr(formmars_daily, mars_daily_fm_state, s_mars_daily_fm_state );
	replacestr(formmars_daily, mars_daily_to_pos, s_mars_daily_to_pos );
	replacestr(formmars_daily, mars_daily_to_call, s_mars_daily_to_call );
	replacestr(formmars_daily, mars_daily_to_state, s_mars_daily_to_state );
	replacestr(formmars_daily, mars_daily_pos1, s_mars_daily_pos1 );
	replacestr(formmars_daily, mars_daily_call1, s_mars_daily_call1 );
	replacestr(formmars_daily, mars_daily_state1, s_mars_daily_state1 );
	replacestr(formmars_daily, mars_daily_pos2, s_mars_daily_pos2 );
	replacestr(formmars_daily, mars_daily_call2, s_mars_daily_call2 );
	replacestr(formmars_daily, mars_daily_state2, s_mars_daily_state2 );
	replacestr(formmars_daily, mars_daily_pos3, s_mars_daily_pos3 );
	replacestr(formmars_daily, mars_daily_call3, s_mars_daily_call3 );
	replacestr(formmars_daily, mars_daily_state3, s_mars_daily_state3 );
	replacestr(formmars_daily, mars_daily_sitrep_id, s_mars_daily_sitrep_id );
	replacestr(formmars_daily, mars_daily_sitrep_loc, s_mars_daily_sitrep_loc );
	replacestr(formmars_daily, mars_daily_24hr, s_mars_daily_24hr );
	replacestr(formmars_daily, mars_daily_netcall, s_mars_daily_netcall );
	replacestr(formmars_daily, mars_daily_e_x, s_mars_daily_e_x );
	replacestr(formmars_daily, mars_daily_dtg_active, s_mars_daily_dtg_active );
	replacestr(formmars_daily, mars_daily_dtg_deactive, s_mars_daily_dtg_deactive );
	replacestr(formmars_daily, mars_daily_nbr_stations, s_mars_daily_nbr_stations );
	replacestr(formmars_daily, mars_daily_details, s_mars_daily_details );
	replacestr(formmars_daily, mars_daily_activations, s_mars_daily_activations );
	replacestr(formmars_daily, mars_daily_agencies, s_mars_daily_agencies );
	replacestr(formmars_daily, mars_daily_remarks, s_mars_daily_remarks );

	FILE *filemars_daily = fopen(mars_daily_fname.c_str(), "w");
	fprintf(filemars_daily,"%s", formmars_daily.c_str());
	fclose(filemars_daily);

	open_url(mars_daily_fname.c_str());
}

void cb_mars_daily_msg_type()
{
	if (tabs_msg_type->value() == tab_mars_daily ) {
		show_filename(def_mars_daily_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_mars_daily_textout()
{
	string temp = "";
	string mars_daily_fname = ICS_dir;
	mars_daily_fname.append("mars_daily.txt");

	update_mars_dailyfields();
	string formmars_daily = mars_daily_text_template;

	replacestr(formmars_daily, mars_daily_incident, s_mars_daily_incident );
	replacestr(formmars_daily, mars_daily_incident, s_mars_daily_incident );
	replacestr(formmars_daily, mars_daily_de, s_mars_daily_de );
	replacestr(formmars_daily, mars_daily_nbr, s_mars_daily_nbr );
	replacestr(formmars_daily, mars_daily_prec, s_mars_daily_prec );
	replacestr(formmars_daily, mars_daily_dtg, s_mars_daily_dtg );
	replacestr(formmars_daily, mars_daily_fm_name, s_mars_daily_fm_name );
	replacestr(formmars_daily, mars_daily_fm_call, s_mars_daily_fm_call );
	replacestr(formmars_daily, mars_daily_fm_state, s_mars_daily_fm_state );
	replacestr(formmars_daily, mars_daily_to_pos, s_mars_daily_to_pos );
	replacestr(formmars_daily, mars_daily_to_call, s_mars_daily_to_call );
	replacestr(formmars_daily, mars_daily_to_state, s_mars_daily_to_state );
	replacestr(formmars_daily, mars_daily_pos1, s_mars_daily_pos1 );
	replacestr(formmars_daily, mars_daily_call1, s_mars_daily_call1 );
	replacestr(formmars_daily, mars_daily_state1, s_mars_daily_state1 );
	replacestr(formmars_daily, mars_daily_pos2, s_mars_daily_pos2 );
	replacestr(formmars_daily, mars_daily_call2, s_mars_daily_call2 );
	replacestr(formmars_daily, mars_daily_state2, s_mars_daily_state2 );
	replacestr(formmars_daily, mars_daily_pos3, s_mars_daily_pos3 );
	replacestr(formmars_daily, mars_daily_call3, s_mars_daily_call3 );
	replacestr(formmars_daily, mars_daily_state3, s_mars_daily_state3 );
	replacestr(formmars_daily, mars_daily_sitrep_id, s_mars_daily_sitrep_id );
	replacestr(formmars_daily, mars_daily_sitrep_loc, s_mars_daily_sitrep_loc );
	replacestr(formmars_daily, mars_daily_24hr, s_mars_daily_24hr );
	replacestr(formmars_daily, mars_daily_netcall, s_mars_daily_netcall );
	replacestr(formmars_daily, mars_daily_e_x, s_mars_daily_e_x );
	replacestr(formmars_daily, mars_daily_dtg_active, s_mars_daily_dtg_active );
	replacestr(formmars_daily, mars_daily_dtg_deactive, s_mars_daily_dtg_deactive );
	replacestr(formmars_daily, mars_daily_nbr_stations, s_mars_daily_nbr_stations );
	replacestr(formmars_daily, mars_daily_details, s_mars_daily_details );
	replacestr(formmars_daily, mars_daily_activations, s_mars_daily_activations );
	replacestr(formmars_daily, mars_daily_agencies, s_mars_daily_agencies );
	replacestr(formmars_daily, mars_daily_remarks, s_mars_daily_remarks );

	FILE *filemars_daily = fopen(mars_daily_fname.c_str(), "w");
	fprintf(filemars_daily,"%s", formmars_daily.c_str());
	fclose(filemars_daily);

	open_url(mars_daily_fname.c_str());
}
