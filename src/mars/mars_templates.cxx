// =====================================================================
//
// ics203_templates.cxx
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
// mars daily form template
//======================================================================

#include "templates.h"

const char mars_daily_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#E9E9E9><big>MARS DAILY REPORT</big><br></td>\
</tr>\
</table><br>\
<FONT face=monospace size=5><b><pre>\
DE :md_de_: NR :md_nbr:\n\
:md_pre: :md_dtg:\n\
FM :md_fnm: :md_fcl: :md_fst:\n\
TO :md_tps:/:md_tcl: :md_tst:\n\
INFO :md_ps1:/:md_cl1: :md_st1:\n\
INFO :md_ps2:/:md_cl2: :md_st2:\n\
INFO :md_ps3:/:md_cl3: :md_st3:\n\
BT\n\
:md_inc:\n\
SUBJECT: SITREP / :md_sid: / :md_slo:\n\
1. :md_22h:\n\
2. :md_ncl: / :md_e_x:\n\
3. :md_dta:/:md_dtd: :md_nst:\n\
A. :md_det:\n\
B. :md_acs:\n\
4. :md_agy:\n\
5. :md_rem:\n\
:md_inc:\n\
BT\n\
/EX\n\
NNNN\n\
</pre></b></FONT>\
</body>\
</html>";

const char mars_daily_text_template[] =
"DE :md_de_: NR :md_nbr:\n\
:md_pre: :md_dtg:\n\
FM :md_fnm: :md_fcl: :md_fst:\n\
TO :md_tps:/:md_tcl: :md_tst:\n\
INFO :md_ps1:/:md_cl1: :md_st1:\n\
INFO :md_ps2:/:md_cl2: :md_st2:\n\
INFO :mars_state_sd:/:call_sign_st:\n\
BT\n\
:md_inc:\n\
SUBJECT: SITREP / :md_sid: / :md_slo:\n\
1. :md_22h:\n\
2. :md_ncl: / :md_e_x:\n\
3. :md_dta:/:md_dtd: :md_nst:\n\
A. :md_det:\n\
B. :md_acs:\n\
4. :md_agy:\n\
5. :md_rem:\n\
:md_inc:\n\
BT\n\
/EX\n\
NNNN\n";

//======================================================================
// Net report templates
//======================================================================

const char mars_net_html_template[] = "\
<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#E9E9E9><big>MARS NET REPORT</big><br></td>\
</tr>\
</table><br>\
<FONT face=monospace size=5><b><pre>\
DE :de: :nbr:\n\
:prec: :dtg:\n\
FM :fmname: :fmcall: :fmstate:\n\
TO :topos:/:tocall: :tostate:\n\
INFO :info1pos:/:info1call: :info1state:\n\
BT\n\
:incident:\n\
SUBJECT: NET REPORT :dnd:\n\
1. :netcall:\n\
2. :dtgstart: :dtgend:\n\
3. :netsb:\n\
4. :ncscall:\n\
5. :nbrstas:, :calls:\n\
6. NA\n\
7. A. :nbrmsgs:\n\
   B. :comments:\n\
:incident:\n\
BT\n\
/EX\n\
NNNN\n\
</pre></b></FONT>\
</body>\
</html>";

const char mars_net_text_template[] = "\
DE :de: :nbr:\n\
:prec: :dtg:\n\
FM :fmname: :fmcall: :fmstate:\n\
TO :topos:/:tocall: :tostate:\n\
INFO :info1pos:/:info1call: :info1state:\n\
BT\n\
:incident:\n\
SUBJECT: NET REPORT :dnd:\n\
1. :netcall:\n\
2. :dtgstart: :dtgend:\n\
3. :netsb:\n\
4. :ncscall:\n\
5. :nbrstas:, :calls:\n\
6. NA\n\
7. A. :nbrmsgs:\n\
   B. :comments:\n\
:incident:\n\
BT\n\
/EX\n\
NNNN\n\
";

//======================================================================
// IN/IEE report templates
//======================================================================

const char mars_ineei_html_template[] = "\
<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#E9E9E9><big>MARS IN/EEI REPORT</big><br></td>\
</tr>\
</table><br>\
<FONT face=monospace size=5><b><pre>\
DE :de: :nbr:\n\
:prec: :dtg:\n\
FM :fmname: :fmcall: :fmstate:\n\
TO :topos:/:tocall: :tostate:\n\
INFO :info1pos:/:info1call: :info1state:\n\
INFO :info2pos:/:info2call: :info2state:\n\
BT\n\
:incident:\n\
SUBJECT: IN/EEI REPORT\n\
1. :ref: :state:\n\
A. :1a_incident: :1a_location: :1a_time:\n\
B. :1b_medfacsts:\n\
C. :1c_trnpsts:\n\
D. :1d_damage:\n\
E. :1e_utilsts:\n\
F. :1f_commsts:\n\
G. :1g_infosrc: :1g_infotime:\n\
H. :1h_remarks:\n\
:incident:\n\
BT\n\
/EX\n\
NNNN\n\
</pre></b></FONT>\
</body>\
</html>";

const char mars_ineei_text_template[] = "\
DE :de: :nbr:\n\
:prec: :dtg:\n\
FM :fmname: :fmcall: :fmstate:\n\
TO :topos:/:tocall: :tostate:\n\
INFO :info1pos:/:info1call: :info1state:\n\
INFO :info2pos:/:info2call: :info2state:\n\
BT\n\
:incident:\n\
SUBJECT: IN/EEI REPORT\n\
1. :ref: :state:\n\
A. :1a_incident: :1a_location: :1a_time:\n\
B. :1b_medfacsts:\n\
C. :1c_trnpsts:\n\
D. :1d_damage:\n\
E. :1e_utilsts:\n\
F. :1f_commsts:\n\
G. :1g_infosrc: :1g_infotime:\n\
H. :1h_remarks:\n\
:incident:\n\
BT\n\
/EX\n\
NNNN\n\
";

//======================================================================
// ARMY message templates
//======================================================================

const char mars_army_html_template[] = "\
<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#E9E9E9><big>ARMY MARS STD MSG</big><br></td>\
</tr>\
</table><br>\
<FONT face=monospace size=5><b><pre>\
DE :de: NR :nbr:\n\
:pre: :dtg:\n\
FM :fm:\n\
TO :to:\n\
INFO :info:\n\
BT\n\
:text:\n\
BT\n\
NNNN\n\
</pre></b></FONT>\
</body>\
</html>";

const char mars_army_text_template[] = "\
DE :de: NR :nbr:\n\
:pre: :dtg:\n\
FM :fm:\n\
TO :to:\n\
INFO :info:\n\
BT\n\
:text:\n\
BT\n\
NNNN\n\
";

//======================================================================
// NAVY message templates
//======================================================================

const char mars_navy_html_template[] = "\
<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head><body>\
<table WIDTH=1000px BORDER=1 CELLPADDING=0 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=3 VALIGN=top BGCOLOR=#E9E9E9><big>NAVY MARS STD MSG</big><br></td>\
</tr>\
</table><br>\
<FONT face=monospace size=5><b><pre>\
:pre: :dtg:\n\
FM :fm:\n\
TO :to:\n\
INFO :info:\n\
BT\n\
:text:\n\
BT\n\
NNNN\n\
</pre></b></FONT>\
</body>\
</html>";

const char mars_navy_text_template[] = "\
:pre: :dtg:\n\
FM :fm:\n\
TO :to:\n\
INFO :info:\n\
BT\n\
:text:\n\
BT\n\
NNNN\n\
";

