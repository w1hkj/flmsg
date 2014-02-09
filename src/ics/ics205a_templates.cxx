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

const char ics205a_html_template[] = 
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html>\n\
<head>\n\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n\
<title>:TITLE:</title>\n\
</head>\n\
<body>\n\
<table width=950px border=1 cellpadding=1 cellspacing=0>\n\
<tbody>\n\
<tr>\
  <td colspan=7 ALIGN=left VALIGN=top><b>1. Incident name</b><br>:inc:</td>\
  <td colspan=4 ALIGN=left VALIGN=top><b>2.From:</b><br>:dfm:  :tfm:</td>\
  <td colspan=4 ALIGN=left VALIGN=top><b>3.To:  </b><br>:dto:  :tto:</td>\
  <td colspan=5 ALIGN=right VALIGN=top  BGCOLOR=#EEFFFF><b>COMMUNICATIONS LIST<br>(ICS-205A)</b></td>\
</tr>\
    <tr BGCOLOR=#EEFFFF>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
      <td WIDTH=5% HEIGHT= 0></td><td WIDTH=5% HEIGHT= 0></td>\
    </tr>\
    <tr>\
      <td colspan=20 ALIGN=left VALIGN=top>\
      <b>4. Basic Local Communications Info</b>\
      </td>\
    </tr>\
    <tr>\
      <td colspan=6 ALIGN=center VALIGN=top><br><b>Assignment</b></td>\
      <td colspan=6 ALIGN=center VALIGN=top><b><br>Name</b><br></td>\
      <td colspan=8 ALIGN=center VALIGN=top>\
      <b>Methods of Contact</b><br>(radio frequency, phone, pager, cell, etc.)</b>\
      </td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[0]:</td>\
      <td colspan=6 VALIGN=top>:nam[0]:</td>\
      <td colspan=8 VALIGN=top>:inf[0]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[1]:</td>\
      <td colspan=6 VALIGN=top>:nam[1]:</td>\
      <td colspan=8 VALIGN=top>:inf[1]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[2]:</td>\
      <td colspan=6 VALIGN=top>:nam[2]:</td>\
      <td colspan=8 VALIGN=top>:inf[2]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[3]:</td>\
      <td colspan=6 VALIGN=top>:nam[3]:</td>\
      <td colspan=8 VALIGN=top>:inf[3]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[4]:</td>\
      <td colspan=6 VALIGN=top>:nam[4]:</td>\
      <td colspan=8 VALIGN=top>:inf[4]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[5]:</td>\
      <td colspan=6 VALIGN=top>:nam[5]:</td>\
      <td colspan=8 VALIGN=top>:inf[5]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[6]:</td>\
      <td colspan=6 VALIGN=top>:nam[6]:</td>\
      <td colspan=8 VALIGN=top>:inf[6]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[7]:</td>\
      <td colspan=6 VALIGN=top>:nam[7]:</td>\
      <td colspan=8 VALIGN=top>:inf[7]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[8]:</td>\
      <td colspan=6 VALIGN=top>:nam[8]:</td>\
      <td colspan=8 VALIGN=top>:inf[8]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[9]:</td>\
      <td colspan=6 VALIGN=top>:nam[9]:</td>\
      <td colspan=8 VALIGN=top>:inf[9]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[10]:</td>\
      <td colspan=6 VALIGN=top>:nam[10]:</td>\
      <td colspan=8 VALIGN=top>:inf[10]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[11]:</td>\
      <td colspan=6 VALIGN=top>:nam[11]:</td>\
      <td colspan=8 VALIGN=top>:inf[11]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[12]:</td>\
      <td colspan=6 VALIGN=top>:nam[12]:</td>\
      <td colspan=8 VALIGN=top>:inf[12]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[13]:</td>\
      <td colspan=6 VALIGN=top>:nam[13]:</td>\
      <td colspan=8 VALIGN=top>:inf[13]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[14]:</td>\
      <td colspan=6 VALIGN=top>:nam[14]:</td>\
      <td colspan=8 VALIGN=top>:inf[14]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[15]:</td>\
      <td colspan=6 VALIGN=top>:nam[15]:</td>\
      <td colspan=8 VALIGN=top>:inf[15]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[16]:</td>\
      <td colspan=6 VALIGN=top>:nam[16]:</td>\
      <td colspan=8 VALIGN=top>:inf[16]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[17]:</td>\
      <td colspan=6 VALIGN=top>:nam[17]:</td>\
      <td colspan=8 VALIGN=top>:inf[17]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[18]:</td>\
      <td colspan=6 VALIGN=top>:nam[18]:</td>\
      <td colspan=8 VALIGN=top>:inf[18]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[19]:</td>\
      <td colspan=6 VALIGN=top>:nam[19]:</td>\
      <td colspan=8 VALIGN=top>:inf[19]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[20]:</td>\
      <td colspan=6 VALIGN=top>:nam[20]:</td>\
      <td colspan=8 VALIGN=top>:inf[20]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[21]:</td>\
      <td colspan=6 VALIGN=top>:nam[21]:</td>\
      <td colspan=8 VALIGN=top>:inf[21]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[22]:</td>\
      <td colspan=6 VALIGN=top>:nam[22]:</td>\
      <td colspan=8 VALIGN=top>:inf[22]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[23]:</td>\
      <td colspan=6 VALIGN=top>:nam[23]:</td>\
      <td colspan=8 VALIGN=top>:inf[23]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[24]:</td>\
      <td colspan=6 VALIGN=top>:nam[24]:</td>\
      <td colspan=8 VALIGN=top>:inf[24]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[25]:</td>\
      <td colspan=6 VALIGN=top>:nam[25]:</td>\
      <td colspan=8 VALIGN=top>:inf[25]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[26]:</td>\
      <td colspan=6 VALIGN=top>:nam[26]:</td>\
      <td colspan=8 VALIGN=top>:inf[26]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[27]:</td>\
      <td colspan=6 VALIGN=top>:nam[27]:</td>\
      <td colspan=8 VALIGN=top>:inf[27]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[28]:</td>\
      <td colspan=6 VALIGN=top>:nam[28]:</td>\
      <td colspan=8 VALIGN=top>:inf[28]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[29]:</td>\
      <td colspan=6 VALIGN=top>:nam[29]:</td>\
      <td colspan=8 VALIGN=top>:inf[29]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[30]:</td>\
      <td colspan=6 VALIGN=top>:nam[30]:</td>\
      <td colspan=8 VALIGN=top>:inf[30]:</td>\
    </tr>\
    <tr>\
      <td colspan=6 VALIGN=top>:asg[31]:</td>\
      <td colspan=6 VALIGN=top>:nam[31]:</td>\
      <td colspan=8 VALIGN=top>:inf[31]:</td>\
    </tr>\
    <tr>\
      <td colspan=8 VALIGN=top>5. Prepared by:<br>:pre:</td>\
      <td colspan=6 VALIGN=top>Position/Title:<br>:pos:</td>\
      <td colspan=6 VALIGN=top>Date time:<br>:dtm:</td>\
    </tr>\
    <tr>\
      <td colspan=4 ALIGN=center VALIGN=middle>ICS-205A</td>\
      <td colspan=4 VALIGN=top>IAP Page</td>\
      <td colspan=12 VALIGN=top>Signature:<br><br></td>\
    </tr>\
</tbody>\
</table>\
</body></html>\
";

const char ics205a_text_template[] =
"ICS 205a UNIT LOG\n\n\
Incident name: :inc:\n\
Date Prepared: :dat:\n\
Time Prepared: :tim:\n\
Prepared by:   :pre:\n\
Preparer position: :pos:\n\
Preparer date time: :dtm:\n\
Comm Group Information\n\
line 0: :asg[0]:, :nam[0]:, :inf[0]:\n\
line 1: :asg[1]:, :nam[1]:, :inf[1]:\n\
line 2: :asg[2]:, :nam[2]:, :inf[2]:\n\
line 3: :asg[3]:, :nam[3]:, :inf[3]:\n\
line 4: :asg[4]:, :nam[4]:, :inf[4]:\n\
line 5: :asg[5]:, :nam[5]:, :inf[5]:\n\
line 6: :asg[6]:, :nam[6]:, :inf[6]:\n\
line 7: :asg[7]:, :nam[7]:, :inf[7]:\n\
line 8: :asg[8]:, :nam[8]:, :inf[8]:\n\
line 9: :asg[9]:, :nam[9]:, :inf[9]:\n\
line 10: :asg[10]:, :nam[10]:, :inf[10]:\n\
line 11: :asg[11]:, :nam[11]:, :inf[11]:\n\
line 12: :asg[12]:, :nam[12]:, :inf[12]:\n\
line 13: :asg[13]:, :nam[13]:, :inf[13]:\n\
line 14: :asg[14]:, :nam[14]:, :inf[14]:\n\
line 15: :asg[15]:, :nam[15]:, :inf[15]:\n\
line 16: :asg[16]:, :nam[16]:, :inf[16]:\n\
line 17: :asg[17]:, :nam[17]:, :inf[17]:\n\
line 18: :asg[18]:, :nam[18]:, :inf[18]:\n\
line 19: :asg[19]:, :nam[19]:, :inf[19]:\n\
line 20: :asg[20]:, :nam[20]:, :inf[20]:\n\
line 21: :asg[21]:, :nam[21]:, :inf[21]:\n\
line 22: :asg[22]:, :nam[22]:, :inf[22]:\n\
line 23: :asg[23]:, :nam[23]:, :inf[23]:\n\
line 24: :asg[24]:, :nam[24]:, :inf[24]:\n\
line 25: :asg[25]:, :nam[25]:, :inf[25]:\n\
line 26: :asg[26]:, :nam[26]:, :inf[26]:\n\
line 27: :asg[27]:, :nam[27]:, :inf[27]:\n\
line 28: :asg[28]:, :nam[28]:, :inf[28]:\n\
line 29: :asg[29]:, :nam[29]:, :inf[29]:\n\
line 30: :asg[30]:, :nam[30]:, :inf[30]:\n\
line 31: :asg[31]:, :nam[31]:, :inf[31]:\n\
";

