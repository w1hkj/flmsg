// =====================================================================
//
// hics_hics203_templates.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2011
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
// hics_hics203 form template
//======================================================================

#include "templates.h"

const char hics203_html_template[] = 
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\
<html><head>\
<meta http-equiv=\"CONTENT-TYPE\" content=\"text/html; charset=utf-8\"><title>HICS-203</title>\
<meta name=\"AUTHOR\" content=\"w1hkj\">\
<meta name=\"CREATED\" content=\"20111027;13000000\">\
</head>\
<body>\
<table style=\"width: 100%;\" cellpadding=\"2\" cellspacing=\"0\" border=\"1\">\
<col width=30%><col width=20%><col width=20%><col width=30%>\
<tbody><tr>\
<td colspan=\"2\"><font style=\"font-size:12pt;\"><b>HICS-203 – ORGANIZATION ASSIGNMENT LIST</b></font></td>\
<td colspan=\"2\"></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\"><b>1. INCIDENT NAME</b></font><br>:inc:</td>\
<td><font style=\"font-size:11pt;\"><b>2. DATE PREPARED</b></font><br>:dat:</td>\
<td><font style=\"font-size:11pt;\"><b>3. TIME PREPARED</b></font><br>:tim:</td>\
<td><font style=\"font-size:11pt;\"><b>4. OPERATIONAL PERIOD DATE/TIME</b></font><br>:opp:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\"><b>POSITION</b></td>\
<td colspan=\"3\" ><font style=\"font-size: 11pt;\"><b>NAME / tech_spec</b></font></td>\
</tr>\
<tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>5.Incident Commander and Staff</b></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Incident Commander</font></td>\
<td colspan=\"3\">:icc:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Public Information Officer</font></td>\
<td colspan=\"3\">:ici:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Liaison Officer</font></font></td>\
<td colspan=\"3\">:icl:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Safety Officer</font></td>\
<td colspan=\"3\">:ics:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Medical/Technical Specialist (Type)</font></td>\
<td colspan=\"3\">:tech_spc[0]:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Medical/Technical Specialist (Type)</font></td>\
</td>\
<td colspan=\"3\">:tech_spc[1]:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Medical/Technical Specialist (Type)</font></td>\
<td colspan=\"3\">:tech_spc[2]:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Medical/Technical Specialist (Type)</font></td>\
<td colspan=\"3\">:tech_spc[3]:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Medical/Technical Specialist (Type)</font></td>\
<td colspan=\"3\">:tech_spc[4]:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Medical/Technical Specialist (Type)</font></td>\
<td colspan=\"3\">:tech_spc[5]:</td>\
</tr>\
<tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>6. Operations Section</span></b></font></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Chief</font></td>\
<td colspan=\"3\">:ops_chief:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Staging Manager</font></td>\
<td colspan=\"3\">:stg_mgr:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Medical Care Branch</font></td>\
<td colspan=\"3\">:med_care_brch:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Infrastructure Branch</font></td>\
<td colspan=\"3\">:infr_brch:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Security Branch</font></td>\
<td colspan=\"3\">:sec_brch:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Business Continuity Branch</font></td>\
<td colspan=\"3\">:bus_brch:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">HazMat Branch</font></td>\
<td colspan=\"3\">:hazmat_brch:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Other Branch:</font></td>\
<td colspan=\"3\">:ops_other:</td>\
</tr>\
<tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>7. Planning Section</span></b></font></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Chief</font></td>\
<td colspan=\"3\">:planning_chief:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Resources Unit</font></td>\
<td colspan=\"3\">:res_unit:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Situation Unit</font></td>\
<td colspan=\"3\">:sit_unit:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Documentation Unit</font></td>\
<td colspan=\"3\">:doc_unit:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Demobilization Unit</font></td>\
<td colspan=\"3\">:dem_unit:</td>\
</tr>\
<tr>\
<td><font style=\"font-size:11pt;\">Other Branch:</font></td>\
<td colspan=\"3\">:planning_other:</td>\
</tr>\
<tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>8. Logistics Section</b></font></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Chief</font></td>\
<td colspan=\"3\">:log_chief:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Service Branch</font></td>\
<td colspan=\"3\">:svc_brch:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Support Branch</font></td>\
<td colspan=\"3\">:sup_brch:</td>\
</tr>\
<tr>\
<td><font style=\"font-size:11pt;\">Other Branch:</font></td>\
<td colspan=\"3\">:log_other:</td>\
</tr>\
<tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>9. Finance/Administration Section</b></font></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Chief</font></td>\
<td colspan=\"3\">:fin_chief:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Time Unit</font></td>\
<td colspan=\"3\">:time_unit:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Procurement Unit</font></td>\
<td colspan=\"3\">:proc_unit:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Compensation/Claims Unit</font></td>\
<td colspan=\"3\">:comp_unit:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Cost Unit</font></td>\
<td colspan=\"3\">:cost_unit:</td>\
</tr>\
<tr>\
<td><font style=\"font-size:11pt;\">Other Branch:</font></td>\
<td colspan=\"3\">:fin_other:</td>\
</tr>\
<tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>10. Agency Representative (in Hospital Command Center)</b></font></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Agency</font></td>\
<td colspan=\"3\">:hcc_agency:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Representative</font></td>\
<td colspan=\"3\">:hcc_rep:</td>\
</tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>11. Hospital Representative (in External EOC)</b></font></td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">External Location</font></td>\
<td colspan=\"3\">:ext_loc:</td>\
</tr>\
<tr valign=\"top\">\
<td><font style=\"font-size:11pt;\">Representative<br></td>\
<td colspan=\"3\">:ext_rep:</td>\
</tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>12. PREPARED BY (RESOURCES UNIT LEADER)</b></font> :pre:</td>\
</tr>\
<tr>\
<td colspan=\"4\"><font style=\"font-size: 11pt;\"><b>13. FACILITY NAME</b></font> :facility:</td>\
</tr>\
</tbody>\
</table>\
Generated by flmsg\
</body>\
</html>";

const char hics203_text_template[] =
"HICS 203 ORGANIZATION ASSIGNMENT LIST\n\n\
1. INCIDENT NAME: :inc:\n\
2. DATE PREPARED: :dat:\n\
3. TIME PREPARED: :tim:\n\
4. OPERATIONAL PERIOD: :opp:\n\
5. Incident Commander and Staff\n\
   Incident Commander: :icc:\n\
   Public Information Officer: :ici:\n\
   Liaison Officer: :icl:\n\
   Safety Officer: :ics:\n\
   Medical/Technical Specialist (Type)\n\
     :tech_spc[0]:\n\
     :tech_spc[1]:\n\
     :tech_spc[2]:\n\
     :tech_spc[3]:\n\
     :tech_spc[4]:\n\
     :tech_spc[5]:\n\
6. Operations Section\n\
   Chief: :ops_chief:\n\
   Staging Manager: :stg_mgr:\n\
   Medical Care Branch: :med_care_brch:\n\
   Infrastructure Branch: :infr_brch:\n\
   Security Branch: :sec_brch:\n\
   Business Continuity Branch: :bus_brch:\n\
   HazMat Branch: :hazmat_brch:\n\
   Other Ops Branch: :ops_other:\n\
7. Planning Section\n\
   Chief: :planning_chief:\n\
   Resources Unit: :res_unit:\n\
   Situation Unit: :sit_unit:\n\
   Documentation Unit: :doc_unit:\n\
   Demobilization Unit: :dem_unit:\n\
   Other Planning Branch: :planning_other:\n\
8. Logistics Section\n\
   Chief: :log_chief:\n\
   Service Branch: :svc_brch:\n\
   Support Branch: :sup_brch:\n\
   Other Logistics Branch: :log_other:\n\
9. Finance/Administration Section\n\
   Chief: :fin_chief:\n\
   Time Unit: :time_unit:\n\
   Procurement Unit: :proc_unit:\n\
   Compensation/Claims Unit: :comp_unit:\n\
   Cost Unit: :cost_unit:\n\
   Other Finance/Admin Branch: :fin_other:\n\
10. Agency Representative (in Hospital Command Center)\n\
    Agency: :hcc_agency:\n\
    Rep: :hcc_rep:\n\
11. Hospital Representative (in External EOC)\n\
    External Location: :ext_loc:\n\
    Rep: :ext_rep:\n\
12. PREPARED BY (RESOURCES UNIT LEADER): :pre:\n\
13. FACILITY NAME: :facility:\n";
