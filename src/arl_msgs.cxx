// =====================================================================
//
// arl_msgs.cxx
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// =====================================================================

#include "ics213.h"
#include "flmsg_dialog.h"

ARL_TEXT arl_list[] = {
{"ONE",          0, "Everyone safe here. Please don't worry." },
{"TWO",          0, "Coming home as soon as possible." },
{"THREE",        1, "Am in ____ hospital. Receiving excellent care and recovering fine." },
{"FOUR",         0, "Only slight property damage here. Do not be concerned about disaster reports." },
{"FIVE",         0, "Am moving to new location. Send no further mail or communication. Will inform you of new address when relocated." },
{"SIX",          0, "Will contact you as soon as possible." },
{"SEVEN",        0, "Please reply by Amateur Radio through the amateur delivering this message. This is a free public service." },
{"EIGHT",        1, "Need additional ____ mobile or portable equipment for immediate emergency use." },
{"NINE",         1, "Additional ____ radio operators needed to assist with emergency at this location." },
{"TEN",          1, "Please contact ____. Advise to standby and provide further emergency information, instructions or assistance." },
{"ELEVEN",       2, "Establish Amateur Radio emergency communications with ____ on ____ MHz." },
{"TWELVE",       0, "Anxious to hear from you. No word in some time. Please contact me as soon as possible." },
{"THIRTEEN",     0, "Medical emergency situation exits here." },
{"FOURTEEN",     1, "Situation here becoming critical. Losses and damage from ____ increasing." },
{"FIFTEEN",      0, "Please advise your condition and what help is needed." },
{"SIXTEEN",      0, "Property damage very severe in this area." },
{"SEVENTEEN",    2, "REACT communications services also available. Establish REACT communication with ____ on channel ____." },
{"EIGHTEEN",     1, "Please contact me as soon as possible at ____." },
{"NINETEEN",     1, "Request health and welfare report on ____ . (State name, address and telephone number.)" },
{"TWENTY",       1, "Temporarily stranded. Will need some assistance. Please contact me at ____." },
{"TWENTY ONE",   0, "Search and Rescue assistance is needed by local authorities here. Advise availability." },
{"TWENTY TWO",   0, "Need accurate information on the extent and type of conditions now existing at your location. Please furnish this information and reply without delay." },
{"TWENTY THREE", 0, "Report at once the accessibility and best way to reach your location." },
{"TWENTY FOUR",  0, "Evacuation of residents from this area urgently needed. Advise plans for help." },
{"TWENTY FIVE",  0, "Furnish as soon as possible the weather conditions at your location." },
{"TWENTY SIX",   0, "Help and care for evacuation of sick and injured from this location needed at once. Emergency/priority messages originating from official sources must carry the signature of the originating official." },
{"FORTY SIX",    0, "Greetings on your birthday and best wishes for many more to come." },
{"FORTY SEVEN",  4, "Reference your message number ____ to ____ delivered on ____ at ____ UTC." },
{"FIFTY",        0, "Greetings by Amateur Radio." },
{"FIFTY ONE",    1, "Greetings by Amateur Radio. This message is sent as a free public service by ham radio operators at ____. Am having a wonderful time." },
{"FIFTY TWO",    0, "Really enjoyed being with you. Looking forward to getting together again." },
{"FIFTY THREE",  1, "Received your ____. It's appreciated; many thanks." },
{"FIFTY FOUR",   0, "Many thanks for your good wishes." },
{"FIFTY FIVE",   0, "Good news is always welcome. Very delighted to hear about yours." },
{"FIFTY SIX",    1, "Congratulations on your ____, a most worthy and deserved achievement." },
{"FIFTY SEVEN",  0, "Wish we could be together." },
{"FIFTY EIGHT",  0, "Have a wonderful time. Let us know when you return." },
{"FIFTY NINE",   0, "Congratulations on the new arrival. Hope mother and child are well." },
{"SIXTY",        1, "Wishing you the best of everything on ____." },
{"SIXTY ONE",    0, "Wishing you a very Merry Christmas and a Happy New Year." },
{"SIXTY TWO",    1, "Greetings and best wishes to you for a pleasant ____ holiday season." },
{"SIXTY THREE",  0, "Victory or defeat, our best wishes are with you. Hope you win." },
{"SIXTY FOUR",   1, "Arrived safely at ____." },
{"SIXTY FIVE",   2, "Arriving ____ on ____. Please arrange to meet me there." },
{"SIXTY SIX",    2, "DX QSLs are on hand for you at the ____ QSL Bureau. Send ____ self addressed envelopes." },
{"SIXTY SEVEN",  2, "Your message number ____ undeliverable because of ____. Please advise." },
{"SIXTY EIGHT",  0, "Sorry to hear you are ill. Best wishes for a speedy recovery." },
{"SIXTY NINE",   1, "Welcome to the ____. We are glad to have you with us and hope you will enjoy the fun and fellowship of the organization." },
{0, 0, 0}
};

int arl_nbr = 0;

void cb_arl()
{
	if (!arlwindow) {
		arlwindow = arl_dialog();
		int n = 0;
		while (arl_list[n].sznbr) {
			select_arl->add(arl_list[n].sznbr);
			n++;
		}
	}
	select_arl->value(1);
	select_arl->do_callback();
	arlwindow->show();
}

void cb_arl_cancel()
{
	arlwindow->hide();
}

void cb_arl_add()
{
	string msg = "ARL ";
	string fill;
	msg.append(arl_list[arl_nbr].sznbr).append(" X ");
	fill = txt_arl_fill1->value(); if (!fill.empty()) msg.append(fill).append(" X ");
	fill = txt_arl_fill2->value(); if (!fill.empty()) msg.append(fill).append(" X ");
	fill = txt_arl_fill3->value(); if (!fill.empty()) msg.append(fill).append(" X ");
	fill = txt_arl_fill4->value(); if (!fill.empty()) msg.append(fill).append(" X ");
	txt_rg_msg->addstr(msg.c_str());
	select_arl->value(1);
	select_arl->do_callback();
	cb_rg_check();
}

