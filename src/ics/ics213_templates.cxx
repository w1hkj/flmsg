// ----------------------------------------------------------------------------
// Copyright (C) 2014
//David Freese, W1HKJ
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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include "templates.h"

const char ics213_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html>\n\
<head>\n\
<meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\n\
<title>:TITLE:</title>\n\
</head>\n\
<body>\n\
<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"1000px\"\n\
align=\"center\">\n\
<tbody>\n\
<tr>\n\
<td>\n\
<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\"\n\
width=\"100%\" align=\"center\">\n\
<tbody>\n\
<tr>\n\
<td align=\"center\"><font face=\"monospace\"><big><big><b>GENERAL\n\
MESSAGE (ICS-213)</b></big></big></font></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
<td><font face=\"monospace\"><br>\n\
<br>\n\
</font></td>\n\
</tr>\n\
<tr>\n\
<td>\n\
<table border=\"1\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"center\">\n\
<tbody>\n\
<tr>\n\
<td valign=\"top\" width=\"100%\"><font face=\"monospace\"><b>1.\n\
Incident Name</b> (optional): :inc:</font></td>\n\
</tr>\n\
<tr>\n\
<td valign=\"top\" width=\"100%\">\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"left\">\n\
<tbody>\n\
<tr>\n\
<td valign=\"top\" width=\"60%\"><font\n\
face=\"monospace\"><b>2. To</b> (Name and\n\
Position): :to:</font></td>\n\
<td valign=\"top\" width=\"40%\"><font\n\
face=\"monospace\">:p1:</font></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td valign=\"top\">\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"left\">\n\
<tbody>\n\
<tr>\n\
<td valign=\"top\" width=\"60%\"><font\n\
face=\"monospace\"><b>3. From</b> (Name and\n\
Position): :fm:</font></td>\n\
<td valign=\"top\" width=\"40%\"><font\n\
face=\"monospace\">:p2:</font></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td valign=\"top\">\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"left\">\n\
<tbody>\n\
<tr>\n\
<td valign=\"top\" width=\"60%\"> <font\n\
face=\"monospace\"><b>4. Subject</b> : :sb: </font></td>\n\
<td valign=\"top\" width=\"20%\"><font\n\
face=\"monospace\"><b>5. Date</b> : :d1: </font></td>\n\
<td valign=\"top\" width=\"20%\"><font\n\
face=\"monospace\"><b>6. Time</b> :t1: </font></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td valign=\"top\">\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"left\">\n\
<tbody>\n\
<tr>\n\
<td> <font face=\"monospace\"><b>7. Message</b>\n\
:<br>\n\
:mg:<br>\n\
</font> </td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td>\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"left\">\n\
<tbody>\n\
<tr>\n\
<td width=\"35%\"><font face=\"monospace\"><b>8.\n\
Approved by:</b> Name : :s1:</font></td>\n\
<td width=\"30%\"><font face=\"monospace\">Signature : _____________________</font></td>\n\
<td width=\"35%\"><font face=\"monospace\">Position/Title : :p3:</font></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td valign=\"top\">\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"left\">\n\
<tbody>\n\
<tr>\n\
<td> <font face=\"monospace\"><b>9. Reply</b> :\n\
<br>\n\
:rp:<br>\n\
</font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td valign=\"top\">\n\
<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\"\n\
width=\"100%\" align=\"left\">\n\
<tbody>\n\
<tr>\n\
<td width=\"35%\"><font face=\"monospace\"><b>10.\n\
Replied by: Name</b> : :s2:</font></td>\n\
<td width=\"30%\"><font face=\"monospace\">Position/Title :\n\
:p4:</font></td>\n\
<td width=\"35%\"><font face=\"monospace\">Signature: ___________________</font></td>\n\
</tr>\n\
<tr>\n\
<td width=\"30%\"><font face=\"monospace\"><b>ICS-213</b></font></td>\n\
<td width=\"35%\"><font face=\"monospace\">Date/Time :\n\
:d2:</font></td>\n\
<td width=\"35%\"><font face=\"monospace\">\n\
:t2:</font></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body>\n\
</html>";

const char ics213_text_template[] =
"GENERAL MESSAGE (ICS 213)\n\
1. Incident Name: :inc:\n\
2. To: :to:, :p1:\n\
3. From: :fm:, :p2:\n\
4. Subject: :sb:\n\
5. Date: :d1:\n\
6. Time: :t1:\n\
7. Message:\n\
:mg:\n\
\n\
8. Approved by: \n\
Name: :s1:\n\
Signature:\n\
Position/Title: :p3:\n\
\n\
9. Reply:\n\
:rp:\n\
\n\
10. Replied by: \n\
Name: :s2: \n\
Position/Title: :p4:\n\
Signature:\n\
Date/Time: :d2:,  :t2:\n\
\n\
ICS213\n";

