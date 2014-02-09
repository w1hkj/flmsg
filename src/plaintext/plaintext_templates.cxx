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

const char pt_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head><meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\
<title>:tt:</title>\
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

