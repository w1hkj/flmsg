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

Fl_Group	*tab_ics214 = (Fl_Group *)0;
Fl_Tabs	*tab_ics214_type = (Fl_Tabs *)0;
Fl_Group	*tab_214_1 = (Fl_Group *)0;
Fl_Input2	*txt_214_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_214_date = (Fl_Input2 *)0;
Fl_Input2	*txt_214_unit_name = (Fl_Input2 *)0;
Fl_Input2	*txt_214_unit_leader = (Fl_Input2 *)0;
Fl_Button	*btn_214_date = (Fl_Button *)0;
Fl_Input2	*txt_214_time = (Fl_Input2 *)0;
Fl_Button	*btn_214_time = (Fl_Button *)0;

Fl_Input2	*txt_214_op_period = (Fl_Input2 *)0;
Fl_Input2	*txt_214_prepared_by = (Fl_Input2 *)0;
Fl_Group	*tab_214_2 = (Fl_Group *)0;
Fl_Input2	*txt_214_roster_name[16]={(Fl_Input2 *)0};
Fl_Input2	*txt_214_roster_position[16]={(Fl_Input2 *)0};
Fl_Input2	*txt_214_roster_home_base[16]={(Fl_Input2 *)0};
Fl_Group	*tab_214_3 = (Fl_Group *)0;
Fl_Input2	*txt_214_activity_time[16]={(Fl_Input2 *)0};
Fl_Input2	*txt_214_activity_event[16]={(Fl_Input2 *)0};

static void cb_btn_214_date(Fl_Button*, void*) {
  cb_214_set_date();
}

static void cb_btn_214_time(Fl_Button*, void*) {
  cb_214_set_time();
}


void create_ics214_tab()
{
	int Y = tab_top;
	tab_ics214 = new Fl_Group(0, Y, 570, 390);
	tab_ics214->align(FL_ALIGN_TOP);

	tab_ics214_type = new Fl_Tabs(0, Y, 570, 387);
	tab_ics214_type->selection_color((Fl_Color)246);

	tab_214_1 = new Fl_Group(0, Y+25, 570, 360, _("Incident"));
		{
		Fl_Group* o = new Fl_Group(2, Y+32, 566, 170);
		o->box(FL_ENGRAVED_FRAME);
		o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		txt_214_incident = new Fl_Input2(135, Y+38, 425, 24, _("Incident Name"));
		txt_214_incident->tooltip(_("Incident name"));
		txt_214_incident->box(FL_DOWN_BOX);
		txt_214_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_214_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_214_incident->labeltype(FL_NORMAL_LABEL);
		txt_214_incident->labelfont(0);
		txt_214_incident->labelsize(14);
		txt_214_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_214_incident->align(FL_ALIGN_LEFT);
		txt_214_incident->callback(ics_changed);
		txt_214_incident->when(FL_WHEN_CHANGED);

		txt_214_date = new Fl_Input2(135, Y+65, 155, 24, _("Date Prepared"));
		txt_214_date->tooltip(_("Date prepared"));
		txt_214_date->box(FL_DOWN_BOX);
		txt_214_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_214_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_214_date->labeltype(FL_NORMAL_LABEL);
		txt_214_date->labelfont(0);
		txt_214_date->labelsize(14);
		txt_214_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_214_date->align(FL_ALIGN_LEFT);
		txt_214_date->callback(ics_changed);
		txt_214_date->when(FL_WHEN_CHANGED);

		btn_214_date = new Fl_Button(294, Y+67, 20, 20, _("..."));
		btn_214_date->tooltip(_("Set today"));
		btn_214_date->callback((Fl_Callback*)cb_btn_214_date);

		txt_214_time = new Fl_Input2(135, Y+90, 103, 24, _("Time Prepared"));
		txt_214_time->tooltip(_("Time prepared"));
		txt_214_time->box(FL_DOWN_BOX);
		txt_214_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_214_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_214_time->labeltype(FL_NORMAL_LABEL);
		txt_214_time->labelfont(0);
		txt_214_time->labelsize(14);
		txt_214_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_214_time->align(FL_ALIGN_LEFT);
		txt_214_time->callback(ics_changed);
		txt_214_time->when(FL_WHEN_CHANGED);

		btn_214_time = new Fl_Button(247, Y+92, 20, 20, _("..."));
		btn_214_time->tooltip(_("Set time now"));
		btn_214_time->callback((Fl_Callback*)cb_btn_214_time);

		txt_214_unit_name = new Fl_Input2(135, Y+115, 425, 24, _("Unit Name"));
		txt_214_unit_name->tooltip(_("Name / Designation"));
		txt_214_unit_name->box(FL_DOWN_BOX);
		txt_214_unit_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_214_unit_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_214_unit_name->labeltype(FL_NORMAL_LABEL);
		txt_214_unit_name->labelfont(0);
		txt_214_unit_name->labelsize(14);
		txt_214_unit_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_214_unit_name->align(FL_ALIGN_LEFT);
		txt_214_unit_name->callback(ics_changed);
		txt_214_unit_name->when(FL_WHEN_CHANGED);

		txt_214_unit_leader = new Fl_Input2(135, Y+140, 425, 24, _("Unit leader"));
		txt_214_unit_leader->tooltip(_("Name and Position"));
		txt_214_unit_leader->box(FL_DOWN_BOX);
		txt_214_unit_leader->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_214_unit_leader->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_214_unit_leader->labeltype(FL_NORMAL_LABEL);
		txt_214_unit_leader->labelfont(0);
		txt_214_unit_leader->labelsize(14);
		txt_214_unit_leader->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_214_unit_leader->align(FL_ALIGN_LEFT);
		txt_214_unit_leader->callback(ics_changed);
		txt_214_unit_leader->when(FL_WHEN_CHANGED);

		txt_214_op_period = new Fl_Input2(135, Y+165, 425, 24, _("Oper\' Period"));
		txt_214_op_period->tooltip(_("Date / Time"));
		txt_214_op_period->box(FL_DOWN_BOX);
		txt_214_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_214_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_214_op_period->labeltype(FL_NORMAL_LABEL);
		txt_214_op_period->labelfont(0);
		txt_214_op_period->labelsize(14);
		txt_214_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_214_op_period->align(FL_ALIGN_LEFT);
		txt_214_op_period->callback(ics_changed);
		txt_214_op_period->when(FL_WHEN_CHANGED);

		o->end();
		}

		{
		Fl_Group* o = new Fl_Group(2, Y+203, 566, 35);
		o->box(FL_ENGRAVED_FRAME);

		txt_214_prepared_by = new Fl_Input2(135, Y+208, 425, 24, _("Prepared By"));
		txt_214_prepared_by->tooltip(_("Name and Position"));
		txt_214_prepared_by->box(FL_DOWN_BOX);
		txt_214_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_214_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_214_prepared_by->labeltype(FL_NORMAL_LABEL);
		txt_214_prepared_by->labelfont(0);
		txt_214_prepared_by->labelsize(14);
		txt_214_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_214_prepared_by->align(FL_ALIGN_LEFT);
		txt_214_prepared_by->callback(ics_changed);
		txt_214_prepared_by->when(FL_WHEN_CHANGED);
		o->end();
		}

	tab_214_1->end();


	tab_214_2 = new Fl_Group(0, Y+25, 570, 360, _("Roster"));
	tab_214_2->hide();

	Fl_Group *g1a = new Fl_Group(0, Y+32, 568, 353);
	g1a->box(FL_FLAT_BOX);

		Fl_Box* bx1a = new Fl_Box(
			5, Y+32,
			180, 20, _("Name"));
		bx1a->box(FL_THIN_DOWN_BOX);
		bx1a->color((Fl_Color)215);

		Fl_Box* bx2a = new Fl_Box(
			bx1a->x() + bx1a->w(), Y+32,
			180, 20, _("ICS Position"));
		bx2a->box(FL_THIN_DOWN_BOX);
		bx2a->color((Fl_Color)215);

		Fl_Box* bx3a = new Fl_Box(
			bx2a->x() + bx2a->w(), Y+32,
			180, 20, _("Home Base"));
		bx3a->box(FL_THIN_DOWN_BOX);
		bx3a->color((Fl_Color)215);

		Fl_Scroll* sc1 = new Fl_Scroll(5, Y+54, 560, 320);
		sc1->type(Fl_Scroll::VERTICAL_ALWAYS);
		sc1->box(FL_THIN_DOWN_BOX);
		for (int i = 0; i < 16; i++) {
			txt_214_roster_name[i] = new Fl_Input2(5, Y+54 + i*24, 180, 24);
			txt_214_roster_name[i]->tooltip(_(""));
			txt_214_roster_name[i]->callback(ics_changed);
			txt_214_roster_name[i]->when(FL_WHEN_CHANGED);

			txt_214_roster_position[i] = new Fl_Input2(186, Y+54 + i*24, 180, 24);
			txt_214_roster_position[i]->tooltip(_(""));
			txt_214_roster_position[i]->callback(ics_changed);
			txt_214_roster_position[i]->when(FL_WHEN_CHANGED);

			txt_214_roster_home_base[i] = new Fl_Input2(367, Y+54 + i*24, 180, 24);
			txt_214_roster_home_base[i]->tooltip(_(""));
			txt_214_roster_home_base[i]->callback(ics_changed);
			txt_214_roster_home_base[i]->when(FL_WHEN_CHANGED);
		}
		sc1->end();
	g1a->end();

	Fl_Group *g2a = new Fl_Group(568, Y+32, 1, 353);
	g2a->box(FL_FLAT_BOX);
	g2a->end();

	tab_214_2->end();
	tab_214_2->resizable(g2a);

	tab_214_3 = new Fl_Group(0, Y+25, 570, 360, _("Activity Log"));
	tab_214_3->hide();

	Fl_Group *g1b = new Fl_Group(5, Y+32, 564, 353);
	g1b->box(FL_FLAT_BOX);

		Fl_Box* bx1b = new Fl_Box(5, Y+32, 100, 20, _("Time"));
		bx1b->box(FL_THIN_DOWN_BOX);
		bx1b->color((Fl_Color)215);

		Fl_Box* bx2b = new Fl_Box(bx1b->x() + bx1b->w(), Y+32, 440, 20, _("Major Events"));
		bx2b->box(FL_THIN_DOWN_BOX);
		bx2b->color((Fl_Color)215);

		Fl_Scroll* sc2 = new Fl_Scroll(4, Y+54, 560, 320);
		sc2->type(Fl_Scroll::VERTICAL_ALWAYS);
		sc2->box(FL_THIN_DOWN_BOX);
		for (int i = 0; i < 16; i++) {
			txt_214_activity_time[i] = new Fl_Input2(5, Y+54 + i*24, 100, 24);
			txt_214_activity_time[i]->tooltip(_(""));
			txt_214_activity_time[i]->callback(ics_changed);
			txt_214_activity_time[i]->when(FL_WHEN_CHANGED);

			txt_214_activity_event[i] = new Fl_Input2(106, Y+54 + i*24, 442, 24);
			txt_214_activity_event[i]->tooltip(_(""));
			txt_214_activity_event[i]->callback(ics_changed);
			txt_214_activity_event[i]->when(FL_WHEN_CHANGED);
		}
		sc2->end();
	g1b->end();

	Fl_Group *g2b = new Fl_Group(569, Y+32, 1, 353);
	g2b->box(FL_FLAT_BOX);
	g2b->end();

	tab_214_3->end();
	tab_214_3->resizable(g2b);

	tab_ics214_type->end();
	Fl_Group::current()->resizable(tab_ics214_type);
	tab_ics214->end();

	tab_ics214->hide();
}
