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

const char ics214_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd>\
<html>\
<head>\
<meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head>\
<body>\
<table ALIGN=left WIDTH=950px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr>\
  <td COLSPAN=2 VALIGN=middle><center><big><b>UNIT LOG</b></big></center></td>\
  <td COLSPAN=2><b>1. Incident name</b><br>:inc:<br></td>\
  <td><b>2.Date Prepared</span></b><br>:dat:<br></td>\
  <td><b>3.Time Prepared</span></b><br>:tim:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=2><b>4. Unit Name / Designatiors</b><br>:und:<br></td>\
  <td COLSPAN=3><b>5. Unit leader (Name and Position)</b><br>:unl:<br></td>\
  <td COLSPAN=1><b>6. Operational Period</b><br>:opp:<br></td>\
<tr><td COLSPAN=6><center><b>7. Personnel Roster Assigned</b></center></td></tr>\
<tr>\
  <td COLSPAN=2><center><b>Name</b></center></td>\
  <td COLSPAN=2><center><b>ICS Position</b></center></td>\
  <td COLSPAN=2><center><b>Home Base</b></center></td>\
</tr>\
<tr><td COLSPAN=2>:nam[0]:</td><td COLSPAN=2>:pos[0]:</td><td COLSPAN=2>:hom[0]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[1]:</td><td COLSPAN=2>:pos[1]:</td><td COLSPAN=2>:hom[1]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[2]:</td><td COLSPAN=2>:pos[2]:</td><td COLSPAN=2>:hom[2]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[3]:</td><td COLSPAN=2>:pos[3]:</td><td COLSPAN=2>:hom[3]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[4]:</td><td COLSPAN=2>:pos[4]:</td><td COLSPAN=2>:hom[4]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[5]:</td><td COLSPAN=2>:pos[5]:</td><td COLSPAN=2>:hom[5]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[6]:</td><td COLSPAN=2>:pos[6]:</td><td COLSPAN=2>:hom[6]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[7]:</td><td COLSPAN=2>:pos[7]:</td><td COLSPAN=2>:hom[7]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[8]:</td><td COLSPAN=2>:pos[8]:</td><td COLSPAN=2>:hom[8]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[9]:</td><td COLSPAN=2>:pos[9]:</td><td COLSPAN=2>:hom[9]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[10]:</td><td COLSPAN=2>:pos[10]:</td><td COLSPAN=2>:hom[10]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[11]:</td><td COLSPAN=2>:pos[11]:</td><td COLSPAN=2>:hom[11]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[12]:</td><td COLSPAN=2>:pos[12]:</td><td COLSPAN=2>:hom[12]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[13]:</td><td COLSPAN=2>:pos[13]:</td><td COLSPAN=2>:hom[13]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[14]:</td><td COLSPAN=2>:pos[14]:</td><td COLSPAN=2>:hom[14]:<br></td></tr>\
<tr><td COLSPAN=2>:nam[15]:</td><td COLSPAN=2>:pos[15]:</td><td COLSPAN=2>:hom[15]:<br></td></tr>\
<tr><td COLSPAN=6><center><b>8. Activity Log</b></center></td></tr>\
<tr><td COLSPAN=1><center><b>Time</b></center></td><td COLSPAN=5><center><b>Major Events</b></center></td></tr>\
<tr><td COLSPAN=1>:at[0]:</td><td COLSPAN=5>:ev[0]:<br></td></tr>\
<tr><td COLSPAN=1>:at[1]:</td><td COLSPAN=5>:ev[1]:<br></td></tr>\
<tr><td COLSPAN=1>:at[2]:</td><td COLSPAN=5>:ev[2]:<br></td></tr>\
<tr><td COLSPAN=1>:at[3]:</td><td COLSPAN=5>:ev[3]:<br></td></tr>\
<tr><td COLSPAN=1>:at[4]:</td><td COLSPAN=5>:ev[4]:<br></td></tr>\
<tr><td COLSPAN=1>:at[5]:</td><td COLSPAN=5>:ev[5]:<br></td></tr>\
<tr><td COLSPAN=1>:at[6]:</td><td COLSPAN=5>:ev[6]:<br></td></tr>\
<tr><td COLSPAN=1>:at[7]:</td><td COLSPAN=5>:ev[7]:<br></td></tr>\
<tr><td COLSPAN=1>:at[8]:</td><td COLSPAN=5>:ev[8]:<br></td></tr>\
<tr><td COLSPAN=1>:at[9]:</td><td COLSPAN=5>:ev[9]:<br></td></tr>\
<tr><td COLSPAN=1>:at[10]:</td><td COLSPAN=5>:ev[10]:<br></td></tr>\
<tr><td COLSPAN=1>:at[11]:</td><td COLSPAN=5>:ev[11]:<br></td></tr>\
<tr><td COLSPAN=1>:at[12]:</td><td COLSPAN=5>:ev[12]:<br></td></tr>\
<tr><td COLSPAN=1>:at[13]:</td><td COLSPAN=5>:ev[13]:<br></td></tr>\
<tr><td COLSPAN=1>:at[14]:</td><td COLSPAN=5>:ev[14]:<br></td></tr>\
<tr><td COLSPAN=1>:at[15]:</td><td COLSPAN=5>:ev[15]:<br></td></tr>\
<tr><td COLSPAN=6><b>9. Prepared by (Name and Position)</b><br>:pre:<br></td></tr>\
<tr>\
  <td VALIGN=top WIDTH=16% HEIGHT=24px>ICS-214</td>\
  <td VALIGN=top WIDTH=16% HEIGHT=24px></td>\
  <td VALIGN=top WIDTH=16% HEIGHT=24px></td>\
  <td VALIGN=top WIDTH=16% HEIGHT=24px></td>\
  <td VALIGN=top WIDTH=16% HEIGHT=24px></td>\
  <td VALIGN=top WIDTH=17% HEIGHT=24px></td>\
</tr>\
</tbody>\
</table>\
</body>\
</html>";

const char ics214_text_template[] =
"ICS 214 UNIT LOG\n\n\
Incident name: :inc:\n\
Date Prepared: :dat:\n\
Time Prepared: :tim:\n\
Personnel Roster Assigned\n\
line 0: :nam[0]:, :pos[0]:, :hom[0]:\n\
line 1: :nam[1]:, :pos[1]:, :hom[1]:\n\
line 2: :nam[2]:, :pos[2]:, :hom[2]:\n\
line 3: :nam[3]:, :pos[3]:, :hom[3]:\n\
line 4: :nam[4]:, :pos[4]:, :hom[4]:\n\
line 5: :nam[5]:, :pos[5]:, :hom[5]:\n\
line 6: :nam[6]:, :pos[6]:, :hom[6]:\n\
line 7: :nam[7]:, :pos[7]:, :hom[7]:\n\
line 8: :nam[8]:, :pos[8]:, :hom[8]:\n\
line 9: :nam[9]:, :pos[9]:, :hom[9]:\n\
line 10: :nam[10]:, :pos[10]:, :hom[10]:\n\
line 11: :nam[11]:, :pos[11]:, :hom[11]:\n\
line 12: :nam[12]:, :pos[12]:, :hom[12]:\n\
line 13: :nam[13]:, :pos[13]:, :hom[13]:\n\
line 14: :nam[14]:, :pos[14]:, :hom[14]:\n\
line 15: :nam[15]:, :pos[15]:, :hom[15]:\n\
Activity Log\n\
line 0: :at[0], :ev[0]:\n\
line 1: :at[1], :ev[1]:\n\
line 2: :at[2], :ev[2]:\n\
line 3: :at[3], :ev[3]:\n\
line 4: :at[4], :ev[4]:\n\
line 5: :at[5], :ev[5]:\n\
line 6: :at[6], :ev[6]:\n\
line 7: :at[7], :ev[7]:\n\
line 8: :at[8], :ev[8]:\n\
line 9: :at[9], :ev[9]:\n\
line 10: :at[10], :ev[10]:\n\
line 11: :at[11], :ev[11]:\n\
line 12: :at[12], :ev[12]:\n\
line 13: :at[13], :ev[13]:\n\
line 14: :at[14], :ev[14]:\n\
line 15: :at[15], :ev[15]:\n\
Prepared by: :pre:\n\
";

