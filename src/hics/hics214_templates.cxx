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

const char hics214_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML>\n\
<HEAD>\n\
<TITLE>HICS-206</TITLE>\n\
<META NAME=\"AUTHOR\" CONTENT=\"w1hkj\">\n\
<META NAME=\"CREATED\" CONTENT=\"20111027\">\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
</STYLE>\n\
</HEAD>\n\
<TABLE WIDTH=100% CELLPADDING=2 CELLSPACING=0 BORDER=1>\n\
<COL WIDTH=14%><COL WIDTH=11%><COL WIDTH=27%><COL WIDTH=48%>\n\
<TR>\n\
<TD COLSPAN=4><p class=F3><B>HICS 214 – OPERATIONAL LOG</B></p></TD>\n\
</TR>\n\
<TR>\n\
<TD COLSPAN=2><F1><B>1. INCIDENT NAME</B><br>:1:</F1></TD>\n\
<TD><F1><B>2. DATE/TIME PREPARED</B><br>:2:</F1></TD>\n\
<TD><F1><B>3. OPERATIONAL PERIOD DATE/TIME</B><br>:3:</F1></TD>\n\
</TR>\n\
<TR>\n\
<TD COLSPAN=2><F1><B>4. SECTION /BRANCH</B><br>:4:</F1></TD>\n\
<TD COLSPAN=2><F1><B>5. POSITION</B><br>:5:</F1></TD>\n\
</TR>\n\
<TR>\n\
<TD COLSPAN=4><p class=F2><B>6. ACTIVITY LOG</B></p></TD>\n\
</TR>\n\
<TR VALIGN=TOP>\n\
<TD><p class=F2><B>Time</B></p></TD>\n\
<TD COLSPAN=3><p class=F2><B>Major Events, Decisions Made, and Notifications Given</B></p></TD>\n\
</TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[00]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[00]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[01]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[01]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[02]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[02]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[03]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[03]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[04]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[04]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[05]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[05]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[06]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[06]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[07]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[07]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[08]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[08]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[09]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[09]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[10]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[10]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[11]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[11]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[12]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[12]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[13]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[13]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[14]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[14]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[15]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[15]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[16]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[16]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[17]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[17]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[18]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[18]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[19]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[19]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[20]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[20]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[21]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[21]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[22]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[22]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[23]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[23]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[24]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[24]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[25]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[25]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[26]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[26]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[27]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[27]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[28]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[28]:<br></p></TD></TR>\n\
<TR VALIGN=TOP><TD><p class=F2>:T[29]:<br></p></TD><TD COLSPAN=3><p class=F2>:E[29]:<br></p></TD></TR>\n\
<TR><TD COLSPAN=4><p class=F2><B>7. Prepared by: </B>:7:</p></TD></TR>\n\
<TR><TD COLSPAN=4><p class=F2><B>8. Facility Name: </B>:8:</p></TD></TR>\n\
</TABLE>\n\
</BODY>\n\
</HTML>\n\
";

const char hics214_text_template[] =
"HICS 214 – OPERATIONAL LOG\n\
1. Incident Name: :1:\n\
2. Date/Time Prepared :2:\n\
3. Operational Period Date/Time :3:\n\
4. Section /Branch :4:\n\
5. Position :5:\n\
6. Activity Log\n\
Major Events, Decisions Made, and Notifications Given</p></TD>\n\\n\
Time: :T[00]:, Event: :E[00]:\n\
Time: :T[01]:, Event: :E[01]:\n\
Time: :T[02]:, Event: :E[02]:\n\
Time: :T[03]:, Event: :E[03]:\n\
Time: :T[04]:, Event: :E[04]:\n\
Time: :T[05]:, Event: :E[05]:\n\
Time: :T[06]:, Event: :E[06]:\n\
Time: :T[07]:, Event: :E[07]:\n\
Time: :T[08]:, Event: :E[08]:\n\
Time: :T[09]:, Event: :E[09]:\n\
Time: :T[10]:, Event: :E[10]:\n\
Time: :T[11]:, Event: :E[11]:\n\
Time: :T[12]:, Event: :E[12]:\n\
Time: :T[13]:, Event: :E[13]:\n\
Time: :T[14]:, Event: :E[14]:\n\
Time: :T[15]:, Event: :E[15]:\n\
Time: :T[16]:, Event: :E[16]:\n\
Time: :T[17]:, Event: :E[17]:\n\
Time: :T[18]:, Event: :E[18]:\n\
Time: :T[19]:, Event: :E[19]:\n\
Time: :T[20]:, Event: :E[20]:\n\
Time: :T[21]:, Event: :E[21]:\n\
Time: :T[22]:, Event: :E[22]:\n\
Time: :T[23]:, Event: :E[23]:\n\
Time: :T[24]:, Event: :E[24]:\n\
Time: :T[25]:, Event: :E[25]:\n\
Time: :T[26]:, Event: :E[26]:\n\
Time: :T[27]:, Event: :E[27]:\n\
Time: :T[28]:, Event: :E[28]:\n\
Time: :T[29]:, Event: :E[29]:\n\
7. Prepared by: :7:\n\
8. Facility Name: :8:\n\
";

