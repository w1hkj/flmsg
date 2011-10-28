// =====================================================================
//
// hics206_templates.cxx
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

const char hics206_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML>\n\
<HEAD>\n\
<TITLE>HICS-206</TITLE>\n\
<META NAME=\"AUTHOR\" CONTENT=\"w1hkj\">\n\
<META NAME=\"CREATED\" CONTENT=\"20111027\">\n\
<STYLE>\n\
F2{font-family: \"sans-serif\"; font-size: 10pt}\n\
F3{font-family: \"sans-serif\"; font-size: 12pt}\n\
F4{font-family: \"monospace\"; font-size: 12pt}\n\
</STYLE>\n\
</HEAD>\n\
<BODY>\n\
<TABLE WIDTH=100% cellpadding=\"2\" cellspacing=\"0\" border=\"1\">\n\
<COL WIDTH=18%>\n\
<COL WIDTH=8%>\n\
<COL WIDTH=6%>\n\
<COL WIDTH=18%>\n\
<COL WIDTH=4%>\n\
<COL WIDTH=4%>\n\
<COL WIDTH=10%>\n\
<COL WIDTH=6%>\n\
<COL WIDTH=26%>\n\
<tr>\n\
<td COLSPAN=9><F3>\n\
<b>HICS 206 – STAFF MEDICAL PLAN</b></F3>\n\
</td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=3><F2>\n\
<b>1. INCIDENT NAME</b>\n\
<br>:1:\n\
</F2>\n\
</td>\n\
<td><F2>\n\
<b>2. DATE PREPARED</b>\n\
<br>:2:\n\
</F2>\n\
</td>\n\
<td COLSPAN=3><F2>\n\
<b>3. TIME PREPARED</b>\n\
<br>:3:\n\
</F2>\n\
</td>\n\
<td COLSPAN=2><F2>\n\
<b>4. OPERATIONAL PERIOD DATE/TIME</b>\n\
<br>:4:\n\
</F2>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9>\n\
<F2>\n\
<b>5. TREATMENT OF INJURED / STAFF</b></F2>\n\
</td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=4><F2>\n\
<b>Location of Staff Treatment Area</b>\n\
<br>:5:<br>\n\
</F2></td>\n\
<td COLSPAN=5><F2>\n\
<b>Contact Information</b>\n\
<br>:6:<br>\n\
</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=4><F2>\n\
<b>Treatment Area Team Leader</b>\n\
<br>:7:<br>\n\
</F2>\n\
</td>\n\
<td COLSPAN=5><F2>\n\
<b>Contact Information</b>\n\
<br>:8:<br>\n\
</F2>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><F2>\n\
<b>Special Instructions</b></F2>\n\
<F4><pre>:9:</pre></F4>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><F2><b>6. RESOURCES ON HAND</b></F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><F2>\n\
<b>STAFF</b>\n\
</F2>\n\
</td>\n\
<td COLSPAN=3>\n\
<F2>\n\
<b>MEDICAL TRANSPORTATION </b>\n\
</F2>\n\
</td>\n\
<td COLSPAN=3>\n\
<F2>\n\
<b>MEDICATION </b>\n\
</F2>\n\
</td>\n\
<td>\n\
<F2>\n\
<b>SUPPLIES</b>\n\
</F2>\n\
</td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><F2>MD/DO: :10:</F2></td>\n\
<td COLSPAN=3><F2>Litters: :11:</F2></td>\n\
<td COLSPAN=3><F2>:12:</F2></td>\n\
<td><F2>:13:</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><F2>PA/NP: :14:</F2></td>\n\
<td COLSPAN=3><F2>Portable :15:</F2></td>\n\
<td COLSPAN=3><F2>:16:</F2></td>\n\
<td><F2>:17:</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><F2>RN/LPN: :18:</F2></td>\n\
<td COLSPAN=3><F2>Transport: :19:</F2></td>\n\
<td COLSPAN=3><F2>:20:</F2></td>\n\
<td><F2>:21:</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><F2>Technicians/CN: :22:</F2></td>\n\
<td COLSPAN=3><F2>Wheelchairs: :23:</F2></td>\n\
<td COLSPAN=3><F2>:24:</F2></td>\n\
<td><F2>:25:</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><F2>Ancillary/Other: :26:</F2></td>\n\
<td COLSPAN=3><F2>:27:</F2></td>\n\
<td COLSPAN=3><F2>:28:</F2></td>\n\
<td><F2>:29:</F2></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><F2><b>7. ALTERNATE CARE SITE(S)</b></F2></td>\n\
</tr>\n\
<tr>\n\
<td ALIGN=CENTER><F2><b>NAME</b></F2></td>\n\
<td COLSPAN=5 ALIGN=CENTER><F2><b>ADDRESS</b></F2></td>\n\
<td COLSPAN=2 ALIGN=CENTER><F2><b>PHONE</b></F2></td>\n\
<td ALIGN=CENTER><F2><b>SPECIALTY CARE</b></F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><F2>:30:<br></F2></td>\n\
<td COLSPAN=5><F2>:31:</F2></td>\n\
<td COLSPAN=2><F2>:32:</F2></td>\n\
<td><F2>:33:</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><F2>:34:<br></F2></td>\n\
<td COLSPAN=5><F2>:35:</F2></td>\n\
<td COLSPAN=2><F2>:36:</F2></td>\n\
<td><F2>:37:</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><F2>:38:<br></F2></td>\n\
<td COLSPAN=5><F2>:39:</F2></td>\n\
<td COLSPAN=2><F2>:40:</F2></td>\n\
<td><F2>:41:</F2></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><F2>:42:<br></F2></td>\n\
<td COLSPAN=5><F2>:43:</F2></td>\n\
<td COLSPAN=2><F2>:44:</F2></td>\n\
<td><F2>:45:</F2></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><F2>\n\
<b>8. PREPARED BY (SUPPORT BRANCH DIRECTOR):</b> :46:\n\
</F2>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><F2>\n\
<b>9. FACILITY NAME</b> :47:\n\
</F2>\n\
</td>\n\
</tr>\n\
</TABLE>\n\
</BODY>\n\
</HTML>";

const char hics206_text_template[] =
"HICS 206 – STAFF MEDICAL PLAN\n\
1. INCIDENT NAME :1:\n\
2. DATE PREPARED :2:\n\
3. TIME PREPARED :3:\n\
4. OPERATIONAL PERIOD DATE/TIME :4:\n\
5. TREATMENT OF INJURED / STAFF\n\
   Location of Staff Treatment Area :5:<br>\n\
   Contact Information :6:<br>\n\
   Treatment Area Team Leader :7:<br>\n\
   Contact Information :8:<br>\n\
   Special Instructions :9:<br>\n\
6. RESOURCES ON HAND\n\
   STAFF\n\
     MD/DO: :10:\n\
     PA/NP: :14:\n\
     RN/LPN: :18:\n\
     Technicians/CN: :22:\n\
     Ancilliary/Other: :26:\n\
   MEDICAL TRANSPORTATION \n\
     Litters: :11:\n\
     Portable: :15:\n\
     Transport: :19:\n\
     Wheelchairs: :23:\n\
     Other: :27:\n\
   MEDICATION\n\
     :12:\n\
     :16:\n\
     :20:\n\
     :24:\n\
     :28:\n\
   SUPPLIES\n\
     :13:\n\
     :17:\n\
     :21:\n\
     :25:\n\
     :29:\n\
7. ALTERNATE CARE SITE(S)\n\
   NAME:      :30:\n\
   ADDRESS:   :31:\n\
   PHONE:     :32:\n\
   SPEC CARE: :33:\n\
   NAME:      :34:\n\
   ADDRESS:   :35:\n\
   PHONE:     :36:\n\
   SPEC CARE: :37:\n\
   NAME:      :38:\n\
   ADDRESS:   :39:\n\
   PHONE:     :40:\n\
   SPEC CARE: :41:\n\
   NAME:      :42:\n\
   ADDRESS:   :43:\n\
   PHONE:     :44:\n\
   SPEC CARE: :45:\n\
8. PREPARED BY (SUPPORT BRANCH DIRECTOR): :46:\n\
9. FACILITY NAME :47:\n";
