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

Fl_Group	*tab_redx_5739 = (Fl_Group *)0;
Fl_Tabs		*tab_redx_5739_type = (Fl_Tabs *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_redx_5739_1 = (Fl_Group *)0;
Fl_Group	*tab_redx_5739_2 = (Fl_Group *)0;

Fl_Input2	*rdx_5739_nbr = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739_name = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739_state = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739_cnty = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739_city = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739_date = (Fl_Input2 *)0;
Fl_Button	*btn_5739_date = (Fl_Button *)0;
Fl_Input2	*rdx_5739_street = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739_georef = (Fl_Input2 *)0;
FTextEdit	*rdx_5739_add_info = (FTextEdit *)0;
Fl_Input2	*rdx_5739_worker = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739_supervisor = (Fl_Input2 *)0;

Fl_Input2	*rdx_sf_destroyed = (Fl_Input2 *)0;
Fl_Input2	*rdx_sf_major = (Fl_Input2 *)0;
Fl_Input2	*rdx_sf_minor = (Fl_Input2 *)0;
Fl_Input2	*rdx_sf_affected = (Fl_Input2 *)0;
Fl_Input2	*rdx_sf_inaccessible = (Fl_Input2 *)0;

Fl_Input2	*rdx_mh_destroyed = (Fl_Input2 *)0;
Fl_Input2	*rdx_mh_major = (Fl_Input2 *)0;
Fl_Input2	*rdx_mh_minor = (Fl_Input2 *)0;
Fl_Input2	*rdx_mh_affected = (Fl_Input2 *)0;
Fl_Input2	*rdx_mh_inaccessible = (Fl_Input2 *)0;

Fl_Input2	*rdx_ap_destroyed = (Fl_Input2 *)0;
Fl_Input2	*rdx_ap_major = (Fl_Input2 *)0;
Fl_Input2	*rdx_ap_minor = (Fl_Input2 *)0;
Fl_Input2	*rdx_ap_affected = (Fl_Input2 *)0;
Fl_Input2	*rdx_ap_inaccessible = (Fl_Input2 *)0;

Fl_Input2	*redx_5739_house_nbr[10];
Fl_Input2	*redx_5739_apt_nbr[10];
Fl_Input2	*redx_5739_desc[10];
Fl_Input2	*redx_5739_nam[10];
Fl_Input2	*redx_5739_destroyed[10];
Fl_Input2	*redx_5739_major[10];
Fl_Input2	*redx_5739_minor[10];
Fl_Input2	*redx_5739_affected[10];
Fl_Input2	*redx_5739_inaccessible[10];
Fl_Input2	*redx_5739_floors[10];
Fl_Input2	*redx_5739_basement[10];
Fl_Input2	*redx_5739_waterlevel[10];
Fl_Input2	*redx_5739_basement_water[10];
Fl_Input2	*redx_5739_electricity[10];
Fl_Input2	*redx_5739_occupancy[10];
Fl_Input2	*redx_5739_OR[10];
Fl_Input2	*redx_5739_901[10];

static void cb_btn_5739_date(Fl_Button*, void*) {
  rdx_5739_date->value(szDate(progStatus.dtformat));
}

void redx_5739_compute(Fl_Widget * w, void *)
{
	int stotal, mtotal, atotal;
	static char strtotal[12];

	stotal = mtotal = atotal = 0;
	strtotal[0] = 0;
	for (int i = 0; i < 10; i++) {
		if (redx_5739_destroyed[i]->value()[0] == 'S') stotal++;
		if (redx_5739_destroyed[i]->value()[0] == 'M') mtotal++;
		if (redx_5739_destroyed[i]->value()[0] == 'A') atotal++;
	}
	if (stotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", stotal);
		rdx_sf_destroyed->value(strtotal);
	} else rdx_sf_destroyed->value("");
	if (mtotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", mtotal);
		rdx_mh_destroyed->value(strtotal);
	} else rdx_mh_destroyed->value("");
	if (atotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", atotal);
		rdx_ap_destroyed->value(strtotal);
	} else rdx_ap_destroyed->value("");

	stotal = mtotal = atotal = 0;
	strtotal[0] = 0;
	for (int i = 0; i < 10; i++) {
		if (redx_5739_major[i]->value()[0] == 'S') stotal++;
		if (redx_5739_major[i]->value()[0] == 'M') mtotal++;
		if (redx_5739_major[i]->value()[0] == 'A') atotal++;
	}
	if (stotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", stotal);
		rdx_sf_major->value(strtotal);
	} else rdx_sf_major->value("");
	if (mtotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", mtotal);
		rdx_mh_major->value(strtotal);
	} else rdx_mh_major->value("");
	if (atotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", atotal);
		rdx_ap_major->value(strtotal);
	} else rdx_ap_major->value("");

	stotal = mtotal = atotal = 0;
	strtotal[0] = 0;
	for (int i = 0; i < 10; i++) {
		if (redx_5739_minor[i]->value()[0] == 'S') stotal++;
		if (redx_5739_minor[i]->value()[0] == 'M') mtotal++;
		if (redx_5739_minor[i]->value()[0] == 'A') atotal++;
	}
	if (stotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", stotal);
		rdx_sf_minor->value(strtotal);
	} else rdx_sf_minor->value("");
	if (mtotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", mtotal);
		rdx_mh_minor->value(strtotal);
	} else rdx_mh_minor->value("");
	if (atotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", atotal);
		rdx_ap_minor->value(strtotal);
	} else rdx_ap_minor->value("");

	stotal = mtotal = atotal = 0;
	strtotal[0] = 0;
	for (int i = 0; i < 10; i++) {
		if (redx_5739_affected[i]->value()[0] == 'S') stotal++;
		if (redx_5739_affected[i]->value()[0] == 'M') mtotal++;
		if (redx_5739_affected[i]->value()[0] == 'A') atotal++;
	}
	if (stotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", stotal);
		rdx_sf_affected->value(strtotal);
	} else rdx_sf_affected->value("");
	if (mtotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", mtotal);
		rdx_mh_affected->value(strtotal);
	} else rdx_mh_affected->value("");
	if (atotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", atotal);
		rdx_ap_affected->value(strtotal);
	} else rdx_ap_affected->value("");

	stotal = mtotal = atotal = 0;
	strtotal[0] = 0;
	for (int i = 0; i < 10; i++) {
		if (redx_5739_inaccessible[i]->value()[0] == 'S') stotal++;
		if (redx_5739_inaccessible[i]->value()[0] == 'M') mtotal++;
		if (redx_5739_inaccessible[i]->value()[0] == 'A') atotal++;
	}
	if (stotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", stotal);
		rdx_sf_inaccessible->value(strtotal);
	} else rdx_sf_inaccessible->value("");
	if (mtotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", mtotal);
		rdx_mh_inaccessible->value(strtotal);
	} else rdx_mh_inaccessible->value("");
	if (atotal) {
		snprintf(strtotal, sizeof(strtotal), "%d", atotal);
		rdx_ap_inaccessible->value(strtotal);
	} else rdx_ap_inaccessible->value("");

}

static void redx_5739_dmgtype(Fl_Widget * w, void * n)
{
	Fl_Input2 * me = (Fl_Input2 *)w;
	int tnbr = (int)reinterpret_cast<long>(n);
	char cdmg = me->value()[0];
	redx_5739_destroyed[tnbr]->value("");
	redx_5739_major[tnbr]->value("");
	redx_5739_minor[tnbr]->value("");
	redx_5739_affected[tnbr]->value("");
	redx_5739_inaccessible[tnbr]->value("");
	switch (cdmg) {
		case 's': case 'S': me->value("S"); break;
		case 'm': case 'M': me->value("M"); break;
		case 'a': case 'A': me->value("A"); break;
		default: break;
	}
	redx_5739_compute(w, NULL);
}

static void redx_5739_yn(Fl_Widget *w, void *)
{
	Fl_Input2 *me = (Fl_Input2 *)w;
	if (me->value()[0]) {
		switch (me->value()[0]) {
			case 'y': case 'Y': me->value("Y"); break;
			case 'n': case 'N':
			default:
				me->value("N");
		}
	} else me->value("");
}

static void redx_5739_or(Fl_Widget *w, void *)
{
	Fl_Input2 *me = (Fl_Input2 *)w;
	if (me->value()[0]) {
		switch (me->value()[0]) {
			case 'o': case 'O': me->value("O"); break;
			default:
				me->value("");
		}
	} else me->value("");
}

static void redx_5739_inches(Fl_Widget *w, void *)
{
	Fl_Input2 *me = (Fl_Input2 *)w;
	int val = 0;
	if (me->value()[0] != 0)
		sscanf(me->value(), "%d", &val);
	if (val) {
		static char sval[5];
		sval[0] = 0;
		snprintf(sval, sizeof(sval), "%d", val);
		me->value(sval);
	} else me->value("");
}

static void redx_5739_occ_check(Fl_Widget *w, void *)
{
	Fl_Input2 *me = (Fl_Input2 *)w;
	if (me->value()[0]) {
		switch (me->value()[0]) {
			case 'o': case 'O': me->value("O"); break;
			case 'r': case 'R': me->value("R"); break;
			case 's': case 'S': me->value("S"); break;
			default:
				me->value("");
		}
	} else me->value("");
}

void create_redx_5739()
{
	int Y = tab_top;
	tab_redx_5739 = new Fl_Group(0, Y, 570, 390);
	tab_redx_5739->align(FL_ALIGN_TOP);

	tab_redx_5739_type = new Fl_Tabs(0, Y, 570, 387);
	tab_redx_5739_type->selection_color((Fl_Color)246);

	tab_redx_5739_1 = new Fl_Group(0, Y+=25, 570, 360, _("5739-1"));

	rdx_5739_nbr = new Fl_Input2(100, Y+=8, 100, 24, "DR #");
	rdx_5739_nbr->tooltip(_("Damage report record number"));
	rdx_5739_name = new Fl_Input2(100, Y+=26, 300, 24, "DR Name");
	rdx_5739_name->tooltip("");
	rdx_5739_state = new Fl_Input2(100, Y+=26, 300, 24, "State");
	rdx_5739_state->tooltip("");
	rdx_5739_cnty = new Fl_Input2(100, Y+=26, 300, 24, "County");
	rdx_5739_cnty->tooltip("");
	rdx_5739_city = new Fl_Input2(100, Y+=26, 300, 24, "City");
	rdx_5739_city->tooltip("");
	rdx_5739_street = new Fl_Input2(100, Y+=26, 300, 24, "Street");
	rdx_5739_street->tooltip("");
	rdx_5739_georef = new Fl_Input2(100, Y+=26, 400, 24, "Geo' Ref'");
	rdx_5739_georef->tooltip(_("geographic reference, GPS lat/lon etc."));

	rdx_5739_date = new Fl_Input2(100, Y+=26, 200, 24, "Date");
	rdx_5739_date->tooltip("");

	btn_5739_date = new Fl_Button(302, Y, 24, 24, _("..."));
	btn_5739_date->tooltip(_("Set today"));
	btn_5739_date->callback((Fl_Callback*)cb_btn_5739_date);

	rdx_5739_add_info = new FTextEdit(4, Y+=40, 560, 60, "Add' Info");
	rdx_5739_add_info->type(FL_MULTILINE_INPUT);
	rdx_5739_add_info->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_5739_add_info->tooltip("");
	rdx_5739_worker = new Fl_Input2(100, Y+=62, 300, 24, "Worker");
	rdx_5739_worker->tooltip("");
	rdx_5739_supervisor = new Fl_Input2(100, Y+=26, 300, 24, "Supervisor");
	rdx_5739_supervisor->tooltip("");

	tab_redx_5739_1->end();

	tab_redx_5739_2 = new Fl_Group(0, tab_top + 25, 570, 360, _("5739-2"));

	Y = tab_top;
	Fl_Box *title = new Fl_Box(0,Y+30, 200, 24, _("Damage totals"));
	title->box(FL_FLAT_BOX);
	title->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

	rdx_sf_destroyed = new Fl_Input2(54, Y+=80, 100, 24, "SF destroyed");
	rdx_sf_destroyed->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_sf_destroyed->tooltip(_("computed value"));
	rdx_sf_destroyed->callback(redx_5739_compute, NULL);
	rdx_sf_major = new Fl_Input2(54, Y+=50, 100, 24, "SF major");
	rdx_sf_major->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_sf_major->tooltip(_("computed value"));
	rdx_sf_major->callback(redx_5739_compute, NULL);
	rdx_sf_minor = new Fl_Input2(54, Y+=50, 100, 24, "SF minor");
	rdx_sf_minor->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_sf_minor->tooltip(_("computed value"));
	rdx_sf_minor->callback(redx_5739_compute, NULL);
	rdx_sf_affected = new Fl_Input2(54, Y+=50, 100, 24, "SF affected");
	rdx_sf_affected->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_sf_affected->tooltip(_("computed value"));
	rdx_sf_affected->callback(redx_5739_compute, NULL);
	rdx_sf_inaccessible = new Fl_Input2(54, Y+=50, 100, 24, "SF inacc'");
	rdx_sf_inaccessible->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_sf_inaccessible->tooltip(_("computed value"));
	rdx_sf_inaccessible->callback(redx_5739_compute, NULL);

	Y = tab_top;
	rdx_mh_destroyed = new Fl_Input2(235, Y+=80, 100, 24, "MH destroyed");
	rdx_mh_destroyed->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_mh_destroyed->tooltip(_("computed value"));
	rdx_mh_destroyed->callback(redx_5739_compute, NULL);
	rdx_mh_major = new Fl_Input2(235, Y+=50, 100, 24, "MH major");
	rdx_mh_major->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_mh_major->tooltip(_("computed value"));
	rdx_mh_major->callback(redx_5739_compute, NULL);
	rdx_mh_minor = new Fl_Input2(235, Y+=50, 100, 24, "MH minor");
	rdx_mh_minor->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_mh_minor->tooltip(_("computed value"));
	rdx_mh_minor->callback(redx_5739_compute, NULL);
	rdx_mh_affected = new Fl_Input2(235, Y+=50, 100, 24, "MH affected");
	rdx_mh_affected->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_mh_affected->tooltip(_("computed value"));
	rdx_mh_affected->callback(redx_5739_compute, NULL);
	rdx_mh_inaccessible = new Fl_Input2(235, Y+=50, 100, 24, "MH inacc'");
	rdx_mh_inaccessible->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_mh_inaccessible->tooltip(_("computed value"));
	rdx_mh_inaccessible->callback(redx_5739_compute, NULL);

	Y = tab_top;
	rdx_ap_destroyed = new Fl_Input2(416, Y+=80, 100, 24, "Apt destroyed");
	rdx_ap_destroyed->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_ap_destroyed->tooltip(_("computed value"));
	rdx_ap_destroyed->callback(redx_5739_compute, NULL);
	rdx_ap_major = new Fl_Input2(416, Y+=50, 100, 24, "Apt major");
	rdx_ap_major->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_ap_major->tooltip(_("computed value"));
	rdx_ap_major->callback(redx_5739_compute, NULL);
	rdx_ap_minor = new Fl_Input2(416, Y+=50, 100, 24, "Apt minor");
	rdx_ap_minor->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_ap_major->tooltip(_("computed value"));
	rdx_ap_minor->callback(redx_5739_compute, NULL);
	rdx_ap_affected = new Fl_Input2(416, Y+=50, 100, 24, "Apt affected");
	rdx_ap_affected->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_ap_affected->tooltip(_("computed value"));
	rdx_ap_affected->callback(redx_5739_compute, NULL);
	rdx_ap_inaccessible = new Fl_Input2(416, Y+=50, 100, 24, "Apt inacc'");
	rdx_ap_inaccessible->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	rdx_ap_inaccessible->tooltip(_("computed value"));
	rdx_ap_inaccessible->callback(redx_5739_compute, NULL);


	tab_redx_5739_2->end();

	for (int i = 0; i < 10; i++) {
		static char tabnbr[10][10];
		snprintf(tabnbr[i], sizeof(tabnbr[i]), "# %d", i+1);
		Fl_Group *o = new Fl_Group(0, tab_top + 25, 570, 360, tabnbr[i]);

		Fl_Box *title = new Fl_Box(0, tab_top+30, 200, 24, _("Damage Classification"));
		title->box(FL_FLAT_BOX);
		title->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

		redx_5739_house_nbr[i] = new Fl_Input2(14, Y = tab_top + 70, 150, 24, _("House nbr"));
		redx_5739_house_nbr[i]->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
		redx_5739_house_nbr[i]->tooltip("");
		redx_5739_apt_nbr[i] = new Fl_Input2(220, Y, 150, 24, _("Apt nbr"));
		redx_5739_apt_nbr[i]->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
		redx_5739_apt_nbr[i]->tooltip("");

		int X = 95;
		redx_5739_destroyed[i] = new Fl_Input2(X-=12, Y+=45, 24, 24, _("Destroyed"));
		redx_5739_destroyed[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_destroyed[i]->tooltip("S/M/A");
		redx_5739_destroyed[i]->callback(redx_5739_dmgtype, reinterpret_cast<void *>(i));
		redx_5739_major[i] = new Fl_Input2(X+=95, Y, 24, 24, _("Major"));
		redx_5739_major[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_major[i]->tooltip("S/M/A");
		redx_5739_major[i]->callback(redx_5739_dmgtype, reinterpret_cast<void *>(i));
		redx_5739_minor[i] = new Fl_Input2(X+=95, Y, 24, 24, _("Minor"));
		redx_5739_minor[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_minor[i]->tooltip("S/M/A");
		redx_5739_minor[i]->callback(redx_5739_dmgtype, reinterpret_cast<void *>(i));
		redx_5739_affected[i] = new Fl_Input2(X+=95, Y, 24, 24, _("Affected"));
		redx_5739_affected[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_affected[i]->tooltip("S/M/A");
		redx_5739_affected[i]->callback(redx_5739_dmgtype, reinterpret_cast<void *>(i));
		redx_5739_inaccessible[i] = new Fl_Input2(X+=95, Y, 24, 24, _("Inacc'"));
		redx_5739_inaccessible[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_inaccessible[i]->tooltip("S/M/A");
		redx_5739_inaccessible[i]->callback(redx_5739_dmgtype, reinterpret_cast<void *>(i));

		X = 95;
		redx_5739_floors[i] = new Fl_Input2(X-=40, Y+=45, 80, 24, _("# Floors"));
		redx_5739_floors[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_floors[i]->tooltip("");
		redx_5739_basement[i] = new Fl_Input2(X+=(95+40-12), Y, 24, 24, _("Basement ?"));
		redx_5739_basement[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_basement[i]->tooltip(_("Y/N"));
		redx_5739_basement[i]->callback(redx_5739_yn, NULL);

		X = 95;
		redx_5739_waterlevel[i] = new Fl_Input2(X-=40, Y+=45, 80, 24, _("Water level"));
		redx_5739_waterlevel[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_waterlevel[i]->tooltip(_("in inches"));
		redx_5739_waterlevel[i]->callback(redx_5739_inches, NULL);
		redx_5739_basement_water[i] = new Fl_Input2(X+=(95), Y, 80, 24, _("W.L. in base'"));
		redx_5739_basement_water[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_basement_water[i]->tooltip(_("in inches"));
		redx_5739_basement_water[i]->callback(redx_5739_inches, NULL);

		X = 95;
		redx_5739_electricity[i] = new Fl_Input2(X-=12, Y+=45, 24, 24, _("Elect'?"));
		redx_5739_electricity[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_electricity[i]->tooltip(("Y/N"));
		redx_5739_electricity[i]->callback(redx_5739_yn, NULL);
		redx_5739_occupancy[i] = new Fl_Input2(X+=95, Y, 24, 24, _("Occ. Type"));
		redx_5739_occupancy[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_occupancy[i]->tooltip(_("O/R/S"));
		redx_5739_occupancy[i]->callback(redx_5739_occ_check, NULL);
		redx_5739_OR[i] = new Fl_Input2(X+=95, Y, 24, 24, _("OR"));
		redx_5739_OR[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_OR[i]->tooltip(_("O-outreach assigned"));
		redx_5739_OR[i]->callback(redx_5739_or, NULL);
		redx_5739_901[i] = new Fl_Input2(X+=95, Y, 24, 24, _("901"));
		redx_5739_901[i]->align(FL_ALIGN_CENTER | FL_ALIGN_TOP);
		redx_5739_901[i]->tooltip(_("case record assigned?"));
		redx_5739_901[i]->callback(redx_5739_yn, NULL);

		redx_5739_desc[i] = new Fl_Input2(4, Y+=45, 562, 24, _("Description:"));
		redx_5739_desc[i]->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
		redx_5739_desc[i]->tooltip(_("Useful info for assistance providers"));

		redx_5739_nam[i] = new Fl_Input2(4, Y+=45, 562, 24, _("Name:"));
		redx_5739_nam[i]->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
		redx_5739_nam[i]->tooltip(_("last name of resident family (if known)"));

		o->end();
	}

	tab_redx_5739_type->end();

	tab_redx_5739->end();

	tab_redx_5739->hide();

}

