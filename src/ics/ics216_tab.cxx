//======================================================================
// ICS 216 tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_ics216 = (Fl_Group *)0;
Fl_Group	*tab_ics_216 = (Fl_Group *)0;
Fl_Tabs		*tab_ics216_type = (Fl_Tabs *)0;
Fl_Group	*tab_216_1 = (Fl_Group *)0;
Fl_Group	*tab_216_2 = (Fl_Group *)0;
Fl_Group	*tab_216_3 = (Fl_Group *)0;
Fl_Group	*tab_216_4 = (Fl_Group *)0;
Fl_Group	*tab_216_5 = (Fl_Group *)0;
Fl_Input2	*txt_216_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_216_date = (Fl_Input2 *)0;
Fl_Button	*btn_216_date = (Fl_Button *)0;
Fl_Input2	*txt_216_time = (Fl_Input2 *)0;
Fl_Button	*btn_216_time = (Fl_Button *)0;
Fl_Input2	*txt_216_branch = (Fl_Input2 *)0;
Fl_Input2	*txt_216_agc = (Fl_Input2 *)0;
Fl_Input2	*txt_216_op_period = (Fl_Input2 *)0;
Fl_Input2	*txt_216_tac_freq = (Fl_Input2 *)0;
Fl_Input2	*txt_216_prepared_by = (Fl_Input2 *)0;
Fl_Input2	*txt_216_div_grp[4]={(Fl_Input2 *)0};
Fl_Input2	*txt_216_agency[4]={(Fl_Input2 *)0};
Fl_Input2	*txt_216_ag[36]={(Fl_Input2 *)0};
Fl_Input2	*txt_216_id[36]={(Fl_Input2 *)0};
Fl_Input2	*txt_216_rr[36]={(Fl_Input2 *)0};

static void cb_btn_216_date(Fl_Button*, void*) {
  cb_216_set_date();
}

static void cb_btn_216_time(Fl_Button*, void*) {
  cb_216_set_time();
}

void create_ics216_tab()
{
tab_ics216 = new Fl_Group(0, 70, 570, 355, _("216"));
tab_ics216->align(FL_ALIGN_TOP_LEFT);
tab_ics216->hide();

	tab_ics216_type = new Fl_Tabs(0, 72, 570, 352);
	tab_ics216_type->align(FL_ALIGN_TOP_LEFT);

		tab_216_1 = new Fl_Group(0, 95, 570, 325, _("Incident"));
			{
			Fl_Group* o = new Fl_Group(2, 102, 566, 190);
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_216_incident = new Fl_Input2(135, 108, 425, 24, _("1.Incident Name"));
			txt_216_incident->tooltip(_("Incident name"));
			txt_216_incident->box(FL_DOWN_BOX);
			txt_216_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_incident->labeltype(FL_NORMAL_LABEL);
			txt_216_incident->labelfont(0);
			txt_216_incident->labelsize(14);
			txt_216_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_incident->align(FL_ALIGN_LEFT);
			txt_216_incident->when(FL_WHEN_RELEASE);

			txt_216_date = new Fl_Input2(135, 135, 155, 24, _("2. Date"));
			txt_216_date->tooltip(_("Date"));
			txt_216_date->box(FL_DOWN_BOX);
			txt_216_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_date->labeltype(FL_NORMAL_LABEL);
			txt_216_date->labelfont(0);
			txt_216_date->labelsize(14);
			txt_216_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_date->align(FL_ALIGN_LEFT);
			txt_216_date->when(FL_WHEN_RELEASE);

			btn_216_date = new Fl_Button(294, 137, 20, 20, _("..."));
			btn_216_date->tooltip(_("Set today"));
			btn_216_date->callback((Fl_Callback*)cb_btn_216_date);

			txt_216_time = new Fl_Input2(135, 160, 103, 24, _("3. Time"));
			txt_216_time->tooltip(_("Time prepared"));
			txt_216_time->box(FL_DOWN_BOX);
			txt_216_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_time->labeltype(FL_NORMAL_LABEL);
			txt_216_time->labelfont(0);
			txt_216_time->labelsize(14);
			txt_216_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_time->align(FL_ALIGN_LEFT);
			txt_216_time->when(FL_WHEN_RELEASE);

			btn_216_time = new Fl_Button(247, 162, 20, 20, _("..."));
			btn_216_time->tooltip(_("Set time now"));
			btn_216_time->callback((Fl_Callback*)cb_btn_216_time);

			txt_216_branch = new Fl_Input2(135, 185, 425, 24, _("4. Branch"));
			txt_216_branch->tooltip(_("branch"));
			txt_216_branch->box(FL_DOWN_BOX);
			txt_216_branch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_branch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_branch->labeltype(FL_NORMAL_LABEL);
			txt_216_branch->labelfont(0);
			txt_216_branch->labelsize(14);
			txt_216_branch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_branch->align(FL_ALIGN_LEFT);
			txt_216_branch->when(FL_WHEN_RELEASE);

			txt_216_agc = new Fl_Input2(135, 210, 425, 24, _("5. Agency"));
			txt_216_agc->tooltip(_("agency name"));
			txt_216_agc->box(FL_DOWN_BOX);
			txt_216_agc->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_agc->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_agc->labeltype(FL_NORMAL_LABEL);
			txt_216_agc->labelfont(0);
			txt_216_agc->labelsize(14);
			txt_216_agc->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_agc->align(FL_ALIGN_LEFT);
			txt_216_agc->when(FL_WHEN_RELEASE);

			txt_216_op_period = new Fl_Input2(135, 235, 425, 24, _("6. Oper\' Period"));
			txt_216_op_period->tooltip(_("Date / Time"));
			txt_216_op_period->box(FL_DOWN_BOX);
			txt_216_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_op_period->labeltype(FL_NORMAL_LABEL);
			txt_216_op_period->labelfont(0);
			txt_216_op_period->labelsize(14);
			txt_216_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_op_period->align(FL_ALIGN_LEFT);
			txt_216_op_period->when(FL_WHEN_RELEASE);

			txt_216_tac_freq = new Fl_Input2(135, 260, 425, 24, _("7. Tac\' Freq\'"));
			txt_216_tac_freq->tooltip(_("tactical frequency"));
			txt_216_tac_freq->box(FL_DOWN_BOX);
			txt_216_tac_freq->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_tac_freq->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_tac_freq->labeltype(FL_NORMAL_LABEL);
			txt_216_tac_freq->labelfont(0);
			txt_216_tac_freq->labelsize(14);
			txt_216_tac_freq->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_tac_freq->align(FL_ALIGN_LEFT);
			txt_216_tac_freq->when(FL_WHEN_RELEASE);

			o->end();
			}

			{
			Fl_Group* o = new Fl_Group(2, 294, 566, 35);
			o->box(FL_ENGRAVED_FRAME);
				
			txt_216_prepared_by = new Fl_Input2(135, 296, 425, 24, _("Prepared By"));
			txt_216_prepared_by->tooltip(_("Name and Position"));
			txt_216_prepared_by->box(FL_DOWN_BOX);
			txt_216_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_prepared_by->labeltype(FL_NORMAL_LABEL);
			txt_216_prepared_by->labelfont(0);
			txt_216_prepared_by->labelsize(14);
			txt_216_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_prepared_by->align(FL_ALIGN_LEFT);
			txt_216_prepared_by->when(FL_WHEN_RELEASE);

			o->end();
			}
		tab_216_1->end();

		tab_216_2 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 1"));
		tab_216_2->hide();
		int y = 105;

			txt_216_div_grp[0] = new Fl_Input2(120, y, 448, 24, _("Division/Group") );
			txt_216_div_grp[0]->tooltip(_(""));
			txt_216_div_grp[0]->box(FL_DOWN_BOX);
			txt_216_div_grp[0]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_div_grp[0]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_div_grp[0]->labeltype(FL_NORMAL_LABEL);
			txt_216_div_grp[0]->labelfont(0);
			txt_216_div_grp[0]->labelsize(14);
			txt_216_div_grp[0]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_div_grp[0]->align(FL_ALIGN_LEFT);
			txt_216_div_grp[0]->when(FL_WHEN_RELEASE);
			y += 24;

			txt_216_agency[0] = new Fl_Input2(120, y, 448, 24, _("Agency") );
			txt_216_agency[0]->tooltip(_(""));
			txt_216_agency[0]->box(FL_DOWN_BOX);
			txt_216_agency[0]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_agency[0]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_agency[0]->labeltype(FL_NORMAL_LABEL);
			txt_216_agency[0]->labelfont(0);
			txt_216_agency[0]->labelsize(14);
			txt_216_agency[0]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_agency[0]->align(FL_ALIGN_LEFT);
			txt_216_agency[0]->when(FL_WHEN_RELEASE);
			y += 48;

			for (int i = 0, j = 0; i < 9; i++, j++) {
				txt_216_ag[j] = new Fl_Input2(5, y, 180, 24, i == 0 ? "Agency" : "");
				txt_216_ag[j]->tooltip(_(""));
				txt_216_ag[j]->box(FL_DOWN_BOX);
				txt_216_ag[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_ag[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_ag[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_ag[j]->labelfont(0);
				txt_216_ag[j]->labelsize(14);
				txt_216_ag[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_ag[j]->align(FL_ALIGN_TOP);
				txt_216_ag[j]->when(FL_WHEN_RELEASE);

				txt_216_id[j] = new Fl_Input2(186, y, 100, 24, i == 0 ? "ID No." : "");
				txt_216_id[j]->tooltip(_(""));
				txt_216_id[j]->box(FL_DOWN_BOX);
				txt_216_id[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_id[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_id[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_id[j]->labelfont(0);
				txt_216_id[j]->labelsize(14);
				txt_216_id[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_id[j]->align(FL_ALIGN_TOP);
				txt_216_id[j]->when(FL_WHEN_RELEASE);

				txt_216_rr[j] = new Fl_Input2(287, y, 280, 24, i == 0 ? "Radio Requirements" : "");
				txt_216_rr[j]->tooltip(_(""));
				txt_216_rr[j]->box(FL_DOWN_BOX);
				txt_216_rr[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_rr[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_rr[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_rr[j]->labelfont(0);
				txt_216_rr[j]->labelsize(14);
				txt_216_rr[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_rr[j]->align(FL_ALIGN_TOP);
				txt_216_rr[j]->when(FL_WHEN_RELEASE);
				y += 24;
			}
		tab_216_2->end();

		tab_216_3 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 2"));
		tab_216_3->hide();
		y = 105;

			txt_216_div_grp[1] = new Fl_Input2(120, y, 448, 24, _("Division/Group") );
			txt_216_div_grp[1]->tooltip(_(""));
			txt_216_div_grp[1]->box(FL_DOWN_BOX);
			txt_216_div_grp[1]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_div_grp[1]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_div_grp[1]->labeltype(FL_NORMAL_LABEL);
			txt_216_div_grp[1]->labelfont(0);
			txt_216_div_grp[1]->labelsize(14);
			txt_216_div_grp[1]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_div_grp[1]->align(FL_ALIGN_LEFT);
			txt_216_div_grp[1]->when(FL_WHEN_RELEASE);
			y += 24;

			txt_216_agency[1] = new Fl_Input2(120, y, 448, 24, _("Agency") );
			txt_216_agency[1]->tooltip(_(""));
			txt_216_agency[1]->box(FL_DOWN_BOX);
			txt_216_agency[1]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_agency[1]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_agency[1]->labeltype(FL_NORMAL_LABEL);
			txt_216_agency[1]->labelfont(0);
			txt_216_agency[1]->labelsize(14);
			txt_216_agency[1]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_agency[1]->align(FL_ALIGN_LEFT);
			txt_216_agency[1]->when(FL_WHEN_RELEASE);
			y += 48;

			for (int i = 0, j = 9; i < 9; i++, j++) {
				txt_216_ag[j] = new Fl_Input2(5, y, 180, 24, i == 0 ? "Agency" : "");
				txt_216_ag[j]->tooltip(_(""));
				txt_216_ag[j]->box(FL_DOWN_BOX);
				txt_216_ag[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_ag[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_ag[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_ag[j]->labelfont(0);
				txt_216_ag[j]->labelsize(14);
				txt_216_ag[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_ag[j]->align(FL_ALIGN_TOP);
				txt_216_ag[j]->when(FL_WHEN_RELEASE);

				txt_216_id[j] = new Fl_Input2(186, y, 100, 24, i == 0 ? "ID No." : "");
				txt_216_id[j]->tooltip(_(""));
				txt_216_id[j]->box(FL_DOWN_BOX);
				txt_216_id[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_id[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_id[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_id[j]->labelfont(0);
				txt_216_id[j]->labelsize(14);
				txt_216_id[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_id[j]->align(FL_ALIGN_TOP);
				txt_216_id[j]->when(FL_WHEN_RELEASE);

				txt_216_rr[j] = new Fl_Input2(287, y, 280, 24, i == 0 ? "Radio Requirements" : "");
				txt_216_rr[j]->tooltip(_(""));
				txt_216_rr[j]->box(FL_DOWN_BOX);
				txt_216_rr[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_rr[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_rr[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_rr[j]->labelfont(0);
				txt_216_rr[j]->labelsize(14);
				txt_216_rr[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_rr[j]->align(FL_ALIGN_TOP);
				txt_216_rr[j]->when(FL_WHEN_RELEASE);
				y += 24;
			}
		tab_216_3->end();

		tab_216_4 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 3"));
		tab_216_4->hide();
		y = 105;

			txt_216_div_grp[2] = new Fl_Input2(120, y, 448, 24, _("Division/Group") );
			txt_216_div_grp[2]->tooltip(_(""));
			txt_216_div_grp[2]->box(FL_DOWN_BOX);
			txt_216_div_grp[2]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_div_grp[2]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_div_grp[2]->labeltype(FL_NORMAL_LABEL);
			txt_216_div_grp[2]->labelfont(0);
			txt_216_div_grp[2]->labelsize(14);
			txt_216_div_grp[2]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_div_grp[2]->align(FL_ALIGN_LEFT);
			txt_216_div_grp[2]->when(FL_WHEN_RELEASE);
			y += 24;

			txt_216_agency[2] = new Fl_Input2(120, y, 448, 24, _("Agency") );
			txt_216_agency[2]->tooltip(_(""));
			txt_216_agency[2]->box(FL_DOWN_BOX);
			txt_216_agency[2]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_agency[2]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_agency[2]->labeltype(FL_NORMAL_LABEL);
			txt_216_agency[2]->labelfont(0);
			txt_216_agency[2]->labelsize(14);
			txt_216_agency[2]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_agency[2]->align(FL_ALIGN_LEFT);
			txt_216_agency[2]->when(FL_WHEN_RELEASE);
			y += 48;

			for (int i = 0, j = 18; i < 9; i++, j++) {
				txt_216_ag[j] = new Fl_Input2(5, y, 180, 24, i == 0 ? "Agency" : "");
				txt_216_ag[j]->tooltip(_(""));
				txt_216_ag[j]->box(FL_DOWN_BOX);
				txt_216_ag[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_ag[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_ag[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_ag[j]->labelfont(0);
				txt_216_ag[j]->labelsize(14);
				txt_216_ag[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_ag[j]->align(FL_ALIGN_TOP);
				txt_216_ag[j]->when(FL_WHEN_RELEASE);

				txt_216_id[j] = new Fl_Input2(186, y, 100, 24, i == 0 ? "ID No." : "");
				txt_216_id[j]->tooltip(_(""));
				txt_216_id[j]->box(FL_DOWN_BOX);
				txt_216_id[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_id[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_id[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_id[j]->labelfont(0);
				txt_216_id[j]->labelsize(14);
				txt_216_id[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_id[j]->align(FL_ALIGN_TOP);
				txt_216_id[j]->when(FL_WHEN_RELEASE);

				txt_216_rr[j] = new Fl_Input2(287, y, 280, 24, i == 0 ? "Radio Requirements" : "");
				txt_216_rr[j]->tooltip(_(""));
				txt_216_rr[j]->box(FL_DOWN_BOX);
				txt_216_rr[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_rr[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_rr[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_rr[j]->labelfont(0);
				txt_216_rr[j]->labelsize(14);
				txt_216_rr[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_rr[j]->align(FL_ALIGN_TOP);
				txt_216_rr[j]->when(FL_WHEN_RELEASE);
				y += 24;
			}
		tab_216_4->end();

		tab_216_5 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 4"));
			tab_216_5->hide();
			y = 105;

			txt_216_div_grp[3] = new Fl_Input2(120, y, 448, 24, _("Division/Group") );
			txt_216_div_grp[3]->tooltip(_(""));
			txt_216_div_grp[3]->box(FL_DOWN_BOX);
			txt_216_div_grp[3]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_div_grp[3]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_div_grp[3]->labeltype(FL_NORMAL_LABEL);
			txt_216_div_grp[3]->labelfont(0);
			txt_216_div_grp[3]->labelsize(14);
			txt_216_div_grp[3]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_div_grp[3]->align(FL_ALIGN_LEFT);
			txt_216_div_grp[3]->when(FL_WHEN_RELEASE);
			y += 24;

			txt_216_agency[3] = new Fl_Input2(120, y, 448, 24, _("Agency") );
			txt_216_agency[3]->tooltip(_(""));
			txt_216_agency[3]->box(FL_DOWN_BOX);
			txt_216_agency[3]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_216_agency[3]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_216_agency[3]->labeltype(FL_NORMAL_LABEL);
			txt_216_agency[3]->labelfont(0);
			txt_216_agency[3]->labelsize(14);
			txt_216_agency[3]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_216_agency[3]->align(FL_ALIGN_LEFT);
			txt_216_agency[3]->when(FL_WHEN_RELEASE);
			y += 48;

			for (int i = 0, j = 27; i < 9; i++, j++) {
				txt_216_ag[j] = new Fl_Input2(5, y, 180, 24, i == 0 ? "Agency" : "");
				txt_216_ag[j]->tooltip(_(""));
				txt_216_ag[j]->box(FL_DOWN_BOX);
				txt_216_ag[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_ag[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_ag[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_ag[j]->labelfont(0);
				txt_216_ag[j]->labelsize(14);
				txt_216_ag[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_ag[j]->align(FL_ALIGN_TOP);
				txt_216_ag[j]->when(FL_WHEN_RELEASE);

				txt_216_id[j] = new Fl_Input2(186, y, 100, 24, i == 0 ? "ID No." : "");
				txt_216_id[j]->tooltip(_(""));
				txt_216_id[j]->box(FL_DOWN_BOX);
				txt_216_id[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_id[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_id[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_id[j]->labelfont(0);
				txt_216_id[j]->labelsize(14);
				txt_216_id[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_id[j]->align(FL_ALIGN_TOP);
				txt_216_id[j]->when(FL_WHEN_RELEASE);

				txt_216_rr[j] = new Fl_Input2(287, y, 280, 24, i == 0 ? "Radio Requirements" : "");
				txt_216_rr[j]->tooltip(_(""));
				txt_216_rr[j]->box(FL_DOWN_BOX);
				txt_216_rr[j]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_216_rr[j]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_216_rr[j]->labeltype(FL_NORMAL_LABEL);
				txt_216_rr[j]->labelfont(0);
				txt_216_rr[j]->labelsize(14);
				txt_216_rr[j]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_216_rr[j]->align(FL_ALIGN_TOP);
				txt_216_rr[j]->when(FL_WHEN_RELEASE);
				y += 24;
			}
		tab_216_5->end();

	tab_ics216_type->end();

tab_ics216->end();
}