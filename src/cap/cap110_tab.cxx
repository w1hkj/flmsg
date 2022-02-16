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

#include <string>

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

void cap110_changed(Fl_Widget *w, void *)
{
	Fl_Input2 *inp = (Fl_Input2 *)w;
	std::string s = inp->value();
	int len = s.length();
	int maxlen = 1000;
	if (inp == txt_110_mission_nbr) maxlen = 14;
	else if (inp == txt_110_station) maxlen = 48;
	else if (inp == txt_110_ds_a) maxlen = 12;
	else if (inp == txt_110_ds_b) maxlen = 12;
	else if (inp == txt_110_ds_c) maxlen = 12;
	else if (inp == txt_110_ds_d) maxlen = 12;
	else if (inp == txt_110_ds_e) maxlen = 12;
	else if (inp == txt_110_ds_f) maxlen = 12;
	else for (int i = 0; i < 23; i++) {
		if (inp == txt_110_comm_chref[i]) { maxlen = 6; break; }
		if (inp == txt_110_comm_call[i]) { maxlen = 10; break; }
		if (inp == txt_110_comm_time[i]) { maxlen = 8; break; }
		if (inp == txt_110_comm_rem[i]) { maxlen = 53; break; }
	}
	if (len > maxlen) { s.erase(len-1); inp->value(s.c_str()); }
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
	tab_cap110 = new Fl_Group(0, Y, 570, 380);
	tab_cap110->align(FL_ALIGN_TOP);

		Y += 24;
		txt_110_mission_nbr = new Fl_Input2(5, Y, 110, 24, _("Mission #"));
		txt_110_mission_nbr->tooltip(_(""));
		txt_110_mission_nbr->box(FL_DOWN_BOX);
		txt_110_mission_nbr->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_110_mission_nbr->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_110_mission_nbr->labeltype(FL_NORMAL_LABEL);
		txt_110_mission_nbr->labelfont(0);
		txt_110_mission_nbr->labelsize(13);
		txt_110_mission_nbr->textsize(11);
		txt_110_mission_nbr->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_110_mission_nbr->align(FL_ALIGN_TOP_LEFT);
		txt_110_mission_nbr->callback(cap110_changed);
		txt_110_mission_nbr->when(FL_WHEN_CHANGED);

		txt_110_station = new Fl_Input2(117, Y, 350, 24, _("Station Functional Desc."));
		txt_110_station->tooltip(_(""));
		txt_110_station->box(FL_DOWN_BOX);
		txt_110_station->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_110_station->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_110_station->labeltype(FL_NORMAL_LABEL);
		txt_110_station->labelfont(0);
		txt_110_station->labelsize(13);
		txt_110_station->textsize(11);
		txt_110_station->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_110_station->align(FL_ALIGN_TOP_LEFT);
		txt_110_station->callback(cap110_changed);
		txt_110_station->when(FL_WHEN_CHANGED);

		txt_110_date = new Fl_Input2(469, Y, 70, 24, _("Date"));
		txt_110_date->tooltip(_("Report date"));
		txt_110_date->box(FL_DOWN_BOX);
		txt_110_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_110_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_110_date->labeltype(FL_NORMAL_LABEL);
		txt_110_date->labelfont(0);
		txt_110_date->labelsize(13);
		txt_110_date->textsize(11);
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
			desig_src->labelsize(13);

			Y += 34;
			txt_110_ds_a = new Fl_Input2(10, Y, 90, 24, _("A"));
			txt_110_ds_a->tooltip(_("Designator/Source A"));
			txt_110_ds_a->box(FL_DOWN_BOX);
			txt_110_ds_a->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_110_ds_a->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_110_ds_a->labeltype(FL_NORMAL_LABEL);
			txt_110_ds_a->labelfont(0);
			txt_110_ds_a->labelsize(13);
			txt_110_ds_a->textsize(11);
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
			txt_110_ds_b->labelsize(13);
			txt_110_ds_b->textsize(11);
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
			txt_110_ds_c->labelsize(13);
			txt_110_ds_c->textsize(11);
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
			txt_110_ds_d->labelsize(13);
			txt_110_ds_d->textsize(11);
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
			txt_110_ds_e->labelsize(13);
			txt_110_ds_e->textsize(11);
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
			txt_110_ds_f->labelsize(13);
			txt_110_ds_f->textsize(11);
			txt_110_ds_f->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_110_ds_f->align(FL_ALIGN_TOP_LEFT);
			txt_110_ds_f->callback(cap110_changed);
			txt_110_ds_f->when(FL_WHEN_CHANGED);

		desig_src->end();
		}

		Y += 36;
		Fl_Group *g1a = new Fl_Group(2, Y, 566, 260);

		Fl_Box* bx1 = new Fl_Box(2, Y, 85, 20, _("TIME"));
		bx1->box(FL_DOWN_BOX);
		bx1->labelsize(13);
		bx1->color((Fl_Color)215);

		Fl_Box* bx2 = new Fl_Box(bx1->x() + bx1->w(), Y, 75, 20, _("CALL"));
		bx2->box(FL_DOWN_BOX);
		bx2->labelsize(13);
		bx2->color((Fl_Color)215);

		Fl_Box* bx3 = new Fl_Box(bx2->x() + bx2->w(), Y, 50, 20, _("CH REF"));
		bx3->box(FL_DOWN_BOX);
		bx3->labelsize(13);
		bx3->color((Fl_Color)215);

		Fl_Box* bx4 = new Fl_Box(bx3->x() + bx3->w(), Y, 340, 20, _("REMARKS"));
		bx4->box(FL_DOWN_BOX);
		bx4->labelsize(13);
		bx4->color((Fl_Color)215);

		Y += 22;
		Fl_Scroll* scrl = new Fl_Scroll(2, Y, 566, 240);
		scrl->type(Fl_Scroll::VERTICAL_ALWAYS);
			scrl->box(FL_DOWN_BOX);
//			scrl->color((Fl_Color)215);
			for (int i = 0; i < 23; i++) {
				txt_110_comm_time[i] = new Fl_Input2(2, Y + i*22, 65, 22);
				txt_110_comm_time[i]->tooltip(_(""));
				txt_110_comm_time[i]->callback(cap110_changed);
				txt_110_comm_time[i]->when(FL_WHEN_CHANGED);

				btn_110_comm_time[i] = new Fl_Button(
					txt_110_comm_time[i]->x() + txt_110_comm_time[i]->w(), Y + i*22,
					20, 22, _(".."));
				btn_110_comm_time[i]->tooltip(_("Set time now"));
				btn_110_comm_time[i]->callback(
									cb_110_comm_time_changed, (void *)&cap_bptr[i]);


				txt_110_comm_call[i] = new Fl_Input2(
					btn_110_comm_time[i]->x() + btn_110_comm_time[i]->w(), Y + i*22,
					75, 22, "");
				txt_110_comm_call[i]->tooltip(_(""));
				txt_110_comm_call[i]->callback(cap110_changed);
				txt_110_comm_call[i]->when(FL_WHEN_CHANGED);

				txt_110_comm_chref[i] = new Fl_Input2(
					txt_110_comm_call[i]->x() + txt_110_comm_call[i]->w(), Y + i*22,
					50, 22);
				txt_110_comm_chref[i]->tooltip(_(""));
				txt_110_comm_chref[i]->callback(cap110_changed);
				txt_110_comm_chref[i]->when(FL_WHEN_CHANGED);

				txt_110_comm_rem[i] = new Fl_Input2(
					txt_110_comm_chref[i]->x() + txt_110_comm_chref[i]->w(), Y + i*22,
					340, 22);
				txt_110_comm_rem[i]->tooltip(_(""));
				txt_110_comm_rem[i]->callback(cap110_changed);
				txt_110_comm_rem[i]->when(FL_WHEN_CHANGED);
			}
			scrl->end();
		g1a->end();

		Fl_Group *g1b = new Fl_Group(569, Y, 2, 260);
		g1b->box(FL_FLAT_BOX);
		g1b->end();

	tab_cap110->end();
	tab_cap110->resizable(g1b);

	tab_cap110->hide();
}

