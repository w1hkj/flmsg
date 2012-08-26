#ifndef FLMSG_DIALOG_H
#define FLMSG_DIALOG_H

#include <FL/Fl.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Counter.H>

#include "FTextView.h"
#include "flinput2.h"
#include "combo.h"
#include "calendar.h"
#include "flmsg.h"


extern Fl_Output	*txt_filename;
extern Fl_Input		*drop_box;
extern Fl_Input		*drop_file;

extern int tab_top;

extern Fl_Tabs	*tabs_msg_type;

//======================================================================

extern Fl_Double_Window* flmsg_dialog();
extern Fl_Menu_Item menu_[];
#define mnuNew (menu_+1)
#define mnuOpen (menu_+2)
#define mnuSave (menu_+3)
#define mnuSaveAs (menu_+4)
#define mnu_html (menu_+6)
#define mnu_html_fcopy (menu_+7)
#define mnu_text (menu_+8)
#define mnu_qimport (menu_+11)
#define mnu_qexport (menu_+12)
#define mnuWrapImport (menu_+15)
#define mnuWrapExport (menu_+16)
#define mnuAutoSend (menu_+17)
#define mnuExit (menu_+19)
#define mnu_load_template (menu_+22)
#define mnu_save_template (menu_+23)
#define mnu_save_as_template (menu_+24)
#define mnuConfig (menu_+26)
#define mnuOptions (menu_+29)
#define mnuOnLineHelp (menu_+30)
#define mnuAbout (menu_+31)

extern Fl_Browser	*brwsOptions;

extern Fl_Double_Window* optionsdialog();
extern Fl_Return_Button	*btnCloseOptions;

extern Fl_Double_Window* arl_dialog();
extern Fl_Browser	*select_arl;
extern Fl_Input2	*txt_arl_fill1;
extern Fl_Input2	*txt_arl_fill2;
extern Fl_Input2	*txt_arl_fill3;
extern Fl_Input2	*txt_arl_fill4;
extern Fl_Button	*btn_arl_cancel;
extern Fl_Button	*btn_arl_add;
extern FTextEdit	*arl_text;
extern Fl_Check_Button	*btnInsertX;

extern Fl_Double_Window* date_time_dialog();
extern Fl_Round_Button	*btn_dtformat0;
extern Fl_Round_Button	*btn_dtformat1;
extern Fl_Round_Button	*btn_dtformat2;
extern Fl_Round_Button	*btn_dtformat3;
extern Fl_Round_Button	*btn_utc_format0;
extern Fl_Round_Button	*btn_utc_format1;
extern Fl_Round_Button	*btn_utc_format2;
extern Fl_Round_Button	*btn_utc_format3;
extern Fl_Round_Button	*btn_utc_format4;
extern Fl_Round_Button	*btn_utc_format5;
extern Fl_Button		*btn_close_date_time_dialog;

extern Fl_Double_Window* personal_dialog();
extern Fl_Input2	*txt_my_call;
extern Fl_Input2	*txt_my_tel;
extern Fl_Input2	*txt_my_name;
extern Fl_Input2	*txt_my_addr;
extern Fl_Input2	*txt_my_city;

extern Fl_Double_Window* headers_dialog();
extern Fl_Input2*	txt_hdr_from;
extern Fl_Input2*	txt_hdr_edit;

extern Fl_Input2*	txt_socket_addr;
extern Fl_Input2*	txt_socket_port;

extern Fl_Double_Window* radiogram_dialog();
extern Fl_Spinner	*cnt_wpl;
extern Fl_Check_Button	*btn_rgnbr_fname;
extern Fl_Input2	*txt_rgnbr;

extern Fl_Double_Window* config_files_dialog();
extern Fl_Check_Button	*btn_open_on_export;
extern Fl_Check_Button	*btn_use_compression;
extern Fl_Check_Button	*btn_call_fname;
extern Fl_Check_Button	*btn_dt_fname;
extern Fl_Check_Button	*btn_sernbr_fname;
extern Fl_Input2	*txt_sernbr;
extern Fl_Input2	*txt_mars_roster_file;

extern Fl_Double_Window* hx_dialog();
extern Fl_Choice	*sel_hx_select;
extern Fl_Button	*btn_hx_select_add;
extern Fl_Input2	*txt_hx_select_text;
extern Fl_Button	*btn_hx_select_cancel;
extern Fl_Return_Button	*btn_hx_select_ok;
extern Fl_Output	*txt_hx_instructions;

extern Fl_Double_Window* socket_dialog();
extern Fl_Input2 * txt_socket_addr;
extern Fl_Input2 * txt_socket_port;
extern Fl_Button * btn_close_socket_dialog;


extern void select_form(int form);

extern Fl_Output *txt_transfer_size;
extern int transfer_size;

extern Fl_ComboBox	*cbo_modes;

extern void estimate();

//======================================================================
// ICS
//======================================================================
extern Fl_Group	*tab_ics;
extern Fl_Tabs	*tab_ics_type;

extern void create_ics_tab();

//======================================================================
// ICS-203
//======================================================================
extern void create_ics203_tab();

extern Fl_Group		*tab_ics203;
extern Fl_Tabs		*tab_ics203_type;
extern Fl_Group		*tab_203_1;
extern Fl_Input2	*txt_203_incident;
extern Fl_Input2	*txt_203_date;
extern Fl_Button	*btn_203_date;
extern Fl_Input2	*txt_203_time;
extern Fl_Button	*btn_203_time;
extern Fl_Input2	*txt_203_op_period;
extern Fl_Input2	*txt_203_incident_commander;
extern Fl_Input2	*txt_203_incident_deputy;
extern Fl_Input2	*txt_203_incident_safety_officer;
extern Fl_Input2	*txt_203_incident_info_officer;
extern Fl_Input2	*txt_203_liaison_officer;
extern Fl_Input2	*txt_203_prepared_by;
extern Fl_Group		*tab_203_agency;
extern Fl_Input2	*txt_203_agency[7];
extern Fl_Input2	*txt_203_agency_name[7];
extern Fl_Group		*tab_203_planning;
extern Fl_Input2	*txt_203_planning_chief;
extern Fl_Input2	*txt_203_planning_deputy;
extern Fl_Input2	*txt_203_resources_unit;
extern Fl_Input2	*txt_203_situation_unit;
extern Fl_Input2	*txt_203_documentation_unit;
extern Fl_Input2	*txt_203_demobilization_unit;
extern Fl_Input2	*txt_203_tech_spc[3];
extern Fl_Group		*tab_203_logistics;
extern Fl_Input2	*txt_203_logistics_chief;
extern Fl_Input2	*txt_203_logistics_deputy;
extern Fl_Input2	*txt_203_support_director;
extern Fl_Input2	*txt_203_supply_unit;
extern Fl_Input2	*txt_203_facilities_unit;
extern Fl_Input2	*txt_203_ground_support;
extern Fl_Input2	*txt_203_service_director;
extern Fl_Input2	*txt_203_communications_unit;
extern Fl_Input2	*txt_203_medical_unit;
extern Fl_Input2	*txt_203_food_unit;
extern Fl_Group		*tab_203_ops;
extern Fl_Input2	*txt_203_ops_chief;
extern Fl_Input2	*txt_203_ops_deputy;
extern Fl_Input2	*txt_203_b1_director;
extern Fl_Input2	*txt_203_b1_deputy;
extern Fl_Input2	*txt_203_b1_div[5];
extern Fl_Input2	*txt_203_b1_grp[5];
extern Fl_Group		*tab_203_opsB;
extern Fl_Input2	*txt_203_b2_director;
extern Fl_Input2	*txt_203_b2_deputy;
extern Fl_Input2	*txt_203_b2_div[5];
extern Fl_Input2	*txt_203_b2_grp[5];
extern Fl_Group		*tab_203_opsC;
extern Fl_Input2	*txt_203_b3_director;
extern Fl_Input2	*txt_203_b3_deputy;
extern Fl_Input2	*txt_203_b3_div[5];
extern Fl_Input2	*txt_203_b3_grp[5];
extern Fl_Group		*tab_203_opsD;
extern Fl_Input2	*txt_203_air_ops_br_dir;
extern Fl_Input2	*txt_203_air_tactical_group_sup;
extern Fl_Input2	*txt_203_air_support_group_sup;
extern Fl_Input2	*txt_203_helicopter_coordinator;
extern Fl_Input2	*txt_203_air_tanker_fixed_wing;
extern Fl_Group		*tab_203_admin;
extern Fl_Input2	*txt_203_finance_chief;
extern Fl_Input2	*txt_203_finance_deputy;
extern Fl_Input2	*txt_203_time_unit;
extern Fl_Input2	*txt_203_procurement_unit;
extern Fl_Input2	*txt_203_claims_unit;
extern Fl_Input2	*txt_203_cost_unit;

//======================================================================
// ICS-205
//======================================================================
extern void create_ics205_tab();

extern Fl_Group		*tab_ics205;
extern Fl_Input2	*txt_205_name;
extern Fl_Input2	*txt_205_dt_prepared;
extern Fl_Button	*btn_205_dt_prepared;
extern Fl_Input2	*txt_205_dt_op_from;
extern Fl_Button	*btn_205_dt_op_from;
extern Fl_Input2	*txt_205_dt_op_to;
extern Fl_Button	*btn_205_dt_op_to;
extern Fl_Input2	*txt_205_type[8];
extern Fl_Input2	*txt_205_channel[8];
extern Fl_Input2	*txt_205_function[8];
extern Fl_Input2	*txt_205_freqtone[8];
extern Fl_Input2	*txt_205_assignment[8];
extern Fl_Input2	*txt_205_remarks[8];
extern Fl_Input2	*txt_205_preparer;

//======================================================================
// ICS-205A
//======================================================================
extern void create_ics205a_tab();

extern Fl_Group		*tab_ics205a;
extern Fl_Tabs		*tab_ics205a_type;
extern Fl_Group		*tab_205a_1;
extern Fl_Group		*tab_205a_2;

extern Fl_Input2	*txt_205a_incident;
extern Fl_Input2	*txt_205a_date_fm;
extern Fl_Button	*btn_205a_date_fm;
extern Fl_Input2	*txt_205a_date_to;
extern Fl_Button	*btn_205a_date_to;
extern Fl_Input2	*txt_205a_time_fm;
extern Fl_Button	*btn_205a_time_fm;
extern Fl_Input2	*txt_205a_time_to;
extern Fl_Button	*btn_205a_time_to;
extern Fl_Input2	*txt_205a_prepared_by;
extern Fl_Input2	*txt_205a_preparer_position;
extern Fl_Input2	*txt_205a_preparer_date_time;
extern Fl_Input2	*txt_205a_comm_group[32];
extern Fl_Input2	*txt_205a_comm_position[32];
extern Fl_Input2	*txt_205a_comm_name[32];
extern Fl_Input2	*txt_205a_comm_info[32];

//======================================================================
// ICS-206
//======================================================================
extern void create_ics206_tab();

extern Fl_Group		*tab_ics206;
extern Fl_Tabs		*tab_ics206_type;
extern Fl_Group		*tab_206_med_plan;
extern Fl_Input2	*txt_206_name;
extern Fl_Input2	*txt_206_op_period;
extern Fl_Input2	*txt_206_time_prepared;
extern Fl_Button	*btn_206_time;
extern Fl_DateInput	*txt_206_date_prepared;
extern Fl_Button	*btn_206_date;
extern Fl_Input2	*txt_206_medaid_sta[5];
extern Fl_Input2	*txt_206_medaid_loc[5];
extern Fl_Check_Button	*btn_206_medaid_paramedics[5];
extern Fl_Input2	*txt_206_preparer;
extern Fl_Input2	*txt_206_reviewer;
extern Fl_Group		*tab_206_transport;
extern Fl_Input2	*txt_206_transport_name[5];
extern Fl_Input2	*txt_206_transport_address[5];
extern Fl_Check_Button	*btn_206_transport_paramedics[5];
extern Fl_Input2	*txt_206_transport_phone[5];
extern Fl_Group		*tab_206_ambulance;
extern Fl_Input2	*txt_206_ambulance_name[5];
extern Fl_Input2	*txt_206_ambulance_loc[5];
extern Fl_Check_Button	*btn_206_ambulance_paramedics[5];
extern Fl_Group		*tab_206_hospital;
extern Fl_Input2	*txt_206_hosp_name[5];
extern Fl_Input2	*txt_206_hosp_address[5];
extern Fl_Input2	*txt_206_hosp_phone[5];
extern Fl_Input2	*txt_206_hosp_airtime[5];
extern Fl_Input2	*txt_206_hosp_gndtime[5];
extern Fl_Check_Button	*btn_206_hosp_helipad[5];
extern Fl_Check_Button	*btn_206_hosp_burn_center[5];
extern Fl_Group		*tab_206_med_proc;
extern FTextEdit	*txt_206_procedure;

//======================================================================
// ICS-213
//======================================================================
extern void create_ics213_tab();

extern Fl_Group		*tab_ics213;
extern Fl_Tabs		*tab_ics213_type;
extern Fl_Group		*tab_213_originator;
extern Fl_Input2	*txt_213_to;
extern Fl_Input2	*txt_213_p1;
extern Fl_Input2	*txt_213_fm;
extern Fl_Input2	*txt_213_p2;
extern Fl_Input2	*txt_213_subj;
extern Fl_DateInput	*txt_213_d1;
extern Fl_Button	*btn_213_date1;
extern Fl_Input2	*txt_213_t1;
extern Fl_Button	*btn_213_time1;
extern FTextEdit	*txt_213_msg;
extern Fl_Input2	*txt_213_s1;
extern Fl_Input2	*txt_213_p3;
extern Fl_Group		*tab_213_responder;
extern Fl_Input2	*txt_213_s2;
extern Fl_DateInput	*txt_213_d2;
extern Fl_Input2	*txt_213_t2;
extern Fl_Button	*btn_213_time2;
extern FTextEdit	*txt_213_reply;
extern Fl_Input2	*txt_213_p4;
extern Fl_Button	*btn_213_date2;

//======================================================================
// ICS-214
//======================================================================
extern void create_ics214_tab();

extern Fl_Group		*tab_ics214;
extern Fl_Tabs		*tab_ics214_type;
extern Fl_Group		*tab_214_1;
extern Fl_Input2	*txt_214_incident;
extern Fl_Input2	*txt_214_date;
extern Fl_Button	*btn_214_date;
extern Fl_Input2	*txt_214_time;
extern Fl_Button	*btn_214_time;
extern Fl_Input2	*txt_214_op_period;
extern Fl_Input2	*txt_214_unit_name;
extern Fl_Input2	*txt_214_unit_leader;
extern Fl_Input2	*txt_214_prepared_by;
extern Fl_Group		*tab_214_2;
extern Fl_Input2	*txt_214_roster_name[16];
extern Fl_Input2	*txt_214_roster_position[16];
extern Fl_Input2	*txt_214_roster_home_base[16];
extern Fl_Group		*tab_214_3;
extern Fl_Input2	*txt_214_activity_time[16];
extern Fl_Input2	*txt_214_activity_event[16];

//======================================================================
// ICS-216
//======================================================================
extern void create_ics216_tab();

extern Fl_Group		*tab_ics216;
extern Fl_Group		*tab_ics_216;
extern Fl_Tabs		*tab_ics216_type;
extern Fl_Group		*tab_216_1;
extern Fl_Group		*tab_216_2;
extern Fl_Group		*tab_216_3;
extern Fl_Group		*tab_216_4;
extern Fl_Group		*tab_216_5;
extern Fl_Input2	*txt_216_incident;
extern Fl_Input2	*txt_216_date;
extern Fl_Button	*btn_216_date;
extern Fl_Input2	*txt_216_time;
extern Fl_Button	*btn_216_time;
extern Fl_Input2	*txt_216_branch;
extern Fl_Input2	*txt_216_agc;
extern Fl_Input2	*txt_216_op_period;
extern Fl_Input2	*txt_216_tac_freq;
extern Fl_Input2	*txt_216_prepared_by;
extern Fl_Group		*tab_216_2;
extern Fl_Input2	*txt_216_div_grp[4];
extern Fl_Input2	*txt_216_agency[4];
extern Fl_Group		*tab_216_3;
extern Fl_Input2	*txt_216_ag[36];
extern Fl_Input2	*txt_216_id[36];
extern Fl_Input2	*txt_216_rr[36];

//======================================================================
// HICS
//======================================================================
extern Fl_Group	*tab_hics;
extern Fl_Tabs	*tab_hics_type;
extern void create_hics_tab();

//======================================================================
// HICS-203
//======================================================================
extern void create_hics203_tab();

extern Fl_Group		*tab_hics203;
extern Fl_Tabs		*tab_hics203_type;

extern Fl_Group		*tab_hics203_1;
extern Fl_Input2	*txt_hics203_incident;
extern Fl_Input2	*txt_hics203_date;
extern Fl_Button	*btn_hics203_date;
extern Fl_Input2	*txt_hics203_time;
extern Fl_Button	*btn_hics203_time;
extern Fl_Input2	*txt_hics203_op_period;

extern Fl_Input2	*txt_hics203_incident_commander;
extern Fl_Input2	*txt_hics203_incident_deputy;
extern Fl_Input2	*txt_hics203_incident_safety_officer;
extern Fl_Input2	*txt_hics203_incident_info_officer;
extern Fl_Input2	*txt_hics203_liaison_officer;
extern Fl_Input2	*txt_hics203_prepared_by;
extern Fl_Input2	*txt_hics203_facility;

extern Fl_Group		*tab_hics203_tech_spec;
extern Fl_Input2	*txt_hics203_tech_spc[];

extern Fl_Group		*tab_hics203_planning;
extern Fl_Input2	*txt_hics203_planning_chief;
extern Fl_Input2	*txt_hics203_planning_other;
extern Fl_Input2	*txt_hics203_res_unit;
extern Fl_Input2	*txt_hics203_sit_unit;
extern Fl_Input2	*txt_hics203_doc_unit;
extern Fl_Input2	*txt_hics203_dem_unit;

extern Fl_Group		*tab_hics203_logisthics;
extern Fl_Input2	*txt_hics203_log_chief;
extern Fl_Input2	*txt_hics203_log_other;
extern Fl_Input2	*txt_hics203_log_sup_brch;
extern Fl_Input2	*txt_hics203_bus_brch;
extern Fl_Input2	*txt_hics203_stg_mgr;
extern Fl_Input2	*txt_hics203_med_care_brch;
extern Fl_Input2	*txt_hics203_infr_brch;
extern Fl_Input2	*txt_hics203_sec_brch;
extern Fl_Input2	*txt_hics203_hazmat_brch;
extern Fl_Input2	*txt_hics203_hcc_agency;
extern Fl_Input2	*txt_hics203_svc_brch;
extern Fl_Input2	*txt_hics203_hcc_rep;
extern Fl_Input2	*txt_hics203_ext_loc;
extern Fl_Input2	*txt_hics203_ext_rep;
extern Fl_Group		*tab_hics203_ops;
extern Fl_Input2	*txt_hics203_ops_chief;
extern Fl_Input2	*txt_hics203_ops_other;
extern Fl_Group		*tab_hics203_admin;
extern Fl_Input2	*txt_hics203_fin_chief;
extern Fl_Input2	*txt_hics203_fin_other;
extern Fl_Input2	*txt_hics203_time_unit;
extern Fl_Input2	*txt_hics203_proc_unit;
extern Fl_Input2	*txt_hics203_comp_unit;
extern Fl_Input2	*txt_hics203_cost_unit;

//======================================================================
// HICS 206 tab
extern void create_hics206_tab();

extern Fl_Group		*h206_tab;
extern Fl_Tabs		*h206_tab_type;

extern Fl_Group		*h206_tab_plan;
extern Fl_Input2	*h206_txt_name;
extern Fl_Input2	*h206_txt_op_period;
extern Fl_Input2	*h206_txt_time_prepared;
extern Fl_Button	*h206_btn_time;
extern Fl_DateInput	*h206_txt_date_prepared;
extern Fl_Button	*h206_btn_date;

extern Fl_Input2	*h206_txt_location;
extern Fl_Input2	*h206_txt_loc_contact;
extern Fl_Input2	*h206_txt_team_leader;
extern Fl_Input2	*h206_txt_team_contact;
extern FTextEdit	*h206_txt_special_instructions;

extern Fl_Input2	*h206_txt_md_do;
extern Fl_Input2	*h206_txt_litters;
extern Fl_Input2	*h206_txt_pa_np;
extern Fl_Input2	*h206_txt_portable;
extern Fl_Input2	*h206_txt_rn_lpn;
extern Fl_Input2	*h206_txt_transport;
extern Fl_Input2	*h206_txt_tech_cn;
extern Fl_Input2	*h206_txt_wheelchairs;
extern Fl_Input2	*h206_txt_team_other;
extern Fl_Input2	*h206_txt_transport_other;
extern Fl_Input2	*h206_txt_meds_1;
extern Fl_Input2	*h206_txt_supp_1;
extern Fl_Input2	*h206_txt_meds_2;
extern Fl_Input2	*h206_txt_supp_2;
extern Fl_Input2	*h206_txt_meds_3;
extern Fl_Input2	*h206_txt_supp_3;
extern Fl_Input2	*h206_txt_meds_4;
extern Fl_Input2	*h206_txt_supp_4;
extern Fl_Input2	*h206_txt_meds_5;
extern Fl_Input2	*h206_txt_supp_5;

extern Fl_Input2	*h206_txt_site_1;
extern Fl_Input2	*h206_txt_address_1;
extern Fl_Input2	*h206_txt_phone_1;
extern Fl_Input2	*h206_txt_spec_care_1;
extern Fl_Input2	*h206_txt_site_2;
extern Fl_Input2	*h206_txt_address_2;
extern Fl_Input2	*h206_txt_phone_2;
extern Fl_Input2	*h206_txt_spec_care_2;
extern Fl_Input2	*h206_txt_site_3;
extern Fl_Input2	*h206_txt_address_3;
extern Fl_Input2	*h206_txt_phone_3;
extern Fl_Input2	*h206_txt_spec_care_3;
extern Fl_Input2	*h206_txt_site_4;
extern Fl_Input2	*h206_txt_address_4;
extern Fl_Input2	*h206_txt_phone_4;
extern Fl_Input2	*h206_txt_spec_care_4;

extern Fl_Input2	*h206_txt_preparer;
extern Fl_Input2	*h206_txt_facility;

//======================================================================
// HICS 213 tab

extern void create_hics213_tab();

extern Fl_Group			*h213_tab;
extern Fl_Tabs			*h213_tab_type;

extern Fl_Group			*tab_213_grp_orig;
extern Fl_Group			*tab_213_grp_msg;
extern Fl_Group			*tab_213_grp_action;
extern Fl_Group			*tab_213_grp_receipt1;
extern Fl_Group			*tab_213_grp_receipt2;

extern Fl_Input2		*h213_txt_to;
extern Fl_Input2		*h213_txt_fm;
extern Fl_DateInput		*h213_txt_date;
extern Fl_Button		*h213_btn_date;
extern Fl_Input2		*h213_txt_time;
extern Fl_Button		*h213_btn_time0;
extern Fl_Check_Button	*h213_btn_phone;
extern Fl_Check_Button	*h213_btn_radio;
extern Fl_Check_Button	*h213_btn_other;
extern Fl_Check_Button	*h213_btn_yes;
extern Fl_Check_Button	*h213_btn_no;
extern Fl_Check_Button	*h213_btn_high;
extern Fl_Check_Button	*h213_btn_medium;
extern Fl_Check_Button	*h213_btn_low;
extern Fl_Input2		*h213_txt_reply_to;
extern FTextEdit		*h213_txt_msg;
extern FTextEdit		*h213_txt_action;
extern Fl_Input2		*h213_txt_rcvd_by;
extern Fl_Input2		*h213_txt_time_rcvd;
extern Fl_Button		*h213_btn_time1;
extern Fl_Input2		*h213_txt_fwd_to;
extern FTextEdit		*h213_txt_comments;
extern Fl_Input2		*h213_txt_rcvd_by2;
extern Fl_Input2		*h213_txt_time_rcvd2;
extern Fl_Button		*h213_btn_time2;
extern Fl_Input2		*h213_txt_fwd_to2;
extern FTextEdit		*h213_txt_comments2;
extern Fl_Input2		*h213_txt_facility;

//======================================================================
// hics-214
//======================================================================

extern void create_hics214_tab();

extern Fl_Group			*hics214_tab;
extern Fl_Tabs			*hics214_tab_type;
extern Fl_Group			*hics214_tab_1;
extern Fl_Input2		*hics214_txt_incident;
extern Fl_Input2		*hics214_txt_date;
extern Fl_Input2		*hics214_txt_sec_brch;
extern Fl_Input2		*hics214_txt_position;
extern Fl_Button		*hics214_btn_date;
extern Fl_Input2		*hics214_txt_time;
extern Fl_Button		*hics214_btn_time;
extern Fl_Input2		*hics214_txt_op_period;
extern Fl_Input2		*hics214_txt_prepared_by;
extern Fl_Input2		*hics214_txt_facility;

extern Fl_Group			*hics214_tab_2;
extern Fl_Input2		*hics214_txt_activity_time[];
extern Fl_Input2		*hics214_txt_activity_event[];

//======================================================================
// IARU message
//======================================================================

extern void			create_iaru_tab();

extern Fl_Group		*tab_iaru;
extern Fl_Tabs		*tabs_iaru;
extern Fl_Group		*tab_iaru_message;
extern Fl_Group		*tab_iaru_information;
extern Fl_Input2	*iaru_txt_nbr;
extern Fl_Choice	*iaru_sel_prec;
extern Fl_Input2	*iaru_txt_station;
extern Fl_Input2	*iaru_txt_orig;
extern Fl_Input2	*iaru_txt_t1;
extern Fl_Button	*iaru_btn_t1;
extern Fl_Input2	*iaru_txt_d1;
extern Fl_Button	*iaru_btn_d1;
extern Fl_Input2	*iaru_txt_check;
extern Fl_Button	*iaru_btn_check;
extern Fl_Input2	*iaru_txt_to;
extern Fl_Input2	*iaru_txt_fm;
extern FTextEdit	*iaru_txt_msg;
extern Fl_Input2	*iaru_txt_rcv_fm;
extern Fl_Input2	*iaru_txt_d2;
extern Fl_Button	*iaru_btn_d2;
extern Fl_Input2	*iaru_txt_t2;
extern Fl_Button	*iaru_btn_t2;
extern Fl_Input2	*iaru_txt_sent_to;
extern Fl_Input2	*iaru_txt_d3;
extern Fl_Button	*iaru_btn_d3;
extern Fl_Input2	*iaru_txt_t3;
extern Fl_Button	*iaru_btn_t3;

//======================================================================
// Radiogram
//======================================================================
extern void			create_radiogram_tab();

extern Fl_Group		*tab_radiogram;
extern Fl_Tabs		*tabs_radiogram;
extern Fl_Group		*tab_radiogram_message;
extern Fl_Input2	*txt_rg_nbr;
extern Fl_Choice	*sel_rg_prec;
extern Fl_Input2	*txt_rg_hx;
extern Fl_Button	*btn_rg_hx;
extern Fl_Input2	*txt_rg_station;
extern Fl_Input2	*txt_rg_place;
extern Fl_Input2	*txt_rg_t1;
extern Fl_Button	*btn_rgTime1;
extern Fl_Input2	*txt_rg_d1;
extern Fl_Button	*btn_rgDate1;
extern Fl_Input2	*txt_rg_to;
extern Fl_Input2	*txt_rg_phone;
extern Fl_Input2	*txt_rg_opnote;
extern FTextEdit	*txt_rg_msg;
extern Fl_Button	*btn_arl;
extern Fl_Input2	*txt_rg_check;
extern Fl_Button	*btn_rg_check;
extern Fl_Input2	*txt_rg_sig;
extern Fl_Input2	*txt_rg_opnote2;
extern Fl_Check_Button	*btn_rg_svc;
extern Fl_Group		*tab_radiogram_information;
extern Fl_Input2	*txt_rg_orig;
extern Fl_Input2	*txt_rg_dt2;
extern Fl_Button	*btn_rgDateTime2;
extern Fl_Input2	*txt_rg_dt3;
extern Fl_Button	*btn_rgDateTime3;
extern Fl_Input2	*txt_rg_dlvd_to;
extern Fl_Input2	*txt_rg_rcv_fm;
extern Fl_Input2	*txt_rg_rcv_net;
extern Fl_Input2	*txt_rg_dt4;
extern Fl_Button	*btn_rgDateTime4;
extern Fl_Input2	*txt_rg_sent_to;
extern Fl_Input2	*txt_rg_snt_net;
extern Fl_Input2	*txt_rg_dt5;
extern Fl_Button	*btn_rgDateTime5;

extern Fl_Check_Button	*btn_rg_standard;

//======================================================================
// Plaintext
//======================================================================
extern void			create_plaintext_tab();

extern Fl_Group		*tab_plaintext;
extern Fl_Input2	*txt_pt_title;
extern Fl_Input2	*txt_pt_to;
extern Fl_Input2	*txt_pt_fm;
extern Fl_Input2	*txt_pt_subj;
extern FTextEdit	*txt_pt_msg;
extern Fl_DateInput	*txt_pt_date;
extern Fl_Button	*btn_pt_date;
extern Fl_Input2	*txt_pt_time;
extern Fl_Button	*btn_pt_time;

//======================================================================
// Blank
//======================================================================
extern void			create_blank_tab();

extern Fl_Group		*tab_blank;
extern FTextEdit	*txt_blank_msg;

//======================================================================
// CSV
//======================================================================
extern void			create_csv_tab();

extern Fl_Group		*tab_csv;
extern FTextEdit	*txt_csv_msg;

//======================================================================
// Drag-n-Drop
//======================================================================
extern void			create_dnd_tab();

extern Fl_Group		*tab_dnd;
extern Fl_Input		*drop_box;

//======================================================================
// MARS tab
//======================================================================

extern void			create_mars_tab();

extern Fl_Group		*tab_mars;
extern Fl_Tabs		*tab_mars_type;

extern string mars_list_lname;
extern string mars_list_call;
extern string mars_list_state;
extern string mars_list_bcall;
extern string mars_list_position;

extern bool get_mars_list_text();

extern void cb_mars_fl_input2(Fl_Widget *w, void *d);
extern void cb_mars_text(Fl_Widget *w, void *d);
extern string notail(string s);
extern string maxchars(string s, unsigned int n, int indent = 0);

//======================================================================
// MARS daily
//======================================================================

extern void			create_mars_daily();

extern Fl_Group		*tab_mars_daily;
extern Fl_Tabs		*tab_mars_daily_type;
extern Fl_Group		*tab_mars_daily_1;
extern Fl_Input2	*txt_mars_daily_incident;
extern Fl_Input2	*txt_mars_daily_de;
extern Fl_Button	*btn_mars_daily_de_me;
extern Fl_Input2	*txt_mars_daily_nbr;
extern Fl_Choice	*sel_mars_daily_prec;
extern Fl_Input2	*txt_mars_daily_dtg;
extern Fl_Button	*btn_mars_daily_dtg;
extern Fl_Input2	*txt_mars_daily_fm_name;
extern Fl_Input2	*txt_mars_daily_fm_call;
extern Fl_Input2	*txt_mars_daily_fm_state;
extern Fl_Button	*btn_mars_daily_pick_fm;
extern Fl_Input2	*txt_mars_daily_to_pos;
extern Fl_Input2	*txt_mars_daily_to_call;
extern Fl_Input2	*txt_mars_daily_to_state;
extern Fl_Button	*btn_mars_daily_pick_to;
extern Fl_Input2	*txt_mars_daily_pos1;
extern Fl_Input2	*txt_mars_daily_call1;
extern Fl_Input2	*txt_mars_daily_state1;
extern Fl_Button	*btn_mars_daily_pick_info1;
extern Fl_Input2	*txt_mars_daily_pos2;
extern Fl_Input2	*txt_mars_daily_call2;
extern Fl_Input2	*txt_mars_daily_state2;
extern Fl_Button	*btn_mars_daily_pick_info2;
extern Fl_Input2	*txt_mars_daily_pos3;
extern Fl_Input2	*txt_mars_daily_call3;
extern Fl_Input2	*txt_mars_daily_state3;
extern Fl_Button	*btn_mars_daily_pick_info3;
extern Fl_Group 	*tab_mars_daily_2;
extern Fl_Input2	*txt_mars_daily_sitrep_id;
extern Fl_Input2	*txt_mars_daily_sitrep_loc;
extern Fl_Input2	*txt_mars_daily_dtg_24hr;
extern Fl_Button	*btn_mars_daily_dtg_24hr;
extern Fl_Input2	*txt_mars_daily_netcall;
extern Fl_Choice	*sel_mars_daily_e_x;
extern Fl_Input2	*txt_mars_daily_dtg_active;
extern Fl_Button	*btn_mars_daily_dtg_active;
extern Fl_Input2	*txt_mars_daily_dtg_deactive;
extern Fl_Button	*btn_mars_daily_dtg_deactive;
extern Fl_Input2	*txt_mars_daily_nbr_stations;
extern Fl_Input2	*txt_mars_daily_details;
extern Fl_Input2	*txt_mars_daily_activations;
extern Fl_Input2	*txt_mars_daily_agencies;
extern Fl_Input2	*txt_mars_daily_remarks;

//======================================================================
// MARS ineei
//======================================================================

extern void			create_mars_ineei();

extern Fl_Group		*tab_mars_ineei;
extern Fl_Tabs		*tab_mars_ineei_type;

extern Fl_Group		*tab_mars_ineei_1;

extern Fl_Input2	*txt_mars_ineei_DE;
extern Fl_Input2	*txt_mars_ineei_NBR;
extern Fl_Choice	*sel_mars_ineei_PREC;
extern Fl_Input2	*txt_mars_ineei_DTG;
extern Fl_Input2	*txt_mars_ineei_FMNAME;
extern Fl_Input2	*txt_mars_ineei_FMCALL;
extern Fl_Input2	*txt_mars_ineei_FMSTATE;
extern Fl_Input2	*txt_mars_ineei_TOPOS;
extern Fl_Input2	*txt_mars_ineei_TOCALL;
extern Fl_Input2	*txt_mars_ineei_TOSTATE;
extern Fl_Input2	*txt_mars_ineei_INFO1POS;
extern Fl_Input2	*txt_mars_ineei_INFO1CALL;
extern Fl_Input2	*txt_mars_ineei_INFO1STATE;
extern Fl_Input2	*txt_mars_ineei_INFO2POS;
extern Fl_Input2	*txt_mars_ineei_INFO2CALL;
extern Fl_Input2	*txt_mars_ineei_INFO2STATE;
extern Fl_Input2	*txt_mars_ineei_INCIDENT;
 
extern Fl_Group		*tab_mars_ineei_2;

extern Fl_Input2	*txt_mars_ineei_REF;
extern Fl_Input2	*txt_mars_ineei_STATE;
extern Fl_Input2	*txt_mars_ineei_1A_INCIDENT;
extern Fl_Input2	*txt_mars_ineei_1A_LOCATION;
extern Fl_Input2	*txt_mars_ineei_1A_TIME;
extern Fl_Input2	*txt_mars_ineei_1B_MEDFACSTS;
extern Fl_Input2	*txt_mars_ineei_1C_TRNPSTS;
extern Fl_Input2	*txt_mars_ineei_1D_DAMAGE;
extern Fl_Input2	*txt_mars_ineei_1E_UTILSTS;
extern Fl_Input2	*txt_mars_ineei_1F_COMMSTS;
extern Fl_Input2	*txt_mars_ineei_1G_INFOSRC;
extern Fl_Input2	*txt_mars_ineei_1G_INFOTIME;
extern Fl_Input2	*txt_mars_ineei_1H_REMARKS;

//======================================================================
// MARS net
//======================================================================

extern void			create_mars_net();

extern Fl_Group		*tab_mars_net;
extern Fl_Tabs		*tab_mars_net_type;

extern Fl_Group		*tab_mars_net_1;
extern Fl_Group		*tab_mars_net_2;

extern Fl_Input2	*txt_mars_net_DE;
extern Fl_Input2	*txt_mars_net_NBR;
extern Fl_Choice	*sel_mars_net_PREC;
extern Fl_Input2	*txt_mars_net_DTG;
extern Fl_Input2	*txt_mars_net_FMNAME;
extern Fl_Input2	*txt_mars_net_FMCALL;
extern Fl_Input2	*txt_mars_net_FMSTATE;
extern Fl_Input2	*txt_mars_net_TOPOS;
extern Fl_Input2	*txt_mars_net_TOCALL;
extern Fl_Input2	*txt_mars_net_TOSTATE;
extern Fl_Input2	*txt_mars_net_INFOPOS;
extern Fl_Input2	*txt_mars_net_INFOCALL;
extern Fl_Input2	*txt_mars_net_INFOSTATE;
extern Fl_Input2	*txt_mars_net_INCIDENT;
extern Fl_Input2	*txt_mars_net_DND;
extern Fl_Input2	*txt_mars_net_NETCALL;
extern Fl_Input2	*txt_mars_net_DTGSTART;
extern Fl_Input2	*txt_mars_net_DTGEND;
extern Fl_Input2	*txt_mars_net_NETSB;
extern Fl_Input2	*txt_mars_net_NCSCALL;
extern Fl_Input2	*txt_mars_net_NBRSTAS;
extern Fl_Input2	*txt_mars_net_CALLS;
extern Fl_Input2	*txt_mars_net_NBRMSGS;
extern Fl_Input2	*txt_mars_net_COMMENTS;

//======================================================================
// MARS Army Standard Message
//======================================================================

extern void			create_mars_army();

extern Fl_Group		*tab_mars_army;

extern Fl_Tabs		*tab_mars_army_type;
extern Fl_Group		*tab_mars_army_1;
extern Fl_Group		*tab_mars_army_2;

extern Fl_Input2	*txt_mars_army_de;
extern Fl_Input2	*txt_mars_army_nbr;

extern Fl_Input2	*txt_mars_army_dtg;
extern Fl_Input2	*txt_mars_army_fm;
extern Fl_Input2	*txt_mars_army_subj;

extern FTextEdit	*txt_mars_army_to;
extern FTextEdit	*txt_mars_army_info;
extern FTextEdit	*txt_mars_army_text;

extern Fl_Button	*btn_mars_army_dtg;
extern Fl_Button	*btn_mars_army_pick_fm;
extern Fl_Button	*btn_mars_army_pick_to;
extern Fl_Button	*btn_mars_army_pick_info;

extern Fl_Choice	*sel_mars_army_prec;

//======================================================================
// MARS Navy Standard Message
//======================================================================

extern void			create_mars_navy();

extern Fl_Group		*tab_mars_navy;

extern Fl_Tabs		*tab_mars_navy_type;
extern Fl_Group		*tab_mars_navy_1;
extern Fl_Group		*tab_mars_navy_2;

extern Fl_Input2	*txt_mars_navy_dtg;
extern Fl_Input2	*txt_mars_navy_fm;
extern Fl_Input2	*txt_mars_navy_subj;

extern FTextEdit	*txt_mars_navy_to;
extern FTextEdit	*txt_mars_navy_info;
extern FTextEdit	*txt_mars_navy_text;

extern Fl_Button	*btn_mars_navy_dtg;
extern Fl_Button	*btn_mars_navy_pick_fm;
extern Fl_Button	*btn_mars_navy_pick_to;
extern Fl_Button	*btn_mars_navy_pick_info;

extern Fl_Choice	*sel_mars_navy_prec;

//======================================================================
// National Hurricane Center, Hurricane Weather Report Form
//======================================================================

extern void create_wxhc_tab();

extern Fl_Group	*tab_wxhc;
extern Fl_Tabs	*tab_wxhc_type;

extern Fl_Group	*tab_wxhc_1;

extern Fl_Input2	*w_wxhc_rptsta;
extern Fl_Input2	*w_wxhc_email;
extern Fl_Input2	*w_wxhc_phone;
extern Fl_Input2	*w_wxhc_addr;
extern Fl_Input2	*w_wxhc_city;
extern Fl_Input2	*w_wxhc_state;
extern Fl_Input2	*w_wxhc_country;
extern Fl_Input2	*w_wxhc_lat;
extern Fl_Input2	*w_wxhc_long;
extern Fl_Input2	*w_wxhc_date;
extern Fl_Input2	*w_wxhc_time;
extern Fl_Check_Button *w_wxhc_meas;
extern Fl_Check_Button *w_wxhc_est;
extern Fl_Input2	*w_wxhc_wind_speed;
extern Fl_ComboBox	*w_wxhc_wind_speed_units;
extern Fl_Input2	*w_wxhc_wind_gusts;
extern Fl_ComboBox	*w_wxhc_wind_gusts_units;
extern Fl_ComboBox	*w_wxhc_wind_dir;
extern Fl_Input2	*w_wxhc_wind_degrees;
extern Fl_Input2	*w_wxhc_baro_press;
extern Fl_ComboBox	*w_wxhc_baro_units;

extern Fl_Group	*tab_wxhc_2;

extern FTextEdit	*w_wxhc_comments;

//======================================================================
// Red Cross
//======================================================================

extern void			create_redx_tab();

//----------------------------------------------------------------------
// Safety and Welfare
//----------------------------------------------------------------------

extern void			create_redx_snw();

extern Fl_Group		*tab_redx;
extern Fl_Tabs		*tab_redx_type;

extern Fl_Group		*tab_redx_snw;
extern Fl_Tabs		*tab_redx_snw_type;

//----------------------------------------------------------------------

extern Fl_Group		*tab_redx_snw_1;

extern Fl_Input2	*snw_lname;
extern Fl_Input2	*snw_fname;
extern Fl_Input2	*snw_area1;

extern Fl_Check_Button *snw_nophone;
extern Fl_Input2	*snw_xchg1;
extern Fl_Input2	*snw_suffix1;
extern Fl_Input2	*snw_area2;
extern Fl_Input2	*snw_xchg2;
extern Fl_Input2	*snw_suffix2;
extern Fl_Input2	*snw_area3;
extern Fl_Input2	*snw_xchg3;
extern Fl_Input2	*snw_suffix3;

extern Fl_Input2	*snw_pdline1;
extern Fl_Input2	*snw_pdline2;
extern Fl_Input2	*snw_pdcity;
extern Fl_Input2	*snw_pdst;
extern Fl_Input2	*snw_pdzip;
extern Fl_Input2	*snw_haline1;
extern Fl_Input2	*snw_haline2;
extern Fl_Input2	*snw_hacity;
extern Fl_Input2	*snw_hast;
extern Fl_Input2	*snw_hazip;

//----------------------------------------------------------------------

extern Fl_Group	*tab_redx_snw_2;

extern Fl_Check_Button *snw_m1;
extern Fl_Check_Button *snw_m2;
extern Fl_Check_Button *snw_m3;
extern Fl_Check_Button *snw_m4;
extern Fl_Check_Button *snw_m5;
extern Fl_Check_Button *snw_m6;
extern Fl_Check_Button *snw_m7;

//----------------------------------------------------------------------

extern Fl_Group	*tab_redx_snw_3;
extern Fl_Check_Button *snw_m8;
extern Fl_Check_Button *snw_m9;
extern Fl_Check_Button *snw_m10;
extern Fl_Check_Button *snw_m11;
extern Fl_Check_Button *snw_m12;
extern Fl_Check_Button *snw_m13;
extern Fl_Check_Button *snw_m14;

//----------------------------------------------------------------------

extern Fl_Group			*tab_redx_snw_4;
extern Fl_Check_Button	*snw_m15;
extern FTextEdit		*snw_cmsg;

//======================================================================
// Red Cross 5739
//======================================================================

extern void create_redx_5739();

extern void redx_5739_compute(Fl_Widget * w, void *);

extern Fl_Group		*tab_redx_5739;
extern Fl_Tabs		*tab_redx_5739_type;

extern Fl_Input2	*rdx_5739_nbr;
extern Fl_Input2	*rdx_5739_name;
extern Fl_Input2	*rdx_5739_state;
extern Fl_Input2	*rdx_5739_cnty;
extern Fl_Input2	*rdx_5739_city;
extern Fl_Input2	*rdx_5739_date;
extern Fl_Input2	*rdx_5739_street;
extern Fl_Input2	*rdx_5739_georef;
extern FTextEdit	*rdx_5739_add_info;
extern Fl_Input2	*rdx_5739_worker;
extern Fl_Input2	*rdx_5739_supervisor;

//----------------------------------------------------------------------

extern Fl_Input2	*rdx_sf_destroyed;
extern Fl_Input2	*rdx_sf_major;
extern Fl_Input2	*rdx_sf_minor;
extern Fl_Input2	*rdx_sf_affected;
extern Fl_Input2	*rdx_sf_inaccessible;

//----------------------------------------------------------------------

extern Fl_Input2	*rdx_mh_destroyed;
extern Fl_Input2	*rdx_mh_major;
extern Fl_Input2	*rdx_mh_minor;
extern Fl_Input2	*rdx_mh_affected;
extern Fl_Input2	*rdx_mh_inaccessible;

//----------------------------------------------------------------------

extern Fl_Input2	*rdx_ap_destroyed;
extern Fl_Input2	*rdx_ap_major;
extern Fl_Input2	*rdx_ap_minor;
extern Fl_Input2	*rdx_ap_affected;
extern Fl_Input2	*rdx_ap_inaccessible;

//----------------------------------------------------------------------

extern Fl_Input2	*redx_5739_house_nbr[];
extern Fl_Input2	*redx_5739_apt_nbr[];
extern Fl_Input2	*redx_5739_desc[];
extern Fl_Input2	*redx_5739_nam[];
extern Fl_Input2	*redx_5739_destroyed[];
extern Fl_Input2	*redx_5739_major[];
extern Fl_Input2	*redx_5739_minor[];
extern Fl_Input2	*redx_5739_affected[];
extern Fl_Input2	*redx_5739_inaccessible[];
extern Fl_Input2	*redx_5739_floors[];
extern Fl_Input2	*redx_5739_basement[];
extern Fl_Input2	*redx_5739_waterlevel[];
extern Fl_Input2	*redx_5739_basement_water[];
extern Fl_Input2	*redx_5739_electricity[];
extern Fl_Input2	*redx_5739_occupancy[];
extern Fl_Input2	*redx_5739_OR[];
extern Fl_Input2	*redx_5739_901[];

//======================================================================
// Red Cross 5739A
//======================================================================

extern void create_redx_5739A();

extern Fl_Group	*tab_redx_5739A;
extern Fl_Tabs		*tab_redx_5739A_type;

extern Fl_Group	*tab_redx_5739A_1;

extern Fl_Input2	*rdx_5739A_nbr;
extern Fl_Input2	*rdx_5739A_name;
extern Fl_Input2	*rdx_5739A_state;
extern Fl_Input2	*rdx_5739A_cnty;
extern Fl_Input2	*rdx_5739A_city;
extern Fl_Input2	*rdx_5739A_date;
extern Fl_Input2	*rdx_5739A_street;
extern Fl_Input2	*rdx_5739A_georef;

extern Fl_Group	*tab_redx_5739A_2;

extern Fl_Input2	*rdx_5739A_adrs0;
extern Fl_Input2	*rdx_5739A_dwell0;
extern Fl_Input2	*rdx_5739A_base0;
extern Fl_Input2	*rdx_5739A_ds0;
extern Fl_Input2	*rdx_5739A_mj0;
extern Fl_Input2	*rdx_5739A_mn0;
extern Fl_Input2	*rdx_5739A_af0;
extern Fl_Input2	*rdx_5739A_in0;
extern Fl_Input2	*rdx_5739A_un0;
extern Fl_Input2	*rdx_5739A_gd0;

extern Fl_Group	*tab_redx_5739A_3;

extern Fl_Input2	*rdx_5739A_adrs1;
extern Fl_Input2	*rdx_5739A_dwell1;
extern Fl_Input2	*rdx_5739A_base1;
extern Fl_Input2	*rdx_5739A_ds1;
extern Fl_Input2	*rdx_5739A_mj1;
extern Fl_Input2	*rdx_5739A_mn1;
extern Fl_Input2	*rdx_5739A_af1;
extern Fl_Input2	*rdx_5739A_in1;
extern Fl_Input2	*rdx_5739A_un1;
extern Fl_Input2	*rdx_5739A_gd1;

//======================================================================
// Red Cross 5739A
//======================================================================

extern void create_redx_5739B();

extern Fl_Group	*tab_redx_5739B;
extern Fl_Tabs		*tab_redx_5739B_type;

extern Fl_Group	*tab_redx_5739B_1;

extern Fl_Input2	*rdx_5739B_nbr;
extern Fl_Input2	*rdx_5739B_name;
extern Fl_Input2	*rdx_5739B_state;
extern Fl_Input2	*rdx_5739B_cnty;
extern Fl_Input2	*rdx_5739B_city;
extern Fl_Input2	*rdx_5739B_date;
extern Fl_Input2	*rdx_5739B_street;
extern Fl_Input2	*rdx_5739B_georef;

extern Fl_Input2	*rdx_5739B_north;
extern Fl_Input2	*rdx_5739B_east;
extern Fl_Input2	*rdx_5739B_south;
extern Fl_Input2	*rdx_5739B_west;

extern Fl_Group	*tab_redx_5739B_2;

extern Fl_Input2	*rdx_5739B_dwell;
extern Fl_Input2	*rdx_5739B_ds;
extern Fl_Input2	*rdx_5739B_mj;
extern Fl_Input2	*rdx_5739B_mn;
extern Fl_Input2	*rdx_5739B_af;
extern Fl_Input2	*rdx_5739B_in;
extern Fl_Input2	*rdx_5739B_un;
extern Fl_Input2	*rdx_5739B_bs;
extern Fl_Input2	*rdx_5739B_gi;

//======================================================================

#endif
