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

#include "templates.h"

const char ics203_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html><head>\
<meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr>\
<td colspan=3 VALIGN=middle><big><b></b>ORGANIZATION ASSIGNMENT LIST</b></big></td>\
<td COLSPAN=2 VALIGN=top><b>1. Incident name</b><br>:inc:<br></td>\
<td VALIGN=top><b>2.Date Prepared</b><br>:dat:<br></td>\
<td VALIGN=top><b>3.Time Prepared</b><br>:tim:<br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><br><br>\
<hr WIDTH=100% HEIGHT=2px><b>5. Incident Command and Staff</b><br></td>\
<td COLSPAN=3 VALIGN=top>\
  <b>4. Operational Period (Date/Time)</b><br>:opp:<br>\
  <hr WIDTH=100%; HEIGHT=2px><b>9. Operations section</b><br>\
</td>\
</tr>\
<tr>\
<td VALIGN=top>Incident Commander<br></td>\
<td COLSPAN=3 VALIGN=top>:icc:<br></td>\
<td VALIGN=top>Chief<br></td>\
<td COLSPAN=2 VALIGN=top>:ops_chief:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Deputy<br></td>\
<td COLSPAN=3 VALIGN=top>:icd:<br></td>\
<td VALIGN=top>Deputy<br></td>\
<td COLSPAN=2 VALIGN=top>:ops_deputy:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Safety Officer<br></td>\
<td COLSPAN=3 VALIGN=top>:ics:<br></td>\
<td COLSPAN=3 VALIGN=top><b>a. Branch I - Division / Groups</b><br></td>\
</tr>\
<tr>\
<td VALIGN=top>Information Officer<br></td>\
<td COLSPAN=3 VALIGN=top>:ici:<br></td>\
<td VALIGN=top>Branch Director<br></td>\
<td COLSPAN=2 VALIGN=top>:b1_director:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Liaison Officer<br></td>\
<td COLSPAN=3 VALIGN=top>:icl:<br></td>\
<td VALIGN=top>Deputy<br></td>\
<td COLSPAN=2 VALIGN=top>:b1_deputy:<br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><b>6. Agency Representative</b><br></td>\
<td COLSPAN=3 VALIGN=top>Division / Group<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Agency<br></td>\
<td COLSPAN=3 VALIGN=top>Name<br></td>\
<td VALIGN=top>:b1_div[0]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b1_grp[0]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:agency[0]:<br></td>\
<td COLSPAN=3 VALIGN=top>:agency_name[0]:<br></td>\
<td VALIGN=top>:b1_div[1]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b1_grp[1]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:agency[1]:<br></td>\
<td COLSPAN=3 VALIGN=top>:agency_name[1]:<br></td>\
<td VALIGN=top>:b1_div[2]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b1_grp[2]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:agency[2]:<br></td>\
<td COLSPAN=3 VALIGN=top>:agency_name[2]:<br></td>\
<td VALIGN=top>:b1_div[3]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b1_grp[3]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:agency[3]:<br></td>\
<td COLSPAN=3 VALIGN=top>:agency_name[3]:<br></td>\
<td COLSPAN=3 VALIGN=top><b>b. Branch II - Division / Groups</b><br></td>\
</tr>\
<tr>\
<td VALIGN=top>:agency[4]:<br></td>\
<td COLSPAN=3 VALIGN=top>:agency_name[4]:<br></td>\
<td VALIGN=top>Chief<br></td>\
<td COLSPAN=2 VALIGN=top>:b2_director:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:agency[5]:<br>\
</td>\
<td COLSPAN=3 VALIGN=top>:agency_name[5]:<br>\
</td>\
<td VALIGN=top>Deputy<br>\
</td>\
<td COLSPAN=2 VALIGN=top>:b2_deputy:<br>\
</td>\
</tr>\
<tr>\
<td VALIGN=top>:agency[6]:<br>\
</td>\
<td COLSPAN=3 VALIGN=top>:agency_name[6]:</td>\
<td COLSPAN=3 VALIGN=top>Division / Group<br>\
</td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><b>7. Planning Section</b><br></td>\
<td VALIGN=top>:b2_div[0]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b2_grp[0]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Chief<br></td>\
<td COLSPAN=3 VALIGN=top>:planning_chief:<br></td>\
<td VALIGN=top>:b2_div[1]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b2_grp[1]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Deputy<br></td>\
<td COLSPAN=3 VALIGN=top>:planning_deputy:<br></td>\
<td VALIGN=top>:b2_div[2]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b2_grp[2]: <br></td>\
</tr>\
<tr>\
<td VALIGN=top>Resources Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:resources_unit:<br></td>\
<td VALIGN=top>:b2_div[3]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b2_grp[3]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Situation Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:situation_unit:<br></td>\
<td COLSPAN=3 VALIGN=top><b>c. Branch III - Division / Groups</b><br></td>\
</tr>\
<tr>\
<td VALIGN=top>Documentation Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:documentation_unit:<br></td>\
<td VALIGN=top>Chief<br></td>\
<td COLSPAN=2 VALIGN=top>:b3_director:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Demobilization Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:demobilization_unit:<br></td>\
<td VALIGN=top>Deputy<br></td>\
<td COLSPAN=2 VALIGN=top>:b3_deputy:<br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top>Technical Specialists<br></td>\
<td COLSPAN=3 VALIGN=top>Division / Group<br></td>\
</tr>\
<tr>\
<td COLSPAN=2 VALIGN=top>Specialist</td>\
<td COLSPAN=2 VALIGN=top>:tech_spc[0]:</td>\
<td VALIGN=top>:b3_div[0]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b3_grp[0]:<br></td>\
</tr>\
<tr>\
<td COLSPAN=2 VALIGN=top>Specialist</td>\
<td COLSPAN=2 VALIGN=top>:tech_spc[1]: </td>\
<td VALIGN=top>:b3_div[1]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b3_grp[1]:<br></td>\
</tr>\
<tr>\
<td COLSPAN=2 VALIGN=top>Specialist</td>\
<td COLSPAN=2 VALIGN=top>:tech_spc[2]: </td>\
<td VALIGN=top>:b3_div[2]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b3_grp[2]:<br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><b>8. Logistics Section</b><br></td>\
<td VALIGN=top>:b3_div[3]:<br></td>\
<td COLSPAN=2 VALIGN=top>:b3_grp[3]:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Chief<br></td>\
<td COLSPAN=3 VALIGN=top>:logistics_chief:<br></td>\
<td COLSPAN=3 VALIGN=top><b>d. Air Operations Branch</b><br></td>\
</tr>\
<tr>\
<td VALIGN=top>Deputy<br></td>\
<td COLSPAN=3 VALIGN=top>:logistics_deputy:<br></td>\
<td VALIGN=top>Air Operations Br. Dir.<br></td>\
<td COLSPAN=2 VALIGN=top>:air_ops_br_dir:<br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><b>a. Support Branch</b><br></td>\
<td VALIGN=top>Air Tactical Group Sup.<br></td>\
<td COLSPAN=2 VALIGN=top>:air_tactical_group_sup:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Director<br></td>\
<td COLSPAN=3 VALIGN=top>:support_director:<br></td>\
<td VALIGN=top>Air Support Group Sup.<br></td>\
<td COLSPAN=2 VALIGN=top>:air_support_group_sup:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Supply Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:supply_unit:<br></td>\
<td VALIGN=top>Helicopter Coordinator<br></td>\
<td COLSPAN=2 VALIGN=top>:helicopter_coordinator:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Facilities Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:facilities_unit:<br></td>\
<td VALIGN=top>Air Tanker / Fixed Wing Crd.<br></td>\
<td COLSPAN=2 VALIGN=top>:air_tanker_fixed_wing:<br>\
</td>\
</tr>\
<tr>\
<td VALIGN=top>Ground Support Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:ground_support:<br></td>\
<td COLSPAN=3 VALIGN=top><br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><b>b. Service Branch</b><br></td>\
<td COLSPAN=3 VALIGN=top><b>10. Finance / Administration Section</b><br></td>\
</tr>\
<tr>\
<td VALIGN=top>Director<br>\
</td>\
<td COLSPAN=3 VALIGN=top>:service_director:<br></td>\
<td VALIGN=top>Chief<br></td>\
<td COLSPAN=2 VALIGN=top>:finance_chief:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Communications Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:communications_unit:<br></td>\
<td VALIGN=top>Deputy<br></td>\
<td COLSPAN=2 VALIGN=top>:finance_deputy:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Medical Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:medical_unit:<br></td>\
<td VALIGN=top>Time Unit<br></td>\
<td COLSPAN=2 VALIGN=top>:time_unit:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>Food Unit<br></td>\
<td COLSPAN=3 VALIGN=top>:food_unit:<br></td>\
<td VALIGN=top>Procurement Unit<br></td>\
<td COLSPAN=2 VALIGN=top>:procurement_unit:<br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><br></td>\
<td VALIGN=top>Compensation/Claims Unit<br></td>\
<td COLSPAN=2 VALIGN=top>:claims_unit:<br></td>\
</tr>\
<tr>\
<td COLSPAN=4 VALIGN=top><br></td>\
<td VALIGN=top>Cost Unit<br></td>\
<td COLSPAN=2 VALIGN=top>:cost_unit:<br></td>\
</tr>\
<tr>\
<td COLSPAN=7 VALIGN=top><b>Prepared by (Resources Unit)</b><br>:pre:<br></td>\
</tr>\
<tr>\
<td WIDTH=15% VALIGN=center HEIGHT=20px>ICS-203</td>\
<td WIDTH=10%></td>\
<td WIDTH=12%></td>\
<td WIDTH=13%></td>\
<td WIDTH=20%></td>\
<td WIDTH=15%></td>\
<td WIDTH=15%></td>\
</tr>\
</tbody>\
</table>\
</body></html>";

const char ics203_text_template[] =
"ICS 203 ORGANIZATION ASSIGNMENT LIST\n\n\
incident: :inc:\n\
date: :dat:\n\
time: :tim:\n\
op_period: :opp:\n\
incident_commander: :icc:\n\
incident_deputy: :icd:\n\
incident_safety_officer: :ics:\n\
incident_info_officer: :ici:\n\
liaison_officer: :icl:\n\
prepared_by: :pre:\n\
agency: :agency[0]:, name: :agency_name[0]:\n\
agency: :agency[1]:, name: :agency_name[1]:\n\
agency: :agency[2]:, name: :agency_name[2]:\n\
agency: :agency[3]:, name: :agency_name[3]:\n\
agency: :agency[4]:, name: :agency_name[4]:\n\
agency: :agency[5]:, name: :agency_name[5]:\n\
agency: :agency[6]:, name: :agency_name[6]:\n\
planning_chief: :planning_chief:\n\
planning_deputy: :planning_deputy:\n\
resources_unit: :resources_unit:\n\
situation_unit: :situation_unit:\n\
documentation_unit: :documentation_unit:\n\
demobilization_unit: :demobilization_unit:\n\
tech_spc: :tech_spc[0]:\n\
tech_spc: :tech_spc[1]:\n\
tech_spc: :tech_spc[2]:\n\
logistics_chief: :logistics_chief:\n\
logistics_deputy: :logistics_deputy:\n\
support_director: :support_director:\n\
supply_unit: :supply_unit:\n\
facilities_unit: :facilities_unit:\n\
ground_support: :ground_support:\n\
service_director: :service_director:\n\
communications_unit: :communications_unit:\n\
medical_unit: :medical_unit:\n\
food_unit: :food_unit:\n\
ops_chief: :ops_chief:\n\
ops_deputy: :ops_deputy:\n\
b1_director: :b1_director:\n\
b1_deputy: :b1_deputy:\n\
b1_div/grp: :b1_div[0]:, :b1_grp[0]:\n\
b1_div/grp: :b1_div[1]:, :b1_grp[1]:\n\
b1_div/grp: :b1_div[2]:, :b1_grp[2]:\n\
b1_div/grp: :b1_div[3]:, :b1_grp[3]:\n\
b1_div/grp: :b1_div[4]:, :b1_grp[4]:\n\
b2_director: :b2_director:\n\
b2_deputy: :b2_deputy:\n\
b2_div/grp: :b2_div[0]:, :b2_grp[0]:\n\
b2_div/grp: :b2_div[1]:, :b2_grp[1]:\n\
b2_div/grp: :b2_div[2]:, :b2_grp[2]:\n\
b2_div/grp: :b2_div[3]:, :b2_grp[3]:\n\
b2_div/grp: :b2_div[4]:, :b2_grp[4]:\n\
b3_director: :b3_director:\n\
b3_deputy: :b3_deputy:\n\
b3_div/grp: :b3_div[0]:, :b3_grp[0]:\n\
b3_div/grp: :b3_div[1]:, :b3_grp[1]:\n\
b3_div/grp: :b3_div[2]:, :b3_grp[2]:\n\
b3_div/grp: :b3_div[3]:, :b3_grp[3]:\n\
b3_div/grp: :b3_div[4]:, :b3_grp[4]:\n\
air_ops_br_dir: :air_ops_br_dir:\n\
air_tactical_group_sup: :air_tactical_group_sup:\n\
air_support_group_sup: :air_support_group_sup:\n\
helicopter_coordinator: :helicopter_coordinator:\n\
air_tanker_fixed_wing: :air_tanker_fixed_wing:\n\
finance_chief: :finance_chief:\n\
finance_deputy: :finance_deputy:\n\
time_unit: :time_unit:\n\
procurement_unit: :procurement_unit:\n\
claims_unit: :claims_unit:\n\
cost_unit: :cost_unit:\n\
";

