//======================================================================
// Plaintext tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_plaintext = (Fl_Group *)0;
Fl_Input2	*txt_pt_title = (Fl_Input2 *)0;
Fl_Input2	*txt_pt_to = (Fl_Input2 *)0;
Fl_Input2	*txt_pt_fm = (Fl_Input2 *)0;
Fl_Input2	*txt_pt_subj = (Fl_Input2 *)0;
FTextEdit	*txt_pt_msg = (FTextEdit *)0;
Fl_DateInput	*txt_pt_date = (Fl_DateInput *)0;
Fl_Button	*btn_pt_date = (Fl_Button *)0;
Fl_Input2	*txt_pt_time = (Fl_Input2 *)0;
Fl_Button	*btn_pt_time = (Fl_Button *)0;

static void cb_btn_pt_date(Fl_Button*, void*) {
  cb_set_pt_date();
}

static void cb_btn_pt_time(Fl_Button*, void*) {
  cb_set_pt_time();
}

void create_plaintext_tab()
{
tab_plaintext = new Fl_Group(0, 45, 570, 380, _("Generic"));
tab_plaintext->hide();
	txt_pt_title = new Fl_Input2(41, 53, 525, 24, _("Title"));
	txt_pt_title->tooltip(_("Addressee"));
	txt_pt_title->box(FL_DOWN_BOX);
	txt_pt_title->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_pt_title->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_pt_title->labeltype(FL_NORMAL_LABEL);
	txt_pt_title->labelfont(0);
	txt_pt_title->labelsize(14);
	txt_pt_title->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_pt_title->align(FL_ALIGN_LEFT);
	txt_pt_title->when(FL_WHEN_RELEASE);

	txt_pt_to = new Fl_Input2(42, 80, 320, 24, _("To"));
	txt_pt_to->tooltip(_("Addressee"));
	txt_pt_to->box(FL_DOWN_BOX);
	txt_pt_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_pt_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_pt_to->labeltype(FL_NORMAL_LABEL);
	txt_pt_to->labelfont(0);
	txt_pt_to->labelsize(14);
	txt_pt_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_pt_to->align(FL_ALIGN_LEFT);
	txt_pt_to->when(FL_WHEN_RELEASE);

	txt_pt_fm = new Fl_Input2(42, 107, 320, 24, _("Fm"));
	txt_pt_fm->tooltip(_("Originator"));
	txt_pt_fm->box(FL_DOWN_BOX);
	txt_pt_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_pt_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_pt_fm->labeltype(FL_NORMAL_LABEL);
	txt_pt_fm->labelfont(0);
	txt_pt_fm->labelsize(14);
	txt_pt_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_pt_fm->align(FL_ALIGN_LEFT);
	txt_pt_fm->when(FL_WHEN_RELEASE);

	txt_pt_subj = new Fl_Input2(42, 135, 525, 24, _("Sub."));
	txt_pt_subj->tooltip(_("Subject"));
	txt_pt_subj->box(FL_DOWN_BOX);
	txt_pt_subj->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_pt_subj->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_pt_subj->labeltype(FL_NORMAL_LABEL);
	txt_pt_subj->labelfont(0);
	txt_pt_subj->labelsize(14);
	txt_pt_subj->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_pt_subj->align(FL_ALIGN_LEFT);
	txt_pt_subj->when(FL_WHEN_RELEASE);

	txt_pt_msg = new FTextEdit(4, 177, 562, 245, _("Message:"));
	txt_pt_msg->box(FL_DOWN_FRAME);
	txt_pt_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_pt_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_pt_msg->labeltype(FL_NORMAL_LABEL);
	txt_pt_msg->labelfont(0);
	txt_pt_msg->labelsize(14);
	txt_pt_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_pt_msg->align(FL_ALIGN_TOP_LEFT);
	txt_pt_msg->when(FL_WHEN_RELEASE);
	Fl_Group::current()->resizable(txt_pt_msg);

	txt_pt_date = new Fl_DateInput(404, 81, 125, 24, _("Date"));
	txt_pt_date->tooltip(_("Date of origination"));
	txt_pt_date->box(FL_DOWN_BOX);
	txt_pt_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_pt_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_pt_date->labeltype(FL_NORMAL_LABEL);
	txt_pt_date->labelfont(0);
	txt_pt_date->labelsize(14);
	txt_pt_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_pt_date->align(FL_ALIGN_LEFT);
	txt_pt_date->when(FL_WHEN_RELEASE);

	btn_pt_date = new Fl_Button(537, 83, 20, 20, _("..."));
	btn_pt_date->tooltip(_("Set today"));
	btn_pt_date->callback((Fl_Callback*)cb_btn_pt_date);

	txt_pt_time = new Fl_Input2(404, 107, 125, 24, _("Time"));
	txt_pt_time->tooltip(_("Time of origination"));
	txt_pt_time->box(FL_DOWN_BOX);
	txt_pt_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_pt_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_pt_time->labeltype(FL_NORMAL_LABEL);
	txt_pt_time->labelfont(0);
	txt_pt_time->labelsize(14);
	txt_pt_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_pt_time->align(FL_ALIGN_LEFT);
	txt_pt_time->when(FL_WHEN_RELEASE);

	btn_pt_time = new Fl_Button(537, 109, 20, 20, _("..."));
	btn_pt_time->tooltip(_("Set time now"));
	btn_pt_time->callback((Fl_Callback*)cb_btn_pt_time);

tab_plaintext->end();
}
