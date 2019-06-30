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

Fl_Group	*tab_ics205a = (Fl_Group *)0;
Fl_Tabs		*tab_ics205a_type = (Fl_Tabs *)0;
Fl_Group	*tab_205a_1 = (Fl_Group *)0;
Fl_Input2	*txt_205a_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_205a_date_fm = (Fl_Input2 *)0;
Fl_Button	*btn_205a_date_fm = (Fl_Button *)0;
Fl_Input2	*txt_205a_date_to = (Fl_Input2 *)0;
Fl_Button	*btn_205a_date_to = (Fl_Button *)0;
Fl_Input2	*txt_205a_time_fm = (Fl_Input2 *)0;
Fl_Button	*btn_205a_time_fm = (Fl_Button *)0;
Fl_Input2	*txt_205a_time_to = (Fl_Input2 *)0;
Fl_Button	*btn_205a_time_to = (Fl_Button *)0;

Fl_Input2	*txt_205a_prepared_by = (Fl_Input2 *)0;
Fl_Input2	*txt_205a_preparer_position = (Fl_Input2 *)0;
Fl_Input2	*txt_205a_preparer_date_time = (Fl_Input2 *)0;

Fl_Group	*tab_205a_2 = (Fl_Group *)0;
Fl_Input2	*txt_205a_comm_group[32] = {(Fl_Input2 *)0};
Fl_Input2	*txt_205a_comm_position[32] = {(Fl_Input2 *)0};
Fl_Input2	*txt_205a_comm_name[32] = {(Fl_Input2 *)0};
Fl_Input2	*txt_205a_comm_info[32] = {(Fl_Input2 *)0};

void create_ics205a_tab()
{
	int Y = tab_top;

	tab_ics205a = new Fl_Group(0, Y, 570, 390);
	tab_ics205a->align(FL_ALIGN_TOP);

	tab_ics205a_type = new Fl_Tabs(0, Y+2, 570, 387);
	tab_ics205a_type->selection_color((Fl_Color)246);

		tab_205a_1 = new Fl_Group(0, Y+25, 570, 360, _("Incident"));
			{
			Fl_Group* o = new Fl_Group(2, Y+32, 566, 135);
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

				txt_205a_incident = new Fl_Input2(135, Y+38, 425, 24, _("Incident Name"));
				txt_205a_incident->tooltip(_("Incident name"));
				txt_205a_incident->box(FL_DOWN_BOX);
				txt_205a_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_incident->labeltype(FL_NORMAL_LABEL);
				txt_205a_incident->labelfont(0);
				txt_205a_incident->labelsize(14);
				txt_205a_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_incident->align(FL_ALIGN_LEFT);
				txt_205a_incident->callback(ics_changed);
				txt_205a_incident->when(FL_WHEN_CHANGED);

				txt_205a_date_fm = new Fl_Input2(135, Y+65, 155, 24, _("From date"));
				txt_205a_date_fm->tooltip(_("Starting date"));
				txt_205a_date_fm->box(FL_DOWN_BOX);
				txt_205a_date_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_date_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_date_fm->labeltype(FL_NORMAL_LABEL);
				txt_205a_date_fm->labelfont(0);
				txt_205a_date_fm->labelsize(14);
				txt_205a_date_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_date_fm->align(FL_ALIGN_LEFT);
				txt_205a_date_fm->callback(ics_changed);
				txt_205a_date_fm->when(FL_WHEN_CHANGED);

				btn_205a_date_fm = new Fl_Button(294, Y+67, 20, 20, _("..."));
				btn_205a_date_fm->tooltip(_("Set today"));
				btn_205a_date_fm->callback((Fl_Callback*)cb_205a_set_date_fm);

				txt_205a_time_fm = new Fl_Input2(135, Y+90, 103, 24, _("From time"));
				txt_205a_time_fm->tooltip(_("Starting time"));
				txt_205a_time_fm->box(FL_DOWN_BOX);
				txt_205a_time_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_time_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_time_fm->labeltype(FL_NORMAL_LABEL);
				txt_205a_time_fm->labelfont(0);
				txt_205a_time_fm->labelsize(14);
				txt_205a_time_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_time_fm->align(FL_ALIGN_LEFT);
				txt_205a_time_fm->callback(ics_changed);
				txt_205a_time_fm->when(FL_WHEN_CHANGED);

				btn_205a_time_fm = new Fl_Button(247, Y+92, 20, 20, _("..."));
				btn_205a_time_fm->tooltip(_("Set time now"));
				btn_205a_time_fm->callback((Fl_Callback*)cb_205a_set_time_fm);

				txt_205a_date_to = new Fl_Input2(135, Y+115, 155, 24, _("To date"));
				txt_205a_date_to->tooltip(_("Ending date"));
				txt_205a_date_to->box(FL_DOWN_BOX);
				txt_205a_date_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_date_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_date_to->labeltype(FL_NORMAL_LABEL);
				txt_205a_date_to->labelfont(0);
				txt_205a_date_to->labelsize(14);
				txt_205a_date_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_date_to->align(FL_ALIGN_LEFT);
				txt_205a_date_to->callback(ics_changed);
				txt_205a_date_to->when(FL_WHEN_CHANGED);

				btn_205a_date_to = new Fl_Button(294, Y+117, 20, 20, _("..."));
				btn_205a_date_to->tooltip(_("Set today"));
				btn_205a_date_to->callback((Fl_Callback*)cb_205a_set_date_to);

				txt_205a_time_to = new Fl_Input2(135, Y+140, 103, 24, _("To time"));
				txt_205a_time_to->tooltip(_("Ending time"));
				txt_205a_time_to->box(FL_DOWN_BOX);
				txt_205a_time_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_time_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_time_to->labeltype(FL_NORMAL_LABEL);
				txt_205a_time_to->labelfont(0);
				txt_205a_time_to->labelsize(14);
				txt_205a_time_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_time_to->align(FL_ALIGN_LEFT);
				txt_205a_time_to->callback(ics_changed);
				txt_205a_time_to->when(FL_WHEN_CHANGED);

				btn_205a_time_to = new Fl_Button(247, Y+142, 20, 20, _("..."));
				btn_205a_time_to->tooltip(_("Set time now"));
				btn_205a_time_to->callback((Fl_Callback*)cb_205a_set_time_to);

				o->end();
			} // Fl_Group* o

			{
			Fl_Group* o = new Fl_Group(2, Y+167, 566, 80);
				o->box(FL_ENGRAVED_FRAME);

				txt_205a_prepared_by = new Fl_Input2(135, Y+170, 425, 24, _("Prepared by"));
				txt_205a_prepared_by->tooltip(_("Name of preparer"));
				txt_205a_prepared_by->box(FL_DOWN_BOX);
				txt_205a_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_prepared_by->labeltype(FL_NORMAL_LABEL);
				txt_205a_prepared_by->labelfont(0);
				txt_205a_prepared_by->labelsize(14);
				txt_205a_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_prepared_by->align(FL_ALIGN_LEFT);
				txt_205a_prepared_by->callback(ics_changed);
				txt_205a_prepared_by->when(FL_WHEN_CHANGED);

				txt_205a_preparer_position = new Fl_Input2(135, Y+195, 425, 24, _("Position"));
				txt_205a_preparer_position->tooltip(_("Preparer's Position"));
				txt_205a_preparer_position->box(FL_DOWN_BOX);
				txt_205a_preparer_position->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_preparer_position->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_preparer_position->labeltype(FL_NORMAL_LABEL);
				txt_205a_preparer_position->labelfont(0);
				txt_205a_preparer_position->labelsize(14);
				txt_205a_preparer_position->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_preparer_position->align(FL_ALIGN_LEFT);
				txt_205a_preparer_position->callback(ics_changed);
				txt_205a_preparer_position->when(FL_WHEN_CHANGED);

				txt_205a_preparer_date_time = new Fl_Input2(135, Y+220, 425, 24, _("Date/Time"));
				txt_205a_preparer_date_time->tooltip(_("Date / Time"));
				txt_205a_preparer_date_time->box(FL_DOWN_BOX);
				txt_205a_preparer_date_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_preparer_date_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_preparer_date_time->labeltype(FL_NORMAL_LABEL);
				txt_205a_preparer_date_time->labelfont(0);
				txt_205a_preparer_date_time->labelsize(14);
				txt_205a_preparer_date_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_preparer_date_time->align(FL_ALIGN_LEFT);
				txt_205a_preparer_date_time->callback(ics_changed);
				txt_205a_preparer_date_time->when(FL_WHEN_CHANGED);

				o->end();
			} // Fl_Group* o

		tab_205a_1->end();

		tab_205a_2 = new Fl_Group(0, Y+25, 570, 360, _("Basic Info"));
		tab_205a_2->hide();

		Fl_Group *g1 = new Fl_Group(5, Y+28, 560, 340);
		g1->box(FL_FLAT_BOX);

			Fl_Box* bx1 = new Fl_Box(5, Y+28, 120, 20, _("Assignment"));
			bx1->box(FL_DOWN_BOX);
			bx1->color((Fl_Color)215);

			Fl_Box* bx2 = new Fl_Box(bx1->x() + bx1->w(), Y+28, 150, 20, _("Name"));
			bx2->box(FL_DOWN_BOX);
			bx2->color((Fl_Color)215);

			Fl_Box* bx3 = new Fl_Box(bx2->x() + bx2->w(), Y+28, 270, 20, _("Method of Contact"));
			bx3->box(FL_DOWN_BOX);
			bx3->color((Fl_Color)215);

			Fl_Scroll* sc = new Fl_Scroll(4, Y+48, 560, 320);
				sc->type(2);
				sc->box(FL_DOWN_BOX);
				sc->color((Fl_Color)215);
				for (int i = 0; i < 32; i++) {

					txt_205a_comm_position[i] = new Fl_Input2(5, Y+50 + i*24, 120, 24);
					txt_205a_comm_position[i]->tooltip(_(""));
					txt_205a_comm_position[i]->box(FL_DOWN_BOX);
					txt_205a_comm_position[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_205a_comm_position[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_205a_comm_position[i]->labeltype(FL_NORMAL_LABEL);
					txt_205a_comm_position[i]->labelfont(0);
					txt_205a_comm_position[i]->labelsize(14);
					txt_205a_comm_position[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_205a_comm_position[i]->align(FL_ALIGN_CENTER);
					txt_205a_comm_position[i]->callback(ics_changed);
					txt_205a_comm_position[i]->when(FL_WHEN_CHANGED);
					
					txt_205a_comm_name[i] = new Fl_Input2(126, Y+50 + i*24, 150, 24);
					txt_205a_comm_name[i]->tooltip(_(""));
					txt_205a_comm_name[i]->box(FL_DOWN_BOX);
					txt_205a_comm_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_205a_comm_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_205a_comm_name[i]->labeltype(FL_NORMAL_LABEL);
					txt_205a_comm_name[i]->labelfont(0);
					txt_205a_comm_name[i]->labelsize(14);
					txt_205a_comm_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_205a_comm_name[i]->align(FL_ALIGN_CENTER);
					txt_205a_comm_name[i]->callback(ics_changed);
					txt_205a_comm_name[i]->when(FL_WHEN_CHANGED);

					txt_205a_comm_info[i] = new Fl_Input2(277, Y+50 + i*24, 270, 24);
					txt_205a_comm_info[i]->tooltip(_(""));
					txt_205a_comm_info[i]->box(FL_DOWN_BOX);
					txt_205a_comm_info[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_205a_comm_info[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_205a_comm_info[i]->labeltype(FL_NORMAL_LABEL);
					txt_205a_comm_info[i]->labelfont(0);
					txt_205a_comm_info[i]->labelsize(14);
					txt_205a_comm_info[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_205a_comm_info[i]->align(FL_ALIGN_CENTER);
					txt_205a_comm_info[i]->callback(ics_changed);
					txt_205a_comm_info[i]->when(FL_WHEN_CHANGED);
				}
			sc->end();
		g1->end();
		Fl_Group *g2 = new Fl_Group(565, Y+32, 1, 350);
		g2->box(FL_FLAT_BOX);
		g2->end();

		tab_205a_2->end();
		tab_205a_2->resizable(g2);

	tab_ics205a_type->end();
	Fl_Group::current()->resizable(tab_ics205a_type);
	tab_ics205a->end();

	tab_ics205a->hide();
}
