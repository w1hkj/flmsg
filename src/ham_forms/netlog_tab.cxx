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

Fl_Group	*tab_netlog = (Fl_Group *)0;
Fl_Tabs		*tab_netlog_type = (Fl_Tabs *)0;
Fl_Group	*tab_netlog_1 = (Fl_Group *)0;
Fl_Input2	*txt_netlog_event = (Fl_Input2 *)0;
Fl_Input2	*txt_netlog_date_fm = (Fl_Input2 *)0;
Fl_Button	*btn_netlog_date_fm = (Fl_Button *)0;
Fl_Input2	*txt_netlog_date_to = (Fl_Input2 *)0;
Fl_Button	*btn_netlog_date_to = (Fl_Button *)0;
Fl_Input2	*txt_netlog_time_fm = (Fl_Input2 *)0;
Fl_Button	*btn_netlog_time_fm = (Fl_Button *)0;
Fl_Input2	*txt_netlog_time_to = (Fl_Input2 *)0;
Fl_Button	*btn_netlog_time_to = (Fl_Button *)0;

Fl_Input2	*txt_netlog_prepared_by = (Fl_Input2 *)0;
Fl_Input2	*txt_netlog_radio_net = (Fl_Input2 *)0;
Fl_Input2	*txt_netlog_radio_operator = (Fl_Input2 *)0;
Fl_Input2	*txt_netlog_preparer_date_time = (Fl_Input2 *)0;
Fl_Button	*btn_netlog_date_time = (Fl_Button *)0;

Fl_Button	*btn_netlog_export_csv = (Fl_Button *)0;

Fl_Group	*tab_netlog_2 = (Fl_Group *)0;
Fl_Input2	*txt_netlog_comm_time[60] = {(Fl_Input2 *)0};
Fl_Button	*btn_netlog_comm_time[60] = {(Fl_Button *)0};
Fl_Input2	*txt_netlog_comm_from[60] = {(Fl_Input2 *)0};
Fl_Input2	*txt_netlog_comm_to[60]   = {(Fl_Input2 *)0};
Fl_Input2	*txt_netlog_comm_msg[60]  = {(Fl_Input2 *)0};

int net_bptr[60] = {\
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \
10,11,12,13,14,15,16,17,18,19, \
20,21,22,23,24,25,26,27,28,29, \
30,31,32,33,34,35,36,37,38,39, \
40,41,42,43,44,45,46,47,48,49, \
50,51,52,53,54,55,56,57,58,59, \
 };

void cb_netlog_comm_time_changed(Fl_Widget *w, void *d)
{
	int p = *(int *)d;
	txt_netlog_comm_time[p]->value(szTime());
	hamform_changed(txt_netlog_comm_time[p], d);
}

void create_netlog_tab()
{
	tab_netlog = new Fl_Group(0, tab_top, 570, 380);
	tab_netlog->align(FL_ALIGN_TOP);

	tab_netlog_type = new Fl_Tabs(0, tab_top, 570, 380);
	tab_netlog_type->selection_color((Fl_Color)246);

		tab_netlog_1 = new Fl_Group(0, tab_top+25, 570, 360, _("Event"));
			{
			Fl_Group* o = new Fl_Group(2, tab_top+34, 566, 146);
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

				txt_netlog_event = new Fl_Input2(135, tab_top+40, 425, 24, _("Event Name"));
				txt_netlog_event->tooltip(_("Event name"));
				txt_netlog_event->box(FL_DOWN_BOX);
				txt_netlog_event->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_event->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_event->labeltype(FL_NORMAL_LABEL);
				txt_netlog_event->labelfont(0);
				txt_netlog_event->labelsize(14);
				txt_netlog_event->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_event->align(FL_ALIGN_LEFT);
				txt_netlog_event->callback(hamform_changed);
				txt_netlog_event->when(FL_WHEN_CHANGED);

				txt_netlog_radio_operator = new Fl_Input2(135, tab_top+67, 425, 24, _("Radio Operator"));
				txt_netlog_radio_operator->tooltip(_("Radio Operator, Name / Callsign"));
				txt_netlog_radio_operator->box(FL_DOWN_BOX);
				txt_netlog_radio_operator->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_radio_operator->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_radio_operator->labeltype(FL_NORMAL_LABEL);
				txt_netlog_radio_operator->labelfont(0);
				txt_netlog_radio_operator->labelsize(14);
				txt_netlog_radio_operator->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_radio_operator->align(FL_ALIGN_LEFT);
				txt_netlog_radio_operator->callback(hamform_changed);
				txt_netlog_radio_operator->when(FL_WHEN_CHANGED);

				txt_netlog_date_fm = new Fl_Input2(135, tab_top+93, 155, 24, _("From: date"));
				txt_netlog_date_fm->tooltip(_("Starting date"));
				txt_netlog_date_fm->box(FL_DOWN_BOX);
				txt_netlog_date_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_date_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_date_fm->labeltype(FL_NORMAL_LABEL);
				txt_netlog_date_fm->labelfont(0);
				txt_netlog_date_fm->labelsize(14);
				txt_netlog_date_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_date_fm->align(FL_ALIGN_LEFT);
				txt_netlog_date_fm->callback(hamform_changed);
				txt_netlog_date_fm->when(FL_WHEN_CHANGED);

				btn_netlog_date_fm = new Fl_Button(292, tab_top+95, 20, 20, _("..."));
				btn_netlog_date_fm->tooltip(_("Set today"));
				btn_netlog_date_fm->callback((Fl_Callback*)cb_netlog_set_date_fm);

				txt_netlog_time_fm = new Fl_Input2(358, tab_top+93, 80, 24, _("time"));
				txt_netlog_time_fm->tooltip(_("Starting time"));
				txt_netlog_time_fm->box(FL_DOWN_BOX);
				txt_netlog_time_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_time_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_time_fm->labeltype(FL_NORMAL_LABEL);
				txt_netlog_time_fm->labelfont(0);
				txt_netlog_time_fm->labelsize(14);
				txt_netlog_time_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_time_fm->align(FL_ALIGN_LEFT);
				txt_netlog_time_fm->callback(hamform_changed);
				txt_netlog_time_fm->when(FL_WHEN_CHANGED);

				btn_netlog_time_fm = new Fl_Button(444, tab_top+95, 20, 20, _("..."));
				btn_netlog_time_fm->tooltip(_("Set time now"));
				btn_netlog_time_fm->callback((Fl_Callback*)cb_netlog_set_time_fm);

				txt_netlog_date_to = new Fl_Input2(135, tab_top+119, 155, 24, _("To: date"));
				txt_netlog_date_to->tooltip(_("Ending date"));
				txt_netlog_date_to->box(FL_DOWN_BOX);
				txt_netlog_date_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_date_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_date_to->labeltype(FL_NORMAL_LABEL);
				txt_netlog_date_to->labelfont(0);
				txt_netlog_date_to->labelsize(14);
				txt_netlog_date_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_date_to->align(FL_ALIGN_LEFT);
				txt_netlog_date_to->callback(hamform_changed);
				txt_netlog_date_to->when(FL_WHEN_CHANGED);

				btn_netlog_date_to = new Fl_Button(292, tab_top+121, 20, 20, _("..."));
				btn_netlog_date_to->tooltip(_("Set today"));
				btn_netlog_date_to->callback((Fl_Callback*)cb_netlog_set_date_to);

				txt_netlog_time_to = new Fl_Input2(358, tab_top+119, 80, 24, _("time"));
				txt_netlog_time_to->tooltip(_("Ending time"));
				txt_netlog_time_to->box(FL_DOWN_BOX);
				txt_netlog_time_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_time_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_time_to->labeltype(FL_NORMAL_LABEL);
				txt_netlog_time_to->labelfont(0);
				txt_netlog_time_to->labelsize(14);
				txt_netlog_time_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_time_to->align(FL_ALIGN_LEFT);
				txt_netlog_time_to->callback(hamform_changed);
				txt_netlog_time_to->when(FL_WHEN_CHANGED);

				btn_netlog_time_to = new Fl_Button(444, tab_top+121, 20, 20, _("..."));
				btn_netlog_time_to->tooltip(_("Set time now"));
				btn_netlog_time_to->callback((Fl_Callback*)cb_netlog_set_time_to);

				txt_netlog_radio_net = new Fl_Input2(135, tab_top+145, 425, 24, _("Net"));
				txt_netlog_radio_net->tooltip(_("Radio Net Name or Position/Tactical Call"));
				txt_netlog_radio_net->box(FL_DOWN_BOX);
				txt_netlog_radio_net->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_radio_net->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_radio_net->labeltype(FL_NORMAL_LABEL);
				txt_netlog_radio_net->labelfont(0);
				txt_netlog_radio_net->labelsize(14);
				txt_netlog_radio_net->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_radio_net->align(FL_ALIGN_LEFT);
				txt_netlog_radio_net->callback(hamform_changed);
				txt_netlog_radio_net->when(FL_WHEN_CHANGED);

				o->end();
			} // Fl_Group* o

			{
			Fl_Group* o = new Fl_Group(2, tab_top+220, 566, 62);
				o->box(FL_ENGRAVED_FRAME);

				txt_netlog_prepared_by = new Fl_Input2(135, tab_top+226, 425, 24, _("Prepared by"));
				txt_netlog_prepared_by->tooltip(_("Name of preparer"));
				txt_netlog_prepared_by->box(FL_DOWN_BOX);
				txt_netlog_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_prepared_by->labeltype(FL_NORMAL_LABEL);
				txt_netlog_prepared_by->labelfont(0);
				txt_netlog_prepared_by->labelsize(14);
				txt_netlog_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_prepared_by->align(FL_ALIGN_LEFT);
				txt_netlog_prepared_by->callback(hamform_changed);
				txt_netlog_prepared_by->when(FL_WHEN_CHANGED);

				txt_netlog_preparer_date_time = new Fl_Input2(135, tab_top+252, 250, 24, _("Date/Time"));
				txt_netlog_preparer_date_time->tooltip(_("Date / Time"));
				txt_netlog_preparer_date_time->box(FL_DOWN_BOX);
				txt_netlog_preparer_date_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_netlog_preparer_date_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_netlog_preparer_date_time->labeltype(FL_NORMAL_LABEL);
				txt_netlog_preparer_date_time->labelfont(0);
				txt_netlog_preparer_date_time->labelsize(14);
				txt_netlog_preparer_date_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_netlog_preparer_date_time->align(FL_ALIGN_LEFT);
				txt_netlog_preparer_date_time->callback(hamform_changed);
				txt_netlog_preparer_date_time->when(FL_WHEN_CHANGED);

				btn_netlog_date_time = new Fl_Button(390, tab_top+254, 20, 20, _("..."));
				btn_netlog_date_time->tooltip(_("Set today / now"));
				btn_netlog_date_time->callback((Fl_Callback*)cb_netlog_set_date_time);

				o->end();

				btn_netlog_export_csv = new Fl_Button(450, tab_top+340, 100, 24, _("Export CSV"));
				btn_netlog_export_csv->tooltip(_("Export Event data to a CSV file"));
				btn_netlog_export_csv->callback((Fl_Callback*)netlog_csv);


			} // Fl_Group* o

		tab_netlog_1->end();

		tab_netlog_2 = new Fl_Group(0, tab_top+25, 570, 360, _("Communications Log"));
		tab_netlog_2->hide();

		Fl_Group *g2a = new Fl_Group(0, tab_top+30, 569, 355);

			Fl_Box* bx1 = new Fl_Box(7, tab_top+30, 70, 20, _("Time"));
			bx1->box(FL_DOWN_BOX);
			bx1->color((Fl_Color)215);

			Fl_Box* bx2 = new Fl_Box(bx1->x()+bx1->w(), tab_top+30, 95, 20, _("From"));
			bx2->box(FL_DOWN_BOX);
			bx2->color((Fl_Color)215);

			Fl_Box* bx3 = new Fl_Box(bx2->x()+bx2->w(), tab_top+30, 95, 20, _("To"));
			bx3->box(FL_DOWN_BOX);
			bx3->color((Fl_Color)215);

			Fl_Box* bx4 = new Fl_Box(bx3->x()+bx3->w(), tab_top+30, 280, 20, _("Message"));
			bx4->box(FL_DOWN_BOX);
			bx4->color((Fl_Color)215);

			Fl_Scroll* scrl = new Fl_Scroll(5, tab_top+52, 560, 320);
				scrl->type(Fl_Scroll::VERTICAL_ALWAYS);
				scrl->box(FL_DOWN_BOX);
				for (int i = 0; i < 60; i++) {

					txt_netlog_comm_time[i] = new Fl_Input2(7, tab_top+52 + i*22, 50, 22);
					txt_netlog_comm_time[i]->tooltip(_(""));
					txt_netlog_comm_time[i]->callback(hamform_changed);
					txt_netlog_comm_time[i]->when(FL_WHEN_CHANGED);

					btn_netlog_comm_time[i] = new Fl_Button(
						txt_netlog_comm_time[i]->x() + txt_netlog_comm_time[i]->w(), tab_top+52 + i*22, 20, 22, _(".."));
					btn_netlog_comm_time[i]->tooltip(_("Set time now"));
					btn_netlog_comm_time[i]->callback(cb_netlog_comm_time_changed, (void *)&net_bptr[i]);

					txt_netlog_comm_from[i] = new Fl_Input2(
						btn_netlog_comm_time[i]->x() + btn_netlog_comm_time[i]->w(), tab_top+52 + i*22, 95, 22, "");
					txt_netlog_comm_from[i]->tooltip(_(""));
					txt_netlog_comm_from[i]->callback(hamform_changed);
					txt_netlog_comm_from[i]->when(FL_WHEN_CHANGED);

					txt_netlog_comm_to[i] = new Fl_Input2(
						txt_netlog_comm_from[i]->x() + txt_netlog_comm_from[i]->w(), tab_top+52 + i*22, 95, 22);
					txt_netlog_comm_to[i]->tooltip(_(""));
					txt_netlog_comm_to[i]->callback(hamform_changed);
					txt_netlog_comm_to[i]->when(FL_WHEN_CHANGED);

					txt_netlog_comm_msg[i] = new Fl_Input2(
						txt_netlog_comm_to[i]->x() + txt_netlog_comm_to[i]->w(), tab_top+52 + i*22, 280, 22);
					txt_netlog_comm_msg[i]->tooltip(_(""));
					txt_netlog_comm_msg[i]->callback(hamform_changed);
					txt_netlog_comm_msg[i]->when(FL_WHEN_CHANGED);
				}
			scrl->end();
		g2a->end();
		Fl_Group *g2b = new Fl_Group(569, tab_top+30, 1, 355);
		g2b->end();
		tab_netlog_2->end();
		tab_netlog_2->resizable(g2b);

	tab_netlog_type->end();
	Fl_Group::current()->resizable(tab_netlog_type);
	tab_netlog->end();

	tab_netlog->hide();
}

