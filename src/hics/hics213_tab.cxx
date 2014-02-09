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

Fl_Group		*h213_tab = (Fl_Group *)0;
Fl_Tabs			*h213_tab_type = (Fl_Tabs *)0;

Fl_Group		*tab_213_grp_orig = (Fl_Group *)0;
Fl_Group		*tab_213_grp_msg = (Fl_Group *)0;
Fl_Group		*tab_213_grp_action = (Fl_Group *)0;
Fl_Group		*tab_213_grp_receipt1 = (Fl_Group *)0;
Fl_Group		*tab_213_grp_receipt2 = (Fl_Group *)0;

Fl_Input2		*h213_txt_to = (Fl_Input2 *)0;
Fl_Input2		*h213_txt_fm = (Fl_Input2 *)0;
Fl_DateInput	*h213_txt_date = (Fl_DateInput *)0;
Fl_Button		*h213_btn_date = (Fl_Button *)0;
Fl_Input2		*h213_txt_time = (Fl_Input2 *)0;
Fl_Button		*h213_btn_time0 = (Fl_Button *)0;
Fl_Check_Button	*h213_btn_phone = (Fl_Check_Button	*)0;
Fl_Check_Button	*h213_btn_radio = (Fl_Check_Button	*)0;
Fl_Check_Button	*h213_btn_other = (Fl_Check_Button	*)0;
Fl_Check_Button	*h213_btn_yes = (Fl_Check_Button	*)0;
Fl_Check_Button	*h213_btn_no = (Fl_Check_Button	*)0;
Fl_Check_Button	*h213_btn_high = (Fl_Check_Button	*)0;
Fl_Check_Button	*h213_btn_medium = (Fl_Check_Button	*)0;
Fl_Check_Button	*h213_btn_low = (Fl_Check_Button	*)0;
Fl_Input2		*h213_txt_reply_to = (Fl_Input2 *)0;
FTextEdit		*h213_txt_msg = (FTextEdit *)0;
FTextEdit		*h213_txt_action = (FTextEdit *)0;
Fl_Input2		*h213_txt_rcvd_by = (Fl_Input2 *)0;
Fl_Input2		*h213_txt_time_rcvd = (Fl_Input2 *)0;
Fl_Button		*h213_btn_time1 = (Fl_Button *)0;
Fl_Input2		*h213_txt_fwd_to = (Fl_Input2 *)0;
FTextEdit		*h213_txt_comments = (FTextEdit *)0;
Fl_Input2		*h213_txt_rcvd_by2 = (Fl_Input2 *)0;
Fl_Input2		*h213_txt_time_rcvd2 = (Fl_Input2 *)0;
Fl_Button		*h213_btn_time2 = (Fl_Button *)0;
Fl_Input2		*h213_txt_fwd_to2 = (Fl_Input2 *)0;
FTextEdit		*h213_txt_comments2 = (FTextEdit *)0;
Fl_Input2		*h213_txt_facility = (Fl_Input2 *)0;

static void h213_cb_btn_date(Fl_Button*, void*) {
  h213_cb_set_date();
}

static void h213_cb_btn_time0(Fl_Button*, void*) {
  h213_cb_set_time0();
}

static void h213_cb_btn_time1(Fl_Button*, void*) {
  h213_cb_set_time1();
}

static void h213_cb_btn_time2(Fl_Button*, void*) {
  h213_cb_set_time2();
}

static void h213_cb_btn_via(Fl_Button *b, void*) {
Fl_Check_Button *btn = (Fl_Check_Button *)b;
	if (btn == h213_btn_other && btn->value()) {
		h213_btn_radio->value(0);
		h213_btn_phone->value(0);
	} else if (btn == h213_btn_radio && btn->value()) {
		h213_btn_phone->value(0);
		h213_btn_other->value(0);
	} else if (btn == h213_btn_phone && btn->value()){
		h213_btn_radio->value(0);
		h213_btn_other->value(0);
	}
}

static void h213_cb_btn_yes_no(Fl_Button *b, void*) {
Fl_Check_Button *btn = (Fl_Check_Button *)b;
	if (btn == h213_btn_yes && btn->value())
		h213_btn_no->value(0);
	else if (btn == h213_btn_no && btn->value())
		h213_btn_yes->value(0);
}

static void h213_cb_btn_priority(Fl_Button *b, void*) {
Fl_Check_Button *btn = (Fl_Check_Button *)b;
	if (btn == h213_btn_low && btn->value()) {
		h213_btn_high->value(0);
		h213_btn_medium->value(0);
	} else if (btn == h213_btn_medium && btn->value()) {
		h213_btn_high->value(0);
		h213_btn_low->value(0);
	} else if (btn == h213_btn_high && btn->value()) {
		h213_btn_medium->value(0);
		h213_btn_low->value(0);
	}
}

void create_hics213_tab()
{
	int Y = tab_top;
	h213_tab = new Fl_Group(0, Y, 570, 390);
	h213_tab->align(FL_ALIGN_TOP);

	h213_tab_type = new Fl_Tabs(0, Y, 570, 387);
	h213_tab_type->selection_color((Fl_Color)246);

	tab_213_grp_orig = new Fl_Group(0, Y+25, 570, 360, _("Originator"));
	{
		h213_txt_fm = new Fl_Input2(80, Y+40, 480, 24, _("From"));
		h213_txt_fm->tooltip(_("originator"));
		h213_txt_fm->box(FL_DOWN_BOX);
		h213_txt_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_fm->labeltype(FL_NORMAL_LABEL);
		h213_txt_fm->labelfont(0);
		h213_txt_fm->labelsize(14);
		h213_txt_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_fm->align(FL_ALIGN_LEFT);
		h213_txt_fm->callback(hics_changed);
		h213_txt_fm->when(FL_WHEN_CHANGED);

		h213_txt_to = new Fl_Input2(80, Y+66, 480, 24, _("To"));
		h213_txt_to->tooltip(_("Addressee"));
		h213_txt_to->box(FL_DOWN_BOX);
		h213_txt_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_to->labeltype(FL_NORMAL_LABEL);
		h213_txt_to->labelfont(0);
		h213_txt_to->labelsize(14);
		h213_txt_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_to->align(FL_ALIGN_LEFT);
		h213_txt_to->callback(hics_changed);
		h213_txt_to->when(FL_WHEN_CHANGED);

		h213_txt_date = new Fl_DateInput(80, Y+92, 125, 24, _("Date"));
		h213_txt_date->tooltip(_("Date of origination"));
		h213_txt_date->box(FL_DOWN_BOX);
		h213_txt_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_date->labeltype(FL_NORMAL_LABEL);
		h213_txt_date->labelfont(0);
		h213_txt_date->labelsize(14);
		h213_txt_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_date->align(FL_ALIGN_LEFT);
		h213_txt_date->when(FL_WHEN_CHANGED);
		h213_txt_date->callback(hics_changed);
		h213_txt_date->local_datetime(progStatus.UTC > 1);
		h213_txt_date->format(2);

		h213_btn_date = new Fl_Button(210, Y+94, 20, 20, _("..."));
		h213_btn_date->tooltip(_("Set today"));
		h213_btn_date->callback((Fl_Callback*)h213_cb_btn_date);

		h213_txt_time = new Fl_Input2(300, Y+92, 103, 24, _("Time"));
		h213_txt_time->tooltip(_("Time of origination"));
		h213_txt_time->box(FL_DOWN_BOX);
		h213_txt_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_time->labeltype(FL_NORMAL_LABEL);
		h213_txt_time->labelfont(0);
		h213_txt_time->labelsize(14);
		h213_txt_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_time->align(FL_ALIGN_LEFT);
		h213_txt_time->callback(hics_changed);
		h213_txt_time->when(FL_WHEN_CHANGED);

		h213_btn_time0 = new Fl_Button(410, Y+94, 20, 20, _("..."));
		h213_btn_time0->tooltip(_("Set time now"));
		h213_btn_time0->callback((Fl_Callback*)h213_cb_btn_time0);

		{ Fl_Group *o = new Fl_Group(2, Y+124, 282, 50, _("Received via:"));
		o->box(FL_ENGRAVED_FRAME);
		o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		h213_btn_phone = new Fl_Check_Button(30, Y+145, 60, 24, _("Phone"));
		h213_btn_phone->value(0);
		h213_btn_phone->callback((Fl_Callback*)h213_cb_btn_via);

		h213_btn_radio = new Fl_Check_Button(120, Y+145, 60, 24, _("Radio"));
		h213_btn_radio->value(0);
		h213_btn_radio->callback((Fl_Callback*)h213_cb_btn_via);

		h213_btn_other = new Fl_Check_Button(210, Y+145, 60, 24, _("Other"));
		h213_btn_other->value(0);
		h213_btn_other->callback((Fl_Callback*)h213_cb_btn_via);

		o->end();
		}

		{ Fl_Group *o = new Fl_Group(286, Y+124, 282, 50, _("Reply requested:"));
		o->box(FL_ENGRAVED_FRAME);
		o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		h213_btn_yes = new Fl_Check_Button(340, Y+145, 60, 24, _("Yes"));
		h213_btn_yes->value(0);
		h213_btn_yes->callback((Fl_Callback*)h213_cb_btn_yes_no);

		h213_btn_no = new Fl_Check_Button(440, Y+145, 60, 24, _("No"));
		h213_btn_no->value(0);
		h213_btn_no->callback((Fl_Callback*)h213_cb_btn_yes_no);

		o->end();
		}

		h213_txt_reply_to = new Fl_Input2(80, Y+175, 480, 24, _("Reply to:"));
		h213_txt_reply_to->tooltip(_("alternate reply-to if NO reply requested"));
		h213_txt_reply_to->box(FL_DOWN_BOX);
		h213_txt_reply_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_reply_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_reply_to->labeltype(FL_NORMAL_LABEL);
		h213_txt_reply_to->labelfont(0);
		h213_txt_reply_to->labelsize(14);
		h213_txt_reply_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_reply_to->align(FL_ALIGN_LEFT);
		h213_txt_reply_to->callback(hics_changed);
		h213_txt_reply_to->when(FL_WHEN_CHANGED);

		{ Fl_Group *o = new Fl_Group(2, Y+205, 566, 50, _("Priority"));
		o->box(FL_ENGRAVED_FRAME);
		o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		h213_btn_high = new Fl_Check_Button(20, Y+226, 60, 24, _("Urgent - High"));
		h213_btn_high->value(0);
		h213_btn_high->callback((Fl_Callback*)h213_cb_btn_priority);

		h213_btn_medium = new Fl_Check_Button(155, Y+226, 60, 24, _("Non Urgent - Medium"));
		h213_btn_medium->value(0);
		h213_btn_medium->callback((Fl_Callback*)h213_cb_btn_priority);

		h213_btn_low = new Fl_Check_Button(340, Y+226, 60, 24, _("Informational - Low"));
		h213_btn_low->value(0);
		h213_btn_low->callback((Fl_Callback*)h213_cb_btn_priority);

		o->end();
		}

		h213_txt_facility = new Fl_Input2(80, Y+270, 480, 24, _("Facility"));
		h213_txt_facility->tooltip(_(""));
		h213_txt_facility->box(FL_DOWN_BOX);
		h213_txt_facility->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_facility->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_facility->labeltype(FL_NORMAL_LABEL);
		h213_txt_facility->labelfont(0);
		h213_txt_facility->labelsize(14);
		h213_txt_facility->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_facility->align(FL_ALIGN_LEFT);
		h213_txt_facility->callback(hics_changed);
		h213_txt_facility->when(FL_WHEN_CHANGED);
	}
	tab_213_grp_orig->end();

	tab_213_grp_msg = new Fl_Group(0, Y+25, 570, 360, _("Message/Action"));
	{
		h213_txt_msg = new FTextEdit(5, Y+50, 562, 155, _("Message:"));
		h213_txt_msg->box(FL_DOWN_FRAME);
		h213_txt_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_msg->labeltype(FL_NORMAL_LABEL);
		h213_txt_msg->labelfont(0);
		h213_txt_msg->labelsize(14);
		h213_txt_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_msg->align(FL_ALIGN_TOP_LEFT);
		h213_txt_msg->callback(hics_changed);
		h213_txt_msg->when(FL_WHEN_CHANGED);

		h213_txt_action = new FTextEdit(5, Y+225, 562, 155, _("Action:"));
		h213_txt_action->box(FL_DOWN_FRAME);
		h213_txt_action->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_action->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_action->labeltype(FL_NORMAL_LABEL);
		h213_txt_action->labelfont(0);
		h213_txt_action->labelsize(14);
		h213_txt_action->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_action->align(FL_ALIGN_TOP_LEFT);
		h213_txt_action->callback(hics_changed);
		h213_txt_action->when(FL_WHEN_CHANGED);

		Fl_Group::current()->resizable(h213_txt_msg);
	}
	tab_213_grp_msg->end();

	tab_213_grp_receipt1 = new Fl_Group(0, Y+25, 570, 360, _("Receipt 1"));
	{
		h213_txt_rcvd_by = new Fl_Input2(80, Y+40, 480, 24, _("Rec' by"));
		h213_txt_rcvd_by->tooltip(_("first receipt"));
		h213_txt_rcvd_by->box(FL_DOWN_BOX);
		h213_txt_rcvd_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_rcvd_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_rcvd_by->labeltype(FL_NORMAL_LABEL);
		h213_txt_rcvd_by->labelfont(0);
		h213_txt_rcvd_by->labelsize(14);
		h213_txt_rcvd_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_rcvd_by->align(FL_ALIGN_LEFT);
		h213_txt_rcvd_by->callback(hics_changed);
		h213_txt_rcvd_by->when(FL_WHEN_CHANGED);

		h213_txt_time_rcvd = new Fl_Input2(80, Y+66, 103, 24, _("Time"));
		h213_txt_time_rcvd->tooltip(_("Time of receipt"));
		h213_txt_time_rcvd->box(FL_DOWN_BOX);
		h213_txt_time_rcvd->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_time_rcvd->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_time_rcvd->labeltype(FL_NORMAL_LABEL);
		h213_txt_time_rcvd->labelfont(0);
		h213_txt_time_rcvd->labelsize(14);
		h213_txt_time_rcvd->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_time_rcvd->align(FL_ALIGN_LEFT);
		h213_txt_time_rcvd->callback(hics_changed);
		h213_txt_time_rcvd->when(FL_WHEN_CHANGED);

		h213_btn_time1 = new Fl_Button(185, Y+68, 20, 20, _("..."));
		h213_btn_time1->tooltip(_("Set time now"));
		h213_btn_time1->callback((Fl_Callback*)h213_cb_btn_time1);

		h213_txt_fwd_to = new Fl_Input2(80, Y+92, 480, 24, _("Fwd to"));
		h213_txt_fwd_to->tooltip(_("forwarded to"));
		h213_txt_fwd_to->box(FL_DOWN_BOX);
		h213_txt_fwd_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_fwd_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_fwd_to->labeltype(FL_NORMAL_LABEL);
		h213_txt_fwd_to->labelfont(0);
		h213_txt_fwd_to->labelsize(14);
		h213_txt_fwd_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_fwd_to->align(FL_ALIGN_LEFT);
		h213_txt_fwd_to->callback(hics_changed);
		h213_txt_fwd_to->when(FL_WHEN_CHANGED);

		h213_txt_comments = new FTextEdit(5, Y+136, 562, 240, _("Comments"));
		h213_txt_comments->box(FL_DOWN_FRAME);
		h213_txt_comments->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_comments->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_comments->labeltype(FL_NORMAL_LABEL);
		h213_txt_comments->labelfont(0);
		h213_txt_comments->labelsize(14);
		h213_txt_comments->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_comments->align(FL_ALIGN_TOP_LEFT);
		h213_txt_comments->callback(hics_changed);
		h213_txt_comments->when(FL_WHEN_CHANGED);

		Fl_Group::current()->resizable(h213_txt_comments);

	}
	tab_213_grp_receipt1->end();

	tab_213_grp_receipt2 = new Fl_Group(0, Y+25, 570, 360, _("Receipt 2"));
	{
		h213_txt_rcvd_by2 = new Fl_Input2(80, Y+40, 480, 24, _("Rec' by"));
		h213_txt_rcvd_by2->tooltip(_("first receipt"));
		h213_txt_rcvd_by2->box(FL_DOWN_BOX);
		h213_txt_rcvd_by2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_rcvd_by2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_rcvd_by2->labeltype(FL_NORMAL_LABEL);
		h213_txt_rcvd_by2->labelfont(0);
		h213_txt_rcvd_by2->labelsize(14);
		h213_txt_rcvd_by2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_rcvd_by2->align(FL_ALIGN_LEFT);
		h213_txt_rcvd_by2->callback(hics_changed);
		h213_txt_rcvd_by2->when(FL_WHEN_CHANGED);

		h213_txt_time_rcvd2 = new Fl_Input2(80, Y+66, 103, 24, _("Time"));
		h213_txt_time_rcvd2->tooltip(_("Time of receipt"));
		h213_txt_time_rcvd2->box(FL_DOWN_BOX);
		h213_txt_time_rcvd2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_time_rcvd2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_time_rcvd2->labeltype(FL_NORMAL_LABEL);
		h213_txt_time_rcvd2->labelfont(0);
		h213_txt_time_rcvd2->labelsize(14);
		h213_txt_time_rcvd2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_time_rcvd2->align(FL_ALIGN_LEFT);
		h213_txt_time_rcvd2->callback(hics_changed);
		h213_txt_time_rcvd2->when(FL_WHEN_CHANGED);

		h213_btn_time2 = new Fl_Button(185, Y+68, 20, 20, _("..."));
		h213_btn_time2->tooltip(_("Set time now"));
		h213_btn_time2->callback((Fl_Callback*)h213_cb_btn_time2);

		h213_txt_fwd_to2 = new Fl_Input2(80, Y+92, 480, 24, _("Fwd to"));
		h213_txt_fwd_to2->tooltip(_("forwarded to"));
		h213_txt_fwd_to2->box(FL_DOWN_BOX);
		h213_txt_fwd_to2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_fwd_to2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_fwd_to2->labeltype(FL_NORMAL_LABEL);
		h213_txt_fwd_to2->labelfont(0);
		h213_txt_fwd_to2->labelsize(14);
		h213_txt_fwd_to2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_fwd_to2->align(FL_ALIGN_LEFT);
		h213_txt_fwd_to2->callback(hics_changed);
		h213_txt_fwd_to2->when(FL_WHEN_CHANGED);

		h213_txt_comments2 = new FTextEdit(5, Y+136, 562, 240, _("Comments"));
		h213_txt_comments2->box(FL_DOWN_FRAME);
		h213_txt_comments2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h213_txt_comments2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h213_txt_comments2->labeltype(FL_NORMAL_LABEL);
		h213_txt_comments2->labelfont(0);
		h213_txt_comments2->labelsize(14);
		h213_txt_comments2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h213_txt_comments2->align(FL_ALIGN_TOP_LEFT);
		h213_txt_comments2->callback(hics_changed);
		h213_txt_comments2->when(FL_WHEN_CHANGED);

		Fl_Group::current()->resizable(h213_txt_comments2);
	}
	tab_213_grp_receipt2->end();

	h213_tab_type->end();
	Fl_Group::current()->resizable(h213_tab_type);

h213_tab->end();

h213_tab->hide();
}
