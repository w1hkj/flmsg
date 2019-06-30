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

Fl_Group	*hics214_tab = (Fl_Group *)0;
Fl_Tabs		*hics214_tab_type = (Fl_Tabs *)0;
Fl_Group	*hics214_tab_1 = (Fl_Group *)0;
Fl_Input2	*hics214_txt_incident = (Fl_Input2 *)0;
Fl_Input2	*hics214_txt_date = (Fl_Input2 *)0;
Fl_Input2	*hics214_txt_sec_brch = (Fl_Input2 *)0;
Fl_Input2	*hics214_txt_position = (Fl_Input2 *)0;
Fl_Button	*hics214_btn_date = (Fl_Button *)0;
Fl_Input2	*hics214_txt_time = (Fl_Input2 *)0;
Fl_Button	*hics214_btn_time = (Fl_Button *)0;
Fl_Input2	*hics214_txt_op_period = (Fl_Input2 *)0;
Fl_Input2	*hics214_txt_prepared_by = (Fl_Input2 *)0;
Fl_Input2	*hics214_txt_facility = (Fl_Input2 *)0;

Fl_Group	*hics214_tab_2 = (Fl_Group *)0;
Fl_Input2	*hics214_txt_activity_time[30]={(Fl_Input2 *)0};
Fl_Input2	*hics214_txt_activity_event[30]={(Fl_Input2 *)0};

static void cb_hics214_btn_date(Fl_Button*, void*) {
  hics214_cb_set_date();
}

static void cb_hics214_btn_time(Fl_Button*, void*) {
  hics214_cb_set_time();
}


void create_hics214_tab()
{
	int Y = tab_top;
	hics214_tab = new Fl_Group(0, Y, 570, 390);
	hics214_tab->align(FL_ALIGN_TOP);

	hics214_tab_type = new Fl_Tabs(0, Y, 570, 387);
	hics214_tab_type->selection_color((Fl_Color)246);

	hics214_tab_1 = new Fl_Group(0, Y+25, 570, 360, _("Incident"));
		{
		Fl_Group* o = new Fl_Group(2, Y+32, 566, 170);
		o->box(FL_ENGRAVED_FRAME);
		o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		hics214_txt_incident = new Fl_Input2(135, Y+38, 425, 24, _("Incident Name"));
		hics214_txt_incident->tooltip(_("Incident name"));
		hics214_txt_incident->box(FL_DOWN_BOX);
		hics214_txt_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_incident->labeltype(FL_NORMAL_LABEL);
		hics214_txt_incident->labelfont(0);
		hics214_txt_incident->labelsize(14);
		hics214_txt_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_incident->align(FL_ALIGN_LEFT);
		hics214_txt_incident->callback(hics_changed);
		hics214_txt_incident->when(FL_WHEN_CHANGED);

		hics214_txt_date = new Fl_Input2(135, Y+65, 155, 24, _("Date Prepared"));
		hics214_txt_date->tooltip(_("Date prepared"));
		hics214_txt_date->box(FL_DOWN_BOX);
		hics214_txt_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_date->labeltype(FL_NORMAL_LABEL);
		hics214_txt_date->labelfont(0);
		hics214_txt_date->labelsize(14);
		hics214_txt_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_date->align(FL_ALIGN_LEFT);
		hics214_txt_date->callback(hics_changed);
		hics214_txt_date->when(FL_WHEN_CHANGED);

		hics214_btn_date = new Fl_Button(294, Y+67, 20, 20, _("..."));
		hics214_btn_date->tooltip(_("Set today"));
		hics214_btn_date->callback((Fl_Callback*)cb_hics214_btn_date);

		hics214_txt_time = new Fl_Input2(135, Y+90, 103, 24, _("Time Prepared"));
		hics214_txt_time->tooltip(_("Time prepared"));
		hics214_txt_time->box(FL_DOWN_BOX);
		hics214_txt_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_time->labeltype(FL_NORMAL_LABEL);
		hics214_txt_time->labelfont(0);
		hics214_txt_time->labelsize(14);
		hics214_txt_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_time->align(FL_ALIGN_LEFT);
		hics214_txt_time->callback(hics_changed);
		hics214_txt_time->when(FL_WHEN_CHANGED);

		hics214_btn_time = new Fl_Button(247, Y+92, 20, 20, _("..."));
		hics214_btn_time->tooltip(_("Set time now"));
		hics214_btn_time->callback((Fl_Callback*)cb_hics214_btn_time);

		hics214_txt_sec_brch = new Fl_Input2(135, Y+115, 425, 24, _("Unit Name"));
		hics214_txt_sec_brch->tooltip(_("Name / Designation"));
		hics214_txt_sec_brch->box(FL_DOWN_BOX);
		hics214_txt_sec_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_sec_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_sec_brch->labeltype(FL_NORMAL_LABEL);
		hics214_txt_sec_brch->labelfont(0);
		hics214_txt_sec_brch->labelsize(14);
		hics214_txt_sec_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_sec_brch->align(FL_ALIGN_LEFT);
		hics214_txt_sec_brch->callback(hics_changed);
		hics214_txt_sec_brch->when(FL_WHEN_CHANGED);

		hics214_txt_position = new Fl_Input2(135, Y+140, 425, 24, _("Unit leader"));
		hics214_txt_position->tooltip(_("Name and Position"));
		hics214_txt_position->box(FL_DOWN_BOX);
		hics214_txt_position->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_position->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_position->labeltype(FL_NORMAL_LABEL);
		hics214_txt_position->labelfont(0);
		hics214_txt_position->labelsize(14);
		hics214_txt_position->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_position->align(FL_ALIGN_LEFT);
		hics214_txt_position->callback(hics_changed);
		hics214_txt_position->when(FL_WHEN_CHANGED);

		hics214_txt_op_period = new Fl_Input2(135, Y+165, 425, 24, _("Oper\' Period"));
		hics214_txt_op_period->tooltip(_("Date / Time"));
		hics214_txt_op_period->box(FL_DOWN_BOX);
		hics214_txt_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_op_period->labeltype(FL_NORMAL_LABEL);
		hics214_txt_op_period->labelfont(0);
		hics214_txt_op_period->labelsize(14);
		hics214_txt_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_op_period->align(FL_ALIGN_LEFT);
		hics214_txt_op_period->callback(hics_changed);
		hics214_txt_op_period->when(FL_WHEN_CHANGED);

		o->end();
		}

		{
		Fl_Group* o = new Fl_Group(2, Y+203, 566, 60);
		o->box(FL_ENGRAVED_FRAME);

		hics214_txt_prepared_by = new Fl_Input2(135, Y+208, 425, 24, _("Prepared By"));
		hics214_txt_prepared_by->tooltip(_("Name and Position"));
		hics214_txt_prepared_by->box(FL_DOWN_BOX);
		hics214_txt_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_prepared_by->labeltype(FL_NORMAL_LABEL);
		hics214_txt_prepared_by->labelfont(0);
		hics214_txt_prepared_by->labelsize(14);
		hics214_txt_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_prepared_by->align(FL_ALIGN_LEFT);
		hics214_txt_prepared_by->callback(hics_changed);
		hics214_txt_prepared_by->when(FL_WHEN_CHANGED);

		hics214_txt_facility = new Fl_Input2(135, Y+234, 425, 24, _("Facility"));
		hics214_txt_facility->tooltip(_(""));
		hics214_txt_facility->box(FL_DOWN_BOX);
		hics214_txt_facility->color((Fl_Color)FL_BACKGROUND2_COLOR);
		hics214_txt_facility->selection_color((Fl_Color)FL_SELECTION_COLOR);
		hics214_txt_facility->labeltype(FL_NORMAL_LABEL);
		hics214_txt_facility->labelfont(0);
		hics214_txt_facility->labelsize(14);
		hics214_txt_facility->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		hics214_txt_facility->align(FL_ALIGN_LEFT);
		hics214_txt_facility->callback(hics_changed);
		hics214_txt_facility->when(FL_WHEN_CHANGED);

		o->end();
		}

	hics214_tab_1->end();

	hics214_tab_2 = new Fl_Group(0, Y+25, 570, 360, _("Activity Log"));
	hics214_tab_2->hide();
	hics214_tab_2->hide();

	Fl_Group *sg1 = new Fl_Group(5, Y+32, 560, 350);
	sg1->box(FL_FLAT_BOX);

		Fl_Box* bx1 = new Fl_Box(5, Y+32, 100, 20, _("Time"));
		bx1->box(FL_THIN_DOWN_BOX);
		bx1->color((Fl_Color)215);

		Fl_Box* bx2 = new Fl_Box(bx1->x() + bx1->w(), Y+32, 440, 20, _("Major Events"));
		bx2->box(FL_THIN_DOWN_BOX);
		bx2->color((Fl_Color)215);

		Fl_Scroll* sc1 = new Fl_Scroll(4, Y+54, 560, 320);
		sc1->type(2);
		sc1->box(FL_THIN_DOWN_BOX);

		for (int i = 0; i < 30; i++) {
			hics214_txt_activity_time[i] = new Fl_Input2(5, Y+54 + i*24, 100, 24);
			hics214_txt_activity_time[i]->tooltip(_(""));
			hics214_txt_activity_time[i]->box(FL_DOWN_BOX);
			hics214_txt_activity_time[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			hics214_txt_activity_time[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			hics214_txt_activity_time[i]->labeltype(FL_NORMAL_LABEL);
			hics214_txt_activity_time[i]->labelfont(0);
			hics214_txt_activity_time[i]->labelsize(14);
			hics214_txt_activity_time[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			hics214_txt_activity_time[i]->align(FL_ALIGN_CENTER);
			hics214_txt_activity_time[i]->when(FL_WHEN_CHANGED);
			hics214_txt_activity_event[i] = new Fl_Input2(106, Y+54 + i*24, 442, 24);
			hics214_txt_activity_event[i]->tooltip(_(""));
			hics214_txt_activity_event[i]->box(FL_DOWN_BOX);
			hics214_txt_activity_event[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			hics214_txt_activity_event[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			hics214_txt_activity_event[i]->labeltype(FL_NORMAL_LABEL);
			hics214_txt_activity_event[i]->labelfont(0);
			hics214_txt_activity_event[i]->labelsize(14);
			hics214_txt_activity_event[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			hics214_txt_activity_event[i]->align(FL_ALIGN_CENTER);
			hics214_txt_activity_event[i]->callback(hics_changed);
			hics214_txt_activity_event[i]->when(FL_WHEN_CHANGED);
		}
		sc1->end();
	sg1->end();
	Fl_Group *sg2 = new Fl_Group(565, Y+32, 1, 350);
	sg2->box(FL_FLAT_BOX);
	sg2->end();

	hics214_tab_2->end();
	hics214_tab_2->resizable(sg2);

	hics214_tab_type->end();
	Fl_Group::current()->resizable(hics214_tab_type);
hics214_tab->end();

hics214_tab->hide();

}
