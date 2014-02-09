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

Fl_Group	*tab_cap110 = (Fl_Group *)0;
Fl_Tabs		*tab_cap110_type = (Fl_Tabs *)0;

Fl_Input2	*txt_110_mission_nbr = (Fl_Input2 *)0;
Fl_Input2	*txt_110_station = (Fl_Input2 *)0;
Fl_Input2	*txt_110_date = (Fl_Input2 *)0;
Fl_Button	*btn_110_date = (Fl_Button *)0;
Fl_Group	*desig_src = (Fl_Group *)0;
Fl_Input2	*txt_110_ds_a = (Fl_Input2 *)0;
Fl_Input2	*txt_110_ds_b = (Fl_Input2 *)0;
Fl_Input2	*txt_110_ds_c = (Fl_Input2 *)0;
Fl_Input2	*txt_110_ds_d = (Fl_Input2 *)0;
Fl_Input2	*txt_110_ds_e = (Fl_Input2 *)0;
Fl_Input2	*txt_110_ds_f = (Fl_Input2 *)0;

Fl_Input2	*txt_110_comm_time[23] = {(Fl_Input2 *)0};
Fl_Button	*btn_110_comm_time[23] = {(Fl_Button *)0};
Fl_Input2	*txt_110_comm_call[23] = {(Fl_Input2 *)0};
Fl_Input2	*txt_110_comm_chref[23]  = {(Fl_Input2 *)0};
Fl_Input2	*txt_110_comm_rem[23]   = {(Fl_Input2 *)0};

int cap_bptr[23] = {\
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \
10,11,12,13,14,15,16,17,18,19, \
20,21,22 };

void cap110_changed(Fl_Widget *, void *)
{
	estimate();
}

void cb_110_comm_time_changed(Fl_Widget *w, void *d)
{
	int p = *(int *)d;
	txt_110_comm_time[p]->value(szTime(progStatus.UTC) );
	cap110_changed(txt_110_comm_time[p], d);
}

void create_cap110_tab()
{
	int Y = tab_top;
	tab_cap110 = new Fl_Group(0, Y, 570, 404);
	tab_cap110->align(FL_ALIGN_TOP);

		Y += 24;
		txt_110_mission_nbr = new Fl_Input2(5, Y, 80, 24, _("Mission #"));
		txt_110_mission_nbr->tooltip(_(""));
		txt_110_mission_nbr->box(FL_DOWN_BOX);
		txt_110_mission_nbr->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_110_mission_nbr->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_110_mission_nbr->labeltype(FL_NORMAL_LABEL);
		txt_110_mission_nbr->labelfont(0);
		txt_110_mission_nbr->labelsize(14);
		txt_110_mission_nbr->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_110_mission_nbr->align(FL_ALIGN_TOP_LEFT);
		txt_110_mission_nbr->callback(cap110_changed);
		txt_110_mission_nbr->when(FL_WHEN_CHANGED);

		txt_110_station = new Fl_Input2(90, Y, 355, 24, _("Station Functional Desc."));
		txt_110_station->tooltip(_(""));
		txt_110_station->box(FL_DOWN_BOX);
		txt_110_station->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_110_station->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_110_station->labeltype(FL_NORMAL_LABEL);
		txt_110_station->labelfont(0);
		txt_110_station->labelsize(14);
		txt_110_station->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_110_station->align(FL_ALIGN_TOP_LEFT);
		txt_110_station->callback(cap110_changed);
		txt_110_station->when(FL_WHEN_CHANGED);

		txt_110_date = new Fl_Input2(450, Y, 90, 24, _("Date"));
		txt_110_date->tooltip(_("Report date"));
		txt_110_date->box(FL_DOWN_BOX);
		txt_110_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_110_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_110_date->labeltype(FL_NORMAL_LABEL);
		txt_110_date->labelfont(0);
		txt_110_date->labelsize(14);
		txt_110_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_110_date->align(FL_ALIGN_TOP_LEFT);
		txt_110_date->callback(cap110_changed);
		txt_110_date->when(FL_WHEN_CHANGED);

		btn_110_date = new Fl_Button(542, Y, 20, 20, _("..."));
		btn_110_date->tooltip(_("Set today"));
		btn_110_date->callback((Fl_Callback*)cap110_set_date);

		Y += 30;
		desig_src = new Fl_Group(2, Y, 566, 60, _("DESIGNATOR/SOURCE"));
		{
			desig_src->box(FL_FLAT_BOX);
			desig_src->align (FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_TOP);
			desig_src->labelfont(0);
			desig_src->labelsize(14);

			Y += 34;
			txt_110_ds_a = new Fl_Input2(10, Y, 90, 24, _("A"));
			txt_110_ds_a->tooltip(_("Designator/Source A"));
			txt_110_ds_a->box(FL_DOWN_BOX);
			txt_110_ds_a->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_110_ds_a->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_110_ds_a->labeltype(FL_NORMAL_LABEL);
			txt_110_ds_a->labelfont(0);
			txt_110_ds_a->labelsize(14);
			txt_110_ds_a->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_110_ds_a->align(FL_ALIGN_TOP_LEFT);
			txt_110_ds_a->callback(cap110_changed);
			txt_110_ds_a->when(FL_WHEN_CHANGED);

			txt_110_ds_b = new Fl_Input2(102, Y, 90, 24, _("B"));
			txt_110_ds_b->tooltip(_("Designator/Source B"));
			txt_110_ds_b->box(FL_DOWN_BOX);
			txt_110_ds_b->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_110_ds_b->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_110_ds_b->labeltype(FL_NORMAL_LABEL);
			txt_110_ds_b->labelfont(0);
			txt_110_ds_b->labelsize(14);
			txt_110_ds_b->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_110_ds_b->align(FL_ALIGN_TOP_LEFT);
			txt_110_ds_b->callback(cap110_changed);
			txt_110_ds_b->when(FL_WHEN_CHANGED);

			txt_110_ds_c = new Fl_Input2(194, Y, 90, 24, _("C"));
			txt_110_ds_c->tooltip(_("Designator/Source C"));
			txt_110_ds_c->box(FL_DOWN_BOX);
			txt_110_ds_c->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_110_ds_c->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_110_ds_c->labeltype(FL_NORMAL_LABEL);
			txt_110_ds_c->labelfont(0);
			txt_110_ds_c->labelsize(14);
			txt_110_ds_c->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_110_ds_c->align(FL_ALIGN_TOP_LEFT);
			txt_110_ds_c->callback(cap110_changed);
			txt_110_ds_c->when(FL_WHEN_CHANGED);

			txt_110_ds_d = new Fl_Input2(286, Y, 90, 24, _("D"));
			txt_110_ds_d->tooltip(_("Designator/Source D"));
			txt_110_ds_d->box(FL_DOWN_BOX);
			txt_110_ds_d->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_110_ds_d->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_110_ds_d->labeltype(FL_NORMAL_LABEL);
			txt_110_ds_d->labelfont(0);
			txt_110_ds_d->labelsize(14);
			txt_110_ds_d->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_110_ds_d->align(FL_ALIGN_TOP_LEFT);
			txt_110_ds_d->callback(cap110_changed);
			txt_110_ds_d->when(FL_WHEN_CHANGED);

			txt_110_ds_e = new Fl_Input2(378, Y, 90, 24, _("E"));
			txt_110_ds_e->tooltip(_("Designator/Source E"));
			txt_110_ds_e->box(FL_DOWN_BOX);
			txt_110_ds_e->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_110_ds_e->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_110_ds_e->labeltype(FL_NORMAL_LABEL);
			txt_110_ds_e->labelfont(0);
			txt_110_ds_e->labelsize(14);
			txt_110_ds_e->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_110_ds_e->align(FL_ALIGN_TOP_LEFT);
			txt_110_ds_e->callback(cap110_changed);
			txt_110_ds_e->when(FL_WHEN_CHANGED);

			txt_110_ds_f = new Fl_Input2(470, Y, 90, 24, _("F"));
			txt_110_ds_f->tooltip(_("Designator/Source F"));
			txt_110_ds_f->box(FL_DOWN_BOX);
			txt_110_ds_f->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_110_ds_f->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_110_ds_f->labeltype(FL_NORMAL_LABEL);
			txt_110_ds_f->labelfont(0);
			txt_110_ds_f->labelsize(14);
			txt_110_ds_f->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_110_ds_f->align(FL_ALIGN_TOP_LEFT);
			txt_110_ds_f->callback(cap110_changed);
			txt_110_ds_f->when(FL_WHEN_CHANGED);

		desig_src->end();
		}

		Y += 36;
		{
		Fl_Box* o = new Fl_Box(2, Y, 80, 20, _("TIME"));
		o->box(FL_BORDER_FRAME);
		o->color((Fl_Color)215);
		} // Fl_Box* o
		{
		Fl_Box* o = new Fl_Box(82, Y, 80, 20, _("CALL"));
		o->box(FL_BORDER_FRAME);
		o->color((Fl_Color)215);
		} // Fl_Box* o
		{
		Fl_Box* o = new Fl_Box(162, Y, 80, 20, _("CH REF"));
		o->box(FL_BORDER_FRAME);
			o->color((Fl_Color)215);
		} // Fl_Box* o
		{
		Fl_Box* o = new Fl_Box(242, Y, 310, 20, _("REMARKS"));
		o->box(FL_BORDER_FRAME);
			o->color((Fl_Color)215);
		} // Fl_Box* o
		{
		Y += 22;
		Fl_Scroll* o = new Fl_Scroll(2, Y, 566, 240);
		o->type(2);
			o->box(FL_DOWN_BOX);
			o->color((Fl_Color)215);
			for (int i = 0; i < 23; i++) {
				txt_110_comm_time[i] = new Fl_Input2(2, Y + i*22, 60, 22);
				txt_110_comm_time[i]->tooltip(_(""));
				txt_110_comm_time[i]->box(FL_DOWN_BOX);
				txt_110_comm_time[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_110_comm_time[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_110_comm_time[i]->labeltype(FL_NORMAL_LABEL);
				txt_110_comm_time[i]->labelfont(0);
				txt_110_comm_time[i]->labelsize(14);
				txt_110_comm_time[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_110_comm_time[i]->align(FL_ALIGN_CENTER);
				txt_110_comm_time[i]->callback(cap110_changed);
				txt_110_comm_time[i]->when(FL_WHEN_CHANGED);

				btn_110_comm_time[i] = new Fl_Button(62, Y + i*22, 20, 20, _(".."));
				btn_110_comm_time[i]->tooltip(_("Set time now"));
				btn_110_comm_time[i]->callback(
									cb_110_comm_time_changed, (void *)&cap_bptr[i]);


				txt_110_comm_call[i] = new Fl_Input2(82, Y + i*22, 80, 22, "");
				txt_110_comm_call[i]->tooltip(_(""));
				txt_110_comm_call[i]->box(FL_DOWN_BOX);
				txt_110_comm_call[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_110_comm_call[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_110_comm_call[i]->labeltype(FL_NORMAL_LABEL);
				txt_110_comm_call[i]->labelfont(0);
				txt_110_comm_call[i]->labelsize(14);
				txt_110_comm_call[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_110_comm_call[i]->align(FL_ALIGN_CENTER);
				txt_110_comm_call[i]->callback(cap110_changed);
				txt_110_comm_call[i]->when(FL_WHEN_CHANGED);

				txt_110_comm_chref[i] = new Fl_Input2(162, Y + i*22, 80, 22);
				txt_110_comm_chref[i]->tooltip(_(""));
				txt_110_comm_chref[i]->box(FL_DOWN_BOX);
				txt_110_comm_chref[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_110_comm_chref[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_110_comm_chref[i]->labeltype(FL_NORMAL_LABEL);
				txt_110_comm_chref[i]->labelfont(0);
				txt_110_comm_chref[i]->labelsize(14);
				txt_110_comm_chref[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_110_comm_chref[i]->align(FL_ALIGN_CENTER);
				txt_110_comm_chref[i]->callback(cap110_changed);
				txt_110_comm_chref[i]->when(FL_WHEN_CHANGED);

				txt_110_comm_rem[i] = new Fl_Input2(242, Y + i*22, 310, 22);
				txt_110_comm_rem[i]->tooltip(_(""));
				txt_110_comm_rem[i]->box(FL_DOWN_BOX);
				txt_110_comm_rem[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_110_comm_rem[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_110_comm_rem[i]->labeltype(FL_NORMAL_LABEL);
				txt_110_comm_rem[i]->labelfont(0);
				txt_110_comm_rem[i]->labelsize(14);
				txt_110_comm_rem[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_110_comm_rem[i]->align(FL_ALIGN_CENTER);
				txt_110_comm_rem[i]->callback(cap110_changed);
				txt_110_comm_rem[i]->when(FL_WHEN_CHANGED);
			}
			o->end();
		} // Fl_Scroll* o

	tab_cap110->end();
	tab_cap110->hide();
}

