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

const char storm_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html>\n\
<head>\n\
<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">\n\
<title>Flmsg NWS - Storm Report</title>\n\
</head>\n\
\n\
<body>\n\
<div align=\"center\">\n\
<table style=\"width: 600px;\" border=\"1\" cellpadding=\"4\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td align=\"center\" bgcolor=\"#ffcc99\" valign=\"middle\">\n\
<div align=\"center\"><b>'Flmsg' Storm Report</b></div>\n\
</td>\n\
</tr>\n\
\n\
<tr>\n\
<td class=\"ODD\" valign=\"middle\">\n\
<table style=\"width: 100%;\" border=\"0\" cellpadding=\"2\" cellspacing=\"2\">\n\
<tbody>\n\
<tr align=\"left\">\n\
<td style=\"left;width: 25%\">Event Time</td><td style=\"left;width: 25%\">:time: :zone:</td>\n\
<td style=\"left;width: 25%\">Event Date</td><td style=\"left;width: 25%\">:date:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
\n\
<tr>\n\
<td class=\"HIGHLIGHT\" align=\"center\" valign=\"top\">Event Location<br><br>\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"2\" width=\"100%\">\n\
<tbody>\n\
<tr align=\"left\">\n\
<td style=\"left;width: 25%\">County</td><td>:county:, :state:</td>\n\
</tr>\n\
<tr align=\"left\">\n\
<td>Location</td><td>:location:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
\n\
<tr>\n\
<td class=\"HIGHLIGHT\" align=\"left\" valign=\"top\">Event Type<br><br>\n\
<table style=\"text-align: left; width: 100%;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:flood:|<br></td>\n\
<td style=\"vertical-align: top;\">Flood<br></td>\n\
<td style=\"vertical-align: top;\">:flood_cat:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:hail:|<br></td>\n\
<td style=\"vertical-align: top;\">Hail<br></td>\n\
<td style=\"vertical-align: top;\">:hail_size:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:high_wind:|<br></td>\n\
<td style=\"vertical-align: top;\">High Wind Speed<br></td>\n\
<td style=\"vertical-align: top;\">:speed:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:tornado:|<br></td>\n\
<td style=\"vertical-align: top;\">Tornado/Funnel Cloud<br></td>\n\
<td style=\"vertical-align: top;\">:tornado_cat:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:damage:|<br></td>\n\
<td style=\"vertical-align: top;\">Wind Damage<br></td>\n\
<td style=\"vertical-align: top;\">:damage_cat:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:snow:|<br></td>\n\
<td style=\"vertical-align: top;\">Snow<br></td>\n\
<td style=\"vertical-align: top;\">:snow_tot:</td>\n\
<td style=\"vertical-align: top;\">:snow_dur:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:f_rain:|<br></td>\n\
<td style=\"vertical-align: top;\">Freezing Rain/Icing<br></td>\n\
<td style=\"vertical-align: top;\">:f_rain_tot:</td>\n\
<td style=\"vertical-align: top;\">:f_rain_dur:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">|:h_rain:|<br></td>\n\
<td style=\"vertical-align: top;\">Heavy Rain<br></td>\n\
<td style=\"vertical-align: top;\">:h_rain_tot:</td>\n\
<td style=\"vertical-align: top;\">:h_rain_dur:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
\n\
<table style=\"width: 600px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td>\n\
<table style=\"width: 100%;\" border=\"0\" cellpadding=\"2\" cellspacing=\"0\"><tbody>\n\
<tr>\n\
<td>Additional Details<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">:details:</td>\n\
</tr>\n\
</tbody></table>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
\n\
<table style=\"width: 600px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td>Contact Information</td>\n\
</tr>\n\
<tr>\n\
<td>\n\
<table style=\"width: 100%;\" border=\"0\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;width: 25%\">Your Name:<br></td>\n\
<td style=\"vertical-align: top;\">:o_name:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">E-mail address:<br></td>\n\
<td style=\"vertical-align: top;\">:o_email:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Phone Number:<br></td>\n\
<td style=\"vertical-align: top;\">:o_tele:</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">Observer Profile:<br></td>\n\
<td style=\"vertical-align: top;\">:o_profile:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
\n\
</body>\n\
</html>\n\
";

const char storm_text_template[] = 
"'Flmsg' Storm Report\n\n\
Date.....................:date:\n\
Time.....................:time:\n\
Zone.....................:zone:\n\
State....................:state:\n\
County...................:county:\n\
location.................:location:\n\n\
Flood....................:flood:\n\
Flood Cat................:flood_cat:\n\
Hail.....................:hail:\n\
Hail size................:hail_size:\n\
High wind................:high_wind:\n\
Wind speed...............:speed:\n\
Tornado..................:tornado:\n\
Tornado Cat..............:tornado_cat:\n\
Wind damage..............:damage:\n\
Wind damage cat..........:damage_cat:\n\
Snow.....................:snow:\n\
Snow total...............:snow_tot:\n\
Snow duration............:snow_dur:\n\
Freezing rain/ice........:f_rain:\n\
Freezing rain/ice total..:f_rain_tot:\n\
Freezing rain/ice dura...:f_rain_dur:\n\
Heavy rain...............:h_rain:\n\
Heavy rain total.........:h_rain_tot:\n\
Heavy rain dura..........:h_rain_dur:\n\
Observer name............:o_name:\n\
Observer email...........:o_email:\n\
Observer tele............:o_tele:\n\
Observer profile.........:o_profile:\n\
Additional Details:\n\
:details:\n";
