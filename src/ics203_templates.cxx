// =====================================================================
//
// ics203_templates.cxx
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

//======================================================================
// ics203 form template
//======================================================================

const char ics203_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n\
<title>:TITLE:</title>\n\
</head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: middle; font-weight: bold;\"><big>ORGANIZATION ASSIGNMENT LIST\n\
</big></td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">1. Incident name</span><br>:inc:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">2.Date Prepared</span><br>:dat:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">3.Time Prepared</span><br>:tim:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\"><br>\n\
</span><br>\n\
<hr style=\"width: 100%; height: 2px;\"><span style=\"font-weight: bold;\">5. Incident Command and Staff</span><br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">4. Operational Period (Date/Time)</span><br>:opp:<br>\n\
<hr style=\"width: 100%; height: 2px;\"><span style=\"font-weight: bold;\">9. Operations section</span><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Incident Commander<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:icc:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Chief<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:ops_chief:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:icd:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:ops_deputy:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Safety Officer<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:ics:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">a. Branch I - Division / Groups</span><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Information Officer<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:ici:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Branch Director<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b1_director:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Liaison Officer<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:icl:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b1_deputy:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">6. Agency Representative</span><br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">Division / Group<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Agency<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">Name<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b1_div[0]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b1_grp[0]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:agency[0]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:agency_name[0]:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b1_div[1]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b1_grp[1]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:agency[1]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:agency_name[1]:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b1_div[2]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b1_grp[2]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:agency[2]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:agency_name[2]:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b1_div[3]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b1_grp[3]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:agency[3]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:agency_name[3]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">b. Branch II - Division / Groups</span><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:agency[4]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:agency_name[4]:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Chief<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b2_director:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:agency[5]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:agency_name[5]:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b2_deputy:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:agency[6]:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:agency_name[6]:</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">Division / Group<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">7. Planning Section</span><br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b2_div[0]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b2_grp[0]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Chief<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:planning_chief:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b2_div[1]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b2_grp[1]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:planning_deputy:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b2_div[2]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b2_grp[2]: <br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Resources Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:resources_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b2_div[3]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b2_grp[3]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Situation Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:situation_unit:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">c. Branch III - Division / Groups</span><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Documentation Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:documentation_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Chief<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b3_director:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Demobilization Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:demobilization_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b3_deputy:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Technical Specialists<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">Division / Group<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Specialist</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:tech_spc[0]:</td>\n\
<td style=\"vertical-align: top;\">:b3_div[0]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b3_grp[0]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Specialist</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:tech_spc[1]: </td>\n\
<td style=\"vertical-align: top;\">:b3_div[1]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b3_grp[1]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Specialist</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:tech_spc[2]: </td>\n\
<td style=\"vertical-align: top;\">:b3_div[2]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b3_grp[2]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">8. Logistics Section</span><br>\n\
</td>\n\
<td style=\"vertical-align: top;\">:b3_div[3]:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:b3_grp[3]:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Chief<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:logistics_chief:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">d. Air Operations Branch</span><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:logistics_deputy:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Air Operations Br. Dir.<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:air_ops_br_dir:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">a. Support Branch</span><br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Air Tactical Group Sup.<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:air_tactical_group_sup:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Director<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:support_director:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Air Support Group Sup.<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:air_support_group_sup:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Supply Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:supply_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Helicopter Coordinator<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:helicopter_coordinator:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Facilities Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:facilities_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Air Tanker / Fixed Wing Crd.<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:air_tanker_fixed_wing:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Ground Support Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:ground_support:<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">b. Service Branch</span><br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">10. Finance / Administration Section</span><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Director<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:service_director:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Chief<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:finance_chief:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Communications Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:communications_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Deputy<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:finance_deputy:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Medical Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:medical_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Time Unit<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:time_unit:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Food Unit<br>\n\
</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">:food_unit:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Procurement Unit<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:procurement_unit:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Compensation/Claims Unit<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:claims_unit:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\"><br>\n\
</td>\n\
<td style=\"vertical-align: top;\">Cost Unit<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">:cost_unit:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"7\" style=\"vertical-align: top;\"><span style=\"font-weight: bold;\">Prepared by (Resources Unit)</span><br>\n\
:pre:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 15%; height: 24px;\">ICS-203\n\
</td>\n\
<td style=\"vertical-align: top; width: 10%; height: 24px;\">\n\
<hr style=\"width: 100%; height: 2px;\"></td>\n\
<td style=\"vertical-align: top; width: 12%; height: 24px;\">\n\
<hr style=\"width: 100%; height: 2px;\"></td>\n\
<td style=\"vertical-align: top; width: 13%; height: 24px;\">\n\
<hr style=\"width: 100%; height: 2px;\"></td>\n\
<td style=\"vertical-align: top; width: 20%; height: 24px;\">\n\
<hr style=\"width: 100%; height: 2px;\"></td>\n\
<td style=\"vertical-align: top; width: 15%; height: 24px;\">\n\
<hr style=\"width: 100%; height: 2px;\"></td>\n\
<td style=\"vertical-align: top; width: 15%; height: 24px;\">\n\
<hr style=\"width: 100%; height: 2px;\"></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body></html>\n\
";

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

