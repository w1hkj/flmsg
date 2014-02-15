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

Fl_Group	*tab_wxhc = (Fl_Group *)0;
Fl_Tabs		*tab_wxhc_type = (Fl_Tabs *)0;

Fl_Group	*tab_wxhc_1 = (Fl_Group *)0;

Fl_Input2	*w_wxhc_rptsta;
Fl_Input2	*w_wxhc_email;
Fl_Input2	*w_wxhc_phone;
Fl_Input2	*w_wxhc_addr;
Fl_Input2	*w_wxhc_city;
Fl_Input2	*w_wxhc_state;
Fl_Input2	*w_wxhc_country;
Fl_Input2	*w_wxhc_lat;
Fl_Input2	*w_wxhc_long;
Fl_Input2	*w_wxhc_date;
Fl_Input2	*w_wxhc_time;
Fl_Check_Button *w_wxhc_meas;
Fl_Check_Button *w_wxhc_est;
Fl_Input2	*w_wxhc_wind_speed;
Fl_ListBox	*w_wxhc_wind_speed_units;
Fl_Input2	*w_wxhc_wind_gusts;
Fl_ListBox	*w_wxhc_wind_gusts_units;
Fl_ListBox	*w_wxhc_wind_dir;
Fl_Input2	*w_wxhc_wind_degrees;
Fl_Input2	*w_wxhc_baro_press;
Fl_ListBox	*w_wxhc_baro_units;

Fl_Group	*tab_wxhc_2 = (Fl_Group *)0;

FTextEdit	*w_wxhc_comments;

//----------------------------------------------------------------------

// widget callbacks & support

//----------------------------------------------------------------------

static void cb_measured(Fl_Check_Button*, void*)
{
	w_wxhc_est->value(!w_wxhc_meas->value());
}

static void cb_estimated(Fl_Check_Button*, void*)
{
	w_wxhc_meas->value(!w_wxhc_est->value());
}

void wxhc_changed(Fl_Widget *, void *)
{
	estimate();
}

void create_wxhc_tab()
{
	int Y = tab_top;
	tab_wxhc = new Fl_Group(0, Y, 570, 390);
	tab_wxhc->begin();
	tab_wxhc->align(FL_ALIGN_TOP);


	tab_wxhc_type = new Fl_Tabs(0, Y+2, 570, 387);
	tab_wxhc_type->selection_color((Fl_Color)246);

	tab_wxhc_1 = new Fl_Group(0, Y+25, 570, 360, _("Report"));
	tab_wxhc_1->begin();

	Y += 35;
	w_wxhc_rptsta = new Fl_Input2(150, Y, 250, 22, _("Reporting Station"));
	w_wxhc_rptsta->tooltip(_("Amateur Radio Callsign or First & Last Name"));
	w_wxhc_rptsta->callback(wxhc_changed);
	w_wxhc_rptsta->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_email = new Fl_Input2(150, Y, 250, 22, _("Email address"));
	w_wxhc_email->tooltip("");
	w_wxhc_email->callback(wxhc_changed);
	w_wxhc_email->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_phone = new Fl_Input2(150, Y, 250, 22, _("Phone number"));
	w_wxhc_phone->tooltip("");
	w_wxhc_phone->callback(wxhc_changed);
	w_wxhc_phone->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_addr = new Fl_Input2(150, Y, 400, 22, _("Street address"));
	w_wxhc_addr->tooltip("");
	w_wxhc_addr->callback(wxhc_changed);
	w_wxhc_addr->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_city = new Fl_Input2(150, Y, 250, 22, _("city"));
	w_wxhc_city->tooltip("");
	w_wxhc_city->callback(wxhc_changed);
	w_wxhc_city->when(FL_WHEN_CHANGED);

	w_wxhc_state = new Fl_Input2(450, Y, 100, 22, _("State"));
	w_wxhc_state->tooltip("");
	w_wxhc_state->callback(wxhc_changed);
	w_wxhc_state->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_country = new Fl_Input2(150, Y, 250, 22, _("Country"));
	w_wxhc_country->tooltip("");
	w_wxhc_country->callback(wxhc_changed);
	w_wxhc_country->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_lat = new Fl_Input2(150, Y, 150, 22, _("Latitude"));
	w_wxhc_lat->tooltip(_("Latitude (degrees North)"));
	w_wxhc_lat->callback(wxhc_changed);
	w_wxhc_lat->when(FL_WHEN_CHANGED);

	w_wxhc_long = new Fl_Input2(400, Y, 150, 22, _("Longitude"));
	w_wxhc_long->tooltip(_("Longitude (degrees West)"));
	w_wxhc_long->callback(wxhc_changed);
	w_wxhc_long->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_date = new Fl_Input2(150, Y, 150, 22, _("Date"));
	w_wxhc_date->tooltip(_("Observation date : month-day-year"));
	w_wxhc_date->callback(wxhc_changed);
	w_wxhc_date->when(FL_WHEN_CHANGED);

	w_wxhc_time = new Fl_Input2(400, Y, 150, 22, _("Time"));
	w_wxhc_time->tooltip(_("Observation time : HHMM Z (GMT/UTC preferred)"));
	w_wxhc_time->callback(wxhc_changed);
	w_wxhc_time->when(FL_WHEN_CHANGED);

	Y += 25;
	w_wxhc_meas = new Fl_Check_Button(150, Y, 50, 22, _("Measured"));
	w_wxhc_meas->tooltip(_("Wind speed measured"));
	w_wxhc_meas->callback((Fl_Callback*)cb_measured);

	w_wxhc_est = new Fl_Check_Button(305, Y, 50, 22, _("Estimated"));
	w_wxhc_est->tooltip(_("Wind speed estimated"));
	w_wxhc_est->callback((Fl_Callback*)cb_estimated);

	Y += 25;
	w_wxhc_wind_speed = new Fl_Input2(150, Y, 80, 22, _("Wind speed"));
	w_wxhc_wind_speed->tooltip(_("Sustained wind speed"));
	w_wxhc_wind_speed->callback(wxhc_changed);
	w_wxhc_wind_speed->when(FL_WHEN_CHANGED);

	w_wxhc_wind_speed_units = new Fl_ListBox(230, Y, 80, 22, _(""));
	w_wxhc_wind_speed_units->begin();
	w_wxhc_wind_speed_units->callback(wxhc_changed);
	w_wxhc_wind_speed_units->when(FL_WHEN_RELEASE);
	w_wxhc_wind_speed_units->end();


	Y += 25;
	w_wxhc_wind_gusts = new Fl_Input2(150, Y, 80, 22, _("Wind gust"));
	w_wxhc_wind_gusts->tooltip(_("Less than 1 minute"));
	w_wxhc_wind_gusts->callback(wxhc_changed);
	w_wxhc_wind_gusts->when(FL_WHEN_CHANGED);

	w_wxhc_wind_gusts_units = new Fl_ListBox(230, Y, 80, 22, _(""));
	w_wxhc_wind_gusts_units->begin();
	w_wxhc_wind_gusts_units->callback(wxhc_changed);
	w_wxhc_wind_gusts_units->when(FL_WHEN_RELEASE);
	w_wxhc_wind_gusts_units->end();

	Y += 25;
	w_wxhc_wind_dir = new Fl_ListBox(150, Y, 50, 22, _("Wind direc'"));
	w_wxhc_wind_dir->begin();
	w_wxhc_wind_dir->align(FL_ALIGN_LEFT);
	w_wxhc_wind_dir->callback(wxhc_changed);
	w_wxhc_wind_dir->when(FL_WHEN_RELEASE);
	w_wxhc_wind_dir->end();

	w_wxhc_wind_degrees = new Fl_Input2(210, Y, 80, 22, _("Degrees"));
	w_wxhc_wind_degrees->align(FL_ALIGN_RIGHT);

	Y += 25;
	w_wxhc_baro_press = new Fl_Input2(150, Y, 80, 22, _("Baro Press"));
	w_wxhc_baro_press->tooltip(_("Must be measured with calibrated barometer"));
	w_wxhc_baro_press->align(FL_ALIGN_LEFT);
	w_wxhc_baro_press->callback(wxhc_changed);
	w_wxhc_baro_press->when(FL_WHEN_CHANGED);

	w_wxhc_baro_units = new Fl_ListBox(230, Y, 100, 22, _(""));
	w_wxhc_baro_units->begin();
	w_wxhc_baro_units->when(FL_WHEN_RELEASE);
	w_wxhc_baro_units->callback(wxhc_changed);
	w_wxhc_baro_units->end();

	tab_wxhc_1->end();

	Y = tab_top;
	tab_wxhc_2 = new Fl_Group(0, Y+25, 570, 360, _("Comments"));
	Y += 35;
	w_wxhc_comments = new FTextEdit(5, Y, 560, 340, _(""));

	tab_wxhc_2->end();

	tab_wxhc->end();

	set_nhc_wx_combos();

	tab_wxhc->hide();

};

