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
Freq/Tone #2: <freq1:\n\
Assignment #2: <ass1:\n\
Remarks #2: <rem1:\n\
Radio Type/Cache #3: <typ2:\n\
Channel #3: <chn2:\n\
Function #3: <fun2:\n\
Freq/Tone #3: <freq2:\n\
Assignment #3: <ass2:\n\
Remarks #3: <rem2:\n\
Radio Type/Cache #4: <typ3:\n\
Channel #4: <chn3:\n\
Function #4: <fun3:\n\
Freq/Tone #4: <freq3:\n\
Assignment #4: <ass3:\n\
Remarks #4: <rem3:\n\
Radio Type/Cache #5: <typ4:\n\
Channel #5: <chn4:\n\
Function #5: <fun4:\n\
Freq/Tone #5: <freq4:\n\
Assignment #5: <ass4:\n\
Remarks #5: <rem4:\n\
Radio Type/Cache #6: <typ5:\n\
Channel #6: <chn5:\n\
Function #6: <fun5:\n\
Freq/Tone #6: <freq5:\n\
Assignment #6: <ass5:\n\
Remarks #6: <rem5:\n\
Radio Type/Cache #7: <typ6:\n\
Channel #7: <chn6:\n\
Function #7: <fun6:\n\
Freq/Tone #7: <freq6:\n\
Assignment #7: <ass6:\n\
Remarks #7: <rem6:\n\
Radio Type/Cache #8: <typ7:\n\
Channel #8: <chn7:\n\
Function #8: <fun7:\n\
Freq/Tone #8: <freq7:\n\
Assignment #8: <ass7:\n\
Remarks #8: <rem7:\n\
Prepared by: <prp:\n";

//======================================================================
// ICS213 templates
//======================================================================
// ICS213 HTML TEMPLATE
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
