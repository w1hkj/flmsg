// =====================================================================
//
// hics213_templates.cxx
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
// HICS213 templates
//======================================================================

#include "templates.h"

const char hics213_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<html><head><meta http-equiv=\"CONTENT-TYPE\" content=\"text/html; charset=utf-8\"><title>HICS-213</title><meta name=\"AUTHOR\" content=\"w1hkj\"><meta name=\"CREATED\" content=\"20111028\"><style>\n\
F2{font-family: \"sans-serif\"; font-size: 10pt}\n\
F3{font-family: \"sans-serif\"; font-size: 14pt}\n\
F4{font-family: \"monospace\"; font-size: 12pt}\n\
</style></head><body>\"\n\
<table border=\"1\" cellpadding=\"2\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"16%\"><col width=\"16%\"><col width=\"16%\"><col width=\"52%\">\n\
<tbody><tr valign=\"top\">\n\
<td colspan=\"4\"><f3><b>HICS-213 – INCIDENT MESSAGE FORM</b></f3></td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td colspan=\"3\"><f2><b>1. FROM (Sender):</b><br>:1:</f2></td>\n\
<td><f2><b>2. TO (Receiver):</b><br>:2:</f2></td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td><f2><b>3. DATE RECEIVED</b></f2></td>\n\
<td><f2><b>4. TIME RECEIVED</b></f2></td>\n\
<td><f2><b>5. RECEIVED VIA</b></f2></td>\n\
<td><f2><b>6. REPLY REQUESTED:</b></f2></td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td><f2>:3:</f2></td>\n\
<td><f2>:4:</f2></td>\n\
<td>\n\
<table border=\"0\" cellpadding=\"1\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<tr>\n\
<td><b><center>:5a:</center></b></td><td>Phone</td>\n\
<td><b><center>:5b:</center></b></td><td>Radio</td>\n\
</tr>\n\
</table>\n\
</td>\n\
<td>\n\
<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"20%\">\n\
<col width=\"5%\"><col width=\"15%\">\n\
<col width=\"5%\"><col width=\"15%\">\n\
<col width=40%>\n\
<tr><td><f2>Reply</f2></td>\n\
<td><f2><b> :6a:</b></f2></td><td><f2>Yes</f2></td>\n\
<td><f2><b> :6b:</b></f2></td><td><f2>No</f2></td>\n\
</tr>\n\
</table>\n\
</td></tr>\n\
<tr valign=\"top\">\n\
<td colspan=\"2\"><br>\n\
</td>\n\
<td>\n\
<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<tr>\n\
<td><b><center>:5c:</center></b></td><td>Other</td>\n\
</tr>\n\
</table>\n\
</td>\n\
<td><f2><b>If NO, REPLY TO:</b> :6c:</f2></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"2\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"15%\">\n\
<col width=\"3%\"><col width=\"20%\">\n\
<col width=\"3%\"><col width=\"20%\">\n\
<col width=\"3%\"><col width=\"20%\">\n\
<col width=\"16%\">\n\
<tbody><tr>\n\
<td><f2><b>7. PRIORITY</b></f2></td>\n\
<td><f2><b><center>:7a:</center></b></f2></td> <td><f2>Urgent - High</f2></td>\n\
<td><f2><b><center>:7b:</center></b></f2></td> <td><f2>Non Urgent – Medium</f2></td>\n\
<td><f2><b><center>:7c:</center></b></f2></td> <td><f2>Informational - Low</f2></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<tbody><tr>\n\
<td><f2><b>8. MESSAGE</b> (KEEP ALL MESSAGES / REQUESTS BRIEF, TO THE POINT, AND VERY SPECIFIC):</f2>\n\
<br><f4></f4><pre>:8:<br><br><br></pre></td>\n\
</tr>\n\
<tr>\n\
<td><f2><b>9. ACTION TAKEN</b> (if any):<br></f2><br>\n\
<f4></f4><pre>:9:<br><br><br></pre></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"30%\"><col width=\"20%\"><col width=\"50%\"><tbody>\n\
<tr valign=\"top\">\n\
<td><f2><b>Received by:</b></f2></td>\n\
<td><f2><b>Time Recveived:</b></f2></td>\n\
<td><f2><b>Forward to:</b></f2></td>\n\
</tr>\n\
<tr>\n\
<td><f2>:10:<br></f2></td>\n\
<td><f2>:11:</f2></td>\n\
<td><f2>:12:</f2></td>\n\
</tr>\n\
<tr><td colspan=\"3\"><f2><b>Comments:</b><br>\n\
<f4></f4></f2><pre>:13:<br><br><br></pre></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"30%\"><col width=\"20%\"><col width=\"50%\"><tbody>\n\
<tr valign=\"top\">\n\
<td><f2><b>Received by:</b></f2></td>\n\
<td><f2><b>Time Recveived:</b></f2></td>\n\
<td><f2><b>Forward to:</b></f2></td>\n\
</tr>\n\
<tr>\n\
<td><f2>:14:<br></f2></td>\n\
<td><f2>:15:</f2></td>\n\
<td><f2>:16:</f2></td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\"><f2><b>Comments:</b><br>\n\
<f4></f4></f2><pre> :17:<br><br><br></pre></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<tbody><tr>\n\
<td><f2><b>10. FACILITY NAME</b><br> :18:<br><br><br></f2></td>\n\
</tr>\n\
</tbody></table>\n\
\n\
</body></html>\n\
";

const char hics213_text_template[] =
"1. FROM (Sender): :1:\n\
2. TO (Receiver): :2:\n\
3. DATE RECEIVED: :3:\n\
4. TIME RECEIVED: :4:\n\
5a. RECEIVED via PHONE: :5a:\n\
5b. RECEIVED via RADIO: :5b:\n\
5b. RECEIVED via OTHER: :5c:\n\
6a. REPLY REQUESTED YES: :6a:\n\
6b. REPLY REQUESTED NO: :6b:\n\
7. PRIORITY high: :7a:, medium: :7b:, low: :7c:\n\
8. MESSAGE: :8:\n\
9. ACTION TAKEN: :9:\n\
10. Received by: :10:\n\
11. Time Recveived: :11:\n\
12. Forward to: :12:\n\
13. Comments: :13:\n\
14. Received by: : 13:\n\
15. Time Recveived: :15:\n\
16. Forward to: :16:\n\
17. Comments: :17:\n\
18. FACILITY NAME :18:\n";
