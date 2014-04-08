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

const char ics205_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html>\n\
<head>\n\
<meta content=\"text/html; charset=UTF-8\" http-equiv=\"content-type\">\n\
<title>:TITLE:</title>\n\
</head>\n\
<body>\n\
<table WIDTH=1000px border=0 cellpadding=0 cellspacing=0>\n\
<tbody>\n\
<tr><td>\n\
<table WIDTH=1000px border=1 cellpadding=2 cellspacing=0>\n\
<tbody>\n\
<tr ALIGN=center>\n\
<td VALIGN=top WIDTH=250px><b>INCIDENT RADIO<br>COMMUNICATIONS PLAN</b></td>\n\
<td VALIGN=top WIDTH=250px>\n\
 <div ALIGN=left>1. Incident Name<br></div><div ALIGN=left>:nam:</div>\n\
</td>\n\
<td VALIGN=top ALIGN=left WIDTH=250px>2. Date/Time Prepared<br>:dt1:</td>\n\
<td VALIGN=top ALIGN=left WIDTH=250px>3. Operational Period<br>\n\
from: :dt2:<br>\n\
__to: :dt3:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td></tr>\n\
<tr><td>\n\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\n\
<tbody>\n\
<tr ALIGN=center>\n\
<td COLSPAN=9 VALIGN=top>4. Basic Radio Channel Utilization<br></td>\n\
</tr>\n\
<tr ALIGN=center>\n\
<td VALIGN=top HALIGN=center WIDTH=30px>LN<br>#<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=160px>Function<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=160px>Channel<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=160px>Assignment<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=115px>Rx Freq<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=115px>Rx Tone<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=115px>Tx Freq<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=115px>Tx Tone<br></td>\n\
<td VALIGN=top HALIGN=center WIDTH=30px>Mode<br>A/D/M<br></td>\n\
</tr>\n\
<tr>\n\
<td>1</td>\n\
<td VALIGN=top>:func00:<br></td>\n\
<td VALIGN=top>:chan00:<br></td>\n\
<td VALIGN=top>:asgn00:<br></td>\n\
<td VALIGN=top>:rxfq00:<br></td>\n\
<td VALIGN=top>:rxtn00:<br></td>\n\
<td VALIGN=top>:txfq00:<br></td>\n\
<td VALIGN=top>:txtn00:<br></td>\n\
<td VALIGN=top>:mode00:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk00:<br></td>\n\
</tr>\n\
<tr>\n\
<td>2</td>\n\
<td VALIGN=top>:func01:<br></td>\n\
<td VALIGN=top>:chan01:<br></td>\n\
<td VALIGN=top>:asgn01:<br></td>\n\
<td VALIGN=top>:rxfq01:<br></td>\n\
<td VALIGN=top>:rxtn01:<br></td>\n\
<td VALIGN=top>:txfq01:<br></td>\n\
<td VALIGN=top>:txtn01:<br></td>\n\
<td VALIGN=top>:mode01:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk01:<br></td>\n\
</tr>\n\
<tr>\n\
<td>3</td>\n\
<td VALIGN=top>:func02:<br></td>\n\
<td VALIGN=top>:chan02:<br></td>\n\
<td VALIGN=top>:asgn02:<br></td>\n\
<td VALIGN=top>:rxfq02:<br></td>\n\
<td VALIGN=top>:rxtn02:<br></td>\n\
<td VALIGN=top>:txfq02:<br></td>\n\
<td VALIGN=top>:txtn02:<br></td>\n\
<td VALIGN=top>:mode02:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk02:<br></td>\n\
</tr>\n\
<tr>\n\
<td>4</td>\n\
<td VALIGN=top>:func03:<br></td>\n\
<td VALIGN=top>:chan03:<br></td>\n\
<td VALIGN=top>:asgn03:<br></td>\n\
<td VALIGN=top>:rxfq03:<br></td>\n\
<td VALIGN=top>:rxtn03:<br></td>\n\
<td VALIGN=top>:txfq03:<br></td>\n\
<td VALIGN=top>:txtn03:<br></td>\n\
<td VALIGN=top>:mode03:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk03:<br></td>\n\
</tr>\n\
<tr>\n\
<td>5</td>\n\
<td VALIGN=top>:func04:<br></td>\n\
<td VALIGN=top>:chan04:<br></td>\n\
<td VALIGN=top>:asgn04:<br></td>\n\
<td VALIGN=top>:rxfq04:<br></td>\n\
<td VALIGN=top>:rxtn04:<br></td>\n\
<td VALIGN=top>:txfq04:<br></td>\n\
<td VALIGN=top>:txtn04:<br></td>\n\
<td VALIGN=top>:mode04:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk04:<br></td>\n\
</tr>\n\
<tr>\n\
<td>6</td>\n\
<td VALIGN=top>:func05:<br></td>\n\
<td VALIGN=top>:chan05:<br></td>\n\
<td VALIGN=top>:asgn05:<br></td>\n\
<td VALIGN=top>:rxfq05:<br></td>\n\
<td VALIGN=top>:rxtn05:<br></td>\n\
<td VALIGN=top>:txfq05:<br></td>\n\
<td VALIGN=top>:txtn05:<br></td>\n\
<td VALIGN=top>:mode05:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk05:<br></td>\n\
</tr>\n\
<tr>\n\
<td>7</td>\n\
<td VALIGN=top>:func06:<br></td>\n\
<td VALIGN=top>:chan06:<br></td>\n\
<td VALIGN=top>:asgn06:<br></td>\n\
<td VALIGN=top>:rxfq06:<br></td>\n\
<td VALIGN=top>:rxtn06:<br></td>\n\
<td VALIGN=top>:txfq06:<br></td>\n\
<td VALIGN=top>:txtn06:<br></td>\n\
<td VALIGN=top>:mode06:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk06:<br></td>\n\
</tr>\n\
<tr>\n\
<td>8</td>\n\
<td VALIGN=top>:func07:<br></td>\n\
<td VALIGN=top>:chan07:<br></td>\n\
<td VALIGN=top>:asgn07:<br></td>\n\
<td VALIGN=top>:rxfq07:<br></td>\n\
<td VALIGN=top>:rxtn07:<br></td>\n\
<td VALIGN=top>:txfq07:<br></td>\n\
<td VALIGN=top>:txtn07:<br></td>\n\
<td VALIGN=top>:mode07:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk07:<br></td>\n\
</tr>\n\
<tr>\n\
<tr>\n\
<td>9</td>\n\
<td VALIGN=top>:func08:<br></td>\n\
<td VALIGN=top>:chan08:<br></td>\n\
<td VALIGN=top>:asgn08:<br></td>\n\
<td VALIGN=top>:rxfq08:<br></td>\n\
<td VALIGN=top>:rxtn08:<br></td>\n\
<td VALIGN=top>:txfq08:<br></td>\n\
<td VALIGN=top>:txtn08:<br></td>\n\
<td VALIGN=top>:mode08:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk08:<br></td>\n\
</tr>\n\
<tr>\n\
<td>10</td>\n\
<td VALIGN=top>:func09:<br></td>\n\
<td VALIGN=top>:chan09:<br></td>\n\
<td VALIGN=top>:asgn09:<br></td>\n\
<td VALIGN=top>:rxfq09:<br></td>\n\
<td VALIGN=top>:rxtn09:<br></td>\n\
<td VALIGN=top>:txfq09:<br></td>\n\
<td VALIGN=top>:txtn09:<br></td>\n\
<td VALIGN=top>:mode09:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk09:<br></td>\n\
</tr>\n\
<tr>\n\
<td>11</td>\n\
<td VALIGN=top>:func10:<br></td>\n\
<td VALIGN=top>:chan10:<br></td>\n\
<td VALIGN=top>:asgn10:<br></td>\n\
<td VALIGN=top>:rxfq10:<br></td>\n\
<td VALIGN=top>:rxtn10:<br></td>\n\
<td VALIGN=top>:txfq10:<br></td>\n\
<td VALIGN=top>:txtn10:<br></td>\n\
<td VALIGN=top>:mode10:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk10:<br></td>\n\
</tr>\n\
<tr>\n\
<td>12</td>\n\
<td VALIGN=top>:func11:<br></td>\n\
<td VALIGN=top>:chan11:<br></td>\n\
<td VALIGN=top>:asgn11:<br></td>\n\
<td VALIGN=top>:rxfq11:<br></td>\n\
<td VALIGN=top>:rxtn11:<br></td>\n\
<td VALIGN=top>:txfq11:<br></td>\n\
<td VALIGN=top>:txtn11:<br></td>\n\
<td VALIGN=top>:mode11:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk11:<br></td>\n\
</tr>\n\
<tr>\n\
<td>13</td>\n\
<td VALIGN=top>:func12:<br></td>\n\
<td VALIGN=top>:chan12:<br></td>\n\
<td VALIGN=top>:asgn12:<br></td>\n\
<td VALIGN=top>:rxfq12:<br></td>\n\
<td VALIGN=top>:rxtn12:<br></td>\n\
<td VALIGN=top>:txfq12:<br></td>\n\
<td VALIGN=top>:txtn12:<br></td>\n\
<td VALIGN=top>:mode12:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk12:<br></td>\n\
</tr>\n\
<tr>\n\
<td>14</td>\n\
<td VALIGN=top>:func13:<br></td>\n\
<td VALIGN=top>:chan13:<br></td>\n\
<td VALIGN=top>:asgn13:<br></td>\n\
<td VALIGN=top>:rxfq13:<br></td>\n\
<td VALIGN=top>:rxtn13:<br></td>\n\
<td VALIGN=top>:txfq13:<br></td>\n\
<td VALIGN=top>:txtn13:<br></td>\n\
<td VALIGN=top>:mode13:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk13:<br></td>\n\
</tr>\n\
<tr>\n\
<td>15</td>\n\
<td VALIGN=top>:func14:<br></td>\n\
<td VALIGN=top>:chan14:<br></td>\n\
<td VALIGN=top>:asgn14:<br></td>\n\
<td VALIGN=top>:rxfq14:<br></td>\n\
<td VALIGN=top>:rxtn14:<br></td>\n\
<td VALIGN=top>:txfq14:<br></td>\n\
<td VALIGN=top>:txtn14:<br></td>\n\
<td VALIGN=top>:mode14:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk14:<br></td>\n\
</tr>\n\
<tr>\n\
<td>16</td>\n\
<td VALIGN=top>:func15:<br></td>\n\
<td VALIGN=top>:chan15:<br></td>\n\
<td VALIGN=top>:asgn15:<br></td>\n\
<td VALIGN=top>:rxfq15:<br></td>\n\
<td VALIGN=top>:rxtn15:<br></td>\n\
<td VALIGN=top>:txfq15:<br></td>\n\
<td VALIGN=top>:txtn15:<br></td>\n\
<td VALIGN=top>:mode15:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk15:<br></td>\n\
</tr>\n\
<tr>\n\
<td>17</td>\n\
<td VALIGN=top>:func16:<br></td>\n\
<td VALIGN=top>:chan16:<br></td>\n\
<td VALIGN=top>:asgn16:<br></td>\n\
<td VALIGN=top>:rxfq16:<br></td>\n\
<td VALIGN=top>:rxtn16:<br></td>\n\
<td VALIGN=top>:txfq16:<br></td>\n\
<td VALIGN=top>:txtn16:<br></td>\n\
<td VALIGN=top>:mode16:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk16:<br></td>\n\
</tr>\n\
<tr>\n\
<td>18</td>\n\
<td VALIGN=top>:func17:<br></td>\n\
<td VALIGN=top>:chan17:<br></td>\n\
<td VALIGN=top>:asgn17:<br></td>\n\
<td VALIGN=top>:rxfq17:<br></td>\n\
<td VALIGN=top>:rxtn17:<br></td>\n\
<td VALIGN=top>:txfq17:<br></td>\n\
<td VALIGN=top>:txtn17:<br></td>\n\
<td VALIGN=top>:mode17:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk17:<br></td>\n\
</tr>\n\
<tr>\n\
<td>19</td>\n\
<td VALIGN=top>:func18:<br></td>\n\
<td VALIGN=top>:chan18:<br></td>\n\
<td VALIGN=top>:asgn18:<br></td>\n\
<td VALIGN=top>:rxfq18:<br></td>\n\
<td VALIGN=top>:rxtn18:<br></td>\n\
<td VALIGN=top>:txfq18:<br></td>\n\
<td VALIGN=top>:txtn18:<br></td>\n\
<td VALIGN=top>:mode18:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk18:<br></td>\n\
</tr>\n\
<tr>\n\
<td>20</td>\n\
<td VALIGN=top>:func19:<br></td>\n\
<td VALIGN=top>:chan19:<br></td>\n\
<td VALIGN=top>:asgn19:<br></td>\n\
<td VALIGN=top>:rxfq19:<br></td>\n\
<td VALIGN=top>:rxtn19:<br></td>\n\
<td VALIGN=top>:txfq19:<br></td>\n\
<td VALIGN=top>:txtn19:<br></td>\n\
<td VALIGN=top>:mode19:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk19:<br></td>\n\
</tr>\n\
<tr>\n\
<td COLSPAN = 4 VALIGN=top>5. Prepared by (Communications unit)<br>:prp:<br></td>\n\
<td COLSPAN = 5 VALIGN=top>6. Incident Location<br>\n\
County: :cnty:  State: :stat: Lat: :lat: Lon: :lon:<br>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td></tr>\n\
</tbody>\n\
</table>\n\
</body>\n\
</html>";

const char ics205_text_template[] =
"ICS 205 INCIDENT RADIO COMMUNICATIONS PLAN\n\n\
Incident name: :nam:\n\
Date/Time Prepared: :dt1:\n\
Operational Period Date/Time from: :dt2:\n\
Operational Period Date/Time to: :dt3:\n\
System/Cache #1: :func00:\n\
Channel #1: :chan00:\n\
Function #1: :func00:\n\
Rx Freq/Tone #1: :rxfq00: :rxtn00:\n\
Tx Freq/Tone #1: :txfq00: :txtn00:\n\
Assignment #1: :mode00:\n\
Remarks #1: :rmrk00:\n\
System/Cache #2: :func01:\n\
Channel #2: :chan01:\n\
Function #2: :asgn01:\n\
Rx Freq/Tone #2: :rxfq01: :rxtn01:\n\
Tx Freq/Tone #2: :txfq01: :txtn01:\n\
Assignment #2: :mode01:\n\
Remarks #2: :rmrk01:\n\
System/Cache #3: :func02:\n\
Channel #3: :chan02:\n\
Function #3: :asgn02:\n\
Rx Freq/Tone #3: :rxfq02: :rxtn02:\n\
Tx Freq/Tone #3: :txfq02: :txtn02:\n\
Assignment #3: :mode02:\n\
Remarks #3: :rmrk02:\n\
System/Cache #4: :func03:\n\
Channel #4: :chan03:\n\
Function #4: :asgn03:\n\
Rx Freq/Tone #4: :rxfq03: :rxtn03:\n\
Tx Freq/Tone #4: :txfq03: :txtn03:\n\
Assignment #4: :mode03:\n\
Remarks #4: :rmrk03:\n\
System/Cache #5: :func04:\n\
Channel #5: :chan04:\n\
Function #5: :asgn04:\n\
Rx Freq/Tone #5: :rxfq04: :rxtn04:\n\
Tx Freq/Tone #5: :txfq04: :txtn04:\n\
Assignment #5: :mode04:\n\
Remarks #5: :rmrk04:\n\
System/Cache #6: :func05:\n\
Channel #6: :chan05:\n\
Function #6: :asgn05:\n\
Rx Freq/Tone #6: :rxfq05: :rxtn05:\n\
Tx Freq/Tone #6: :txfq05: :txtn05:\n\
Assignment #6: :mode05:\n\
Remarks #6: :rmrk05:\n\
System/Cache #7: :func06:\n\
Channel #7: :chan06:\n\
Function #7: :asgn06:\n\
Rx Freq/Tone #7: :rxfq06: :rxtn06:\n\
Tx Freq/Tone #7: :txfq06: :txtn06:\n\
Assignment #7: :mode06:\n\
Remarks #7: :rmrk06:\n\
System/Cache #8: :func07:\n\
Channel #8: :chan07:\n\
Function #8: :asgn07:\n\
Rx Freq/Tone #8: :rxfq07: :rxtn07:\n\
Tx Freq/Tone #8: :txfq07: :txtn07:\n\
Assignment #8: :mode07:\n\
Remarks #8: :rmrk07:\n\
System/Cache #9: :func08:\n\
Channel #9: :chan08:\n\
Function #9: :asgn08:\n\
Rx Freq/Tone #9: :rxfq08: :rxtn08:\n\
Tx Freq/Tone #9: :txfq08: :txtn08:\n\
Assignment #9: :mode08:\n\
Remarks #9: :rmrk08:\n\
System/Cache #10: :func09:\n\
Channel #10: :chan09:\n\
Function #10: :asgn09:\n\
Rx Freq/Tone #10: :rxfq09: :rxtn09:\n\
Tx Freq/Tone #10: :txfq09: :txtn09:\n\
Assignment #10: :mode09:\n\
Remarks #10: :rmrk09:\n\
System/Cache #11: :func10:\n\
Channel #11: :chan10:\n\
Function #11: :asgn10:\n\
Rx Freq/Tone #11: :rxfq10: :rxtn10:\n\
Tx Freq/Tone #11: :txfq10: :txtn10:\n\
Assignment #11: :mode10:\n\
Remarks #11: :rmrk10:\n\
System/Cache #12: :func11:\n\
Channel #12: :chan11:\n\
Function #12: :asgn11:\n\
Rx Freq/Tone #12: :rxfq11: :rxtn11:\n\
Tx Freq/Tone #12: :txfq11: :txtn11:\n\
Assignment #12: :mode11:\n\
Remarks #12: :rmrk11:\n\
System/Cache #13: :func12:\n\
Channel #13: :chan12:\n\
Function #13: :asgn12:\n\
Rx Freq/Tone #13: :rxfq12: :rxtn12:\n\
Tx Freq/Tone #13: :txfq12: :txtn12:\n\
Assignment #13: :mode12:\n\
Remarks #13: :rmrk12:\n\
System/Cache #14: :func13:\n\
Channel #14: :chan13:\n\
Function #14: :asgn13:\n\
Rx Freq/Tone #14: :rxfq13: :rxtn13:\n\
Tx Freq/Tone #14: :txfq13: :txtn13:\n\
Assignment #14: :mode13:\n\
Remarks #14: :rmrk13:\n\
System/Cache #15: :func14:\n\
Channel #15: :chan14:\n\
Function #15: :asgn14:\n\
Rx Freq/Tone #15: :rxfq14: :rxtn14:\n\
Tx Freq/Tone #15: :txfq14: :txtn14:\n\
Assignment #15: :mode14:\n\
Remarks #15: :rmrk14:\n\
System/Cache #16: :func15:\n\
Channel #16: :chan15:\n\
Function #16: :asgn15:\n\
Rx Freq/Tone #16: :rxfq15: :rxtn15:\n\
Tx Freq/Tone #16: :txfq15: :txtn15:\n\
Assignment #16: :mode15:\n\
Remarks #16: :rmrk15:\n\
System/Cache #17: :func16:\n\
Channel #17: :chan16:\n\
Function #17: :asgn16:\n\
Rx Freq/Tone #17: :rxfq16: :rxtn16:\n\
Tx Freq/Tone #17: :txfq16: :txtn16:\n\
Assignment #17: :mode16:\n\
Remarks #17: :rmrk16:\n\
System/Cache #18: :func17:\n\
Channel #18: :chan17:\n\
Function #18: :asgn17:\n\
Rx Freq/Tone #18: :rxfq17: :rxtn17:\n\
Tx Freq/Tone #18: :txfq17: :txtn17:\n\
Assignment #18: :mode17:\n\
Remarks #18: :rmrk17:\n\
System/Cache #19: :func18:\n\
Channel #19: :chan18:\n\
Function #19: :asgn18:\n\
Rx Freq/Tone #19: :rxfq18: :rxtn18:\n\
Tx Freq/Tone #19: :txfq18: :txtn18:\n\
Assignment #19: :mode18:\n\
Remarks #19: :rmrk18:\n\
System/Cache #20: :func19:\n\
Channel #20: :chan19:\n\
Function #20: :asgn19:\n\
Rx Freq/Tone #20: :rxfq19: :rxtn19:\n\
Tx Freq/Tone #20: :txfq19: :txtn19:\n\
Assignment #20: :mode19:\n\
Remarks #20: :rmrk19:\n\
Prepared by (Communications unit): :prp:\n\
County: :cnty:\n\
State: :stat:\n\
Latitude: :lat:\n\
Longitude: :lon:\n";
