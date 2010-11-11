// =====================================================================
//
// flmsg_dialog.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2010
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  It is
// copyright under the GNU General Public License.
//
// You should have received a copy of the GNU General Public License
// along with the program; if not, write to the Free Software
// Foundation, Inc.
// 59 Temple Place, Suite 330
// Boston, MA  02111-1307 USA
//
// =====================================================================

#include "gettext.h"
#include "flmsg_dialog.h"
#include "status.h"
#include "flmsg.h"

//======================================================================

Fl_Group	*tab_ics = (Fl_Group	*)0;
Fl_Tabs	*tab_ics_type = (Fl_Tabs	*)0;

//======================================================================

Fl_Group	*tab_ics203 = (Fl_Group	*)0;
Fl_Tabs		*tab_ics203_type = (Fl_Tabs	*)0;
Fl_Group	*tab_203_1 = (Fl_Group	*)0;
Fl_Input2	*txt_203_incident = (Fl_Input2	*)0;
Fl_Input2	*txt_203_date = (Fl_Input2	*)0;
Fl_Button	*btn_203_date = (Fl_Button	*)0;
Fl_Input2	*txt_203_time = (Fl_Input2	*)0;
Fl_Button	*btn_203_time = (Fl_Button	*)0;
Fl_Input2	*txt_203_op_period = (Fl_Input2	*)0;
Fl_Input2	*txt_203_incident_commander = (Fl_Input2	*)0;
Fl_Input2	*txt_203_incident_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_incident_safety_officer = (Fl_Input2	*)0;
Fl_Input2	*txt_203_incident_info_officer = (Fl_Input2	*)0;
Fl_Input2	*txt_203_liaison_officer = (Fl_Input2	*)0;
Fl_Input2	*txt_203_prepared_by = (Fl_Input2	*)0;
Fl_Group	*tab_203_agency = (Fl_Group	*)0;
Fl_Input2	*txt_203_agency[7]={(Fl_Input2	*)0};
Fl_Input2	*txt_203_agency_name[7]={(Fl_Input2	*)0};
Fl_Group	*tab_203_planning = (Fl_Group	*)0;
Fl_Input2	*txt_203_planning_chief = (Fl_Input2	*)0;
Fl_Input2	*txt_203_planning_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_resources_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_situation_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_documentation_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_demobilization_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_tech_spc[3]={(Fl_Input2	*)0};
Fl_Group	*tab_203_logistics = (Fl_Group	*)0;
Fl_Input2	*txt_203_logistics_chief = (Fl_Input2	*)0;
Fl_Input2	*txt_203_logistics_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_support_director = (Fl_Input2	*)0;
Fl_Input2	*txt_203_supply_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_facilities_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_ground_support = (Fl_Input2	*)0;
Fl_Input2	*txt_203_service_director = (Fl_Input2	*)0;
Fl_Input2	*txt_203_communications_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_medical_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_food_unit = (Fl_Input2	*)0;
Fl_Group	*tab_203_opsA = (Fl_Group	*)0;
Fl_Input2	*txt_203_ops_chief = (Fl_Input2	*)0;
Fl_Input2	*txt_203_ops_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_b1_director = (Fl_Input2	*)0;
Fl_Input2	*txt_203_b1_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_b1_div[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_203_b1_grp[5]={(Fl_Input2	*)0};
Fl_Group	*tab_203_opsB = (Fl_Group	*)0;
Fl_Input2	*txt_203_b2_director = (Fl_Input2	*)0;
Fl_Input2	*txt_203_b2_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_b2_div[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_203_b2_grp[5]={(Fl_Input2	*)0};
Fl_Group	*tab_203_opsC = (Fl_Group	*)0;
Fl_Input2	*txt_203_b3_director = (Fl_Input2	*)0;
Fl_Input2	*txt_203_b3_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_b3_div[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_203_b3_grp[5]={(Fl_Input2	*)0};
Fl_Group	*tab_203_opsD = (Fl_Group	*)0;
Fl_Input2	*txt_203_air_ops_br_dir = (Fl_Input2	*)0;
Fl_Input2	*txt_203_air_tactical_group_sup = (Fl_Input2	*)0;
Fl_Input2	*txt_203_air_support_group_sup = (Fl_Input2	*)0;
Fl_Input2	*txt_203_helicopter_coordinator = (Fl_Input2	*)0;
Fl_Input2	*txt_203_air_tanker_fixed_wing = (Fl_Input2	*)0;
Fl_Group	*tab_203_admin = (Fl_Group	*)0;
Fl_Input2	*txt_203_finance_chief = (Fl_Input2	*)0;
Fl_Input2	*txt_203_finance_deputy = (Fl_Input2	*)0;
Fl_Input2	*txt_203_time_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_procurement_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_claims_unit = (Fl_Input2	*)0;
Fl_Input2	*txt_203_cost_unit = (Fl_Input2	*)0;

//======================================================================

Fl_Group	*tab_ics205 = (Fl_Group	*)0;
Fl_Input2	*txt_205_name = (Fl_Input2	*)0;
Fl_Input2	*txt_205_dt_prepared = (Fl_Input2	*)0;
Fl_Button	*btn_205DateTime1 = (Fl_Button	*)0;

Fl_Input2	*txt_205_dt_operational = (Fl_Input2	*)0;
Fl_Button	*btn_205_DateTime2 = (Fl_Button	*)0;
Fl_Input2	*txt_205_type[8]={(Fl_Input2	*)0};
Fl_Input2	*txt_205_channel[8]={(Fl_Input2	*)0};
Fl_Input2	*txt_205_function[8]={(Fl_Input2	*)0};
Fl_Input2	*txt_205_freqtone[8]={(Fl_Input2	*)0};
Fl_Input2	*txt_205_assignment[8]={(Fl_Input2	*)0};
Fl_Input2	*txt_205_remarks[8]={(Fl_Input2	*)0};
Fl_Input2	*txt_205_preparer = (Fl_Input2	*)0;

//======================================================================

Fl_Group	*tab_ics206 = (Fl_Group	*)0;
Fl_Tabs		*tab_ics206_type = (Fl_Tabs	*)0;
Fl_Group	*tab_206_med_plan = (Fl_Group	*)0;
Fl_Input2	*txt_206_name = (Fl_Input2	*)0;
Fl_Input2	*txt_206_op_period = (Fl_Input2	*)0;
Fl_Input2	*txt_206_time_prepared = (Fl_Input2	*)0;
Fl_Button	*btn_206_time = (Fl_Button	*)0;
Fl_DateInput	*txt_206_date_prepared = (Fl_DateInput	*)0;
Fl_Button	*btn_206_date = (Fl_Button	*)0;
Fl_Input2	*txt_206_medaid_sta[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_206_medaid_loc[5]={(Fl_Input2	*)0};
Fl_Check_Button	*btn_206_medaid_paramedics[5]={(Fl_Check_Button	*)0};
Fl_Input2	*txt_206_preparer = (Fl_Input2	*)0;
Fl_Input2	*txt_206_reviewer = (Fl_Input2	*)0;
Fl_Group	*tab_206_transport = (Fl_Group	*)0;
Fl_Input2	*txt_206_transport_name[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_206_transport_address[5]={(Fl_Input2	*)0};
Fl_Check_Button	*btn_206_transport_paramedics[5]={(Fl_Check_Button	*)0};
Fl_Input2	*txt_206_transport_phone[5]={(Fl_Input2	*)0};
Fl_Group	*tab_206_ambulance = (Fl_Group	*)0;
Fl_Input2	*txt_206_ambulance_name[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_206_ambulance_loc[5]={(Fl_Input2	*)0};
Fl_Check_Button	*btn_206_ambulance_paramedics[5]={(Fl_Check_Button	*)0};
Fl_Group	*tab_206_hospital = (Fl_Group	*)0;
Fl_Input2	*txt_206_hosp_name[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_206_hosp_address[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_206_hosp_phone[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_206_hosp_airtime[5]={(Fl_Input2	*)0};
Fl_Input2	*txt_206_hosp_gndtime[5]={(Fl_Input2	*)0};
Fl_Check_Button	*btn_206_hosp_helipad[5]={(Fl_Check_Button	*)0};
Fl_Check_Button	*btn_206_hosp_burn_center[5]={(Fl_Check_Button	*)0};
Fl_Group	*tab_206_med_proc = (Fl_Group	*)0;
FTextEdit	*txt_206_procedure = (FTextEdit	*)0;

//======================================================================

Fl_Group	*tab_ics213 = (Fl_Group	*)0;
Fl_Tabs		*tab_ics213_type = (Fl_Tabs	*)0;
Fl_Group	*tab_213_originator = (Fl_Group	*)0;
Fl_Input2	*txt_213_to = (Fl_Input2	*)0;
Fl_Input2	*txt_213_p1 = (Fl_Input2	*)0;
Fl_Input2	*txt_213_fm = (Fl_Input2	*)0;
Fl_Input2	*txt_213_p2 = (Fl_Input2	*)0;
Fl_Input2	*txt_213_subj = (Fl_Input2	*)0;
Fl_DateInput	*txt_213_d1 = (Fl_DateInput	*)0;
Fl_Button	*btn_213_date1 = (Fl_Button	*)0;

Fl_Output	*txt_filename = (Fl_Output	*)0;
Fl_Tabs	*tabs_msg_type = (Fl_Tabs	*)0;

Fl_Input2	*txt_213_t1 = (Fl_Input2	*)0;
Fl_Button	*btn_213_time1 = (Fl_Button	*)0;
FTextEdit	*txt_213_msg = (FTextEdit	*)0;
Fl_Input2	*txt_213_s1 = (Fl_Input2	*)0;
Fl_Input2	*txt_213_p3 = (Fl_Input2	*)0;
Fl_Group	*tab_213_responder = (Fl_Group	*)0;
Fl_Input2	*txt_213_s2 = (Fl_Input2	*)0;
Fl_DateInput	*txt_213_d2 = (Fl_DateInput	*)0;
Fl_Input2	*txt_213_t2 = (Fl_Input2	*)0;
Fl_Button	*btn_213_time2 = (Fl_Button	*)0;
FTextEdit	*txt_213_reply = (FTextEdit	*)0;
Fl_Input2	*txt_213_p4 = (Fl_Input2	*)0;
Fl_Button	*btn_213_date2 = (Fl_Button	*)0;

//======================================================================

Fl_Group	*tab_ics214 = (Fl_Group	*)0;
Fl_Tabs	*tab_ics214_type = (Fl_Tabs	*)0;
Fl_Group	*tab_214_1 = (Fl_Group	*)0;
Fl_Input2	*txt_214_incident = (Fl_Input2	*)0;
Fl_Input2	*txt_214_date = (Fl_Input2	*)0;
Fl_Input2	*txt_214_unit_name = (Fl_Input2	*)0;
Fl_Input2	*txt_214_unit_leader = (Fl_Input2	*)0;
Fl_Button	*btn_214_date = (Fl_Button	*)0;
Fl_Input2	*txt_214_time = (Fl_Input2	*)0;
Fl_Button	*btn_214_time = (Fl_Button	*)0;

Fl_Input2	*txt_214_op_period = (Fl_Input2	*)0;
Fl_Input2	*txt_214_prepared_by = (Fl_Input2	*)0;
Fl_Group	*tab_214_2 = (Fl_Group	*)0;
Fl_Input2	*txt_214_roster_name[16]={(Fl_Input2	*)0};
Fl_Input2	*txt_214_roster_position[16]={(Fl_Input2	*)0};
Fl_Input2	*txt_214_roster_home_base[16]={(Fl_Input2	*)0};
Fl_Group	*tab_214_3 = (Fl_Group	*)0;
Fl_Input2	*txt_214_activity_time[16]={(Fl_Input2	*)0};
Fl_Input2	*txt_214_activity_event[16]={(Fl_Input2	*)0};

//======================================================================

Fl_Group	*tab_ics216 = (Fl_Group	*)0;
Fl_Group	*tab_ics_216 = (Fl_Group	*)0;
Fl_Tabs		*tab_ics216_type = (Fl_Tabs	*)0;
Fl_Group	*tab_216_1 = (Fl_Group	*)0;
Fl_Group	*tab_216_2 = (Fl_Group	*)0;
Fl_Group	*tab_216_3 = (Fl_Group	*)0;
Fl_Group	*tab_216_4 = (Fl_Group	*)0;
Fl_Group	*tab_216_5 = (Fl_Group	*)0;
Fl_Input2	*txt_216_incident = (Fl_Input2	*)0;
Fl_Input2	*txt_216_date = (Fl_Input2	*)0;
Fl_Button	*btn_216_date = (Fl_Button	*)0;
Fl_Input2	*txt_216_time = (Fl_Input2	*)0;
Fl_Button	*btn_216_time = (Fl_Button	*)0;
Fl_Input2	*txt_216_branch = (Fl_Input2	*)0;
Fl_Input2	*txt_216_agc = (Fl_Input2	*)0;
Fl_Input2	*txt_216_op_period = (Fl_Input2	*)0;
Fl_Input2	*txt_216_tac_freq = (Fl_Input2	*)0;
Fl_Input2	*txt_216_prepared_by = (Fl_Input2	*)0;
Fl_Input2	*txt_216_div_grp[4]={(Fl_Input2	*)0};
Fl_Input2	*txt_216_agency[4]={(Fl_Input2	*)0};
Fl_Input2	*txt_216_ag[36]={(Fl_Input2	*)0};
Fl_Input2	*txt_216_id[36]={(Fl_Input2	*)0};
Fl_Input2	*txt_216_rr[36]={(Fl_Input2	*)0};

//======================================================================

Fl_Group	*tab_radiogram = (Fl_Group	*)0;
Fl_Tabs	*tabs_radiogram = (Fl_Tabs	*)0;
Fl_Group	*tab_radiogram_message = (Fl_Group	*)0;
Fl_Input2	*txt_rg_nbr = (Fl_Input2	*)0;

Fl_Choice	*sel_rg_prec = (Fl_Choice	*)0;
Fl_Input2	*txt_rg_hx = (Fl_Input2	*)0;
Fl_Button	*btn_rg_hx = (Fl_Button	*)0;
Fl_Input2	*txt_rg_station = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_place = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_t1 = (Fl_Input2	*)0;
Fl_Button	*btn_rgTime1 = (Fl_Button	*)0;
Fl_Input2	*txt_rg_d1 = (Fl_Input2	*)0;
Fl_Button	*btn_rgDate1 = (Fl_Button	*)0;
Fl_Input2	*txt_rg_to = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_phone = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_opnote = (Fl_Input2	*)0;
FTextEdit	*txt_rg_msg = (FTextEdit	*)0;
Fl_Button	*btn_arl = (Fl_Button	*)0;
Fl_Input2	*txt_rg_check = (Fl_Input2	*)0;
Fl_Button	*btn_rg_check = (Fl_Button	*)0;

Fl_Input2	*txt_rg_sig = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_opnote2 = (Fl_Input2	*)0;
Fl_Check_Button	*btn_rg_svc = (Fl_Check_Button	*)0;
Fl_Group	*tab_radiogram_information = (Fl_Group	*)0;
Fl_Input2	*txt_rg_orig = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_dt2 = (Fl_Input2	*)0;
Fl_Button	*btn_rgDateTime2 = (Fl_Button	*)0;
Fl_Input2	*txt_rg_dt3 = (Fl_Input2	*)0;
Fl_Button	*btn_rgDateTime3 = (Fl_Button	*)0;
Fl_Input2	*txt_rg_dlvd_to = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_rcv_fm = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_rcv_net = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_dt4 = (Fl_Input2	*)0;
Fl_Button	*btn_rgDateTime4 = (Fl_Button	*)0;
Fl_Input2	*txt_rg_sent_to = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_snt_net = (Fl_Input2	*)0;
Fl_Input2	*txt_rg_dt5 = (Fl_Input2	*)0;
Fl_Button	*btn_rgDateTime5 = (Fl_Button	*)0;
Fl_Group	*tab_plaintext = (Fl_Group	*)0;
Fl_Input2	*txt_pt_title = (Fl_Input2	*)0;
Fl_Input2	*txt_pt_to = (Fl_Input2	*)0;
Fl_Input2	*txt_pt_fm = (Fl_Input2	*)0;
Fl_Input2	*txt_pt_subj = (Fl_Input2	*)0;
FTextEdit	*txt_pt_msg = (FTextEdit	*)0;
Fl_DateInput	*txt_pt_date = (Fl_DateInput	*)0;
Fl_Button	*btn_pt_date = (Fl_Button	*)0;
Fl_Input2	*txt_pt_time = (Fl_Input2	*)0;
Fl_Button	*btn_pt_time = (Fl_Button	*)0;

Fl_Group	*tab_blank = (Fl_Group	*)0;
FTextEdit	*txt_blank_msg = (FTextEdit	*)0;

//======================================================================

static void cb_mnuNew(Fl_Menu_*, void*) {
  cb_new();
}

static void cb_mnuOpen(Fl_Menu_*, void*) {
  cb_open();
}

static void cb_mnuSave(Fl_Menu_*, void*) {
  cb_save();
}

static void cb_mnuSaveAs(Fl_Menu_*, void*) {
  cb_save_as();
}

static void cb_mnu_html(Fl_Menu_*, void*) {
  cb_html();
}

static void cb_mnu_html_fcopy(Fl_Menu_*, void*) {
  cb_html_fcopy();
}

static void cb_mnu_text(Fl_Menu_*, void*) {
  cb_text();
}

static void cb_mnu_qimport(Fl_Menu_*, void*) {
  cb_import();
}

static void cb_mnu_qexport(Fl_Menu_*, void*) {
  cb_export();
}

static void cb_mnuWrapImport(Fl_Menu_*, void*) {
  cb_wrap_import();
}

static void cb_mnuWrapExport(Fl_Menu_*, void*) {
  cb_wrap_export();
}

static void cb_mnuAutoSend(Fl_Menu_*, void*) {
  cb_wrap_autosend();
}

static void cb_mnuExit(Fl_Menu_*, void*) {
  cb_exit();
}

static void cb_mnu_load_template(Fl_Menu_*, void*) {
  cb_load_template();
}

static void cb_mnu_save_template(Fl_Menu_*, void*) {
  cb_save_template();
}

static void cb_mnu_save_as_template(Fl_Menu_*, void*) {
  cb_save_as_template();
}

static void cb_mnuConfig(Fl_Menu_*, void*) {
  cb_config();
}

static void cb_mnuOptions(Fl_Menu_*, void*) {
  showoptions();
}

static void cb_mnuOnLineHelp(Fl_Menu_*, void*) {
  show_help();
}

static void cb_mnuAbout(Fl_Menu_*, void*) {
  cb_About();
}

static void cb_tabs_msg_type(Fl_Tabs*, void*) {
  cb_msg_type();
}

static void cb_tab_ics_type(Fl_Tabs*, void*) {
  cb_msg_type();
}

static void cb_btn_203_date(Fl_Button*, void*) {
  cb_203_set_date();
}

static void cb_btn_203_time(Fl_Button*, void*) {
  cb_203_set_time();
}

static void cb_btn_205DateTime1(Fl_Button*, void*) {
  cb_205_SetDateTime1();
}

static void cb_btn_205_DateTime2(Fl_Button*, void*) {
  cb_205_SetDateTime2();
}

static void cb_btn_206_time(Fl_Button*, void*) {
  cb_206_settime();
}

static void cb_btn_206_date(Fl_Button*, void*) {
  cb_206_setdate();
}

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

static void cb_btn_214_date(Fl_Button*, void*) {
  cb_214_set_date();
}

static void cb_btn_214_time(Fl_Button*, void*) {
  cb_214_set_time();
}

static void cb_btn_216_date(Fl_Button*, void*) {
  cb_216_set_date();
}

static void cb_btn_216_time(Fl_Button*, void*) {
  cb_216_set_time();
}

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

static void cb_btn_pt_date(Fl_Button*, void*) {
  cb_set_pt_date();
}

static void cb_btn_pt_time(Fl_Button*, void*) {
  cb_set_pt_time();
}

Fl_Menu_Item menu_[] = {
 {_("&File"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&New"), 0x4006e,  (Fl_Callback*)cb_mnuNew, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&Open"), 0x4006f,  (Fl_Callback*)cb_mnuOpen, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&Save"), 0x40073,  (Fl_Callback*)cb_mnuSave, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Save &As"), 0x40061,  (Fl_Callback*)cb_mnuSaveAs, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("View"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Html delivery"), 0,  (Fl_Callback*)cb_mnu_html, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Html file copy"), 0,  (Fl_Callback*)cb_mnu_html_fcopy, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Plain Text"), 0,  (Fl_Callback*)cb_mnu_text, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("Q-forms"), 0,  0, 0, 192, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Import"), 0,  (Fl_Callback*)cb_mnu_qimport, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Export"), 0,  (Fl_Callback*)cb_mnu_qexport, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("Wrap"), 0,  0, 0, 192, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Import"), 0,  (Fl_Callback*)cb_mnuWrapImport, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Export"), 0,  (Fl_Callback*)cb_mnuWrapExport, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("AutoSend"), 0,  (Fl_Callback*)cb_mnuAutoSend, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("E&xit"), 0x40078,  (Fl_Callback*)cb_mnuExit, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("&Template"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Load"), 0,  (Fl_Callback*)cb_mnu_load_template, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Save"), 0,  (Fl_Callback*)cb_mnu_save_template, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Save As"), 0,  (Fl_Callback*)cb_mnu_save_as_template, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("&Config"), 0,  (Fl_Callback*)cb_mnuConfig, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("	  "), 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&Help"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Command line options"), 0,  (Fl_Callback*)cb_mnuOptions, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("On Line help"), 0,  (Fl_Callback*)cb_mnuOnLineHelp, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("About"), 0,  (Fl_Callback*)cb_mnuAbout, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Double_Window* ics_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(570, 430, _("Standard Message Generator"));;
	w->align(FL_ALIGN_CLIP|FL_ALIGN_INSIDE);

	Fl_Menu_Bar* mb = new Fl_Menu_Bar(0, 0, 290, 20);
		mb->menu(menu_);

	txt_filename = new Fl_Output(365, 2, 200, 20, _("filename:"));
	txt_filename->box(FL_FLAT_BOX);
	txt_filename->color((Fl_Color)FL_BACKGROUND_COLOR);

	{ // tab_msg_type
	tabs_msg_type = new Fl_Tabs(-1, 22, 608, 405);
	tabs_msg_type->selection_color((Fl_Color)246);
	tabs_msg_type->callback((Fl_Callback*)cb_tabs_msg_type);

		{ // tab_ics
		tab_ics = new Fl_Group(0, 45, 607, 380, _("ICS"));
		tab_ics_type = new Fl_Tabs(0, 45, 607, 380);
		tab_ics_type->selection_color((Fl_Color)246);
		tab_ics_type->callback((Fl_Callback*)cb_tab_ics_type);
			{ tab_ics203 = new Fl_Group(0, 70, 607, 355, _("203"));
			tab_ics203->align(FL_ALIGN_TOP_LEFT);
			tab_ics203_type = new Fl_Tabs(0, 73, 607, 352);
			tab_ics203_type->selection_color((Fl_Color)246);
			tab_ics203_type->align(FL_ALIGN_TOP_LEFT);
				{ // tab_203_orglist
				tab_203_1 = new Fl_Group(0, 95, 570, 325, _("Org List"));
					{ // group_203_orglist_1
					Fl_Group* group_203_orglist_1 = new Fl_Group(2, 101, 566, 115);
					group_203_orglist_1->box(FL_ENGRAVED_FRAME);
					group_203_orglist_1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
					{	txt_203_incident = new Fl_Input2(135, 107, 425, 24, _("1. Incident Name"));
						txt_203_incident->tooltip(_("Incident name"));
						txt_203_incident->box(FL_DOWN_BOX);
						txt_203_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident->labeltype(FL_NORMAL_LABEL);
						txt_203_incident->labelfont(0);
						txt_203_incident->labelsize(14);
						txt_203_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident->align(FL_ALIGN_LEFT);
						txt_203_incident->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_incident
					{	txt_203_date = new Fl_Input2(135, 134, 155, 24, _("2. Date Prepared"));
						txt_203_date->tooltip(_("Date prepared"));
						txt_203_date->box(FL_DOWN_BOX);
						txt_203_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_date->labeltype(FL_NORMAL_LABEL);
						txt_203_date->labelfont(0);
						txt_203_date->labelsize(14);
						txt_203_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_date->align(FL_ALIGN_LEFT);
						txt_203_date->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_date
					{	btn_203_date = new Fl_Button(294, 136, 20, 20, _("..."));
						btn_203_date->tooltip(_("Set today"));
						btn_203_date->callback((Fl_Callback*)cb_btn_203_date);
					} // Fl_Button* btn_203_date
					{	txt_203_time = new Fl_Input2(135, 159, 103, 24, _("3. Time Prepared"));
						txt_203_time->tooltip(_("Time prepared"));
						txt_203_time->box(FL_DOWN_BOX);
						txt_203_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_time->labeltype(FL_NORMAL_LABEL);
						txt_203_time->labelfont(0);
						txt_203_time->labelsize(14);
						txt_203_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_time->align(FL_ALIGN_LEFT);
						txt_203_time->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_time
					{	btn_203_time = new Fl_Button(247, 161, 20, 20, _("..."));
						btn_203_time->tooltip(_("Set time now"));
						btn_203_time->callback((Fl_Callback*)cb_btn_203_time);
					} // Fl_Button* btn_203_time
					{	txt_203_op_period = new Fl_Input2(135, 187, 425, 24, _("4. Oper\' Period"));
						txt_203_op_period->tooltip(_("Date / Time"));
						txt_203_op_period->box(FL_DOWN_BOX);
						txt_203_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_op_period->labeltype(FL_NORMAL_LABEL);
						txt_203_op_period->labelfont(0);
						txt_203_op_period->labelsize(14);
						txt_203_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_op_period->align(FL_ALIGN_LEFT);
						txt_203_op_period->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_op_period
					group_203_orglist_1->end();
					} // group_203_orglist_1
					{ // group_203_orglist_2
					Fl_Group* group_203_orglist_2 = new Fl_Group(2, 217, 566, 167, _("Incident Command and Staff"));
					group_203_orglist_2->box(FL_ENGRAVED_FRAME);
					group_203_orglist_2->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
						txt_203_incident_commander = new Fl_Input2(133, 238, 425, 24, _("Commander"));
						txt_203_incident_commander->tooltip(_("Incident name"));
						txt_203_incident_commander->box(FL_DOWN_BOX);
						txt_203_incident_commander->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_commander->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_commander->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_commander->labelfont(0);
						txt_203_incident_commander->labelsize(14);
						txt_203_incident_commander->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_commander->align(FL_ALIGN_LEFT);
						txt_203_incident_commander->when(FL_WHEN_RELEASE);

						txt_203_incident_deputy = new Fl_Input2(133, 267, 425, 24, _("Deputy"));
						txt_203_incident_deputy->tooltip(_("Incident name"));
						txt_203_incident_deputy->box(FL_DOWN_BOX);
						txt_203_incident_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_deputy->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_deputy->labelfont(0);
						txt_203_incident_deputy->labelsize(14);
						txt_203_incident_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_deputy->align(FL_ALIGN_LEFT);
						txt_203_incident_deputy->when(FL_WHEN_RELEASE);

						txt_203_incident_safety_officer = new Fl_Input2(133, 296, 425, 24, _("Safety Officer"));
						txt_203_incident_safety_officer->tooltip(_("Incident name"));
						txt_203_incident_safety_officer->box(FL_DOWN_BOX);
						txt_203_incident_safety_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_safety_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_safety_officer->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_safety_officer->labelfont(0);
						txt_203_incident_safety_officer->labelsize(14);
						txt_203_incident_safety_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_safety_officer->align(FL_ALIGN_LEFT);
						txt_203_incident_safety_officer->when(FL_WHEN_RELEASE);

						txt_203_incident_info_officer = new Fl_Input2(133, 325, 425, 24, _("Information Off\'"));
						txt_203_incident_info_officer->tooltip(_("Incident name"));
						txt_203_incident_info_officer->box(FL_DOWN_BOX);
						txt_203_incident_info_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_info_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_info_officer->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_info_officer->labelfont(0);
						txt_203_incident_info_officer->labelsize(14);
						txt_203_incident_info_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_info_officer->align(FL_ALIGN_LEFT);
						txt_203_incident_info_officer->when(FL_WHEN_RELEASE);

						txt_203_liaison_officer = new Fl_Input2(133, 355, 425, 24, _("Liaison Officer"));
						txt_203_liaison_officer->tooltip(_("Incident name"));
						txt_203_liaison_officer->box(FL_DOWN_BOX);
						txt_203_liaison_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_liaison_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_liaison_officer->labeltype(FL_NORMAL_LABEL);
						txt_203_liaison_officer->labelfont(0);
						txt_203_liaison_officer->labelsize(14);
						txt_203_liaison_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_liaison_officer->align(FL_ALIGN_LEFT);
						txt_203_liaison_officer->when(FL_WHEN_RELEASE);

					group_203_orglist_2->end();
					} // group_203_orglist_2
					{ // group_203_orglist_3
					Fl_Group* group_203_orglist_3 = new Fl_Group(2, 385, 565, 35);
					group_203_orglist_3->box(FL_ENGRAVED_FRAME);
						txt_203_prepared_by = new Fl_Input2(133, 389, 425, 24, _("Prepared By"));
						txt_203_prepared_by->tooltip(_("Incident name"));
						txt_203_prepared_by->box(FL_DOWN_BOX);
						txt_203_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_prepared_by->labeltype(FL_NORMAL_LABEL);
						txt_203_prepared_by->labelfont(0);
						txt_203_prepared_by->labelsize(14);
						txt_203_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_prepared_by->align(FL_ALIGN_LEFT);
						txt_203_prepared_by->when(FL_WHEN_RELEASE);
					group_203_orglist_3->end();
					} // group_203_orglist_3
				tab_203_1->end();
				} // Fl_Group* tab_203_orglist
				{ // tab_203_agency
				tab_203_agency = new Fl_Group(0, 95, 570, 325, _("Agency"));
				tab_203_agency->hide();
				{ Fl_Group* o = new Fl_Group(2, 106, 566, 314, _("Agency Representatives"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				for (int i = 0; i < 7; i++) {
					txt_203_agency[i] = new Fl_Input2(11, 149 + 39*i, 275, 24, _("Agency"));
					txt_203_agency[i]->tooltip(_("Incident name"));
					txt_203_agency[i]->box(FL_DOWN_BOX);
					txt_203_agency[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_agency[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_agency[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_agency[i]->labelfont(0);
					txt_203_agency[i]->labelsize(14);
					txt_203_agency[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_agency[i]->align(FL_ALIGN_TOP);
					txt_203_agency[i]->when(FL_WHEN_RELEASE);

					txt_203_agency_name[i] = new Fl_Input2(290, 149 + 39*i, 275, 24, _("Name"));
					txt_203_agency_name[i]->tooltip(_("Incident name"));
					txt_203_agency_name[i]->box(FL_DOWN_BOX);
					txt_203_agency_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_agency_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_agency_name[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_agency_name[i]->labelfont(0);
					txt_203_agency_name[i]->labelsize(14);
					txt_203_agency_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_agency_name[i]->align(FL_ALIGN_TOP);
					txt_203_agency_name[i]->when(FL_WHEN_RELEASE);
				}
				o->end();
				} // Fl_Group* o
				tab_203_agency->end();
			  } // Fl_Group* tab_203_agency
				{ // tab_203_planning
				tab_203_planning = new Fl_Group(0, 95, 570, 325, _("Planning"));
				tab_203_planning->hide();
				{ Fl_Group* o = new Fl_Group(2, 101, 566, 289, _("Planning Section"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
					txt_203_planning_chief = new Fl_Input2(158, 122, 400, 24, _("Chief"));
					txt_203_planning_chief->tooltip(_("Incident name"));
					txt_203_planning_chief->box(FL_DOWN_BOX);
					txt_203_planning_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_planning_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_planning_chief->labeltype(FL_NORMAL_LABEL);
					txt_203_planning_chief->labelfont(0);
					txt_203_planning_chief->labelsize(14);
					txt_203_planning_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_planning_chief->align(FL_ALIGN_LEFT);
					txt_203_planning_chief->when(FL_WHEN_RELEASE);

					txt_203_planning_deputy = new Fl_Input2(158, 151, 400, 24, _("Deputy"));
					txt_203_planning_deputy->tooltip(_("Incident name"));
					txt_203_planning_deputy->box(FL_DOWN_BOX);
					txt_203_planning_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_planning_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_planning_deputy->labeltype(FL_NORMAL_LABEL);
					txt_203_planning_deputy->labelfont(0);
					txt_203_planning_deputy->labelsize(14);
					txt_203_planning_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_planning_deputy->align(FL_ALIGN_LEFT);
					txt_203_planning_deputy->when(FL_WHEN_RELEASE);

					txt_203_resources_unit = new Fl_Input2(158, 181, 400, 24, _("Resources Unit"));
					txt_203_resources_unit->tooltip(_("Incident name"));
					txt_203_resources_unit->box(FL_DOWN_BOX);
					txt_203_resources_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_resources_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_resources_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_resources_unit->labelfont(0);
					txt_203_resources_unit->labelsize(14);
					txt_203_resources_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_resources_unit->align(FL_ALIGN_LEFT);
					txt_203_resources_unit->when(FL_WHEN_RELEASE);

					txt_203_situation_unit = new Fl_Input2(158, 210, 400, 24, _("Situation Unit"));
					txt_203_situation_unit->tooltip(_("Incident name"));
					txt_203_situation_unit->box(FL_DOWN_BOX);
					txt_203_situation_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_situation_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_situation_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_situation_unit->labelfont(0);
					txt_203_situation_unit->labelsize(14);
					txt_203_situation_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_situation_unit->align(FL_ALIGN_LEFT);
					txt_203_situation_unit->when(FL_WHEN_RELEASE);

					txt_203_documentation_unit = new Fl_Input2(158, 240, 400, 24, _("Documentation Unit"));
					txt_203_documentation_unit->tooltip(_("Incident name"));
					txt_203_documentation_unit->box(FL_DOWN_BOX);
					txt_203_documentation_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_documentation_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_documentation_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_documentation_unit->labelfont(0);
					txt_203_documentation_unit->labelsize(14);
					txt_203_documentation_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_documentation_unit->align(FL_ALIGN_LEFT);
					txt_203_documentation_unit->when(FL_WHEN_RELEASE);

					txt_203_demobilization_unit = new Fl_Input2(158, 269, 400, 24, _("Demobilization Unit"));
					txt_203_demobilization_unit->tooltip(_("Incident name"));
					txt_203_demobilization_unit->box(FL_DOWN_BOX);
					txt_203_demobilization_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_demobilization_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_demobilization_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_demobilization_unit->labelfont(0);
					txt_203_demobilization_unit->labelsize(14);
					txt_203_demobilization_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_demobilization_unit->align(FL_ALIGN_LEFT);
					txt_203_demobilization_unit->when(FL_WHEN_RELEASE);

					for (int i = 0; i < 3; i++) {
						txt_203_tech_spc[i] = new Fl_Input2(158, 299 + i*29, 400, 24, _("Technical Specialist"));
						txt_203_tech_spc[i]->tooltip(_("Name"));
						txt_203_tech_spc[i]->box(FL_DOWN_BOX);
						txt_203_tech_spc[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_tech_spc[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_tech_spc[i]->labeltype(FL_NORMAL_LABEL);
						txt_203_tech_spc[i]->labelfont(0);
						txt_203_tech_spc[i]->labelsize(14);
						txt_203_tech_spc[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_tech_spc[i]->align(FL_ALIGN_LEFT);
						txt_203_tech_spc[i]->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_tech_spc[i]
					o->end();
					} // Fl_Group* o
				tab_203_planning->end();
				} // tab_203_planning
				{ // tab_203_logistics
				tab_203_logistics = new Fl_Group(0, 95, 570, 325, _("Logistics"));
				tab_203_logistics->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Logistics Section"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
					txt_203_logistics_chief = new Fl_Input2(165, 119, 395, 24, _("Chief"));
					txt_203_logistics_chief->tooltip(_("Incident name"));
					txt_203_logistics_chief->box(FL_DOWN_BOX);
					txt_203_logistics_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_logistics_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_logistics_chief->labeltype(FL_NORMAL_LABEL);
					txt_203_logistics_chief->labelfont(0);
					txt_203_logistics_chief->labelsize(14);
					txt_203_logistics_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_logistics_chief->align(FL_ALIGN_LEFT);
					txt_203_logistics_chief->when(FL_WHEN_RELEASE);

					txt_203_logistics_deputy = new Fl_Input2(165, 146, 395, 24, _("Deputy"));
					txt_203_logistics_deputy->tooltip(_("Incident name"));
					txt_203_logistics_deputy->box(FL_DOWN_BOX);
					txt_203_logistics_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_logistics_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_logistics_deputy->labeltype(FL_NORMAL_LABEL);
					txt_203_logistics_deputy->labelfont(0);
					txt_203_logistics_deputy->labelsize(14);
					txt_203_logistics_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_logistics_deputy->align(FL_ALIGN_LEFT);
					txt_203_logistics_deputy->when(FL_WHEN_RELEASE);

					{ Fl_Group* o = new Fl_Group(6, 175, 558, 118, _("a. Support"));
					o->box(FL_THIN_DOWN_BOX);
					o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
						txt_203_support_director = new Fl_Input2(165, 182, 395, 24, _("Director"));
						txt_203_support_director->tooltip(_("Incident name"));
						txt_203_support_director->box(FL_DOWN_BOX);
						txt_203_support_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_support_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_support_director->labeltype(FL_NORMAL_LABEL);
						txt_203_support_director->labelfont(0);
						txt_203_support_director->labelsize(14);
						txt_203_support_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_support_director->align(FL_ALIGN_LEFT);
						txt_203_support_director->when(FL_WHEN_RELEASE);

						txt_203_supply_unit = new Fl_Input2(165, 209, 395, 24, _("Supply Unit"));
						txt_203_supply_unit->tooltip(_("Incident name"));
						txt_203_supply_unit->box(FL_DOWN_BOX);
						txt_203_supply_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_supply_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_supply_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_supply_unit->labelfont(0);
						txt_203_supply_unit->labelsize(14);
						txt_203_supply_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_supply_unit->align(FL_ALIGN_LEFT);
						txt_203_supply_unit->when(FL_WHEN_RELEASE);

						txt_203_facilities_unit = new Fl_Input2(165, 236, 395, 24, _("Facilities Unit"));
						txt_203_facilities_unit->tooltip(_("Incident name"));
						txt_203_facilities_unit->box(FL_DOWN_BOX);
						txt_203_facilities_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_facilities_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_facilities_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_facilities_unit->labelfont(0);
						txt_203_facilities_unit->labelsize(14);
						txt_203_facilities_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_facilities_unit->align(FL_ALIGN_LEFT);
						txt_203_facilities_unit->when(FL_WHEN_RELEASE);

						txt_203_ground_support = new Fl_Input2(165, 264, 395, 24, _("Ground Support Unit"));
						txt_203_ground_support->tooltip(_("Incident name"));
						txt_203_ground_support->box(FL_DOWN_BOX);
						txt_203_ground_support->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_ground_support->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_ground_support->labeltype(FL_NORMAL_LABEL);
						txt_203_ground_support->labelfont(0);
						txt_203_ground_support->labelsize(14);
						txt_203_ground_support->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_ground_support->align(FL_ALIGN_LEFT);
						txt_203_ground_support->when(FL_WHEN_RELEASE);
					o->end();
					} // Fl_Group* o
					{ Fl_Group* o = new Fl_Group(6, 294, 558, 123, _("b. Service"));
					o->box(FL_THIN_DOWN_BOX);
					o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
						txt_203_service_director = new Fl_Input2(165, 307, 395, 24, _("Director"));
						txt_203_service_director->tooltip(_("Incident name"));
						txt_203_service_director->box(FL_DOWN_BOX);
						txt_203_service_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_service_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_service_director->labeltype(FL_NORMAL_LABEL);
						txt_203_service_director->labelfont(0);
						txt_203_service_director->labelsize(14);
						txt_203_service_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_service_director->align(FL_ALIGN_LEFT);
						txt_203_service_director->when(FL_WHEN_RELEASE);

						txt_203_communications_unit = new Fl_Input2(165, 334, 395, 24, _("Communications Unit"));
						txt_203_communications_unit->tooltip(_("Incident name"));
						txt_203_communications_unit->box(FL_DOWN_BOX);
						txt_203_communications_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_communications_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_communications_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_communications_unit->labelfont(0);
						txt_203_communications_unit->labelsize(14);
						txt_203_communications_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_communications_unit->align(FL_ALIGN_LEFT);
						txt_203_communications_unit->when(FL_WHEN_RELEASE);

						txt_203_medical_unit = new Fl_Input2(165, 362, 395, 24, _("Medical Unit"));
						txt_203_medical_unit->tooltip(_("Incident name"));
						txt_203_medical_unit->box(FL_DOWN_BOX);
						txt_203_medical_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_medical_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_medical_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_medical_unit->labelfont(0);
						txt_203_medical_unit->labelsize(14);
						txt_203_medical_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_medical_unit->align(FL_ALIGN_LEFT);
						txt_203_medical_unit->when(FL_WHEN_RELEASE);

						txt_203_food_unit = new Fl_Input2(165, 390, 395, 24, _("Food Unit"));
						txt_203_food_unit->tooltip(_("Incident name"));
						txt_203_food_unit->box(FL_DOWN_BOX);
						txt_203_food_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_food_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_food_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_food_unit->labelfont(0);
						txt_203_food_unit->labelsize(14);
						txt_203_food_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_food_unit->align(FL_ALIGN_LEFT);
						txt_203_food_unit->when(FL_WHEN_RELEASE);
					o->end();
					} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_logistics->end();
				} // Fl_Group* tab_203_logistics
				{ // tab_203_opsA
				tab_203_opsA = new Fl_Group(0, 95, 570, 325, _("Ops A"));
				tab_203_opsA->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318);
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_ops_chief = new Fl_Input2(132, 111, 425, 24, _("Chief"));
				txt_203_ops_chief->tooltip(_("Incident name"));
				txt_203_ops_chief->box(FL_DOWN_BOX);
				txt_203_ops_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_ops_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_ops_chief->labeltype(FL_NORMAL_LABEL);
				txt_203_ops_chief->labelfont(0);
				txt_203_ops_chief->labelsize(14);
				txt_203_ops_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_ops_chief->align(FL_ALIGN_LEFT);
				txt_203_ops_chief->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_ops_chief
				{ txt_203_ops_deputy = new Fl_Input2(132, 138, 425, 24, _("Deputy"));
				txt_203_ops_deputy->tooltip(_("Incident name"));
				txt_203_ops_deputy->box(FL_DOWN_BOX);
				txt_203_ops_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_ops_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_ops_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_ops_deputy->labelfont(0);
				txt_203_ops_deputy->labelsize(14);
				txt_203_ops_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_ops_deputy->align(FL_ALIGN_LEFT);
				txt_203_ops_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_ops_deputy
				{ Fl_Group* o = new Fl_Group(6, 166, 558, 248, _("Branch I - Division/Groups"));
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_b1_director = new Fl_Input2(132, 190, 425, 24, _("Branch Director"));
				txt_203_b1_director->tooltip(_("Incident name"));
				txt_203_b1_director->box(FL_DOWN_BOX);
				txt_203_b1_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b1_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b1_director->labeltype(FL_NORMAL_LABEL);
				txt_203_b1_director->labelfont(0);
				txt_203_b1_director->labelsize(14);
				txt_203_b1_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b1_director->align(FL_ALIGN_LEFT);
				txt_203_b1_director->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b1_director
				{ txt_203_b1_deputy = new Fl_Input2(133, 221, 425, 24, _("Deputy"));
				txt_203_b1_deputy->tooltip(_("Incident name"));
				txt_203_b1_deputy->box(FL_DOWN_BOX);
				txt_203_b1_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b1_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b1_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_b1_deputy->labelfont(0);
				txt_203_b1_deputy->labelsize(14);
				txt_203_b1_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b1_deputy->align(FL_ALIGN_LEFT);
				txt_203_b1_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b1_deputy
				for (int i = 0; i < 5; i++) {
					// Fl_Input2* txt_203_b1_div[i]
					txt_203_b1_div[i] = new Fl_Input2(134, 250 + i*23, 161, 24, i == 0 ? _("Division / Group"):"");
					txt_203_b1_div[i]->tooltip(_("division"));
					txt_203_b1_div[i]->box(FL_DOWN_BOX);
					txt_203_b1_div[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_b1_div[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_b1_div[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_b1_div[i]->labelfont(0);
					txt_203_b1_div[i]->labelsize(14);
					txt_203_b1_div[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_b1_div[i]->align(FL_ALIGN_LEFT);
					txt_203_b1_div[i]->when(FL_WHEN_RELEASE);
					// Fl_Input2* txt_203_b1_grp[i]
					txt_203_b1_grp[i] = new Fl_Input2(297, 250 + i*23, 261, 24);
					txt_203_b1_grp[i]->tooltip(_("group"));
					txt_203_b1_grp[i]->box(FL_DOWN_BOX);
					txt_203_b1_grp[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_b1_grp[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_b1_grp[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_b1_grp[i]->labelfont(0);
					txt_203_b1_grp[i]->labelsize(14);
					txt_203_b1_grp[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_b1_grp[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
					txt_203_b1_grp[i]->when(FL_WHEN_RELEASE);
				}
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsA->end();
			  } // Fl_Group* tab_203_opsA
				{ // tab_203_opsB
				tab_203_opsB = new Fl_Group(0, 95, 570, 325, _("Ops B"));
				tab_203_opsB->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Branch II - Divisions/Groups"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 127, 558, 248);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_b2_director = new Fl_Input2(132, 143, 425, 24, _("Branch Director"));
				txt_203_b2_director->tooltip(_("Director"));
				txt_203_b2_director->box(FL_DOWN_BOX);
				txt_203_b2_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_director->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_director->labelfont(0);
				txt_203_b2_director->labelsize(14);
				txt_203_b2_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_director->align(FL_ALIGN_LEFT);
				txt_203_b2_director->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b2_director
				{ txt_203_b2_deputy = new Fl_Input2(132, 174, 425, 24, _("Deputy"));
				txt_203_b2_deputy->tooltip(_("Deputy"));
				txt_203_b2_deputy->box(FL_DOWN_BOX);
				txt_203_b2_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_deputy->labelfont(0);
				txt_203_b2_deputy->labelsize(14);
				txt_203_b2_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_deputy->align(FL_ALIGN_LEFT);
				txt_203_b2_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b2_deputy
				for (int i = 0; i < 5; i++) {
				txt_203_b2_div[i] = new Fl_Input2(132, 203 + i*33, 161, 24, _("Division / Group"));
				txt_203_b2_div[i]->tooltip(_("division"));
				txt_203_b2_div[i]->box(FL_DOWN_BOX);
				txt_203_b2_div[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_div[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_div[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_div[i]->labelfont(0);
				txt_203_b2_div[i]->labelsize(14);
				txt_203_b2_div[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_div[i]->align(FL_ALIGN_LEFT);
				txt_203_b2_div[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_203_b2_div[i]
				txt_203_b2_grp[i] = new Fl_Input2(295, 203 + i*33, 261, 24);
				txt_203_b2_grp[i]->tooltip(_("group"));
				txt_203_b2_grp[i]->box(FL_DOWN_BOX);
				txt_203_b2_grp[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_grp[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_grp[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_grp[i]->labelfont(0);
				txt_203_b2_grp[i]->labelsize(14);
				txt_203_b2_grp[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_grp[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
				txt_203_b2_grp[i]->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b2_grp[i]
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsB->end();
			  } // Fl_Group* tab_203_opsB
				{ // tab_203_opsC
				tab_203_opsC = new Fl_Group(0, 95, 570, 325, _("OPs C"));
				tab_203_opsC->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Branch III - Divisions/Groups"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 127, 558, 248);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_b3_director = new Fl_Input2(132, 143, 425, 24, _("Branch Director"));
				txt_203_b3_director->tooltip(_("Incident name"));
				txt_203_b3_director->box(FL_DOWN_BOX);
				txt_203_b3_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_director->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_director->labelfont(0);
				txt_203_b3_director->labelsize(14);
				txt_203_b3_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_director->align(FL_ALIGN_LEFT);
				txt_203_b3_director->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b3_director
				{ txt_203_b3_deputy = new Fl_Input2(132, 174, 425, 24, _("Deputy"));
				txt_203_b3_deputy->tooltip(_("Incident name"));
				txt_203_b3_deputy->box(FL_DOWN_BOX);
				txt_203_b3_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_deputy->labelfont(0);
				txt_203_b3_deputy->labelsize(14);
				txt_203_b3_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_deputy->align(FL_ALIGN_LEFT);
				txt_203_b3_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b3_deputy
				for (int i = 0; i < 5; i++) {
				txt_203_b3_div[i] = new Fl_Input2(132, 203, 161, 24, _("Division / Group"));
				txt_203_b3_div[i]->tooltip(_("Division"));
				txt_203_b3_div[i]->box(FL_DOWN_BOX);
				txt_203_b3_div[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_div[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_div[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_div[i]->labelfont(0);
				txt_203_b3_div[i]->labelsize(14);
				txt_203_b3_div[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_div[i]->align(FL_ALIGN_LEFT);
				txt_203_b3_div[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_203_b3_div[i]
				txt_203_b3_grp[i] = new Fl_Input2(295, 203, 261, 24);
				txt_203_b3_grp[i]->tooltip(_("Group"));
				txt_203_b3_grp[i]->box(FL_DOWN_BOX);
				txt_203_b3_grp[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_grp[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_grp[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_grp[i]->labelfont(0);
				txt_203_b3_grp[i]->labelsize(14);
				txt_203_b3_grp[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_grp[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
				txt_203_b3_grp[i]->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b3_grp[i]
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsC->end();
			  } // Fl_Group* tab_203_opsC
				{ // tab_203_opsD
				tab_203_opsD = new Fl_Group(0, 95, 570, 325, _("OPs D"));
				tab_203_opsD->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Air Operations Branch"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 130, 558, 183);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_air_ops_br_dir = new Fl_Input2(228, 146, 300, 24, _("Air Operations Br. Dir."));
				txt_203_air_ops_br_dir->tooltip(_("Incident name"));
				txt_203_air_ops_br_dir->box(FL_DOWN_BOX);
				txt_203_air_ops_br_dir->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_ops_br_dir->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_ops_br_dir->labeltype(FL_NORMAL_LABEL);
				txt_203_air_ops_br_dir->labelfont(0);
				txt_203_air_ops_br_dir->labelsize(14);
				txt_203_air_ops_br_dir->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_ops_br_dir->align(FL_ALIGN_LEFT);
				txt_203_air_ops_br_dir->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_ops_br_dir
				{ txt_203_air_tactical_group_sup = new Fl_Input2(228, 177, 300, 24, _("Air Tactical Group Sup."));
				txt_203_air_tactical_group_sup->tooltip(_("Incident name"));
				txt_203_air_tactical_group_sup->box(FL_DOWN_BOX);
				txt_203_air_tactical_group_sup->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_tactical_group_sup->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_tactical_group_sup->labeltype(FL_NORMAL_LABEL);
				txt_203_air_tactical_group_sup->labelfont(0);
				txt_203_air_tactical_group_sup->labelsize(14);
				txt_203_air_tactical_group_sup->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_tactical_group_sup->align(FL_ALIGN_LEFT);
				txt_203_air_tactical_group_sup->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_tactical_group_sup
				{ txt_203_air_support_group_sup = new Fl_Input2(228, 206, 300, 24, _("Air Support Group Sup."));
				txt_203_air_support_group_sup->tooltip(_("Incident name"));
				txt_203_air_support_group_sup->box(FL_DOWN_BOX);
				txt_203_air_support_group_sup->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_support_group_sup->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_support_group_sup->labeltype(FL_NORMAL_LABEL);
				txt_203_air_support_group_sup->labelfont(0);
				txt_203_air_support_group_sup->labelsize(14);
				txt_203_air_support_group_sup->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_support_group_sup->align(FL_ALIGN_LEFT);
				txt_203_air_support_group_sup->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_support_group_sup
				{ txt_203_helicopter_coordinator = new Fl_Input2(228, 239, 300, 24, _("Helicopter Coordinator"));
				txt_203_helicopter_coordinator->tooltip(_("Incident name"));
				txt_203_helicopter_coordinator->box(FL_DOWN_BOX);
				txt_203_helicopter_coordinator->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_helicopter_coordinator->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_helicopter_coordinator->labeltype(FL_NORMAL_LABEL);
				txt_203_helicopter_coordinator->labelfont(0);
				txt_203_helicopter_coordinator->labelsize(14);
				txt_203_helicopter_coordinator->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_helicopter_coordinator->align(FL_ALIGN_LEFT);
				txt_203_helicopter_coordinator->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_helicopter_coordinator
				{ txt_203_air_tanker_fixed_wing = new Fl_Input2(228, 273, 300, 24, _("Air Tanker / Fixed Wing Crd."));
				txt_203_air_tanker_fixed_wing->tooltip(_("Incident name"));
				txt_203_air_tanker_fixed_wing->box(FL_DOWN_BOX);
				txt_203_air_tanker_fixed_wing->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_tanker_fixed_wing->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_tanker_fixed_wing->labeltype(FL_NORMAL_LABEL);
				txt_203_air_tanker_fixed_wing->labelfont(0);
				txt_203_air_tanker_fixed_wing->labelsize(14);
				txt_203_air_tanker_fixed_wing->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_tanker_fixed_wing->align(FL_ALIGN_LEFT);
				txt_203_air_tanker_fixed_wing->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_tanker_fixed_wing
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsD->end();
			  } // Fl_Group* tab_203_opsD
				{ // tab_203_admin
				tab_203_admin = new Fl_Group(0, 95, 570, 326, _("Admin"));
				tab_203_admin->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Finance/Admin Section"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 132, 558, 215);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_finance_chief = new Fl_Input2(230, 148, 300, 24, _("Chief"));
				txt_203_finance_chief->tooltip(_("Incident name"));
				txt_203_finance_chief->box(FL_DOWN_BOX);
				txt_203_finance_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_finance_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_finance_chief->labeltype(FL_NORMAL_LABEL);
				txt_203_finance_chief->labelfont(0);
				txt_203_finance_chief->labelsize(14);
				txt_203_finance_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_finance_chief->align(FL_ALIGN_LEFT);
				txt_203_finance_chief->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_finance_chief
				{ txt_203_finance_deputy = new Fl_Input2(230, 180, 300, 24, _("Deputy"));
				txt_203_finance_deputy->tooltip(_("Incident name"));
				txt_203_finance_deputy->box(FL_DOWN_BOX);
				txt_203_finance_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_finance_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_finance_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_finance_deputy->labelfont(0);
				txt_203_finance_deputy->labelsize(14);
				txt_203_finance_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_finance_deputy->align(FL_ALIGN_LEFT);
				txt_203_finance_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_finance_deputy
				{ txt_203_time_unit = new Fl_Input2(230, 212, 300, 24, _("Time Unit"));
				txt_203_time_unit->tooltip(_("Incident name"));
				txt_203_time_unit->box(FL_DOWN_BOX);
				txt_203_time_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_time_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_time_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_time_unit->labelfont(0);
				txt_203_time_unit->labelsize(14);
				txt_203_time_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_time_unit->align(FL_ALIGN_LEFT);
				txt_203_time_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_time_unit
				{ txt_203_procurement_unit = new Fl_Input2(230, 244, 300, 24, _("Procurement Unit"));
				txt_203_procurement_unit->tooltip(_("Incident name"));
				txt_203_procurement_unit->box(FL_DOWN_BOX);
				txt_203_procurement_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_procurement_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_procurement_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_procurement_unit->labelfont(0);
				txt_203_procurement_unit->labelsize(14);
				txt_203_procurement_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_procurement_unit->align(FL_ALIGN_LEFT);
				txt_203_procurement_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_procurement_unit
				{ txt_203_claims_unit = new Fl_Input2(230, 276, 300, 24, _("Compensation / Claims Unit"));
				txt_203_claims_unit->tooltip(_("Incident name"));
				txt_203_claims_unit->box(FL_DOWN_BOX);
				txt_203_claims_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_claims_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_claims_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_claims_unit->labelfont(0);
				txt_203_claims_unit->labelsize(14);
				txt_203_claims_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_claims_unit->align(FL_ALIGN_LEFT);
				txt_203_claims_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_claims_unit
				{ txt_203_cost_unit = new Fl_Input2(230, 308, 300, 24, _("Cost Unit"));
				txt_203_cost_unit->tooltip(_("Incident name"));
				txt_203_cost_unit->box(FL_DOWN_BOX);
				txt_203_cost_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_cost_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_cost_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_cost_unit->labelfont(0);
				txt_203_cost_unit->labelsize(14);
				txt_203_cost_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_cost_unit->align(FL_ALIGN_LEFT);
				txt_203_cost_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_cost_unit
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_admin->end();
			  } // Fl_Group* tab_203_admin
			tab_ics203_type->end();
			Fl_Group::current()->resizable(tab_ics203_type);
			tab_ics203->end();
			} // Fl_Group* tab_ics203
			{ tab_ics205 = new Fl_Group(0, 70, 570, 355, _("205"));
			tab_ics205->align(FL_ALIGN_TOP_LEFT);
			tab_ics205->hide();
			{ Fl_Group* o = new Fl_Group(2, 76, 566, 67);
			  o->box(FL_ENGRAVED_FRAME);
			  { txt_205_name = new Fl_Input2(113, 80, 450, 24, _("Incident Name"));
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
			  } // Fl_Input2* txt_205_name
			  { txt_205_dt_prepared = new Fl_Input2(97, 112, 155, 24, _("DT/TM Prep\'"));
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
			  } // Fl_Input2* txt_205_dt_prepared
			  { btn_205DateTime1 = new Fl_Button(254, 112, 24, 24, _("..."));
				btn_205DateTime1->tooltip(_("Set today"));
				btn_205DateTime1->callback((Fl_Callback*)cb_btn_205DateTime1);
			  } // Fl_Button* btn_205DateTime1
			  { txt_205_dt_operational = new Fl_Input2(378, 112, 155, 24, _("DT/TM Oper\'"));
				txt_205_dt_operational->tooltip(_("ddhhmm MMM YY of preparation"));
				txt_205_dt_operational->box(FL_DOWN_BOX);
				txt_205_dt_operational->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205_dt_operational->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205_dt_operational->labeltype(FL_NORMAL_LABEL);
				txt_205_dt_operational->labelfont(0);
				txt_205_dt_operational->labelsize(14);
				txt_205_dt_operational->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205_dt_operational->align(FL_ALIGN_LEFT);
				txt_205_dt_operational->when(FL_WHEN_RELEASE);
			  } // Fl_Input2* txt_205_dt_operational
			  { btn_205_DateTime2 = new Fl_Button(536, 112, 24, 24, _("..."));
				btn_205_DateTime2->tooltip(_("Set today"));
				btn_205_DateTime2->callback((Fl_Callback*)cb_btn_205_DateTime2);
			  } // Fl_Button* btn_205_DateTime2
			  o->end();
			} // Fl_Group* o
			{ Fl_Group* o = new Fl_Group(2, 145, 566, 245);
			  o->box(FL_ENGRAVED_FRAME);
			  for (int i = 0; i < 8; i++ ) {
				txt_205_type[i] = new Fl_Input2(5, 166 + i*28, 90, 24, i == 0 ? _("Sys\' / Cache"):"");
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
				// Fl_Input2* txt_205_type[i]
				txt_205_channel[i] = new Fl_Input2(97, 166 + i*28, 63, 24, i == 0 ? _("Channel"):"");
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
				// Fl_Input2* txt_205_channel[i]
				txt_205_function[i] = new Fl_Input2(164, 166 + i*28, 80, 24, i == 0 ?_("Function"):"");
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
				// Fl_Input2* txt_205_function[i]
				txt_205_freqtone[i] = new Fl_Input2(247, 166 + i*28, 80, 24, i == 0 ? _("Freq/Tone"):"");
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
				// Fl_Input2* txt_205_freqtone[i]
				txt_205_assignment[i] = new Fl_Input2(330, 166 + i*28, 90, 24, i == 0 ? _("Assignment"):"");
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
				// Fl_Input2* txt_205_assignment[i]
				txt_205_remarks[i] = new Fl_Input2(422, 167 + i*28, 140, 24, i == 0 ? _("Remarks"):"");
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
				// Fl_Input2* txt_205_remarks[i]
			  }
			  o->end();
			} // Fl_Group* o
			{ Fl_Group* o = new Fl_Group(2, 391, 566, 30);
			  o->box(FL_ENGRAVED_BOX);
			  { txt_205_preparer = new Fl_Input2(77, 394, 485, 24, _("Preparer:"));
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
			  } // Fl_Input2* txt_205_preparer
			  o->end();
			} // Fl_Group* o
			tab_ics205->end();
		  } // Fl_Group* tab_ics205
			{ tab_ics206 = new Fl_Group(0, 70, 570, 355, _("206"));
			tab_ics206->align(FL_ALIGN_TOP_LEFT);
			tab_ics206->hide();
			{ tab_ics206_type = new Fl_Tabs(0, 72, 570, 352);
			  tab_ics206_type->selection_color((Fl_Color)246);
			  tab_ics206_type->align(FL_ALIGN_TOP_LEFT);
			  { tab_206_med_plan = new Fl_Group(0, 95, 570, 325, _("Med Plan"));
				{ Fl_Group* o = new Fl_Group(2, 100, 566, 80);
				o->box(FL_ENGRAVED_FRAME);
				{ txt_206_name = new Fl_Input2(9, 119, 242, 24, _("Incident Name"));
				txt_206_name->tooltip(_("Addressee"));
				txt_206_name->box(FL_DOWN_BOX);
				txt_206_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_name->labeltype(FL_NORMAL_LABEL);
				txt_206_name->labelfont(0);
				txt_206_name->labelsize(14);
				txt_206_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_name->align(FL_ALIGN_TOP_LEFT);
				txt_206_name->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_206_name
				{ txt_206_op_period = new Fl_Input2(151, 147, 410, 24, _("Operational Period:"));
				txt_206_op_period->tooltip(_("Subject"));
				txt_206_op_period->box(FL_DOWN_BOX);
				txt_206_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_op_period->labeltype(FL_NORMAL_LABEL);
				txt_206_op_period->labelfont(0);
				txt_206_op_period->labelsize(14);
				txt_206_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_op_period->align(FL_ALIGN_LEFT);
				txt_206_op_period->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_206_op_period
				{ txt_206_time_prepared = new Fl_Input2(407, 117, 103, 24, _("Time Prepared"));
				txt_206_time_prepared->tooltip(_("Time of origination"));
				txt_206_time_prepared->box(FL_DOWN_BOX);
				txt_206_time_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_time_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_time_prepared->labeltype(FL_NORMAL_LABEL);
				txt_206_time_prepared->labelfont(0);
				txt_206_time_prepared->labelsize(14);
				txt_206_time_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_time_prepared->align(FL_ALIGN_TOP_LEFT);
				txt_206_time_prepared->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_206_time_prepared
				{ btn_206_time = new Fl_Button(517, 119, 20, 20, _("..."));
				btn_206_time->tooltip(_("Set time now"));
				btn_206_time->callback((Fl_Callback*)cb_btn_206_time);
				} // Fl_Button* btn_206_time
				{ txt_206_date_prepared = new Fl_DateInput(256, 118, 125, 24, _("Date Prepared"));
				txt_206_date_prepared->tooltip(_("Date of origination"));
				txt_206_date_prepared->box(FL_DOWN_BOX);
				txt_206_date_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_date_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_date_prepared->labeltype(FL_NORMAL_LABEL);
				txt_206_date_prepared->labelfont(0);
				txt_206_date_prepared->labelsize(14);
				txt_206_date_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_date_prepared->align(FL_ALIGN_TOP_LEFT);
				txt_206_date_prepared->when(FL_WHEN_RELEASE);
				} // Fl_DateInput* txt_206_date_prepared
				{ btn_206_date = new Fl_Button(383, 119, 20, 20, _("..."));
				btn_206_date->tooltip(_("Set today"));
				btn_206_date->callback((Fl_Callback*)cb_btn_206_date);
				} // Fl_Button* btn_206_date
				o->end();
				} // Fl_Group* o
				{ Fl_Group* o = new Fl_Group(2, 180, 566, 210);
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT);
				for (int i = 0; i < 5; i++) {
				txt_206_medaid_sta[i] = new Fl_Input2(7, 206 + i*38, 160, 24, i == 0 ? _("Medical Aid Stations"):"");
				txt_206_medaid_sta[i]->tooltip(_(""));
				txt_206_medaid_sta[i]->box(FL_DOWN_BOX);
				txt_206_medaid_sta[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_medaid_sta[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_medaid_sta[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_medaid_sta[i]->labelfont(0);
				txt_206_medaid_sta[i]->labelsize(14);
				txt_206_medaid_sta[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_medaid_sta[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_medaid_sta[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_medaid_sta[i]
				txt_206_medaid_loc[i] = new Fl_Input2(169, 206 + i*38, 370, 24, i == 0 ? _("Location"):"");
				txt_206_medaid_loc[i]->tooltip(_(""));
				txt_206_medaid_loc[i]->box(FL_DOWN_BOX);
				txt_206_medaid_loc[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_medaid_loc[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_medaid_loc[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_medaid_loc[i]->labelfont(0);
				txt_206_medaid_loc[i]->labelsize(14);
				txt_206_medaid_loc[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_medaid_loc[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_medaid_loc[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_medaid_loc[i]
				btn_206_medaid_paramedics[i] = new Fl_Check_Button(540, 206 + i*38, 20, 22, i == 0 ? _("Paramedics"):"");
				btn_206_medaid_paramedics[i]->down_box(FL_DOWN_BOX);
				btn_206_medaid_paramedics[i]->align(FL_ALIGN_TOP_RIGHT);
				} // Fl_Check_Button* btn_206_medaid_paramedics[i]
				o->end();
				} // Fl_Group* o
				{ Fl_Group* o = new Fl_Group(2, 390, 566, 30);
				o->box(FL_ENGRAVED_FRAME);
				{ txt_206_preparer = new Fl_Input2(71, 393, 210, 24, _("Preparer"));
				txt_206_preparer->tooltip(_("Addressee"));
				txt_206_preparer->box(FL_DOWN_BOX);
				txt_206_preparer->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_preparer->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_preparer->labeltype(FL_NORMAL_LABEL);
				txt_206_preparer->labelfont(0);
				txt_206_preparer->labelsize(14);
				txt_206_preparer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_preparer->align(FL_ALIGN_LEFT);
				txt_206_preparer->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_206_preparer
				{ txt_206_reviewer = new Fl_Input2(353, 393, 210, 24, _("Reviewer"));
				txt_206_reviewer->tooltip(_("Addressee"));
				txt_206_reviewer->box(FL_DOWN_BOX);
				txt_206_reviewer->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_reviewer->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_reviewer->labeltype(FL_NORMAL_LABEL);
				txt_206_reviewer->labelfont(0);
				txt_206_reviewer->labelsize(14);
				txt_206_reviewer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_reviewer->align(FL_ALIGN_LEFT);
				txt_206_reviewer->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_206_reviewer
				o->end();
				} // Fl_Group* o
				tab_206_med_plan->end();
			  } // Fl_Group* tab_206_med_plan
			  { tab_206_transport = new Fl_Group(0, 95, 570, 325, _("Transport"));
				tab_206_transport->hide();
				{ Fl_Group* o = new Fl_Group(2, 105, 566, 238, _("Ambulance Services"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				for (int i = 0; i < 5; i++) {
				txt_206_transport_name[i] = new Fl_Input2(7, 150 + i*38, 125, 24, i == 0 ? _("Service Name"):"");
				txt_206_transport_name[i]->tooltip(_(""));
				txt_206_transport_name[i]->box(FL_DOWN_BOX);
				txt_206_transport_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_transport_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_transport_name[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_transport_name[i]->labelfont(0);
				txt_206_transport_name[i]->labelsize(14);
				txt_206_transport_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_transport_name[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_transport_name[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_transport_name[i]
				txt_206_transport_address[i] = new Fl_Input2(135, 150 + i*38, 280, 24, i == 0 ? _("Address"):"");
				txt_206_transport_address[i]->tooltip(_(""));
				txt_206_transport_address[i]->box(FL_DOWN_BOX);
				txt_206_transport_address[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_transport_address[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_transport_address[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_transport_address[i]->labelfont(0);
				txt_206_transport_address[i]->labelsize(14);
				txt_206_transport_address[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_transport_address[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_transport_address[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_transport_address[i]
				btn_206_transport_paramedics[i] = new Fl_Check_Button(540, 150 + i*38, 20, 22, i == 0 ? _("Paramedics"):"");
				btn_206_transport_paramedics[i]->down_box(FL_DOWN_BOX);
				btn_206_transport_paramedics[i]->align(FL_ALIGN_TOP_RIGHT);
				// Fl_Check_Button* btn_206_transport_paramedics[i]
				txt_206_transport_phone[i] = new Fl_Input2(417, 150 + i*38, 121, 24, i == 0 ? _("Phone"):"");
				txt_206_transport_phone[i]->tooltip(_(""));
				txt_206_transport_phone[i]->box(FL_DOWN_BOX);
				txt_206_transport_phone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_transport_phone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_transport_phone[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_transport_phone[i]->labelfont(0);
				txt_206_transport_phone[i]->labelsize(14);
				txt_206_transport_phone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_transport_phone[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_transport_phone[i]->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_206_transport_phone[i]
				o->end();
				} // Fl_Group* o
				tab_206_transport->end();
			  } // Fl_Group* tab_206_transport
			  { tab_206_ambulance = new Fl_Group(0, 95, 570, 325, _("Ambulance"));
				tab_206_ambulance->hide();
				{ Fl_Group* o = new Fl_Group(2, 100, 565, 235, _("Indicent Ambulances"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				for (int i = 0; i < 5; i++) {
				txt_206_ambulance_name[i] = new Fl_Input2(8, 147 + i*38, 160, 24, i == 0 ? _("Name"):"");
				txt_206_ambulance_name[i]->tooltip(_(""));
				txt_206_ambulance_name[i]->box(FL_DOWN_BOX);
				txt_206_ambulance_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_ambulance_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_ambulance_name[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_ambulance_name[i]->labelfont(0);
				txt_206_ambulance_name[i]->labelsize(14);
				txt_206_ambulance_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_ambulance_name[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_ambulance_name[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_ambulance_name[i]
				txt_206_ambulance_loc[i] = new Fl_Input2(170, 147 + i*38, 370, 24, i == 0 ? _("Location"):"");
				txt_206_ambulance_loc[i]->tooltip(_(""));
				txt_206_ambulance_loc[i]->box(FL_DOWN_BOX);
				txt_206_ambulance_loc[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_ambulance_loc[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_ambulance_loc[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_ambulance_loc[i]->labelfont(0);
				txt_206_ambulance_loc[i]->labelsize(14);
				txt_206_ambulance_loc[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_ambulance_loc[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_ambulance_loc[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_ambulance_loc[i]
				btn_206_ambulance_paramedics[i] = new Fl_Check_Button(541, 147 + i*38, 20, 22, i == 0 ? _("Paramedics"):"");
				btn_206_ambulance_paramedics[i]->down_box(FL_DOWN_BOX);
				btn_206_ambulance_paramedics[i]->align(FL_ALIGN_TOP_RIGHT);
				} // Fl_Check_Button* btn_206_ambulance_paramedics[i]
				o->end();
				} // Fl_Group* o
				tab_206_ambulance->end();
			  } // Fl_Group* tab_206_ambulance
			  { tab_206_hospital = new Fl_Group(0, 95, 570, 325, _("Hospital"));
				tab_206_hospital->hide();
				{ Fl_Group* o = new Fl_Group(2, 101, 566, 318, _("Hospitals"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				for (int i = 0; i < 5; i++) {
				txt_206_hosp_name[i] = new Fl_Input2(9, 146 + i*54, 125, 24, i == 0 ? _("Name"):"");
				txt_206_hosp_name[i]->tooltip(_(""));
				txt_206_hosp_name[i]->box(FL_DOWN_BOX);
				txt_206_hosp_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_hosp_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_hosp_name[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_hosp_name[i]->labelfont(0);
				txt_206_hosp_name[i]->labelsize(14);
				txt_206_hosp_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_hosp_name[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_hosp_name[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_hosp_name[i]
				txt_206_hosp_address[i] = new Fl_Input2(137, 146 + i*54, 300, 24, i == 0 ? _("Address"):"");
				txt_206_hosp_address[i]->tooltip(_(""));
				txt_206_hosp_address[i]->box(FL_DOWN_BOX);
				txt_206_hosp_address[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_hosp_address[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_hosp_address[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_hosp_address[i]->labelfont(0);
				txt_206_hosp_address[i]->labelsize(14);
				txt_206_hosp_address[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_hosp_address[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_hosp_address[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_hosp_address[i]
				txt_206_hosp_phone[i] = new Fl_Input2(440, 146 + i*54, 121, 24, i == 0 ? _("Phone"):"");
				txt_206_hosp_phone[i]->tooltip(_(""));
				txt_206_hosp_phone[i]->box(FL_DOWN_BOX);
				txt_206_hosp_phone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_hosp_phone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_hosp_phone[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_hosp_phone[i]->labelfont(0);
				txt_206_hosp_phone[i]->labelsize(14);
				txt_206_hosp_phone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_hosp_phone[i]->align(FL_ALIGN_TOP_LEFT);
				txt_206_hosp_phone[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_hosp_phone[i]
				txt_206_hosp_airtime[i] = new Fl_Input2(136, 174 + i*54, 80, 24, _("Travel Time Air:"));
				txt_206_hosp_airtime[i]->tooltip(_(""));
				txt_206_hosp_airtime[i]->box(FL_DOWN_BOX);
				txt_206_hosp_airtime[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_hosp_airtime[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_hosp_airtime[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_hosp_airtime[i]->labelfont(0);
				txt_206_hosp_airtime[i]->labelsize(14);
				txt_206_hosp_airtime[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_hosp_airtime[i]->align(FL_ALIGN_LEFT);
				txt_206_hosp_airtime[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_hosp_airtime[i]
				txt_206_hosp_gndtime[i] = new Fl_Input2(253, 174 + i*54, 80, 24, _("Gnd"));
				txt_206_hosp_gndtime[i]->tooltip(_(""));
				txt_206_hosp_gndtime[i]->box(FL_DOWN_BOX);
				txt_206_hosp_gndtime[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_hosp_gndtime[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_hosp_gndtime[i]->labeltype(FL_NORMAL_LABEL);
				txt_206_hosp_gndtime[i]->labelfont(0);
				txt_206_hosp_gndtime[i]->labelsize(14);
				txt_206_hosp_gndtime[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_hosp_gndtime[i]->align(FL_ALIGN_LEFT);
				txt_206_hosp_gndtime[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_206_hosp_gndtime[i]
				btn_206_hosp_helipad[i] = new Fl_Check_Button(342, 178 + i*54, 82, 15, _("Helipad"));
				btn_206_hosp_helipad[i]->down_box(FL_DOWN_BOX);
				// Fl_Check_Button* btn_206_hosp_helipad[i]
				btn_206_hosp_burn_center[i] = new Fl_Check_Button(440, 178 + i*54, 107, 15, _("Burn center"));
				btn_206_hosp_burn_center[i]->down_box(FL_DOWN_BOX);
				} // Fl_Check_Button* btn_206_hosp_burn_center[i]
				o->end();
				} // Fl_Group* o
				tab_206_hospital->end();
			  } // Fl_Group* tab_206_hospital
			  { tab_206_med_proc = new Fl_Group(0, 95, 570, 325, _("Med\' Proc\'"));
				tab_206_med_proc->hide();
				{ txt_206_procedure = new FTextEdit(4, 100, 562, 320);
				txt_206_procedure->box(FL_DOWN_FRAME);
				txt_206_procedure->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_206_procedure->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_206_procedure->labeltype(FL_NORMAL_LABEL);
				txt_206_procedure->labelfont(0);
				txt_206_procedure->labelsize(14);
				txt_206_procedure->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_206_procedure->align(FL_ALIGN_CENTER);
				txt_206_procedure->when(FL_WHEN_RELEASE);
				Fl_Group::current()->resizable(txt_206_procedure);
				} // FTextEdit* txt_206_procedure
				tab_206_med_proc->end();
			  } // Fl_Group* tab_206_med_proc
			  tab_ics206_type->end();
			  Fl_Group::current()->resizable(tab_ics206_type);
			} // Fl_Tabs* tab_ics206_type
			tab_ics206->end();
		  } // Fl_Group* tab_ics206
			{ tab_ics213 = new Fl_Group(0, 70, 570, 355, _("213"));
			tab_ics213->align(FL_ALIGN_TOP_LEFT);
			tab_ics213->hide();
			{ tab_ics213_type = new Fl_Tabs(0, 72, 570, 352);
			  tab_ics213_type->selection_color((Fl_Color)246);
			  tab_ics213_type->align(FL_ALIGN_TOP_LEFT);
			  { tab_213_originator = new Fl_Group(0, 95, 570, 325, _("Originator"));
				{ txt_213_to = new Fl_Input2(40, 110, 242, 24, _("To"));
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
				} // Fl_Input2* txt_213_to
				{ txt_213_p1 = new Fl_Input2(321, 110, 242, 24, _("Pos."));
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
				} // Fl_Input2* txt_213_p1
				{ txt_213_fm = new Fl_Input2(40, 136, 242, 24, _("Fm"));
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
				} // Fl_Input2* txt_213_fm
				{ txt_213_p2 = new Fl_Input2(321, 136, 242, 24, _("Pos."));
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
				} // Fl_Input2* txt_213_p2
				{ txt_213_subj = new Fl_Input2(40, 162, 522, 24, _("Sub."));
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
				} // Fl_Input2* txt_213_subj
				{ txt_213_d1 = new Fl_DateInput(232, 188, 125, 24, _("Date"));
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
				} // Fl_DateInput* txt_213_d1
				{ btn_213_date1 = new Fl_Button(365, 190, 20, 20, _("..."));
				btn_213_date1->tooltip(_("Set today"));
				btn_213_date1->callback((Fl_Callback*)cb_btn_213_date1);
				} // Fl_Button* btn_213_date1
				{ txt_213_t1 = new Fl_Input2(430, 188, 103, 24, _("Time"));
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
				} // Fl_Input2* txt_213_t1
				{ btn_213_time1 = new Fl_Button(540, 190, 20, 20, _("..."));
				btn_213_time1->tooltip(_("Set time now"));
				btn_213_time1->callback((Fl_Callback*)cb_btn_213_time1);
				} // Fl_Button* btn_213_time1
				{ txt_213_msg = new FTextEdit(5, 218, 562, 175, _("Message:"));
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
				} // FTextEdit* txt_213_msg
				{ txt_213_s1 = new Fl_Input2(33, 396, 247, 24, _("Sig."));
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
				} // Fl_Input2* txt_213_s1
				{ txt_213_p3 = new Fl_Input2(316, 396, 247, 24, _("Pos."));
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
				} // Fl_Input2* txt_213_p3
				tab_213_originator->end();
			  } // Fl_Group* tab_213_originator
			  { tab_213_responder = new Fl_Group(0, 95, 570, 325, _("Responder"));
				tab_213_responder->hide();
				{ txt_213_s2 = new Fl_Input2(37, 396, 248, 24, _("Sig."));
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
				} // Fl_Input2* txt_213_s2
				{ txt_213_d2 = new Fl_DateInput(243, 112, 126, 24, _("Date"));
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
				} // Fl_DateInput* txt_213_d2
				{ txt_213_t2 = new Fl_Input2(434, 112, 103, 24, _("Time"));
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
				} // Fl_Input2* txt_213_t2
				{ btn_213_time2 = new Fl_Button(540, 112, 24, 24, _("..."));
				btn_213_time2->tooltip(_("Now"));
				btn_213_time2->callback((Fl_Callback*)cb_btn_213_time2);
				} // Fl_Button* btn_213_time2
				{ txt_213_reply = new FTextEdit(5, 142, 562, 250, _("Reply"));
				txt_213_reply->box(FL_DOWN_FRAME);
				txt_213_reply->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_213_reply->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_213_reply->labeltype(FL_NORMAL_LABEL);
				txt_213_reply->labelfont(0);
				txt_213_reply->labelsize(14);
				txt_213_reply->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_213_reply->align(FL_ALIGN_TOP_LEFT);
				txt_213_reply->when(FL_WHEN_RELEASE);
				} // FTextEdit* txt_213_reply
				{ txt_213_p4 = new Fl_Input2(323, 396, 242, 24, _("Pos."));
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
				} // Fl_Input2* txt_213_p4
				{ btn_213_date2 = new Fl_Button(370, 112, 24, 24, _("..."));
				btn_213_date2->tooltip(_("Today"));
				btn_213_date2->callback((Fl_Callback*)cb_btn_213_date2);
				} // Fl_Button* btn_213_date2
				tab_213_responder->end();
				Fl_Group::current()->resizable(tab_213_responder);
			  } // Fl_Group* tab_213_responder
			  tab_ics213_type->end();
			  Fl_Group::current()->resizable(tab_ics213_type);
			} // Fl_Tabs* tab_ics213_type
			tab_ics213->end();
		  } // Fl_Group* tab_ics213
			{ tab_ics214 = new Fl_Group(0, 70, 597, 355, _("214"));
			tab_ics214->align(FL_ALIGN_TOP_LEFT);
			tab_ics214->hide();
			{ tab_ics214_type = new Fl_Tabs(0, 72, 597, 352);
			  tab_ics214_type->align(FL_ALIGN_TOP_LEFT);
			  { tab_214_1 = new Fl_Group(0, 95, 570, 325, _("Incident"));
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 170);
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_214_incident = new Fl_Input2(135, 108, 425, 24, _("Incident Name"));
				txt_214_incident->tooltip(_("Incident name"));
				txt_214_incident->box(FL_DOWN_BOX);
				txt_214_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_214_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_214_incident->labeltype(FL_NORMAL_LABEL);
				txt_214_incident->labelfont(0);
				txt_214_incident->labelsize(14);
				txt_214_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_214_incident->align(FL_ALIGN_LEFT);
				txt_214_incident->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_214_incident
				{ txt_214_date = new Fl_Input2(135, 135, 155, 24, _("Date Prepared"));
				txt_214_date->tooltip(_("Date prepared"));
				txt_214_date->box(FL_DOWN_BOX);
				txt_214_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_214_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_214_date->labeltype(FL_NORMAL_LABEL);
				txt_214_date->labelfont(0);
				txt_214_date->labelsize(14);
				txt_214_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_214_date->align(FL_ALIGN_LEFT);
				txt_214_date->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_214_date
				{ btn_214_date = new Fl_Button(294, 137, 20, 20, _("..."));
				btn_214_date->tooltip(_("Set today"));
				btn_214_date->callback((Fl_Callback*)cb_btn_214_date);
				} // Fl_Button* btn_214_date
				{ txt_214_time = new Fl_Input2(135, 160, 103, 24, _("Time Prepared"));
				txt_214_time->tooltip(_("Time prepared"));
				txt_214_time->box(FL_DOWN_BOX);
				txt_214_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_214_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_214_time->labeltype(FL_NORMAL_LABEL);
				txt_214_time->labelfont(0);
				txt_214_time->labelsize(14);
				txt_214_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_214_time->align(FL_ALIGN_LEFT);
				txt_214_time->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_214_time
				{ btn_214_time = new Fl_Button(247, 162, 20, 20, _("..."));
				btn_214_time->tooltip(_("Set time now"));
				btn_214_time->callback((Fl_Callback*)cb_btn_214_time);
				} // Fl_Button* btn_214_time
				{ txt_214_unit_name = new Fl_Input2(135, 185, 425, 24, _("Unit Name"));
				txt_214_unit_name->tooltip(_("Name / Designation"));
				txt_214_unit_name->box(FL_DOWN_BOX);
				txt_214_unit_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_214_unit_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_214_unit_name->labeltype(FL_NORMAL_LABEL);
				txt_214_unit_name->labelfont(0);
				txt_214_unit_name->labelsize(14);
				txt_214_unit_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_214_unit_name->align(FL_ALIGN_LEFT);
				txt_214_unit_name->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_214_incident
				{ txt_214_unit_leader = new Fl_Input2(135, 210, 425, 24, _("Unit leader"));
				txt_214_unit_leader->tooltip(_("Name and Position"));
				txt_214_unit_leader->box(FL_DOWN_BOX);
				txt_214_unit_leader->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_214_unit_leader->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_214_unit_leader->labeltype(FL_NORMAL_LABEL);
				txt_214_unit_leader->labelfont(0);
				txt_214_unit_leader->labelsize(14);
				txt_214_unit_leader->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_214_unit_leader->align(FL_ALIGN_LEFT);
				txt_214_unit_leader->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_214_incident
				{ txt_214_op_period = new Fl_Input2(135, 235, 425, 24, _("Oper\' Period"));
				txt_214_op_period->tooltip(_("Date / Time"));
				txt_214_op_period->box(FL_DOWN_BOX);
				txt_214_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_214_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_214_op_period->labeltype(FL_NORMAL_LABEL);
				txt_214_op_period->labelfont(0);
				txt_214_op_period->labelsize(14);
				txt_214_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_214_op_period->align(FL_ALIGN_LEFT);
				txt_214_op_period->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_214_op_period
				o->end();
				} // Fl_Group* o
				{ Fl_Group* o = new Fl_Group(2, 273, 565, 35);
				o->box(FL_ENGRAVED_FRAME);
				{ txt_214_prepared_by = new Fl_Input2(135, 278, 425, 24, _("Prepared By"));
				txt_214_prepared_by->tooltip(_("Name and Position"));
				txt_214_prepared_by->box(FL_DOWN_BOX);
				txt_214_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_214_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_214_prepared_by->labeltype(FL_NORMAL_LABEL);
				txt_214_prepared_by->labelfont(0);
				txt_214_prepared_by->labelsize(14);
				txt_214_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_214_prepared_by->align(FL_ALIGN_LEFT);
				txt_214_prepared_by->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_214_prepared_by
				o->end();
				} // Fl_Group* o
				tab_214_1->end();
			  } // Fl_Group* tab_214_1
			  { tab_214_2 = new Fl_Group(0, 95, 597, 325, _("Roster"));
				tab_214_2->hide();
				{ Fl_Box* o = new Fl_Box(5, 106, 180, 20, _("Name"));
				o->box(FL_THIN_DOWN_BOX);
				o->color((Fl_Color)215);
				} // Fl_Box* o
				{ Fl_Box* o = new Fl_Box(186, 106, 180, 20, _("ICS Position"));
				o->box(FL_THIN_DOWN_BOX);
				o->color((Fl_Color)215);
				} // Fl_Box* o
				{ Fl_Box* o = new Fl_Box(367, 106, 180, 20, _("Home Base"));
				o->box(FL_THIN_DOWN_BOX);
				o->color((Fl_Color)215);
				} // Fl_Box* o
				{ Fl_Scroll* o = new Fl_Scroll(4, 128, 560, 290);
				o->type(2);
				o->box(FL_THIN_DOWN_BOX);
				o->color((Fl_Color)215);
				for (int i = 0; i < 16; i++) {
					txt_214_roster_name[i] = new Fl_Input2(5, 130 + i*24, 180, 24);
					txt_214_roster_name[i]->tooltip(_(""));
					txt_214_roster_name[i]->box(FL_DOWN_BOX);
					txt_214_roster_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_214_roster_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_214_roster_name[i]->labeltype(FL_NORMAL_LABEL);
					txt_214_roster_name[i]->labelfont(0);
					txt_214_roster_name[i]->labelsize(14);
					txt_214_roster_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_214_roster_name[i]->align(FL_ALIGN_CENTER);
					txt_214_roster_name[i]->when(FL_WHEN_RELEASE);
					txt_214_roster_position[i] = new Fl_Input2(186, 130 + i*24, 180, 24);
					txt_214_roster_position[i]->tooltip(_(""));
					txt_214_roster_position[i]->box(FL_DOWN_BOX);
					txt_214_roster_position[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_214_roster_position[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_214_roster_position[i]->labeltype(FL_NORMAL_LABEL);
					txt_214_roster_position[i]->labelfont(0);
					txt_214_roster_position[i]->labelsize(14);
					txt_214_roster_position[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_214_roster_position[i]->align(FL_ALIGN_CENTER);
					txt_214_roster_position[i]->when(FL_WHEN_RELEASE);
					txt_214_roster_home_base[i] = new Fl_Input2(367, 130 + i*24, 180, 24);
					txt_214_roster_home_base[i]->tooltip(_(""));
					txt_214_roster_home_base[i]->box(FL_DOWN_BOX);
					txt_214_roster_home_base[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_214_roster_home_base[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_214_roster_home_base[i]->labeltype(FL_NORMAL_LABEL);
					txt_214_roster_home_base[i]->labelfont(0);
					txt_214_roster_home_base[i]->labelsize(14);
					txt_214_roster_home_base[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_214_roster_home_base[i]->align(FL_ALIGN_CENTER);
					txt_214_roster_home_base[i]->when(FL_WHEN_RELEASE);
				}
				o->end();
				} // Fl_Scroll* o
				tab_214_2->end();
			  } // Fl_Group* tab_214_2
			  { tab_214_3 = new Fl_Group(0, 95, 570, 325, _("Activity Log"));
				tab_214_3->hide();
				tab_214_2->hide();
				{ Fl_Box* o = new Fl_Box(5, 106, 100, 20, _("Time"));
				o->box(FL_THIN_DOWN_BOX);
				o->color((Fl_Color)215);
				} // Fl_Box* o
				{ Fl_Box* o = new Fl_Box(106, 106, 440, 20, _("Major Events"));
				o->box(FL_THIN_DOWN_BOX);
				o->color((Fl_Color)215);
				} // Fl_Box* o
				{ Fl_Scroll* o = new Fl_Scroll(4, 128, 560, 290);
				o->type(2);
				o->box(FL_THIN_DOWN_BOX);
				o->color((Fl_Color)215);
				for (int i = 0; i < 16; i++) {
					txt_214_activity_time[i] = new Fl_Input2(5, 130 + i*24, 100, 24);
					txt_214_activity_time[i]->tooltip(_(""));
					txt_214_activity_time[i]->box(FL_DOWN_BOX);
					txt_214_activity_time[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_214_activity_time[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_214_activity_time[i]->labeltype(FL_NORMAL_LABEL);
					txt_214_activity_time[i]->labelfont(0);
					txt_214_activity_time[i]->labelsize(14);
					txt_214_activity_time[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_214_activity_time[i]->align(FL_ALIGN_CENTER);
					txt_214_activity_time[i]->when(FL_WHEN_RELEASE);
					txt_214_activity_event[i] = new Fl_Input2(106, 130 + i*24, 442, 24);
					txt_214_activity_event[i]->tooltip(_(""));
					txt_214_activity_event[i]->box(FL_DOWN_BOX);
					txt_214_activity_event[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_214_activity_event[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_214_activity_event[i]->labeltype(FL_NORMAL_LABEL);
					txt_214_activity_event[i]->labelfont(0);
					txt_214_activity_event[i]->labelsize(14);
					txt_214_activity_event[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_214_activity_event[i]->align(FL_ALIGN_CENTER);
					txt_214_activity_event[i]->when(FL_WHEN_RELEASE);
				}
				o->end();
				} // Fl_Scroll* o
				tab_214_3->end();
			  } // Fl_Group* tab_214_3
			  tab_ics214_type->end();
			  Fl_Group::current()->resizable(tab_ics214_type);
			} // Fl_Tabs* tab_ics214_type
			tab_ics214->end();
			} // Fl_Group* tab_ics214
			{ tab_ics216 = new Fl_Group(0, 70, 597, 355, _("216"));
			tab_ics216->align(FL_ALIGN_TOP_LEFT);
			tab_ics216->hide();
			{ 	tab_ics216_type = new Fl_Tabs(0, 72, 597, 352);
				tab_ics216_type->align(FL_ALIGN_TOP_LEFT);
				{ tab_216_1 = new Fl_Group(0, 95, 570, 325, _("Incident"));
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 190);
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_216_incident = new Fl_Input2(135, 108, 425, 24, _("1.Incident Name"));
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
				} // Fl_Input2* txt_216_incident
				{ txt_216_date = new Fl_Input2(135, 135, 155, 24, _("2. Date"));
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
				} // Fl_Input2* txt_216_date
				{ btn_216_date = new Fl_Button(294, 137, 20, 20, _("..."));
				btn_216_date->tooltip(_("Set today"));
				btn_216_date->callback((Fl_Callback*)cb_btn_216_date);
				} // Fl_Button* btn_216_date
				{ txt_216_time = new Fl_Input2(135, 160, 103, 24, _("3. Time"));
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
				} // Fl_Input2* txt_216_time
				{ btn_216_time = new Fl_Button(247, 162, 20, 20, _("..."));
				btn_216_time->tooltip(_("Set time now"));
				btn_216_time->callback((Fl_Callback*)cb_btn_216_time);
				} // Fl_Button* btn_216_time
				{ txt_216_branch = new Fl_Input2(135, 185, 425, 24, _("4. Branch"));
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
				} // Fl_Input2* txt_216_incident
				{ txt_216_agc = new Fl_Input2(135, 210, 425, 24, _("5. Agency"));
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
				} // Fl_Input2* txt_216_incident
				{ txt_216_op_period = new Fl_Input2(135, 235, 425, 24, _("6. Oper\' Period"));
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
				} // Fl_Input2* txt_216_op_period
				{ txt_216_tac_freq = new Fl_Input2(135, 260, 425, 24, _("7. Tac\' Freq\'"));
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
				} // Fl_Input2* txt_216_tac_freq
				o->end();
				} // Fl_Group* o
				{ Fl_Group* o = new Fl_Group(2, 294, 565, 35);
				o->box(FL_ENGRAVED_FRAME);
				{ txt_216_prepared_by = new Fl_Input2(135, 296, 425, 24, _("Prepared By"));
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
				} // Fl_Input2* txt_216_prepared_by
				o->end();
				} // Fl_Group* o
				tab_216_1->end();
			  } // Fl_Group* tab_216_1
				{ tab_216_2 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 1"));
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
						txt_216_ag[j] = new Fl_Input2(5, y, 180, 24,
							i == 0 ? "Agency" : "");
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

						txt_216_id[j] = new Fl_Input2(186, y, 100, 24,
							i == 0 ? "ID No." : "");
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

						txt_216_rr[j] = new Fl_Input2(287, y, 280, 24,
							i == 0 ? "Radio Requirements" : "");
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
				} // Fl_Group* tab_216_2
				{ tab_216_3 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 2"));
					tab_216_3->hide();
					int y = 105;

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
						txt_216_ag[j] = new Fl_Input2(5, y, 180, 24,
							i == 0 ? "Agency" : "");
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

						txt_216_id[j] = new Fl_Input2(186, y, 100, 24,
							i == 0 ? "ID No." : "");
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

						txt_216_rr[j] = new Fl_Input2(287, y, 280, 24,
							i == 0 ? "Radio Requirements" : "");
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
						} // for
						tab_216_3->end();
					} // Fl_Group* tab_216_3
				{ tab_216_4 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 3"));
					tab_216_4->hide();
					int y = 105;

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
						txt_216_ag[j] = new Fl_Input2(5, y, 180, 24,
							i == 0 ? "Agency" : "");
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

						txt_216_id[j] = new Fl_Input2(186, y, 100, 24,
							i == 0 ? "ID No." : "");
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

						txt_216_rr[j] = new Fl_Input2(287, y, 280, 24,
							i == 0 ? "Radio Requirements" : "");
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
						} // for
						tab_216_4->end();
					} // Fl_Group* tab_216_4
				{ tab_216_5 = new Fl_Group(0, 95, 570, 325, _("Div-Grp 4"));
					tab_216_5->hide();
					int y = 105;

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
					for (int i = 0, j = 26; i < 9; i++, j++) {
						txt_216_ag[j] = new Fl_Input2(5, y, 180, 24,
							i == 0 ? "Agency" : "");
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

						txt_216_id[j] = new Fl_Input2(186, y, 100, 24,
							i == 0 ? "ID No." : "");
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

						txt_216_rr[j] = new Fl_Input2(287, y, 280, 24,
							i == 0 ? "Radio Requirements" : "");
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
						} // for
						tab_216_5->end();
					} // Fl_Group* tab_216_5
			} // Fl_Group* tab_ics
				tab_ics216->end();
			} // Fl_Group* tab_ics216
		Fl_Group::current()->resizable(tab_ics216_type);
		tab_ics_type->end();
		tab_ics->end();
		} // Fl_Tabs* tab_ics
		{ // tab_radiogram
		tab_radiogram = new Fl_Group(0, 45, 570, 380, _("Radiogram"));
		tab_radiogram->hide();
		{ tabs_radiogram = new Fl_Tabs(0, 45, 570, 380);
		  tabs_radiogram->selection_color((Fl_Color)246);
		  { tab_radiogram_message = new Fl_Group(0, 70, 570, 355, _("Message"));
			{ txt_rg_nbr = new Fl_Input2(36, 96, 50, 24, _("*NR"));
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
			} // Fl_Input2* txt_rg_nbr
			{ sel_rg_prec = new Fl_Choice(88, 96, 120, 24, _("*PREC"));
			  sel_rg_prec->tooltip(_("Message Precedence"));
			  sel_rg_prec->down_box(FL_BORDER_BOX);
			  sel_rg_prec->align(FL_ALIGN_TOP);
			} // Fl_Choice* sel_rg_prec
			{ txt_rg_hx = new Fl_Input2(210, 96, 95, 24, _("HX__"));
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
			} // Fl_Input2* txt_rg_hx
			{ btn_rg_hx = new Fl_Button(308, 96, 24, 24, _("hx"));
			  btn_rg_hx->tooltip(_("Open HX dialog"));
			  btn_rg_hx->callback((Fl_Callback*)cb_btn_rg_hx);
			} // Fl_Button* btn_rg_hx
			{ txt_rg_station = new Fl_Input2(336, 96, 101, 24, _("*STN ORIG"));
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
			} // Fl_Input2* txt_rg_station
			{ txt_rg_place = new Fl_Input2(6, 137, 266, 24, _("PLACE OF ORIG"));
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
			} // Fl_Input2* txt_rg_place
			{ txt_rg_t1 = new Fl_Input2(288, 137, 81, 24, _("TIME FILED"));
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
			} // Fl_Input2* txt_rg_t1
			{ btn_rgTime1 = new Fl_Button(372, 137, 24, 24, _("..."));
			  btn_rgTime1->tooltip(_("Set time now"));
			  btn_rgTime1->callback((Fl_Callback*)cb_btn_rgTime1);
			} // Fl_Button* btn_rgTime1
			{ txt_rg_d1 = new Fl_Input2(416, 137, 123, 24, _("*MON DY"));
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
			} // Fl_Input2* txt_rg_d1
			{ btn_rgDate1 = new Fl_Button(541, 137, 24, 24, _("..."));
			  btn_rgDate1->tooltip(_("Set today"));
			  btn_rgDate1->callback((Fl_Callback*)cb_btn_rgDate1);
			} // Fl_Button* btn_rgDate1
			{ txt_rg_to = new Fl_Input2(6, 179, 277, 70, _("*TO"));
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
			} // Fl_Input2* txt_rg_to
			{ txt_rg_phone = new Fl_Input2(327, 176, 238, 24, _("TEL:"));
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
			} // Fl_Input2* txt_rg_phone
			{ txt_rg_opnote = new Fl_Input2(360, 203, 205, 24, _("OP NOTE:"));
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
			} // Fl_Input2* txt_rg_opnote
			{ txt_rg_msg = new FTextEdit(4, 271, 562, 119, _("TXT:"));
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
			} // FTextEdit* txt_rg_msg
			{ btn_arl = new Fl_Button(489, 238, 76, 24, _("ARL MSG"));
			  btn_arl->tooltip(_("ARL message selector"));
			  btn_arl->callback((Fl_Callback*)cb_btn_arl);
			} // Fl_Button* btn_arl
			{ txt_rg_check = new Fl_Input2(439, 96, 101, 24, _("CK"));
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
			} // Fl_Input2* txt_rg_check
			{ btn_rg_check = new Fl_Button(541, 96, 24, 24, _("ck"));
			  btn_rg_check->tooltip(_("Compute check count"));
			  btn_rg_check->callback((Fl_Callback*)cb_btn_rg_check);
			} // Fl_Button* btn_rg_check
			{ txt_rg_sig = new Fl_Input2(48, 396, 238, 24, _("SIG:"));
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
			} // Fl_Input2* txt_rg_sig
			{ txt_rg_opnote2 = new Fl_Input2(364, 396, 201, 24, _("OP NOTE:"));
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
			} // Fl_Input2* txt_rg_opnote2
			{ btn_rg_svc = new Fl_Check_Button(12, 100, 17, 15, _("SVC"));
			  btn_rg_svc->tooltip(_("Check for Service Message"));
			  btn_rg_svc->down_box(FL_DOWN_BOX);
			  btn_rg_svc->align(FL_ALIGN_TOP);
			} // Fl_Check_Button* btn_rg_svc
			tab_radiogram_message->end();
		  } // Fl_Group* tab_radiogram_message
		  { tab_radiogram_information = new Fl_Group(0, 70, 570, 355, _("Records"));
			tab_radiogram_information->hide();
			{ Fl_Group* o = new Fl_Group(5, 113, 560, 140, _("ORIG - FM - DATE/TIME"));
			  o->box(FL_ENGRAVED_FRAME);
			  o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
			  { txt_rg_orig = new Fl_Input2(10, 148, 550, 100, _("Name/Addr/City/Tel"));
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
			  } // Fl_Input2* txt_rg_orig
			  { txt_rg_dt2 = new Fl_Input2(381, 119, 152, 24, _("DT/TM"));
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
			  } // Fl_Input2* txt_rg_dt2
			  { btn_rgDateTime2 = new Fl_Button(536, 119, 24, 24, _("..."));
				btn_rgDateTime2->tooltip(_("Set today"));
				btn_rgDateTime2->callback((Fl_Callback*)cb_btn_rgDateTime2);
			  } // Fl_Button* btn_rgDateTime2
			  o->end();
			} // Fl_Group* o
			{ Fl_Group* o = new Fl_Group(5, 284, 560, 140, _("DLVD -TO - DATE/TIME"));
			  o->box(FL_ENGRAVED_FRAME);
			  o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
			  { txt_rg_dt3 = new Fl_Input2(381, 290, 152, 24, _("DT/TM"));
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
			  } // Fl_Input2* txt_rg_dt3
			  { btn_rgDateTime3 = new Fl_Button(537, 290, 24, 24, _("..."));
				btn_rgDateTime3->tooltip(_("Set to today"));
				btn_rgDateTime3->callback((Fl_Callback*)cb_btn_rgDateTime3);
			  } // Fl_Button* btn_rgDateTime3
			  { txt_rg_dlvd_to = new Fl_Input2(10, 319, 550, 100, _("Name/Addr/City/Tel"));
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
			  } // Fl_Input2* txt_rg_dlvd_to
			  o->end();
			} // Fl_Group* o
			{ Fl_Group* o = new Fl_Group(5, 82, 560, 30);
			  o->box(FL_ENGRAVED_FRAME);
			  { txt_rg_rcv_fm = new Fl_Input2(82, 85, 100, 24, _("RCVD FM:"));
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
			  } // Fl_Input2* txt_rg_rcv_fm
			  { txt_rg_rcv_net = new Fl_Input2(221, 85, 100, 24, _("NET:"));
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
			  } // Fl_Input2* txt_rg_rcv_net
			  { txt_rg_dt4 = new Fl_Input2(381, 85, 152, 24, _("DT/TM"));
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
			  } // Fl_Input2* txt_rg_dt4
			  { btn_rgDateTime4 = new Fl_Button(536, 85, 24, 24, _("..."));
				btn_rgDateTime4->tooltip(_("Set today"));
				btn_rgDateTime4->callback((Fl_Callback*)cb_btn_rgDateTime4);
			  } // Fl_Button* btn_rgDateTime4
			  o->end();
			} // Fl_Group* o
			{ Fl_Group* o = new Fl_Group(5, 253, 560, 30);
			  o->box(FL_ENGRAVED_FRAME);
			  { txt_rg_sent_to = new Fl_Input2(82, 256, 100, 24, _("SENT TO:"));
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
			  } // Fl_Input2* txt_rg_sent_to
			  { txt_rg_snt_net = new Fl_Input2(221, 256, 100, 24, _("NET:"));
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
			  } // Fl_Input2* txt_rg_snt_net
			  { txt_rg_dt5 = new Fl_Input2(381, 256, 152, 24, _("DT/TM"));
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
			  } // Fl_Input2* txt_rg_dt5
			  { btn_rgDateTime5 = new Fl_Button(536, 256, 24, 24, _("..."));
				btn_rgDateTime5->tooltip(_("Set today"));
				btn_rgDateTime5->callback((Fl_Callback*)cb_btn_rgDateTime5);
			  } // Fl_Button* btn_rgDateTime5
			  o->end();
			} // Fl_Group* o
			tab_radiogram_information->end();
			Fl_Group::current()->resizable(tab_radiogram_information);
		  } // Fl_Group* tab_radiogram_information
		  tabs_radiogram->end();
		  Fl_Group::current()->resizable(tabs_radiogram);
		} // Fl_Tabs* tabs_radiogram
		tab_radiogram->end();
	  } // Fl_Group* tab_radiogram
		{ // tab plaintext
		tab_plaintext = new Fl_Group(0, 45, 570, 380, _("Generic"));
		tab_plaintext->hide();
		{ txt_pt_title = new Fl_Input2(41, 53, 525, 24, _("Title"));
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
		} // Fl_Input2* txt_pt_title
		{ txt_pt_to = new Fl_Input2(42, 80, 320, 24, _("To"));
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
		} // Fl_Input2* txt_pt_to
		{ txt_pt_fm = new Fl_Input2(42, 107, 320, 24, _("Fm"));
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
		} // Fl_Input2* txt_pt_fm
		{ txt_pt_subj = new Fl_Input2(42, 135, 525, 24, _("Sub."));
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
		} // Fl_Input2* txt_pt_subj
		{ txt_pt_msg = new FTextEdit(4, 177, 562, 245, _("Message:"));
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
		} // FTextEdit* txt_pt_msg
		{ Fl_DateInput* o = txt_pt_date = new Fl_DateInput(404, 81, 125, 24, _("Date"));
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
		  o->format(2);
		} // Fl_DateInput* txt_pt_date
		{ btn_pt_date = new Fl_Button(537, 83, 20, 20, _("..."));
		  btn_pt_date->tooltip(_("Set today"));
		  btn_pt_date->callback((Fl_Callback*)cb_btn_pt_date);
		} // Fl_Button* btn_pt_date
		{ txt_pt_time = new Fl_Input2(404, 107, 125, 24, _("Time"));
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
		} // Fl_Input2* txt_pt_time
		{ btn_pt_time = new Fl_Button(537, 109, 20, 20, _("..."));
		  btn_pt_time->tooltip(_("Set time now"));
		  btn_pt_time->callback((Fl_Callback*)cb_btn_pt_time);
		} // Fl_Button* btn_pt_time
		tab_plaintext->end();
	  } // Fl_Group* tab_plaintext
		{ // tab blank
		tab_blank = new Fl_Group(0, 45, 570, 380, _("Blank"));
		tab_blank->hide();
		{ txt_blank_msg = new FTextEdit(4, 50, 562, 370);
		  txt_blank_msg->box(FL_DOWN_FRAME);
		  txt_blank_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
		  txt_blank_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
		  txt_blank_msg->labeltype(FL_NORMAL_LABEL);
		  txt_blank_msg->labelfont(0);
		  txt_blank_msg->labelsize(14);
		  txt_blank_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		  txt_blank_msg->align(FL_ALIGN_TOP_LEFT);
		  txt_blank_msg->when(FL_WHEN_RELEASE);
		  Fl_Group::current()->resizable(txt_blank_msg);
		} // FTextEdit* txt_blank_msg
		tab_blank->end();
	  } // Fl_Group* tab_blank
	  tabs_msg_type->end();
	} // Fl_Tabs* tabs_msg_type
	w->end();
//	w->resizable(w);
//  } // Fl_Double_Window* o
	return w;
}

Fl_Browser	*brwsOptions = (Fl_Browser	*)0;

Fl_Return_Button	*btnCloseOptions = (Fl_Return_Button	*)0;

static void cb_btnCloseOptions(Fl_Return_Button*, void*) {
  closeoptions();
}

Fl_Double_Window* optionsdialog() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(410, 260, _("Command Line Options"));
	w = o;
	{ brwsOptions = new Fl_Browser(3, 31, 405, 202);
	} // Fl_Browser* brwsOptions
	{ btnCloseOptions = new Fl_Return_Button(329, 239, 72, 20, _("OK"));
	  btnCloseOptions->callback((Fl_Callback*)cb_btnCloseOptions);
	} // Fl_Return_Button* btnCloseOptions
	{ Fl_Box* o = new Fl_Box(4, 7, 401, 21, _("usage: flics -<option> [filename]"));
	  o->box(FL_FLAT_BOX);
	  o->color((Fl_Color)FL_LIGHT3);
	  o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
	} // Fl_Box* o
	o->end();
  } // Fl_Double_Window* o
  return w;
}

Fl_Browser	*select_arl = (Fl_Browser	*)0;

static void cb_select_arl(Fl_Browser* o, void*) {
  arl_nbr = o->value()- 1;
arl_text->clear();
arl_text->addstr(arl_list[arl_nbr].text);
txt_arl_fill1->value("");
txt_arl_fill1->deactivate();
txt_arl_fill2->value("");
txt_arl_fill2->deactivate();
txt_arl_fill3->value("");
txt_arl_fill3->deactivate();
txt_arl_fill4->value("");
txt_arl_fill4->deactivate();
if (arl_list[arl_nbr].nfills > 0) txt_arl_fill1->activate();
if (arl_list[arl_nbr].nfills > 1) txt_arl_fill2->activate();
if (arl_list[arl_nbr].nfills > 2) txt_arl_fill3->activate();
if (arl_list[arl_nbr].nfills > 3) txt_arl_fill4->activate();
}

Fl_Input	*txt_arl_fill1 = (Fl_Input	*)0;

Fl_Input	*txt_arl_fill2 = (Fl_Input	*)0;

Fl_Input	*txt_arl_fill3 = (Fl_Input	*)0;

Fl_Input	*txt_arl_fill4 = (Fl_Input	*)0;

Fl_Button	*btn_arl_cancel = (Fl_Button	*)0;

static void cb_btn_arl_cancel(Fl_Button*, void*) {
  cb_arl_cancel();
}

Fl_Button	*btn_arl_add = (Fl_Button	*)0;

static void cb_btn_arl_add(Fl_Button*, void*) {
  cb_arl_add();
}

FTextEdit	*arl_text = (FTextEdit	*)0;

Fl_Check_Button	*btnInsertX = (Fl_Check_Button	*)0;

static void cb_btnInsertX(Fl_Check_Button* o, void*) {
  progStatus.insert_x = o->value();
}

Fl_Double_Window* arl_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(521, 261, _("ARL Message Selector"));
		select_arl = new Fl_Browser(6, 21, 161, 107, _("ARL #"));
		select_arl->type(2);
		select_arl->callback((Fl_Callback*)cb_select_arl);
		select_arl->align(FL_ALIGN_TOP);

		txt_arl_fill1 = new Fl_Input(48, 131, 465, 22, _("fill 1:"));

		txt_arl_fill2 = new Fl_Input(48, 155, 465, 22, _("fill 2:"));

		txt_arl_fill3 = new Fl_Input(48, 179, 465, 22, _("fill 3:"));

		txt_arl_fill4 = new Fl_Input(48, 204, 465, 22, _("fill 4:"));

		btn_arl_cancel = new Fl_Button(362, 232, 70, 20, _("Cancel"));
		btn_arl_cancel->callback((Fl_Callback*)cb_btn_arl_cancel);

		btn_arl_add = new Fl_Button(440, 232, 70, 20, _("Add"));
		btn_arl_add->callback((Fl_Callback*)cb_btn_arl_add);

		arl_text = new FTextEdit(169, 21, 345, 107, _("Message:"));
		arl_text->tooltip(_("Message contents - recommend limit to 25 words or less"));
		arl_text->box(FL_DOWN_BOX);
		arl_text->color((Fl_Color)FL_LIGHT3);
		arl_text->selection_color((Fl_Color)FL_SELECTION_COLOR);
		arl_text->labeltype(FL_NORMAL_LABEL);
		arl_text->labelfont(0);
		arl_text->labelsize(14);
		arl_text->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		arl_text->align(FL_ALIGN_TOP_LEFT);
		arl_text->when(FL_WHEN_RELEASE);
		Fl_Group::current()->resizable(arl_text);

		btnInsertX = new Fl_Check_Button(18, 234, 201, 15, _("Insert \"X\" between fields"));
		btnInsertX->down_box(FL_DOWN_BOX);
		btnInsertX->callback((Fl_Callback*)cb_btnInsertX);
		btnInsertX->value(progStatus.insert_x);
	return w;
}

Fl_Round_Button	*btn_dtformat0 = (Fl_Round_Button	*)0;

static void cb_btn_dtformat0(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 0;
btn_dtformat1->value(0);
btn_dtformat2->value(0);
};
}

Fl_Round_Button	*btn_dtformat1 = (Fl_Round_Button	*)0;

static void cb_btn_dtformat1(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 1;
btn_dtformat0->value(0);
btn_dtformat2->value(0);
};
}

Fl_Round_Button	*btn_dtformat2 = (Fl_Round_Button	*)0;

static void cb_btn_dtformat2(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 2;
btn_dtformat1->value(0);
btn_dtformat0->value(0);
};
}

Fl_Round_Button	*btn_utc_format0 = (Fl_Round_Button	*)0;

static void cb_btn_utc_format0(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 0;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
}

Fl_Round_Button	*btn_utc_format1 = (Fl_Round_Button	*)0;

static void cb_btn_utc_format1(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 1;
btn_utc_format0->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
}

Fl_Round_Button	*btn_utc_format2 = (Fl_Round_Button	*)0;

static void cb_btn_utc_format2(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 2;
btn_utc_format1->value(0);
btn_utc_format0->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
}

Fl_Round_Button	*btn_utc_format3 = (Fl_Round_Button	*)0;

static void cb_btn_utc_format3(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 3;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format0->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
}

Fl_Round_Button	*btn_utc_format4 = (Fl_Round_Button	*)0;

static void cb_btn_utc_format4(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 4;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format0->value(0);
btn_utc_format5->value(0);
};
}

Fl_Round_Button	*btn_utc_format5 = (Fl_Round_Button	*)0;

static void cb_btn_utc_format5(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 5;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format0->value(0);
};
}

Fl_Button	*btn_close_config = (Fl_Button	*)0;

static void cb_btn_close_config(Fl_Button*, void*) {
  cb_close_config();
}

Fl_Input	*txt_my_call = (Fl_Input	*)0;

static void cb_txt_my_call(Fl_Input* o, void*) {
  progStatus.my_call = o->value();
}

Fl_Input	*txt_my_tel = (Fl_Input	*)0;

static void cb_txt_my_tel(Fl_Input* o, void*) {
  progStatus.my_tel = o->value();
}

Fl_Input	*txt_my_name = (Fl_Input	*)0;

static void cb_txt_my_name(Fl_Input* o, void*) {
  progStatus.my_name = o->value();
}

Fl_Input	*txt_my_addr = (Fl_Input	*)0;

static void cb_txt_my_addr(Fl_Input* o, void*) {
  progStatus.my_addr = o->value();
}

Fl_Input	*txt_my_city = (Fl_Input	*)0;

static void cb_txt_my_city(Fl_Input* o, void*) {
  progStatus.my_city = o->value();
}

Fl_Spinner	*cnt_wpl = (Fl_Spinner	*)0;

static void cb_cnt_wpl(Fl_Spinner* o, void*) {
  progStatus.wpl = (int)o->value();
}

Fl_Check_Button	*btn_compress = (Fl_Check_Button	*)0;

static void cb_btn_compress(Fl_Check_Button* o, void*) {
  progStatus.compression = o->value();
}

Fl_Check_Button	*btn_call_fname = (Fl_Check_Button	*)0;

static void cb_btn_call_fname(Fl_Check_Button* o, void*) {
  progStatus.call_fname = o->value();
}

Fl_Check_Button	*btn_dt_fname = (Fl_Check_Button	*)0;

static void cb_btn_dt_fname(Fl_Check_Button* o, void*) {
  progStatus.dt_fname = o->value();
}

Fl_Check_Button	*btn_sernbr_fname = (Fl_Check_Button	*)0;

static void cb_btn_sernbr_fname(Fl_Check_Button* o, void*) {
  progStatus.sernbr_fname = o->value();
}

Fl_Input	*txt_sernbr = (Fl_Input	*)0;

static void cb_txt_sernbr(Fl_Input* o, void*) {
  progStatus.sernbr = o->value();
}

Fl_Check_Button	*btn_rgnbr_fname = (Fl_Check_Button	*)0;

static void cb_btn_rgnbr_fname(Fl_Check_Button* o, void*) {
  progStatus.rgnbr_fname = o->value();
}

Fl_Input	*txt_rgnbr = (Fl_Input	*)0;

static void cb_txt_rgnbr(Fl_Input* o, void*) {
  progStatus.rgnbr = o->value();
}

Fl_Double_Window* config_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(577, 239, _("flmsg configure"));
		{ // group_1
		Fl_Group* group_1 = new Fl_Group(4, 7, 135, 81, _("Date"));
		group_1->box(FL_ENGRAVED_FRAME);
		group_1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

			btn_dtformat0 = new Fl_Round_Button(13, 27, 70, 15, _("YYYY-DD-MM"));
			btn_dtformat0->down_box(FL_ROUND_DOWN_BOX);
			btn_dtformat0->callback((Fl_Callback*)cb_btn_dtformat0);
			if (progStatus.dtformat == 0) btn_dtformat0->value(1); else btn_dtformat0->value(0);

			btn_dtformat1 = new Fl_Round_Button(13, 47, 70, 15, _("MM/DD/YY"));
			btn_dtformat1->down_box(FL_ROUND_DOWN_BOX);
			btn_dtformat1->callback((Fl_Callback*)cb_btn_dtformat1);
			if (progStatus.dtformat == 1) btn_dtformat1->value(1); else btn_dtformat1->value(0);

			btn_dtformat2 = new Fl_Round_Button(13, 67, 70, 15, _("DD/MM/YY"));
			btn_dtformat2->down_box(FL_ROUND_DOWN_BOX);
			btn_dtformat2->callback((Fl_Callback*)cb_btn_dtformat2);
			if (progStatus.dtformat == 2) btn_dtformat2->value(1); else btn_dtformat2->value(0);

		group_1->end();
		} // group_1
		{ // group_2
		Fl_Group* group_2 = new Fl_Group(4, 89, 135, 146, _("Time"));
		group_2->box(FL_ENGRAVED_FRAME);
		group_2->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		btn_utc_format0 = new Fl_Round_Button(11, 107, 70, 15, _("hhmmL"));
		btn_utc_format0->down_box(FL_ROUND_DOWN_BOX);
		btn_utc_format0->callback((Fl_Callback*)cb_btn_utc_format0);
		if (progStatus.UTC == 0) btn_utc_format0->value(1); else btn_utc_format0->value(0);

		btn_utc_format1 = new Fl_Round_Button(11, 128, 70, 15, _("hh:mmL"));
		btn_utc_format1->down_box(FL_ROUND_DOWN_BOX);
		btn_utc_format1->callback((Fl_Callback*)cb_btn_utc_format1);
		if (progStatus.UTC == 1) btn_utc_format1->value(1); else btn_utc_format1->value(0);

		btn_utc_format2 = new Fl_Round_Button(11, 150, 70, 15, _("hhmmZ"));
		btn_utc_format2->down_box(FL_ROUND_DOWN_BOX);
		btn_utc_format2->callback((Fl_Callback*)cb_btn_utc_format2);
		if (progStatus.UTC == 2) btn_utc_format2->value(1); else btn_utc_format2->value(0);

		btn_utc_format3 = new Fl_Round_Button(11, 172, 70, 15, _("hh:mmZ"));
		btn_utc_format3->down_box(FL_ROUND_DOWN_BOX);
		btn_utc_format3->callback((Fl_Callback*)cb_btn_utc_format3);
		if (progStatus.UTC == 3) btn_utc_format3->value(1); else btn_utc_format3->value(0);

		btn_utc_format4 = new Fl_Round_Button(11, 194, 70, 15, _("hhmm UTC"));
		btn_utc_format4->down_box(FL_ROUND_DOWN_BOX);
		btn_utc_format4->callback((Fl_Callback*)cb_btn_utc_format4);
		if (progStatus.UTC == 4) btn_utc_format4->value(1); else btn_utc_format4->value(0);

		btn_utc_format5 = new Fl_Round_Button(11, 216, 70, 15, _("hh:mm UTC"));
		btn_utc_format5->down_box(FL_ROUND_DOWN_BOX);
		btn_utc_format5->callback((Fl_Callback*)cb_btn_utc_format5);
		if (progStatus.UTC == 5) btn_utc_format5->value(1); else btn_utc_format5->value(0);

		group_2->end();
		} // group_2
		{ // group_3
		Fl_Group* group_3 = new Fl_Group(140, 7, 300, 185, _("Radiogram format"));
		group_3->box(FL_ENGRAVED_FRAME);
		group_3->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		txt_my_call = new Fl_Input(194, 32, 77, 24, _("Call:"));
		txt_my_call->callback((Fl_Callback*)cb_txt_my_call);
		txt_my_call->value(progStatus.my_call.c_str());

		txt_my_tel = new Fl_Input(303, 32, 130, 24, _("Tel:"));
		txt_my_tel->callback((Fl_Callback*)cb_txt_my_tel);
		txt_my_tel->value(progStatus.my_tel.c_str());

		txt_my_name = new Fl_Input(198, 64, 235, 24, _("Name:"));
		txt_my_name->callback((Fl_Callback*)cb_txt_my_name);
		txt_my_name->value(progStatus.my_name.c_str());

		txt_my_addr = new Fl_Input(198, 96, 235, 24, _("Addr:"));
		txt_my_addr->callback((Fl_Callback*)cb_txt_my_addr);
		txt_my_addr->value(progStatus.my_addr.c_str());

		txt_my_city = new Fl_Input(233, 128, 200, 24, _("City/St/Zip:"));
		txt_my_city->callback((Fl_Callback*)cb_txt_my_city);
		txt_my_city->value(progStatus.my_city.c_str());

		cnt_wpl = new Fl_Spinner(150, 160, 40, 24, _("message words/line"));
		cnt_wpl->tooltip(_("Radiogram message contents auto format"));
		cnt_wpl->minimum(4);
		cnt_wpl->maximum(10);
		cnt_wpl->value(5);
		cnt_wpl->callback((Fl_Callback*)cb_cnt_wpl);
		cnt_wpl->align(FL_ALIGN_RIGHT);
		cnt_wpl->value(progStatus.wpl);

		group_3->end();
		} // group_3
		{ // group_4
		Fl_Group* group_4 = new Fl_Group(140, 194, 300, 40, _("Wrap"));
		group_4->box(FL_ENGRAVED_FRAME);
		group_4->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		btn_compress = new Fl_Check_Button(191, 209, 70, 15, _("Use compression"));
		btn_compress->tooltip(_("Compress wrap files"));
		btn_compress->down_box(FL_DOWN_BOX);
		btn_compress->callback((Fl_Callback*)cb_btn_compress);
		btn_compress->value(progStatus.compression);

		group_4->end();
		} // group_4
		{ // group_5
		Fl_Group* group_5 = new Fl_Group(442, 7, 134, 114, _("Naming Files"));
		group_5->box(FL_ENGRAVED_FRAME);
		group_5->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		btn_call_fname = new Fl_Check_Button(449, 32, 70, 15, _("Callsign"));
		btn_call_fname->down_box(FL_DOWN_BOX);
		btn_call_fname->callback((Fl_Callback*)cb_btn_call_fname);
		btn_call_fname->value(progStatus.call_fname);

		btn_dt_fname = new Fl_Check_Button(449, 51, 70, 15, _("Date-time"));
		btn_dt_fname->down_box(FL_DOWN_BOX);
		btn_dt_fname->callback((Fl_Callback*)cb_btn_dt_fname);
		btn_dt_fname->value(progStatus.dt_fname);

		btn_sernbr_fname = new Fl_Check_Button(449, 70, 70, 15, _("Serial #"));
		btn_sernbr_fname->down_box(FL_DOWN_BOX);
		btn_sernbr_fname->callback((Fl_Callback*)cb_btn_sernbr_fname);
		btn_sernbr_fname->value(progStatus.sernbr_fname);

		txt_sernbr = new Fl_Input(448, 90, 66, 24, _("Next #"));
		txt_sernbr->type(2);
		txt_sernbr->callback((Fl_Callback*)cb_txt_sernbr);
		txt_sernbr->align(FL_ALIGN_RIGHT);
		txt_sernbr->value(progStatus.sernbr.c_str());

		group_5->end();
		} // group_5
		{ // group_6
		Fl_Group* group_6 = new Fl_Group(442, 119, 134, 73, _("Radiograms"));
		group_6->box(FL_ENGRAVED_FRAME);
		group_6->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

		btn_rgnbr_fname = new Fl_Check_Button(449, 143, 70, 15, _("Auto incr\'"));
		btn_rgnbr_fname->down_box(FL_DOWN_BOX);
		btn_rgnbr_fname->callback((Fl_Callback*)cb_btn_rgnbr_fname);
		btn_rgnbr_fname->value(progStatus.rgnbr_fname);

		txt_rgnbr = new Fl_Input(448, 161, 66, 24, _("Next #"));
		txt_rgnbr->type(2);
		txt_rgnbr->callback((Fl_Callback*)cb_txt_rgnbr);
		txt_rgnbr->align(FL_ALIGN_RIGHT);
		txt_rgnbr->value(progStatus.rgnbr.c_str());

		group_6->end();
		} // group_6
		btn_close_config = new Fl_Button(467, 201, 73, 25, _("close"));
		btn_close_config->callback((Fl_Callback*)cb_btn_close_config);
	return w;
}

Fl_Choice	*sel_hx_select = (Fl_Choice	*)0;

static void cb_sel_hx_select(Fl_Choice*, void*) {
  cb_hx_select();
}

Fl_Button	*btn_hx_select_add = (Fl_Button	*)0;

static void cb_btn_hx_select_add(Fl_Button*, void*) {
  cb_hx_select_add();
}

Fl_Input2	*txt_hx_select_text = (Fl_Input2	*)0;

Fl_Button	*btn_hx_select_cancel = (Fl_Button	*)0;

static void cb_btn_hx_select_cancel(Fl_Button*, void*) {
  cb_hx_select_cancel();
}

Fl_Return_Button	*btn_hx_select_ok = (Fl_Return_Button	*)0;

static void cb_btn_hx_select_ok(Fl_Return_Button*, void*) {
  cb_hx_select_ok();
}

Fl_Output	*txt_hx_instructions = (Fl_Output	*)0;

Fl_Double_Window* hx_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(359, 121, _("Optional Handling"));

		sel_hx_select = new Fl_Choice(3, 20, 68, 24, _("HX__:"));
		sel_hx_select->down_box(FL_BORDER_BOX);
		sel_hx_select->callback((Fl_Callback*)cb_sel_hx_select);
		sel_hx_select->align(FL_ALIGN_TOP_LEFT);

		btn_hx_select_add = new Fl_Button(73, 20, 30, 24, _("=>"));
		btn_hx_select_add->callback((Fl_Callback*)cb_btn_hx_select_add);

		txt_hx_select_text = new Fl_Input2(105, 20, 121, 24, _("HX text"));
		txt_hx_select_text->box(FL_DOWN_BOX);
		txt_hx_select_text->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_hx_select_text->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_hx_select_text->labeltype(FL_NORMAL_LABEL);
		txt_hx_select_text->labelfont(0);
		txt_hx_select_text->labelsize(14);
		txt_hx_select_text->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_hx_select_text->align(FL_ALIGN_TOP_LEFT);
		txt_hx_select_text->when(FL_WHEN_RELEASE);

		btn_hx_select_cancel = new Fl_Button(229, 20, 60, 24, _("Cancel"));
		btn_hx_select_cancel->callback((Fl_Callback*)cb_btn_hx_select_cancel);

		btn_hx_select_ok = new Fl_Return_Button(293, 20, 60, 24, _("OK"));
		btn_hx_select_ok->callback((Fl_Callback*)cb_btn_hx_select_ok);

		txt_hx_instructions = new Fl_Output(5, 47, 348, 70);
		txt_hx_instructions->type(12);
		txt_hx_instructions->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);

	w->end();
	return w;
}
