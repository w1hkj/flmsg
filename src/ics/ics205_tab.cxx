//======================================================================
// ICS 205 tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_ics205 = (Fl_Group *)0;
Fl_Input2	*txt_205_name = (Fl_Input2 *)0;
Fl_Input2	*txt_205_dt_prepared = (Fl_Input2 *)0;
Fl_Button	*btn_205_dt_prepared = (Fl_Button *)0;

Fl_Input2	*txt_205_dt_op_from = (Fl_Input2 *)0;
Fl_Button	*btn_205_dt_op_from = (Fl_Button *)0;

Fl_Input2	*txt_205_dt_op_to = (Fl_Input2 *)0;
Fl_Button	*btn_205_dt_op_to = (Fl_Button *)0;

Fl_Input2	*txt_205_type[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_channel[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_function[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_freqtone[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_assignment[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_remarks[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_preparer = (Fl_Input2 *)0;

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

	{
	Fl_Group* o = new Fl_Group(2, Y+6, 566, 92);
	o->box(FL_ENGRAVED_FRAME);

	txt_205_name = new Fl_Input2(113, Y+10, 450, 24, _("Incident Name"));
	txt_205_name->tooltip(_(""));
	txt_205_name->box(FL_DOWN_BOX);
	txt_205_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_name->labeltype(FL_NORMAL_LABEL);
	txt_205_name->labelfont(0);
	txt_205_name->labelsize(14);
	txt_205_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_name->align(FL_ALIGN_LEFT);
	txt_205_name->when(FL_WHEN_RELEASE);

	txt_205_dt_prepared = new Fl_Input2(97, Y+42, 155, 24, _("DT/TM Prep\'"));
	txt_205_dt_prepared->tooltip(_("ddhhmm MMM YY of preparation"));
	txt_205_dt_prepared->box(FL_DOWN_BOX);
	txt_205_dt_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_prepared->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_prepared->labelfont(0);
	txt_205_dt_prepared->labelsize(14);
	txt_205_dt_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_prepared->align(FL_ALIGN_LEFT);
	txt_205_dt_prepared->when(FL_WHEN_RELEASE);

	btn_205_dt_prepared = new Fl_Button(254, Y+42, 24, 24, _("..."));
	btn_205_dt_prepared->tooltip(_("Set today"));
	btn_205_dt_prepared->callback((Fl_Callback*)cb_btn_205_dt_prepared);

	txt_205_dt_op_from = new Fl_Input2(378, Y+42, 155, 24, _("D/T from\'"));
	txt_205_dt_op_from->tooltip(_("Operational period from: ddhhmm MMM YY"));
	txt_205_dt_op_from->box(FL_DOWN_BOX);
	txt_205_dt_op_from->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_op_from->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_op_from->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_op_from->labelfont(0);
	txt_205_dt_op_from->labelsize(14);
	txt_205_dt_op_from->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_op_from->align(FL_ALIGN_LEFT);
	txt_205_dt_op_from->when(FL_WHEN_RELEASE);

	btn_205_dt_op_from = new Fl_Button(536, Y+42, 24, 24, _("..."));
	btn_205_dt_op_from->tooltip(_("Set today"));
	btn_205_dt_op_from->callback((Fl_Callback*)cb_btn_205_dt_op_from);

	txt_205_dt_op_to = new Fl_Input2(378, Y+68, 155, 24, _("D/T to"));
	txt_205_dt_op_to->tooltip(_("Operational period to: ddhhmm MMM YY"));
	txt_205_dt_op_to->box(FL_DOWN_BOX);
	txt_205_dt_op_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_op_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_op_to->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_op_to->labelfont(0);
	txt_205_dt_op_to->labelsize(14);
	txt_205_dt_op_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_op_to->align(FL_ALIGN_LEFT);
	txt_205_dt_op_to->when(FL_WHEN_RELEASE);

	btn_205_dt_op_to = new Fl_Button(536, Y+68, 24, 24, _("..."));
	btn_205_dt_op_to->tooltip(_("Set today"));
	btn_205_dt_op_to->callback((Fl_Callback*)cb_btn_205_dt_op_to);

	o->end();
	} // Fl_Group* o

	{
	Fl_Group* o = new Fl_Group(2, Y+100, 566, 245);
	o->box(FL_ENGRAVED_FRAME);
	for (int i = 0; i < 8; i++ ) {
		txt_205_type[i] = new Fl_Input2(5, Y+120 + i*28, 90, 24, i == 0 ? _("Sys\' / Cache"):"");
		txt_205_type[i]->tooltip(_(""));
		txt_205_type[i]->box(FL_DOWN_BOX);
		txt_205_type[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_type[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_type[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_type[i]->labelfont(0);
		txt_205_type[i]->labelsize(14);
		txt_205_type[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_type[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_type[i]->when(FL_WHEN_RELEASE);

		txt_205_channel[i] = new Fl_Input2(97, Y+120 + i*28, 63, 24, i == 0 ? _("Channel"):"");
		txt_205_channel[i]->tooltip(_(""));
		txt_205_channel[i]->box(FL_DOWN_BOX);
		txt_205_channel[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_channel[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_channel[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_channel[i]->labelfont(0);
		txt_205_channel[i]->labelsize(14);
		txt_205_channel[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_channel[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_channel[i]->when(FL_WHEN_RELEASE);

		txt_205_function[i] = new Fl_Input2(164, Y+120 + i*28, 80, 24, i == 0 ?_("Function"):"");
		txt_205_function[i]->tooltip(_(""));
		txt_205_function[i]->box(FL_DOWN_BOX);
		txt_205_function[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_function[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_function[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_function[i]->labelfont(0);
		txt_205_function[i]->labelsize(14);
		txt_205_function[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_function[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_function[i]->when(FL_WHEN_RELEASE);

		txt_205_freqtone[i] = new Fl_Input2(247, Y+120 + i*28, 80, 24, i == 0 ? _("Freq/Tone"):"");
		txt_205_freqtone[i]->tooltip(_(""));
		txt_205_freqtone[i]->box(FL_DOWN_BOX);
		txt_205_freqtone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_freqtone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_freqtone[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_freqtone[i]->labelfont(0);
		txt_205_freqtone[i]->labelsize(14);
		txt_205_freqtone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_freqtone[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_freqtone[i]->when(FL_WHEN_RELEASE);

		txt_205_assignment[i] = new Fl_Input2(330, Y+120 + i*28, 90, 24, i == 0 ? _("Assignment"):"");
		txt_205_assignment[i]->tooltip(_(""));
		txt_205_assignment[i]->box(FL_DOWN_BOX);
		txt_205_assignment[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_assignment[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_assignment[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_assignment[i]->labelfont(0);
		txt_205_assignment[i]->labelsize(14);
		txt_205_assignment[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_assignment[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_assignment[i]->when(FL_WHEN_RELEASE);

		txt_205_remarks[i] = new Fl_Input2(422, Y+120 + i*28, 140, 24, i == 0 ? _("Remarks"):"");
		txt_205_remarks[i]->tooltip(_(""));
		txt_205_remarks[i]->box(FL_DOWN_BOX);
		txt_205_remarks[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_remarks[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_remarks[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_remarks[i]->labelfont(0);
		txt_205_remarks[i]->labelsize(14);
		txt_205_remarks[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_remarks[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_remarks[i]->when(FL_WHEN_RELEASE);
	}
	o->end();
	} // Fl_Group* o

	{
	Fl_Group* o = new Fl_Group(2, Y+347, 566, 30);
	o->box(FL_ENGRAVED_BOX);
	txt_205_preparer = new Fl_Input2(77, Y+349, 485, 24, _("Preparer:"));
	txt_205_preparer->tooltip(_("Addressee"));
	txt_205_preparer->box(FL_DOWN_BOX);
	txt_205_preparer->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_preparer->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_preparer->labeltype(FL_NORMAL_LABEL);
	txt_205_preparer->labelfont(0);
	txt_205_preparer->labelsize(14);
	txt_205_preparer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_preparer->align(FL_ALIGN_LEFT);
	txt_205_preparer->when(FL_WHEN_RELEASE);
	o->end();
	} // Fl_Group* o
	tab_ics205->end();

	tab_ics205->hide();
}
