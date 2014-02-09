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

//Fl_Group	*tab_mars = (Fl_Group *)0;
//Fl_Tabs		*tab_mars_type = (Fl_Tabs *)0;

void mars_changed(Fl_Widget *, void *)
{
	estimate();
}

void create_mars_tab()
{
	create_mars_daily();
	create_mars_ineei();
	create_mars_net();
	create_mars_army();
	create_mars_navy();
}

//======================================================================
// MARS support functions
//======================================================================

Fl_Double_Window	*mars_list_window = 0;
Fl_Hold_Browser	*brws_mars_list = (Fl_Hold_Browser *)0;
const int mars_list_widths[] = {160, 100, 40, 160, 0};

string mars_list_lname;
string mars_list_call;
string mars_list_state;
string mars_list_bcall;
string mars_list_position;
static bool mars_list_ok = false;

void cb_list_ok(Fl_Widget *w, void *d)
{
	string retstr = brws_mars_list->text(brws_mars_list->value());
	mars_list_window->hide();

	mars_list_call.clear();
	mars_list_lname.clear();
	mars_list_state.clear();
	mars_list_bcall.clear();
	mars_list_position.clear();

	size_t p = retstr.find('\t');
	if (p != string::npos) {
		mars_list_call = retstr.substr(0, p);
		retstr.erase(0,p+1);
	}
	p = retstr.find('\t');
	if (p != string::npos) {
		mars_list_lname = retstr.substr(0, p);
		retstr.erase(0,p+1);
	}
	p = retstr.find('\t');
	if (p != string::npos) {
		mars_list_state = retstr.substr(0, p);
		retstr.erase(0,p+1);
	}
	p = retstr.find('\t');
	if (p != string::npos) {
		mars_list_bcall = retstr.substr(0, p);
		retstr.erase(0,p+1);
	}
	if (!retstr.empty()) {
		mars_list_position = retstr;
	}
	mars_list_ok = true;
}

void cb_list_cancel(Fl_Widget *w, void *d)
{
	mars_list_window->hide();
	mars_list_ok = false;
}

Fl_Double_Window* mars_list_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(562, 280, _("Roster"));
	brws_mars_list = new Fl_Hold_Browser(1,1,560,250,"");
	brws_mars_list->column_widths(mars_list_widths);
	Fl_Button *cancel = new Fl_Button(280, 252, 80, 24, "cancel");
	cancel->callback((Fl_Callback*)cb_list_cancel);
	Fl_Button *ok = new Fl_Button(370, 252, 80, 24, "select");
	ok->callback((Fl_Callback*)cb_list_ok);

	FILE	*flist = fopen(progStatus.mars_roster_file.c_str(), "r");
	if (flist) {
		char line[80];
		char *retstr = fgets(line, 80, flist); // header
		line[0] = 0;
		if (retstr) {
			while(fgets(line, 80, flist)) {
				while( line[strlen(line)-1] == '\n') line[strlen(line)-1] = 0;
				while( line[strlen(line)-1] == '\r') line[strlen(line)-1] = 0;
				for (size_t i = 0; i < strlen(line); i++)
					if (line[i] == ',') line[i] = '\t';
				if (strlen(line)) brws_mars_list->add(line);
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

bool get_mars_list_text()
{
	if (!mars_list_window) mars_list_window = mars_list_dialog();
	mars_list_window->show();
	while (mars_list_window->visible()) Fl::wait();
	return mars_list_ok;
}

void cb_mars_fl_input2(Fl_Widget *w, void *d)
{
	Fl_Input2 *inp = (Fl_Input2 *)w;
	int pos = inp->position();
	string text = inp->value();
	ucase(text);
	inp->value(text.c_str());
	inp->position(pos);
	estimate();
}

void cb_mars_text(Fl_Widget *w, void *d)
{
	FTextEdit *inp = (FTextEdit *)w;
	int pos = inp->insert_position();
	string text = inp->buffer()->text();
	ucase(text);
	inp->clear();
	inp->add(text.c_str());
	inp->insert_position(pos);
	estimate();
}

string notail(string s)
{
	static string str;
	str = s;
	while (str[str.length()-1] == '\n')
		str.erase(str.length()-1, 1);
	return str;
}

string maxchars(string s, unsigned int nchars, int indent)
{
	static string str;
	str = notail(s);
	if (str.length() <= nchars) return str;
	size_t ccount = 0;
	size_t lastspace = -1;
	size_t p = 0;
	while ( p < str.length() ) {
		if (str[p] == '\n') {
			ccount = 0;
			if (indent) {
				str.insert(lastspace+1, indent, ' ');
				p += indent;
				ccount = indent;
			}
		} else if (str[p] == ' ') lastspace = p;
		p++;
		ccount++;
		if (ccount > nchars - 1) {
			str[lastspace] = '\n';
			if (indent)
				str.insert(lastspace+1, indent, ' ');
			p = lastspace+1;
			ccount = 0;
		}
	}
	return str;
}
