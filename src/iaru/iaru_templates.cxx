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

const char iaru_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\"><title>iaru</title>\n\
<meta content=\"w1hkj\" name=\"author\">\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 8pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
p.F6 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
</STYLE>\n\
</head>\n\
<body>\n\
<table style=\"text-align: left; width: 100%;\" border=0 cellpadding=0 cellspacing=0>\n\
<tr>\n\
<td VALIGN=top ALIGN=center><p class=F5><b>IARU MESSAGE</b></p></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center; width: 15%;\">\n\
<p class=F2>NUMBER</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 15%;\">\n\
<p class=F2>PRECEDENCE</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\">\n\
<p class=F2>STATION OF ORIGIN</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\">\n\
<p class=F2>CHECK</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\">\n\
<p class=F2>PLACE OF ORIGIN</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\">\n\
<p class=F2>FILING TIME</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\">\n\
<p class=F2>FILING DATE</p></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:nbr:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:prec:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:sta:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:ck:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:org:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:t1:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:d1:<br></p></td>\n\
</tr>\n\
</table>\n\
<br>\n\
<table width=100% border=1 cellpadding=2 cellspacing=0>\n\
<tr><td>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
	<td VALIGN=top>\n\
	<p class=F2><B>To:</B></p><br>\n\
	<pre><p class=F4>:to:</p></pre></td>\n\
	<td><br><br><br></td>\n\
</tr>\n\
<tr>\n\
	<td VALIGN=top>\n\
	<pre><p class=F4>:msg:</p></pre></td>\n\
	<td><br><br><br><br><br><br><br><br><br></td>\n\
</tr>\n\
<tr>\n\
	<td VALIGN=top>\n\
	<p class=F2><B>From:</B></p>\n\
	<pre><p class=F4>:fm:</p></pre></td>\n\
	<td><br><br><br></td>\n\
</tr>\n\
</table>\n\
</td></tr>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center; width: 24%;\">\n\
<p class=F2>RECEIVED FROM</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\">\n\
<p class=F2>DATE</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\">\n\
<p class=F2>TIME</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 4%;\" ROWSPAN=2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 24%;\">\n\
<p class=F2>SENT TO</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\">\n\
<p class=F2>DATE</p></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\">\n\
<p class=F2>TIME</p></td>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:rcv:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:d2:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:t2:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:sto:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:d3:<br></p></td>\n\
<td style=\"vertical-align: top; text-align: center;\">\n\
<p class=F4>:t3:<br></p></td>\n\
</tr>\n\
</table>\n\
</td>\n\
</tr>\n\
</table>\n\
<br>\n\
</body></html>\n\
";

const char iaru_txt_template[] =
":nbr: :prec: :sta: :ck: :org: :t1: :d1:\n\
:to:\n\
BT\n\
:msg:\n\
BT\n\
:fm:\n\
AR\n\
";

