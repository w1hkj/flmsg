//======================================================================
// Blank tab

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_blank = (Fl_Group *)0;
FTextEdit	*txt_blank_msg = (FTextEdit *)0;

void create_blank_tab()
{
	tab_blank = new Fl_Group(0, tab_top, 570, 380);
	tab_blank->align(FL_ALIGN_TOP);

	txt_blank_msg = new FTextEdit(4, 50, 562, 370);
	txt_blank_msg->box(FL_DOWN_FRAME);
	txt_blank_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_blank_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_blank_msg->labeltype(FL_NORMAL_LABEL);
	txt_blank_msg->labelfont(0);
	txt_blank_msg->labelsize(14);
	txt_blank_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_blank_msg->align(FL_ALIGN_TOP_LEFT);
	txt_blank_msg->when(FL_WHEN_RELEASE);
	Fl_Group::current()->resizable(txt_blank_msg);
	tab_blank->end();
	tab_blank->hide();
}
