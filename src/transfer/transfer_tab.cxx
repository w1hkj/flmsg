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
#include "transfer.h"

Fl_Group	*tab_transfer = (Fl_Group *)0;

Fl_Button	*btn_select_send = (Fl_Button *)0;
Fl_Button	*btn_save_rcvd = (Fl_Button *)0;
Fl_Output	*txt_send_filename = (Fl_Output *)0;
Fl_Output	*txt_rcvd_filename = (Fl_Output *)0;

static void cb_btn_select_send(Fl_Button*, void*) {
	cb_transfer_open();
}

static void cb_btn_save_rcvd(Fl_Button*, void*) {
	cb_transfer_save_as();
}

void create_transfer_tab()
{
	tab_transfer = new Fl_Group(0, tab_top, 570, 430 - tab_top);
	tab_transfer->align(FL_ALIGN_TOP);

	txt_send_filename = new Fl_Output(5, tab_top + 50, 485, 24, _("Transmit file:"));
	txt_send_filename->align(FL_ALIGN_TOP_LEFT);
	txt_send_filename->tooltip("");

	btn_select_send = new Fl_Button(495, tab_top + 50, 70, 24, _("Select"));
	btn_select_send->tooltip(_("Select data file to transfer"));
	btn_select_send->callback((Fl_Callback*)cb_btn_select_send);

	txt_rcvd_filename = new Fl_Output(5, tab_top + 120, 485, 24, _("Received file:"));
	txt_rcvd_filename->align(FL_ALIGN_TOP_LEFT);
	txt_rcvd_filename->tooltip("");

	btn_save_rcvd = new Fl_Button(495, tab_top + 120, 70, 24, _("Save"));
	btn_save_rcvd->tooltip(_("Export data to file"));
	btn_save_rcvd->callback((Fl_Callback*)cb_btn_save_rcvd);

	tab_transfer->end();
	tab_transfer->hide();
}
