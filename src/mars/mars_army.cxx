// =====================================================================
//
// mars_army.cxx
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

const char army_precedent[] = "RPOZM";

string mars_army_prec	= ":pre:";
string mars_army_dtg	= ":dtg:";
string mars_army_fm		= ":fm:";
string mars_army_to		= ":to:";
string mars_army_info	= ":info:";
string mars_army_subj	= ":subj:";
string mars_army_text	= ":text:";

string s_mars_army_prec;
string s_mars_army_dtg;
string s_mars_army_fm;
string s_mars_army_to;
string s_mars_army_subj;
string s_mars_army_info;
string s_mars_army_text;

string buffmars_army;
string def_mars_army_filename = "";
string base_mars_army_filename = "";
string def_mars_army_TemplateName = "";

bool using_mars_army_template = false;

void clear_mars_armyfields()
{
	s_mars_army_prec = "R";
	s_mars_army_dtg.clear();
	s_mars_army_fm.clear();
	s_mars_army_to.clear();
	s_mars_army_subj.clear();
	s_mars_army_info.clear();
	s_mars_army_text.clear();
}

void update_mars_armyfields()
{
	s_mars_army_prec.clear();
	s_mars_army_prec = army_precedent[sel_mars_army_prec->value()];
	s_mars_army_dtg = txt_mars_army_dtg->value();
	s_mars_army_fm = txt_mars_army_fm->value();
	s_mars_army_to = txt_mars_army_to->buffer()->text();
	s_mars_army_info = txt_mars_army_info->buffer()->text();
	s_mars_army_subj = txt_mars_army_subj->value();
	s_mars_army_text = txt_mars_army_text->buffer()->text();
}

void update_mars_armyform()
{
	size_t n = strchr(army_precedent, s_mars_army_prec[0]) - army_precedent;
	if (n < 0) n = 0;
	if (n > 4) n = 4;
	sel_mars_army_prec->value(n);

	txt_mars_army_dtg->value(s_mars_army_dtg.c_str());
	txt_mars_army_fm->value(s_mars_army_fm.c_str());
	txt_mars_army_to->add(s_mars_army_to.c_str());
	txt_mars_army_info->add(s_mars_army_info.c_str());
	txt_mars_army_subj->value(s_mars_army_subj.c_str());
	txt_mars_army_text->add(s_mars_army_text.c_str());

}

void clear_mars_army_form()
{
	clear_mars_armyfields();
	sel_mars_army_prec->value(0);
	txt_mars_army_dtg->value("");
	txt_mars_army_fm->value("");

	txt_mars_army_to->clear();
	txt_mars_army_info->clear();
	txt_mars_army_subj->value("");
	txt_mars_army_text->clear();
}

void make_buffmars_army()
{
	update_mars_armyfields();
	buffmars_army = header("<mars_army>");

	buffmars_army.append( lineout( mars_army_prec,		s_mars_army_prec ) );
	buffmars_army.append( lineout( mars_army_dtg,		s_mars_army_dtg ) );
	buffmars_army.append( lineout( mars_army_fm,		s_mars_army_fm ) );
	buffmars_army.append( lineout( mars_army_to,		s_mars_army_to ) );
	buffmars_army.append( lineout( mars_army_info,		s_mars_army_info ) );
	buffmars_army.append( lineout( mars_army_subj,		s_mars_army_subj ) );
	buffmars_army.append( lineout( mars_army_text,		s_mars_army_text ) );
}

void read_mars_army_buffer(string data)
{
	clear_mars_armyfields();
// search the file buffer for each of the mars_army fields
	s_mars_army_prec = findstr( data, mars_army_prec );
	s_mars_army_dtg = findstr( data, mars_army_dtg );
	s_mars_army_fm = findstr( data, mars_army_fm );
	s_mars_army_to = findstr( data, mars_army_to );
	s_mars_army_info = findstr( data, mars_army_info );
	s_mars_army_subj = findstr( data, mars_army_subj );
	s_mars_army_text = findstr( data, mars_army_text );

	update_mars_armyform();
}

void cb_mars_army_new()
{
	clear_mars_army_form();
	def_mars_army_filename = ICS_msg_dir;
	def_mars_army_filename.append("new"FMARSARMY_EXT);
	show_filename(def_mars_army_filename);
	using_mars_army_template = false;
}

void cb_mars_army_import()
{
	fl_alert2("Not implemented");
}

void cb_mars_army_export()
{
	fl_alert2("Not implemented");
}

void cb_mars_army_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_mars_army_form();
	read_mars_army_buffer(inpbuffer);
	def_mars_army_filename = ICS_msg_dir;
	def_mars_army_filename.append(wrapfilename);
	show_filename(def_mars_army_filename);
	using_mars_army_template = false;
}

void cb_mars_army_wrap_export()
{
	if (base_mars_army_filename == "new"FMARSARMY_EXT || base_mars_army_filename == "default"FMARSARMY_EXT)
		cb_mars_army_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_army_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_buffmars_army();
		export_wrapfile(base_mars_army_filename, wrapfilename, buffmars_army, pext != ".wrap");
	}
}

void cb_mars_army_wrap_autosend()
{
	if (base_mars_army_filename == "new"FMARSARMY_EXT || 
		base_mars_army_filename == "default"FMARSARMY_EXT ||
		using_mars_army_template == true)
		cb_mars_army_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buffmars_army();
	export_wrapfile(base_mars_army_filename, wrapfilename, buffmars_army, false);
}

void cb_mars_army_load_template()
{
	string def_mars_army_filename = def_mars_army_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"TMARSARMY_EXT,
			def_mars_army_filename.c_str());
	if (p) {
		clear_mars_army_form();
		read_data_file(p);
		def_mars_army_TemplateName = p;
		show_filename(def_mars_army_TemplateName);
		using_mars_army_template = true;
	}
}

void cb_mars_army_save_template()
{
	if (!using_mars_army_template) {
		cb_mars_army_save_as_template();
		return;
	}
	string def_mars_army_filename = def_mars_army_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"TMARSARMY_EXT,
			def_mars_army_filename.c_str());
	if (p)
		write_mars_army(p);
}

void cb_mars_army_save_as_template()
{
	string def_mars_army_filename = def_mars_army_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"TMARSARMY_EXT,
			def_mars_army_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_army_TemplateName = p;
		if (strlen(pext) == 0) def_mars_army_TemplateName.append(TMARSARMY_EXT);
		remove_spaces_from_filename(def_mars_army_TemplateName);
		write_mars_army(def_mars_army_TemplateName);
		show_filename(def_mars_army_TemplateName);
		using_mars_army_template = true;
	}
}

void cb_mars_army_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-mars_army\t*"FMARSARMY_EXT,
					def_mars_army_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_army_form();
	read_data_file(p);
	using_mars_army_template = false;
	def_mars_army_filename = p;
	show_filename(def_mars_army_filename);
}

void write_mars_army(string s)
{
	FILE *filemars_army = fopen(s.c_str(), "w");
	if (!filemars_army) return;
	make_buffmars_army();
	fwrite(buffmars_army.c_str(), buffmars_army.length(), 1, filemars_army);
	fclose(filemars_army);
}

void cb_mars_army_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FMARSARMY_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_army_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-mars_army\t*"FMARSARMY_EXT,
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
	def_mars_army_filename = p;
	if (strlen(pext) == 0) def_mars_army_filename.append(FMARSARMY_EXT);

	remove_spaces_from_filename(def_mars_army_filename);
	write_mars_army(def_mars_army_filename);

	using_mars_army_template = false;
	show_filename(def_mars_army_filename);
}

void cb_mars_army_save()
{
	if (base_mars_army_filename == "new"FMARSARMY_EXT || 
		base_mars_army_filename == "default"FMARSARMY_EXT ||
		using_mars_army_template == true) {
		cb_mars_army_save_as();
		return;
	}
	write_mars_army(def_mars_army_filename);
	using_mars_army_template = false;
}

void cb_mars_army_html()
{
	string fname_name = fl_filename_name(def_mars_army_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string mars_army_fname = ICS_dir;
	mars_army_fname.append(fname_name);
	mars_army_fname.append(".html");

	update_mars_armyfields();
	string formmars_army = mars_army_html_template;

	replacestr(formmars_army, TITLE, fname_name);

	replacestr(formmars_army, mars_army_prec, s_mars_army_prec );
	replacestr(formmars_army, mars_army_dtg, s_mars_army_dtg );
	replacestr(formmars_army, mars_army_fm, s_mars_army_fm );
	replacestr(formmars_army, mars_army_to, s_mars_army_to );
	replacestr(formmars_army, mars_army_info, s_mars_army_info );

	string text = "";
	string temp = "";
	if (!s_mars_army_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_army_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_army_text, 69);
	text.append(temp);

	replacestr(formmars_army, mars_army_text, text );

	FILE *filemars_army = fopen(mars_army_fname.c_str(), "w");
	fprintf(filemars_army,"%s", formmars_army.c_str());
	fclose(filemars_army);

	open_url(mars_army_fname.c_str());
}

void cb_mars_army_msg_type()
{
	if (tabs_msg_type->value() == tab_mars_army ) {
		show_filename(def_mars_army_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_mars_army_textout()
{
	string mars_army_fname = ICS_dir;
	mars_army_fname.append("mars_army.txt");

	update_mars_armyfields();
	string formmars_army = mars_army_text_template;

	replacestr(formmars_army, mars_army_prec, s_mars_army_prec );
	replacestr(formmars_army, mars_army_dtg, s_mars_army_dtg );
	replacestr(formmars_army, mars_army_fm, s_mars_army_fm );
	replacestr(formmars_army, mars_army_to, s_mars_army_to );
	replacestr(formmars_army, mars_army_info, s_mars_army_info );

	string text = "";
	string temp = "";
	if (!s_mars_army_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_army_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_army_text, 69);
	text.append(temp);

	replacestr(formmars_army, mars_army_text, text );

	FILE *filemars_army = fopen(mars_army_fname.c_str(), "w");
	fprintf(filemars_army,"%s", formmars_army.c_str());
	fclose(filemars_army);

	open_url(mars_army_fname.c_str());
}
