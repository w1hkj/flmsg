// =====================================================================
//
// flmsg.h
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

#ifndef FLMSG_H
#define FLMSG_H

#include <string>
#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>

#include "arl_msgs.h"
#include "hx_msgs.h"

using namespace std;

struct FIELD { string f_type; string f_data; void **w; char w_type; };
extern FIELD fields[];
extern FIELD ptfields[];
extern FIELD rgfields[];

extern void checkdirectories(void);
extern int parse_args(int argc, char **argv, int& idx);
extern void showoptions();

extern Fl_Double_Window *mainwindow;
extern Fl_Double_Window *optionswindow;
extern Fl_Double_Window *arlwindow;
extern Fl_Double_Window *configwindow;
extern Fl_Double_Window *hxwindow;
extern string flmsgHomeDir;
extern string IcsHomeDir;

extern int arl_nbr;

extern string NBEMS_dir;
extern string ARQ_dir;
extern string ARQ_files_dir;
extern string ARQ_recv_dir;
extern string ARQ_send;
extern string WRAP_dir;
extern string WRAP_recv_dir;
extern string WRAP_send_dir;
extern string WRAP_auto_dir;
extern string ICS_dir;
extern string ICS_msg_dir;
extern string ICS_tmp_dir;


extern string title;
extern string buffer;

extern void cb_msg_type();

extern char *named_file();

//menu callbacks
extern void cb_new();
extern void cb_open();
extern void cb_save();
extern void cb_save_as();
extern void cb_text();
extern void cb_import();
extern void cb_export();
extern void cb_wrap_import();
extern void cb_wrap_export();
extern void cb_wrap_autosend();
extern void cb_exit();
extern void cb_load_template();
extern void cb_save_template();
extern void cb_save_as_template();
extern void cb_config();
extern void cb_close_config();
extern void showoptions();
extern void show_help();
extern void cb_About();
extern void cb_html();
extern void cb_html_fcopy();

extern void open_url(const char* url);

extern void cb_arl();
extern void cb_arl_cancel();
extern void cb_arl_add();

extern void cb_hx();
extern void cb_hx_select();
extern void cb_hx_select_add();
extern void cb_hx_select_cancel();
extern void cb_hx_select_ok();

extern void closeoptions();

extern void remove_spaces_from_filename(string &fname);
extern char *szTime(int typ = 0);
extern char *szDate();
extern char *szAbbrevDate();
extern char *szDateTime();

extern void set_main_label();
extern void show_filename(string);
extern void clear_fields();
extern void update_fields();

extern void to_html(string &s);
extern void fm_html(string &html);

// used by all form management

extern string lineout( string &, string & );
extern string binout( string &, bool & );
extern string header( const char * );
extern string findstr(string &, string &);
extern bool   findbin(string &, string &);
extern void   replacestr(string &form, string &where, string &what);
extern void   replacelf(string &form, int n = 0);

// ics205
extern string base_205_filename;
extern string def_205_filename;
extern string def_205_TemplateName;
extern bool using_ics205_template;

extern void cb_205_SetDateTime1();
extern void cb_205_SetDateTime2();
extern void clear_205fields();
extern void update_205fields();
extern void clear_205_form();
extern void make_buff205();
extern string find(string haystack, string needle);
extern void read_205_buffer(string data);
extern void cb_205_new();
extern void cb_205_import();
extern void cb_205_export();
extern void cb_205_wrap_import(string wrapfilename, string inpbuffer);
extern void cb_205_wrap_export();
extern void cb_205_wrap_autosend();
extern void cb_205_load_template();
extern void cb_205_save_template();
extern void cb_205_save_as_template();
extern void cb_205_open();
extern void write_205(string s);
extern void cb_205_save_as();
extern void cb_205_save();
extern void cb_205_html();
extern void cb_205_msg_type();
extern void cb_205_textout();

// ics203
extern string yes;
extern string no;

extern string buff203;
extern string def_203_filename;
extern string base_203_filename;
extern string def_203_TemplateName;
extern bool using_ics203_template;

extern void cb_203_set_date();
extern void cb_203_set_time();
extern void clear_203fields();
extern void update_203fields();
extern void clear_203_form();
extern void make_buff203();
extern void read_203_buffer(string data);
extern void cb_203_new();
extern void cb_203_import();
extern void cb_203_export();
extern void cb_203_wrap_import(string wrapfilename, string inpbuffer);
extern void cb_203_wrap_export();
extern void cb_203_wrap_autosend();
extern void cb_203_load_template();
extern void cb_203_save_template();
extern void cb_203_save_as_template();
extern void cb_203_open();
extern void write_203(string s);
extern void cb_203_save_as();
extern void cb_203_save();
extern void cb_203_html();
extern void cb_203_msg_type();
extern void cb_203_textout();

// ics206
extern string yes;
extern string no;

extern string buff206;
extern string def_206_filename;
extern string base_206_filename;
extern string def_206_TemplateName;
extern bool using_ics206_template;

extern void cb_206_setdate();
extern void cb_206_settime();
extern void clear_206fields();
extern void update_206fields();
extern void clear_206_form();
extern void make_buff206();
extern void read_206_buffer(string data);
extern void cb_206_new();
extern void cb_206_import();
extern void cb_206_export();
extern void cb_206_wrap_import(string wrapfilename, string inpbuffer);
extern void cb_206_wrap_export();
extern void cb_206_wrap_autosend();
extern void cb_206_load_template();
extern void cb_206_save_template();
extern void cb_206_save_as_template();
extern void cb_206_open();
extern void write_206(string s);
extern void cb_206_save_as();
extern void cb_206_save();
extern void cb_206_html();
extern void cb_206_msg_type();
extern void cb_206_textout();

// ics213
extern bool using_213Template;
extern string base_213_filename;
extern string def_213_filename;
extern string def_213_TemplateName;

extern void clear_213_form();
extern void read_213(string);
extern void write_213(string);
extern void read_213_buffer(string);

extern void cb_213_new();
extern void cb_213_open();
extern void cb_213_save();
extern void cb_213_save_as();
extern void cb_213_write();
extern void cb_213_html();
extern void cb_213_textout();
extern void cb_213_import();
extern void cb_213_export();
extern void cb_213_wrap_import(string, string);
extern void cb_213_wrap_export();
extern void cb_213_wrap_autosend();
extern void cb_213_load_template();
extern void cb_213_save_template();
extern void cb_213_save_as_template();
extern void cb_SetDate1();
extern void cb_SetDate2();
extern void cb_SetTime1();
extern void cb_SetTime2();

// radiogram
extern bool using_rg_template;
extern string base_rg_filename;
extern string def_rg_filename;
extern string def_rg_TemplateName;

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
extern void make_rg_buffer();
extern void read_rg_buffer(string data);
extern void cb_rg_new();
extern void cb_rg_import();
extern void cb_rg_export();
extern void cb_rg_wrap_import(string, string);
extern void cb_rg_wrap_export();
extern void cb_rg_wrap_autosend();
extern void cb_rg_load_template();
extern void cb_rg_save_template();
extern void cb_rg_save_as_template();
extern void read_rg(string s);
extern void cb_rg_open();
extern void write_rg(string s);
extern void cb_rg_save_as();
extern void cb_rg_save();
extern void cb_rg_html();
extern void cb_rg_html_fcopy();
extern void cb_rg_rtf();
extern void cb_rg_textout();
extern void set_rg_choices();
extern void cb_rg_check();
extern void cb_rg_nbr(Fl_Widget *);
extern void cb_rg_filter_input(Fl_Widget *);

extern void read_data_file(string);

// plaintext
extern bool using_pt_template;
extern string base_pt_filename;
extern string def_pt_filename;
extern string def_pt_TemplateName;

extern void cb_set_pt_date();
extern void cb_set_pt_time();
extern void clear_ptfields();
extern void update_ptfields();
extern void clear_pt_form();
extern void make_ptbuffer();
extern void read_ptbuffer(string data);
extern void cb_pt_new();
extern void cb_pt_import();
extern void cb_pt_export();
extern void cb_pt_wrap_import(string wrapfilename, string inpbuffer);
extern void cb_pt_wrap_export();
extern void cb_pt_wrap_autosend();
extern void cb_pt_load_template();
extern void cb_pt_save_template();
extern void cb_pt_save_as_template();
extern void read_pt_data_file(string s);
extern void cb_pt_open();
extern void write_pt(string s);
extern void cb_pt_save_as();
extern void cb_pt_save();
extern void cb_pt_html();
extern void cb_pt_msg_type();
extern void cb_pt_textout();

// blank form
extern bool using_blank_template;
extern string base_blank_filename;
extern string def_blank_filename;
extern string def_blank_TemplateName;

extern void clear_blankfields();
extern void update_blankfields();
extern void clear_blank_form();
extern void make_blankbuffer();
extern void read_blankbuffer(string data);
extern void cb_blank_new();
extern void cb_blank_import();
extern void cb_blank_export();
extern void cb_blank_wrap_import(string wrapfilename, string inpbuffer);
extern void cb_blank_wrap_export();
extern void cb_blank_wrap_autosend();
extern void cb_blank_load_template();
extern void cb_blank_save_template();
extern void cb_blank_save_as_template();
extern void read_blank_data_file(string s);
extern void cb_blank_open();
extern void write_blank(string s);
extern void cb_blank_save_as();
extern void cb_blank_save();
extern void cb_blank_html();
extern void cb_blank_msg_type();
extern void cb_blank_textout();

#endif
