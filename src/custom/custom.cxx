// ----------------------------------------------------------------------------
// Copyright (C) 2014
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
#include <string>
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
#include <FL/Fl_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Table_Row.H>
#include <FL/Fl_Browser.H>

#include <vector>

#include "mongoose.h"

#include "config.h"
#include "flmsg.h"
#include "templates.h"
#include "debug.h"
#include "util.h"
#include "gettext.h"
#include "flmsg_dialog.h"
#include "flmsg_config.h"
#include "flinput2.h"
#include "date.h"
#include "calendar.h"
#include "icons.h"
#include "fileselect.h"
#include "wrap.h"
#include "status.h"
#include "parse_xml.h"
#include "icons.h"
#include "threads.h"

#include "ext_string.h"

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

extern int custom_select;

extern struct mg_server *server;

static string action_str   = "\n<FORM ACTION=\"/handle_post_request\" METHOD=\"post\">\n";
static string submit_str   = "\n<INPUT TYPE=\"submit\" VALUE=\"Submit Form\">\n</form>";
static string input_str    = "<INPUT";
static string select_str   = "<SELECT";
static string end_sel_str  = "</SELECT";
static string option_str   = "<OPTION";
static string textarea_str = "<TEXTAREA";
static string textend_str  = "</TEXTAREA";
static string checked      = "CHECKED";
static string checkedeq    = "CHECKED=\"CHECKED\"";
static string selected     = "SELECTED";

static string value_str    = "VALUE=\"";
static string name_str     = "NAME=\"";

static string text_type_str = "TYPE=\"TEXT\"";
static string radio_type_str = "TYPE=\"RADIO\"";
static string checkbox_type_str = "TYPE=\"CHECKBOX\"";
static string password_type_str = "TYPE=\"PASSWORD\"";

enum {T_TEXT, T_RADIO, T_CHECKBOX, T_AREA, T_SELECT, T_OPTION, T_PASSWORD};

struct INPUT_TYPE {
	int id;
	string txt;
	INPUT_TYPE(int i, string s) {
		id = i;
		txt = s;
	}
};

static INPUT_TYPE input_types[] = {
	INPUT_TYPE(T_TEXT, text_type_str),
	INPUT_TYPE(T_PASSWORD, password_type_str),
	INPUT_TYPE(T_AREA, textarea_str),
	INPUT_TYPE(T_RADIO, radio_type_str),
	INPUT_TYPE(T_CHECKBOX, checkbox_type_str),
	INPUT_TYPE(T_SELECT, select_str)
//	INPUT_TYPE(T_OPTION, option_str)
};

struct NAME_VALUE {
	int    id;
	string name;
	string value;
	NAME_VALUE(int ID, string S1, string S2) {id = ID; name = S1; value = S2;}
};

std::vector<NAME_VALUE> name_values;

string html_form;
string edit_txt;

int convert_case(string &s)
{
	extstring mystring;
	mystring.assign(s);
	if (mystring.ufind("<FORM", 0) == string::npos ||
		mystring.ufind("</FORM", 0) == string::npos )
		return 1;
	mystring.ureplace("<FORM");
	mystring.ureplace("</FORM");
	mystring.ureplace("<INPUT");
	mystring.ureplace("<TEXTAREA");
	mystring.ureplace("</TEXTAREA");
	mystring.ureplace("VALUE=\"");
	mystring.ureplace("NAME=\"");
	mystring.ureplace("TYPE=\"");
	mystring.ureplace("=\"TEXT\"");
	mystring.ureplace("=\"RADIO\"");
	mystring.ureplace("=\"CHECKBOX\"");
	mystring.ureplace("=\"PASSWORD\"");
	mystring.ureplace("SELECTED");
	mystring.ureplace("CHECKED");
	mystring.ureplace("<SELECT");
	mystring.ureplace("</SELECT");
	mystring.ureplace("<OPTION");
	s.assign(mystring);
	return 0;
}

// this function may be called by the main or the web_server thread
// reads the values associated with each form type and
// clears the html form of those value.
void extract_fields()
{
	if (custom_select < 0) return;
	string fname = CUSTOM_dir;
	{
		guard_lock web_lock(&mutex_web_server);
		fname.append(custom_pairs[custom_select].file_name);
		edit_txt.assign("CUSTOM_FORM,")
				.append(custom_pairs[custom_select].file_name)
				.append("\n");
	}
	FILE *html_file = fopen(fname.c_str(), "r");
	char c;
	html_form.clear();
	while ((c = fgetc(html_file)) != EOF) html_form += c;
	fclose(html_file);

	if (convert_case(html_form)) {
		html_form.clear();
		custom_select = 0;
		edit_txt.assign("INVALID HTML FORM DOCUMENT");
		return;
	}

	size_t ptype, pstart, pend, pname, pvalue, p1, p2, p3;
	string field_name;
	string field_value;

	name_values.clear();

	for (size_t i = 0; i < sizeof(input_types) / sizeof(INPUT_TYPE); i++) {
		ptype = html_form.find(input_types[i].txt);
		while (ptype != string::npos) {
			field_name.clear();
			field_value.clear();
			pstart = html_form.rfind("<", ptype);
			pend = html_form.find(">", ptype);
			pname = html_form.find(name_str, pstart);

			if (pname == string::npos || pname > pend) {
				ptype = html_form.find(input_types[i].txt, ptype + 1);
				continue;
			}

			pname += name_str.length();
			p1 = html_form.find("\"", pname);
			field_name = html_form.substr(pname, p1 - pname);

			switch (input_types[i].id) {
				case T_TEXT: case T_PASSWORD:
					pvalue = html_form.find(value_str, pstart);
					if (pvalue == string::npos || pvalue > pend) break;
					pvalue += value_str.length();
					p2 = html_form.find("\"", pvalue);
					field_value = html_form.substr(pvalue, p2 - pvalue);
					break;
				case T_RADIO:
					pvalue = html_form.find(value_str, pstart);
					if (pvalue == string::npos || pvalue > pend) break;
					pvalue += value_str.length();
					p1 = html_form.find("\"", pvalue);
					if (p1 < pend) {
						field_name.append(".")
								  .append(html_form.substr(pvalue, p1 - pvalue));
						field_value.clear();
						p2 = html_form.find(checkedeq, pstart);
						if (p2 < pend) {
							field_value = checked;
							html_form.erase(p2 - 1, checkedeq.length() + 1);
							pend = html_form.find(">", pstart);
						} else {
							p2 = html_form.find(checked, pstart);
							if (p2 < pend) {
								field_value = checked;
								html_form.erase(p2 - 1, checked.length() + 1);
								pend = html_form.find(">", pstart);
							}
						}
					}
					break;
				case T_CHECKBOX:
					pvalue = html_form.find(value_str, pstart);
					if (pvalue != string::npos && pvalue < pend) {
						pvalue += value_str.length();
						p1 = html_form.find("\"", pvalue);
						if (p1 < pend) {
							field_name.append(".")
									  .append(html_form.substr(pvalue, p1 - pvalue));
						}
					}
					field_value.clear();
					p2 = html_form.find(checkedeq, pstart);
					if (p2 < pend) {
						field_value = "ON";
						html_form.erase(p2 - 1, checkedeq.length() + 1);
						pend = html_form.find(">", pstart);
					} else {
						p2 = html_form.find(checked, pstart);
						if (p2 < pend) {
							field_value = "ON";
							html_form.erase(p2 - 1, checked.length() + 1);
							pend = html_form.find(">", pstart);
						} else {
							p2 = html_form.find(" ON", pstart);
							if (p2 < pend) {
								field_value = "ON";
								html_form.erase(p2, 3);
								pend = html_form.find(">", pstart);
							}
						}
					}
					break;
				case T_AREA:
					pvalue = pend + 1;
					p1 = html_form.find(textend_str, pvalue);
					if (p1 == string::npos) break;
					field_value.assign("\"")
							   .append(html_form.substr(pvalue, p1 - pvalue))
							   .append("\"");
					html_form.erase(pvalue, field_value.length() - 2);
					break;
				case T_SELECT:
					p3 = html_form.find(end_sel_str, pstart);
					if (p3 == string::npos) break;
					p2 = html_form.find(selected, pstart);
					if (p2 != string::npos && p2 < p3) {
						pvalue = html_form.rfind(value_str, p2);
						if (pvalue != string::npos) {
							pvalue += value_str.length();
							p1 = html_form.find("\"", pvalue);
							if (p1 < p2)
								field_value = html_form.substr(pvalue, p1 - pvalue);
						}
					}
					break;
				default:
					break;
			}
			edit_txt.append(field_name).append(",");
			edit_txt.append(field_value).append("\n");
			name_values.push_back(NAME_VALUE(input_types[i].id, field_name, field_value));

			ptype = html_form.find(input_types[i].txt, ptype+1);
		}
	}
}

void refresh_txt_custom_msg(void *)
{
	txt_custom_msg->clear();
	txt_custom_msg->add(edit_txt.c_str());
}

// called by web server thread
void get_html_vars(struct mg_connection *conn)
{
	char buff[500];
	size_t p;
	if (custom_select < 0) return;

	edit_txt.assign("CUSTOM_FORM,")
			.append(custom_pairs[custom_select].file_name)
			.append("\n");

	string field, line;
	for (size_t n = 0; n < name_values.size(); n++)
		name_values[n].value.clear();

	for (size_t n = 0; n < name_values.size(); n++) {
		field = name_values[n].name;
		if (name_values[n].id == T_CHECKBOX ||
			name_values[n].id == T_RADIO) {
			if ((p = field.find(".")) != string::npos)
				field.erase(p);
		}
		mg_get_var(conn, field.c_str(), buff, sizeof(buff));
		switch (name_values[n].id) {
			case T_RADIO :
				p = name_values[n].name.find(".");
				if (name_values[n].name.substr(p+1) == buff)
					name_values[n].value = checked;
				line.assign(name_values[n].name)
					.append(",")
					.append(name_values[n].value);
				break;
			case T_CHECKBOX :
				if (strstr(buff, "on") == buff || strstr(buff, "ON") == buff)
					name_values[n].value = "ON";
				line.assign(name_values[n].name)
					.append(",")
					.append(name_values[n].value);
				break;
			case T_AREA:
				name_values[n].value = buff;
				p = name_values[n].value.find("\r\n");
				while (p != string::npos) {
					name_values[n].value.erase(p,1);
					p = name_values[n].value.find("\r\n");
				}
				line.assign(name_values[n].name)
					.append(",").append("\"")
					.append(name_values[n].value)
					.append("\"");
				break;
			case T_SELECT:
			default :  // T_TEXT, T_PASSWORD, T_SELECT
				name_values[n].value = buff;
				line.assign(name_values[n].name)
					.append(",")
					.append(name_values[n].value);
		}
		edit_txt.append(line).append("\n");
	}
	Fl::awake(refresh_txt_custom_msg);
}

// modify the html form with the value strings

void assign_values(string &html)
{
	string nm, val, s1, s2, temp;
	size_t p, p0, p1, p2, p3, pbeg, pend, pval, pnm;

	for (size_t n = 0; n < name_values.size(); n++) {
		switch (name_values[n].id) {
			case T_TEXT : case T_PASSWORD :
				nm.assign("NAME=\"").append(name_values[n].name).append("\"");
				pnm = html.find(nm);
				if (pnm != string::npos) {
					pnm += nm.length();
					p1 = html.find(value_str, pnm);
					p2 = html.find(">", pnm);
					val = name_values[n].value;
					if (p1 < p2) {
						p1 += value_str.length();
						p2 = html.find("\"", p1);
						html.replace(p1, p2 - p1, val);
					} else {
						temp.assign(" VALUE=\"").append(val).append("\"");
						html.insert(p2, temp);
					}
				}
				break;
			case T_RADIO :
				temp = name_values[n].name;
				p = temp.find(".");
				s1.assign(temp.substr(0, p));
				s2.assign(temp.substr(p+1));
				nm.assign(name_str).append(s1).append("\"");
				val.assign(value_str).append(s2).append("\"");
				pnm = html.find(nm);
				while (pnm != string::npos) {
					pbeg = html.rfind("<", pnm); // beginning of tag specifier
					pend = html.find(">", pbeg); // end of tag specifier
					pval = html.find(val, pbeg);
					if (pval == string::npos || pval > pend) {
						pnm = html.find(nm, pend);
						continue;
					}
				// found name and value pair
					if (name_values[n].value == checked)
						html.insert(pend, string(" ").append(checked));
					pend = html.find(">", pbeg);
					pnm = html.find(nm, pend);
				}
				break;
			case T_CHECKBOX :
				nm.assign("NAME=\"").append(name_values[n].name).append("\"");
				pnm = html.find(nm);
				if (pnm != string::npos) {
					pbeg = html.rfind("<", pnm);
					pend = html.find(">", pbeg);
					if (name_values[n].value == "ON") {
						html.insert(pend, string(" ").append(checked));
						pend = html.find(">", pbeg);
					}
				}
				break;
			case T_AREA :
				nm.assign("NAME=\"").append(name_values[n].name).append("\"");
				pnm = html.find(nm);
				if (pnm != string::npos) {
					p1 = html.find("</TEXTAREA", pnm);
					p0 = html.rfind(">", p1);
					string val = name_values[n].value;
					if (val[0] == '"') val.erase(0,1);
					if (val[val.length() -1] == '"') val.erase(val.length()-1, 1);
					html.replace(p0+1, p1-p0-1, val);
				}
				break;
			case T_SELECT :
				nm.assign("NAME=\"").append(name_values[n].name).append("\"");
				pnm = html.find(nm);
				if (pnm != string::npos) {
					p2 = html.find("</SELECT", pnm);
					p0 = html.find(value_str, pnm);
					while(p0 != string::npos && p0 < p2) {
						p0 += value_str.length();
						p1 = html.find("\"", p0);
						if (p1 != string::npos && p1 < p2) {
							p3 = html.find(">", p1);
							if (html.substr(p0, p1 - p0) == name_values[n].value) {
								html.replace(p1+1, p3 - p1 - 1, " SELECTED");
							} else
								html.replace(p1+1, p3 - p1 - 1, "");
						}
						p0 = html.find(value_str, p0);
					}
				}
				break;
			default :
				break;
		}
	}
}

void custom_editor(struct mg_connection *conn)
{
	string html_edit = html_form;
	size_t p = html_edit.find("<FORM>");

	if (p == string::npos) return;

	html_edit.replace(p, 6, action_str);
	p = html_edit.find("</FORM>");
	html_edit.replace(p, 7, submit_str);
	assign_values(html_edit);
	mg_send_data(conn, html_edit.c_str(), html_edit.length());
}

void custom_viewer(struct mg_connection *conn)
{
	string html_view = html_form;

	assign_values(html_view);

// add readonly attribute to all input controls
	size_t pstart, ptext, pradio, pcheckbox, ppassword, pend;
	pstart = html_view.find("<INPUT");

	while (pstart != string::npos) {
		pend = html_view.find(">", pstart);
		ppassword = html_view.find("\"PASSWORD\"", pstart);
		if (ppassword < pend) {
			size_t pvalue = html_view.find("VALUE=\"", pstart);
			if (pvalue < pend) {
				pvalue += 7;
				while (html_view[pvalue] != '\"') {
					html_view[pvalue] = '*';
					pvalue++;
				}
			}
			html_view.replace(ppassword, 10, "\"TEXT\"");
		}
		pstart = html_view.find("<INPUT", pend + 1);
	}

	pstart = html_view.find("<INPUT");
	while (pstart != string::npos) {
		pend = html_view.find(">", pstart);
		ptext = html_view.find("\"TEXT\"", pstart);
		pradio = html_view.find("\"RADIO\"", pstart);
		pcheckbox = html_view.find("\"CHECKBOX\"", pstart);
		if (ptext < pend)
			html_view.insert(pstart + 6, " READONLY ");
		else if (pradio < pend || pcheckbox < pend)
			html_view.insert(pstart + 6, " DISABLED ");
		pstart = html_view.find("<INPUT", pend + 1);
	}

	while (pstart != string::npos) {
		pend = html_view.find(">", pstart);
		ptext = html_view.find("\"TEXT\"", pstart);
		ppassword = html_view.find("\"PASSWORD\"", pstart);
		pradio = html_view.find("\"RADIO\"", pstart);
		pcheckbox = html_view.find("\"CHECKBOX\"", pstart);
		if (ppassword < pend) {
			size_t pvalue = html_view.find("VALUE=\"");
			if (pvalue < pend) {
				pvalue += 7;
				while (html_view[pvalue] != '\"') {
					html_view[pvalue] = '*';
					pvalue++;
				}
			}
			html_view.replace(ppassword, 10, "\"TEXT\"");
			html_view.insert(pstart + 6, " READONLY ");
		} else if (ptext < pend)
			html_view.insert(pstart + 6, " READONLY ");
		else if (pradio < pend || pcheckbox < pend)
			html_view.insert(pstart + 6, " DISABLED ");
		pstart = html_view.find("<INPUT", pend + 1);
	}
	pstart = html_view.find("<TEXTAREA");
	while (pstart != string::npos) {
		pend = html_view.find(">", pstart);
		html_view.insert(pstart + 10, " READONLY ");
		pstart = html_view.find("<TEXTAREA", pend + 1);
	}
	pstart = html_view.find("<SELECT");
	while (pstart != string::npos) {
		pend = html_view.find(">", pstart);
		html_view.insert(pstart + 7, " DISABLED ");
		pstart = html_view.find("<SELECT", pend + 1);
	}
	mg_send_data(conn, html_view.c_str(), html_view.length());
}

// customform fields

string custombuffer;
string def_custom_filename = "";
string base_custom_filename = "";
string def_custom_TemplateName = "";

string custom_title = ":TITLE:";
string custom_msg = ":mg:";
string custom_field;

bool using_custom_template = false;

void clear_customfields()
{
	custom_field.clear();
}

bool check_customfields()
{
	return (custom_field != txt_custom_msg->buffer()->text());
}

void update_customfields()
{
	custom_field = txt_custom_msg->buffer()->text();
}

void clear_custom_form()
{
	clear_customfields();
	txt_custom_msg->clear();
}

void text_to_pairs()
{
	size_t p, p1, pquote;
	for (size_t n = 0; n < name_values.size(); n++) {
		p = edit_txt.find(name_values[n].name);
		if (p != string::npos) {
			p += name_values[n].name.length() + 1;
			pquote = edit_txt.find("\"", p);
			p1 = edit_txt.find("\n", p);
			if (pquote < p1) {
				p = pquote + 1;
				p1 = edit_txt.find("\"", p + 1);
			}
			name_values[n].value = edit_txt.substr(p, p1 - p);
		}
	}
}

void update_customform()
{
	extract_fields();
	edit_txt = custom_field;
	txt_custom_msg->clear();
	txt_custom_msg->add(edit_txt.c_str());
	text_to_pairs();
}

void read_custombuffer(string data)
{
	size_t p0, p1;

	clear_customfields();
	read_header(data);
	custom_field = findstr(data, custom_msg);

	custom_select = -1;

	p0 = custom_field.find("CUSTOM_FORM,");
	if (p0 == string::npos) return;
	p0 += 12;//strlen("CUSTOM_FORM,");
	p1 = custom_field.find("\n", p0);
	if (p1 == string::npos) return;
	string fname = custom_field.substr(p0, p1-p0);
	string html_fname = CUSTOM_dir;
	html_fname.append(fname);

	{ // treat this block as a critical section
		guard_lock web_lock(&mutex_web_server);
		for (int i = 0; i < num_custom_entries; i++) {
			if (fname == custom_pairs[i].file_name) {
				custom_select = i;
				break;
			}
		}
	}
	update_customform();
}

void cb_custom_new()
{
	if (check_customfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_custom_save();
		}
	}
	clear_custom_form();
	clear_header();
	def_custom_filename = ICS_msg_dir;
	def_custom_filename.append("new"CUSTOMFILE_EXT);
	show_filename(def_custom_filename);
	using_custom_template = false;
}

void cb_custom_import()
{
	fl_alert2("Not implemented");
}

void cb_custom_export()
{
	fl_alert2("Not implemented");
}

void cb_custom_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_custom_form();
	read_custombuffer(inpbuffer);
	def_custom_filename = ICS_msg_dir;
	def_custom_filename.append(wrapfilename);
	show_filename(def_custom_filename);
	using_custom_template = false;
}

int eval_custom_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_custom_filename).append("]");
	update_customfields();
	update_header(FROM);
	evalstr.append(header("<customform>"));
	string outbuf = lineout( custom_msg, custom_field );
	if (outbuf.empty()) return 0;
	compress_maybe( outbuf );
	evalstr.append( outbuf );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_custom_wrap_export()
{
	if (check_customfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_customfields();
	if (custom_field.empty()) return;

	if (base_custom_filename == "new"CUSTOMFILE_EXT || base_custom_filename == "default"CUSTOMFILE_EXT)
		if (!cb_custom_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_custom_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(FROM);
		custombuffer.assign(header("<customform>"));
		string outbuf = lineout( custom_msg, custom_field );
		compress_maybe(outbuf);
		custombuffer.append(outbuf);
		export_wrapfile(base_custom_filename, wrapfilename, custombuffer, pext != WRAP_EXT);

		custombuffer.assign(header("<customform>")).append(lineout( custom_msg, custom_field ));
		write_custom(def_custom_filename);
	}
}

void cb_custom_wrap_autosend()
{
	if (check_customfields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_customfields();
	if (custom_field.empty()) return;

	if (base_custom_filename == "new"CUSTOMFILE_EXT || base_custom_filename == "default"CUSTOMFILE_EXT)
		if (!cb_custom_save_as()) return;

	update_header(FROM);
	custombuffer.assign(header("<customform>"));
	string outbuf = lineout( custom_msg, custom_field );

	compress_maybe(outbuf);
	custombuffer.append(outbuf);
	xfr_via_socket(base_custom_filename, custombuffer);

	custombuffer.assign(header("<customform>")).append(lineout( custom_msg, custom_field ));
	write_custom(def_custom_filename);
}

void cb_custom_load_template()
{
	return;
}

void cb_custom_save_template()
{
	if (!using_custom_template) {
		cb_custom_save_as_template();
		return;
	}
	string def_custom_filename = def_custom_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"CUSTOMTEMP_EXT,
			def_custom_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_customfields();
		custombuffer.assign(header("<customform>"));
		custombuffer.append( lineout( custom_msg, custom_field ) );
		write_custom(p);
	}
}

void cb_custom_save_as_template()
{
	string def_custom_filename = def_custom_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"CUSTOMTEMP_EXT,
			def_custom_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_custom_TemplateName = p;
		if (strlen(pext) == 0) def_custom_TemplateName.append(CUSTOMTEMP_EXT);
		remove_spaces_from_filename(def_custom_TemplateName);
		clear_header();
		update_header(CHANGED);
		update_customfields();
		custombuffer.assign(header("<customform>"));
		custombuffer.append( lineout( custom_msg, custom_field ) );
		write_custom(def_custom_TemplateName);
		show_filename(def_custom_TemplateName);
		using_custom_template = true;
	}
}

void cb_custom_open()
{
	const char *p = FSEL::select(_("Open data file"), "custom form\t*.k2s",
					def_custom_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_custom_form();
	read_data_file(p);
	using_custom_template = false;
	def_custom_filename = p;
	show_filename(def_custom_filename);
}

void write_custom(string s)
{
	if (custombuffer.empty()) 
		return;
	FILE *customfile = fopen(s.c_str(), "w");
	if (!customfile) return;
	fwrite(custombuffer.c_str(), custombuffer.length(), 1, customfile);
	fclose(customfile);
}

bool cb_custom_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(".k2s");
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_custom_filename;

	p = FSEL::saveas(_("Save data file"), "custom form\t*.k2s",
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
	def_custom_filename = p;
	if (strlen(pext) == 0) def_custom_filename.append(".k2s");

	remove_spaces_from_filename(def_custom_filename);
	update_header(NEW);
	update_customfields();
	custombuffer.assign(header("<customform>"));
	custombuffer.append( lineout( custom_msg, custom_field ) );
	write_custom(def_custom_filename);

	using_custom_template = false;
	show_filename(def_custom_filename);
	return true;
}

void cb_custom_save()
{
	if (base_custom_filename == "new.k2s" || 
		base_custom_filename == "default.k2s" ||
		using_custom_template == true) {
		cb_custom_save_as();
		return;
	}
	if (check_customfields()) update_header(CHANGED);
	update_customfields();
	custombuffer.assign(header("<customform>"));
	custombuffer.append( lineout( custom_msg, custom_field ) );
	write_custom(def_custom_filename);
	using_custom_template = false;
}

void cb_custom_msg_type()
{
	if (tabs_msg_type->value() == tab_custom ) {
		show_filename(def_custom_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_custom_import_data()
{
	def_custom_filename = CUSTOM_dir;
	def_custom_filename.append("default.custom");

	const char *p = FSEL::select(
						_("Import custom data"),
						"custom file\t*.custom",
						def_custom_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;\

	clear_custom_form();
	clear_estimate();

// open the custom file, read all data
	long filesize = 0;
	char *buff;
	FILE *custom_datafile;

	custom_datafile = fopen (p, "r");
	if (!custom_datafile)
		return;
// determine its size for buffer creation
	fseek (custom_datafile, 0, SEEK_END);
	filesize = ftell (custom_datafile);
// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
		return;
	}

	buff = new char[filesize + 1];
	memset(buff, 0, filesize + 1);
// read the entire file into the buffer
	fseek (custom_datafile, 0, SEEK_SET);
	int retval = fread (buff, filesize, 1, custom_datafile);
	fclose (custom_datafile);
	if (retval != 1) return;

	custom_field = buff;
// strip any cr-lf pairs if the file was a DOS text file
	size_t ptr = custom_field.find("\r\n");
	while (ptr != string::npos) {
		custom_field.erase(ptr, 1);
		ptr = custom_field.find("\r\n");
	}
	update_customform();

	delete [] buff;

	using_custom_template = false;

	def_custom_filename = ICS_msg_dir;
	def_custom_filename.append(fl_filename_name(p));
	size_t pext = def_custom_filename.find(".custom");
	if (pext == string::npos) pext = def_custom_filename.find(".custom");
	if (pext != string::npos) def_custom_filename.erase(pext);
	def_custom_filename.append(".k2s");
	show_filename(def_custom_filename);
	estimate();
}

void cb_custom_export_data(bool open_file)
{
	update_customfields();
	if (custom_field.empty()) return;

	string fname_name = fl_filename_name(def_custom_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string custom_name = CUSTOM_dir;
	custom_name.append(fname_name).append(".custom");

	const char *pfilename = FSEL::saveas(
							_("Export custom data"),
							"custom file\t*.custom",
							custom_name.c_str());

	if (!pfilename) return;
	if (strlen(pfilename) == 0) return;
	custom_name = pfilename;
	if (custom_name.find(".custom") == string::npos)
		custom_name.append(".custom");

	FILE *customfile = fopen(custom_name.c_str(), "w");
	fprintf(customfile,"%s", custom_field.c_str());
	fclose(customfile);

	if (open_file) {
		fl_alert2("If you modify the data you must save as custom and\nimport the modified file");
		open_url(pfilename);
	} else
		fl_alert2("Data written to %s", custom_name.c_str());

}

void custom_set_fname(const char *fn)
{
	string fname = fn;
	size_t pext = fname.find(".custom");
	if (pext == string::npos) pext = fname.find(".custom");
	if (pext == string::npos) {
		txt_custom_msg->clear();
		return;
	}
	using_custom_template = false;
	def_custom_filename = ICS_msg_dir;
	def_custom_filename.append(fl_filename_name(fn));
	def_custom_filename.find(".custom");
	if (pext == string::npos) pext = def_custom_filename.find(".custom");
	if (pext != string::npos) def_custom_filename.erase(pext);
	def_custom_filename.append(".k2s");
	show_filename(def_custom_filename);
}

void cb_custom_html()
{
	if (custom_field.find("CUSTOM_FORM") == 0) {
		size_t plf = custom_field.find("\n");
		if (plf != string::npos) {
			string fname = CUSTOM_dir;
			fname.append(custom_field.substr(12, plf - 12));
			FILE *html_file = fopen(fname.c_str(), "r");
			char c;

			html_form.clear();
			while ((c = fgetc(html_file)) != EOF) html_form += c;
			fclose(html_file);

			handle_type = HANDLE_VIEW;
			string url = "http://127.0.0.1:";
			url.append(flmsg_webserver_szportnbr);
			open_url(url.c_str());
		}
	}
}

void cb_custom_textout()
{
	if (custom_field.find("CUSTOM_FORM") == 0) {
		size_t plf = custom_field.find("\n");
		if (plf != string::npos) {
			string tempfile = FLMSG_temp_dir;
			tempfile.append(custom_field.substr(12, plf - 12));
			tempfile.append(".txt");
			FILE *textfile = fopen(tempfile.c_str(), "w");
			fprintf(textfile,"%s", edit_txt.c_str());
			fclose(textfile);
			open_url(tempfile.c_str());
		}
	}
}

//==============================================================================
// Support for transfering / receiving custom FORM, html files
//==============================================================================

string transfer_custom_buffer;
string def_custom_transfer_filename;

string def_custom_rx_filename;
string receive_custom_buffer;

void read_custom_transfer_buffer(string data)
{
	const char *xfrstr = "<html_form>\n";
	size_t p1 = data.find(xfrstr);
	if (p1 != string::npos) p1 += strlen(xfrstr);
	data.erase(0, p1);
	receive_custom_buffer = data;
	read_header(data);
}

void cb_custom_form_wrap_import(string wrapfilename, string inpbuffer)
{
	read_custom_transfer_buffer(inpbuffer);

	def_custom_rx_filename = CUSTOM_dir;
	def_custom_rx_filename.append(wrapfilename);
	txt_rcvd_custom_html_filename->value(def_custom_rx_filename.c_str());
	btn_save_custom_html_file->color(FL_RED);
}

int eval_transfer_custom_form_fsize()
{
	if (transfer_custom_buffer.empty()) return 0;

	Ccrc16 chksum;

	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(fl_filename_name(def_custom_transfer_filename.c_str())).append("]");
	evalstr.append(header("<html_form>"));

	string outbuf(transfer_custom_buffer);
	if (outbuf.empty()) return 0;

	compress_maybe( outbuf, false );

	evalstr.append( outbuf );
	string ck = chksum.scrc16(evalstr);

	evalstr.append("[WRAP:chksum ").append(ck).append("][WRAP:end]");

	return evalstr.length();
}

void load_custom_html_file()
{
	string fname = CUSTOM_dir;
	fname.append(def_custom_transfer_filename);
	transfer_custom_buffer.clear();

	FILE *dfile = fopen(fname.c_str(), "rb");
	if (!dfile) {
		show_filename("ERROR");
		transfer_custom_buffer.clear();
		return;
	}
	fseek(dfile, 0, SEEK_END);
	size_t fsize = ftell(dfile);
	if (fsize <= 0) return;
	fseek(dfile, 0, SEEK_SET);
	transfer_custom_buffer.resize(fsize);
	size_t r = fread((void *)transfer_custom_buffer.c_str(), 1, fsize, dfile);
	fclose(dfile);
	if (r != fsize) {
		show_filename("ERROR");
		transfer_custom_buffer.clear();
		return;
	}
	estimate();
}

void cb_transfer_custom_html()
{
	if (transfer_custom_buffer.empty()) return;

	update_header(FROM);
	string fbuff(header("<html_form>"));
	string outbuf(transfer_custom_buffer);
	compress_maybe(outbuf, false);
	fbuff.append(outbuf);
	xfr_via_socket(fl_filename_name(def_custom_transfer_filename.c_str()), fbuff);
}

void cb_save_custom_html(Fl_Widget *w, void *d)
{
	btn_save_custom_html_file->color(FL_BACKGROUND_COLOR);

	if (receive_custom_buffer.empty()) return;

	FILE *binfile = fopen(def_custom_rx_filename.c_str(), "wb");
	if (binfile) {
		fwrite(receive_custom_buffer.c_str(), receive_custom_buffer.length(), 1, binfile);
		fclose(binfile);
	}
	txt_rcvd_custom_html_filename->value("");
	update_custom_transfer();
}

void cb_btn_select_custom_html(Fl_Widget *w, void *d)
{
	def_custom_transfer_filename = custom_files[custom_selector->index()];
	show_filename(def_custom_transfer_filename);
	load_custom_html_file();
}
