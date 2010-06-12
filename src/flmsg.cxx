// =====================================================================
//
// flmsg.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2010
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  It is
// copyright under the GNU General Public License.
//
// You should have received a copy of the GNU General Public License
// along with the program; if not, write to the Free Software
// Foundation, Inc.
// 59 Temple Place, Suite 330
// Boston, MA  02111-1307 USA
//
// =====================================================================

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/x.H>
#include <FL/Fl_Help_Dialog.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_File_Icon.H>

#include "config.h"
#include "flmsg_config.h"

#include "templates.h"
#include "debug.h"
#include "util.h"
#include "gettext.h"
#include "flmsg_dialog.h"
#include "flinput2.h"
#include "date.h"
#include "calendar.h"
#include "icons.h"
#include "fileselect.h"
#include "wrap.h"
#include "status.h"

#ifdef WIN32
#  include "flmsgrc.h"
#  include "compat.h"
#  define dirent fl_dirent_no_thanks
#endif

#include <FL/filename.H>
#ifdef __MINGW32__
#  undef dirent
#endif
#include <dirent.h>

#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Image.H>

using namespace std;

Fl_Double_Window *mainwindow = 0;
Fl_Double_Window *optionswindow = 0;
Fl_Double_Window *arlwindow = 0;
Fl_Double_Window *configwindow = 0;
Fl_Double_Window *hxwindow = 0;

string title;
string flmsgHomeDir;

// flarq, fldigi, flmsg, flwrap share a common NBEMS directory

string NBEMS_dir;
string ARQ_dir;
string ARQ_files_dir;
string ARQ_recv_dir;
string ARQ_send;
string WRAP_dir;
string WRAP_recv_dir;
string WRAP_send_dir;
string WRAP_auto_dir;
string ICS_dir;
string ICS_msg_dir;
string ICS_tmp_dir;

string baseFileName = "";
string defFileName = "";
string defTemplateName = "";
string defRTFname = "";

bool usingTemplate = false;

// utility functions

void remove_spaces_from_filename(string &fname)
{
	size_t n = fname.length();
	char szfname[n + 1];
	char *p;
	memset(szfname, 0, n + 1);
	strcpy(szfname, fname.c_str());
	p = (char *)fl_filename_name(szfname);
	while (*p) {
		if (*p == ' ') *p = '_';
		p++;
	}
	fname = szfname;
}

char *szTime(int typ)
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	switch (typ) {
		case 0:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H%M", &sTime);
			break;
		case 1:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H:%M", &sTime);
			break;
		case 2:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H%MZ", &sTime);
			break;
		case 3:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H:%MZ", &sTime);
			break;
		case 4:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H%M UTC", &sTime);
			break;
		case 5:
			gmtime_r (&tmptr, &sTime);
			strftime(szDt, 79, "%H:%M UTC", &sTime);
			break;
		default:
			localtime_r(&tmptr, &sTime);
			strftime(szDt, 79, "%H%ML", &sTime);
	}
	return szDt;
}

char *szDate()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (progStatus.UTC) {
		gmtime_r (&tmptr, &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
	}
	switch (progStatus.dtformat) {
		case 1: strftime(szDt, 79, "%m/%d/%y", &sTime); break;
		case 2: strftime(szDt, 79, "%d/%m/%y", &sTime); break;
		case 0:
		default:
			strftime(szDt, 79, "%Y-%m-%d", &sTime);
	}
	return szDt;
}

char *szAbbrevDate()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (progStatus.UTC) {
		gmtime_r (&tmptr, &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
	}
	strftime(szDt, 79, "%b %d", &sTime);
	for (int i = 0; i < 3; i++) szDt[i] = toupper(szDt[i]);
	return szDt;
}

char *szDateTime()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (progStatus.UTC) {
		gmtime_r (&tmptr, &sTime);
		strftime(szDt, 79, "%0d%0H%0MZ %b %Y", &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
		strftime(szDt, 79, "%0d%0H%0ML %b %Y", &sTime);
	}
	for (size_t i = 0; i < strlen(szDt); i++) szDt[i] = toupper(szDt[i]);
	return szDt;
}

//

void cb_new()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_new();
	else cb_rg_new();
}

void cb_import()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_import();
	else cb_rg_import();
}

void cb_export()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_export();
	else cb_rg_export();
}

void cb_wrap_import()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_wrap_import();
	else cb_rg_wrap_import();
}

void cb_wrap_export()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_wrap_export();
	else cb_rg_wrap_export();
}

void cb_wrap_autosend()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_wrap_autosend();
	else cb_rg_wrap_autosend();
}

void cb_load_template()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_load_template();
}

void cb_save_template()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_save_template();
}

void cb_save_as_template()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_save_as_template();
}

void cb_open()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_open();
	else cb_rg_open();
}

void cb_save_as()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_save_as();
	else cb_rg_save_as();
}

void cb_save()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_save();
	else cb_rg_save();
}

void cb_write()
{
}

void cb_html()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_html();
	else cb_rg_html();
}

void cb_html_fcopy()
{
	if (tabs_msg_type->value() == tab_ics213) ;
	else cb_rg_html_fcopy();
}

void cb_rtf()
{
	if (tabs_msg_type->value() == tab_ics213) cb_ics_write();
	else cb_rg_rtf();
}

void cb_text()
{
	if (tabs_msg_type->value() == tab_ics213) ;
	else cb_rg_textout();
}

void cb_exit()
{
	progStatus.saveLastState();
	FSEL::destroy();
	exit(0);
}

void exit_main(Fl_Widget *w)
{
	if (Fl::event_key() == FL_Escape)
		return;
	cb_exit();
}

void cb_About()
{
	fl_alert2(_("Version "PACKAGE_VERSION));
}

void show_filename(string p)
{
	baseFileName = fl_filename_name(p.c_str());
	txt_filename->value(baseFileName.c_str());
	txt_filename->redraw();
}

void set_main_label()
{
	string main_label = PACKAGE_NAME;
	main_label.append(": ").append(PACKAGE_VERSION);
	mainwindow->label(main_label.c_str());
}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		if (strcasecmp("--help", argv[1]) == 0) {
			printf("\
  --help this help text\n\
  --version\n\
\n\
  Usage: flmsg\n");
			return 0;
		} 
		if (strcasecmp("--version", argv[1]) == 0) {
			printf("Version: "VERSION"\n");
			return 0;
		}
	}

	mainwindow = ics_dialog();
	configwindow = config_dialog();

char dirbuf[FL_PATH_MAX + 1];
#ifdef __WIN32__
	fl_filename_expand(dirbuf, sizeof(dirbuf) - 1, "$USERPROFILE/NBEMS.files/");
#else
	fl_filename_expand(dirbuf, sizeof(dirbuf) - 1, "$HOME/.nbems/");
#endif
	NBEMS_dir = dirbuf;
	checkdirectories();

	defFileName = ICS_msg_dir;
	defFileName.append("default"DATAFILE_EXT);
	defRTFname = ICS_dir;
	defRTFname.append("default.rtf");
	defTemplateName = ICS_tmp_dir;
	defTemplateName.append("default.f2t");

	def_rgFileName = ICS_msg_dir;
	def_rgFileName.append("default"RGFILE_EXT);
	set_rg_choices();

	Fl_File_Icon::load_system_icons();
	FSEL::create();

	int arg_idx;
	if (Fl::args(argc, argv, arg_idx, parse_args) != argc)
		showoptions();

	progStatus.loadLastState();

	mainwindow->resize( progStatus.mainX, progStatus.mainY, mainwindow->w(), mainwindow->h());

	tab_ics213->show();

#ifdef WIN32
	mainwindow->icon((char*)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));
	mainwindow->show(1, argv);
#else
	mainwindow->show(argc, argv);
#endif
	set_main_label();
	show_filename(defFileName);

	return Fl::run();
}

void checkdirectories(void)
{
	struct DIRS {
		string& dir;
		const char* suffix;
		void (*new_dir_func)(void);
	};
	DIRS NBEMS_dirs[] = {
		{ NBEMS_dir,     0, 0 },
		{ ARQ_dir,       "ARQ", 0 },
		{ ARQ_files_dir, "ARQ/files", 0 },
		{ ARQ_recv_dir,  "ARQ/recv", 0 },
		{ ARQ_send,      "ARQ/send", 0 },
		{ WRAP_dir,      "WRAP", 0 },
		{ WRAP_recv_dir, "WRAP/recv", 0 },
		{ WRAP_send_dir, "WRAP/send", 0 },
		{ WRAP_auto_dir, "WRAP/auto", 0 },
		{ ICS_dir,       "ICS", 0 },
		{ ICS_msg_dir,   "ICS/messages", 0 },
		{ ICS_tmp_dir,   "ICS/templates", 0 },
	};

	int r;

	for (size_t i = 0; i < sizeof(NBEMS_dirs)/sizeof(*NBEMS_dirs); i++) {
		if (NBEMS_dirs[i].suffix)
			NBEMS_dirs[i].dir.assign(NBEMS_dir).append(NBEMS_dirs[i].suffix).append(PATH_SEP);

		if ((r = mkdir(NBEMS_dirs[i].dir.c_str(), 0777)) == -1 && errno != EEXIST) {
			cerr << _("Could not make directory") << ' ' << NBEMS_dirs[i].dir
			     << ": " << strerror(errno) << '\n';
			exit(EXIT_FAILURE);
		}
		else if (r == 0 && NBEMS_dirs[i].new_dir_func)
			NBEMS_dirs[i].new_dir_func();
	}
}

const char *options[] = {\
"-bg\t-background [COLOR]",
"-bg2\t-background2 [COLOR]",
"-di\t-display [host:n.n]",
"-dn\t-dnd : enable drag and drop",
"-nodn\t-nodnd : disable drag and drop",
"-fg\t-foreground [COLOR]",
"-g\t-geometry [WxH+X+Y]",
"-i\t-iconic",
"-k\t-kbd : enable keyboard focus:",
"-nok\t-nokbd : en/disable keyboard focus",
"-na\t-name [CLASSNAME]",
"-s\t-scheme [plastic | gtk+]",
"-ti\t-title [WINDOWTITLE]",
"-to\t-tooltips : enable tooltips",
"-not\t-notooltips : disable tooltips\n",
0
};

const int widths[] = {60, 0};

void showoptions()
{
	if (!optionswindow) {
		optionswindow = optionsdialog();
		brwsOptions->column_widths(widths);
		for (int i = 0; options[i] != 0; i++)
			brwsOptions->add(options[i]);
	}
	optionswindow->show();
}

void closeoptions()
{
	optionswindow->hide();
}

void cb_config()
{
	btn_compress->value(progStatus.compression);

	btn_dtformat0->value(progStatus.dtformat == 0);
	btn_dtformat1->value(progStatus.dtformat == 1);
	btn_dtformat2->value(progStatus.dtformat == 2);

	btn_utc_format0->value(progStatus.UTC == 0);
	btn_utc_format1->value(progStatus.UTC == 1);
	btn_utc_format2->value(progStatus.UTC == 2);
	btn_utc_format3->value(progStatus.UTC == 3);
	btn_utc_format4->value(progStatus.UTC == 4);
	btn_utc_format5->value(progStatus.UTC == 5);

	txt_my_call->value(progStatus.my_call.c_str());
	txt_my_name->value(progStatus.my_name.c_str());
	txt_my_addr->value(progStatus.my_addr.c_str());
	txt_my_city->value(progStatus.my_city.c_str());
	txt_my_tel->value(progStatus.my_tel.c_str());
	cnt_wpl->value(progStatus.wpl);

	configwindow->show();
}

void cb_close_config()
{
	configwindow->hide();
}

void show_help()
{
	open_url("http://www.w1hkj.com/flmsg-help/index.html");
}

int parse_args(int argc, char **argv, int& idx)
{
// Only handle a filename option
	if ( argv[idx][0] == '-' )
		return 0;

string fname = argv[idx];
	if (fname.find(".f2s")) {
		clear_ics_form();
		defFileName = fname;
		read_ics(defFileName);
		usingTemplate = false;
		show_filename(defFileName);
	}
	else if (fname.find(".f2t")) {
		clear_ics_form();
		defFileName = fname;
		read_ics(defFileName);
		usingTemplate = true;
		show_filename(defFileName);
	}

	idx++;
	return 1;
}

void open_url(const char* url)
{
#ifndef __WOE32__
	const char* browsers[] = {
#  ifdef __APPLE__
		getenv("FLDIGI_BROWSER"), // valid for any OS - set by user
		"open"                    // OS X
#  else
		"fl-xdg-open",            // Puppy Linux
		"xdg-open",               // other Unix-Linux distros
		getenv("FLDIGI_BROWSER"), // force use of spec'd browser
		getenv("BROWSER"),        // most Linux distributions
		"sensible-browser",
		"firefox",
		"mozilla"                 // must be something out there!
#  endif
	};
	switch (fork()) {
	case 0:
#  ifndef NDEBUG
		unsetenv("MALLOC_CHECK_");
		unsetenv("MALLOC_PERTURB_");
#  endif
		for (size_t i = 0; i < sizeof(browsers)/sizeof(browsers[0]); i++)
			if (browsers[i])
				execlp(browsers[i], browsers[i], url, (char*)0);
		exit(EXIT_FAILURE);
	case -1:
		fl_alert2(_("Could not run a web browser:\n%s\n\n"
			 "Open this URL manually:\n%s"),
			 strerror(errno), url);
	}
#else
	if ((int)ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL) <= 32)
		fl_alert2(_("Could not open url:\n%s\n"), url);
#endif
}
