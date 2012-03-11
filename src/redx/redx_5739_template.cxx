// =====================================================================
//
// redx_templates.cxx
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
// red cross safety and welfare template
//======================================================================

#include "templates.h"

const char redx_5739_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>RedCross-5739</title></head><body>\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 9%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
<td style=\"vertical-align: top; width: 7%;\"></td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"7\" style=\"vertical-align: top;\">American Red Cross Form 5739</td>\n\
<td colspan=\"7\" style=\"vertical-align: top; text-align: right;\">On-Site Detailed Damage Assessment Worksheet (Street Sheet)</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">DR #:<br>:nbr:</td>\n\
\n\
<td colspan=\"3\" style=\"vertical-align: top;\">DR Name:<br>:name:</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">State:<br>:state:</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">County:<br>:cnty:</td>\n\
<td colspan=\"3\" style=\"vertical-align: top;\">City/Community:<br>:city:</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Date:<br>:date:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"5\" style=\"vertical-align: top;\">Street name: :street:</td>\n\
<td colspan=\"9\" style=\"vertical-align: top;\">Geographical Reference: :georef:</td>\n\
\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">House #</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">Apt<br>/ Unit #</td>\n\
<td colspan=\"5\" style=\"vertical-align: top; text-align: center; background-color: rgb(207, 207, 207);\">Damage Classification</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\"># floors in<br>dwelling</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">Basement<br>Y/N</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">Water Level<br>inches</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">Water Level<br>in basement</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">Electric<br>Y/N</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">Own/Rent/<br>Seasonal</td>\n\
<td rowspan=\"2\" style=\"vertical-align: top; text-align: center;\">OR<br>/ 901</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">Destroyed</td>\n\
<td style=\"vertical-align: top; text-align: center;\">Major</td>\n\
<td style=\"vertical-align: top; text-align: center;\">Minor</td>\n\
<td style=\"vertical-align: top; text-align: center;\">Affected</td>\n\
<td style=\"vertical-align: top; text-align: center;\"><small>Inaccessible</small></td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[0]:</td>\n\
<td style=\"vertical-align: top;\">:ap[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[0]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[0]:</td>\n\
<td style=\"vertical-align: top;\">:or[0]:/:901[0]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[0]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[0]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[1]:</td>\n\
<td style=\"vertical-align: top;\">:ap[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[1]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[1]:</td>\n\
<td style=\"vertical-align: top;\">:or[1]:/:901[1]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[1]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[1]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[2]:</td>\n\
<td style=\"vertical-align: top;\">:ap[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[2]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[2]:</td>\n\
<td style=\"vertical-align: top;\">:or[2]:/:901[2]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[2]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[2]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[3]:</td>\n\
<td style=\"vertical-align: top;\">:ap[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[3]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[3]:</td>\n\
<td style=\"vertical-align: top;\">:or[3]:/:901[3]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[3]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[3]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[4]:</td>\n\
<td style=\"vertical-align: top;\">:ap[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[4]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[4]:</td>\n\
<td style=\"vertical-align: top;\">:or[4]:/:901[4]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[4]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[4]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[5]:</td>\n\
<td style=\"vertical-align: top;\">:ap[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[5]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[5]:</td>\n\
<td style=\"vertical-align: top;\">:or[5]:/:901[5]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[5]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[5]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[6]:</td>\n\
<td style=\"vertical-align: top;\">:ap[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[6]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[6]:</td>\n\
<td style=\"vertical-align: top;\">:or[6]:/:901[6]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[6]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[6]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[7]:</td>\n\
<td style=\"vertical-align: top;\">:ap[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[7]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[7]:</td>\n\
<td style=\"vertical-align: top;\">:or[7]:/:901[7]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[7]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[7]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[8]:</td>\n\
<td style=\"vertical-align: top;\">:ap[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[8]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[8]:</td>\n\
<td style=\"vertical-align: top;\">:or[8]:/:901[8]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[8]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[8]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:hb[9]:</td>\n\
<td style=\"vertical-align: top;\">:ap[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:des[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:maj[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:min[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:aff[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:acc[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:flr[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bas[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:wtr[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:bwl[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ele[9]:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:occ[9]:</td>\n\
<td style=\"vertical-align: top;\">:or[9]:/:901[9]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" style=\"vertical-align: top;\">Description: :desc[9]:</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">Name: :nam[9]:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"14\" style=\"vertical-align: top;\">\n\
<hr style=\"width: 90%; height: 2px;\"></td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Total single family:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:sf_des:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:sf_maj:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:sf_min:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:sf_aff:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:sf_ina:</td>\n\
<td colspan=\"7\" rowspan=\"2\" style=\"vertical-align: top;\">Additional information: :addinf:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Total mobile home:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:mh_des:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:mh_maj:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:mh_min:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:mh_aff:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:mh_ina:</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Total apartment:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ap_des:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ap_maj:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ap_min:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ap_aff:</td>\n\
<td style=\"vertical-align: top; text-align: center;\">:ap_ina:</td>\n\
<td colspan=\"5\" style=\"vertical-align: top;\">Worker completing form: :worker:</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">Supervisor: :supervisor:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<br>\n\
</body></html>";


const char redx_5739_text_template[] = 
"            On-Site Detailed Damage Assessment Worksheet\n\
DR #:           :nbr:\n\
DR Name:        :name:\n\
State:          :state:\n\
County:         :cnty:\n\
City:           :city:\n\
Date:           :date:\n\
Street:         :street:\n\
Geo ref:        :georef:\n\
\n\
House #:        :hb[0]:\n\
Apt/Unit #:     :ap[0]:\n\
Destroyed:      :des[0]:\n\
Major:          :maj[0]:\n\
Minor:          :min[0]:\n\
Affected:       :aff[0]:\n\
Inaccessible:   :acc[0]:\n\
# floors:       :flr[0]:\n\
Basement:       :bas[0]:\n\
Water level:    :wtr[0]:\n\
Bsmnt water:    :bwl[0]:\n\
Electric:       :ele[0]:\n\
Occupancy type: :occ[0]:\n\
OR:             :or[0]:\n\
901:            :901[0]:\n\
Description:    :desc[0]:\n\
Name:           :nam[0]:\n\
House #:        :hb[1]:\n\
Apt/Unit #:     :ap[1]:\n\
Destroyed:      :des[1]:\n\
Major:          :maj[1]:\n\
Minor:          :min[1]:\n\
Affected:       :aff[1]:\n\
Inaccessible:   :acc[1]:\n\
# floors:       :flr[1]:\n\
Basement:       :bas[1]:\n\
Water level:    :wtr[1]:\n\
Bsmnt water:    :bwl[1]:\n\
Electric:       :ele[1]:\n\
Occupancy type: :occ[1]:\n\
OR:             :or[1]:\n\
901:            :901[1]:\n\
Description:    :desc[1]:\n\
Name:           :nam[1]:\n\
House #:        :hb[2]:\n\
Apt/Unit #:     :ap[2]:\n\
Destroyed:      :des[2]:\n\
Major:          :maj[2]:\n\
Minor:          :min[2]:\n\
Affected:       :aff[2]:\n\
Inaccessible:   :acc[2]:\n\
# floors:       :flr[2]:\n\
Basement:       :bas[2]:\n\
Water level:    :wtr[2]:\n\
Bsmnt water:    :bwl[2]:\n\
Electric:       :ele[2]:\n\
Occupancy type: :occ[2]:\n\
OR:             :or[2]:\n\
901:            :901[2]:\n\
Description:    :desc[2]:\n\
Name:           :nam[2]:\n\
House #:        :hb[3]:\n\
Apt/Unit #:     :ap[3]:\n\
Destroyed:      :des[3]:\n\
Major:          :maj[3]:\n\
Minor:          :min[3]:\n\
Affected:       :aff[3]:\n\
Inaccessible:   :acc[3]:\n\
# floors:       :flr[3]:\n\
Basement:       :bas[3]:\n\
Water level:    :wtr[3]:\n\
Bsmnt water:    :bwl[3]:\n\
Electric:       :ele[3]:\n\
Occupancy type: :occ[3]:\n\
OR:             :or[3]:\n\
901:            :901[3]:\n\
Description:    :desc[3]:\n\
Name:           :nam[3]:\n\
House #:        :hb[4]:\n\
Apt/Unit #:     :ap[4]:\n\
Destroyed:      :des[4]:\n\
Major:          :maj[4]:\n\
Minor:          :min[4]:\n\
Affected:       :aff[4]:\n\
Inaccessible:   :acc[4]:\n\
# floors:       :flr[4]:\n\
Basement:       :bas[4]:\n\
Water level:    :wtr[4]:\n\
Bsmnt water:    :bwl[4]:\n\
Electric:       :ele[4]:\n\
Occupancy type: :occ[4]:\n\
OR:             :or[4]:\n\
901:            :901[4]:\n\
Description:    :desc[4]:\n\
Name:           :nam[4]:\n\
House #:        :hb[5]:\n\
Apt/Unit #:     :ap[5]:\n\
Destroyed:      :des[5]:\n\
Major:          :maj[5]:\n\
Minor:          :min[5]:\n\
Affected:       :aff[5]:\n\
Inaccessible:   :acc[5]:\n\
# floors:       :flr[5]:\n\
Basement:       :bas[5]:\n\
Water level:    :wtr[5]:\n\
Bsmnt water:    :bwl[5]:\n\
Electric:       :ele[5]:\n\
Occupancy type: :occ[5]:\n\
OR:             :or[5]:\n\
901:            :901[5]:\n\
Description:    :desc[5]:\n\
Name:           :nam[5]:\n\
House #:        :hb[6]:\n\
Apt/Unit #:     :ap[6]:\n\
Destroyed:      :des[6]:\n\
Major:          :maj[6]:\n\
Minor:          :min[6]:\n\
Affected:       :aff[6]:\n\
Inaccessible:   :acc[6]:\n\
# floors:       :flr[6]:\n\
Basement:       :bas[6]:\n\
Water level:    :wtr[6]:\n\
Bsmnt water:    :bwl[6]:\n\
Electric:       :ele[6]:\n\
Occupancy type: :occ[6]:\n\
OR:             :or[6]:\n\
901:            :901[6]:\n\
Description:    :desc[6]:\n\
Name:           :nam[6]:\n\
House #:        :hb[7]:\n\
Apt/Unit #:     :ap[7]:\n\
Destroyed:      :des[7]:\n\
Major:          :maj[7]:\n\
Minor:          :min[7]:\n\
Affected:       :aff[7]:\n\
Inaccessible:   :acc[7]:\n\
# floors:       :flr[7]:\n\
Basement:       :bas[7]:\n\
Water level:    :wtr[7]:\n\
Bsmnt water:    :bwl[7]:\n\
Electric:       :ele[7]:\n\
Occupancy type: :occ[7]:\n\
OR:             :or[7]:\n\
901:            :901[7]:\n\
Description:    :desc[7]:\n\
Name:           :nam[7]:\n\
House #:        :hb[8]:\n\
Apt/Unit #:     :ap[8]:\n\
Destroyed:      :des[8]:\n\
Major:          :maj[8]:\n\
Minor:          :min[8]:\n\
Affected:       :aff[8]:\n\
Inaccessible:   :acc[8]:\n\
# floors:       :flr[8]:\n\
Basement:       :bas[8]:\n\
Water level:    :wtr[8]:\n\
Bsmnt water:    :bwl[8]:\n\
Electric:       :ele[8]:\n\
Occupancy type: :occ[8]:\n\
OR:             :or[8]:\n\
901:            :901[8]:\n\
Description:    :desc[8]:\n\
Name:           :nam[8]:\n\
House #:        :hb[9]:\n\
Apt/Unit #:     :ap[9]:\n\
Destroyed:      :des[9]:\n\
Major:          :maj[9]:\n\
Minor:          :min[9]:\n\
Affected:       :aff[9]:\n\
Inaccessible:   :acc[9]:\n\
# floors:       :flr[9]:\n\
Basement:       :bas[9]:\n\
Water level:    :wtr[9]:\n\
Bsmnt water:    :bwl[9]:\n\
Electric:       :ele[9]:\n\
Occupancy type: :occ[9]:\n\
OR:             :or[9]:\n\
901:            :901[9]:\n\
Description:    :desc[9]:\n\
Name:           :nam[9]:\n\
\n\
Total Single Family:\n\
  destroyed:    :sf_des:\n\
  major:        :sf_maj:\n\
  minor:        :sf_min:\n\
  affected:     :sf_aff:\n\
  inaccessible: :sf_ina:\n\
Total Mobile Home:\n\
  destroyed:    :mh_des:\n\
  major:        :mh_maj:\n\
  minor:        :mh_min:\n\
  affected:     :mh_aff:\n\
  inaccessible: :mh_ina:\n\
Total Apartment:\n\
  destroyed:    :ap_des:\n\
  major:        :ap_maj:\n\
  minor:        :ap_min:\n\
  affected:     :ap_aff:\n\
  inaccessible: :ap_ina:\n\
\n\
Additional info: :add_info:\n\
Worker:          :worker:\n\
Supervisor:      :supervisor:\n\
\n";


