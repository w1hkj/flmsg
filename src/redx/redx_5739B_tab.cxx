#include <FL/Fl_Hold_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"
#include "fileselect.h"

Fl_Group	*tab_redx_5739B = (Fl_Group *)0;
Fl_Tabs		*tab_redx_5739B_type = (Fl_Tabs *)0;

Fl_Group	*tab_redx_5739B_1 = (Fl_Group *)0;

Fl_Input2	*rdx_5739B_nbr = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_name = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_state = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_cnty = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_city = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_date = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_street = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_georef = (Fl_Input2 *)0;

Fl_Input2	*rdx_5739B_north = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_east = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_south = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_west = (Fl_Input2 *)0;

Fl_Group	*tab_redx_5739B_2 = (Fl_Group *)0;

Fl_Input2	*rdx_5739B_dwell = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_ds = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_mj = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_mn = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_af = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_in = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_un = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_bs = (Fl_Input2 *)0;
Fl_Input2	*rdx_5739B_gi = (Fl_Input2 *)0;

//----------------------------------------------------------------------

// widget callbacks & support

//----------------------------------------------------------------------
static void cb_btn_5739B_date(Fl_Button*, void*) {
  rdx_5739B_date->value(szDate());
  estimate();
}

void create_redx_5739B()
{
	int Y = tab_top;
	tab_redx_5739B = new Fl_Group(0, Y, 570, 390);
	tab_redx_5739B->align(FL_ALIGN_TOP);

	tab_redx_5739B_type = new Fl_Tabs(0, Y+2, 570, 387);
	tab_redx_5739B_type->selection_color((Fl_Color)246);

	tab_redx_5739B_1 = new Fl_Group(0, Y+25, 570, 360, _("DR data"));

	Y += 35;
	Fl_Box *bx = new Fl_Box(50, Y, 200, 24, _("Red Cross Form 5739B"));
	bx->box(FL_FLAT_BOX);
	bx->align(FL_ALIGN_INSIDE | FL_ALIGN_CENTER);
	Y += 30;
	rdx_5739B_nbr = new Fl_Input2(100, Y, 150, 24, _("DR #"));
	rdx_5739B_nbr->tooltip(_(""));
	rdx_5739B_nbr->callback(redx_changed);
	rdx_5739B_nbr->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_name = new Fl_Input2(100, Y, 250, 24, _("DR Name"));
	rdx_5739B_name->tooltip(_(""));
	rdx_5739B_name->callback(redx_changed);
	rdx_5739B_name->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_state = new Fl_Input2(100, Y, 50, 24, _("State"));
	rdx_5739B_state->tooltip(_(""));
	rdx_5739B_state->callback(redx_changed);
	rdx_5739B_state->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_cnty = new Fl_Input2(100, Y, 250, 24, _("County"));
	rdx_5739B_cnty->tooltip(_(""));
	rdx_5739B_cnty->callback(redx_changed);
	rdx_5739B_cnty->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_city = new Fl_Input2(100, Y, 450, 24, _("City"));
	rdx_5739B_city->tooltip(_(""));
	rdx_5739B_city->callback(redx_changed);
	rdx_5739B_city->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_date = new Fl_Input2(100, Y, 150, 24, _("Date"));
	rdx_5739B_date->tooltip(_(""));
	rdx_5739B_date->callback(redx_changed);
	rdx_5739B_date->when(FL_WHEN_CHANGED);

	Fl_Button *btn_5739B_date = new Fl_Button(260, Y+2, 20, 20, _("..."));
	btn_5739B_date->tooltip(_("Set today"));
	btn_5739B_date->callback((Fl_Callback*)cb_btn_5739B_date);

	Y += 30;
	rdx_5739B_georef = new Fl_Input2(100, Y, 450, 24, _("Geo. Ref."));
	rdx_5739B_georef->tooltip(_(""));
	rdx_5739B_georef->callback(redx_changed);
	rdx_5739B_georef->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_north = new Fl_Input2(175, Y, 225, 24, _("Boundaries, North:"));
	rdx_5739B_north->tooltip(_(""));
	rdx_5739B_north->callback(redx_changed);
	rdx_5739B_north->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_west = new Fl_Input2(50, Y, 225, 24, _("West:"));
	rdx_5739B_west->tooltip(_(""));
	rdx_5739B_west->callback(redx_changed);
	rdx_5739B_west->when(FL_WHEN_CHANGED);

	rdx_5739B_east = new Fl_Input2(325, Y, 225, 24, _("East:"));
	rdx_5739B_east->tooltip(_(""));
	rdx_5739B_east->callback(redx_changed);
	rdx_5739B_east->when(FL_WHEN_CHANGED);

	Y += 30;
	rdx_5739B_south = new Fl_Input2(175, Y, 225, 24, _("South:"));
	rdx_5739B_south->tooltip(_(""));
	rdx_5739B_south->callback(redx_changed);
	rdx_5739B_south->when(FL_WHEN_CHANGED);

	tab_redx_5739B_1->end();

	Y = tab_top;
	tab_redx_5739B_2 = new Fl_Group(0, Y+25, 570, 360, _("Area"));
	Y += 35;
	rdx_5739B_dwell = new Fl_Input2(160, Y, 50, 24, _("# affected dwellings"));
	rdx_5739B_dwell->tooltip(_(""));
	rdx_5739B_dwell->callback(redx_changed);
	rdx_5739B_dwell->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_ds = new Fl_Input2(160, Y, 50, 24, _("Destroyed %"));
	rdx_5739B_ds->tooltip(_(""));
	rdx_5739B_ds->callback(redx_changed);
	rdx_5739B_ds->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_mj = new Fl_Input2(160, Y, 50, 24, _("Major damage %"));
	rdx_5739B_mj->tooltip(_(""));
	rdx_5739B_mj->callback(redx_changed);
	rdx_5739B_mj->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_mn = new Fl_Input2(160, Y, 50, 24, _("Minor damage %"));
	rdx_5739B_mn->tooltip(_(""));
	rdx_5739B_mn->callback(redx_changed);
	rdx_5739B_mn->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_af = new Fl_Input2(160, Y, 50, 24, _("Affected %"));
	rdx_5739B_af->tooltip(_(""));
	rdx_5739B_af->callback(redx_changed);
	rdx_5739B_af->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_in = new Fl_Input2(160, Y, 50, 24, _("Inaccessible %"));
	rdx_5739B_in->tooltip(_(""));
	rdx_5739B_in->callback(redx_changed);
	rdx_5739B_in->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_un = new Fl_Input2(160, Y, 50, 24, _("Unknown/None %"));
	rdx_5739B_un->tooltip(_(""));
	rdx_5739B_un->callback(redx_changed);
	rdx_5739B_un->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_bs = new Fl_Input2(160, Y, 50, 24, _("Basements?"));
	rdx_5739B_bs->tooltip(_("Yes/No"));
	rdx_5739B_bs->callback(redx_changed);
	rdx_5739B_bs->when(FL_WHEN_CHANGED);

	Y += 25;
	rdx_5739B_gi = new Fl_Input2(160, Y, 400, 96, _("General info:"));
	rdx_5739B_gi->align(FL_ALIGN_LEFT_TOP);
	rdx_5739B_gi->type(4);
	rdx_5739B_gi->tooltip(_(""));
	rdx_5739B_gi->callback(redx_changed);
	rdx_5739B_gi->when(FL_WHEN_CHANGED);


	tab_redx_5739B_2->end();

	tab_redx_5739B->end();

	tab_redx_5739B->hide();

};

