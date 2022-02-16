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

#ifndef FLMSG_H
#define FLMSG_H

#include <string>
#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>

#include "arl_msgs.h"
#include "hx_msgs.h"
#include "crc16.h"
#include "threads.h"

#define DEBUG 0

enum MSGTYPE { NONE,
ICS203, ICS205, ICS205A, ICS206, ICS213, ICS214, ICS216, ICS309, NETLOG,
HICS203, HICS206, HICS213, HICS214, IARU,
RADIOGRAM, PLAINTEXT, BLANK, CSV, CUSTOM,
MARSDAILY, MARSINEEI, MARSNET, MARSARMY, MARSMSG,
WXHC, SEVEREWX, STORMREP, CAP105, CAP110, TRANSFER, CUSTOM_TRANSFER };

struct FIELD { std::string f_type; std::string f_data; void **w; char w_type; };
extern FIELD fields[];
extern FIELD ptfields[];
extern FIELD rgfields[];

extern int selected_form;

extern void checkdirectories(void);
extern int parse_args(int argc, char **argv, int& idx);
extern void showoptions();

extern Fl_Double_Window *mainwindow;
extern Fl_Double_Window *expert_dialog;
extern Fl_Double_Window *tyro_dialog;

extern Fl_Double_Window *optionswindow;
extern Fl_Double_Window *arlwindow;
extern Fl_Double_Window *config_files_window;
extern Fl_Double_Window *hxwindow;
extern Fl_Double_Window *header_window;
extern Fl_Double_Window *time_estimate_window;
extern Fl_Double_Window *socket_window;
extern std::string flmsgHomeDir;
extern std::string IcsHomeDir;

extern bool printme;
extern bool update_custom;
//extern bool flmsg_editor;

extern int arl_nbr;

extern std::string FLMSG_dir;
extern std::string ARQ_dir;
extern std::string ARQ_files_dir;
extern std::string ARQ_recv_dir;
extern std::string ARQ_send_dir;
extern std::string WRAP_dir;
extern std::string WRAP_recv_dir;
extern std::string WRAP_send_dir;
extern std::string WRAP_auto_dir;
extern std::string ICS_dir;
extern std::string ICS_msg_dir;
extern std::string ICS_tmp_dir;
extern std::string CSV_dir;
extern std::string CUSTOM_dir;
extern std::string FLMSG_custom_dir;
extern std::string XFR_dir;
extern std::string FLMSG_temp_dir;
extern std::string FLMSG_log_dir;

extern std::string title;
extern std::string buffer;

extern std::string evalstr;

extern char *named_file();

extern pthread_t *xmlrpc_thread;
extern pthread_mutex_t mutex_xmlrpc;

//menu callbacks
extern void cb_new();
extern void cb_open();
extern void cb_save();
extern void cb_save_as();
extern void cb_text();
extern void cb_import();
extern void cb_export();
extern void cb_wrap_import();
extern void wrap_import(const char *fname);
extern void cb_wrap_export();
extern void cb_wrap_autosend();
extern void cb_exit();
extern void cb_load_template();
extern void cb_save_template();
extern void cb_save_as_template();
extern void cb_config_files();
extern void cb_config_date_time();
extern void cb_config_personal();
extern void cb_config_radiogram();
extern void cb_config_socket();
extern void cb_config_arq();
extern void cb_config_UI();
extern void showoptions();
extern void show_help();
extern void custom_download();
extern void cb_About();
extern void cb_html();
extern void cb_html_fcopy();
extern void cb_folders();

extern void open_url(const char* url, int folder = 0);

extern void cb_arl();
extern void cb_arl_cancel();
extern void cb_arl_add();

extern void cb_hx();
extern void cb_hx_select();
extern void cb_hx_select_add();
extern void cb_hx_select_cancel();
extern void cb_hx_select_ok();

extern void closeoptions();

extern void remove_spaces_from_filename(std::string &fname);
extern char *szTime(int typ = 0);
extern char *szDate(int df = -1);
extern char *szAbbrevDate();
extern char *szDateTime();
extern char *szMarsDateTime();
extern char *szCAPDateTime();

extern void set_main_label();
extern void show_filename(std::string);
extern void clear_fields();
extern void update_fields();

extern void to_html(std::string &s);
extern void fm_html(std::string &html);

extern void drop_box_changed();

extern int eval_transfer_size();

extern void extract_text(std::string &buffer, const char *fname);

// used by all form management

extern std::string lineout( std::string &, std::string & );
extern std::string binout( std::string &, bool & );

extern std::string hdr_from;
extern std::string hdr_edit;

extern void clear_header();
extern std::string header(const char *);
extern void read_header(std::string &str);
enum hdr_reason {NEW, CHANGED, FROM};
extern void update_header(hdr_reason sender = NEW);

extern std::string findstr(std::string &, std::string &);
extern bool   findbin(std::string &, std::string &);
extern void   replacestr(std::string &form, std::string &where, std::string &what);
extern void   replacelf(std::string &form, int n = 0);
extern void   striplf(std::string &);

extern void   update_sernbr();

extern void print_and_exit();

// ham_form
extern void hamform_changed(Fl_Widget *, void*);

// ics
extern void ics_changed(Fl_Widget *, void *);

// ics205
extern std::string base_205_filename;
extern std::string def_205_filename;
extern std::string def_205_TemplateName;
extern bool using_ics205_template;

extern void cb_205_SetDateTime1();
extern void cb_205_SetDateTime2();
extern void cb_205_SetDateTime3();
extern void clear_205fields();
extern void update_205fields();
extern void clear_205_form();
extern std::string find(std::string haystack, std::string needle);
extern void read_205_buffer(std::string data);
extern void cb_205_new();
extern void cb_205_import();
extern void cb_205_export();
extern void cb_205_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_205_wrap_export();
extern void cb_205_wrap_autosend();
extern void cb_205_load_template();
extern void cb_205_save_template();
extern void cb_205_save_as_template();
extern void cb_205_open();
extern void write_205(std::string s);
extern bool cb_205_save_as();
extern void cb_205_save();
extern void cb_205_html();
extern void cb_205_msg_type();
extern void cb_205_textout();
extern int  eval_205_fsize();

// ics205a
extern std::string base_205a_filename;
extern std::string def_205a_filename;
extern std::string def_205a_TemplateName;
extern bool using_ics205a_template;

extern void cb_205a_set_date_fm();
extern void cb_205a_set_time_fm();
extern void cb_205a_set_date_to();
extern void cb_205a_set_time_to();
extern void clear_205afields();
extern void update_205afields();
extern void update_205aform();
extern void clear_205a_form();
extern void read_205a_buffer(std::string data);
extern void cb_205a_new();
extern void cb_205a_import();
extern void cb_205a_export();
extern void cb_205a_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_205a_wrap_export();
extern void cb_205a_wrap_autosend();
extern void cb_205a_load_template();
extern void cb_205a_save_template();
extern void cb_205a_save_as_template();
extern void cb_205a_open();
extern void write_205a(std::string s);
extern bool cb_205a_save_as();
extern void cb_205a_save();
extern void cb_205a_html();
extern void cb_205a_msg_type();
extern void cb_205a_textout();
extern int  eval_205a_fsize();

// ics203
extern std::string yes;
extern std::string no;

extern std::string buff203;
extern std::string def_203_filename;
extern std::string base_203_filename;
extern std::string def_203_TemplateName;
extern bool  using_203_template;

extern void cb_203_set_date();
extern void cb_203_set_time();
extern void clear_203fields();
extern void update_203fields();
extern void clear_203_form();
extern void read_203_buffer(std::string data);
extern void cb_203_new();
extern void cb_203_import();
extern void cb_203_export();
extern void cb_203_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_203_wrap_export();
extern void cb_203_wrap_autosend();
extern void cb_203_load_template();
extern void cb_203_save_template();
extern void cb_203_save_as_template();
extern void cb_203_open();
extern void write_203(std::string s);
extern bool cb_203_save_as();
extern void cb_203_save();
extern void cb_203_html();
extern void cb_203_msg_type();
extern void cb_203_textout();
extern int  eval_203_fsize();

// ics206
extern std::string yes;
extern std::string no;

extern std::string buff206;
extern std::string def_206_filename;
extern std::string base_206_filename;
extern std::string def_206_TemplateName;
extern bool using_ics206_template;

extern void cb_206_setdate();
extern void cb_206_settime();
extern void clear_206fields();
extern void update_206fields();
extern void clear_206_form();
extern void read_206_buffer(std::string data);
extern void cb_206_new();
extern void cb_206_import();
extern void cb_206_export();
extern void cb_206_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_206_wrap_export();
extern void cb_206_wrap_autosend();
extern void cb_206_load_template();
extern void cb_206_save_template();
extern void cb_206_save_as_template();
extern void cb_206_open();
extern void write_206(std::string s);
extern bool cb_206_save_as();
extern void cb_206_save();
extern void cb_206_html();
extern void cb_206_msg_type();
extern void cb_206_textout();
extern int  eval_206_fsize();

// ics213
extern bool using_213Template;
extern std::string base_213_filename;
extern std::string def_213_filename;
extern std::string def_213_TemplateName;

extern void clear_213_form();
extern void read_213(std::string);
extern void write_213(std::string);
extern void read_213_buffer(std::string);

extern void cb_213_new();
extern void cb_213_open();
extern void cb_213_save();
extern bool cb_213_save_as();
extern void cb_213_write();
extern void cb_213_html();
extern void cb_213_textout();
extern void cb_213_import();
extern void cb_213_export();
extern void cb_213_wrap_import(std::string, std::string);
extern void cb_213_wrap_export();
extern void cb_213_wrap_autosend();
extern void cb_213_load_template();
extern void cb_213_save_template();
extern void cb_213_save_as_template();
extern void cb_SetDate1();
extern void cb_SetDate2();
extern void cb_SetTime1();
extern void cb_SetTime2();
extern int  eval_213_fsize();

// ics214

extern std::string buff214;
extern std::string def_214_filename;
extern std::string base_214_filename;
extern std::string def_214_TemplateName;
extern bool using_ics214_template;

extern void cb_214_set_date();
extern void cb_214_set_time();
extern void clear_214fields();
extern void update_214fields();
extern void clear_214_form();
extern void read_214_buffer(std::string data);
extern void cb_214_new();
extern void cb_214_import();
extern void cb_214_export();
extern void cb_214_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_214_wrap_export();
extern void cb_214_wrap_autosend();
extern void cb_214_load_template();
extern void cb_214_save_template();
extern void cb_214_save_as_template();
extern void cb_214_open();
extern void write_214(std::string s);
extern bool cb_214_save_as();
extern void cb_214_save();
extern void cb_214_html();
extern void cb_214_msg_type();
extern void cb_214_textout();
extern int  eval_214_fsize();

// ics216

extern std::string buff216;
extern std::string def_216_filename;
extern std::string base_216_filename;
extern std::string def_216_TemplateName;
extern bool using_ics216_template;

extern void cb_216_set_date();
extern void cb_216_set_time();
extern void clear_216fields();
extern void update_216fields();
extern void clear_216_form();
extern void read_216_buffer(std::string data);
extern void cb_216_new();
extern void cb_216_import();
extern void cb_216_export();
extern void cb_216_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_216_wrap_export();
extern void cb_216_wrap_autosend();
extern void cb_216_load_template();
extern void cb_216_save_template();
extern void cb_216_save_as_template();
extern void cb_216_open();
extern void write_216(std::string s);
extern bool cb_216_save_as();
extern void cb_216_save();
extern void cb_216_html();
extern void cb_216_msg_type();
extern void cb_216_textout();
extern int  eval_216_fsize();

// ics309

extern std::string buff309;
extern std::string def_309_filename;
extern std::string base_309_filename;
extern std::string def_309_TemplateName;
extern bool using_ics309_template;

extern void cb_309_set_date_fm();
extern void cb_309_set_time_fm();
extern void cb_309_set_date_to();
extern void cb_309_set_time_to();
extern void cb_309_set_date_time();
extern void clear_309fields();
extern void update_309fields();
extern void clear_309_form();
extern void read_309_buffer(std::string data);
extern void cb_309_new();
extern void cb_309_import();
extern void cb_309_export();
extern void cb_309_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_309_wrap_export();
extern void cb_309_wrap_autosend();
extern void cb_309_load_template();
extern void cb_309_save_template();
extern void cb_309_save_as_template();
extern void cb_309_open();
extern void write_309(std::string s);
extern bool cb_309_save_as();
extern void cb_309_save();
extern void cb_309_html();
extern void cb_309_msg_type();
extern void cb_309_textout();
extern int  eval_309_fsize();
extern void ics309_csv(Fl_Widget *w, void *d);

// netlog

extern std::string buffnetlog;
extern std::string def_netlog_filename;
extern std::string base_netlog_filename;
extern std::string def_netlog_TemplateName;
extern bool using_netlog_template;

extern void cb_netlog_set_date_fm();
extern void cb_netlog_set_time_fm();
extern void cb_netlog_set_date_to();
extern void cb_netlog_set_time_to();
extern void cb_netlog_set_date_time();
extern void clear_netlogfields();
extern void update_netlogfields();
extern void clear_netlog_form();
extern void read_netlog_buffer(std::string data);
extern void cb_netlog_new();
extern void cb_netlog_import();
extern void cb_netlog_export();
extern void cb_netlog_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_netlog_wrap_export();
extern void cb_netlog_wrap_autosend();
extern void cb_netlog_load_template();
extern void cb_netlog_save_template();
extern void cb_netlog_save_as_template();
extern void cb_netlog_open();
extern void write_netlog(std::string s);
extern bool cb_netlog_save_as();
extern void cb_netlog_save();
extern void cb_netlog_html();
extern void cb_netlog_msg_type();
extern void cb_netlog_textout();
extern int  eval_netlog_fsize();
extern void netlog_csv(Fl_Widget *w, void *d);

// radiogram
extern bool using_rg_template;
extern std::string base_rg_filename;
extern std::string def_rg_filename;
extern std::string def_rg_TemplateName;

extern const char hxitems[];
extern const char precitems[];
extern const char *s_prec[];
extern const char *s_hx[];

extern void cb_rgSetDate1();
extern void cb_rgSetTime1();
extern void cb_rgSetDateTime2();
extern void cb_rgSetDateTime3();
extern void cb_rgSetDateTime4();
extern void cb_rgSetDateTime5();
extern void clear_rgfields();
extern void update_rgfields();
extern void clear_rg_form();
extern void read_rg_buffer(std::string data);
extern void cb_rg_new();
extern void cb_rg_import();
extern void cb_rg_export();
extern void cb_rg_wrap_import(std::string, std::string);
extern void cb_rg_wrap_export();
extern void cb_rg_wrap_autosend();
extern void cb_rg_load_template();
extern void cb_rg_save_template();
extern void cb_rg_save_as_template();
extern void read_rg(std::string s);
extern void cb_rg_open();
extern void write_rg(std::string s);
extern bool cb_rg_save_as();
extern void cb_rg_save();
extern void cb_rg_html();
extern void cb_rg_html_fcopy();
extern void cb_rg_rtf();
extern void cb_rg_textout();
extern void set_rg_choices();
extern void cb_rg_check();
extern void cb_rg_nbr(Fl_Widget *);
extern void cb_rg_filter_input(Fl_Widget *);
extern int  eval_rg_fsize();

extern void read_data_file(std::string);

// plaintext
extern bool using_pt_template;
extern std::string base_pt_filename;
extern std::string def_pt_filename;
extern std::string def_pt_TemplateName;

extern void cb_set_pt_date();
extern void cb_set_pt_time();
extern void clear_ptfields();
extern void update_ptfields();
extern void clear_pt_form();
extern void read_ptbuffer(std::string data);
extern void cb_pt_new();
extern void cb_pt_import();
extern void cb_pt_export();
extern void cb_pt_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_pt_wrap_export();
extern void cb_pt_wrap_autosend();
extern void cb_pt_load_template();
extern void cb_pt_save_template();
extern void cb_pt_save_as_template();
extern void read_pt_data_file(std::string s);
extern void cb_pt_open();
extern void write_pt(std::string s);
extern bool cb_pt_save_as();
extern void cb_pt_save();
extern void cb_pt_html();
extern void cb_pt_msg_type();
extern void cb_pt_textout();
extern int  eval_pt_fsize();

// blank form
extern bool using_blank_template;
extern std::string base_blank_filename;
extern std::string def_blank_filename;
extern std::string def_blank_TemplateName;

extern std::string TITLE;
extern std::string errtext;

extern void clear_blankfields();
extern void update_blankfields();
extern void clear_blank_form();
extern void read_blankbuffer(std::string data);
extern void cb_blank_new();
extern void cb_blank_import();
extern void cb_blank_export();
extern void cb_blank_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_blank_wrap_export();
extern void cb_blank_wrap_autosend();
extern void cb_blank_load_template();
extern void cb_blank_save_template();
extern void cb_blank_save_as_template();
extern void read_blank_data_file(std::string s);
extern void cb_blank_open();
extern void write_blank(std::string s);
extern bool cb_blank_save_as();
extern void cb_blank_save();
extern void cb_blank_html();
extern void cb_blank_msg_type();
extern void cb_blank_textout();
extern int  eval_blank_fsize();

// csv form
extern bool using_csv_template;
extern std::string base_csv_filename;
extern std::string def_csv_filename;
extern std::string def_csv_TemplateName;

extern void clear_csvfields();
extern void update_csvfields();
extern void clear_csv_form();
extern void read_csvbuffer(std::string data);
extern void cb_csv_new();
extern void cb_csv_import();
extern void cb_csv_export();
extern void cb_csv_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_csv_wrap_export();
extern void cb_csv_wrap_autosend();
extern void cb_csv_load_template();
extern void cb_csv_save_template();
extern void cb_csv_save_as_template();
extern void read_csv_data_file(std::string s);
extern void cb_csv_open();
extern void write_csv(std::string s);
extern bool cb_csv_save_as();
extern void cb_csv_save();
extern void cb_csv_html();
extern void cb_csv_msg_type();
extern void cb_csv_textout();
extern void cb_csv_export_data(bool);
extern void cb_csv_import_data();
extern void csv_set_fname(const char *);
extern int  eval_csv_fsize();

// custom form

enum HANDLE_TYPE {HANDLE_NONE, HANDLE_EDIT, HANDLE_VIEW, HANDLE_WAITING};

extern int custom_select;
extern int handle_type;

extern int flmsg_webserver_portnbr;
extern char sz_srvr_portnbr[];

extern pthread_t *web_server_thread;
extern pthread_mutex_t mutex_web_server;

struct CUSTOM_PAIRS {
	char *mnu_name;
	char *file_name;
};

extern CUSTOM_PAIRS custom_pairs[];

extern bool using_custom_template;
extern std::string base_custom_filename;
extern std::string def_custom_filename;
extern std::string def_custom_TemplateName;

extern void clear_customfields();
extern void update_customfields();
extern void clear_custom_form();
extern void read_custombuffer(std::string data);
extern void cb_custom_new();
extern void cb_custom_import();
extern void cb_custom_export();
extern void cb_custom_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_custom_wrap_export();
extern void cb_custom_wrap_autosend();
extern void cb_custom_load_template();
extern void cb_custom_save_template();
extern void cb_custom_save_as_template();
extern void read_custom_data_file(std::string s);
extern void cb_custom_open();
extern void write_custom(std::string s);
extern bool cb_custom_save_as();
extern void cb_custom_save();
extern void cb_custom_html(bool);
extern void cb_custom_msg_type();
extern void cb_custom_textout();
extern void cb_custom_export_data(bool);
extern void cb_custom_import_data();
extern void custom_set_fname(const char *);
extern int  eval_custom_fsize();

// mars daily
extern std::string	def_mars_daily_filename;
extern std::string	def_mars_daily_TemplateName;
extern std::string	base_mars_daily_filename;

extern void mars_changed(Fl_Widget *, void *);

extern void clear_mars_dailyfields();
extern void update_mars_dailyfields();
extern void clear_mars_daily_form();
extern void read_mars_daily_buffer(std::string data);
extern void cb_mars_daily_new();
extern void cb_mars_daily_import();
extern void cb_mars_daily_export();
extern void cb_mars_daily_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_mars_daily_wrap_export();
extern void cb_mars_daily_wrap_autosend();
extern void cb_mars_daily_load_template();
extern void cb_mars_daily_save_template();
extern void cb_mars_daily_save_as_template();
extern void read_mars_daily__data_file(std::string s);
extern void cb_mars_daily_open();
extern void write_mars_daily(std::string s);
extern bool cb_mars_daily_save_as();
extern void cb_mars_daily_save();
extern void cb_mars_daily_html();
extern void cb_mars_daily_msg_type();
extern void cb_mars_daily_textout();
extern int  eval_mars_daily_fsize();

// mars ineei
extern std::string	def_mars_ineei_filename;
extern std::string	def_mars_ineei_TemplateName;
extern std::string	base_mars_ineei_filename;

extern void cb_mars_ineei_SetDTG();
extern void clear_mars_ineei_fields();
extern void update_mars_ineei_fields();
extern void update_mars_ineeiform();
extern void clear_mars_ineei_form();
extern void read_mars_ineei_buffer(std::string data);
extern void cb_mars_ineei_new();
extern void cb_mars_ineei_import();
extern void cb_mars_ineei_export();
extern void cb_mars_ineei_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_mars_ineei_wrap_export();
extern void cb_mars_ineei_wrap_autosend();
extern void cb_mars_ineei_load_template();
extern void cb_mars_ineei_save_template();
extern void cb_mars_ineei_save_as_template();
extern void cb_mars_ineei_open();
extern void write_mars_ineei(std::string s);
extern bool cb_mars_ineei_save_as();
extern void cb_mars_ineei_save();
extern void cb_mars_ineei_html();
extern void cb_mars_ineei_textout();
extern void cb_mars_ineei_html();
extern void cb_mars_ineei_textout();
extern int  eval_mars_ineei_fsize();

// mars net
extern std::string	def_mars_net_filename;
extern std::string	def_mars_net_TemplateName;
extern std::string	base_mars_net_filename;

extern void cb_mars_net_SetDTG();
extern void cb_mars_net_SetDTGSTART();
extern void cb_mars_net_SetDTGEND();
extern void clear_mars_net_fields();
extern void update_mars_net_fields();
extern void update_mars_netform();
extern void clear_mars_net_form();
extern void read_mars_net_buffer(std::string data);
extern void cb_mars_net_new();
extern void cb_mars_net_import();
extern void cb_mars_net_export();
extern void cb_mars_net_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_mars_net_wrap_export();
extern void cb_mars_net_wrap_autosend();
extern void cb_mars_net_load_template();
extern void cb_mars_net_save_template();
extern void cb_mars_net_save_as_template();
extern void cb_mars_net_open();
extern void write_mars_net(std::string s);
extern bool cb_mars_net_save_as();
extern void cb_mars_net_save();
extern void cb_mars_net_html();
extern void cb_mars_net_textout();
extern int  eval_mars_net_fsize();

// mars army
extern bool using_mars_army_template;
extern std::string base_mars_army_filename;
extern std::string def_mars_army_filename;
extern std::string def_mars_army_TemplateName;

extern void clear_mars_armyfields();
extern void update_mars_armyfields();
extern void update_mars_armyform();
extern void clear_mars_army_form();
extern void read_mars_army_buffer(std::string data);
extern void cb_mars_army_new();
extern void cb_mars_army_import();
extern void cb_mars_army_export();
extern void cb_mars_army_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_mars_army_wrap_export();
extern void cb_mars_army_wrap_autosend();
extern void cb_mars_army_load_template();
extern void cb_mars_army_save_template();
extern void cb_mars_army_save_as_template();
extern void cb_mars_army_open();
extern void write_mars_army(std::string s);
extern bool cb_mars_army_save_as();
extern void cb_mars_army_save();
extern void cb_mars_army_html();
extern void cb_mars_army_msg_type();
extern void cb_mars_army_textout();
extern int  eval_mars_army_fsize();

// mars msg
extern bool using_mars_msg_template;
extern std::string base_mars_msg_filename;
extern std::string def_mars_msg_filename;
extern std::string def_mars_msg_TemplateName;

extern void clear_mars_msgfields();
extern void update_mars_msgfields();
extern void update_mars_msgform();
extern void clear_mars_msg_form();
extern void read_mars_msg_buffer(std::string data);
extern void cb_mars_msg_new();
extern void cb_mars_msg_import();
extern void cb_mars_msg_export();
extern void cb_mars_msg_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_mars_msg_wrap_export();
extern void cb_mars_msg_wrap_autosend();
extern void cb_mars_msg_load_template();
extern void cb_mars_msg_save_template();
extern void cb_mars_msg_save_as_template();
extern void cb_mars_msg_open();
extern void write_mars_msg(std::string s);
extern bool cb_mars_msg_save_as();
extern void cb_mars_msg_save();
extern void cb_mars_msg_html();
extern void cb_mars_msg_msg_type();
extern void cb_mars_msg_textout();
extern int  eval_mars_msg_fsize();

// hics203
extern std::string hics_buff203;
extern std::string def_hics203_filename;
extern std::string base_hics203_filename;
extern std::string def_hics203_TemplateName;
extern bool   using_hics203_template;
extern void   hics_changed(Fl_Widget *, void *);

extern void cb_hics203_set_date();
extern void cb_hics203_set_time();
extern void clear_hics203fields();
extern void update_hics203fields();
extern void clear_hics203_form();
extern void read_hics203_buffer(std::string data);
extern void cb_hics203_new();
extern void cb_hics203_import();
extern void cb_hics203_export();
extern void cb_hics203_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_hics203_wrap_export();
extern void cb_hics203_wrap_autosend();
extern void cb_hics203_load_template();
extern void cb_hics203_save_template();
extern void cb_hics203_save_as_template();
extern void cb_hics203_open();
extern void write_hics203(std::string s);
extern bool cb_hics203_save_as();
extern void cb_hics203_save();
extern void cb_hics203_html();
extern void cb_hics203_msg_type();
extern void cb_hics203_textout();
extern int  eval_hics203_fsize();

// ics_h206
extern std::string h206_buff;
extern std::string h206_def_filename;
extern std::string h206_base_filename;
extern std::string h206_def_template_name;
extern bool   h206_using_template;

extern void h206_cb_setdate();
extern void h206_cb_settime();
extern void h206_clear_fields();
extern void h206_update_fields();
extern void h206_clear__form();
extern void h206_read_buffer(std::string data);
extern void h206_cb_new();
extern void h206_cb_import();
extern void h206_cb_export();
extern void h206_cb_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void h206_cb_wrap_export();
extern void h206_cb_wrap_autosend();
extern void h206_cb_load_template();
extern void h206_cb_save_template();
extern void h206_cb_save_as_template();
extern void h206_cb_open();
extern void h206_write(std::string s);
extern bool h206_cb_save_as();
extern void h206_cb_save();
extern void h206_cb_html();
extern void h206_cb_textout();
extern int  eval_h206_fsize();

// ics_h213

extern std::string h213_buffer;
extern std::string h213_def_filename;
extern std::string h213_base_filename;
extern std::string h213_def_template_name;
extern bool   h213_using_template;

extern void h213_cb_set_date();
extern void h213_cb_set_time0();
extern void h213_cb_set_time1();
extern void h213_cb_set_time2();
extern void h213_clear_fields();
extern void h213_update_fields();
extern void h213_clear_form();
extern void h213_update_form();
extern void h213_read_buffer(std::string data);
extern void h213_cb_new();
extern void h213_cb_import();
extern void h213_cb_export();
extern void h213_cb_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void h213_cb_wrap_export();
extern void h213_cb_wrap_autosend();
extern void h213_cb_load_template();
extern void h213_cb_save_template();
extern void h213_cb_save_as_template();
extern void h213_cb_open();
extern void h213_write(std::string s);
extern bool h213_cb_save_as();
extern void h213_cb_save();
extern void h213_cb_html();
extern void h213_cb_textout();
extern int  eval_h213_fsize();

// hics 214 variables and functions

extern std::string hics214_incident;
extern std::string hics214_date;
extern std::string hics214_time;
extern std::string hics214_op_period;
extern std::string hics214_sec_brch;
extern std::string hics214_position;
extern std::string hics214_activity_time[30];
extern std::string hics214_activity_event[30];
extern std::string hics214_prepared_by;
extern std::string hics214_facility;

extern std::string hics214_buff;
extern std::string hics214_def_filename;
extern std::string hics214_base_filename;
extern std::string hics214_template_name;
extern bool   hics214_using_template;

extern void hics214_cb_set_date();
extern void hics214_cb_set_time();
extern void hics214_clear_fields();
extern void hics214_update_fields();
extern void hics214_update_form();
extern void hics214_clear_form();
extern void hics214_read_buffer(std::string data);
extern void hics214_cb_new();
extern void hics214_cb_import();
extern void hics214_cb_export();
extern void hics214_cb_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void hics214_cb_wrap_export();
extern void hics214_cb_wrap_autosend();
extern void hics214_cb_load_template();
extern void hics214_cb_save_template();
extern void hics214_cb_save_as_template();
extern void hics214_cb_open();
extern void hics214_write(std::string s);
extern bool hics214_cb_save_as();
extern void hics214_cb_save();
extern void hics214_cb_html();
extern void hics214_cb_textout();
extern int  eval_hics214_fsize();

// IARU form

extern bool iaru_using_template;
extern int iaru_num_fields;

extern void iaru_cb_set_d1();
extern void iaru_cb_set_t1();
extern void iaru_cb_set_d2();
extern void iaru_cb_set_t2();
extern void iaru_cb_set_d3();
extern void iaru_cb_set_t3();
extern void iaru_cb_nbr(Fl_Widget *wdg);
extern void iaru_cb_filter_input(Fl_Widget *wdg);
extern void iaru_clear_fields();
extern void iaru_set_choices();
extern void iaru_update_fields();
extern void iaru_clear_form();
extern void iaru_update_form();
extern void iaru_read_buffer(std::string data);
extern void iaru_cb_new();
extern void iaru_cb_import();
extern void iaru_cb_export();
extern void iaru_cb_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void iaru_cb_wrap_export();
extern void iaru_cb_wrap_autosend();
extern void iaru_cb_load_template();
extern void iaru_cb_save_template();
extern void iaru_cb_save_as_template();
extern void iaru_cb_open();
extern void iaru_write(std::string s);
extern bool iaru_cb_save_as();
extern void iaru_cb_save();
extern void iaru_cb_check();
extern void iaru_cb_html();
extern void iaru_cb_textout();
extern int  eval_iaru_fsize();

extern std::string iaru_base_filename;
extern std::string iaru_def_filename;
extern std::string iaru_def_template_name;

//======================================================================
// National Hurricane Center, Hurricane Weather Report Form
//======================================================================

extern std::string buffwxhc;
extern std::string def_wxhc_filename;
extern std::string base_wxhc_filename;
extern std::string def_wxhc_TemplateName;

extern void clear_wxhcfields();
extern bool check_wxhcfields();
extern void update_wxhcfields();
extern void set_nhc_wx_combos();
extern void update_wxhcform();
extern void clear_wxhc_form();
extern void read_wxhc_buffer(std::string data);
extern void cb_wxhc_new();
extern void cb_wxhc_import();
extern void cb_wxhc_export();
extern void cb_wxhc_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern void cb_wxhc_wrap_export();
extern void cb_wxhc_wrap_autosend();
extern void cb_wxhc_load_template();
extern void cb_wxhc_save_template();
extern void cb_wxhc_save_as_template();
extern void cb_wxhc_open();
extern void write_wxhc(std::string s);
extern bool cb_wxhc_save_as();
extern void cb_wxhc_save();
extern void cb_wxhc_html();
extern void cb_wxhc_textout();
extern int  eval_wxhc_fsize();

//======================================================================
// Severe Weather Report Form
//======================================================================

extern std::string buffsevere_wx;
extern std::string def_severe_wx_filename;
extern std::string base_severe_wx_filename;
extern std::string def_severe_wx_TemplateName;

extern void clear_severe_wxfields();
extern bool check_severe_wxfields();
extern void update_severe_wxfields();
extern void update_severe_wxform();
extern void clear_severe_wx_form();
extern void read_severe_wx_buffer(std::string data);
extern void cb_severe_wx_new();
extern void cb_severe_wx_import();
extern void cb_severe_wx_export();
extern void cb_severe_wx_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern int  eval_severe_wx_fsize();
extern void cb_severe_wx_wrap_export();
extern void cb_severe_wx_wrap_autosend();
extern void cb_severe_wx_load_template();
extern void cb_severe_wx_save_template();
extern void cb_severe_wx_save_as_template();
extern void cb_severe_wx_open();
extern void write_severe_wx(std::string s);
extern bool cb_severe_wx_save_as();
extern void cb_severe_wx_save();
extern void cb_severe_wx_html();
extern void cb_severe_wx_textout();
extern void set_severe_wx_combos();
extern void set_severe_wx_counties(int);

//======================================================================
// Storm Report Form
//======================================================================

extern std::string buffstorm;
extern std::string def_storm_filename;
extern std::string base_storm_filename;
extern std::string def_storm_TemplateName;

extern void clear_stormfields();
extern bool check_stormfields();
extern void update_stormfields();
extern void update_stormform();
extern void clear_storm_form();
extern void read_storm_buffer(std::string data);
extern void cb_storm_new();
extern void cb_storm_import();
extern void cb_storm_export();
extern void cb_storm_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern int  eval_storm_fsize();
extern void cb_storm_wrap_export();
extern void cb_storm_wrap_autosend();
extern void cb_storm_load_template();
extern void cb_storm_save_template();
extern void cb_storm_save_as_template();
extern void cb_storm_open();
extern void write_storm(std::string s);
extern bool cb_storm_save_as();
extern void cb_storm_save();
extern void cb_storm_html();
extern void cb_storm_textout();

//======================================================================
// generic file transfer
//======================================================================

extern std::string transfer_buffer;
extern std::string def_transfer_filename;
extern std::string base_transfer_filename;

extern void clear_transfer_form();
extern void read_transfer_buffer(std::string data);
extern void cb_transfer_new();
extern void cb_transfer_import();
extern void cb_transfer_export();
extern void cb_transfer_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern int eval_transfer_fsize();
extern void cb_transfer_wrap_export();
extern void cb_transfer_wrap_autosend();
extern void cb_transfer_load_template();
extern void cb_transfer_save_template();
extern void cb_transfer_save_as_template();
extern void cb_transfer_open();
extern void write_transfer(std::string s);
extern void cb_transfer_open_as();
extern void cb_transfer_msg_type();
extern void cb_transfer_html();
extern void cb_transfer_textout();
extern void cb_transfer_import_data();
extern void cb_transfer_export_data();

extern std::string def_custom_transfer_filename;
extern void load_custom_html_file();
extern void load_custom_transfer();
extern void update_custom_transfer();

extern void cb_custom_form_wrap_import(std::string s1, std::string s2);
extern int  eval_transfer_custom_form_fsize();
extern void cb_transfer_custom_html();
extern void cb_save_custom_html(Fl_Widget *w, void *d);
extern void cb_btn_select_custom_html(Fl_Widget *w, void *d);

//=====================================================================
// CAP 105
//=====================================================================

extern std::string cap105_base_filename;
extern std::string cap105_def_filename;
extern std::string cap105_def_template_name;

extern void cap105_cb_set_dtm();
extern void cap105_cb_set_rcvd_dtm();
extern void cap105_cb_set_sent_dtm();
extern void cap105_cb_nbr(Fl_Widget *wdg);
extern void cap105_cb_filter_input(Fl_Widget *wdg);
extern void cap105_clear_fields();
extern void cap105_set_choices();
extern bool cap105_check_fields();
extern void cap105_update_fields();
extern void cap105_clear_form();
extern void cap105_update_form();
extern void cap105_make_buffer(bool compress = false);
extern void cap105_read_buffer(std::string data);
extern void cap105_cb_new();
extern void cap105_cb_import();
extern void cap105_cb_export();
extern void cap105_cb_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern int  eval_cap105_fsize();
extern void cap105_cb_wrap_export();
extern void cap105_cb_wrap_autosend();
extern void cap105_cb_load_template();
extern void cap105_cb_save_template();
extern void cap105_cb_save_as_template();
extern void cap105_cb_open();
extern void cap105_write(std::string s);
extern bool cap105_cb_save_as();
extern void cap105_cb_save();
extern void cap105_cb_check();
extern void cap105_cb_html();
extern void cap105_cb_textout();

//=====================================================================
// CAP 105
//=====================================================================

extern std::string	cap110_def_filename;
extern std::string	cap110_base_filename;
extern std::string	cap110_def_template_name;

extern void cap110_set_date();
extern void clear_110fields();
extern bool check_110fields();
extern void update_110fields();
extern void update_110form();
extern void clear_110_form();
extern std::string &cap110_nn(std::string & subst, int n);
extern void read_c110_buffer(std::string data);
extern void cap110_cb_load_template(std::string data);
extern void cap110_cb_new();
extern void cap110_cb_import();
extern void cap110_cb_export();
extern void cap110_cb_wrap_import(std::string wrapfilename, std::string inpbuffer);
extern int eval_cap110_fsize();
extern void cap110_cb_wrap_export();
extern void cap110_cb_wrap_autosend();
extern void cap110_cb_load_template();
extern void cap110_cb_save_template();
extern void cap110_cb_save_as_template();
extern void cap110_cb_open();
extern void write_110(std::string s);
extern bool cap110_cb_save_as();
extern void cap110_cb_save();
extern void cap110_cb_html();
extern void cap110_cb_msg_type();
extern void cap110_cb_textout();

#endif
