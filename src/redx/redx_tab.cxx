//======================================================================
// Red Cross Tabs

#include <FL/Fl_Hold_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_redx = (Fl_Group *)0;
Fl_Tabs		*tab_redx_type = (Fl_Tabs *)0;

static void cb_tab_redx_type(Fl_Tabs*, void*) {
printf("redx tab pressed\n");
  cb_msg_type();
}

void create_redx_tab()
{
	tab_redx = new Fl_Group(0, 45, 570, 380, _("Red Cross"));
	tab_redx_type = new Fl_Tabs(0, 45, 570, 380);
	tab_redx_type->selection_color((Fl_Color)246);
	tab_redx_type->callback((Fl_Callback*)cb_tab_redx_type);
	create_redx_snw();
	Fl_Group::current()->resizable(tab_redx_snw);
	tab_redx_type->end();
	tab_redx->end();
}

