//======================================================================
// HICS forms

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

void hics_changed(Fl_Widget *, void *)
{
	estimate();
}

void create_hics_tab()
{
	create_hics203_tab();
	create_hics206_tab();
	create_hics213_tab();
	create_hics214_tab();
}
