// generated by Fast Light User Interface Designer (fluid) version 1.0110

#ifndef flmsg_dialog_h
#define flmsg_dialog_h
#include <FL/Fl.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Text_Editor.H>
#include "FTextView.h"
#include "flinput2.h"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include "ics213.h"
#include <FL/Fl_Output.H>
extern Fl_Output *txt_filename;
#include <FL/Fl_Tabs.H>
extern Fl_Tabs *tabs_msg_type;
#include <FL/Fl_Group.H>
extern Fl_Group *tab_ics213;
extern Fl_Tabs *tabs_ics213;
extern Fl_Group *tab_originator;
extern Fl_Input2 *txt_To;
extern Fl_Input2 *txt_P1;
extern Fl_Input2 *txt_Fm;
extern Fl_Input2 *txt_P2;
extern Fl_Input2 *txt_Subj;
#include "calendar.h"
extern Fl_DateInput *txt_D1;
#include <FL/Fl_Button.H>
extern Fl_Button *btnDate1;
extern Fl_Input2 *txt_T1;
extern Fl_Button *btnTime1;
extern FTextEdit *txt_Msg;
extern Fl_Input2 *txt_S1;
extern Fl_Input2 *txt_P3;
extern Fl_Group *tab_responder;
extern Fl_Input2 *txt_S2;
extern Fl_DateInput *txt_D2;
extern Fl_Input2 *txt_T2;
extern Fl_Button *btnTime2;
extern FTextEdit *txt_Reply;
extern Fl_Input2 *txt_P4;
extern Fl_Button *btnDate2;
extern Fl_Group *tab_radiogram;
extern Fl_Tabs *tabs_radiogram;
extern Fl_Group *tab_radiogram_message;
extern Fl_Input2 *txt_rg_nbr;
#include <FL/Fl_Choice.H>
extern Fl_Choice *sel_rg_prec;
extern Fl_Input2 *txt_rg_hx;
extern Fl_Button *btn_rg_hx;
extern Fl_Input2 *txt_rg_station;
extern Fl_Input2 *txt_rg_place;
extern Fl_Input2 *txt_rg_t1;
extern Fl_Button *btn_rgTime1;
extern Fl_Input2 *txt_rg_d1;
extern Fl_Button *btn_rgDate1;
extern Fl_Input2 *txt_rg_to;
extern Fl_Input2 *txt_rg_phone;
extern Fl_Input2 *txt_rg_opnote;
extern FTextEdit *txt_rg_msg;
extern Fl_Button *btn_arl;
extern Fl_Input2 *txt_rg_check;
extern Fl_Button *btn_rg_check;
extern Fl_Input2 *txt_rg_sig;
extern Fl_Input2 *txt_rg_opnote2;
#include <FL/Fl_Check_Button.H>
extern Fl_Check_Button *btn_rg_svc;
extern Fl_Group *tab_radiogram_information;
extern Fl_Input2 *txt_rg_orig;
extern Fl_Input2 *txt_rg_dt2;
extern Fl_Button *btn_rgDateTime2;
extern Fl_Input2 *txt_rg_dt3;
extern Fl_Button *btn_rgDateTime3;
extern Fl_Input2 *txt_rg_dlvd_to;
extern Fl_Input2 *txt_rg_rcv_fm;
extern Fl_Input2 *txt_rg_rcv_net;
extern Fl_Input2 *txt_rg_dt4;
extern Fl_Button *btn_rgDateTime4;
extern Fl_Input2 *txt_rg_sent_to;
extern Fl_Input2 *txt_rg_snt_net;
extern Fl_Input2 *txt_rg_dt5;
extern Fl_Button *btn_rgDateTime5;
Fl_Double_Window* ics_dialog();
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
#include <FL/Fl_Browser.H>
extern Fl_Browser *brwsOptions;
#include <FL/Fl_Return_Button.H>
extern Fl_Return_Button *btnCloseOptions;
#include <FL/Fl_Box.H>
Fl_Double_Window* optionsdialog();
extern Fl_Browser *select_arl;
#include <FL/Fl_Input.H>
extern Fl_Input *txt_arl_fill1;
extern Fl_Input *txt_arl_fill2;
extern Fl_Input *txt_arl_fill3;
extern Fl_Input *txt_arl_fill4;
extern Fl_Button *btn_arl_cancel;
extern Fl_Button *btn_arl_add;
extern FTextEdit *arl_text;
extern Fl_Check_Button *btnInsertX;
Fl_Double_Window* arl_dialog();
#include <FL/Fl_Round_Button.H>
extern Fl_Round_Button *btn_dtformat0;
extern Fl_Round_Button *btn_dtformat1;
extern Fl_Round_Button *btn_dtformat2;
extern Fl_Round_Button *btn_utc_format0;
extern Fl_Round_Button *btn_utc_format1;
extern Fl_Round_Button *btn_utc_format2;
extern Fl_Round_Button *btn_utc_format3;
extern Fl_Round_Button *btn_utc_format4;
extern Fl_Round_Button *btn_utc_format5;
extern Fl_Button *btn_close_config;
extern Fl_Input *txt_my_call;
extern Fl_Input *txt_my_tel;
extern Fl_Input *txt_my_name;
extern Fl_Input *txt_my_addr;
extern Fl_Input *txt_my_city;
#include <FL/Fl_Spinner.H>
extern Fl_Spinner *cnt_wpl;
extern Fl_Check_Button *btn_compress;
extern Fl_Check_Button *btn_call_fname;
extern Fl_Check_Button *btn_dt_fname;
extern Fl_Check_Button *btn_sernbr_fname;
extern Fl_Input *txt_sernbr;
Fl_Double_Window* config_dialog();
extern Fl_Choice *sel_hx_select;
extern Fl_Button *btn_hx_select_add;
extern Fl_Input2 *txt_hx_select_text;
extern Fl_Button *btn_hx_select_cancel;
extern Fl_Return_Button *btn_hx_select_ok;
extern Fl_Output *txt_hx_instructions;
Fl_Double_Window* hx_dialog();
#endif
