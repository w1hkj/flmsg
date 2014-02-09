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

const char cap105_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html>\n\
<head><meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\n\
<title>:TITLE:</title>\n\
</head>\n\
<body>\n\
<table cellpadding=\"0\" cellspacing=\"0\" width=\"800\">\n\
<col width=\"90\"><col width=\"10\"><col width=\"250\">\n\
<col width=\"90\"><col width=\"10\"><col width=\"250\">\n\
<tbody>\n\
<tr>\n\
<td colspan=\"6\" style=\"border-style: solid solid none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px; padding: 0in 0.08in;\" valign=\"top\">\n\
<p align=\"center\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
<b>CAP RADIO MESSAGE FORM</b>\n\
</font></font>\n\
</p>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"6\" align= \"right\" style=\"border-style: solid solid none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px; padding: 0in 0.08in;\" valign=\"top\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
Page :pg: of :npgs: Pages\n\
</font></font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
<tbody>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: solid none none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
MSG NUMBER: \n\
</font></font>\n\
</td>\n\
<td style=\"border-style: solid none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: solid solid none none; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:msg nbr:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
PRECEDENCE:\n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:prec:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
DTG:\n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:dtm:</font></font>\n\
</td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
FROM:\n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:from:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
TO:\n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:to:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
INFO: \n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:info:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
SUBJ: \n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:subj:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr><td colspan=\"6\" style=\"border-style: none solid none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1pt; padding: 0in 0in 0in 0.08in;\"><br></td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td align=\"right\" style=\"border-style: none none none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 0px 1px; padding: 0in 0in 0in 0in;\" >\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
GROUP COUNT: \n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none;  border-width: 1px 1px 1px 1px; padding-bottom: 0in; padding-left: 0in; padding-right: 0in;\"></td>\n\
<td align=\"left\" colspan=\"4\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 0px 1px 0px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:grpcnt:\n\
</font></font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
<tbody>\n\
<tr>\n\
<td colspan=\"6\" style=\"border-style: solid solid none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1pt; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
BREAK\n\
</font></font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
<tbody>\n\
<tr valign=\"top\">\n\
<td colspan=\"2\" valign=\"top\" height=\"600px\" style=\"border-style: solid none none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\"></td>\n\
<td align=\"justify\" colspan=\"4\" style=\"border-style: solid solid none none; border-color: rgb(0, 0, 10) rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:msgtxt:\n\
</font></font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
<tbody>\n\
<tr>\n\
<td colspan=\"6\" style=\"border-style: solid solid none solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
BREAK\n\
</font></font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
<tbody>\n\
<tr>\n\
<td colspan=\"3\" style=\"border-style: solid solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in;\" bgcolor=\"#bfbfbf\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
MESSAGE RECEIVED\n\
</font></font>\n\
</td>\n\
<td colspan=\"3\" style=\"border-style: solid solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\" bgcolor=\"#bfbfbf\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
MESSAGE SENT\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
FROM:\n\
</font></font>\n\
</td>\n\
<td colspan=\"2\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:rcvd_fm:\n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
TO:\n\
</font></font>\n\
</td>\n\
<td colspan=\"2\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:sent_to:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"border-style: none none none solid; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
DTG:\n\
</font></font>\n\
</td>\n\
<td colspan=\"2\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:rcvd_dtm:\n\
</font></font>\n\
</td>\n\
<td style=\"border-style: none none none none; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
DTG:\n\
</font></font>\n\
</td>\n\
<td colspan=\"2\" style=\"border-style: none solid none none; border-color: rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0.08in 0in 0in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
:sent_dtm:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
RECEIVING OPERATOR INITIALS: :rcvop:\n\
</font></font>\n\
</td>\n\
<td colspan=\"3\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
SENDING OPERATOR INITIALS: :sendop:\n\
</font></font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table cellpadding=\"0\" cellspacing=\"0\" width=\"800\">\n\
<col width=\"450\"><col width=\"450\">\n\
<tbody>\n\
<tr>\n\
<font face=\"Arial, serif\">\n\
<td align=\"left\"><b>Flmsg CAP FORM 105</b></td>\n\
</font>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body>\n\
</html>\n\
";

const char cap105_txt_template[] =
"Flmsg CAP RADIO MESSAGE FORM\n\n\
MSG NUMBER:  :msg nbr:\n\
PRECEDENCE:  :prec:\n\
DTG:         :dtm:\n\
FROM:        :from:\n\
TO:          :to:\n\
INFO:        :info:\n\
SUBJ:        :subj:\n\
\n\
GROUP COUNT: :grpcnt:\n\
\n\
BREAK\n\n\
:msgtxt:\n\n\
BREAK\n\n\
MESSAGE RECEIVED                        MESSAGE SENT\n\
FROM: :rcvd_fm:                         TO:   :sent_to:\n\
DTG:  :rcvd_dtm:                        DTG::sent_dtm:\n\
RECEIVING OPERATOR INITIALS: :rcvop:    SENDING OPERATOR INITIALS: :sendop:\n\
";

//==============================================================================
const char cap110_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html>\n\
<head><meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\n\
<title>:TITLE:</title>\n\
</head>\n\
<body>\n\
<table cellpadding=\"0\" cellspacing=\"0\" width=\"910\">\n\
<col width=\"90\"><col width=\"40\"><col width=\"12\">\n\
<col width=\"105\"><col width=\"135\"><col width=\"134\">\n\
<col width=\"134\"><col width=\"9\"><col width=\"125\">\n\
<tbody>\n\
<tr>\n\
<td align=\"center\" colspan=\"8\" style=\"border-style: solid solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px; padding: 0in 0.08in;\" valign=\"top\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
<b>Communications Log</b>\n\
</font></font>\n\
</td>\n\
<td align=\"left\" style=\"border-style: solid solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10) -moz-use-text-color; border-width: 1px 1px 1px; padding: 0in 0.08in;\" valign=\"top\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">\n\
Page 1 of 1 Pages\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr valign=\"top\">\n\
<td colspan=\"2\" align=\"left\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
MISSION NUMBER<br><font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:mnbr:\n\
</font></font>\n\
</td>\n\
<td colspan=\"6\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
STATION FUNCTIONAL DESIGNATOR OR LOCATION<br><font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:sta:\n\
</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
DATE<br><font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:date:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"10\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
DESIGNATOR / SOURCE\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" align=\"left\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
A<br>\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:ds_a:\n\
</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
B<br>\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:ds_b:\n\
</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
C<br>\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:ds_c:\n\
</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
D<br>\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:ds_d:\n\
</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
E<br>\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:ds_e:\n\
</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">\n\
F<br>\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:ds_f:\n\
</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">TIME</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">CALL</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">CH REF</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 9pt;\">REMARKS</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[0]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[0]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[0]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[0]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[1]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[1]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[1]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[1]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[2]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[2]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[2]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[2]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[3]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[3]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[3]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[3]:</font></font>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[4]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[4]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[4]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[4]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[5]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[5]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[5]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[5]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[6]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[6]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[6]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[6]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[7]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[7]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[7]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[7]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[8]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[8]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[8]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[8]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[9]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[9]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[9]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[9]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[10]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[10]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[10]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[10]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[11]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[11]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[11]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[11]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[12]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[12]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[12]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[12]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[13]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[13]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[13]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[13]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[14]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[14]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[14]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[14]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[15]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[15]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[15]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[15]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[16]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[16]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[16]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[16]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[17]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[17]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[17]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[17]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[18]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[18]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[18]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[18]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[19]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[19]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[19]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[19]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[20]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[20]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[20]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[20]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[21]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[21]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[21]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[21]:</font></font>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid solid; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:time[22]:</font></font>\n\
</td>\n\
<td colspan=\"2\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:call[22]:</font></font>\n\
</td>\n\
<td colspan=\"1\" align=\"center\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:chref[22]:</font></font>\n\
</td>\n\
<td colspan=\"5\" align=\"left\" style=\"border-style: none solid solid none; border-color: rgb(0, 0, 10) rgb(0, 0, 10); border-width: 1px 1px 1px 1px; padding: 0in 0in 0in 0.08in;\">\n\
<font face=\"Arial, serif\"><font style=\"font-size: 11pt;\">:rem[22]:</font></font>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table cellpadding=\"0\" cellspacing=\"0\" width=\"910\">\n\
<col width=\"450\"><col width=\"460\">\n\
<tbody>\n\
<tr>\n\
<font face=\"Arial, serif\">\n\
<td align=\"left\"><b>Flmsg CAP FORM 110</b></td>\n\
</font>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body>\n\
</html>\n\
";

const char cap110_text_template[] =
"Flmsg CAP Communications Report\n\n\
Mission number....:mnbr:\n\
Station...........:sta:\n\
Date..............:date:\n\
Desig/Src A.......:ds_a:\n\
Desig/Src B.......:ds_b:\n\
Desig/Src C.......:ds_c:\n\
Desig/Src D.......:ds_d:\n\
Desig/Src E.......:ds_e:\n\
Desig/Src F.......:ds_f:\n\n\
:logdata:";

