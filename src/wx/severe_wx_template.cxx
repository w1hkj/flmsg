// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include "templates.h"

const char severe_wx_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html>\n\
<head>\n\
<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">\n\
<title>Flmsg NWS - Severe Wx</title>\n\
</head>\n\
\n\
<body>\n\
<div align=\"center\">\n\
<table style=\"width: 600px; height: 700px;\" border=\"1\" cellpadding=\"4\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td align=\"center\" bgcolor=\"#ffcc99\" valign=\"middle\">\n\
<div align=\"center\">\n\
<strong>'Flmsg' Severe Weather Report</strong>\n\
<font color=\"#ffffff\"></font>\n\
</div>\n\
<font color=\"#ffffff\"></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td class=\"HIGHLIGHT\" valign=\"middle\">\n\
<div align=\"center\">Date &amp; Time</div>\n\
</td>\n\
</tr>\n\
</tbody>\n\
\n\
<tbody>\n\
<tr>\n\
<td class=\"ODD\" valign=\"middle\">\n\
<table style=\"width: 100%;\" border=\"0\" cellpadding=\"2\" cellspacing=\"2\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td>Date</td>\n\
<td>Time</td>\n\
<td style=\"width: 20px; right\">|:not_exact:|</td>\n\
<td><div align=\"left\">Estimated</div></td>\n\
</tr>\n\
<tr align=\"center\">\n\
<td>:date:</td>\n\
<td>:time: :zone:</td>\n\
<td style=\"width: 20px; right\">|:exact:|</td>\n\
<td><div align=\"left\">Exact</div></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td class=\"HIGHLIGHT\" align=\"center\" valign=\"top\">Location</td>\n\
</tr>\n\
<tr>\n\
<td class=\"ODD\" valign=\"top\">\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"2\" width=\"100%\">\n\
<tbody>\n\
<tr>\n\
<td>County, State</td>\n\
<td>City/Town</td>\n\
</tr>\n\
<tr>\n\
<td>:county:, :state:<br></td>\n\
<td>:city:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td class=\"HIGHLIGHT\" align=\"center\" valign=\"top\">Weather<br>\n\
<table style=\"text-align: left; width: 100%;\" \n\
       border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 24px; text-align: center;\">|:tornado:|<br></td>\n\
<td style=\"vertical-align: top;\">Tornado<br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:funnel_cloud:|<br></td>\n\
<td style=\"vertical-align: top;\">Funnel Cloud<br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:wall_cloud:|<br></td>\n\
<td style=\"vertical-align: top;\">Wall Cloud<br></td>\n\
<td style=\"vertical-align: top;\">Note if there is rotation in narrative<br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:hail:|<br></td>\n\
<td style=\"vertical-align: top;\">Hail<br></td>\n\
<td style=\"vertical-align: top;\">\n\
<table style=\"text-align: left; width: 100%;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: right; width: 25%;\">Size:&nbsp;<br></td>\n\
<td style=\"vertical-align: top; text-align: left;\">:hail_size:<br></td>\n\
 </tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:high_wind:|<br></td>\n\
<td style=\"vertical-align: top;\">High Wind<br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top; text-align: center;\">|:measured:|<br></td>\n\
<td style=\"vertical-align: top;\">Measured<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:flood:|<br></td>\n\
<td style=\"vertical-align: top;\">Flood<br></td>\n\
<td style=\"vertical-align: top;\">Speed :speed: MPH</td>\n\
<td style=\"vertical-align: top; text-align: center;\">|:estimated:|<br></td>\n\
<td style=\"vertical-align: top;\">Estimated<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:flash_flood:|<br></td>\n\
<td style=\"vertical-align: top;\">Flash Flood<br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:other:|<br></td>\n\
<td style=\"vertical-align: top;\">Other<br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
<td style=\"vertical-align: top;\"><br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td class=\"HIGHLIGHT\" align=\"center\" valign=\"top\">Damage, Injuries, Narrative</td>\n\
</tr>\n\
<tr>\n\
<td class=\"ODD\" valign=\"top\">\n\
<div align=\"center\">\n\
<table style=\"width: 100%;\" border=\"0\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td align=\"right\">Any Damage?</td>\n\
<td style=\"vertical-align: top; width: 24px; left\">|:dmg_yes:|<br></td>\n\
<td align=\"center; left\">Yes</td>\n\
<td style=\"vertical-align: top; width: 24px; left\">|:dmg_no:|<br></td>\n\
<td align=\"center; left\">No</td>\n\
</tr>\n\
<tr>\n\
<td align=\"right\">Was Anyone Hurt?</td>\n\
<td style=\"vertical-align: top; left\">|:inj_yes:|<br></td>\n\
<td align=\"center; left\">Yes</td>\n\
<td style=\"vertical-align: top; left\">|:inj_no:|<br></td>\n\
<td align=\"center; left\">No</td>\n\
</tr>\n\
</tbody>\n\
</table><br>\n\
Please describe what you observed,movement and any associated damage, including injuries, 2500 characters maximum:\n\
<br><br>\n\
<table style=\"text-align: left; width: 100%; height: 300px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:narrative:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</div>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
\n\
</div><br><br>\n\
<span style=\"color: white; font-size: 9px;\">50.51.5.206</span>\n\
</body>\n\
</html>\n\
";

const char severe_wx_text_template[] = 
"'Flmsg' Severe Weather Report\n\
Date:   :date:\n\
Time:   :time:\n\
Zone:   :zone:\n\
Exact:  :exact:\n\
Not exact: :not_exact:\n\
State:  :state:\n\
County: :county:\n\
City:   :city:\n\
Tornado:       :tornado:\n\
Funnel Cloud:  :funnel_cloud:\n\
Wall Cloud:    :wall_cloud:\n\
Hail:          :hail:\n\
Hail size:     :hail_size:\n\
High wind:     :high_wind:\n\
Wind speed:    :speed:\n\
  Estimated:   :estimated:\n\
  Measured:    :measured:\n\
Flood:         :flood:\n\
Flash flood:   :flash_flood:\n\
Other:         :other:\n\
Damages (yes): :dmg_yes:\n\
Damages (no):  :dmg_no:\n\
Injuries (yes): :inj_yes:\n\
Injuries (no):  :inj_no:\n\
Narrative:\n\
:narrative:\n";

