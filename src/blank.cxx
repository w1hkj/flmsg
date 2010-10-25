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

const char * blank_msg = "<mg:";

string blankbuffer;
string def_blank_filename = "";
string base_blank_filename = "";
string def_blank_TemplateName = "";

FIELD blankfields[] = {
{ blank_msg,	"", (Fl_Widget **)&txt_blank_msg,		'e' } };

bool using_blank_template = false;

int num_blankfields = sizeof(blankfields) / sizeof(FIELD);

void clear_blankfields()
{
	for (int i = 0; i < num_blankfields; i++)
		blankfields[i].f_data.clear();
}

void update_blankfields()
{
	for (int i = 0; i < num_blankfields; i++) {
		if (blankfields[i].w_type == 'd')
			blankfields[i].f_data = ((Fl_DateInput *)(*blankfields[i].w))->value();
		else if (blankfields[i].w_type == 't')
			blankfields[i].f_data = ((Fl_Input2 *)(*blankfields[i].w))->value();
		else if (blankfields[i].f_type == blank_msg) {
			char *txt = txt_blank_msg->buffer()->text();
			blankfields[i].f_data = txt;
			free(txt);
		}
	}
}

void clear_blank_form()
{
	clear_blankfields();
	update_blankfields();
}

void make_blankbuffer()
{
	char sznum[80];
	update_blankfields();
	blankbuffer.clear();
	blankbuffer.append("<flmsg>");
	blankbuffer.append(PACKAGE_VERSION);
	blankbuffer += '\n';
	blankbuffer.append("<blankform>\n");
	for (int i = 0; i < num_blankfields; i++) {
		snprintf(sznum, sizeof(sznum), "%0d", (int)strlen(blankfields[i].f_data.c_str()));
		blankbuffer.append(blankfields[i].f_type);
		blankbuffer.append(sznum);
		blankbuffer += ' ';
		blankbuffer.append(blankfields[i].f_data);
		blankbuffer += '\n';
	}
}

void read_blankbuffer(string data)
{
	const char *buff, *p1, *p2, *buffend;
	size_t pos = 0;

	while ((pos = data.find('\r', pos)) != string::npos) data.erase(pos, 1);
	p1 = buff = data.c_str();
	buffend = p1 + data.length();
	clear_blankfields();

// search the file buffer for each of the ics fields
	for (int i = 0; i < num_blankfields; i++) {
		p1 = strstr(buff, blankfields[i].f_type);
		if (p1) {
			int nchars;
			p2 = p1 + strlen(blankfields[i].f_type);
			sscanf(p2, "%d", &nchars);
			if (nchars) {
				p2 = strchr(p2, ' ') + 1;
				if (p2 < buffend && p2 + nchars < buffend) {
					blankfields[i].f_data.clear();
					for ( int ch = 0; ch < nchars; ch++, p2++)
						blankfields[i].f_data += *p2;
				}
				if (blankfields[i].w_type == 'd')
					((Fl_DateInput *)(*blankfields[i].w))->value(blankfields[i].f_data.c_str());
				else if (blankfields[i].w_type == 't')
					((Fl_Input2 *)(*blankfields[i].w))->value(blankfields[i].f_data.c_str());
				else if (blankfields[i].f_type == blank_msg) {
					txt_blank_msg->clear();
					txt_blank_msg->addstr(blankfields[i].f_data.c_str());
				}
			}
		}
	}
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
/*
	string def_blank_filename = ICS_dir;
	def_blank_filename.append("DEFAULT.XML");
	const char *p = FSEL::select(
		"Open Qblankforms xml file",
		"Qblankforms xml\t*.{xml,XML}",
		def_blank_filename.c_str());
	if (p){
		clear_blank_blankform();
		qform_blank_import(p);
	}
*/
}

void cb_blank_export()
{
	fl_alert2("Not implemented");
/*
	string def_blank_filename = ICS_dir;
	def_blank_filename.append(base_blank_filename);
	def_blank_filename.append(".XML");
	const char *p = FSEL::saveas(
			"Open Qblankforms xml file",
			"Qblankforms xml\t*.{xml,XML}",
			def_blank_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_blank_filename = p;
		if (strlen(pext) == 0) def_blank_filename.append(".XML");
		qform_blank_export(def_blank_filename);
	}
*/
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

void cb_blank_html()
{
	string blank_name = ICS_dir;
	string html_text = "";
	blank_name.append("blankform_doc.html");

	update_blankfields();
	string blankform = blank_html_template;

	string blank_msgtxt = blankfields[num_blankfields-1].f_data;

	int nlines = 0;
	size_t pos = blank_msgtxt.find('\n');
	while (pos != string::npos) {
		blank_msgtxt.replace(pos, 1, "<br>");
		nlines++;
		pos = blank_msgtxt.find( '\n', pos );
	}
	for (int i = nlines; i < 20; i++) blank_msgtxt.append("<br>");
	to_html(blank_msgtxt);

	for (int i = 0; i < num_blankfields - 1; i++) {
		pos = blankform.find(blankfields[i].f_type);
		if (pos != string::npos) {
			html_text = blankfields[i].f_data;
			to_html(html_text);
			blankform.replace( pos, strlen(blankfields[i].f_type), html_text);
		}
	}
	pos = blankform.find(blankfields[num_blankfields-1].f_type);
	if (pos)
		blankform.replace(	pos,
						strlen(blankfields[num_blankfields-1].f_type),
						blank_msgtxt);

	FILE *blankfile = fopen(blank_name.c_str(), "w");
	fprintf(blankfile,"%s", blankform.c_str());
	fclose(blankfile);

	open_url(blank_name.c_str());
}

void cb_blank_msg_type()
{
	if (tabs_msg_type->value() == tab_blank ) {
		show_filename(def_blank_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_blank_textout()
{
	string blank_name = ICS_dir;
	blank_name.append("blankform.txt");

	update_blankfields();
	string blankform = blank_txt_template;

	size_t pos;
	for (int i = 0; i < num_blankfields; i++) {
		pos = blankform.find(blankfields[i].f_type);
		if (pos != string::npos)
			blankform.replace(	pos,
							strlen(blankfields[i].f_type),
							blankfields[i].f_data );
	}
	FILE *blankfile = fopen(blank_name.c_str(), "w");
	fprintf(blankfile,"%s", blankform.c_str());
	fclose(blankfile);

	open_url(blank_name.c_str());
}
