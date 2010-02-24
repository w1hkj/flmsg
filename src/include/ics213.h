#ifndef ICS213_H
#define ICS213_H

#include <string>
#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>

using namespace std;

struct FIELD { const char *f_type; string f_data; Fl_Widget **w; char w_type; };
extern FIELD fields[];

extern string IcsHomeDir;
extern Fl_Double_Window *mainwindow;

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

extern string defFileName;
extern string defRTFname;
extern string title;

extern void clear_form();
extern void read_ics(string);
extern void write_ics(string);
extern void cb_new();
extern void cb_open();
extern void cb_save();
extern void cb_save_as();
extern void cb_write();
extern void cb_import();
extern void cb_export();
extern void cb_wrap_import();
extern void cb_wrap_export();
extern void cb_wrap_autosend();
extern void cb_exit();
extern void cb_load_template();
extern void cb_save_template();
extern void cb_save_as_template();
extern void cb_About();
extern void cb_SetTime1();
extern void cb_SetTime2();
extern void cb_useZulu(bool);
extern void cb_SetDate1();
extern void cb_SetDate2();
extern void showoptions();
extern void closeoptions();

extern void set_main_label();
extern void show_filename(string);
extern void clear_fields();
extern void update_fields();

#endif
