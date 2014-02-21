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

Fl_Group	*tab_iaru = (Fl_Group *)0;
Fl_Tabs		*tabs_iaru = (Fl_Tabs *)0;
Fl_Group	*tab_iaru_message = (Fl_Group *)0;
Fl_Group	*tab_iaru_information = (Fl_Group *)0;
Fl_Input2	*iaru_txt_nbr = (Fl_Input2 *)0;

Fl_ListBox	*iaru_sel_prec = (Fl_ListBox *)0;

Fl_Input2	*iaru_txt_station = (Fl_Input2 *)0;
Fl_Input2	*iaru_txt_orig = (Fl_Input2 *)0;

Fl_Input2	*iaru_txt_t1 = (Fl_Input2 *)0;
Fl_Button	*iaru_btn_t1 = (Fl_Button *)0;
Fl_Input2	*iaru_txt_d1 = (Fl_Input2 *)0;
Fl_Button	*iaru_btn_d1 = (Fl_Button *)0;

Fl_Input2	*iaru_txt_check = (Fl_Input2 *)0;
Fl_Button	*iaru_btn_check = (Fl_Button *)0;

Fl_Input2	*iaru_txt_to = (Fl_Input2 *)0;
FTextEdit	*iaru_txt_msg = (FTextEdit *)0;
Fl_Input2	*iaru_txt_fm = (Fl_Input2 *)0;

Fl_Input2	*iaru_txt_rcv_fm = (Fl_Input2 *)0;
Fl_Input2	*iaru_txt_d2 = (Fl_Input2 *)0;
Fl_Button	*iaru_btn_d2 = (Fl_Button *)0;
Fl_Input2	*iaru_txt_t2 = (Fl_Input2 *)0;
Fl_Button	*iaru_btn_t2 = (Fl_Button *)0;

Fl_Input2	*iaru_txt_sent_to = (Fl_Input2 *)0;
Fl_Input2	*iaru_txt_d3 = (Fl_Input2 *)0;
Fl_Button	*iaru_btn_d3 = (Fl_Button *)0;
Fl_Input2	*iaru_txt_t3 = (Fl_Input2 *)0;
Fl_Button	*iaru_btn_t3 = (Fl_Button *)0;

static void cb_iaru_txt_nbr(Fl_Input2*, void*) {
  iaru_cb_nbr(iaru_txt_nbr);
}

static void cb_iaru_txt_station(Fl_Input2*, void*) {
  iaru_cb_filter_input(iaru_txt_station);
}

static void cb_iaru_txt_orig(Fl_Input2*, void*) {
  iaru_cb_filter_input(iaru_txt_orig);
}

static void cb_iaru_btn_t1(Fl_Button*, void*) {
  iaru_cb_set_t1();
}

static void cb_iaru_btn_d1(Fl_Button*, void*) {
  iaru_cb_set_d1();
}

static void cb_iaru_btn_t2(Fl_Button*, void*) {
  iaru_cb_set_t2();
}

static void cb_iaru_btn_d2(Fl_Button*, void*) {
  iaru_cb_set_d2();
}

static void cb_iaru_btn_t3(Fl_Button*, void*) {
  iaru_cb_set_t3();
}

static void cb_iaru_btn_d3(Fl_Button*, void*) {
  iaru_cb_set_d3();
}

static void cb_iaru_txt_to(Fl_Input2*, void*) {
  iaru_cb_filter_input(iaru_txt_to);
}

static void cb_iaru_txt_fm(Fl_Input2*, void*) {
  iaru_cb_filter_input(iaru_txt_fm);
}

static void cb_iaru_txt_msg(FTextEdit*, void*) {
  iaru_btn_check->labelcolor(FL_RED);
iaru_btn_check->redraw_label();
}

static void cb_iaru_btn_check(Fl_Button*, void*) {
  iaru_cb_check();
}

void iaru_changed(Fl_Widget *, void *)
{
	estimate();
}

void create_iaru_tab()
{
	int Y = tab_top;
	tab_iaru = new Fl_Group(0, Y, 570, 404);
	tab_iaru->align(FL_ALIGN_TOP);

		iaru_txt_nbr = new Fl_Input2(4, Y+20, 102, 24, _("NR"));
		iaru_txt_nbr->tooltip(_("Message number at station of origin"));
		iaru_txt_nbr->box(FL_DOWN_BOX);
		iaru_txt_nbr->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_nbr->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_nbr->labeltype(FL_NORMAL_LABEL);
		iaru_txt_nbr->labelfont(0);
		iaru_txt_nbr->labelsize(14);
		iaru_txt_nbr->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_nbr->callback((Fl_Callback*)cb_iaru_txt_nbr);
		iaru_txt_nbr->align(FL_ALIGN_TOP);
		iaru_txt_nbr->callback(iaru_changed);
		iaru_txt_nbr->when(FL_WHEN_CHANGED);

		iaru_sel_prec = new Fl_ListBox(108, Y+20, 120, 24, _("PREC"));
		iaru_sel_prec->tooltip(_("Message Precedence"));
		iaru_sel_prec->align(FL_ALIGN_TOP);

		iaru_txt_station = new Fl_Input2(230, Y+20, 100, 24, _("STN OF ORIG"));
		iaru_txt_station->tooltip(_("Station call sign"));
		iaru_txt_station->box(FL_DOWN_BOX);
		iaru_txt_station->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_station->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_station->labeltype(FL_NORMAL_LABEL);
		iaru_txt_station->labelfont(0);
		iaru_txt_station->labelsize(14);
		iaru_txt_station->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_station->callback((Fl_Callback*)cb_iaru_txt_station);
		iaru_txt_station->align(FL_ALIGN_TOP);
		iaru_txt_station->callback(iaru_changed);
		iaru_txt_station->when(FL_WHEN_CHANGED);

		iaru_txt_orig = new Fl_Input2(332, Y+20, 230, 24, _("PLACE OF ORIG"));
		iaru_txt_orig->tooltip(_("Place of origin"));
		iaru_txt_orig->box(FL_DOWN_BOX);
		iaru_txt_orig->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_orig->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_orig->labeltype(FL_NORMAL_LABEL);
		iaru_txt_orig->labelfont(0);
		iaru_txt_orig->labelsize(14);
		iaru_txt_orig->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_orig->callback((Fl_Callback*)cb_iaru_txt_orig);
		iaru_txt_orig->align(FL_ALIGN_TOP_LEFT);
		iaru_txt_orig->callback(iaru_changed);
		iaru_txt_orig->when(FL_WHEN_CHANGED);

		iaru_txt_t1 = new Fl_Input2(90, Y+50, 80, 24, _("FILED TIME"));
		iaru_txt_t1->tooltip(_("Time of filing"));
		iaru_txt_t1->box(FL_DOWN_BOX);
		iaru_txt_t1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_t1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_t1->labeltype(FL_NORMAL_LABEL);
		iaru_txt_t1->labelfont(0);
		iaru_txt_t1->labelsize(14);
		iaru_txt_t1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_t1->align(FL_ALIGN_LEFT);
		iaru_txt_t1->callback(iaru_changed);
		iaru_txt_t1->when(FL_WHEN_CHANGED);

		iaru_btn_t1 = new Fl_Button(174, Y+52, 20, 20, _("..."));
		iaru_btn_t1->tooltip(_("Set time now"));
		iaru_btn_t1->callback((Fl_Callback*)cb_iaru_btn_t1);

		iaru_txt_d1 = new Fl_Input2(290, Y+50, 80, 24, _("FILED DATE"));
		iaru_txt_d1->tooltip(_("Date of filing"));
		iaru_txt_d1->box(FL_DOWN_BOX);
		iaru_txt_d1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_d1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_d1->labeltype(FL_NORMAL_LABEL);
		iaru_txt_d1->labelfont(0);
		iaru_txt_d1->labelsize(14);
		iaru_txt_d1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_d1->align(FL_ALIGN_LEFT);
		iaru_txt_d1->callback(iaru_changed);
		iaru_txt_d1->when(FL_WHEN_CHANGED);

		iaru_btn_d1 = new Fl_Button(372, Y+52, 20, 20, _("..."));
		iaru_btn_d1->tooltip(_("Set today"));
		iaru_btn_d1->callback((Fl_Callback*)cb_iaru_btn_d1);

		iaru_txt_check = new Fl_Input2(460, Y+50, 50, 24, _("CHECK"));
		iaru_txt_check->tooltip(_("Message check count"));
		iaru_txt_check->box(FL_DOWN_BOX);
		iaru_txt_check->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_check->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_check->labeltype(FL_NORMAL_LABEL);
		iaru_txt_check->labelfont(0);
		iaru_txt_check->labelsize(14);
		iaru_txt_check->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_check->align(FL_ALIGN_LEFT);
		iaru_txt_check->callback(iaru_changed);
		iaru_txt_check->when(FL_WHEN_CHANGED);

		iaru_btn_check = new Fl_Button(512, Y+52, 22, 22, _("ck"));
		iaru_btn_check->tooltip(_("Compute check count"));
		iaru_btn_check->callback((Fl_Callback*)cb_iaru_btn_check);

		iaru_txt_to = new Fl_Input2(4, Y+93, 275, 60, _("TO"));
		iaru_txt_to->tooltip(_("Addressee"));
		iaru_txt_to->type(4);
		iaru_txt_to->box(FL_DOWN_BOX);
		iaru_txt_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_to->labeltype(FL_NORMAL_LABEL);
		iaru_txt_to->labelfont(0);
		iaru_txt_to->labelsize(14);
		iaru_txt_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_to->callback((Fl_Callback*)cb_iaru_txt_to);
		iaru_txt_to->align(FL_ALIGN_TOP_LEFT);
		iaru_txt_to->callback(iaru_changed);
		iaru_txt_to->when(FL_WHEN_CHANGED);

		iaru_txt_fm = new Fl_Input2(290, Y+93, 275, 60, _("FROM"));
		iaru_txt_fm->tooltip(_("Message originator"));
		iaru_txt_fm->type(4);
		iaru_txt_fm->box(FL_DOWN_BOX);
		iaru_txt_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_fm->labeltype(FL_NORMAL_LABEL);
		iaru_txt_fm->labelfont(0);
		iaru_txt_fm->labelsize(14);
		iaru_txt_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_fm->callback((Fl_Callback*)cb_iaru_txt_fm);
		iaru_txt_fm->align(FL_ALIGN_TOP_LEFT);
		iaru_txt_fm->callback(iaru_changed);
		iaru_txt_fm->when(FL_WHEN_CHANGED);

		iaru_txt_msg = new FTextEdit(4, Y+172, 562, 140, _("MESSAGE"));
		iaru_txt_msg->tooltip(_("Message contents"));
		iaru_txt_msg->box(FL_DOWN_BOX);
		iaru_txt_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_msg->labeltype(FL_NORMAL_LABEL);
		iaru_txt_msg->labelfont(0);
		iaru_txt_msg->labelsize(14);
		iaru_txt_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_msg->callback((Fl_Callback*)cb_iaru_txt_msg);
		iaru_txt_msg->align(FL_ALIGN_TOP_LEFT);
		iaru_txt_msg->callback(iaru_changed);
		iaru_txt_msg->when(FL_WHEN_CHANGED);

		iaru_txt_rcv_fm = new Fl_Input2(130, Y+315, 100, 24, _("RECEIVED FROM"));
		iaru_txt_rcv_fm->tooltip(_("Call sign of sender"));
		iaru_txt_rcv_fm->box(FL_DOWN_BOX);
		iaru_txt_rcv_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_rcv_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_rcv_fm->labeltype(FL_NORMAL_LABEL);
		iaru_txt_rcv_fm->labelfont(0);
		iaru_txt_rcv_fm->labelsize(14);
		iaru_txt_rcv_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_rcv_fm->align(FL_ALIGN_LEFT);
		iaru_txt_rcv_fm->callback(iaru_changed);
		iaru_txt_rcv_fm->when(FL_WHEN_CHANGED);

		iaru_txt_d2 = new Fl_Input2(280, Y+315, 80, 24, _("DATE"));
		iaru_txt_d2->tooltip(_("date of receipt"));
		iaru_txt_d2->box(FL_DOWN_BOX);
		iaru_txt_d2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_d2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_d2->labeltype(FL_NORMAL_LABEL);
		iaru_txt_d2->labelfont(0);
		iaru_txt_d2->labelsize(14);
		iaru_txt_d2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_d2->align(FL_ALIGN_LEFT);
		iaru_txt_d2->callback(iaru_changed);
		iaru_txt_d2->when(FL_WHEN_CHANGED);

		iaru_btn_d2 = new Fl_Button(362, Y+317, 20, 20, _("..."));
		iaru_btn_d2->tooltip(_("Set today"));
		iaru_btn_d2->callback((Fl_Callback*)cb_iaru_btn_d2);

		iaru_txt_t2 = new Fl_Input2(440, Y+315, 80, 24, _("TIME"));
		iaru_txt_t2->tooltip(_("Time of receipt"));
		iaru_txt_t2->box(FL_DOWN_BOX);
		iaru_txt_t2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_t2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_t2->labeltype(FL_NORMAL_LABEL);
		iaru_txt_t2->labelfont(0);
		iaru_txt_t2->labelsize(14);
		iaru_txt_t2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_t2->align(FL_ALIGN_LEFT);
		iaru_txt_t2->callback(iaru_changed);
		iaru_txt_t2->when(FL_WHEN_CHANGED);

		iaru_btn_t2 = new Fl_Button(522, Y+317, 20, 20, _("..."));
		iaru_btn_t2->tooltip(_("Set time now"));
		iaru_btn_t2->callback((Fl_Callback*)cb_iaru_btn_t2);

		iaru_txt_sent_to = new Fl_Input2(130, Y+340, 100, 24, _("SENT TO"));
		iaru_txt_sent_to->tooltip(_("Sent to call sign"));
		iaru_txt_sent_to->box(FL_DOWN_BOX);
		iaru_txt_sent_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_sent_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_sent_to->labeltype(FL_NORMAL_LABEL);
		iaru_txt_sent_to->labelfont(0);
		iaru_txt_sent_to->labelsize(14);
		iaru_txt_sent_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_sent_to->align(FL_ALIGN_LEFT);
		iaru_txt_sent_to->callback(iaru_changed);
		iaru_txt_sent_to->when(FL_WHEN_CHANGED);

		iaru_txt_d3 = new Fl_Input2(280, Y+340, 80, 24, _("DATE"));
		iaru_txt_d3->tooltip(_("date message sent"));
		iaru_txt_d3->box(FL_DOWN_BOX);
		iaru_txt_d3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_d3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_d3->labeltype(FL_NORMAL_LABEL);
		iaru_txt_d3->labelfont(0);
		iaru_txt_d3->labelsize(14);
		iaru_txt_d3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_d3->align(FL_ALIGN_LEFT);
		iaru_txt_d3->callback(iaru_changed);
		iaru_txt_d3->when(FL_WHEN_CHANGED);

		iaru_btn_d3 = new Fl_Button(362, Y+342, 20, 20, _("..."));
		iaru_btn_d3->tooltip(_("Set today"));
		iaru_btn_d3->callback((Fl_Callback*)cb_iaru_btn_d3);

		iaru_txt_t3 = new Fl_Input2(440, Y+340, 81, 24, _("TIME"));
		iaru_txt_t3->tooltip(_("Time sent"));
		iaru_txt_t3->box(FL_DOWN_BOX);
		iaru_txt_t3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		iaru_txt_t3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		iaru_txt_t3->labeltype(FL_NORMAL_LABEL);
		iaru_txt_t3->labelfont(0);
		iaru_txt_t3->labelsize(14);
		iaru_txt_t3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		iaru_txt_t3->align(FL_ALIGN_LEFT);
		iaru_txt_t3->callback(iaru_changed);
		iaru_txt_t3->when(FL_WHEN_CHANGED);

		iaru_btn_t3 = new Fl_Button(522, Y+342, 20, 20, _("..."));
		iaru_btn_t3->tooltip(_("Set time now"));
		iaru_btn_t3->callback((Fl_Callback*)cb_iaru_btn_t3);

	tab_iaru->end();
	tab_iaru->hide();
}
