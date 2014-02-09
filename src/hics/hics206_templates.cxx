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

const char hics206_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML>\n\
<HEAD>\n\
<TITLE>HICS-206</TITLE>\n\
<META NAME=\"AUTHOR\" CONTENT=\"w1hkj\">\n\
<META NAME=\"CREATED\" CONTENT=\"20111027\">\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 12pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
</STYLE>\n\
</HEAD>\n\
<BODY>\n\
<TABLE WIDTH=100% cellpadding=\"2\" cellspacing=\"0\" border=\"1\">\n\
<COL WIDTH=18%>\n\
<COL WIDTH=8%>\n\
<COL WIDTH=6%>\n\
<COL WIDTH=18%>\n\
<COL WIDTH=4%>\n\
<COL WIDTH=4%>\n\
<COL WIDTH=10%>\n\
<COL WIDTH=6%>\n\
<COL WIDTH=26%>\n\
<tr>\n\
<td COLSPAN=9><p class=F3>\n\
<b>HICS 206 – STAFF MEDICAL PLAN</b></p>\n\
</td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=3><p class=F2>\n\
<b>1. INCIDENT NAME</b>\n\
<br>:1:\n\
</p>\n\
</td>\n\
<td><p class=F2>\n\
<b>2. DATE PREPARED</b>\n\
<br>:2:\n\
</p>\n\
</td>\n\
<td COLSPAN=3><p class=F2>\n\
<b>3. TIME PREPARED</b>\n\
<br>:3:\n\
</p>\n\
</td>\n\
<td COLSPAN=2><p class=F2>\n\
<b>4. OPERATIONAL PERIOD DATE/TIME</b>\n\
<br>:4:\n\
</p>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9>\n\
<p class=F2>\n\
<b>5. TREATMENT OF INJURED / STAFF</b></p>\n\
</td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=4><p class=F2>\n\
<b>Location of Staff Treatment Area</b>\n\
<br>:5:<br>\n\
</p></td>\n\
<td COLSPAN=5><p class=F2>\n\
<b>Contact Information</b>\n\
<br>:6:<br>\n\
</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=4><p class=F2>\n\
<b>Treatment Area Team Leader</b>\n\
<br>:7:<br>\n\
</p>\n\
</td>\n\
<td COLSPAN=5><p class=F2>\n\
<b>Contact Information</b>\n\
<br>:8:<br>\n\
</p>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><p class=F2>\n\
<b>Special Instructions</b></p>\n\
<pre><p class=F4>:9:</p></pre>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><p class=F2><b>6. RESOURCES ON HAND</b></p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><p class=F2>\n\
<b>STAFF</b>\n\
</p>\n\
</td>\n\
<td COLSPAN=3>\n\
<p class=F2>\n\
<b>MEDICAL TRANSPORTATION </b>\n\
</p>\n\
</td>\n\
<td COLSPAN=3>\n\
<p class=F2>\n\
<b>MEDICATION </b>\n\
</p>\n\
</td>\n\
<td>\n\
<p class=F2>\n\
<b>SUPPLIES</b>\n\
</p>\n\
</td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><p class=F2>MD/DO: :10:</p></td>\n\
<td COLSPAN=3><p class=F2>Litters: :11:</p></td>\n\
<td COLSPAN=3><p class=F2>:12:</p></td>\n\
<td><p class=F2>:13:</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><p class=F2>PA/NP: :14:</p></td>\n\
<td COLSPAN=3><p class=F2>Portable :15:</p></td>\n\
<td COLSPAN=3><p class=F2>:16:</p></td>\n\
<td><p class=F2>:17:</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><p class=F2>RN/LPN: :18:</p></td>\n\
<td COLSPAN=3><p class=F2>Transport: :19:</p></td>\n\
<td COLSPAN=3><p class=F2>:20:</p></td>\n\
<td><p class=F2>:21:</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><p class=F2>Technicians/CN: :22:</p></td>\n\
<td COLSPAN=3><p class=F2>Wheelchairs: :23:</p></td>\n\
<td COLSPAN=3><p class=F2>:24:</p></td>\n\
<td><p class=F2>:25:</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td COLSPAN=2><p class=F2>Ancillary/Other: :26:</p></td>\n\
<td COLSPAN=3><p class=F2>:27:</p></td>\n\
<td COLSPAN=3><p class=F2>:28:</p></td>\n\
<td><p class=F2>:29:</p></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><p class=F2><b>7. ALTERNATE CARE SITE(S)</b></p></td>\n\
</tr>\n\
<tr>\n\
<td ALIGN=CENTER><p class=F2><b>NAME</b></p></td>\n\
<td COLSPAN=5 ALIGN=CENTER><p class=F2><b>ADDRESS</b></p></td>\n\
<td COLSPAN=2 ALIGN=CENTER><p class=F2><b>PHONE</b></p></td>\n\
<td ALIGN=CENTER><p class=F2><b>SPECIALTY CARE</b></p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><p class=F2>:30:<br></p></td>\n\
<td COLSPAN=5><p class=F2>:31:</p></td>\n\
<td COLSPAN=2><p class=F2>:32:</p></td>\n\
<td><p class=F2>:33:</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><p class=F2>:34:<br></p></td>\n\
<td COLSPAN=5><p class=F2>:35:</p></td>\n\
<td COLSPAN=2><p class=F2>:36:</p></td>\n\
<td><p class=F2>:37:</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><p class=F2>:38:<br></p></td>\n\
<td COLSPAN=5><p class=F2>:39:</p></td>\n\
<td COLSPAN=2><p class=F2>:40:</p></td>\n\
<td><p class=F2>:41:</p></td>\n\
</tr>\n\
<tr VALIGN=TOP>\n\
<td><p class=F2>:42:<br></p></td>\n\
<td COLSPAN=5><p class=F2>:43:</p></td>\n\
<td COLSPAN=2><p class=F2>:44:</p></td>\n\
<td><p class=F2>:45:</p></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><p class=F2>\n\
<b>8. PREPARED BY (SUPPORT BRANCH DIRECTOR):</b> :46:\n\
</p>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9><p class=F2>\n\
<b>9. FACILITY NAME</b> :47:\n\
</p>\n\
</td>\n\
</tr>\n\
</TABLE>\n\
</BODY>\n\
</HTML>";

const char hics206_text_template[] =
"HICS 206 – STAFF MEDICAL PLAN\n\
1. INCIDENT NAME :1:\n\
2. DATE PREPARED :2:\n\
3. TIME PREPARED :3:\n\
4. OPERATIONAL PERIOD DATE/TIME :4:\n\
5. TREATMENT OF INJURED / STAFF\n\
   Location of Staff Treatment Area :5:<br>\n\
   Contact Information :6:<br>\n\
   Treatment Area Team Leader :7:<br>\n\
   Contact Information :8:<br>\n\
   Special Instructions :9:<br>\n\
6. RESOURCES ON HAND\n\
   STAFF\n\
     MD/DO: :10:\n\
     PA/NP: :14:\n\
     RN/LPN: :18:\n\
     Technicians/CN: :22:\n\
     Ancilliary/Other: :26:\n\
   MEDICAL TRANSPORTATION \n\
     Litters: :11:\n\
     Portable: :15:\n\
     Transport: :19:\n\
     Wheelchairs: :23:\n\
     Other: :27:\n\
   MEDICATION\n\
     :12:\n\
     :16:\n\
     :20:\n\
     :24:\n\
     :28:\n\
   SUPPLIES\n\
     :13:\n\
     :17:\n\
     :21:\n\
     :25:\n\
     :29:\n\
7. ALTERNATE CARE SITE(S)\n\
   NAME:      :30:\n\
   ADDRESS:   :31:\n\
   PHONE:     :32:\n\
   SPEC CARE: :33:\n\
   NAME:      :34:\n\
   ADDRESS:   :35:\n\
   PHONE:     :36:\n\
   SPEC CARE: :37:\n\
   NAME:      :38:\n\
   ADDRESS:   :39:\n\
   PHONE:     :40:\n\
   SPEC CARE: :41:\n\
   NAME:      :42:\n\
   ADDRESS:   :43:\n\
   PHONE:     :44:\n\
   SPEC CARE: :45:\n\
8. PREPARED BY (SUPPORT BRANCH DIRECTOR): :46:\n\
9. FACILITY NAME :47:\n";
