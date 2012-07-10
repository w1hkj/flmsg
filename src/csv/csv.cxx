// =====================================================================
//
// csvform.cxx
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

// csvform fields

string csvbuffer;
string def_csv_filename = "";
string base_csv_filename = "";
string def_csv_TemplateName = "";

string csv_title = ":TITLE:";
string csv_msg = ":mg:";
string csv_field;

bool using_csv_template = false;

void clear_csvfields()
{
	csv_field.clear();
}

void update_csvfields()
{
	csv_field = txt_csv_msg->buffer()->text();
}

void clear_csv_form()
{
	clear_csvfields();
	txt_csv_msg->clear();
}

void update_csvform()
{
	txt_csv_msg->clear();
	txt_csv_msg->add(csv_field.c_str());
}

void make_csvbuffer()
{
	update_csvfields();
	csvbuffer.append( lineout( csv_msg, csv_field ) );
}

void read_csvbuffer(string data)
{
	clear_csvfields();
	read_header(data);
	csv_field = findstr(data, csv_msg);
	update_csvform();
}

void cb_csv_new()
{
	clear_csv_form();
	clear_header();
	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append("new"CSVFILE_EXT);
	show_filename(def_csv_filename);
	using_csv_template = false;
}

void cb_csv_import()
{
	fl_alert2("Not implemented");
}

void cb_csv_export()
{
	fl_alert2("Not implemented");
}

void cb_csv_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_csv_form();
	read_csvbuffer(inpbuffer);
	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append(wrapfilename);
	show_filename(def_csv_filename);
	using_csv_template = false;
}

void cb_csv_wrap_export()
{
	if (base_csv_filename == "new"CSVFILE_EXT || base_csv_filename == "default"CSVFILE_EXT)
		cb_csv_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_csv_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(true);
		csvbuffer.assign(header("<csvform>", true, true));
		make_csvbuffer();
		export_wrapfile(base_csv_filename, wrapfilename, csvbuffer, pext != WRAP_EXT);
	}
}

void cb_csv_wrap_autosend()
{
	if (base_csv_filename == "new"CSVFILE_EXT || 
		base_csv_filename == "default"CSVFILE_EXT ||
		using_csv_template == true)
		cb_csv_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	update_header(true);
	csvbuffer.assign(header("<csvform>", true, true));
	make_csvbuffer();
	export_wrapfile(base_csv_filename, wrapfilename, csvbuffer, false);
}

void cb_csv_load_template()
{
	string def_csv_filename = def_csv_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"CSVTEMP_EXT,
			def_csv_filename.c_str());
	if (p) {
		clear_csv_form();
		read_data_file(p);
		def_csv_TemplateName = p;
		show_filename(def_csv_TemplateName);
		using_csv_template = true;
	}
}

void cb_csv_save_template()
{
	if (!using_csv_template) {
		cb_csv_save_as_template();
		return;
	}
	string def_csv_filename = def_csv_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"CSVTEMP_EXT,
			def_csv_filename.c_str());
	if (p) {
		clear_header();
		write_csv(p);
	}
}

void cb_csv_save_as_template()
{
	string def_csv_filename = def_csv_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"CSVTEMP_EXT,
			def_csv_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_csv_TemplateName = p;
		if (strlen(pext) == 0) def_csv_TemplateName.append(CSVTEMP_EXT);
		remove_spaces_from_filename(def_csv_TemplateName);
		clear_header();
		write_csv(def_csv_TemplateName);
		show_filename(def_csv_TemplateName);
		using_csv_template = true;
	}
}

void cb_csv_open()
{
	const char *p = FSEL::select(_("Open data file"), "csv form\t*.c2s",
					def_csv_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_csv_form();
	read_data_file(p);
	using_csv_template = false;
	def_csv_filename = p;
	show_filename(def_csv_filename);
}

void write_csv(string s)
{
	FILE *csvfile = fopen(s.c_str(), "w");
	if (!csvfile) return;
	update_header();
	csvbuffer.assign(save_header("<csvform>"));
	make_csvbuffer();
	fwrite(csvbuffer.c_str(), csvbuffer.length(), 1, csvfile);
	fclose(csvfile);
}

void cb_csv_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(".c2s");
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_csv_filename;

	p = FSEL::saveas(_("Save data file"), "csv form\t*.c2s",
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
	def_csv_filename = p;
	if (strlen(pext) == 0) def_csv_filename.append(".c2s");

	remove_spaces_from_filename(def_csv_filename);
	clear_header();
	update_header();
	csvbuffer.assign(save_header("<csvform>"));
	write_csv(def_csv_filename);

	using_csv_template = false;
	show_filename(def_csv_filename);
}

void cb_csv_save()
{
	if (base_csv_filename == "new.c2s" || 
		base_csv_filename == "default.c2s" ||
		using_csv_template == true) {
		cb_csv_save_as();
		return;
	}
	update_header();
	csvbuffer.assign(save_header("<csvform>"));
	write_csv(def_csv_filename);
	using_csv_template = false;
}

void cb_csv_msg_type()
{
	if (tabs_msg_type->value() == tab_csv ) {
		show_filename(def_csv_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_csv_html()
{
	string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);
	string csv_name = FLMSG_temp_dir;
	string html_text = "";
	csv_name.append(fname_name);
	csv_name.append(".html");

	update_csvfields();
	string csvform = csv_html_template;
	string rows;
	string row;
	string field;
	size_t p_eol = string::npos;
	size_t p_eof = string::npos;
	char sepchar = ',';

	rows.assign(csv_field);
	int nrows = 0, ncols = 0;
	int cols = 0;
	while (!rows.empty()) {
		p_eol = rows.find('\n');
		nrows++;
		cols = 0;
		if (p_eol != string::npos)
			row.assign(rows.substr(0,p_eol));
		else
			row.assign(rows);
		while(!row.empty()) {
			cols++;
			p_eof = row.find(sepchar);
			if (p_eof != string::npos)
				row.erase(0, p_eof + 1);
			else
				row.clear();
		}
		if (cols > ncols) ncols = cols;
		if (p_eol != string::npos)
			rows.erase(0,p_eol+1);
		else
			rows.clear();
	}

	char header[200];
	snprintf(header, sizeof(header),"<table BORDER=1 CELLPADDING=4 CELLSPACING=0 COLS=%d>\
<tbody>\
", ncols);
	html_text.append(header);
	rows.assign(csv_field);
	while (!rows.empty()) {
		cols = 0;
		html_text.append("<tr>\n");
		p_eol = rows.find('\n');
		if (p_eol != string::npos)
			row.assign(rows.substr(0,p_eol));
		else
			row.assign(rows);
		while(!row.empty()) {
			cols++;
			if (row[0] == '"') {
				p_eof = row.find('"', 1);
				field.assign(row.substr(1, p_eof - 1));
				p_eof = row.find(sepchar, p_eof);
			}
			else {
				p_eof = row.find(sepchar);
				field.assign(row.substr(0, p_eof));
			}
			if (field.empty()) field.assign("<br>");
			p = 0;
			while((p = field.find('"', p)) != string::npos)
				field.replace(p, 1,"&#34;");
			html_text.append("<td VALIGN=top>").append(field).append("</td>\n");
			if (p_eof != string::npos)
				row.erase(0, p_eof + 1);
			else
				row.clear();
		}
		while (cols < ncols) {
			html_text.append("<td></td>\n");
			cols++;
		}
		html_text.append("</tr>\n");
		if (p_eol != string::npos)
			rows.erase(0,p_eol+1);
		else
			rows.clear();
	}
	html_text.append("</tbody>\n");

	replacestr(csvform, csv_title, fname_name);
	replacestr(csvform, csv_msg, html_text);

	FILE *csvfile = fopen(csv_name.c_str(), "w");
	fprintf(csvfile,"%s", csvform.c_str());
	fclose(csvfile);

	open_url(csv_name.c_str());
}

void cb_csv_textout()
{
	string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string csv_name = FLMSG_temp_dir;

	csv_name.append(fname_name).append(".txt");

	update_csvfields();
	string csvform = csv_txt_template;

	replacestr(csvform, csv_msg, csv_field);

	FILE *csvfile = fopen(csv_name.c_str(), "w");
	fprintf(csvfile,"%s", csvform.c_str());
	fclose(csvfile);

	open_url(csv_name.c_str());
}

void cb_csv_import_data()
{
	def_csv_filename = CSV_dir;
	def_csv_filename.append("default.csv");

	const char *p = FSEL::select(
						_("Import CSV data"),
						"csv file\t*.csv",
						def_csv_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;\

	clear_csv_form();

// open the CSV file, read all data
	long filesize = 0;
	char *buff;
	int retval;
	FILE *csv_datafile;

	csv_datafile = fopen (p, "r");
	if (!csv_datafile)
		return;
// determine its size for buffer creation
	fseek (csv_datafile, 0, SEEK_END);
	filesize = ftell (csv_datafile);
// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
		return;
	}

	buff = new char[filesize + 1];
	memset(buff, 0, filesize + 1);
// read the entire file into the buffer
	fseek (csv_datafile, 0, SEEK_SET);
	retval = fread (buff, filesize, 1, csv_datafile);
	fclose (csv_datafile);

	csv_field = buff;
	update_csvform();

	delete [] buff;

	using_csv_template = false;

	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append(fl_filename_name(p));
	size_t pext = def_csv_filename.find(".csv");
	def_csv_filename.erase(pext);
	def_csv_filename.append(".c2s");
	show_filename(def_csv_filename);
}

void cb_csv_export_data(bool open_file)
{
	string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string csv_name = CSV_dir;
	csv_name.append(fname_name).append(".csv");

	const char *pfilename = FSEL::saveas(
							_("Export CSV data"),
							"csv file\t*.csv",
							csv_name.c_str());

	if (!pfilename) return;
	if (strlen(pfilename) == 0) return;
	csv_name = pfilename;
	if (csv_name.find(".csv") == string::npos)
		csv_name.append(".csv");

	update_csvfields();

	FILE *csvfile = fopen(csv_name.c_str(), "w");
	fprintf(csvfile,"%s", csv_field.c_str());
	fclose(csvfile);

	if (open_file)
		open_url(pfilename);
	else
		fl_alert2("Data written to %s", csv_name.c_str());

}

void csv_set_fname(const char *fn)
{
	string fname = fn;
	if (fname.find(".csv") == string::npos) {
		txt_csv_msg->clear();
		return;
	}
	using_csv_template = false;
	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append(fl_filename_name(fn));
	size_t pext = def_csv_filename.find(".csv");
	def_csv_filename.erase(pext);
	def_csv_filename.append(".c2s");
	show_filename(def_csv_filename);
}
