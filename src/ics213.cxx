// =====================================================================
//
// ics213.cxx
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

// ICS213 fields

const char * _to = "<to:";
const char * _fm = "<fm:";
const char * _p1 = "<p1:";
const char * _p2 = "<p2:";
const char * _subj = "<sb:";
const char * _d1 = "<d1:";
const char * _t1 = "<t1:";
const char * _msg = "<mg:";
const char * _s1 = "<s1:";
const char * _p3 = "<p3:";
const char * _reply = "<rp:";
const char * _d2 = "<d2:";
const char * _t2 = "<t2:";
const char * _s2 = "<s2:";
const char * _p4 = "<p4:";

string ICS_msg = "";
string ICS_reply = "";
string buffer;

FIELD fields[] = {
{ _to,	"", (Fl_Widget **)&txt_To,	't' },
{ _p1,	"", (Fl_Widget **)&txt_P1,	't' },
{ _fm,	"", (Fl_Widget **)&txt_Fm,	't' },
{ _p2,	"", (Fl_Widget **)&txt_P2,	't' },
{ _d1,	"", (Fl_Widget **)&txt_D1,	'd' },
{ _t1,	"", (Fl_Widget **)&txt_T1,	't' },
{ _subj,  "", (Fl_Widget **)&txt_Subj,  't' },
{ _s1,	"", (Fl_Widget **)&txt_S1,	't' },
{ _p3,	"", (Fl_Widget **)&txt_P3,	't' },
{ _s2,	"", (Fl_Widget **)&txt_S2,	't' },
{ _p4,	"", (Fl_Widget **)&txt_P4,	't' },
{ _d2,	"", (Fl_Widget **)&txt_D2,	'd' },
{ _t2,	"", (Fl_Widget **)&txt_T2,	't' },
{ _msg,   "", (Fl_Widget **)&txt_Msg,   'e' },
{ _reply, "", (Fl_Widget **)&txt_Reply, 'e' } };

int numfields = sizeof(fields) / sizeof(FIELD);

void cb_SetDate1()
{
	txt_D1->value(szDate());
}

void cb_SetDate2()
{
	txt_D2->value(szDate());
}

void cb_SetTime1()
{
	txt_T1->value(szTime(progStatus.UTC));
}

void cb_SetTime2()
{
	txt_T2->value(szTime(progStatus.UTC));
}

void clear_fields()
{
	for (int i = 0; i < numfields; i++)
		fields[i].f_data.clear();
}

void update_fields()
{
	for (int i = 0; i < numfields; i++) {
		if (fields[i].w_type == 'd')
			fields[i].f_data = ((Fl_DateInput *)(*fields[i].w))->value();
		else if (fields[i].w_type == 't')
			fields[i].f_data = ((Fl_Input2 *)(*fields[i].w))->value();
		else if (fields[i].f_type == _msg) {
			char *txt = txt_Msg->buffer()->text();
			fields[i].f_data = txt;
			free(txt);
		}
		else if (fields[i].f_type == _reply) {
			char *txt = txt_Reply->buffer()->text();
			fields[i].f_data = txt;
			free(txt);
		}
	}
}

void clear_ics_form()
{
	clear_fields();
	txt_To->value("");
	txt_P1->value("");
	txt_Fm->value("");
	txt_P2->value("");
	txt_Subj->value("");
	txt_D1->value("");
	txt_T1->value("");
	txt_Msg->clear();
	txt_S1->value("");
	txt_P3->value("");
	txt_Reply->clear();
	txt_S2->value("");
	txt_D2->value("");
	txt_T2->value("");
	txt_P4->value("");
	update_fields();
}

void make_buffer()
{
	char sznum[80];
	update_fields();
	buffer.clear();
	buffer.append("<flmsg>");
	buffer.append(PACKAGE_VERSION);
	buffer += '\n';
	buffer.append("<ics213>\n");
	for (int i = 0; i < numfields; i++) {
		snprintf(sznum, sizeof(sznum), "%0d", (int)strlen(fields[i].f_data.c_str()));
		buffer.append(fields[i].f_type);
		buffer.append(sznum);
		buffer += ' ';
		buffer.append(fields[i].f_data);
		buffer += '\n';
	}
}

void read_buffer(string data)
{
	const char *buff, *p1, *p2, *buffend;
	size_t pos = 0;

	while ((pos = data.find('\r', pos)) != string::npos) data.erase(pos, 1);
	p1 = buff = data.c_str();
	buffend = p1 + data.length();
	clear_fields();

// search the file buffer for each of the ics fields
	for (int i = 0; i < numfields; i++) {
		p1 = strstr(buff, fields[i].f_type);
		if (p1) {
			int nchars;
			p2 = p1 + strlen(fields[i].f_type);
			sscanf(p2, "%d", &nchars);
			if (nchars) {
				p2 = strchr(p2, ' ') + 1;
				if (p2 < buffend && p2 + nchars < buffend)
					for ( int ch = 0; ch < nchars; ch++, p2++)
						fields[i].f_data += *p2;
				if (fields[i].w_type == 'd')
					((Fl_DateInput *)(*fields[i].w))->value(fields[i].f_data.c_str());
				else if (fields[i].w_type == 't')
					((Fl_Input2 *)(*fields[i].w))->value(fields[i].f_data.c_str());
				else if (fields[i].f_type == _msg) {
					txt_Msg->clear();
					txt_Msg->addstr(fields[i].f_data.c_str());
				} else if (fields[i].f_type == _reply) {
					txt_Reply->clear();
					txt_Reply->addstr(fields[i].f_data.c_str());
				}
			}
		}
	}
}

void cb_ics_new()
{
	clear_ics_form();
	defFileName = ICS_msg_dir;
	defFileName.append("new"DATAFILE_EXT);
	show_filename(defFileName);
}

void cb_ics_import()
{
	string deffilename = ICS_dir;
	deffilename.append("DEFAULT.XML");
	const char *p = FSEL::select(
		"Open Qforms xml file",
		"Qforms xml\t*.{xml,XML}",
		deffilename.c_str());
	if (p){
		clear_ics_form();
		qform_ics_import(p);
	}
}

void cb_ics_export()
{
	string deffilename = ICS_dir;
	deffilename.append(baseFileName);
	deffilename.append(".XML");
	const char *p = FSEL::saveas(
			"Open Qforms xml file",
			"Qforms xml\t*.{xml,XML}",
			deffilename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		deffilename = p;
		if (strlen(pext) == 0) deffilename.append(".XML");
		qform_ics_export(deffilename);
	}
}

void cb_ics_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_ics_form();
	read_buffer(inpbuffer);
	defFileName = ICS_msg_dir;
	defFileName.append(wrapfilename);
	show_filename(defFileName);
}

void cb_ics_wrap_export()
{
	if (baseFileName == "new"DATAFILE_EXT || baseFileName == "default"DATAFILE_EXT)
		cb_ics_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(baseFileName);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		make_buffer();
		export_wrapfile(baseFileName, wrapfilename, buffer, pext != ".wrap");
	}
}

void cb_ics_wrap_autosend()
{
	if (baseFileName == "new"DATAFILE_EXT || baseFileName == "default"DATAFILE_EXT)
		cb_ics_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	make_buffer();
	export_wrapfile(baseFileName, wrapfilename, buffer, false);
}

void cb_ics_load_template()
{
	string deffilename = defTemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*.f2t",
			deffilename.c_str());
	if (p) {
		clear_ics_form();
		read_data_file(p);
		defTemplateName = p;
		show_filename(defTemplateName);
		usingTemplate = true;
	}
}

void cb_ics_save_template()
{
	if (!usingTemplate) {
		cb_save_as_template();
		return;
	}
	string deffilename = defTemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*.f2t",
			deffilename.c_str());
	if (p)
		write_ics(p);
}

void cb_ics_save_as_template()
{
	string deffilename = defTemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*.f2t",
			deffilename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		defTemplateName = p;
		if (strlen(pext) == 0) defTemplateName.append(".f2t");
		remove_spaces_from_filename(defTemplateName);
		write_ics(defTemplateName);
		show_filename(defTemplateName);
		usingTemplate = true;
	}
}

void read_data_file(string s)
{
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
// test file integrity
	if (filesize == 0) {
		fl_alert2(_("Empty file"));
		return;
	}

	buff = new char[filesize + 1];
// read the entire file into the buffer
	fseek (icsfile, 0, SEEK_SET);
	retval = fread (buff, filesize, 1, icsfile);
	fclose (icsfile);
	buffend = buff + filesize;

	if (strstr(buff, "<radiogram>") != 0) {
		read_rg_buffer(buff);
		tabs_msg_type->value(tab_radiogram);
		tabs_msg_type->redraw();
	} else if (strstr(buff, "<ics213>") != 0) {
		read_buffer(buff);
		tabs_msg_type->value(tab_ics213);
		tabs_msg_type->redraw();
	} else
		fl_alert2(_("Not an flmsg data file"));

	delete [] buff;

}

void cb_ics_open()
{
	const char *p = FSEL::select(_("Open data file"), "F2S\t*"DATAFILE_EXT,
					defFileName.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_ics_form();
	read_data_file(p);
//	read_ics(p);
	usingTemplate = false;
	defFileName = p;
	show_filename(defFileName);
}

void write_ics(string s)
{
	FILE *icsfile = fopen(s.c_str(), "w");
	if (!icsfile) return;
	make_buffer();
	fwrite(buffer.c_str(), buffer.length(), 1, icsfile);
	fclose(icsfile);
}

void cb_ics_save_as()
{
	const char *p;
	string newfilename;

	if (usingTemplate) {
		newfilename = ICS_msg_dir;
		newfilename.append(fl_filename_name ( defTemplateName.c_str() ));
		size_t ext = newfilename.find(".f2t");
		if (ext != string::npos) newfilename.erase(ext, 4);
		newfilename.append(DATAFILE_EXT);
	} else {
		newfilename = named_file();
		if (!newfilename.empty())
			newfilename.append(DATAFILE_EXT);
		else
			newfilename = defFileName;
		p = FSEL::saveas(_("Save data file"), "F2S\t*"DATAFILE_EXT,
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
		defFileName = p;
		if (strlen(pext) == 0) defFileName.append(DATAFILE_EXT);
	}
	remove_spaces_from_filename(defFileName);
	write_ics(defFileName);
	show_filename(defFileName);
	usingTemplate = false;
}

void cb_ics_save()
{
	if (baseFileName == "new"DATAFILE_EXT || baseFileName == "default"DATAFILE_EXT) {
		cb_ics_save_as();
		return;
	}
	if (usingTemplate) {
		fl_alert2("Template file, use 'save as'");
		return;
	}
	write_ics(defFileName);
}

void cb_ics_write()
{
	string rtfname = ICS_dir;
	rtfname.append("ics213_doc.rtf");

	update_fields();

	string form = ics_rtf_template;
	FILE *rtf_file = fopen(rtfname.c_str(), "w");

	ICS_msg = fields[numfields-2].f_data;
	ICS_reply = fields[numfields-1].f_data;

	size_t pos = ICS_msg.find('\n');
	while (pos != string::npos) {
		ICS_msg.replace(pos, 1, nuline);
		pos = ICS_msg.find( '\n', pos + strlen(nuline) );
	}
	pos = ICS_reply.find('\n');
	while (pos != string::npos) {
		ICS_reply.replace(pos, 1, nuline);
		pos = ICS_reply.find( '\n', pos + strlen(nuline) );
	}
	for (int i = 0; i < numfields - 2; i++)
		form.replace(	form.find(fields[i].f_type),
						strlen(fields[i].f_type),
						fields[i].f_data );
	form.replace(	form.find(fields[numfields-2].f_type),
					strlen(fields[numfields-2].f_type),
					ICS_msg);
	form.replace(	form.find(fields[numfields-1].f_type),
					strlen(fields[numfields-1].f_type),
					ICS_reply);
	fprintf(rtf_file,"%s", form.c_str());
	fclose(rtf_file);

	open_url(rtfname.c_str());
}

void cb_ics_html()
{
	string icsname = ICS_dir;
	string html_text = "";
	icsname.append("ics213_doc.html");

	update_fields();
	string form = ics_html_template;

	ICS_msg = fields[numfields-2].f_data;
	ICS_reply = fields[numfields-1].f_data;

	int nlines = 0;
	size_t pos = ICS_msg.find('\n');
	while (pos != string::npos) {
		ICS_msg.replace(pos, 1, "<br>");
		nlines++;
		pos = ICS_msg.find( '\n', pos );
	}
	for (int i = nlines; i < 20; i++) ICS_msg.append("<br>");
	to_html(ICS_msg);

	nlines = 0;
	pos = ICS_reply.find('\n');
	while (pos != string::npos) {
		ICS_reply.replace(pos, 1, "<br>");
		nlines++;
		pos = ICS_reply.find( '\n', pos );
	}
	for (int i = nlines; i < 20; i++) ICS_reply.append("<br>");
	to_html(ICS_reply);

	for (int i = 0; i < numfields - 2; i++) {
		pos = form.find(fields[i].f_type);
		if (pos != string::npos) {
			html_text = fields[i].f_data;
			to_html(html_text);
			form.replace( pos, strlen(fields[i].f_type), html_text);
		}
	}
	pos = form.find(fields[numfields-2].f_type);
	if (pos)
		form.replace(	pos,
						strlen(fields[numfields-2].f_type),
						ICS_msg);
	pos = form.find(fields[numfields-1].f_type);
	if (pos)
		form.replace(	pos,
						strlen(fields[numfields-1].f_type),
						ICS_reply);

	FILE *icsfile = fopen(icsname.c_str(), "w");
	fprintf(icsfile,"%s", form.c_str());
	fclose(icsfile);

	open_url(icsname.c_str());
}

void cb_msg_type()
{
	if (tabs_msg_type->value() == tab_ics213 ) {
		show_filename(defFileName);
	} else {
		show_filename(def_rgFileName);
	}
}

void cb_ics_textout()
{
	string icsname = ICS_dir;
	icsname.append("ics213.txt");

	update_fields();
	string form = ics_text_template;

	ICS_msg = fields[numfields-2].f_data;
	ICS_reply = fields[numfields-1].f_data;

	size_t pos;
	for (int i = 0; i < numfields - 2; i++) {
		pos = form.find(fields[i].f_type);
		if (pos != string::npos)
			form.replace(	pos,
							strlen(fields[i].f_type),
							fields[i].f_data );
	}
	pos = form.find(fields[numfields-2].f_type);
	if (pos)
		form.replace(	pos,
						strlen(fields[numfields-2].f_type),
						ICS_msg);
	pos = form.find(fields[numfields-1].f_type);
	if (pos)
		form.replace(	pos,
						strlen(fields[numfields-1].f_type),
						ICS_reply);

	FILE *icsfile = fopen(icsname.c_str(), "w");
	fprintf(icsfile,"%s", form.c_str());
	fclose(icsfile);

	open_url(icsname.c_str());
}
