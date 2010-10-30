// =====================================================================
//
// blankform.cxx
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

// blankform fields

string blankbuffer;
string def_blank_filename = "";
string base_blank_filename = "";
string def_blank_TemplateName = "";

string blank_msg = "<mg:";
string blank_field;

bool using_blank_template = false;

void clear_blankfields()
{
	blank_field.clear();
}

void update_blankfields()
{
	blank_field = txt_blank_msg->buffer()->text();
}

void clear_blank_form()
{
	clear_blankfields();
	txt_blank_msg->clear();
}

void update_blankform()
{
	txt_blank_msg->clear();
	txt_blank_msg->add(blank_field.c_str());
}

void make_blankbuffer()
{
	update_blankfields();
	blankbuffer = header("<blankform>");
	blankbuffer.append( lineout( blank_msg, blank_field ) );
}

void read_blankbuffer(string data)
{
	clear_blankfields();
	blank_field = findstr(data, blank_msg);
	update_blankform();
}

void cb_blank_new()
{
	clear_blank_form();
	def_blank_filename = ICS_msg_dir;
	def_blank_filename.append("new"BLANKFILE_EXT);
	show_filename(def_blank_filename);
	using_blank_template = false;
}

void cb_blank_import()
{
	fl_alert2("Not implemented");
}

void cb_blank_export()
{
	fl_alert2("Not implemented");
}

void cb_blank_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_blank_form();
	read_blankbuffer(inpbuffer);
	def_blank_filename = ICS_msg_dir;
	def_blank_filename.append(wrapfilename);
	show_filename(def_blank_filename);
	using_blank_template = false;
}

void cb_blank_wrap_export()
{
	if (base_blank_filename == "new"BLANKFILE_EXT || base_blank_filename == "default"BLANKFILE_EXT)
		cb_blank_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_blank_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_blankbuffer();
		export_wrapfile(base_blank_filename, wrapfilename, blankbuffer, pext != WRAP_EXT);
	}
}

void cb_blank_wrap_autosend()
{
	if (base_blank_filename == "new"BLANKFILE_EXT || 
		base_blank_filename == "default"BLANKFILE_EXT ||
		using_blank_template == true)
		cb_blank_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_blankbuffer();
	export_wrapfile(base_blank_filename, wrapfilename, blankbuffer, false);
}

void cb_blank_load_template()
{
	string def_blank_filename = def_blank_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"BLANKTEMP_EXT,
			def_blank_filename.c_str());
	if (p) {
		clear_blank_form();
		read_data_file(p);
		def_blank_TemplateName = p;
		show_filename(def_blank_TemplateName);
		using_blank_template = true;
	}
}

void cb_blank_save_template()
{
	if (!using_blank_template) {
		cb_blank_save_as_template();
		return;
	}
	string def_blank_filename = def_blank_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"BLANKTEMP_EXT,
			def_blank_filename.c_str());
	if (p)
		write_blank(p);
}

void cb_blank_save_as_template()
{
	string def_blank_filename = def_blank_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"BLANKTEMP_EXT,
			def_blank_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_blank_TemplateName = p;
		if (strlen(pext) == 0) def_blank_TemplateName.append(BLANKTEMP_EXT);
		remove_spaces_from_filename(def_blank_TemplateName);
		write_blank(def_blank_TemplateName);
		show_filename(def_blank_TemplateName);
		using_blank_template = true;
	}
}

void cb_blank_open()
{
	const char *p = FSEL::select(_("Open data file"), "b2s\t*.b2s",
					def_blank_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_blank_form();
	read_data_file(p);
	using_blank_template = false;
	def_blank_filename = p;
	show_filename(def_blank_filename);
}

void write_blank(string s)
{
	FILE *blankfile = fopen(s.c_str(), "w");
	if (!blankfile) return;
	make_blankbuffer();
	fwrite(blankbuffer.c_str(), blankbuffer.length(), 1, blankfile);
	fclose(blankfile);
}

void cb_blank_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(".b2s");
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_blank_filename;

	p = FSEL::saveas(_("Save data file"), "b2s\t*.b2s",
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
	def_blank_filename = p;
	if (strlen(pext) == 0) def_blank_filename.append(".b2s");

	remove_spaces_from_filename(def_blank_filename);
	write_blank(def_blank_filename);

	using_blank_template = false;
	show_filename(def_blank_filename);
}

void cb_blank_save()
{
	if (base_blank_filename == "new.b2s" || 
		base_blank_filename == "default.b2s" ||
		using_blank_template == true) {
		cb_blank_save_as();
		return;
	}
	write_blank(def_blank_filename);
	using_blank_template = false;
}

void cb_blank_msg_type()
{
	if (tabs_msg_type->value() == tab_blank ) {
		show_filename(def_blank_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_blank_html()
{
	string blank_name = ICS_dir;
	string html_text = "";
	blank_name.append("blankform_doc.html");

	update_blankfields();
	string blankform = blank_html_template;

	html_text = blank_field;
	to_html(html_text);
	replacelf(html_text);
	replacestr(blankform, blank_msg, html_text);

	FILE *blankfile = fopen(blank_name.c_str(), "w");
	fprintf(blankfile,"%s", blankform.c_str());
	fclose(blankfile);

	open_url(blank_name.c_str());
}

void cb_blank_textout()
{
	string blank_name = ICS_dir;
	blank_name.append("blankform.txt");

	update_blankfields();
	string blankform = blank_txt_template;

	replacestr(blankform, blank_msg, blank_field);

	FILE *blankfile = fopen(blank_name.c_str(), "w");
	fprintf(blankfile,"%s", blankform.c_str());
	fclose(blankfile);

	open_url(blank_name.c_str());
}
