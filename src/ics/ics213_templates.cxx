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

const char ics213_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\n\
<title>:TITLE:</title></head><body>\n\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=4 CELLSPACING=0>\n\
<tbody>\n\
<tr ALIGN=center>\n\
<td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE><big><b>GENERAL MESSAGE<b></big><br>(ics-213)<br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top WIDTH=100% COLSPAN=3>1.0 Incident (optional): :inc:<br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top>2. TO: :to:<br></td>\n\
<td VALIGN=top WIDTH=50% COLSPAN=2>POSITION: :p1:<br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top>3. FROM: :fm:<br></td>\n\
<td COLSPAN=2 VALIGN=top>POSITION: :p2:<br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top>4. SUBJ: :sb:<br></td>\n\
<td VALIGN=top WIDTH=25%>5. DATE: :d1:<br></td>\n\
<td VALIGN=top>6. TIME: :t1:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE>7. MESSAGE:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=3 VALIGN=top>\n\
<table WIDTH=1000px ALIGN=left BORDER=0 CELLPADDING=0 CELLSPACING=0>\n\
<COL WIDTH 998px>\n\
<COL WIDTH 2px>\n\
	<tr>\n\
		<td VALIGN=top>:mg:</td>\n\
		<td VALIGN=top>\n\
		<br><br><br><br><br><br><br><br><br><br>\n\
		<br><br><br><br><br><br><br><br><br><br>\n\
		</td>\n\
	</tr>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top>8. SIGNATURE: :s1:<br></td>\n\
<td COLSPAN=2 VALIGN=top>POSITION: :p3:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE>9. REPLY:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=3 VALIGN=top>\n\
<table WIDTH=1000px ALIGN=left BORDER=0 CELLPADDING=0 CELLSPACING=0>\n\
<COL WIDTH 998px>\n\
<COL WIDTH 2px>\n\
	<tr>\n\
		<td VALIGN=top>:rp:</td>\n\
		<td VALIGN=top>\n\
		<br><br><br><br><br><br><br><br><br><br>\n\
		<br><br><br><br><br><br><br><br><br><br>\n\
		</td>\n\
	</tr>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top COLSPAN=3>\n\
<table ALIGN=left WIDTH=1000px BORDER=0 CELLPADDING=0 CELLSPACING=0>\n\
<tbody>\n\
<tr>\n\
<td VALIGN=top WIDTH =15% HEIGHT=100%>10. Replied by:</td>\n\
<td VALIGN=top WIDTH=25% HEIGHT=100%>DATE:<br>:d2:<br></td>\n\
<td VALIGN=top WIDTH=25% HEIGHT=100%>TIME:<br>:t2:<br></td>\n\
<td VALIGN=top WIDTH=35%>SIGNATURE/POSITION:<br>:s2: / :p4:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<br>\n\
</body>\n\
</html>";

const char ics213_text_template[] =
"ICS 213 GENERAL MESSAGE\n\n\
INC: :inc:\n\
TO: :to:\n\
POSITION: :p1:\n\
FROM: :fm:\n\
POSITION: :p2:\n\
SUBJ: :sb:\n\
DATE: :d1:\n\
TIME: :t1:\n\
MESSAGE:\n\
:mg:\n\
SIGNATURE: :s1:\n\
POSITION: :p3:\n\
REPLY:\n\
:rp:\n\
DATE: :d2:\n\
TIME: :t2:\n\
SIGNATURE: :s2:\n\
POSITION: :p4:\n";

