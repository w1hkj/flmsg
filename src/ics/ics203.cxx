// =====================================================================
//
// ics203.cxx
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
// ics 203 field variables and template variables
// ---------------------------------------------------------------------

string ics203_incident					= ":inc:";
string ics203_date						= ":dat:";
string ics203_time						= ":tim:";
string ics203_op_period					= ":opp:";
string ics203_incident_commander		= ":icc:";
string ics203_incident_deputy			= ":icd:";
string ics203_incident_safety_officer	= ":ics:";
string ics203_incident_info_officer		= ":ici:";
string ics203_liaison_officer			= ":icl:";
string ics203_prepared_by				= ":pre:";
string ics203_agency					= ":agency[n]:"; // 7
string ics203_agency_name				= ":agency_name[n]:"; // 7
string ics203_planning_chief			= ":planning_chief:";
string ics203_planning_deputy			= ":planning_deputy:";
string ics203_resources_unit			= ":resources_unit:";
string ics203_situation_unit			= ":situation_unit:";
string ics203_documentation_unit		= ":documentation_unit:";
string ics203_demobilization_unit		= ":demobilization_unit:";
string ics203_tech_spc					= ":tech_spc[n]:"; // 3
string ics203_logistics_chief			= ":logistics_chief:";
string ics203_logistics_deputy			= ":logistics_deputy:";
string ics203_support_director			= ":support_director:";
string ics203_supply_unit				= ":supply_unit:";
string ics203_facilities_unit			= ":facilities_unit:";
string ics203_ground_support			= ":ground_support:";
string ics203_service_director			= ":service_director:";
string ics203_communications_unit		= ":communications_unit:";
string ics203_medical_unit				= ":medical_unit:";
string ics203_food_unit					= ":food_unit:";
string ics203_ops_chief					= ":ops_chief:";
string ics203_ops_deputy				= ":ops_deputy:";
string ics203_b1_director				= ":b1_director:";
string ics203_b1_deputy					= ":b1_deputy:";
string ics203_b1_div					= ":b1_div[n]:"; // 4
string ics203_b1_grp					= ":b1_grp[n]:"; // 4
string ics203_b2_director				= ":b2_director:";
string ics203_b2_deputy					= ":b2_deputy:";
string ics203_b2_div					= ":b2_div[n]:"; // 4
string ics203_b2_grp					= ":b2_grp[n]:"; // 4
string ics203_b3_director				= ":b3_director:";
string ics203_b3_deputy					= ":b3_deputy:";
string ics203_b3_div					= ":b3_div[n]:"; // 4
string ics203_b3_grp					= ":b3_grp[n]:"; // 4
string ics203_air_ops_br_dir			= ":air_ops_br_dir:";
string ics203_air_tactical_group_sup	= ":air_tactical_group_sup:";
string ics203_air_support_group_sup		= ":air_support_group_sup:";
string ics203_helicopter_coordinator	= ":helicopter_coordinator:";
string ics203_air_tanker_fixed_wing		= ":air_tanker_fixed_wing:";
string ics203_finance_chief				= ":finance_chief:";
string ics203_finance_deputy			= ":finance_deputy:";
string ics203_time_unit					= ":time_unit:";
string ics203_procurement_unit			= ":procurement_unit:";
string ics203_claims_unit				= ":claims_unit:";
string ics203_cost_unit					= ":cost_unit:";

string s203_incident;
string s203_date;
string s203_time;
string s203_op_period;
string s203_incident_commander;
string s203_incident_deputy;
string s203_incident_safety_officer;
string s203_incident_info_officer;
string s203_liaison_officer;
string s203_prepared_by;
string s203_agency[7];
string s203_agency_name[7];
string s203_planning_chief;
string s203_planning_deputy;
string s203_resources_unit;
string s203_situation_unit;
string s203_documentation_unit;
string s203_demobilization_unit;
string s203_tech_spc[3];
string s203_logistics_chief;
string s203_logistics_deputy;
string s203_support_director;
string s203_supply_unit;
string s203_facilities_unit;
string s203_ground_support;
string s203_service_director;
string s203_communications_unit;
string s203_medical_unit;
string s203_food_unit;
string s203_ops_chief;
string s203_ops_deputy;
string s203_b1_director;
string s203_b1_deputy;
string s203_b1_div[5];
string s203_b1_grp[5];
string s203_b2_director;
string s203_b2_deputy;
string s203_b2_div[5];
string s203_b2_grp[5];
string s203_b3_director;
string s203_b3_deputy;
string s203_b3_div[5];
string s203_b3_grp[5];
string s203_air_ops_br_dir;
string s203_air_tactical_group_sup;
string s203_air_support_group_sup;
string s203_helicopter_coordinator;
string s203_air_tanker_fixed_wing;
string s203_finance_chief;
string s203_finance_deputy;
string s203_time_unit;
string s203_procurement_unit;
string s203_claims_unit;
string s203_cost_unit;

// =====================================================================

string buff203;
string def_203_filename = "";
string base_203_filename = "";
string def_203_TemplateName = "";
bool using_ics203_template = false;

void cb_203_set_date()
{
	txt_203_date->value(szDate());
}

void cb_203_set_time()
{
	txt_203_time->value(szTime());
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

string &ics_n(string & subst, int n)
{
	static string garbage = "#$^*!";
	size_t pos = subst.find("[");
	if (pos == string::npos) return garbage;
	pos++;
	subst[pos] = '0' + n;
	return subst;
}

void make_buff203()
{
	update_203fields();
	buff203.clear();

	buff203 = header("<ics203>");

	buff203.append( lineout( ics203_incident, s203_incident ) );
	buff203.append( lineout( ics203_date, s203_date ) );
	buff203.append( lineout( ics203_time, s203_time ) );
	buff203.append( lineout( ics203_op_period, s203_op_period ) );
	buff203.append( lineout( ics203_incident_commander, s203_incident_commander ) );
	buff203.append( lineout( ics203_incident_deputy, s203_incident_deputy ) );
	buff203.append( lineout( ics203_incident_safety_officer, s203_incident_safety_officer ) );
	buff203.append( lineout( ics203_incident_info_officer, s203_incident_info_officer ) );
	buff203.append( lineout( ics203_liaison_officer, s203_liaison_officer ) );
	buff203.append( lineout( ics203_prepared_by, s203_prepared_by ) );
	buff203.append( lineout( ics203_planning_chief, s203_planning_chief ) );
	buff203.append( lineout( ics203_planning_deputy, s203_planning_deputy ) );
	buff203.append( lineout( ics203_resources_unit, s203_resources_unit ) );
	buff203.append( lineout( ics203_situation_unit, s203_situation_unit ) );
	buff203.append( lineout( ics203_documentation_unit, s203_documentation_unit ) );
	buff203.append( lineout( ics203_demobilization_unit, s203_demobilization_unit ) );
	buff203.append( lineout( ics203_logistics_chief, s203_logistics_chief ) );
	buff203.append( lineout( ics203_logistics_deputy, s203_logistics_deputy ) );
	buff203.append( lineout( ics203_support_director, s203_support_director ) );
	buff203.append( lineout( ics203_supply_unit, s203_supply_unit ) );
	buff203.append( lineout( ics203_facilities_unit, s203_facilities_unit ) );
	buff203.append( lineout( ics203_ground_support, s203_ground_support ) );
	buff203.append( lineout( ics203_service_director, s203_service_director ) );
	buff203.append( lineout( ics203_communications_unit, s203_communications_unit ) );
	buff203.append( lineout( ics203_medical_unit, s203_medical_unit ) );
	buff203.append( lineout( ics203_food_unit, s203_food_unit ) );
	buff203.append( lineout( ics203_ops_chief, s203_ops_chief ) );
	buff203.append( lineout( ics203_ops_deputy, s203_ops_deputy ) );
	buff203.append( lineout( ics203_b1_director, s203_b1_director ) );
	buff203.append( lineout( ics203_b1_deputy, s203_b1_deputy ) );
	buff203.append( lineout( ics203_b2_director, s203_b2_director ) );
	buff203.append( lineout( ics203_b2_deputy, s203_b2_deputy ) );
	buff203.append( lineout( ics203_b3_director, s203_b3_director ) );
	buff203.append( lineout( ics203_b3_deputy, s203_b3_deputy ) );
	buff203.append( lineout( ics203_air_ops_br_dir, s203_air_ops_br_dir ) );
	buff203.append( lineout( ics203_air_tactical_group_sup, s203_air_tactical_group_sup ) );
	buff203.append( lineout( ics203_air_support_group_sup, s203_air_support_group_sup ) );
	buff203.append( lineout( ics203_helicopter_coordinator, s203_helicopter_coordinator ) );
	buff203.append( lineout( ics203_air_tanker_fixed_wing, s203_air_tanker_fixed_wing ) );
	buff203.append( lineout( ics203_finance_chief, s203_finance_chief ) );
	buff203.append( lineout( ics203_finance_deputy, s203_finance_deputy ) );
	buff203.append( lineout( ics203_time_unit, s203_time_unit ) );
	buff203.append( lineout( ics203_procurement_unit, s203_procurement_unit ) );
	buff203.append( lineout( ics203_claims_unit, s203_claims_unit ) );
	buff203.append( lineout( ics203_cost_unit, s203_cost_unit ) );

	for (int i = 0; i < 7; i++) {
		buff203.append( lineout( ics_n( ics203_agency, i ), s203_agency[i] ) );
		buff203.append( lineout( ics_n( ics203_agency_name, i ), s203_agency_name[i] ) );
	}
	for (int i = 0; i < 3; i++) {
		buff203.append( lineout( ics_n( ics203_tech_spc, i ), s203_tech_spc[i] ) );
	}
	for (int i = 0; i < 5; i++) {
		buff203.append( lineout( ics_n( ics203_b1_div, i ), s203_b1_div[i] ) );
		buff203.append( lineout( ics_n( ics203_b1_grp, i ), s203_b1_grp[i] ) );
		buff203.append( lineout( ics_n( ics203_b2_div, i ), s203_b2_div[i] ) );
		buff203.append( lineout( ics_n( ics203_b2_grp, i ), s203_b2_grp[i] ) );
		buff203.append( lineout( ics_n( ics203_b3_div, i ), s203_b3_div[i] ) );
		buff203.append( lineout( ics_n( ics203_b3_grp, i ), s203_b3_grp[i] ) );
	}
}

void read_203_buffer(string data)
{
	clear_203fields();

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
	clear_203_form();
	def_203_filename = ICS_msg_dir;
	def_203_filename.append("new"F203_EXT);
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

void cb_203_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_203_form();
	read_203_buffer(inpbuffer);
	def_203_filename = ICS_msg_dir;
	def_203_filename.append(wrapfilename);
	show_filename(def_203_filename);
	using_ics203_template = false;
}

void cb_203_wrap_export()
{
	if (base_203_filename == "new"F203_EXT || base_203_filename == "default"F203_EXT)
		cb_203_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_203_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_buff203();
		export_wrapfile(base_203_filename, wrapfilename, buff203, pext != ".wrap");
	}
}

void cb_203_wrap_autosend()
{
	if (base_203_filename == "new"F203_EXT || 
		base_203_filename == "default"F203_EXT ||
		using_ics203_template == true)
		cb_203_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buff203();
	export_wrapfile(base_203_filename, wrapfilename, buff203, false);
}

void cb_203_load_template()
{
	string def_203_filename = def_203_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"T203_EXT,
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
	string def_203_filename = def_203_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"T203_EXT,
			def_203_filename.c_str());
	if (p)
		write_203(p);
}

void cb_203_save_as_template()
{
	string def_203_filename = def_203_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"T203_EXT,
			def_203_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_203_TemplateName = p;
		if (strlen(pext) == 0) def_203_TemplateName.append(T203_EXT);
		remove_spaces_from_filename(def_203_TemplateName);
		write_203(def_203_TemplateName);
		show_filename(def_203_TemplateName);
		using_ics203_template = true;
	}
}

void cb_203_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-203\t*"F203_EXT,
					def_203_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_203_form();
	read_data_file(p);
	using_ics203_template = false;
	def_203_filename = p;
	show_filename(def_203_filename);
}

void write_203(string s)
{
	FILE *file203 = fopen(s.c_str(), "w");
	if (!file203) return;
	make_buff203();
	fwrite(buff203.c_str(), buff203.length(), 1, file203);
	fclose(file203);
}

void cb_203_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(F203_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_203_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-203\t*"F203_EXT,
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
	def_203_filename = p;
	if (strlen(pext) == 0) def_203_filename.append(F203_EXT);

	remove_spaces_from_filename(def_203_filename);
	write_203(def_203_filename);

	using_ics203_template = false;
	show_filename(def_203_filename);
}

void cb_203_save()
{
	if (base_203_filename == "new"F203_EXT || 
		base_203_filename == "default"F203_EXT ||
		using_ics203_template == true) {
		cb_203_save_as();
		return;
	}
	write_203(def_203_filename);
	using_ics203_template = false;
}

void cb_203_html()
{
	string fname_name = fl_filename_name(def_203_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string ics203_fname = ICS_dir;
	ics203_fname.append(fname_name);
	ics203_fname.append(".html");

	string html_text = "";

	update_203fields();
	string form203 = ics203_html_template;
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
	string ics203_fname = ICS_dir;
	ics203_fname.append("ics203.txt");

	update_203fields();
	string form203 = ics203_text_template;

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
