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
Fl_ComboBox	*w_wxhc_wind_speed_units;
Fl_Input2	*w_wxhc_wind_gusts;
Fl_ComboBox	*w_wxhc_wind_gusts_units;
Fl_ComboBox	*w_wxhc_wind_dir;
Fl_Input2	*w_wxhc_wind_degrees;
Fl_Input2	*w_wxhc_baro_press;
Fl_ComboBox	*w_wxhc_baro_units;

Fl_Group	*tab_wxhc_2 = (Fl_Group *)0;

FTextEdit	*w_wxhc_comments;

//----------------------------------------------------------------------

// widget callbacks & support

//----------------------------------------------------------------------
static void cb_btn_date(Fl_Button*, void*) {
  w_wxhc_date->value(szDate());
}

static void cb_measured(Fl_Check_Button*, void*)
{
	w_wxhc_est->value(!w_wxhc_meas->value());
}

static void cb_estimated(Fl_Check_Button*, void*)
{
	w_wxhc_meas->value(!w_wxhc_est->value());
}

void create_wxhc_tab()
{
	int Y = tab_top;
	tab_wxhc = new Fl_Group(0, Y, 570, 390);
	tab_wxhc->align(FL_ALIGN_TOP);

	tab_wxhc_type = new Fl_Tabs(0, Y+2, 570, 387);
	tab_wxhc_type->selection_color((Fl_Color)246);

	tab_wxhc_1 = new Fl_Group(0, Y+25, 570, 360, _("Report"));

	Y += 35;
	w_wxhc_rptsta = new Fl_Input2(150, Y, 250, 22, _("Reporting Station"));
	w_wxhc_rptsta->tooltip(_("Amateur Radio Callsign or First & Last Name"));
	Y += 25;
	w_wxhc_email = new Fl_Input2(150, Y, 250, 22, _("Email address"));
	w_wxhc_email->tooltip("");
	Y += 25;
	w_wxhc_phone = new Fl_Input2(150, Y, 250, 22, _("Phone number"));
	w_wxhc_phone->tooltip("");
	Y += 25;
	w_wxhc_addr = new Fl_Input2(150, Y, 400, 22, _("Street address"));
	w_wxhc_addr->tooltip("");
	Y += 25;
	w_wxhc_city = new Fl_Input2(150, Y, 250, 22, _("city"));
	w_wxhc_city->tooltip("");
	w_wxhc_state = new Fl_Input2(450, Y, 100, 22, _("State"));
	w_wxhc_state->tooltip("");
	Y += 25;
	w_wxhc_country = new Fl_Input2(150, Y, 250, 22, _("Country"));
	w_wxhc_country->tooltip("");
	Y += 25;
	w_wxhc_lat = new Fl_Input2(150, Y, 150, 22, _("Latitude"));
	w_wxhc_lat->tooltip(_("Latitude (degrees North)"));
	w_wxhc_long = new Fl_Input2(400, Y, 150, 22, _("Longitude"));
	w_wxhc_long->tooltip(_("Longitude (degrees West)"));
	Y += 25;
	w_wxhc_date = new Fl_Input2(150, Y, 150, 22, _("Date"));
	w_wxhc_date->tooltip(_("Observation date : month-day-year"));
	w_wxhc_time = new Fl_Input2(400, Y, 150, 22, _("Time"));
	w_wxhc_time->tooltip(_("Observation time : HHMM Z (GMT/UTC preferred)"));
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
	w_wxhc_wind_speed_units = new Fl_ComboBox(230, Y, 80, 22, _(""));
	Y += 25;
	w_wxhc_wind_gusts = new Fl_Input2(150, Y, 80, 22, _("Wind gust"));
	w_wxhc_wind_gusts->tooltip(_("Less than 1 minute"));
	w_wxhc_wind_gusts_units = new Fl_ComboBox(230, Y, 80, 22, _(""));
	Y += 25;
	w_wxhc_wind_dir = new Fl_ComboBox(150, Y, 50, 22, _("Wind direc'"));
	w_wxhc_wind_dir->align(FL_ALIGN_LEFT);
	w_wxhc_wind_degrees = new Fl_Input2(210, Y, 80, 22, _("Degrees"));
	w_wxhc_wind_degrees->align(FL_ALIGN_RIGHT);
	Y += 25;
	w_wxhc_baro_press = new Fl_Input2(150, Y, 80, 22, _("Baro Press"));
	w_wxhc_baro_press->tooltip(_("Must be measured with calibrated barometer"));
	w_wxhc_baro_units = new Fl_ComboBox(230, Y, 100, 22, _(""));

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

