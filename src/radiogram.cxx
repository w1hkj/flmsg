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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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

const char * _rg_nbr = "<nbr:";
const char * _rg_prec = "<prec:";
const char * _rg_hx = "<hx:";
const char * _rg_d1 = "<d1:";
const char * _rg_t1 = "<t1:";
const char * _rg_dt2 = "<dt2:";
const char * _rg_dt3 = "<dt3:";
const char * _rg_to = "<to:";
const char * _rg_rx = "<rx:";
const char * _rg_phone = "<tel:";
const char * _rg_opnote = "<opn:";
const char * _rg_msg = "<msg:";
const char * _rg_check = "<ck:";
const char * _rg_station = "<sta:";
const char * _rg_place = "<org:";
const char * _rg_signed = "<sgn:";
const char * _rg_sent_to = "<sto:";

const char *s_prec[] = {
"ROUTINE", "WELFARE", "PRIORITY", "EMERGENCY",
"TEST ROUTINE", "TEST WELFARE", "TEST PRIORITY", "TEST EMERGENCY"};
const char precitems[] = 
"ROUTINE|WELFARE|PRIORITY|EMERGENCY|\
TEST ROUTINE|TEST WELFARE|TEST PRIORITY|TEST EMERGENCY";

const char *s_hx[] = {"", "HXA", "HXB", "HXC", "HXD", "HXE", "HXF", "HXG"};
const char hxitems[] = " |HXA|HXB|HXC|HXD|HXE|HXF|HXG";

FIELD rg_fields[] = {
{ _rg_nbr,	"", (Fl_Widget **)&txt_rg_nbr,	't' },			// 0
{ _rg_prec,	"", (Fl_Widget **)&sel_rg_prec,  's' },			// 1
{ _rg_hx,	"", (Fl_Widget **)&txt_rg_hx,  't' },			// 2
{ _rg_d1,	"", (Fl_Widget **)&txt_rg_d1,	't' },			// 3
{ _rg_t1,	"", (Fl_Widget **)&txt_rg_t1,	't' },			// 4
{ _rg_dt2,	"", (Fl_Widget **)&txt_rg_dt2,	't' },			// 5
{ _rg_dt3,	"", (Fl_Widget **)&txt_rg_dt3,	't' },			// 6
{ _rg_to,	"", (Fl_Widget **)&txt_rg_to,	't' },			// 7
{ _rg_rx,	"", (Fl_Widget **)&txt_rg_rx,	't' },			// 8
{ _rg_phone,	"", (Fl_Widget **)&txt_rg_phone,	't' },	// 9
{ _rg_msg,   "", (Fl_Widget **)&txt_rg_msg,   'e' },		// 10
{ _rg_station,	"", (Fl_Widget **)&txt_rg_station,	't' },	// 11
{ _rg_place,	"", (Fl_Widget **)&txt_rg_place,	't' },	// 12
{ _rg_signed,	"", (Fl_Widget **)&txt_rg_signed,	't' },	// 13
{ _rg_sent_to,	"", (Fl_Widget **)&txt_rg_sent_to,	't' },	// 14
{ _rg_check,	"", (Fl_Widget **)&txt_rg_check,	't' },	// 15
{ _rg_opnote,	"", (Fl_Widget **)&txt_rg_opnote,		't' } };// 16

int num_rg_fields = sizeof(rg_fields) / sizeof(FIELD);

//======================================================================

void ucase(string &s)
{
	for (size_t n = 0; n < s.length(); n++) s[n] = toupper(s[n]);
}

//======================================================================

void cb_rgSetDate1()
{
	txt_rg_d1->value(szAbbrevDate());
}

void cb_rgSetDateTime2()
{
	txt_rg_dt2->value(szDateTime());
}

void cb_rgSetDateTime3()
{
	txt_rg_dt3->value(szDateTime());
}

void cb_rgSetTime1()
{
	txt_rg_t1->value(szTime(1));
}

void cb_rgSetTime2()
{
//	txt_rg_t2->value(szTime(1));
}

void cb_rgSetTime3()
{
//	txt_rg_t3->value(szTime(1));
}

void clear_rg_fields()
{
	for (int i = 0; i < num_rg_fields; i++)
		rg_fields[i].f_data.clear();
}

void cb_rg_hx()
{
	fl_alert2("to be developed");
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
		else if (rg_fields[i].w_type == 'e') {
			rg_fields[i].f_data = ((FTextEdit *)(*rg_fields[i].w))->buffer()->text();
		}
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

void cb_rg_wrap_import()
{
	string wrapfilename = WRAP_recv_dir;
	string inpbuffer;
	bool isok;
	wrapfilename.append("default.wrap");
	const char *p = FSEL::select(
		"Import wrapped radiogram file",
		"Wrap file\t*.{wrap,WRAP}",
		wrapfilename.c_str());
	if (p){
		clear_rg_form();
		isok = import_wrapfile(p, wrapfilename, inpbuffer);
		read_rg_buffer(inpbuffer);
		def_rgFileName = ICS_msg_dir;
		def_rgFileName.append(wrapfilename);
		show_filename(def_rgFileName);
	}
}

void cb_rg_wrap_export()
{
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
	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_rg_buffer();
	export_wrapfile(baseFileName, wrapfilename, buffer, false);
}

void read_rg(string s)
{
//	def_rgFileName = s;
	long filesize = 0;
	char *buff, *buffend;
	int retval;
	FILE *icsfile;

	icsfile = fopen (s.c_str(), "r");
	if (!icsfile)
		return;
// determine its size for buffer creation
	fseek (icsfile, 0, SEEK_END);
	filesize = ftell (icsfile);
	buff = new char[filesize + 1];
// read the entire file into the buffer
	fseek (icsfile, 0, SEEK_SET);
	retval = fread (buff, filesize, 1, icsfile);
	fclose (icsfile);
	buffend = buff + filesize;

// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
		return;
	}

	if (strstr(buff, "<flmsg") != buff) {
		fl_alert2(_("Not an flmsg data file"));
		return;
	}
	read_rg_buffer(buff);
	delete [] buff;

}

void cb_rg_open()
{
	const char *p = FSEL::select(_("Open data file"), "M2S\t*"RGFILE_EXT,
					def_rgFileName.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_ics_form();
	read_rg(p);
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
	newfilename = def_rgFileName;

	p = FSEL::saveas(_("Save data file"), "M2S\t*"RGFILE_EXT,
					newfilename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;

	const char *pext = fl_filename_ext(p);
	def_rgFileName = p;
	if (strlen(pext) == 0) def_rgFileName.append(".m2s");
	remove_spaces_from_filename(def_rgFileName);
	write_rg(def_rgFileName);
	show_filename(def_rgFileName);
}

void cb_rg_save()
{
	if (rg_base_filename == "new"RGFILE_EXT || rg_base_filename == "default"RGFILE_EXT) {
		cb_save_as();
		return;
	}
	write_rg(def_rgFileName);
}

const char *punctuation[] = {
". ", " X ",
",", " COMMA ",
"?", " QUERY ",
"\\", " BACKSLASH ",
"/ ", " SLASH ",
"~", " TILDE ",
"_", " UNDERSCORE ",
"@", " AT ",
"#", " POUNDSIGN ",
"\"", " QUOTE ",
"\'", "",
 0, 0 };

void cb_rg_check()
{
	update_rg_fields();

	string temp = txt_rg_msg->buffer()->text();
	if (temp.empty()) {
		txt_rg_check->value("");
		return;
	}

	// convert to uppercase
	for (size_t n = 0; n < temp.length(); n++)
		temp[n] = toupper(temp[n]);

	size_t pos = string::npos;
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
}

void cb_rg_html()
{
	string rgname;
	int nbr;
	rgname = ICS_dir;
	rgname.append("radiogram.html");

	cb_rg_check();
	string form = rg_html_template;

	int nlines = 0;
	size_t pos;
	for (int i = 0; i < num_rg_fields; i++) {
		if (rg_fields[i].w_type == 'e' || rg_fields[i].w_type == 't') {
			nlines = 0;
			string MSG = rg_fields[i].f_data;
			size_t pos2 = MSG.find('\n');
			while (pos2 != string::npos) {
				MSG.replace(pos2, 1, "<br>");
				nlines++;
				pos2 = MSG.find( '\n', pos2 );
			}
			if (strcmp(rg_fields[i].f_type ,"<msg:") == 0)
				for (int k = nlines; k < 10; k++) MSG.append("<br>");
			to_html(MSG);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), MSG );
		} else if (strcmp(rg_fields[i].f_type, "<prec:") == 0) {
			sscanf(rg_fields[i].f_data.c_str(), "%d", &nbr);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), s_prec[nbr] );
		} else if (strcmp(rg_fields[i].f_type, "<hx:") == 0) {
			sscanf(rg_fields[i].f_data.c_str(), "%d", &nbr);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), s_hx[nbr] );
		} else {
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace(	pos, strlen(rg_fields[i].f_type),
								rg_fields[i].f_data );
		}
	}

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
		} else if (strcmp(rg_fields[i].f_type, "<hx:") == 0) {
			sscanf(rg_fields[i].f_data.c_str(), "%d", &nbr);
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace( pos, strlen(rg_fields[i].f_type), s_hx[nbr] );
		} else {
			if ((pos = form.find(rg_fields[i].f_type)) != string::npos)
				form.replace(	pos, strlen(rg_fields[i].f_type),
								rg_fields[i].f_data );
		}
	}

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
	int nbr;
	rgname = ICS_dir;
	rgname.append("radiogram.txt");

	cb_rg_check();

// first line
	lines = rg_fields[0].f_data; // message number
	lines += ' ';
	sscanf(rg_fields[1].f_data.c_str(), "%d", &nbr);
	str = s_prec[nbr];
	if (str.find("TEST") != string::npos) { // test message
		if (str.find("EMERGENCY") != string::npos)
			lines.append(str);
		else
			lines.append(str.substr(0, 6));
	} else {
		if (str.find("EMERGENCY") != string::npos)
			lines.append(str);
		else
			lines += str[0];
	}

	// HX
	if (!rg_fields[2].f_data.empty()) lines.append(" ").append(rg_fields[2].f_data);

	lines.append(" ").append(rg_fields[11].f_data); // station
	lines.append(" ").append(rg_fields[15].f_data); // check
	lines.append(" ").append(rg_fields[4].f_data); // time
	lines.append(" ").append(rg_fields[5].f_data); // date
	lines += '\n';
// addressee
	lines.append(rg_fields[7].f_data);
	if (lines[lines.length()-1] != '\n') lines += '\n';
// telephone
	str = "";
	if (!rg_fields[9].f_data.empty())
		str.append(rg_fields[9].f_data).append(" ");
// opnote
	if (!rg_fields[16].f_data.empty())
		str.append(rg_fields[16].f_data);
	if (!str.empty()) lines.append(str).append("\n");

	lines.append("BT\n");
// body of message
	lines.append(rg_fields[10].f_data);
	if (lines[lines.length()-1] != '\n') lines += '\n';
	lines.append("BT\n");
// signed
	lines.append(rg_fields[13].f_data).append("\nAR\n");

	ucase(lines);

	FILE *rgfile = fopen(rgname.c_str(), "w");
	fprintf(rgfile,"%s", lines.c_str());
	fclose(rgfile);

	open_url(rgname.c_str());
}

