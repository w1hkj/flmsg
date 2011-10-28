//======================================================================
// HICS forms

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_hics = (Fl_Group *)0;
Fl_Tabs		*tab_hics_type = (Fl_Tabs *)0;

static void cb_tab_hics_type(Fl_Tabs*, void*) {
  cb_msg_type();
}

void create_hics_tab()
{
	tab_hics = new Fl_Group(0, 45, 570, 380, _("HICS"));
	tab_hics_type = new Fl_Tabs(0, 45, 570, 380);
	tab_hics_type->selection_color((Fl_Color)246);
	tab_hics_type->callback((Fl_Callback*)cb_tab_hics_type);
	create_hics203_tab();
	create_hics206_tab();
	create_hics213_tab();
	create_hics214_tab();
	Fl_Group::current()->resizable(tab_hics203_type);
	tab_hics_type->end();
	tab_hics->end();
}
