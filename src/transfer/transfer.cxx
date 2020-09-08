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

#include "transfer.h"

using namespace std;

string transfer_buffer = "";
string def_transfer_filename = "";
string base_transfer_filename = "";

const char xfrstr[] = "<transfer>\n";

void clear_transfer_form()
{
	txt_send_filename->value("");
	show_filename("");
	transfer_buffer.clear();
}

void read_transfer_buffer(string data)
{
	size_t p1 = data.find(xfrstr);
	if (p1 != string::npos) p1 += strlen(xfrstr);
	data.erase(0, p1);
	transfer_buffer = data;
	read_header(data);
}

void cb_transfer_new()
{
	clear_transfer_form();
	def_transfer_filename = XFR_dir;
	show_filename(def_transfer_filename);
	clear_estimate();
}

void cb_transfer_import()
{
	fl_alert2("Not implemented");
}

void cb_transfer_export()
{
	fl_alert2("Not implemented");
}

void cb_transfer_wrap_import(string fname, string txt)
{
	clear_transfer_form();

	string fnam = fname;
	string outfname;
	string tst_name;
	string tst_ext = "";

// write to file with name(s) such as
// test.b2s, test-01.txt, test-02.txt etc.  up to 999
	size_t pos = fnam.find(".");
	if (pos != string::npos) {
		tst_name = fnam.substr(0, pos);
		tst_ext = fnam.substr(pos);
	} else
		tst_name = fnam;

	char fnum[8]="";
	int num = 0;
	outfname.assign(XFR_dir).append(tst_name).append(tst_ext);

	ifstream tstfile;
	tstfile.open(outfname.c_str());
	while (tstfile) {
		tstfile.close();
		snprintf(fnum, sizeof(fnum), "-%03d", (++num % 1000));
		outfname.assign(XFR_dir).append(tst_name).append(fnum).append(tst_ext);
		tstfile.open(outfname.c_str());
	}

// decompress_maybe returns 0 on failure

	pos = txt.find(xfrstr);
	if (pos != string::npos) {
LOG_INFO("Text length %d", (int)txt.length());
		pos += strlen(xfrstr);
		txt.erase(0, pos);
	}

	pos = txt.find("[b64");
	if (pos != string::npos) {
		txt.erase(0, pos);
		decompress_maybe(txt);
LOG_INFO("File length %d", (int)txt.length());
	}

	ofstream ofile(outfname.c_str(), ios::binary);
	if (ofile) ofile << txt;
	ofile.close();

	brws_xfr_filenames->add(outfname.c_str());
}

int eval_transfer_fsize()
{
	if (transfer_buffer.empty()) return 0;

	Ccrc16 chksum;

	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(fl_filename_name(def_transfer_filename.c_str())).append("]");
	evalstr.append(header(xfrstr));

	string outbuf(transfer_buffer);
	if (outbuf.empty()) return 0;

	if (!progStatus.send_original)
		compress_maybe( outbuf, true );

	evalstr.append( outbuf );
	string ck = chksum.scrc16(evalstr);

	evalstr.append("[WRAP:chksum ").append(ck).append("][WRAP:end]");
	return evalstr.length();
}

// not called in 3.x

void cb_transfer_wrap_export()
{
	if (transfer_buffer.empty()) return;

	string wrapfilename = WRAP_send_dir;
	base_transfer_filename = fl_filename_name(def_transfer_filename.c_str());
	wrapfilename.append(base_transfer_filename);
	wrapfilename.append(WRAP_EXT);
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		string fbuff(header("<transfer>"));
		string outbuf(transfer_buffer);
		if (!progStatus.send_original)
			compress_maybe(outbuf, true);
		fbuff.append(outbuf);

		export_wrapfile(base_transfer_filename, wrapfilename, fbuff, pext != WRAP_EXT);
	}
}

void cb_transfer_wrap_autosend()
{
	if (transfer_buffer.empty()) return;

	update_header(FROM);
	string fbuff(header("<transfer>"));
	string outbuf(transfer_buffer);
	if (!progStatus.send_original)
		compress_maybe(outbuf, true);
	fbuff.append(outbuf);
	xfr_via_socket(fl_filename_name(def_transfer_filename.c_str()), fbuff);

}

void cb_transfer_load_template()
{
	fl_alert2("Not implemented");
}

void cb_transfer_save_template()
{
	fl_alert2("Not implemented");
}

void cb_transfer_open_as_template()
{
	fl_alert2("Not implemented");
}

void cb_transfer_open()
{
	const char *p = FSEL::select(_("Open file"), "transfer\t*",
					def_transfer_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_transfer_form();
	def_transfer_filename = p;
	txt_send_filename->value(def_transfer_filename.c_str());
	transfer_buffer.clear();

	FILE *dfile = fopen(p, "rb");
	if (!dfile) {
		txt_send_filename->value("");
		transfer_buffer.clear();
		return;
	}
	fseek(dfile, 0, SEEK_END);
	size_t fsize = ftell(dfile);
	if (fsize <= 0) {
        fclose (dfile);
        return;
    }
	fseek(dfile, 0, SEEK_SET);
	transfer_buffer.resize(fsize);
	size_t r = fread((void *)transfer_buffer.c_str(), 1, fsize, dfile);
	fclose(dfile);
	if (r != fsize) {
		txt_send_filename->value("");
		transfer_buffer.clear();
		return;
	}

	estimate();
}

void write_transfer(string s)
{
	return;
}

void cb_transfer_open_as()
{
	int selected = brws_xfr_filenames->value();
	if (!selected) return;
	const char *p = brws_xfr_filenames->text(selected);

	open_url(p);

	return;
}

void cb_transfer_msg_type()
{
	if (tabs_msg_type->value() == tab_transfer ) {
		show_filename(def_transfer_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void cb_transfer_html()
{
	fl_alert2("Not implemented");
}

void cb_transfer_textout()
{
	fl_alert2("Not implemented");
}

void cb_transfer_import_data()
{
	fl_alert2("Not implemented");
}

void cb_transfer_export_data()
{
	fl_alert2("Not implemented");
}

