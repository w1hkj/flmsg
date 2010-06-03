// =====================================================================
//
// hx_msgs.cxx
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


#include "ics213.h"
#include "flmsg_dialog.h"

hx_TEXT hx_list[] = {
{"HXA",   "HXAnn", "\
Collect landline delivery authorized within\n___ miles" },
{"HXB",   "HXBnn", "\
Cancel message if not delivered within\n\
___ hours of filing time." },
{"HXC",   "HXC", "\
Report data & time of delivery back to the\n\
originating station" },
{"HXD",   "HXD", "\
Report to originating station the identity\n\
of station from which received, plus date\nand time" },
{"HXE",   "HXE", "\
Delivering station get reply from addressee,\n\
originate message back." },
{"HXF",   "HXFnn", "\
Hold delivery until ___ [date]" },
{"HXG",   "HXG", "\
Delivery by mail or landline toll call not required\n\
If toll call or other expenses involved, cancel\n\
message and send service message back to\n\
originating station." },
{0, 0, 0}
};

int hx_nbr = 0;

void cb_hx()
{
	if (!hxwindow) {
		hxwindow = hx_dialog();
		int n = 0;
		while (hx_list[n].sznbr) {
			sel_hx_select->add(hx_list[n].sznbr);
			n++;
		}
		sel_hx_select->value(0);
		txt_hx_instructions->value(hx_list[0].instruct);
	}
	hxwindow->show();
}

void cb_hx_select()
{
	int n = sel_hx_select->value();
	txt_hx_instructions->value(hx_list[n].instruct);
}

void cb_hx_select_add()
{
	string hxadd = txt_hx_select_text->value();
	int n = sel_hx_select->value();
	if (n < 0) return;
	if (hxadd.empty())
		hxadd = hx_list[n].text;
	else
		hxadd.append(" ").append(hx_list[n].text);
	txt_hx_select_text->value(hxadd.c_str());
}

void cb_hx_select_cancel()
{
	hxwindow->hide();
}

void cb_hx_select_ok()
{
	txt_rg_hx->value(txt_hx_select_text->value());
	hxwindow->hide();
}

