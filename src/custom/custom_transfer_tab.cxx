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
#include "combo.h"

Fl_Group   *tab_custom_transfer = (Fl_Group *)0;

Fl_ListBox *custom_selector = (Fl_ListBox *)0;
Fl_Output  *txt_rcvd_custom_html_filename = (Fl_Output *)0;
Fl_Button  *btn_save_custom_html_file = (Fl_Button *)0;

void create_custom_transfer_tab()
{
	tab_custom_transfer = new Fl_Group(0, tab_top, 570, 380);
	tab_custom_transfer->align(FL_ALIGN_TOP);

	Fl_Group *TransmitGroup = new Fl_Group(2, tab_top + 30, 566, 80, _("Transmit Custom FORM for transfer"));
	TransmitGroup->box(FL_ENGRAVED_BOX);
	TransmitGroup->align(FL_ALIGN_TOP | FL_ALIGN_INSIDE);

		custom_selector = new Fl_ListBox( 10, tab_top + 65, 480, 24, _("Select custom form"));
		custom_selector->align(FL_ALIGN_TOP_LEFT);
		load_custom_transfer();
		custom_selector->callback((Fl_Callback*)cb_btn_select_custom_html);

	TransmitGroup->end();

	Fl_Group *ReceiveGroup = new Fl_Group(2, tab_top + 115, 566, 80, _("Receive Custom FORM"));
	ReceiveGroup->box(FL_ENGRAVED_BOX);
	ReceiveGroup->align(FL_ALIGN_TOP | FL_ALIGN_INSIDE);

		txt_rcvd_custom_html_filename = new Fl_Output(10, tab_top + 150, 480, 24, _("Received custom form"));
		txt_rcvd_custom_html_filename->align(FL_ALIGN_TOP_LEFT);
		txt_rcvd_custom_html_filename->tooltip("");

		btn_save_custom_html_file = new Fl_Button(495, tab_top + 150, 70, 24, _("Save"));
		btn_save_custom_html_file->tooltip(_("Export data to file"));
		btn_save_custom_html_file->callback((Fl_Callback*)cb_save_custom_html);

	ReceiveGroup->end();

	tab_custom_transfer->end();
	tab_custom_transfer->hide();
}

