#include <FL/Fl_Hold_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"
#include "fileselect.h"

Fl_Group	*tab_redx_snw = (Fl_Group *)0;
Fl_Tabs		*tab_redx_snw_type = (Fl_Tabs *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_redx_snw_1 = (Fl_Group *)0;

Fl_Input2	*snw_lname = (Fl_Input2 *)0;
Fl_Input2	*snw_fname = (Fl_Input2 *)0;
Fl_Input2	*snw_area1 = (Fl_Input2 *)0;

Fl_Check_Button *snw_nophone = (Fl_Check_Button *)0;
Fl_Input2	*snw_xchg1 = (Fl_Input2 *)0;
Fl_Input2	*snw_suffix1 = (Fl_Input2 *)0;
Fl_Input2	*snw_area2 = (Fl_Input2 *)0;
Fl_Input2	*snw_xchg2 = (Fl_Input2 *)0;
Fl_Input2	*snw_suffix2 = (Fl_Input2 *)0;
Fl_Input2	*snw_area3 = (Fl_Input2 *)0;
Fl_Input2	*snw_xchg3 = (Fl_Input2 *)0;
Fl_Input2	*snw_suffix3 = (Fl_Input2 *)0;

Fl_Input2	*snw_pdline1 = (Fl_Input2 *)0;
Fl_Input2	*snw_pdline2 = (Fl_Input2 *)0;
Fl_Input2	*snw_pdcity = (Fl_Input2 *)0;
Fl_Input2	*snw_pdst = (Fl_Input2 *)0;
Fl_Input2	*snw_pdzip = (Fl_Input2 *)0;
Fl_Input2	*snw_haline1 = (Fl_Input2 *)0;
Fl_Input2	*snw_haline2 = (Fl_Input2 *)0;
Fl_Input2	*snw_hacity = (Fl_Input2 *)0;
Fl_Input2	*snw_hast = (Fl_Input2 *)0;
Fl_Input2	*snw_hazip = (Fl_Input2 *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_redx_snw_2 = (Fl_Group *)0;

Fl_Check_Button *snw_m1 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m2 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m3 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m4 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m5 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m6 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m7 = (Fl_Check_Button *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_redx_snw_3 = (Fl_Group *)0;
Fl_Check_Button *snw_m8 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m9 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m10 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m11 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m12 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m13 = (Fl_Check_Button *)0;
Fl_Check_Button *snw_m14 = (Fl_Check_Button *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_redx_snw_4 = (Fl_Group *)0;
Fl_Check_Button *snw_m15 = (Fl_Check_Button *)0;
FTextEdit	*snw_cmsg = (FTextEdit *)0;

//----------------------------------------------------------------------

// widget callbacks & support

//----------------------------------------------------------------------

void create_redx_snw()
{
	int Y = 0;
	tab_redx_snw = new Fl_Group(0, 70, 570, 355, _("Safety - Welfare"));
	tab_redx_snw->align(FL_ALIGN_TOP_LEFT);

	tab_redx_snw_type = new Fl_Tabs(0, 72, 570, 352);
	tab_redx_snw->align(FL_ALIGN_TOP_LEFT);

	tab_redx_snw_1 = new Fl_Group(0, 95, 570, 325, _("Respondee"));

	Y = 100;

	snw_lname = new Fl_Input2(100, Y, 150, 24, _("Lname"));
	snw_lname->tooltip(_(""));
	snw_fname = new Fl_Input2(320, Y, 150, 24, _("Fname"));
	snw_fname->tooltip(_(""));
	Y += 25;
	snw_nophone =  new Fl_Check_Button(10, Y, 24, 24, _("No phone #"));
	Y += 50;
	int X = 10;
	snw_area1 = new Fl_Input2( X, Y, 50, 24, _("Phone #1"));
	snw_area1->align(FL_ALIGN_TOP_LEFT);
	snw_area1->tooltip(_("Area code"));
	snw_xchg1 = new Fl_Input2( X = X+54, Y, 50, 24, "");
	snw_xchg1->tooltip(_("exchange"));
	snw_suffix1 = new Fl_Input2( X = X+54, Y, 50, 24, "");
	snw_suffix1->tooltip(_("suffix"));
	
	snw_area2 = new Fl_Input2( X=X+86, Y, 50, 24, _("Phone #2"));
	snw_area2->align(FL_ALIGN_TOP_LEFT);
	snw_area2->tooltip(_("Area code"));
	snw_xchg2 = new Fl_Input2( X=X+54, Y, 50, 24, "");
	snw_xchg2->tooltip(_("exchange"));
	snw_suffix2 = new Fl_Input2( X=X+54, Y, 50, 24, "");
	snw_suffix2->tooltip(_("suffix"));
	
	snw_area3 = new Fl_Input2( X=X+86, Y, 50, 24, _("Phone #3"));
	snw_area3->align(FL_ALIGN_TOP_LEFT);
	snw_area3->tooltip(_("Area code"));
	snw_xchg3 = new Fl_Input2( X=X+54, Y, 50, 24, "");
	snw_xchg3->tooltip(_("exchange"));
	snw_suffix3 = new Fl_Input2( X+54, Y, 50, 24, "");
	snw_suffix3->tooltip(_("suffix"));
	Y += 25;
	Fl_Box *bx = new Fl_Box(100, Y, 200, 24, _("Pre disaster address:"));
	bx->box(FL_FLAT_BOX);
	bx->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
	Y += 25;
	snw_pdline1 = new Fl_Input2(100, Y, 400, 24, _("Addr line 1"));
	snw_pdline1->tooltip("");
	Y += 25;
	snw_pdline2 = new Fl_Input2(100, Y, 400, 24, _("Addr line 2"));
	snw_pdline2->tooltip("");
	Y += 25;
	snw_pdcity = new Fl_Input2(100, Y, 246, 24, _("City"));
	snw_pdcity->tooltip("");
	snw_pdst = new Fl_Input2(348, Y, 50, 24, "");
	snw_pdst->tooltip(_("State"));
	snw_pdzip = new Fl_Input2(400, Y, 100, 24, "");
	snw_pdzip->tooltip(_("Zip"));
	Y += 25;
	bx = new Fl_Box(100, Y, 200, 24, _("Current home address:"));
	bx->box(FL_FLAT_BOX);
	bx->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
	Y += 25;
	snw_haline1 = new Fl_Input2(100, Y, 400, 24, _("Addr line 1"));
	snw_haline1->tooltip("");
	Y += 25;
	snw_haline2 = new Fl_Input2(100, Y, 400, 24, _("Addr line 2"));
	snw_haline2->tooltip("");
	Y += 25;
	snw_hacity = new Fl_Input2(100, Y, 246, 24, _("City"));
	snw_hacity->tooltip("");
	snw_hast = new Fl_Input2(348, Y, 50, 24, "");
	snw_hast->tooltip(_("State"));
	snw_hazip = new Fl_Input2(400, Y, 100, 24, "");
	snw_hazip->tooltip(_("Zip"));
	tab_redx_snw_1->end();

	tab_redx_snw_2 = new Fl_Group(0, 95, 570, 325, _("Msgs-1"));
	Y = 140;
	snw_m1 = new Fl_Check_Button(100, Y, 24, 24, _("I am safe and well."));
	Y += 25;
	snw_m2 = new Fl_Check_Button(100, Y, 24, 24, _("Family and I are safe and well."));
	Y += 25;
	snw_m3 = new Fl_Check_Button(100, Y, 24, 24, _("Currently at shelter."));
	Y += 25;
	snw_m4 = new Fl_Check_Button(100, Y, 24, 24, _("Currently at home."));
	Y += 25;
	snw_m5 = new Fl_Check_Button(100, Y, 24, 24, _("Currently at friend / family / neighbor's."));
	Y += 25;
	snw_m6 = new Fl_Check_Button(100, Y, 24, 24, _("I am evacuating to the house of a family member / friend."));
	Y += 25;
	snw_m7 = new Fl_Check_Button(100, Y, 24, 24, _("Will make phone call when able."));
	tab_redx_snw_2->end();

	tab_redx_snw_3 = new Fl_Group(0, 95, 570, 325, _("Msgs-2"));
	Y = 140;
	snw_m8 = new Fl_Check_Button(100, Y, 24, 24, _("Will email when able."));
	Y += 25;
	snw_m9 = new Fl_Check_Button(100, Y, 24, 24, _("Will mail letter / postcard when able."));
	Y += 25;
	snw_m10 = new Fl_Check_Button(100, Y, 24, 24, _("I am safe and in the process of evacuating."));
	Y += 25;
	snw_m11 = new Fl_Check_Button(100, Y, 24, 24, _("I have evacuated and I am safe."));
	Y += 25;
	snw_m12 = new Fl_Check_Button(100, Y, 24, 24, _("I am evacuating to a shelter."));
	Y += 25;
	snw_m13 = new Fl_Check_Button(100, Y, 24, 24, _("I am currently at a hotel."));
	Y += 25;
	snw_m14 = new Fl_Check_Button(100, Y, 24, 24, _("I am currently remaining at home."));
	tab_redx_snw_3->end();

	tab_redx_snw_4 = new Fl_Group(0, 95, 570, 325, _("Msgs-3"));
	Y = 100;
	snw_m15 = new Fl_Check_Button(10, Y, 24, 24, _("Custom message:"));
	Y += 25;
	snw_cmsg = new FTextEdit(10, Y, 550, 280, _(""));
	snw_cmsg->tooltip(_("Enter custom message"));
	snw_cmsg->box(FL_DOWN_FRAME);
	snw_cmsg->color((Fl_Color)FL_BACKGROUND2_COLOR);
	snw_cmsg->selection_color((Fl_Color)FL_SELECTION_COLOR);
	snw_cmsg->labeltype(FL_NORMAL_LABEL);
	snw_cmsg->labelfont(0);
	snw_cmsg->labelsize(14);
	snw_cmsg->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	snw_cmsg->align(FL_ALIGN_TOP_LEFT);
	snw_cmsg->when(FL_WHEN_RELEASE);
	tab_redx_snw_4->end();

	tab_mars_type->end();

	tab_redx_snw->end();

};

