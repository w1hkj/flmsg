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

const char ics213_text_template[] = \
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
const char rg_html_template[] = \
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

const char rg_txt_template[] = \
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

const char pt_txt_template[] = \
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

const char blank_txt_template[] = \
"<mg:";
