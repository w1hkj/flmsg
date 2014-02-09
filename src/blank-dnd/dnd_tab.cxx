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
