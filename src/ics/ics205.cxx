// =====================================================================
//
// ics205.cxx
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

// ics205 fields

// compatibility fields required to read older data files

string aics205_name  = "<nam:";
string aics205_dt1   = "<dt1:";
string aics205_dt2   = "<dt2:";
string aics205_type  = "<typ0:";
string aics205_chan  = "<chn0:";
string aics205_func  = "<fun0:";
string aics205_freq  = "<frq0:";
string aics205_ass   = "<ass0:";
string aics205_rem   = "<rem0:";
string aics205_prep  = "<prp:";

string ics205_name  = ":nam:";
string ics205_dt1   = ":dt1:";
string ics205_dt2   = ":dt2:";
string ics205_dt3   = ":dt3:";
string ics205_type  = ":typ0:";
string ics205_chan  = ":chn0:";
string ics205_func  = ":fun0:";
string ics205_freq  = ":frq0:";
string ics205_ass   = ":ass0:";
string ics205_rem   = ":rem0:";
string ics205_prep  = ":prp:";

string s205_name;
string s205_dt_prepared;
string s205_dt_op_from;
string s205_dt_op_to;
string s205_type[8];
string s205_channel[8];
string s205_function[8];
string s205_freqtone[8];
string s205_assignment[8];
string s205_remarks[8];
string s205_preparer;

string buff205;
string def_205_filename = "";
string base_205_filename = "";
string def_205_TemplateName = "";
bool using_ics205_template = false;

void cb_205_SetDateTime1()
{
	txt_205_dt_prepared->value(szDateTime());
}

void cb_205_SetDateTime2()
{
	txt_205_dt_op_from->value(szDateTime());
}

void cb_205_SetDateTime3()
{
	txt_205_dt_op_to->value(szDateTime());
}

void clear_205fields()
{
	s205_name.clear();
	s205_dt_prepared.clear();
	s205_dt_op_from.clear();
	for (int i = 0; i < 8; i++) {
		s205_type[i].clear();
		s205_channel[i].clear();
		s205_function[i].clear();
		s205_freqtone[i].clear();
		s205_assignment[i].clear();
		s205_remarks[i].clear();
	}
	s205_preparer.clear();
}

bool check_205fields()
{
	if (s205_name != txt_205_name->value())
		return true;
	if (s205_dt_prepared != txt_205_dt_prepared->value())
		return true;
	if (s205_dt_op_from != txt_205_dt_op_from->value())
		return true;
	if (s205_dt_op_to != txt_205_dt_op_to->value())
		return true;
	for (int i = 0; i < 8; i++) {
		if (s205_type[i] != txt_205_type[i]->value())
			return true;
		if (s205_channel[i] != txt_205_channel[i]->value())
			return true;
		if (s205_function[i] != txt_205_function[i]->value())
			return true;
		if (s205_freqtone[i] != txt_205_freqtone[i]->value())
			return true;
		if (s205_assignment[i] != txt_205_assignment[i]->value())
			return true;
		if (s205_remarks[i] != txt_205_remarks[i]->value())
			return true;
	}
	if (s205_preparer != txt_205_preparer->value())
		return true;
	return false;
}

void update_205fields()
{
	s205_name = txt_205_name->value();
	s205_dt_prepared = txt_205_dt_prepared->value();
	s205_dt_op_from = txt_205_dt_op_from->value();
	s205_dt_op_to = txt_205_dt_op_to->value();
	for (int i = 0; i < 8; i++) {
		s205_type[i] = txt_205_type[i]->value();
		s205_channel[i] = txt_205_channel[i]->value();
		s205_function[i] = txt_205_function[i]->value();
		s205_freqtone[i] = txt_205_freqtone[i]->value();
		s205_assignment[i] = txt_205_assignment[i]->value();
		s205_remarks[i] = txt_205_remarks[i]->value();
	}
	s205_preparer = txt_205_preparer->value();
}

void update_205form()
{
	txt_205_name->value(s205_name.c_str());
	txt_205_dt_prepared->value(s205_dt_prepared.c_str());
	txt_205_dt_op_from->value(s205_dt_op_from.c_str());
	txt_205_dt_op_to->value(s205_dt_op_to.c_str());
	for (int i = 0; i < 8; i++) {
		txt_205_type[i]->value(s205_type[i].c_str());
		txt_205_channel[i]->value(s205_channel[i].c_str());
		txt_205_function[i]->value(s205_function[i].c_str());
		txt_205_freqtone[i]->value(s205_freqtone[i].c_str());
		txt_205_assignment[i]->value(s205_assignment[i].c_str());
		txt_205_remarks[i]->value(s205_remarks[i].c_str());
	}
	txt_205_preparer->value(s205_preparer.c_str());
}

void clear_205_form()
{
	clear_205fields();
	txt_205_name->value("");
	txt_205_dt_prepared->value("");
	txt_205_dt_op_from->value("");
	txt_205_dt_op_to->value("");
	for (int i = 0; i < 8; i++) {
		txt_205_type[i]->value("");
		txt_205_channel[i]->value("");
		txt_205_function[i]->value("");
		txt_205_freqtone[i]->value("");
		txt_205_assignment[i]->value("");
		txt_205_remarks[i]->value("");
	}
	txt_205_preparer->value("");
}

void make_buff205(bool compress = false)
{
	string mbuff;
	mbuff.clear();
	mbuff.append( lineout( ics205_name, s205_name ) );
	mbuff.append( lineout( ics205_dt1, s205_dt_prepared ) );
	mbuff.append( lineout( ics205_dt2, s205_dt_op_from ) );
	mbuff.append( lineout( ics205_dt3, s205_dt_op_to ) );

	for (int i = 0; i < 8; i++) {
		ics205_type[4] = ics205_chan[4] = ics205_func[4] = 
		ics205_freq[4] = ics205_ass[4] = ics205_rem[4] = '0' + i;
		mbuff.append( lineout ( ics205_type, s205_type[i] ) );
		mbuff.append( lineout ( ics205_chan, s205_channel[i] ) );
		mbuff.append( lineout ( ics205_func, s205_function[i] ) );
		mbuff.append( lineout ( ics205_freq, s205_freqtone[i] ) );
		mbuff.append( lineout ( ics205_ass, s205_assignment[i] ) );
		mbuff.append( lineout ( ics205_rem, s205_remarks[i] ) );
	}
	mbuff.append( lineout ( ics205_prep, s205_preparer ) );
	if (compress) compress_maybe(mbuff);
	buff205.append(mbuff);
}

void read_205_buffer(string data)
{
	clear_205fields();
	read_header(data);

	s205_name = findstr(data, ics205_name);
	s205_dt_prepared = findstr(data, ics205_dt1);
	s205_dt_op_from = findstr(data, ics205_dt2);
	s205_dt_op_to = findstr(data, ics205_dt3);
	for (int i = 0; i < 8; i++) {
		ics205_type[4] = 
		ics205_chan[4] = 
		ics205_func[4] =
		ics205_freq[4] =
		ics205_ass[4]  =
		ics205_rem[4] = '0' + i;;
		s205_type[i] = findstr(data, ics205_type);
		s205_channel[i] = findstr(data, ics205_chan);
		s205_function[i] = findstr(data, ics205_func);
		s205_freqtone[i] = findstr(data, ics205_freq);
		s205_assignment[i] = findstr(data, ics205_ass);
		s205_remarks[i] = findstr(data, ics205_rem);
	}
	s205_preparer = findstr(data, ics205_prep);
	if (s205_name.empty()) {
		s205_name = findstr(data, aics205_name);
		s205_dt_prepared = findstr(data, aics205_dt1);
		s205_dt_op_from = findstr(data, aics205_dt2);
		for (int i = 0; i < 8; i++) {
			aics205_type[4] = 
			aics205_chan[4] = 
			aics205_func[4] =
			aics205_freq[4] =
			aics205_ass[4]  =
			aics205_rem[4] = '0' + i;;
			s205_type[i] = findstr(data, aics205_type);
			s205_channel[i] = findstr(data, aics205_chan);
			s205_function[i] = findstr(data, aics205_func);
			s205_freqtone[i] = findstr(data, aics205_freq);
			s205_assignment[i] = findstr(data, aics205_ass);
			s205_remarks[i] = findstr(data, aics205_rem);
		}
		s205_preparer = findstr(data, aics205_prep);
	}
	update_205form();
}

void cb_205_new()
{
	if (check_205fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_205_save();
		}
	}
	clear_205_form();
	clear_header();
	def_205_filename = ICS_msg_dir;
	def_205_filename.append("new"F205_EXT);
	show_filename(def_205_filename);
	using_ics205_template = false;
}

void cb_205_import()
{
	fl_alert2("Not implemented");
}

void cb_205_export()
{
	fl_alert2("Not implemented");
}

void cb_205_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_205_form();
	read_205_buffer(inpbuffer);
	def_205_filename = ICS_msg_dir;
	def_205_filename.append(wrapfilename);
	show_filename(def_205_filename);
	using_ics205_template = false;
}

int eval_205_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_205_filename).append("]");
	update_205fields();
	update_header(FROM);
	evalstr.append(header("<ics205>"));
	buff205.clear();
	make_buff205(true);
	if (buff205.empty()) return 0;
	compress_maybe( buff205 );
	evalstr.append( buff205 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_205_wrap_export()
{
	if (check_205fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_205fields();

	if (base_205_filename == "new"F205_EXT || base_205_filename == "default"F205_EXT)
		if (!cb_205_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_205_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		buff205.assign(header("<ics205>"));
		make_buff205(true);
		export_wrapfile(base_205_filename, wrapfilename, buff205, pext != ".wrap");

		buff205.assign(header("<ics205>"));
		make_buff205(false);
		write_205(def_205_filename);
	}
}

void cb_205_wrap_autosend()
{
	if (check_205fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_205fields();

	if (base_205_filename == "new"F205_EXT || base_205_filename == "default"F205_EXT)
		if (!cb_205_save_as()) return;

	update_header(FROM);
	buff205.assign(header("<ics205>"));
	make_buff205(true);
	xfr_via_socket(base_205_filename, buff205);

	buff205.assign(header("<ics205>"));
	make_buff205(false);
	write_205(def_205_filename);
}

void cb_205_load_template()
{
	string def_205_filename = def_205_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"T205_EXT,
			def_205_filename.c_str());
	if (p) {
		clear_205_form();
		read_data_file(p);
		def_205_TemplateName = p;
		show_filename(def_205_TemplateName);
		using_ics205_template = true;
	}
}

void cb_205_save_template()
{
	if (!using_ics205_template) {
		cb_205_save_as_template();
		return;
	}
	string def_205_filename = def_205_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"T205_EXT,
			def_205_filename.c_str());
	if (p) {
		clear_header();
		make_buff205();
		write_205(p);
	}
}

void cb_205_save_as_template()
{
	string def_205_filename = def_205_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"T205_EXT,
			def_205_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_205_TemplateName = p;
		if (strlen(pext) == 0) def_205_TemplateName.append(T205_EXT);
		remove_spaces_from_filename(def_205_TemplateName);
		clear_header();
		make_buff205();
		write_205(def_205_TemplateName);
		show_filename(def_205_TemplateName);
		using_ics205_template = true;
	}
}

void cb_205_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-205\t*"F205_EXT,
					def_205_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_205_form();
	read_data_file(p);
	using_ics205_template = false;
	def_205_filename = p;
	show_filename(def_205_filename);
}

void write_205(string s)
{
	FILE *file205 = fopen(s.c_str(), "w");
	if (!file205) return;

	fwrite(buff205.c_str(), buff205.length(), 1, file205);
	fclose(file205);
}

bool cb_205_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(F205_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_205_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-205\t*"F205_EXT,
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
	def_205_filename = p;
	if (strlen(pext) == 0) def_205_filename.append(F205_EXT);

	remove_spaces_from_filename(def_205_filename);
	update_205fields();
	clear_header();
	update_header(CHANGED);
	buff205.assign(header("<ics205>"));
	make_buff205();
	write_205(def_205_filename);

	using_ics205_template = false;
	show_filename(def_205_filename);
	return true;
}

void cb_205_save()
{
	if (base_205_filename == "new"F205_EXT || 
		base_205_filename == "default"F205_EXT ||
		using_ics205_template == true) {
		cb_205_save_as();
		return;
	}
	if (check_205fields()) update_header(CHANGED);
	update_205fields();
	buff205.assign(header("<ics205>"));
	make_buff205();
	write_205(def_205_filename);
	using_ics205_template = false;
}

void cb_205_html()
{
	string fname_name = fl_filename_name(def_205_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string ics205_fname = ICS_dir;
	ics205_fname.append(fname_name);
	ics205_fname.append(".html");

	string html_text = "";

	update_205fields();
	string form205 = ics205_html_template;

	replacestr(form205, TITLE, fname_name);
	replacestr(form205, ics205_name, s205_name);
	replacestr(form205, ics205_dt1, s205_dt_prepared);
	replacestr(form205, ics205_dt2, s205_dt_op_from);
	replacestr(form205, ics205_dt3, s205_dt_op_to);
	for (int i = 0; i < 8; i++) {
		ics205_type[4] = ics205_chan[4] = ics205_func[4] =
		ics205_freq[4] = ics205_ass[4] = ics205_rem[4] = '0' + i;
		replacestr(form205, ics205_type, s205_type[i]);
		replacestr(form205, ics205_chan, s205_channel[i]);
		replacestr(form205, ics205_func, s205_function[i]);
		replacestr(form205, ics205_freq, s205_freqtone[i]);
		replacestr(form205, ics205_ass, s205_assignment[i]);
		replacestr(form205, ics205_rem, s205_remarks[i]);
	}
	replacestr(form205, ics205_prep, s205_preparer);

	FILE *file205 = fopen(ics205_fname.c_str(), "w");
	fprintf(file205,"%s", form205.c_str());
	fclose(file205);

	open_url(ics205_fname.c_str());
}

void cb_205_msg_type()
{
	if (tabs_msg_type->value() == tab_ics205 ) {
		show_filename(def_205_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_205_textout()
{
	string temp = "";
	string ics205_fname = ICS_dir;
	ics205_fname.append("ics205.txt");

	update_205fields();
	string form205 = ics205_text_template;

	replacestr(form205, ics205_name, s205_name);
	replacestr(form205, ics205_dt1, s205_dt_prepared);
	replacestr(form205, ics205_dt2, s205_dt_op_from);
	replacestr(form205, ics205_dt3, s205_dt_op_to);
	for (int i = 0; i < 8; i++) {
		ics205_type[4] = ics205_chan[4] = ics205_func[4] =
		ics205_freq[4] = ics205_ass[4] = ics205_rem[4] = '0' + i;
		replacestr(form205, ics205_type, s205_type[i]);
		replacestr(form205, ics205_chan, s205_channel[i]);
		replacestr(form205, ics205_func, s205_function[i]);
		replacestr(form205, ics205_freq, s205_freqtone[i]);
		replacestr(form205, ics205_ass, s205_assignment[i]);
		temp = s205_remarks[i];
		replacelf(temp);
		replacestr(form205, ics205_rem, temp);
	}
	replacestr(form205, ics205_prep, s205_preparer);

	FILE *file205 = fopen(ics205_fname.c_str(), "w");
	fprintf(file205,"%s", form205.c_str());
	fclose(file205);

	open_url(ics205_fname.c_str());
}
