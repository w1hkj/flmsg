#include <FL/Fl_Hold_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"
#include "fileselect.h"

Fl_Group	*tab_mars_ineei = (Fl_Group *)0;
Fl_Tabs		*tab_mars_ineei_type = (Fl_Tabs *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_mars_ineei_1 = (Fl_Group *)0;//

Fl_Input2	*txt_mars_ineei_DE = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_NBR = (Fl_Input2 *)0;//
Fl_Choice	*sel_mars_ineei_PREC = (Fl_Choice *)0;//
Fl_Input2	*txt_mars_ineei_DTG = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_FMNAME = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_FMCALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_FMSTATE = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_TOPOS = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_TOCALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_TOSTATE = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_INFO1POS = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_INFO1CALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_INFO1STATE = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_INFO2POS = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_INFO2CALL = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_INFO2STATE = (Fl_Input2 *)0;//
Fl_Input2	*txt_mars_ineei_INCIDENT = (Fl_Input2 *)0;//

Fl_Button	*btn_mars_ineei_DE = (Fl_Button*)0;
Fl_Button	*btn_mars_ineei_DTG = (Fl_Button*)0;
Fl_Button	*btn_mars_ineei_pick_fm = (Fl_Button*)0;
Fl_Button	*btn_mars_ineei_pick_to = (Fl_Button*)0;
Fl_Button	*btn_mars_ineei_pick_INFO1 = (Fl_Button*)0;
Fl_Button	*btn_mars_ineei_pick_INFO2 = (Fl_Button*)0;

//----------------------------------------------------------------------

Fl_Group	*tab_mars_ineei_2 = (Fl_Group *)0;

Fl_Input2	*txt_mars_ineei_REF = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_STATE = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1A_INCIDENT = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1A_LOCATION = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1A_TIME = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1B_MEDFACSTS = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1C_TRNPSTS = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1D_DAMAGE = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1E_UTILSTS = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1F_COMMSTS = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1G_INFOSRC = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1G_INFOTIME = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_ineei_1H_REMARKS = (Fl_Input2 *)0;

//----------------------------------------------------------------------

// widget callbacks & support
void cb_btn_mars_ineei_DE(Fl_Widget *w, void *d)
{
	txt_mars_ineei_DE->value(progStatus.my_call.c_str());
}

void cb_btn_mars_ineei_DTG(Fl_Widget *w, void *d)
{
	txt_mars_ineei_DTG->value(szMarsDateTime());
}

void cb_btn_mars_ineei_pick_fm(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_ineei_FMCALL->value(mars_list_call.c_str());
	txt_mars_ineei_FMNAME->value(mars_list_lname.c_str());
	txt_mars_ineei_FMSTATE->value(mars_list_state.c_str());
}

void cb_btn_mars_ineei_pick_to(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_ineei_TOCALL->value(mars_list_bcall.c_str());
	txt_mars_ineei_TOPOS->value(mars_list_position.c_str());
	txt_mars_ineei_TOSTATE->value(mars_list_state.c_str());
}

void cb_btn_mars_ineei_pick_INFO1(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_ineei_INFO1CALL->value(mars_list_bcall.c_str());
	txt_mars_ineei_INFO1POS->value(mars_list_position.c_str());
	txt_mars_ineei_INFO1STATE->value(mars_list_state.c_str());
}

void cb_btn_mars_ineei_pick_INFO2(Fl_Widget *w, void *d)
{
	if (!get_mars_list_text()) return;
	txt_mars_ineei_INFO2CALL->value(mars_list_bcall.c_str());
	txt_mars_ineei_INFO2POS->value(mars_list_position.c_str());
	txt_mars_ineei_INFO2STATE->value(mars_list_state.c_str());
}

//----------------------------------------------------------------------

void create_mars_ineei()
{
	int Y = 0;
	tab_mars_ineei = new Fl_Group(0, 70, 570, 355, _("IN/EEI"));
	tab_mars_ineei->align(FL_ALIGN_TOP_LEFT);

	tab_mars_ineei_type = new Fl_Tabs(0, 72, 570, 352);
	tab_mars_ineei->align(FL_ALIGN_TOP_LEFT);

//-----------tab 1-------------

	tab_mars_ineei_1 = new Fl_Group(0, 95, 570, 325, _("Header"));

	Y = 100;

	txt_mars_ineei_DE = new Fl_Input2(80, Y, 150, 24, _("DE"));
	txt_mars_ineei_DE->tooltip(_(""));
	txt_mars_ineei_DE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_DE->when(FL_WHEN_CHANGED);

	btn_mars_ineei_DE = new Fl_Button(232, Y, 30, 24, _("ME"));
	btn_mars_ineei_DE->callback((Fl_Callback*)cb_btn_mars_ineei_DE);

	txt_mars_ineei_NBR = new Fl_Input2(350, Y, 150, 24, _("MSG NBR"));
	txt_mars_ineei_NBR->tooltip(_(""));
	txt_mars_ineei_NBR->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_NBR->when(FL_WHEN_CHANGED);

	Y += 25;
	sel_mars_ineei_PREC = new Fl_Choice(80, Y, 45, 24, _("PREC"));
	sel_mars_ineei_PREC->tooltip(
		_("R - Routine\nP - Priority\nI - Immediate\nF - Flash\nM - MARSGram"));
	sel_mars_ineei_PREC->add("R|P|I|F|M");
	sel_mars_ineei_PREC->value(4);
	sel_mars_ineei_PREC->down_box(FL_BORDER_BOX);

	txt_mars_ineei_DTG = new Fl_Input2(165, Y, 150, 24, _("DTG"));
	txt_mars_ineei_DTG->tooltip(_(""));

	btn_mars_ineei_DTG = new Fl_Button(315, Y, 22, 24, _("..."));
	btn_mars_ineei_DTG->tooltip(_("Set Date/Time Group"));
	btn_mars_ineei_DTG->callback((Fl_Callback*)cb_btn_mars_ineei_DTG);

	Y += 25;
	txt_mars_ineei_FMNAME = new Fl_Input2(80, Y, 150, 24, _("FM"));
	txt_mars_ineei_FMNAME->tooltip(_("Name"));
	txt_mars_ineei_FMNAME->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_FMNAME->when(FL_WHEN_CHANGED);

	txt_mars_ineei_FMCALL = new Fl_Input2(232, Y, 150, 24, _(""));
	txt_mars_ineei_FMCALL->tooltip(_("Call"));
	txt_mars_ineei_FMCALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_FMCALL->when(FL_WHEN_CHANGED);

	txt_mars_ineei_FMSTATE = new Fl_Input2(384, Y, 30, 24, _(""));
	txt_mars_ineei_FMSTATE->tooltip(_("State"));
	txt_mars_ineei_FMSTATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_FMSTATE->when(FL_WHEN_CHANGED);

	btn_mars_ineei_pick_fm = new Fl_Button(416, Y, 30, 24, _("List"));
	btn_mars_ineei_pick_fm->tooltip(_("Select from list"));
	btn_mars_ineei_pick_fm->callback((Fl_Callback*)cb_btn_mars_ineei_pick_fm);

	Y += 25;
	txt_mars_ineei_TOPOS = new Fl_Input2(80, Y, 150, 24, _("TO"));
	txt_mars_ineei_TOPOS->tooltip(_("Position"));
	txt_mars_ineei_TOPOS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_TOPOS->when(FL_WHEN_CHANGED);

	txt_mars_ineei_TOCALL = new Fl_Input2(232, Y, 150, 24, _(""));
	txt_mars_ineei_TOCALL->tooltip(_("Call"));
	txt_mars_ineei_TOCALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_TOCALL->when(FL_WHEN_CHANGED);

	txt_mars_ineei_TOSTATE = new Fl_Input2(384, Y, 30, 24, _(""));
	txt_mars_ineei_TOSTATE->tooltip(_("State"));
	txt_mars_ineei_TOSTATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_TOSTATE->when(FL_WHEN_CHANGED);

	btn_mars_ineei_pick_to = new Fl_Button(416, Y, 30, 24, _("List"));
	btn_mars_ineei_pick_to->tooltip(_("Select from list"));
	btn_mars_ineei_pick_to->callback((Fl_Callback*)cb_btn_mars_ineei_pick_to);

	Y += 25;
	txt_mars_ineei_INFO1POS = new Fl_Input2(80, Y, 150, 24, _("INFO"));
	txt_mars_ineei_INFO1POS->tooltip(_("Position"));
	txt_mars_ineei_INFO1POS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_INFO1POS->when(FL_WHEN_CHANGED);

	txt_mars_ineei_INFO1CALL = new Fl_Input2(232, Y, 150, 24, _(""));
	txt_mars_ineei_INFO1CALL->tooltip(_("Call"));
	txt_mars_ineei_INFO1CALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_INFO1CALL->when(FL_WHEN_CHANGED);

	txt_mars_ineei_INFO1STATE = new Fl_Input2(384, Y, 30, 24, _(""));
	txt_mars_ineei_INFO1STATE->tooltip(_("State"));
	txt_mars_ineei_INFO1STATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_INFO1STATE->when(FL_WHEN_CHANGED);

	btn_mars_ineei_pick_INFO1 = new Fl_Button(416, Y, 30, 24, _("List"));
	btn_mars_ineei_pick_INFO1->tooltip(_("Select from list"));
	btn_mars_ineei_pick_INFO1->callback((Fl_Callback*)cb_btn_mars_ineei_pick_INFO1);

	Y += 25;
	txt_mars_ineei_INFO2POS = new Fl_Input2(80, Y, 150, 24, _("INFO"));
	txt_mars_ineei_INFO2POS->tooltip(_("Position"));
	txt_mars_ineei_INFO2POS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_INFO2POS->when(FL_WHEN_CHANGED);

	txt_mars_ineei_INFO2CALL = new Fl_Input2(232, Y, 150, 24, _(""));
	txt_mars_ineei_INFO2CALL->tooltip(_("Call"));
	txt_mars_ineei_INFO2CALL->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_INFO2CALL->when(FL_WHEN_CHANGED);

	txt_mars_ineei_INFO2STATE = new Fl_Input2(384, Y, 30, 24, _(""));
	txt_mars_ineei_INFO2STATE->tooltip(_("State"));
	txt_mars_ineei_INFO2STATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_INFO2STATE->when(FL_WHEN_CHANGED);

	btn_mars_ineei_pick_INFO2 = new Fl_Button(416, Y, 30, 24, _("List"));
	btn_mars_ineei_pick_INFO2->tooltip(_("Select from list"));
	btn_mars_ineei_pick_INFO2->callback((Fl_Callback*)cb_btn_mars_ineei_pick_INFO2);

	Y += 49;
	txt_mars_ineei_INCIDENT = new Fl_Input2(80, Y, 450, 24, _("INCIDENT"));
	txt_mars_ineei_INCIDENT->tooltip(_("Incident\nleave blank for normal ops"));
	txt_mars_ineei_INCIDENT->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_INCIDENT->when(FL_WHEN_CHANGED);

	tab_mars_ineei_1->end();

//-----------tab 2-------------

	tab_mars_ineei_2 = new Fl_Group(0, 95, 570, 325, _("Body"));

	Fl_Box *label = (Fl_Box *)0;

	Y = 100;
	label = new Fl_Box(0, Y, 28, 24, "1.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

	txt_mars_ineei_REF = new Fl_Input2(80, Y, 160, 24, "REF");
	txt_mars_ineei_REF->tooltip("Use appropriate event identifier");
	txt_mars_ineei_REF->align(FL_ALIGN_LEFT);
	txt_mars_ineei_REF->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_REF->when(FL_WHEN_CHANGED);

	txt_mars_ineei_STATE = new Fl_Input2(280, Y, 40, 24, "ST");
	txt_mars_ineei_STATE->tooltip("State");
	txt_mars_ineei_STATE->align(FL_ALIGN_LEFT);
	txt_mars_ineei_STATE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_STATE->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "A.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1A_INCIDENT = new Fl_Input2(80, Y, 160, 24, "INC");
	txt_mars_ineei_1A_INCIDENT->tooltip("Incident");
	txt_mars_ineei_1A_INCIDENT->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1A_INCIDENT->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1A_INCIDENT->when(FL_WHEN_CHANGED);

	txt_mars_ineei_1A_LOCATION = new Fl_Input2(280, Y, 160, 24, "LOC");
	txt_mars_ineei_1A_LOCATION->tooltip("Incident Location");
	txt_mars_ineei_1A_LOCATION->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1A_LOCATION->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1A_LOCATION->when(FL_WHEN_CHANGED);

	txt_mars_ineei_1A_TIME = new Fl_Input2(480, Y, 80, 24, "TIME");
	txt_mars_ineei_1A_TIME->tooltip("Incident time");
	txt_mars_ineei_1A_TIME->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1A_TIME->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1A_TIME->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "B.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1B_MEDFACSTS = new Fl_Input2(80, Y, 480, 24, "MED");
	txt_mars_ineei_1B_MEDFACSTS->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1B_MEDFACSTS->tooltip("Emergency Medical Facility Status");
	txt_mars_ineei_1B_MEDFACSTS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1B_MEDFACSTS->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "C.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1C_TRNPSTS = new Fl_Input2(80, Y, 480, 24, "TRNS");
	txt_mars_ineei_1C_TRNPSTS->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1C_TRNPSTS->tooltip("Local Transportation Status");
	txt_mars_ineei_1C_TRNPSTS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1C_TRNPSTS->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "D.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1D_DAMAGE = new Fl_Input2(80, Y, 480, 24, "DMG");
	txt_mars_ineei_1D_DAMAGE->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1D_DAMAGE->tooltip("General Damage Characteristics");
	txt_mars_ineei_1D_DAMAGE->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1D_DAMAGE->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "E.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1E_UTILSTS = new Fl_Input2(80, Y, 480, 24, "UTIL");
	txt_mars_ineei_1E_UTILSTS->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1E_UTILSTS->tooltip("Area Utulity Status");
	txt_mars_ineei_1E_UTILSTS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1E_UTILSTS->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "F.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1F_COMMSTS = new Fl_Input2(80, Y, 480, 24, "COMM");
	txt_mars_ineei_1F_COMMSTS->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1F_COMMSTS->tooltip("Communication Status");
	txt_mars_ineei_1F_COMMSTS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1F_COMMSTS->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "G.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1G_INFOSRC = new Fl_Input2(80, Y, 220, 24, "INFO");
	txt_mars_ineei_1G_INFOSRC->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1G_INFOSRC->tooltip("Information Source");
	txt_mars_ineei_1G_INFOSRC->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1G_INFOSRC->when(FL_WHEN_CHANGED);

	txt_mars_ineei_1G_INFOTIME = new Fl_Input2(360, Y, 120, 24, "TIME");
	txt_mars_ineei_1G_INFOTIME->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1G_INFOTIME->tooltip("Information Time");
	txt_mars_ineei_1G_INFOTIME->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1G_INFOTIME->when(FL_WHEN_CHANGED);

	Y += 25;
	label = new Fl_Box(0, Y, 28, 24, "H.");
	label->box(FL_FLAT_BOX);
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_ineei_1H_REMARKS = new Fl_Input2(80, Y, 480, 72, "REM");
	txt_mars_ineei_1H_REMARKS->type(4);
	txt_mars_ineei_1H_REMARKS->align(FL_ALIGN_LEFT);
	txt_mars_ineei_1H_REMARKS->tooltip("enter remarks");
	txt_mars_ineei_1H_REMARKS->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_ineei_1H_REMARKS->when(FL_WHEN_CHANGED);

	tab_mars_ineei_2->end();

	tab_mars_type->end();

	tab_mars_ineei->end();

};
