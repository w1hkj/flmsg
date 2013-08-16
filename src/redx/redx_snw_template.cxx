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

const char redx_snw_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\
<html><head>\
<meta http-equiv=\"CONTENT-TYPE\" content=\"text/html; charset=UTF-8\"><title>Red Cross Safe &amp; Well Registry Information Sheet</title>\n\
<meta name=\"GENERATOR\" content=\"OpenOffice.org 3.2(Linux)\">\
<meta name=\"AUTHOR\" content=\"DCC\">\
<meta name=\"CREATED\" content=\"20110906;5060000\">\
<meta name=\"CHANGEDBY\" content=\"DCC\">\
<meta name=\"CHANGED\" content=\"20110906;5070000\">\
<meta name=\"Info 1\" content=\"\">\
<meta name=\"Info 2\" content=\"\">\
<meta name=\"Info 3\" content=\"\">\
<meta name=\"Info 4\" content=\"\">\
<style type=\"text/css\">\
<!--\
@page { margin-right: 0.2in; margin-top: 0.1in; margin-bottom: 0.1in }\
P { margin-bottom: 0.08in; direction: ltr; color: #000000; widows: 2; orphans: 2 }\
P.western { font-family: \"Times New Roman\", \"Serif\"; font-size: 12pt; so-language: en-US }\
P.cjk { font-family: \"Times New Roman\", \"Serif\"; font-size: 12pt }\
P.ctl { font-family: \"Times New Roman\", \"Serif\"; font-size: 12pt; so-language: ar-SA }\
-->\
</style></head><body dir=\"ltr\" lang=\"en-US\" text=\"#000000\">\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"4\" cellspacing=\"0\">\
<tbody>\
<tr align=\"center\">\
<td colspan=\"2\" style=\"vertical-align: top;\"><font face=\"ArialMT,Bold, sans-serif\"><font size=\"5\"><b>Red Cross Safe &amp; Well Registry Information Sheet</b></font></font></td>\
</tr>\
<tr>\
<td style=\"vertical-align: top; width: 50%;\">Last Name: <big>:lname:</big><br>\
</td>\
<td style=\"vertical-align: top;\">First Name: <big>:fname:</big><br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\"><font face=\"ArialMT, sans-serif\">Pre-disaster phone #'s;&nbsp; [:nophone:] no phone number recorded<br>\
</font></td>\
<td style=\"vertical-align: top;\"><big>:area1: - :xchg1: - :suffix1:</big><br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\"><big>:area2: - :xchg2: - :suffix2:</big></td>\
<td style=\"vertical-align: top;\"><big>:area3: - :xchg3: - :suffix3:</big></td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">Pre-disaster home address<br><big>\
:pdline1:<br>\
:pdline2:<br>\
:pdcity:, :pdst:&nbsp; :pdzip:</big><br>\
</td>\
<td style=\"vertical-align: top;\">Current home address<br><big>\
:haline1:<br>\
:haline2:<br>\
:hacity:, :hast:&nbsp; :hazip:</big><br>\
</td>\
</tr>\
<tr>\
<td colspan=\"2\" style=\"vertical-align: top; text-align: center;\"><big><span style=\"font-weight: bold;\">Safe and Well Messages</span></big><br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">[:m1:] I am safe and well.<br>\
</td>\
<td style=\"vertical-align: top;\">[:m8:] Will email when able.<br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">[:m2:] Family and I are safe and well.<br>\
</td>\
<td style=\"vertical-align: top;\">[:m9:] Will mail letter / postcard when able.<br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">[:m3:] Currently at shelter. <br>\
</td>\
<td style=\"vertical-align: top;\">[:m10:] I am safe and in the process of evacuating.<br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">[:m4:] Currently at home.<br>\
</td>\
<td style=\"vertical-align: top;\">[:m11:] I have evacuated and I am safe.<br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">[:m5:] Currently at friend / family / neighbor's.<br>\
</td>\
<td style=\"vertical-align: top;\">[:m12:] I am evacuating to a shelter.<br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">[:m6:] I am evacuating to the house of a family member / friend.<br>\
</td>\
<td style=\"vertical-align: top;\">[:m13:] I am currently at a hotel<br>\
</td>\
</tr>\
<tr>\
<td style=\"vertical-align: top;\">[:m7:] Will make phone call when able.<br>\
</td>\
<td style=\"vertical-align: top;\">[:m14:] I am currently remaining at home<br>\
</td>\
</tr>\
<tr>\
<td colspan=\"2\" style=\"vertical-align: top;\">[:m15:] Custom message<br>\
:cmsg:<br>\
</td>\
</tr>\
</tbody>\
</table>\
<br>\
</body></html>";

const char redx_snw_text_template[] = 
"            Red Cross Safe & Well Registry Information Sheet\n\
\n\
Last Name:                        First Name\n\
:lname:                           :fname:\n\
\n\
Pre-disaster phone #'s\n\
[:nophone:] no phone number recorded\n\
     Phone #1: :area1: - :xchg1: - :suffix1:\n\
     Phone #2: :area2: - :xchg2: - :suffix2:\n\
     Phone #3: :area3: - :xchg3: - :suffix3:\n\
\n\
Pre-disaster home address:\n\
     :pdline1:\n\
     :pdline2:\n\
     :pdcity:, :pdst: :pdzip:\n\
\n\
Current home address:\n\
     :haline1:\n\
     :haline2:\n\
     :hacity:, :hast: :hazip:\n\
\n\
                        Safe and Well Messages\n\
\n\
[:m1:] I am safe and well.\n\
[:m2:] Family and I are safe and well.\n\
[:m3:] Currently at shelter.\n\
[:m4:] Currently at home.\n\
[:m5:] Currently at friend / family / neighbor's.\n\
[:m6:] I am evacuating to the house of a family member / friend.\n\
[:m7:] Will make phone call when able.\n\
[:m8:] Will email when able.\n\
[:m9:] Will mail letter / postcard when able.\n\
[:m10:] I am safe and in the process of evacuating.\n\
[:m11:] I have evacuated and I am safe.\n\
[:m12:] I am evacuating to a shelter.\n\
[:m13:] I am currently at a hotel.\n\
[:m14:] I am currently remaining at home.\n\
[:m15:] Custom message :\n\
:cmsg:\n";


