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

Fl_Group	*tab_ics = (Fl_Group *)0;
Fl_Tabs	*tab_ics_type = (Fl_Tabs *)0;

//======================================================================

Fl_Group	*tab_ics203 = (Fl_Group *)0;
Fl_Tabs		*tab_ics203_type = (Fl_Tabs *)0;
Fl_Group	*tab_203_1 = (Fl_Group *)0;
Fl_Input2	*txt_203_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_203_date = (Fl_Input2 *)0;
Fl_Button	*btn_203_date = (Fl_Button *)0;
Fl_Input2	*txt_203_time = (Fl_Input2 *)0;
Fl_Button	*btn_203_time = (Fl_Button *)0;
Fl_Input2	*txt_203_op_period = (Fl_Input2 *)0;
Fl_Input2	*txt_203_incident_commander = (Fl_Input2 *)0;
Fl_Input2	*txt_203_incident_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_incident_safety_officer = (Fl_Input2 *)0;
Fl_Input2	*txt_203_incident_info_officer = (Fl_Input2 *)0;
Fl_Input2	*txt_203_liaison_officer = (Fl_Input2 *)0;
Fl_Input2	*txt_203_prepared_by = (Fl_Input2 *)0;
Fl_Group	*tab_203_agency = (Fl_Group *)0;
Fl_Input2	*txt_203_agency[7]={(Fl_Input2 *)0};
Fl_Input2	*txt_203_agency_name[7]={(Fl_Input2 *)0};
Fl_Group	*tab_203_planning = (Fl_Group *)0;
Fl_Input2	*txt_203_planning_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_203_planning_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_resources_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_situation_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_documentation_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_demobilization_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_tech_spc[3]={(Fl_Input2 *)0};
Fl_Group	*tab_203_logistics = (Fl_Group *)0;
Fl_Input2	*txt_203_logistics_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_203_logistics_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_support_director = (Fl_Input2 *)0;
Fl_Input2	*txt_203_supply_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_facilities_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_ground_support = (Fl_Input2 *)0;
Fl_Input2	*txt_203_service_director = (Fl_Input2 *)0;
Fl_Input2	*txt_203_communications_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_medical_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_food_unit = (Fl_Input2 *)0;
Fl_Group	*tab_203_opsA = (Fl_Group *)0;
Fl_Input2	*txt_203_ops_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_203_ops_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_b1_director = (Fl_Input2 *)0;
Fl_Input2	*txt_203_b1_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_b1_div[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_203_b1_grp[5]={(Fl_Input2 *)0};
Fl_Group	*tab_203_opsB = (Fl_Group *)0;
Fl_Input2	*txt_203_b2_director = (Fl_Input2 *)0;
Fl_Input2	*txt_203_b2_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_b2_div[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_203_b2_grp[5]={(Fl_Input2 *)0};
Fl_Group	*tab_203_opsC = (Fl_Group *)0;
Fl_Input2	*txt_203_b3_director = (Fl_Input2 *)0;
Fl_Input2	*txt_203_b3_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_b3_div[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_203_b3_grp[5]={(Fl_Input2 *)0};
Fl_Group	*tab_203_opsD = (Fl_Group *)0;
Fl_Input2	*txt_203_air_ops_br_dir = (Fl_Input2 *)0;
Fl_Input2	*txt_203_air_tactical_group_sup = (Fl_Input2 *)0;
Fl_Input2	*txt_203_air_support_group_sup = (Fl_Input2 *)0;
Fl_Input2	*txt_203_helicopter_coordinator = (Fl_Input2 *)0;
Fl_Input2	*txt_203_air_tanker_fixed_wing = (Fl_Input2 *)0;
Fl_Group	*tab_203_admin = (Fl_Group *)0;
Fl_Input2	*txt_203_finance_chief = (Fl_Input2 *)0;
Fl_Input2	*txt_203_finance_deputy = (Fl_Input2 *)0;
Fl_Input2	*txt_203_time_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_procurement_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_claims_unit = (Fl_Input2 *)0;
Fl_Input2	*txt_203_cost_unit = (Fl_Input2 *)0;

//======================================================================

Fl_Group	*tab_ics205 = (Fl_Group *)0;
Fl_Input2	*txt_205_name = (Fl_Input2 *)0;
Fl_Input2	*txt_205_dt_prepared = (Fl_Input2 *)0;
Fl_Button	*btn_205DateTime1 = (Fl_Button *)0;

Fl_Input2	*txt_205_dt_operational = (Fl_Input2 *)0;
Fl_Button	*btn_205_DateTime2 = (Fl_Button *)0;
Fl_Input2	*txt_205_type[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_channel[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_function[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_freqtone[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_assignment[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_remarks[8]={(Fl_Input2 *)0};
Fl_Input2	*txt_205_preparer = (Fl_Input2 *)0;

//======================================================================

Fl_Group	*tab_ics205a = (Fl_Group *)0;
Fl_Tabs		*tab_ics205a_type = (Fl_Tabs *)0;
Fl_Group	*tab_205a_1 = (Fl_Group *)0;
Fl_Input2	*txt_205a_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_205a_date_fm = (Fl_Input2 *)0;
Fl_Button	*btn_205a_date_fm = (Fl_Button *)0;
Fl_Input2	*txt_205a_date_to = (Fl_Input2 *)0;
Fl_Button	*btn_205a_date_to = (Fl_Button *)0;
Fl_Input2	*txt_205a_time_fm = (Fl_Input2 *)0;
Fl_Button	*btn_205a_time_fm = (Fl_Button *)0;
Fl_Input2	*txt_205a_time_to = (Fl_Input2 *)0;
Fl_Button	*btn_205a_time_to = (Fl_Button *)0;

Fl_Input2	*txt_205a_prepared_by = (Fl_Input2 *)0;
Fl_Input2	*txt_205a_preparer_position = (Fl_Input2 *)0;
Fl_Input2	*txt_205a_preparer_date_time = (Fl_Input2 *)0;

Fl_Group	*tab_205a_2 = (Fl_Group *)0;
Fl_Input2	*txt_205a_comm_group[32] = {(Fl_Input2 *)0};
Fl_Input2	*txt_205a_comm_position[32] = {(Fl_Input2 *)0};
Fl_Input2	*txt_205a_comm_name[32] = {(Fl_Input2 *)0};
Fl_Input2	*txt_205a_comm_info[32] = {(Fl_Input2 *)0};

//======================================================================

Fl_Group	*tab_ics206 = (Fl_Group *)0;
Fl_Tabs		*tab_ics206_type = (Fl_Tabs *)0;
Fl_Group	*tab_206_med_plan = (Fl_Group *)0;
Fl_Input2	*txt_206_name = (Fl_Input2 *)0;
Fl_Input2	*txt_206_op_period = (Fl_Input2 *)0;
Fl_Input2	*txt_206_time_prepared = (Fl_Input2 *)0;
Fl_Button	*btn_206_time = (Fl_Button *)0;
Fl_DateInput	*txt_206_date_prepared = (Fl_DateInput *)0;
Fl_Button	*btn_206_date = (Fl_Button *)0;
Fl_Input2	*txt_206_medaid_sta[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_medaid_loc[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_medaid_paramedics[5]={(Fl_Check_Button *)0};
Fl_Input2	*txt_206_preparer = (Fl_Input2 *)0;
Fl_Input2	*txt_206_reviewer = (Fl_Input2 *)0;
Fl_Group	*tab_206_transport = (Fl_Group *)0;
Fl_Input2	*txt_206_transport_name[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_transport_address[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_transport_paramedics[5]={(Fl_Check_Button *)0};
Fl_Input2	*txt_206_transport_phone[5]={(Fl_Input2 *)0};
Fl_Group	*tab_206_ambulance = (Fl_Group *)0;
Fl_Input2	*txt_206_ambulance_name[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_ambulance_loc[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_ambulance_paramedics[5]={(Fl_Check_Button *)0};
Fl_Group	*tab_206_hospital = (Fl_Group *)0;
Fl_Input2	*txt_206_hosp_name[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_address[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_phone[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_airtime[5]={(Fl_Input2 *)0};
Fl_Input2	*txt_206_hosp_gndtime[5]={(Fl_Input2 *)0};
Fl_Check_Button	*btn_206_hosp_helipad[5]={(Fl_Check_Button *)0};
Fl_Check_Button	*btn_206_hosp_burn_center[5]={(Fl_Check_Button *)0};
Fl_Group	*tab_206_med_proc = (Fl_Group *)0;
FTextEdit	*txt_206_procedure = (FTextEdit *)0;

//======================================================================

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

Fl_Output	*txt_filename = (Fl_Output *)0;
Fl_Tabs	*tabs_msg_type = (Fl_Tabs *)0;

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

//======================================================================

Fl_Group	*tab_ics214 = (Fl_Group *)0;
Fl_Tabs	*tab_ics214_type = (Fl_Tabs *)0;
Fl_Group	*tab_214_1 = (Fl_Group *)0;
Fl_Input2	*txt_214_incident = (Fl_Input2 *)0;
Fl_Input2	*txt_214_date = (Fl_Input2 *)0;
Fl_Input2	*txt_214_unit_name = (Fl_Input2 *)0;
Fl_Input2	*txt_214_unit_leader = (Fl_Input2 *)0;
Fl_Button	*btn_214_date = (Fl_Button *)0;
Fl_Input2	*txt_214_time = (Fl_Input2 *)0;
Fl_Button	*btn_214_time = (Fl_Button *)0;

Fl_Input2	*txt_214_op_period = (Fl_Input2 *)0;
Fl_Input2	*txt_214_prepared_by = (Fl_Input2 *)0;
Fl_Group	*tab_214_2 = (Fl_Group *)0;
Fl_Input2	*txt_214_roster_name[16]={(Fl_Input2 *)0};
Fl_Input2	*txt_214_roster_position[16]={(Fl_Input2 *)0};
Fl_Input2	*txt_214_roster_home_base[16]={(Fl_Input2 *)0};
Fl_Group	*tab_214_3 = (Fl_Group *)0;
Fl_Input2	*txt_214_activity_time[16]={(Fl_Input2 *)0};
Fl_Input2	*txt_214_activity_event[16]={(Fl_Input2 *)0};

//======================================================================

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

//======================================================================

Fl_Group	*tab_radiogram = (Fl_Group *)0;
Fl_Tabs	*tabs_radiogram = (Fl_Tabs *)0;
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

Fl_Group	*tab_blank = (Fl_Group *)0;
FTextEdit	*txt_blank_msg = (FTextEdit *)0;

//======================================================================

Fl_Group	*tab_dnd = (Fl_Group *)0;
Fl_Input	*drop_box = (Fl_Input *)0;

//======================================================================

static void cb_mnu_folders(Fl_Menu_*, void*) {
  cb_folders();
}

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

static void cb_drop_box(Fl_Input*, void*) {
  drop_box_changed();
}

Fl_Menu_Item menu_[] = {
 {_("&File"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&Folders"), 0, (Fl_Callback*)cb_mnu_folders, 0, FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},
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
// ICS tabs
		{ // tab_ics
		tab_ics = new Fl_Group(0, 45, 607, 380, _("ICS"));
		tab_ics_type = new Fl_Tabs(0, 45, 607, 380);
		tab_ics_type->selection_color((Fl_Color)246);
		tab_ics_type->callback((Fl_Callback*)cb_tab_ics_type);
#include "ics203_tab.cxx"
#include "ics205_tab.cxx"
#include "ics205a_tab.cxx"  
#include "ics206_tab.cxx"
#include "ics213_tab.cxx"
#include "ics214_tab.cxx"
#include "ics216_tab.cxx"
		Fl_Group::current()->resizable(tab_ics216_type);
		tab_ics_type->end();
		tab_ics->end();
		} // Fl_Tabs* tab_ics

// RADIOGRAM tab
#include "radiogram_tab.cxx"

// PLAINTEXT
#include "plaintext_tab.cxx"

// BLANKFORM
#include "blank_tab.cxx"

// DRAG AND DROP
#include "dnd_tab.cxx"

	  tabs_msg_type->end();
	} // Fl_Tabs* tabs_msg_type
	w->end();
	return w;
}

Fl_Browser	*brwsOptions = (Fl_Browser *)0;

Fl_Return_Button	*btnCloseOptions = (Fl_Return_Button *)0;

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

Fl_Browser	*select_arl = (Fl_Browser *)0;

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

Fl_Input	*txt_arl_fill1 = (Fl_Input *)0;

Fl_Input	*txt_arl_fill2 = (Fl_Input *)0;

Fl_Input	*txt_arl_fill3 = (Fl_Input *)0;

Fl_Input	*txt_arl_fill4 = (Fl_Input *)0;

Fl_Button	*btn_arl_cancel = (Fl_Button *)0;

static void cb_btn_arl_cancel(Fl_Button*, void*) {
  cb_arl_cancel();
}

Fl_Button	*btn_arl_add = (Fl_Button *)0;

static void cb_btn_arl_add(Fl_Button*, void*) {
  cb_arl_add();
}

FTextEdit	*arl_text = (FTextEdit *)0;

Fl_Check_Button	*btnInsertX = (Fl_Check_Button *)0;

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

Fl_Round_Button	*btn_dtformat0 = (Fl_Round_Button *)0;

static void cb_btn_dtformat0(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 0;
btn_dtformat1->value(0);
btn_dtformat2->value(0);
};
}

Fl_Round_Button	*btn_dtformat1 = (Fl_Round_Button *)0;

static void cb_btn_dtformat1(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 1;
btn_dtformat0->value(0);
btn_dtformat2->value(0);
};
}

Fl_Round_Button	*btn_dtformat2 = (Fl_Round_Button *)0;

static void cb_btn_dtformat2(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 2;
btn_dtformat1->value(0);
btn_dtformat0->value(0);
};
}

Fl_Round_Button	*btn_utc_format0 = (Fl_Round_Button *)0;

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

Fl_Round_Button	*btn_utc_format1 = (Fl_Round_Button *)0;

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

Fl_Round_Button	*btn_utc_format2 = (Fl_Round_Button *)0;

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

Fl_Round_Button	*btn_utc_format3 = (Fl_Round_Button *)0;

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

Fl_Round_Button	*btn_utc_format4 = (Fl_Round_Button *)0;

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

Fl_Round_Button	*btn_utc_format5 = (Fl_Round_Button *)0;

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

Fl_Button	*btn_close_config = (Fl_Button *)0;

static void cb_btn_close_config(Fl_Button*, void*) {
  cb_close_config();
}

Fl_Input	*txt_my_call = (Fl_Input *)0;

static void cb_txt_my_call(Fl_Input* o, void*) {
  progStatus.my_call = o->value();
}

Fl_Input	*txt_my_tel = (Fl_Input *)0;

static void cb_txt_my_tel(Fl_Input* o, void*) {
  progStatus.my_tel = o->value();
}

Fl_Input	*txt_my_name = (Fl_Input *)0;

static void cb_txt_my_name(Fl_Input* o, void*) {
  progStatus.my_name = o->value();
}

Fl_Input	*txt_my_addr = (Fl_Input *)0;

static void cb_txt_my_addr(Fl_Input* o, void*) {
  progStatus.my_addr = o->value();
}

Fl_Input	*txt_my_city = (Fl_Input *)0;

static void cb_txt_my_city(Fl_Input* o, void*) {
  progStatus.my_city = o->value();
}

Fl_Spinner	*cnt_wpl = (Fl_Spinner *)0;

static void cb_cnt_wpl(Fl_Spinner* o, void*) {
  progStatus.wpl = (int)o->value();
}

Fl_Check_Button	*btn_open_on_export = (Fl_Check_Button *)0;

static void cb_btn_open_on_export(Fl_Check_Button* o, void*) {
  progStatus.open_on_export = o->value();
}

Fl_Check_Button	*btn_call_fname = (Fl_Check_Button *)0;

static void cb_btn_call_fname(Fl_Check_Button* o, void*) {
  progStatus.call_fname = o->value();
}

Fl_Check_Button	*btn_dt_fname = (Fl_Check_Button *)0;

static void cb_btn_dt_fname(Fl_Check_Button* o, void*) {
  progStatus.dt_fname = o->value();
}

Fl_Check_Button	*btn_sernbr_fname = (Fl_Check_Button *)0;

static void cb_btn_sernbr_fname(Fl_Check_Button* o, void*) {
  progStatus.sernbr_fname = o->value();
}

Fl_Input	*txt_sernbr = (Fl_Input *)0;

static void cb_txt_sernbr(Fl_Input* o, void*) {
  progStatus.sernbr = o->value();
}

Fl_Check_Button	*btn_rgnbr_fname = (Fl_Check_Button *)0;

static void cb_btn_rgnbr_fname(Fl_Check_Button* o, void*) {
  progStatus.rgnbr_fname = o->value();
}

Fl_Input	*txt_rgnbr = (Fl_Input *)0;

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

		btn_open_on_export = new Fl_Check_Button(160, 215, 70, 15, _("Open folder when exporting"));
		btn_open_on_export->tooltip(_(""));
		btn_open_on_export->down_box(FL_DOWN_BOX);
		btn_open_on_export->callback((Fl_Callback*)cb_btn_open_on_export);
		btn_open_on_export->value(progStatus.open_on_export);

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

Fl_Choice	*sel_hx_select = (Fl_Choice *)0;

static void cb_sel_hx_select(Fl_Choice*, void*) {
  cb_hx_select();
}

Fl_Button	*btn_hx_select_add = (Fl_Button *)0;

static void cb_btn_hx_select_add(Fl_Button*, void*) {
  cb_hx_select_add();
}

Fl_Input2	*txt_hx_select_text = (Fl_Input2 *)0;

Fl_Button	*btn_hx_select_cancel = (Fl_Button *)0;

static void cb_btn_hx_select_cancel(Fl_Button*, void*) {
  cb_hx_select_cancel();
}

Fl_Return_Button	*btn_hx_select_ok = (Fl_Return_Button *)0;

static void cb_btn_hx_select_ok(Fl_Return_Button*, void*) {
  cb_hx_select_ok();
}

Fl_Output	*txt_hx_instructions = (Fl_Output *)0;

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
