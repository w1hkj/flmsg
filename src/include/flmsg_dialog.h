// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#ifndef FLMSG_DIALOG_H
#define FLMSG_DIALOG_H

#include <string>
#include <vector>

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
#include "mongoose.h"

extern Fl_Output	*txt_filename;
extern Fl_Input		*drop_box;
extern Fl_Input		*drop_file;

extern int tab_top;

extern Fl_Tabs	*tabs_msg_type;

//======================================================================

extern Fl_Double_Window* flmsg_dialog();
extern Fl_Menu_Item menu_[];
extern void load_custom_menu();

extern Fl_Browser	*brwsOptions;

extern Fl_Double_Window* create_config_dialog();
extern Fl_Tabs		*tabs_config;
extern Fl_Group	*tab_date_time;
extern Fl_Group	*tab_personal;
extern Fl_Group	*tab_config_radiogram;
extern Fl_Group	*tab_files;
extern Fl_Group	*tab_headers;
extern Fl_Group	*tab_socket;

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

//extern Fl_Double_Window* date_time_dialog();
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
extern Fl_Check_Button *btn_caplocal;

//extern Fl_Double_Window* personal_dialog();
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
extern Fl_Output*	txt_web_port;

//extern Fl_Double_Window* radiogram_dialog();
extern Fl_Spinner	*cnt_wpl;
extern Fl_Check_Button	*btn_rgnbr_fname;
extern Fl_Input2	*txt_rgnbr;

//extern Fl_Double_Window* config_files_dialog();
extern Fl_Check_Button	*btn_open_on_export;
extern Fl_Check_Button	*btn_use_compression;
extern Fl_Check_Button	*btn_call_fname;
extern Fl_Check_Button	*btn_dt_fname;
extern Fl_Check_Button	*btn_sernbr_fname;
extern Fl_Input2	*txt_sernbr;
extern Fl_Input2	*txt_mars_roster_file;

extern Fl_Double_Window* hx_dialog();
extern Fl_ListBox	*sel_hx_select;
extern Fl_Button	*btn_hx_select_add;
extern Fl_Input2	*txt_hx_select_text;
extern Fl_Button	*btn_hx_select_cancel;
extern Fl_Return_Button	*btn_hx_select_ok;
extern Fl_Output	*txt_hx_instructions;

//extern Fl_Double_Window* socket_dialog();
extern Fl_Input2 * txt_socket_addr;
extern Fl_Input2 * txt_socket_port;
extern Fl_Button * btn_close_socket_dialog;


extern void select_form(int form);

extern Fl_Output *txt_xfr_size_time;
extern int transfer_size;

extern Fl_ListBox	*cbo_modes;

extern void clear_estimate();
extern void estimate();
extern bool valid_mode_check(string &md);
extern void update_cbo_modes(string &fldigi_modes);

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
extern Fl_Input2	*txt_203_agency[];
extern Fl_Input2	*txt_203_agency_name[];
extern Fl_Group		*tab_203_planning;
extern Fl_Input2	*txt_203_planning_chief;
extern Fl_Input2	*txt_203_planning_deputy;
extern Fl_Input2	*txt_203_resources_unit;
extern Fl_Input2	*txt_203_situation_unit;
extern Fl_Input2	*txt_203_documentation_unit;
extern Fl_Input2	*txt_203_demobilization_unit;
extern Fl_Input2	*txt_203_tech_spc[];
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
extern Fl_Input2	*txt_203_b1_div[];
extern Fl_Input2	*txt_203_b1_grp[];
extern Fl_Group		*tab_203_opsB;
extern Fl_Input2	*txt_203_b2_director;
extern Fl_Input2	*txt_203_b2_deputy;
extern Fl_Input2	*txt_203_b2_div[];
extern Fl_Input2	*txt_203_b2_grp[];
extern Fl_Group		*tab_203_opsC;
extern Fl_Input2	*txt_203_b3_director;
extern Fl_Input2	*txt_203_b3_deputy;
extern Fl_Input2	*txt_203_b3_div[];
extern Fl_Input2	*txt_203_b3_grp[];
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
extern Fl_Tabs		*tabs_ics205;
extern Fl_Group		*tab_205_1;
extern Fl_Group		*tab_205_2;
extern Fl_Input2	*txt_205_name;
extern Fl_Input2	*txt_205_dt_prepared;
extern Fl_Button	*btn_205_dt_prepared;
extern Fl_Input2	*txt_205_dt_op_from;
extern Fl_Button	*btn_205_dt_op_from;
extern Fl_Input2	*txt_205_dt_op_to;
extern Fl_Button	*btn_205_dt_op_to;
extern Fl_Input2	*txt_205_func[];
extern Fl_Input2	*txt_205_channel[];
extern Fl_Input2	*txt_205_assign[];
extern Fl_Input2	*txt_205_rx_freq[];
extern Fl_Input2	*txt_205_rx_tone[];
extern Fl_Input2	*txt_205_tx_freq[];
extern Fl_Input2	*txt_205_tx_tone[];
extern Fl_Input2	*txt_205_mode_adm[];
extern Fl_Input2	*txt_205_remarks[];
extern Fl_Input2	*txt_205_preparer;
extern Fl_Input2	*txt_205_county;
extern Fl_Input2	*txt_205_state;
extern Fl_Input2	*txt_205_latitude;
extern Fl_Input2	*txt_205_longitude;


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
extern Fl_Input2	*txt_205a_comm_group[];
extern Fl_Input2	*txt_205a_comm_position[];
extern Fl_Input2	*txt_205a_comm_name[];
extern Fl_Input2	*txt_205a_comm_info[];

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
extern Fl_Input2	*txt_206_medaid_sta[];
extern Fl_Input2	*txt_206_medaid_loc[];
extern Fl_Check_Button	*btn_206_medaid_paramedics[];
extern Fl_Input2	*txt_206_preparer;
extern Fl_Input2	*txt_206_reviewer;
extern Fl_Group		*tab_206_transport;
extern Fl_Input2	*txt_206_transport_name[];
extern Fl_Input2	*txt_206_transport_address[];
extern Fl_Check_Button	*btn_206_transport_paramedics[];
extern Fl_Input2	*txt_206_transport_phone[];
extern Fl_Group		*tab_206_ambulance;
extern Fl_Input2	*txt_206_ambulance_name[];
extern Fl_Input2	*txt_206_ambulance_loc[];
extern Fl_Check_Button	*btn_206_ambulance_paramedics[];
extern Fl_Group		*tab_206_hospital;
extern Fl_Input2	*txt_206_hosp_name[];
extern Fl_Input2	*txt_206_hosp_address[];
extern Fl_Input2	*txt_206_hosp_phone[];
extern Fl_Input2	*txt_206_hosp_airtime[];
extern Fl_Input2	*txt_206_hosp_gndtime[];
extern Fl_Check_Button	*btn_206_hosp_helipad[];
extern Fl_Check_Button	*btn_206_hosp_burn_center[];
extern Fl_Group		*tab_206_med_proc;
extern FTextEdit	*txt_206_procedure;

//======================================================================
// ICS-213
//======================================================================
extern void create_ics213_tab();

extern Fl_Group		*tab_ics213;
extern Fl_Tabs			*tab_ics213_type;
extern Fl_Group		*tab_213_originator;
extern Fl_Input2		*txt_213_inc;
extern Fl_Input2		*txt_213_to;
extern Fl_Input2		*txt_213_p1;
extern Fl_Input2		*txt_213_fm;
extern Fl_Input2		*txt_213_p2;
extern Fl_Input2		*txt_213_subj;
extern Fl_DateInput	*txt_213_d1;
extern Fl_Button		*btn_213_date1;
extern Fl_Input2		*txt_213_t1;
extern Fl_Button		*btn_213_time1;
extern FTextEdit		*txt_213_msg;
extern Fl_Input2		*txt_213_s1;
extern Fl_Input2		*txt_213_p3;
extern Fl_Group		*tab_213_responder;
extern Fl_Input2		*txt_213_s2;
extern Fl_DateInput	*txt_213_d2;
extern Fl_Input2		*txt_213_t2;
extern Fl_Button		*btn_213_time2;
extern FTextEdit		*txt_213_reply;
extern Fl_Input2		*txt_213_p4;
extern Fl_Button		*btn_213_date2;

//======================================================================
// ICS-214
//======================================================================
extern void create_ics214_tab();

extern Fl_Group	*tab_ics214;
extern Fl_Tabs		*tab_ics214_type;
extern Fl_Group	*tab_214_1;
extern Fl_Input2	*txt_214_incident;
extern Fl_Input2	*txt_214_date;
extern Fl_Button	*btn_214_date;
extern Fl_Input2	*txt_214_time;
extern Fl_Button	*btn_214_time;
extern Fl_Input2	*txt_214_op_period;
extern Fl_Input2	*txt_214_unit_name;
extern Fl_Input2	*txt_214_unit_leader;
extern Fl_Input2	*txt_214_prepared_by;
extern Fl_Group	*tab_214_2;
extern Fl_Input2	*txt_214_roster_name[];
extern Fl_Input2	*txt_214_roster_position[];
extern Fl_Input2	*txt_214_roster_home_base[];
extern Fl_Group	*tab_214_3;
extern Fl_Input2	*txt_214_activity_time[];
extern Fl_Input2	*txt_214_activity_event[];

//======================================================================
// ICS-216
//======================================================================
extern void create_ics216_tab();

extern Fl_Group	*tab_ics216;
extern Fl_Group	*tab_ics_216;
extern Fl_Tabs		*tab_ics216_type;
extern Fl_Group	*tab_216_1;
extern Fl_Group	*tab_216_2;
extern Fl_Group	*tab_216_3;
extern Fl_Group	*tab_216_4;
extern Fl_Group	*tab_216_5;
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
extern Fl_Group	*tab_216_2;
extern Fl_Input2	*txt_216_div_grp[];
extern Fl_Input2	*txt_216_agency[];
extern Fl_Group	*tab_216_3;
extern Fl_Input2	*txt_216_ag[];
extern Fl_Input2	*txt_216_id[];
extern Fl_Input2	*txt_216_rr[];

//======================================================================
// ICS-309
//======================================================================
extern void create_ics309_tab();

extern Fl_Group	*tab_ics309;
extern Fl_Tabs		*tab_ics309_type;
extern Fl_Group	*tab_309_1;
extern Fl_Input2	*txt_309_incident;
extern Fl_Input2	*txt_309_date_fm;
extern Fl_Button	*btn_309_date_fm;
extern Fl_Input2	*txt_309_date_to;
extern Fl_Button	*btn_309_date_to;
extern Fl_Input2	*txt_309_time_fm;
extern Fl_Button	*btn_309_time_fm;
extern Fl_Input2	*txt_309_time_to;
extern Fl_Button	*btn_309_time_to;

extern Fl_Input2	*txt_309_prepared_by;
extern Fl_Input2	*txt_309_radio_net;
extern Fl_Input2	*txt_309_radio_operator;
extern Fl_Input2	*txt_309_preparer_date_time;

extern Fl_Group	*tab_309_2;
extern Fl_Input2	*txt_309_comm_time[];
extern Fl_Input2	*txt_309_comm_from[];
extern Fl_Input2	*txt_309_comm_to[];
extern Fl_Input2	*txt_309_comm_msg[];

//======================================================================
// ICS-netlog
//======================================================================
extern void create_hamform_tab();

extern void create_netlog_tab();

extern Fl_Group		*tab_netlog;
extern Fl_Tabs		*tab_netlog_type;
extern Fl_Group		*tab_netlog_1;
extern Fl_Input2	*txt_netlog_event;
extern Fl_Input2	*txt_netlog_date_fm;
extern Fl_Button	*btn_netlog_date_fm;
extern Fl_Input2	*txt_netlog_date_to;
extern Fl_Button	*btn_netlog_date_to;
extern Fl_Input2	*txt_netlog_time_fm;
extern Fl_Button	*btn_netlog_time_fm;
extern Fl_Input2	*txt_netlog_time_to;
extern Fl_Button	*btn_netlog_time_to;

extern Fl_Input2	*txt_netlog_prepared_by;
extern Fl_Input2	*txt_netlog_radio_net;
extern Fl_Input2	*txt_netlog_radio_operator;
extern Fl_Input2	*txt_netlog_preparer_date_time;

extern Fl_Group	*tab_netlog_2;
extern Fl_Input2	*txt_netlog_comm_time[];
extern Fl_Input2	*txt_netlog_comm_from[];
extern Fl_Input2	*txt_netlog_comm_to[];
extern Fl_Input2	*txt_netlog_comm_msg[];

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

extern Fl_Group	*tab_hics203;
extern Fl_Tabs		*tab_hics203_type;

extern Fl_Group	*tab_hics203_1;
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

extern Fl_Group	*tab_hics203_tech_spec;
extern Fl_Input2	*txt_hics203_tech_spc[];

extern Fl_Group	*tab_hics203_planning;
extern Fl_Input2	*txt_hics203_planning_chief;
extern Fl_Input2	*txt_hics203_planning_other;
extern Fl_Input2	*txt_hics203_res_unit;
extern Fl_Input2	*txt_hics203_sit_unit;
extern Fl_Input2	*txt_hics203_doc_unit;
extern Fl_Input2	*txt_hics203_dem_unit;

extern Fl_Group	*tab_hics203_logisthics;
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
extern Fl_Group	*tab_hics203_ops;
extern Fl_Input2	*txt_hics203_ops_chief;
extern Fl_Input2	*txt_hics203_ops_other;
extern Fl_Group	*tab_hics203_admin;
extern Fl_Input2	*txt_hics203_fin_chief;
extern Fl_Input2	*txt_hics203_fin_other;
extern Fl_Input2	*txt_hics203_time_unit;
extern Fl_Input2	*txt_hics203_proc_unit;
extern Fl_Input2	*txt_hics203_comp_unit;
extern Fl_Input2	*txt_hics203_cost_unit;

//======================================================================
// HICS 206 tab
extern void create_hics206_tab();

extern Fl_Group	*h206_tab;
extern Fl_Tabs		*h206_tab_type;

extern Fl_Group	*h206_tab_plan;
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
extern Fl_ListBox	*iaru_sel_prec;
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
extern Fl_ListBox	*sel_rg_prec;
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
extern FTextEdit		*txt_blank_msg;

//======================================================================
// CSV
//======================================================================
extern void			create_csv_tab();

extern Fl_Group		*tab_csv;
extern FTextEdit		*txt_csv_msg;

//======================================================================
// CUSTOM
//======================================================================
extern int num_custom_entries;
extern int custom_select;

extern void			create_custom_tab();
extern Fl_Group		*tab_custom;
extern FTextView		*txt_custom_msg;

extern void get_html_vars(struct mg_connection *conn);
extern void custom_editor(struct mg_connection *conn);
extern void custom_viewer(struct mg_connection *conn);

extern void			create_custom_transfer_tab();
extern Fl_Group		*tab_custom_transfer;

extern Fl_ListBox *custom_selector;
extern Fl_Output  * txt_rcvd_custom_html_filename;
extern Fl_Button  * btn_save_custom_html_file;
extern vector<string> custom_files;

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
extern Fl_ListBox	*sel_mars_daily_prec;
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
extern Fl_ListBox	*sel_mars_daily_e_x;
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
extern Fl_ListBox	*sel_mars_ineei_PREC;
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
extern Fl_Input2	*txt_mars_ineei_INFO3POS;
extern Fl_Input2	*txt_mars_ineei_INFO3CALL;
extern Fl_Input2	*txt_mars_ineei_INFO3STATE;
extern Fl_Input2	*txt_mars_ineei_INFO4POS;
extern Fl_Input2	*txt_mars_ineei_INFO4CALL;
extern Fl_Input2	*txt_mars_ineei_INFO4STATE;
extern Fl_Input2	*txt_mars_ineei_INFO5POS;
extern Fl_Input2	*txt_mars_ineei_INFO5CALL;
extern Fl_Input2	*txt_mars_ineei_INFO5STATE;
extern Fl_Input2	*txt_mars_ineei_INFO6POS;
extern Fl_Input2	*txt_mars_ineei_INFO6CALL;
extern Fl_Input2	*txt_mars_ineei_INFO6STATE;
extern Fl_Input2	*txt_mars_ineei_INFO7POS;
extern Fl_Input2	*txt_mars_ineei_INFO7CALL;
extern Fl_Input2	*txt_mars_ineei_INFO7STATE;
extern Fl_Input2	*txt_mars_ineei_INFO8POS;
extern Fl_Input2	*txt_mars_ineei_INFO8CALL;
extern Fl_Input2	*txt_mars_ineei_INFO8STATE;
extern Fl_Input2	*txt_mars_ineei_INFO9POS;
extern Fl_Input2	*txt_mars_ineei_INFO9CALL;
extern Fl_Input2	*txt_mars_ineei_INFO9STATE;
extern Fl_Input2	*txt_mars_ineei_INFO10POS;
extern Fl_Input2	*txt_mars_ineei_INFO10CALL;
extern Fl_Input2	*txt_mars_ineei_INFO10STATE;
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
extern Fl_ListBox	*sel_mars_net_PREC;
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

extern Fl_ListBox	*sel_mars_army_prec;

//======================================================================
// MARS Navy Standard Message
//======================================================================

extern void			create_mars_navy();

extern Fl_Group		*tab_mars_navy;

extern Fl_Tabs		*tab_mars_navy_type;
extern Fl_Group	*tab_mars_navy_1;
extern Fl_Group	*tab_mars_navy_2;

extern Fl_Input2	*txt_mars_navy_de;
extern Fl_Input2	*txt_mars_navy_serno;

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

extern Fl_ListBox	*sel_mars_navy_prec;

//======================================================================
// National Hurricane Center, Hurricane Weather Report Form
//======================================================================

extern void create_wxhc_tab();

extern Fl_Group	*tab_wxhc;
extern Fl_Tabs		*tab_wxhc_type;

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
extern Fl_ListBox	*w_wxhc_wind_speed_units;
extern Fl_Input2	*w_wxhc_wind_gusts;
extern Fl_ListBox	*w_wxhc_wind_gusts_units;
extern Fl_ListBox	*w_wxhc_wind_dir;
extern Fl_Input2	*w_wxhc_wind_degrees;
extern Fl_Input2	*w_wxhc_baro_press;
extern Fl_ListBox	*w_wxhc_baro_units;

extern Fl_Group	*tab_wxhc_2;

extern FTextEdit	*w_wxhc_comments;

//======================================================================
// Severe Weather Report Form
//======================================================================

extern void create_severe_wx_tab();

extern Fl_Group	*tab_severe_wx;
extern Fl_Tabs		*tab_severe_wx_type;

extern Fl_Group	*tab_severe_wx_1;
extern Fl_DateInput	*w_severe_wx_date;
extern Fl_Input2	*w_severe_wx_time;
extern Fl_ListBox	*w_severe_wx_zone;
extern Fl_Check_Button *w_severe_wx_meas;
extern Fl_Check_Button *w_severe_wx_est;
extern Fl_ListBox	*w_severe_wx_state;
extern Fl_ListBox	*w_severe_wx_county;
extern Fl_Input2	*w_severe_wx_city;
extern Fl_Input2	*w_severe_wx_wind_speed;
extern Fl_ListBox	*w_severe_wx_hail_size;
extern Fl_Check_Button *w_severe_wx_exact;
extern Fl_Check_Button *w_severe_wx_not_exact;
extern Fl_Check_Button *w_severe_wx_tornado;
extern Fl_Check_Button *w_severe_wx_funnel_cloud;
extern Fl_Check_Button *w_severe_wx_wall_cloud;
extern Fl_Check_Button *w_severe_wx_hail;
extern Fl_Check_Button *w_severe_wx_high_wind;
extern Fl_Check_Button *w_severe_wx_measured;
extern Fl_Check_Button *w_severe_wx_estimated;
extern Fl_Check_Button *w_severe_wx_flood;
extern Fl_Check_Button *w_severe_wx_flash_flood;
extern Fl_Check_Button *w_severe_wx_other;
extern Fl_Check_Button *w_severe_wx_dmg_yes;
extern Fl_Check_Button *w_severe_wx_dmg_no;
extern Fl_Check_Button *w_severe_wx_inj_yes;
extern Fl_Check_Button *w_severe_wx_inj_no;

extern Fl_Group	*tab_severe_wx_2;
extern FTextEdit	*w_severe_wx_narrative;

//======================================================================
// Severe Weather Report Form
//======================================================================

extern void create_storm_tab();

extern Fl_Group		*tab_storm;
extern Fl_Tabs			*tab_storm_type;

extern Fl_Group		*tab_storm_1;

extern Fl_DateInput	*w_storm_date;
extern Fl_Input2		*w_storm_time;
extern Fl_ListBox		*w_storm_zone;

extern Fl_ListBox		*w_storm_state;
extern Fl_ListBox		*w_storm_county;
extern Fl_Input2		*w_storm_location;

extern Fl_Check_Button *w_storm_tornado;
extern Fl_ListBox		*w_storm_tornado_cat;

extern Fl_Check_Button *w_storm_hail;
extern Fl_ListBox		*w_storm_hail_size;

extern Fl_Check_Button *w_storm_wind;
extern Fl_ListBox		*w_storm_wind_cat;

extern Fl_Check_Button *w_storm_flood;
extern Fl_ListBox		*w_storm_flood_cat;

extern Fl_Check_Button *w_storm_damage;
extern Fl_ListBox		*w_storm_damage_cat;

extern Fl_Check_Button *w_storm_snow;
extern Fl_ListBox		*w_storm_snow_tot;
extern Fl_ListBox		*w_storm_snow_dur;

extern Fl_Check_Button *w_storm_f_rain;
extern Fl_ListBox		*w_storm_f_rain_tot;
extern Fl_ListBox		*w_storm_f_rain_dur;

extern Fl_Check_Button *w_storm_h_rain;
extern Fl_ListBox		*w_storm_h_rain_tot;
extern Fl_ListBox		*w_storm_h_rain_dur;

extern Fl_Input2		*w_storm_o_name;
extern Fl_Input2		*w_storm_o_email;
extern Fl_Input2		*w_storm_o_tele;
extern Fl_ListBox		*w_storm_o_profile;

extern Fl_Group		*tab_storm_2;
extern FTextEdit		*w_storm_details;

extern void set_storm_counties(int);

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
// Civil Air Patrol (CAP) forms
//======================================================================
// CAP-105, Radio Message

extern Fl_Group	*tab_cap105;
extern Fl_Tabs		*tabs_cap105;
extern Fl_Group	*tab_cap105_message;
extern Fl_Group	*tab_cap105_information;

extern Fl_Input2 *cap105_txt_nbr;
extern Fl_ListBox *cap105_sel_prec;

extern Fl_Input2 *cap105_txt_dtm;
extern Fl_Button *cap105_btn_dtm;

extern Fl_Input2 *cap105_txt_from;
extern Fl_Input2 *cap105_txt_to;
extern Fl_Input2 *cap105_txt_info;

extern Fl_Input2 *cap105_txt_subj;

extern Fl_Input2 *cap105_txt_grpcnt;
extern Fl_Button *cap105_btn_check;

extern FTextEdit *cap105_txt_msg;

extern Fl_Input2 *cap105_txt_rcvd_fm;
extern Fl_Input2 *cap105_txt_rcvd_dtm;
extern Fl_Button *cap105_btn_rcvd_dtm;

extern Fl_Input2 *cap105_txt_sent_to;
extern Fl_Input2 *cap105_txt_sent_dtm;
extern Fl_Button *cap105_btn_sent_dtm;

extern Fl_Input2 *cap105_txt_rcvop;
extern Fl_Input2 *cap105_txt_sendop;

extern void create_cap105_tab();

// cap110 comms report

extern Fl_Group	*tab_cap110;
extern Fl_Tabs		*tab_cap110_type;
extern Fl_Group	*tab_cap110_1;

extern Fl_Input2	*txt_110_mission_nbr;
extern Fl_Input2	*txt_110_station;
extern Fl_Input2	*txt_110_date;
extern Fl_Button	*btn_110_date;
extern Fl_Input2	*txt_110_ds_a;
extern Fl_Input2	*txt_110_ds_b;
extern Fl_Input2	*txt_110_ds_c;
extern Fl_Input2	*txt_110_ds_d;
extern Fl_Input2	*txt_110_ds_e;
extern Fl_Input2	*txt_110_ds_f;

extern Fl_Group	*tab_cap110_2;
extern Fl_Input2	*txt_110_comm_time[23];
extern Fl_Input2	*txt_110_comm_call[23];
extern Fl_Input2	*txt_110_comm_chref[23];
extern Fl_Input2	*txt_110_comm_rem[23];

extern void create_cap110_tab();

//======================================================================
// external string arrays
//
extern const std::string counties;
extern const std::string states[];
extern int numstates;
extern const std::string hail_size[];
extern int num_hail_size;
extern const string tzones[];
extern int num_tzones;
extern const std::string us_tzones[];
extern int num_us_tzones;

#endif
