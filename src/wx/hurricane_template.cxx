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

const char wxhc_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head>\n\
<meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\n\
<title>Hurricane Wx Report</title>\n\
</head>\n\
<body>\n\
<center>\n\
<table style=\"text-align: left; width: 80%;\" border=0 cellpadding=0 cellspacing=0>\n\
<tbody>\n\
<tr><td COLSPAN=\"2\"><H2><center>Hurricane Weather Report Form</center></H2></td></tr>\n\
<tr><td COLSPAN=\"2\"><hr width=\"80%\"></td></tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left; width: 25%\">Reporting Station</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:rptsta:</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Email Address</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:email:</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Phone Number</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:phone:</td>\n\
</tr>\n\
<tr><td COLSPAN=\"2\"><hr width=\"80%\"></td></tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\" COLSPAN=\"2\">Geographic Location</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Address</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:addr:</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">City</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:city:</td>\n\
</tr>\n\
<tr>\n\
   <td style=\"vertical-align: top; text-align: left;\">State</td>\n\
   <td style=\"vertical-align: top; text-align: left;\">:state:</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Country</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:country:</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Location (Lat/Lon)</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:lat: Degrees North : :long: Degrees West</td>\n\
</tr>\n\
<tr><td COLSPAN=\"2\"><hr width=\"80%\"></td></tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Date</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:date: (month-day-year)</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Time of observation</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:time:</td>\n\
</tr>\n\
<tr><td COLSPAN=\"2\"><hr width=\"80%\"></td></tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Wind measurements</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">[:meas:] Measured,   [:est:] Estimated</td>\n\
</tr>\n\
<tr><td COLSPAN=\"2\"><br></td></tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Sustained Wind Speed</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:wspd: :wsunits:</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Gust speed</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:wgst: :wgunits:</td>\n\
</tr>\n\
<tr>\n\
   <td style=\"vertical-align: top; text-align: left;\">Wind Direction</td>\n\
   <td style=\"vertical-align: top; text-align: left;\">:wdir:, :wdeg: Degrees</td>\n\
</tr>\n\
<tr><td COLSPAN=\"2\"><hr width=\"80%\"></td></tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\">Barometric pressure</td>\n\
  <td style=\"vertical-align: top; text-align: left;\">:baro: :bunits:</td>\n\
</tr>\n\
<tr><td COLSPAN=\"2\"><hr width=\"80%\"></td></tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\" COLSPAN=\"2\">Comments:</td>\n\
</tr>\n\
<tr>\n\
  <td style=\"vertical-align: top; text-align: left;\" COLSPAN=\"2\"><p>:cmmts:</p></td>\n\
</tr>\n\
</td>\n\
</tbody>\n\
</table>\n\
</center>\n\
</body>\n\
</html>\n\
";


const char wxhc_text_template[] = 
"            Hurricane Weather Report Form\n\
Reporting Station:    :rptsta:\n\
Email Address :       :email:\n\
Phone Number:         :phone:\n\
\n\
Geographic Location:\n\
Address:              :addr:\n\
City:                 :city:  State: :state:\n\
Country:              :country:\n\
\n\
Location (Lat/Lon):   :lat: Degrees North :long: Degrees West\n\
Date:                 :date: (month-day-year)\n\
Time of observation:  :time:\n\
\n\
Wind measurements are:\n\
[:meas:] Measured,   [:est:] Estimated\n\
\n\
Sustained Wind Speed: :wspd: :wsunits:\n\
\n\
Gust speed:           :wgst: :wgunits:\n\
\n\
Wind Direction:       :wdir:, :wdeg: Degrees\n\
\n\
Barometric pressure:  :baro: :bunits:\n\
\n\
Comments:\n\
:cmmts:\n";

