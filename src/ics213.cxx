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
#include "flics_config.h"

#include "ics213_template.h"
#include "debug.h"
#include "util.h"
#include "gettext.h"
#include "ics213_dialog.h"
#include "flinput2.h"
#include "date.h"
#include "calendar.h"
#include "icons.h"
#include "fileselect.h"
#include "wrap.h"

#ifdef WIN32
#  include "flicsrc.h"
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

void checkdirectories(void);
int parse_args(int argc, char **argv, int& idx);
void showoptions();

Fl_Double_Window *mainwindow = 0;
Fl_Double_Window *optionswindow = 0;
string title;

// flarq, fldigi, flics, flwrap share a common NBEMS directory

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

const char * _to = "<to:";
const char * _fm = "<fm:";
const char * _p1 = "<p1:";
const char * _p2 = "<p2:";
const char * _subj = "<sb:";
const char * _d1 = "<d1:";
const char * _t1 = "<t1:";
const char * _msg = "<mg:";
const char * _s1 = "<s1:";
const char * _p3 = "<p3:";
const char * _reply = "<rp:";
const char * _d2 = "<d2:";
const char * _t2 = "<t2:";
const char * _s2 = "<s2:";
const char * _p4 = "<p4:";

string ICS_msg = "";
string ICS_reply = "";
string buffer;

FIELD fields[] = {
{ _to,	"", (Fl_Widget **)&txt_To,	't' },
{ _p1,	"", (Fl_Widget **)&txt_P1,	't' },
{ _fm,	"", (Fl_Widget **)&txt_Fm,	't' },
{ _p2,	"", (Fl_Widget **)&txt_P2,	't' },
{ _d1,	"", (Fl_Widget **)&txt_D1,	'd' },
{ _t1,	"", (Fl_Widget **)&txt_T1,	't' },
{ _subj,  "", (Fl_Widget **)&txt_Subj,  't' },
{ _s1,	"", (Fl_Widget **)&txt_S1,	't' },
{ _p3,	"", (Fl_Widget **)&txt_P3,	't' },
{ _s2,	"", (Fl_Widget **)&txt_S2,	't' },
{ _p4,	"", (Fl_Widget **)&txt_P4,	't' },
{ _d2,	"", (Fl_Widget **)&txt_D2,	'd' },
{ _t2,	"", (Fl_Widget **)&txt_T2,	't' },
{ _msg,   "", (Fl_Widget **)&txt_Msg,   'e' },
{ _reply, "", (Fl_Widget **)&txt_Reply, 'e' } };

int numfields = sizeof(fields) / sizeof(FIELD);

bool useZulu = true;

void removespaces(string &fname)
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

void cb_useZulu(bool use)
{
	useZulu = use;
}

char *szTime()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (useZulu) {
		gmtime_r (&tmptr, &sTime);
		strftime(szDt, 79, "%H:%M UTC", &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
		strftime(szDt, 79, "%H:%M", &sTime);
	}
	return szDt;
}

char *szDate()
{
	static char szDt[80];
	time_t tmptr;
	tm sTime;
	time (&tmptr);
	if (useZulu) {
		gmtime_r (&tmptr, &sTime);
	} else {
		localtime_r(&tmptr, &sTime);
	}
	strftime(szDt, 79, "%Y-%m-%d", &sTime);
	return szDt;
}

void cb_SetDate1()
{
	txt_D1->value(szDate());
}

void cb_SetDate2()
{
	txt_D2->value(szDate());
}

void cb_SetTime1()
{
	txt_T1->value(szTime());
}

void cb_SetTime2()
{
	txt_T2->value(szTime());
}

void clear_fields()
{
	for (int i = 0; i < numfields; i++)
		fields[i].f_data.clear();
}

void update_fields()
{
	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type == 'd')
			fields[i].f_data = ((Fl_DateInput *)(*fields[i].w))->value();
		else if (fields[i].w_type == 't')
			fields[i].f_data = ((Fl_Input2 *)(*fields[i].w))->value();
		else if (fields[i].f_type == _msg) {
			char *txt = txt_Msg->buffer()->text();
			fields[i].f_data = txt;
			free(txt);
		}
		else if (fields[i].f_type == _reply) {
			char *txt = txt_Reply->buffer()->text();
			fields[i].f_data = txt;
			free(txt);
		}
	}
}

void clear_form()
{
	clear_fields();
	txt_To->value("");
	txt_P1->value("");
	txt_Fm->value("");
	txt_P2->value("");
	txt_Subj->value("");
	txt_D1->value("");
	txt_T1->value("");
	txt_Msg->clear();
	txt_S1->value("");
	txt_P3->value("");
	txt_Reply->clear();
	txt_S2->value("");
	txt_D2->value("");
	txt_T2->value("");
	txt_P4->value("");
	update_fields();
}

void make_buffer()
{
	char sznum[80];
	update_fields();
	buffer.clear();
	buffer.append("<flics>");
	buffer.append(PACKAGE_VERSION);
	buffer += '\n';
	for (int i = 0; i < numfields; i++) {
		snprintf(sznum, sizeof(sznum), "%0d", strlen(fields[i].f_data.c_str()));
		buffer.append(fields[i].f_type);
		buffer.append(sznum);
		buffer += ' ';
		buffer.append(fields[i].f_data);
		buffer += '\n';
	}
}

void read_buffer(string data)
{
	const char *buff = data.c_str();
	const char *p1 = data.c_str();
	const char *p2;
	const char *buffend = p1 + data.length();
	clear_fields();
// search the file buffer for each of the ics fields
	for (int i = 0; i < numfields; i++) {
		p1 = strstr(buff, fields[i].f_type);
		if (p1) {
			int nchars;
			p2 = p1 + strlen(fields[i].f_type);
			sscanf(p2, "%d", &nchars);
			if (nchars) {
				p2 = strchr(p2, ' ') + 1;
				if (p2 < buffend && p2 + nchars < buffend)
					for ( int ch = 0; ch < nchars; ch++, p2++)
						fields[i].f_data += *p2;
				if (fields[i].w_type == 'd')
					((Fl_DateInput *)(*fields[i].w))->value(fields[i].f_data.c_str());
				else if (fields[i].w_type == 't')
					((Fl_Input2 *)(*fields[i].w))->value(fields[i].f_data.c_str());
				else if (fields[i].f_type == _msg) {
					txt_Msg->clear();
					txt_Msg->addstr(fields[i].f_data.c_str());
				} else if (fields[i].f_type == _reply) {
					txt_Reply->clear();
					txt_Reply->addstr(fields[i].f_data.c_str());
				}
			}
		}
	}
}

void cb_new()
{
	clear_form();
	defFileName = ICS_msg_dir;
	defFileName.append("new"DATAFILE_EXT);
	show_filename(defFileName);
}

void cb_import()
{
extern void qform_import(string);
	string deffilename = ICS_dir;
	deffilename.append("DEFAULT.XML");
	const char *p = FSEL::select(
		"Open Qforms xml file",
		"Qforms xml\t*.{xml,XML}",
		deffilename.c_str());
	if (p){
		clear_form();
		qform_import(p);
	}
}

void cb_export()
{
extern void qform_export(string);
	string deffilename = ICS_dir;
	deffilename.append(baseFileName);
	deffilename.append(".XML");
	const char *p = FSEL::saveas(
			"Open Qforms xml file",
			"Qforms xml\t*.{xml,XML}",
			deffilename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		deffilename = p;
		if (strlen(pext) == 0) deffilename.append(".XML");
		qform_export(deffilename);
	}
}

void cb_wrap_import()
{
	string wrapfilename = WRAP_recv_dir;
	string inpbuffer;
	bool isok;
	wrapfilename.append("default.wrap");
	const char *p = FSEL::select(
		"Import wrapped ICS-213 file",
		"Wrap file\t*.{wrap,WRAP}",
		wrapfilename.c_str());
	if (p){
		clear_form();
		isok = import_wrapfile(p, wrapfilename, inpbuffer);
		read_buffer(inpbuffer);
		defFileName = ICS_msg_dir;
		defFileName.append(wrapfilename);
		show_filename(defFileName);
	}
}

void cb_wrap_export()
{
	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(baseFileName);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		wrapfilename = p;
		if (strlen(pext) == 0) wrapfilename.append(".wrap");
		make_buffer();
		export_wrapfile(baseFileName, wrapfilename, buffer);
	}
}

void cb_wrap_autosend()
{
	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buffer();
	export_wrapfile(baseFileName, wrapfilename, buffer);
}

void cb_load_template()
{
	string deffilename = defTemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*.f2t",
			deffilename.c_str());
	if (p) {
		clear_form();
		read_ics(p);
		defTemplateName = p;
		show_filename(defTemplateName);
		usingTemplate = true;
	}
}

void cb_save_template()
{
	if (!usingTemplate) {
		cb_save_as_template();
		return;
	}
	string deffilename = defTemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*.f2t",
			deffilename.c_str());
	if (p)
		write_ics(p);
}

void cb_save_as_template()
{
	string deffilename = defTemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*.f2t",
			deffilename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		defTemplateName = p;
		if (strlen(pext) == 0) defTemplateName.append(".f2t");
		removespaces(defTemplateName);
		write_ics(defTemplateName);
		show_filename(defTemplateName);
		usingTemplate = true;
	}
}

void read_ics(string s)
{
//	defFileName = s;
	long filesize = 0;
	char *buff, *buffend;
	int retval;
	FILE *icsfile;

	icsfile = fopen (s.c_str(), "r");
	if (!icsfile)
		return;
// determine its size for buffer creation
	fseek (icsfile, 0, SEEK_END);
	filesize = ftell (icsfile);
	buff = new char[filesize + 1];
// read the entire file into the buffer
	fseek (icsfile, 0, SEEK_SET);
	retval = fread (buff, filesize, 1, icsfile);
	fclose (icsfile);
	buffend = buff + filesize;

// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
		return;
	}

	read_buffer(buff);

	if (strstr(buff, "<flics") != buff) {
		fl_alert2(_("Not an flics data file"));
		return;
	}
// file is OK
	clear_fields();
	char *p1 = buff, *p2;
// search the file buffer for each of the ics fields
	for (int i = 0; i < numfields; i++) {
		p1 = strstr(buff, fields[i].f_type);
		if (p1) {
			int nchars;
			p2 = p1 + strlen(fields[i].f_type);
			sscanf(p2, "%d", &nchars);
			if (nchars) {
				p2 = strchr(p2, ' ') + 1;
				if (p2 < buffend && p2 + nchars < buffend)
					for ( int ch = 0; ch < nchars; ch++, p2++)
						fields[i].f_data += *p2;
				if (fields[i].w_type == 'd')
					((Fl_DateInput *)(*fields[i].w))->value(fields[i].f_data.c_str());
				else if (fields[i].w_type == 't')
					((Fl_Input2 *)(*fields[i].w))->value(fields[i].f_data.c_str());
				else if (fields[i].f_type == _msg) {
					txt_Msg->clear();
					txt_Msg->addstr(fields[i].f_data.c_str());
				} else if (fields[i].f_type == _reply) {
					txt_Reply->clear();
					txt_Reply->addstr(fields[i].f_data.c_str());
				}
			}
		}
	}
	delete [] buff;

}

void cb_open()
{
	const char *p = FSEL::select(_("Open data file"), "F2S\t*"DATAFILE_EXT,
					defFileName.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_form();
	read_ics(p);
	usingTemplate = false;
	defFileName = p;
	show_filename(defFileName);
}

void write_ics(string s)
{
#ifdef __WIN32__
	FILE *icsfile = fopen(s.c_str(), "wb");
#else
	FILE *icsfile = fopen(s.c_str(), "w");
#endif
	if (!icsfile) return;
	make_buffer();
	fwrite(buffer.c_str(), buffer.length(), 1, icsfile);
	fclose(icsfile);
}

void cb_save_as()
{
	const char *p;
	string newfilename;
	if (usingTemplate) {
		newfilename = ICS_msg_dir;
		newfilename.append(fl_filename_name ( defTemplateName.c_str() ));
		size_t ext = newfilename.find(".f2t");
		if (ext != string::npos) newfilename.erase(ext, 4);
		newfilename.append(".f2s");
	} else newfilename = defFileName;

	p = FSEL::saveas(_("Save data file"), "F2S\t*"DATAFILE_EXT,
					newfilename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;

	const char *pext = fl_filename_ext(p);
	defFileName = p;
	if (strlen(pext) == 0) defFileName.append(".f2s");
	removespaces(defFileName);
	write_ics(defFileName);
	show_filename(defFileName);
	usingTemplate = false;
}

void cb_save()
{
	if (baseFileName == "new.f2s" || baseFileName == "default.f2s") {
		cb_save_as();
		return;
	}
	if (usingTemplate) {
		fl_alert2("Template file, use 'save as'");
		return;
	}
	write_ics(defFileName);
}

void cb_write()
{
	const char *p;
	string rtfname;
	rtfname = ICS_dir;
	if (usingTemplate) {
		rtfname.append(fl_filename_name ( defTemplateName.c_str() ));
		size_t ext = rtfname.find(".f2t");
		if (ext != string::npos) rtfname.erase(ext, 4);
	} else {
		rtfname.append(fl_filename_name ( defFileName.c_str() ));
		size_t ext = rtfname.find(".f2s");
		if (ext != string::npos) rtfname.erase(ext, 4);
	}
	rtfname.append(".rtf");

	p = FSEL::saveas(_("Write Rich Text Format file"), "RTF\t*.rtf",
					rtfname.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;

	const char *pext = fl_filename_ext(p);
	rtfname = p;
	if (strlen(pext) == 0)
		rtfname.append(".rtf");
	removespaces(rtfname);

	update_fields();

	string form = rtf_template;
	FILE *rtf_file = fopen(rtfname.c_str(), "w");

	ICS_msg = fields[numfields-2].f_data;
	ICS_reply = fields[numfields-1].f_data;

	size_t pos = ICS_msg.find('\n');
	while (pos != string::npos) {
		ICS_msg.replace(pos, 1, nuline);
		pos = ICS_msg.find( '\n', pos + strlen(nuline) );
	}
	pos = ICS_reply.find('\n');
	while (pos != string::npos) {
		ICS_reply.replace(pos, 1, nuline);
		pos = ICS_reply.find( '\n', pos + strlen(nuline) );
	}
	for (int i = 0; i < numfields - 2; i++)
		form.replace(	form.find(fields[i].f_type),
						strlen(fields[i].f_type),
						fields[i].f_data );
	form.replace(	form.find(fields[numfields-2].f_type),
					strlen(fields[numfields-2].f_type),
					ICS_msg);
	form.replace(	form.find(fields[numfields-1].f_type),
					strlen(fields[numfields-1].f_type),
					ICS_reply);
	fprintf(rtf_file,"%s", form.c_str());
	fclose(rtf_file);
}

void cb_exit()
{
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
  Usage: flics\n");
			return 0;
		} 
		if (strcasecmp("--version", argv[1]) == 0) {
			printf("Version: "VERSION"\n");
			return 0;
		}
	}

	mainwindow = ics_dialog();

char dirbuf[FL_PATH_MAX + 1];
#ifdef __WIN32__
	fl_filename_expand(dirbuf, sizeof(dirbuf) - 1, "$USERPROFILE/NBEMS.files/");
#else
	fl_filename_expand(dirbuf, sizeof(dirbuf) - 1, "$HOME/NBEMS.files/");
#endif
	NBEMS_dir = dirbuf;
	checkdirectories();
	defFileName = ICS_msg_dir;
	defFileName.append("default"DATAFILE_EXT);
	defRTFname = ICS_dir;
	defRTFname.append("default.rtf");
	defTemplateName = ICS_tmp_dir;
	defTemplateName.append("default.f2t");

	Fl_File_Icon::load_system_icons();
	FSEL::create();

	int arg_idx;
	if (Fl::args(argc, argv, arg_idx, parse_args) != argc)
		showoptions();

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

int parse_args(int argc, char **argv, int& idx)
{
// Only handle a filename option
	if ( argv[idx][0] == '-' )
		return 0;

string fname = argv[idx];
	if (fname.find(".f2s")) {
		clear_form();
		defFileName = fname;
		read_ics(defFileName);
		usingTemplate = false;
		show_filename(defFileName);
	}
	else if (fname.find(".f2t")) {
		clear_form();
		defFileName = fname;
		read_ics(defFileName);
		usingTemplate = true;
		show_filename(defFileName);
	}

	idx++;
	return 1;
}
