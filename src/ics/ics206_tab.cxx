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

Fl_Group	*tab_ics206 = (Fl_Group *)0;
Fl_Tabs		*tab_ics206_type = (Fl_Tabs *)0;
Fl_Group	*tab_206_med_plan = (Fl_Group *)0;
Fl_Input2	*txt_206_name = (Fl_Input2 *)0;
Fl_Input2	*txt_206_op_period = (Fl_Input2 *)0;
Fl_Input2	*txt_206_time_prepared = (Fl_Input2 *)0;
Fl_Button	*btn_206_time = (Fl_Button *)0;
Fl_DateInput	*txt_206_date_prepared = (Fl_DateInput *)0;
Fl_Button	*btn_206_date = (Fl_Button *)0;
Fl_Input2	*txt_206_medaid_sta[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_medaid_loc[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_medaid_paramedics[5]={(Fl_Check_Button *)0};
Fl_Input2	*txt_206_preparer = (Fl_Input2 *)0;
Fl_Input2	*txt_206_reviewer = (Fl_Input2 *)0;
Fl_Group	*tab_206_transport = (Fl_Group *)0;
Fl_Input2	*txt_206_transport_name[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_transport_address[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_transport_paramedics[5]={(Fl_Check_Button *)0};
Fl_Input2	*txt_206_transport_phone[5]={(Fl_Input2 *)0};
Fl_Group	*tab_206_ambulance = (Fl_Group *)0;
Fl_Input2	*txt_206_ambulance_name[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_ambulance_loc[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_ambulance_paramedics[5]={(Fl_Check_Button *)0};
Fl_Group	*tab_206_hospital = (Fl_Group *)0;
Fl_Input2	*txt_206_hosp_name[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_address[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_phone[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_airtime[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_gndtime[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_hosp_helipad[5]={(Fl_Check_Button *)0};
Fl_Check_Button	*btn_206_hosp_burn_center[5]={(Fl_Check_Button *)0};
Fl_Group	*tab_206_med_proc = (Fl_Group *)0;
FTextEdit	*txt_206_procedure = (FTextEdit *)0;

static void cb_btn_206_time(Fl_Button*, void*) {
  cb_206_settime();
}

static void cb_btn_206_date(Fl_Button*, void*) {
  cb_206_setdate();
}

void create_ics206_tab()
{
	int Y = tab_top;
	tab_ics206 = new Fl_Group(0, Y, 570, 390);
	tab_ics206->align(FL_ALIGN_TOP);

	tab_ics206_type = new Fl_Tabs(0, Y, 570, 387);
	tab_ics206_type->selection_color((Fl_Color)246);

	tab_206_med_plan = new Fl_Group(0, Y+25, 570, 360, _("Med Plan"));
		{
		Fl_Group* o = new Fl_Group(2, Y+30, 566, 80);
		o->box(FL_ENGRAVED_FRAME);
		txt_206_name = new Fl_Input2(9, Y+49, 242, 24, _("Incident Name"));
		txt_206_name->tooltip(_("Addressee"));
		txt_206_name->box(FL_DOWN_BOX);
		txt_206_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_name->labeltype(FL_NORMAL_LABEL);
		txt_206_name->labelfont(0);
		txt_206_name->labelsize(14);
		txt_206_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_name->align(FL_ALIGN_TOP_LEFT);
		txt_206_name->callback(ics_changed);
		txt_206_name->when(FL_WHEN_CHANGED);

		txt_206_op_period = new Fl_Input2(151, Y+77, 410, 24, _("Operational Period:"));
		txt_206_op_period->tooltip(_("Subject"));
		txt_206_op_period->box(FL_DOWN_BOX);
		txt_206_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_op_period->labeltype(FL_NORMAL_LABEL);
		txt_206_op_period->labelfont(0);
		txt_206_op_period->labelsize(14);
		txt_206_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_op_period->align(FL_ALIGN_LEFT);
		txt_206_op_period->callback(ics_changed);
		txt_206_op_period->when(FL_WHEN_CHANGED);

		txt_206_time_prepared = new Fl_Input2(407, Y+47, 103, 24, _("Time Prepared"));
		txt_206_time_prepared->tooltip(_("Time of origination"));
		txt_206_time_prepared->box(FL_DOWN_BOX);
		txt_206_time_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_time_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_time_prepared->labeltype(FL_NORMAL_LABEL);
		txt_206_time_prepared->labelfont(0);
		txt_206_time_prepared->labelsize(14);
		txt_206_time_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_time_prepared->align(FL_ALIGN_TOP_LEFT);
		txt_206_time_prepared->callback(ics_changed);
		txt_206_time_prepared->when(FL_WHEN_CHANGED);

		btn_206_time = new Fl_Button(517, Y+49, 20, 20, _("..."));
		btn_206_time->tooltip(_("Set time now"));
		btn_206_time->callback((Fl_Callback*)cb_btn_206_time);

		txt_206_date_prepared = new Fl_DateInput(256, Y+47, 125, 24, _("Date Prepared"));
		txt_206_date_prepared->tooltip(_("Date of origination"));
		txt_206_date_prepared->box(FL_DOWN_BOX);
		txt_206_date_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_date_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_date_prepared->labeltype(FL_NORMAL_LABEL);
		txt_206_date_prepared->labelfont(0);
		txt_206_date_prepared->labelsize(14);
		txt_206_date_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_date_prepared->align(FL_ALIGN_TOP_LEFT);
		txt_206_date_prepared->callback(ics_changed);
		txt_206_date_prepared->when(FL_WHEN_CHANGED);

		btn_206_date = new Fl_Button(383, Y+49, 20, 20, _("..."));
		btn_206_date->tooltip(_("Set today"));
		btn_206_date->callback((Fl_Callback*)cb_btn_206_date);

		o->end();
		}
		{
		Fl_Group* o = new Fl_Group(2, Y+110, 566, 210);
		o->box(FL_ENGRAVED_FRAME);
		o->align(FL_ALIGN_TOP_LEFT);
		for (int i = 0; i < 5; i++) {
			txt_206_medaid_sta[i] = new Fl_Input2(
				7, Y+136 + i*38, 160, 24, i == 0 ? _("Medical Aid Stations"):"");
			txt_206_medaid_sta[i]->tooltip(_(""));
			txt_206_medaid_sta[i]->box(FL_DOWN_BOX);
			txt_206_medaid_sta[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_206_medaid_sta[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_206_medaid_sta[i]->labeltype(FL_NORMAL_LABEL);
			txt_206_medaid_sta[i]->labelfont(0);
			txt_206_medaid_sta[i]->labelsize(14);
			txt_206_medaid_sta[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_206_medaid_sta[i]->align(FL_ALIGN_TOP_LEFT);
			txt_206_medaid_sta[i]->callback(ics_changed);
			txt_206_medaid_sta[i]->when(FL_WHEN_CHANGED);

			txt_206_medaid_loc[i] = new Fl_Input2(169, Y+136 + i*38, 370, 24, i == 0 ? _("Location"):"");
			txt_206_medaid_loc[i]->tooltip(_(""));
			txt_206_medaid_loc[i]->box(FL_DOWN_BOX);
			txt_206_medaid_loc[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_206_medaid_loc[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_206_medaid_loc[i]->labeltype(FL_NORMAL_LABEL);
			txt_206_medaid_loc[i]->labelfont(0);
			txt_206_medaid_loc[i]->labelsize(14);
			txt_206_medaid_loc[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_206_medaid_loc[i]->align(FL_ALIGN_TOP_LEFT);
			txt_206_medaid_loc[i]->callback(ics_changed);
			txt_206_medaid_loc[i]->when(FL_WHEN_CHANGED);

			btn_206_medaid_paramedics[i] = new Fl_Check_Button(
				540, Y+136 + i*38, 20, 22, i == 0 ? _("Paramedics"):"");
			btn_206_medaid_paramedics[i]->down_box(FL_DOWN_BOX);
			btn_206_medaid_paramedics[i]->align(FL_ALIGN_TOP_RIGHT);
		} // Fl_Check_Button* btn_206_medaid_paramedics[i]
		o->end();
		}

		{
		Fl_Group* o = new Fl_Group(2, Y+320, 566, 30);
		o->box(FL_ENGRAVED_FRAME);
		txt_206_preparer = new Fl_Input2(71, Y+323, 210, 24, _("Preparer"));
		txt_206_preparer->tooltip(_(""));
		txt_206_preparer->box(FL_DOWN_BOX);
		txt_206_preparer->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_preparer->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_preparer->labeltype(FL_NORMAL_LABEL);
		txt_206_preparer->labelfont(0);
		txt_206_preparer->labelsize(14);
		txt_206_preparer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_preparer->align(FL_ALIGN_LEFT);
		txt_206_preparer->callback(ics_changed);
		txt_206_preparer->when(FL_WHEN_CHANGED);

		txt_206_reviewer = new Fl_Input2(350, Y+323, 210, 24, _("Reviewer"));
		txt_206_reviewer->tooltip(_(""));
		txt_206_reviewer->box(FL_DOWN_BOX);
		txt_206_reviewer->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_reviewer->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_reviewer->labeltype(FL_NORMAL_LABEL);
		txt_206_reviewer->labelfont(0);
		txt_206_reviewer->labelsize(14);
		txt_206_reviewer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_reviewer->align(FL_ALIGN_LEFT);
		txt_206_reviewer->callback(ics_changed);
		txt_206_reviewer->when(FL_WHEN_CHANGED);

		o->end();
		}
	tab_206_med_plan->end();

	tab_206_transport = new Fl_Group(0, Y+25, 570, 360, _("Transport"));
	tab_206_transport->hide();
	{
	Fl_Group* o = new Fl_Group(2, Y+35, 566, 238, _("Ambulance Services"));
	o->box(FL_ENGRAVED_FRAME);
	o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
	for (int i = 0; i < 5; i++) {
		txt_206_transport_name[i] = new Fl_Input2(
			7, Y+80 + i*38, 125, 24, i == 0 ? _("Service Name"):"");
		txt_206_transport_name[i]->tooltip(_(""));
		txt_206_transport_name[i]->box(FL_DOWN_BOX);
		txt_206_transport_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_transport_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_transport_name[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_transport_name[i]->labelfont(0);
		txt_206_transport_name[i]->labelsize(14);
		txt_206_transport_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_transport_name[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_transport_name[i]->callback(ics_changed);
		txt_206_transport_name[i]->when(FL_WHEN_CHANGED);

		txt_206_transport_address[i] = new Fl_Input2(
			135, Y+80 + i*38, 280, 24, i == 0 ? _("Address"):"");
		txt_206_transport_address[i]->tooltip(_(""));
		txt_206_transport_address[i]->box(FL_DOWN_BOX);
		txt_206_transport_address[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_transport_address[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_transport_address[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_transport_address[i]->labelfont(0);
		txt_206_transport_address[i]->labelsize(14);
		txt_206_transport_address[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_transport_address[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_transport_address[i]->callback(ics_changed);
		txt_206_transport_address[i]->when(FL_WHEN_CHANGED);

		btn_206_transport_paramedics[i] = new Fl_Check_Button(
			540, Y+80 + i*38, 20, 22, i == 0 ? _("Paramedics"):"");
		btn_206_transport_paramedics[i]->down_box(FL_DOWN_BOX);
		btn_206_transport_paramedics[i]->align(FL_ALIGN_TOP_RIGHT);

		txt_206_transport_phone[i] = new Fl_Input2(
			417, Y+80 + i*38, 121, 24, i == 0 ? _("Phone"):"");
		txt_206_transport_phone[i]->tooltip(_(""));
		txt_206_transport_phone[i]->box(FL_DOWN_BOX);
		txt_206_transport_phone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_transport_phone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_transport_phone[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_transport_phone[i]->labelfont(0);
		txt_206_transport_phone[i]->labelsize(14);
		txt_206_transport_phone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_transport_phone[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_transport_phone[i]->callback(ics_changed);
		txt_206_transport_phone[i]->when(FL_WHEN_CHANGED);
	}
	o->end();
	}
	tab_206_transport->end();

	tab_206_ambulance = new Fl_Group(0, Y+25, 570, 360, _("Ambulance"));
	tab_206_ambulance->hide();
	{
	Fl_Group* o = new Fl_Group(2, Y+30, 565, 235, _("Incident Ambulances"));
	o->box(FL_ENGRAVED_FRAME);
	o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
	for (int i = 0; i < 5; i++) {
		txt_206_ambulance_name[i] = new Fl_Input2(
			8, Y+77 + i*38, 160, 24, i == 0 ? _("Name"):"");
		txt_206_ambulance_name[i]->tooltip(_(""));
		txt_206_ambulance_name[i]->box(FL_DOWN_BOX);
		txt_206_ambulance_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_ambulance_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_ambulance_name[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_ambulance_name[i]->labelfont(0);
		txt_206_ambulance_name[i]->labelsize(14);
		txt_206_ambulance_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_ambulance_name[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_ambulance_name[i]->callback(ics_changed);
		txt_206_ambulance_name[i]->when(FL_WHEN_CHANGED);

		txt_206_ambulance_loc[i] = new Fl_Input2(
			170, Y+77 + i*38, 370, 24, i == 0 ? _("Location"):"");
		txt_206_ambulance_loc[i]->tooltip(_(""));
		txt_206_ambulance_loc[i]->box(FL_DOWN_BOX);
		txt_206_ambulance_loc[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_ambulance_loc[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_ambulance_loc[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_ambulance_loc[i]->labelfont(0);
		txt_206_ambulance_loc[i]->labelsize(14);
		txt_206_ambulance_loc[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_ambulance_loc[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_ambulance_loc[i]->callback(ics_changed);
		txt_206_ambulance_loc[i]->when(FL_WHEN_CHANGED);

		btn_206_ambulance_paramedics[i] = new Fl_Check_Button(
			541, Y+77 + i*38, 20, 22, i == 0 ? _("Paramedics"):"");
		btn_206_ambulance_paramedics[i]->down_box(FL_DOWN_BOX);
		btn_206_ambulance_paramedics[i]->align(FL_ALIGN_TOP_RIGHT);
	}
	o->end();
	} // Fl_Group* o
	tab_206_ambulance->end();

	tab_206_hospital = new Fl_Group(0, Y+25, 570, 360, _("Hospital"));
	tab_206_hospital->hide();
	{
	Fl_Group* o = new Fl_Group(2, Y+31, 566, 318, _("Hospitals"));
	o->box(FL_ENGRAVED_FRAME);
	o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
	for (int i = 0; i < 5; i++) {
		txt_206_hosp_name[i] = new Fl_Input2(9, Y+76 + i*54, 125, 24, i == 0 ? _("Name"):"");
		txt_206_hosp_name[i]->tooltip(_(""));
		txt_206_hosp_name[i]->box(FL_DOWN_BOX);
		txt_206_hosp_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_hosp_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_hosp_name[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_hosp_name[i]->labelfont(0);
		txt_206_hosp_name[i]->labelsize(14);
		txt_206_hosp_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_hosp_name[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_hosp_name[i]->callback(ics_changed);
		txt_206_hosp_name[i]->when(FL_WHEN_CHANGED);

		txt_206_hosp_address[i] = new Fl_Input2(137, Y+76 + i*54, 300, 24, i == 0 ? _("Address"):"");
		txt_206_hosp_address[i]->tooltip(_(""));
		txt_206_hosp_address[i]->box(FL_DOWN_BOX);
		txt_206_hosp_address[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_hosp_address[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_hosp_address[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_hosp_address[i]->labelfont(0);
		txt_206_hosp_address[i]->labelsize(14);
		txt_206_hosp_address[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_hosp_address[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_hosp_address[i]->callback(ics_changed);
		txt_206_hosp_address[i]->when(FL_WHEN_CHANGED);

		txt_206_hosp_phone[i] = new Fl_Input2(440, Y+76 + i*54, 121, 24, i == 0 ? _("Phone"):"");
		txt_206_hosp_phone[i]->tooltip(_(""));
		txt_206_hosp_phone[i]->box(FL_DOWN_BOX);
		txt_206_hosp_phone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_hosp_phone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_hosp_phone[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_hosp_phone[i]->labelfont(0);
		txt_206_hosp_phone[i]->labelsize(14);
		txt_206_hosp_phone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_hosp_phone[i]->align(FL_ALIGN_TOP_LEFT);
		txt_206_hosp_phone[i]->callback(ics_changed);
		txt_206_hosp_phone[i]->when(FL_WHEN_CHANGED);

		txt_206_hosp_airtime[i] = new Fl_Input2(136, Y+104 + i*54, 80, 24, _("Travel Time Air:"));		txt_206_hosp_airtime[i]->tooltip(_(""));
		txt_206_hosp_airtime[i]->box(FL_DOWN_BOX);
		txt_206_hosp_airtime[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_hosp_airtime[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_hosp_airtime[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_hosp_airtime[i]->labelfont(0);
		txt_206_hosp_airtime[i]->labelsize(14);
		txt_206_hosp_airtime[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_hosp_airtime[i]->align(FL_ALIGN_LEFT);
		txt_206_hosp_airtime[i]->callback(ics_changed);
		txt_206_hosp_airtime[i]->when(FL_WHEN_CHANGED);

		txt_206_hosp_gndtime[i] = new Fl_Input2(253, Y+104 + i*54, 80, 24, _("Gnd"));
		txt_206_hosp_gndtime[i]->tooltip(_(""));
		txt_206_hosp_gndtime[i]->box(FL_DOWN_BOX);
		txt_206_hosp_gndtime[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_206_hosp_gndtime[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_206_hosp_gndtime[i]->labeltype(FL_NORMAL_LABEL);
		txt_206_hosp_gndtime[i]->labelfont(0);
		txt_206_hosp_gndtime[i]->labelsize(14);
		txt_206_hosp_gndtime[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_206_hosp_gndtime[i]->align(FL_ALIGN_LEFT);
		txt_206_hosp_gndtime[i]->callback(ics_changed);
		txt_206_hosp_gndtime[i]->when(FL_WHEN_CHANGED);

		btn_206_hosp_helipad[i] = new Fl_Check_Button(342, Y+108 + i*54, 82, 15, _("Helipad"));
		btn_206_hosp_helipad[i]->down_box(FL_DOWN_BOX);

		btn_206_hosp_burn_center[i] = new Fl_Check_Button(440, Y+108 + i*54, 107, 15, _("Burn center"));
		btn_206_hosp_burn_center[i]->down_box(FL_DOWN_BOX);
	}
	o->end();
	} // Fl_Group* o

	tab_206_hospital->end();

	tab_206_med_proc = new Fl_Group(0, Y+25, 570, 360, _("Med\' Proc\'"));
	tab_206_med_proc->hide();
	txt_206_procedure = new FTextEdit(4, Y+35, 562, 345);
	txt_206_procedure->box(FL_DOWN_FRAME);
	txt_206_procedure->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_206_procedure->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_206_procedure->labeltype(FL_NORMAL_LABEL);
	txt_206_procedure->labelfont(0);
	txt_206_procedure->labelsize(14);
	txt_206_procedure->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_206_procedure->align(FL_ALIGN_CENTER);
	txt_206_procedure->callback(ics_changed);
	txt_206_procedure->when(FL_WHEN_CHANGED);

	Fl_Group::current()->resizable(txt_206_procedure);
	tab_206_med_proc->end();
	tab_ics206_type->end();
	Fl_Group::current()->resizable(tab_ics206_type);
	tab_ics206->end();

	tab_ics206->hide();
}
