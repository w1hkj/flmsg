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
// along with this program.  If not, see<http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include "templates.h"

const char rg_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML><HEAD><TITLE>radiogram</TITLE>\n\
<META content=\"text/html; charset=UTF-8\" http-equiv=content-type>\n\
<META name=author content=w1hkj>\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 8pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
p.F6 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
</STYLE>\n\
\n\
<META name=GENERATOR content=\"MSHTML 8.00.6001.19154\"></HEAD>\n\
<BODY>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=0 \n\
cellPadding=0>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%; MARGIN-LEFT: auto; MARGIN-RIGHT: auto\" border=0 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<DIV style=\"TEXT-ALIGN: center\">\n\
<FONT size=3><B>THE AMERICAN RADIO RELAY LEAGUE</B></FONT><BR>\n\
</DIV>\n\
<DIV style=\"TEXT-ALIGN: center\">\n\
<FONT size=6><B>RADIOGRAM</B></FONT><BR>\n\
</DIV>\n\
<DIV style=\"TEXT-ALIGN: center\">\n\
<FONT size=3><B>VIA AMATEUR RADIO<BR></B></FONT>\n\
</DIV>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=1 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>NUMBER</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 14%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PRECEDENCE</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>HX</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>STATION OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
<p class=F2>CHECK</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PLACE OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
<p class=F2>TIME FILED</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F2>DATE</p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:nbr:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:prec:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:hx:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=\"F4\">:sta:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:ck:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:org:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:t1:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:d1:<br></p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><p class=\"F2\">TO</p></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:to:</p></pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top; TEXT-ALIGN: center\">\n\
<p class=F2>THIS RADIO MESSAGE WAS RECEIVED AT</p>\n\
</td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:rx:</p><pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><p class=F2>PHONE NUMBER</p></td>\n\
<td><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>:tel:</p></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><pre><p class=F4>:msg:</p></pre></td>\n\
<td><br><br><br><br><br><br><br><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>:sig:</p></td>\n\
<td><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=2 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<p class=F4>:exp:</p>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE><BR>\n\
</BODY>\n\
</HTML>\n\
";

const char rg_html_fcopy_template[] = 
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML><HEAD><TITLE>radiogram</TITLE>\n\
<META content=\"text/html; charset=UTF-8\" http-equiv=content-type>\n\
<META name=author content=w1hkj>\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 8pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
p.F6 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
</STYLE>\n\
\n\
<META name=GENERATOR content=\"MSHTML 8.00.6001.19154\"></HEAD>\n\
<BODY>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=0 \n\
cellPadding=0>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%; MARGIN-LEFT: auto; MARGIN-RIGHT: auto\" border=0 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<DIV style=\"TEXT-ALIGN: center\">\n\
<FONT size=3><B>THE AMERICAN RADIO RELAY LEAGUE</B></FONT><BR>\n\
</DIV>\n\
<DIV style=\"TEXT-ALIGN: center\">\n\
<FONT size=6><B>RADIOGRAM</B></FONT><BR>\n\
</DIV>\n\
<DIV style=\"TEXT-ALIGN: center\">\n\
<FONT size=3><B>VIA AMATEUR RADIO<BR></B></FONT>\n\
</DIV>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=1 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>NUMBER</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 14%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PRECEDENCE</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>HX</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>STATION OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 8%; VERTICAL-ALIGN: top\">\n\
<p class=F2>CHECK</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PLACE OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
<p class=F2>TIME FILED</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F2>DATE</p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:nbr:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:prec:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:hx:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=\"F4\">:sta:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:ck:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:org:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:t1:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:d1:<br></p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><p class=\"F2\">TO</p></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:to:</p></pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top; TEXT-ALIGN: center\">\n\
<p class=F2>THIS RADIO MESSAGE WAS RECEIVED AT</p>\n\
</td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:rx:</p></pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><p class=F2>PHONE NUMBER</p></td>\n\
<td><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>:tel:</p></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><pre><p class=F4>:msg:</p></pre></td>\n\
<td><br><br><br><br><br><br><br><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>:sig:</p></td>\n\
<td><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE><BR>\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>ORIG FROM:\n:ori:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME:<br>:dt2:</FONT></pre></td>\n\
<td></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DLVD TO:\n:dlv:></FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME:<br>:dt3:</FONT></pre></td>\n\
<td></td>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>RCVD FM: :rfm:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>NET: :rnt:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME: :dt4:</FONT></pre></td>\n\
</tr>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>SENT TO: :sto:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>NET: :snt:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME: :dt5:</FONT></pre></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body>\n\
</html>";

const char rg_txt_template[] =
"\
:nbr: :prec::hx: :sta: :ck: :org: :t1: :d1:\n\
:to:\n\
:tel::opn:\n\
BT\n\
:msg:\n\
BT\n\
:sig::op2:\n\
AR\n\
";

#include "templates.h"

const char rri_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML><HEAD><TITLE>radiogram</TITLE>\n\
<META content=\"text/html; charset=UTF-8\" http-equiv=content-type>\n\
<META name=author content=w1hkj>\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 8pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
p.F6 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
</STYLE>\n\
\n\
<META name=GENERATOR content=\"MSHTML 8.00.6001.19154\"></HEAD>\n\
<BODY>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=0 \n\
cellPadding=0>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<TABLE \n\
style=\"TEXT-ALIGN: left; WIDTH: 100%; MARGIN-LEFT: auto; MARGIN-RIGHT: auto\" \n\
border=0 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<tr>\n\
<td valign=\"middle\" align=\"center\"><img src=\"data:image/jpeg;base64,%0A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\" alt=\"\" width=\"90\" height=\"88\"><br>\n\
</td>\n\
<td valign=\"middle\" align=\"center\">\n\
<h1><font size=\"+5\">RADIOGRAM</font></h1>\n\
</td>\n\
<td valign=\"middle\" align=\"center\"><img src=\"data:image/jpeg;base64,%0A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\" alt=\"\" width=\"90\" height=\"88\"><br>\n\
</td>\n\
</tr>\n\
</TBODY>\n\
</TABLE>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=1 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>NUMBER</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 14%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PRECEDENCE</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>HX</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>STATION OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
<p class=F2>CHECK</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PLACE OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
<p class=F2>TIME FILED</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F2>DATE</p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:nbr:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:prec:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:hx:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=\"F4\">:sta:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:ck:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:org:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:t1:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:d1:<br></p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><p class=\"F2\">TO</p></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:to:</p></pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top; TEXT-ALIGN: center\">\n\
<p class=F2>THIS RADIO MESSAGE WAS RECEIVED AT</p>\n\
</td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:rx:</p><pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><p class=F2>PHONE NUMBER</p></td>\n\
<td><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>:tel:</p></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><pre><p class=F4>:msg:</p></pre></td>\n\
<td><br><br><br><br><br><br><br><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>Signature: :sig:</p></td>\n\
<td><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=2 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<p class=F4>:exp:</p>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE><BR>\n\
</BODY>\n\
</HTML>\n\
";

const char rri_html_fcopy_template[] = 
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML><HEAD><TITLE>radiogram</TITLE>\n\
<META content=\"text/html; charset=UTF-8\" http-equiv=content-type>\n\
<META name=author content=w1hkj>\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 8pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
p.F6 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
</STYLE>\n\
\n\
<META name=GENERATOR content=\"MSHTML 8.00.6001.19154\"></HEAD>\n\
<BODY>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=0 \n\
cellPadding=0>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\">\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%; MARGIN-LEFT: auto; MARGIN-RIGHT: auto\" border=0 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<td valign=\"middle\" align=\"center\"><img src=\"data:image/jpeg;base64,%0A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\" alt=\"\" width=\"90\" height=\"88\"><br>\n\
</td>\n\
<td valign=\"middle\" align=\"center\">\n\
<h1><font size=\"+5\">RADIOGRAM</font></h1>\n\
</td>\n\
<td valign=\"middle\" align=\"center\"><img src=\"data:image/jpeg;base64,%0A/9j/4AAQSkZJRgABAQAAAQABAAD/2wBDAAMCAgICAgMCAgIDAwMDBAYEBAQEBAgGBgUGCQgK%0ACgkICQkKDA8MCgsOCwkJDRENDg8QEBEQCgwSExIQEw8QEBD/wAALCABYAFoBAREA/8QAHQAA%0AAgIDAQEBAAAAAAAAAAAABgcFCAMECQIAAf/EADsQAAEDAwMEAQEFBAgHAAAAAAECAwQFBhEA%0ABxIIEyExIkEUFTJRYRYjQlIJFzNicXKBoiRjc4KEocH/2gAIAQEAAD8A6oLUpJAGNR1buWgW%0AzC+8bkrcClxeXDvzJCGUFXvHJRAz4Pj9NB0rqF2Zi8x/WBTJJbTyUIZXKIT+f7pKvH66M03J%0AQFUNq5jWoSaS8wmSicp9KWC0oZC+ZOMEH3oAqfUfthEbW7SplRrrbf4nqXAcdjj/AMhQSz/v%0A0HvdZu37Dim3aLIZUDji/W6Q2v8A1SZeRqZoXVVYla8mhV9tOfxxWmKinj/N/wAG66cf6aYN%0Ap7m2DfK1s2tdMGdIa/tYoXwkNf52V4Wn/VI1o3HvNtlaVaet+4btiw50ZCHH0LbcUlkKGU81%0ApSUoJHnBIOMH662qDurtvdEtun27fVBqEt38Edie2p1XjPhGeR8A/TRPzVkeBrJrw57Ghq/7%0ADo+41sSbarCAAtSH4sgIClxJLZ5NPIz45JUAfyIyD4J0oYW1W2W9NGrds3TR49Ivu31/d9Sl%0AUiUtl2LI48mZbISoDgscXEhQx7SfR0qdudurPpF9ytl+oa12am5IkJcpcp6RIRDceP4FtNhY%0AQlt7BUkAfB0OI9KRlbdVdyWXt5vBU9t4OzNjVmm0Ggs1dK7iqsxK1pIyplrL3Er8/FAGT51q%0AbmjZGibbbQ3rZ/Tdt/GlblpdD7VckyG40NaCkZLocSAjJJ5K+mNYqHWNlJXTLde98LptsyHc%0AdpVxqkFDEiSqG+VLbHcbWlwK9L+h+gP11ZLcazNh7N27ou49QsSI7dFQp7SqSHKhL5NurZC1%0AqC+4VpabBKlYOcAAZKgDpbIdM1EVQ3dyN7GZTiVsKfg02oTHUJhx/wAa5Ur55U+5gKIUSG0B%0ACB+HTL2gtW3Lsqbe8MKkQ49M7K4lpsNoSS1CJwuUo+T3HuIwCfi2EjwSrTgHg6y68LGSNVo3%0A/wB6d6Nu7iqFr0ZqhNoqEMyLeMaIqRNlpHxeGFvIQl1okKAwQsegSCnWrsB087o2pfkHc65r%0AxXFSaeqLJprS23BPDhK1uPlKTzcKzz59wnPgYT406d29qKLunQRDlgR6nDyuBNQSlbSzglJI%0A88SQP8ClKh5SNUe3V2/2zu/dGdA6iLiuKFfdUobdDhMRKGZLb/aUkM1Bl0HBcPEpUjx5KseC%0ANNO99oLO3GtzbG2bup24UyJtyntLQLKdSiqNcUJ4OJBw38UDyM+fOg65LO2h2w6aqpsPet23%0AxR6FWawJsKoy7QW0+2ruIX2QnP745TjPvz/hp77VbW1O9qnTNxNxorgh0uKxFoFJkowWY7IT%0A2lOp9ciUhxQ+q+PsNpyd9QG2Fe3f22nWLQbtk0Bc1aC88wQlTzaTntFXFRSknGcDzjHonVYY%0AF1b5dM1fqFtVOXT1wZ8ZqUz9piIehvzSShPAtOtlpx5Q5L+ASOKnFBPkm59rquR23qc9d7VP%0AbrS2EKmt08qMdDpGSlBV5IHrJ9+9S+vxRSkFaiAAPJP01ye6398qjX7pabolQejvVKUmptPN%0ALKXGIEZxSICEkeU8lB6Sce+63/KNXE6PupG4NwbSpFr7ssfZblVFaMWoccM1FKkc0IUcAJk9%0Avi4UfVKkqHsgaV0X91CVvf8ArO2FtXDKg0hgsS47sGkRu3Eh4Idckyn+QThScJSlClHP0HnQ%0Adu5f5iXVBnbcXVVK1cdPQ63Er1acQ9FYQ5zS8tplpCUrSnsqJSoEq4goT6Og7p96qLv3m3el%0AbbVP9pn25dNkpZnIq6mHmpDfy7yWEcEAHA+AyQCfJ0+a7S1XBSItFuu6qzIhtOs1aM3ViWXU%0ArbV4KZAR8u25gEK5gfBWD6GnuTce69oWAL+2/vS73o1LZWqr02fCgTpUH45StbakNrcR9SUu%0AZ4+QD9GbQ905ttbM0S8dxVGfX5kRCTEpzGHZ80g/umGh9SQf0AHIkDOuX++PUVufWuoGJfV6%0AKbMGCltUKkMOKVE+6pCPm0MgcittSkrURnkCPHEAdQOnK8xdm3bEN2omc/Q1pgiSo5VJiltL%0AsV5X5lcdxok/zctNPQZvPXXrb2ouusRXA3IZpT6I6s4w8tJQ3/uUnXJbdDaLcG8Nzl3c7alQ%0AbsmVcbFqQ6oUfuQ3HUmMAPJIGGlecYJB850+92HbqsvbHa+9LHoy6wiqzaj97U6JyK2pE9DZ%0ApyVBPybWhCI/bPggtpx71Ebw7lbvW7tVUL1uCtQmLsrkMW9UVsLStmQyntolBpxOB9obKGUu%0ApGQCpZSSMhILt7WKAjZobkbj7utqmVKvswWI0JvuT6C4hJ4TOAUlRGG0jAyOPrJyNWi2n6fo%0A0m/Lp6j7f3CMmt3GCbbns0tbsUNrQhLrzqEoGVLUleAgjAP55GiPe7d9O3Ni1WNbt3wajeNK%0ARJU1S6kwhpCmH3e0pZKkpxhTiFhJPnjqkGw143TRN1Kztuu+lzqPXgGaktMhUhMt4KQpttlJ%0AICnFv8Gxg4wpQzjzptXrdm/ci+6Tt4uE3MVVKpTLfos6nqLqqYxEeBnRnMAdt8kNqeVxHJI+%0AJKCNCPVxs5Ubr3Uaom1tKNclv1qXEgswSlQcYfQJiQFZxxQ4qWnOcAJ1ZXoHlXHRWxZ90wZM%0ACpM0ZdOmxZCcLak02WpvCv17Mpgf4JHnVy9LjqFydp6qnCSkyqeFg+uP21jP/rXKy3d5dzKh%0AuCxtDULrlLtaHdU+cxTilPESAt5SfljkRzOcE4yc6f29Nnblhm17u2SuGMunXDblu29dbHfA%0A+65KAyqJKfR7QnCkYcx4x+R0FdRNnruzpp2wTtlEen0K1ZVbiF7B7k4MuIS5Mx/zFhxePok6%0AAOmPprrG4t32yzuRSJVDsmp9yqt1Mt4VUEtgcWm1eRgk+1DwOWNdWrGrFk2/bUei02o02HEh%0AOyGGWGyltDaEvLAASMADH0A1z061t2Nrrn3iRYlzS5dQoVJkrclOUlCEusSHS3yKnTkuoDYz%0A2xj5Y8g5GktZtB2+i7y2RA21fcumDLuJhDM16O9BkNOlxPBtSVKUkhHhYIGTgg+/Fgt5IO5N%0A0b/XZJ6fpColZrdRnWtcMJD3D7A422hKqnyOAhDkYpBX7Cgr341HdS9xSNjhQKptDdiEy7Zg%0A27DiVSKUuoeUmNUGnVDOUrCgnz7B8aOf6Pu6rivS5Y11XRVH6hVapJuORKkOny6VCmkqIHgf%0ALAwPA10A0D74Ud6u7RXZT4zZcfFLekMJGcl1kd1Hr+8ga5jNdPF8PbmXVvjR5VITbVt11Vac%0AbXJzIdjLxKIS2kHjlhZIKiAfppubmbWydwdtbPuPb3cimW5fsanPWfOgz6gIjVeYiOFCEBas%0AIU6EhtaQf4VpIxgHRt0uVClvxavsdGkFxyxoVIk05Erilxc51p4z2eJJHIuKdTx8ghIzkaDu%0Aq2JVtjrFFxbO0efRHZ1banvzKcrnAjNISsApYWFCOsOLUhSRgAcQc+NTfRb1s3judWoe0V40%0AdmTWXkyZQraWh2ykZWpT6QpIT5OMp8EkePOh3qa6Vdu7mi3fvMzebn7SyYU+uPw4TYMTLSiE%0AKWPmpBXgD2B4OgLoH2cq8OVVOoi7I6ots2xEkSqU2+kD7wntsrKVNg+w2nn5H8Rx9DrJRrBr%0Au+N0w91ndyodn21fcCBDu2ZJmpYkT5qQjvxYjSTzd58Ws4GORI84xqH62nWapXhbFjUWQ9TI%0AlURT4jcSOpaW48KOiGwn4j2p77UBnySnVhv6Oa1JlLpEFyXGW0qDRJMp5K04KHZ00hIOfIPb%0AgpOP7w1eLXlxtDzamnEhSFgpUk+iD7GqL1GyaTaO5M6xbstpuv05SF0yNDlTHWWFqALsJxwB%0AYbLbkRK2VKKFq5Q8JBJAMFatDsiV967FbxpbqVArTMR9iRFS407BlqaxAlNd4BbZca4xzzA+%0AbTfIYdGkjcku1OnuJXRttulUKjdjNbp89cKv0h+m1WGYS1FKcrJQ8hSVqSoAgkAEZGRq5FTv%0APafqdt27NsrhuD9iqw/TY0t95EhosyoUhttbcpsr+C8FYbV5CgRgnGsfT30eVLp8h100F61r%0AomVlooj1ia2tp5lGRwSEhLgCR5J4nyeP5aYVVodv2rRKk5vNflBi0xqCt+XTYqQ0gxG0cTy5%0AkrWkBXHwkeVePkrOqnbxdSNKuO6NtKHRHaTZW38ekzpxjy88GWHkPxI7jrDQ5lXZJcSyPJ7g%0AyR71r7R2Nsltbah3ToV0V687jjocg2lOrdJXApsIgKLkthpwkqQykqcU56zgD5KGiim0Gs2H%0AZCrgepVdo1z3WtqJb0sVR5gFgnCRMZ9JW2jvylFaFJUVLwsYxq0XTHaDdvbf/fYjuNG4HESI%0A6XRhxMBptLMQK/UtIDh/vOq03teFHiQdJnqS2jVfdANx0WG+9VadHUy+zEX25EqJyC8MrGOM%0AhpwB5k5/Ekp9LOqk3BcEOo0Kk2q9Harm4FQ7sK3o8diV26kHHUJ7iyolBZU0hZkl5SnkuDA4%0AcEnRdVbmeMUWFunYtq1qq01KUQKvXKOqrOxGijkgKKShyWyAQQ6jLiU/2jf8RBpey9el3VF3%0Acq93WFNgIjPRGoO3duP1B2fHU0pC2FQ0/u2wQsglwpwfPvTH6SLI6tbJtK8oNMp6abb8htTl%0ArwrvW4mSy7hWODaFK7KDlOQokZA8ezpJUvYrc6uU65LY3dVc9Bu+uTmpc+rV2iOTaTObbWVJ%0AYVOjqUtpvlhWAEpJAz6GGJQWWNvkwqbuHb+yd8yaKlMSLHo1DKzGVn49+cohpBJI+HFx1XpK%0ACdZKncDcu4o177qVdluK4t+n/ZDDQhqI+23zjwnWnAUwkYJcYacSe642lTvtKUmO2dg1Te6/%0AhVqwxOZpMGM1GktSmkNqp8NSUKchhKMht+UpIW40lRSyyooGC4QLqNttsNoZaQlCEAJSlIwE%0AgegB+WvevDnsa+Qr+E6Qu9fTY1dLz902IERaot1Ut+CHzHS9IIwZEd4AmPII8E4Lbg8OJPsV%0AvvCRfK6PKsi64E6dUadAqUqO2/GV9teqr39lKlRQeTnbyri7GU62ClvAQARqLYgWPa1JZqUH%0AekTahRrYkVWt1KQhxMlclh9ppTSS0WJSVKLighK1qzxCvR0T7S1vfTc+zIV10i/6nT25dOFS%0A+yOXJJyhnvSGiElxC1KUPsylY5Hwf01H/e5valSXqpuNNrCm7ZhXM01PlSXEvR3n1trSEyHu%0AyVo4HILOCSNSEqRs3R41Rbtei1C8HGWk/dtwqmpag0p8qVkpcWluM1wW1HcSEJ5K5rCc+iWW%0AjstuDvZd/wDWDeCkU9hzh26gIXYbaaSSUJhsOJC33E8lBMuSn4Anto9K1bW1LUt+x6DGt224%0ACIcGMDxSCVKWsnKlrUfK1qOSpRySSSdSucqB1k14WCSMa1pLVQUD9lcYSfpzSf8A5qEnR9wD%0An7BOpify5NnQLetg7j3rC+7q7EtWpxweSEy4oWW1fzIURlJ/UEHSZuLpK3TqxW21WKLIjKGB%0AEqzLdTZSPySZKFuJH6BY1Es9Hu7UVIbj0vbtCEYDaWmZrCEAcsBKGpKUpHzV4AH4j+Z19Tuj%0ATdSEWBGTYdNTHR2m1QaM0p1KM54pckB1SRnPrHs6Zdm7A39a8tmpvtUGp1BjHbm1RS5jzX/T%0A7hKW/wDsCdNyBE3WTj7dUqQf8rZ1Pw2bkAH26TCV+fBB1JIQ4AOZBP5jWXX/2Q==\" alt=\"\" width=\"90\" height=\"88\"><br>\n\
</td>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=1 cellSpacing=0 cellPadding=2>\n\
<TBODY>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>NUMBER</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 14%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PRECEDENCE</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
<p class=F2>HX</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>STATION OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 8%; VERTICAL-ALIGN: top\">\n\
<p class=F2>CHECK</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
<p class=F2>PLACE OF ORIGIN</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
<p class=F2>TIME FILED</p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F2>DATE</p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:nbr:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:prec:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:hx:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=\"F4\">:sta:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:ck:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:org:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:t1:<br></p>\n\
</TD>\n\
<TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
<p class=F4>:d1:<br></p>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><p class=\"F2\">TO</p></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:to:</p></pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top; TEXT-ALIGN: center\">\n\
<p class=F2>THIS RADIO MESSAGE WAS RECEIVED AT</p>\n\
</td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:rx:</p></pre></td>\n\
<td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><p class=F2>PHONE NUMBER</p></td>\n\
<td><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>:tel:</p></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
<TR>\n\
<TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
<td VALIGN=top><pre><p class=F4>:msg:</p></pre></td>\n\
<td><br><br><br><br><br><br><br><br></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><p class=F4>Signature: :sig:</p></td>\n\
<td><br></td>\n\
</tr>\n\
</table>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE>\n\
</TD>\n\
</TR>\n\
</TBODY>\n\
</TABLE><BR>\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>ORIG FROM:\n:ori:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME:<br>:dt2:</FONT></pre></td>\n\
<td></td>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DLVD TO:\n:dlv:></FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME:<br>:dt3:</FONT></pre></td>\n\
<td></td>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>RCVD FM: :rfm:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>NET: :rnt:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME: :dt4:</FONT></pre></td>\n\
</tr>\n\
</tr>\n\
<tr>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>SENT TO: :sto:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>NET: :snt:</FONT></pre></td>\n\
<td VALIGN=top><pre><FONT face=monospace size=4>DATE/TIME: :dt5:</FONT></pre></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body>\n\
</html>";

const char rri_txt_template[] =
"\
:nbr: :prec::hx: :sta: :ck: :org: :t1: :d1:\n\
:to:\n\
:tel::opn:\n\
BT\n\
:msg:\n\
BT\n\
:sig::op2:\n\
AR\n\
";


