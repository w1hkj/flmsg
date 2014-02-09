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

const char ics309_html_template[] = 
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
  <td colspan=4 ALIGN=CENTER VALIGN=top><b>COMM Log</b><br>ICS309<br>ARES/RACES</td>\
  <td colspan=8 ALIGN=left VALIGN=top>1. Incident name<br>:inc:</td>\
  <td colspan=8 ALIGN=left VALIGN=top>2. Operational Period<br>From: :dfm: :tfm:<br>To: :dto: :tto: </td>\
</tr>\
<tr>\
  <td colspan=10 ALIGN=left VALIGN=top>3. Radio Net Name or Position/Tactical Call<br> :net:</td>\
  <td colspan=20 ALIGN=left VALIGN=top>4. Radio Operator (Name, Call Sign)<br>:opr:</td>\
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
      <td colspan=2 ALIGN=left VALIGN=top>5.\
      <td colspan=19 ALIGN=center VALIGN=top>\
      <b>COMMUNICATIONS LOG</b>\
      </td>\
    </tr>\
    <tr>\
      <td colspan=2 ALIGN=center VALIGN=top>Time<br>(24:00)</td>\
      <td colspan=4 ALIGN=center VALIGN=top>FROM<br>Call Sign/ID   Msg #</td>\
      <td colspan=4 ALIGN=center VALIGN=top>TO<br>Call Sign/ID   Msg #</td>\
      <td colspan=10 ALIGN=left VALIGN=center>Message</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[0]:</td>\
      <td colspan=4 VALIGN=top>:fm[0]:</td>\
      <td colspan=4 VALIGN=top>:to[0]:</td>\
      <td colspan=10 VALIGN=top>:msg[0]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[1]:</td>\
      <td colspan=4 VALIGN=top>:fm[1]:</td>\
      <td colspan=4 VALIGN=top>:to[1]:</td>\
      <td colspan=10 VALIGN=top>:msg[1]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[2]:</td>\
      <td colspan=4 VALIGN=top>:fm[2]:</td>\
      <td colspan=4 VALIGN=top>:to[2]:</td>\
      <td colspan=10 VALIGN=top>:msg[2]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[3]:</td>\
      <td colspan=4 VALIGN=top>:fm[3]:</td>\
      <td colspan=4 VALIGN=top>:to[3]:</td>\
      <td colspan=10 VALIGN=top>:msg[3]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[4]:</td>\
      <td colspan=4 VALIGN=top>:fm[4]:</td>\
      <td colspan=4 VALIGN=top>:to[4]:</td>\
      <td colspan=10 VALIGN=top>:msg[4]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[5]:</td>\
      <td colspan=4 VALIGN=top>:fm[5]:</td>\
      <td colspan=4 VALIGN=top>:to[5]:</td>\
      <td colspan=10 VALIGN=top>:msg[5]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[6]:</td>\
      <td colspan=4 VALIGN=top>:fm[6]:</td>\
      <td colspan=4 VALIGN=top>:to[6]:</td>\
      <td colspan=10 VALIGN=top>:msg[6]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[7]:</td>\
      <td colspan=4 VALIGN=top>:fm[7]:</td>\
      <td colspan=4 VALIGN=top>:to[7]:</td>\
      <td colspan=10 VALIGN=top>:msg[7]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[8]:</td>\
      <td colspan=4 VALIGN=top>:fm[8]:</td>\
      <td colspan=4 VALIGN=top>:to[8]:</td>\
      <td colspan=10 VALIGN=top>:msg[8]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[9]:</td>\
      <td colspan=4 VALIGN=top>:fm[9]:</td>\
      <td colspan=4 VALIGN=top>:to[9]:</td>\
      <td colspan=10 VALIGN=top>:msg[9]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[10]:</td>\
      <td colspan=4 VALIGN=top>:fm[10]:</td>\
      <td colspan=4 VALIGN=top>:to[10]:</td>\
      <td colspan=10 VALIGN=top>:msg[10]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[11]:</td>\
      <td colspan=4 VALIGN=top>:fm[11]:</td>\
      <td colspan=4 VALIGN=top>:to[11]:</td>\
      <td colspan=10 VALIGN=top>:msg[11]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[12]:</td>\
      <td colspan=4 VALIGN=top>:fm[12]:</td>\
      <td colspan=4 VALIGN=top>:to[12]:</td>\
      <td colspan=10 VALIGN=top>:msg[12]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[13]:</td>\
      <td colspan=4 VALIGN=top>:fm[13]:</td>\
      <td colspan=4 VALIGN=top>:to[13]:</td>\
      <td colspan=10 VALIGN=top>:msg[13]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[14]:</td>\
      <td colspan=4 VALIGN=top>:fm[14]:</td>\
      <td colspan=4 VALIGN=top>:to[14]:</td>\
      <td colspan=10 VALIGN=top>:msg[14]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[15]:</td>\
      <td colspan=4 VALIGN=top>:fm[15]:</td>\
      <td colspan=4 VALIGN=top>:to[15]:</td>\
      <td colspan=10 VALIGN=top>:msg[15]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[16]:</td>\
      <td colspan=4 VALIGN=top>:fm[16]:</td>\
      <td colspan=4 VALIGN=top>:to[16]:</td>\
      <td colspan=10 VALIGN=top>:msg[16]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[17]:</td>\
      <td colspan=4 VALIGN=top>:fm[17]:</td>\
      <td colspan=4 VALIGN=top>:to[17]:</td>\
      <td colspan=10 VALIGN=top>:msg[17]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[18]:</td>\
      <td colspan=4 VALIGN=top>:fm[18]:</td>\
      <td colspan=4 VALIGN=top>:to[18]:</td>\
      <td colspan=10 VALIGN=top>:msg[18]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[19]:</td>\
      <td colspan=4 VALIGN=top>:fm[19]:</td>\
      <td colspan=4 VALIGN=top>:to[19]:</td>\
      <td colspan=10 VALIGN=top>:msg[19]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[20]:</td>\
      <td colspan=4 VALIGN=top>:fm[20]:</td>\
      <td colspan=4 VALIGN=top>:to[20]:</td>\
      <td colspan=10 VALIGN=top>:msg[20]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[21]:</td>\
      <td colspan=4 VALIGN=top>:fm[21]:</td>\
      <td colspan=4 VALIGN=top>:to[21]:</td>\
      <td colspan=10 VALIGN=top>:msg[21]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[22]:</td>\
      <td colspan=4 VALIGN=top>:fm[22]:</td>\
      <td colspan=4 VALIGN=top>:to[22]:</td>\
      <td colspan=10 VALIGN=top>:msg[22]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[23]:</td>\
      <td colspan=4 VALIGN=top>:fm[23]:</td>\
      <td colspan=4 VALIGN=top>:to[23]:</td>\
      <td colspan=10 VALIGN=top>:msg[23]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[24]:</td>\
      <td colspan=4 VALIGN=top>:fm[24]:</td>\
      <td colspan=4 VALIGN=top>:to[24]:</td>\
      <td colspan=10 VALIGN=top>:msg[24]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[25]:</td>\
      <td colspan=4 VALIGN=top>:fm[25]:</td>\
      <td colspan=4 VALIGN=top>:to[25]:</td>\
      <td colspan=10 VALIGN=top>:msg[25]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[26]:</td>\
      <td colspan=4 VALIGN=top>:fm[26]:</td>\
      <td colspan=4 VALIGN=top>:to[26]:</td>\
      <td colspan=10 VALIGN=top>:msg[26]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[27]:</td>\
      <td colspan=4 VALIGN=top>:fm[27]:</td>\
      <td colspan=4 VALIGN=top>:to[27]:</td>\
      <td colspan=10 VALIGN=top>:msg[27]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[28]:</td>\
      <td colspan=4 VALIGN=top>:fm[28]:</td>\
      <td colspan=4 VALIGN=top>:to[28]:</td>\
      <td colspan=10 VALIGN=top>:msg[28]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[29]:</td>\
      <td colspan=4 VALIGN=top>:fm[29]:</td>\
      <td colspan=4 VALIGN=top>:to[29]:</td>\
      <td colspan=10 VALIGN=top>:msg[29]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[30]:</td>\
      <td colspan=4 VALIGN=top>:fm[30]:</td>\
      <td colspan=4 VALIGN=top>:to[30]:</td>\
      <td colspan=10 VALIGN=top>:msg[30]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[31]:</td>\
      <td colspan=4 VALIGN=top>:fm[31]:</td>\
      <td colspan=4 VALIGN=top>:to[31]:</td>\
      <td colspan=10 VALIGN=top>:msg[31]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[32]:</td>\
      <td colspan=4 VALIGN=top>:fm[32]:</td>\
      <td colspan=4 VALIGN=top>:to[32]:</td>\
      <td colspan=10 VALIGN=top>:msg[32]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[33]:</td>\
      <td colspan=4 VALIGN=top>:fm[33]:</td>\
      <td colspan=4 VALIGN=top>:to[33]:</td>\
      <td colspan=10 VALIGN=top>:msg[33]:</td>\
    </tr>\
    <tr>\
      <td colspan=7 VALIGN=top>6. Prepared by<br>:pre:</td>\
      <td colspan=7 VALIGN=top>7. Date & Time Prepared<br>:dtm:</td>\
      <td colspan=6 VALIGN=top>8.<br> Page __1__of __1__</td>\
    </tr>\
</tbody>\
</table>\
</body></html>\
";

const char ics309_text_template[] =
"ICS 309 COMM LOG\n\n\
Incident name: :inc:\n\
Operational Period\n\
  From: :dfm: :tfm:\n\
  To:   :dto: :tto:\n\
Radio Net Name: :net:\n\
Radio Operator: :opr:\n\
Comm Log\n\
line 0: :tm[0]:, :fm[0]:, :to[0]:, :msg[0]:\n\
line 0: :tm[1]:, :fm[1]:, :to[1]:, :msg[1]:\n\
line 0: :tm[2]:, :fm[2]:, :to[2]:, :msg[2]:\n\
line 0: :tm[3]:, :fm[3]:, :to[3]:, :msg[3]:\n\
line 0: :tm[4]:, :fm[4]:, :to[4]:, :msg[4]:\n\
line 0: :tm[5]:, :fm[5]:, :to[5]:, :msg[5]:\n\
line 0: :tm[6]:, :fm[6]:, :to[6]:, :msg[6]:\n\
line 0: :tm[7]:, :fm[7]:, :to[7]:, :msg[7]:\n\
line 0: :tm[8]:, :fm[8]:, :to[8]:, :msg[8]:\n\
line 0: :tm[9]:, :fm[9]:, :to[9]:, :msg[9]:\n\
line 0: :tm[10]:, :fm[10]:, :to[10]:, :msg[10]:\n\
line 0: :tm[11]:, :fm[11]:, :to[11]:, :msg[11]:\n\
line 0: :tm[12]:, :fm[12]:, :to[12]:, :msg[12]:\n\
line 0: :tm[13]:, :fm[13]:, :to[13]:, :msg[13]:\n\
line 0: :tm[14]:, :fm[14]:, :to[14]:, :msg[14]:\n\
line 0: :tm[15]:, :fm[15]:, :to[15]:, :msg[15]:\n\
line 0: :tm[16]:, :fm[16]:, :to[16]:, :msg[16]:\n\
line 0: :tm[17]:, :fm[17]:, :to[17]:, :msg[17]:\n\
line 0: :tm[18]:, :fm[18]:, :to[18]:, :msg[18]:\n\
line 0: :tm[19]:, :fm[19]:, :to[19]:, :msg[19]:\n\
line 0: :tm[20]:, :fm[10]:, :to[20]:, :msg[20]:\n\
line 0: :tm[21]:, :fm[21]:, :to[21]:, :msg[21]:\n\
line 0: :tm[22]:, :fm[22]:, :to[22]:, :msg[22]:\n\
line 0: :tm[23]:, :fm[23]:, :to[23]:, :msg[23]:\n\
line 0: :tm[24]:, :fm[24]:, :to[24]:, :msg[24]:\n\
line 0: :tm[25]:, :fm[25]:, :to[25]:, :msg[25]:\n\
line 0: :tm[26]:, :fm[26]:, :to[26]:, :msg[26]:\n\
line 0: :tm[27]:, :fm[27]:, :to[27]:, :msg[27]:\n\
line 0: :tm[28]:, :fm[28]:, :to[28]:, :msg[28]:\n\
line 0: :tm[29]:, :fm[29]:, :to[29]:, :msg[29]:\n\
line 0: :tm[30]:, :fm[30]:, :to[30]:, :msg[30]:\n\
line 0: :tm[31]:, :fm[31]:, :to[31]:, :msg[31]:\n\
line 0: :tm[32]:, :fm[32]:, :to[32]:, :msg[32]:\n\
Prepared by:   :pre:\n\
Date & Time Prepared: :dtm:\n\
";

