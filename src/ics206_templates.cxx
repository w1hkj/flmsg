// =====================================================================
//
// ics206_templates.cxx
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
// ICS206 templates
//======================================================================

const char ics206_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>ics205</title></head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr style=\"font-weight: bold;\" align=\"center\">\n\
<td colspan=\"2\" style=\"vertical-align: middle; width: 200px;\"><span style=\"font-weight: bold;\">MEDICAL</span> <span style=\"font-weight: bold;\">PLAN</span></td>\n\
<td style=\"vertical-align: top; width: 200px; text-align: left;\"><span style=\"font-weight: normal;\">1. Incident Name</span><br>\n\
<span style=\"font-weight: normal;\"><nam:</span><br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top; font-weight: normal; width: 200px;\">\n\
<div style=\"text-align: left;\">2. Date Prepared<br>\n\
</div>\n\
<div style=\"text-align: left;\">\n\
<dat:</div>\n\
</td>\n\
<td style=\"vertical-align: top; text-align: left; font-weight: normal; width: 200px;\">3. Time Prepared<br>\n\
<tim:</td>\n\
<td style=\"vertical-align: top; text-align: left; font-weight: normal; width: 200px;\">4. Operational Period<br>\n\
<opp:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">5. Incident Medical Aid Station<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: middle;\">Medical Aid Stations<br>\n\
</td>\n\
<td style=\"vertical-align: middle;\">Location<br>\n\
</td>\n\
<td colspan=\"1\" style=\"vertical-align: top;\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Paramedics<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 40%;\"><msta0:<br></td>\n\
<td style=\"vertical-align: top; width: 45%;\"><mloc0:<br></td>\n\
<td style=\"vertical-align: top; width: 15%; text-align: center;\"><mpar0:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta1:<br></td>\n\
<td style=\"vertical-align: top;\"><mloc1:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar1:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta2:<br></td>\n\
<td style=\"vertical-align: top;\"><mloc2:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar2:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta3:<br></td>\n\
<td style=\"vertical-align: top;\"><mloc3:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar3:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><msta4:<br></td>\n\
<td style=\"vertical-align: top;\"><mloc4:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><mpar4:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"4\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">6. Transportation<br>\n\
</td>\n\
</tr>\n\
<tr align=\"center\">\n\
<td colspan=\"4\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">A. Ambulance Services<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 25%;\">Name</td>\n\
<td style=\"vertical-align: top; width: 40%;\">Address<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 20%;\">Phone<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 15%; text-align: center;\">Paramedics<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname0:<br></td>\n\
<td style=\"vertical-align: top;\"><taddr0:<br></td>\n\
<td style=\"vertical-align: top;\"><tphon0:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara0:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname1:<br></td>\n\
<td style=\"vertical-align: top;\"><taddr1:<br></td>\n\
<td style=\"vertical-align: top;\"><tphon1:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara1:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname2:<br></td>\n\
<td style=\"vertical-align: top;\"><taddr2:<br></td>\n\
<td style=\"vertical-align: top;\"><tphon2:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara2:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname3:<br></td>\n\
<td style=\"vertical-align: top;\"><taddr3:<br></td>\n\
<td style=\"vertical-align: top;\"><tphon3:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara3:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tname4:<br></td>\n\
<td style=\"vertical-align: top;\"><taddr4:<br></td>\n\
<td style=\"vertical-align: top;\"><tphon4:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><tpara4:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">B. Incident Ambulances<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 25%;\">Name<br></td>\n\
<td style=\"vertical-align: top; width: 60%;\">Location<br></td>\n\
<td style=\"vertical-align: top;  width: 15%; text-align: center;\">Paramedics<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname0:<br></td>\n\
<td style=\"vertical-align: top;\"><aloca0:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara0:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname1:<br></td>\n\
<td style=\"vertical-align: top;\"><aloca1:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara1:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname2:<br></td>\n\
<td style=\"vertical-align: top;\"><aloca2:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara2:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname3:<br></td>\n\
<td style=\"vertical-align: top;\"><aloca3:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara3:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><aname4:<br></td>\n\
<td style=\"vertical-align: top;\"><aloca4:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><apara4:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"7\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">7. Hospitals<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: bottom; width: 20%;\">Name<br></td>\n\
<td style=\"vertical-align: bottom; width: 30%;\">Address<br></td>\n\
<td colspan=\"2\" style=\"vertical-align: top; width: 10%;\">&nbsp; Travel Time<br>&nbsp; Air&nbsp;&nbsp;&nbsp; &nbsp; &nbsp; Grnd<br></td>\n\
<td style=\"vertical-align: bottom; width: 15%;\">Phone<br></td>\n\
<td style=\"vertical-align: bottom; width: 5%;\">Helipad<br></td>\n\
<td style=\"vertical-align: top; width: 5%; text-align: center;\">Burn<br>Center<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname0:<br></td>\n\
<td style=\"vertical-align: top;\"><haddr0:<br></td>\n\
<td style=\"vertical-align: top; width: 5%;\"><hatim0:<br></td>\n\
<td style=\"vertical-align: top; width: 5%;\"><hgtim0:<br></td>\n\
<td style=\"vertical-align: top;\"><hphon0:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli0:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn0:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname1:<br></td>\n\
<td style=\"vertical-align: top;\"><haddr1:<br></td>\n\
<td style=\"vertical-align: top;\"><hatim1:<br></td>\n\
<td style=\"vertical-align: top;\"><hgtim1:<br></td>\n\
<td style=\"vertical-align: top;\"><hphon1:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli1:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn1:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname2:<br></td>\n\
<td style=\"vertical-align: top;\"><haddr2:<br></td>\n\
<td style=\"vertical-align: top;\"><hatim2:<br></td>\n\
<td style=\"vertical-align: top;\"><hgtim2:<br></td>\n\
<td style=\"vertical-align: top;\"><hphon2:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli2:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn2:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname3:<br></td>\n\
<td style=\"vertical-align: top;\"><haddr3:<br></td>\n\
<td style=\"vertical-align: top;\"><hatim3:<br></td>\n\
<td style=\"vertical-align: top;\"><hgtim3:<br></td>\n\
<td style=\"vertical-align: top;\"><hphon3:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli3:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn3:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><hname4:<br></td>\n\
<td style=\"vertical-align: top;\"><haddr4:<br></td>\n\
<td style=\"vertical-align: top;\"><hatim4:<br></td>\n\
<td style=\"vertical-align: top;\"><hgtim4:<br></td>\n\
<td style=\"vertical-align: top;\"><hphon4:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hheli4:<br></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><hburn4:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"2\" style=\"vertical-align: top; background-color: rgb(233, 233, 233);\">8. Medical Emergency Procedures<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"2\" style=\"vertical-align: top; height: 200px;\"><proc:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%;\">9. Prepared by (Medical Unit Leader)<br>\n\
<prep:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">10.Reviewed by (Safety Officer)<br>\n\
<rvwr:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
ICS206<br>\n\
</body></html>";

const char ics206_text_template[] =
"ICS 206 MEDICAL PLAN\n\n\
Incident name: <nam:\n\
Operational period: <opp:\n\
Date Prepared: <dat:\n\
Time Prepared: <tim:\n\
Medical Aid Station #1: <msta0:\n\
Location #1: <mloc0:\n\
Paramedics #1: <mpar0:\n\
Medical Aid Station #2: <msta1:\n\
Location #2: <mloc1:\n\
Paramedics #2: <mpar1:\n\
Medical Aid Station #3: <msta2:\n\
Location #3: <mloc2:\n\
Paramedics #3: <mpar2:\n\
Medical Aid Station #4: <msta3:\n\
Location #4: <mloc3:\n\
Paramedics #4: <mpar3:\n\
Medical Aid Station #5: <msta4:\n\
Location #5: <mloc4:\n\
Paramedics #5: <mpar4:\n\
Ambulance service #1: <tname0:\n\
Address #1: <taddr0:\n\
Phone #1: <tphon0:\n\
Paramedics #1: <tpara0:\n\
Ambulance service #2: <tname1:\n\
Address #2: <taddr1:\n\
Phone #2: <tphon1:\n\
Paramedics #2: <tpara1:\n\
Ambulance service #3: <tname2:\n\
Address #3: <taddr2:\n\
Phone #3: <tphon2:\n\
Paramedics #3: <tpara2:\n\
Ambulance service #4: <tname3:\n\
Address #4: <taddr3:\n\
Phone #4: <tphon3:\n\
Paramedics #4: <tpara3:\n\
Ambulance service #5: <tname4:\n\
Address #5: <taddr4:\n\
Phone #5: <tphon4:\n\
Paramedics #5: <tpara4:\n\
Incident ambulance name #1: <aname0:\n\
Location #1: <aloca0:\n\
Paramedics #1 <apara0:\n\
Incident ambulance name #2: <aname1:\n\
Location #2: <aloca1:\n\
Paramedics #2 <apara1:\n\
Incident ambulance name #3: <aname2:\n\
Location #3: <aloca2:\n\
Paramedics #3 <apara2:\n\
Incident ambulance name #4: <aname3:\n\
Location #4: <aloca3:\n\
Paramedics #4 <apara3:\n\
Incident ambulance name #5: <aname4:\n\
Location #5: <aloca4:\n\
Paramedics #5 <apara4:\n\
Hospital name #1: <hname0:\n\
Address #1: <haddr0:\n\
Travel time, air #1: <hatim0:\n\
Travel time, ground #1: <hgtim0:\n\
Phone #1: <hphon0:\n\
Helipad #1: <hheli0:\n\
Burn center #1: <hburn0:\n\
Hospital name #2: <hname1:\n\
Address #2: <haddr1:\n\
Travel time, air #2: <hatim1:\n\
Travel time, ground #2: <hgtim1:\n\
Phone #2: <hphon1:\n\
Helipad #2: <hheli1:\n\
Burn center #2: <hburn1:\n\
Hospital name #3: <hname2:\n\
Address #3: <haddr2:\n\
Travel time, air #3: <hatim2:\n\
Travel time, ground #3: <hgtim2:\n\
Phone #3: <hphon2:\n\
Helipad #3: <hheli2:\n\
Burn center #3: <hburn2:\n\
Hospital name #4: <hname3:\n\
Address #4: <haddr3:\n\
Travel time, air #4: <hatim3:\n\
Travel time, ground #4: <hgtim3:\n\
Phone #4: <hphon3:\n\
Helipad #4: <hheli3:\n\
Burn center #4: <hburn3:\n\
Hospital name #5: <hname4:\n\
Address #5: <haddr4:\n\
Travel time, air #5: <hatim4:\n\
Travel time, ground #5: <hgtim4:\n\
Phone #5: <hphon4:\n\
Helipad #5: <hheli4:\n\
Burn center #5: <hburn4:\n\
Medical Emergency Procedures: <proc:\n\
Prepared by: <prep:\n\
Reviewed by: <rvwr:\n\
";

