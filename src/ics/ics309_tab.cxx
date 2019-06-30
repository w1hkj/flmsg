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

Fl_Group	*tab_ics309 = (Fl_Group *)0;
Fl_Tabs		*tab_ics309_type = (Fl_Tabs *)0;
Fl_Group	*tab_309_1 = (Fl_Group *)0;
Fl_Input2	*txt_309_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_309_date_fm = (Fl_Input2 *)0;
Fl_Button	*btn_309_date_fm = (Fl_Button *)0;
Fl_Input2	*txt_309_date_to = (Fl_Input2 *)0;
Fl_Button	*btn_309_date_to = (Fl_Button *)0;
Fl_Input2	*txt_309_time_fm = (Fl_Input2 *)0;
Fl_Button	*btn_309_time_fm = (Fl_Button *)0;
Fl_Input2	*txt_309_time_to = (Fl_Input2 *)0;
Fl_Button	*btn_309_time_to = (Fl_Button *)0;

Fl_Input2	*txt_309_prepared_by = (Fl_Input2 *)0;
Fl_Input2	*txt_309_radio_net = (Fl_Input2 *)0;
Fl_Input2	*txt_309_radio_operator = (Fl_Input2 *)0;
Fl_Input2	*txt_309_preparer_date_time = (Fl_Input2 *)0;
Fl_Button	*btn_309_date_time = (Fl_Button *)0;

Fl_Button	*btn_309_export_csv = (Fl_Button *)0;

Fl_Group	*tab_309_2 = (Fl_Group *)0;
Fl_Input2	*txt_309_comm_time[34] = {(Fl_Input2 *)0};
Fl_Button	*btn_309_comm_time[34] = {(Fl_Button *)0};
Fl_Input2	*txt_309_comm_from[34] = {(Fl_Input2 *)0};
Fl_Input2	*txt_309_comm_to[34]   = {(Fl_Input2 *)0};
Fl_Input2	*txt_309_comm_msg[34]  = {(Fl_Input2 *)0};

int bptr[34] = {\
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \
10,11,12,13,14,15,16,17,18,19, \
20,21,22,23,24,25,26,27,28,29, \
30,31,32,33 };

void cb_309_comm_time_changed(Fl_Widget *w, void *d)
{
	int p = *(int *)d;
	txt_309_comm_time[p]->value(szTime(progStatus.UTC));
	ics_changed(txt_309_comm_time[p], d);
}

void create_ics309_tab()
{
	int Y = tab_top;

	tab_ics309 = new Fl_Group(0, Y, 570, 390);
	tab_ics309->align(FL_ALIGN_TOP);

	tab_ics309_type = new Fl_Tabs(0, Y+2, 570, 387);
	tab_ics309_type->selection_color((Fl_Color)246);

		tab_309_1 = new Fl_Group(0, Y+25, 570, 360, _("Incident"));
			{
			Fl_Group* o = new Fl_Group(2, Y+34, 566, 146);
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

				txt_309_incident = new Fl_Input2(135, Y+40, 425, 24, _("Incident Name"));
				txt_309_incident->tooltip(_("Incident name"));
				txt_309_incident->box(FL_DOWN_BOX);
				txt_309_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_incident->labeltype(FL_NORMAL_LABEL);
				txt_309_incident->labelfont(0);
				txt_309_incident->labelsize(14);
				txt_309_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_incident->align(FL_ALIGN_LEFT);
				txt_309_incident->callback(ics_changed);
				txt_309_incident->when(FL_WHEN_CHANGED);

				txt_309_radio_operator = new Fl_Input2(135, Y+67, 425, 24, _("Radio Operator"));
				txt_309_radio_operator->tooltip(_("Radio Operator, Name / Callsign"));
				txt_309_radio_operator->box(FL_DOWN_BOX);
				txt_309_radio_operator->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_radio_operator->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_radio_operator->labeltype(FL_NORMAL_LABEL);
				txt_309_radio_operator->labelfont(0);
				txt_309_radio_operator->labelsize(14);
				txt_309_radio_operator->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_radio_operator->align(FL_ALIGN_LEFT);
				txt_309_radio_operator->callback(ics_changed);
				txt_309_radio_operator->when(FL_WHEN_CHANGED);

				txt_309_date_fm = new Fl_Input2(135, Y+93, 155, 24, _("From: date"));
				txt_309_date_fm->tooltip(_("Starting date"));
				txt_309_date_fm->box(FL_DOWN_BOX);
				txt_309_date_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_date_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_date_fm->labeltype(FL_NORMAL_LABEL);
				txt_309_date_fm->labelfont(0);
				txt_309_date_fm->labelsize(14);
				txt_309_date_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_date_fm->align(FL_ALIGN_LEFT);
				txt_309_date_fm->callback(ics_changed);
				txt_309_date_fm->when(FL_WHEN_CHANGED);

				btn_309_date_fm = new Fl_Button(292, Y+95, 20, 20, _("..."));
				btn_309_date_fm->tooltip(_("Set today"));
				btn_309_date_fm->callback((Fl_Callback*)cb_309_set_date_fm);

				txt_309_time_fm = new Fl_Input2(358, Y+93, 80, 24, _("time"));
				txt_309_time_fm->tooltip(_("Starting time"));
				txt_309_time_fm->box(FL_DOWN_BOX);
				txt_309_time_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_time_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_time_fm->labeltype(FL_NORMAL_LABEL);
				txt_309_time_fm->labelfont(0);
				txt_309_time_fm->labelsize(14);
				txt_309_time_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_time_fm->align(FL_ALIGN_LEFT);
				txt_309_time_fm->callback(ics_changed);
				txt_309_time_fm->when(FL_WHEN_CHANGED);

				btn_309_time_fm = new Fl_Button(444, Y+95, 20, 20, _("..."));
				btn_309_time_fm->tooltip(_("Set time now"));
				btn_309_time_fm->callback((Fl_Callback*)cb_309_set_time_fm);

				txt_309_date_to = new Fl_Input2(135, Y+119, 155, 24, _("To: date"));
				txt_309_date_to->tooltip(_("Ending date"));
				txt_309_date_to->box(FL_DOWN_BOX);
				txt_309_date_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_date_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_date_to->labeltype(FL_NORMAL_LABEL);
				txt_309_date_to->labelfont(0);
				txt_309_date_to->labelsize(14);
				txt_309_date_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_date_to->align(FL_ALIGN_LEFT);
				txt_309_date_to->callback(ics_changed);
				txt_309_date_to->when(FL_WHEN_CHANGED);

				btn_309_date_to = new Fl_Button(292, Y+121, 20, 20, _("..."));
				btn_309_date_to->tooltip(_("Set today"));
				btn_309_date_to->callback((Fl_Callback*)cb_309_set_date_to);

				txt_309_time_to = new Fl_Input2(358, Y+119, 80, 24, _("time"));
				txt_309_time_to->tooltip(_("Ending time"));
				txt_309_time_to->box(FL_DOWN_BOX);
				txt_309_time_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_time_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_time_to->labeltype(FL_NORMAL_LABEL);
				txt_309_time_to->labelfont(0);
				txt_309_time_to->labelsize(14);
				txt_309_time_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_time_to->align(FL_ALIGN_LEFT);
				txt_309_time_to->callback(ics_changed);
				txt_309_time_to->when(FL_WHEN_CHANGED);

				btn_309_time_to = new Fl_Button(444, Y+121, 20, 20, _("..."));
				btn_309_time_to->tooltip(_("Set time now"));
				btn_309_time_to->callback((Fl_Callback*)cb_309_set_time_to);

				txt_309_radio_net = new Fl_Input2(135, Y+145, 425, 24, _("Net"));
				txt_309_radio_net->tooltip(_("Radio Net Name or Position/Tactical Call"));
				txt_309_radio_net->box(FL_DOWN_BOX);
				txt_309_radio_net->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_radio_net->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_radio_net->labeltype(FL_NORMAL_LABEL);
				txt_309_radio_net->labelfont(0);
				txt_309_radio_net->labelsize(14);
				txt_309_radio_net->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_radio_net->align(FL_ALIGN_LEFT);
				txt_309_radio_net->callback(ics_changed);
				txt_309_radio_net->when(FL_WHEN_CHANGED);

				o->end();
			} // Fl_Group* o

			{
			Fl_Group* o = new Fl_Group(2, Y+220, 566, 62);
				o->box(FL_ENGRAVED_FRAME);

				txt_309_prepared_by = new Fl_Input2(135, Y+226, 425, 24, _("Prepared by"));
				txt_309_prepared_by->tooltip(_("Name of preparer"));
				txt_309_prepared_by->box(FL_DOWN_BOX);
				txt_309_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_prepared_by->labeltype(FL_NORMAL_LABEL);
				txt_309_prepared_by->labelfont(0);
				txt_309_prepared_by->labelsize(14);
				txt_309_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_prepared_by->align(FL_ALIGN_LEFT);
				txt_309_prepared_by->callback(ics_changed);
				txt_309_prepared_by->when(FL_WHEN_CHANGED);

				txt_309_preparer_date_time = new Fl_Input2(135, Y+252, 250, 24, _("Date/Time"));
				txt_309_preparer_date_time->tooltip(_("Date / Time"));
				txt_309_preparer_date_time->box(FL_DOWN_BOX);
				txt_309_preparer_date_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_309_preparer_date_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_309_preparer_date_time->labeltype(FL_NORMAL_LABEL);
				txt_309_preparer_date_time->labelfont(0);
				txt_309_preparer_date_time->labelsize(14);
				txt_309_preparer_date_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_309_preparer_date_time->align(FL_ALIGN_LEFT);
				txt_309_preparer_date_time->callback(ics_changed);
				txt_309_preparer_date_time->when(FL_WHEN_CHANGED);

				btn_309_date_time = new Fl_Button(390, Y+254, 20, 20, _("..."));
				btn_309_date_time->tooltip(_("Set today / now"));
				btn_309_date_time->callback((Fl_Callback*)cb_309_set_date_time);

				o->end();

				btn_309_export_csv = new Fl_Button(450, Y+340, 100, 24, _("Export CSV"));
				btn_309_export_csv->tooltip(_("Export Incident data to a CSV file"));
				btn_309_export_csv->callback((Fl_Callback*)ics309_csv);


			} // Fl_Group* o

		tab_309_1->end();

		tab_309_2 = new Fl_Group(0, Y+25, 570, 360, _("Communications Log"));
		tab_309_2->hide();

		Fl_Group *g1 = new Fl_Group( 0, Y+30, 569, 355);
		g1->box(FL_FLAT_BOX);

			Fl_Box* bx1 = new Fl_Box(5, Y+30, 70, 20, _("Time"));
			bx1->box(FL_DOWN_BOX);
			bx1->color((Fl_Color)215);

			Fl_Box* bx2 = new Fl_Box(bx1->x() + bx1->w(), Y+30, 95, 20, _("From"));
			bx2->box(FL_DOWN_BOX);
			bx2->color((Fl_Color)215);

			Fl_Box* bx3 = new Fl_Box(bx2->x() + bx2->w(), Y+30, 95, 20, _("To"));
			bx3->box(FL_DOWN_BOX);
			bx3->color((Fl_Color)215);

			Fl_Box* bx4 = new Fl_Box(bx3->x() + bx3->w(), Y+30, 284, 20, _("Message"));
			bx4->box(FL_DOWN_BOX);
			bx4->color((Fl_Color)215);

			Fl_Scroll* scrl = new Fl_Scroll(3, Y+52, 566, 334);
				scrl->type(Fl_Scroll::BOTH_ALWAYS);
				scrl->box(FL_DOWN_BOX);

				for (int i = 0; i < 34; i++) {

					txt_309_comm_time[i] = new Fl_Input2(5, Y+52 + i*22, 50, 22);
					txt_309_comm_time[i]->tooltip(_(""));
					txt_309_comm_time[i]->callback(ics_changed);
					txt_309_comm_time[i]->when(FL_WHEN_CHANGED);

					btn_309_comm_time[i] = new Fl_Button(
						txt_309_comm_time[i]->x() + txt_309_comm_time[i]->w(),Y+52 + i*22,
						20, 20, _(".."));
					btn_309_comm_time[i]->tooltip(_("Set time now"));
					btn_309_comm_time[i]->callback(cb_309_comm_time_changed, (void *)&bptr[i]);

					txt_309_comm_from[i] = new Fl_Input2(
						btn_309_comm_time[i]->x() + btn_309_comm_time[i]->w(),Y+52 + i*22,
						95, 22, "");
					txt_309_comm_from[i]->tooltip(_(""));
					txt_309_comm_from[i]->callback(ics_changed);
					txt_309_comm_from[i]->when(FL_WHEN_CHANGED);

					txt_309_comm_to[i] = new Fl_Input2(
						txt_309_comm_from[i]->x() + txt_309_comm_from[i]->w(),Y+52 + i*22,
						95, 22);
					txt_309_comm_to[i]->tooltip(_(""));
					txt_309_comm_to[i]->callback(ics_changed);
					txt_309_comm_to[i]->when(FL_WHEN_CHANGED);

					txt_309_comm_msg[i] = new Fl_Input2(
						txt_309_comm_to[i]->x() + txt_309_comm_to[i]->w(),Y+52 + i*22,
						285, 22);
					txt_309_comm_msg[i]->tooltip(_(""));
					txt_309_comm_msg[i]->callback(ics_changed);
					txt_309_comm_msg[i]->when(FL_WHEN_CHANGED);
				}
				scrl->end();

		g1->end();

		Fl_Group *g2 = new Fl_Group( 569, Y+30, 1, 355);
		g2->box(FL_FLAT_BOX);

		tab_309_2->end();
		tab_309_2->resizable(g2);

	tab_ics309_type->end();
	Fl_Group::current()->resizable(tab_ics309_type);
	tab_ics309->end();

	tab_ics309->hide();
}

