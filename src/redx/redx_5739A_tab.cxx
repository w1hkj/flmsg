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

#include <FL/Fl_Hold_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"
#include "fileselect.h"

Fl_Group	*tab_redx_5739A = (Fl_Group *)0;
Fl_Tabs		*tab_redx_5739A_type = (Fl_Tabs *)0;

Fl_Group	*tab_redx_5739A_1 = (Fl_Group *)0;

Fl_Input2	*rdx_5739A_nbr = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_name = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_state = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_cnty = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_city = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_date = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_street = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_georef = (Fl_Input2 *)0;

Fl_Group	*tab_redx_5739A_2 = (Fl_Group *)0;

Fl_Input2	*rdx_5739A_adrs0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_dwell0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_base0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_ds0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_mj0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_mn0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_af0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_in0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_un0 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_gd0 = (Fl_Input2 *)0;

Fl_Group	*tab_redx_5739A_3 = (Fl_Group *)0;

Fl_Input2	*rdx_5739A_adrs1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_dwell1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_base1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_ds1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_mj1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_mn1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_af1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_in1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_un1 = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739A_gd1 = (Fl_Input2 *)0;

//----------------------------------------------------------------------

// widget callbacks & support

//----------------------------------------------------------------------
static void cb_btn_5739A_date(Fl_Button*, void*) {
  rdx_5739A_date->value(szDate());
  estimate();
}

void create_redx_5739A()
{
	int Y = tab_top;
	tab_redx_5739A = new Fl_Group(0, Y, 570, 390);
	tab_redx_5739A->align(FL_ALIGN_TOP);

	tab_redx_5739A_type = new Fl_Tabs(0, Y+2, 570, 387);
	tab_redx_5739A_type->selection_color((Fl_Color)246);

	tab_redx_5739A_1 = new Fl_Group(0, Y+25, 570, 360, _("DR data"));

	Y += 35;
	Fl_Box *bx = new Fl_Box(50, Y, 200, 24, _("Red Cross Form 5739A"));
	bx->box(FL_FLAT_BOX);
	bx->align(FL_ALIGN_INSIDE | FL_ALIGN_CENTER);
	Y += 30;
	rdx_5739A_nbr = new Fl_Input2(100, Y, 150, 24, _("DR #"));
	rdx_5739A_nbr->tooltip(_(""));
	rdx_5739A_nbr->callback(redx_changed);
	rdx_5739A_nbr->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739A_name = new Fl_Input2(100, Y, 250, 24, _("DR Name"));
	rdx_5739A_name->tooltip(_(""));
	rdx_5739A_name->callback(redx_changed);
	rdx_5739A_name->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739A_state = new Fl_Input2(100, Y, 50, 24, _("State"));
	rdx_5739A_state->tooltip(_(""));
	rdx_5739A_state->callback(redx_changed);
	rdx_5739A_state->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739A_cnty = new Fl_Input2(100, Y, 250, 24, _("County"));
	rdx_5739A_cnty->tooltip(_(""));
	rdx_5739A_cnty->callback(redx_changed);
	rdx_5739A_cnty->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739A_city = new Fl_Input2(100, Y, 450, 24, _("City"));
	rdx_5739A_city->tooltip(_(""));
	rdx_5739A_city->callback(redx_changed);
	rdx_5739A_city->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739A_date = new Fl_Input2(100, Y, 150, 24, _("Date"));
	rdx_5739A_date->tooltip(_(""));
	rdx_5739A_date->callback(redx_changed);
	rdx_5739A_date->when(FL_WHEN_CHANGED);

	Fl_Button *btn_5739A_date = new Fl_Button(260, Y+2, 20, 20, _("..."));
	btn_5739A_date->tooltip(_("Set today"));
	btn_5739A_date->callback((Fl_Callback*)cb_btn_5739A_date);

	Y += 30;
	rdx_5739A_street = new Fl_Input2(100, Y, 450, 24, _("Street"));
	rdx_5739A_street->tooltip(_(""));
	rdx_5739A_street->callback(redx_changed);
	rdx_5739A_street->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739A_georef = new Fl_Input2(100, Y, 450, 24, _("Geo. Ref."));
	rdx_5739A_georef->tooltip(_(""));
	rdx_5739A_georef->callback(redx_changed);
	rdx_5739A_georef->when(FL_WHEN_CHANGED);

	tab_redx_5739A_1->end();

	Y = tab_top;
	tab_redx_5739A_2 = new Fl_Group(0, Y+25, 570, 360, _("Area-1"));
	Y += 35;
	rdx_5739A_adrs0 = new Fl_Input2(160, Y, 300, 24, _("range of address #'s"));
	rdx_5739A_adrs0->tooltip(_(""));
	rdx_5739A_adrs0->callback(redx_changed);
	rdx_5739A_adrs0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_dwell0 = new Fl_Input2(160, Y, 50, 24, _("# affected dwellings"));
	rdx_5739A_dwell0->tooltip(_(""));
	rdx_5739A_dwell0->callback(redx_changed);
	rdx_5739A_dwell0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_base0 = new Fl_Input2(160, Y, 50, 24, _("Basements y/n?"));
	rdx_5739A_base0->tooltip(_(""));
	rdx_5739A_base0->callback(redx_changed);
	rdx_5739A_base0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_ds0 = new Fl_Input2(160, Y, 50, 24, _("Destroyed %"));
	rdx_5739A_ds0->tooltip(_(""));
	rdx_5739A_ds0->callback(redx_changed);
	rdx_5739A_ds0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_mj0 = new Fl_Input2(160, Y, 50, 24, _("Major damage %"));
	rdx_5739A_mj0->tooltip(_(""));
	rdx_5739A_mj0->callback(redx_changed);
	rdx_5739A_mj0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_mn0 = new Fl_Input2(160, Y, 50, 24, _("Minor damage %"));
	rdx_5739A_mn0->tooltip(_(""));
	rdx_5739A_mn0->callback(redx_changed);
	rdx_5739A_mn0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_af0 = new Fl_Input2(160, Y, 50, 24, _("Affected %"));
	rdx_5739A_af0->tooltip(_(""));
	rdx_5739A_af0->callback(redx_changed);
	rdx_5739A_af0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_in0 = new Fl_Input2(160, Y, 50, 24, _("Inaccessible %"));
	rdx_5739A_in0->tooltip(_(""));
	rdx_5739A_in0->callback(redx_changed);
	rdx_5739A_in0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_un0 = new Fl_Input2(160, Y, 50, 24, _("Unknown/None %"));
	rdx_5739A_un0->tooltip(_(""));
	rdx_5739A_un0->callback(redx_changed);
	rdx_5739A_un0->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_gd0 = new Fl_Input2(160, Y, 400, 76, _("General desc."));
	rdx_5739A_gd0->align(FL_ALIGN_LEFT_TOP);
	rdx_5739A_gd0->type(4);
	rdx_5739A_gd0->tooltip(_(""));
	rdx_5739A_gd0->callback(redx_changed);
	rdx_5739A_gd0->when(FL_WHEN_CHANGED);

	tab_redx_5739A_2->end();

	Y = tab_top;
	tab_redx_5739A_3 = new Fl_Group(0, Y+25, 570, 360, _("Area-2"));
	Y += 35;
	rdx_5739A_adrs1 = new Fl_Input2(160, Y, 300, 24, _("range of address #'s"));
	rdx_5739A_adrs1->tooltip(_(""));
	rdx_5739A_adrs1->callback(redx_changed);
	rdx_5739A_adrs1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_dwell1 = new Fl_Input2(160, Y, 50, 24, _("# affected dwellings"));
	rdx_5739A_dwell1->tooltip(_(""));
	rdx_5739A_dwell1->callback(redx_changed);
	rdx_5739A_dwell1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_base1 = new Fl_Input2(160, Y, 50, 24, _("Basements y/n?"));
	rdx_5739A_base1->tooltip(_(""));
	rdx_5739A_base1->callback(redx_changed);
	rdx_5739A_base1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_ds1 = new Fl_Input2(160, Y, 50, 24, _("Destroyed %"));
	rdx_5739A_ds1->tooltip(_(""));
	rdx_5739A_ds1->callback(redx_changed);
	rdx_5739A_ds1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_mj1 = new Fl_Input2(160, Y, 50, 24, _("Major damage %"));
	rdx_5739A_mj1->tooltip(_(""));
	rdx_5739A_mj1->callback(redx_changed);
	rdx_5739A_mj1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_mn1 = new Fl_Input2(160, Y, 50, 24, _("Minor damage %"));
	rdx_5739A_mn1->tooltip(_(""));
	rdx_5739A_mn1->callback(redx_changed);
	rdx_5739A_mn1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_af1 = new Fl_Input2(160, Y, 50, 24, _("Affected %"));
	rdx_5739A_af1->tooltip(_(""));
	rdx_5739A_af1->callback(redx_changed);
	rdx_5739A_af1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_in1 = new Fl_Input2(160, Y, 50, 24, _("Inaccessible %"));
	rdx_5739A_in1->tooltip(_(""));
	rdx_5739A_in1->callback(redx_changed);
	rdx_5739A_in1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_un1 = new Fl_Input2(160, Y, 50, 24, _("Unknown/None %"));
	rdx_5739A_un1->tooltip(_(""));
	rdx_5739A_un1->callback(redx_changed);
	rdx_5739A_un1->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739A_gd1 = new Fl_Input2(160, Y, 400, 76, _("General desc."));
	rdx_5739A_gd1->align(FL_ALIGN_LEFT_TOP);
	rdx_5739A_gd1->type(4);
	rdx_5739A_gd1->tooltip(_(""));
	rdx_5739A_gd1->callback(redx_changed);
	rdx_5739A_gd1->when(FL_WHEN_CHANGED);

	tab_redx_5739A_3->end();

	tab_redx_5739A->end();

	tab_redx_5739A->hide();

};

