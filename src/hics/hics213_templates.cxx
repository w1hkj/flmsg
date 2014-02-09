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

const char hics213_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<html><head><meta http-equiv=\"CONTENT-TYPE\" content=\"text/html; charset=utf-8\"><title>HICS-213</title><meta name=\"AUTHOR\" content=\"w1hkj\"><meta name=\"CREATED\" content=\"20111028\">\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
</STYLE>\n\
<table border=\"1\" cellpadding=\"2\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"16%\"><col width=\"16%\"><col width=\"16%\"><col width=\"52%\">\n\
<tbody><tr valign=\"top\">\n\
<td colspan=\"4\"><p class=F3><b>HICS-213 – INCIDENT MESSAGE FORM</b></p></td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td colspan=\"3\"><p class=F2><b>1. FROM (Sender):</b><br>:1:</p></td>\n\
<td><p class=F2><b>2. TO (Receiver):</b><br>:2:</p></td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td><p class=F2><b>3. DATE RECEIVED</b></p></td>\n\
<td><p class=F2><b>4. TIME RECEIVED</b></p></td>\n\
<td><p class=F2><b>5. RECEIVED VIA</b></p></td>\n\
<td><p class=F2><b>6. REPLY REQUESTED:</b></p></td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td><p class=F2>:3:</p></td>\n\
<td><p class=F2>:4:</p></td>\n\
<td>\n\
<table border=\"0\" cellpadding=\"1\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<tr>\n\
<td><b>:5a:</b></td><td>Phone</td>\n\
<td><b>:5b:</b></td><td>Radio</td>\n\
</tr>\n\
</table>\n\
</td>\n\
<td>\n\
<table border=\"0\" cellpadding=\"1\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"20%\">\n\
<col width=\"5%\"><col width=\"15%\">\n\
<col width=\"5%\"><col width=\"15%\">\n\
<col width=40%>\n\
<tr><td><p class=F2>Reply</p></td>\n\
<td><p class=F2><b>:6a:</b></p></td><td><p class=F2>Yes</p></td>\n\
<td><p class=F2><b>:6b:</b></p></td><td><p class=F2>No</p></td>\n\
</tr>\n\
</table>\n\
</td></tr>\n\
<tr valign=\"top\">\n\
<td colspan=\"2\"><br>\n\
</td>\n\
<td>\n\
<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<col width=\"10%\"><col width=\"40%\">\n\
<tr>\n\
<td><b>:5c:</b></td><td>Other</td>\n\
</tr>\n\
</table>\n\
</td>\n\
<td><p class=F2><b>If YES, REPLY TO:</b> :6c:</p></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"2\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"15%\">\n\
<col width=\"3%\"><col width=\"20%\">\n\
<col width=\"3%\"><col width=\"20%\">\n\
<col width=\"3%\"><col width=\"20%\">\n\
<col width=\"16%\">\n\
<tbody><tr>\n\
<td><p class=F2><b>7. PRIORITY</b></p></td>\n\
<td><p class=F2><b>:7a:</b></p></td> <td><p class=F2>Urgent - High</p></td>\n\
<td><p class=F2><b>:7b:</b></p></td> <td><p class=F2>Non Urgent – Medium</p></td>\n\
<td><p class=F2><b>:7c:</b></p></td> <td><p class=F2>Informational - Low</p></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<tbody><tr>\n\
<td><p class=F2><b>8. MESSAGE</b> (KEEP ALL MESSAGES / REQUESTS BRIEF, TO THE POINT, AND VERY SPECIFIC):</p>\n\
<pre><p class=F4>:8:</p></pre></td>\n\
</tr>\n\
<tr>\n\
<td><p class=F2><b>9. ACTION TAKEN</b> (if any):<br></p><br>\n\
<pre><p class=F4>:9:</p></pre></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"30%\"><col width=\"20%\"><col width=\"50%\"><tbody>\n\
<tr valign=\"top\">\n\
<td><p class=F2><b>Received by:</b></p></td>\n\
<td><p class=F2><b>Time Received:</b></p></td>\n\
<td><p class=F2><b>Forward to:</b></p></td>\n\
</tr>\n\
<tr>\n\
<td><p class=F2>:10:<br></p></td>\n\
<td><p class=F2>:11:</p></td>\n\
<td><p class=F2>:12:</p></td>\n\
</tr>\n\
<tr><td colspan=\"3\"><p class=F2><b>Comments:</b></p>\n\
<pre><p class=F4>:13:</p></pre></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<col width=\"30%\"><col width=\"20%\"><col width=\"50%\"><tbody>\n\
<tr valign=\"top\">\n\
<td><p class=F2><b>Received by:</b></p></td>\n\
<td><p class=F2><b>Time Received:</b></p></td>\n\
<td><p class=F2><b>Forward to:</b></p></td>\n\
</tr>\n\
<tr>\n\
<td><p class=F2>:14:<br></p></td>\n\
<td><p class=F2>:15:</p></td>\n\
<td><p class=F2>:16:</p></td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\"><p class=F2><b>Comments:</b><br></p>\n\
<pre><p class=F4> :17:</p></pre></td>\n\
</tr>\n\
</tbody></table>\n\
<br>\n\
<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\" width=\"100%\">\n\
<tbody><tr>\n\
<td><p class=F2><b>10. FACILITY NAME</b><br>:18:</p></td>\n\
</tr>\n\
</tbody></table>\n\
\n\
</body></html>\n\
";

const char hics213_text_template[] =
"1. FROM (Sender): :1:\n\
2. TO (Receiver): :2:\n\
3. DATE RECEIVED: :3:\n\
4. TIME RECEIVED: :4:\n\
5a. RECEIVED via PHONE: :5a:\n\
5b. RECEIVED via RADIO: :5b:\n\
5b. RECEIVED via OTHER: :5c:\n\
6a. REPLY REQUESTED YES: :6a:\n\
6b. REPLY REQUESTED NO: :6b:\n\
6c. IF YES REPLY TO: :6c:\n\
7. PRIORITY high: :7a:, medium: :7b:, low: :7c:\n\
8. MESSAGE: :8:\n\
9. ACTION TAKEN: :9:\n\
10. Received by: :10:\n\
11. Time Received: :11:\n\
12. Forward to: :12:\n\
13. Comments: :13:\n\
14. Received by: :14:\n\
15. Time Received: :15:\n\
16. Forward to: :16:\n\
17. Comments: :17:\n\
18. FACILITY NAME :18:\n";
