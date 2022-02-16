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

const char mars_precedent[] = "RPOZ";
const char mars_e_x[] = "EX";

std::string mars_daily_incident		= ":md_inc:";
std::string mars_daily_de			= ":md_de_:";
std::string mars_daily_nbr			= ":md_nbr:";
std::string mars_daily_prec			= ":md_pre:";
std::string mars_daily_dtg			= ":md_dtg:";
std::string mars_daily_fm_name		= ":md_fnm:";
std::string mars_daily_fm_call		= ":md_fcl:";
std::string mars_daily_fm_state		= ":md_fst:";
std::string mars_daily_to_pos		= ":md_tps:";
std::string mars_daily_to_call		= ":md_tcl:";
std::string mars_daily_to_state		= ":md_tst:";
std::string mars_daily_pos1			= ":md_ps1:";
std::string mars_daily_call1			= ":md_cl1:";
std::string mars_daily_state1		= ":md_st1:";
std::string mars_daily_pos2			= ":md_ps2:";
std::string mars_daily_call2			= ":md_cl2:";
std::string mars_daily_state2		= ":md_st2:";
std::string mars_daily_pos3			= ":md_ps3:";
std::string mars_daily_call3			= ":md_cl3:";
std::string mars_daily_state3		= ":md_st3:";
std::string mars_daily_sitrep_id		= ":md_sid:";
std::string mars_daily_sitrep_loc	= ":md_slo:";
std::string mars_daily_24hr			= ":md_22h:";
std::string mars_daily_netcall		= ":md_ncl:";
std::string mars_daily_e_x			= ":md_e_x:";
std::string mars_daily_dtg_active	= ":md_dta:";
std::string mars_daily_dtg_deactive	= ":md_dtd:";
std::string mars_daily_nbr_stations	= ":md_nst:";
std::string mars_daily_details		= ":md_det:";
std::string mars_daily_activations	= ":md_acs:";
std::string mars_daily_agencies		= ":md_agy:";
std::string mars_daily_remarks		= ":md_rem:";

std::string s_mars_daily_incident;
std::string s_mars_daily_de;
std::string s_mars_daily_nbr;
std::string s_mars_daily_prec = "R";
std::string s_mars_daily_dtg;
std::string s_mars_daily_fm_name;
std::string s_mars_daily_fm_call;
std::string s_mars_daily_fm_state;
std::string s_mars_daily_to_pos;
std::string s_mars_daily_to_call;
std::string s_mars_daily_to_state;
std::string s_mars_daily_pos1;
std::string s_mars_daily_call1;
std::string s_mars_daily_state1;
std::string s_mars_daily_pos2;
std::string s_mars_daily_call2;
std::string s_mars_daily_state2;
std::string s_mars_daily_pos3;
std::string s_mars_daily_call3;
std::string s_mars_daily_state3;
std::string s_mars_daily_sitrep_id;
std::string s_mars_daily_sitrep_loc;
std::string s_mars_daily_24hr;
std::string s_mars_daily_netcall;
std::string s_mars_daily_e_x = "X";
std::string s_mars_daily_dtg_active;
std::string s_mars_daily_dtg_deactive;
std::string s_mars_daily_nbr_stations;
std::string s_mars_daily_details;
std::string s_mars_daily_activations;
std::string s_mars_daily_agencies;
std::string s_mars_daily_remarks;

std::string buffmars_daily;
std::string def_mars_daily_filename = "";
std::string base_mars_daily_filename = "";
std::string def_mars_daily_TemplateName = "";

bool using_mars_daily_template = false;

void clear_mars_dailyfields()
{
	s_mars_daily_incident.clear();
	s_mars_daily_de.clear();
	s_mars_daily_nbr.clear();
	s_mars_daily_prec = "R";
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

bool check_mars_dailyfields()
{
	std::string temp;
	if (s_mars_daily_incident != txt_mars_daily_incident->value()) return true;
	if (s_mars_daily_de != txt_mars_daily_de->value()) return true;
	if (s_mars_daily_nbr != txt_mars_daily_nbr->value()) return true;
	int val = sel_mars_daily_prec->index();
	temp.clear();
	temp += mars_precedent[val];
	if (s_mars_daily_prec != temp) return true;
	if (s_mars_daily_dtg != txt_mars_daily_dtg->value()) return true;
	if (s_mars_daily_fm_name != txt_mars_daily_fm_name->value()) return true;
	if (s_mars_daily_fm_call != txt_mars_daily_fm_call->value()) return true;
	if (s_mars_daily_fm_state != txt_mars_daily_fm_state->value()) return true;
	if (s_mars_daily_to_pos != txt_mars_daily_to_pos->value()) return true;
	if (s_mars_daily_to_call != txt_mars_daily_to_call->value()) return true;
	if (s_mars_daily_to_state != txt_mars_daily_to_state->value()) return true;
	if (s_mars_daily_pos1 != txt_mars_daily_pos1->value()) return true;
	if (s_mars_daily_call1 != txt_mars_daily_call1->value()) return true;
	if (s_mars_daily_state1 != txt_mars_daily_state1->value()) return true;
	if (s_mars_daily_pos2 != txt_mars_daily_pos2->value()) return true;
	if (s_mars_daily_call2 != txt_mars_daily_call2->value()) return true;
	if (s_mars_daily_state2 != txt_mars_daily_state2->value()) return true;
	if (s_mars_daily_pos3 != txt_mars_daily_pos3->value()) return true;
	if (s_mars_daily_call3 != txt_mars_daily_call3->value()) return true;
	if (s_mars_daily_state3 != txt_mars_daily_state3->value()) return true;
	if (s_mars_daily_sitrep_id != txt_mars_daily_sitrep_id->value()) return true;
	if (s_mars_daily_sitrep_loc != txt_mars_daily_sitrep_loc->value()) return true;
	if (s_mars_daily_24hr != txt_mars_daily_dtg_24hr->value()) return true;
	if (s_mars_daily_netcall != txt_mars_daily_netcall->value()) return true;
	temp.clear();
	temp += mars_e_x[sel_mars_daily_e_x->index()];
	if (s_mars_daily_e_x != temp) return true;
	if (s_mars_daily_dtg_active != txt_mars_daily_dtg_active->value()) return true;
	if (s_mars_daily_dtg_deactive != txt_mars_daily_dtg_deactive->value()) return true;
	if (s_mars_daily_nbr_stations != txt_mars_daily_nbr_stations->value()) return true;
	if (s_mars_daily_details != txt_mars_daily_details->value()) return true;
	if (s_mars_daily_activations != txt_mars_daily_activations->value()) return true;
	if (s_mars_daily_agencies != txt_mars_daily_agencies->value()) return true;
	if (s_mars_daily_remarks != txt_mars_daily_remarks->value()) return true;
	return false;
}

void update_mars_dailyfields()
{
	s_mars_daily_incident = txt_mars_daily_incident->value();
	s_mars_daily_de = txt_mars_daily_de->value();
	s_mars_daily_nbr = txt_mars_daily_nbr->value();
	size_t n = sel_mars_daily_prec->index();
	if (n < 0) n = 0;
	if (n >= strlen(mars_precedent)) n = strlen(mars_precedent) - 1;
	s_mars_daily_prec = mars_precedent[n];
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
	n = sel_mars_daily_e_x->index();
	if (n < 0) n = 0;
	if (n >= strlen(mars_e_x)) n = strlen(mars_e_x) - 1;
	s_mars_daily_e_x = mars_e_x[n];
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
	if (n >= strlen(mars_precedent)) n = strlen(mars_precedent) - 1;
	sel_mars_daily_prec->index(n);

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
	if (n >= strlen(mars_e_x)) n = strlen(mars_e_x) - 1;
	sel_mars_daily_e_x->index(n);

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
	sel_mars_daily_prec->index(0);
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
	sel_mars_daily_e_x->index(1);
	txt_mars_daily_dtg_active->value("");
	txt_mars_daily_dtg_deactive->value("");
	txt_mars_daily_nbr_stations->value("");
	txt_mars_daily_details->value("");
	txt_mars_daily_activations->value("");
	txt_mars_daily_agencies->value("");
	txt_mars_daily_remarks->value("");
}

void make_buffmars_daily(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( mars_daily_incident,	s_mars_daily_incident ) );
	mbuff.append( lineout( mars_daily_de,			s_mars_daily_de ) );
	mbuff.append( lineout( mars_daily_nbr,			s_mars_daily_nbr ) );
	mbuff.append( lineout( mars_daily_prec,		s_mars_daily_prec ) );
	mbuff.append( lineout( mars_daily_dtg,			s_mars_daily_dtg ) );
	mbuff.append( lineout( mars_daily_fm_name,		s_mars_daily_fm_name ) );
	mbuff.append( lineout( mars_daily_fm_call,		s_mars_daily_fm_call ) );
	mbuff.append( lineout( mars_daily_fm_state,	s_mars_daily_fm_state ) );
	mbuff.append( lineout( mars_daily_to_pos,		s_mars_daily_to_pos ) );
	mbuff.append( lineout( mars_daily_to_call,		s_mars_daily_to_call ) );
	mbuff.append( lineout( mars_daily_to_state,	s_mars_daily_to_state ) );
	mbuff.append( lineout( mars_daily_pos1,		s_mars_daily_pos1 ) );
	mbuff.append( lineout( mars_daily_call1,		s_mars_daily_call1 ) );
	mbuff.append( lineout( mars_daily_state1,		s_mars_daily_state1 ) );
	mbuff.append( lineout( mars_daily_pos2,		s_mars_daily_pos2 ) );
	mbuff.append( lineout( mars_daily_call2,		s_mars_daily_call2 ) );
	mbuff.append( lineout( mars_daily_state2,		s_mars_daily_state2 ) );
	mbuff.append( lineout( mars_daily_pos3,		s_mars_daily_pos3 ) );
	mbuff.append( lineout( mars_daily_call3,		s_mars_daily_call3 ) );
	mbuff.append( lineout( mars_daily_state3,		s_mars_daily_state3 ) );
	mbuff.append( lineout( mars_daily_sitrep_id,	s_mars_daily_sitrep_id ) );
	mbuff.append( lineout( mars_daily_sitrep_loc,	s_mars_daily_sitrep_loc ) );
	mbuff.append( lineout( mars_daily_24hr,		s_mars_daily_24hr ) );
	mbuff.append( lineout( mars_daily_netcall,		s_mars_daily_netcall ) );
	mbuff.append( lineout( mars_daily_e_x,			s_mars_daily_e_x ) );
	mbuff.append( lineout( mars_daily_dtg_active,	s_mars_daily_dtg_active ) );
	mbuff.append( lineout( mars_daily_dtg_deactive,s_mars_daily_dtg_deactive ) );
	mbuff.append( lineout( mars_daily_nbr_stations,s_mars_daily_nbr_stations ) );
	mbuff.append( lineout( mars_daily_details,		s_mars_daily_details ) );
	mbuff.append( lineout( mars_daily_activations,	s_mars_daily_activations ) );
	mbuff.append( lineout( mars_daily_agencies,	s_mars_daily_agencies ) );
	mbuff.append( lineout( mars_daily_remarks,		s_mars_daily_remarks ) );

	if (compress) compress_maybe(mbuff);
	buffmars_daily.append(mbuff);
}

void read_mars_daily_buffer(std::string data)
{
	clear_mars_dailyfields();

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
	if (check_mars_dailyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_mars_daily_save();
		}
	}
	clear_mars_daily_form();
	def_mars_daily_filename = ICS_msg_dir;
	def_mars_daily_filename.append("new").append(FMARSDAILY_EXT);
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

void cb_mars_daily_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_mars_daily_form();
	read_mars_daily_buffer(inpbuffer);
	def_mars_daily_filename = ICS_msg_dir;
	def_mars_daily_filename.append(wrapfilename);
	show_filename(def_mars_daily_filename);
	using_mars_daily_template = false;
}

int eval_mars_daily_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_mars_daily_filename).append("]");
	update_mars_dailyfields();
	update_header(FROM);
	evalstr.append(header("<mars_daily>"));
	buffmars_daily.clear();
	make_buffmars_daily(true);
	if (buffmars_daily.empty()) return 0;
	compress_maybe( buffmars_daily );
	evalstr.append( buffmars_daily );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_mars_daily_wrap_export()
{
	if (check_mars_dailyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_dailyfields();

	if (base_mars_daily_filename == std::string("new").append(FMARSDAILY_EXT) ||
		base_mars_daily_filename == std::string("default").append(FMARSDAILY_EXT) )
		if (!cb_mars_daily_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_daily_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buffmars_daily.assign(header("<mars_daily>"));
		make_buffmars_daily(true);
		export_wrapfile(base_mars_daily_filename, wrapfilename, buffmars_daily, pext != ".wrap");

		buffmars_daily.assign(header("<mars_daily>"));
		make_buffmars_daily(false);
		write_mars_daily(def_mars_daily_filename);
	}
}

void cb_mars_daily_wrap_autosend()
{
	if (check_mars_dailyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_dailyfields();

	if (base_mars_daily_filename == std::string("new").append(FMARSDAILY_EXT) ||
		base_mars_daily_filename == std::string("default").append(FMARSDAILY_EXT) )
		if (!cb_mars_daily_save_as()) return;

	update_header(FROM);
	buffmars_daily.assign(header("<mars_daily>"));
	make_buffmars_daily(true);
	xfr_via_socket(base_mars_daily_filename, buffmars_daily);

	buffmars_daily.assign(header("<mars_daily>"));
	make_buffmars_daily(false);
	write_mars_daily(def_mars_daily_filename);
}

void cb_mars_daily_load_template()
{
	std::string def_mars_daily_filename = def_mars_daily_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TMARSDAILY_EXT).c_str(),
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
	std::string def_mars_daily_filename = def_mars_daily_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TMARSDAILY_EXT).c_str(),
			def_mars_daily_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_mars_dailyfields();
		buffmars_daily.assign(header("<mars_daily>"));
		make_buffmars_daily();
		write_mars_daily(p);
	}
}

void cb_mars_daily_save_as_template()
{
	std::string def_mars_daily_filename = def_mars_daily_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TMARSDAILY_EXT).c_str(),
			def_mars_daily_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_daily_TemplateName = p;
		if (strlen(pext) == 0) def_mars_daily_TemplateName.append(TMARSDAILY_EXT);
		remove_spaces_from_filename(def_mars_daily_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_mars_dailyfields();
		buffmars_daily.assign(header("<mars_daily>"));
		make_buffmars_daily();
		write_mars_daily(def_mars_daily_TemplateName);

		show_filename(def_mars_daily_TemplateName);
		using_mars_daily_template = true;
	}
}

void cb_mars_daily_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-mars_daily\t*").append(FMARSDAILY_EXT).c_str(),
			def_mars_daily_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_daily_form();
	read_data_file(p);
	using_mars_daily_template = false;
	def_mars_daily_filename = p;
	show_filename(def_mars_daily_filename);
}

void write_mars_daily(std::string s)
{
	FILE *filemars_daily = fopen(s.c_str(), "w");
	if (!filemars_daily) return;

	fwrite(buffmars_daily.c_str(), buffmars_daily.length(), 1, filemars_daily);
	fclose(filemars_daily);
}

bool cb_mars_daily_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(FMARSDAILY_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_daily_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-mars_daily\t*").append(FMARSDAILY_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_mars_daily_filename = p;
	if (strlen(pext) == 0) def_mars_daily_filename.append(FMARSDAILY_EXT);

	remove_spaces_from_filename(def_mars_daily_filename);

	update_header(NEW);
	update_mars_dailyfields();
	buffmars_daily.assign(header("<mars_daily>"));
	make_buffmars_daily();
	write_mars_daily(def_mars_daily_filename);

	using_mars_daily_template = false;
	show_filename(def_mars_daily_filename);
	return true;
}

void cb_mars_daily_save()
{
	if (base_mars_daily_filename == std::string("new").append(FMARSDAILY_EXT) || 
		base_mars_daily_filename == std::string("default").append(FMARSDAILY_EXT) ||
		using_mars_daily_template == true) {
		cb_mars_daily_save_as();
		return;
	}
	if (check_mars_dailyfields()) update_header(CHANGED);
	update_mars_dailyfields();
	buffmars_daily.assign(header("<mars_daily>"));
	make_buffmars_daily();
	write_mars_daily(def_mars_daily_filename);

	using_mars_daily_template = false;
}

void cb_mars_daily_html()
{
	std::string fname_name = fl_filename_name(def_mars_daily_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string mars_daily_fname = ICS_dir;
	mars_daily_fname.append(fname_name);
	mars_daily_fname.append(".html");

	std::string html_text = "";

	update_mars_dailyfields();
	std::string formmars_daily = mars_daily_html_template;

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
	std::string temp = "";
	std::string mars_daily_fname = ICS_dir;
	mars_daily_fname.append("mars_daily.txt");

	update_mars_dailyfields();
	std::string formmars_daily = mars_daily_text_template;

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

