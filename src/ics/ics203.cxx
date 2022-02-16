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

// ---------------------------------------------------------------------
// ics 203 field variables and template variables
// ---------------------------------------------------------------------

std::string ics203_incident					= ":inc:";
std::string ics203_date						= ":dat:";
std::string ics203_time						= ":tim:";
std::string ics203_op_period					= ":opp:";
std::string ics203_incident_commander		= ":icc:";
std::string ics203_incident_deputy			= ":icd:";
std::string ics203_incident_safety_officer	= ":ics:";
std::string ics203_incident_info_officer		= ":ici:";
std::string ics203_liaison_officer			= ":icl:";
std::string ics203_prepared_by				= ":pre:";
std::string ics203_agency					= ":agency[n]:"; // 7
std::string ics203_agency_name				= ":agency_name[n]:"; // 7
std::string ics203_planning_chief			= ":planning_chief:";
std::string ics203_planning_deputy			= ":planning_deputy:";
std::string ics203_resources_unit			= ":resources_unit:";
std::string ics203_situation_unit			= ":situation_unit:";
std::string ics203_documentation_unit		= ":documentation_unit:";
std::string ics203_demobilization_unit		= ":demobilization_unit:";
std::string ics203_tech_spc					= ":tech_spc[n]:"; // 3
std::string ics203_logistics_chief			= ":logistics_chief:";
std::string ics203_logistics_deputy			= ":logistics_deputy:";
std::string ics203_support_director			= ":support_director:";
std::string ics203_supply_unit				= ":supply_unit:";
std::string ics203_facilities_unit			= ":facilities_unit:";
std::string ics203_ground_support			= ":ground_support:";
std::string ics203_service_director			= ":service_director:";
std::string ics203_communications_unit		= ":communications_unit:";
std::string ics203_medical_unit				= ":medical_unit:";
std::string ics203_food_unit					= ":food_unit:";
std::string ics203_ops_chief					= ":ops_chief:";
std::string ics203_ops_deputy				= ":ops_deputy:";
std::string ics203_b1_director				= ":b1_director:";
std::string ics203_b1_deputy					= ":b1_deputy:";
std::string ics203_b1_div					= ":b1_div[n]:"; // 4
std::string ics203_b1_grp					= ":b1_grp[n]:"; // 4
std::string ics203_b2_director				= ":b2_director:";
std::string ics203_b2_deputy					= ":b2_deputy:";
std::string ics203_b2_div					= ":b2_div[n]:"; // 4
std::string ics203_b2_grp					= ":b2_grp[n]:"; // 4
std::string ics203_b3_director				= ":b3_director:";
std::string ics203_b3_deputy					= ":b3_deputy:";
std::string ics203_b3_div					= ":b3_div[n]:"; // 4
std::string ics203_b3_grp					= ":b3_grp[n]:"; // 4
std::string ics203_air_ops_br_dir			= ":air_ops_br_dir:";
std::string ics203_air_tactical_group_sup	= ":air_tactical_group_sup:";
std::string ics203_air_support_group_sup		= ":air_support_group_sup:";
std::string ics203_helicopter_coordinator	= ":helicopter_coordinator:";
std::string ics203_air_tanker_fixed_wing		= ":air_tanker_fixed_wing:";
std::string ics203_finance_chief				= ":finance_chief:";
std::string ics203_finance_deputy			= ":finance_deputy:";
std::string ics203_time_unit					= ":time_unit:";
std::string ics203_procurement_unit			= ":procurement_unit:";
std::string ics203_claims_unit				= ":claims_unit:";
std::string ics203_cost_unit					= ":cost_unit:";

std::string s203_incident;
std::string s203_date;
std::string s203_time;
std::string s203_op_period;
std::string s203_incident_commander;
std::string s203_incident_deputy;
std::string s203_incident_safety_officer;
std::string s203_incident_info_officer;
std::string s203_liaison_officer;
std::string s203_prepared_by;
std::string s203_agency[7];
std::string s203_agency_name[7];
std::string s203_planning_chief;
std::string s203_planning_deputy;
std::string s203_resources_unit;
std::string s203_situation_unit;
std::string s203_documentation_unit;
std::string s203_demobilization_unit;
std::string s203_tech_spc[3];
std::string s203_logistics_chief;
std::string s203_logistics_deputy;
std::string s203_support_director;
std::string s203_supply_unit;
std::string s203_facilities_unit;
std::string s203_ground_support;
std::string s203_service_director;
std::string s203_communications_unit;
std::string s203_medical_unit;
std::string s203_food_unit;
std::string s203_ops_chief;
std::string s203_ops_deputy;
std::string s203_b1_director;
std::string s203_b1_deputy;
std::string s203_b1_div[5];
std::string s203_b1_grp[5];
std::string s203_b2_director;
std::string s203_b2_deputy;
std::string s203_b2_div[5];
std::string s203_b2_grp[5];
std::string s203_b3_director;
std::string s203_b3_deputy;
std::string s203_b3_div[5];
std::string s203_b3_grp[5];
std::string s203_air_ops_br_dir;
std::string s203_air_tactical_group_sup;
std::string s203_air_support_group_sup;
std::string s203_helicopter_coordinator;
std::string s203_air_tanker_fixed_wing;
std::string s203_finance_chief;
std::string s203_finance_deputy;
std::string s203_time_unit;
std::string s203_procurement_unit;
std::string s203_claims_unit;
std::string s203_cost_unit;

// =====================================================================

std::string buff203;
std::string def_203_filename = "";
std::string base_203_filename = "";
std::string def_203_TemplateName = "";
bool using_ics203_template = false;

void cb_203_set_date()
{
	txt_203_date->value(szDate(progStatus.dtformat));
}

void cb_203_set_time()
{
	txt_203_time->value(szTime(progStatus.UTC));
}

void clear_203fields()
{
	s203_incident.clear();
	s203_date.clear();
	s203_time.clear();
	s203_op_period.clear();
	s203_incident_commander.clear();
	s203_incident_deputy.clear();
	s203_incident_safety_officer.clear();
	s203_incident_info_officer.clear();
	s203_liaison_officer.clear();
	s203_prepared_by.clear();
	s203_planning_chief.clear();
	s203_planning_deputy.clear();
	s203_resources_unit.clear();
	s203_situation_unit.clear();
	s203_documentation_unit.clear();
	s203_demobilization_unit.clear();
	s203_logistics_chief.clear();
	s203_logistics_deputy.clear();
	s203_support_director.clear();
	s203_supply_unit.clear();
	s203_facilities_unit.clear();
	s203_ground_support.clear();
	s203_service_director.clear();
	s203_communications_unit.clear();
	s203_medical_unit.clear();
	s203_food_unit.clear();
	s203_ops_chief.clear();
	s203_ops_deputy.clear();
	s203_b1_director.clear();
	s203_b1_deputy.clear();
	s203_b2_director.clear();
	s203_b2_deputy.clear();
	s203_b3_director.clear();
	s203_b3_deputy.clear();
	s203_air_ops_br_dir.clear();
	s203_air_tactical_group_sup.clear();
	s203_air_support_group_sup.clear();
	s203_helicopter_coordinator.clear();
	s203_air_tanker_fixed_wing.clear();
	s203_finance_chief.clear();
	s203_finance_deputy.clear();
	s203_time_unit.clear();
	s203_procurement_unit.clear();
	s203_claims_unit.clear();
	s203_cost_unit.clear();

	for (int i = 0; i < 7; i++) {
		s203_agency[i].clear();
		s203_agency_name[i].clear();
	}
	for (int i = 0; i < 3; i++) {
		s203_tech_spc[i].clear();
	}
	for (int i = 0; i < 5; i++) {
		s203_b1_div[i].clear();
		s203_b1_grp[i].clear();
		s203_b2_div[i].clear();
		s203_b2_grp[i].clear();
		s203_b3_div[i].clear();
		s203_b3_grp[i].clear();
	}
}

bool check_203fields() {
	if (s203_incident != txt_203_incident->value())
		return true;
	if (s203_date != txt_203_date->value())
		return true;
	if (s203_time != txt_203_time->value())
		return true;
	if (s203_op_period != txt_203_op_period->value())
		return true;
	if (s203_incident_commander != txt_203_incident_commander->value())
		return true;
	if (s203_incident_deputy != txt_203_incident_deputy->value())
		return true;
	if (s203_incident_safety_officer != txt_203_incident_safety_officer->value())
		return true;
	if (s203_incident_info_officer != txt_203_incident_info_officer->value())
		return true;
	if (s203_liaison_officer != txt_203_liaison_officer->value())
		return true;
	if (s203_prepared_by != txt_203_prepared_by->value())
		return true;
	if (s203_planning_chief != txt_203_planning_chief->value())
		return true;
	if (s203_planning_deputy != txt_203_planning_deputy->value())
		return true;
	if (s203_resources_unit != txt_203_resources_unit->value())
		return true;
	if (s203_situation_unit != txt_203_situation_unit->value())
		return true;
	if (s203_documentation_unit != txt_203_documentation_unit->value())
		return true;
	if (s203_demobilization_unit != txt_203_demobilization_unit->value())
		return true;
	if (s203_logistics_chief != txt_203_logistics_chief->value())
		return true;
	if (s203_logistics_deputy != txt_203_logistics_deputy->value())
		return true;
	if (s203_support_director != txt_203_support_director->value())
		return true;
	if (s203_supply_unit != txt_203_supply_unit->value())
		return true;
	if (s203_facilities_unit != txt_203_facilities_unit->value())
		return true;
	if (s203_ground_support != txt_203_ground_support->value())
		return true;
	if (s203_service_director != txt_203_service_director->value())
		return true;
	if (s203_communications_unit != txt_203_communications_unit->value())
		return true;
	if (s203_medical_unit != txt_203_medical_unit->value())
		return true;
	if (s203_food_unit != txt_203_food_unit->value())
		return true;
	if (s203_ops_chief != txt_203_ops_chief->value())
		return true;
	if (s203_ops_deputy != txt_203_ops_deputy->value())
		return true;
	if (s203_b1_director != txt_203_b1_director->value())
		return true;
	if (s203_b1_deputy != txt_203_b1_deputy->value())
		return true;
	if (s203_b2_director != txt_203_b2_director->value())
		return true;
	if (s203_b2_deputy != txt_203_b2_deputy->value())
		return true;
	if (s203_b3_director != txt_203_b3_director->value())
		return true;
	if (s203_b3_deputy != txt_203_b3_deputy->value())
		return true;
	if (s203_air_ops_br_dir != txt_203_air_ops_br_dir->value())
		return true;
	if (s203_air_tactical_group_sup != txt_203_air_tactical_group_sup->value())
		return true;
	if (s203_air_support_group_sup != txt_203_air_support_group_sup->value())
		return true;
	if (s203_helicopter_coordinator != txt_203_helicopter_coordinator->value())
		return true;
	if (s203_air_tanker_fixed_wing != txt_203_air_tanker_fixed_wing->value())
		return true;
	if (s203_finance_chief != txt_203_finance_chief->value())
		return true;
	if (s203_finance_deputy != txt_203_finance_deputy->value())
		return true;
	if (s203_time_unit != txt_203_time_unit->value())
		return true;
	if (s203_procurement_unit != txt_203_procurement_unit->value())
		return true;
	if (s203_claims_unit != txt_203_claims_unit->value())
		return true;
	if (s203_cost_unit != txt_203_cost_unit->value())
		return true;

	for (int i = 0; i < 7; i++) {
		if (s203_agency[i] != txt_203_agency[i]->value())
			return true;
		if (s203_agency_name[i] != txt_203_agency_name[i]->value())
			return true;
	}

	for (int i = 0; i < 3; i++) {
		if (s203_tech_spc[i] != txt_203_tech_spc[i]->value())
			return true;
	}

	for (int i = 0; i < 5; i++) {
		if (s203_b1_div[i] != txt_203_b1_div[i]->value())
			return true;
		if (s203_b1_grp[i] != txt_203_b1_grp[i]->value())
			return true;
		if (s203_b2_div[i] != txt_203_b2_div[i]->value())
			return true;
		if (s203_b2_grp[i] != txt_203_b2_grp[i]->value())
			return true;
		if (s203_b3_div[i] != txt_203_b3_div[i]->value())
			return true;
		if (s203_b3_grp[i] != txt_203_b3_grp[i]->value())
			return true;
	}
	return false;
}

void update_203fields()
{
	s203_incident = txt_203_incident->value();
	s203_date = txt_203_date->value();
	s203_time = txt_203_time->value();
	s203_op_period = txt_203_op_period->value();
	s203_incident_commander = txt_203_incident_commander->value();
	s203_incident_deputy = txt_203_incident_deputy->value();
	s203_incident_safety_officer = txt_203_incident_safety_officer->value();
	s203_incident_info_officer = txt_203_incident_info_officer->value();
	s203_liaison_officer = txt_203_liaison_officer->value();
	s203_prepared_by = txt_203_prepared_by->value();
	s203_planning_chief = txt_203_planning_chief->value();
	s203_planning_deputy = txt_203_planning_deputy->value();
	s203_resources_unit = txt_203_resources_unit->value();
	s203_situation_unit = txt_203_situation_unit->value();
	s203_documentation_unit = txt_203_documentation_unit->value();
	s203_demobilization_unit = txt_203_demobilization_unit->value();
	s203_logistics_chief = txt_203_logistics_chief->value();
	s203_logistics_deputy = txt_203_logistics_deputy->value();
	s203_support_director = txt_203_support_director->value();
	s203_supply_unit = txt_203_supply_unit->value();
	s203_facilities_unit = txt_203_facilities_unit->value();
	s203_ground_support = txt_203_ground_support->value();
	s203_service_director = txt_203_service_director->value();
	s203_communications_unit = txt_203_communications_unit->value();
	s203_medical_unit = txt_203_medical_unit->value();
	s203_food_unit = txt_203_food_unit->value();
	s203_ops_chief = txt_203_ops_chief->value();
	s203_ops_deputy = txt_203_ops_deputy->value();
	s203_b1_director = txt_203_b1_director->value();
	s203_b1_deputy = txt_203_b1_deputy->value();
	s203_b2_director = txt_203_b2_director->value();
	s203_b2_deputy = txt_203_b2_deputy->value();
	s203_b3_director = txt_203_b3_director->value();
	s203_b3_deputy = txt_203_b3_deputy->value();
	s203_air_ops_br_dir = txt_203_air_ops_br_dir->value();
	s203_air_tactical_group_sup = txt_203_air_tactical_group_sup->value();
	s203_air_support_group_sup = txt_203_air_support_group_sup->value();
	s203_helicopter_coordinator = txt_203_helicopter_coordinator->value();
	s203_air_tanker_fixed_wing = txt_203_air_tanker_fixed_wing->value();
	s203_finance_chief = txt_203_finance_chief->value();
	s203_finance_deputy = txt_203_finance_deputy->value();
	s203_time_unit = txt_203_time_unit->value();
	s203_procurement_unit = txt_203_procurement_unit->value();
	s203_claims_unit = txt_203_claims_unit->value();
	s203_cost_unit = txt_203_cost_unit->value();

	for (int i = 0; i < 7; i++) {
		s203_agency[i] = txt_203_agency[i]->value();
		s203_agency_name[i] = txt_203_agency_name[i]->value();
	}

	for (int i = 0; i < 3; i++) {
		s203_tech_spc[i] = txt_203_tech_spc[i]->value();
	}

	for (int i = 0; i < 5; i++) {
		s203_b1_div[i] = txt_203_b1_div[i]->value();
		s203_b1_grp[i] = txt_203_b1_grp[i]->value();
		s203_b2_div[i] = txt_203_b2_div[i]->value();
		s203_b2_grp[i] = txt_203_b2_grp[i]->value();
		s203_b3_div[i] = txt_203_b3_div[i]->value();
		s203_b3_grp[i] = txt_203_b3_grp[i]->value();
	}
}

void update_203form()
{
	txt_203_incident->value(s203_incident.c_str());
	txt_203_date->value(s203_date.c_str());
	txt_203_time->value(s203_time.c_str());
	txt_203_op_period->value(s203_op_period.c_str());
	txt_203_incident_commander->value(s203_incident_commander.c_str());
	txt_203_incident_deputy->value(s203_incident_deputy.c_str());
	txt_203_incident_safety_officer->value(s203_incident_safety_officer.c_str());
	txt_203_incident_info_officer->value(s203_incident_info_officer.c_str());
	txt_203_liaison_officer->value(s203_liaison_officer.c_str());
	txt_203_prepared_by->value(s203_prepared_by.c_str());
	txt_203_planning_chief->value(s203_planning_chief.c_str());
	txt_203_planning_deputy->value(s203_planning_deputy.c_str());
	txt_203_resources_unit->value(s203_resources_unit.c_str());
	txt_203_situation_unit->value(s203_situation_unit.c_str());
	txt_203_documentation_unit->value(s203_documentation_unit.c_str());
	txt_203_demobilization_unit->value(s203_demobilization_unit.c_str());
	txt_203_logistics_chief->value(s203_logistics_chief.c_str());
	txt_203_logistics_deputy->value(s203_logistics_deputy.c_str());
	txt_203_support_director->value(s203_support_director.c_str());
	txt_203_supply_unit->value(s203_supply_unit.c_str());
	txt_203_facilities_unit->value(s203_facilities_unit.c_str());
	txt_203_ground_support->value(s203_ground_support.c_str());
	txt_203_service_director->value(s203_service_director.c_str());
	txt_203_communications_unit->value(s203_communications_unit.c_str());
	txt_203_medical_unit->value(s203_medical_unit.c_str());
	txt_203_food_unit->value(s203_food_unit.c_str());
	txt_203_ops_chief->value(s203_ops_chief.c_str());
	txt_203_ops_deputy->value(s203_ops_deputy.c_str());
	txt_203_b1_director->value(s203_b1_director.c_str());
	txt_203_b1_deputy->value(s203_b1_deputy.c_str());
	txt_203_b2_director->value(s203_b2_director.c_str());
	txt_203_b2_deputy->value(s203_b2_deputy.c_str());
	txt_203_b3_director->value(s203_b3_director.c_str());
	txt_203_b3_deputy->value(s203_b3_deputy.c_str());
	txt_203_air_ops_br_dir->value(s203_air_ops_br_dir.c_str());
	txt_203_air_tactical_group_sup->value(s203_air_tactical_group_sup.c_str());
	txt_203_air_support_group_sup->value(s203_air_support_group_sup.c_str());
	txt_203_helicopter_coordinator->value(s203_helicopter_coordinator.c_str());
	txt_203_air_tanker_fixed_wing->value(s203_air_tanker_fixed_wing.c_str());
	txt_203_finance_chief->value(s203_finance_chief.c_str());
	txt_203_finance_deputy->value(s203_finance_deputy.c_str());
	txt_203_time_unit->value(s203_time_unit.c_str());
	txt_203_procurement_unit->value(s203_procurement_unit.c_str());
	txt_203_claims_unit->value(s203_claims_unit.c_str());
	txt_203_cost_unit->value(s203_cost_unit.c_str());

	for (int i = 0; i < 7; i++) {
		txt_203_agency[i]->value(s203_agency[i].c_str());
		txt_203_agency_name[i]->value(s203_agency_name[i].c_str());
	}
	for (int i = 0; i < 3; i++) {
		txt_203_tech_spc[i]->value(s203_tech_spc[i].c_str());
	}
	for (int i = 0; i < 5; i++) {
		txt_203_b1_div[i]->value(s203_b1_div[i].c_str());
		txt_203_b1_grp[i]->value(s203_b1_grp[i].c_str());
		txt_203_b2_div[i]->value(s203_b2_div[i].c_str());
		txt_203_b2_grp[i]->value(s203_b2_grp[i].c_str());
		txt_203_b3_div[i]->value(s203_b3_div[i].c_str());
		txt_203_b3_grp[i]->value(s203_b3_grp[i].c_str());
	}
}

void clear_203_form()
{
	clear_203fields();

	txt_203_incident->value("");
	txt_203_date->value("");
	txt_203_time->value("");
	txt_203_op_period->value("");
	txt_203_incident_commander->value("");
	txt_203_incident_deputy->value("");
	txt_203_incident_safety_officer->value("");
	txt_203_incident_info_officer->value("");
	txt_203_liaison_officer->value("");
	txt_203_prepared_by->value("");
	txt_203_planning_chief->value("");
	txt_203_planning_deputy->value("");
	txt_203_resources_unit->value("");
	txt_203_situation_unit->value("");
	txt_203_documentation_unit->value("");
	txt_203_demobilization_unit->value("");
	txt_203_logistics_chief->value("");
	txt_203_logistics_deputy->value("");
	txt_203_support_director->value("");
	txt_203_supply_unit->value("");
	txt_203_facilities_unit->value("");
	txt_203_ground_support->value("");
	txt_203_service_director->value("");
	txt_203_communications_unit->value("");
	txt_203_medical_unit->value("");
	txt_203_food_unit->value("");
	txt_203_ops_chief->value("");
	txt_203_ops_deputy->value("");
	txt_203_b1_director->value("");
	txt_203_b1_deputy->value("");
	txt_203_b2_director->value("");
	txt_203_b2_deputy->value("");
	txt_203_b3_director->value("");
	txt_203_b3_deputy->value("");
	txt_203_air_ops_br_dir->value("");
	txt_203_air_tactical_group_sup->value("");
	txt_203_air_support_group_sup->value("");
	txt_203_helicopter_coordinator->value("");
	txt_203_air_tanker_fixed_wing->value("");
	txt_203_finance_chief->value("");
	txt_203_finance_deputy->value("");
	txt_203_time_unit->value("");
	txt_203_procurement_unit->value("");
	txt_203_claims_unit->value("");
	txt_203_cost_unit->value("");

	for (int i = 0; i < 7; i++) {
		txt_203_agency[i]->value("");
		txt_203_agency_name[i]->value("");
	}
	for (int i = 0; i < 3; i++) {
		txt_203_tech_spc[i]->value("");
	}
	for (int i = 0; i < 5; i++) {
		txt_203_b1_div[i]->value("");
		txt_203_b1_grp[i]->value("");
		txt_203_b2_div[i]->value("");
		txt_203_b2_grp[i]->value("");
		txt_203_b3_div[i]->value("");
		txt_203_b3_grp[i]->value("");
	}
}

std::string &ics_n(std::string & subst, int n)
{
	static std::string garbage = "#$^*!";
	size_t pos = subst.find("[");
	if (pos == std::string::npos) return garbage;
	pos++;
	subst[pos] = '0' + n;
	return subst;
}

void make_buff203(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( ics203_incident, s203_incident ) );
	mbuff.append( lineout( ics203_date, s203_date ) );
	mbuff.append( lineout( ics203_time, s203_time ) );
	mbuff.append( lineout( ics203_op_period, s203_op_period ) );
	mbuff.append( lineout( ics203_incident_commander, s203_incident_commander ) );
	mbuff.append( lineout( ics203_incident_deputy, s203_incident_deputy ) );
	mbuff.append( lineout( ics203_incident_safety_officer, s203_incident_safety_officer ) );
	mbuff.append( lineout( ics203_incident_info_officer, s203_incident_info_officer ) );
	mbuff.append( lineout( ics203_liaison_officer, s203_liaison_officer ) );
	mbuff.append( lineout( ics203_prepared_by, s203_prepared_by ) );
	mbuff.append( lineout( ics203_planning_chief, s203_planning_chief ) );
	mbuff.append( lineout( ics203_planning_deputy, s203_planning_deputy ) );
	mbuff.append( lineout( ics203_resources_unit, s203_resources_unit ) );
	mbuff.append( lineout( ics203_situation_unit, s203_situation_unit ) );
	mbuff.append( lineout( ics203_documentation_unit, s203_documentation_unit ) );
	mbuff.append( lineout( ics203_demobilization_unit, s203_demobilization_unit ) );
	mbuff.append( lineout( ics203_logistics_chief, s203_logistics_chief ) );
	mbuff.append( lineout( ics203_logistics_deputy, s203_logistics_deputy ) );
	mbuff.append( lineout( ics203_support_director, s203_support_director ) );
	mbuff.append( lineout( ics203_supply_unit, s203_supply_unit ) );
	mbuff.append( lineout( ics203_facilities_unit, s203_facilities_unit ) );
	mbuff.append( lineout( ics203_ground_support, s203_ground_support ) );
	mbuff.append( lineout( ics203_service_director, s203_service_director ) );
	mbuff.append( lineout( ics203_communications_unit, s203_communications_unit ) );
	mbuff.append( lineout( ics203_medical_unit, s203_medical_unit ) );
	mbuff.append( lineout( ics203_food_unit, s203_food_unit ) );
	mbuff.append( lineout( ics203_ops_chief, s203_ops_chief ) );
	mbuff.append( lineout( ics203_ops_deputy, s203_ops_deputy ) );
	mbuff.append( lineout( ics203_b1_director, s203_b1_director ) );
	mbuff.append( lineout( ics203_b1_deputy, s203_b1_deputy ) );
	mbuff.append( lineout( ics203_b2_director, s203_b2_director ) );
	mbuff.append( lineout( ics203_b2_deputy, s203_b2_deputy ) );
	mbuff.append( lineout( ics203_b3_director, s203_b3_director ) );
	mbuff.append( lineout( ics203_b3_deputy, s203_b3_deputy ) );
	mbuff.append( lineout( ics203_air_ops_br_dir, s203_air_ops_br_dir ) );
	mbuff.append( lineout( ics203_air_tactical_group_sup, s203_air_tactical_group_sup ) );
	mbuff.append( lineout( ics203_air_support_group_sup, s203_air_support_group_sup ) );
	mbuff.append( lineout( ics203_helicopter_coordinator, s203_helicopter_coordinator ) );
	mbuff.append( lineout( ics203_air_tanker_fixed_wing, s203_air_tanker_fixed_wing ) );
	mbuff.append( lineout( ics203_finance_chief, s203_finance_chief ) );
	mbuff.append( lineout( ics203_finance_deputy, s203_finance_deputy ) );
	mbuff.append( lineout( ics203_time_unit, s203_time_unit ) );
	mbuff.append( lineout( ics203_procurement_unit, s203_procurement_unit ) );
	mbuff.append( lineout( ics203_claims_unit, s203_claims_unit ) );
	mbuff.append( lineout( ics203_cost_unit, s203_cost_unit ) );

	for (int i = 0; i < 7; i++) {
		mbuff.append( lineout( ics_n( ics203_agency, i ), s203_agency[i] ) );
		mbuff.append( lineout( ics_n( ics203_agency_name, i ), s203_agency_name[i] ) );
	}
	for (int i = 0; i < 3; i++) {
		mbuff.append( lineout( ics_n( ics203_tech_spc, i ), s203_tech_spc[i] ) );
	}
	for (int i = 0; i < 5; i++) {
		mbuff.append( lineout( ics_n( ics203_b1_div, i ), s203_b1_div[i] ) );
		mbuff.append( lineout( ics_n( ics203_b1_grp, i ), s203_b1_grp[i] ) );
		mbuff.append( lineout( ics_n( ics203_b2_div, i ), s203_b2_div[i] ) );
		mbuff.append( lineout( ics_n( ics203_b2_grp, i ), s203_b2_grp[i] ) );
		mbuff.append( lineout( ics_n( ics203_b3_div, i ), s203_b3_div[i] ) );
		mbuff.append( lineout( ics_n( ics203_b3_grp, i ), s203_b3_grp[i] ) );
	}
	if (compress) compress_maybe(mbuff);
	buff203.append(mbuff);
}

void read_203_buffer(std::string data)
{
	clear_203fields();
	read_header(data);

	s203_incident = findstr(data, ics203_incident);
	s203_date = findstr(data, ics203_date);
	s203_time = findstr(data, ics203_time);
	s203_op_period = findstr(data, ics203_op_period);
	s203_incident_commander = findstr(data, ics203_incident_commander);
	s203_incident_deputy = findstr(data, ics203_incident_deputy);
	s203_incident_safety_officer = findstr(data, ics203_incident_safety_officer);
	s203_incident_info_officer = findstr(data, ics203_incident_info_officer);
	s203_liaison_officer = findstr(data, ics203_liaison_officer);
	s203_prepared_by = findstr(data, ics203_prepared_by);
	s203_planning_chief = findstr(data, ics203_planning_chief);
	s203_planning_deputy = findstr(data, ics203_planning_deputy);
	s203_resources_unit = findstr(data, ics203_resources_unit);
	s203_situation_unit = findstr(data, ics203_situation_unit);
	s203_documentation_unit = findstr(data, ics203_documentation_unit);
	s203_demobilization_unit = findstr(data, ics203_demobilization_unit);
	s203_logistics_chief = findstr(data, ics203_logistics_chief);
	s203_logistics_deputy = findstr(data, ics203_logistics_deputy);
	s203_support_director = findstr(data, ics203_support_director);
	s203_supply_unit = findstr(data, ics203_supply_unit);
	s203_facilities_unit = findstr(data, ics203_facilities_unit);
	s203_ground_support = findstr(data, ics203_ground_support);
	s203_service_director = findstr(data, ics203_service_director);
	s203_communications_unit = findstr(data, ics203_communications_unit);
	s203_medical_unit = findstr(data, ics203_medical_unit);
	s203_food_unit = findstr(data, ics203_food_unit);
	s203_ops_chief = findstr(data, ics203_ops_chief);
	s203_ops_deputy = findstr(data, ics203_ops_deputy);
	s203_b1_director = findstr(data, ics203_b1_director);
	s203_b1_deputy = findstr(data, ics203_b1_deputy);
	s203_b2_director = findstr(data, ics203_b2_director);
	s203_b2_deputy = findstr(data, ics203_b2_deputy);
	s203_b3_director = findstr(data, ics203_b3_director);
	s203_b3_deputy = findstr(data, ics203_b3_deputy);
	s203_air_ops_br_dir = findstr(data, ics203_air_ops_br_dir);
	s203_air_tactical_group_sup = findstr(data, ics203_air_tactical_group_sup);
	s203_air_support_group_sup = findstr(data, ics203_air_support_group_sup);
	s203_helicopter_coordinator = findstr(data, ics203_helicopter_coordinator);
	s203_air_tanker_fixed_wing = findstr(data, ics203_air_tanker_fixed_wing);
	s203_finance_chief = findstr(data, ics203_finance_chief);
	s203_finance_deputy = findstr(data, ics203_finance_deputy);
	s203_time_unit = findstr(data, ics203_time_unit);
	s203_procurement_unit = findstr(data, ics203_procurement_unit);
	s203_claims_unit = findstr(data, ics203_claims_unit);
	s203_cost_unit = findstr(data, ics203_cost_unit);

	for (int i = 0; i < 7; i++) {
		s203_agency[i] = findstr(data, ics_n( ics203_agency, i) );
		s203_agency_name[i] = findstr(data, ics_n( ics203_agency_name, i) );
	}
	for (int i = 0; i < 3; i++) {
		s203_tech_spc[i] = findstr(data, ics_n( ics203_tech_spc, i) );
	}
	for (int i = 0; i < 5; i++) {
		s203_b1_div[i] = findstr(data, ics_n( ics203_b1_div, i) );
		s203_b1_grp[i] = findstr(data, ics_n( ics203_b1_grp, i) );
		s203_b2_div[i] = findstr(data, ics_n( ics203_b2_div, i) );
		s203_b2_grp[i] = findstr(data, ics_n( ics203_b2_grp, i) );
		s203_b3_div[i] = findstr(data, ics_n( ics203_b3_div, i) );
		s203_b3_grp[i] = findstr(data, ics_n( ics203_b3_grp, i) );
	}
	update_203form();
}

void cb_203_new()
{
	if (check_203fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_203_save();
		}
	}
	clear_203_form();
	clear_header();
	def_203_filename = ICS_msg_dir;
	def_203_filename.append("new").append(F203_EXT);
	show_filename(def_203_filename);
	using_ics203_template = false;
}

void cb_203_import()
{
	fl_alert2("Not implemented");
}

void cb_203_export()
{
	fl_alert2("Not implemented");
}

void cb_203_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_203_form();
	read_203_buffer(inpbuffer);
	def_203_filename = ICS_msg_dir;
	def_203_filename.append(wrapfilename);
	show_filename(def_203_filename);
	using_ics203_template = false;
}

int eval_203_fsize()
{
	Ccrc16 chksum;
	evalstr.append("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_203_filename).append("]");
	update_203fields();
	update_header(FROM);
	evalstr.append(header("<ics203>"));
	buff203.clear();
	make_buff203(true);
	if (buff203.empty()) return 0;
	compress_maybe( buff203 );
	evalstr.append( buff203 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_203_wrap_export()
{
	if (check_203fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_203fields();

	if (base_203_filename == std::string("new").append(F203_EXT) ||
		base_203_filename == std::string("default").append(F203_EXT) )
		if (!cb_203_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_203_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff203.assign(header("<ics203>"));
		make_buff203(true);
		export_wrapfile(base_203_filename, wrapfilename, buff203, pext != ".wrap");

		buff203.assign(header("<ics203>"));
		make_buff203(true);
		write_203(def_203_filename);
	}
}

void cb_203_wrap_autosend()
{
	if (check_203fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_203fields();

	if (base_203_filename == std::string("new").append(F203_EXT) ||
		base_203_filename == std::string("default").append(F203_EXT) )
		if (!cb_203_save_as()) return;

	update_header(FROM);
	buff203.assign(header("<ics203>"));
	make_buff203(true);
	xfr_via_socket(base_203_filename, buff203);

	buff203.assign(header("<ics203>"));
	make_buff203(true);
	write_203(def_203_filename);
}

void cb_203_load_template()
{
	std::string def_203_filename = def_203_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(T203_EXT).c_str(),
			def_203_filename.c_str());
	if (p) {
		clear_203_form();
		read_data_file(p);
		def_203_TemplateName = p;
		show_filename(def_203_TemplateName);
		using_ics203_template = true;
	}
}

void cb_203_save_template()
{
	if (!using_ics203_template) {
		cb_203_save_as_template();
		return;
	}
	std::string def_203_filename = def_203_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(T203_EXT).c_str(),
			def_203_filename.c_str());
	if (p) {
		update_header(CHANGED);
		buff203.assign(header("<ics203>"));
		make_buff203();
		write_203(p);
	}
}

void cb_203_save_as_template()
{
	std::string def_203_filename = def_203_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(T203_EXT).c_str(),
			def_203_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_203_TemplateName = p;
		if (strlen(pext) == 0) def_203_TemplateName.append(T203_EXT);
		remove_spaces_from_filename(def_203_TemplateName);
		clear_header();
		update_header(CHANGED);
		buff203.assign(header("<ics203>"));
		make_buff203();
		write_203(def_203_TemplateName);
		show_filename(def_203_TemplateName);
		using_ics203_template = true;
	}
}

void cb_203_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-203\t*").append(F203_EXT).c_str(),
			def_203_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_203_form();
	read_data_file(p);
	using_ics203_template = false;
	def_203_filename = p;
	show_filename(def_203_filename);
}

void write_203(std::string s)
{
	FILE *file203 = fopen(s.c_str(), "w");
	if (!file203) return;

	fwrite(buff203.c_str(), buff203.length(), 1, file203);
	fclose(file203);
}

bool cb_203_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(F203_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_203_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-203\t*").append(F203_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_203_filename = p;
	if (strlen(pext) == 0) def_203_filename.append(F203_EXT);

	remove_spaces_from_filename(def_203_filename);
	update_203fields();
	update_header(NEW);
	buff203.assign(header("<ics203>"));
	make_buff203();
	write_203(def_203_filename);

	using_ics203_template = false;
	show_filename(def_203_filename);
	return true;
}

void cb_203_save()
{
	if (base_203_filename == std::string("new").append(F203_EXT) || 
		base_203_filename == std::string("default").append(F203_EXT) ||
		using_ics203_template == true) {
		cb_203_save_as();
		return;
	}
	if (check_203fields()) update_header(CHANGED);
	update_203fields();
	buff203.assign(header("<ics203>"));
	make_buff203();
	write_203(def_203_filename);
	using_ics203_template = false;
}

void cb_203_html()
{
	std::string fname_name = fl_filename_name(def_203_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string ics203_fname = ICS_dir;
	ics203_fname.append(fname_name);
	ics203_fname.append(".html");

	std::string html_text = "";

	update_203fields();
	std::string form203 = ics203_html_template;
	replacestr(form203, TITLE, fname_name);

	replacestr(form203, ics203_incident, s203_incident );
	replacestr(form203, ics203_date, s203_date );
	replacestr(form203, ics203_time, s203_time );
	replacestr(form203, ics203_op_period, s203_op_period );
	replacestr(form203, ics203_incident_commander, s203_incident_commander );
	replacestr(form203, ics203_incident_deputy, s203_incident_deputy );
	replacestr(form203, ics203_incident_safety_officer, s203_incident_safety_officer );
	replacestr(form203, ics203_incident_info_officer, s203_incident_info_officer );
	replacestr(form203, ics203_liaison_officer, s203_liaison_officer );
	replacestr(form203, ics203_prepared_by, s203_prepared_by );
	replacestr(form203, ics203_planning_chief, s203_planning_chief );
	replacestr(form203, ics203_planning_deputy, s203_planning_deputy );
	replacestr(form203, ics203_resources_unit, s203_resources_unit );
	replacestr(form203, ics203_situation_unit, s203_situation_unit );
	replacestr(form203, ics203_documentation_unit, s203_documentation_unit );
	replacestr(form203, ics203_demobilization_unit, s203_demobilization_unit );
	replacestr(form203, ics203_logistics_chief, s203_logistics_chief );
	replacestr(form203, ics203_logistics_deputy, s203_logistics_deputy );
	replacestr(form203, ics203_support_director, s203_support_director );
	replacestr(form203, ics203_supply_unit, s203_supply_unit );
	replacestr(form203, ics203_facilities_unit, s203_facilities_unit );
	replacestr(form203, ics203_ground_support, s203_ground_support );
	replacestr(form203, ics203_service_director, s203_service_director );
	replacestr(form203, ics203_communications_unit, s203_communications_unit );
	replacestr(form203, ics203_medical_unit, s203_medical_unit );
	replacestr(form203, ics203_food_unit, s203_food_unit );
	replacestr(form203, ics203_ops_chief, s203_ops_chief );
	replacestr(form203, ics203_ops_deputy, s203_ops_deputy );
	replacestr(form203, ics203_b1_director, s203_b1_director );
	replacestr(form203, ics203_b1_deputy, s203_b1_deputy );
	replacestr(form203, ics203_b2_director, s203_b2_director );
	replacestr(form203, ics203_b2_deputy, s203_b2_deputy );
	replacestr(form203, ics203_b3_director, s203_b3_director );
	replacestr(form203, ics203_b3_deputy, s203_b3_deputy );
	replacestr(form203, ics203_air_ops_br_dir, s203_air_ops_br_dir );
	replacestr(form203, ics203_air_tactical_group_sup, s203_air_tactical_group_sup );
	replacestr(form203, ics203_air_support_group_sup, s203_air_support_group_sup );
	replacestr(form203, ics203_helicopter_coordinator, s203_helicopter_coordinator );
	replacestr(form203, ics203_air_tanker_fixed_wing, s203_air_tanker_fixed_wing );
	replacestr(form203, ics203_finance_chief, s203_finance_chief );
	replacestr(form203, ics203_finance_deputy, s203_finance_deputy );
	replacestr(form203, ics203_time_unit, s203_time_unit );
	replacestr(form203, ics203_procurement_unit, s203_procurement_unit );
	replacestr(form203, ics203_claims_unit, s203_claims_unit );
	replacestr(form203, ics203_cost_unit, s203_cost_unit );

	for (int i = 0; i < 7; i++) {
		replacestr(form203, ics_n( ics203_agency, i ), s203_agency[i] );
		replacestr(form203, ics_n( ics203_agency_name, i ), s203_agency_name[i] );
	}
	for (int i = 0; i < 3; i++) {
		replacestr(form203, ics_n( ics203_tech_spc, i ), s203_tech_spc[i] );
	}
	for (int i = 0; i < 5; i++) {
		replacestr(form203, ics_n( ics203_b1_div, i ), s203_b1_div[i] );
		replacestr(form203, ics_n( ics203_b1_grp, i ), s203_b1_grp[i] );
		replacestr(form203, ics_n( ics203_b2_div, i ), s203_b2_div[i] );
		replacestr(form203, ics_n( ics203_b2_grp, i ), s203_b2_grp[i] );
		replacestr(form203, ics_n( ics203_b3_div, i ), s203_b3_div[i] );
		replacestr(form203, ics_n( ics203_b3_grp, i ), s203_b3_grp[i] );
	}

	FILE *file203 = fopen(ics203_fname.c_str(), "w");
	fprintf(file203,"%s", form203.c_str());
	fclose(file203);

	open_url(ics203_fname.c_str());
}

void cb_203_msg_type()
{
	if (tabs_msg_type->value() == tab_ics203 ) {
		tab_ics203_type->value(tab_203_1);
		show_filename(def_203_filename);
	}
}

void cb_203_textout()
{
	std::string ics203_fname = ICS_dir;
	ics203_fname.append("ics203.txt");

	update_203fields();
	std::string form203 = ics203_text_template;

	replacestr(form203, ics203_incident, s203_incident );
	replacestr(form203, ics203_date, s203_date );
	replacestr(form203, ics203_time, s203_time );
	replacestr(form203, ics203_op_period, s203_op_period );
	replacestr(form203, ics203_incident_commander, s203_incident_commander );
	replacestr(form203, ics203_incident_deputy, s203_incident_deputy );
	replacestr(form203, ics203_incident_safety_officer, s203_incident_safety_officer );
	replacestr(form203, ics203_incident_info_officer, s203_incident_info_officer );
	replacestr(form203, ics203_liaison_officer, s203_liaison_officer );
	replacestr(form203, ics203_prepared_by, s203_prepared_by );
	replacestr(form203, ics203_planning_chief, s203_planning_chief );
	replacestr(form203, ics203_planning_deputy, s203_planning_deputy );
	replacestr(form203, ics203_resources_unit, s203_resources_unit );
	replacestr(form203, ics203_situation_unit, s203_situation_unit );
	replacestr(form203, ics203_documentation_unit, s203_documentation_unit );
	replacestr(form203, ics203_demobilization_unit, s203_demobilization_unit );
	replacestr(form203, ics203_logistics_chief, s203_logistics_chief );
	replacestr(form203, ics203_logistics_deputy, s203_logistics_deputy );
	replacestr(form203, ics203_support_director, s203_support_director );
	replacestr(form203, ics203_supply_unit, s203_supply_unit );
	replacestr(form203, ics203_facilities_unit, s203_facilities_unit );
	replacestr(form203, ics203_ground_support, s203_ground_support );
	replacestr(form203, ics203_service_director, s203_service_director );
	replacestr(form203, ics203_communications_unit, s203_communications_unit );
	replacestr(form203, ics203_medical_unit, s203_medical_unit );
	replacestr(form203, ics203_food_unit, s203_food_unit );
	replacestr(form203, ics203_ops_chief, s203_ops_chief );
	replacestr(form203, ics203_ops_deputy, s203_ops_deputy );
	replacestr(form203, ics203_b1_director, s203_b1_director );
	replacestr(form203, ics203_b1_deputy, s203_b1_deputy );
	replacestr(form203, ics203_b2_director, s203_b2_director );
	replacestr(form203, ics203_b2_deputy, s203_b2_deputy );
	replacestr(form203, ics203_b3_director, s203_b3_director );
	replacestr(form203, ics203_b3_deputy, s203_b3_deputy );
	replacestr(form203, ics203_air_ops_br_dir, s203_air_ops_br_dir );
	replacestr(form203, ics203_air_tactical_group_sup, s203_air_tactical_group_sup );
	replacestr(form203, ics203_air_support_group_sup, s203_air_support_group_sup );
	replacestr(form203, ics203_helicopter_coordinator, s203_helicopter_coordinator );
	replacestr(form203, ics203_air_tanker_fixed_wing, s203_air_tanker_fixed_wing );
	replacestr(form203, ics203_finance_chief, s203_finance_chief );
	replacestr(form203, ics203_finance_deputy, s203_finance_deputy );
	replacestr(form203, ics203_time_unit, s203_time_unit );
	replacestr(form203, ics203_procurement_unit, s203_procurement_unit );
	replacestr(form203, ics203_claims_unit, s203_claims_unit );
	replacestr(form203, ics203_cost_unit, s203_cost_unit );

	for (int i = 0; i < 7; i++) {
		replacestr(form203, ics_n( ics203_agency, i ), s203_agency[i] );
		replacestr(form203, ics_n( ics203_agency_name, i ), s203_agency_name[i] );
	}
	for (int i = 0; i < 3; i++) {
		replacestr(form203, ics_n( ics203_tech_spc, i ), s203_tech_spc[i] );
	}
	for (int i = 0; i < 5; i++) {
		replacestr(form203, ics_n( ics203_b1_div, i ), s203_b1_div[i] );
		replacestr(form203, ics_n( ics203_b1_grp, i ), s203_b1_grp[i] );
		replacestr(form203, ics_n( ics203_b2_div, i ), s203_b2_div[i] );
		replacestr(form203, ics_n( ics203_b2_grp, i ), s203_b2_grp[i] );
		replacestr(form203, ics_n( ics203_b3_div, i ), s203_b3_div[i] );
		replacestr(form203, ics_n( ics203_b3_grp, i ), s203_b3_grp[i] );
	}

	FILE *file203 = fopen(ics203_fname.c_str(), "w");
	fprintf(file203,"%s", form203.c_str());
	fclose(file203);

	open_url(ics203_fname.c_str());
}
