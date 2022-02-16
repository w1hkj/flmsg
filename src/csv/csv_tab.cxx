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

#include "flmsg_dialog.h"
#include "flmsg.h"

extern void csv_editor(std::string);

Fl_Group	*tab_csv = (Fl_Group *)0;

FTextEdit	*txt_csv_msg = (FTextEdit *)0;
Fl_Button	*btn_csv_import = (Fl_Button *)0;
Fl_Button	*btn_csv_export = (Fl_Button *)0;
Fl_Button	*btn_csv_edit = (Fl_Button *)0;
Fl_Button	*btn_csv_view = (Fl_Button *)0;

static void cb_btn_csv_import(Fl_Button*, void*) {
	cb_csv_import_data();
}

static void cb_btn_csv_export(Fl_Button*, void*) {
	cb_csv_export_data(false);
}

static void cb_btn_csv_edit(Fl_Button*, void*) {
	cb_csv_export_data(true);
}

static void cb_btn_csv_view(Fl_Button*, void*) {
	csv_editor(txt_csv_msg->buffer()->text());
}

static void do_read_cb(const char *fn) {
	csv_set_fname(fn);
}

static void csv_changed(FTextEdit *, void *)
{
	estimate();
}

void create_csv_tab()
{
	tab_csv = new Fl_Group(0, tab_top, 570, 380);
	tab_csv->align(FL_ALIGN_TOP);

	btn_csv_import = new Fl_Button(570/2 - 220, tab_top + 5, 100, 24, _("Import CSV"));
	btn_csv_import->tooltip(_("Import data from spreadsheet CSV file"));
	btn_csv_import->callback((Fl_Callback*)cb_btn_csv_import);

	btn_csv_export = new Fl_Button(570/2 - 105, tab_top + 5, 100, 24, _("Export CSV"));
	btn_csv_export->tooltip(_("Export data to spreadsheet CSV file"));
	btn_csv_export->callback((Fl_Callback*)cb_btn_csv_export);

	btn_csv_view = new Fl_Button(570/2 + 10, tab_top + 5, 100, 24, _("View CSV"));
	btn_csv_view->tooltip(_(""));
	btn_csv_view->callback((Fl_Callback*)cb_btn_csv_view);

	btn_csv_edit = new Fl_Button(570/2 + 120, tab_top + 5, 100, 24, _("Edit CSV"));
	btn_csv_edit->tooltip(_(""));
	btn_csv_edit->callback((Fl_Callback*)cb_btn_csv_edit);

	txt_csv_msg = new FTextEdit(2, tab_top + 24 + 10, 566, 430 - (tab_top + 24 + 10 + 2));
	txt_csv_msg->box(FL_DOWN_FRAME);
	txt_csv_msg->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_csv_msg->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_csv_msg->labeltype(FL_NORMAL_LABEL);
	txt_csv_msg->labelfont(0);
	txt_csv_msg->labelsize(14);
	txt_csv_msg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_csv_msg->align(FL_ALIGN_TOP_LEFT);
	txt_csv_msg->set_read_cb(do_read_cb);
	txt_csv_msg->callback((Fl_Callback*)csv_changed);
	txt_csv_msg->when(FL_WHEN_CHANGED);

	tab_csv->end();
	tab_csv->hide();
}
