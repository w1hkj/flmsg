// =====================================================================
//
// ics213_templates.cxx
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
// ICS213 templates
//======================================================================

#include "templates.h"

const char ics213_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n\
<title>:TITLE:</title></head><body>\n\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=4 CELLSPACING=0>\n\
<tbody>\n\
<tr ALIGN=center>\n\
<td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE><big><br><b>GENERAL MESSAGE<b></big><br>(ics-213)<br><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top>TO: :to:<br></td>\n\
<td VALIGN=top WIDTH=50% COLSPAN=2>POSITION: :p1:<br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top>FROM: :fm:<br></td>\n\
<td COLSPAN=2 VALIGN=top>POSITION: :p2:<br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top>SUBJ: :sb:<br></td>\n\
<td VALIGN=top WIDTH=25%>DATE: :d1:<br></td>\n\
<td VALIGN=top>TIME: :t1:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE>MESSAGE:<br></td>\n\
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
<td VALIGN=top>SIGNATURE: :s1:<br></td>\n\
<td COLSPAN=2 VALIGN=top>POSITION: :p3:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE>REPLY:<br></td>\n\
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
<td VALIGN=top>\n\
<table ALIGN=left WIDTH=100% BORDER=0 CELLPADDING=0 CELLSPACING=0>\n\
<tbody>\n\
<tr>\n\
<td VALIGN=top WIDTH=50% HEIGHT=100%>DATE:<br>:d2:<br></td>\n\
<td VALIGN=top>TIME:<br>:t2:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
<td VALIGN=top COLSPAN=2>SIGNATURE/POSITION:<br>:s2: / :p4:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</body>\n\
</html>";

const char ics213_text_template[] =
"ICS 213 GENERAL MESSAGE\n\n\
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

