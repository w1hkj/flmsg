// ----------------------------------------------------------------------------
// < (C) 2014
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
#include "icons.h"

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

// csvform fields

std::string csvbuffer;
std::string def_csv_filename = "";
std::string base_csv_filename = "";
std::string def_csv_TemplateName = "";

std::string csv_title = ":TITLE:";
std::string csv_msg = ":mg:";
std::string csv_field;

bool using_csv_template = false;

void clear_csvfields()
{
	csv_field.clear();
}

bool check_csvfields()
{
	return (csv_field != txt_csv_msg->buffer()->text());
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

void read_csvbuffer(std::string data)
{
	clear_csvfields();
	read_header(data);
	csv_field = findstr(data, csv_msg);
	update_csvform();
}

void cb_csv_new()
{
	if (check_csvfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_csv_save();
		}
	}
	clear_csv_form();
	clear_header();
	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append("new").append(CSVFILE_EXT);
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

void cb_csv_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_csv_form();
	read_csvbuffer(inpbuffer);
	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append(wrapfilename);
	show_filename(def_csv_filename);
	using_csv_template = false;
}

int eval_csv_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_csv_filename).append("]");
	update_csvfields();
	update_header(FROM);
	evalstr.append(header("<csvform>"));
	std::string outbuf = lineout( csv_msg, csv_field );
	if (outbuf.empty()) return 0;
	compress_maybe( outbuf );
	evalstr.append( outbuf );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_csv_wrap_export()
{
	if (check_csvfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_csvfields();
	if (csv_field.empty()) return;

	if (base_csv_filename == std::string("new").append(CSVFILE_EXT) ||
		base_csv_filename == std::string("default").append(CSVFILE_EXT) )
		if (!cb_csv_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_csv_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		csvbuffer.assign(header("<csvform>"));
		std::string outbuf = lineout( csv_msg, csv_field );
		compress_maybe(outbuf);
		csvbuffer.append(outbuf);
		export_wrapfile(base_csv_filename, wrapfilename, csvbuffer, pext != WRAP_EXT);

		csvbuffer.assign(header("<csvform>")).append(lineout( csv_msg, csv_field ));
		write_csv(def_csv_filename);
	}
}

void cb_csv_wrap_autosend()
{
	if (check_csvfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_csvfields();
	if (csv_field.empty()) return;

	if (base_csv_filename == std::string("new").append(CSVFILE_EXT) ||
		base_csv_filename == std::string("default").append(CSVFILE_EXT) )
		if (!cb_csv_save_as()) return;

	update_header(FROM);
	csvbuffer.assign(header("<csvform>"));
	std::string outbuf = lineout( csv_msg, csv_field );

	compress_maybe(outbuf);
	csvbuffer.append(outbuf);
	xfr_via_socket(base_csv_filename, csvbuffer);

	csvbuffer.assign(header("<csvform>")).append(lineout( csv_msg, csv_field ));
	write_csv(def_csv_filename);
}

void cb_csv_load_template()
{
	std::string def_csv_filename = def_csv_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(CSVTEMP_EXT).c_str(),
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
	std::string def_csv_filename = def_csv_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(CSVTEMP_EXT).c_str(),
			def_csv_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_csvfields();
		csvbuffer.assign(header("<csvform>"));
		csvbuffer.append( lineout( csv_msg, csv_field ) );
		write_csv(p);
	}
}

void cb_csv_save_as_template()
{
	std::string def_csv_filename = def_csv_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(CSVTEMP_EXT).c_str(),
			def_csv_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_csv_TemplateName = p;
		if (strlen(pext) == 0) def_csv_TemplateName.append(CSVTEMP_EXT);
		remove_spaces_from_filename(def_csv_TemplateName);
		clear_header();
		update_header(CHANGED);
		update_csvfields();
		csvbuffer.assign(header("<csvform>"));
		csvbuffer.append( lineout( csv_msg, csv_field ) );
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

void write_csv(std::string s)
{
	if (csvbuffer.empty()) 
		return;
	FILE *csvfile = fopen(s.c_str(), "w");
	if (!csvfile) return;
	fwrite(csvbuffer.c_str(), csvbuffer.length(), 1, csvfile);
	fclose(csvfile);
}

bool cb_csv_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(".c2s");
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_csv_filename;

	p = FSEL::saveas(_("Save data file"), "csv form\t*.c2s",
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_csv_filename = p;
	if (strlen(pext) == 0) def_csv_filename.append(".c2s");

	remove_spaces_from_filename(def_csv_filename);
	update_header(NEW);
	update_csvfields();
	csvbuffer.assign(header("<csvform>"));
	csvbuffer.append( lineout( csv_msg, csv_field ) );
	write_csv(def_csv_filename);

	using_csv_template = false;
	show_filename(def_csv_filename);
	return true;
}

void cb_csv_save()
{
	if (base_csv_filename == "new.c2s" || 
		base_csv_filename == "default.c2s" ||
		using_csv_template == true) {
		cb_csv_save_as();
		return;
	}
	if (check_csvfields()) update_header(CHANGED);
	update_csvfields();
	csvbuffer.assign(header("<csvform>"));
	csvbuffer.append( lineout( csv_msg, csv_field ) );
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

void cb_csv_import_data()
{
	def_csv_filename = CSV_dir;
	def_csv_filename.append("default.csv");

	const char *p = FSEL::select(
						_("Import CSV data"),
						"csv file\t*.csv",
						def_csv_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;

	clear_csv_form();
	clear_estimate();

// open the CSV file, read all data
	long filesize = 0;
	FILE *csv_datafile;

	csv_datafile = fopen (p, "rb");
	if (!csv_datafile) {
		fl_alert2(_("Could not open file"));
		return;
	}
// determine its size for buffer creation
	fseek (csv_datafile, 0, SEEK_END);
	filesize = ftell (csv_datafile);
// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
        fclose(csv_datafile);
		return;
	}

	char *buff = new char[filesize + 1];
	memset(buff, 0, filesize + 1);
// read the entire file into the buffer
	fseek (csv_datafile, 0, SEEK_SET);
	int retval = fread (buff, 1, filesize, csv_datafile);
	fclose (csv_datafile);

	if (retval != filesize) {
		fl_alert2(_("Error reading file"));
        delete[] buff;
		return;
	}

	csv_field = buff;
// strip any cr-lf pairs if the file was a DOS text file
	size_t ptr = csv_field.find("\r\n");
	while (ptr != std::string::npos) {
		csv_field.erase(ptr, 1);
		ptr = csv_field.find("\r\n");
	}
	update_csvform();

	delete [] buff;

	using_csv_template = false;

	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append(fl_filename_name(p));
	size_t pext = def_csv_filename.find(".csv");
	if (pext == std::string::npos) pext = def_csv_filename.find(".CSV");
	if (pext != std::string::npos) def_csv_filename.erase(pext);
	def_csv_filename.append(".c2s");
	show_filename(def_csv_filename);
	estimate();
}

void cb_csv_export_data(bool open_file)
{
	update_csvfields();
	if (csv_field.empty()) return;

	std::string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string csv_name = CSV_dir;
	csv_name.append(fname_name).append(".csv");

	const char *pfilename = FSEL::saveas(
							_("Export CSV data"),
							"csv file\t*.csv",
							csv_name.c_str());

	if (!pfilename) return;
	if (strlen(pfilename) == 0) return;
	csv_name = pfilename;
	if (csv_name.find(".csv") == std::string::npos)
		csv_name.append(".csv");

	FILE *csvfile = fopen(csv_name.c_str(), "w");
	fprintf(csvfile,"%s", csv_field.c_str());
	fclose(csvfile);

	if (open_file) {
		fl_alert2("If you modify the data you must save as CSV and\nimport the modified file");
		open_url(pfilename);
	} else
		fl_alert2("Data written to %s", csv_name.c_str());

}

void csv_set_fname(const char *fn)
{
	std::string fname = fn;
	size_t pext = fname.find(".csv");
	if (pext == std::string::npos) pext = fname.find(".CSV");
	if (pext == std::string::npos) {
		txt_csv_msg->clear();
		return;
	}
	using_csv_template = false;
	def_csv_filename = ICS_msg_dir;
	def_csv_filename.append(fl_filename_name(fn));
	def_csv_filename.find(".csv");
	if (pext == std::string::npos) pext = def_csv_filename.find(".CSV");
	if (pext != std::string::npos) def_csv_filename.erase(pext);
	def_csv_filename.append(".c2s");
	show_filename(def_csv_filename);
}

void custom_csv_html(std::string form, std::string contents)
{
	std::string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string csv_name = FLMSG_temp_dir;

	csv_name.append(fname_name).append(".htm");

	std::string line;
	std::string field;
	std::string data;
	while (data[0] == '\n') data.erase(0,1);
	size_t comma = contents.find(",");
	while (contents[comma+1] == ' ') contents.erase(comma+1,1);
	size_t quote = contents.find("\"");
	size_t lfptr = contents.find("\n");
	size_t tab;
	if (quote == comma + 1) {
		contents.erase(quote,1);
		lfptr = contents.find("\"\n");
	}
	while (comma != std::string::npos) {
		field = ":"; field.append(contents.substr(0, comma)).append(":");
		if (lfptr != std::string::npos) {
			data = contents.substr(comma + 1, lfptr - comma - 1);
			tab = data.find("\t");
			while (tab != std::string::npos) {
				data.replace(tab, 1, "     ");
				tab = data.find("\t");
			}
			contents.erase(0, lfptr + 1);
			while (data[0] == '\n') data.erase(0,1);
			while ((quote = data.find("\"")) != std::string::npos) data.erase(quote,1);
		} else {
			data = contents.substr(comma + 1);
			tab = data.find("\t");
			while (tab != std::string::npos) {
				data.replace(tab, 1, "     ");
				tab = data.find("\t");
			}
			while ((quote = data.find("\"")) != std::string::npos) data.erase(quote,1);
			contents.clear();
		}
		lfptr = data.find("\n");
		while (lfptr != std::string::npos) {
			data.replace(lfptr, 1, "<br>");
			lfptr = data.find("\n");
		}
		replacestr(form, field, data);
		comma = contents.find(",");
		while (contents[comma+1] == ' ') contents.erase(comma+1,1);
		quote = contents.find("\"");
		if (quote == comma + 1) {
			contents.erase(quote,1);
			lfptr = contents.find("\"\n");
		} else
			lfptr = contents.find("\n");
	}

	FILE *csvfile = fopen(csv_name.c_str(), "w");
	fprintf(csvfile,"%s", form.c_str());
	fclose(csvfile);

	open_url(csv_name.c_str());
}

void cb_csv_html()
{
	update_csvfields();
	if (csv_field.find("CUSTOM_FORM") == 0) {
		size_t plf = csv_field.find("\n");
		if (plf != std::string::npos) {
			std::string fname = CUSTOM_dir;
			fname.append(csv_field.substr(12, plf - 12));
			fname.append(".htm");
			FILE *ffile = fopen(fname.c_str(), "r");
			if (!ffile) {
				fname += 'l';
				ffile = fopen(fname.c_str(), "r");
			}
			if (ffile) {
				std::string form;
				char c = fgetc(ffile);
				while (!feof(ffile)) {
					form += c;
					c = fgetc(ffile);
				}
				fclose(ffile);
				custom_csv_html(form, csv_field.substr(plf+1));
				return;
			}
		}
	}

	csvbuffer.assign(header("<csvform>"));
	csvbuffer.append( lineout( csv_msg, csv_field ) );
	write_csv(def_csv_filename);

	std::string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);
	std::string csv_name = FLMSG_temp_dir;
	std::string html_text = "";
	csv_name.append(fname_name);
	csv_name.append(".htm");

	std::string csvform = csv_html_template;
	std::string rows;
	std::string row;
	std::string field;
	size_t p_eol = std::string::npos;
	size_t p_eof = std::string::npos;
	char sepchar = ',';

	rows.assign(csv_field);
	int nrows = 0, ncols = 0;
	int cols = 0;
	while (!rows.empty()) {
		p_eol = rows.find('\n');
		nrows++;
		cols = 0;
		if (p_eol != std::string::npos)
			row.assign(rows.substr(0,p_eol));
		else
			row.assign(rows);
		while(!row.empty()) {
			cols++;
			p_eof = row.find(sepchar);
			if (p_eof != std::string::npos)
				row.erase(0, p_eof + 1);
			else
				row.clear();
		}
		if (cols > ncols) ncols = cols;
		if (p_eol != std::string::npos)
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
		if (p_eol != std::string::npos)
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
			while((p = field.find('"', p)) != std::string::npos)
				field.replace(p, 1,"&#34;");
			html_text.append("<td VALIGN=top>").append(field).append("</td>\n");
			if (p_eof != std::string::npos)
				row.erase(0, p_eof + 1);
			else
				row.clear();
		}
		while (cols < ncols) {
			html_text.append("<td></td>\n");
			cols++;
		}
		html_text.append("</tr>\n");
		if (p_eol != std::string::npos)
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

void custom_csv_text(std::string form, std::string contents)
{
	std::string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string csv_name = FLMSG_temp_dir;

	csv_name.append(fname_name).append(".txt");

	std::string line;
	std::string field;
	std::string data;
	while (data[0] == '\n') data.erase(0,1);
	size_t comma = contents.find(",");
	while (contents[comma+1] == ' ') contents.erase(comma+1,1);
	size_t quote = contents.find("\"");
	size_t lfptr = contents.find("\n");
	size_t tab;
	if (quote == comma + 1) {
		contents.erase(quote,1);
		lfptr = contents.find("\"\n");
	}
	while (comma != std::string::npos) {
		field = ":"; field.append(contents.substr(0, comma)).append(":");
		if (lfptr != std::string::npos) {
			data = contents.substr(comma + 1, lfptr - comma - 1);
			tab = data.find("\t");
			while (tab != std::string::npos) {
				data.replace(tab, 1, "     ");
				tab = data.find("\t");
			}
			contents.erase(0, lfptr + 1);
			while (data[0] == '\n') data.erase(0,1);
			while ((quote = data.find("\"")) != std::string::npos) data.erase(quote,1);
		} else {
			data = contents.substr(comma + 1);
			tab = data.find("\t");
			while (tab != std::string::npos) {
				data.replace(tab, 1, "     ");
				tab = data.find("\t");
			}
			while ((quote = data.find("\"")) != std::string::npos) data.erase(quote,1);
			contents.clear();
		}
		replacestr(form, field, data);
		comma = contents.find(",");
		while (contents[comma+1] == ' ') contents.erase(comma+1,1);
		quote = contents.find("\"");
		if (quote == comma + 1) {
			contents.erase(quote,1);
			lfptr = contents.find("\"\n");
		} else
			lfptr = contents.find("\n");
	}

	FILE *csvfile = fopen(csv_name.c_str(), "w");
	fprintf(csvfile,"%s", form.c_str());
	fclose(csvfile);

	open_url(csv_name.c_str());
}

void cb_csv_textout()
{
	update_csvfields();

	csvbuffer.assign(header("<csvform>"));
	csvbuffer.append( lineout( csv_msg, csv_field ) );
	write_csv(def_csv_filename);

	if (csv_field.find("CUSTOM_FORM") == 0) {
		size_t plf = csv_field.find("\n");
		if (plf != std::string::npos) {
			std::string fname = CUSTOM_dir;
			fname.append(csv_field.substr(12, plf - 12));
			fname.append(".txt");
			FILE *ffile = fopen(fname.c_str(), "r");
			if (ffile) {
				std::string form;
				char c = fgetc(ffile);
				while (!feof(ffile)) {
					form += c;
					c = fgetc(ffile);
				}
				fclose(ffile);
				custom_csv_text(form, csv_field.substr(plf+1));
				return;
			}
		}
	}

	std::string fname_name = fl_filename_name(def_csv_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string csv_name = FLMSG_temp_dir;

	csv_name.append(fname_name).append(".txt");

	std::string csvform = csv_txt_template;

	replacestr(csvform, csv_msg, csv_field);

	FILE *csvfile = fopen(csv_name.c_str(), "w");
	fprintf(csvfile,"%s", csvform.c_str());
	fclose(csvfile);

	open_url(csv_name.c_str());
}
