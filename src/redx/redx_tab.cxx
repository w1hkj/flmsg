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

void redx_changed(Fl_Widget *, void *)
{
	estimate();
}

void create_redx_tab()
{
	create_redx_snw();
	create_redx_5739();
	create_redx_5739A();
	create_redx_5739B();
}

