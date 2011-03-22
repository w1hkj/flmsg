// =====================================================================
//
// templates.cxx
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

#include "templates.h"
#include "ics203_templates.cxx"
#include "ics205_templates.cxx"
#include "ics205a_templates.cxx"
#include "ics206_templates.cxx"
#include "ics213_templates.cxx"
#include "ics214_templates.cxx"
#include "ics216_templates.cxx"

//======================================================================
// RADIOGRAM templates
//======================================================================
const char rg_html_template[] =
"<html>\
<head>\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head>\
<body>\
<table WIDTH=1000px BORDER=0 CELLPADDING=0 CELLSPACING=2>\
<tbody>\
<tr>\
<td VALIGN=top>\
<div ALIGN=center><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\
<font size=\"6\"><b>RADIOGRAM</b></font><br>\
<font size=\"3\"><b>VIA AMATEUR RADIO</b></font><br>\
<br>\
</div>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top WIDTH=8%>NR</td>\
<td VALIGN=top WIDTH=17%>PREC</td>\
<td VALIGN=top WIDTH=15%>HX__</td>\
<td VALIGN=top WIDTH=10%>STN ORIG</td>\
<td VALIGN=top WIDTH=8%>CK</td>\
<td VALIGN=top WIDTH=22%>PLACE OF ORIGIN</td>\
<td VALIGN=top WIDTH=12%>TIME FILED</td>\
<td VALIGN=top WIDTH=8%>MON DY</td>\
</tr>\
<tr>\
<td VALIGN=top>:nbr:<br></td>\
<td VALIGN=top>:prec:<br></td>\
<td VALIGN=top>:hx:<br></td>\
<td VALIGN=top>:sta:<br></td>\
<td VALIGN=top>:ck:<br></td>\
<td VALIGN=top>:org:<br></td>\
<td VALIGN=top>:t1:<br></td>\
<td VALIGN=top>:d1:<br></td>\
</tr>\
</tbody>\
</table>\
<br>\
<table WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top>TO<br>\
</td>\
<td VALIGN=top>THIS RADIO MESSAGE WAS RECEIVED AT<br>\
</td>\
</tr>\
<tr>\
<td VALIGN=top WIDTH=50%>:to:<br>\
</td>\
<td VALIGN=top WIDTH=50%>:rx:<br>\
</td>\
</tr>\
</tbody>\
</table>\
<br>\
<table WIDTH=1000px BORDER=0 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top>TELEPHONE NUMBER<br>\
</td>\
</tr>\
<tr>\
<td VALIGN=top>:tel:<br>\
</td>\
</tr>\
</tbody>\
</table>\
<br>\
<table WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top>\
<p>:msg:</p>\
<p>:sig:</p>\
</td>\
</tr>\
</tbody>\
</table>\
</body></html>";

const char rg_html_fcopy_template[] = 
"<html>\
<head>\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head>\
<body>\
<table WIDTH=1000px BORDER=0 CELLPADDING=0 CELLSPACING=2>\
<tbody>\
<tr>\
<td ALIGN=top>\
<div ALIGN=center><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\
<font size=\"6\"><b>RADIOGRAM</b></font><br>\
<font size=\"3\"><b>VIA AMATEUR RADIO</b></font><br>\
<font size=\"2\"><b>FILE COPY</b></font><br>\
<br>\
</div>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top WIDTH=8%>NR</td>\
<td VALIGN=top WIDTH=17%>PREC</td>\
<td VALIGN=top WIDTH=15%>HX__</td>\
<td VALIGN=top WIDTH=10%>STN ORIG</td>\
<td VALIGN=top WIDTH=8%>CK</td>\
<td VALIGN=top WIDTH=22%>PLACE OF ORIGIN</td>\
<td VALIGN=top WIDTH=12%>TIME FILED</td>\
<td VALIGN=top WIDTH=8%>MON DY</td>\
</tr>\
<tr>\
<td ALIGN=top>:nbr:<br></td>\
<td ALIGN=top>:prec:<br></td>\
<td ALIGN=top>:hx:<br></td>\
<td ALIGN=top>:sta:<br></td>\
<td ALIGN=top>:ck:<br></td>\
<td ALIGN=top>:org:<br></td>\
<td ALIGN=top>:t1:<br></td>\
<td ALIGN=top>:d1:<br></td>\
</tr>\
</tbody>\
</table>\
<br>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top width 50%>TO<br></td>\
<td VALIGN=top width 50%>THIS RADIO MESSAGE WAS RECEIVED AT<br></td>\
</tr>\
<tr>\
<td VALIGN=top WIDTH=50%>:to:<br></td>\
<td VALIGN=top WIDTH=50%>:rx:<br></td>\
</tr>\
</tbody>\
</table>\
<br>\
<table WIDTH=1000px BORDER=0 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td ALIGN=top>TEL<br></td>\
</tr>\
<tr>\
<td ALIGN=top>:tel:<br></td>\
</tr>\
<tr>\
<td ALIGN=top>OP NOTE :opn:<br></td>\
</tr>\
</tbody>\
</table>\
<br>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td ALIGN=top>\
<p>:msg:</p>\
<p>:sig: OP NOTE :op2:</p>\
</td>\
</tr>\
</tbody>\
</table>\
<br>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top WIDTH=15%>FROM<br>:rfm:</td>\
<td VALIGN=top WIDTH=15%>NET<br>:rnt:</td>\
<td VALIGN=top WIDTH=20%>DATE/TIME<br>:dt2:</td>\
<td VALIGN=top WIDTH=15%>SENT TO<br>:sto:</td>\
<td VALIGN=top WIDTH=15%>NET<br>:snt:</td>\
<td VALIGN=top WIDTH=20%>DATE/TIME<br>:dt3:</td>\
</tr>\
</tbody>\
</table>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td VALIGN=top WIDTH=500px>ORIG - FROM / DATE/TIME<br>:ori:</td>\
<td VALIGN=top WIDTH=500px>DLVD - to / DATE/TIME<br>:dlv:</td>\
</tr>\
</tbody>\
</table>\
<br>\
</td>\
</tr>\
</tbody>\
</table>\
<br>\
</body></html>";

const char rg_txt_template[] =
":nbr: :prec::hx: :sta: :ck: :org: :t1: :d1:\n\
:to:\n\
:tel::opn:\n\
BT\n\
:msg:\n\
BT\n\
:sig::op2:\n\
AR\n\
";

//======================================================================
// plaintext templates
//======================================================================

const char pt_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE><big><b>:tt:</b></big><br></td>\
</tr>\
<tr><td VALIGN=top>TO: :to:<br></td></tr>\
<tr><td VALIGN=top>FROM: :fm:<br></td></tr>\
<tr><td VALIGN=top>SUBJ: :sb:<br></td></tr>\
<tr><td VALIGN=top>DATE: :dt:<br></td></tr>\
<tr><td VALIGN=top>TIME: :tm:<br></td></tr>\
<tr><td COLSPAN=3 VALIGN=top BGCOLOR=#EEEEEE>MESSAGE:<br></td></tr>\
<tr><td COLSPAN=3 VALIGN=top>:mg:<br></td></tr>\
</table>\
</body></html>";

const char pt_txt_template[] =
"TITLE: :tt:\n\
TO: :to:\n\
FROM: :fm:\n\
SUBJ: :sb:\n\
DATE: :dt:\n\
TIME: :tm:\n\
MESSAGE:\n\
:mg:\n\
";

//======================================================================
// blank form template
//======================================================================

const char blank_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title></head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td COLSPAN=3 VALIGN=top>:mg:<br>\
</td>\
</tr>\
</table>\
</body></html>";

//======================================================================
// bad data form template
//======================================================================

const char baddata_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title></head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr>\
<td COLSPAN=3 VALIGN=top><txt:<br>\
</td>\
</tr>\
</table>\
</body></html>";

const char blank_txt_template[] =
":mg:";

