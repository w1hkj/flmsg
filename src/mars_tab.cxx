//======================================================================
// Navy Mars

#include <FL/Fl_Hold_Browser.H>

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

Fl_Group	*tab_mars = (Fl_Group *)0;
Fl_Tabs		*tab_mars_type = (Fl_Tabs *)0;

static void cb_tab_mars_type(Fl_Tabs*, void*) {
  cb_msg_type();
}

void create_mars_tab()
{
	tab_mars = new Fl_Group(0, 45, 570, 380, _("MARS"));
	tab_mars_type = new Fl_Tabs(0, 45, 570, 380);
	tab_mars_type->selection_color((Fl_Color)246);
	tab_mars_type->callback((Fl_Callback*)cb_tab_mars_type);
	create_mars_daily();
	create_mars_ineei();
	create_mars_net();
	create_mars_navy();
	Fl_Group::current()->resizable(tab_mars_daily);
	tab_mars_type->end();
	tab_mars->end();
}

//======================================================================
// MARS support functions
//======================================================================

Fl_Double_Window	*mars_list_window = 0;
Fl_Hold_Browser	*brws_mars_list = (Fl_Hold_Browser *)0;
const int mars_list_widths[] = {80, 170, 30, 0};

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
	Fl_Double_Window* w = new Fl_Double_Window(452, 280, _("Roster"));
	brws_mars_list = new Fl_Hold_Browser(1,1,450,250,"");
	brws_mars_list->column_widths(mars_list_widths);
	Fl_Button *cancel = new Fl_Button(280, 252, 80, 24, "cancel");
	cancel->callback((Fl_Callback*)cb_list_cancel);
	Fl_Button *ok = new Fl_Button(370, 252, 80, 24, "select");
	ok->callback((Fl_Callback*)cb_list_ok);

	FILE	*flist = fopen(progStatus.mars_roster_file.c_str(), "r");
	char *retstr;
	if (flist) {
		char line[80];
		retstr = fgets(line, 80, flist); // header
		line[0] = 0;
		while(fgets(line, 80, flist)) {
			while( line[strlen(line)-1] == '\n') line[strlen(line)-1] = 0;
			while( line[strlen(line)-1] == '\r') line[strlen(line)-1] = 0;
			for (size_t i = 0; i < strlen(line); i++)
				if (line[i] == ',') line[i] = '\t';
			if (strlen(line)) brws_mars_list->add(line);
			line[0] = 0;
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
	string text = inp->value();
	ucase(text);
	inp->value(text.c_str());
}

void cb_mars_text(Fl_Widget *w, void *d)
{
	FTextEdit *inp = (FTextEdit *)w;
	string text = inp->buffer()->text();
	ucase(text);
	inp->clear();
	inp->add(text.c_str());
}

string notail(string s)
{
	static string str = s;
	while (str[str.length()-1] == '\n')
		str.erase(str.length()-1, 1);
	return str;
}
