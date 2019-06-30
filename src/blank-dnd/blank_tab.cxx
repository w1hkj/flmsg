// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_blank = (Fl_Group *)0;
FTextEdit	*txt_blank_msg = (FTextEdit *)0;

static void blank_changed(FTextEdit*, void*)
{
	estimate();
}

void create_blank_tab()
{
	tab_blank = new Fl_Group(0, tab_top, 570, 380);
	tab_blank->align(FL_ALIGN_TOP);

//	txt_blank_msg = new FTextEdit(4, 50, 562, 370);
	txt_blank_msg = new FTextEdit(2, tab_blank->y() + 4, tab_blank->w() - 4, tab_blank->h() - 6);
	txt_blank_msg->box(FL_DOWN_FRAME);
	txt_blank_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_blank_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_blank_msg->labeltype(FL_NORMAL_LABEL);
	txt_blank_msg->labelfont(0);
	txt_blank_msg->labelsize(14);
	txt_blank_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_blank_msg->align(FL_ALIGN_TOP_LEFT);
	txt_blank_msg->callback((Fl_Callback*)blank_changed);
	txt_blank_msg->when(FL_WHEN_CHANGED);
	Fl_Group::current()->resizable(txt_blank_msg);
	tab_blank->end();
	tab_blank->hide();
}
