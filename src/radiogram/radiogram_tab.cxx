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

Fl_Group	*tab_radiogram = (Fl_Group *)0;
Fl_Tabs		*tabs_radiogram = (Fl_Tabs *)0;
Fl_Group	*tab_radiogram_message = (Fl_Group *)0;
Fl_Input2	*txt_rg_nbr = (Fl_Input2 *)0;

Fl_ListBox	*sel_rg_prec = (Fl_ListBox *)0;
Fl_Input2	*txt_rg_hx = (Fl_Input2 *)0;
Fl_Button	*btn_rg_hx = (Fl_Button *)0;
Fl_Input2	*txt_rg_station = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_place = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_t1 = (Fl_Input2 *)0;
Fl_Button	*btn_rgTime1 = (Fl_Button *)0;
Fl_Input2	*txt_rg_d1 = (Fl_Input2 *)0;
Fl_Button	*btn_rgDate1 = (Fl_Button *)0;
Fl_Input2	*txt_rg_to = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_phone = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_opnote = (Fl_Input2 *)0;
FTextEdit	*txt_rg_msg = (FTextEdit *)0;
Fl_Button	*btn_arl = (Fl_Button *)0;
Fl_Input2	*txt_rg_check = (Fl_Input2 *)0;
Fl_Button	*btn_rg_check = (Fl_Button *)0;

Fl_Input2	*txt_rg_sig = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_opnote2 = (Fl_Input2 *)0;
Fl_Check_Button	*btn_rg_svc = (Fl_Check_Button *)0;
Fl_Group	*tab_radiogram_information = (Fl_Group *)0;
Fl_Input2	*txt_rg_orig = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_dt2 = (Fl_Input2 *)0;
Fl_Button	*btn_rgDateTime2 = (Fl_Button *)0;
Fl_Input2	*txt_rg_dt3 = (Fl_Input2 *)0;
Fl_Button	*btn_rgDateTime3 = (Fl_Button *)0;
Fl_Input2	*txt_rg_dlvd_to = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_rcv_fm = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_rcv_net = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_dt4 = (Fl_Input2 *)0;
Fl_Button	*btn_rgDateTime4 = (Fl_Button *)0;
Fl_Input2	*txt_rg_sent_to = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_snt_net = (Fl_Input2 *)0;
Fl_Input2	*txt_rg_dt5 = (Fl_Input2 *)0;
Fl_Button	*btn_rgDateTime5 = (Fl_Button *)0;

Fl_Check_Button	*btn_rg_standard;

static void cb_txt_rg_nbr(Fl_Input2*, void*) {
  cb_rg_nbr(txt_rg_nbr);
  estimate();
}

static void cb_btn_rg_hx(Fl_Button*, void*) {
  cb_hx();
  estimate();
}

static void cb_txt_rg_station(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_station);
  estimate();
}

static void cb_txt_rg_place(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_place);
  estimate();
}

static void cb_btn_rgTime1(Fl_Button*, void*) {
  cb_rgSetTime1();
  estimate();
}

static void cb_btn_rgDate1(Fl_Button*, void*) {
  cb_rgSetDate1();
  estimate();
}

static void cb_txt_rg_to(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_to);
  estimate();
}

static void cb_txt_rg_phone(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_phone);
  estimate();
}

static void cb_txt_rg_opnote(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_opnote);
  estimate();
}

static void cb_txt_rg_msg(FTextEdit*, void*) {
  btn_rg_check->labelcolor(FL_RED);
  btn_rg_check->redraw_label();
  estimate();
}

static void cb_btn_arl(Fl_Button*, void*) {
  cb_arl();
  estimate();
}

static void cb_btn_rg_check(Fl_Button*, void*) {
  cb_rg_check();
  estimate();
}

static void cb_txt_rg_sig(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_sig);
  estimate();
}

static void cb_txt_rg_opnote2(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_opnote2);
  estimate();
}

static void cb_btn_rgDateTime2(Fl_Button*, void*) {
  cb_rgSetDateTime2();
  estimate();
}

static void cb_btn_rgDateTime3(Fl_Button*, void*) {
  cb_rgSetDateTime3();
  estimate();
}

static void cb_btn_rgDateTime4(Fl_Button*, void*) {
  cb_rgSetDateTime4();
  estimate();
}

static void cb_btn_rgDateTime5(Fl_Button*, void*) {
  cb_rgSetDateTime5();
  estimate();
}

void rg_changed(Fl_Widget *, void *)
{
	estimate();
}

void create_radiogram_tab()
{
	int Y = tab_top;
	tab_radiogram = new Fl_Group(0, Y, 570, 380);
	tab_radiogram->hide();

	tabs_radiogram = new Fl_Tabs(0, Y, 570, 380);
	tabs_radiogram->selection_color((Fl_Color)246);

		tab_radiogram_message = new Fl_Group(0, Y+25, 570, 355, _("Message"));

			Fl_Box *svctxt = new Fl_Box(12, Y+34, 17, 15, _("SVC"));
			svctxt->box(FL_FLAT_BOX);
			btn_rg_svc = new Fl_Check_Button(12, Y+55, 17, 15);
			btn_rg_svc->tooltip(_("Check for Service Message"));
			btn_rg_svc->down_box(FL_DOWN_BOX);
			btn_rg_svc->align(FL_ALIGN_TOP);

			txt_rg_nbr = new Fl_Input2(36, Y+50, 50, 24, _("*NR"));
			txt_rg_nbr->tooltip(_("Message number at station of origin"));
			txt_rg_nbr->box(FL_DOWN_BOX);
			txt_rg_nbr->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_nbr->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_nbr->labeltype(FL_NORMAL_LABEL);
			txt_rg_nbr->labelfont(0);
			txt_rg_nbr->labelsize(14);
			txt_rg_nbr->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_nbr->callback((Fl_Callback*)cb_txt_rg_nbr);
			txt_rg_nbr->align(FL_ALIGN_TOP);
			txt_rg_nbr->when(FL_WHEN_CHANGED);

			sel_rg_prec = new Fl_ListBox(88, Y+50, 120, 24, _("*PREC"));
			sel_rg_prec->tooltip(_("Message Precedence"));
			sel_rg_prec->align(FL_ALIGN_TOP);

			txt_rg_hx = new Fl_Input2(210, Y+50, 95, 24, _("HX__"));
			txt_rg_hx->tooltip(_("Handling instructions"));
			txt_rg_hx->box(FL_DOWN_BOX);
			txt_rg_hx->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_hx->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_hx->labeltype(FL_NORMAL_LABEL);
			txt_rg_hx->labelfont(0);
			txt_rg_hx->labelsize(14);
			txt_rg_hx->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_hx->align(FL_ALIGN_TOP);
			txt_rg_hx->callback(rg_changed);
			txt_rg_hx->when(FL_WHEN_CHANGED);

			btn_rg_hx = new Fl_Button(308, Y+50, 24, 24, _("hx"));
			btn_rg_hx->tooltip(_("Open HX dialog"));
			btn_rg_hx->callback((Fl_Callback*)cb_btn_rg_hx);

			txt_rg_station = new Fl_Input2(336, Y+50, 101, 24, _("*STN ORIG"));
			txt_rg_station->tooltip(_("Station call sign"));
			txt_rg_station->box(FL_DOWN_BOX);
			txt_rg_station->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_station->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_station->labeltype(FL_NORMAL_LABEL);
			txt_rg_station->labelfont(0);
			txt_rg_station->labelsize(14);
			txt_rg_station->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_station->callback((Fl_Callback*)cb_txt_rg_station);
			txt_rg_station->align(FL_ALIGN_TOP);
			txt_rg_station->when(FL_WHEN_CHANGED);

			txt_rg_check = new Fl_Input2(439, Y+50, 101, 24, _("CK"));
			txt_rg_check->tooltip(_("Message check count"));
			txt_rg_check->box(FL_DOWN_BOX);
			txt_rg_check->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_check->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_check->labeltype(FL_NORMAL_LABEL);
			txt_rg_check->labelfont(0);
			txt_rg_check->labelsize(14);
			txt_rg_check->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_check->align(FL_ALIGN_TOP);
			txt_rg_check->when(FL_WHEN_CHANGED);

			btn_rg_check = new Fl_Button(541, Y+50, 24, 24, _("ck"));
			btn_rg_check->tooltip(_("Compute check count"));
			btn_rg_check->callback((Fl_Callback*)cb_btn_rg_check);

			txt_rg_place = new Fl_Input2(6, Y+96, 266, 24, _("PLACE OF ORIG"));
			txt_rg_place->tooltip(_("Place of origin"));
			txt_rg_place->box(FL_DOWN_BOX);
			txt_rg_place->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_place->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_place->labeltype(FL_NORMAL_LABEL);
			txt_rg_place->labelfont(0);
			txt_rg_place->labelsize(14);
			txt_rg_place->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_place->callback((Fl_Callback*)cb_txt_rg_place);
			txt_rg_place->align(FL_ALIGN_TOP_LEFT);
			txt_rg_place->when(FL_WHEN_CHANGED);

			txt_rg_t1 = new Fl_Input2(288, Y+96, 81, 24, _("TIME FILED"));
			txt_rg_t1->tooltip(_("Time of origination"));
			txt_rg_t1->box(FL_DOWN_BOX);
			txt_rg_t1->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_t1->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_t1->labeltype(FL_NORMAL_LABEL);
			txt_rg_t1->labelfont(0);
			txt_rg_t1->labelsize(14);
			txt_rg_t1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_t1->align(FL_ALIGN_TOP_LEFT);
			txt_rg_t1->callback(rg_changed);
			txt_rg_t1->when(FL_WHEN_CHANGED);

			btn_rgTime1 = new Fl_Button(372, Y+96, 24, 24, _("..."));
			btn_rgTime1->tooltip(_("Set time now"));
			btn_rgTime1->callback((Fl_Callback*)cb_btn_rgTime1);

			txt_rg_d1 = new Fl_Input2(416, Y+96, 123, 24, _("*MON DY"));
			txt_rg_d1->tooltip(_("Date of origination"));
			txt_rg_d1->box(FL_DOWN_BOX);
			txt_rg_d1->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_d1->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_d1->labeltype(FL_NORMAL_LABEL);
			txt_rg_d1->labelfont(0);
			txt_rg_d1->labelsize(14);
			txt_rg_d1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_d1->align(FL_ALIGN_TOP_LEFT);
			txt_rg_d1->callback(rg_changed);
			txt_rg_d1->when(FL_WHEN_CHANGED);

			btn_rgDate1 = new Fl_Button(541, Y+96, 24, 24, _("..."));
			btn_rgDate1->tooltip(_("Set today"));
			btn_rgDate1->callback((Fl_Callback*)cb_btn_rgDate1);

			txt_rg_to = new Fl_Input2(6, Y+138, 277, 70, _("*TO"));
			txt_rg_to->tooltip(_("Addressee"));
			txt_rg_to->type(4);
			txt_rg_to->box(FL_DOWN_BOX);
			txt_rg_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_to->labeltype(FL_NORMAL_LABEL);
			txt_rg_to->labelfont(0);
			txt_rg_to->labelsize(14);
			txt_rg_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_to->callback((Fl_Callback*)cb_txt_rg_to);
			txt_rg_to->align(FL_ALIGN_TOP_LEFT);
			txt_rg_to->when(FL_WHEN_CHANGED);

			txt_rg_phone = new Fl_Input2(327, Y+137, 238, 24, _("TEL:"));
			txt_rg_phone->tooltip(_("Addressee telephone number"));
			txt_rg_phone->box(FL_DOWN_BOX);
			txt_rg_phone->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_phone->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_phone->labeltype(FL_NORMAL_LABEL);
			txt_rg_phone->labelfont(0);
			txt_rg_phone->labelsize(14);
			txt_rg_phone->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_phone->callback((Fl_Callback*)cb_txt_rg_phone);
			txt_rg_phone->align(FL_ALIGN_LEFT);
			txt_rg_phone->when(FL_WHEN_CHANGED);

			txt_rg_opnote = new Fl_Input2(360, Y+164, 205, 24, _("OP NOTE:"));
			txt_rg_opnote->tooltip(_("Operating notes"));
			txt_rg_opnote->box(FL_DOWN_BOX);
			txt_rg_opnote->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_opnote->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_opnote->labeltype(FL_NORMAL_LABEL);
			txt_rg_opnote->labelfont(0);
			txt_rg_opnote->labelsize(14);
			txt_rg_opnote->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_opnote->callback((Fl_Callback*)cb_txt_rg_opnote);
			txt_rg_opnote->align(FL_ALIGN_LEFT);
			txt_rg_opnote->when(FL_WHEN_CHANGED);

			btn_rg_standard = new Fl_Check_Button(300, Y+195, 50, 24, _("Standard Format"));
			btn_rg_standard->tooltip(_("Uncheck to allow punctuation and lower case"));
			btn_rg_standard->value(1);

			btn_arl = new Fl_Button(489, Y+195, 76, 24, _("ARL MSG"));
			btn_arl->tooltip(_("ARL message selector"));
			btn_arl->callback((Fl_Callback*)cb_btn_arl);

			txt_rg_msg = new FTextEdit(4, Y+227, 562, 125, _("TXT:"));
			txt_rg_msg->tooltip(_("Message contents - recommend limit to 25 words or less"));
			txt_rg_msg->box(FL_DOWN_BOX);
			txt_rg_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_msg->labeltype(FL_NORMAL_LABEL);
			txt_rg_msg->labelfont(0);
			txt_rg_msg->labelsize(14);
			txt_rg_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_msg->callback((Fl_Callback*)cb_txt_rg_msg);
			txt_rg_msg->align(FL_ALIGN_TOP_LEFT);
			txt_rg_msg->when(FL_WHEN_CHANGED);

			txt_rg_sig = new Fl_Input2(48, Y+354, 238, 24, _("SIG:"));
			txt_rg_sig->tooltip(_("Signature"));
			txt_rg_sig->box(FL_DOWN_BOX);
			txt_rg_sig->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_sig->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_sig->labeltype(FL_NORMAL_LABEL);
			txt_rg_sig->labelfont(0);
			txt_rg_sig->labelsize(14);
			txt_rg_sig->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_sig->callback((Fl_Callback*)cb_txt_rg_sig);
			txt_rg_sig->align(FL_ALIGN_LEFT);
			txt_rg_sig->when(FL_WHEN_CHANGED);

			txt_rg_opnote2 = new Fl_Input2(364, Y+354, 201, 24, _("OP NOTE:"));
			txt_rg_opnote2->tooltip(_("Operating notes"));
			txt_rg_opnote2->box(FL_DOWN_BOX);
			txt_rg_opnote2->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_opnote2->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_opnote2->labeltype(FL_NORMAL_LABEL);
			txt_rg_opnote2->labelfont(0);
			txt_rg_opnote2->labelsize(14);
			txt_rg_opnote2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_opnote2->callback((Fl_Callback*)cb_txt_rg_opnote2);
			txt_rg_opnote2->align(FL_ALIGN_LEFT);
			txt_rg_opnote2->when(FL_WHEN_CHANGED);

		tab_radiogram_message->end();

		tab_radiogram_information = new Fl_Group(0, Y+25, 570, 355, _("Records"));
		tab_radiogram_information->hide();

			Fl_Group* frame1 = new Fl_Group(5, Y+32, 560, 58);
			frame1->box(FL_ENGRAVED_FRAME);

			txt_rg_rcv_fm = new Fl_Input2(82, Y+36, 100, 24, _("RCVD FM:"));
			txt_rg_rcv_fm->tooltip(_("Call sign of sender"));
			txt_rg_rcv_fm->box(FL_DOWN_BOX);
			txt_rg_rcv_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_rcv_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_rcv_fm->labeltype(FL_NORMAL_LABEL);
			txt_rg_rcv_fm->labelfont(0);
			txt_rg_rcv_fm->labelsize(14);
			txt_rg_rcv_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_rcv_fm->align(FL_ALIGN_LEFT);
			txt_rg_rcv_fm->callback(rg_changed);
			txt_rg_rcv_fm->when(FL_WHEN_CHANGED);

			txt_rg_rcv_net = new Fl_Input2(221, Y+36, 100, 24, _("NET:"));
			txt_rg_rcv_net->tooltip(_("Net rcvd from"));
			txt_rg_rcv_net->box(FL_DOWN_BOX);
			txt_rg_rcv_net->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_rcv_net->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_rcv_net->labeltype(FL_NORMAL_LABEL);
			txt_rg_rcv_net->labelfont(0);
			txt_rg_rcv_net->labelsize(14);
			txt_rg_rcv_net->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_rcv_net->align(FL_ALIGN_LEFT);
			txt_rg_rcv_net->callback(rg_changed);
			txt_rg_rcv_net->when(FL_WHEN_CHANGED);

			txt_rg_dt4 = new Fl_Input2(381, Y+36, 152, 24, _("DT/TM"));
			txt_rg_dt4->tooltip(_("ddhhmm MMM YY of receipt"));
			txt_rg_dt4->box(FL_DOWN_BOX);
			txt_rg_dt4->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt4->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt4->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt4->labelfont(0);
			txt_rg_dt4->labelsize(14);
			txt_rg_dt4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt4->align(FL_ALIGN_LEFT);
			txt_rg_dt4->callback(rg_changed);
			txt_rg_dt4->when(FL_WHEN_CHANGED);

			btn_rgDateTime4 = new Fl_Button(536, Y+36, 24, 24, _("..."));
			btn_rgDateTime4->tooltip(_("Set today"));
			btn_rgDateTime4->callback((Fl_Callback*)cb_btn_rgDateTime4);

			txt_rg_sent_to = new Fl_Input2(82, Y+62, 100, 24, _("SENT TO:"));
			txt_rg_sent_to->tooltip(_("Sent to call sign"));
			txt_rg_sent_to->box(FL_DOWN_BOX);
			txt_rg_sent_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_sent_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_sent_to->labeltype(FL_NORMAL_LABEL);
			txt_rg_sent_to->labelfont(0);
			txt_rg_sent_to->labelsize(14);
			txt_rg_sent_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_sent_to->align(FL_ALIGN_LEFT);
			txt_rg_sent_to->callback(rg_changed);
			txt_rg_sent_to->when(FL_WHEN_CHANGED);

			txt_rg_snt_net = new Fl_Input2(221, Y+62, 100, 24, _("NET:"));
			txt_rg_snt_net->tooltip(_("Sent via net"));
			txt_rg_snt_net->box(FL_DOWN_BOX);
			txt_rg_snt_net->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_snt_net->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_snt_net->labeltype(FL_NORMAL_LABEL);
			txt_rg_snt_net->labelfont(0);
			txt_rg_snt_net->labelsize(14);
			txt_rg_snt_net->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_snt_net->align(FL_ALIGN_LEFT);
			txt_rg_snt_net->callback(rg_changed);
			txt_rg_snt_net->when(FL_WHEN_CHANGED);

			txt_rg_dt5 = new Fl_Input2(381, Y+62, 152, 24, _("DT/TM"));
			txt_rg_dt5->tooltip(_("ddhhmm MMM YY when sent"));
			txt_rg_dt5->box(FL_DOWN_BOX);
			txt_rg_dt5->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt5->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt5->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt5->labelfont(0);
			txt_rg_dt5->labelsize(14);
			txt_rg_dt5->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt5->align(FL_ALIGN_LEFT);
			txt_rg_dt5->callback(rg_changed);
			txt_rg_dt5->when(FL_WHEN_CHANGED);

			btn_rgDateTime5 = new Fl_Button(536, Y+62, 24, 24, _("..."));
			btn_rgDateTime5->tooltip(_("Set today"));
			btn_rgDateTime5->callback((Fl_Callback*)cb_btn_rgDateTime5);

			frame1->end();

			Fl_Group* frame2 = new Fl_Group(5, Y+90, 560, 142, _("ORIG - FM - DATE/TIME"));
			frame2->box(FL_ENGRAVED_FRAME);
			frame2->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_rg_dt2 = new Fl_Input2(381, Y+96, 152, 24, _("DT/TM"));
			txt_rg_dt2->tooltip(_("ddhhmm MMM YY of preparation"));
			txt_rg_dt2->box(FL_DOWN_BOX);
			txt_rg_dt2->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt2->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt2->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt2->labelfont(0);
			txt_rg_dt2->labelsize(14);
			txt_rg_dt2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt2->align(FL_ALIGN_LEFT);
			txt_rg_dt2->callback(rg_changed);
			txt_rg_dt2->when(FL_WHEN_CHANGED);

			btn_rgDateTime2 = new Fl_Button(536, Y+96, 24, 24, _("..."));
			btn_rgDateTime2->tooltip(_("Set today"));
			btn_rgDateTime2->callback((Fl_Callback*)cb_btn_rgDateTime2);

			txt_rg_orig = new Fl_Input2(10, Y+128, 550, 98, _("Name/Addr/City/Tel"));
			txt_rg_orig->tooltip(_("Person requesting message"));
			txt_rg_orig->type(4);
			txt_rg_orig->box(FL_DOWN_BOX);
			txt_rg_orig->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_orig->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_orig->labeltype(FL_NORMAL_LABEL);
			txt_rg_orig->labelfont(0);
			txt_rg_orig->labelsize(14);
			txt_rg_orig->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_orig->align(FL_ALIGN_TOP_LEFT);
			txt_rg_orig->callback(rg_changed);
			txt_rg_orig->when(FL_WHEN_CHANGED);

			frame2->end();

			Fl_Group* frame4 = new Fl_Group(5, Y+234, 560, 144, _("DLVD -TO - DATE/TIME"));
			frame4->box(FL_ENGRAVED_FRAME);
			frame4->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_rg_dt3 = new Fl_Input2(381, Y+240, 152, 24, _("DT/TM"));
			txt_rg_dt3->tooltip(_("ddhhmm MMM YY of delivery"));
			txt_rg_dt3->box(FL_DOWN_BOX);
			txt_rg_dt3->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt3->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt3->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt3->labelfont(0);
			txt_rg_dt3->labelsize(14);
			txt_rg_dt3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt3->align(FL_ALIGN_LEFT);
			txt_rg_dt3->callback(rg_changed);
			txt_rg_dt3->when(FL_WHEN_CHANGED);

			btn_rgDateTime3 = new Fl_Button(537, Y+240, 24, 24, _("..."));
			btn_rgDateTime3->tooltip(_("Set to today"));
			btn_rgDateTime3->callback((Fl_Callback*)cb_btn_rgDateTime3);

			txt_rg_dlvd_to = new Fl_Input2(10, Y+272, 550, 100, _("Name/Addr/City/Tel"));
			txt_rg_dlvd_to->tooltip(_("Message sent to"));
			txt_rg_dlvd_to->type(4);
			txt_rg_dlvd_to->box(FL_DOWN_BOX);
			txt_rg_dlvd_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dlvd_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dlvd_to->labeltype(FL_NORMAL_LABEL);
			txt_rg_dlvd_to->labelfont(0);
			txt_rg_dlvd_to->labelsize(14);
			txt_rg_dlvd_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dlvd_to->align(FL_ALIGN_TOP_LEFT);
			txt_rg_dlvd_to->callback(rg_changed);
			txt_rg_dlvd_to->when(FL_WHEN_CHANGED);

			frame4->end();

		tab_radiogram_information->end();
		Fl_Group::current()->resizable(tab_radiogram_information);
	tabs_radiogram->end();
	Fl_Group::current()->resizable(tabs_radiogram);
	tab_radiogram->end();

	tab_radiogram->hide();
}
