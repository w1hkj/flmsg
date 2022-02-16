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

#include <FL/Fl_Hold_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"
#include "fileselect.h"

Fl_Group	*tab_mars_net = (Fl_Group *)0;
Fl_Tabs		*tab_mars_net_type = (Fl_Tabs *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_mars_net_1 = (Fl_Group *)0;//

Fl_Input2	*txt_mars_net_DE = (Fl_Input2 *)0;//

Fl_Input2	*txt_mars_net_NBR = (Fl_Input2 *)0;//
Fl_ListBox	*sel_mars_net_PREC = (Fl_ListBox *)0;//
Fl_Input2	*txt_mars_net_DTG = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_FMNAME = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_FMCALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_FMSTATE = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_TOPOS = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_TOCALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_TOSTATE = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_INFOPOS = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_INFOCALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_INFOSTATE = (Fl_Input2 *)0;//

Fl_Input2	*txt_mars_net_INCIDENT = (Fl_Input2 *)0;//

Fl_Input2	*txt_mars_net_DND = (Fl_Input2 *)0;// date net designator
Fl_Input2	*txt_mars_net_NETCALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_DTGSTART = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_DTGEND = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_NETSB = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_NCSCALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_NBRSTAS = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_CALLS = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_net_NBRMSGS = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_net_COMMENTS = (Fl_Input2 *)0;

Fl_Button	*btn_mars_net_DE = (Fl_Button*)0;
Fl_Button	*btn_mars_net_DTG = (Fl_Button*)0;
Fl_Button	*btn_mars_net_pick_fm = (Fl_Button*)0;
Fl_Button	*btn_mars_net_pick_to = (Fl_Button*)0;
Fl_Button	*btn_mars_net_pick_INFO = (Fl_Button*)0;
Fl_Button	*btn_mars_net_pick_NETCALL = (Fl_Button*)0;
Fl_Button	*btn_mars_net_DTGSTART = (Fl_Button*)0;
Fl_Button	*btn_mars_net_DTGEND = (Fl_Button*)0;
Fl_Button	*btn_mars_net_pick_NCSCALL = (Fl_Button*)0;
Fl_Button	*btn_mars_net_add_calls = (Fl_Button*)0;

//----------------------------------------------------------------------

Fl_Group	*tab_mars_net_2 = (Fl_Group *)0;

// widget callbacks & support
void cb_btn_mars_net_DE(Fl_Widget *w, void *d)
{
	txt_mars_net_DE->value(progStatus.my_call.c_str());
}

void cb_btn_mars_net_DTG(Fl_Widget *w, void *d)
{
	txt_mars_net_DTG->value(szMarsDateTime());
}

void cb_btn_mars_net_pick_fm(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_net_FMCALL->value(mars_list_call.c_str());
	txt_mars_net_FMNAME->value(mars_list_lname.c_str());
	txt_mars_net_FMSTATE->value(mars_list_state.c_str());
}

void cb_btn_mars_net_pick_to(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_net_TOCALL->value(mars_list_bcall.c_str());
	txt_mars_net_TOPOS->value(mars_list_position.c_str());
	txt_mars_net_TOSTATE->value(mars_list_state.c_str());
}

void cb_btn_mars_net_pick_INFO(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_net_INFOCALL->value(mars_list_bcall.c_str());
	txt_mars_net_INFOPOS->value(mars_list_position.c_str());
	txt_mars_net_INFOSTATE->value(mars_list_state.c_str());
}

void cb_btn_mars_net_pick_NETCALL(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_net_NETCALL->value(mars_list_bcall.c_str());
}

void cb_btn_mars_net_DTGSTART(Fl_Widget *w, void *d)
{
	txt_mars_net_DTGSTART->value(szMarsDateTime());
}

void cb_btn_mars_net_DTGEND(Fl_Widget *w, void *d)
{
	txt_mars_net_DTGEND->value(szMarsDateTime());
}

void cb_btn_mars_net_pick_NCSCALL(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_net_NCSCALL->value(mars_list_call.c_str());
}

void cb_btn_mars_net_add_calls(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	std::string calls = txt_mars_net_CALLS->value();
	if (calls.length() && (calls[calls.length()-1] != '\n')) calls.append(" ");
	calls.append(mars_list_call);
	txt_mars_net_CALLS->value(calls.c_str());
}

//----------------------------------------------------------------------

void create_mars_net()
{
	int Y = tab_top;
	tab_mars_net = new Fl_Group(0, Y, 570, 355);
	tab_mars_net->align(FL_ALIGN_TOP);

	tab_mars_net_type = new Fl_Tabs(0, Y+2, 570, 352);
	tab_mars_net_type->selection_color((Fl_Color)246);

	tab_mars_net_1 = new Fl_Group(0, Y+25, 570, 325, _("Header"));

	Y += 30;

	txt_mars_net_DE = new Fl_Input2(100, Y, 150, 24, _("DE"));
	txt_mars_net_DE->tooltip(_(""));
	txt_mars_net_DE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_DE->when(FL_WHEN_CHANGED);

	btn_mars_net_DE = new Fl_Button(252, Y, 30, 24, _("ME"));
	btn_mars_net_DE->callback((Fl_Callback*)cb_btn_mars_net_DE);

	txt_mars_net_NBR = new Fl_Input2(370, Y, 150, 24, _("MSG NBR"));
	txt_mars_net_NBR->tooltip(_(""));
	txt_mars_net_NBR->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_NBR->when(FL_WHEN_CHANGED);

	Y += 25;
	sel_mars_net_PREC = new Fl_ListBox(100, Y, 45, 24, _("PREC"));
	sel_mars_net_PREC->tooltip(
		_("R - Routine\nP - Priority\nO - Immediate\nZ - Flash"));
	sel_mars_net_PREC->add("R|P|O|Z");
	sel_mars_net_PREC->align(FL_ALIGN_LEFT);
	sel_mars_net_PREC->index(0);

	txt_mars_net_DTG = new Fl_Input2(185, Y, 150, 24, _("DTG"));
	txt_mars_net_DTG->tooltip(_(""));

	btn_mars_net_DTG = new Fl_Button(335, Y, 22, 24, _("..."));
	btn_mars_net_DTG->tooltip(_("Set Date/Time Group"));
	btn_mars_net_DTG->callback((Fl_Callback*)cb_btn_mars_net_DTG);

	Y += 25;
	txt_mars_net_FMNAME = new Fl_Input2(100, Y, 150, 24, _("FM"));
	txt_mars_net_FMNAME->tooltip(_("Name"));
	txt_mars_net_FMNAME->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_FMNAME->when(FL_WHEN_CHANGED);

	txt_mars_net_FMCALL = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_net_FMCALL->tooltip(_("Call"));
	txt_mars_net_FMCALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_FMCALL->when(FL_WHEN_CHANGED);

	txt_mars_net_FMSTATE = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_net_FMSTATE->tooltip(_("State"));
	txt_mars_net_FMSTATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_FMSTATE->when(FL_WHEN_CHANGED);

	btn_mars_net_pick_fm = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_net_pick_fm->tooltip(_("Select from list"));
	btn_mars_net_pick_fm->callback((Fl_Callback*)cb_btn_mars_net_pick_fm);

	Y += 25;
	txt_mars_net_TOPOS = new Fl_Input2(100, Y, 150, 24, _("TO"));
	txt_mars_net_TOPOS->tooltip(_("Position"));
	txt_mars_net_TOPOS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_TOPOS->when(FL_WHEN_CHANGED);

	txt_mars_net_TOCALL = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_net_TOCALL->tooltip(_("Call"));
	txt_mars_net_TOCALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_TOCALL->when(FL_WHEN_CHANGED);

	txt_mars_net_TOSTATE = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_net_TOSTATE->tooltip(_("State"));
	txt_mars_net_TOSTATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_TOSTATE->when(FL_WHEN_CHANGED);

	btn_mars_net_pick_to = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_net_pick_to->tooltip(_("Select from list"));
	btn_mars_net_pick_to->callback((Fl_Callback*)cb_btn_mars_net_pick_to);

	Y += 25;
	txt_mars_net_INFOPOS = new Fl_Input2(100, Y, 150, 24, _("INFO"));
	txt_mars_net_INFOPOS->tooltip(_("Position"));
	txt_mars_net_INFOPOS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_INFOPOS->when(FL_WHEN_CHANGED);

	txt_mars_net_INFOCALL = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_net_INFOCALL->tooltip(_("Call"));
	txt_mars_net_INFOCALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_INFOCALL->when(FL_WHEN_CHANGED);

	txt_mars_net_INFOSTATE = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_net_INFOSTATE->tooltip(_("State"));
	txt_mars_net_INFOSTATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_INFOSTATE->when(FL_WHEN_CHANGED);

	btn_mars_net_pick_INFO = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_net_pick_INFO->tooltip(_("Select from list"));
	btn_mars_net_pick_INFO->callback((Fl_Callback*)cb_btn_mars_net_pick_INFO);

	Y += 49;
	txt_mars_net_INCIDENT = new Fl_Input2(100, Y, 450, 24, _("INCIDENT"));
	txt_mars_net_INCIDENT->tooltip(_("Incident\nleave blank for normal ops"));
	txt_mars_net_INCIDENT->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_INCIDENT->when(FL_WHEN_CHANGED);

	Y += 49;
	txt_mars_net_DND = new Fl_Input2(100, Y, 80, 24, _("NET REPORT"));
	txt_mars_net_DND->tooltip(_("date net designator"));
	txt_mars_net_DND->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_DND->when(FL_WHEN_CHANGED);

	tab_mars_net_1->end();

	tab_mars_net_2 = new Fl_Group(0, 95, 570, 325, _("Body"));

	Y = 100;
	Fl_Box *label = new Fl_Box(40, Y, 40, 24, "1.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);

	txt_mars_net_NETCALL = new Fl_Input2(40, Y, 150, 24, "");
	txt_mars_net_NETCALL->tooltip(_("net call"));
	txt_mars_net_NETCALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_NETCALL->when(FL_WHEN_CHANGED);

	btn_mars_net_pick_NETCALL = new Fl_Button(192, Y, 30, 24, _("List"));
	btn_mars_net_pick_NETCALL->tooltip(_("Select from list"));
	btn_mars_net_pick_NETCALL->callback((Fl_Callback*)cb_btn_mars_net_pick_NETCALL);

	Y += 25;
	label = new Fl_Box(40, Y, 40, 24, "2.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);

	txt_mars_net_DTGSTART = new Fl_Input2(40, Y, 150, 24, "");
	txt_mars_net_DTGSTART->tooltip(_("DTG start"));

	btn_mars_net_DTGSTART = new Fl_Button(192, Y, 22, 24, _("..."));
	btn_mars_net_DTGSTART->tooltip(_("Set Date/Time Group"));
	btn_mars_net_DTGSTART->callback((Fl_Callback*)cb_btn_mars_net_DTGSTART);

	txt_mars_net_DTGEND = new Fl_Input2(220, Y, 150, 24, _(""));
	txt_mars_net_DTGEND->tooltip(_("DTG end"));

	btn_mars_net_DTGEND = new Fl_Button(372, Y, 22, 24, _("..."));
	btn_mars_net_DTGEND->tooltip(_("Set Date/Time Group"));
	btn_mars_net_DTGEND->callback((Fl_Callback*)cb_btn_mars_net_DTGEND);

	Y += 25;
	label = new Fl_Box(40, Y, 40, 24, "3.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);

	txt_mars_net_NETSB = new Fl_Input2(40, Y, 80, 24, "");
	txt_mars_net_NETSB->tooltip(_("USB / LSB"));
	txt_mars_net_NETSB->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_NETSB->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(40, Y, 40, 24, "4.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);

	txt_mars_net_NCSCALL = new Fl_Input2(40, Y, 150, 24, "");
	txt_mars_net_NCSCALL->tooltip(_("net call"));
	txt_mars_net_NCSCALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_NCSCALL->when(FL_WHEN_CHANGED);

	btn_mars_net_pick_NCSCALL = new Fl_Button(192, Y, 30, 24, _("List"));
	btn_mars_net_pick_NCSCALL->tooltip(_("Select from list"));
	btn_mars_net_pick_NCSCALL->callback((Fl_Callback*)cb_btn_mars_net_pick_NCSCALL);

	Y += 25;
	label = new Fl_Box(40, Y, 40, 24, "5.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);

	txt_mars_net_NBRSTAS = new Fl_Input2(40, Y, 120, 24, "");
	txt_mars_net_NBRSTAS->tooltip(_("# stations IN NET"));

	btn_mars_net_add_calls = new Fl_Button(480, Y, 80, 24, _("Add Call"));
	btn_mars_net_add_calls->tooltip(_("Add from list"));
	btn_mars_net_add_calls->callback((Fl_Callback*)cb_btn_mars_net_add_calls);

	Y += 25;
	txt_mars_net_CALLS = new Fl_Input2(40, Y, 520, 72, "");
	txt_mars_net_CALLS->tooltip(_("Station calls\nstarting with alternate NCS"));
	txt_mars_net_CALLS->type(4);
	txt_mars_net_CALLS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_CALLS->when(FL_WHEN_CHANGED);

	Y += 73;
	label = new Fl_Box(40, Y, 40, 24, "6.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);
	label = new Fl_Box(40, Y, 2, 24, "N/A");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT);

	Y += 25;
	label = new Fl_Box(40, Y, 40, 24, "7. A.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);

	txt_mars_net_NBRMSGS = new Fl_Input2(40, Y, 120, 24, "");
	txt_mars_net_NBRMSGS->tooltip(_("# messages"));

	Y += 25;
	label = new Fl_Box(40, Y, 40, 24, "B.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT);

	txt_mars_net_COMMENTS = new Fl_Input2(40, Y, 520, 72, "");
	txt_mars_net_COMMENTS->tooltip(_("Comments"));
	txt_mars_net_COMMENTS->type(4);
	txt_mars_net_COMMENTS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_net_COMMENTS->when(FL_WHEN_CHANGED);

	tab_mars_net_2->end();

//	tab_mars_type->end();

	tab_mars_net->end();

	tab_mars_net->hide();
};

