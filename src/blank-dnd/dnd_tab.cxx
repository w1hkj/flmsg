//======================================================================
// Drag-n-Drop tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_dnd = (Fl_Group *)0;
Fl_Input	*drop_box = (Fl_Input *)0;

static void cb_drop_box(Fl_Input*, void*) {
  drop_box_changed();
}

void create_dnd_tab()
{
	tab_dnd = new Fl_Group(0, tab_top, 570, 380);
	Fl_Box *b = new Fl_Box(50, 50, 470, 80,
	_(
"flmsg data files, wrapped data files and/or\n\
data file text may be imported."));
	b->box(FL_FLAT_BOX);
	b->align(FL_ALIGN_CENTER);
	drop_box = new Fl_Input(175, 135, 220, 220, _("^Drop Text/File Here^"));
	drop_box->callback((Fl_Callback*)cb_drop_box);
	drop_box->box(FL_DOWN_BOX);
	drop_box->value("");
	drop_box->labeltype(FL_NORMAL_LABEL);
	drop_box->labelfont(0);
	drop_box->labelsize(16);
	drop_box->color((Fl_Color)FL_BACKGROUND2_COLOR);
	drop_box->selection_color((Fl_Color)FL_SELECTION_COLOR);
	drop_box->align(FL_ALIGN_BOTTOM | FL_ALIGN_CENTER);
	drop_box->when(FL_WHEN_CHANGED);

	tab_dnd->end();

	tab_dnd->hide();
}
