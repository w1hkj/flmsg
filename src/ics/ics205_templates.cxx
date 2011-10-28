// =====================================================================
//
// ics205_templates.cxx
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
// ics205 form template
//======================================================================

#include "templates.h"

const char ics205_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head>\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head>\
<body>\
<table ALIGN=left WIDTH=1000px border=1 cellpadding=2 cellspacing=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=2 VALIGN=top WIDTH=250px><b>INCIDENT RADIO<br>COMMUNICATIONS PLAN</b></td>\
<td COLSPAN=2 VALIGN=top WIDTH=250px>\
 <div ALIGN=left>1. Incident Name<br></div><div ALIGN=left>:nam:</div>\
</td>\
<td VALIGN=top ALIGN=left WIDTH=250px>2. Date/Time Prepared<br>:dt1:</td>\
<td VALIGN=top ALIGN=left WIDTH=250px>3. Operational Period Date/Time<br>:dt2:</td>\
</tr>\
</tbody>\
</table>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=6 VALIGN=top>4. Basic Radio Channel Utilization<br></td>\
</tr>\
<tr ALIGN=center>\
<td VALIGN=top WIDTH=125px>System<br>Cache</td>\
<td VALIGN=top WIDTH=125px>Channel<br></td>\
<td VALIGN=top WIDTH=125px>Function<br></td>\
<td VALIGN=top WIDTH=125px>Frequency<br>Tone<br></td>\
<td VALIGN=top WIDTH=250px>Assignment<br></td>\
<td VALIGN=top WIDTH=250px>Remarks<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ0:<br></td>\
<td VALIGN=top>:chn0:<br></td>\
<td VALIGN=top>:fun0:<br></td>\
<td VALIGN=top>:frq0:<br></td>\
<td VALIGN=top>:ass0:<br></td>\
<td VALIGN=top>:rem0:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ1:<br></td>\
<td VALIGN=top>:chn1:<br></td>\
<td VALIGN=top>:fun1:<br></td>\
<td VALIGN=top>:frq1:<br></td>\
<td VALIGN=top>:ass1:<br></td>\
<td VALIGN=top>:rem1:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ2:<br></td>\
<td VALIGN=top>:chn2:<br></td>\
<td VALIGN=top>:fun2:<br></td>\
<td VALIGN=top>:frq2:<br></td>\
<td VALIGN=top>:ass2:<br></td>\
<td VALIGN=top>:rem2:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ3:<br></td>\
<td VALIGN=top>:chn3:<br></td>\
<td VALIGN=top>:fun3:<br></td>\
<td VALIGN=top>:frq3:<br></td>\
<td VALIGN=top>:ass3:<br></td>\
<td VALIGN=top>:rem3:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ4:<br></td>\
<td VALIGN=top>:chn4:<br></td>\
<td VALIGN=top>:fun4:<br></td>\
<td VALIGN=top>:frq4:<br></td>\
<td VALIGN=top>:ass4:<br></td>\
<td VALIGN=top>:rem4:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ5:<br></td>\
<td VALIGN=top>:chn5:<br></td>\
<td VALIGN=top>:fun5:<br></td>\
<td VALIGN=top>:frq5:<br></td>\
<td VALIGN=top>:ass5:<br></td>\
<td VALIGN=top>:rem5:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ6:<br></td>\
<td VALIGN=top>:chn6:<br></td>\
<td VALIGN=top>:fun6:<br></td>\
<td VALIGN=top>:frq6:<br></td>\
<td VALIGN=top>:ass6:<br></td>\
<td VALIGN=top>:rem6:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:typ7:<br></td>\
<td VALIGN=top>:chn7:<br></td>\
<td VALIGN=top>:fun7:<br></td>\
<td VALIGN=top>:frq7:<br></td>\
<td VALIGN=top>:ass7:<br></td>\
<td VALIGN=top>:rem7:<br></td>\
</tr>\
<tr>\
<td COLSPAN=6 VALIGN=top>5. Prepared by (Communications unit)<br>:prp:</td>\
</tr>\
</tbody>\
</table>\
</body>\
</html>";

const char ics205_text_template[] =
"ICS 205 INCIDENT RADIO COMMUNICATIONS PLAN\n\n\
Incident name: :nam:\n\
Date/Time Prepared: :dt1:\n\
Operational Period Date/Time: :dt2:\n\
System/Cache #1: :typ0:\n\
Channel #1: :chn0:\n\
Function #1: :fun0:\n\
Freq/Tone #1: :freq0:\n\
Assignment #1: :ass0:\n\
Remarks #1: :rem0:\n\
System/Cache #2: :typ1:\n\
Channel #2: :chn1:\n\
Function #2: :fun1:\n\
Freq/Tone #2: :frq1:\n\
Assignment #2: :ass1:\n\
Remarks #2: :rem1:\n\
System/Cache #3: :typ2:\n\
Channel #3: :chn2:\n\
Function #3: :fun2:\n\
Freq/Tone #3: :frq2:\n\
Assignment #3: :ass2:\n\
Remarks #3: :rem2:\n\
System/Cache #4: :typ3:\n\
Channel #4: :chn3:\n\
Function #4: :fun3:\n\
Freq/Tone #4: :frq3:\n\
Assignment #4: :ass3:\n\
Remarks #4: :rem3:\n\
System/Cache #5: :typ4:\n\
Channel #5: :chn4:\n\
Function #5: :fun4:\n\
Freq/Tone #5: :frq4:\n\
Assignment #5: :ass4:\n\
Remarks #5: :rem4:\n\
System/Cache #6: :typ5:\n\
Channel #6: :chn5:\n\
Function #6: :fun5:\n\
Freq/Tone #6: :frq5:\n\
Assignment #6: :ass5:\n\
Remarks #6: :rem5:\n\
System/Cache #7: :typ6:\n\
Channel #7: :chn6:\n\
Function #7: :fun6:\n\
Freq/Tone #7: :frq6:\n\
Assignment #7: :ass6:\n\
Remarks #7: :rem6:\n\
System/Cache #8: :typ7:\n\
Channel #8: :chn7:\n\
Function #8: :fun7:\n\
Freq/Tone #8: :frq7:\n\
Assignment #8: :ass7:\n\
Remarks #8: :rem7:\n\
Prepared by (Communications unit): :prp:\n";

