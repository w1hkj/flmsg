// =====================================================================
//
// ics213.cxx
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

#include "flmsg.h"
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
#include "parse_xml.h"

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

// ICS213 fields

string _213_to = "<to:";
string _213_fm = "<fm:";
string _213_p1 = "<p1:";
string _213_p2 = "<p2:";
string _213_subj = "<sb:";
string _213_d1 = "<d1:";
string _213_t1 = "<t1:";
string _213_msg = "<mg:";
string _213_s1 = "<s1:";
string _213_p3 = "<p3:";
string _213_reply = "<rp:";
string _213_d2 = "<d2:";
string _213_t2 = "<t2:";
string _213_s2 = "<s2:";
string _213_p4 = "<p4:";

string ICS_213_msg = "";
string ICS_213_reply = "";
string buffer;

FIELD fields[] = {
{ _213_to,		"", (Fl_Widget **)&txt_213_to,		't' },
{ _213_p1,		"", (Fl_Widget **)&txt_213_p1,		't' },
{ _213_fm,		"", (Fl_Widget **)&txt_213_fm,		't' },
{ _213_p2,		"", (Fl_Widget **)&txt_213_p2,		't' },
{ _213_d1,		"", (Fl_Widget **)&txt_213_d1,		'd' },
{ _213_t1,		"", (Fl_Widget **)&txt_213_t1,		't' },
{ _213_subj,	"", (Fl_Widget **)&txt_213_subj,	't' },
{ _213_s1,		"", (Fl_Widget **)&txt_213_s1,		't' },
{ _213_p3,		"", (Fl_Widget **)&txt_213_p3,		't' },
{ _213_s2,		"", (Fl_Widget **)&txt_213_s2,		't' },
{ _213_p4,		"", (Fl_Widget **)&txt_213_p4,		't' },
{ _213_d2,		"", (Fl_Widget **)&txt_213_d2,		'd' },
{ _213_t2,		"", (Fl_Widget **)&txt_213_t2,		't' },
{ _213_msg,		"", (Fl_Widget **)&txt_213_msg,		'e' },
{ _213_reply,	"", (Fl_Widget **)&txt_213_reply,	'e' } };

bool using_213Template = false;

string base_213_filename = "";
string def_213_filename = "";
string def_213_TemplateName = "";

int numfields = sizeof(fields) / sizeof(FIELD);

void cb_SetDate1()
{
	txt_213_d1->value(szDate());
}

void cb_SetDate2()
{
	txt_213_d2->value(szDate());
}

void cb_SetTime1()
{
	txt_213_t1->value(szTime(progStatus.UTC));
}

void cb_SetTime2()
{
	txt_213_t2->value(szTime(progStatus.UTC));
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
		else if (fields[i].w_type == 'e')
			fields[i].f_data = ((FTextEdit *)(*fields[i].w))->buffer()->text();
	}
}

void clear_213_form()
{
	clear_fields();
	txt_213_to->value("");
	txt_213_p1->value("");
	txt_213_fm->value("");
	txt_213_p2->value("");
	txt_213_subj->value("");
	txt_213_d1->value("");
	txt_213_t1->value("");
	txt_213_msg->clear();
	txt_213_s1->value("");
	txt_213_p3->value("");
	txt_213_reply->clear();
	txt_213_s2->value("");
	txt_213_d2->value("");
	txt_213_t2->value("");
	txt_213_p4->value("");
	update_fields();
}

void update_form213()
{
	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type == 'd')
			((Fl_DateInput *)(*fields[i].w))->value(fields[i].f_data.c_str());
		else if (fields[i].w_type == 't')
			((Fl_Input2 *)(*fields[i].w))->value(fields[i].f_data.c_str());
		else if (fields[i].w_type == 'e') {
			((FTextEdit *)(*fields[i].w))->clear();
			((FTextEdit *)(*fields[i].w))->add(fields[i].f_data.c_str());
		}
	}
}

void make_buffer()
{
	update_fields();
	buffer = header("<ics213>");
	for (int i = 0; i < numfields; i++)
		buffer.append( lineout( fields[i].f_type, fields[i].f_data ) );
}

void read_213_buffer(string data)
{
	clear_fields();
	for (int i = 0; i < numfields; i++)
		fields[i].f_data = findstr(data, fields[i].f_type);
	update_form213();
}

void cb_213_new()
{
	clear_213_form();
	def_213_filename = ICS_msg_dir;
	def_213_filename.append("new"DATAFILE_EXT);
	using_213Template = false;
	show_filename(def_213_filename);
}

void cb_213_import()
{
	string def_213_filename = ICS_dir;
	def_213_filename.append("DEFAULT.XML");
	const char *p = FSEL::select(
		"Open Qforms xml file",
		"Qforms xml\t*.{xml,XML}",
		def_213_filename.c_str());
	if (p){
		clear_213_form();
		qform_ics_import(p);
		using_213Template = false;
	}
}

void cb_213_export()
{
	string def_213_filename = ICS_dir;
	def_213_filename.append(base_213_filename);
	def_213_filename.append(".XML");
	const char *p = FSEL::saveas(
			"Open Qforms xml file",
			"Qforms xml\t*.{xml,XML}",
			def_213_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_213_filename = p;
		if (strlen(pext) == 0) def_213_filename.append(".XML");
		qform_ics_export(def_213_filename);
	}
}

void cb_213_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_213_form();
	read_213_buffer(inpbuffer);
	def_213_filename = ICS_msg_dir;
	def_213_filename.append(wrapfilename);
	using_213Template = false;
	show_filename(def_213_filename);
}

void cb_213_wrap_export()
{
	if (base_213_filename == "new"DATAFILE_EXT || base_213_filename == "default"DATAFILE_EXT)
		cb_213_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_213_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_buffer();
		export_wrapfile(base_213_filename, wrapfilename, buffer, pext != WRAP_EXT);
	}
}

void cb_213_wrap_autosend()
{
	if (base_213_filename == "new"DATAFILE_EXT || base_213_filename == "default"DATAFILE_EXT)
		cb_213_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buffer();
	export_wrapfile(base_213_filename, wrapfilename, buffer, false);
}

void cb_213_load_template()
{
	string def_213_filename = def_213_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"DATATEMP_EXT,
			def_213_filename.c_str());
	if (p) {
		clear_213_form();
		read_data_file(p);
		def_213_TemplateName = p;
		show_filename(def_213_TemplateName);
		using_213Template = true;
	}
}

void cb_213_save_template()
{
	if (!using_213Template) {
		cb_save_as_template();
		return;
	}
	string def_213_filename = def_213_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"DATATEMP_EXT,
			def_213_filename.c_str());
	if (p)
		write_213(p);
}

void cb_213_save_as_template()
{
	string def_213_filename = def_213_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"DATATEMP_EXT,
			def_213_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_213_TemplateName = p;
		if (strlen(pext) == 0) def_213_TemplateName.append(""DATATEMP_EXT);
		remove_spaces_from_filename(def_213_TemplateName);
		write_213(def_213_TemplateName);
		show_filename(def_213_TemplateName);
		using_213Template = true;
	}
}

void cb_213_open()
{
	const char *p = FSEL::select(_("Open data file"), "F2S\t*"DATAFILE_EXT,
					def_213_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_213_form();
	read_data_file(p);
	using_213Template = false;
	def_213_filename = p;
	show_filename(def_213_filename);
}

void write_213(string s)
{
	FILE *icsfile = fopen(s.c_str(), "w");
	if (!icsfile) return;
	make_buffer();
	fwrite(buffer.c_str(), buffer.length(), 1, icsfile);
	fclose(icsfile);
}

void cb_213_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
	name.append(DATAFILE_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_213_filename;
	p = FSEL::saveas(_("Save data file"), "F2S\t*"DATAFILE_EXT,
					newfilename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	if (progStatus.sernbr_fname) {
		string haystack = p;
		if (haystack.find(newfilename) != string::npos) {
			int n = atoi(progStatus.sernbr.c_str());
			n++;
			char szn[10];
			snprintf(szn, sizeof(szn), "%d", n);
			progStatus.sernbr = szn;
			txt_sernbr->value(szn);
			txt_sernbr->redraw();
		}
	}

	const char *pext = fl_filename_ext(p);
	def_213_filename = p;
	if (strlen(pext) == 0) def_213_filename.append(DATAFILE_EXT);

	remove_spaces_from_filename(def_213_filename);
	write_213(def_213_filename);

	using_213Template = false;
	show_filename(def_213_filename);
}

void cb_213_save()
{
	if (base_213_filename == "new"DATAFILE_EXT || 
		base_213_filename == "default"DATAFILE_EXT ||
		using_213Template == true) {
		cb_213_save_as();
		return;
	}
	write_213(def_213_filename);
	using_213Template = false;
}

void cb_213_html()
{
	string icsname = ICS_dir;
	string html_text = "";
	icsname.append("ics213_doc.html");

	update_fields();
	string form = ics213_html_template;

	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type != 'e')
			replacestr( form, fields[i].f_type, fields[i].f_data );
		else {
			html_text = fields[i].f_data;
			to_html(html_text);
			replacelf(html_text, 20);
			replacestr( form, fields[i].f_type, html_text );
		}
	}

	FILE *icsfile = fopen(icsname.c_str(), "w");
	fprintf(icsfile,"%s", form.c_str());
	fclose(icsfile);

	open_url(icsname.c_str());
}

void cb_213_textout()
{
	string icsname = ICS_dir;
	icsname.append("ics213.txt");

	update_fields();
	string form = ics213_text_template;

	for (int i = 0; i < numfields; i++)
		replacestr( form, fields[i].f_type, fields[i].f_data);

	FILE *icsfile = fopen(icsname.c_str(), "w");
	fprintf(icsfile,"%s", form.c_str());
	fclose(icsfile);

	open_url(icsname.c_str());
}
