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

const char ics206_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head>\
<meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head>\
<body>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=2 VALIGN=middle WIDTH=200px><b>MEDICAL PLAN</b></td>\
<td VALIGN=top WIDTH=200px ALIGN=left>1. Incident Name</span><br>:nam:<br></td>\
<td COLSPAN=2 VALIGN=top WIDTH=200px>\
<div ALIGN=left>2. Date Prepared<br></div>\
<div ALIGN=left>:dat:</div>\
</td>\
<td VALIGN=top ALIGN=left WIDTH=200px>3. Time Prepared<br>:tim:</td>\
<td VALIGN=top ALIGN=left WIDTH=200px>4. Operational Period<br>:opp:</td>\
</tr>\
</tbody>\
</table>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#E9E9E9>5. Incident Medical Aid Station<br></td>\
</tr>\
<tr>\
<td VALIGN=middle>Medical Aid Stations<br></td>\
<td VALIGN=middle>Location<br></td>\
<td COLSPAN=1 VALIGN=top;>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Paramedics<br></td>\
</tr>\
<tr>\
<td VALIGN=top WIDTH=40%>:msta0:<br></td>\
<td VALIGN=top WIDTH=45%>:mloc0:<br></td>\
<td VALIGN=top WIDTH=15% ALIGN=center>:mpar0:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:msta1:<br></td>\
<td VALIGN=top>:mloc1:<br></td>\
<td VALIGN=top ALIGN=center>:mpar1:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:msta2:<br></td>\
<td VALIGN=top>:mloc2:<br></td>\
<td VALIGN=top ALIGN=center>:mpar2:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:msta3:<br></td>\
<td VALIGN=top>:mloc3:<br></td>\
<td VALIGN=top ALIGN=center>:mpar3:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:msta4:<br></td>\
<td VALIGN=top>:mloc4:<br></td>\
<td VALIGN=top ALIGN=center>:mpar4:<br></td>\
</tr>\
</tbody>\
</table>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=4 VALIGN=top BGCOLOR=#E9E9E9>6. Transportation<br></td>\
</tr>\
<tr ALIGN=center>\
<td COLSPAN=4 VALIGN=top; BGCOLOR=#E9E9E9>A. Ambulance Services<br></td>\
</tr>\
<tr>\
<td VALIGN=top WIDTH=25%>Name</td>\
<td VALIGN=top WIDTH=40%>Address<br></td>\
<td VALIGN=top WIDTH=20%>Phone<br></td>\
<td VALIGN=top WIDTH=15% ALIGN=center>Paramedics<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:tname0:<br></td>\
<td VALIGN=top>:taddr0:<br></td>\
<td VALIGN=top>:tphon0:<br></td>\
<td VALIGN=top ALIGN=center>:tpara0:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:tname1:<br></td>\
<td VALIGN=top>:taddr1:<br></td>\
<td VALIGN=top>:tphon1:<br></td>\
<td VALIGN=top ALIGN=center>:tpara1:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:tname2:<br></td>\
<td VALIGN=top>:taddr2:<br></td>\
<td VALIGN=top>:tphon2:<br></td>\
<td VALIGN=top ALIGN=center>:tpara2:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:tname3:<br></td>\
<td VALIGN=top>:taddr3:<br></td>\
<td VALIGN=top>:tphon3:<br></td>\
<td VALIGN=top ALIGN=center>:tpara3:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:tname4:<br></td>\
<td VALIGN=top>:taddr4:<br></td>\
<td VALIGN=top>:tphon4:<br></td>\
<td VALIGN=top ALIGN=center>:tpara4:<br></td>\
</tr>\
</tbody>\
</table>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#E9E9E9>B. Incident Ambulances<br></td>\
</tr>\
<tr>\
<td VALIGN=top WIDTH=25%>Name<br></td>\
<td VALIGN=top WIDTH=60%>Location<br></td>\
<td VALIGN=top  WIDTH=15%; ALIGN=center>Paramedics<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:aname0:<br></td>\
<td VALIGN=top>:aloca0:<br></td>\
<td VALIGN=top ALIGN=center>:apara0:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:aname1:<br></td>\
<td VALIGN=top>:aloca1:<br></td>\
<td VALIGN=top ALIGN=center>:apara1:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:aname2:<br></td>\
<td VALIGN=top>:aloca2:<br></td>\
<td VALIGN=top ALIGN=center>:apara2:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:aname3:<br></td>\
<td VALIGN=top>:aloca3:<br></td>\
<td VALIGN=top ALIGN=center>:apara3:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:aname4:<br></td>\
<td VALIGN=top>:aloca4:<br></td>\
<td VALIGN=top ALIGN=center>:apara4:<br></td>\
</tr>\
</tbody>\
</table>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=7 VALIGN=top BGCOLOR=#E9E9E9>7. Hospitals<br></td>\
</tr>\
<tr>\
<td VALIGN=bottom WIDTH=20%>Name<br></td>\
<td VALIGN=bottom WIDTH=30%>Address<br></td>\
<td COLSPAN=2 VALIGN=top WIDTH=10%>&nbsp; Travel Time<br>&nbsp; Air&nbsp;&nbsp;&nbsp; &nbsp; &nbsp; Grnd<br></td>\
<td VALIGN=bottom WIDTH=15%>Phone<br></td>\
<td VALIGN=bottom WIDTH=5%>Helipad<br></td>\
<td VALIGN=top WIDTH=5% ALIGN=center>Burn<br>Center<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:hname0:<br></td>\
<td VALIGN=top>:haddr0:<br></td>\
<td VALIGN=top WIDTH=5%>:hatim0:<br></td>\
<td VALIGN=top WIDTH=5%>:hgtim0:<br></td>\
<td VALIGN=top>:hphon0:<br></td>\
<td VALIGN=top ALIGN=center>:hheli0:<br></td>\
<td VALIGN=top ALIGN=center>:hburn0:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:hname1:<br></td>\
<td VALIGN=top>:haddr1:<br></td>\
<td VALIGN=top>:hatim1:<br></td>\
<td VALIGN=top>:hgtim1:<br></td>\
<td VALIGN=top>:hphon1:<br></td>\
<td VALIGN=top ALIGN=center>:hheli1:<br></td>\
<td VALIGN=top ALIGN=center>:hburn1:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:hname2:<br></td>\
<td VALIGN=top>:haddr2:<br></td>\
<td VALIGN=top>:hatim2:<br></td>\
<td VALIGN=top>:hgtim2:<br></td>\
<td VALIGN=top>:hphon2:<br></td>\
<td VALIGN=top ALIGN=center>:hheli2:<br></td>\
<td VALIGN=top ALIGN=center>:hburn2:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:hname3:<br></td>\
<td VALIGN=top>:haddr3:<br></td>\
<td VALIGN=top>:hatim3:<br></td>\
<td VALIGN=top>:hgtim3:<br></td>\
<td VALIGN=top>:hphon3:<br></td>\
<td VALIGN=top ALIGN=center>:hheli3:<br></td>\
<td VALIGN=top ALIGN=center>:hburn3:<br></td>\
</tr>\
<tr>\
<td VALIGN=top>:hname4:<br></td>\
<td VALIGN=top>:haddr4:<br></td>\
<td VALIGN=top>:hatim4:<br></td>\
<td VALIGN=top>:hgtim4:<br></td>\
<td VALIGN=top>:hphon4:<br></td>\
<td VALIGN=top ALIGN=center>:hheli4:<br></td>\
<td VALIGN=top ALIGN=center>:hburn4:<br></td>\
</tr>\
</tbody>\
</table>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=2 VALIGN=top BGCOLOR=#E9E9E9>8. Medical Emergency Procedures<br></td>\
</tr>\
<tr>\
<td COLSPAN=2 VALIGN=top HEIGHT=200px>:proc:<br></td>\
</tr>\
<tr>\
<td VALIGN=top WIDTH=50%>9. Prepared by (Medical Unit Leader)<br>:prep:<br></td>\
<td VALIGN=top>10.Reviewed by (Safety Officer)<br>:rvwr:<br></td>\
</tr>\
</tbody>\
</table>\
</body>\
</html>";

const char ics206_text_template[] =
"ICS 206 MEDICAL PLAN\n\n\
Incident name: :nam:\n\
Operational period: :opp:\n\
Date Prepared: :dat:\n\
Time Prepared: :tim:\n\
Medical Aid Station #1: :msta0:\n\
Location #1: :mloc0:\n\
Paramedics #1: :mpar0:\n\
Medical Aid Station #2: :msta1:\n\
Location #2: :mloc1:\n\
Paramedics #2: :mpar1:\n\
Medical Aid Station #3: :msta2:\n\
Location #3: :mloc2:\n\
Paramedics #3: :mpar2:\n\
Medical Aid Station #4: :msta3:\n\
Location #4: :mloc3:\n\
Paramedics #4: :mpar3:\n\
Medical Aid Station #5: :msta4:\n\
Location #5: :mloc4:\n\
Paramedics #5: :mpar4:\n\
Ambulance service #1: :tname0:\n\
Address #1: :taddr0:\n\
Phone #1: :tphon0:\n\
Paramedics #1: :tpara0:\n\
Ambulance service #2: :tname1:\n\
Address #2: :taddr1:\n\
Phone #2: :tphon1:\n\
Paramedics #2: :tpara1:\n\
Ambulance service #3: :tname2:\n\
Address #3: :taddr2:\n\
Phone #3: :tphon2:\n\
Paramedics #3: :tpara2:\n\
Ambulance service #4: :tname3:\n\
Address #4: :taddr3:\n\
Phone #4: :tphon3:\n\
Paramedics #4: :tpara3:\n\
Ambulance service #5: :tname4:\n\
Address #5: :taddr4:\n\
Phone #5: :tphon4:\n\
Paramedics #5: :tpara4:\n\
Incident ambulance name #1: :aname0:\n\
Location #1: :aloca0:\n\
Paramedics #1 :apara0:\n\
Incident ambulance name #2: :aname1:\n\
Location #2: :aloca1:\n\
Paramedics #2 :apara1:\n\
Incident ambulance name #3: :aname2:\n\
Location #3: :aloca2:\n\
Paramedics #3 :apara2:\n\
Incident ambulance name #4: :aname3:\n\
Location #4: :aloca3:\n\
Paramedics #4 :apara3:\n\
Incident ambulance name #5: :aname4:\n\
Location #5: :aloca4:\n\
Paramedics #5 :apara4:\n\
Hospital name #1: :hname0:\n\
Address #1: :haddr0:\n\
Travel time, air #1: :hatim0:\n\
Travel time, ground #1: :hgtim0:\n\
Phone #1: :hphon0:\n\
Helipad #1: :hheli0:\n\
Burn center #1: :hburn0:\n\
Hospital name #2: :hname1:\n\
Address #2: :haddr1:\n\
Travel time, air #2: :hatim1:\n\
Travel time, ground #2: :hgtim1:\n\
Phone #2: :hphon1:\n\
Helipad #2: :hheli1:\n\
Burn center #2: :hburn1:\n\
Hospital name #3: :hname2:\n\
Address #3: :haddr2:\n\
Travel time, air #3: :hatim2:\n\
Travel time, ground #3: :hgtim2:\n\
Phone #3: :hphon2:\n\
Helipad #3: :hheli2:\n\
Burn center #3: :hburn2:\n\
Hospital name #4: :hname3:\n\
Address #4: :haddr3:\n\
Travel time, air #4: :hatim3:\n\
Travel time, ground #4: :hgtim3:\n\
Phone #4: :hphon3:\n\
Helipad #4: :hheli3:\n\
Burn center #4: :hburn3:\n\
Hospital name #5: :hname4:\n\
Address #5: :haddr4:\n\
Travel time, air #5: :hatim4:\n\
Travel time, ground #5: :hgtim4:\n\
Phone #5: :hphon4:\n\
Helipad #5: :hheli4:\n\
Burn center #5: :hburn4:\n\
Medical Emergency Procedures: :proc:\n\
Prepared by: :prep:\n\
Reviewed by: :rvwr:\n\
";

