//======================================================================
// HICS 206 tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group		*h206_tab = (Fl_Group *)0;
Fl_Tabs			*h206_tab_type = (Fl_Tabs *)0;

Fl_Group		*h206_tab_plan = (Fl_Group *)0;
Fl_Group		*h206_tab_treatment = (Fl_Group *)0;
Fl_Group		*h206_tab_resource = (Fl_Group *)0;
Fl_Group		*h206_tab_staff = (Fl_Group *)0;
Fl_Group		*h206_tab_medicines = (Fl_Group *)0;
Fl_Group		*h206_tab_sites = (Fl_Group *)0;

Fl_Input2		*h206_txt_name = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_op_period = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_time_prepared = (Fl_Input2 *)0;
Fl_Button		*h206_btn_time = (Fl_Button *)0;
Fl_DateInput	*h206_txt_date_prepared = (Fl_DateInput *)0;
Fl_Button		*h206_btn_date = (Fl_Button *)0;

Fl_Input2		*h206_txt_location = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_loc_contact = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_team_leader = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_team_contact = (Fl_Input2 *)0;
FTextEdit		*h206_txt_special_instructions = (FTextEdit *)0;

Fl_Input2		*h206_txt_md_do = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_pa_np = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_rn_lpn = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_tech_cn = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_team_other = (Fl_Input2 *)0;

Fl_Input2		*h206_txt_litters = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_portable = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_transport = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_wheelchairs = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_transport_other = (Fl_Input2 *)0;

Fl_Input2		*h206_txt_meds_1 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_meds_2 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_meds_3 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_meds_4 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_meds_5 = (Fl_Input2 *)0;

Fl_Input2		*h206_txt_supp_1 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_supp_2 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_supp_3 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_supp_4 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_supp_5 = (Fl_Input2 *)0;

Fl_Input2		*h206_txt_site_1 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_address_1 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_phone_1 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_spec_care_1 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_site_2 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_address_2 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_phone_2 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_spec_care_2 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_site_3 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_address_3 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_phone_3 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_spec_care_3 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_site_4 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_address_4 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_phone_4 = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_spec_care_4 = (Fl_Input2 *)0;

Fl_Input2		*h206_txt_preparer = (Fl_Input2 *)0;
Fl_Input2		*h206_txt_facility = (Fl_Input2 *)0;

static void cb_btn_h206time(Fl_Button*, void*) {
  h206_cb_settime();
}

static void cb_btn_h206date(Fl_Button*, void*) {
  h206_cb_setdate();
}

void create_hics206_tab()
{
	h206_tab = new Fl_Group(0, 70, 570, 355, _("206"));
	h206_tab->align(FL_ALIGN_TOP_LEFT);
	h206_tab->hide();
	h206_tab_type = new Fl_Tabs(0, 72, 570, 352);
	h206_tab_type->selection_color((Fl_Color)246);
	h206_tab_type->align(FL_ALIGN_TOP_LEFT);

	h206_tab_plan = new Fl_Group(0, 95, 570, 325, _("Plan"));
		{
		Fl_Group* o = new Fl_Group(2, 100, 566, 80);
		o->box(FL_ENGRAVED_FRAME);
		h206_txt_name = new Fl_Input2(9, 119, 242, 24, _("Incident Name"));
		h206_txt_name->tooltip(_(""));
		h206_txt_name->box(FL_DOWN_BOX);
		h206_txt_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_name->labeltype(FL_NORMAL_LABEL);
		h206_txt_name->labelfont(0);
		h206_txt_name->labelsize(14);
		h206_txt_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_name->align(FL_ALIGN_TOP_LEFT);
		h206_txt_name->when(FL_WHEN_RELEASE);

		h206_txt_op_period = new Fl_Input2(151, 147, 410, 24, _("Operational Period:"));
		h206_txt_op_period->tooltip(_(""));
		h206_txt_op_period->box(FL_DOWN_BOX);
		h206_txt_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_op_period->labeltype(FL_NORMAL_LABEL);
		h206_txt_op_period->labelfont(0);
		h206_txt_op_period->labelsize(14);
		h206_txt_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_op_period->align(FL_ALIGN_LEFT);
		h206_txt_op_period->when(FL_WHEN_RELEASE);

		h206_txt_time_prepared = new Fl_Input2(407, 117, 103, 24, _("Time Prepared"));
		h206_txt_time_prepared->tooltip(_("Time of origination"));
		h206_txt_time_prepared->box(FL_DOWN_BOX);
		h206_txt_time_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_time_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_time_prepared->labeltype(FL_NORMAL_LABEL);
		h206_txt_time_prepared->labelfont(0);
		h206_txt_time_prepared->labelsize(14);
		h206_txt_time_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_time_prepared->align(FL_ALIGN_TOP_LEFT);
		h206_txt_time_prepared->when(FL_WHEN_RELEASE);

		h206_btn_time = new Fl_Button(517, 119, 20, 20, _("..."));
		h206_btn_time->tooltip(_("Set time now"));
		h206_btn_time->callback((Fl_Callback*)cb_btn_h206time);

		h206_txt_date_prepared = new Fl_DateInput(256, 118, 125, 24, _("Date Prepared"));
		h206_txt_date_prepared->tooltip(_("Date of origination"));
		h206_txt_date_prepared->box(FL_DOWN_BOX);
		h206_txt_date_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_date_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_date_prepared->labeltype(FL_NORMAL_LABEL);
		h206_txt_date_prepared->labelfont(0);
		h206_txt_date_prepared->labelsize(14);
		h206_txt_date_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_date_prepared->align(FL_ALIGN_TOP_LEFT);
		h206_txt_date_prepared->when(FL_WHEN_RELEASE);

		h206_btn_date = new Fl_Button(383, 119, 20, 20, _("..."));
		h206_btn_date->tooltip(_("Set today"));
		h206_btn_date->callback((Fl_Callback*)cb_btn_h206date);

		o->end();
		}
		{
		Fl_Group* o = new Fl_Group(2, 182, 566, 30);
		o->box(FL_ENGRAVED_FRAME);
		h206_txt_preparer = new Fl_Input2(71, 184, 210, 24, _("Preparer"));
		h206_txt_preparer->tooltip(_(""));
		h206_txt_preparer->box(FL_DOWN_BOX);
		h206_txt_preparer->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_preparer->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_preparer->labeltype(FL_NORMAL_LABEL);
		h206_txt_preparer->labelfont(0);
		h206_txt_preparer->labelsize(14);
		h206_txt_preparer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_preparer->align(FL_ALIGN_LEFT);
		h206_txt_preparer->when(FL_WHEN_RELEASE);

		h206_txt_facility = new Fl_Input2(350, 184, 210, 24, _("Facility"));
		h206_txt_facility->tooltip(_(""));
		h206_txt_facility->box(FL_DOWN_BOX);
		h206_txt_facility->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_facility->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_facility->labeltype(FL_NORMAL_LABEL);
		h206_txt_facility->labelfont(0);
		h206_txt_facility->labelsize(14);
		h206_txt_facility->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_facility->align(FL_ALIGN_LEFT);
		h206_txt_facility->when(FL_WHEN_RELEASE);

		o->end();
		}
	h206_tab_plan->end();

	h206_tab_treatment = new Fl_Group(0, 95, 570, 325, _("Trmnt"));
		{
		h206_txt_location = new Fl_Input2(4, 119, 278, 24, _("Location"));
		h206_txt_location->tooltip(_("location of staff treatment area"));
		h206_txt_location->box(FL_DOWN_BOX);
		h206_txt_location->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_location->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_location->labeltype(FL_NORMAL_LABEL);
		h206_txt_location->labelfont(0);
		h206_txt_location->labelsize(14);
		h206_txt_location->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_location->align(FL_ALIGN_TOP_LEFT);
		h206_txt_location->when(FL_WHEN_RELEASE);

		h206_txt_loc_contact = new Fl_Input2(284, 119, 278, 24, _("Contact Information"));
		h206_txt_loc_contact->tooltip(_(""));
		h206_txt_loc_contact->box(FL_DOWN_BOX);
		h206_txt_loc_contact->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_loc_contact->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_loc_contact->labeltype(FL_NORMAL_LABEL);
		h206_txt_loc_contact->labelfont(0);
		h206_txt_loc_contact->labelsize(14);
		h206_txt_loc_contact->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_loc_contact->align(FL_ALIGN_TOP_LEFT);
		h206_txt_loc_contact->when(FL_WHEN_RELEASE);

		h206_txt_team_leader = new Fl_Input2(4, 167, 278, 24, _("Treatment area team leader"));
		h206_txt_team_leader->tooltip(_(""));
		h206_txt_team_leader->box(FL_DOWN_BOX);
		h206_txt_team_leader->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_team_leader->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_team_leader->labeltype(FL_NORMAL_LABEL);
		h206_txt_team_leader->labelfont(0);
		h206_txt_team_leader->labelsize(14);
		h206_txt_team_leader->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_team_leader->align(FL_ALIGN_TOP_LEFT);
		h206_txt_team_leader->when(FL_WHEN_RELEASE);

		h206_txt_team_contact = new Fl_Input2(284, 167, 278, 24, _("Contact Information"));
		h206_txt_team_contact->tooltip(_(""));
		h206_txt_team_contact->box(FL_DOWN_BOX);
		h206_txt_team_contact->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_team_contact->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_team_contact->labeltype(FL_NORMAL_LABEL);
		h206_txt_team_contact->labelfont(0);
		h206_txt_team_contact->labelsize(14);
		h206_txt_team_contact->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_team_contact->align(FL_ALIGN_TOP_LEFT);
		h206_txt_team_contact->when(FL_WHEN_RELEASE);

		h206_txt_special_instructions = new FTextEdit(4, 215, 562, 200, _("Special Instructions"));
		h206_txt_special_instructions->box(FL_DOWN_FRAME);
		h206_txt_special_instructions->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_special_instructions->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_special_instructions->labeltype(FL_NORMAL_LABEL);
		h206_txt_special_instructions->labelfont(0);
		h206_txt_special_instructions->labelsize(14);
		h206_txt_special_instructions->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_special_instructions->align(FL_ALIGN_TOP_LEFT);
		h206_txt_special_instructions->when(FL_WHEN_RELEASE);
		}
	h206_tab_treatment->end();

	h206_tab_staff = new Fl_Group(0, 95, 570, 325, _("Staff/Trans'"));
		{
		Fl_Group *grp1 = new Fl_Group(2, 98, 566, 155, "Staff");
		grp1->box(FL_ENGRAVED_FRAME);
		grp1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		h206_txt_md_do = new Fl_Input2(110, 120, 445, 24, _("MD/DO"));
		h206_txt_md_do->tooltip(_("medical doctor"));
		h206_txt_md_do->box(FL_DOWN_BOX);
		h206_txt_md_do->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_md_do->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_md_do->labeltype(FL_NORMAL_LABEL);
		h206_txt_md_do->labelfont(0);
		h206_txt_md_do->labelsize(14);
		h206_txt_md_do->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_md_do->align(FL_ALIGN_LEFT);
		h206_txt_md_do->when(FL_WHEN_RELEASE);

		h206_txt_pa_np = new Fl_Input2(110, 146, 445, 24, _("PA/NP"));
		h206_txt_pa_np->tooltip(_("physicians assistant / nurse practitioner"));
		h206_txt_pa_np->box(FL_DOWN_BOX);
		h206_txt_pa_np->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_pa_np->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_pa_np->labeltype(FL_NORMAL_LABEL);
		h206_txt_pa_np->labelfont(0);
		h206_txt_pa_np->labelsize(14);
		h206_txt_pa_np->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_pa_np->align(FL_ALIGN_LEFT);
		h206_txt_pa_np->when(FL_WHEN_RELEASE);

		h206_txt_rn_lpn = new Fl_Input2(110, 172, 445, 24, _("RN/LPN"));
		h206_txt_rn_lpn->tooltip(_("registered nurse / licensed practical nurse"));
		h206_txt_rn_lpn->box(FL_DOWN_BOX);
		h206_txt_rn_lpn->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_rn_lpn->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_rn_lpn->labeltype(FL_NORMAL_LABEL);
		h206_txt_rn_lpn->labelfont(0);
		h206_txt_rn_lpn->labelsize(14);
		h206_txt_rn_lpn->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_rn_lpn->align(FL_ALIGN_LEFT);
		h206_txt_rn_lpn->when(FL_WHEN_RELEASE);

		h206_txt_tech_cn = new Fl_Input2(110, 198, 445, 24, _("Tech/CN"));
		h206_txt_tech_cn->tooltip(_("technician"));
		h206_txt_tech_cn->box(FL_DOWN_BOX);
		h206_txt_tech_cn->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_tech_cn->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_tech_cn->labeltype(FL_NORMAL_LABEL);
		h206_txt_tech_cn->labelfont(0);
		h206_txt_tech_cn->labelsize(14);
		h206_txt_tech_cn->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_tech_cn->align(FL_ALIGN_LEFT);
		h206_txt_tech_cn->when(FL_WHEN_RELEASE);

		h206_txt_team_other = new Fl_Input2(110, 224, 445, 24, _("Team-other"));
		h206_txt_team_other->tooltip(_(""));
		h206_txt_team_other->box(FL_DOWN_BOX);
		h206_txt_team_other->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_team_other->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_team_other->labeltype(FL_NORMAL_LABEL);
		h206_txt_team_other->labelfont(0);
		h206_txt_team_other->labelsize(14);
		h206_txt_team_other->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_team_other->align(FL_ALIGN_LEFT);
		h206_txt_team_other->when(FL_WHEN_RELEASE);
		grp1->end();

		Fl_Group *grp2 = new Fl_Group(2, 255, 566, 165, "Transportation");
		grp2->box(FL_ENGRAVED_FRAME);
		grp2->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		h206_txt_litters = new Fl_Input2(110, 280, 445, 24, _("Litters"));
		h206_txt_litters->tooltip(_(""));
		h206_txt_litters->box(FL_DOWN_BOX);
		h206_txt_litters->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_litters->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_litters->labeltype(FL_NORMAL_LABEL);
		h206_txt_litters->labelfont(0);
		h206_txt_litters->labelsize(14);
		h206_txt_litters->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_litters->align(FL_ALIGN_LEFT);
		h206_txt_litters->when(FL_WHEN_RELEASE);

		h206_txt_portable = new Fl_Input2(110, 306, 445, 24, _("Portable"));
		h206_txt_portable->tooltip(_(""));
		h206_txt_portable->box(FL_DOWN_BOX);
		h206_txt_portable->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_portable->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_portable->labeltype(FL_NORMAL_LABEL);
		h206_txt_portable->labelfont(0);
		h206_txt_portable->labelsize(14);
		h206_txt_portable->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_portable->align(FL_ALIGN_LEFT);
		h206_txt_portable->when(FL_WHEN_RELEASE);

		h206_txt_transport = new Fl_Input2(110, 332, 445, 24, _("Transport"));
		h206_txt_transport->tooltip(_(""));
		h206_txt_transport->box(FL_DOWN_BOX);
		h206_txt_transport->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_transport->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_transport->labeltype(FL_NORMAL_LABEL);
		h206_txt_transport->labelfont(0);
		h206_txt_transport->labelsize(14);
		h206_txt_transport->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_transport->align(FL_ALIGN_LEFT);
		h206_txt_transport->when(FL_WHEN_RELEASE);

		h206_txt_wheelchairs = new Fl_Input2(110, 358, 445, 24, _("Wheelchairs"));
		h206_txt_wheelchairs->tooltip(_(""));
		h206_txt_wheelchairs->box(FL_DOWN_BOX);
		h206_txt_wheelchairs->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_wheelchairs->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_wheelchairs->labeltype(FL_NORMAL_LABEL);
		h206_txt_wheelchairs->labelfont(0);
		h206_txt_wheelchairs->labelsize(14);
		h206_txt_wheelchairs->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_wheelchairs->align(FL_ALIGN_LEFT);
		h206_txt_wheelchairs->when(FL_WHEN_RELEASE);

		h206_txt_transport_other = new Fl_Input2(110, 384, 445, 24, _("Trans'-other"));
		h206_txt_transport_other->tooltip(_(""));
		h206_txt_transport_other->box(FL_DOWN_BOX);
		h206_txt_transport_other->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_transport_other->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_transport_other->labeltype(FL_NORMAL_LABEL);
		h206_txt_transport_other->labelfont(0);
		h206_txt_transport_other->labelsize(14);
		h206_txt_transport_other->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_transport_other->align(FL_ALIGN_LEFT);
		h206_txt_transport_other->when(FL_WHEN_RELEASE);
		}
	h206_tab_staff->end();

	h206_tab_medicines = new Fl_Group(0, 95, 570, 325, _("Med/Supply"));
		{
		Fl_Group *grp1 = new Fl_Group(2, 98, 566, 155, "Medicines");
		grp1->box(FL_ENGRAVED_FRAME);
		grp1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		h206_txt_meds_1 = new Fl_Input2(110, 120, 445, 24, _("Medicine"));
		h206_txt_meds_1->tooltip(_(""));
		h206_txt_meds_1->box(FL_DOWN_BOX);
		h206_txt_meds_1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_meds_1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_meds_1->labeltype(FL_NORMAL_LABEL);
		h206_txt_meds_1->labelfont(0);
		h206_txt_meds_1->labelsize(14);
		h206_txt_meds_1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_meds_1->align(FL_ALIGN_LEFT);
		h206_txt_meds_1->when(FL_WHEN_RELEASE);


		h206_txt_meds_2 = new Fl_Input2(110, 146, 445, 24, _("Medicine"));
		h206_txt_meds_2->tooltip(_(""));
		h206_txt_meds_2->box(FL_DOWN_BOX);
		h206_txt_meds_2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_meds_2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_meds_2->labeltype(FL_NORMAL_LABEL);
		h206_txt_meds_2->labelfont(0);
		h206_txt_meds_2->labelsize(14);
		h206_txt_meds_2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_meds_2->align(FL_ALIGN_LEFT);
		h206_txt_meds_2->when(FL_WHEN_RELEASE);

		h206_txt_meds_3 = new Fl_Input2(110, 172, 445, 24, _("Medicine"));
		h206_txt_meds_3->tooltip(_(""));
		h206_txt_meds_3->box(FL_DOWN_BOX);
		h206_txt_meds_3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_meds_3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_meds_3->labeltype(FL_NORMAL_LABEL);
		h206_txt_meds_3->labelfont(0);
		h206_txt_meds_3->labelsize(14);
		h206_txt_meds_3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_meds_3->align(FL_ALIGN_LEFT);
		h206_txt_meds_3->when(FL_WHEN_RELEASE);

		h206_txt_meds_4 = new Fl_Input2(110, 198, 445, 24, _("Medicine"));
		h206_txt_meds_4->tooltip(_(""));
		h206_txt_meds_4->box(FL_DOWN_BOX);
		h206_txt_meds_4->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_meds_4->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_meds_4->labeltype(FL_NORMAL_LABEL);
		h206_txt_meds_4->labelfont(0);
		h206_txt_meds_4->labelsize(14);
		h206_txt_meds_4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_meds_4->align(FL_ALIGN_LEFT);
		h206_txt_meds_4->when(FL_WHEN_RELEASE);

		h206_txt_meds_5 = new Fl_Input2(110, 224, 445, 24, _("Medicine"));
		h206_txt_meds_5->tooltip(_(""));
		h206_txt_meds_5->box(FL_DOWN_BOX);
		h206_txt_meds_5->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_meds_5->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_meds_5->labeltype(FL_NORMAL_LABEL);
		h206_txt_meds_5->labelfont(0);
		h206_txt_meds_5->labelsize(14);
		h206_txt_meds_5->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_meds_5->align(FL_ALIGN_LEFT);
		h206_txt_meds_5->when(FL_WHEN_RELEASE);

		grp1->end();

		Fl_Group *grp2 = new Fl_Group(2, 255, 566, 165, "Supplies");
		grp2->box(FL_ENGRAVED_FRAME);
		grp2->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		h206_txt_supp_1 = new Fl_Input2(110, 280, 445, 24, _("Supply"));
		h206_txt_supp_1->tooltip(_(""));
		h206_txt_supp_1->box(FL_DOWN_BOX);
		h206_txt_supp_1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_supp_1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_supp_1->labeltype(FL_NORMAL_LABEL);
		h206_txt_supp_1->labelfont(0);
		h206_txt_supp_1->labelsize(14);
		h206_txt_supp_1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_supp_1->align(FL_ALIGN_LEFT);
		h206_txt_supp_1->when(FL_WHEN_RELEASE);

		h206_txt_supp_2 = new Fl_Input2(110, 306, 445, 24, _("Supply"));
		h206_txt_supp_2->tooltip(_(""));
		h206_txt_supp_2->box(FL_DOWN_BOX);
		h206_txt_supp_2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_supp_2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_supp_2->labeltype(FL_NORMAL_LABEL);
		h206_txt_supp_2->labelfont(0);
		h206_txt_supp_2->labelsize(14);
		h206_txt_supp_2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_supp_2->align(FL_ALIGN_LEFT);
		h206_txt_supp_2->when(FL_WHEN_RELEASE);

		h206_txt_supp_3 = new Fl_Input2(110, 332, 445, 24, _("Supply"));
		h206_txt_supp_3->tooltip(_(""));
		h206_txt_supp_3->box(FL_DOWN_BOX);
		h206_txt_supp_3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_supp_3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_supp_3->labeltype(FL_NORMAL_LABEL);
		h206_txt_supp_3->labelfont(0);
		h206_txt_supp_3->labelsize(14);
		h206_txt_supp_3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_supp_3->align(FL_ALIGN_LEFT);
		h206_txt_supp_3->when(FL_WHEN_RELEASE);

		h206_txt_supp_4 = new Fl_Input2(110, 358, 445, 24, _("Supply"));
		h206_txt_supp_4->tooltip(_(""));
		h206_txt_supp_4->box(FL_DOWN_BOX);
		h206_txt_supp_4->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_supp_4->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_supp_4->labeltype(FL_NORMAL_LABEL);
		h206_txt_supp_4->labelfont(0);
		h206_txt_supp_4->labelsize(14);
		h206_txt_supp_4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_supp_4->align(FL_ALIGN_LEFT);
		h206_txt_supp_4->when(FL_WHEN_RELEASE);

		h206_txt_supp_5 = new Fl_Input2(110, 384, 445, 24, _("Supply"));
		h206_txt_supp_5->tooltip(_(""));
		h206_txt_supp_5->box(FL_DOWN_BOX);
		h206_txt_supp_5->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_supp_5->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_supp_5->labeltype(FL_NORMAL_LABEL);
		h206_txt_supp_5->labelfont(0);
		h206_txt_supp_5->labelsize(14);
		h206_txt_supp_5->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_supp_5->align(FL_ALIGN_LEFT);
		h206_txt_supp_5->when(FL_WHEN_RELEASE);

		}
	h206_tab_medicines->end();

	h206_tab_sites = new Fl_Group(0, 95, 570, 325, _("Sites"));
	{
		h206_txt_site_1 = new Fl_Input2(80, 110, 200, 24, _("Name"));
		h206_txt_site_1->tooltip(_(""));
		h206_txt_site_1->box(FL_DOWN_BOX);
		h206_txt_site_1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_site_1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_site_1->labeltype(FL_NORMAL_LABEL);
		h206_txt_site_1->labelfont(0);
		h206_txt_site_1->labelsize(14);
		h206_txt_site_1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_site_1->align(FL_ALIGN_LEFT);
		h206_txt_site_1->when(FL_WHEN_RELEASE);

		h206_txt_phone_1 = new Fl_Input2(360, 110, 200, 24, _("Phone"));
		h206_txt_phone_1->tooltip(_(""));
		h206_txt_phone_1->box(FL_DOWN_BOX);
		h206_txt_phone_1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_phone_1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_phone_1->labeltype(FL_NORMAL_LABEL);
		h206_txt_phone_1->labelfont(0);
		h206_txt_phone_1->labelsize(14);
		h206_txt_phone_1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_phone_1->align(FL_ALIGN_LEFT);
		h206_txt_phone_1->when(FL_WHEN_RELEASE);

		h206_txt_address_1 = new Fl_Input2(80, 136, 200, 24, _("Address"));
		h206_txt_address_1->tooltip(_(""));
		h206_txt_address_1->box(FL_DOWN_BOX);
		h206_txt_address_1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_address_1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_address_1->labeltype(FL_NORMAL_LABEL);
		h206_txt_address_1->labelfont(0);
		h206_txt_address_1->labelsize(14);
		h206_txt_address_1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_address_1->align(FL_ALIGN_LEFT);
		h206_txt_address_1->when(FL_WHEN_RELEASE);

		h206_txt_spec_care_1 = new Fl_Input2(360, 136, 200, 24, _("Spec care"));
		h206_txt_spec_care_1->tooltip(_(""));
		h206_txt_spec_care_1->box(FL_DOWN_BOX);
		h206_txt_spec_care_1->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_spec_care_1->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_spec_care_1->labeltype(FL_NORMAL_LABEL);
		h206_txt_spec_care_1->labelfont(0);
		h206_txt_spec_care_1->labelsize(14);
		h206_txt_spec_care_1->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_spec_care_1->align(FL_ALIGN_LEFT);
		h206_txt_spec_care_1->when(FL_WHEN_RELEASE);

		h206_txt_site_2 = new Fl_Input2(80, 176, 200, 24, _("Name"));
		h206_txt_site_2->tooltip(_(""));
		h206_txt_site_2->box(FL_DOWN_BOX);
		h206_txt_site_2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_site_2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_site_2->labeltype(FL_NORMAL_LABEL);
		h206_txt_site_2->labelfont(0);
		h206_txt_site_2->labelsize(14);
		h206_txt_site_2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_site_2->align(FL_ALIGN_LEFT);
		h206_txt_site_2->when(FL_WHEN_RELEASE);

		h206_txt_phone_2 = new Fl_Input2(360, 176, 200, 24, _("Phone"));
		h206_txt_phone_2->tooltip(_(""));
		h206_txt_phone_2->box(FL_DOWN_BOX);
		h206_txt_phone_2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_phone_2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_phone_2->labeltype(FL_NORMAL_LABEL);
		h206_txt_phone_2->labelfont(0);
		h206_txt_phone_2->labelsize(14);
		h206_txt_phone_2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_phone_2->align(FL_ALIGN_LEFT);
		h206_txt_phone_2->when(FL_WHEN_RELEASE);

		h206_txt_address_2 = new Fl_Input2(80, 202, 200, 24, _("Address"));
		h206_txt_address_2->tooltip(_(""));
		h206_txt_address_2->box(FL_DOWN_BOX);
		h206_txt_address_2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_address_2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_address_2->labeltype(FL_NORMAL_LABEL);
		h206_txt_address_2->labelfont(0);
		h206_txt_address_2->labelsize(14);
		h206_txt_address_2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_address_2->align(FL_ALIGN_LEFT);
		h206_txt_address_2->when(FL_WHEN_RELEASE);

		h206_txt_spec_care_2 = new Fl_Input2(360, 202, 200, 24, _("Spec care"));
		h206_txt_spec_care_2->tooltip(_(""));
		h206_txt_spec_care_2->box(FL_DOWN_BOX);
		h206_txt_spec_care_2->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_spec_care_2->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_spec_care_2->labeltype(FL_NORMAL_LABEL);
		h206_txt_spec_care_2->labelfont(0);
		h206_txt_spec_care_2->labelsize(14);
		h206_txt_spec_care_2->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_spec_care_2->align(FL_ALIGN_LEFT);
		h206_txt_spec_care_2->when(FL_WHEN_RELEASE);

		h206_txt_site_3 = new Fl_Input2(80, 242, 200, 24, _("Name"));
		h206_txt_site_3->tooltip(_(""));
		h206_txt_site_3->box(FL_DOWN_BOX);
		h206_txt_site_3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_site_3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_site_3->labeltype(FL_NORMAL_LABEL);
		h206_txt_site_3->labelfont(0);
		h206_txt_site_3->labelsize(14);
		h206_txt_site_3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_site_3->align(FL_ALIGN_LEFT);
		h206_txt_site_3->when(FL_WHEN_RELEASE);

		h206_txt_phone_3 = new Fl_Input2(360, 242, 200, 24, _("Phone"));
		h206_txt_phone_3->tooltip(_(""));
		h206_txt_phone_3->box(FL_DOWN_BOX);
		h206_txt_phone_3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_phone_3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_phone_3->labeltype(FL_NORMAL_LABEL);
		h206_txt_phone_3->labelfont(0);
		h206_txt_phone_3->labelsize(14);
		h206_txt_phone_3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_phone_3->align(FL_ALIGN_LEFT);
		h206_txt_phone_3->when(FL_WHEN_RELEASE);

		h206_txt_address_3 = new Fl_Input2(80, 268, 200, 24, _("Address"));
		h206_txt_address_3->tooltip(_(""));
		h206_txt_address_3->box(FL_DOWN_BOX);
		h206_txt_address_3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_address_3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_address_3->labeltype(FL_NORMAL_LABEL);
		h206_txt_address_3->labelfont(0);
		h206_txt_address_3->labelsize(14);
		h206_txt_address_3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_address_3->align(FL_ALIGN_LEFT);
		h206_txt_address_3->when(FL_WHEN_RELEASE);

		h206_txt_spec_care_3 = new Fl_Input2(360, 268, 200, 24, _("Spec care"));
		h206_txt_spec_care_3->tooltip(_(""));
		h206_txt_spec_care_3->box(FL_DOWN_BOX);
		h206_txt_spec_care_3->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_spec_care_3->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_spec_care_3->labeltype(FL_NORMAL_LABEL);
		h206_txt_spec_care_3->labelfont(0);
		h206_txt_spec_care_3->labelsize(14);
		h206_txt_spec_care_3->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_spec_care_3->align(FL_ALIGN_LEFT);
		h206_txt_spec_care_3->when(FL_WHEN_RELEASE);

		h206_txt_site_4 = new Fl_Input2(80, 308, 200, 24, _("Name"));
		h206_txt_site_4->tooltip(_(""));
		h206_txt_site_4->box(FL_DOWN_BOX);
		h206_txt_site_4->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_site_4->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_site_4->labeltype(FL_NORMAL_LABEL);
		h206_txt_site_4->labelfont(0);
		h206_txt_site_4->labelsize(14);
		h206_txt_site_4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_site_4->align(FL_ALIGN_LEFT);
		h206_txt_site_4->when(FL_WHEN_RELEASE);

		h206_txt_phone_4 = new Fl_Input2(360, 308, 200, 24, _("Phone"));
		h206_txt_phone_4->tooltip(_(""));
		h206_txt_phone_4->box(FL_DOWN_BOX);
		h206_txt_phone_4->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_phone_4->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_phone_4->labeltype(FL_NORMAL_LABEL);
		h206_txt_phone_4->labelfont(0);
		h206_txt_phone_4->labelsize(14);
		h206_txt_phone_4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_phone_4->align(FL_ALIGN_LEFT);
		h206_txt_phone_4->when(FL_WHEN_RELEASE);

		h206_txt_address_4 = new Fl_Input2(80, 334, 200, 24, _("Address"));
		h206_txt_address_4->tooltip(_(""));
		h206_txt_address_4->box(FL_DOWN_BOX);
		h206_txt_address_4->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_address_4->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_address_4->labeltype(FL_NORMAL_LABEL);
		h206_txt_address_4->labelfont(0);
		h206_txt_address_4->labelsize(14);
		h206_txt_address_4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_address_4->align(FL_ALIGN_LEFT);
		h206_txt_address_4->when(FL_WHEN_RELEASE);

		h206_txt_spec_care_4 = new Fl_Input2(360, 334, 200, 24, _("Spec care"));
		h206_txt_spec_care_4->tooltip(_(""));
		h206_txt_spec_care_4->box(FL_DOWN_BOX);
		h206_txt_spec_care_4->color((Fl_Color)FL_BACKGROUND2_COLOR);
		h206_txt_spec_care_4->selection_color((Fl_Color)FL_SELECTION_COLOR);
		h206_txt_spec_care_4->labeltype(FL_NORMAL_LABEL);
		h206_txt_spec_care_4->labelfont(0);
		h206_txt_spec_care_4->labelsize(14);
		h206_txt_spec_care_4->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		h206_txt_spec_care_4->align(FL_ALIGN_LEFT);
		h206_txt_spec_care_4->when(FL_WHEN_RELEASE);

	}
	h206_tab_sites->end();
	
	h206_tab_type->end();
	Fl_Group::current()->resizable(h206_tab_type);
	h206_tab->end();
}
