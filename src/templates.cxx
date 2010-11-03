// =====================================================================
//
// templates.cxx
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

#include "templates.h"

//======================================================================
// ics203 form template
//======================================================================

const char ics203_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n\
<title>ics203</title>\n\
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

//======================================================================
// ics205 form template
//======================================================================

const char ics205_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>ics205</title></head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr style=\"font-weight: bold;\" align=\"center\">\n\
<td colspan=\"2\" style=\"vertical-align: top; width: 250px;\"><span style=\"font-weight: bold;\">INCIDENT RADIO<br>\n\
COMMUNICATIONS</span> <span style=\"font-weight: bold;\">PLAN</span></td>\n\
<td colspan=\"2\" style=\"vertical-align: top; font-weight: normal; width: 250px;\">\n\
<div style=\"text-align: left;\">1. Incident Name<br>\n\
</div>\n\
<div style=\"text-align: left;\">\n\
<nam:</div>\n\
</td>\n\
      <td style=\"vertical-align: top; text-align: left; font-weight: normal; width: 250px;\">2. Date/Time Prepared<br>\n\
<dt1:</td>\n\
      <td style=\"vertical-align: top; text-align: left; font-weight: normal; width: 250px;\">3. Operational Period Date/Time<br>\n\
<dt2:</td>\n\
    </tr>\n\
  </tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
  <tbody>\n\
    <tr align=\"center\">\n\
      <td colspan=\"6\" style=\"vertical-align: top;\">4. Basic Radio Channel Utilization<br>\n\
      </td>\n\
    </tr>\n\
    <tr align=\"center\">\n\
      <td style=\"vertical-align: top; width: 125px;\">Radio Type<br>\n\
Cache<br>\n\
      </td>\n\
      <td style=\"vertical-align: top; width: 125px;\">Channel<br>\n\
      </td>\n\
      <td style=\"vertical-align: top; width: 125px;\">Function<br>\n\
      </td>\n\
      <td style=\"vertical-align: top; width: 125px;\">Frequency<br>\n\
Tone<br>\n\
      </td>\n\
      <td style=\"vertical-align: top; width: 250px;\">Assignment<br>\n\
      </td>\n\
      <td style=\"vertical-align: top; width: 250px;\">Remarks<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ0:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn0:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun0:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq0:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass0:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem0:<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ1:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn1:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun1:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq1:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass1:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem1:<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ2:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn2:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun2:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq2:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass2:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem2:<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ3:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn3:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun3:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq3:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass3:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem3:<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ4:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn4:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun4:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq4:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass4:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem4:<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ5:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn5:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun5:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq5:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass5:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem5:<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ6:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn6:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun6:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq6:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass6:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem6:<br>\n\
      </td>\n\
    </tr>\n\
    <tr>\n\
      <td style=\"vertical-align: top;\"><typ7:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><chn7:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><fun7:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><frq7:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><ass7:<br>\n\
      </td>\n\
      <td style=\"vertical-align: top;\"><rem7:<br>\n\
      </td>\n\
    </tr><tr>\n\
      <td colspan=\"6\" style=\"vertical-align: top;\">5. Prepared by: <prp:<br>\n\
      </td>\n\
    </tr>\n\
  </tbody>\n\
</table>\n\
<br>\n\
";

const char ics205_text_template[] =
"ICS 205 INCIDENT RADIO COMMUNICATIONS PLAN\n\n\
Incident name: <nam:\n\
Date/Time Prepared: <dt1:\n\
Operational Period Date/Time: <dt2:\n\
Radio Type/Cache #1: <typ0:\n\
Channel #1: <chn0:\n\
Function #1: <fun0:\n\
Freq/Tone #1: <freq0:\n\
Assignment #1: <ass0:\n\
Remarks #1: <rem0:\n\
Radio Type/Cache #2: <typ1:\n\
Channel #2: <chn1:\n\
Function #2: <fun1:\n\
Freq/Tone #2: <frq1:\n\
Assignment #2: <ass1:\n\
Remarks #2: <rem1:\n\
Radio Type/Cache #3: <typ2:\n\
Channel #3: <chn2:\n\
Function #3: <fun2:\n\
Freq/Tone #3: <frq2:\n\
Assignment #3: <ass2:\n\
Remarks #3: <rem2:\n\
Radio Type/Cache #4: <typ3:\n\
Channel #4: <chn3:\n\
Function #4: <fun3:\n\
Freq/Tone #4: <frq3:\n\
Assignment #4: <ass3:\n\
Remarks #4: <rem3:\n\
Radio Type/Cache #5: <typ4:\n\
Channel #5: <chn4:\n\
Function #5: <fun4:\n\
Freq/Tone #5: <frq4:\n\
Assignment #5: <ass4:\n\
Remarks #5: <rem4:\n\
Radio Type/Cache #6: <typ5:\n\
Channel #6: <chn5:\n\
Function #6: <fun5:\n\
Freq/Tone #6: <frq5:\n\
Assignment #6: <ass5:\n\
Remarks #6: <rem5:\n\
Radio Type/Cache #7: <typ6:\n\
Channel #7: <chn6:\n\
Function #7: <fun6:\n\
Freq/Tone #7: <frq6:\n\
Assignment #7: <ass6:\n\
Remarks #7: <rem6:\n\
Radio Type/Cache #8: <typ7:\n\
Channel #8: <chn7:\n\
Function #8: <fun7:\n\
Freq/Tone #8: <frq7:\n\
Assignment #8: <ass7:\n\
Remarks #8: <rem7:\n\
Prepared by: <prp:\n";

//======================================================================
// ICS206 templates
//======================================================================
const char ics206_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>ics205</title></head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr style=\"font-weight: bold;\" align=\"center\">\n\
<td colspan=\"2\" style=\"vertical-align: middle; width: 200px;\"><span style=\"font-weight: bold;\">MEDICAL</span> <span style=\"font-weight: bold;\">PLAN</span></td>\n\
<td style=\"vertical-align: top; width: 200px; text-align: left;\"><span style=\"font-weight: normal;\">1. Incident Name</span><br>\n\
<span style=\"font-weight: normal;\"><nam:</span><br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top; font-weight: normal; width: 200px;\">\n\
<div style=\"text-align: left;\">2. Date Prepared<br>\n\
</div>\n\
<div style=\"text-align: left;\">\n\
<dat:</div>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: left; font-weight: normal; width: 200px;\">3. Time Prepared<br>\n\
<tim:</td>\n\
<td style=\"vertical-align: top; text-align: left; font-weight: normal; width: 200px;\">4. Operational Period<br>\n\
<opp:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">5. Incident Medical Aid Station<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: middle;\">Medical Aid Stations<br>\n\
</td>\n\
<td style=\"vertical-align: middle;\">Location<br>\n\
</td>\n\
<td colspan=\"1\" style=\"vertical-align: top;\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Paramedics<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 40;\"><msta0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 45%;\"><mloc0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 15%; text-align: center;\"><mpar0:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta1:</td>\n\
<td style=\"vertical-align: top;\"><mloc1:</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar1:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta2:</td>\n\
<td style=\"vertical-align: top;\"><mloc2:</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar2:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta3:</td>\n\
<td style=\"vertical-align: top;\"><mloc3:</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar3:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta4:</td>\n\
<td style=\"vertical-align: top;\"><mloc4:</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar4:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"4\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">6. Transportation<br>\n\
</td>\n\
</tr>\n\
<tr align=\"center\">\n\
<td colspan=\"4\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">A. Ambulance Services<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 25%;\">Name</td>\n\
<td style=\"vertical-align: top; width: 40%;\">Address<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 20%;\">Phone<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 15%; text-align: center;\">Paramedics<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname0:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><taddr0:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><tphon0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara0:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><taddr1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><tphon1:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara1:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><taddr2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><tphon2:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara2:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname3:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><taddr3:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><tphon3:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara3:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname4:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><taddr4:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><tphon4:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara4:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">B. Incident Ambulances<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 25%;\">Name<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 60%;\">Location<br>\n\
</td>\n\
<td style=\"vertical-align: top;  width: 15%; text-align: center;\">Paramedics<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname0:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><aloca0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara0:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><aloca1:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara1:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><aloca2:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara2:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname3:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><aloca3:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara3:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname4:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><aloca4:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara4:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"7\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">7. Hospitals<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: bottom; width: 20%;\">Name<br>\n\
</td>\n\
<td style=\"vertical-align: bottom; width: 30%;\">Address<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top; width: 10%;\">&nbsp; Travel Time<br>\n\
&nbsp; Air&nbsp;&nbsp;&nbsp; &nbsp; &nbsp; Grnd<br>\n\
</td>\n\
<td style=\"vertical-align: bottom; width: 15%;\">Phone<br>\n\
</td>\n\
<td style=\"vertical-align: bottom; width: 5%;\">Helipad<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 5%; text-align: center;\">Burn<br>\n\
Center<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname0:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><haddr0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 5%;\"><hatim0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 5%;\"><hgtim0:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hphon0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli0:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn0:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><haddr1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hatim1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hgtim1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hphon1:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli1:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn1:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><haddr2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hatim2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hgtim2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hphon2:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli2:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn2:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname3:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><haddr3:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hatim3:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hgtim3:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hphon3:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli3:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn3:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname4:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><haddr4:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hatim4:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hgtim4:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\"><hphon4:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli4:<br>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn4:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"2\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">8. Medical Emergency Procedures<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top; height: 200px;\"><proc:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%;\">9. Prepared by (Medical Unit Leader)<br>\n\
<prep:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">10.Reviewed by (Safety Officer)<br>\n\
<rvwr:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
ICS206<br>\n\
</body></html>";

const char ics206_text_template[] =
"ICS 206 MEDICAL PLAN\n\n\
Incident name: <nam:\n\
Operational period: <opp:\n\
Date Prepared: <dat:\n\
Time Prepared: <tim:\n\
Medical Aid Station #1: <msta0:\n\
Location #1: <mloc0:\n\
Paramedics #1: <mpar0:\n\
Medical Aid Station #2: <msta1:\n\
Location #2: <mloc1:\n\
Paramedics #2: <mpar1:\n\
Medical Aid Station #3: <msta2:\n\
Location #3: <mloc2:\n\
Paramedics #3: <mpar2:\n\
Medical Aid Station #4: <msta3:\n\
Location #4: <mloc3:\n\
Paramedics #4: <mpar3:\n\
Medical Aid Station #5: <msta4:\n\
Location #5: <mloc4:\n\
Paramedics #5: <mpar4:\n\
Ambulance service #1: <tname0:\n\
Address #1: <taddr0:\n\
Phone #1: <tphon0:\n\
Paramedics #1: <tpara0:\n\
Ambulance service #2: <tname1:\n\
Address #2: <taddr1:\n\
Phone #2: <tphon1:\n\
Paramedics #2: <tpara1:\n\
Ambulance service #3: <tname2:\n\
Address #3: <taddr2:\n\
Phone #3: <tphon2:\n\
Paramedics #3: <tpara2:\n\
Ambulance service #4: <tname3:\n\
Address #4: <taddr3:\n\
Phone #4: <tphon3:\n\
Paramedics #4: <tpara3:\n\
Ambulance service #5: <tname4:\n\
Address #5: <taddr4:\n\
Phone #5: <tphon4:\n\
Paramedics #5: <tpara4:\n\
Incident ambulance name #1: <aname0:\n\
Location #1: <aloca0:\n\
Paramedics #1 <apara0:\n\
Incident ambulance name #2: <aname1:\n\
Location #2: <aloca1:\n\
Paramedics #2 <apara1:\n\
Incident ambulance name #3: <aname2:\n\
Location #3: <aloca2:\n\
Paramedics #3 <apara2:\n\
Incident ambulance name #4: <aname3:\n\
Location #4: <aloca3:\n\
Paramedics #4 <apara3:\n\
Incident ambulance name #5: <aname4:\n\
Location #5: <aloca4:\n\
Paramedics #5 <apara4:\n\
Hospital name #1: <hname0:\n\
Address #1: <haddr0:\n\
Travel time, air #1: <hatim0:\n\
Travel time, ground #1: <hgtim0:\n\
Phone #1: <hphon0:\n\
Helipad #1: <hheli0:\n\
Burn center #1: <hburn0:\n\
Hospital name #2: <hname1:\n\
Address #2: <haddr1:\n\
Travel time, air #2: <hatim1:\n\
Travel time, ground #2: <hgtim1:\n\
Phone #2: <hphon1:\n\
Helipad #2: <hheli1:\n\
Burn center #2: <hburn1:\n\
Hospital name #3: <hname2:\n\
Address #3: <haddr2:\n\
Travel time, air #3: <hatim2:\n\
Travel time, ground #3: <hgtim2:\n\
Phone #3: <hphon2:\n\
Helipad #3: <hheli2:\n\
Burn center #3: <hburn2:\n\
Hospital name #4: <hname3:\n\
Address #4: <haddr3:\n\
Travel time, air #4: <hatim3:\n\
Travel time, ground #4: <hgtim3:\n\
Phone #4: <hphon3:\n\
Helipad #4: <hheli3:\n\
Burn center #4: <hburn3:\n\
Hospital name #5: <hname4:\n\
Address #5: <haddr4:\n\
Travel time, air #5: <hatim4:\n\
Travel time, ground #5: <hgtim4:\n\
Phone #5: <hphon4:\n\
Helipad #5: <hheli4:\n\
Burn center #5: <hburn4:\n\
Medical Emergency Procedures: <proc:\n\
Prepared by: <prep:\n\
Reviewed by: <rvwr:\n\
";

//======================================================================
// ICS213 templates
//======================================================================

const char ics213_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>ics213_html_template</title></head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\"><big><span style=\"font-weight: bold;\"><br>\n\
GENERAL MESSAGE</span></big><br>\n\
(ics-213)<br>\n\
<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TO: <to:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 50%;\" colspan=\"2\">POSITION: <p1:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">FROM: <fm:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">POSITION: <p2:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">SUBJ: <sb:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 25%;\">DATE: <d1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">TIME: <t1:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\">MESSAGE:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><mg:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">SIGNATURE: <s1:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">POSITION: <p3:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\">REPLY:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><rp:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<table style=\"text-align: left; width: 100%;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%; height: 100%;\">DATE:<br>\n\
<d2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">TIME:<br>\n\
<t2:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
<td style=\"vertical-align: top;\" colspan=\"2\">SIGNATURE/POSITION:<br>\n\
<s2:/<p4:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</body></html>\
";

const char ics213_text_template[] =
"ICS 213 GENERAL MESSAGE\n\n\
TO: <to:\n\
POSITION: <p1:\n\
FROM: <fm:\n\
POSITION: <p2:\n\
SUBJ: <sb:\n\
DATE: <d1:\n\
TIME: <t1:\n\
MESSAGE:\n\
<mg:\n\
SIGNATURE: <s1:\n\
POSITION: <p3:\n\
REPLY:\n\
<rp:\n\
DATE: <d2:\n\
TIME: <t2:\n\
SIGNATURE: <s2:\n\
POSITION: <p4:\n";

//======================================================================
// RADIOGRAM templates
//======================================================================
const char rg_html_template[] =
"<html>\n\
<head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n\
<title>rg_html_template</title>\n\
</head>\n\
<body>\n\
<table style=\"text-align: left; width: 1000px; \" border=\"0\" cellpadding=\"0\" cellspacing=\"2\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\n\
<font size=\"6\"><b>RADIOGRAM</b></font><br>\n\
<font size=\"3\"><b>VIA AMATEUR RADIO</b></font><br>\n\
<br>\n\
</div>\n\
<table style=\"width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 8%;\">NR</td>\n\
<td style=\"vertical-align: top; width: 17%;\">PREC</td>\n\
<td style=\"vertical-align: top; width: 15%;\">HX__</td>\n\
<td style=\"vertical-align: top; width: 10%;\">STN ORIG</td>\n\
<td style=\"vertical-align: top; width: 8%;\">CK</td>\n\
<td style=\"vertical-align: top; width: 22%;\">PLACE OF ORIGIN</td>\n\
<td style=\"vertical-align: top; width: 12%;\">TIME FILED</td>\n\
<td style=\"vertical-align: top; width: 8%;\">MON DY</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><nbr:<br></td>\n\
<td style=\"vertical-align: top;\"><prec:<br></td>\n\
<td style=\"vertical-align: top;\"><hx:<hn:<br></td>\n\
<td style=\"vertical-align: top;\"><sta:<br></td>\n\
<td style=\"vertical-align: top;\"><ck:<br></td>\n\
<td style=\"vertical-align: top;\"><org:<br></td>\n\
<td style=\"vertical-align: top;\"><t1:<br></td>\n\
<td style=\"vertical-align: top;\"><d1:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TO<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">THIS RADIO MESSAGE WAS RECEIVED AT<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%\"><to:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 50%;\"><rx:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TELEPHONE NUMBER<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tel:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<p><msg:</p>\n\
<p><sig:</p>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body></html>";

const char rg_html_fcopy_template[] = 
"<html>\n\
<head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n\
<title>rg_html_template</title>\n\
</head>\n\
<body>\n\
<table style=\"text-align: left; width: 1000px; \" border=\"0\" cellpadding=\"0\" cellspacing=\"2\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\n\
<font size=\"6\"><b>RADIOGRAM</b></font><br>\n\
<font size=\"3\"><b>VIA AMATEUR RADIO</b></font><br>\n\
<font size=\"2\"><b>FILE COPY</b></font><br>\n\
<br>\n\
</div>\n\
<table style=\"width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 8%;\">NR</td>\n\
<td style=\"vertical-align: top; width: 17%;\">PREC</td>\n\
<td style=\"vertical-align: top; width: 15%;\">HX__</td>\n\
<td style=\"vertical-align: top; width: 10%;\">STN ORIG</td>\n\
<td style=\"vertical-align: top; width: 8%;\">CK</td>\n\
<td style=\"vertical-align: top; width: 22%;\">PLACE OF ORIGIN</td>\n\
<td style=\"vertical-align: top; width: 12%;\">TIME FILED</td>\n\
<td style=\"vertical-align: top; width: 8%;\">MON DY</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><nbr:<br></td>\n\
<td style=\"vertical-align: top;\"><prec:<br></td>\n\
<td style=\"vertical-align: top;\"><hx:<hn:<br></td>\n\
<td style=\"vertical-align: top;\"><sta:<br></td>\n\
<td style=\"vertical-align: top;\"><ck:<br></td>\n\
<td style=\"vertical-align: top;\"><org:<br></td>\n\
<td style=\"vertical-align: top;\"><t1:<br></td>\n\
<td style=\"vertical-align: top;\"><d1:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width 50%;\">TO<br></td>\n\
<td style=\"vertical-align: top; width 50%;\">THIS RADIO MESSAGE WAS RECEIVED AT<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%;\"><to:<br></td>\n\
<td style=\"vertical-align: top; width: 50%;\"><rx:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TEL<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tel:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">OP NOTE <opn:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<p><msg:</p>\n\
<p><sig: OP NOTE <op2:</p>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 15%;\">FROM<br><rfm:</td>\n\
<td style=\"vertical-align: top; width: 15%;\">NET<br><rnt:</td>\n\
<td style=\"vertical-align: top; width: 20%;\">DATE/TIME<br><dt2:</td>\n\
<td style=\"vertical-align: top; wisth: 15%;\">SENT TO<br><sto:</td>\n\
<td style=\"vertical-align: top; width: 15%;\">NET<br><snt:</td>\n\
<td style=\"vertical-align: top; width: 20%;\">DATE/TIME<br><dt3:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 500px\">ORIG - FROM / DATE/TIME<br><ori:</td>\n\
<td style=\"vertical-align: top; width: 500px\">DLVD - to / DATE/TIME<br><dlv:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</body></html>";

const char rg_txt_template[] =
"<nbr: <prec:<hx: <sta: <ck: <org: <t1: <d1:\n\
<to:\n\
<tel:<opn:\n\
BT\n\
<msg:\n\
BT\n\
<sig:<op2:\n\
AR\n\
";

//======================================================================
// plaintext templates
//======================================================================

const char pt_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>pt_html_template</title></head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\">\n\
<big><span style=\"font-weight: bold;\"><tt:</span>\n\
</big><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TO: <to:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">FROM: <fm:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">SUBJ: <sb:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">DATE: <dt:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TIME: <tm:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\">MESSAGE:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><mg:<br>\n\
</td>\n\
</tr>\n\
</table>\n\
</body></html>\
";

const char pt_txt_template[] =
"TITLE: <tt:\n\
TO: <to:\n\
FROM: <fm:\n\
SUBJ: <sb:\n\
DATE: <dt:\n\
TIME: <tm:\n\
MESSAGE:\n\
<mg:\n\
";

//======================================================================
// blank form template
//======================================================================

const char blank_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>pt_html_template</title></head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><mg:<br>\n\
</td>\n\
</tr>\n\
</table>\n\
</body></html>\
";

const char blank_txt_template[] =
"<mg:";
