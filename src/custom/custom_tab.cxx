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

#include <string>

#include "gettext.h"
#include "status.h"
#include "util.h"
#include "threads.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_custom = (Fl_Group *)0;

FTextView	*txt_custom_msg  = (FTextView *)0;
Fl_Button	*btn_custom_edit = (Fl_Button *)0;
Fl_Button	*btn_custom_view = (Fl_Button *)0;

static void cb_btn_custom_edit(Fl_Button*, void*) {
	if (custom_select < 0) return;
	handle_type = HANDLE_EDIT;
	std::string url = "http://127.0.0.1:";
	url.append(sz_srvr_portnbr);
	open_url(url.c_str());
}

static void cb_btn_custom_view(Fl_Button*, void*) {
	if (custom_select < 0) return;
	handle_type = HANDLE_VIEW;
	std::string url = "http://127.0.0.1:";
	url.append(sz_srvr_portnbr);
	open_url(url.c_str());
}

static void custom_changed(FTextEdit *, void *)
{
	estimate();
}

static void do_read_cb(const char *fn) {
	custom_set_fname(fn);
}

void create_custom_tab()
{
	int width = 570;
	tab_custom = new Fl_Group(0, tab_top, 570, 380);
	tab_custom->align(FL_ALIGN_TOP);

	btn_custom_edit = new Fl_Button(width/2 - 120, tab_top + 5, 100, 24, _("Edit Form"));
	btn_custom_edit->tooltip(_(""));
	btn_custom_edit->callback((Fl_Callback*)cb_btn_custom_edit);

	btn_custom_view = new Fl_Button(width/2 + 20, tab_top + 5, 100, 24, _("View Form"));
	btn_custom_view->tooltip(_(""));
	btn_custom_view->callback((Fl_Callback*)cb_btn_custom_view);

	txt_custom_msg = new FTextView(2, tab_top + 24 + 10, 566, 430 - (tab_top + 24 + 10 + 2));
	txt_custom_msg->box(FL_DOWN_FRAME);
	txt_custom_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_custom_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_custom_msg->labeltype(FL_NORMAL_LABEL);
	txt_custom_msg->labelfont(0);
	txt_custom_msg->labelsize(14);
	txt_custom_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_custom_msg->align(FL_ALIGN_TOP_LEFT);
	txt_custom_msg->set_read_cb(do_read_cb);
	txt_custom_msg->callback((Fl_Callback*)custom_changed);
	txt_custom_msg->when(FL_WHEN_CHANGED);

	tab_custom->end();
	tab_custom->hide();
}
