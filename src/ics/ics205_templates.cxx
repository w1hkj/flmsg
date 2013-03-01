// =====================================================================
//
// ics205_templates.cxx
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
// ics205 form template
//======================================================================

#include "templates.h"

const char ics205_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html>\
<head>\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\
<title>:TITLE:</title>\
</head>\
<body>\
<table ALIGN=left WIDTH=1000px border=1 cellpadding=2 cellspacing=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=4 VALIGN=top WIDTH=250px><b>INCIDENT RADIO<br>COMMUNICATIONS PLAN</b></td>\
<td COLSPAN=4 VALIGN=top WIDTH=250px>\
 <div ALIGN=left>1. Incident Name<br></div><div ALIGN=left>:nam:</div>\
</td>\
<td VALIGN=top ALIGN=left WIDTH=250px>2. Date/Time Prepared<br>:dt1:</td>\
<td VALIGN=top ALIGN=left WIDTH=250px>3. Operational Period<br>\
from: :dt2:<br>\
__to: :dt3:</td>\
</tr>\
</tbody>\
</table>\
<table ALIGN=left WIDTH=1000px BORDER=1 CELLPADDING=2 CELLSPACING=0>\
<tbody>\
<tr ALIGN=center>\
<td COLSPAN=9 VALIGN=top>4. Basic Radio Channel Utilization<br></td>\
</tr>\
<tr ALIGN=center>\
<td VALIGN=top HALIGN=center WIDTH=30px>LN<br>#<br></td>\
<td VALIGN=top HALIGN=center WIDTH=160px>Function<br></td>\
<td VALIGN=top HALIGN=center WIDTH=160px>Channel<br></td>\
<td VALIGN=top HALIGN=center WIDTH=160px>Assignment<br></td>\
<td VALIGN=top HALIGN=center WIDTH=115px>Rx Freq<br></td>\
<td VALIGN=top HALIGN=center WIDTH=115px>Rx Tone<br></td>\
<td VALIGN=top HALIGN=center WIDTH=115px>Tx Freq<br></td>\
<td VALIGN=top HALIGN=center WIDTH=115px>Tx Tone<br></td>\
<td VALIGN=top HALIGN=center WIDTH=30px>Mode<br>A/D/M<br></td>\
</tr>\
<tr>\
<td>1</td><td VALIGN=top>:func0:<br></td>\
<td VALIGN=top>:chan0:<br></td>\
<td VALIGN=top>:asgn0:<br></td>\
<td VALIGN=top>:rxfq0:<br></td>\
<td VALIGN=top>:rxtn0:<br></td>\
<td VALIGN=top>:txfq0:<br></td>\
<td VALIGN=top>:txtn0:<br></td>\
<td VALIGN=top>:mode0:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk0:<br></td>\
</tr>\
<tr>\
<td>2</td><td VALIGN=top>:func1:<br></td>\
<td VALIGN=top>:chan1:<br></td>\
<td VALIGN=top>:asgn1:<br></td>\
<td VALIGN=top>:rxfq1:<br></td>\
<td VALIGN=top>:rxtn1:<br></td>\
<td VALIGN=top>:txfq1:<br></td>\
<td VALIGN=top>:txtn1:<br></td>\
<td VALIGN=top>:mode1:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk1:<br></td>\
</tr>\
<tr>\
<td>3</td><td VALIGN=top>:func2:<br></td>\
<td VALIGN=top>:chan2:<br></td>\
<td VALIGN=top>:asgn2:<br></td>\
<td VALIGN=top>:rxfq2:<br></td>\
<td VALIGN=top>:rxtn2:<br></td>\
<td VALIGN=top>:txfq2:<br></td>\
<td VALIGN=top>:txtn2:<br></td>\
<td VALIGN=top>:mode2:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk2:<br></td>\
</tr>\
<tr>\
<td>4</td><td VALIGN=top>:func3:<br></td>\
<td VALIGN=top>:chan3:<br></td>\
<td VALIGN=top>:asgn3:<br></td>\
<td VALIGN=top>:rxfq3:<br></td>\
<td VALIGN=top>:rxtn3:<br></td>\
<td VALIGN=top>:txfq3:<br></td>\
<td VALIGN=top>:txtn3:<br></td>\
<td VALIGN=top>:mode3:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk3:<br></td>\
</tr>\
<tr>\
<td>5</td><td VALIGN=top>:func4:<br></td>\
<td VALIGN=top>:chan4:<br></td>\
<td VALIGN=top>:asgn4:<br></td>\
<td VALIGN=top>:rxfq4:<br></td>\
<td VALIGN=top>:rxtn4:<br></td>\
<td VALIGN=top>:txfq4:<br></td>\
<td VALIGN=top>:txtn4:<br></td>\
<td VALIGN=top>:mode4:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk4:<br></td>\
</tr>\
<tr>\
<td>6</td><td VALIGN=top>:func5:<br></td>\
<td VALIGN=top>:chan5:<br></td>\
<td VALIGN=top>:asgn5:<br></td>\
<td VALIGN=top>:rxfq5:<br></td>\
<td VALIGN=top>:rxtn5:<br></td>\
<td VALIGN=top>:txfq5:<br></td>\
<td VALIGN=top>:txtn5:<br></td>\
<td VALIGN=top>:mode5:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk5:<br></td>\
</tr>\
<tr>\
<td>7</td><td VALIGN=top>:func6:<br></td>\
<td VALIGN=top>:chan6:<br></td>\
<td VALIGN=top>:asgn6:<br></td>\
<td VALIGN=top>:rxfq6:<br></td>\
<td VALIGN=top>:rxtn6:<br></td>\
<td VALIGN=top>:txfq6:<br></td>\
<td VALIGN=top>:txtn6:<br></td>\
<td VALIGN=top>:mode6:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk6:<br></td>\
</tr>\
<tr>\
<td>8</td><td VALIGN=top>:func7:<br></td>\
<td VALIGN=top>:chan7:<br></td>\
<td VALIGN=top>:asgn7:<br></td>\
<td VALIGN=top>:rxfq7:<br></td>\
<td VALIGN=top>:rxtn7:<br></td>\
<td VALIGN=top>:txfq7:<br></td>\
<td VALIGN=top>:txtn7:<br></td>\
<td VALIGN=top>:mode7:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk7:<br></td>\
</tr>\
<tr>\
<tr>\
<td>9</td><td VALIGN=top>:func8:<br></td>\
<td VALIGN=top>:chan8:<br></td>\
<td VALIGN=top>:asgn8:<br></td>\
<td VALIGN=top>:rxfq8:<br></td>\
<td VALIGN=top>:rxtn8:<br></td>\
<td VALIGN=top>:txfq8:<br></td>\
<td VALIGN=top>:txtn8:<br></td>\
<td VALIGN=top>:mode8:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk8:<br></td>\
</tr>\
<tr>\
<td>10</td><td VALIGN=top>:func9:<br></td>\
<td VALIGN=top>:chan9:<br></td>\
<td VALIGN=top>:asgn9:<br></td>\
<td VALIGN=top>:rxfq9:<br></td>\
<td VALIGN=top>:rxtn9:<br></td>\
<td VALIGN=top>:txfq9:<br></td>\
<td VALIGN=top>:txtn9:<br></td>\
<td VALIGN=top>:mode9:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk9:<br></td>\
</tr>\
<tr>\
<td>11</td><td VALIGN=top>:func10:<br></td>\
<td VALIGN=top>:chan10:<br></td>\
<td VALIGN=top>:asgn10:<br></td>\
<td VALIGN=top>:rxfq10:<br></td>\
<td VALIGN=top>:rxtn10:<br></td>\
<td VALIGN=top>:txfq10:<br></td>\
<td VALIGN=top>:txtn10:<br></td>\
<td VALIGN=top>:mode10:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk10:<br></td>\
</tr>\
<tr>\
<td>12</td><td VALIGN=top>:func11:<br></td>\
<td VALIGN=top>:chan11:<br></td>\
<td VALIGN=top>:asgn11:<br></td>\
<td VALIGN=top>:rxfq11:<br></td>\
<td VALIGN=top>:rxtn11:<br></td>\
<td VALIGN=top>:txfq11:<br></td>\
<td VALIGN=top>:txtn11:<br></td>\
<td VALIGN=top>:mode11:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk11:<br></td>\
</tr>\
<tr>\
<tr>\
<td>13</td><td VALIGN=top>:func12:<br></td>\
<td VALIGN=top>:chan12:<br></td>\
<td VALIGN=top>:asgn12:<br></td>\
<td VALIGN=top>:rxfq12:<br></td>\
<td VALIGN=top>:rxtn12:<br></td>\
<td VALIGN=top>:txfq12:<br></td>\
<td VALIGN=top>:txtn12:<br></td>\
<td VALIGN=top>:mode12:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk12:<br></td>\
</tr>\
<td>14</td><td VALIGN=top>:func13:<br></td>\
<td VALIGN=top>:chan13:<br></td>\
<td VALIGN=top>:asgn13:<br></td>\
<td VALIGN=top>:rxfq13:<br></td>\
<td VALIGN=top>:rxtn13:<br></td>\
<td VALIGN=top>:txfq13:<br></td>\
<td VALIGN=top>:txtn13:<br></td>\
<td VALIGN=top>:mode13:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk13:<br></td>\
</tr>\
<tr>\
<td>15</td><td VALIGN=top>:func14:<br></td>\
<td VALIGN=top>:chan14:<br></td>\
<td VALIGN=top>:asgn14:<br></td>\
<td VALIGN=top>:rxfq14:<br></td>\
<td VALIGN=top>:rxtn14:<br></td>\
<td VALIGN=top>:txfq14:<br></td>\
<td VALIGN=top>:txtn14:<br></td>\
<td VALIGN=top>:mode14:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk14:<br></td>\
</tr>\
<tr>\
<td>16</td><td VALIGN=top>:func15:<br></td>\
<td VALIGN=top>:chan15:<br></td>\
<td VALIGN=top>:asgn15:<br></td>\
<td VALIGN=top>:rxfq15:<br></td>\
<td VALIGN=top>:rxtn15:<br></td>\
<td VALIGN=top>:txfq15:<br></td>\
<td VALIGN=top>:txtn15:<br></td>\
<td VALIGN=top>:mode15:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk15:<br></td>\
</tr>\
<tr>\
<td>17</td><td VALIGN=top>:func16:<br></td>\
<td VALIGN=top>:chan16:<br></td>\
<td VALIGN=top>:asgn16:<br></td>\
<td VALIGN=top>:rxfq16:<br></td>\
<td VALIGN=top>:rxtn16:<br></td>\
<td VALIGN=top>:txfq16:<br></td>\
<td VALIGN=top>:txtn16:<br></td>\
<td VALIGN=top>:mode16:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk16:<br></td>\
</tr>\
<tr>\
<td>18</td><td VALIGN=top>:func17:<br></td>\
<td VALIGN=top>:chan17:<br></td>\
<td VALIGN=top>:asgn17:<br></td>\
<td VALIGN=top>:rxfq17:<br></td>\
<td VALIGN=top>:rxtn17:<br></td>\
<td VALIGN=top>:txfq17:<br></td>\
<td VALIGN=top>:txtn17:<br></td>\
<td VALIGN=top>:mode17:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk17:<br></td>\
</tr>\
<tr>\
<td>19</td><td VALIGN=top>:func18:<br></td>\
<td VALIGN=top>:chan18:<br></td>\
<td VALIGN=top>:asgn18:<br></td>\
<td VALIGN=top>:rxfq18:<br></td>\
<td VALIGN=top>:rxtn18:<br></td>\
<td VALIGN=top>:txfq18:<br></td>\
<td VALIGN=top>:txtn18:<br></td>\
<td VALIGN=top>:mode18:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk18:<br></td>\
</tr>\
<tr>\
<td>20</td><td VALIGN=top>:func19:<br></td>\
<td VALIGN=top>:chan19:<br></td>\
<td VALIGN=top>:asgn19:<br></td>\
<td VALIGN=top>:rxfq19:<br></td>\
<td VALIGN=top>:rxtn19:<br></td>\
<td VALIGN=top>:txfq19:<br></td>\
<td VALIGN=top>:txtn19:<br></td>\
<td VALIGN=top>:mode19:<br></td>\
</tr>\
<tr>\
<td COLSPAN=9 VALIGN=top>Remark: :rmrk19:<br></td>\
</tr>\
<tr>\
<td COLSPAN = 4 VALIGN=top>5. Prepared by (Communications unit)<br>:prp:<br></td>\
<td COLSPAN = 5 VALIGN=top>6. Incident Location<br>\
County: :cnty:  State: :stat: Lat: :lat: Lon: :lon:<br>\
</tr>\
</tbody>\
</table>\
</body>\
</html>";

const char ics205_text_template[] =
"ICS 205 INCIDENT RADIO COMMUNICATIONS PLAN\n\n\
Incident name: :nam:\n\
Date/Time Prepared: :dt1:\n\
Operational Period Date/Time from: :dt2:\n\
Operational Period Date/Time to: :dt3:\n\
System/Cache #1: :func0:\n\
Channel #1: :chan0:\n\
Function #1: :asgn0:\n\
Rx Freq/Tone #1: :rxfq0: :rxtn0:\n\
Tx Freq/Tone #1: :txfq0: :txtn0:\n\
Assignment #1: :mode0:\n\
Remarks #1: :rmrk0:\n\
System/Cache #2: :func1:\n\
Channel #2: :chan1:\n\
Function #2: :asgn1:\n\
Rx Freq/Tone #2: :rxfq1: :rxtn1:\n\
Tx Freq/Tone #2: :txfq1: :txtn1:\n\
Assignment #2: :mode1:\n\
Remarks #2: :rmrk1:\n\
System/Cache #3: :func2:\n\
Channel #3: :chan2:\n\
Function #3: :asgn2:\n\
Rx Freq/Tone #3: :rxfq2: :rxtn2:\n\
Tx Freq/Tone #3: :txfq2: :txtn2:\n\
Assignment #3: :mode2:\n\
Remarks #3: :rmrk2:\n\
System/Cache #4: :func3:\n\
Channel #4: :chan3:\n\
Function #4: :asgn3:\n\
Rx Freq/Tone #4: :rxfq3: :rxtn3:\n\
Tx Freq/Tone #4: :txfq3: :txtn3:\n\
Assignment #4: :mode3:\n\
Remarks #4: :rmrk3:\n\
System/Cache #5: :func4:\n\
Channel #5: :chan4:\n\
Function #5: :asgn4:\n\
Freq/Tone #5: :rxfq4:\n\
Assignment #5: :mode4:\n\
Remarks #5: :rmrk4:\n\
System/Cache #6: :func5:\n\
Channel #6: :chan5:\n\
Function #6: :asgn5:\n\
Rx Freq/Tone #6: :rxfq5: :rxtn5:\n\
Tx Freq/Tone #6: :txfq5: :txtn5:\n\
Assignment #6: :mode5:\n\
Remarks #6: :rmrk5:\n\
System/Cache #7: :func6:\n\
Channel #7: :chan6:\n\
Function #7: :asgn6:\n\
Rx Freq/Tone #7: :rxfq6: :rxtn6:\n\
Tx Freq/Tone #7: :txfq6: :txtn6:\n\
Assignment #7: :mode6:\n\
Remarks #7: :rmrk6:\n\
System/Cache #8: :func7:\n\
Channel #8: :chan7:\n\
Function #8: :asgn7:\n\
Rx Freq/Tone #8: :rxfq7: :rxtn7:\n\
Tx Freq/Tone #8: :txfq7: :txtn7:\n\
Assignment #8: :mode7:\n\
Remarks #9: :rmrk8:\n\
System/Cache #9: :func8:\n\
Channel #9: :chan8:\n\
Function #9: :asgn8:\n\
Rx Freq/Tone #9: :rxfq8: :rxtn8:\n\
Tx Freq/Tone #9: :txfq8: :txtn8:\n\
Assignment #9: :mode8:\n\
Remarks #9: :rmrk8:\n\
System/Cache #10: :func9:\n\
Channel #10: :chan9:\n\
Function #10: :asgn9:\n\
Rx Freq/Tone #10: :rxfq9: :rxtn9:\n\
Tx Freq/Tone #10: :txfq9: :txtn9:\n\
Assignment #10: :mode9:\n\
Remarks #10: :rmrk9:\n\
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

