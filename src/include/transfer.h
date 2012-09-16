#ifndef _TRANSFER_
#define _TRANSFER_

#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>

extern Fl_Group	*tab_transfer;
extern Fl_Output	*txt_send_filename;
extern Fl_Output	*txt_rcvd_filename;
extern Fl_Button	*btn_select_send;
extern Fl_Button	*btn_save_rcvd;

extern string def_transfer_filename;

extern void create_transfer_tab();
extern void clear_transfer_form();

#endif
