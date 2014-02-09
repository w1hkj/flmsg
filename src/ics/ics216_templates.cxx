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

const char ics216_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html><head>\
<meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table ALIGN=left WIDTH=1600px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr>\
  <td COLSPAN=5 VALIGN=middle><big><center><b>RADIO REQUIREMENTS WORKSHEET</b></center></big></td>\
  <td COLSPAN=5><b>1. Incident name</b><br>:inc:<br></td>\
  <td COLSPAN=3><b>2.Date Prepared</span></b><br>:dat:<br></td>\
  <td COLSPAN=3><b>3.Time Prepared</span></b><br>:tim:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=4><b>4. Branch</b><br>:br:<br></td>\
  <td COLSPAN=4><b>5. Agency</b><br>:agc:<br></td>\
  <td COLSPAN=4><b>6. Operational Period</b><br>:opp:<br></td>\
  <td COLSPAN=4><b>7. Tactical Frequency</b><br>:tfr:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=4><b>8. Division/Group</b><br>:div[0]:<br></td>\
  <td COLSPAN=4><b>Division/Group</b><br>:div[1]:<br></td>\
  <td COLSPAN=4><b>Division/Group</b><br>:div[2]:<br></td>\
  <td COLSPAN=4><b>Division/Group</b><br>:div[3]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=4><b>Agency</b><br>:agy[0]:<br></td>\
  <td COLSPAN=4><b>Agency</b><br>:agy[1]:<br></td>\
  <td COLSPAN=4><b>Agency</b><br>:agy[2]:<br></td>\
  <td COLSPAN=4><b>Agency</b><br>:agy[3]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1><b>9. Agency</b></td>\
  <td COLSPAN=1><center><b>ID No.</b></center></td>\
  <td COLSPAN=2><center><b>Radio Requirements</b></center></td>\
  <td COLSPAN=1><center><b>Agency</b></center></td>\
  <td COLSPAN=1><center><b>ID No.</b></center></td>\
  <td COLSPAN=2><center><b>Radio Requirements</b></center></td>\
  <td COLSPAN=1><center><b>Agency</b></center></td>\
  <td COLSPAN=1><center><b>ID No.</b></center></td>\
  <td COLSPAN=2><center><b>Radio Requirements</b></center></td>\
  <td COLSPAN=1><center><b>Agency</b></center></td>\
  <td COLSPAN=1><center><b>ID No.</b></center></td>\
  <td COLSPAN=2><center><b>Radio Requirements</b></center></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[0]:<br></td>\
  <td COLSPAN=1>:id[0]:<br></td>\
  <td COLSPAN=2>:rr[0]:<br></td>\
  <td COLSPAN=1>:ag[9]:<br></td>\
  <td COLSPAN=1>:id[9]:<br></td>\
  <td COLSPAN=2>:rr[9]:<br></td>\
  <td COLSPAN=1>:ag[18]:<br></td>\
  <td COLSPAN=1>:id[18]:<br></td>\
  <td COLSPAN=2>:rr[18]:<br></td>\
  <td COLSPAN=1>:ag[27]:<br></td>\
  <td COLSPAN=1>:id[27]:<br></td>\
  <td COLSPAN=2>:rr[27]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[1]:<br></td>\
  <td COLSPAN=1>:id[1]:<br></td>\
  <td COLSPAN=2>:rr[1]:<br></td>\
  <td COLSPAN=1>:ag[10]:<br></td>\
  <td COLSPAN=1>:id[10]:<br></td>\
  <td COLSPAN=2>:rr[10]:<br></td>\
  <td COLSPAN=1>:ag[19]:<br></td>\
  <td COLSPAN=1>:id[19]:<br></td>\
  <td COLSPAN=2>:rr[19]:<br></td>\
  <td COLSPAN=1>:ag[28]:<br></td>\
  <td COLSPAN=1>:id[28]:<br></td>\
  <td COLSPAN=2>:rr[28]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[2]:<br></td>\
  <td COLSPAN=1>:id[2]:<br></td>\
  <td COLSPAN=2>:rr[2]:<br></td>\
  <td COLSPAN=1>:ag[11]:<br></td>\
  <td COLSPAN=1>:id[11]:<br></td>\
  <td COLSPAN=2>:rr[11]:<br></td>\
  <td COLSPAN=1>:ag[20]:<br></td>\
  <td COLSPAN=1>:id[20]:<br></td>\
  <td COLSPAN=2>:rr[20]:<br></td>\
  <td COLSPAN=1>:ag[29]:<br></td>\
  <td COLSPAN=1>:id[29]:<br></td>\
  <td COLSPAN=2>:rr[29]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[3]:<br></td>\
  <td COLSPAN=1>:id[3]:<br></td>\
  <td COLSPAN=2>:rr[3]:<br></td>\
  <td COLSPAN=1>:ag[12]:<br></td>\
  <td COLSPAN=1>:id[12]:<br></td>\
  <td COLSPAN=2>:rr[12]:<br></td>\
  <td COLSPAN=1>:ag[21]:<br></td>\
  <td COLSPAN=1>:id[21]:<br></td>\
  <td COLSPAN=2>:rr[21]:<br></td>\
  <td COLSPAN=1>:ag[30]:<br></td>\
  <td COLSPAN=1>:id[30]:<br></td>\
  <td COLSPAN=2>:rr[30]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[4]:<br></td>\
  <td COLSPAN=1>:id[4]:<br></td>\
  <td COLSPAN=2>:rr[4]:<br></td>\
  <td COLSPAN=1>:ag[13]:<br></td>\
  <td COLSPAN=1>:id[13]:<br></td>\
  <td COLSPAN=2>:rr[13]:<br></td>\
  <td COLSPAN=1>:ag[22]:<br></td>\
  <td COLSPAN=1>:id[22]:<br></td>\
  <td COLSPAN=2>:rr[22]:<br></td>\
  <td COLSPAN=1>:ag[31]:<br></td>\
  <td COLSPAN=1>:id[31]:<br></td>\
  <td COLSPAN=2>:rr[31]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[5]:<br></td>\
  <td COLSPAN=1>:id[5]:<br></td>\
  <td COLSPAN=2>:rr[5]:<br></td>\
  <td COLSPAN=1>:ag[14]:<br></td>\
  <td COLSPAN=1>:id[14]:<br></td>\
  <td COLSPAN=2>:rr[14]:<br></td>\
  <td COLSPAN=1>:ag[23]:<br></td>\
  <td COLSPAN=1>:id[23]:<br></td>\
  <td COLSPAN=2>:rr[23]:<br></td>\
  <td COLSPAN=1>:ag[32]:<br></td>\
  <td COLSPAN=1>:id[32]:<br></td>\
  <td COLSPAN=2>:rr[32]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[6]:<br></td>\
  <td COLSPAN=1>:id[6]:<br></td>\
  <td COLSPAN=2>:rr[6]:<br></td>\
  <td COLSPAN=1>:ag[15]:<br></td>\
  <td COLSPAN=1>:id[15]:<br></td>\
  <td COLSPAN=2>:rr[15]:<br></td>\
  <td COLSPAN=1>:ag[24]:<br></td>\
  <td COLSPAN=1>:id[24]:<br></td>\
  <td COLSPAN=2>:rr[24]:<br></td>\
  <td COLSPAN=1>:ag[33]:<br></td>\
  <td COLSPAN=1>:id[33]:<br></td>\
  <td COLSPAN=2>:rr[33]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[7]:<br></td>\
  <td COLSPAN=1>:id[7]:<br></td>\
  <td COLSPAN=2>:rr[7]:<br></td>\
  <td COLSPAN=1>:ag[16]:<br></td>\
  <td COLSPAN=1>:id[16]:<br></td>\
  <td COLSPAN=2>:rr[16]:<br></td>\
  <td COLSPAN=1>:ag[25]:<br></td>\
  <td COLSPAN=1>:id[25]:<br></td>\
  <td COLSPAN=2>:rr[25]:<br></td>\
  <td COLSPAN=1>:ag[34]:<br></td>\
  <td COLSPAN=1>:id[34]:<br></td>\
  <td COLSPAN=2>:rr[34]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=1>:ag[8]:<br></td>\
  <td COLSPAN=1>:id[8]:<br></td>\
  <td COLSPAN=2>:rr[8]:<br></td>\
  <td COLSPAN=1>:ag[17]:<br></td>\
  <td COLSPAN=1>:id[17]:<br></td>\
  <td COLSPAN=2>:rr[17]:<br></td>\
  <td COLSPAN=1>:ag[26]:<br></td>\
  <td COLSPAN=1>:id[26]:<br></td>\
  <td COLSPAN=2>:rr[26]:<br></td>\
  <td COLSPAN=1>:ag[35]:<br></td>\
  <td COLSPAN=1>:id[35]:<br></td>\
  <td COLSPAN=2>:rr[35]:<br></td>\
</tr>\
<tr>\
  <td COLSPAN=4><center><b>Page __ of __</b></center></td>\
  <td COLSPAN=12><b>10. Prepared by (Name and Position)</b><br>:pre:<br></td>\
</tr>\
<tr>\
  <td VALIGN=center WIDTH=100px HEIGHT=20px>ICS-216</td>\
  <td></td><td></td><td></td><td></td><td></td><td></td>\
  <td></td><td></td><td></td><td></td><td></td><td></td>\
  <td></td><td></td><td></td>\
</tr>\
</tbody>\
</table>\
</body></html>";


const char ics216_text_template[] =
"ICS 216 RADIO REQUIREMENTS WORKSHEET\n\n\
1.  Incident name:      :inc:\n\
2.  Date Prepared:      :dat:\n\
3.  Time Prepared:      :tim:\n\
4.  Branch:             :br:\n\
5.  Agency:             :agc:\n\
6.  Operational Period: :opp:\n\
7.  Tactical Frequency: :tfr:\n\
8. Division/Group:      :div[0]:\n\
   Agency:              :agy[0]:\n\
   Division/Group       :div[1]:\n\
   Agency               :div[2]:\n\
   Division/Group       :div[3]:\n\
   Abency:              :agy[1]:\n\
   Division/Group       :agy[2]:\n\
   Agency:              :agy[3]:\n\
9. Agency / ID / Radio Requirements\n\
   :ag[0]: / :id[0]:/ :rr[0]:\n\
   :ag[1]: / :id[1]:/ :rr[1]:\n\
   :ag[2]: / :id[2]:/ :rr[2]:\n\
   :ag[3]: / :id[3]:/ :rr[3]:\n\
   :ag[4]: / :id[4]:/ :rr[4]:\n\
   :ag[5]: / :id[5]:/ :rr[5]:\n\
   :ag[6]: / :id[6]:/ :rr[6]:\n\
   :ag[7]: / :id[7]:/ :rr[7]:\n\
   :ag[8]: / :id[8]:/ :rr[8]:\n\
   :ag[9]: / :id[9]:/ :rr[9]:\n\
   :ag[10]: / :id[10]:/ :rr[10]:\n\
   :ag[11]: / :id[11]:/ :rr[11]:\n\
   :ag[12]: / :id[12]:/ :rr[12]:\n\
   :ag[13]: / :id[13]:/ :rr[13]:\n\
   :ag[14]: / :id[14]:/ :rr[14]:\n\
   :ag[15]: / :id[15]:/ :rr[15]:\n\
   :ag[16]: / :id[16]:/ :rr[16]:\n\
   :ag[17]: / :id[17]:/ :rr[17]:\n\
   :ag[18]: / :id[18]:/ :rr[18]:\n\
   :ag[19]: / :id[19]:/ :rr[19]:\n\
   :ag[20]: / :id[20]:/ :rr[20]:\n\
   :ag[21]: / :id[21]:/ :rr[21]:\n\
   :ag[22]: / :id[22]:/ :rr[22]:\n\
   :ag[23]: / :id[23]:/ :rr[23]:\n\
   :ag[24]: / :id[24]:/ :rr[24]:\n\
   :ag[25]: / :id[25]:/ :rr[25]:\n\
   :ag[26]: / :id[26]:/ :rr[26]:\n\
   :ag[27]: / :id[27]:/ :rr[27]:\n\
   :ag[28]: / :id[28]:/ :rr[28]:\n\
   :ag[29]: / :id[29]:/ :rr[29]:\n\
   :ag[30]: / :id[30]:/ :rr[30]:\n\
   :ag[31]: / :id[31]:/ :rr[31]:\n\
   :ag[32]: / :id[32]:/ :rr[32]:\n\
   :ag[33]: / :id[33]:/ :rr[33]:\n\
   :ag[34]: / :id[34]:/ :rr[34]:\n\
   :ag[35]: / :id[35]:/ :rr[35]:\n\
10. Prepared by:        :pre:\n\
";

