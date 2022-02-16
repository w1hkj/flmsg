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
#include "fileselect.h"
#include "calendar.h"
#include "wx_strings.h"

Fl_Group	*tab_storm = (Fl_Group *)0;
Fl_Tabs		*tab_storm_type = (Fl_Tabs *)0;

Fl_Group	*tab_storm_1 = (Fl_Group *)0;

Fl_DateInput	*w_storm_date = (Fl_DateInput *)0;
Fl_Input2	*w_storm_time = (Fl_Input2 *)0;
Fl_Button	*w_storm_btn_time = (Fl_Button *)0;
Fl_ListBox *w_storm_zone = (Fl_ListBox *)0;

Fl_ListBox	*w_storm_state = (Fl_ListBox *)0;
Fl_ListBox	*w_storm_county = (Fl_ListBox *)0;
Fl_Input2	*w_storm_location = (Fl_Input2 *)0;

Fl_Button	*use_storm_default = (Fl_Button *)0;
Fl_Button	*make_storm_default = (Fl_Button *)0;

Fl_Check_Button *w_storm_tornado = (Fl_Check_Button *)0;
Fl_ListBox		*w_storm_tornado_cat = (Fl_ListBox *)0;

Fl_Check_Button *w_storm_hail = (Fl_Check_Button *)0;
Fl_ListBox	*w_storm_hail_size = (Fl_ListBox *)0;

Fl_Check_Button *w_storm_wind = (Fl_Check_Button *)0;
Fl_ListBox		*w_storm_wind_cat = (Fl_ListBox *)0;;

Fl_Check_Button *w_storm_flood = (Fl_Check_Button *)0;
Fl_ListBox		*w_storm_flood_cat = (Fl_ListBox *)0;

Fl_Check_Button *w_storm_damage = (Fl_Check_Button *)0;
Fl_ListBox		*w_storm_damage_cat = (Fl_ListBox *)0;

Fl_Check_Button *w_storm_snow = (Fl_Check_Button *)0;
Fl_ListBox		*w_storm_snow_tot = (Fl_ListBox *)0;
Fl_ListBox		*w_storm_snow_dur = (Fl_ListBox *)0;

Fl_Check_Button *w_storm_f_rain = (Fl_Check_Button *)0;
Fl_ListBox		*w_storm_f_rain_tot = (Fl_ListBox *)0;
Fl_ListBox		*w_storm_f_rain_dur = (Fl_ListBox *)0;

Fl_Check_Button *w_storm_h_rain = (Fl_Check_Button *)0;
Fl_ListBox		*w_storm_h_rain_tot = (Fl_ListBox *)0;
Fl_ListBox		*w_storm_h_rain_dur = (Fl_ListBox *)0;

Fl_Input2	*w_storm_o_name = (Fl_Input2 *)0;
Fl_Input2	*w_storm_o_email = (Fl_Input2 *)0;
Fl_Input2	*w_storm_o_tele = (Fl_Input2 *)0;
Fl_ListBox	*w_storm_o_profile = (Fl_ListBox *)0;

Fl_Group	*tab_storm_2 = (Fl_Group *)0;
FTextEdit	*w_storm_details = (FTextEdit *)0;

//----------------------------------------------------------------------

// widget callbacks & support

//----------------------------------------------------------------------

void set_storm_counties(int ndx)
{
	std::string st = states[ndx];
	size_t p = st.find(',');
	if (p != std::string::npos) {
		st.erase(p+1);
		size_t p1 = counties.find(st);
		size_t p2 = counties.rfind(st);
		std::string cnty = counties.substr(p1+3, p2 - p1 - 3);
		size_t pc = cnty.find(',');
		p1 = 0;
		w_storm_county->clear();
		while (pc != std::string::npos) {
			w_storm_county->add(cnty.substr(p1, pc - p1).c_str());
			p1 = pc + 1;
			pc = cnty.find(',', pc + 1);
		}
	}
	w_storm_county->index(0);
}

static void set_storm_combos()
{
	w_storm_state->clear();
	for (int i = 0; i < numstates; i++) {
		if (i == 0)
			w_storm_state->add("--Select State--");
		else
			w_storm_state->add(states[i].c_str());
	}
	w_storm_state->index(0);

	w_storm_zone->clear();
	for (int i = 0; i < num_us_tzones; i++)
		w_storm_zone->add(us_tzones[i].c_str());
	w_storm_zone->index(0);

	w_storm_flood_cat->clear();
	for (int i = 0; i < num_flood_categories; i++)
		w_storm_flood_cat->add(flood_categories[i].c_str());
	w_storm_flood_cat->index(0);

	w_storm_hail_size->clear();
	for (int i = 0; i < num_hail_size; i++)
		w_storm_hail_size->add(hail_size[i].c_str());
	w_storm_hail_size->index(0);

	w_storm_tornado_cat->clear();
	for (int i = 0; i < num_tornado_categories; i++)
		w_storm_tornado_cat->add(tornado_categories[i].c_str());
	w_storm_tornado_cat->index(0);

	w_storm_wind_cat->clear();
	for (int i = 0; i < num_wind_speeds; i++)
		w_storm_wind_cat->add(wind_speeds[i].c_str());
	w_storm_wind_cat->index(0);

	w_storm_damage_cat->clear();
	for (int i = 0; i < num_damage; i++)
		w_storm_damage_cat->add(damage[i].c_str());
	w_storm_damage_cat->index(0);

	w_storm_snow_dur->clear();
	for (int i = 0; i < num_snow_dur; i++)
		w_storm_snow_dur->add(snow_dur[i].c_str());
	w_storm_snow_dur->index(0);

	w_storm_snow_tot->clear();
	for (int i = 0; i < num_snow_tot; i++)
		w_storm_snow_tot->add(snow_tot[i].c_str());
	w_storm_snow_tot->index(0);

	w_storm_f_rain_dur->clear();
	for (int i = 0; i < num_ice_dur; i++)
		w_storm_f_rain_dur->add(ice_dur[i].c_str());
	w_storm_f_rain_dur->index(0);

	w_storm_f_rain_tot->clear();
	for (int i = 0; i < num_ice_tot; i++)
		w_storm_f_rain_tot->add(ice_tot[i].c_str());
	w_storm_f_rain_tot->index(0);

	w_storm_h_rain_dur->clear();
	for (int i = 0; i < num_rainfall_dur; i++)
		w_storm_h_rain_dur->add(rainfall_dur[i].c_str());
	w_storm_h_rain_dur->index(0);

	w_storm_h_rain_tot->clear();
	for (int i = 0; i < num_rainfall; i++)
		w_storm_h_rain_tot->add(rainfall[i].c_str());
	w_storm_h_rain_tot->index(0);

	w_storm_o_profile->clear();
	for (int i = 0; i < num_profiles; i++)
		w_storm_o_profile->add(profiles[i].c_str());
	w_storm_o_profile->index(0);

	set_storm_counties(0);
}

static void cb_btn_time(Fl_Button*, void*) {
	w_storm_time->value(szTime(7));
}

static void cb_make_storm_default(Fl_Button*, void*)
{
	progStatus.swx_index_default_county = w_storm_county->index();
	progStatus.swx_index_default_state = w_storm_state->index();
	progStatus.swx_default_location = w_storm_location->value();
	progStatus.swx_default_zone = w_storm_zone->value();
	progStatus.swx_default_profile = w_storm_o_profile->value();
}

static void cb_use_storm_default(Fl_Button*, void*)
{
	w_storm_state->index(progStatus.swx_index_default_state);
	set_storm_counties(progStatus.swx_index_default_state);
	w_storm_county->index(progStatus.swx_index_default_county);
	w_storm_location->value(progStatus.swx_default_location.c_str());
	w_storm_zone->value(progStatus.swx_default_zone.c_str());
	w_storm_o_name->value(progStatus.my_name.c_str());
	w_storm_o_tele->value(progStatus.my_tel.c_str());
	w_storm_o_email->value(progStatus.my_email.c_str());
	w_storm_o_profile->value(progStatus.swx_default_profile.c_str());
}

void storm_changed(Fl_Widget *, void *)
{
	estimate();
}

void cb_storm_state(Fl_Widget *, void *)
{
	int n = w_storm_state->index();
	set_storm_counties(n);
	estimate();
}

void cb_flood(Fl_Widget *, void *)
{
	w_storm_flood_cat->index(0);
	if (w_storm_flood->value())
		w_storm_flood_cat->activate();
	else
		w_storm_flood_cat->deactivate();
	estimate();
}

void cb_hail(Fl_Widget *, void *)
{
	w_storm_hail_size->index(0);
	if (w_storm_hail->value())
		w_storm_hail_size->activate();
	else
		w_storm_hail_size->deactivate();
	estimate();
}

void cb_high_wind(Fl_Widget *, void *)
{
	w_storm_wind_cat->index(0);
	if (w_storm_wind->value())
		w_storm_wind_cat->activate();
	else
		w_storm_wind_cat->deactivate();
	estimate();
}

void cb_tornado(Fl_Widget *, void *)
{
	w_storm_tornado_cat->index(0);
	if (w_storm_tornado->value())
		w_storm_tornado_cat->activate();
	else
		w_storm_tornado_cat->deactivate();
	estimate();
}

void cb_damage(Fl_Widget *, void *)
{
	w_storm_damage_cat->index(0);
	if (w_storm_damage->value())
		w_storm_damage_cat->activate();
	else
		w_storm_damage_cat->deactivate();
	estimate();
}

void cb_snow(Fl_Widget *, void *)
{
	w_storm_snow_tot->index(0);
	w_storm_snow_dur->index(0);
	if (w_storm_snow->value()) {
		w_storm_snow_tot->activate();
		w_storm_snow_dur->activate();
	} else {
		w_storm_snow_tot->deactivate();
		w_storm_snow_dur->deactivate();
	}
	estimate();
}

void cb_f_rain(Fl_Widget *, void *)
{
	w_storm_f_rain_tot->index(0);
	w_storm_f_rain_dur->index(0);
	if (w_storm_f_rain->value()) {
		w_storm_f_rain_tot->activate();
		w_storm_f_rain_dur->activate();
	} else {
		w_storm_f_rain_tot->deactivate();
		w_storm_f_rain_dur->deactivate();
	}
	estimate();
}

void cb_h_rain(Fl_Widget *, void *)
{
	w_storm_h_rain_tot->index(0);
	w_storm_h_rain_dur->index(0);
	if (w_storm_h_rain->value()) {
		w_storm_h_rain_tot->activate();
		w_storm_h_rain_dur->activate();
	} else {
		w_storm_h_rain_tot->deactivate();
		w_storm_h_rain_dur->deactivate();
	}
	estimate();
}

void create_storm_tab()
{
	int Y = tab_top;
	tab_storm = new Fl_Group(0, Y, 570, 390, "tab_storm");
	tab_storm->begin();
	tab_storm->copy_label("");
	tab_storm->align(FL_ALIGN_INSIDE);

	tab_storm_type = new Fl_Tabs(0, Y+2, 570, 387, "wx_tabs");
	tab_storm_type->selection_color((Fl_Color)246);
	tab_storm_type->copy_label("");
	tab_storm_type->align(FL_ALIGN_INSIDE);

	tab_storm_1 = new Fl_Group(0, Y+25, 570, 360, "Report");
	tab_storm_1->begin();

	Y += 35;

	w_storm_date = new Fl_DateInput(70, Y, 140, 22, _("Date"));
	w_storm_date->tooltip(_("Observation date : month/day/year"));
	w_storm_date->align(FL_ALIGN_LEFT);
	w_storm_date->box(FL_DOWN_BOX);
	w_storm_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
	w_storm_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
	w_storm_date->labeltype(FL_NORMAL_LABEL);
	w_storm_date->labelfont(0);
	w_storm_date->labelsize(14);
	w_storm_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	w_storm_date->when(FL_WHEN_CHANGED);
	w_storm_date->callback(storm_changed);
	w_storm_date->local_datetime();

	w_storm_time = new Fl_Input2(250, Y, 60, 22, _("Time"));
	w_storm_time->tooltip(_("Observation time : HHMM"));
	w_storm_time->align(FL_ALIGN_LEFT);
	w_storm_time->when(FL_WHEN_CHANGED);
	w_storm_time->callback(storm_changed);

	w_storm_btn_time = new Fl_Button(312, Y, 22, 22, _("..."));
	w_storm_btn_time->tooltip(_("Current local time"));
	w_storm_btn_time->callback((Fl_Callback*)cb_btn_time);

	w_storm_zone = new Fl_ListBox(335, Y, 80, 22, "");
	w_storm_zone->begin();
	w_storm_zone->align(FL_ALIGN_TOP || FL_ALIGN_INSIDE);
	w_storm_zone->tooltip(_("Time Zone, ie: EDT"));
	w_storm_zone->when(FL_WHEN_CHANGED);
	w_storm_zone->align(FL_ALIGN_RIGHT);
	for (int n = 0; n < num_us_tzones; n++)
		w_storm_zone->add(us_tzones[n].c_str());
	w_storm_zone->callback(storm_changed);
	w_storm_zone->end();

	Y += 25;
	w_storm_state = new Fl_ListBox(70, Y, 200, 22, _("State"));
	w_storm_state->begin();
	w_storm_state->tooltip(_("Select state / territory"));
	w_storm_state->align(FL_ALIGN_LEFT);
	w_storm_state->when(FL_WHEN_CHANGED);
	w_storm_state->callback((Fl_Callback*)cb_storm_state);
	w_storm_state->end();

	w_storm_county = new Fl_ListBox(325, Y, 235, 22, _("County"));
	w_storm_county->begin();
	w_storm_county->tooltip(_("Select county"));
	w_storm_county->align(FL_ALIGN_LEFT);
	w_storm_county->when(FL_WHEN_CHANGED);
	w_storm_county->callback((Fl_Callback*)storm_changed);
	w_storm_county->end();

	Y += 25;
	int y1 = Y;
	w_storm_location = new Fl_Input2(70, Y, 200, 22, _("Location"));
	w_storm_location->tooltip(_("Enter location/town"));
	w_storm_location->align(FL_ALIGN_LEFT);
	w_storm_location->when(FL_WHEN_CHANGED);
	w_storm_location->callback((Fl_Callback*)storm_changed);

// flood
	Y += 35;
	w_storm_flood = new Fl_Check_Button(20, Y, 180, 22, _("Flood"));
	w_storm_flood->tooltip(_("Report flooding"));
	w_storm_flood->when(FL_WHEN_CHANGED);
	w_storm_flood->callback((Fl_Callback*)cb_flood);

	w_storm_flood_cat = new Fl_ListBox(200, Y, 365, 22, "");
	w_storm_flood_cat->tooltip(_("Select a flooding category"));
	w_storm_flood_cat->when(FL_WHEN_CHANGED);
	w_storm_flood_cat->callback((Fl_Callback*)storm_changed);
	w_storm_flood_cat->deactivate();
//hail
	Y += 25;
	w_storm_hail = new Fl_Check_Button(20, Y, 180, 22, _("Hail"));
	w_storm_hail->tooltip(_("Report incidence of hail"));
	w_storm_hail->when(FL_WHEN_CHANGED);
	w_storm_hail->callback((Fl_Callback*)cb_hail);

	w_storm_hail_size = new Fl_ListBox(200, Y, 365, 22, "");
	w_storm_hail_size->tooltip(_("Select a Hail size"));
	w_storm_hail_size->when(FL_WHEN_CHANGED);
	w_storm_hail_size->callback((Fl_Callback*)storm_changed);
	w_storm_hail_size->deactivate();
//high speed wind
	Y += 25;
	w_storm_wind = new Fl_Check_Button(20, Y, 180, 22, _("High Wind Speed"));
	w_storm_wind->tooltip(_("Report high winds"));
	w_storm_wind->when(FL_WHEN_CHANGED);
	w_storm_wind->callback((Fl_Callback*)cb_high_wind);

	w_storm_wind_cat = new Fl_ListBox(200, Y, 365, 22, "");
	w_storm_wind_cat->tooltip(_("Select a wind speed"));
	w_storm_wind_cat->when(FL_WHEN_CHANGED);
	w_storm_wind_cat->callback((Fl_Callback*)storm_changed);
	w_storm_wind_cat->deactivate();
//tornado/funnel cloud
	Y += 25;
	w_storm_tornado = new Fl_Check_Button(20, Y, 180, 22, _("Tornado/Funnel cloud"));
	w_storm_tornado->tooltip(_("Report tornado sighting"));
	w_storm_tornado->when(FL_WHEN_CHANGED);
	w_storm_tornado->callback((Fl_Callback*)cb_tornado);

	w_storm_tornado_cat = new Fl_ListBox(200, Y, 365, 22, "");
	w_storm_tornado_cat->tooltip(_("Select a report"));
	w_storm_tornado_cat->when(FL_WHEN_CHANGED);
	w_storm_tornado_cat->callback((Fl_Callback*)storm_changed);
	w_storm_tornado_cat->deactivate();
//wind damage
	Y += 25;
	w_storm_damage = new Fl_Check_Button(20, Y, 180, 22, _("Wind Damage?"));
	w_storm_damage->tooltip("Report wind damage");
	w_storm_damage->when(FL_WHEN_CHANGED);
	w_storm_damage->callback((Fl_Callback*)cb_damage);

	w_storm_damage_cat = new Fl_ListBox(200, Y, 365, 22, "");
	w_storm_damage_cat->tooltip(_("Select a Damage Desc'"));
	w_storm_damage_cat->when(FL_WHEN_CHANGED);
	w_storm_damage_cat->callback((Fl_Callback*)storm_changed);
	w_storm_damage_cat->deactivate();
//snow
	Y += 25;
	w_storm_snow = new Fl_Check_Button(20, Y, 180, 22, _("Snow"));
	w_storm_snow->tooltip("Report Snowfall");
	w_storm_snow->when(FL_WHEN_CHANGED);
	w_storm_snow->callback((Fl_Callback*)cb_snow);

	w_storm_snow_tot = new Fl_ListBox(200, Y, 180, 22, "");
	w_storm_snow_tot->tooltip(_("Select a snow tot'"));
	w_storm_snow_tot->when(FL_WHEN_CHANGED);
	w_storm_snow_tot->callback((Fl_Callback*)storm_changed);
	w_storm_snow_tot->deactivate();

	w_storm_snow_dur = new Fl_ListBox(385, Y, 180, 22, "");
	w_storm_snow_dur->tooltip(_("Select a snow total"));
	w_storm_snow_dur->when(FL_WHEN_CHANGED);
	w_storm_snow_dur->callback((Fl_Callback*)storm_changed);
	w_storm_snow_dur->deactivate();

//freezing rain/icing
	Y += 25;
	w_storm_f_rain = new Fl_Check_Button(20, Y, 180, 22, _("Freezing Rain/Icing"));
	w_storm_f_rain->tooltip("Report freezing rain / ice");
	w_storm_f_rain->when(FL_WHEN_CHANGED);
	w_storm_f_rain->callback((Fl_Callback*)cb_f_rain);

	w_storm_f_rain_tot = new Fl_ListBox(200, Y, 180, 22, "");
	w_storm_f_rain_tot->tooltip(_("Select an ice total"));
	w_storm_f_rain_tot->when(FL_WHEN_CHANGED);
	w_storm_f_rain_tot->callback((Fl_Callback*)storm_changed);
	w_storm_f_rain_tot->deactivate();

	w_storm_f_rain_dur = new Fl_ListBox(385, Y, 180, 22, "");
	w_storm_f_rain_dur->tooltip(_("Select a duration"));
	w_storm_f_rain_dur->when(FL_WHEN_CHANGED);
	w_storm_f_rain_dur->callback((Fl_Callback*)storm_changed);
	w_storm_f_rain_dur->deactivate();
//heavy rain
	Y += 25;
	w_storm_h_rain = new Fl_Check_Button(20, Y, 180, 22, _("Heavy Rain"));
	w_storm_h_rain->tooltip("Report heavy rain");
	w_storm_h_rain->when(FL_WHEN_CHANGED);
	w_storm_h_rain->callback((Fl_Callback*)cb_h_rain);

	w_storm_h_rain_tot = new Fl_ListBox(200, Y, 180, 22, "");
	w_storm_h_rain_tot->tooltip(_("Select rain total"));
	w_storm_h_rain_tot->when(FL_WHEN_CHANGED);
	w_storm_h_rain_tot->callback((Fl_Callback*)storm_changed);
	w_storm_h_rain_tot->deactivate();

	w_storm_h_rain_dur = new Fl_ListBox(385, Y, 180, 22, "");
	w_storm_h_rain_dur->tooltip(_("Select a duration"));
	w_storm_h_rain_dur->when(FL_WHEN_CHANGED);
	w_storm_h_rain_dur->callback((Fl_Callback*)storm_changed);
	w_storm_h_rain_dur->deactivate();
//contact information
	Y += 35;
	w_storm_o_name = new Fl_Input2(70, Y, 240, 22, _("Name"));
	w_storm_o_name->when(FL_WHEN_CHANGED);
	w_storm_o_name->align(FL_ALIGN_LEFT);

	w_storm_o_tele = new Fl_Input2(380, Y, 185, 22, _("Phone"));
	w_storm_o_tele->when(FL_WHEN_CHANGED);
	w_storm_o_tele->align(FL_ALIGN_LEFT);

	Y += 25;
	w_storm_o_email = new Fl_Input2(70, Y, 240, 22, _("Email"));
	w_storm_o_email->when(FL_WHEN_CHANGED);
	w_storm_o_email->align(FL_ALIGN_LEFT);

	w_storm_o_profile = new Fl_ListBox(380, Y, 185, 22, _("Profile"));
	w_storm_o_profile->begin();
	w_storm_o_profile->align(FL_ALIGN_LEFT);
	w_storm_o_profile->tooltip(_("Select a profile"));
	w_storm_o_profile->when(FL_WHEN_CHANGED);
	w_storm_o_profile->callback((Fl_Callback*)storm_changed);
	w_storm_o_profile->end();

	make_storm_default = new Fl_Button(415, y1, 70, 24, _("Store"));
	make_storm_default->tooltip(_("Store state/county/location\ntime-zone\nname, email, tele, profile\nas default"));
	make_storm_default->callback((Fl_Callback*)cb_make_storm_default);

	use_storm_default = new Fl_Button(490, y1, 70, 24, _("Default"));
	use_storm_default->tooltip(_("Use state/county/location\ntime-zone\nname, email, tele, profile\nas default"));
	use_storm_default->callback((Fl_Callback*)cb_use_storm_default);
	tab_storm_1->end();

	Y = tab_top;
	tab_storm_2 = new Fl_Group(0, Y+25, 570, 360, _("Details"));
	tab_storm_2->begin();

	Y += 35;
	w_storm_details = new FTextEdit(5, Y, 560, 340, _(""));
	w_storm_details->when(FL_WHEN_RELEASE);
	w_storm_details->callback((Fl_Callback*)storm_changed);

	tab_storm_2->end();

	tab_storm->end();

	set_storm_combos();

	tab_storm->hide();

};

