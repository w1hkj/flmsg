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

const char netlog_html_template[] = 
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
  <td colspan=4 ALIGN=CENTER VALIGN=top><b>Net Log</b></td>\
  <td colspan=8 ALIGN=left VALIGN=top>1. Incident name<br>:inc:</td>\
  <td colspan=8 ALIGN=left VALIGN=top>2. Operational Period<br>From: :dfm: :tfm:<br>To: :dto: :tto: </td>\
</tr>\
<tr>\
  <td colspan=10 ALIGN=left VALIGN=top>3. Net Name<br> :net:</td>\
  <td colspan=20 ALIGN=left VALIGN=top>4. Operator (Name, Call Sign)<br>:opr:</td>\
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
      <td colspan=2 VALIGN=top>:tm[00]:</td>\
      <td colspan=4 VALIGN=top>:fm[00]:</td>\
      <td colspan=4 VALIGN=top>:to[00]:</td>\
      <td colspan=10 VALIGN=top>:msg[00]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[01]:</td>\
      <td colspan=4 VALIGN=top>:fm[01]:</td>\
      <td colspan=4 VALIGN=top>:to[01]:</td>\
      <td colspan=10 VALIGN=top>:msg[01]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[02]:</td>\
      <td colspan=4 VALIGN=top>:fm[02]:</td>\
      <td colspan=4 VALIGN=top>:to[02]:</td>\
      <td colspan=10 VALIGN=top>:msg[02]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[03]:</td>\
      <td colspan=4 VALIGN=top>:fm[03]:</td>\
      <td colspan=4 VALIGN=top>:to[03]:</td>\
      <td colspan=10 VALIGN=top>:msg[03]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[04]:</td>\
      <td colspan=4 VALIGN=top>:fm[04]:</td>\
      <td colspan=4 VALIGN=top>:to[04]:</td>\
      <td colspan=10 VALIGN=top>:msg[04]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[05]:</td>\
      <td colspan=4 VALIGN=top>:fm[05]:</td>\
      <td colspan=4 VALIGN=top>:to[05]:</td>\
      <td colspan=10 VALIGN=top>:msg[05]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[06]:</td>\
      <td colspan=4 VALIGN=top>:fm[06]:</td>\
      <td colspan=4 VALIGN=top>:to[06]:</td>\
      <td colspan=10 VALIGN=top>:msg[06]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[07]:</td>\
      <td colspan=4 VALIGN=top>:fm[07]:</td>\
      <td colspan=4 VALIGN=top>:to[07]:</td>\
      <td colspan=10 VALIGN=top>:msg[07]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[08]:</td>\
      <td colspan=4 VALIGN=top>:fm[08]:</td>\
      <td colspan=4 VALIGN=top>:to[08]:</td>\
      <td colspan=10 VALIGN=top>:msg[08]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[09]:</td>\
      <td colspan=4 VALIGN=top>:fm[09]:</td>\
      <td colspan=4 VALIGN=top>:to[09]:</td>\
      <td colspan=10 VALIGN=top>:msg[09]:</td>\
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
      <td colspan=2 VALIGN=top>:tm[34]:</td>\
      <td colspan=4 VALIGN=top>:fm[34]:</td>\
      <td colspan=4 VALIGN=top>:to[34]:</td>\
      <td colspan=10 VALIGN=top>:msg[34]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[35]:</td>\
      <td colspan=4 VALIGN=top>:fm[35]:</td>\
      <td colspan=4 VALIGN=top>:to[35]:</td>\
      <td colspan=10 VALIGN=top>:msg[36]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[36]:</td>\
      <td colspan=4 VALIGN=top>:fm[36]:</td>\
      <td colspan=4 VALIGN=top>:to[36]:</td>\
      <td colspan=10 VALIGN=top>:msg[36]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[37]:</td>\
      <td colspan=4 VALIGN=top>:fm[37]:</td>\
      <td colspan=4 VALIGN=top>:to[37]:</td>\
      <td colspan=10 VALIGN=top>:msg[37]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[38]:</td>\
      <td colspan=4 VALIGN=top>:fm[38]:</td>\
      <td colspan=4 VALIGN=top>:to[38]:</td>\
      <td colspan=10 VALIGN=top>:msg[38]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[39]:</td>\
      <td colspan=4 VALIGN=top>:fm[39]:</td>\
      <td colspan=4 VALIGN=top>:to[39]:</td>\
      <td colspan=10 VALIGN=top>:msg[39]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[40]:</td>\
      <td colspan=4 VALIGN=top>:fm[40]:</td>\
      <td colspan=4 VALIGN=top>:to[40]:</td>\
      <td colspan=10 VALIGN=top>:msg[40]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[41]:</td>\
      <td colspan=4 VALIGN=top>:fm[41]:</td>\
      <td colspan=4 VALIGN=top>:to[41]:</td>\
      <td colspan=10 VALIGN=top>:msg[41]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[42]:</td>\
      <td colspan=4 VALIGN=top>:fm[42]:</td>\
      <td colspan=4 VALIGN=top>:to[42]:</td>\
      <td colspan=10 VALIGN=top>:msg[42]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[43]:</td>\
      <td colspan=4 VALIGN=top>:fm[43]:</td>\
      <td colspan=4 VALIGN=top>:to[43]:</td>\
      <td colspan=10 VALIGN=top>:msg[43]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[44]:</td>\
      <td colspan=4 VALIGN=top>:fm[44]:</td>\
      <td colspan=4 VALIGN=top>:to[44]:</td>\
      <td colspan=10 VALIGN=top>:msg[44]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[45]:</td>\
      <td colspan=4 VALIGN=top>:fm[45]:</td>\
      <td colspan=4 VALIGN=top>:to[45]:</td>\
      <td colspan=10 VALIGN=top>:msg[45]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[46]:</td>\
      <td colspan=4 VALIGN=top>:fm[46]:</td>\
      <td colspan=4 VALIGN=top>:to[46]:</td>\
      <td colspan=10 VALIGN=top>:msg[46]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[47]:</td>\
      <td colspan=4 VALIGN=top>:fm[47]:</td>\
      <td colspan=4 VALIGN=top>:to[47]:</td>\
      <td colspan=10 VALIGN=top>:msg[47]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[48]:</td>\
      <td colspan=4 VALIGN=top>:fm[48]:</td>\
      <td colspan=4 VALIGN=top>:to[48]:</td>\
      <td colspan=10 VALIGN=top>:msg[48]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[49]:</td>\
      <td colspan=4 VALIGN=top>:fm[49]:</td>\
      <td colspan=4 VALIGN=top>:to[49]:</td>\
      <td colspan=10 VALIGN=top>:msg[49]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[50]:</td>\
      <td colspan=4 VALIGN=top>:fm[50]:</td>\
      <td colspan=4 VALIGN=top>:to[50]:</td>\
      <td colspan=10 VALIGN=top>:msg[50]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[51]:</td>\
      <td colspan=4 VALIGN=top>:fm[51]:</td>\
      <td colspan=4 VALIGN=top>:to[51]:</td>\
      <td colspan=10 VALIGN=top>:msg[51]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[52]:</td>\
      <td colspan=4 VALIGN=top>:fm[52]:</td>\
      <td colspan=4 VALIGN=top>:to[52]:</td>\
      <td colspan=10 VALIGN=top>:msg[52]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[53]:</td>\
      <td colspan=4 VALIGN=top>:fm[53]:</td>\
      <td colspan=4 VALIGN=top>:to[53]:</td>\
      <td colspan=10 VALIGN=top>:msg[53]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[54]:</td>\
      <td colspan=4 VALIGN=top>:fm[54]:</td>\
      <td colspan=4 VALIGN=top>:to[54]:</td>\
      <td colspan=10 VALIGN=top>:msg[54]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[55]:</td>\
      <td colspan=4 VALIGN=top>:fm[55]:</td>\
      <td colspan=4 VALIGN=top>:to[55]:</td>\
      <td colspan=10 VALIGN=top>:msg[55]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[56]:</td>\
      <td colspan=4 VALIGN=top>:fm[56]:</td>\
      <td colspan=4 VALIGN=top>:to[56]:</td>\
      <td colspan=10 VALIGN=top>:msg[56]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[57]:</td>\
      <td colspan=4 VALIGN=top>:fm[57]:</td>\
      <td colspan=4 VALIGN=top>:to[57]:</td>\
      <td colspan=10 VALIGN=top>:msg[57]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[58]:</td>\
      <td colspan=4 VALIGN=top>:fm[58]:</td>\
      <td colspan=4 VALIGN=top>:to[58]:</td>\
      <td colspan=10 VALIGN=top>:msg[58]:</td>\
    </tr>\
    <tr>\
      <td colspan=2 VALIGN=top>:tm[59]:</td>\
      <td colspan=4 VALIGN=top>:fm[59]:</td>\
      <td colspan=4 VALIGN=top>:to[59]:</td>\
      <td colspan=10 VALIGN=top>:msg[59]:</td>\
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

const char netlog_text_template[] =
"HAM COMM LOG\n\n\
Incident name: :inc:\n\
Operational Period\n\
  From: :dfm: :tfm:\n\
  To:   :dto: :tto:\n\
Radio Net Name: :net:\n\
Radio Operator: :opr:\n\
Comm Log\n\
line 01: :tm[00]:, :fm[00]:, :to[00]:, :msg[00]:\n\
line 02: :tm[01]:, :fm[01]:, :to[01]:, :msg[01]:\n\
line 03: :tm[02]:, :fm[02]:, :to[02]:, :msg[02]:\n\
line 04: :tm[03]:, :fm[03]:, :to[03]:, :msg[03]:\n\
line 05: :tm[04]:, :fm[04]:, :to[04]:, :msg[04]:\n\
line 06: :tm[05]:, :fm[05]:, :to[05]:, :msg[05]:\n\
line 07: :tm[06]:, :fm[06]:, :to[06]:, :msg[06]:\n\
line 08: :tm[07]:, :fm[07]:, :to[07]:, :msg[07]:\n\
line 09: :tm[08]:, :fm[08]:, :to[08]:, :msg[08]:\n\
line 10: :tm[09]:, :fm[09]:, :to[09]:, :msg[09]:\n\
line 11: :tm[10]:, :fm[10]:, :to[10]:, :msg[10]:\n\
line 12: :tm[11]:, :fm[11]:, :to[11]:, :msg[11]:\n\
line 13: :tm[12]:, :fm[12]:, :to[12]:, :msg[12]:\n\
line 14: :tm[13]:, :fm[13]:, :to[13]:, :msg[13]:\n\
line 15: :tm[14]:, :fm[14]:, :to[14]:, :msg[14]:\n\
line 16: :tm[15]:, :fm[15]:, :to[15]:, :msg[15]:\n\
line 17: :tm[16]:, :fm[16]:, :to[16]:, :msg[16]:\n\
line 18: :tm[17]:, :fm[17]:, :to[17]:, :msg[17]:\n\
line 19: :tm[18]:, :fm[18]:, :to[18]:, :msg[18]:\n\
line 20: :tm[19]:, :fm[19]:, :to[19]:, :msg[19]:\n\
line 21: :tm[20]:, :fm[10]:, :to[20]:, :msg[20]:\n\
line 22: :tm[21]:, :fm[21]:, :to[21]:, :msg[21]:\n\
line 23: :tm[22]:, :fm[22]:, :to[22]:, :msg[22]:\n\
line 24: :tm[23]:, :fm[23]:, :to[23]:, :msg[23]:\n\
line 25: :tm[24]:, :fm[24]:, :to[24]:, :msg[24]:\n\
line 26: :tm[25]:, :fm[25]:, :to[25]:, :msg[25]:\n\
line 27: :tm[26]:, :fm[26]:, :to[26]:, :msg[26]:\n\
line 28: :tm[27]:, :fm[27]:, :to[27]:, :msg[27]:\n\
line 29: :tm[28]:, :fm[28]:, :to[28]:, :msg[28]:\n\
line 30: :tm[29]:, :fm[29]:, :to[29]:, :msg[29]:\n\
line 31: :tm[30]:, :fm[30]:, :to[30]:, :msg[30]:\n\
line 32: :tm[31]:, :fm[31]:, :to[31]:, :msg[31]:\n\
line 33: :tm[32]:, :fm[32]:, :to[32]:, :msg[32]:\n\
line 34: :tm[33]:, :fm[33]:, :to[33]:, :msg[33]:\n\
line 35: :tm[34]:, :fm[34]:, :to[34]:, :msg[34]:\n\
line 36: :tm[35]:, :fm[35]:, :to[35]:, :msg[35]:\n\
line 37: :tm[36]:, :fm[36]:, :to[36]:, :msg[36]:\n\
line 38: :tm[37]:, :fm[37]:, :to[37]:, :msg[37]:\n\
line 39: :tm[38]:, :fm[38]:, :to[38]:, :msg[38]:\n\
line 40: :tm[39]:, :fm[39]:, :to[39]:, :msg[39]:\n\
line 41: :tm[40]:, :fm[40]:, :to[40]:, :msg[40]:\n\
line 42: :tm[41]:, :fm[41]:, :to[41]:, :msg[41]:\n\
line 43: :tm[42]:, :fm[42]:, :to[42]:, :msg[42]:\n\
line 44: :tm[43]:, :fm[43]:, :to[43]:, :msg[43]:\n\
line 45: :tm[44]:, :fm[44]:, :to[44]:, :msg[44]:\n\
line 46: :tm[45]:, :fm[45]:, :to[45]:, :msg[45]:\n\
line 47: :tm[46]:, :fm[46]:, :to[46]:, :msg[46]:\n\
line 48: :tm[47]:, :fm[47]:, :to[47]:, :msg[47]:\n\
line 49: :tm[48]:, :fm[48]:, :to[48]:, :msg[48]:\n\
line 50: :tm[49]:, :fm[49]:, :to[49]:, :msg[49]:\n\
line 51: :tm[40]:, :fm[50]:, :to[50]:, :msg[50]:\n\
line 52: :tm[51]:, :fm[51]:, :to[51]:, :msg[51]:\n\
line 53: :tm[52]:, :fm[52]:, :to[52]:, :msg[52]:\n\
line 54: :tm[53]:, :fm[53]:, :to[53]:, :msg[53]:\n\
line 55: :tm[54]:, :fm[54]:, :to[54]:, :msg[54]:\n\
line 56: :tm[55]:, :fm[55]:, :to[55]:, :msg[55]:\n\
line 57: :tm[56]:, :fm[56]:, :to[56]:, :msg[56]:\n\
line 58: :tm[57]:, :fm[57]:, :to[57]:, :msg[57]:\n\
line 59: :tm[58]:, :fm[58]:, :to[58]:, :msg[58]:\n\
line 60: :tm[59]:, :fm[59]:, :to[59]:, :msg[59]:\n\
Prepared by:   :pre:\n\
Date & Time Prepared: :dtm:\n\
";

