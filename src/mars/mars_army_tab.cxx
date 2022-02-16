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

#include <FL/Fl_Multi_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"
#include "fileselect.h"

extern Fl_Double_Window* mars_army_list_dialog();
extern Fl_Double_Window	*mars_army_list_window;
extern Fl_Multi_Browser	*brws_mars_army_list;
extern std::string mars_army_list_text;
extern bool mars_army_list_ok;

Fl_Group	*tab_mars_army = (Fl_Group *)0;

Fl_Tabs		*tab_mars_army_type = (Fl_Tabs *)0;

//----------------------------------------------------------------------

Fl_Group	*tab_mars_army_1 = (Fl_Group *)0;
Fl_Group	*tab_mars_army_2 = (Fl_Group *)0;

Fl_Input2	*txt_mars_army_dtg = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_army_fm = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_army_de = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_army_nbr = (Fl_Input2 *)0;
Fl_Input2	*txt_mars_army_subj = (Fl_Input2 *)0;

Fl_Button	*btn_mars_army_dtg = (Fl_Button *)0;
Fl_Button	*btn_mars_army_pick_fm = (Fl_Button *)0;
Fl_Button	*btn_mars_army_pick_to = (Fl_Button *)0;
Fl_Button	*btn_mars_army_pick_info = (Fl_Button *)0;

FTextEdit	*txt_mars_army_to = (FTextEdit *)0;
FTextEdit	*txt_mars_army_info = (FTextEdit *)0;
FTextEdit	*txt_mars_army_text = (FTextEdit *)0;

Fl_Button	*btn_mars_army_de_me = (Fl_Button *)0;

Fl_ListBox	*sel_mars_army_prec = (Fl_ListBox *)0;

//----------------------------------------------------------------------

// widget callbacks & support
bool get_mars_army_list_text()
{
	if (!mars_army_list_window) mars_army_list_window = mars_army_list_dialog();
	brws_mars_army_list->deselect();
	mars_army_list_window->show();
	while (mars_army_list_window->visible()) Fl::wait();
	return mars_army_list_ok;
}


void cb_btn_mars_army_pick_fm(Fl_Widget *w, void *d)
{
	if (!get_mars_army_list_text()) return;
	std::string s = mars_army_list_text;
	size_t p;
	if ((p = s.find('\n')) != std::string::npos) s.erase(p);
	txt_mars_army_fm->value(s.c_str());
	estimate();
}

void cb_btn_mars_army_pick_to(Fl_Widget *w, void *d)
{
	if (!get_mars_army_list_text()) return;
	std::string s = txt_mars_army_to->buffer()->text();
	if (s.length()) s += '\n';
	s.append(mars_army_list_text);
	txt_mars_army_to->clear();
	txt_mars_army_to->add(s.c_str());
	estimate();
}

void cb_btn_mars_army_pick_info(Fl_Widget *w, void *d)
{
	if (!get_mars_army_list_text()) return;
	std::string s = txt_mars_army_info->buffer()->text();
	if (s.length()) s += '\n';
	s.append(mars_army_list_text);
	txt_mars_army_info->clear();
	txt_mars_army_info->add(s.c_str());
	estimate();
}

void cb_btn_mars_army_dtg(Fl_Widget *w, void *d)
{
	txt_mars_army_dtg->value(szMarsDateTime());
	estimate();
}

void cb_btn_mars_army_de_me(Fl_Widget *w, void *d)
{
	txt_mars_army_de->value(progStatus.my_call.c_str());
	estimate();
}

void create_mars_army()
{
	int Y = tab_top;
	tab_mars_army = new Fl_Group(0, Y, 570, 390);
	tab_mars_army->align(FL_ALIGN_TOP);

	tab_mars_army_type = new Fl_Tabs(0, Y+2, 570, 387);

	tab_mars_army_1 = new Fl_Group(0, Y+25, 570, 360, _("Header"));

	Y += 35;

	txt_mars_army_de = new Fl_Input2(50, Y, 200, 24, _("DE"));
	txt_mars_army_de->tooltip(_(""));
	txt_mars_army_de->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_army_de->when(FL_WHEN_CHANGED);

	btn_mars_army_de_me = new Fl_Button(252, Y, 30, 24, _("ME"));
	btn_mars_army_de_me->callback((Fl_Callback*)cb_btn_mars_army_de_me);
	btn_mars_army_de_me->tooltip(_("insert operator callsign"));

	txt_mars_army_nbr = new Fl_Input2(320, Y, 150, 24, _("NR"));
	txt_mars_army_nbr->tooltip(_(""));
	txt_mars_army_nbr->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_army_nbr->when(FL_WHEN_CHANGED);

	Y += 35;
	sel_mars_army_prec = new Fl_ListBox(50, Y, 45, 24, _("PREC"));
	sel_mars_army_prec->tooltip(
		_("R - Routine\nP - Priority\nO - Immediate\nZ - Flash"));
	sel_mars_army_prec->add("R|P|O|Z");
	sel_mars_army_prec->align(FL_ALIGN_LEFT);
	sel_mars_army_prec->index(0);

	txt_mars_army_dtg = new Fl_Input2(135, Y, 150, 24, _("DTG"));
	txt_mars_army_dtg->tooltip(_(""));

	btn_mars_army_dtg = new Fl_Button(285, Y, 22, 24, _("..."));
	btn_mars_army_dtg->tooltip(_("Set Date/Time Group"));
	btn_mars_army_dtg->callback((Fl_Callback*)cb_btn_mars_army_dtg);

	Y += 26;
	btn_mars_army_pick_fm = new Fl_Button(4, Y, 44, 24, _("FM"));
	btn_mars_army_pick_fm->tooltip(_("Select from list"));
	btn_mars_army_pick_fm->callback((Fl_Callback*)cb_btn_mars_army_pick_fm);

	txt_mars_army_fm = new Fl_Input2(50, Y, 500, 24, _(""));
	txt_mars_army_fm->tooltip(_("use pick list button"));
	txt_mars_army_fm->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_army_fm->when(FL_WHEN_CHANGED);

	Y += 26;
	btn_mars_army_pick_to = new Fl_Button(4, Y, 44, 24, _("TO"));
	btn_mars_army_pick_to->tooltip(_("Select from list"));
	btn_mars_army_pick_to->callback((Fl_Callback*)cb_btn_mars_army_pick_to);

	txt_mars_army_to = new FTextEdit(50, Y, 500, 100, _(""));
	txt_mars_army_to->tooltip(_("use pick list button"));
	txt_mars_army_to->textfont(FL_HELVETICA);
	txt_mars_army_to->box(FL_DOWN_FRAME);
	txt_mars_army_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_mars_army_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_mars_army_to->labeltype(FL_NORMAL_LABEL);
	txt_mars_army_to->labelfont(0);
	txt_mars_army_to->labelsize(14);
	txt_mars_army_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_mars_army_to->align(FL_ALIGN_TOP_LEFT);
	txt_mars_army_to->callback((Fl_Callback*)cb_mars_text);
	txt_mars_army_to->when(FL_WHEN_CHANGED);

	Y += 102;
	btn_mars_army_pick_info = new Fl_Button(4, Y, 44, 24, _("INFO"));
	btn_mars_army_pick_info->tooltip(_("Select from list"));
	btn_mars_army_pick_info->callback((Fl_Callback*)cb_btn_mars_army_pick_info);

	txt_mars_army_info = new FTextEdit(50, Y, 500, 100, _(""));
	txt_mars_army_info->tooltip(_("use pick list button"));
	txt_mars_army_info->textfont(FL_HELVETICA);
	txt_mars_army_info->box(FL_DOWN_FRAME);
	txt_mars_army_info->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_mars_army_info->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_mars_army_info->labeltype(FL_NORMAL_LABEL);
	txt_mars_army_info->labelfont(0);
	txt_mars_army_info->labelsize(14);
	txt_mars_army_info->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_mars_army_info->align(FL_ALIGN_TOP_LEFT);
	txt_mars_army_info->callback((Fl_Callback*)cb_mars_text);
	txt_mars_army_info->when(FL_WHEN_CHANGED);

	Y += 102;
	Fl_Box *label = new Fl_Box(0, Y, 50, 24, "SUBJ");
	label->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

	txt_mars_army_subj = new Fl_Input2(50, Y, 500, 24, _(""));
	txt_mars_army_subj->tooltip(_("message subject"));
	txt_mars_army_subj->callback((Fl_Callback*)cb_mars_fl_input2);
	txt_mars_army_subj->when(FL_WHEN_CHANGED);

	tab_mars_army_1->end();

	Y = tab_top;

	tab_mars_army_2 = new Fl_Group(0, Y+25, 570, 355, _("Body"));

	Y += 30;
	txt_mars_army_text = new FTextEdit(2, Y, 566, 350, "");
	txt_mars_army_text->tooltip("enter text of message");
	txt_mars_army_text->textfont(FL_HELVETICA);
	txt_mars_army_text->box(FL_DOWN_FRAME);
	txt_mars_army_text->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_mars_army_text->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_mars_army_text->labeltype(FL_NORMAL_LABEL);
	txt_mars_army_text->labelfont(0);
	txt_mars_army_text->labelsize(14);
	txt_mars_army_text->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_mars_army_text->align(FL_ALIGN_TOP_LEFT);
	txt_mars_army_text->callback((Fl_Callback*)cb_mars_text);
	txt_mars_army_text->when(FL_WHEN_CHANGED);

	tab_mars_army_2->end();

	tab_mars_army_type->end();

	tab_mars_army->end();

	tab_mars_army->hide();
};

//======================================================================
//======================================================================
Fl_Double_Window	*mars_army_list_window = 0;
Fl_Multi_Browser	*brws_mars_army_list = (Fl_Multi_Browser *)0;

const int mars_army_list_widths[] = {80, 170, 30, 0};

std::string mars_army_list_text;
bool mars_army_list_ok = false;

void cb_army_list_ok(Fl_Widget *w, void *d)
{
	std::string retstr;
	mars_army_list_text.clear();
	size_t p;
	for (int i = 1; i <= brws_mars_army_list->size(); i++) {
		if (brws_mars_army_list->selected(i)) {
			if (mars_army_list_text.length()) mars_army_list_text += '\n';
			retstr = brws_mars_army_list->text(i);
			p = retstr.find('\t');
			mars_army_list_text.append(retstr.substr(0, p));
			retstr.erase(0,p+1);
			p = retstr.find('\t');
			retstr.erase(0,p+1);
			mars_army_list_text.append(" ").append(retstr);
		}
	}
	mars_army_list_window->hide();
	mars_army_list_ok = true;
}

void cb_army_list_cancel(Fl_Widget *w, void *d)
{
	mars_army_list_window->hide();
	mars_army_list_ok = false;
}

Fl_Double_Window* mars_army_list_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(452, 280, _("Roster"));
	brws_mars_army_list = new Fl_Multi_Browser(1,1,450,250,"");
	brws_mars_army_list->column_widths(mars_army_list_widths);
	Fl_Button *cancel = new Fl_Button(280, 252, 80, 24, "cancel");
	cancel->callback((Fl_Callback*)cb_army_list_cancel);
	Fl_Button *ok = new Fl_Button(370, 252, 80, 24, "select");
	ok->callback((Fl_Callback*)cb_army_list_ok);

	FILE	*flist = fopen(progStatus.mars_roster_file.c_str(), "r");
	char *retstr;
	if (flist) {
		char line[80];
		retstr = fgets(line, 80, flist); // header
		line[0] = 0;
 		if (retstr) {
 			while(fgets(line, 80, flist)) {
 				while( line[strlen(line)-1] == '\n') line[strlen(line)-1] = 0;
 				while( line[strlen(line)-1] == '\r') line[strlen(line)-1] = 0;
 				for (size_t i = 0; i < strlen(line); i++)
 					if (line[i] == ',') line[i] = '\t';
 				if (strlen(line)) brws_mars_army_list->add(line);
 				line[0] = 0;
 			}
		}
		fclose(flist);
	} else
		printf("could not open %s\n", progStatus.mars_roster_file.c_str());
	w->set_modal();
	w->end();
	return w;
}

