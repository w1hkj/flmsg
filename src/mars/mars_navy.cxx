// =====================================================================
//
// mars_navy.cxx
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
#include "dirent-check.h"

#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Image.H>

using namespace std;

const char navy_precedent[] = "RPIF";

string mars_navy_de     = ":de:";
string mars_navy_serno  = ":serno:";
string mars_navy_prec	= ":pre:";
string mars_navy_dtg	= ":dtg:";
string mars_navy_fm		= ":fm:";
string mars_navy_to		= ":to:";
string mars_navy_info	= ":info:";
string mars_navy_subj	= ":subj:";
string mars_navy_text	= ":text:";

string s_mars_navy_de;
string s_mars_navy_serno;
string s_mars_navy_prec = "R";
string s_mars_navy_dtg;
string s_mars_navy_fm;
string s_mars_navy_to;
string s_mars_navy_subj;
string s_mars_navy_info;
string s_mars_navy_text;

string buffmars_navy;
string def_mars_navy_filename = "";
string base_mars_navy_filename = "";
string def_mars_navy_TemplateName = "";

bool using_mars_navy_template = false;

void clear_mars_navyfields()
{
	s_mars_navy_de.clear();
	s_mars_navy_serno.clear();

	s_mars_navy_prec = "R";
	s_mars_navy_dtg.clear();
	s_mars_navy_fm.clear();
	s_mars_navy_to.clear();
	s_mars_navy_subj.clear();
	s_mars_navy_info.clear();
	s_mars_navy_text.clear();
}

bool check_mars_navyfields()
{
	string temp;
	temp = navy_precedent[sel_mars_navy_prec->value()];
	if (s_mars_navy_prec != temp) return true;

	if (s_mars_navy_de != txt_mars_navy_de->value()) return true;
	if (s_mars_navy_serno != txt_mars_navy_serno->value()) return true;

	if (s_mars_navy_dtg != txt_mars_navy_dtg->value()) return true;
	if (s_mars_navy_fm != txt_mars_navy_fm->value()) return true;
	if (s_mars_navy_serno != txt_mars_navy_serno->value()) return true;
	if (s_mars_navy_to != txt_mars_navy_to->buffer()->text()) return true;
	if (s_mars_navy_info != txt_mars_navy_info->buffer()->text()) return true;
	if (s_mars_navy_subj != txt_mars_navy_subj->value()) return true;
	if (s_mars_navy_text != txt_mars_navy_text->buffer()->text()) return true;
	return false;
}

void update_mars_navyfields()
{
	s_mars_navy_de = txt_mars_navy_de->value();
	s_mars_navy_serno = txt_mars_navy_serno->value();

	s_mars_navy_prec.clear();
	s_mars_navy_prec = navy_precedent[sel_mars_navy_prec->value()];
	s_mars_navy_dtg = txt_mars_navy_dtg->value();
	s_mars_navy_fm = txt_mars_navy_fm->value();
	s_mars_navy_to = txt_mars_navy_to->buffer()->text();
	s_mars_navy_info = txt_mars_navy_info->buffer()->text();
	s_mars_navy_subj = txt_mars_navy_subj->value();
	s_mars_navy_text = txt_mars_navy_text->buffer()->text();
}

void update_mars_navyform()
{
	size_t n = strchr(navy_precedent, s_mars_navy_prec[0]) - navy_precedent;
	if (n < 0) n = 0;
	if (n > 4) n = 4;
	sel_mars_navy_prec->value(n);

	txt_mars_navy_de->value(s_mars_navy_de.c_str());
	txt_mars_navy_serno->value(s_mars_navy_serno.c_str());

	txt_mars_navy_dtg->value(s_mars_navy_dtg.c_str());
	txt_mars_navy_fm->value(s_mars_navy_fm.c_str());
	txt_mars_navy_to->add(s_mars_navy_to.c_str());
	txt_mars_navy_info->add(s_mars_navy_info.c_str());
	txt_mars_navy_subj->value(s_mars_navy_subj.c_str());
	txt_mars_navy_text->add(s_mars_navy_text.c_str());

}

void clear_mars_navy_form()
{
	clear_mars_navyfields();

	txt_mars_navy_de->value("");
	txt_mars_navy_serno->value("");

	sel_mars_navy_prec->value(0);
	txt_mars_navy_dtg->value("");
	txt_mars_navy_fm->value("");

	txt_mars_navy_to->clear();
	txt_mars_navy_info->clear();
	txt_mars_navy_subj->value("");
	txt_mars_navy_text->clear();
}

void make_buffmars_navy(bool compress = false)
{
	string mbuff;
	mbuff.clear();
	mbuff.append( lineout( mars_navy_de,		s_mars_navy_de ) );
	mbuff.append( lineout( mars_navy_serno,		s_mars_navy_serno ) );
	mbuff.append( lineout( mars_navy_prec,		s_mars_navy_prec ) );
	mbuff.append( lineout( mars_navy_dtg,		s_mars_navy_dtg ) );
	mbuff.append( lineout( mars_navy_fm,		s_mars_navy_fm ) );
	mbuff.append( lineout( mars_navy_to,		s_mars_navy_to ) );
	mbuff.append( lineout( mars_navy_info,		s_mars_navy_info ) );
	mbuff.append( lineout( mars_navy_subj,		s_mars_navy_subj ) );
	mbuff.append( lineout( mars_navy_text,		s_mars_navy_text ) );
	if (compress) compress_maybe(mbuff);
	buffmars_navy.append(mbuff);
}

void read_mars_navy_buffer(string data)
{
	clear_mars_navyfields();

	s_mars_navy_de = findstr( data, mars_navy_de );
	s_mars_navy_serno = findstr( data, mars_navy_serno );
	s_mars_navy_prec = findstr( data, mars_navy_prec );
	s_mars_navy_dtg = findstr( data, mars_navy_dtg );
	s_mars_navy_fm = findstr( data, mars_navy_fm );
	s_mars_navy_to = findstr( data, mars_navy_to );
	s_mars_navy_info = findstr( data, mars_navy_info );
	s_mars_navy_subj = findstr( data, mars_navy_subj );
	s_mars_navy_text = findstr( data, mars_navy_text );
	update_mars_navyform();
}

void cb_mars_navy_new()
{
	if (check_mars_navyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_mars_navy_save();
		}
	}
	clear_mars_navy_form();
	def_mars_navy_filename = ICS_msg_dir;
	def_mars_navy_filename.append("new"FMARSNAVY_EXT);
	show_filename(def_mars_navy_filename);
	using_mars_navy_template = false;
}

void cb_mars_navy_import()
{
	fl_alert2("Not implemented");
}

void cb_mars_navy_export()
{
	fl_alert2("Not implemented");
}

void cb_mars_navy_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_mars_navy_form();
	read_mars_navy_buffer(inpbuffer);
	def_mars_navy_filename = ICS_msg_dir;
	def_mars_navy_filename.append(wrapfilename);
	show_filename(def_mars_navy_filename);
	using_mars_navy_template = false;
}

int eval_mars_navy_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_mars_navy_filename).append("]");
	update_mars_navyfields();
	update_header(FROM);
	evalstr.append(header("<mars_navy>"));
	buffmars_navy.clear();
	make_buffmars_navy(true);
	if (buffmars_navy.empty()) return 0;
	compress_maybe( buffmars_navy );
	evalstr.append( buffmars_navy );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_mars_navy_wrap_export()
{
	if (check_mars_navyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_navyfields();

	if (base_mars_navy_filename == "new"FMARSNAVY_EXT || base_mars_navy_filename == "default"FMARSNAVY_EXT)
		if (!cb_mars_navy_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_navy_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buffmars_navy.assign(header("<mars_navy>"));
		make_buffmars_navy(true);
		export_wrapfile(base_mars_navy_filename, wrapfilename, buffmars_navy, pext != ".wrap");

		buffmars_navy.assign(header("<mars_navy>"));
		make_buffmars_navy(false);
		write_mars_navy(def_mars_navy_filename);
	}
}

void cb_mars_navy_wrap_autosend()
{
	if (check_mars_navyfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_navyfields();

	if (base_mars_navy_filename == "new"FMARSNAVY_EXT || base_mars_navy_filename == "default"FMARSNAVY_EXT)
		cb_mars_navy_save_as();

	update_header(FROM);
	buffmars_navy.assign(header("<mars_navy>"));
	make_buffmars_navy(true);
	xfr_via_socket(base_mars_navy_filename, buffmars_navy);

	buffmars_navy.assign(header("<mars_navy>"));
	make_buffmars_navy(false);
	write_mars_navy(def_mars_navy_filename);
}

void cb_mars_navy_load_template()
{
	string def_mars_navy_filename = def_mars_navy_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"TMARSNAVY_EXT,
			def_mars_navy_filename.c_str());
	if (p) {
		clear_mars_navy_form();
		read_data_file(p);
		def_mars_navy_TemplateName = p;
		show_filename(def_mars_navy_TemplateName);
		using_mars_navy_template = true;
	}
}

void cb_mars_navy_save_template()
{
	if (!using_mars_navy_template) {
		cb_mars_navy_save_as_template();
		return;
	}
	string def_mars_navy_filename = def_mars_navy_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"TMARSNAVY_EXT,
			def_mars_navy_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_mars_navyfields();
		buffmars_navy.assign(header("<mars_navy>"));
		make_buffmars_navy();
		write_mars_navy(p);
	}
}

void cb_mars_navy_save_as_template()
{
	string def_mars_navy_filename = def_mars_navy_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"TMARSNAVY_EXT,
			def_mars_navy_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_navy_TemplateName = p;
		if (strlen(pext) == 0) def_mars_navy_TemplateName.append(TMARSNAVY_EXT);
		remove_spaces_from_filename(def_mars_navy_TemplateName);
	
		clear_header();
		update_header(CHANGED);
		buffmars_navy.assign(header("<mars_navy>"));
		make_buffmars_navy();
		write_mars_navy(def_mars_navy_TemplateName);

		show_filename(def_mars_navy_TemplateName);
		using_mars_navy_template = true;
	}
}

void cb_mars_navy_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-mars_navy\t*"FMARSNAVY_EXT,
					def_mars_navy_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_navy_form();
	read_data_file(p);
	using_mars_navy_template = false;
	def_mars_navy_filename = p;
	show_filename(def_mars_navy_filename);
}

void write_mars_navy(string s)
{
	FILE *filemars_navy = fopen(s.c_str(), "w");
	if (!filemars_navy) return;

	fwrite(buffmars_navy.c_str(), buffmars_navy.length(), 1, filemars_navy);
	fclose(filemars_navy);
}

bool cb_mars_navy_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FMARSNAVY_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_navy_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-mars_navy\t*"FMARSNAVY_EXT,
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

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
	def_mars_navy_filename = p;
	if (strlen(pext) == 0) def_mars_navy_filename.append(FMARSNAVY_EXT);

	remove_spaces_from_filename(def_mars_navy_filename);

	update_header(NEW);
	update_mars_navyfields();
	buffmars_navy.assign(header("<mars_navy>"));
	make_buffmars_navy();
	write_mars_navy(def_mars_navy_filename);

	using_mars_navy_template = false;
	show_filename(def_mars_navy_filename);
	return true;
}

void cb_mars_navy_save()
{
	if (base_mars_navy_filename == "new"FMARSNAVY_EXT || 
		base_mars_navy_filename == "default"FMARSNAVY_EXT ||
		using_mars_navy_template == true) {
		cb_mars_navy_save_as();
		return;
	}

	if (check_mars_navyfields()) update_header(CHANGED);
	update_mars_navyfields();
	buffmars_navy.assign(header("<mars_navy>"));
	make_buffmars_navy();
	write_mars_navy(def_mars_navy_filename);

	using_mars_navy_template = false;
}

void cb_mars_navy_html()
{
	string fname_name = fl_filename_name(def_mars_navy_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string mars_navy_fname = ICS_dir;
	mars_navy_fname.append(fname_name);
	mars_navy_fname.append(".html");

	update_mars_navyfields();
	string formmars_navy = mars_navy_html_template;

	replacestr(formmars_navy, TITLE, fname_name);

	string temp = s_mars_navy_prec;
	if (!s_mars_navy_de.empty()) {
		temp.assign("DE ").append(s_mars_navy_de).append(" ");
		if (!s_mars_navy_serno.empty()) {
			if (s_mars_navy_serno.length() < 4)
				temp.append(4-s_mars_navy_serno.length(),'0');
			temp.append(s_mars_navy_serno);
		}
		temp.append("\n");
		temp.append(s_mars_navy_prec);
	}
	replacestr(formmars_navy, mars_navy_prec, temp );
	replacestr(formmars_navy, mars_navy_dtg, s_mars_navy_dtg );
	replacestr(formmars_navy, mars_navy_fm, s_mars_navy_fm );
	temp = s_mars_navy_to;
	if (!s_mars_navy_info.empty())
		temp.append("\nINFO ").append(s_mars_navy_info);
	replacestr(formmars_navy, mars_navy_to, temp );

	string text = "";
	temp = "";
	if (!s_mars_navy_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_navy_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_navy_text, 69);
	text.append(temp);

	replacestr(formmars_navy, mars_navy_text, text );

	FILE *filemars_navy = fopen(mars_navy_fname.c_str(), "w");
	fprintf(filemars_navy,"%s", formmars_navy.c_str());
	fclose(filemars_navy);

	open_url(mars_navy_fname.c_str());
}

void cb_mars_navy_msg_type()
{
	if (tabs_msg_type->value() == tab_mars_navy ) {
		show_filename(def_mars_navy_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_mars_navy_textout()
{
	string mars_navy_fname = ICS_dir;
	mars_navy_fname.append("mars_navy.txt");

	update_mars_navyfields();
	string formmars_navy = mars_navy_text_template;

	string temp = s_mars_navy_prec;
	if (!s_mars_navy_de.empty()) {
		temp.assign("DE ").append(s_mars_navy_de).append(" ");
		if (!s_mars_navy_serno.empty()) {
			if (s_mars_navy_serno.length() < 4)
				temp.append(4-s_mars_navy_serno.length(),'0');
			temp.append(s_mars_navy_serno);
		}
		temp.append("\n");
		temp.append(s_mars_navy_prec);
	}
	replacestr(formmars_navy, mars_navy_prec, temp );
	replacestr(formmars_navy, mars_navy_dtg, s_mars_navy_dtg );
	replacestr(formmars_navy, mars_navy_fm, s_mars_navy_fm );
	temp = s_mars_navy_to;
	if (!s_mars_navy_info.empty())
		temp.append("\nINFO ").append(s_mars_navy_info);
	replacestr(formmars_navy, mars_navy_to, temp );

	string text = "";
	temp = "";
	if (!s_mars_navy_subj.empty()) {
		temp = "SUBJ: "; temp.append(s_mars_navy_subj);
		temp = maxchars(temp, 69, 6);
		text = temp;
		text += '\n';
	}
	temp = maxchars(s_mars_navy_text, 69);
	text.append(temp);

	replacestr(formmars_navy, mars_navy_text, text );

	FILE *filemars_navy = fopen(mars_navy_fname.c_str(), "w");
	fprintf(filemars_navy,"%s", formmars_navy.c_str());
	fclose(filemars_navy);

	open_url(mars_navy_fname.c_str());
}

