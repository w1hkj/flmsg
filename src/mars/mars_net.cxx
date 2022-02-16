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

const char mars_net_precedent[] = "RPOZ";

std::string buffnet;
std::string def_mars_net_filename = "";
std::string base_mars_net_filename = "";
std::string def_mars_net_TemplateName = "";
bool using_mars_net_template = false;

// mars_net fields

std::string mars_net_DE			= ":de:";
std::string mars_net_NBR			= ":nbr:";
std::string mars_net_PREC		= ":prec:";
std::string mars_net_DTG			= ":dtg:";
std::string mars_net_FMNAME		= ":fmname:";
std::string mars_net_FMCALL		= ":fmcall:";
std::string mars_net_FMSTATE		= ":fmstate:";
std::string mars_net_TOPOS		= ":topos:";
std::string mars_net_TOCALL		= ":tocall:";
std::string mars_net_TOSTATE		= ":tostate:";
std::string mars_net_INFOPOS	= ":INFOpos:";
std::string mars_net_INFOCALL	= ":INFOcall:";
std::string mars_net_INFOSTATE	= ":INFOstate:";
std::string mars_net_INCIDENT	= ":incident:";
std::string mars_net_DND			= ":dnd:";
std::string mars_net_NETCALL		= ":netcall:";
std::string mars_net_DTGSTART	= ":dtgstart:";
std::string mars_net_DTGEND		= ":dtgend:";
std::string mars_net_NETSB		= ":netsb:";
std::string mars_net_NCSCALL		= ":ncscall:";
std::string mars_net_NBRSTAS		= ":nbrstas:";
std::string mars_net_CALLS		= ":calls:";
std::string mars_net_NBRMSGS		= ":nbrmsgs:";
std::string mars_net_COMMENTS	= ":comments:";

std::string s_mars_net_DE;
std::string s_mars_net_NBR;
std::string s_mars_net_PREC = "R";
std::string s_mars_net_DTG;
std::string s_mars_net_FMNAME;
std::string s_mars_net_FMCALL;
std::string s_mars_net_FMSTATE;
std::string s_mars_net_TOPOS;
std::string s_mars_net_TOCALL;
std::string s_mars_net_TOSTATE;
std::string s_mars_net_INFOPOS;
std::string s_mars_net_INFOCALL;
std::string s_mars_net_INFOSTATE;
std::string s_mars_net_INCIDENT;
std::string s_mars_net_DND;
std::string s_mars_net_NETCALL;
std::string s_mars_net_DTGSTART;
std::string s_mars_net_DTGEND;
std::string s_mars_net_NETSB;
std::string s_mars_net_NCSCALL;
std::string s_mars_net_NBRSTAS;
std::string s_mars_net_CALLS;
std::string s_mars_net_NBRMSGS;
std::string s_mars_net_COMMENTS;

void cb_mars_net_SetDTG()
{
	txt_mars_net_DTG->value(szDateTime());
}

void cb_mars_net_SetDTGSTART()
{
	txt_mars_net_DTGSTART->value(szDateTime());
}

void cb_mars_net_SetDTGEND()
{
	txt_mars_net_DTGEND->value(szDateTime());
}

void clear_mars_net_fields()
{
	s_mars_net_DE.clear();
	s_mars_net_NBR.clear();
	s_mars_net_PREC = "R";
	s_mars_net_DTG.clear();
	s_mars_net_FMNAME.clear();
	s_mars_net_FMCALL.clear();
	s_mars_net_FMSTATE.clear();
	s_mars_net_TOPOS.clear();
	s_mars_net_TOCALL.clear();
	s_mars_net_TOSTATE.clear();
	s_mars_net_INFOPOS.clear();
	s_mars_net_INFOCALL.clear();
	s_mars_net_INFOSTATE.clear();
	s_mars_net_INCIDENT.clear();
	s_mars_net_DND.clear();
	s_mars_net_NETCALL.clear();
	s_mars_net_DTGSTART.clear();
	s_mars_net_DTGEND.clear();
	s_mars_net_NETSB.clear();
	s_mars_net_NCSCALL.clear();
	s_mars_net_NBRSTAS.clear();
	s_mars_net_CALLS.clear();
	s_mars_net_NBRMSGS.clear();
	s_mars_net_COMMENTS.clear();

}

bool check_mars_net_fields()
{
	std::string temp;
	if (s_mars_net_DE != txt_mars_net_DE->value()) return true;
	if (s_mars_net_NBR != txt_mars_net_NBR->value()) return true;
	temp = mars_net_precedent[sel_mars_net_PREC->index()];
	if (s_mars_net_PREC != temp) return true;
	if (s_mars_net_DTG != txt_mars_net_DTG->value()) return true;
	if (s_mars_net_FMNAME != txt_mars_net_FMNAME->value()) return true;
	if (s_mars_net_FMCALL != txt_mars_net_FMCALL->value()) return true;
	if (s_mars_net_FMSTATE != txt_mars_net_FMSTATE->value()) return true;
	if (s_mars_net_TOPOS != txt_mars_net_TOPOS->value()) return true;
	if (s_mars_net_TOCALL != txt_mars_net_TOCALL->value()) return true;
	if (s_mars_net_TOSTATE != txt_mars_net_TOSTATE->value()) return true;
	if (s_mars_net_INFOPOS != txt_mars_net_INFOPOS->value()) return true;
	if (s_mars_net_INFOCALL != txt_mars_net_INFOCALL->value()) return true;
	if (s_mars_net_INFOSTATE != txt_mars_net_INFOSTATE->value()) return true;
	if (s_mars_net_INCIDENT != txt_mars_net_INCIDENT->value()) return true;
	if (s_mars_net_DND != txt_mars_net_DND->value()) return true;
	if (s_mars_net_NETCALL != txt_mars_net_NETCALL->value()) return true;
	if (s_mars_net_DTGSTART != txt_mars_net_DTGSTART->value()) return true;
	if (s_mars_net_DTGEND != txt_mars_net_DTGEND->value()) return true;
	if (s_mars_net_NETSB != txt_mars_net_NETSB->value()) return true;
	if (s_mars_net_NCSCALL != txt_mars_net_NCSCALL->value()) return true;
	if (s_mars_net_NBRSTAS != txt_mars_net_NBRSTAS->value()) return true;
	if (s_mars_net_CALLS != txt_mars_net_CALLS->value()) return true;
	if (s_mars_net_NBRMSGS != txt_mars_net_NBRMSGS->value()) return true;
	if (s_mars_net_COMMENTS != txt_mars_net_COMMENTS->value()) return true;
	return false;
}

void update_mars_net_fields()
{
	s_mars_net_DE = txt_mars_net_DE->value();
	s_mars_net_NBR = txt_mars_net_NBR->value();
	s_mars_net_PREC.clear();
	s_mars_net_PREC = mars_net_precedent[sel_mars_net_PREC->index()];
	s_mars_net_DTG = txt_mars_net_DTG->value();
	s_mars_net_FMNAME = txt_mars_net_FMNAME->value();
	s_mars_net_FMCALL = txt_mars_net_FMCALL->value();
	s_mars_net_FMSTATE = txt_mars_net_FMSTATE->value();
	s_mars_net_TOPOS = txt_mars_net_TOPOS->value();
	s_mars_net_TOCALL = txt_mars_net_TOCALL->value();
	s_mars_net_TOSTATE = txt_mars_net_TOSTATE->value();
	s_mars_net_INFOPOS = txt_mars_net_INFOPOS->value();
	s_mars_net_INFOCALL = txt_mars_net_INFOCALL->value();
	s_mars_net_INFOSTATE = txt_mars_net_INFOSTATE->value();
	s_mars_net_INCIDENT = txt_mars_net_INCIDENT->value();
	s_mars_net_DND = txt_mars_net_DND->value();
	s_mars_net_NETCALL = txt_mars_net_NETCALL->value();
	s_mars_net_DTGSTART = txt_mars_net_DTGSTART->value();
	s_mars_net_DTGEND = txt_mars_net_DTGEND->value();
	s_mars_net_NETSB = txt_mars_net_NETSB->value();
	s_mars_net_NCSCALL = txt_mars_net_NCSCALL->value();
	s_mars_net_NBRSTAS = txt_mars_net_NBRSTAS->value();
	s_mars_net_CALLS = txt_mars_net_CALLS->value();
	s_mars_net_NBRMSGS = txt_mars_net_NBRMSGS->value();
	s_mars_net_COMMENTS = txt_mars_net_COMMENTS->value();
}

void update_mars_netform()
{
	txt_mars_net_DE->value(s_mars_net_DE.c_str());
	txt_mars_net_NBR->value(s_mars_net_NBR.c_str());

	size_t n = strchr(mars_net_precedent, s_mars_net_PREC[0]) - mars_net_precedent;
	if (n < 0) n = 0;
	if (n > 4) n = 4;
	sel_mars_net_PREC->index(n);

	txt_mars_net_DTG->value(s_mars_net_DTG.c_str());
	txt_mars_net_FMNAME->value(s_mars_net_FMNAME.c_str());
	txt_mars_net_FMCALL->value(s_mars_net_FMCALL.c_str());
	txt_mars_net_FMSTATE->value(s_mars_net_FMSTATE.c_str());
	txt_mars_net_TOPOS->value(s_mars_net_TOPOS.c_str());
	txt_mars_net_TOCALL->value(s_mars_net_TOCALL.c_str());
	txt_mars_net_TOSTATE->value(s_mars_net_TOSTATE.c_str());
	txt_mars_net_INFOPOS->value(s_mars_net_INFOPOS.c_str());
	txt_mars_net_INFOCALL->value(s_mars_net_INFOCALL.c_str());
	txt_mars_net_INFOSTATE->value(s_mars_net_INFOSTATE.c_str());
	txt_mars_net_INCIDENT->value(s_mars_net_INCIDENT.c_str());
	txt_mars_net_DND->value(s_mars_net_DND.c_str());
	txt_mars_net_NETCALL->value(s_mars_net_NETCALL.c_str());
	txt_mars_net_DTGSTART->value(s_mars_net_DTGSTART.c_str());
	txt_mars_net_DTGEND->value(s_mars_net_DTGEND.c_str());
	txt_mars_net_NETSB->value(s_mars_net_NETSB.c_str());
	txt_mars_net_NCSCALL->value(s_mars_net_NCSCALL.c_str());
	txt_mars_net_NBRSTAS->value(s_mars_net_NBRSTAS.c_str());
	txt_mars_net_CALLS->value(s_mars_net_CALLS.c_str());
	txt_mars_net_NBRMSGS->value(s_mars_net_NBRMSGS.c_str());
	txt_mars_net_COMMENTS->value(s_mars_net_COMMENTS.c_str());
}

void clear_mars_net_form()
{
	clear_mars_net_fields();
	txt_mars_net_DE->value("");
	txt_mars_net_NBR->value("");
	sel_mars_net_PREC->index(4);
	txt_mars_net_DTG->value("");
	txt_mars_net_FMNAME->value("");
	txt_mars_net_FMCALL->value("");
	txt_mars_net_FMSTATE->value("");
	txt_mars_net_TOPOS->value("");
	txt_mars_net_TOCALL->value("");
	txt_mars_net_TOSTATE->value("");
	txt_mars_net_INFOPOS->value("");
	txt_mars_net_INFOCALL->value("");
	txt_mars_net_INFOSTATE->value("");
	txt_mars_net_INCIDENT->value("");
	txt_mars_net_DND->value("");
	txt_mars_net_NETCALL->value("");
	txt_mars_net_DTGSTART->value("");
	txt_mars_net_DTGEND->value("");
	txt_mars_net_NETSB->value("");
	txt_mars_net_NCSCALL->value("");
	txt_mars_net_NBRSTAS->value("");
	txt_mars_net_CALLS->value("");
	txt_mars_net_NBRMSGS->value("");
	txt_mars_net_COMMENTS->value("");
}

void make_mars_buffnet(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( mars_net_DE, s_mars_net_DE ) );
	mbuff.append( lineout( mars_net_NBR, s_mars_net_NBR ) );
	mbuff.append( lineout( mars_net_PREC, s_mars_net_PREC ) );
	mbuff.append( lineout( mars_net_DTG, s_mars_net_DTG ) );
	mbuff.append( lineout( mars_net_FMNAME, s_mars_net_FMNAME ) );
	mbuff.append( lineout( mars_net_FMCALL, s_mars_net_FMCALL ) );
	mbuff.append( lineout( mars_net_FMSTATE, s_mars_net_FMSTATE ) );
	mbuff.append( lineout( mars_net_TOPOS, s_mars_net_TOPOS ) );
	mbuff.append( lineout( mars_net_TOCALL, s_mars_net_TOCALL ) );
	mbuff.append( lineout( mars_net_TOSTATE, s_mars_net_TOSTATE ) );
	mbuff.append( lineout( mars_net_INFOPOS, s_mars_net_INFOPOS ) );
	mbuff.append( lineout( mars_net_INFOCALL, s_mars_net_INFOCALL ) );
	mbuff.append( lineout( mars_net_INFOSTATE, s_mars_net_INFOSTATE ) );
	mbuff.append( lineout( mars_net_INCIDENT, s_mars_net_INCIDENT ) );
	mbuff.append( lineout( mars_net_DND, s_mars_net_DND ) );
	mbuff.append( lineout( mars_net_NETCALL, s_mars_net_NETCALL ) );
	mbuff.append( lineout( mars_net_DTGSTART, s_mars_net_DTGSTART ) );
	mbuff.append( lineout( mars_net_DTGEND, s_mars_net_DTGEND ) );
	mbuff.append( lineout( mars_net_NETSB, s_mars_net_NETSB ) );
	mbuff.append( lineout( mars_net_NCSCALL, s_mars_net_NCSCALL ) );
	mbuff.append( lineout( mars_net_NBRSTAS, s_mars_net_NBRSTAS ) );
	mbuff.append( lineout( mars_net_CALLS, s_mars_net_CALLS ) );
	mbuff.append( lineout( mars_net_NBRMSGS, s_mars_net_NBRMSGS ) );
	mbuff.append( lineout( mars_net_COMMENTS, s_mars_net_COMMENTS ) );
	if (compress) compress_maybe(mbuff);
	buffnet.append(mbuff);
}

void read_mars_net_buffer(std::string data)
{
	clear_mars_net_fields();
// search the file buffer for each of the mars_net fields

	s_mars_net_DE = findstr(data, mars_net_DE);
	s_mars_net_NBR = findstr(data, mars_net_NBR);
	s_mars_net_PREC = findstr(data, mars_net_PREC);
	s_mars_net_DTG = findstr(data, mars_net_DTG);
	s_mars_net_FMNAME = findstr(data, mars_net_FMNAME);
	s_mars_net_FMCALL = findstr(data, mars_net_FMCALL);
	s_mars_net_FMSTATE = findstr(data, mars_net_FMSTATE);
	s_mars_net_TOPOS = findstr(data, mars_net_TOPOS);
	s_mars_net_TOCALL = findstr(data, mars_net_TOCALL);
	s_mars_net_TOSTATE = findstr(data, mars_net_TOSTATE);
	s_mars_net_INFOPOS = findstr(data, mars_net_INFOPOS);
	s_mars_net_INFOCALL = findstr(data, mars_net_INFOCALL);
	s_mars_net_INFOSTATE = findstr(data, mars_net_INFOSTATE);
	s_mars_net_INCIDENT = findstr(data, mars_net_INCIDENT);
	s_mars_net_DND = findstr(data, mars_net_DND);
	s_mars_net_NETCALL = findstr(data, mars_net_NETCALL);
	s_mars_net_DTGSTART = findstr(data, mars_net_DTGSTART);
	s_mars_net_DTGEND = findstr(data, mars_net_DTGEND);
	s_mars_net_NETSB = findstr(data, mars_net_NETSB);
	s_mars_net_NCSCALL = findstr(data, mars_net_NCSCALL);
	s_mars_net_NBRSTAS = findstr(data, mars_net_NBRSTAS);
	s_mars_net_CALLS = findstr(data, mars_net_CALLS);
	s_mars_net_NBRMSGS = findstr(data, mars_net_NBRMSGS);
	s_mars_net_COMMENTS = findstr(data, mars_net_COMMENTS);

	update_mars_netform();
}

void cb_mars_net_new()
{
	if (check_mars_net_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_mars_net_save();
		}
	}
	clear_mars_net_form();
	def_mars_net_filename = ICS_msg_dir;
	def_mars_net_filename.append("new").append(FMARSNET_EXT);
	show_filename(def_mars_net_filename);
	using_mars_net_template = false;
}

void cb_mars_net_import()
{
	fl_alert2("Not implemented");
}

void cb_mars_net_export()
{
	fl_alert2("Not implemented");
}

void cb_mars_net_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_mars_net_form();
	read_mars_net_buffer(inpbuffer);
	def_mars_net_filename = ICS_msg_dir;
	def_mars_net_filename.append(wrapfilename);
	show_filename(def_mars_net_filename);
	using_mars_net_template = false;
}

int eval_mars_net_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_mars_net_filename).append("]");
	update_mars_net_fields();
	update_header(FROM);
	evalstr.append(header("<mars_net>"));
	buffnet.clear();
	make_mars_buffnet(true);
	if (buffnet.empty()) return 0;
	compress_maybe( buffnet );
	evalstr.append( buffnet );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_mars_net_wrap_export()
{
	if (check_mars_net_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_net_fields();

	if (base_mars_net_filename == std::string("new").append(FMARSNET_EXT) ||
		base_mars_net_filename == std::string("default").append(FMARSNET_EXT) )
		if (!cb_mars_net_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_net_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffnet.assign(header("<mars_net>"));
		make_mars_buffnet(true);
		export_wrapfile(base_mars_net_filename, wrapfilename, buffnet, pext != ".wrap");

		buffnet.assign(header("<mars_net>"));
		make_mars_buffnet(false);
		write_mars_net(def_mars_net_filename);
	}
}

void cb_mars_net_wrap_autosend()
{
	if (check_mars_net_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_net_fields();

	if (base_mars_net_filename == std::string("new").append(FMARSNET_EXT) ||
		base_mars_net_filename == std::string("default").append(FMARSNET_EXT) )
		if (!cb_mars_net_save_as()) return;

	update_header(FROM);
	buffnet.assign(header("<mars_net>"));
	make_mars_buffnet(true);
	xfr_via_socket(base_mars_net_filename, buffnet);

	buffnet.assign(header("<mars_net>"));
	make_mars_buffnet(false);
	write_mars_net(def_mars_net_filename);
}

void cb_mars_net_load_template()
{
	std::string def_mars_net_filename = def_mars_net_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TMARSNET_EXT).c_str(),
			def_mars_net_filename.c_str());
	if (p) {
		clear_mars_net_form();
		read_data_file(p);
		def_mars_net_TemplateName = p;
		show_filename(def_mars_net_TemplateName);
		using_mars_net_template = true;
	}
}

void cb_mars_net_save_template()
{
	if (!using_mars_net_template) {
		cb_mars_net_save_as_template();
		return;
	}
	std::string def_mars_net_filename = def_mars_net_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TMARSNET_EXT).c_str(),
			def_mars_net_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_mars_net_fields();
		buffnet.assign(header("<mars_net>"));
		make_mars_buffnet();
		write_mars_net(p);
	}
}

void cb_mars_net_save_as_template()
{
	std::string def_mars_net_filename = def_mars_net_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TMARSNET_EXT).c_str(),
			def_mars_net_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_net_TemplateName = p;
		if (strlen(pext) == 0) def_mars_net_TemplateName.append(TMARSNET_EXT);
		remove_spaces_from_filename(def_mars_net_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_mars_net_fields();
		buffnet.assign(header("<mars_net>"));
		make_mars_buffnet();
		write_mars_net(def_mars_net_TemplateName);

		show_filename(def_mars_net_TemplateName);
		using_mars_net_template = true;
	}
}

void cb_mars_net_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-net\t*").append(FMARSNET_EXT).c_str(),
			def_mars_net_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_net_form();
	read_data_file(p);
	using_mars_net_template = false;
	def_mars_net_filename = p;
	show_filename(def_mars_net_filename);
}

void write_mars_net(std::string s)
{
	FILE *filenet = fopen(s.c_str(), "w");
	if (!filenet) return;
	make_mars_buffnet();
	fwrite(buffnet.c_str(), buffnet.length(), 1, filenet);
	fclose(filenet);
}

bool cb_mars_net_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(FMARSNET_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_net_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-net\t*").append(FMARSNET_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_mars_net_filename = p;
	if (strlen(pext) == 0) def_mars_net_filename.append(FMARSNET_EXT);

	remove_spaces_from_filename(def_mars_net_filename);

	update_header(NEW);
	update_mars_net_fields();
	buffnet.assign(header("<mars_net>"));
	make_mars_buffnet();
	write_mars_net(def_mars_net_filename);

	using_mars_net_template = false;
	show_filename(def_mars_net_filename);
	return true;
}

void cb_mars_net_save()
{
	if (base_mars_net_filename == std::string("new").append(FMARSNET_EXT) || 
		base_mars_net_filename == std::string("default").append(FMARSNET_EXT) ||
		using_mars_net_template == true) {
		cb_mars_net_save_as();
		return;
	}
	if (check_mars_net_fields()) update_header(CHANGED);
	update_mars_net_fields();
	buffnet.assign(header("<mars_net>"));
	make_mars_buffnet();
	write_mars_net(def_mars_net_filename);

	using_mars_net_template = false;
}

void cb_mars_net_html()
{
	std::string fname_name = fl_filename_name(def_mars_net_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	std::string mars_net_fname = ICS_dir;
	mars_net_fname.append(fname_name);
	mars_net_fname.append(".html");

	std::string formnet = mars_net_html_template;

	replacestr(formnet, mars_net_DE, s_mars_net_DE);
	replacestr(formnet, mars_net_NBR, s_mars_net_NBR);
	replacestr(formnet, mars_net_PREC, s_mars_net_PREC);
	replacestr(formnet, mars_net_DTG, s_mars_net_DTG);
	replacestr(formnet, mars_net_FMNAME, s_mars_net_FMNAME);
	replacestr(formnet, mars_net_FMCALL, s_mars_net_FMCALL);
	replacestr(formnet, mars_net_FMSTATE, s_mars_net_FMSTATE);
	replacestr(formnet, mars_net_TOPOS, s_mars_net_TOPOS);
	replacestr(formnet, mars_net_TOCALL, s_mars_net_TOCALL);
	replacestr(formnet, mars_net_TOSTATE, s_mars_net_TOSTATE);
	replacestr(formnet, mars_net_INFOPOS, s_mars_net_INFOPOS);
	replacestr(formnet, mars_net_INFOCALL, s_mars_net_INFOCALL);
	replacestr(formnet, mars_net_INFOSTATE, s_mars_net_INFOSTATE);
	replacestr(formnet, mars_net_INCIDENT, s_mars_net_INCIDENT);
	replacestr(formnet, mars_net_INCIDENT, s_mars_net_INCIDENT); // 2 in form
	replacestr(formnet, mars_net_DND, s_mars_net_DND);
	replacestr(formnet, mars_net_NETCALL, s_mars_net_NETCALL);
	replacestr(formnet, mars_net_DTGSTART, s_mars_net_DTGSTART);
	replacestr(formnet, mars_net_DTGEND, s_mars_net_DTGEND);
	replacestr(formnet, mars_net_NETSB, s_mars_net_NETSB);
	replacestr(formnet, mars_net_NCSCALL, s_mars_net_NCSCALL);
	replacestr(formnet, mars_net_NBRSTAS, s_mars_net_NBRSTAS);
	replacestr(formnet, mars_net_CALLS, s_mars_net_CALLS);
	replacestr(formnet, mars_net_NBRMSGS, s_mars_net_NBRMSGS);
	replacestr(formnet, mars_net_COMMENTS, s_mars_net_COMMENTS);

	FILE *filenet = fopen(mars_net_fname.c_str(), "w");
	fprintf(filenet,"%s", formnet.c_str());
	fclose(filenet);

	open_url(mars_net_fname.c_str());
}

void cb_mars_net_textout()
{
	std::string temp = "";
	std::string mars_net_fname = ICS_dir;
	mars_net_fname.append("mars_net.txt");

	std::string formnet = mars_net_text_template;

	replacestr(formnet, mars_net_DE, s_mars_net_DE);
	replacestr(formnet, mars_net_NBR, s_mars_net_NBR);
	replacestr(formnet, mars_net_PREC, s_mars_net_PREC);
	replacestr(formnet, mars_net_DTG, s_mars_net_DTG);
	replacestr(formnet, mars_net_FMNAME, s_mars_net_FMNAME);
	replacestr(formnet, mars_net_FMCALL, s_mars_net_FMCALL);
	replacestr(formnet, mars_net_FMSTATE, s_mars_net_FMSTATE);
	replacestr(formnet, mars_net_TOPOS, s_mars_net_TOPOS);
	replacestr(formnet, mars_net_TOCALL, s_mars_net_TOCALL);
	replacestr(formnet, mars_net_TOSTATE, s_mars_net_TOSTATE);
	replacestr(formnet, mars_net_INFOPOS, s_mars_net_INFOPOS);
	replacestr(formnet, mars_net_INFOCALL, s_mars_net_INFOCALL);
	replacestr(formnet, mars_net_INFOSTATE, s_mars_net_INFOSTATE);
	replacestr(formnet, mars_net_INCIDENT, s_mars_net_INCIDENT);
	replacestr(formnet, mars_net_INCIDENT, s_mars_net_INCIDENT); // 2 in form
	replacestr(formnet, mars_net_DND, s_mars_net_DND);
	replacestr(formnet, mars_net_NETCALL, s_mars_net_NETCALL);
	replacestr(formnet, mars_net_DTGSTART, s_mars_net_DTGSTART);
	replacestr(formnet, mars_net_DTGEND, s_mars_net_DTGEND);
	replacestr(formnet, mars_net_NETSB, s_mars_net_NETSB);
	replacestr(formnet, mars_net_NCSCALL, s_mars_net_NCSCALL);
	replacestr(formnet, mars_net_NBRSTAS, s_mars_net_NBRSTAS);
	replacestr(formnet, mars_net_CALLS, s_mars_net_CALLS);
	replacestr(formnet, mars_net_NBRMSGS, s_mars_net_NBRMSGS);
	replacestr(formnet, mars_net_COMMENTS, s_mars_net_COMMENTS);

	FILE *filenet = fopen(mars_net_fname.c_str(), "w");
	fprintf(filenet,"%s", formnet.c_str());
	fclose(filenet);

	open_url(mars_net_fname.c_str());
}

