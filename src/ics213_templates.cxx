// =====================================================================
//
// ics213_templates.cxx
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
// ICS213 templates
//======================================================================

const char ics213_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>:TITLE:</title></head><body>\n\
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

