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
#include "fileselect.h"
#include "calendar.h"

Fl_Group	*tab_severe_wx = (Fl_Group *)0;
Fl_Tabs		*tab_severe_wx_type = (Fl_Tabs *)0;

Fl_Group	*tab_severe_wx_1 = (Fl_Group *)0;

Fl_DateInput	*w_severe_wx_date = (Fl_DateInput *)0;
Fl_Input2	*w_severe_wx_time = (Fl_Input2 *)0;
Fl_Button	*w_severe_wx_btn_time = (Fl_Button *)0;
Fl_ListBox *w_severe_wx_zone = (Fl_ListBox *)0;

Fl_Check_Button *w_severe_wx_meas = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_est = (Fl_Check_Button *)0;

Fl_ListBox	*w_severe_wx_state = (Fl_ListBox *)0;
Fl_ListBox	*w_severe_wx_county = (Fl_ListBox *)0;
Fl_Input2	*w_severe_wx_city = (Fl_Input2 *)0;
Fl_Button	*use_default = (Fl_Button *)0;
Fl_Button	*make_default = (Fl_Button *)0;

Fl_Input2	*w_severe_wx_wind_speed = (Fl_Input2 *)0;
Fl_ListBox	*w_severe_wx_hail_size = (Fl_ListBox *)0;

Fl_Check_Button *w_severe_wx_exact = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_not_exact = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_tornado = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_funnel_cloud = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_wall_cloud = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_hail = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_high_wind = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_measured = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_estimated = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_flood = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_flash_flood = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_other = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_dmg_yes = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_dmg_no = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_inj_yes = (Fl_Check_Button *)0;
Fl_Check_Button *w_severe_wx_inj_no = (Fl_Check_Button *)0;

Fl_Group	*tab_severe_wx_2 = (Fl_Group *)0;
FTextEdit	*w_severe_wx_narrative = (FTextEdit *)0;

//----------------------------------------------------------------------

// widget callbacks & support

//----------------------------------------------------------------------

static void cb_btn_time(Fl_Button*, void*) {
	w_severe_wx_time->value(szTime(7));
}

static void cb_exact(Fl_Check_Button*, void*)
{
	w_severe_wx_not_exact->value(!w_severe_wx_exact->value());
	estimate();
}

static void cb_not_exact(Fl_Check_Button*, void*)
{
	w_severe_wx_exact->value(!w_severe_wx_not_exact->value());
	estimate();
}

static void cb_severe_wx_measured(Fl_Check_Button*, void*)
{
	w_severe_wx_estimated->value(!w_severe_wx_measured->value());
	estimate();
}

static void cb_severe_wx_estimated(Fl_Check_Button*, void*)
{
	w_severe_wx_measured->value(!w_severe_wx_estimated->value());
	estimate();
}

static void cb_dmg_yes(Fl_Check_Button*, void*)
{
	w_severe_wx_dmg_no->value(!w_severe_wx_dmg_yes->value());
	estimate();
}

static void cb_dmg_no(Fl_Check_Button*, void*)
{
	w_severe_wx_dmg_yes->value(!w_severe_wx_dmg_no->value());
	estimate();
}

static void cb_inj_yes(Fl_Check_Button*, void*)
{
	w_severe_wx_inj_no->value(!w_severe_wx_inj_yes->value());
	estimate();
}

static void cb_inj_no(Fl_Check_Button*, void*)
{
	w_severe_wx_inj_yes->value(!w_severe_wx_inj_no->value());
	estimate();
}

static void cb_make_default(Fl_Button*, void*)
{
	progStatus.swx_index_default_county = w_severe_wx_county->index();
	progStatus.swx_index_default_state = w_severe_wx_state->index();
	progStatus.swx_default_city = w_severe_wx_city->value();
	progStatus.swx_default_zone = w_severe_wx_zone->value();
}

static void cb_use_default(Fl_Button*, void*)
{
	w_severe_wx_state->index(progStatus.swx_index_default_state);
	set_severe_wx_counties(progStatus.swx_index_default_state);
	w_severe_wx_county->index(progStatus.swx_index_default_county);
	w_severe_wx_city->value(progStatus.swx_default_city.c_str());
	w_severe_wx_zone->value(progStatus.swx_default_zone.c_str());
}

void severe_wx_changed(Fl_Widget *, void *)
{
	estimate();
}

void cb_state(Fl_Widget *, void *)
{
	int n = w_severe_wx_state->index();
	set_severe_wx_counties(n);
	estimate();
}

void cb_hail_changed(Fl_Widget *, void *)
{
	w_severe_wx_hail_size->index(0);
	if (w_severe_wx_hail->value())
		w_severe_wx_hail_size->activate();
	else
		w_severe_wx_hail_size->deactivate();
}

void create_severe_wx_tab()
{
	int Y = tab_top;
	tab_severe_wx = new Fl_Group(0, Y, 570, 390, "tab_severe_wx");
	tab_severe_wx->begin();
	tab_severe_wx->copy_label("");
	tab_severe_wx->align(FL_ALIGN_INSIDE);

	tab_severe_wx_type = new Fl_Tabs(0, Y+2, 570, 387, "wx_tabs");
	tab_severe_wx_type->selection_color((Fl_Color)246);
	tab_severe_wx_type->copy_label("");
	tab_severe_wx_type->align(FL_ALIGN_INSIDE);

	tab_severe_wx_1 = new Fl_Group(0, Y+25, 570, 360, "Report");
	tab_severe_wx_1->begin();

	Y += 35;

	w_severe_wx_date = new Fl_DateInput(50, Y, 140, 22, _("Date"));
	w_severe_wx_date->tooltip(_("Observation date : month/day/year"));
	w_severe_wx_date->callback(severe_wx_changed);
	w_severe_wx_date->box(FL_DOWN_BOX);
	w_severe_wx_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
	w_severe_wx_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
	w_severe_wx_date->labeltype(FL_NORMAL_LABEL);
	w_severe_wx_date->labelfont(0);
	w_severe_wx_date->labelsize(14);
	w_severe_wx_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	w_severe_wx_date->when(FL_WHEN_RELEASE);
	w_severe_wx_date->align(FL_ALIGN_LEFT);
	w_severe_wx_date->local_datetime();

	w_severe_wx_time = new Fl_Input2(230, Y, 60, 22, _("Time"));
	w_severe_wx_time->tooltip(_("Observation time : HHMM"));
	w_severe_wx_time->callback(severe_wx_changed);
	w_severe_wx_time->when(FL_WHEN_RELEASE);
	w_severe_wx_time->align(FL_ALIGN_LEFT);

	w_severe_wx_btn_time = new Fl_Button(292, Y, 22, 22, _("..."));
	w_severe_wx_btn_time->tooltip(_("Current local time"));
	w_severe_wx_btn_time->callback((Fl_Callback*)cb_btn_time);

	w_severe_wx_zone = new Fl_ListBox(316, Y, 80, 22, "Zone");
	w_severe_wx_zone->copy_label(_(""));
	w_severe_wx_zone->align(FL_ALIGN_TOP || FL_ALIGN_INSIDE);
	w_severe_wx_zone->tooltip(_("Time Zone, ie: EDT"));
	w_severe_wx_zone->when(FL_WHEN_RELEASE);
	w_severe_wx_zone->align(FL_ALIGN_RIGHT);
	for (int n = 0; n < num_us_tzones; n++)
		w_severe_wx_zone->add(us_tzones[n].c_str());
	w_severe_wx_zone->callback(severe_wx_changed);

	w_severe_wx_exact = new Fl_Check_Button(410, Y, 22, 22, "");
	w_severe_wx_exact->copy_label(_("Meas."));
	w_severe_wx_exact->tooltip(_("Date time exact"));
	w_severe_wx_exact->callback((Fl_Callback*)cb_exact);

	w_severe_wx_not_exact = new Fl_Check_Button(480, Y, 22, 22, "");
	w_severe_wx_not_exact->copy_label(_("Est."));
	w_severe_wx_not_exact->tooltip(_("Date time estimated"));
	w_severe_wx_not_exact->callback((Fl_Callback*)cb_not_exact);

	Y += 25;
	w_severe_wx_state = new Fl_ListBox(125, Y, 400, 22, "State");
	w_severe_wx_state->copy_label(_("State/Province"));
	w_severe_wx_state->tooltip(_("Select state / province"));
	w_severe_wx_state->align(FL_ALIGN_LEFT);
	w_severe_wx_state->when(FL_WHEN_RELEASE);
	w_severe_wx_state->callback((Fl_Callback*)cb_state);

	Y += 25;
	w_severe_wx_county = new Fl_ListBox(125, Y, 400, 22, "County");
	w_severe_wx_county->copy_label(_("County"));
	w_severe_wx_county->tooltip(_("Select county"));
	w_severe_wx_county->align(FL_ALIGN_LEFT);
	w_severe_wx_county->when(FL_WHEN_RELEASE);
	w_severe_wx_county->callback((Fl_Callback*)severe_wx_changed);

	Y += 25;
	w_severe_wx_city = new Fl_Input2(50, Y, 250, 22, "City");
	w_severe_wx_city->copy_label(_("City"));
	w_severe_wx_city->tooltip(_("Enter city/town"));
	w_severe_wx_city->align(FL_ALIGN_LEFT);
	w_severe_wx_city->when(FL_WHEN_RELEASE);
	w_severe_wx_city->callback((Fl_Callback*)severe_wx_changed);

	make_default = new Fl_Button(410, Y, 70, 24, _("Store"));
	make_default->tooltip(_("Store state/county/city/time-zone as default"));
	make_default->callback((Fl_Callback*)cb_make_default);

	use_default = new Fl_Button(485, Y, 70, 24, _("Default"));
	use_default->tooltip(_("Use default state/province/county/city/time-zone"));
	use_default->callback((Fl_Callback*)cb_use_default);

	Y += 35;
	w_severe_wx_tornado = new Fl_Check_Button(50, Y, 150, 22, _("Tornado"));
	w_severe_wx_tornado->tooltip(_("Report tornado sighting"));
	w_severe_wx_tornado->callback((Fl_Callback*)severe_wx_changed);

	Y += 25;
	w_severe_wx_funnel_cloud = new Fl_Check_Button(50, Y, 150, 22, _("Funnel cloud"));
	w_severe_wx_funnel_cloud->tooltip(_("Report funnel cloud sighting"));
	w_severe_wx_funnel_cloud->callback((Fl_Callback*)severe_wx_changed);

	Y += 25;
	w_severe_wx_wall_cloud = new Fl_Check_Button(50, Y, 150, 22, _("Wall cloud"));
	w_severe_wx_wall_cloud->tooltip(_("Report wall cloud sighting"));
	w_severe_wx_wall_cloud->callback((Fl_Callback*)severe_wx_changed);

	Fl_Group lbl1(200, Y, 200, 22, _("Note if there is rotation in narrative"));
	lbl1.begin();
	lbl1.box(FL_FLAT_BOX);
	lbl1.end();

	Y += 25;
	w_severe_wx_hail = new Fl_Check_Button(50, Y, 150, 22, _("Hail"));
	w_severe_wx_hail->tooltip(_("Report incidence of hail"));
	w_severe_wx_hail->callback((Fl_Callback*)cb_hail_changed);

	w_severe_wx_hail_size = new Fl_ListBox(150, Y, 150, 22, "hail size");
	w_severe_wx_hail_size->copy_label(_("Size"));
	w_severe_wx_hail_size->align(FL_ALIGN_LEFT);
	w_severe_wx_hail_size->when(FL_WHEN_RELEASE);
	w_severe_wx_hail_size->callback((Fl_Callback*)severe_wx_changed);
	w_severe_wx_hail_size->deactivate();

	Y += 25;
	w_severe_wx_high_wind = new Fl_Check_Button(50, Y, 60, 22, _("High Wind"));
	w_severe_wx_high_wind->tooltip(_("Report high winds"));
	w_severe_wx_high_wind->callback((Fl_Callback*)severe_wx_changed);

	w_severe_wx_wind_speed = new Fl_Input2(150, Y, 50, 22, _("Wind Speed"));
	w_severe_wx_wind_speed->align(FL_ALIGN_RIGHT);
	w_severe_wx_wind_speed->tooltip(_("Enter wind speed"));
	w_severe_wx_wind_speed->callback((Fl_Callback*)severe_wx_changed);

	w_severe_wx_measured = new Fl_Check_Button(350, Y, 50, 22, _("Meas'"));
	w_severe_wx_measured->tooltip(_("Winds were measured"));
	w_severe_wx_measured->value(0);
	w_severe_wx_measured->callback((Fl_Callback*)cb_severe_wx_measured);

	w_severe_wx_estimated = new Fl_Check_Button(425, Y, 50, 22, _("Est'"));
	w_severe_wx_estimated->tooltip(_("Winds are estimated"));
	w_severe_wx_estimated->value(1);
	w_severe_wx_estimated->callback((Fl_Callback*)cb_severe_wx_estimated);

	Y += 25;
	w_severe_wx_flood = new Fl_Check_Button(50, Y, 80, 22, _("Flood"));
	w_severe_wx_flood->tooltip(_("Report flooding"));
	w_severe_wx_flood->callback((Fl_Callback*)severe_wx_changed);

	Y += 25;
	w_severe_wx_flash_flood = new Fl_Check_Button(50, Y, 80, 22, _("Flash Flood"));
	w_severe_wx_flash_flood->tooltip(_("Report flash flooding"));
	w_severe_wx_flash_flood->callback((Fl_Callback*)severe_wx_changed);

	w_severe_wx_dmg_yes = new Fl_Check_Button(350, Y, 22, 22,
		_("Any damage?   Yes "));
	w_severe_wx_dmg_yes->align(FL_ALIGN_LEFT);
	w_severe_wx_dmg_yes->tooltip("");
	w_severe_wx_dmg_yes->callback((Fl_Callback*)cb_dmg_yes);

	w_severe_wx_dmg_no = new Fl_Check_Button(400, Y, 22, 22,
		_("No "));
	w_severe_wx_dmg_no->align(FL_ALIGN_LEFT);
	w_severe_wx_dmg_no->tooltip("");
	w_severe_wx_dmg_no->value(1);
	w_severe_wx_dmg_no->callback((Fl_Callback*)cb_dmg_no);

	Y += 25;
	w_severe_wx_other = new Fl_Check_Button(50, Y, 80, 22, _("Other"));
	w_severe_wx_other->tooltip(_("Report other in narrative"));
	w_severe_wx_other->callback((Fl_Callback*)severe_wx_changed);

	w_severe_wx_inj_yes = new Fl_Check_Button(350, Y, 22, 22,
		_("Any injuries?   Yes "));
	w_severe_wx_inj_yes->align(FL_ALIGN_LEFT);
	w_severe_wx_inj_yes->tooltip("");
	w_severe_wx_inj_yes->callback((Fl_Callback*)cb_inj_yes);

	w_severe_wx_inj_no = new Fl_Check_Button(400, Y, 22, 22,
		_("No "));
	w_severe_wx_inj_no->align(FL_ALIGN_LEFT);
	w_severe_wx_inj_no->tooltip("");
	w_severe_wx_inj_no->value(1);
	w_severe_wx_inj_no->callback((Fl_Callback*)cb_inj_no);

	tab_severe_wx_1->end();

	Y = tab_top;
	tab_severe_wx_2 = new Fl_Group(0, Y+25, 570, 360, "Narrative");
	tab_severe_wx_2->begin();
	Y += 35;
	w_severe_wx_narrative = new FTextEdit(5, Y, 560, 340, _(""));

	tab_severe_wx_2->end();

	tab_severe_wx->end();

	set_severe_wx_combos();

	tab_severe_wx->hide();

};

