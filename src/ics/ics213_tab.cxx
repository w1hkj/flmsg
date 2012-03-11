//======================================================================
// ICS 213 tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Tabs	*tabs_msg_type = (Fl_Tabs *)0;

Fl_Group	*tab_ics213 = (Fl_Group *)0;
Fl_Tabs		*tab_ics213_type = (Fl_Tabs *)0;
Fl_Group	*tab_213_originator = (Fl_Group *)0;
Fl_Input2	*txt_213_to = (Fl_Input2 *)0;
Fl_Input2	*txt_213_p1 = (Fl_Input2 *)0;
Fl_Input2	*txt_213_fm = (Fl_Input2 *)0;
Fl_Input2	*txt_213_p2 = (Fl_Input2 *)0;
Fl_Input2	*txt_213_subj = (Fl_Input2 *)0;
Fl_DateInput	*txt_213_d1 = (Fl_DateInput *)0;
Fl_Button	*btn_213_date1 = (Fl_Button *)0;
Fl_Input2	*txt_213_t1 = (Fl_Input2 *)0;
Fl_Button	*btn_213_time1 = (Fl_Button *)0;
FTextEdit	*txt_213_msg = (FTextEdit *)0;
Fl_Input2	*txt_213_s1 = (Fl_Input2 *)0;
Fl_Input2	*txt_213_p3 = (Fl_Input2 *)0;
Fl_Group	*tab_213_responder = (Fl_Group *)0;
Fl_Input2	*txt_213_s2 = (Fl_Input2 *)0;
Fl_DateInput	*txt_213_d2 = (Fl_DateInput *)0;
Fl_Input2	*txt_213_t2 = (Fl_Input2 *)0;
Fl_Button	*btn_213_time2 = (Fl_Button *)0;
FTextEdit	*txt_213_reply = (FTextEdit *)0;
Fl_Input2	*txt_213_p4 = (Fl_Input2 *)0;
Fl_Button	*btn_213_date2 = (Fl_Button *)0;

static void cb_btn_213_date1(Fl_Button*, void*) {
  cb_SetDate1();
}

static void cb_btn_213_time1(Fl_Button*, void*) {
  cb_SetTime1();
}

static void cb_btn_213_time2(Fl_Button*, void*) {
  cb_SetTime2();
}

static void cb_btn_213_date2(Fl_Button*, void*) {
  cb_SetDate2();
}

void create_ics213_tab()
{
	int Y = tab_top;
	tab_ics213 = new Fl_Group(0, Y, 570, 390);
	tab_ics213->align(FL_ALIGN_TOP);

	tab_ics213_type = new Fl_Tabs(0, Y, 570, 387);
	tab_ics213_type->selection_color((Fl_Color)246);

	tab_213_originator = new Fl_Group(0, Y+25, 570, 360, _("Originator"));

		txt_213_to = new Fl_Input2(40, Y+40, 242, 24, _("To"));
		txt_213_to->tooltip(_("Addressee"));
		txt_213_to->box(FL_DOWN_BOX);
		txt_213_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_to->labeltype(FL_NORMAL_LABEL);
		txt_213_to->labelfont(0);
		txt_213_to->labelsize(14);
		txt_213_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_to->align(FL_ALIGN_LEFT);
		txt_213_to->when(FL_WHEN_RELEASE);

		txt_213_p1 = new Fl_Input2(321, Y+40, 242, 24, _("Pos."));
		txt_213_p1->tooltip(_("Position of addressee"));
		txt_213_p1->box(FL_DOWN_BOX);
		txt_213_p1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_p1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_p1->labeltype(FL_NORMAL_LABEL);
		txt_213_p1->labelfont(0);
		txt_213_p1->labelsize(14);
		txt_213_p1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_p1->align(FL_ALIGN_LEFT);
		txt_213_p1->when(FL_WHEN_RELEASE);

		txt_213_fm = new Fl_Input2(40, Y+66, 242, 24, _("Fm"));
		txt_213_fm->tooltip(_("Originator"));
		txt_213_fm->box(FL_DOWN_BOX);
		txt_213_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_fm->labeltype(FL_NORMAL_LABEL);
		txt_213_fm->labelfont(0);
		txt_213_fm->labelsize(14);
		txt_213_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_fm->align(FL_ALIGN_LEFT);
		txt_213_fm->when(FL_WHEN_RELEASE);

		txt_213_p2 = new Fl_Input2(321, Y+66, 242, 24, _("Pos."));
		txt_213_p2->tooltip(_("Position of originator"));
		txt_213_p2->box(FL_DOWN_BOX);
		txt_213_p2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_p2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_p2->labeltype(FL_NORMAL_LABEL);
		txt_213_p2->labelfont(0);
		txt_213_p2->labelsize(14);
		txt_213_p2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_p2->align(FL_ALIGN_LEFT);
		txt_213_p2->when(FL_WHEN_RELEASE);

		txt_213_subj = new Fl_Input2(40, Y+92, 522, 24, _("Sub."));
		txt_213_subj->tooltip(_("Subject"));
		txt_213_subj->box(FL_DOWN_BOX);
		txt_213_subj->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_subj->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_subj->labeltype(FL_NORMAL_LABEL);
		txt_213_subj->labelfont(0);
		txt_213_subj->labelsize(14);
		txt_213_subj->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_subj->align(FL_ALIGN_LEFT);
		txt_213_subj->when(FL_WHEN_RELEASE);

		txt_213_d1 = new Fl_DateInput(232, Y+118, 125, 24, _("Date"));
		txt_213_d1->tooltip(_("Date of origination"));
		txt_213_d1->box(FL_DOWN_BOX);
		txt_213_d1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_d1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_d1->labeltype(FL_NORMAL_LABEL);
		txt_213_d1->labelfont(0);
		txt_213_d1->labelsize(14);
		txt_213_d1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_d1->align(FL_ALIGN_LEFT);
		txt_213_d1->when(FL_WHEN_RELEASE);
		txt_213_d1->format(2);

		btn_213_date1 = new Fl_Button(365, Y+120, 20, 20, _("..."));
		btn_213_date1->tooltip(_("Set today"));
		btn_213_date1->callback((Fl_Callback*)cb_btn_213_date1);

		txt_213_t1 = new Fl_Input2(430, Y+118, 103, 24, _("Time"));
		txt_213_t1->tooltip(_("Time of origination"));
		txt_213_t1->box(FL_DOWN_BOX);
		txt_213_t1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_t1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_t1->labeltype(FL_NORMAL_LABEL);
		txt_213_t1->labelfont(0);
		txt_213_t1->labelsize(14);
		txt_213_t1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_t1->align(FL_ALIGN_LEFT);
		txt_213_t1->when(FL_WHEN_RELEASE);

		btn_213_time1 = new Fl_Button(540, Y+120, 20, 20, _("..."));
		btn_213_time1->tooltip(_("Set time now"));
		btn_213_time1->callback((Fl_Callback*)cb_btn_213_time1);

		txt_213_msg = new FTextEdit(5, Y+148, 562, 200, _("Message:"));
		txt_213_msg->box(FL_DOWN_FRAME);
		txt_213_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_msg->labeltype(FL_NORMAL_LABEL);
		txt_213_msg->labelfont(0);
		txt_213_msg->labelsize(14);
		txt_213_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_msg->align(FL_ALIGN_TOP_LEFT);
		txt_213_msg->when(FL_WHEN_RELEASE);

		Fl_Group::current()->resizable(txt_213_msg);

		txt_213_s1 = new Fl_Input2(33, Y+351, 247, 24, _("Sig."));
		txt_213_s1->tooltip(_("Signature of preparer"));
		txt_213_s1->box(FL_DOWN_BOX);
		txt_213_s1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_s1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_s1->labeltype(FL_NORMAL_LABEL);
		txt_213_s1->labelfont(0);
		txt_213_s1->labelsize(14);
		txt_213_s1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_s1->align(FL_ALIGN_LEFT);
		txt_213_s1->when(FL_WHEN_RELEASE);

		txt_213_p3 = new Fl_Input2(316, Y+351, 247, 24, _("Pos."));
		txt_213_p3->tooltip(_("Position of preparer"));
		txt_213_p3->box(FL_DOWN_BOX);
		txt_213_p3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_p3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_p3->labeltype(FL_NORMAL_LABEL);
		txt_213_p3->labelfont(0);
		txt_213_p3->labelsize(14);
		txt_213_p3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_p3->align(FL_ALIGN_LEFT);
		txt_213_p3->when(FL_WHEN_RELEASE);

	tab_213_originator->end();

	tab_213_responder = new Fl_Group(0, Y+25, 570, 360, _("Responder"));
	tab_213_responder->hide();

		txt_213_d2 = new Fl_DateInput(240, Y+42, 126, 24, _("Date"));
		txt_213_d2->tooltip(_("Reply Date"));
		txt_213_d2->box(FL_DOWN_BOX);
		txt_213_d2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_d2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_d2->labeltype(FL_NORMAL_LABEL);
		txt_213_d2->labelfont(0);
		txt_213_d2->labelsize(14);
		txt_213_d2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_d2->align(FL_ALIGN_LEFT);
		txt_213_d2->when(FL_WHEN_RELEASE);

		btn_213_date2 = new Fl_Button(367, Y+44, 20, 20, _("..."));
		btn_213_date2->tooltip(_("Today"));
		btn_213_date2->callback((Fl_Callback*)cb_btn_213_date2);

		txt_213_t2 = new Fl_Input2(434, Y+42, 103, 24, _("Time"));
		txt_213_t2->tooltip(_("Reply Time"));
		txt_213_t2->box(FL_DOWN_BOX);
		txt_213_t2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_t2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_t2->labeltype(FL_NORMAL_LABEL);
		txt_213_t2->labelfont(0);
		txt_213_t2->labelsize(14);
		txt_213_t2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_t2->align(FL_ALIGN_LEFT);
		txt_213_t2->when(FL_WHEN_RELEASE);

		btn_213_time2 = new Fl_Button(540, Y+44, 20, 20, _("..."));
		btn_213_time2->tooltip(_("Now"));
		btn_213_time2->callback((Fl_Callback*)cb_btn_213_time2);

		txt_213_reply = new FTextEdit(5, Y+72, 562, 275, _("Reply"));
		txt_213_reply->box(FL_DOWN_FRAME);
		txt_213_reply->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_reply->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_reply->labeltype(FL_NORMAL_LABEL);
		txt_213_reply->labelfont(0);
		txt_213_reply->labelsize(14);
		txt_213_reply->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_reply->align(FL_ALIGN_TOP_LEFT);
		txt_213_reply->when(FL_WHEN_RELEASE);

		txt_213_s2 = new Fl_Input2(37, Y+351, 248, 24, _("Sig."));
		txt_213_s2->tooltip(_("Signature of responder"));
		txt_213_s2->box(FL_DOWN_BOX);
		txt_213_s2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_s2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_s2->labeltype(FL_NORMAL_LABEL);
		txt_213_s2->labelfont(0);
		txt_213_s2->labelsize(14);
		txt_213_s2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_s2->align(FL_ALIGN_LEFT);
		txt_213_s2->when(FL_WHEN_RELEASE);

		txt_213_p4 = new Fl_Input2(323, Y+351, 242, 24, _("Pos."));
		txt_213_p4->tooltip(_("Position of responder"));
		txt_213_p4->box(FL_DOWN_BOX);
		txt_213_p4->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_213_p4->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_213_p4->labeltype(FL_NORMAL_LABEL);
		txt_213_p4->labelfont(0);
		txt_213_p4->labelsize(14);
		txt_213_p4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_213_p4->align(FL_ALIGN_LEFT);
		txt_213_p4->when(FL_WHEN_RELEASE);

	tab_213_responder->end();
	Fl_Group::current()->resizable(tab_213_responder);

	tab_ics213_type->end();
	Fl_Group::current()->resizable(tab_ics213_type);

	tab_ics213->end();

	tab_ics213->hide();
}
