//======================================================================
// Radiogram tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_radiogram = (Fl_Group *)0;
Fl_Tabs		*tabs_radiogram = (Fl_Tabs *)0;
Fl_Group	*tab_radiogram_message = (Fl_Group *)0;
Fl_Input2	*txt_rg_nbr = (Fl_Input2 *)0;

Fl_Choice	*sel_rg_prec = (Fl_Choice *)0;
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

static void cb_txt_rg_nbr(Fl_Input2*, void*) {
  cb_rg_nbr(txt_rg_nbr);
}

static void cb_btn_rg_hx(Fl_Button*, void*) {
  cb_hx();
}

static void cb_txt_rg_station(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_station);
}

static void cb_txt_rg_place(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_place);
}

static void cb_btn_rgTime1(Fl_Button*, void*) {
  cb_rgSetTime1();
}

static void cb_btn_rgDate1(Fl_Button*, void*) {
  cb_rgSetDate1();
}

static void cb_txt_rg_to(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_to);
}

static void cb_txt_rg_phone(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_phone);
}

static void cb_txt_rg_opnote(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_opnote);
}

static void cb_txt_rg_msg(FTextEdit*, void*) {
  btn_rg_check->labelcolor(FL_RED);
btn_rg_check->redraw_label();
}

static void cb_btn_arl(Fl_Button*, void*) {
  cb_arl();
}

static void cb_btn_rg_check(Fl_Button*, void*) {
  cb_rg_check();
}

static void cb_txt_rg_sig(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_sig);
}

static void cb_txt_rg_opnote2(Fl_Input2*, void*) {
  cb_rg_filter_input(txt_rg_opnote2);
}

static void cb_btn_rgDateTime2(Fl_Button*, void*) {
  cb_rgSetDateTime2();
}

static void cb_btn_rgDateTime3(Fl_Button*, void*) {
  cb_rgSetDateTime3();
}

static void cb_btn_rgDateTime4(Fl_Button*, void*) {
  cb_rgSetDateTime4();
}

static void cb_btn_rgDateTime5(Fl_Button*, void*) {
  cb_rgSetDateTime5();
}

void create_radiogram_tab()
{
tab_radiogram = new Fl_Group(0, 45, 570, 380, _("Radiogram"));
tab_radiogram->hide();

	tabs_radiogram = new Fl_Tabs(0, 45, 570, 380);
	tabs_radiogram->selection_color((Fl_Color)246);

		tab_radiogram_message = new Fl_Group(0, 70, 570, 355, _("Message"));

			txt_rg_nbr = new Fl_Input2(36, 96, 50, 24, _("*NR"));
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

			sel_rg_prec = new Fl_Choice(88, 96, 120, 24, _("*PREC"));
			sel_rg_prec->tooltip(_("Message Precedence"));
			sel_rg_prec->down_box(FL_BORDER_BOX);
			sel_rg_prec->align(FL_ALIGN_TOP);

			txt_rg_hx = new Fl_Input2(210, 96, 95, 24, _("HX__"));
			txt_rg_hx->tooltip(_("Handling instructions"));
			txt_rg_hx->box(FL_DOWN_BOX);
			txt_rg_hx->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_hx->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_hx->labeltype(FL_NORMAL_LABEL);
			txt_rg_hx->labelfont(0);
			txt_rg_hx->labelsize(14);
			txt_rg_hx->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_hx->align(FL_ALIGN_TOP);
			txt_rg_hx->when(FL_WHEN_RELEASE);

			btn_rg_hx = new Fl_Button(308, 96, 24, 24, _("hx"));
			btn_rg_hx->tooltip(_("Open HX dialog"));
			btn_rg_hx->callback((Fl_Callback*)cb_btn_rg_hx);

			txt_rg_station = new Fl_Input2(336, 96, 101, 24, _("*STN ORIG"));
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
			txt_rg_station->when(FL_WHEN_RELEASE);

			txt_rg_place = new Fl_Input2(6, 137, 266, 24, _("PLACE OF ORIG"));
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
			txt_rg_place->when(FL_WHEN_RELEASE);

			txt_rg_t1 = new Fl_Input2(288, 137, 81, 24, _("TIME FILED"));
			txt_rg_t1->tooltip(_("Time of origination"));
			txt_rg_t1->box(FL_DOWN_BOX);
			txt_rg_t1->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_t1->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_t1->labeltype(FL_NORMAL_LABEL);
			txt_rg_t1->labelfont(0);
			txt_rg_t1->labelsize(14);
			txt_rg_t1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_t1->align(FL_ALIGN_TOP_LEFT);
			txt_rg_t1->when(FL_WHEN_RELEASE);

			btn_rgTime1 = new Fl_Button(372, 137, 24, 24, _("..."));
			btn_rgTime1->tooltip(_("Set time now"));
			btn_rgTime1->callback((Fl_Callback*)cb_btn_rgTime1);

			txt_rg_d1 = new Fl_Input2(416, 137, 123, 24, _("*MON DY"));
			txt_rg_d1->tooltip(_("Date of origination"));
			txt_rg_d1->box(FL_DOWN_BOX);
			txt_rg_d1->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_d1->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_d1->labeltype(FL_NORMAL_LABEL);
			txt_rg_d1->labelfont(0);
			txt_rg_d1->labelsize(14);
			txt_rg_d1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_d1->align(FL_ALIGN_TOP_LEFT);
			txt_rg_d1->when(FL_WHEN_RELEASE);

			btn_rgDate1 = new Fl_Button(541, 137, 24, 24, _("..."));
			btn_rgDate1->tooltip(_("Set today"));
			btn_rgDate1->callback((Fl_Callback*)cb_btn_rgDate1);

			txt_rg_to = new Fl_Input2(6, 179, 277, 70, _("*TO"));
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
			txt_rg_to->when(FL_WHEN_RELEASE);

			txt_rg_phone = new Fl_Input2(327, 176, 238, 24, _("TEL:"));
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
			txt_rg_phone->when(FL_WHEN_RELEASE);

			txt_rg_opnote = new Fl_Input2(360, 203, 205, 24, _("OP NOTE:"));
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
			txt_rg_opnote->when(FL_WHEN_RELEASE);

			txt_rg_msg = new FTextEdit(4, 271, 562, 119, _("TXT:"));
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

			btn_arl = new Fl_Button(489, 238, 76, 24, _("ARL MSG"));
			btn_arl->tooltip(_("ARL message selector"));
			btn_arl->callback((Fl_Callback*)cb_btn_arl);

			txt_rg_check = new Fl_Input2(439, 96, 101, 24, _("CK"));
			txt_rg_check->tooltip(_("Message check count"));
			txt_rg_check->box(FL_DOWN_BOX);
			txt_rg_check->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_check->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_check->labeltype(FL_NORMAL_LABEL);
			txt_rg_check->labelfont(0);
			txt_rg_check->labelsize(14);
			txt_rg_check->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_check->align(FL_ALIGN_TOP);
			txt_rg_check->when(FL_WHEN_RELEASE);

			btn_rg_check = new Fl_Button(541, 96, 24, 24, _("ck"));
			btn_rg_check->tooltip(_("Compute check count"));
			btn_rg_check->callback((Fl_Callback*)cb_btn_rg_check);

			txt_rg_sig = new Fl_Input2(48, 396, 238, 24, _("SIG:"));
			txt_rg_sig->tooltip(_("Addressee telephone number"));
			txt_rg_sig->box(FL_DOWN_BOX);
			txt_rg_sig->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_sig->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_sig->labeltype(FL_NORMAL_LABEL);
			txt_rg_sig->labelfont(0);
			txt_rg_sig->labelsize(14);
			txt_rg_sig->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_sig->callback((Fl_Callback*)cb_txt_rg_sig);
			txt_rg_sig->align(FL_ALIGN_LEFT);
			txt_rg_sig->when(FL_WHEN_RELEASE);

			txt_rg_opnote2 = new Fl_Input2(364, 396, 201, 24, _("OP NOTE:"));
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
			txt_rg_opnote2->when(FL_WHEN_RELEASE);

			btn_rg_svc = new Fl_Check_Button(12, 100, 17, 15, _("SVC"));
			btn_rg_svc->tooltip(_("Check for Service Message"));
			btn_rg_svc->down_box(FL_DOWN_BOX);
			btn_rg_svc->align(FL_ALIGN_TOP);

		tab_radiogram_message->end();

		tab_radiogram_information = new Fl_Group(0, 70, 570, 355, _("Records"));
		tab_radiogram_information->hide();

			{
			Fl_Group* o = new Fl_Group(5, 113, 560, 140, _("ORIG - FM - DATE/TIME"));
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_rg_orig = new Fl_Input2(10, 148, 550, 100, _("Name/Addr/City/Tel"));
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
			txt_rg_orig->when(FL_WHEN_RELEASE);

			txt_rg_dt2 = new Fl_Input2(381, 119, 152, 24, _("DT/TM"));
			txt_rg_dt2->tooltip(_("ddhhmm MMM YY of preparation"));
			txt_rg_dt2->box(FL_DOWN_BOX);
			txt_rg_dt2->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt2->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt2->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt2->labelfont(0);
			txt_rg_dt2->labelsize(14);
			txt_rg_dt2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt2->align(FL_ALIGN_LEFT);
			txt_rg_dt2->when(FL_WHEN_RELEASE);

			btn_rgDateTime2 = new Fl_Button(536, 119, 24, 24, _("..."));
			btn_rgDateTime2->tooltip(_("Set today"));
			btn_rgDateTime2->callback((Fl_Callback*)cb_btn_rgDateTime2);

			o->end();
			}

			{
			Fl_Group* o = new Fl_Group(5, 284, 560, 140, _("DLVD -TO - DATE/TIME"));
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_rg_dt3 = new Fl_Input2(381, 290, 152, 24, _("DT/TM"));
			txt_rg_dt3->tooltip(_("ddhhmm MMM YY of deliver"));
			txt_rg_dt3->box(FL_DOWN_BOX);
			txt_rg_dt3->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt3->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt3->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt3->labelfont(0);
			txt_rg_dt3->labelsize(14);
			txt_rg_dt3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt3->align(FL_ALIGN_LEFT);
			txt_rg_dt3->when(FL_WHEN_RELEASE);

			btn_rgDateTime3 = new Fl_Button(537, 290, 24, 24, _("..."));
			btn_rgDateTime3->tooltip(_("Set to today"));
			btn_rgDateTime3->callback((Fl_Callback*)cb_btn_rgDateTime3);

			txt_rg_dlvd_to = new Fl_Input2(10, 319, 550, 100, _("Name/Addr/City/Tel"));
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
			txt_rg_dlvd_to->when(FL_WHEN_RELEASE);

			o->end();
			}

			{
			Fl_Group* o = new Fl_Group(5, 82, 560, 30);
			o->box(FL_ENGRAVED_FRAME);

			txt_rg_rcv_fm = new Fl_Input2(82, 85, 100, 24, _("RCVD FM:"));
			txt_rg_rcv_fm->tooltip(_("Call sign of sender"));
			txt_rg_rcv_fm->box(FL_DOWN_BOX);
			txt_rg_rcv_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_rcv_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_rcv_fm->labeltype(FL_NORMAL_LABEL);
			txt_rg_rcv_fm->labelfont(0);
			txt_rg_rcv_fm->labelsize(14);
			txt_rg_rcv_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_rcv_fm->align(FL_ALIGN_LEFT);
			txt_rg_rcv_fm->when(FL_WHEN_RELEASE);

			txt_rg_rcv_net = new Fl_Input2(221, 85, 100, 24, _("NET:"));
			txt_rg_rcv_net->tooltip(_("Net rcvd from"));
			txt_rg_rcv_net->box(FL_DOWN_BOX);
			txt_rg_rcv_net->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_rcv_net->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_rcv_net->labeltype(FL_NORMAL_LABEL);
			txt_rg_rcv_net->labelfont(0);
			txt_rg_rcv_net->labelsize(14);
			txt_rg_rcv_net->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_rcv_net->align(FL_ALIGN_LEFT);
			txt_rg_rcv_net->when(FL_WHEN_RELEASE);

			txt_rg_dt4 = new Fl_Input2(381, 85, 152, 24, _("DT/TM"));
			txt_rg_dt4->tooltip(_("ddhhmm MMM YY of preparation"));
			txt_rg_dt4->box(FL_DOWN_BOX);
			txt_rg_dt4->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt4->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt4->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt4->labelfont(0);
			txt_rg_dt4->labelsize(14);
			txt_rg_dt4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt4->align(FL_ALIGN_LEFT);
			txt_rg_dt4->when(FL_WHEN_RELEASE);

			btn_rgDateTime4 = new Fl_Button(536, 85, 24, 24, _("..."));
			btn_rgDateTime4->tooltip(_("Set today"));
			btn_rgDateTime4->callback((Fl_Callback*)cb_btn_rgDateTime4);

			o->end();
			}

			{
			Fl_Group* o = new Fl_Group(5, 253, 560, 30);
			o->box(FL_ENGRAVED_FRAME);

			txt_rg_sent_to = new Fl_Input2(82, 256, 100, 24, _("SENT TO:"));
			txt_rg_sent_to->tooltip(_("Sent to call sign"));
			txt_rg_sent_to->box(FL_DOWN_BOX);
			txt_rg_sent_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_sent_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_sent_to->labeltype(FL_NORMAL_LABEL);
			txt_rg_sent_to->labelfont(0);
			txt_rg_sent_to->labelsize(14);
			txt_rg_sent_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_sent_to->align(FL_ALIGN_LEFT);
			txt_rg_sent_to->when(FL_WHEN_RELEASE);

			txt_rg_snt_net = new Fl_Input2(221, 256, 100, 24, _("NET:"));
			txt_rg_snt_net->tooltip(_("Sent via net"));
			txt_rg_snt_net->box(FL_DOWN_BOX);
			txt_rg_snt_net->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_snt_net->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_snt_net->labeltype(FL_NORMAL_LABEL);
			txt_rg_snt_net->labelfont(0);
			txt_rg_snt_net->labelsize(14);
			txt_rg_snt_net->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_snt_net->align(FL_ALIGN_LEFT);
			txt_rg_snt_net->when(FL_WHEN_RELEASE);

			txt_rg_dt5 = new Fl_Input2(381, 256, 152, 24, _("DT/TM"));
			txt_rg_dt5->tooltip(_("ddhhmm MMM YY of preparation"));
			txt_rg_dt5->box(FL_DOWN_BOX);
			txt_rg_dt5->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_rg_dt5->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_rg_dt5->labeltype(FL_NORMAL_LABEL);
			txt_rg_dt5->labelfont(0);
			txt_rg_dt5->labelsize(14);
			txt_rg_dt5->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_rg_dt5->align(FL_ALIGN_LEFT);
			txt_rg_dt5->when(FL_WHEN_RELEASE);

			btn_rgDateTime5 = new Fl_Button(536, 256, 24, 24, _("..."));
			btn_rgDateTime5->tooltip(_("Set today"));
			btn_rgDateTime5->callback((Fl_Callback*)cb_btn_rgDateTime5);

			o->end();
			}

		tab_radiogram_information->end();
		Fl_Group::current()->resizable(tab_radiogram_information);
	tabs_radiogram->end();
	Fl_Group::current()->resizable(tabs_radiogram);
tab_radiogram->end();
}
