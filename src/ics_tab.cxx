//======================================================================
// ICS forms

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_ics = (Fl_Group *)0;
Fl_Tabs	*tab_ics_type = (Fl_Tabs *)0;

static void cb_tabs_msg_type(Fl_Tabs*, void*) {
  cb_msg_type();
}

static void cb_tab_ics_type(Fl_Tabs*, void*) {
  cb_msg_type();
}

void create_ics_tab()
{ // tab_msg_type
	tabs_msg_type = new Fl_Tabs(0, 22, 570, 405);
	tabs_msg_type->selection_color((Fl_Color)246);
	tabs_msg_type->callback((Fl_Callback*)cb_tabs_msg_type);
	tab_ics = new Fl_Group(0, 45, 570, 380, _("ICS"));
	tab_ics_type = new Fl_Tabs(0, 45, 570, 380);
	tab_ics_type->selection_color((Fl_Color)246);
	tab_ics_type->callback((Fl_Callback*)cb_tab_ics_type);
	create_ics203_tab();
	create_ics205_tab();
	create_ics205a_tab();
	create_ics206_tab();
	create_ics213_tab();
	create_ics214_tab();
	create_ics216_tab();
	Fl_Group::current()->resizable(tab_ics216_type);
	tab_ics_type->end();
	tab_ics->end();
}
