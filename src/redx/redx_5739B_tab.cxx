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
	Y += 30;
	rdx_5739B_name = new Fl_Input2(100, Y, 250, 24, _("DR Name"));
	rdx_5739B_name->tooltip(_(""));
	Y += 30;
	rdx_5739B_state = new Fl_Input2(100, Y, 50, 24, _("State"));
	rdx_5739B_state->tooltip(_(""));
	Y += 30;
	rdx_5739B_cnty = new Fl_Input2(100, Y, 250, 24, _("County"));
	rdx_5739B_cnty->tooltip(_(""));
	Y += 30;
	rdx_5739B_city = new Fl_Input2(100, Y, 450, 24, _("City"));
	rdx_5739B_city->tooltip(_(""));

	Y += 30;
	rdx_5739B_date = new Fl_Input2(100, Y, 150, 24, _("Date"));
	rdx_5739B_date->tooltip(_(""));

	Fl_Button *btn_5739B_date = new Fl_Button(260, Y+2, 20, 20, _("..."));
	btn_5739B_date->tooltip(_("Set today"));
	btn_5739B_date->callback((Fl_Callback*)cb_btn_5739B_date);

	Y += 30;
	rdx_5739B_georef = new Fl_Input2(100, Y, 450, 24, _("Geo. Ref."));
	rdx_5739B_georef->tooltip(_(""));

	Y += 30;
	rdx_5739B_north = new Fl_Input2(175, Y, 225, 24, _("Boundaries, North:"));
	rdx_5739B_north->tooltip(_(""));

	Y += 30;
	rdx_5739B_west = new Fl_Input2(50, Y, 225, 24, _("West:"));
	rdx_5739B_west->tooltip(_(""));

	rdx_5739B_east = new Fl_Input2(325, Y, 225, 24, _("East:"));
	rdx_5739B_east->tooltip(_(""));

	Y += 30;
	rdx_5739B_south = new Fl_Input2(175, Y, 225, 24, _("South:"));
	rdx_5739B_south->tooltip(_(""));

	tab_redx_5739B_1->end();

	Y = tab_top;
	tab_redx_5739B_2 = new Fl_Group(0, Y+25, 570, 360, _("Area"));
	Y += 35;
	rdx_5739B_dwell = new Fl_Input2(160, Y, 50, 24, _("# affected dwellings"));
	rdx_5739B_dwell->tooltip(_(""));
	Y += 25;
	rdx_5739B_ds = new Fl_Input2(160, Y, 50, 24, _("Destroyed %"));
	rdx_5739B_ds->tooltip(_(""));
	Y += 25;
	rdx_5739B_mj = new Fl_Input2(160, Y, 50, 24, _("Major damage %"));
	rdx_5739B_mj->tooltip(_(""));
	Y += 25;
	rdx_5739B_mn = new Fl_Input2(160, Y, 50, 24, _("Minor damage %"));
	rdx_5739B_mn->tooltip(_(""));
	Y += 25;
	rdx_5739B_af = new Fl_Input2(160, Y, 50, 24, _("Affected %"));
	rdx_5739B_af->tooltip(_(""));
	Y += 25;
	rdx_5739B_in = new Fl_Input2(160, Y, 50, 24, _("Inaccessible %"));
	rdx_5739B_in->tooltip(_(""));
	Y += 25;
	rdx_5739B_un = new Fl_Input2(160, Y, 50, 24, _("Unknown/None %"));
	rdx_5739B_un->tooltip(_(""));
	Y += 25;
	rdx_5739B_bs = new Fl_Input2(160, Y, 50, 24, _("Basements?"));
	rdx_5739B_bs->tooltip(_("Yes/No"));
	Y += 25;
	rdx_5739B_gi = new Fl_Input2(160, Y, 400, 96, _("General info:"));
	rdx_5739B_gi->align(FL_ALIGN_LEFT_TOP);
	rdx_5739B_gi->type(4);
	rdx_5739B_gi->tooltip(_(""));

	tab_redx_5739B_2->end();

	tab_redx_5739B->end();

	tab_redx_5739B->hide();

};

