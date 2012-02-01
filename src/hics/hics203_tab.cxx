//======================================================================
// HICS 203 tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_hics203 = (Fl_Group *)0;

Fl_Tabs		*tab_hics203_type = (Fl_Tabs *)0;

Fl_Group	*tab_hics203_1 = (Fl_Group *)0;
Fl_Input2	*txt_hics203_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_date = (Fl_Input2 *)0;
Fl_Button	*btn_hics203_date = (Fl_Button *)0;
Fl_Input2	*txt_hics203_time = (Fl_Input2 *)0;
Fl_Button	*btn_hics203_time = (Fl_Button *)0;
Fl_Input2	*txt_hics203_op_period = (Fl_Input2 *)0;

Fl_Input2	*txt_hics203_incident_commander = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_incident_safety_officer = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_incident_info_officer = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_liaison_officer = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_prepared_by = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_facility = (Fl_Input2 *)0;

Fl_Group	*tab_hics203_tech_spec = (Fl_Group *)0;
Fl_Input2	*txt_hics203_tech_spc[6]={(Fl_Input2 *)0};

Fl_Group	*tab_hics203_planning = (Fl_Group *)0;
Fl_Input2	*txt_hics203_planning_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_planning_other = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_res_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_sit_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_doc_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_dem_unit = (Fl_Input2 *)0;

Fl_Group	*tab_hics203_logisthics = (Fl_Group *)0;
Fl_Input2	*txt_hics203_log_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_log_other = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_log_sup_brch = (Fl_Input2 *)0;

Fl_Group	*tab_hics203_ops = (Fl_Group *)0;
Fl_Input2	*txt_hics203_ops_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_bus_brch = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_stg_mgr = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_med_care_brch = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_infr_brch = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_sec_brch = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_hazmat_brch = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_ops_other = (Fl_Input2 *)0;

Fl_Input2	*txt_hics203_hcc_agency = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_svc_brch = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_hcc_rep = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_ext_loc = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_ext_rep = (Fl_Input2 *)0;

Fl_Group	*tab_hics203_admin = (Fl_Group *)0;
Fl_Input2	*txt_hics203_fin_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_fin_other = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_time_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_proc_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_comp_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_hics203_cost_unit = (Fl_Input2 *)0;

static void cb_btn_hics203_date(Fl_Button*, void*) {
  cb_hics203_set_date();
}

static void cb_btn_hics203_time(Fl_Button*, void*) {
  cb_hics203_set_time();
}

void create_hics203_tab()
{
	tab_hics203 = new Fl_Group(0, 70, 570, 355, _("203"));
	tab_hics203->align(FL_ALIGN_TOP_LEFT);
	tab_hics203_type = new Fl_Tabs(0, 73, 570, 352);
	tab_hics203_type->selection_color((Fl_Color)246);
	tab_hics203_type->align(FL_ALIGN_TOP_LEFT);
		{ // tab_hics203_orglist
		tab_hics203_1 = new Fl_Group(0, 95, 570, 325, _("Org"));
			{ // group_hics203_orglist_1
			Fl_Group* group_hics203_orglist_1 = new Fl_Group(2, 101, 566, 115);
			group_hics203_orglist_1->box(FL_ENGRAVED_FRAME);
			group_hics203_orglist_1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
			{	txt_hics203_incident = new Fl_Input2(135, 106, 425, 24, _("1. Incident Name"));
				txt_hics203_incident->tooltip(_("Incident name"));
				txt_hics203_incident->box(FL_DOWN_BOX);
				txt_hics203_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_incident->labeltype(FL_NORMAL_LABEL);
				txt_hics203_incident->labelfont(0);
				txt_hics203_incident->labelsize(14);
				txt_hics203_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_incident->align(FL_ALIGN_LEFT);
				txt_hics203_incident->when(FL_WHEN_RELEASE);
			} // Fl_Input2* txt_hics203_incident
			{	txt_hics203_date = new Fl_Input2(135, 132, 155, 24, _("2. Date Prepared"));
				txt_hics203_date->tooltip(_("Date prepared"));
				txt_hics203_date->box(FL_DOWN_BOX);
				txt_hics203_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_date->labeltype(FL_NORMAL_LABEL);
				txt_hics203_date->labelfont(0);
				txt_hics203_date->labelsize(14);
				txt_hics203_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_date->align(FL_ALIGN_LEFT);
				txt_hics203_date->when(FL_WHEN_RELEASE);
			} // Fl_Input2* txt_hics203_date
			{	btn_hics203_date = new Fl_Button(294, 134, 20, 20, _("..."));
				btn_hics203_date->tooltip(_("Set today"));
				btn_hics203_date->callback((Fl_Callback*)cb_btn_hics203_date);
			} // Fl_Button* btn_hics203_date
			{	txt_hics203_time = new Fl_Input2(135, 158, 103, 24, _("3. Time Prepared"));
				txt_hics203_time->tooltip(_("Time prepared"));
				txt_hics203_time->box(FL_DOWN_BOX);
				txt_hics203_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_time->labeltype(FL_NORMAL_LABEL);
				txt_hics203_time->labelfont(0);
				txt_hics203_time->labelsize(14);
				txt_hics203_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_time->align(FL_ALIGN_LEFT);
				txt_hics203_time->when(FL_WHEN_RELEASE);
			} // Fl_Input2* txt_hics203_time
			{	btn_hics203_time = new Fl_Button(247, 160, 20, 20, _("..."));
				btn_hics203_time->tooltip(_("Set time now"));
				btn_hics203_time->callback((Fl_Callback*)cb_btn_hics203_time);
			} // Fl_Button* btn_hics203_time
			{	txt_hics203_op_period = new Fl_Input2(135, 186, 425, 24, _("4. Oper\' Period"));
				txt_hics203_op_period->tooltip(_("Date / Time"));
				txt_hics203_op_period->box(FL_DOWN_BOX);
				txt_hics203_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_op_period->labeltype(FL_NORMAL_LABEL);
				txt_hics203_op_period->labelfont(0);
				txt_hics203_op_period->labelsize(14);
				txt_hics203_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_op_period->align(FL_ALIGN_LEFT);
				txt_hics203_op_period->when(FL_WHEN_RELEASE);
			}
			group_hics203_orglist_1->end();
			} // group_hics203_orglist_1
			{ // group_hics203_orglist_2
			Fl_Group* group_hics203_orglist_2 = new Fl_Group(2, 217, 566, 138, "");
			group_hics203_orglist_2->box(FL_ENGRAVED_FRAME);
			group_hics203_orglist_2->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
				txt_hics203_incident_commander = new Fl_Input2(133, 222, 425, 24, _("Commander"));
				txt_hics203_incident_commander->tooltip(_("name"));
				txt_hics203_incident_commander->box(FL_DOWN_BOX);
				txt_hics203_incident_commander->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_incident_commander->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_incident_commander->labeltype(FL_NORMAL_LABEL);
				txt_hics203_incident_commander->labelfont(0);
				txt_hics203_incident_commander->labelsize(14);
				txt_hics203_incident_commander->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_incident_commander->align(FL_ALIGN_LEFT);
				txt_hics203_incident_commander->when(FL_WHEN_RELEASE);

				txt_hics203_incident_safety_officer = new Fl_Input2(133, 248, 425, 24, _("Safety Officer"));
				txt_hics203_incident_safety_officer->tooltip(_("name"));
				txt_hics203_incident_safety_officer->box(FL_DOWN_BOX);
				txt_hics203_incident_safety_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_incident_safety_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_incident_safety_officer->labeltype(FL_NORMAL_LABEL);
				txt_hics203_incident_safety_officer->labelfont(0);
				txt_hics203_incident_safety_officer->labelsize(14);
				txt_hics203_incident_safety_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_incident_safety_officer->align(FL_ALIGN_LEFT);
				txt_hics203_incident_safety_officer->when(FL_WHEN_RELEASE);

				txt_hics203_incident_info_officer = new Fl_Input2(133, 275, 425, 24, _("Information Off\'"));
				txt_hics203_incident_info_officer->tooltip(_("name"));
				txt_hics203_incident_info_officer->box(FL_DOWN_BOX);
				txt_hics203_incident_info_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_incident_info_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_incident_info_officer->labeltype(FL_NORMAL_LABEL);
				txt_hics203_incident_info_officer->labelfont(0);
				txt_hics203_incident_info_officer->labelsize(14);
				txt_hics203_incident_info_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_incident_info_officer->align(FL_ALIGN_LEFT);
				txt_hics203_incident_info_officer->when(FL_WHEN_RELEASE);

				txt_hics203_liaison_officer = new Fl_Input2(133, 300, 425, 24, _("Liaison Officer"));
				txt_hics203_liaison_officer->tooltip(_("name"));
				txt_hics203_liaison_officer->box(FL_DOWN_BOX);
				txt_hics203_liaison_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_liaison_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_liaison_officer->labeltype(FL_NORMAL_LABEL);
				txt_hics203_liaison_officer->labelfont(0);
				txt_hics203_liaison_officer->labelsize(14);
				txt_hics203_liaison_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_liaison_officer->align(FL_ALIGN_LEFT);
				txt_hics203_liaison_officer->when(FL_WHEN_RELEASE);

			group_hics203_orglist_2->end();
			} // group_hics203_orglist_2
			{ // group_hics203_orglist_3
			Fl_Group* group_hics203_orglist_3 = new Fl_Group(2, 356, 565, 60);
			group_hics203_orglist_3->box(FL_ENGRAVED_FRAME);
			{
				txt_hics203_prepared_by = new Fl_Input2(133, 362, 425, 24, _("Prepared By"));
				txt_hics203_prepared_by->tooltip(_("preparer"));
				txt_hics203_prepared_by->box(FL_DOWN_BOX);
				txt_hics203_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_prepared_by->labeltype(FL_NORMAL_LABEL);
				txt_hics203_prepared_by->labelfont(0);
				txt_hics203_prepared_by->labelsize(14);
				txt_hics203_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_prepared_by->align(FL_ALIGN_LEFT);
				txt_hics203_prepared_by->when(FL_WHEN_RELEASE);
			}
			{
				txt_hics203_facility = new Fl_Input2(133, 388, 425, 24, _("Facility"));
				txt_hics203_facility->tooltip(_("facility name"));
				txt_hics203_facility->box(FL_DOWN_BOX);
				txt_hics203_facility->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_hics203_facility->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_hics203_facility->labeltype(FL_NORMAL_LABEL);
				txt_hics203_facility->labelfont(0);
				txt_hics203_facility->labelsize(14);
				txt_hics203_facility->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_hics203_facility->align(FL_ALIGN_LEFT);
				txt_hics203_facility->when(FL_WHEN_RELEASE);
			}
			group_hics203_orglist_3->end();
			} // group_hics203_orglist_3
		tab_hics203_1->end();
	} // Fl_Group* tab_hics203_orglist

	{ // tab_hics203_tech_spec
		tab_hics203_tech_spec = new Fl_Group(0, 95, 570, 325, _("Med/Tech"));
		tab_hics203_tech_spec->hide();
		{ Fl_Group* o = new Fl_Group(2, 106, 566, 314, _("Medical / Technical Specialists"));
		o->box(FL_ENGRAVED_FRAME);
		o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
		for (int i = 0; i < 6; i++) {
			txt_hics203_tech_spc[i] = new Fl_Input2(135, 132 + 30*i, 425, 24, _("Specialist"));
			txt_hics203_tech_spc[i]->tooltip(_("med / tech spec."));
			txt_hics203_tech_spc[i]->box(FL_DOWN_BOX);
			txt_hics203_tech_spc[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_tech_spc[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_tech_spc[i]->labeltype(FL_NORMAL_LABEL);
			txt_hics203_tech_spc[i]->labelfont(0);
			txt_hics203_tech_spc[i]->labelsize(14);
			txt_hics203_tech_spc[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_tech_spc[i]->align(FL_ALIGN_LEFT);
			txt_hics203_tech_spc[i]->when(FL_WHEN_RELEASE);
		}
		o->end();
		} // Fl_Group* o
		tab_hics203_tech_spec->end();
		} // Fl_Group* tab_hics203_tech_spec

		{ // tab_hics203_ops
			tab_hics203_ops = new Fl_Group(0, 95, 570, 325, _("Ops"));
			tab_hics203_ops->hide();

			txt_hics203_ops_chief = new Fl_Input2(135, 110, 425, 24, _("Chief"));
			txt_hics203_ops_chief->tooltip("");
			txt_hics203_ops_chief->box(FL_DOWN_BOX);
			txt_hics203_ops_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_ops_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_ops_chief->labeltype(FL_NORMAL_LABEL);
			txt_hics203_ops_chief->labelfont(0);
			txt_hics203_ops_chief->labelsize(14);
			txt_hics203_ops_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_ops_chief->align(FL_ALIGN_LEFT);
			txt_hics203_ops_chief->when(FL_WHEN_RELEASE);

			txt_hics203_bus_brch = new Fl_Input2(135, 136, 425, 24, _("Bus'/Cont' branch"));
			txt_hics203_bus_brch->tooltip(_("business continuity"));
			txt_hics203_bus_brch->box(FL_DOWN_BOX);
			txt_hics203_bus_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_bus_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_bus_brch->labeltype(FL_NORMAL_LABEL);
			txt_hics203_bus_brch->labelfont(0);
			txt_hics203_bus_brch->labelsize(14);
			txt_hics203_bus_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_bus_brch->align(FL_ALIGN_LEFT);
			txt_hics203_bus_brch->when(FL_WHEN_RELEASE);

			txt_hics203_stg_mgr = new Fl_Input2(135, 162, 425, 24, _("Staging manager"));
			txt_hics203_stg_mgr->tooltip(_("staging"));
			txt_hics203_stg_mgr->box(FL_DOWN_BOX);
			txt_hics203_stg_mgr->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_stg_mgr->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_stg_mgr->labeltype(FL_NORMAL_LABEL);
			txt_hics203_stg_mgr->labelfont(0);
			txt_hics203_stg_mgr->labelsize(14);
			txt_hics203_stg_mgr->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_stg_mgr->align(FL_ALIGN_LEFT);
			txt_hics203_stg_mgr->when(FL_WHEN_RELEASE);

			txt_hics203_med_care_brch = new Fl_Input2(135, 188, 425, 24, _("Med' care branch"));
			txt_hics203_med_care_brch->tooltip(_("medical care"));
			txt_hics203_med_care_brch->box(FL_DOWN_BOX);
			txt_hics203_med_care_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_med_care_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_med_care_brch->labeltype(FL_NORMAL_LABEL);
			txt_hics203_med_care_brch->labelfont(0);
			txt_hics203_med_care_brch->labelsize(14);
			txt_hics203_med_care_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_med_care_brch->align(FL_ALIGN_LEFT);
			txt_hics203_med_care_brch->when(FL_WHEN_RELEASE);

			txt_hics203_infr_brch = new Fl_Input2(135, 214, 425, 24, _("Infra' branch"));
			txt_hics203_infr_brch->tooltip(_("infrastructure"));
			txt_hics203_infr_brch->box(FL_DOWN_BOX);
			txt_hics203_infr_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_infr_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_infr_brch->labeltype(FL_NORMAL_LABEL);
			txt_hics203_infr_brch->labelfont(0);
			txt_hics203_infr_brch->labelsize(14);
			txt_hics203_infr_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_infr_brch->align(FL_ALIGN_LEFT);
			txt_hics203_infr_brch->when(FL_WHEN_RELEASE);

			txt_hics203_sec_brch = new Fl_Input2(135, 240, 425, 24, _("Security branch"));
			txt_hics203_sec_brch->tooltip(_("security"));
			txt_hics203_sec_brch->box(FL_DOWN_BOX);
			txt_hics203_sec_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_sec_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_sec_brch->labeltype(FL_NORMAL_LABEL);
			txt_hics203_sec_brch->labelfont(0);
			txt_hics203_sec_brch->labelsize(14);
			txt_hics203_sec_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_sec_brch->align(FL_ALIGN_LEFT);
			txt_hics203_sec_brch->when(FL_WHEN_RELEASE);

			txt_hics203_hazmat_brch = new Fl_Input2(135, 266, 425, 24, _("Hazmat branch"));
			txt_hics203_hazmat_brch->tooltip(_("hazardous materials"));
			txt_hics203_hazmat_brch->box(FL_DOWN_BOX);
			txt_hics203_hazmat_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_hazmat_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_hazmat_brch->labeltype(FL_NORMAL_LABEL);
			txt_hics203_hazmat_brch->labelfont(0);
			txt_hics203_hazmat_brch->labelsize(14);
			txt_hics203_hazmat_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_hazmat_brch->align(FL_ALIGN_LEFT);
			txt_hics203_hazmat_brch->when(FL_WHEN_RELEASE);

			txt_hics203_ops_other = new Fl_Input2(135, 292, 425, 24, _("Other"));
			txt_hics203_ops_other->tooltip("");
			txt_hics203_ops_other->box(FL_DOWN_BOX);
			txt_hics203_ops_other->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_ops_other->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_ops_other->labeltype(FL_NORMAL_LABEL);
			txt_hics203_ops_other->labelfont(0);
			txt_hics203_ops_other->labelsize(14);
			txt_hics203_ops_other->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_ops_other->align(FL_ALIGN_LEFT);
			txt_hics203_ops_other->when(FL_WHEN_RELEASE);

			tab_hics203_ops->end();
		} // Fl_Group* tab_hics203_ops

		{ // tab_hics203_planning
		tab_hics203_planning = new Fl_Group(0, 95, 570, 325, _("Plan'/Log'"));
		tab_hics203_planning->hide();
		{ Fl_Group* o = new Fl_Group(2, 101, 566, 184, _("Planning"));
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_hics203_planning_chief = new Fl_Input2(135, 116, 425, 24, _("Chief"));
			txt_hics203_planning_chief->tooltip("");
			txt_hics203_planning_chief->box(FL_DOWN_BOX);
			txt_hics203_planning_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_planning_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_planning_chief->labeltype(FL_NORMAL_LABEL);
			txt_hics203_planning_chief->labelfont(0);
			txt_hics203_planning_chief->labelsize(14);
			txt_hics203_planning_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_planning_chief->align(FL_ALIGN_LEFT);
			txt_hics203_planning_chief->when(FL_WHEN_RELEASE);

			txt_hics203_res_unit = new Fl_Input2(135, 142, 425, 24, _("Resources Unit"));
			txt_hics203_res_unit->tooltip(_("resources"));
			txt_hics203_res_unit->box(FL_DOWN_BOX);
			txt_hics203_res_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_res_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_res_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_res_unit->labelfont(0);
			txt_hics203_res_unit->labelsize(14);
			txt_hics203_res_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_res_unit->align(FL_ALIGN_LEFT);
			txt_hics203_res_unit->when(FL_WHEN_RELEASE);

			txt_hics203_sit_unit = new Fl_Input2(135, 168, 425, 24, _("Situation Unit"));
			txt_hics203_sit_unit->tooltip(_("situation"));
			txt_hics203_sit_unit->box(FL_DOWN_BOX);
			txt_hics203_sit_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_sit_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_sit_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_sit_unit->labelfont(0);
			txt_hics203_sit_unit->labelsize(14);
			txt_hics203_sit_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_sit_unit->align(FL_ALIGN_LEFT);
			txt_hics203_sit_unit->when(FL_WHEN_RELEASE);

			txt_hics203_doc_unit = new Fl_Input2(135, 194, 425, 24, _("Doc' Unit"));
			txt_hics203_doc_unit->tooltip(_("documentation"));
			txt_hics203_doc_unit->box(FL_DOWN_BOX);
			txt_hics203_doc_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_doc_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_doc_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_doc_unit->labelfont(0);
			txt_hics203_doc_unit->labelsize(14);
			txt_hics203_doc_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_doc_unit->align(FL_ALIGN_LEFT);
			txt_hics203_doc_unit->when(FL_WHEN_RELEASE);

			txt_hics203_dem_unit = new Fl_Input2(135, 220, 425, 24, _("Demob' Unit"));
			txt_hics203_dem_unit->tooltip(_("demobilization"));
			txt_hics203_dem_unit->box(FL_DOWN_BOX);
			txt_hics203_dem_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_dem_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_dem_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_dem_unit->labelfont(0);
			txt_hics203_dem_unit->labelsize(14);
			txt_hics203_dem_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_dem_unit->align(FL_ALIGN_LEFT);
			txt_hics203_dem_unit->when(FL_WHEN_RELEASE);

			txt_hics203_planning_other = new Fl_Input2(135, 246, 425, 24, _("Other branch"));
			txt_hics203_planning_other->tooltip("");
			txt_hics203_planning_other->box(FL_DOWN_BOX);
			txt_hics203_planning_other->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_planning_other->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_planning_other->labeltype(FL_NORMAL_LABEL);
			txt_hics203_planning_other->labelfont(0);
			txt_hics203_planning_other->labelsize(14);
			txt_hics203_planning_other->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_planning_other->align(FL_ALIGN_LEFT);
			txt_hics203_planning_other->when(FL_WHEN_RELEASE);

			o->end();
			} // Fl_Group* o
		{ Fl_Group* o = new Fl_Group(2, 285, 566, 140, _("Logistics"));
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_hics203_log_chief = new Fl_Input2(135, 310, 425, 24, _("Chief"));
			txt_hics203_log_chief->tooltip("");
			txt_hics203_log_chief->box(FL_DOWN_BOX);
			txt_hics203_log_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_log_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_log_chief->labeltype(FL_NORMAL_LABEL);
			txt_hics203_log_chief->labelfont(0);
			txt_hics203_log_chief->labelsize(14);
			txt_hics203_log_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_log_chief->align(FL_ALIGN_LEFT);
			txt_hics203_log_chief->when(FL_WHEN_RELEASE);

			txt_hics203_svc_brch = new Fl_Input2(135, 336, 425, 24, _("Services branch"));
			txt_hics203_svc_brch->tooltip("");
			txt_hics203_svc_brch->box(FL_DOWN_BOX);
			txt_hics203_svc_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_svc_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_svc_brch->labeltype(FL_NORMAL_LABEL);
			txt_hics203_svc_brch->labelfont(0);
			txt_hics203_svc_brch->labelsize(14);
			txt_hics203_svc_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_svc_brch->align(FL_ALIGN_LEFT);
			txt_hics203_svc_brch->when(FL_WHEN_RELEASE);

			txt_hics203_log_sup_brch = new Fl_Input2(135, 362, 425, 24, _("Support branch"));
			txt_hics203_log_sup_brch->tooltip("");
			txt_hics203_log_sup_brch->box(FL_DOWN_BOX);
			txt_hics203_log_sup_brch->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_log_sup_brch->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_log_sup_brch->labeltype(FL_NORMAL_LABEL);
			txt_hics203_log_sup_brch->labelfont(0);
			txt_hics203_log_sup_brch->labelsize(14);
			txt_hics203_log_sup_brch->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_log_sup_brch->align(FL_ALIGN_LEFT);
			txt_hics203_log_sup_brch->when(FL_WHEN_RELEASE);

			txt_hics203_log_other = new Fl_Input2(135, 388, 425, 24, _("Other branch"));
			txt_hics203_log_other->tooltip("");
			txt_hics203_log_other->box(FL_DOWN_BOX);
			txt_hics203_log_other->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_log_other->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_log_other->labeltype(FL_NORMAL_LABEL);
			txt_hics203_log_other->labelfont(0);
			txt_hics203_log_other->labelsize(14);
			txt_hics203_log_other->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_log_other->align(FL_ALIGN_LEFT);
			txt_hics203_log_other->when(FL_WHEN_RELEASE);

			o->end();
			} // Fl_Group* o
		tab_hics203_planning->end();
		} // tab_hics203_planning

		{ // tab_hics203_admin
		tab_hics203_admin = new Fl_Group(0, 95, 570, 326, _("Admin"));
		tab_hics203_admin->hide();
		{ Fl_Group* o = new Fl_Group(2, 102, 566, 176, _("Finance/Admin Section"));
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_hics203_fin_chief = new Fl_Input2(135, 120, 425, 24, _("Chief"));
			txt_hics203_fin_chief->tooltip("");
			txt_hics203_fin_chief->box(FL_DOWN_BOX);
			txt_hics203_fin_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_fin_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_fin_chief->labeltype(FL_NORMAL_LABEL);
			txt_hics203_fin_chief->labelfont(0);
			txt_hics203_fin_chief->labelsize(14);
			txt_hics203_fin_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_fin_chief->align(FL_ALIGN_LEFT);
			txt_hics203_fin_chief->when(FL_WHEN_RELEASE);

			txt_hics203_time_unit = new Fl_Input2(135, 146, 425, 24, _("Time"));
			txt_hics203_time_unit->tooltip("time unit");
			txt_hics203_time_unit->box(FL_DOWN_BOX);
			txt_hics203_time_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_time_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_time_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_time_unit->labelfont(0);
			txt_hics203_time_unit->labelsize(14);
			txt_hics203_time_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_time_unit->align(FL_ALIGN_LEFT);
			txt_hics203_time_unit->when(FL_WHEN_RELEASE);

			txt_hics203_proc_unit = new Fl_Input2(135, 172, 425, 24, _("Procurement"));
			txt_hics203_proc_unit->tooltip("procurement unit");
			txt_hics203_proc_unit->box(FL_DOWN_BOX);
			txt_hics203_proc_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_proc_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_proc_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_proc_unit->labelfont(0);
			txt_hics203_proc_unit->labelsize(14);
			txt_hics203_proc_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_proc_unit->align(FL_ALIGN_LEFT);
			txt_hics203_proc_unit->when(FL_WHEN_RELEASE);

			txt_hics203_comp_unit = new Fl_Input2(135, 198, 425, 24, _("Comp' / Claims"));
			txt_hics203_comp_unit->tooltip("compensation/claims unit");
			txt_hics203_comp_unit->box(FL_DOWN_BOX);
			txt_hics203_comp_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_comp_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_comp_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_comp_unit->labelfont(0);
			txt_hics203_comp_unit->labelsize(14);
			txt_hics203_comp_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_comp_unit->align(FL_ALIGN_LEFT);
			txt_hics203_comp_unit->when(FL_WHEN_RELEASE);

			txt_hics203_cost_unit = new Fl_Input2(135, 224, 425, 24, _("Cost Unit"));
			txt_hics203_cost_unit->tooltip("");
			txt_hics203_cost_unit->box(FL_DOWN_BOX);
			txt_hics203_cost_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_cost_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_cost_unit->labeltype(FL_NORMAL_LABEL);
			txt_hics203_cost_unit->labelfont(0);
			txt_hics203_cost_unit->labelsize(14);
			txt_hics203_cost_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_cost_unit->align(FL_ALIGN_LEFT);
			txt_hics203_cost_unit->when(FL_WHEN_RELEASE);

			txt_hics203_fin_other = new Fl_Input2(135, 250, 425, 24, _("Other branch"));
			txt_hics203_fin_other->tooltip("");
			txt_hics203_fin_other->box(FL_DOWN_BOX);
			txt_hics203_fin_other->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_fin_other->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_fin_other->labeltype(FL_NORMAL_LABEL);
			txt_hics203_fin_other->labelfont(0);
			txt_hics203_fin_other->labelsize(14);
			txt_hics203_fin_other->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_fin_other->align(FL_ALIGN_LEFT);
			txt_hics203_fin_other->when(FL_WHEN_RELEASE);

			o->end();
		} // Fl_Group* o

		{ Fl_Group* o = new Fl_Group(2, 278, 566, 144, _("Representatives"));
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			txt_hics203_hcc_agency = new Fl_Input2(135, 308, 425, 24, _("Hospital CC"));
			txt_hics203_hcc_agency->tooltip(_("hospital command center"));
			txt_hics203_hcc_agency->box(FL_DOWN_BOX);
			txt_hics203_hcc_agency->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_hcc_agency->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_hcc_agency->labeltype(FL_NORMAL_LABEL);
			txt_hics203_hcc_agency->labelfont(0);
			txt_hics203_hcc_agency->labelsize(14);
			txt_hics203_hcc_agency->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_hcc_agency->align(FL_ALIGN_LEFT);
			txt_hics203_hcc_agency->when(FL_WHEN_RELEASE);

			txt_hics203_hcc_rep = new Fl_Input2(135, 334, 425, 24, _("Representative"));
			txt_hics203_hcc_rep->tooltip(_("HCC representative"));
			txt_hics203_hcc_rep->box(FL_DOWN_BOX);
			txt_hics203_hcc_rep->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_hcc_rep->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_hcc_rep->labeltype(FL_NORMAL_LABEL);
			txt_hics203_hcc_rep->labelfont(0);
			txt_hics203_hcc_rep->labelsize(14);
			txt_hics203_hcc_rep->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_hcc_rep->align(FL_ALIGN_LEFT);
			txt_hics203_hcc_rep->when(FL_WHEN_RELEASE);

			txt_hics203_ext_loc = new Fl_Input2(135, 360, 425, 24, _("Ext Location"));
			txt_hics203_ext_loc->tooltip(_("external location"));
			txt_hics203_ext_loc->box(FL_DOWN_BOX);
			txt_hics203_ext_loc->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_ext_loc->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_ext_loc->labeltype(FL_NORMAL_LABEL);
			txt_hics203_ext_loc->labelfont(0);
			txt_hics203_ext_loc->labelsize(14);
			txt_hics203_ext_loc->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_ext_loc->align(FL_ALIGN_LEFT);
			txt_hics203_ext_loc->when(FL_WHEN_RELEASE);

			txt_hics203_ext_rep = new Fl_Input2(135, 388, 425, 24, _("Representative"));
			txt_hics203_ext_rep->tooltip(_("external representative"));
			txt_hics203_ext_rep->box(FL_DOWN_BOX);
			txt_hics203_ext_rep->color((Fl_Color)FL_BACKGROUND2_COLOR);
			txt_hics203_ext_rep->selection_color((Fl_Color)FL_SELECTION_COLOR);
			txt_hics203_ext_rep->labeltype(FL_NORMAL_LABEL);
			txt_hics203_ext_rep->labelfont(0);
			txt_hics203_ext_rep->labelsize(14);
			txt_hics203_ext_rep->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
			txt_hics203_ext_rep->align(FL_ALIGN_LEFT);
			txt_hics203_ext_rep->when(FL_WHEN_RELEASE);

		o->end();
			o->end();
		} // Fl_Group* o

		tab_hics203_admin->end();
	  } // Fl_Group* tab_hics203_admin
	tab_hics203_type->end();
	Fl_Group::current()->resizable(tab_hics203_type);
	tab_hics203->end();
} // Fl_Group* tab_hics203