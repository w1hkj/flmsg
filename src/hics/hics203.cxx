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

// ---------------------------------------------------------------------
// hics 203 field variables and template variables
// ---------------------------------------------------------------------

std::string hics203_tag_incident					= ":inc:";
std::string hics203_tag_date						= ":dat:";
std::string hics203_tag_time						= ":tim:";
std::string hics203_tag_op_period				= ":opp:";
std::string hics203_tag_incident_commander		= ":icc:";
std::string hics203_tag_incident_safety_officer	= ":ics:";
std::string hics203_tag_incident_info_officer	= ":ici:";
std::string hics203_tag_liaison_officer			= ":icl:";
std::string hics203_tag_prepared_by				= ":pre:";
std::string hics203_tag_facility					= ":facility:";

std::string hics203_tag_tech_spc					= ":tech_spc[n]:"; // 6

std::string hics203_tag_ops_chief				= ":ops_chief:";
std::string hics203_tag_bus_brch					= ":bus_brch:";
std::string hics203_tag_stg_mgr					= ":stg_mgr:";
std::string hics203_tag_med_care_brch			= ":med_care_brch:";
std::string hics203_tag_infr_brch				= ":infr_brch:";
std::string hics203_tag_sec_brch					= ":sec_brch:";
std::string hics203_tag_hazmat_brch				= ":hazmat_brch:";
std::string hics203_tag_ops_other				= ":ops_other:";

std::string hics203_tag_fin_chief				= ":fin_chief:";
std::string hics203_tag_cost_unit				= ":cost_unit:";
std::string hics203_tag_proc_unit				= ":proc_unit:";
std::string hics203_tag_comp_unit				= ":comp_unit:";
std::string hics203_tag_time_unit				= ":time_unit:";
std::string hics203_tag_fin_other				= ":fin_other:";

std::string hics203_tag_planning_chief			= ":planning_chief:";
std::string hics203_tag_res_unit					= ":res_unit:";
std::string hics203_tag_sit_unit					= ":sit_unit:";
std::string hics203_tag_doc_unit					= ":doc_unit:";
std::string hics203_tag_dem_unit					= ":dem_unit:";
std::string hics203_tag_planning_other			= ":planning_other:";

std::string hics203_tag_log_chief				= ":log_chief:";
std::string hics203_tag_sup_brch					= ":sup_brch:";
std::string hics203_tag_svc_brch					= ":svc_brch:";
std::string hics203_tag_log_other				= ":log_other:";

std::string hics203_tag_hcc_agency				= ":hcc_agency:";
std::string hics203_tag_hcc_rep					= ":hcc_rep:";
std::string hics203_tag_ext_loc					= ":ext_loc:";
std::string hics203_tag_ext_rep					= ":ext_rep:";

std::string hics203_incident;
std::string hics203_date;
std::string hics203_time;
std::string hics203_op_period;
std::string hics203_incident_commander;
std::string hics203_incident_safety_officer;
std::string hics203_incident_info_officer;
std::string hics203_liaison_officer;
std::string hics203_prepared_by;
std::string hics203_facility;

std::string hics203_fin_chief;
std::string hics203_fin_other;
std::string hics203_time_unit;
std::string hics203_proc_unit;
std::string hics203_comp_unit;
std::string hics203_cost_unit;

std::string hics203_tech_spc[6];

std::string hics203_planning_chief;
std::string hics203_planning_other;
std::string hics203_res_unit;
std::string hics203_sit_unit;
std::string hics203_doc_unit;
std::string hics203_dem_unit;
std::string hics203_log_chief;
std::string hics203_log_other;
std::string hics203_log_sup_brch;
std::string hics203_bus_brch;
std::string hics203_stg_mgr;
std::string hics203_med_care_brch;
std::string hics203_infr_brch;
std::string hics203_sec_brch;
std::string hics203_hazmat_brch;
std::string hics203_hcc_agency;
std::string hics203_svc_brch;
std::string hics203_hcc_rep;
std::string hics203_ext_loc;
std::string hics203_ext_rep;
std::string hics203_ops_chief;
std::string hics203_ops_other;

// =====================================================================

std::string hics_buff203;
std::string def_hics203_filename = "";
std::string base_hics203_filename = "";
std::string def_hics203_TemplateName = "";
bool   using_hics203_template = false;

void cb_hics203_set_date()
{
	txt_hics203_date->value(szDate(progStatus.dtformat));
}

void cb_hics203_set_time()
{
	txt_hics203_time->value(szTime(progStatus.UTC));
}

void clear_hics203fields()
{
	hics203_incident.clear();
	hics203_date.clear();
	hics203_time.clear();
	hics203_op_period.clear();
	hics203_incident_commander.clear();
	hics203_incident_safety_officer.clear();
	hics203_incident_info_officer.clear();
	hics203_liaison_officer.clear();
	hics203_prepared_by.clear();
	hics203_facility.clear();
	hics203_planning_chief.clear();
	hics203_planning_other.clear();
	hics203_res_unit.clear();
	hics203_sit_unit.clear();
	hics203_doc_unit.clear();
	hics203_dem_unit.clear();
	hics203_log_chief.clear();
	hics203_log_other.clear();
	hics203_log_sup_brch.clear();
	hics203_bus_brch.clear();
	hics203_stg_mgr.clear();
	hics203_med_care_brch.clear();
	hics203_infr_brch.clear();
	hics203_sec_brch.clear();
	hics203_hazmat_brch.clear();
	hics203_hcc_agency.clear();
	hics203_svc_brch.clear();
	hics203_hcc_rep.clear();
	hics203_ext_loc.clear();
	hics203_ext_rep.clear();
	hics203_ops_chief.clear();
	hics203_ops_other.clear();
	hics203_fin_chief.clear();
	hics203_fin_other.clear();
	hics203_time_unit.clear();
	hics203_proc_unit.clear();
	hics203_comp_unit.clear();
	hics203_cost_unit.clear();

	for (int i = 0; i < 6; i++) {
		hics203_tech_spc[i].clear();
	}
}

bool check_hics203fields()
{
	if (hics203_incident != txt_hics203_incident->value())
		return true;
	if (hics203_date != txt_hics203_date->value())
		return true;
	if (hics203_time != txt_hics203_time->value())
		return true;
	if (hics203_op_period != txt_hics203_op_period->value())
		return true;
	if (hics203_incident_commander != txt_hics203_incident_commander->value())
		return true;
	if (hics203_incident_safety_officer != txt_hics203_incident_safety_officer->value())
		return true;
	if (hics203_incident_info_officer != txt_hics203_incident_info_officer->value())
		return true;
	if (hics203_liaison_officer != txt_hics203_liaison_officer->value())
		return true;
	if (hics203_prepared_by != txt_hics203_prepared_by->value())
		return true;
	if (hics203_facility != txt_hics203_facility->value())
		return true;
	if (hics203_planning_chief != txt_hics203_planning_chief->value())
		return true;
	if (hics203_planning_other != txt_hics203_planning_other->value())
		return true;
	if (hics203_res_unit != txt_hics203_res_unit->value())
		return true;
	if (hics203_sit_unit != txt_hics203_sit_unit->value())
		return true;
	if (hics203_doc_unit != txt_hics203_doc_unit->value())
		return true;
	if (hics203_dem_unit != txt_hics203_dem_unit->value())
		return true;
	if (hics203_log_chief != txt_hics203_log_chief->value())
		return true;
	if (hics203_log_other != txt_hics203_log_other->value())
		return true;
	if (hics203_log_sup_brch != txt_hics203_log_sup_brch->value())
		return true;
	if (hics203_bus_brch != txt_hics203_bus_brch->value())
		return true;
	if (hics203_stg_mgr != txt_hics203_stg_mgr->value())
		return true;
	if (hics203_med_care_brch != txt_hics203_med_care_brch->value())
		return true;
	if (hics203_infr_brch != txt_hics203_infr_brch->value())
		return true;
	if (hics203_sec_brch != txt_hics203_sec_brch->value())
		return true;
	if (hics203_hazmat_brch != txt_hics203_hazmat_brch->value())
		return true;
	if (hics203_hcc_agency != txt_hics203_hcc_agency->value())
		return true;
	if (hics203_svc_brch != txt_hics203_svc_brch->value())
		return true;
	if (hics203_hcc_rep != txt_hics203_hcc_rep->value())
		return true;
	if (hics203_ext_loc != txt_hics203_ext_loc->value())
		return true;
	if (hics203_ext_rep != txt_hics203_ext_rep->value())
		return true;
	if (hics203_ops_chief != txt_hics203_ops_chief->value())
		return true;
	if (hics203_ops_other != txt_hics203_ops_other->value())
		return true;
	if (hics203_fin_chief != txt_hics203_fin_chief->value())
		return true;
	if (hics203_fin_other != txt_hics203_fin_other->value())
		return true;
	if (hics203_time_unit != txt_hics203_time_unit->value())
		return true;
	if (hics203_proc_unit != txt_hics203_proc_unit->value())
		return true;
	if (hics203_comp_unit != txt_hics203_comp_unit->value())
		return true;
	if (hics203_cost_unit != txt_hics203_cost_unit->value())
		return true;

	for (int i = 0; i < 6; i++) {
		if (hics203_tech_spc[i] != txt_hics203_tech_spc[i]->value())
			return true;
	}
	return false;
}

void update_hics203fields()
{
	hics203_incident = txt_hics203_incident->value();
	hics203_date = txt_hics203_date->value();
	hics203_time = txt_hics203_time->value();
	hics203_op_period = txt_hics203_op_period->value();
	hics203_incident_commander = txt_hics203_incident_commander->value();
	hics203_incident_safety_officer = txt_hics203_incident_safety_officer->value();
	hics203_incident_info_officer = txt_hics203_incident_info_officer->value();
	hics203_liaison_officer = txt_hics203_liaison_officer->value();
	hics203_prepared_by = txt_hics203_prepared_by->value();
	hics203_facility = txt_hics203_facility->value();
	hics203_planning_chief = txt_hics203_planning_chief->value();
	hics203_planning_other = txt_hics203_planning_other->value();
	hics203_res_unit = txt_hics203_res_unit->value();
	hics203_sit_unit = txt_hics203_sit_unit->value();
	hics203_doc_unit = txt_hics203_doc_unit->value();
	hics203_dem_unit = txt_hics203_dem_unit->value();
	hics203_log_chief = txt_hics203_log_chief->value();
	hics203_log_other = txt_hics203_log_other->value();
	hics203_log_sup_brch = txt_hics203_log_sup_brch->value();
	hics203_bus_brch = txt_hics203_bus_brch->value();
	hics203_stg_mgr = txt_hics203_stg_mgr->value();
	hics203_med_care_brch = txt_hics203_med_care_brch->value();
	hics203_infr_brch = txt_hics203_infr_brch->value();
	hics203_sec_brch = txt_hics203_sec_brch->value();
	hics203_hazmat_brch = txt_hics203_hazmat_brch->value();
	hics203_hcc_agency = txt_hics203_hcc_agency->value();
	hics203_svc_brch = txt_hics203_svc_brch->value();
	hics203_hcc_rep = txt_hics203_hcc_rep->value();
	hics203_ext_loc = txt_hics203_ext_loc->value();
	hics203_ext_rep = txt_hics203_ext_rep->value();
	hics203_ops_chief = txt_hics203_ops_chief->value();
	hics203_ops_other = txt_hics203_ops_other->value();
	hics203_fin_chief = txt_hics203_fin_chief->value();
	hics203_fin_other = txt_hics203_fin_other->value();
	hics203_time_unit = txt_hics203_time_unit->value();
	hics203_proc_unit = txt_hics203_proc_unit->value();
	hics203_comp_unit = txt_hics203_comp_unit->value();
	hics203_cost_unit = txt_hics203_cost_unit->value();

	for (int i = 0; i < 6; i++) {
		hics203_tech_spc[i] = txt_hics203_tech_spc[i]->value();
	}
}

void update_hics203form()
{
	txt_hics203_incident->value(hics203_incident.c_str());
	txt_hics203_date->value(hics203_date.c_str());
	txt_hics203_time->value(hics203_time.c_str());
	txt_hics203_op_period->value(hics203_op_period.c_str());
	txt_hics203_incident_commander->value(hics203_incident_commander.c_str());
	txt_hics203_incident_safety_officer->value(hics203_incident_safety_officer.c_str());
	txt_hics203_incident_info_officer->value(hics203_incident_info_officer.c_str());
	txt_hics203_liaison_officer->value(hics203_liaison_officer.c_str());
	txt_hics203_prepared_by->value(hics203_prepared_by.c_str());
	txt_hics203_facility->value(hics203_facility.c_str());
	txt_hics203_planning_chief->value(hics203_planning_chief.c_str());
	txt_hics203_planning_other->value(hics203_planning_other.c_str());
	txt_hics203_res_unit->value(hics203_res_unit.c_str());
	txt_hics203_sit_unit->value(hics203_sit_unit.c_str());
	txt_hics203_doc_unit->value(hics203_doc_unit.c_str());
	txt_hics203_dem_unit->value(hics203_dem_unit.c_str());
	txt_hics203_log_chief->value(hics203_log_chief.c_str());
	txt_hics203_log_other->value(hics203_log_other.c_str());
	txt_hics203_log_sup_brch->value(hics203_log_sup_brch.c_str());
	txt_hics203_bus_brch->value(hics203_bus_brch.c_str());
	txt_hics203_stg_mgr->value(hics203_stg_mgr.c_str());
	txt_hics203_med_care_brch->value(hics203_med_care_brch.c_str());
	txt_hics203_infr_brch->value(hics203_infr_brch.c_str());
	txt_hics203_sec_brch->value(hics203_sec_brch.c_str());
	txt_hics203_hazmat_brch->value(hics203_hazmat_brch.c_str());
	txt_hics203_hcc_agency->value(hics203_hcc_agency.c_str());
	txt_hics203_svc_brch->value(hics203_svc_brch.c_str());
	txt_hics203_hcc_rep->value(hics203_hcc_rep.c_str());
	txt_hics203_ext_loc->value(hics203_ext_loc.c_str());
	txt_hics203_ext_rep->value(hics203_ext_rep.c_str());
	txt_hics203_ops_chief->value(hics203_ops_chief.c_str());
	txt_hics203_ops_other->value(hics203_ops_other.c_str());
	txt_hics203_fin_chief->value(hics203_fin_chief.c_str());
	txt_hics203_fin_other->value(hics203_fin_other.c_str());
	txt_hics203_time_unit->value(hics203_time_unit.c_str());
	txt_hics203_proc_unit->value(hics203_proc_unit.c_str());
	txt_hics203_comp_unit->value(hics203_comp_unit.c_str());
	txt_hics203_cost_unit->value(hics203_cost_unit.c_str());

	for (int i = 0; i < 6; i++) {
		txt_hics203_tech_spc[i]->value(hics203_tech_spc[i].c_str());
	}
}

void clear_hics203_form()
{
	clear_hics203fields();

	txt_hics203_incident->value("");
	txt_hics203_date->value("");
	txt_hics203_time->value("");
	txt_hics203_op_period->value("");
	txt_hics203_incident_commander->value("");
	txt_hics203_incident_safety_officer->value("");
	txt_hics203_incident_info_officer->value("");
	txt_hics203_liaison_officer->value("");
	txt_hics203_prepared_by->value("");
	txt_hics203_facility->value("");
	txt_hics203_planning_chief->value("");
	txt_hics203_planning_other->value("");
	txt_hics203_res_unit->value("");
	txt_hics203_sit_unit->value("");
	txt_hics203_doc_unit->value("");
	txt_hics203_dem_unit->value("");
	txt_hics203_log_chief->value("");
	txt_hics203_log_other->value("");
	txt_hics203_log_sup_brch->value("");
	txt_hics203_bus_brch->value("");
	txt_hics203_stg_mgr->value("");
	txt_hics203_med_care_brch->value("");
	txt_hics203_infr_brch->value("");
	txt_hics203_sec_brch->value("");
	txt_hics203_hazmat_brch->value("");
	txt_hics203_hcc_agency->value("");
	txt_hics203_svc_brch->value("");
	txt_hics203_hcc_rep->value("");
	txt_hics203_ext_loc->value("");
	txt_hics203_ext_rep->value("");
	txt_hics203_ops_chief->value("");
	txt_hics203_ops_other->value("");
	txt_hics203_fin_chief->value("");
	txt_hics203_fin_other->value("");
	txt_hics203_time_unit->value("");
	txt_hics203_proc_unit->value("");
	txt_hics203_comp_unit->value("");
	txt_hics203_cost_unit->value("");

	for (int i = 0; i < 6; i++) {
		txt_hics203_tech_spc[i]->value("");
	}
}

std::string &hics_n(std::string & subst, int n)
{
	static std::string garbage = "#$^*!";
	size_t pos = subst.find("[");
	if (pos == std::string::npos) return garbage;
	pos++;
	subst[pos] = '0' + n;
	return subst;
}

void make_hics_buff203(bool compress = false)
{
	std::string mbuff;
	mbuff.assign( lineout( hics203_tag_incident, hics203_incident ) );
	mbuff.append( lineout( hics203_tag_date, hics203_date ) );
	mbuff.append( lineout( hics203_tag_time, hics203_time ) );
	mbuff.append( lineout( hics203_tag_op_period, hics203_op_period ) );
	mbuff.append( lineout( hics203_tag_incident_commander, hics203_incident_commander ) );
	mbuff.append( lineout( hics203_tag_incident_safety_officer, hics203_incident_safety_officer ) );
	mbuff.append( lineout( hics203_tag_incident_info_officer, hics203_incident_info_officer ) );
	mbuff.append( lineout( hics203_tag_liaison_officer, hics203_liaison_officer ) );
	mbuff.append( lineout( hics203_tag_prepared_by, hics203_prepared_by ) );
	mbuff.append( lineout( hics203_tag_facility, hics203_facility ) );
	mbuff.append( lineout( hics203_tag_planning_chief, hics203_planning_chief ) );
	mbuff.append( lineout( hics203_tag_planning_other, hics203_planning_other ) );
	mbuff.append( lineout( hics203_tag_res_unit, hics203_res_unit ) );
	mbuff.append( lineout( hics203_tag_sit_unit, hics203_sit_unit ) );
	mbuff.append( lineout( hics203_tag_doc_unit, hics203_doc_unit ) );
	mbuff.append( lineout( hics203_tag_dem_unit, hics203_dem_unit ) );
	mbuff.append( lineout( hics203_tag_log_chief, hics203_log_chief ) );
	mbuff.append( lineout( hics203_tag_log_other, hics203_log_other ) );
	mbuff.append( lineout( hics203_tag_sup_brch, hics203_log_sup_brch ) );
	mbuff.append( lineout( hics203_tag_bus_brch, hics203_bus_brch ) );
	mbuff.append( lineout( hics203_tag_stg_mgr, hics203_stg_mgr ) );
	mbuff.append( lineout( hics203_tag_med_care_brch, hics203_med_care_brch ) );
	mbuff.append( lineout( hics203_tag_infr_brch, hics203_infr_brch ) );
	mbuff.append( lineout( hics203_tag_sec_brch, hics203_sec_brch ) );
	mbuff.append( lineout( hics203_tag_hazmat_brch, hics203_hazmat_brch ) );
	mbuff.append( lineout( hics203_tag_hcc_agency, hics203_hcc_agency ) );
	mbuff.append( lineout( hics203_tag_svc_brch, hics203_svc_brch ) );
	mbuff.append( lineout( hics203_tag_hcc_rep, hics203_hcc_rep ) );
	mbuff.append( lineout( hics203_tag_ext_loc, hics203_ext_loc ) );
	mbuff.append( lineout( hics203_tag_ext_rep, hics203_ext_rep ) );
	mbuff.append( lineout( hics203_tag_ops_chief, hics203_ops_chief ) );
	mbuff.append( lineout( hics203_tag_ops_other, hics203_ops_other ) );
	mbuff.append( lineout( hics203_tag_fin_chief, hics203_fin_chief ) );
	mbuff.append( lineout( hics203_tag_fin_other, hics203_fin_other ) );
	mbuff.append( lineout( hics203_tag_time_unit, hics203_time_unit ) );
	mbuff.append( lineout( hics203_tag_proc_unit, hics203_proc_unit ) );
	mbuff.append( lineout( hics203_tag_comp_unit, hics203_comp_unit ) );
	mbuff.append( lineout( hics203_tag_cost_unit, hics203_cost_unit ) );

	for (int i = 0; i < 6; i++) {
		mbuff.append( lineout( hics_n( hics203_tag_tech_spc, i ), hics203_tech_spc[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	hics_buff203.append(mbuff);
}

void read_hics203_buffer(std::string data)
{
	clear_hics203fields();
	read_header(data);

	hics203_incident = findstr(data, hics203_tag_incident);
	hics203_date = findstr(data, hics203_tag_date);
	hics203_time = findstr(data, hics203_tag_time);
	hics203_op_period = findstr(data, hics203_tag_op_period);
	hics203_incident_commander = findstr(data, hics203_tag_incident_commander);
	hics203_incident_safety_officer = findstr(data, hics203_tag_incident_safety_officer);
	hics203_incident_info_officer = findstr(data, hics203_tag_incident_info_officer);
	hics203_liaison_officer = findstr(data, hics203_tag_liaison_officer);
	hics203_prepared_by = findstr(data, hics203_tag_prepared_by);
	hics203_facility = findstr(data, hics203_tag_facility);
	hics203_planning_chief = findstr(data, hics203_tag_planning_chief);
	hics203_planning_other = findstr(data, hics203_tag_planning_other);
	hics203_res_unit = findstr(data, hics203_tag_res_unit);
	hics203_sit_unit = findstr(data, hics203_tag_sit_unit);
	hics203_doc_unit = findstr(data, hics203_tag_doc_unit);
	hics203_dem_unit = findstr(data, hics203_tag_dem_unit);
	hics203_log_chief = findstr(data, hics203_tag_log_chief);
	hics203_log_other = findstr(data, hics203_tag_log_other);
	hics203_log_sup_brch = findstr(data, hics203_tag_sup_brch);
	hics203_bus_brch = findstr(data, hics203_tag_bus_brch);
	hics203_stg_mgr = findstr(data, hics203_tag_stg_mgr);
	hics203_med_care_brch = findstr(data, hics203_tag_med_care_brch);
	hics203_infr_brch = findstr(data, hics203_tag_infr_brch);
	hics203_sec_brch = findstr(data, hics203_tag_sec_brch);
	hics203_hazmat_brch = findstr(data, hics203_tag_hazmat_brch);
	hics203_hcc_agency = findstr(data, hics203_tag_hcc_agency);
	hics203_svc_brch = findstr(data, hics203_tag_svc_brch);
	hics203_hcc_rep = findstr(data, hics203_tag_hcc_rep);
	hics203_ext_loc = findstr(data, hics203_tag_ext_loc);
	hics203_ext_rep = findstr(data, hics203_tag_ext_rep);
	hics203_ops_chief = findstr(data, hics203_tag_ops_chief);
	hics203_ops_other = findstr(data, hics203_tag_ops_other);
	hics203_fin_chief = findstr(data, hics203_tag_fin_chief);
	hics203_fin_other = findstr(data, hics203_tag_fin_other);
	hics203_time_unit = findstr(data, hics203_tag_time_unit);
	hics203_proc_unit = findstr(data, hics203_tag_proc_unit);
	hics203_comp_unit = findstr(data, hics203_tag_comp_unit);
	hics203_cost_unit = findstr(data, hics203_tag_cost_unit);

	for (int i = 0; i < 6; i++) {
		hics203_tech_spc[i] = findstr(data, hics_n( hics203_tag_tech_spc, i) );
	}
	update_hics203form();
}

void cb_hics203_new()
{
	if (check_hics203fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_hics203_save();
		}
	}
	clear_hics203_form();
	clear_header();
	def_hics203_filename = ICS_msg_dir;
	def_hics203_filename.append("new").append(HF203_EXT);
	show_filename(def_hics203_filename);
	using_hics203_template = false;
}

void cb_hics203_import()
{
	fl_alert2("Not implemented");
}

void cb_hics203_export()
{
	fl_alert2("Not implemented");
}

void cb_hics203_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_hics203_form();
	read_hics203_buffer(inpbuffer);
	def_hics203_filename = ICS_msg_dir;
	def_hics203_filename.append(wrapfilename);
	show_filename(def_hics203_filename);
	using_hics203_template = false;
}

int eval_hics203_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_hics203_filename).append("]");
	update_hics203fields();
	update_header(FROM);
	evalstr.append(header("<hics203>"));
	hics_buff203.clear();
	make_hics_buff203(true);
	if (hics_buff203.empty()) return 0;
	compress_maybe( hics_buff203 );
	evalstr.append( hics_buff203 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_hics203_wrap_export()
{
	if (check_hics203fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_hics203fields();

	if (base_hics203_filename == std::string("new").append(HF203_EXT) ||
		base_hics203_filename == std::string("default").append(HF203_EXT) )
		if (!cb_hics203_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_hics203_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		hics_buff203.assign(header("<hics203>"));
		make_hics_buff203(true);
		export_wrapfile(base_hics203_filename, wrapfilename, hics_buff203, pext != ".wrap");

		hics_buff203.assign(header("<hics203>"));
		make_hics_buff203(false);
		write_hics203(def_hics203_filename);
	}
}

void cb_hics203_wrap_autosend()
{
	if (check_hics203fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_hics203fields();

	if (base_hics203_filename == std::string("new").append(HF203_EXT) ||
		base_hics203_filename == std::string("default").append(HF203_EXT) )
		cb_hics203_save_as();

	update_header(FROM);
	hics_buff203.assign(header("<hics203>"));
	make_hics_buff203(true);
	xfr_via_socket(base_hics203_filename, hics_buff203);

	hics_buff203.assign(header("<hics203>"));
	make_hics_buff203(false);
	write_hics203(def_hics203_filename);
}

void cb_hics203_load_template()
{
	std::string def_hics203_filename = def_hics203_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(HT203_EXT).c_str(),
			def_hics203_filename.c_str());
	if (p) {
		clear_hics203_form();
		read_data_file(p);
		def_hics203_TemplateName = p;
		show_filename(def_hics203_TemplateName);
		using_hics203_template = true;
	}
}

void cb_hics203_save_template()
{
	if (!using_hics203_template) {
		cb_hics203_save_as_template();
		return;
	}
	std::string def_hics203_filename = def_hics203_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(HT203_EXT).c_str(),
			def_hics203_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_203fields();
		hics_buff203.assign(header("<hics203>"));
		make_hics_buff203();
		write_hics203(p);
	}
}

void cb_hics203_save_as_template()
{
	std::string def_hics203_filename = def_hics203_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(HT203_EXT).c_str(),
			def_hics203_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_hics203_TemplateName = p;
		if (strlen(pext) == 0) def_hics203_TemplateName.append(HT203_EXT);
		remove_spaces_from_filename(def_hics203_TemplateName);
		clear_header();
		update_header(CHANGED);
		update_203fields();
		hics_buff203.assign(header("<hics203>"));
		make_hics_buff203();
		write_hics203(def_hics203_TemplateName);
		show_filename(def_hics203_TemplateName);
		using_hics203_template = true;
	}
}

void cb_hics203_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("HICS-203\t*").append(HF203_EXT).c_str(),
			def_hics203_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_hics203_form();
	read_data_file(p);
	using_hics203_template = false;
	def_hics203_filename = p;
	show_filename(def_hics203_filename);
}

void write_hics203(std::string s)
{
	FILE *file203 = fopen(s.c_str(), "w");
	if (!file203) return;

	fwrite(hics_buff203.c_str(), hics_buff203.length(), 1, file203);
	fclose(file203);
}

bool cb_hics203_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(F203_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_hics203_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("HICS-203\t*").append(HF203_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_hics203_filename = p;
	if (strlen(pext) == 0) def_hics203_filename.append(HF203_EXT);

	remove_spaces_from_filename(def_hics203_filename);
	update_hics203fields();
	update_header(NEW);
	hics_buff203.assign(header("<hics203>"));
	make_hics_buff203();
	write_hics203(def_hics203_filename);

	using_hics203_template = false;
	show_filename(def_hics203_filename);
	return true;
}

void cb_hics203_save()
{
	if (base_hics203_filename == std::string("new").append(HF203_EXT) || 
		base_hics203_filename == std::string("default").append(HF203_EXT) ||
		using_hics203_template == true) {
		cb_hics203_save_as();
		return;
	}
	if (check_hics203fields()) update_header(CHANGED);
	update_hics203fields();
	hics_buff203.assign(header("<hics203>"));
	make_hics_buff203();
	write_hics203(def_hics203_filename);
	using_hics203_template = false;
}

void cb_hics203_html()
{
	std::string fname_name = fl_filename_name(def_hics203_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string hics203_fname = ICS_dir;
	hics203_fname.append(fname_name);
	hics203_fname.append(".html");

	std::string html_text = "";

	update_hics203fields();
	std::string form203 = hics203_html_template;
	replacestr(form203, TITLE, fname_name);

	replacestr(form203, hics203_tag_incident, hics203_incident );
	replacestr(form203, hics203_tag_date, hics203_date );
	replacestr(form203, hics203_tag_time, hics203_time );
	replacestr(form203, hics203_tag_op_period, hics203_op_period );
	replacestr(form203, hics203_tag_incident_commander, hics203_incident_commander );
	replacestr(form203, hics203_tag_incident_safety_officer, hics203_incident_safety_officer );
	replacestr(form203, hics203_tag_incident_info_officer, hics203_incident_info_officer );
	replacestr(form203, hics203_tag_liaison_officer, hics203_liaison_officer );
	replacestr(form203, hics203_tag_prepared_by, hics203_prepared_by );
	replacestr(form203, hics203_tag_facility, hics203_facility );
	replacestr(form203, hics203_tag_planning_chief, hics203_planning_chief );
	replacestr(form203, hics203_tag_planning_other, hics203_planning_other );
	replacestr(form203, hics203_tag_res_unit, hics203_res_unit );
	replacestr(form203, hics203_tag_sit_unit, hics203_sit_unit );
	replacestr(form203, hics203_tag_doc_unit, hics203_doc_unit );
	replacestr(form203, hics203_tag_dem_unit, hics203_dem_unit );
	replacestr(form203, hics203_tag_log_chief, hics203_log_chief );
	replacestr(form203, hics203_tag_log_other, hics203_log_other );
	replacestr(form203, hics203_tag_sup_brch, hics203_log_sup_brch );
	replacestr(form203, hics203_tag_bus_brch, hics203_bus_brch );
	replacestr(form203, hics203_tag_stg_mgr, hics203_stg_mgr);
	replacestr(form203, hics203_tag_med_care_brch, hics203_med_care_brch);
	replacestr(form203, hics203_tag_infr_brch, hics203_infr_brch);
	replacestr(form203, hics203_tag_sec_brch, hics203_sec_brch);
	replacestr(form203, hics203_tag_hazmat_brch, hics203_hazmat_brch );
	replacestr(form203, hics203_tag_hcc_agency, hics203_hcc_agency );
	replacestr(form203, hics203_tag_svc_brch, hics203_svc_brch );
	replacestr(form203, hics203_tag_hcc_rep, hics203_hcc_rep );
	replacestr(form203, hics203_tag_ext_loc, hics203_ext_loc );
	replacestr(form203, hics203_tag_ext_rep, hics203_ext_rep );
	replacestr(form203, hics203_tag_ops_chief, hics203_ops_chief );
	replacestr(form203, hics203_tag_ops_other, hics203_ops_other );
	replacestr(form203, hics203_tag_fin_chief, hics203_fin_chief );
	replacestr(form203, hics203_tag_fin_other, hics203_fin_other );
	replacestr(form203, hics203_tag_time_unit, hics203_time_unit );
	replacestr(form203, hics203_tag_proc_unit, hics203_proc_unit );
	replacestr(form203, hics203_tag_comp_unit, hics203_comp_unit );
	replacestr(form203, hics203_tag_cost_unit, hics203_cost_unit );

	for (int i = 0; i < 6; i++) {
		replacestr(form203, hics_n( hics203_tag_tech_spc, i ), hics203_tech_spc[i] );
	}

	FILE *file203 = fopen(hics203_fname.c_str(), "w");
	fprintf(file203,"%s", form203.c_str());
	fclose(file203);

	open_url(hics203_fname.c_str());
}

void cb_hics203_msg_type()
{
	if (tabs_msg_type->value() == tab_hics203 ) {
		tab_hics203_type->value(tab_hics203_1);
		show_filename(def_hics203_filename);
	}
}

void cb_hics203_textout()
{
	std::string hics203_fname = ICS_dir;
	hics203_fname.append("hics203.txt");

	update_hics203fields();
	std::string form203 = hics203_text_template;

	replacestr(form203, hics203_tag_incident, hics203_incident );
	replacestr(form203, hics203_tag_date, hics203_date );
	replacestr(form203, hics203_tag_time, hics203_time );
	replacestr(form203, hics203_tag_op_period, hics203_op_period );
	replacestr(form203, hics203_tag_incident_commander, hics203_incident_commander );
	replacestr(form203, hics203_tag_incident_safety_officer, hics203_incident_safety_officer );
	replacestr(form203, hics203_tag_incident_info_officer, hics203_incident_info_officer );
	replacestr(form203, hics203_tag_liaison_officer, hics203_liaison_officer );
	replacestr(form203, hics203_tag_prepared_by, hics203_prepared_by );
	replacestr(form203, hics203_tag_facility, hics203_facility );
	replacestr(form203, hics203_tag_planning_chief, hics203_planning_chief );
	replacestr(form203, hics203_tag_planning_other, hics203_planning_other );
	replacestr(form203, hics203_tag_res_unit, hics203_res_unit );
	replacestr(form203, hics203_tag_sit_unit, hics203_sit_unit );
	replacestr(form203, hics203_tag_doc_unit, hics203_doc_unit );
	replacestr(form203, hics203_tag_dem_unit, hics203_dem_unit );
	replacestr(form203, hics203_tag_log_chief, hics203_log_chief );
	replacestr(form203, hics203_tag_log_other, hics203_log_other );
	replacestr(form203, hics203_tag_sup_brch, hics203_log_sup_brch );
	replacestr(form203, hics203_tag_bus_brch, hics203_bus_brch );
	replacestr(form203, hics203_tag_stg_mgr, hics203_stg_mgr);
	replacestr(form203, hics203_tag_med_care_brch, hics203_med_care_brch);
	replacestr(form203, hics203_tag_infr_brch, hics203_infr_brch);
	replacestr(form203, hics203_tag_sec_brch, hics203_sec_brch);
	replacestr(form203, hics203_tag_hazmat_brch, hics203_hazmat_brch );
	replacestr(form203, hics203_tag_hcc_agency, hics203_hcc_agency );
	replacestr(form203, hics203_tag_svc_brch, hics203_svc_brch );
	replacestr(form203, hics203_tag_hcc_rep, hics203_hcc_rep );
	replacestr(form203, hics203_tag_ext_loc, hics203_ext_loc );
	replacestr(form203, hics203_tag_ext_rep, hics203_ext_rep );
	replacestr(form203, hics203_tag_ops_chief, hics203_ops_chief );
	replacestr(form203, hics203_tag_ops_other, hics203_ops_other );
	replacestr(form203, hics203_tag_fin_chief, hics203_fin_chief );
	replacestr(form203, hics203_tag_fin_other, hics203_fin_other );
	replacestr(form203, hics203_tag_time_unit, hics203_time_unit );
	replacestr(form203, hics203_tag_proc_unit, hics203_proc_unit );
	replacestr(form203, hics203_tag_comp_unit, hics203_comp_unit );
	replacestr(form203, hics203_tag_cost_unit, hics203_cost_unit );

	for (int i = 0; i < 6; i++) {
		replacestr(form203, hics_n( hics203_tag_tech_spc, i ), hics203_tech_spc[i] );
	}

	FILE *file203 = fopen(hics203_fname.c_str(), "w");
	fprintf(file203,"%s", form203.c_str());
	fclose(file203);

	open_url(hics203_fname.c_str());
}
