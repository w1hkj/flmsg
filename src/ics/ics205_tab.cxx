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

Fl_Group	*tab_ics205 = (Fl_Group *)0;
Fl_Tabs		*tabs_ics205 = (Fl_Tabs *)0;
Fl_Group	*tab_205_1 = (Fl_Group *)0;
Fl_Group	*tab_205_2 = (Fl_Group *)0;

Fl_Input2	*txt_205_name = (Fl_Input2 *)0;
Fl_Input2	*txt_205_dt_prepared = (Fl_Input2 *)0;
Fl_Button	*btn_205_dt_prepared = (Fl_Button *)0;

Fl_Input2	*txt_205_dt_op_from = (Fl_Input2 *)0;
Fl_Button	*btn_205_dt_op_from = (Fl_Button *)0;

Fl_Input2	*txt_205_dt_op_to = (Fl_Input2 *)0;
Fl_Button	*btn_205_dt_op_to = (Fl_Button *)0;

Fl_Input2	*txt_205_func[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_channel[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_assign[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_rx_freq[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_rx_tone[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_tx_freq[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_tx_tone[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_mode_adm[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_remarks[20]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_preparer = (Fl_Input2 *)0;
Fl_Input2	*txt_205_county = (Fl_Input2 *)0;
Fl_Input2	*txt_205_state = (Fl_Input2 *)0;
Fl_Input2	*txt_205_latitude = (Fl_Input2 *)0;
Fl_Input2	*txt_205_longitude = (Fl_Input2 *)0;

static void cb_btn_205_dt_prepared(Fl_Button*, void*) {
  cb_205_SetDateTime1();
}

static void cb_btn_205_dt_op_from(Fl_Button*, void*) {
  cb_205_SetDateTime2();
}

static void cb_btn_205_dt_op_to(Fl_Button*, void*) {
  cb_205_SetDateTime3();
}


void create_ics205_tab()
{
	int Y = tab_top;
	tab_ics205 = new Fl_Group(0, Y, 570, 390);
	tab_ics205->align(FL_ALIGN_TOP);

	tabs_ics205 = new Fl_Tabs(0, Y+3, 570, 387);
	tabs_ics205->selection_color((Fl_Color)246);

	tab_205_1 = new Fl_Group(0, Y+25, 570, 360, _("Plan"));

	txt_205_name = new Fl_Input2(110, Y+35, 450, 24, _("Incident Name"));
	txt_205_name->tooltip(_(""));
	txt_205_name->box(FL_DOWN_BOX);
	txt_205_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_name->labeltype(FL_NORMAL_LABEL);
	txt_205_name->labelfont(0);
	txt_205_name->labelsize(14);
	txt_205_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_name->align(FL_ALIGN_LEFT);
	txt_205_name->callback(ics_changed);
	txt_205_name->when(FL_WHEN_CHANGED);

	txt_205_dt_prepared = new Fl_Input2(110, Y+67, 155, 24, _("DT/TM Prep\'"));
	txt_205_dt_prepared->tooltip(_("ddhhmm MMM YY of preparation"));
	txt_205_dt_prepared->box(FL_DOWN_BOX);
	txt_205_dt_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_prepared->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_prepared->labelfont(0);
	txt_205_dt_prepared->labelsize(14);
	txt_205_dt_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_prepared->align(FL_ALIGN_LEFT);
	txt_205_dt_prepared->callback(ics_changed);
	txt_205_dt_prepared->when(FL_WHEN_CHANGED);

	btn_205_dt_prepared = new Fl_Button(254, Y+67, 24, 24, _("..."));
	btn_205_dt_prepared->tooltip(_("Set today"));
	btn_205_dt_prepared->callback((Fl_Callback*)cb_btn_205_dt_prepared);

	txt_205_dt_op_from = new Fl_Input2(378, Y+67, 155, 24, _("D/T from\'"));
	txt_205_dt_op_from->tooltip(_("Operational period from: ddhhmm MMM YY"));
	txt_205_dt_op_from->box(FL_DOWN_BOX);
	txt_205_dt_op_from->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_op_from->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_op_from->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_op_from->labelfont(0);
	txt_205_dt_op_from->labelsize(14);
	txt_205_dt_op_from->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_op_from->align(FL_ALIGN_LEFT);
	txt_205_dt_op_from->callback(ics_changed);
	txt_205_dt_op_from->when(FL_WHEN_CHANGED);

	btn_205_dt_op_from = new Fl_Button(536, Y+67, 24, 24, _("..."));
	btn_205_dt_op_from->tooltip(_("Set today"));
	btn_205_dt_op_from->callback((Fl_Callback*)cb_btn_205_dt_op_from);

	txt_205_dt_op_to = new Fl_Input2(378, Y+94, 155, 24, _("D/T to"));
	txt_205_dt_op_to->tooltip(_("Operational period to: ddhhmm MMM YY"));
	txt_205_dt_op_to->box(FL_DOWN_BOX);
	txt_205_dt_op_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_op_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_op_to->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_op_to->labelfont(0);
	txt_205_dt_op_to->labelsize(14);
	txt_205_dt_op_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_op_to->align(FL_ALIGN_LEFT);
	txt_205_dt_op_to->callback(ics_changed);
	txt_205_dt_op_to->when(FL_WHEN_CHANGED);

	btn_205_dt_op_to = new Fl_Button(536, Y+94, 24, 24, _("..."));
	btn_205_dt_op_to->tooltip(_("Set today"));
	btn_205_dt_op_to->callback((Fl_Callback*)cb_btn_205_dt_op_to);

	txt_205_preparer = new Fl_Input2(110, Y+140, 450, 24, _("Prepared by:"));
	txt_205_preparer->tooltip(_("Communications Unit"));
	txt_205_preparer->box(FL_DOWN_BOX);
	txt_205_preparer->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_preparer->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_preparer->labeltype(FL_NORMAL_LABEL);
	txt_205_preparer->labelfont(0);
	txt_205_preparer->labelsize(14);
	txt_205_preparer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_preparer->align(FL_ALIGN_LEFT);
	txt_205_preparer->callback(ics_changed);
	txt_205_preparer->when(FL_WHEN_CHANGED);

	txt_205_county = new Fl_Input2(110, Y+170, 200, 24, _("County:"));
	txt_205_county->tooltip(_("County"));
	txt_205_county->box(FL_DOWN_BOX);
	txt_205_county->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_county->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_county->labeltype(FL_NORMAL_LABEL);
	txt_205_county->labelfont(0);
	txt_205_county->labelsize(14);
	txt_205_county->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_county->align(FL_ALIGN_LEFT);
	txt_205_county->callback(ics_changed);
	txt_205_county->when(FL_WHEN_CHANGED);

	txt_205_state = new Fl_Input2(110, Y+196, 60, 24, _("State:"));
	txt_205_state->tooltip(_("State (abbreviated)"));
	txt_205_state->box(FL_DOWN_BOX);
	txt_205_state->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_state->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_state->labeltype(FL_NORMAL_LABEL);
	txt_205_state->labelfont(0);
	txt_205_state->labelsize(14);
	txt_205_state->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_state->align(FL_ALIGN_LEFT);
	txt_205_state->callback(ics_changed);
	txt_205_state->when(FL_WHEN_CHANGED);

	txt_205_latitude = new Fl_Input2(110, Y+226, 120, 24, _("Latitude:"));
	txt_205_latitude->tooltip(_("decimal degrees, North +"));
	txt_205_latitude->box(FL_DOWN_BOX);
	txt_205_latitude->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_latitude->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_latitude->labeltype(FL_NORMAL_LABEL);
	txt_205_latitude->labelfont(0);
	txt_205_latitude->labelsize(14);
	txt_205_latitude->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_latitude->align(FL_ALIGN_LEFT);
	txt_205_latitude->callback(ics_changed);
	txt_205_latitude->when(FL_WHEN_CHANGED);

	txt_205_longitude = new Fl_Input2(110, Y+252, 120, 24, _("Longitude:"));
	txt_205_longitude->tooltip(_("decimal degrees, West +"));
	txt_205_longitude->box(FL_DOWN_BOX);
	txt_205_longitude->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_longitude->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_longitude->labeltype(FL_NORMAL_LABEL);
	txt_205_longitude->labelfont(0);
	txt_205_longitude->labelsize(14);
	txt_205_longitude->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_longitude->align(FL_ALIGN_LEFT);
	txt_205_longitude->callback(ics_changed);
	txt_205_longitude->when(FL_WHEN_CHANGED);

	tab_205_1->end();

	tab_205_1 = new Fl_Group(0, Y+25, 570, 360, _("Line items"));

	Fl_Scroll* os = new Fl_Scroll(2, Y+30, 566, 356);
	os->type(Fl_Scroll::BOTH_ALWAYS);
	os->box(FL_DOWN_BOX);
	os->color((Fl_Color)215);

	Fl_Box* osbox = new Fl_Box(2, Y+27, 2, 10);
	osbox->box(FL_NO_BOX);

	for (int i = 0; i < 20; i++) {
		txt_205_func[i] = new Fl_Input2(2, Y + 40 + (i+1)*24, 70, 24, 
								i == 0 ? _("Func'"):"");
		txt_205_func[i]->tooltip(_(""));
		txt_205_func[i]->box(FL_DOWN_BOX);
		txt_205_func[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_func[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_func[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_func[i]->labelfont(0);
		txt_205_func[i]->labelsize(14);
		txt_205_func[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_func[i]->align(FL_ALIGN_TOP);
		txt_205_func[i]->callback(ics_changed);
		txt_205_func[i]->when(FL_WHEN_CHANGED);

		txt_205_channel[i] = new Fl_Input2(72, Y + 40 + (i+1)*24, 60, 24,
								i == 0 ? _("Chan'"):"");
		txt_205_channel[i]->tooltip(_(""));
		txt_205_channel[i]->box(FL_DOWN_BOX);
		txt_205_channel[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_channel[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_channel[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_channel[i]->labelfont(0);
		txt_205_channel[i]->labelsize(14);
		txt_205_channel[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_channel[i]->align(FL_ALIGN_TOP);
		txt_205_channel[i]->callback(ics_changed);
		txt_205_channel[i]->when(FL_WHEN_CHANGED);

		txt_205_assign[i] = new Fl_Input2(132, Y + 40 + (i+1)*24, 80, 24,
								i == 0 ?_("Assign'"):"");
		txt_205_assign[i]->tooltip(_(""));
		txt_205_assign[i]->box(FL_DOWN_BOX);
		txt_205_assign[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_assign[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_assign[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_assign[i]->labelfont(0);
		txt_205_assign[i]->labelsize(14);
		txt_205_assign[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_assign[i]->align(FL_ALIGN_TOP);
		txt_205_assign[i]->callback(ics_changed);
		txt_205_assign[i]->when(FL_WHEN_CHANGED);

		txt_205_rx_freq[i] = new Fl_Input2(212, Y + 40 + (i+1)*24, 60, 24,
								i == 0 ? _("Rx\nFreq"):"");
		txt_205_rx_freq[i]->tooltip(_(""));
		txt_205_rx_freq[i]->box(FL_DOWN_BOX);
		txt_205_rx_freq[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_rx_freq[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_rx_freq[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_rx_freq[i]->labelfont(0);
		txt_205_rx_freq[i]->labelsize(14);
		txt_205_rx_freq[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_rx_freq[i]->align(FL_ALIGN_TOP);
		txt_205_rx_freq[i]->callback(ics_changed);
		txt_205_rx_freq[i]->when(FL_WHEN_CHANGED);

		txt_205_rx_tone[i] = new Fl_Input2(272, Y + 40 + (i+1)*24, 40, 24,
								i == 0 ? _("Rx\nTone"):"");
		txt_205_rx_tone[i]->tooltip(_(""));
		txt_205_rx_tone[i]->box(FL_DOWN_BOX);
		txt_205_rx_tone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_rx_tone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_rx_tone[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_rx_tone[i]->labelfont(0);
		txt_205_rx_tone[i]->labelsize(14);
		txt_205_rx_tone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_rx_tone[i]->align(FL_ALIGN_TOP);
		txt_205_rx_tone[i]->callback(ics_changed);
		txt_205_rx_tone[i]->when(FL_WHEN_CHANGED);

		txt_205_tx_freq[i] = new Fl_Input2(312, Y + 40 + (i+1)*24, 60, 24,
								i == 0 ? _("Tx\nFreq"):"");
		txt_205_tx_freq[i]->tooltip(_(""));
		txt_205_tx_freq[i]->box(FL_DOWN_BOX);
		txt_205_tx_freq[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_tx_freq[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_tx_freq[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_tx_freq[i]->labelfont(0);
		txt_205_tx_freq[i]->labelsize(14);
		txt_205_tx_freq[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_tx_freq[i]->align(FL_ALIGN_TOP);
		txt_205_tx_freq[i]->callback(ics_changed);
		txt_205_tx_freq[i]->when(FL_WHEN_CHANGED);

		txt_205_tx_tone[i] = new Fl_Input2(372, Y + 40 + (i+1)*24, 40, 24,
								i == 0 ? _("Tx\nTone"):"");
		txt_205_tx_tone[i]->tooltip(_(""));
		txt_205_tx_tone[i]->box(FL_DOWN_BOX);
		txt_205_tx_tone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_tx_tone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_tx_tone[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_tx_tone[i]->labelfont(0);
		txt_205_tx_tone[i]->labelsize(14);
		txt_205_tx_tone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_tx_tone[i]->align(FL_ALIGN_TOP);
		txt_205_tx_tone[i]->callback(ics_changed);
		txt_205_tx_tone[i]->when(FL_WHEN_CHANGED);

		txt_205_mode_adm[i] = new Fl_Input2(412, Y + 40 + (i+1)*24, 50, 24,
								i == 0 ? _("Mode\nA/D/M"):"");
		txt_205_mode_adm[i]->tooltip(_(""));
		txt_205_mode_adm[i]->box(FL_DOWN_BOX);
		txt_205_mode_adm[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_mode_adm[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_mode_adm[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_mode_adm[i]->labelfont(0);
		txt_205_mode_adm[i]->labelsize(14);
		txt_205_mode_adm[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_mode_adm[i]->align(FL_ALIGN_TOP);
		txt_205_mode_adm[i]->callback(ics_changed);
		txt_205_mode_adm[i]->when(FL_WHEN_CHANGED);

		txt_205_remarks[i] = new Fl_Input2(462, Y + 40 + (i+1)*24, 548, 24,
								i == 0 ? _("Remarks"):"");
		txt_205_remarks[i]->tooltip(_(""));
		txt_205_remarks[i]->box(FL_DOWN_BOX);
		txt_205_remarks[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_remarks[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_remarks[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_remarks[i]->labelfont(0);
		txt_205_remarks[i]->labelsize(14);
		txt_205_remarks[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_remarks[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_remarks[i]->callback(ics_changed);
		txt_205_remarks[i]->when(FL_WHEN_CHANGED);
	}
	os->end();

	tab_205_1->end();

	tabs_ics205->end();
	Fl_Group::current()->resizable(tabs_ics205);

	tab_ics205->end();

	tab_ics205->hide();
}
