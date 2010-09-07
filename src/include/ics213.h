// =====================================================================
//
// ics213.h
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

#ifndef ICS213_H
#define ICS213_H

#include <string>
#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>

#include "arl_msgs.h"
#include "hx_msgs.h"

using namespace std;

struct FIELD { const char *f_type; string f_data; Fl_Widget **w; char w_type; };
extern FIELD fields[];
extern FIELD rg_fields[];


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

extern string baseFileName;
extern string defTemplateName;
extern string defFileName;
extern string defRTFname;
extern string title;
extern string buffer;

extern void cb_msg_type();

//menu callbacks
extern void cb_new();
extern void cb_open();
extern void cb_save();
extern void cb_save_as();
extern void cb_write();
extern void cb_rtf();
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

// ics213

extern string rg_base_filename;
extern string def_rgFileName;

extern bool usingTemplate;

extern void clear_ics_form();
extern void read_ics(string);
extern void write_ics(string);
extern void cb_ics_new();
extern void cb_ics_open();
extern void cb_ics_save();
extern void cb_ics_save_as();
extern void cb_ics_write();
extern void cb_ics_html();
extern void cb_ics_textout();
//extern void cb_ics_html_fcopy();
extern void cb_ics_import();
extern void cb_ics_export();
extern void cb_ics_wrap_import(string, string);
extern void cb_ics_wrap_export();
extern void cb_ics_wrap_autosend();
extern void cb_ics_load_template();
extern void cb_ics_save_template();
extern void cb_ics_save_as_template();
extern void cb_SetDate1();
extern void cb_SetDate2();
extern void cb_SetTime1();
extern void cb_SetTime2();

// radiogram

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
extern void clear_rg_fields();
extern void update_rg_fields();
extern void clear_rg_form();
extern void make_rg_buffer();
extern void read_rg_buffer(string data);
extern void cb_rg_new();
extern void cb_rg_import();
extern void cb_rg_export();
extern void cb_rg_wrap_import(string, string);
extern void cb_rg_wrap_export();
extern void cb_rg_wrap_autosend();
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

#endif
