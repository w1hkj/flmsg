// =====================================================================
//
// iaru.cxx
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

string iaru_base_filename = "";
string iaru_def_filename = "";
string iaru_def_template_name = "";

static string iaru_buffer;

// iaru iaru_fields

const char *iaru_s_prec[] = {"ROUTINE", "PRIORITY", "EMERGENCY"};
const char iaru_prec_items[] = "ROUTINE|PRIORITY|EMERGENCY";

// new tag strings

string iaru_nbr		= ":nbr:";		// 0
string iaru_prec	= ":prec:";		// 1
string iaru_station	= ":sta:";		// 2
string iaru_check	= ":ck:";		// 3
string iaru_orig	= ":org:";		// 4

string iaru_d1		= ":d1:";		// 5
string iaru_t1		= ":t1:";		// 6

string iaru_to		= ":to:";		// 7
string iaru_msg		= ":msg:";		// 8
string iaru_fm		= ":fm:";		// 9

string iaru_rcv_fm	= ":rcv:";		// 10
string iaru_d2		= ":d2:";		// 11
string iaru_t2		= ":t2:";		// 12

string iaru_sent_to	= ":sto:";		// 13
string iaru_d3		= ":d3:";		// 14
string iaru_t3		= ":t3:";		// 15

FIELD iaru_fields[] = {
{ iaru_nbr,		"", (void **)&iaru_txt_nbr,			't' },	// 0
{ iaru_prec,	"", (void **)&iaru_sel_prec,		's' },	// 1
{ iaru_station,	"", (void **)&iaru_txt_station,		't' },	// 2
{ iaru_check,	"", (void **)&iaru_txt_check,		't' },	// 3
{ iaru_orig,	"", (void **)&iaru_txt_orig,		't' },	// 4
{ iaru_d1,		"", (void **)&iaru_txt_d1,			't' },	// 5
{ iaru_t1,		"", (void **)&iaru_txt_t1,			't' },	// 6
{ iaru_to,		"", (void **)&iaru_txt_to,			't' },	// 7
{ iaru_msg,		"", (void **)&iaru_txt_msg,			'e' },	// 8
{ iaru_fm,		"", (void **)&iaru_txt_fm,			't' },	// 9
{ iaru_rcv_fm,	"", (void **)&iaru_txt_rcv_fm,		't' },	// 10
{ iaru_d2,		"", (void **)&iaru_txt_d2,			't' },	// 11
{ iaru_t2,		"", (void **)&iaru_txt_t2,			't' },	// 12
{ iaru_sent_to,	"", (void **)&iaru_txt_sent_to,		't' },	// 113
{ iaru_d3,		"", (void **)&iaru_txt_d3,			't' },	// 14
{ iaru_t3,		"", (void **)&iaru_txt_t3,			't' }	// 15

};

bool iaru_using_template = false;

int iaru_num_fields = sizeof(iaru_fields) / sizeof(FIELD);

//======================================================================

void iaru_cb_set_d1()
{
	iaru_txt_d1->value(szAbbrevDate());
}

void iaru_cb_set_t1()
{
	iaru_txt_t1->value(szTime(progStatus.UTC));
}

void iaru_cb_set_d2()
{
	iaru_txt_d2->value(szAbbrevDate());
}

void iaru_cb_set_t2()
{
	iaru_txt_t2->value(szTime(progStatus.UTC));
}

void iaru_cb_set_d3()
{
	iaru_txt_d3->value(szAbbrevDate());
}

void iaru_cb_set_t3()
{
	iaru_txt_t3->value(szTime(progStatus.UTC));
}

void iaru_cb_nbr(Fl_Widget *wdg)
{
	Fl_Input2 *inp = (Fl_Input2 *)wdg;
	string s = inp->value();
	for (size_t n = 0; n < s.length(); n++)
		if (!isdigit(s[n])) s.erase(n,1);
	strip_leading_zeros(s);
	inp->value(s.c_str());
}

static char valid_input[] = "0123456789/ ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

void iaru_cb_filter_input(Fl_Widget *wdg)
{
	Fl_Input2 *inp = (Fl_Input2 *)wdg;
	string s = inp->value();
	ucase(s);
	for (size_t n = 0; n < s.length(); n++)
		if (strchr(valid_input, s[n]) == NULL)
			s.erase(n,1);
	inp->value(s.c_str());
}

void iaru_clear_fields()
{
	for (int i = 0; i < iaru_num_fields; i++)
		iaru_fields[i].f_data.clear();
}

static string numeric(int n)
{
	static char snum[10];
	snprintf(snum, sizeof(snum), "%d", n);
	return snum;
}

void iaru_set_choices() {
	iaru_sel_prec->clear();
	iaru_sel_prec->add(iaru_prec_items);
	iaru_sel_prec->value(0);
}

void iaru_update_fields()
{
	for (int i = 0; i < iaru_num_fields; i++) {
		if (iaru_fields[i].w_type == 'd')
			iaru_fields[i].f_data = ((Fl_DateInput *)(*iaru_fields[i].w))->value();
		else if (iaru_fields[i].w_type == 't')
			iaru_fields[i].f_data = ((Fl_Input2 *)(*iaru_fields[i].w))->value();
		else if (iaru_fields[i].w_type == 's')
			iaru_fields[i].f_data = numeric(((Fl_Choice *)(*iaru_fields[i].w))->value());
		else if (iaru_fields[i].w_type == 'e')
			iaru_fields[i].f_data = ((FTextEdit *)(*iaru_fields[i].w))->buffer()->text();
		else if (iaru_fields[i].w_type == 'b')
			iaru_fields[i].f_data = ((Fl_Button *)(*iaru_fields[i].w))->value() ? "T" : "F";
	}
}

void iaru_clear_form()
{
	iaru_clear_fields();

	if (progStatus.rgnbr_fname)
		iaru_txt_nbr->value(progStatus.rgnbr.c_str());
	else
		iaru_txt_nbr->value("");

	for (int i = 1; i < iaru_num_fields; i++)
		if (iaru_fields[i].w_type == 'd')
			((Fl_DateInput *)(*iaru_fields[i].w))->value("");
		else if (iaru_fields[i].w_type == 't')
			((Fl_Input2 *)(*iaru_fields[i].w))->value("");
		else if (iaru_fields[i].w_type == 's')
			((Fl_Choice *)(*iaru_fields[i].w))->value(0);
		else if (iaru_fields[i].w_type == 'e')
			((FTextEdit *)(*iaru_fields[i].w))->clear();
		else if (iaru_fields[i].w_type == 'b')
			((Fl_Button *)(*iaru_fields[i].w))->value(0);
	iaru_update_fields();
}

void iaru_update_form()
{
	for (int i = 0; i < iaru_num_fields; i++) {
		if (iaru_fields[i].w_type == 'd')
			((Fl_DateInput *)(*iaru_fields[i].w))->value(iaru_fields[i].f_data.c_str());
		else if (iaru_fields[i].w_type == 't')
			((Fl_Input2 *)(*iaru_fields[i].w))->value(iaru_fields[i].f_data.c_str());
		else if (iaru_fields[i].w_type == 's')
			((Fl_Choice *)(*iaru_fields[i].w))->value(atoi(iaru_fields[i].f_data.c_str()));
		else if (iaru_fields[i].w_type == 'e') {
			((FTextEdit *)(*iaru_fields[i].w))->clear();
			((FTextEdit *)(*iaru_fields[i].w))->add(iaru_fields[i].f_data.c_str());
		} else if (iaru_fields[i].w_type == 'b')
			((Fl_Button *)(*iaru_fields[i].w))->value(iaru_fields[i].f_data == "T" ? 1 : 0);
	}
}

void iaru_make_buffer()
{
	iaru_update_fields();

	for (int i = 0; i < iaru_num_fields; i++)
		iaru_buffer.append( lineout( iaru_fields[i].f_type, iaru_fields[i].f_data ) );
}

void iaru_read_buffer(string data)
{
	bool data_ok = false;
	clear_fields();
	read_header(data);

	for (int i = 0; i < iaru_num_fields; i++) {
		iaru_fields[i].f_data = findstr(data, iaru_fields[i].f_type);
		if (!iaru_fields[i].f_data.empty()) data_ok = true;
	}

	iaru_update_form();
}

void iaru_cb_new()
{
	iaru_clear_form();
	clear_header();
	iaru_def_filename = ICS_msg_dir;
	iaru_def_filename.append("new"IARU_FILE_EXT);
	iaru_using_template = false;
	show_filename(iaru_def_filename);
}

void iaru_cb_import()
{
	fl_alert2("Not implemented");
}

void iaru_cb_export()
{
	fl_alert2("Not implemented");
}

void iaru_cb_wrap_import(string wrapfilename, string inpbuffer)
{
	iaru_clear_form();
	iaru_read_buffer(inpbuffer);
	iaru_def_filename = ICS_msg_dir;
	iaru_def_filename.append(wrapfilename);
	show_filename(iaru_def_filename);
	iaru_using_template = false;
}

void iaru_cb_wrap_export()
{
	if (iaru_base_filename == "new"IARU_FILE_EXT || iaru_base_filename == "default"IARU_FILE_EXT)
		iaru_cb_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(iaru_base_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrapped iaru file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(true);
		buffer.assign(header("<radiogram>", true, true));
		iaru_make_buffer();
		export_wrapfile(iaru_base_filename, wrapfilename, iaru_buffer, pext != WRAP_EXT);
	}
}

void iaru_cb_wrap_autosend()
{
	if (iaru_base_filename == "new"IARU_FILE_EXT || 
		iaru_base_filename == "default"IARU_FILE_EXT ||
		iaru_using_template == true)
		iaru_cb_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	update_header(true);
	buffer.assign(header("<radiogram>", true, true));
	iaru_make_buffer();
	export_wrapfile(iaru_base_filename, wrapfilename, iaru_buffer, false);
}

void iaru_cb_load_template()
{
	string iaru_def_filename = iaru_def_template_name;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"IARU_TEMP_EXT,
			iaru_def_filename.c_str());
	if (p) {
		iaru_clear_form();
		read_data_file(p);
		iaru_def_template_name = p;
		show_filename(iaru_def_template_name);
		iaru_using_template = true;
	}
}

void iaru_cb_save_template()
{
	if (!iaru_using_template) {
		iaru_cb_save_as_template();
		return;
	}
	string iaru_def_filename = iaru_def_template_name;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"IARU_TEMP_EXT,
			iaru_def_filename.c_str());
	if (p) {
		clear_header();
		iaru_write(p);
	}
}

void iaru_cb_save_as_template()
{
	string iaru_def_filename = iaru_def_template_name;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"IARU_TEMP_EXT,
			iaru_def_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		iaru_def_template_name = p;
		if (strlen(pext) == 0) iaru_def_template_name.append(IARU_TEMP_EXT);
		remove_spaces_from_filename(iaru_def_template_name);
		clear_header();
		iaru_write(iaru_def_template_name);
		show_filename(iaru_def_template_name);
		iaru_using_template = true;
	}
}

void iaru_cb_open()
{
	const char *p = FSEL::select(_("Open data file"), "iaru\t*"IARU_FILE_EXT,
					iaru_def_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	iaru_clear_form();
	read_data_file(p);
	iaru_using_template = false;
	iaru_def_filename = p;
	show_filename(iaru_def_filename);
}

void iaru_write(string s)
{
	FILE *iaru_file = fopen(s.c_str(), "w");
	if (!iaru_file) return;
	update_header();
	buffer.assign(save_header("<radiogram>"));
	iaru_make_buffer();
	fwrite(iaru_buffer.c_str(), iaru_buffer.length(), 1, iaru_file);
	fclose(iaru_file);
}

void iaru_cb_save_as()
{
	const char *p;
	string newfilename;
	string name = named_file();

	if (!name.empty()) {
		name.append(IARU_FILE_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = iaru_def_filename;
	p = FSEL::saveas(_("Save data file"), "iaru\t*"IARU_FILE_EXT,
						newfilename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	if (progStatus.rgnbr_fname) {
		int n = atoi(progStatus.rgnbr.c_str());
		n++;
		char szn[10];
		snprintf(szn, sizeof(szn), "%d", n);
		progStatus.rgnbr = szn;
		txt_rgnbr->value(szn);
		txt_rgnbr->redraw();
	} else if (progStatus.sernbr_fname) {
		int n = atoi(progStatus.sernbr.c_str());
		n++;
		char szn[10];
		snprintf(szn, sizeof(szn), "%d", n);
		progStatus.sernbr = szn;
		txt_sernbr->value(szn);
		txt_sernbr->redraw();
	}
	const char *pext = fl_filename_ext(p);
	iaru_def_filename = p;
	if (strlen(pext) == 0) iaru_def_filename.append(IARU_FILE_EXT);

	remove_spaces_from_filename(iaru_def_filename);
	clear_header();
	iaru_write(iaru_def_filename);

	iaru_using_template = false;
	show_filename(iaru_def_filename);
}

void iaru_cb_save()
{
	if (iaru_base_filename == "new"IARU_FILE_EXT || 
		iaru_base_filename == "default"IARU_FILE_EXT ||
		iaru_using_template == true) {
		iaru_cb_save_as();
		return;
	}
	iaru_write(iaru_def_filename);
	iaru_using_template = false;
}

const char *iaru_punctuation[] = {
". ", " X ",
",", " COMMA ",
"?", " QUERY ",
"\\", " BACKSLASH ",
"://", " COLON SLASH SLASH ",
"~", " TILDE ",
"_", " UNDERSCORE ",
"@", " AT ",
"#", " POUNDSIGN ",
"\"", " QUOTE ",
"\'", "",
 0, 0 };

void iaru_cb_check()
{
	string temp = iaru_txt_msg->buffer()->text();
	if (temp.empty()) {
		iaru_txt_check->value("");
		iaru_btn_check->labelcolor(FL_BLACK);
		iaru_btn_check->redraw_label();
		return;
	}

	// convert to uppercase
	for (size_t n = 0; n < temp.length(); n++)
		temp[n] = toupper(temp[n]);

	size_t pos = string::npos;

	strip_lfs(temp);
	// remove trailing period
	if (temp[temp.length()-1] == '.') temp.erase(temp.length()-1,1);
	// convert punctuation
	for (int n = 0; iaru_punctuation[n]; n += 2)
		while ((pos = temp.find(iaru_punctuation[n])) != string::npos)
			temp.replace(pos,1,iaru_punctuation[n+1]);
	//convert embedded periods
	while ((pos = temp.find(".")) != string::npos)
		if (isdigit(temp[pos-1]) || isdigit(temp[pos+1]))
			temp[pos] = 'R';
		else
			temp.replace(pos, 1, " DOT ");

	// remove any user inserted end-of-lines
	while ((pos = temp.find('\n')) != string::npos) temp[pos] = ' ';

	// only single spaces no trailing spaces, no leading spaces
	while ((pos = temp.find("  ")) != string::npos) temp.erase(pos,1);
	while (temp[temp.length() -1] == ' ') temp.erase(temp.length()-1, 1);
	if (temp[0] == ' ') temp.erase(0,1);

	// count number of words in textiaru_def_filename
	int numwords = 1;
	if (temp.length()) {
		pos = 0;
		while ((pos = temp.find(" ", pos + 1)) != string::npos) numwords++;
	}

	// no more than 5 words to a line
	if (numwords > progStatus.wpl) {
		int wc = numwords;
		size_t pos = 0;
		while (wc > progStatus.wpl) {
			for (int i = 0; i < progStatus.wpl; i++) pos = temp.find(' ', pos + 1);
			temp[pos] = '\n';
			wc -= progStatus.wpl;
		}
	}
	// insert trailing end-of-line
	temp += '\n';

	// return converted text to editor
	iaru_txt_msg->clear();
	iaru_txt_msg->addstr(temp.c_str());

	char snum[10];
	snprintf(snum, sizeof(snum), "%s%d", 
		temp.find("ARL") != string::npos ? "ARL " : "",
		numwords);
	iaru_txt_check->value(snum);
	iaru_update_fields();
	iaru_btn_check->labelcolor(FL_BLACK);
	iaru_btn_check->redraw_label();
}

void iaru_cb_html()
{
	string iaru_name;
	string html_text;
	int nbr;
	iaru_name = ICS_dir;
	iaru_name.append("iaru.html");

	iaru_update_fields();
	iaru_cb_check();
	string form = iaru_html_template;

	for (int i = 0; i < iaru_num_fields; i++) {
		if (iaru_fields[i].f_type == iaru_prec) {
			sscanf(iaru_fields[i].f_data.c_str(), "%d", &nbr);
			html_text = iaru_s_prec[nbr];
			replacestr( form, iaru_fields[i].f_type, html_text );
		} else if (iaru_fields[i].w_type == 'b') {
			replacestr( form, iaru_fields[i].f_type, iaru_fields[i].f_data == "T" ? yes : no);
		} else
			replacestr( form, iaru_fields[i].f_type, iaru_fields[i].f_data );
	}

	string rxstr = "";
	rxstr.append(progStatus.my_call).append(" ").append(progStatus.my_tel);
	rxstr.append("<br>").append(progStatus.my_name);
	rxstr.append("<br>").append(progStatus.my_addr);
	rxstr.append("<br>").append(progStatus.my_city);
	html_text = ":rx:";
	replacestr( form, html_text, rxstr);

	html_text = ":exp:";
	string arlmsgs = "";
	if (progStatus.arl_desc)
		arlmsgs = expand_arl(iaru_fields[10].f_data);
	replacestr( form, html_text, arlmsgs);

	FILE *iaru_file = fopen(iaru_name.c_str(), "w");
	fprintf(iaru_file,"%s", form.c_str());
	fclose(iaru_file);

	open_url(iaru_name.c_str());
}

void iaru_cb_textout()
{
	string iaru_name;
	string lines;
	string str;
	int nbr = 0;//, fn;
	iaru_name = ICS_dir;
	iaru_name.append("iaru.txt");

	iaru_update_fields();
	iaru_cb_check();

	string form = iaru_txt_template;

	for (int i = 0; i < iaru_num_fields; i++) {
		str.clear();
		if (iaru_fields[i].f_type == iaru_prec) {
			sscanf(iaru_fields[i].f_data.c_str(), "%d", &nbr);
			str = iaru_s_prec[nbr];
			if (str.find("EMERGENCY") == string::npos)
				str = str[0];
			replacestr( form, iaru_fields[i].f_type, str);
		} else {
			str = iaru_fields[i].f_data;
			strip_lfs(str);
			replacestr( form, iaru_fields[i].f_type, str);
		}
	}

	FILE *iaru_file = fopen(iaru_name.c_str(), "w");
	fprintf(iaru_file,"%s", form.c_str());
	fclose(iaru_file);
	open_url(iaru_name.c_str());
}

