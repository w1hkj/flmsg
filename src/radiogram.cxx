// =====================================================================
//
// radiogram.cxx
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

string rg_base_filename = "";
string def_rgFileName = "";

// Radiogram rg_fields

const char *s_prec[] = {
"ROUTINE", "WELFARE", "PRIORITY", "EMERGENCY",
"TEST ROUTINE", "TEST WELFARE", "TEST PRIORITY", "TEST EMERGENCY"};
const char precitems[] = 
"ROUTINE|WELFARE|PRIORITY|EMERGENCY|\
TEST ROUTINE|TEST WELFARE|TEST PRIORITY|TEST EMERGENCY";

const char *s_hx[] = {"", "HXA", "HXB", "HXC", "HXD", "HXE", "HXF", "HXG"};
const char hxitems[] = " |HXA|HXB|HXC|HXD|HXE|HXF|HXG";

const char * _rg_nbr		= "<nbr:";		// 0.
const char * _rg_prec		= "<prec:";		// 1.
const char * _rg_hx			= "<hx:";		// 2.
const char * _rg_d1			= "<d1:";		// 3.
const char * _rg_t1			= "<t1:";		// 4.
const char * _rg_dt2		= "<dt2:";		// 5.
const char * _rg_dt3		= "<dt3:";		// 6.
const char * _rg_to			= "<to:";		// 7.
const char * _rg_phone		= "<tel:";		// 8.
const char * _rg_opnote		= "<opn:";		// 9
const char * _rg_msg		= "<msg:";		// 10.
const char * _rg_sig		= "<sig:";		// 11.
const char * _rg_opnote2	= "<op2:";		// 12
const char * _rg_check		= "<ck:";		// 13.
const char * _rg_station	= "<sta:";		// 14.
const char * _rg_place		= "<org:";		// 15
const char * _rg_orig		= "<ori:";		// 16
const char * _rg_dlvd_to	= "<dlv:";		// 17
const char * _rg_sent_to	= "<sto:";		// 18
const char * _rg_snt_net	= "<snt:";		// 19
const char * _rg_dt4		= "<dt4:";		// 20
const char * _rg_rcv_fm		= "<rfm:";		// 21
const char * _rg_rcv_net	= "<rnt:";		// 22
const char * _rg_dt5		= "<dt5:";		// 23
const char * _rg_svc		= "<svc:";		// 24

FIELD rg_fields[] = {
{ _rg_nbr,		"", (Fl_Widget **)&txt_rg_nbr,		't' },	// 0
{ _rg_prec,		"", (Fl_Widget **)&sel_rg_prec,		's' },	// 1
{ _rg_hx,		"", (Fl_Widget **)&txt_rg_hx,		't' },	// 2
{ _rg_d1,		"", (Fl_Widget **)&txt_rg_d1,		't' },	// 3
{ _rg_t1,		"", (Fl_Widget **)&txt_rg_t1,		't' },	// 4
{ _rg_dt2,		"", (Fl_Widget **)&txt_rg_dt2,		't' },	// 5
{ _rg_dt3,		"", (Fl_Widget **)&txt_rg_dt3,		't' },	// 6
{ _rg_to,		"", (Fl_Widget **)&txt_rg_to,		't' },	// 7
{ _rg_phone,	"", (Fl_Widget **)&txt_rg_phone,	't' },	// 8
{ _rg_opnote,	"", (Fl_Widget **)&txt_rg_opnote,	't' },	// 9
{ _rg_msg,		"", (Fl_Widget **)&txt_rg_msg,		'e' },	// 10
{ _rg_sig,		"",	(Fl_Widget **)&txt_rg_sig,		't' },	// 11
{ _rg_opnote2,	"",	(Fl_Widget **)&txt_rg_opnote2,	't' },	// 12
{ _rg_check,	"", (Fl_Widget **)&txt_rg_check,	't' },	// 13
{ _rg_station,	"", (Fl_Widget **)&txt_rg_station,	't' },	// 14
{ _rg_place,	"", (Fl_Widget **)&txt_rg_place,	't' },	// 15
{ _rg_orig,		"", (Fl_Widget **)&txt_rg_orig,		't' },	// 16
{ _rg_dlvd_to,	"", (Fl_Widget **)&txt_rg_dlvd_to,	't' },	// 17
{ _rg_sent_to,	"",	(Fl_Widget **)&txt_rg_sent_to,	't' },	// 18
{ _rg_snt_net,	"",	(Fl_Widget **)&txt_rg_snt_net,	't' },	// 19
{ _rg_dt4,		"", (Fl_Widget **)&txt_rg_dt4,		't' },	// 20
{ _rg_rcv_fm,	"",	(Fl_Widget **)&txt_rg_rcv_fm,	't' },	// 21
{ _rg_rcv_net,	"",	(Fl_Widget **)&txt_rg_rcv_net,	't' },	// 22
{ _rg_dt5,		"", (Fl_Widget **)&txt_rg_dt5,		't' },	// 23
{ _rg_svc,		"",	(Fl_Widget **)&btn_rg_svc,		'b' }	// 24
};

int num_rg_fields = sizeof(rg_fields) / sizeof(FIELD);

int fld_nbr(const char *fld)
{
	for (int i = 0; i < num_rg_fields; i++)
		if (strcmp(rg_fields[i].f_type, fld) == 0)
			return i;
	printf("err %s\n", fld);
	exit(1);
}

//======================================================================

void cb_rgSetDate1()
{
	txt_rg_d1->value(szAbbrevDate());
}

void cb_rgSetTime1()
{
	txt_rg_t1->value(szTime(progStatus.UTC));
}

void cb_rgSetDateTime2()
{
	txt_rg_dt2->value(szDateTime());
}

void cb_rgSetDateTime3()
{
	txt_rg_dt3->value(szDateTime());
}

void cb_rgSetDateTime4()
{
	txt_rg_dt4->value(szDateTime());
}

void cb_rgSetDateTime5()
{
	txt_rg_dt5->value(szDateTime());
}

void cb_rg_nbr(Fl_Widget *wdg)
{
	Fl_Input2 *inp = (Fl_Input2 *)wdg;
	string s = inp->value();
	for (size_t n = 0; n < s.length(); n++)
		if (!isdigit(s[n])) s.erase(n,1);
	strip_leading_zeros(s);
	inp->value(s.c_str());
}

static char valid_input[] = "0123456789/ ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

void cb_rg_filter_input(Fl_Widget *wdg)
{
	Fl_Input2 *inp = (Fl_Input2 *)wdg;
	string s = inp->value();
	ucase(s);
	for (size_t n = 0; n < s.length(); n++)
		if (strchr(valid_input, s[n]) == NULL)
			s.erase(n,1);
	inp->value(s.c_str());
}

void clear_rg_fields()
{
	for (int i = 0; i < num_rg_fields; i++)
		rg_fields[i].f_data.clear();
}

string numeric(int n)
{
	static char snum[10];
	snprintf(snum, sizeof(snum), "%d", n);
	return snum;
}

void update_rg_fields()
{
	for (int i = 0; i < num_rg_fields; i++) {
		if (rg_fields[i].w_type == 'd')
			rg_fields[i].f_data = ((Fl_DateInput *)(*rg_fields[i].w))->value();
		else if (rg_fields[i].w_type == 't')
			rg_fields[i].f_data = ((Fl_Input2 *)(*rg_fields[i].w))->value();
		else if (rg_fields[i].w_type == 's')
			rg_fields[i].f_data = numeric(((Fl_Choice *)(*rg_fields[i].w))->value());
		else if (rg_fields[i].w_type == 'e')
			rg_fields[i].f_data = ((FTextEdit *)(*rg_fields[i].w))->buffer()->text();
		else if (rg_fields[i].w_type == 'b')
			rg_fields[i].f_data = ((Fl_Button *)(*rg_fields[i].w))->value() ? "T" : "F";
	}
}

void set_rg_choices() {
	sel_rg_prec->clear();
	sel_rg_prec->add(precitems);
	sel_rg_prec->value(0);
}

void clear_rg_form()
{
	clear_rg_fields();

	for (int i = 0; i < num_rg_fields; i++)
		if (rg_fields[i].w_type == 'd')
			((Fl_DateInput *)(*rg_fields[i].w))->value("");
		else if (rg_fields[i].w_type == 't')
			((Fl_Input2 *)(*rg_fields[i].w))->value("");
		else if (rg_fields[i].w_type == 's')
			((Fl_Choice *)(*rg_fields[i].w))->value(0);
		else if (rg_fields[i].w_type == 'e')
			((FTextEdit *)(*rg_fields[i].w))->clear();
		else if (rg_fields[i].w_type == 'b')
			((Fl_Button *)(*rg_fields[i].w))->value(0);
	update_rg_fields();
}

void make_rg_buffer()
{
	char sznum[80];
	update_rg_fields();
	buffer.clear();
	buffer.append("<flmsg>");
	buffer.append(PACKAGE_VERSION);
	buffer += '\n';
	buffer.append("<radiogram>\n");
	for (int i = 0; i < num_rg_fields; i++) {
		snprintf(sznum, sizeof(sznum), "%0d", (int)strlen(rg_fields[i].f_data.c_str()));
		buffer.append(rg_fields[i].f_type);
		buffer.append(sznum);
		buffer += ' ';
		buffer.append(rg_fields[i].f_data);
		buffer += '\n';
	}
}

void read_rg_buffer(string data)
{
	const char *buff, *p1, *p2, *buffend;
	size_t pos = 0;

	while ((pos = data.find('\r', pos)) != string::npos) data.erase(pos, 1);
	p1 = buff = data.c_str();
	buffend = p1 + data.length();
	clear_rg_fields();

// search the file buffer for each of the ics rg_fields
	for (int i = 0; i < num_rg_fields; i++) {
		p1 = strstr(buff, rg_fields[i].f_type);
		if (p1) {
			int nchars;
			p2 = p1 + strlen(rg_fields[i].f_type);
			sscanf(p2, "%d", &nchars);
			if (nchars) {
				p2 = strchr(p2, ' ') + 1;
				if (p2 < buffend && p2 + nchars < buffend)
					for ( int ch = 0; ch < nchars; ch++, p2++)
						rg_fields[i].f_data += *p2;
				if (rg_fields[i].w_type == 'd')
					((Fl_DateInput *)(*rg_fields[i].w))->value(rg_fields[i].f_data.c_str());
				else if (rg_fields[i].w_type == 't')
					((Fl_Input2 *)(*rg_fields[i].w))->value(rg_fields[i].f_data.c_str());
				else if (rg_fields[i].w_type == 's') {
					int n;
					sscanf(rg_fields[i].f_data.c_str(),"%d", &n);
					((Fl_Choice *)(*rg_fields[i].w))->value(n);
				}
				else if (rg_fields[i].w_type == 'e') {
					((FTextEdit *)(*rg_fields[i].w))->clear();
					((FTextEdit *)(*rg_fields[i].w))->addstr(rg_fields[i].f_data.c_str());
				}
				else if (rg_fields[i].w_type == 'b') {
					((Fl_Button *)(*rg_fields[i].w))->value(
						rg_fields[i].f_data == "T" ? 1 : 0);
				}
			}
		}
	}
}

void cb_rg_new()
{
	clear_rg_form();
	def_rgFileName = ICS_msg_dir;
	def_rgFileName.append("new"RGFILE_EXT);
	show_filename(def_rgFileName);
}

void cb_rg_import()
{
	string def_rgFileName = ICS_dir;
	def_rgFileName.append("DEFAULT.XML");
	const char *p = FSEL::select(
		"Open Qforms xml file",
		"Qforms xml\t*.{xml,XML}",
		def_rgFileName.c_str());
	if (p){
		clear_rg_form();
		qform_rg_import(p);
	}
}

void cb_rg_export()
{
	string def_rgFileName = ICS_dir;
	def_rgFileName.append(rg_base_filename);
	def_rgFileName.append(".XML");
	const char *p = FSEL::saveas(
			"Open Qforms xml file",
			"Qforms xml\t*.{xml,XML}",
			def_rgFileName.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_rgFileName = p;
		if (strlen(pext) == 0) def_rgFileName.append(".XML");
		qform_rg_export(def_rgFileName);
	}
}

void cb_rg_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_rg_form();
	read_rg_buffer(inpbuffer);
	def_rgFileName = ICS_msg_dir;
	def_rgFileName.append(wrapfilename);
	show_filename(def_rgFileName);
}

void cb_rg_wrap_export()
{
	if (rg_base_filename == "new"RGFILE_EXT || rg_base_filename == "default"RGFILE_EXT)
		cb_rg_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(baseFileName);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrapped radiogram file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_rg_buffer();
		export_wrapfile(baseFileName, wrapfilename, buffer, pext != ".wrap");
	}
}

void cb_rg_wrap_autosend()
{
	if (rg_base_filename == "new"RGFILE_EXT || rg_base_filename == "default"RGFILE_EXT)
		cb_rg_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_rg_buffer();
	export_wrapfile(baseFileName, wrapfilename, buffer, false);
}

void cb_rg_open()
{
	const char *p = FSEL::select(_("Open data file"), "M2S\t*"RGFILE_EXT,
					def_rgFileName.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_ics_form();
	read_data_file(p);
	usingTemplate = false;
	def_rgFileName = p;
	show_filename(def_rgFileName);
}

void write_rg(string s)
{
	FILE *icsfile = fopen(s.c_str(), "w");
	if (!icsfile) return;
	make_rg_buffer();
	fwrite(buffer.c_str(), buffer.length(), 1, icsfile);
	fclose(icsfile);
}

void cb_rg_save_as()
{
	const char *p;
	string newfilename;
	string name = named_file();

	if (!name.empty()) {
		name.append(RGFILE_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_rgFileName;

	p = FSEL::saveas(_("Save data file"), "M2S\t*"RGFILE_EXT,
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
	def_rgFileName = p;
	if (strlen(pext) == 0) def_rgFileName.append(RGFILE_EXT);

	remove_spaces_from_filename(def_rgFileName);
	write_rg(def_rgFileName);
	show_filename(def_rgFileName);
}

void cb_rg_save()
{
	if (rg_base_filename == "new"RGFILE_EXT || rg_base_filename == "default"RGFILE_EXT) {
		cb_rg_save_as();
		return;
	}
	write_rg(def_rgFileName);
}

const char *punctuation[] = {
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

void cb_rg_check()
{
	string temp = txt_rg_msg->buffer()->text();
	if (temp.empty()) {
		txt_rg_check->value("");
		btn_rg_check->labelcolor(FL_BLACK);
		btn_rg_check->redraw_label();
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
	for (int n = 0; punctuation[n]; n += 2)
		while ((pos = temp.find(punctuation[n])) != string::npos)
			temp.replace(pos,1,punctuation[n+1]);
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

	// count number of words in text
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
	txt_rg_msg->clear();
	txt_rg_msg->addstr(temp.c_str());

	char snum[10];
	snprintf(snum, sizeof(snum), "%s%d", 
		temp.find("ARL") != string::npos ? "ARL " : "",
		numwords);
	txt_rg_check->value(snum);
	update_rg_fields();
	btn_rg_check->labelcolor(FL_BLACK);
	btn_rg_check->redraw_label();
}

void cb_rg_html()
{
	string rgname;
	string MSG;
	string html_text;
	int nbr;
	rgname = ICS_dir;
	rgname.append("radiogram.html");

	update_rg_fields();
	cb_rg_check();
	string form = rg_html_template;

	size_t pos;
	for (int i = 0; i < num_rg_fields; i++) {
		if (rg_fields[i].w_type == 'e' || rg_fields[i].w_type == 't') {
			MSG = rg_fields[i].f_data;
			size_t pos2 = MSG.find('\n');
			while (pos2 != string::npos) {
				MSG.replace(pos2, 1, "<br>");
				pos2 = MSG.find( '\n', pos2 );
			}
			if (strcmp(rg_fields[i].f_type ,"<msg:") == 0) MSG.append("<br>");
			to_html(MSG);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), MSG );
		} else if (strcmp(rg_fields[i].f_type, "<prec:") == 0) {
			sscanf(rg_fields[i].f_data.c_str(), "%d", &nbr);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), s_prec[nbr] );
		} else {
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos) {
				html_text = rg_fields[i].f_data;
				to_html(html_text);
				form.replace( pos, strlen(rg_fields[i].f_type), html_text );
			}
		}
	}

	string rxstr = "";
	rxstr.append(progStatus.my_call).append(" ").append(progStatus.my_tel);
	rxstr.append("<br>").append(progStatus.my_name);
	rxstr.append("<br>").append(progStatus.my_addr);
	rxstr.append("<br>").append(progStatus.my_city);

	if ((pos = form.find("<rx:")) != string::npos)
		form.replace( pos, 4, rxstr);

	FILE *rgfile = fopen(rgname.c_str(), "w");
	fprintf(rgfile,"%s", form.c_str());
	fclose(rgfile);

	open_url(rgname.c_str());
}

void cb_rg_html_fcopy()
{
	string rgname;
	string MSG = "";
	string html_text;
	int nbr;
	rgname = ICS_dir;
	rgname.append("rg_file_copy.html");

	update_rg_fields();
	cb_rg_check();
	string form = rg_html_fcopy_template;

	size_t pos;
	for (int i = 0; i < num_rg_fields; i++) {
		if (rg_fields[i].w_type == 'e' || rg_fields[i].w_type == 't') {
			MSG = rg_fields[i].f_data;
			size_t pos2 = MSG.find('\n');
			while (pos2 != string::npos) {
				MSG.replace(pos2, 1, "<br>");
				pos2 = MSG.find( '\n', pos2 );
			}
			if (strcmp(rg_fields[i].f_type ,"<msg:") == 0) MSG.append("<br>");
			to_html(MSG);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), MSG );
		} else if (strcmp(rg_fields[i].f_type, "<prec:") == 0) {
			sscanf(rg_fields[i].f_data.c_str(), "%d", &nbr);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), s_prec[nbr] );
		} else {
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos) {
				html_text = rg_fields[i].f_data;
				to_html(html_text);
				form.replace( pos, strlen(rg_fields[i].f_type), html_text );
			}
		}
	}

	string rxstr = "";
	rxstr.append(progStatus.my_call).append(" ").append(progStatus.my_tel);
	rxstr.append("<br>").append(progStatus.my_name);
	rxstr.append("<br>").append(progStatus.my_addr);
	rxstr.append("<br>").append(progStatus.my_city);

	if ((pos = form.find("<rx:")) != string::npos)
		form.replace( pos, 4, rxstr);

	FILE *rgfile = fopen(rgname.c_str(), "w");
	fprintf(rgfile,"%s", form.c_str());
	fclose(rgfile);

	open_url(rgname.c_str());
}

void cb_rg_rtf()
{
	string rgname;
	int nbr;
	rgname = ICS_dir;
	rgname.append("radiogram.rtf");

	update_rg_fields();
	cb_rg_check();
	string form = rg_rtf_template;

	int nlines = 0;
	size_t pos;
	for (int i = 0; i < num_rg_fields; i++) {
		if (rg_fields[i].w_type == 'e' || rg_fields[i].w_type == 't') {
			nlines = 0;
			string MSG = rg_fields[i].f_data;
			size_t pos2 = MSG.find('\n');
			while (pos2 != string::npos) {
				MSG.replace(pos2, 1, nuline);
				nlines++;
				pos2 = MSG.find( '\n', pos2 + strlen(nuline) );
			}
			if (strcmp(rg_fields[i].f_type ,"<msg:") == 0)
				for (int k = nlines; k < 10; k++) MSG.append("\n");//nuline);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), MSG );
		} else if (strcmp(rg_fields[i].f_type, "<prec:") == 0) {
			sscanf(rg_fields[i].f_data.c_str(), "%d", &nbr);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), s_prec[nbr] );
		} else {
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace(	pos, strlen(rg_fields[i].f_type),
								rg_fields[i].f_data );
		}
	}
	string rxstr = "";
	rxstr.append(progStatus.my_call).append(" ").append(progStatus.my_tel);
	rxstr.append(nuline).append(progStatus.my_name);
	rxstr.append(nuline).append(progStatus.my_addr);
	rxstr.append(nuline).append(progStatus.my_city);

	if ((pos = form.find("<rx:")) != string::npos)
		form.replace( pos, 4, rxstr);

	FILE *rgfile = fopen(rgname.c_str(), "w");
	fprintf(rgfile,"%s", form.c_str());
	fclose(rgfile);

	open_url(rgname.c_str());
}

void cb_rg_textout()
{
	string rgname;
	string lines;
	string str;
	int nbr = 0;//, fn;
	rgname = ICS_dir;
	rgname.append("radiogram.txt");

	update_rg_fields();
	cb_rg_check();

	string form = rg_txt_template;

//	int nlines = 0;
	size_t pos;
	for (int i = 0; i < num_rg_fields; i++) {
		str.clear();
		if (rg_fields[i].w_type == 'e' || rg_fields[i].w_type == 't') {
			if ((strcmp(rg_fields[i].f_type, _rg_opnote) == 0) ||
			    (strcmp(rg_fields[i].f_type, _rg_opnote2) == 0)) {
			    if (!rg_fields[i].f_data.empty())
					str.append(" OPNOTE ").append(rg_fields[i].f_data);
			    if ((pos=form.find(rg_fields[i].f_type)) != string::npos)
			      form.replace(pos, strlen(rg_fields[i].f_type), str);
			} else if (strcmp(rg_fields[i].f_type, _rg_hx) == 0 &&
					!rg_fields[i].f_data.empty()) {
				str = " ";
				str.append(rg_fields[i].f_data);
			} else {
				str = rg_fields[i].f_data;
				strip_lfs(str);
			}
		} else if (strcmp(rg_fields[i].f_type, "<prec:") == 0) {
			sscanf(rg_fields[i].f_data.c_str(), "%d", &nbr);
			str = s_prec[nbr];
			if (str.find("TEST") != string::npos) {				// test message
				if (str.find("EMERGENCY") == string::npos)
					str = str.substr(0, 6);
			} else {
				if (str.find("EMERGENCY") == string::npos)
					str = str[0];
			}
		} else {
			str = rg_fields[i].f_data;
			strip_spaces(str);
		}
		if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
			form.replace( pos, strlen(rg_fields[i].f_type), str);
	}
	FILE *rgfile = fopen(rgname.c_str(), "w");
	fprintf(rgfile,"%s", form.c_str());
	fclose(rgfile);
	open_url(rgname.c_str());
}
