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

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"
#include "fileselect.h"

Fl_Group	*tab_mars_daily = (Fl_Group *)0;

Fl_Tabs		*tab_mars_daily_type = (Fl_Tabs *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_mars_daily_1 = (Fl_Group *)0;

Fl_Input2	*txt_mars_daily_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_de = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_nbr = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_dtg = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_fm_name = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_fm_call = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_fm_state = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_to_pos = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_to_call = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_to_state = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_pos1 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_call1 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_state1 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_pos2 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_call2 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_state2 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_pos3 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_call3 = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_state3 = (Fl_Input2 *)0;

Fl_Button	*btn_mars_daily_de_me = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_dtg = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_pick_fm = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_pick_to = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_pick_info1 = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_pick_info2 = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_pick_info3 = (Fl_Button *)0;

Fl_ListBox	*sel_mars_daily_prec = (Fl_ListBox *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_mars_daily_2 = (Fl_Group *)0;

Fl_Input2	*txt_mars_daily_sitrep_id = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_sitrep_loc = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_dtg_24hr = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_netcall = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_dtg_active = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_dtg_deactive = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_nbr_stations = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_details = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_activations = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_agencies = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_daily_remarks = (Fl_Input2 *)0;

Fl_Button	*btn_mars_daily_dtg_24hr = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_pick_netcall = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_dtg_active = (Fl_Button *)0;
Fl_Button	*btn_mars_daily_dtg_deactive = (Fl_Button *)0;

Fl_ListBox	*sel_mars_daily_e_x = (Fl_ListBox *)0;

//----------------------------------------------------------------------

// widget callbacks & support
void cb_btn_mars_daily_de_me(Fl_Widget *w, void *d)
{
	txt_mars_daily_de->value(progStatus.my_call.c_str());
}

void cb_btn_mars_daily_pick_fm(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_daily_fm_call->value(mars_list_call.c_str());
	txt_mars_daily_fm_name->value(mars_list_lname.c_str());
	txt_mars_daily_fm_state->value(mars_list_state.c_str());
}

void cb_btn_mars_daily_pick_to(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_daily_to_call->value(mars_list_bcall.c_str());
	txt_mars_daily_to_pos->value(mars_list_position.c_str());
	txt_mars_daily_to_state->value(mars_list_state.c_str());
}

void cb_btn_mars_daily_pick_info1(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_daily_call1->value(mars_list_bcall.c_str());
	txt_mars_daily_pos1->value(mars_list_position.c_str());
	txt_mars_daily_state1->value(mars_list_state.c_str());
}

void cb_btn_mars_daily_pick_info2(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_daily_call2->value(mars_list_bcall.c_str());
	txt_mars_daily_pos2->value(mars_list_position.c_str());
	txt_mars_daily_state2->value(mars_list_state.c_str());
}

void cb_btn_mars_daily_pick_info3(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_daily_call3->value(mars_list_bcall.c_str());
	txt_mars_daily_pos3->value(mars_list_position.c_str());
	txt_mars_daily_state3->value(mars_list_state.c_str());
}

void cb_btn_mars_daily_dtg(Fl_Widget *w, void *d)
{
	txt_mars_daily_dtg->value(szMarsDateTime());
}

void cb_btn_mars_daily_dtg_24hr(Fl_Widget *w, void *d)
{
	txt_mars_daily_dtg_24hr->value(szMarsDateTime());
}

void cb_btn_mars_daily_dtg_active(Fl_Widget *w, void *d)
{
	txt_mars_daily_dtg_active->value(szMarsDateTime());
}

void cb_btn_mars_daily_dtg_deactive(Fl_Widget *w, void *d)
{
	txt_mars_daily_dtg_deactive->value(szMarsDateTime());
}

void cb_btn_mars_daily_pick_netcall(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_daily_netcall->value(mars_list_bcall.c_str());
}

void create_mars_daily()
{
	int Y = tab_top;
	tab_mars_daily = new Fl_Group(0, Y, 570, 390);
	tab_mars_daily->align(FL_ALIGN_TOP);

	tab_mars_daily_type = new Fl_Tabs(0, Y+2, 570, 387);
	tab_mars_daily_type->selection_color((Fl_Color)246);

	tab_mars_daily_1 = new Fl_Group(0, Y+25, 570, 360, _("Header"));

	Y += 30;

	txt_mars_daily_incident = new Fl_Input2(100, Y, 450, 24, _("INCIDENT"));
	txt_mars_daily_incident->tooltip(_("Incident"));
	txt_mars_daily_incident->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_incident->when(FL_WHEN_CHANGED);

	Y += 25;
	txt_mars_daily_de = new Fl_Input2(100, Y, 150, 24, _("DE"));
	txt_mars_daily_de->tooltip(_(""));
	txt_mars_daily_de->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_de->when(FL_WHEN_CHANGED);

	btn_mars_daily_de_me = new Fl_Button(252, Y, 30, 24, _("ME"));
	btn_mars_daily_de_me->callback((Fl_Callback*)cb_btn_mars_daily_de_me);

	txt_mars_daily_nbr = new Fl_Input2(370, Y, 150, 24, _("MSG NBR"));
	txt_mars_daily_nbr->tooltip(_(""));
	txt_mars_daily_nbr->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_nbr->when(FL_WHEN_CHANGED);

	Y += 25;
	sel_mars_daily_prec = new Fl_ListBox(100, Y, 45, 24, _("PREC"));
	sel_mars_daily_prec->tooltip(
		_("R - Routine\nP - Priority\nO - Immediate\nZ - Flash"));
	sel_mars_daily_prec->add("R|P|O|Z");
	sel_mars_daily_prec->align(FL_ALIGN_LEFT);
	sel_mars_daily_prec->index(0);

	txt_mars_daily_dtg = new Fl_Input2(185, Y, 150, 24, _("DTG"));
	txt_mars_daily_dtg->tooltip(_(""));

	btn_mars_daily_dtg = new Fl_Button(335, Y, 22, 24, _("..."));
	btn_mars_daily_dtg->tooltip(_("Set Date/Time Group"));
	btn_mars_daily_dtg->callback((Fl_Callback*)cb_btn_mars_daily_dtg);

	Y += 25;
	txt_mars_daily_fm_name = new Fl_Input2(100, Y, 150, 24, _("FM"));
	txt_mars_daily_fm_name->tooltip(_("Name"));
	txt_mars_daily_fm_name->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_fm_name->when(FL_WHEN_CHANGED);

	txt_mars_daily_fm_call = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_daily_fm_call->tooltip(_("Call"));
	txt_mars_daily_fm_call->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_fm_call->when(FL_WHEN_CHANGED);

	txt_mars_daily_fm_state = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_daily_fm_state->tooltip(_("State"));
	txt_mars_daily_fm_state->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_fm_state->when(FL_WHEN_CHANGED);

	btn_mars_daily_pick_fm = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_daily_pick_fm->tooltip(_("Select from list"));
	btn_mars_daily_pick_fm->callback((Fl_Callback*)cb_btn_mars_daily_pick_fm);

	Y += 25;
	txt_mars_daily_to_pos = new Fl_Input2(100, Y, 150, 24, _("TO"));
	txt_mars_daily_to_pos->tooltip(_("Position"));
	txt_mars_daily_to_pos->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_to_pos->when(FL_WHEN_CHANGED);

	txt_mars_daily_to_call = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_daily_to_call->tooltip(_("Call"));
	txt_mars_daily_to_call->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_to_call->when(FL_WHEN_CHANGED);

	txt_mars_daily_to_state = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_daily_to_state->tooltip(_("State"));
	txt_mars_daily_to_state->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_to_state->when(FL_WHEN_CHANGED);

	btn_mars_daily_pick_to = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_daily_pick_to->tooltip(_("Select from list"));
	btn_mars_daily_pick_to->callback((Fl_Callback*)cb_btn_mars_daily_pick_to);

	Y += 25;
	txt_mars_daily_pos1 = new Fl_Input2(100, Y, 150, 24, _("INFO1"));
	txt_mars_daily_pos1->tooltip(_("Position"));
	txt_mars_daily_pos1->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_pos1->when(FL_WHEN_CHANGED);

	txt_mars_daily_call1 = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_daily_call1->tooltip(_("Call"));
	txt_mars_daily_call1->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_call1->when(FL_WHEN_CHANGED);

	txt_mars_daily_state1 = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_daily_state1->tooltip(_("State"));
	txt_mars_daily_state1->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_state1->when(FL_WHEN_CHANGED);

	btn_mars_daily_pick_info1 = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_daily_pick_info1->tooltip(_("Select from list"));
	btn_mars_daily_pick_info1->callback((Fl_Callback*)cb_btn_mars_daily_pick_info1);

	Y += 25;
	txt_mars_daily_pos2 = new Fl_Input2(100, Y, 150, 24, _("INFO2"));
	txt_mars_daily_pos2->tooltip(_("Position"));
	txt_mars_daily_pos2->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_pos2->when(FL_WHEN_CHANGED);

	txt_mars_daily_call2 = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_daily_call2->tooltip(_("Call"));
	txt_mars_daily_call2->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_call2->when(FL_WHEN_CHANGED);

	txt_mars_daily_state2 = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_daily_state2->tooltip(_("State"));
	txt_mars_daily_state2->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_state2->when(FL_WHEN_CHANGED);

	btn_mars_daily_pick_info2 = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_daily_pick_info2->tooltip(_("Select from list"));
	btn_mars_daily_pick_info2->callback((Fl_Callback*)cb_btn_mars_daily_pick_info2);

	Y += 25;
	txt_mars_daily_pos3 = new Fl_Input2(100, Y, 150, 24, _("INFO3"));
	txt_mars_daily_pos3->tooltip(_("Position"));
	txt_mars_daily_pos3->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_pos3->when(FL_WHEN_CHANGED);

	txt_mars_daily_call3 = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_daily_call3->tooltip(_("Call"));
	txt_mars_daily_call3->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_call3->when(FL_WHEN_CHANGED);

	txt_mars_daily_state3 = new Fl_Input2(404, Y, 30, 24, _(""));
	txt_mars_daily_state3->tooltip(_("State"));
	txt_mars_daily_state3->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_state3->when(FL_WHEN_CHANGED);

	btn_mars_daily_pick_info3 = new Fl_Button(436, Y, 30, 24, _("List"));
	btn_mars_daily_pick_info3->tooltip(_("Select from list"));
	btn_mars_daily_pick_info3->callback((Fl_Callback*)cb_btn_mars_daily_pick_info3);

	Y += 25;
	txt_mars_daily_sitrep_id = new Fl_Input2(100, Y, 150, 24, _("SUBJECT"));
	txt_mars_daily_sitrep_id->tooltip(_("Sitrep Id"));
	txt_mars_daily_sitrep_id->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_sitrep_id->when(FL_WHEN_CHANGED);

	txt_mars_daily_sitrep_loc = new Fl_Input2(252, Y, 150, 24, _(""));
	txt_mars_daily_sitrep_loc->tooltip(_("Sitrep location"));
	txt_mars_daily_sitrep_loc->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_sitrep_loc->when(FL_WHEN_CHANGED);

	Y += 25;
	tab_mars_daily_1->end();

	Y = tab_top;
	tab_mars_daily_2 = new Fl_Group(0, Y+25, 570, 360, _("Body"));

	Y += 30;
	txt_mars_daily_dtg_24hr = new Fl_Input2(30, Y, 150, 24, _("1."));
	txt_mars_daily_dtg_24hr->tooltip(_("DTG 24 HR PERIOD"));
	btn_mars_daily_dtg_24hr = new Fl_Button(182, Y, 22, 24, _("..."));
	btn_mars_daily_dtg_24hr->tooltip(_("Set Date/Time Group"));
	btn_mars_daily_dtg_24hr->callback((Fl_Callback*)cb_btn_mars_daily_dtg_24hr);

	Y += 25;
	txt_mars_daily_netcall = new Fl_Input2(30, Y, 150, 24, _("2."));
	txt_mars_daily_netcall->tooltip(_("Net call"));
	txt_mars_daily_netcall->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_netcall->when(FL_WHEN_CHANGED);

	btn_mars_daily_pick_netcall = new Fl_Button(182, Y, 30, 24, _("List"));
	btn_mars_daily_pick_netcall->tooltip(_("Select from list"));
	btn_mars_daily_pick_netcall->callback((Fl_Callback*)cb_btn_mars_daily_pick_netcall);

	sel_mars_daily_e_x = new Fl_ListBox(214, Y, 40, 24, _("E/X"));
	sel_mars_daily_e_x->tooltip(
		_("E - Emergency\nX - eXercise"));
	sel_mars_daily_e_x->add("E|X");
	sel_mars_daily_e_x->index(1);
	sel_mars_daily_e_x->align(FL_ALIGN_RIGHT);

	Y += 25;
	txt_mars_daily_dtg_active = new Fl_Input2(30, Y, 150, 24, _("3."));
	txt_mars_daily_dtg_active->tooltip(_("DTG activation"));
	btn_mars_daily_dtg_active = new Fl_Button(182, Y, 22, 24, _("..."));
	btn_mars_daily_dtg_active->tooltip(_("Set Date/Time Group"));
	btn_mars_daily_dtg_active->callback((Fl_Callback*)cb_btn_mars_daily_dtg_active);

	txt_mars_daily_dtg_deactive = new Fl_Input2(210, Y, 150, 24, _(""));
	txt_mars_daily_dtg_deactive->tooltip(_("DTG deactivation"));
	btn_mars_daily_dtg_deactive = new Fl_Button(362, Y, 22, 24, _("..."));
	btn_mars_daily_dtg_deactive->tooltip(_("Set Date/Time Group"));
	btn_mars_daily_dtg_deactive->callback((Fl_Callback*)cb_btn_mars_daily_dtg_deactive);

	txt_mars_daily_nbr_stations = new Fl_Input2(390, Y, 120, 24, _(""));
	txt_mars_daily_nbr_stations->tooltip(_("# stations"));

	Y += 25;
	Fl_Box *label = new Fl_Box(0, Y, 30, 24, "A.");
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_daily_details = new Fl_Input2(30, Y, 530, 58, "");
	txt_mars_daily_details->tooltip(_("DETAILS"));
	txt_mars_daily_details->type(4);
	txt_mars_daily_details->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_mars_daily_details->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_mars_daily_details->labeltype(FL_NORMAL_LABEL);
	txt_mars_daily_details->labelfont(0);
	txt_mars_daily_details->labelsize(14);
	txt_mars_daily_details->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_mars_daily_details->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_details->when(FL_WHEN_CHANGED);

	Y += 60;
	label = new Fl_Box(0, Y, 30, 24, "B.");
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_daily_activations = new Fl_Input2(30, Y, 530, 58, "");
	txt_mars_daily_activations->tooltip(_("Activitations"));
	txt_mars_daily_activations->type(4);
	txt_mars_daily_activations->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_mars_daily_activations->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_mars_daily_activations->labeltype(FL_NORMAL_LABEL);
	txt_mars_daily_activations->labelfont(0);
	txt_mars_daily_activations->labelsize(14);
	txt_mars_daily_activations->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_mars_daily_activations->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_activations->when(FL_WHEN_CHANGED);

	Y += 60;
	label = new Fl_Box(0, Y, 30, 24, "4.");
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_daily_agencies = new Fl_Input2(30, Y, 530, 58, "");
	txt_mars_daily_agencies->tooltip(_("AGENCIES"));
	txt_mars_daily_agencies->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_mars_daily_agencies->type(4);
	txt_mars_daily_agencies->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_mars_daily_agencies->labeltype(FL_NORMAL_LABEL);
	txt_mars_daily_agencies->labelfont(0);
	txt_mars_daily_agencies->labelsize(14);
	txt_mars_daily_agencies->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_mars_daily_agencies->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_agencies->when(FL_WHEN_CHANGED);

	Y += 60;
	label = new Fl_Box(0, Y, 30, 24, "5.");
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_daily_remarks = new Fl_Input2(30, Y, 530, 58, "");
	txt_mars_daily_remarks->tooltip(_("REMARKS"));
	txt_mars_daily_remarks->type(4);
	txt_mars_daily_remarks->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_mars_daily_remarks->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_mars_daily_remarks->labeltype(FL_NORMAL_LABEL);
	txt_mars_daily_remarks->labelfont(0);
	txt_mars_daily_remarks->labelsize(14);
	txt_mars_daily_remarks->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_mars_daily_remarks->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_daily_remarks->when(FL_WHEN_CHANGED);

	tab_mars_daily_2->end();

	tab_mars_daily_type->end();

	tab_mars_daily->end();

	tab_mars_daily->hide();
};

