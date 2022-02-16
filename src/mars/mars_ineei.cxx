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

const char mars_ineei_precedent[] = "RPIFM";

std::string ineei_buff;
std::string def_mars_ineei_filename = "";
std::string base_mars_ineei_filename = "";
std::string def_mars_ineei_TemplateName = "";
bool using_mars_ineei_template = false;

// mars_ineei fields

std::string mars_ineei_DE			= ":de:";
std::string mars_ineei_NBR			= ":nbr:";
std::string mars_ineei_PREC			= ":prec:";
std::string mars_ineei_DTG			= ":dtg:";
std::string mars_ineei_FMNAME		= ":fmname:";
std::string mars_ineei_FMCALL		= ":fmcall:";
std::string mars_ineei_FMSTATE		= ":fmstate:";
std::string mars_ineei_TOPOS			= ":topos:";
std::string mars_ineei_TOCALL		= ":tocall:";
std::string mars_ineei_TOSTATE		= ":tostate:";
std::string mars_ineei_INFO1POS		= ":info1pos:";
std::string mars_ineei_INFO1CALL		= ":info1call:";
std::string mars_ineei_INFO1STATE	= ":info1state:";
std::string mars_ineei_INFO2POS		= ":info2pos:";
std::string mars_ineei_INFO2CALL		= ":info2call:";
std::string mars_ineei_INFO2STATE	= ":info2state:";
std::string mars_ineei_INFO3POS		= ":info3pos:";
std::string mars_ineei_INFO3CALL		= ":info3call:";
std::string mars_ineei_INFO3STATE	= ":info3state:";
std::string mars_ineei_INFO4POS		= ":info4pos:";
std::string mars_ineei_INFO4CALL		= ":info4call:";
std::string mars_ineei_INFO4STATE	= ":info4state:";
std::string mars_ineei_INFO5POS		= ":info5pos:";
std::string mars_ineei_INFO5CALL		= ":info5call:";
std::string mars_ineei_INFO5STATE	= ":info5state:";
std::string mars_ineei_INFO6POS		= ":info6pos:";
std::string mars_ineei_INFO6CALL		= ":info6call:";
std::string mars_ineei_INFO6STATE	= ":info6state:";
std::string mars_ineei_INFO7POS		= ":info7pos:";
std::string mars_ineei_INFO7CALL		= ":info7call:";
std::string mars_ineei_INFO7STATE	= ":info7state:";
std::string mars_ineei_INFO8POS		= ":info8pos:";
std::string mars_ineei_INFO8CALL		= ":info8call:";
std::string mars_ineei_INFO8STATE	= ":info8state:";
std::string mars_ineei_INFO9POS		= ":info9pos:";
std::string mars_ineei_INFO9CALL		= ":info9call:";
std::string mars_ineei_INFO9STATE	= ":info9state:";
std::string mars_ineei_INFO10POS		= ":info10pos:";
std::string mars_ineei_INFO10CALL	= ":info10call:";
std::string mars_ineei_INFO10STATE	= ":info10state:";
std::string mars_ineei_INCIDENT		= ":incident:";
std::string mars_ineei_REF			= ":ref:";
std::string mars_ineei_STATE			= ":state:";
std::string mars_ineei_1A_INCIDENT	= ":1a_incident:";
std::string mars_ineei_1A_LOCATION	= ":1a_location:";
std::string mars_ineei_1A_TIME		= ":1a_time:";
std::string mars_ineei_1B_MEDFACSTS	= ":1b_medfacsts:";
std::string mars_ineei_1C_TRNPSTS	= ":1c_trnpsts:";
std::string mars_ineei_1D_DAMAGE		= ":1d_damage:";
std::string mars_ineei_1E_UTILSTS	= ":1e_utilsts:";
std::string mars_ineei_1F_COMMSTS	= ":1f_commsts:";
std::string mars_ineei_1G_INFOSRC	= ":1g_infosrc:";
std::string mars_ineei_1G_INFOTIME	= ":1g_infotime:";
std::string mars_ineei_1H_REMARKS	= ":1h_remarks:";

std::string s_mars_ineei_DE;
std::string s_mars_ineei_NBR;
std::string s_mars_ineei_PREC = "R";
std::string s_mars_ineei_DTG;
std::string s_mars_ineei_FMNAME;
std::string s_mars_ineei_FMCALL;
std::string s_mars_ineei_FMSTATE;
std::string s_mars_ineei_TOPOS;
std::string s_mars_ineei_TOCALL;
std::string s_mars_ineei_TOSTATE;
std::string s_mars_ineei_INFO1POS;
std::string s_mars_ineei_INFO1CALL;
std::string s_mars_ineei_INFO1STATE;
std::string s_mars_ineei_INFO2POS;
std::string s_mars_ineei_INFO2CALL;
std::string s_mars_ineei_INFO2STATE;
std::string s_mars_ineei_INFO3POS;
std::string s_mars_ineei_INFO3CALL;
std::string s_mars_ineei_INFO3STATE;
std::string s_mars_ineei_INFO4POS;
std::string s_mars_ineei_INFO4CALL;
std::string s_mars_ineei_INFO4STATE;
std::string s_mars_ineei_INFO5POS;
std::string s_mars_ineei_INFO5CALL;
std::string s_mars_ineei_INFO5STATE;
std::string s_mars_ineei_INFO6POS;
std::string s_mars_ineei_INFO6CALL;
std::string s_mars_ineei_INFO6STATE;
std::string s_mars_ineei_INFO7POS;
std::string s_mars_ineei_INFO7CALL;
std::string s_mars_ineei_INFO7STATE;
std::string s_mars_ineei_INFO8POS;
std::string s_mars_ineei_INFO8CALL;
std::string s_mars_ineei_INFO8STATE;
std::string s_mars_ineei_INFO9POS;
std::string s_mars_ineei_INFO9CALL;
std::string s_mars_ineei_INFO9STATE;
std::string s_mars_ineei_INFO10POS;
std::string s_mars_ineei_INFO10CALL;
std::string s_mars_ineei_INFO10STATE;
std::string s_mars_ineei_INCIDENT;
std::string s_mars_ineei_REF;
std::string s_mars_ineei_STATE;
std::string s_mars_ineei_1A_INCIDENT;
std::string s_mars_ineei_1A_LOCATION;
std::string s_mars_ineei_1A_TIME;
std::string s_mars_ineei_1B_MEDFACSTS;
std::string s_mars_ineei_1C_TRNPSTS;
std::string s_mars_ineei_1D_DAMAGE;
std::string s_mars_ineei_1E_UTILSTS;
std::string s_mars_ineei_1F_COMMSTS;
std::string s_mars_ineei_1G_INFOSRC;
std::string s_mars_ineei_1G_INFOTIME;
std::string s_mars_ineei_1H_REMARKS;

void cb_mars_ineei_SetDTG()
{
	txt_mars_ineei_DTG->value(szDateTime());
}

void clear_mars_ineei_fields()
{
	s_mars_ineei_DE.clear();
	s_mars_ineei_NBR.clear();
	s_mars_ineei_PREC = "M";
	s_mars_ineei_DTG.clear();
	s_mars_ineei_FMNAME.clear();
	s_mars_ineei_FMCALL.clear();
	s_mars_ineei_FMSTATE.clear();
	s_mars_ineei_TOPOS.clear();
	s_mars_ineei_TOCALL.clear();
	s_mars_ineei_TOSTATE.clear();
	s_mars_ineei_INFO1POS.clear();
	s_mars_ineei_INFO1CALL.clear();
	s_mars_ineei_INFO1STATE.clear();
	s_mars_ineei_INFO2POS.clear();
	s_mars_ineei_INFO2CALL.clear();
	s_mars_ineei_INFO2STATE.clear();
	s_mars_ineei_INFO3POS.clear();
	s_mars_ineei_INFO3CALL.clear();
	s_mars_ineei_INFO3STATE.clear();
	s_mars_ineei_INFO4POS.clear();
	s_mars_ineei_INFO4CALL.clear();
	s_mars_ineei_INFO4STATE.clear();
	s_mars_ineei_INFO5POS.clear();
	s_mars_ineei_INFO5CALL.clear();
	s_mars_ineei_INFO5STATE.clear();
	s_mars_ineei_INFO6POS.clear();
	s_mars_ineei_INFO6CALL.clear();
	s_mars_ineei_INFO6STATE.clear();
	s_mars_ineei_INFO7POS.clear();
	s_mars_ineei_INFO7CALL.clear();
	s_mars_ineei_INFO7STATE.clear();
	s_mars_ineei_INFO8POS.clear();
	s_mars_ineei_INFO8CALL.clear();
	s_mars_ineei_INFO8STATE.clear();
	s_mars_ineei_INFO9POS.clear();
	s_mars_ineei_INFO9CALL.clear();
	s_mars_ineei_INFO9STATE.clear();
	s_mars_ineei_INFO10POS.clear();
	s_mars_ineei_INFO10CALL.clear();
	s_mars_ineei_INFO10STATE.clear();
	s_mars_ineei_INCIDENT.clear();
	s_mars_ineei_REF.clear();
	s_mars_ineei_STATE.clear();
	s_mars_ineei_1A_INCIDENT.clear();
	s_mars_ineei_1A_LOCATION.clear();
	s_mars_ineei_1A_TIME.clear();
	s_mars_ineei_1B_MEDFACSTS.clear();
	s_mars_ineei_1C_TRNPSTS.clear();
	s_mars_ineei_1D_DAMAGE.clear();
	s_mars_ineei_1E_UTILSTS.clear();
	s_mars_ineei_1F_COMMSTS.clear();
	s_mars_ineei_1G_INFOSRC.clear();
	s_mars_ineei_1G_INFOTIME.clear();
	s_mars_ineei_1H_REMARKS.clear();
}

bool check_mars_ineei_fields()
{
	std::string temp;
	if (s_mars_ineei_DE != txt_mars_ineei_DE->value()) return true;
	if (s_mars_ineei_NBR != txt_mars_ineei_NBR->value()) return true;
	temp = mars_ineei_precedent[sel_mars_ineei_PREC->index()];
	if (s_mars_ineei_PREC != temp) return true;
	if (s_mars_ineei_DTG != txt_mars_ineei_DTG->value()) return true;
	if (s_mars_ineei_FMNAME != txt_mars_ineei_FMNAME->value()) return true;
	if (s_mars_ineei_FMCALL != txt_mars_ineei_FMCALL->value()) return true;
	if (s_mars_ineei_FMSTATE != txt_mars_ineei_FMSTATE->value()) return true;
	if (s_mars_ineei_TOPOS != txt_mars_ineei_TOPOS->value()) return true;
	if (s_mars_ineei_TOCALL != txt_mars_ineei_TOCALL->value()) return true;
	if (s_mars_ineei_TOSTATE != txt_mars_ineei_TOSTATE->value()) return true;
	if (s_mars_ineei_INFO1POS != txt_mars_ineei_INFO1POS->value()) return true;
	if (s_mars_ineei_INFO1CALL != txt_mars_ineei_INFO1CALL->value()) return true;
	if (s_mars_ineei_INFO1STATE != txt_mars_ineei_INFO1STATE->value()) return true;
	if (s_mars_ineei_INFO2POS != txt_mars_ineei_INFO2POS->value()) return true;
	if (s_mars_ineei_INFO2CALL != txt_mars_ineei_INFO2CALL->value()) return true;
	if (s_mars_ineei_INFO2STATE != txt_mars_ineei_INFO2STATE->value()) return true;
	if (s_mars_ineei_INFO3POS != txt_mars_ineei_INFO3POS->value()) return true;
	if (s_mars_ineei_INFO3CALL != txt_mars_ineei_INFO3CALL->value()) return true;
	if (s_mars_ineei_INFO3STATE != txt_mars_ineei_INFO3STATE->value()) return true;
	if (s_mars_ineei_INFO4POS != txt_mars_ineei_INFO4POS->value()) return true;
	if (s_mars_ineei_INFO4CALL != txt_mars_ineei_INFO4CALL->value()) return true;
	if (s_mars_ineei_INFO4STATE != txt_mars_ineei_INFO4STATE->value()) return true;
	if (s_mars_ineei_INFO5POS != txt_mars_ineei_INFO5POS->value()) return true;
	if (s_mars_ineei_INFO5CALL != txt_mars_ineei_INFO5CALL->value()) return true;
	if (s_mars_ineei_INFO5STATE != txt_mars_ineei_INFO5STATE->value()) return true;
	if (s_mars_ineei_INFO6POS != txt_mars_ineei_INFO6POS->value()) return true;
	if (s_mars_ineei_INFO6CALL != txt_mars_ineei_INFO6CALL->value()) return true;
	if (s_mars_ineei_INFO6STATE != txt_mars_ineei_INFO6STATE->value()) return true;
	if (s_mars_ineei_INFO7POS != txt_mars_ineei_INFO7POS->value()) return true;
	if (s_mars_ineei_INFO7CALL != txt_mars_ineei_INFO7CALL->value()) return true;
	if (s_mars_ineei_INFO7STATE != txt_mars_ineei_INFO7STATE->value()) return true;
	if (s_mars_ineei_INFO8POS != txt_mars_ineei_INFO8POS->value()) return true;
	if (s_mars_ineei_INFO8CALL != txt_mars_ineei_INFO8CALL->value()) return true;
	if (s_mars_ineei_INFO8STATE != txt_mars_ineei_INFO8STATE->value()) return true;
	if (s_mars_ineei_INFO9POS != txt_mars_ineei_INFO9POS->value()) return true;
	if (s_mars_ineei_INFO9CALL != txt_mars_ineei_INFO9CALL->value()) return true;
	if (s_mars_ineei_INFO9STATE != txt_mars_ineei_INFO9STATE->value()) return true;
	if (s_mars_ineei_INFO10POS != txt_mars_ineei_INFO10POS->value()) return true;
	if (s_mars_ineei_INFO10CALL != txt_mars_ineei_INFO10CALL->value()) return true;
	if (s_mars_ineei_INFO10STATE != txt_mars_ineei_INFO10STATE->value()) return true;
	if (s_mars_ineei_INCIDENT != txt_mars_ineei_INCIDENT->value()) return true;
	if (s_mars_ineei_REF != txt_mars_ineei_REF->value()) return true;
	if (s_mars_ineei_STATE != txt_mars_ineei_STATE->value()) return true;
	if (s_mars_ineei_1A_INCIDENT != txt_mars_ineei_1A_INCIDENT->value()) return true;
	if (s_mars_ineei_1A_LOCATION != txt_mars_ineei_1A_LOCATION->value()) return true;
	if (s_mars_ineei_1A_TIME != txt_mars_ineei_1A_TIME->value()) return true;
	if (s_mars_ineei_1B_MEDFACSTS != txt_mars_ineei_1B_MEDFACSTS->value()) return true;
	if (s_mars_ineei_1C_TRNPSTS != txt_mars_ineei_1C_TRNPSTS->value()) return true;
	if (s_mars_ineei_1D_DAMAGE != txt_mars_ineei_1D_DAMAGE->value()) return true;
	if (s_mars_ineei_1E_UTILSTS != txt_mars_ineei_1E_UTILSTS->value()) return true;
	if (s_mars_ineei_1F_COMMSTS != txt_mars_ineei_1F_COMMSTS->value()) return true;
	if (s_mars_ineei_1G_INFOSRC != txt_mars_ineei_1G_INFOSRC->value()) return true;
	if (s_mars_ineei_1G_INFOTIME != txt_mars_ineei_1G_INFOTIME->value()) return true;
	if (s_mars_ineei_1H_REMARKS != txt_mars_ineei_1H_REMARKS->value()) return true;
	return false;
}

void update_mars_ineei_fields()
{
	s_mars_ineei_DE = txt_mars_ineei_DE->value();
	s_mars_ineei_NBR = txt_mars_ineei_NBR->value();
	s_mars_ineei_PREC.clear();
	s_mars_ineei_PREC = mars_ineei_precedent[sel_mars_ineei_PREC->index()];
	s_mars_ineei_DTG = txt_mars_ineei_DTG->value();
	s_mars_ineei_FMNAME = txt_mars_ineei_FMNAME->value();
	s_mars_ineei_FMCALL = txt_mars_ineei_FMCALL->value();
	s_mars_ineei_FMSTATE = txt_mars_ineei_FMSTATE->value();
	s_mars_ineei_TOPOS = txt_mars_ineei_TOPOS->value();
	s_mars_ineei_TOCALL = txt_mars_ineei_TOCALL->value();
	s_mars_ineei_TOSTATE = txt_mars_ineei_TOSTATE->value();
	s_mars_ineei_INFO1POS = txt_mars_ineei_INFO1POS->value();
	s_mars_ineei_INFO1CALL = txt_mars_ineei_INFO1CALL->value();
	s_mars_ineei_INFO1STATE = txt_mars_ineei_INFO1STATE->value();
	s_mars_ineei_INFO2POS = txt_mars_ineei_INFO2POS->value();
	s_mars_ineei_INFO2CALL = txt_mars_ineei_INFO2CALL->value();
	s_mars_ineei_INFO2STATE = txt_mars_ineei_INFO2STATE->value();
	s_mars_ineei_INFO3POS = txt_mars_ineei_INFO3POS->value();
	s_mars_ineei_INFO3CALL = txt_mars_ineei_INFO3CALL->value();
	s_mars_ineei_INFO3STATE = txt_mars_ineei_INFO3STATE->value();
	s_mars_ineei_INFO4POS = txt_mars_ineei_INFO4POS->value();
	s_mars_ineei_INFO4CALL = txt_mars_ineei_INFO4CALL->value();
	s_mars_ineei_INFO4STATE = txt_mars_ineei_INFO4STATE->value();
	s_mars_ineei_INFO5POS = txt_mars_ineei_INFO5POS->value();
	s_mars_ineei_INFO5CALL = txt_mars_ineei_INFO5CALL->value();
	s_mars_ineei_INFO5STATE = txt_mars_ineei_INFO5STATE->value();
	s_mars_ineei_INFO6POS = txt_mars_ineei_INFO6POS->value();
	s_mars_ineei_INFO6CALL = txt_mars_ineei_INFO6CALL->value();
	s_mars_ineei_INFO6STATE = txt_mars_ineei_INFO6STATE->value();
	s_mars_ineei_INFO7POS = txt_mars_ineei_INFO7POS->value();
	s_mars_ineei_INFO7CALL = txt_mars_ineei_INFO7CALL->value();
	s_mars_ineei_INFO7STATE = txt_mars_ineei_INFO7STATE->value();
	s_mars_ineei_INFO8POS = txt_mars_ineei_INFO8POS->value();
	s_mars_ineei_INFO8CALL = txt_mars_ineei_INFO8CALL->value();
	s_mars_ineei_INFO8STATE = txt_mars_ineei_INFO8STATE->value();
	s_mars_ineei_INFO9POS = txt_mars_ineei_INFO9POS->value();
	s_mars_ineei_INFO9CALL = txt_mars_ineei_INFO9CALL->value();
	s_mars_ineei_INFO9STATE = txt_mars_ineei_INFO9STATE->value();
	s_mars_ineei_INFO10POS = txt_mars_ineei_INFO10POS->value();
	s_mars_ineei_INFO10CALL = txt_mars_ineei_INFO10CALL->value();
	s_mars_ineei_INFO10STATE = txt_mars_ineei_INFO10STATE->value();
	s_mars_ineei_INCIDENT = txt_mars_ineei_INCIDENT->value();
	s_mars_ineei_REF = txt_mars_ineei_REF->value();
	s_mars_ineei_STATE = txt_mars_ineei_STATE->value();
	s_mars_ineei_1A_INCIDENT = txt_mars_ineei_1A_INCIDENT->value();
	s_mars_ineei_1A_LOCATION = txt_mars_ineei_1A_LOCATION->value();
	s_mars_ineei_1A_TIME = txt_mars_ineei_1A_TIME->value();
	s_mars_ineei_1B_MEDFACSTS = txt_mars_ineei_1B_MEDFACSTS->value();
	s_mars_ineei_1C_TRNPSTS = txt_mars_ineei_1C_TRNPSTS->value();
	s_mars_ineei_1D_DAMAGE = txt_mars_ineei_1D_DAMAGE->value();
	s_mars_ineei_1E_UTILSTS = txt_mars_ineei_1E_UTILSTS->value();
	s_mars_ineei_1F_COMMSTS = txt_mars_ineei_1F_COMMSTS->value();
	s_mars_ineei_1G_INFOSRC = txt_mars_ineei_1G_INFOSRC->value();
	s_mars_ineei_1G_INFOTIME = txt_mars_ineei_1G_INFOTIME->value();
	s_mars_ineei_1H_REMARKS = txt_mars_ineei_1H_REMARKS->value();
}

void update_mars_ineeiform()
{
	txt_mars_ineei_DE->value(s_mars_ineei_DE.c_str());
	txt_mars_ineei_NBR->value(s_mars_ineei_NBR.c_str());

	size_t n = strchr(mars_ineei_precedent, s_mars_ineei_PREC[0]) - mars_ineei_precedent;
	if (n < 0) n = 0;
	if (n > 4) n = 4;
	sel_mars_ineei_PREC->index(n);

	txt_mars_ineei_DTG->value(s_mars_ineei_DTG.c_str());
	txt_mars_ineei_FMNAME->value(s_mars_ineei_FMNAME.c_str());
	txt_mars_ineei_FMCALL->value(s_mars_ineei_FMCALL.c_str());
	txt_mars_ineei_FMSTATE->value(s_mars_ineei_FMSTATE.c_str());
	txt_mars_ineei_TOPOS->value(s_mars_ineei_TOPOS.c_str());
	txt_mars_ineei_TOCALL->value(s_mars_ineei_TOCALL.c_str());
	txt_mars_ineei_TOSTATE->value(s_mars_ineei_TOSTATE.c_str());
	txt_mars_ineei_INFO1POS->value(s_mars_ineei_INFO1POS.c_str());
	txt_mars_ineei_INFO1CALL->value(s_mars_ineei_INFO1CALL.c_str());
	txt_mars_ineei_INFO1STATE->value(s_mars_ineei_INFO1STATE.c_str());
	txt_mars_ineei_INFO2POS->value(s_mars_ineei_INFO2POS.c_str());
	txt_mars_ineei_INFO2CALL->value(s_mars_ineei_INFO2CALL.c_str());
	txt_mars_ineei_INFO2STATE->value(s_mars_ineei_INFO2STATE.c_str());
	txt_mars_ineei_INFO3POS->value(s_mars_ineei_INFO3POS.c_str());
	txt_mars_ineei_INFO3CALL->value(s_mars_ineei_INFO3CALL.c_str());
	txt_mars_ineei_INFO3STATE->value(s_mars_ineei_INFO3STATE.c_str());
	txt_mars_ineei_INFO4POS->value(s_mars_ineei_INFO4POS.c_str());
	txt_mars_ineei_INFO4CALL->value(s_mars_ineei_INFO4CALL.c_str());
	txt_mars_ineei_INFO4STATE->value(s_mars_ineei_INFO4STATE.c_str());
	txt_mars_ineei_INFO5POS->value(s_mars_ineei_INFO5POS.c_str());
	txt_mars_ineei_INFO5CALL->value(s_mars_ineei_INFO5CALL.c_str());
	txt_mars_ineei_INFO5STATE->value(s_mars_ineei_INFO5STATE.c_str());
	txt_mars_ineei_INFO6POS->value(s_mars_ineei_INFO6POS.c_str());
	txt_mars_ineei_INFO6CALL->value(s_mars_ineei_INFO6CALL.c_str());
	txt_mars_ineei_INFO6STATE->value(s_mars_ineei_INFO6STATE.c_str());
	txt_mars_ineei_INFO7POS->value(s_mars_ineei_INFO7POS.c_str());
	txt_mars_ineei_INFO7CALL->value(s_mars_ineei_INFO7CALL.c_str());
	txt_mars_ineei_INFO7STATE->value(s_mars_ineei_INFO7STATE.c_str());
	txt_mars_ineei_INFO8POS->value(s_mars_ineei_INFO8POS.c_str());
	txt_mars_ineei_INFO8CALL->value(s_mars_ineei_INFO8CALL.c_str());
	txt_mars_ineei_INFO8STATE->value(s_mars_ineei_INFO8STATE.c_str());
	txt_mars_ineei_INFO9POS->value(s_mars_ineei_INFO9POS.c_str());
	txt_mars_ineei_INFO9CALL->value(s_mars_ineei_INFO9CALL.c_str());
	txt_mars_ineei_INFO9STATE->value(s_mars_ineei_INFO9STATE.c_str());
	txt_mars_ineei_INFO10POS->value(s_mars_ineei_INFO10POS.c_str());
	txt_mars_ineei_INFO10CALL->value(s_mars_ineei_INFO10CALL.c_str());
	txt_mars_ineei_INFO10STATE->value(s_mars_ineei_INFO10STATE.c_str());
	txt_mars_ineei_INCIDENT->value(s_mars_ineei_INCIDENT.c_str());
	txt_mars_ineei_REF->value(s_mars_ineei_REF.c_str());
	txt_mars_ineei_STATE->value(s_mars_ineei_STATE.c_str());
	txt_mars_ineei_1A_INCIDENT->value(s_mars_ineei_1A_INCIDENT.c_str());
	txt_mars_ineei_1A_LOCATION->value(s_mars_ineei_1A_LOCATION.c_str());
	txt_mars_ineei_1A_TIME->value(s_mars_ineei_1A_TIME.c_str());
	txt_mars_ineei_1B_MEDFACSTS->value(s_mars_ineei_1B_MEDFACSTS.c_str());
	txt_mars_ineei_1C_TRNPSTS->value(s_mars_ineei_1C_TRNPSTS.c_str());
	txt_mars_ineei_1D_DAMAGE->value(s_mars_ineei_1D_DAMAGE.c_str());
	txt_mars_ineei_1E_UTILSTS->value(s_mars_ineei_1E_UTILSTS.c_str());
	txt_mars_ineei_1F_COMMSTS->value(s_mars_ineei_1F_COMMSTS.c_str());
	txt_mars_ineei_1G_INFOSRC->value(s_mars_ineei_1G_INFOSRC.c_str());
	txt_mars_ineei_1G_INFOTIME->value(s_mars_ineei_1G_INFOTIME.c_str());
	txt_mars_ineei_1H_REMARKS->value(s_mars_ineei_1H_REMARKS.c_str());
}

void clear_mars_ineei_form()
{
	clear_mars_ineei_fields();
	txt_mars_ineei_DE->value("");
	txt_mars_ineei_NBR->value("");
	sel_mars_ineei_PREC->index(4);
	txt_mars_ineei_DTG->value("");
	txt_mars_ineei_FMNAME->value("");
	txt_mars_ineei_FMCALL->value("");
	txt_mars_ineei_FMSTATE->value("");
	txt_mars_ineei_TOPOS->value("");
	txt_mars_ineei_TOCALL->value("");
	txt_mars_ineei_TOSTATE->value("");
	txt_mars_ineei_INFO1POS->value("");
	txt_mars_ineei_INFO1CALL->value("");
	txt_mars_ineei_INFO1STATE->value("");
	txt_mars_ineei_INFO2POS->value("");
	txt_mars_ineei_INFO2CALL->value("");
	txt_mars_ineei_INFO2STATE->value("");
	txt_mars_ineei_INFO3POS->value("");
	txt_mars_ineei_INFO3CALL->value("");
	txt_mars_ineei_INFO3STATE->value("");
	txt_mars_ineei_INFO4POS->value("");
	txt_mars_ineei_INFO4CALL->value("");
	txt_mars_ineei_INFO4STATE->value("");
	txt_mars_ineei_INFO5POS->value("");
	txt_mars_ineei_INFO5CALL->value("");
	txt_mars_ineei_INFO5STATE->value("");
	txt_mars_ineei_INFO6POS->value("");
	txt_mars_ineei_INFO6CALL->value("");
	txt_mars_ineei_INFO6STATE->value("");
	txt_mars_ineei_INFO7POS->value("");
	txt_mars_ineei_INFO7CALL->value("");
	txt_mars_ineei_INFO7STATE->value("");
	txt_mars_ineei_INFO8POS->value("");
	txt_mars_ineei_INFO8CALL->value("");
	txt_mars_ineei_INFO8STATE->value("");
	txt_mars_ineei_INFO9POS->value("");
	txt_mars_ineei_INFO9CALL->value("");
	txt_mars_ineei_INFO9STATE->value("");
	txt_mars_ineei_INFO10POS->value("");
	txt_mars_ineei_INFO10CALL->value("");
	txt_mars_ineei_INFO10STATE->value("");
	txt_mars_ineei_INCIDENT->value("");
	txt_mars_ineei_REF->value("");
	txt_mars_ineei_STATE->value("");
	txt_mars_ineei_1A_INCIDENT->value("");
	txt_mars_ineei_1A_LOCATION->value("");
	txt_mars_ineei_1A_TIME->value("");
	txt_mars_ineei_1B_MEDFACSTS->value("");
	txt_mars_ineei_1C_TRNPSTS->value("");
	txt_mars_ineei_1D_DAMAGE->value("");
	txt_mars_ineei_1E_UTILSTS->value("");
	txt_mars_ineei_1F_COMMSTS->value("");
	txt_mars_ineei_1G_INFOSRC->value("");
	txt_mars_ineei_1G_INFOTIME->value("");
	txt_mars_ineei_1H_REMARKS->value("");
}

void make_mars_ineei_buff(bool compress = false)
{
	std::string mbuff;
	mbuff.clear();
	mbuff.append( lineout( mars_ineei_DE, s_mars_ineei_DE ) );
	mbuff.append( lineout( mars_ineei_NBR, s_mars_ineei_NBR ) );
	mbuff.append( lineout( mars_ineei_PREC, s_mars_ineei_PREC ) );
	mbuff.append( lineout( mars_ineei_DTG, s_mars_ineei_DTG ) );
	mbuff.append( lineout( mars_ineei_FMNAME, s_mars_ineei_FMNAME ) );
	mbuff.append( lineout( mars_ineei_FMCALL, s_mars_ineei_FMCALL ) );
	mbuff.append( lineout( mars_ineei_FMSTATE, s_mars_ineei_FMSTATE ) );
	mbuff.append( lineout( mars_ineei_TOPOS, s_mars_ineei_TOPOS ) );
	mbuff.append( lineout( mars_ineei_TOCALL, s_mars_ineei_TOCALL ) );
	mbuff.append( lineout( mars_ineei_TOSTATE, s_mars_ineei_TOSTATE ) );
	mbuff.append( lineout( mars_ineei_INFO1POS, s_mars_ineei_INFO1POS ) );
	mbuff.append( lineout( mars_ineei_INFO1CALL, s_mars_ineei_INFO1CALL ) );
	mbuff.append( lineout( mars_ineei_INFO1STATE, s_mars_ineei_INFO1STATE ) );
	mbuff.append( lineout( mars_ineei_INFO2POS, s_mars_ineei_INFO2POS ) );
	mbuff.append( lineout( mars_ineei_INFO2CALL, s_mars_ineei_INFO2CALL ) );
	mbuff.append( lineout( mars_ineei_INFO2STATE, s_mars_ineei_INFO2STATE ) );
	mbuff.append( lineout( mars_ineei_INFO3POS, s_mars_ineei_INFO3POS ) );
	mbuff.append( lineout( mars_ineei_INFO3CALL, s_mars_ineei_INFO3CALL ) );
	mbuff.append( lineout( mars_ineei_INFO3STATE, s_mars_ineei_INFO3STATE ) );
	mbuff.append( lineout( mars_ineei_INFO4POS, s_mars_ineei_INFO4POS ) );
	mbuff.append( lineout( mars_ineei_INFO4CALL, s_mars_ineei_INFO4CALL ) );
	mbuff.append( lineout( mars_ineei_INFO4STATE, s_mars_ineei_INFO4STATE ) );
	mbuff.append( lineout( mars_ineei_INFO5POS, s_mars_ineei_INFO5POS ) );
	mbuff.append( lineout( mars_ineei_INFO5CALL, s_mars_ineei_INFO5CALL ) );
	mbuff.append( lineout( mars_ineei_INFO5STATE, s_mars_ineei_INFO5STATE ) );
	mbuff.append( lineout( mars_ineei_INFO6POS, s_mars_ineei_INFO6POS ) );
	mbuff.append( lineout( mars_ineei_INFO6CALL, s_mars_ineei_INFO6CALL ) );
	mbuff.append( lineout( mars_ineei_INFO6STATE, s_mars_ineei_INFO6STATE ) );
	mbuff.append( lineout( mars_ineei_INFO7POS, s_mars_ineei_INFO7POS ) );
	mbuff.append( lineout( mars_ineei_INFO7CALL, s_mars_ineei_INFO7CALL ) );
	mbuff.append( lineout( mars_ineei_INFO7STATE, s_mars_ineei_INFO7STATE ) );
	mbuff.append( lineout( mars_ineei_INFO8POS, s_mars_ineei_INFO8POS ) );
	mbuff.append( lineout( mars_ineei_INFO8CALL, s_mars_ineei_INFO8CALL ) );
	mbuff.append( lineout( mars_ineei_INFO8STATE, s_mars_ineei_INFO8STATE ) );
	mbuff.append( lineout( mars_ineei_INFO9POS, s_mars_ineei_INFO9POS ) );
	mbuff.append( lineout( mars_ineei_INFO9CALL, s_mars_ineei_INFO9CALL ) );
	mbuff.append( lineout( mars_ineei_INFO9STATE, s_mars_ineei_INFO9STATE ) );
	mbuff.append( lineout( mars_ineei_INFO10POS, s_mars_ineei_INFO10POS ) );
	mbuff.append( lineout( mars_ineei_INFO10CALL, s_mars_ineei_INFO10CALL ) );
	mbuff.append( lineout( mars_ineei_INFO10STATE, s_mars_ineei_INFO10STATE ) );
	mbuff.append( lineout( mars_ineei_INCIDENT, s_mars_ineei_INCIDENT ) );
	mbuff.append( lineout( mars_ineei_REF, s_mars_ineei_REF));
	mbuff.append( lineout( mars_ineei_STATE, s_mars_ineei_STATE));
	mbuff.append( lineout( mars_ineei_1A_INCIDENT, s_mars_ineei_1A_INCIDENT));
	mbuff.append( lineout( mars_ineei_1A_LOCATION, s_mars_ineei_1A_LOCATION));
	mbuff.append( lineout( mars_ineei_1A_TIME, s_mars_ineei_1A_TIME));
	mbuff.append( lineout( mars_ineei_1B_MEDFACSTS, s_mars_ineei_1B_MEDFACSTS));
	mbuff.append( lineout( mars_ineei_1C_TRNPSTS, s_mars_ineei_1C_TRNPSTS));
	mbuff.append( lineout( mars_ineei_1D_DAMAGE, s_mars_ineei_1D_DAMAGE));
	mbuff.append( lineout( mars_ineei_1E_UTILSTS, s_mars_ineei_1E_UTILSTS));
	mbuff.append( lineout( mars_ineei_1F_COMMSTS, s_mars_ineei_1F_COMMSTS));
	mbuff.append( lineout( mars_ineei_1G_INFOSRC, s_mars_ineei_1G_INFOSRC));
	mbuff.append( lineout( mars_ineei_1G_INFOTIME, s_mars_ineei_1G_INFOTIME));
	mbuff.append( lineout( mars_ineei_1H_REMARKS, s_mars_ineei_1H_REMARKS ) );

	if (compress) compress_maybe(mbuff);
	ineei_buff.append(mbuff);
}

void read_mars_ineei_buffer(std::string data)
{
	clear_mars_ineei_fields();
// search the file buffer for each of the mars_ineei fields

	s_mars_ineei_DE = findstr(data, mars_ineei_DE);
	s_mars_ineei_NBR = findstr(data, mars_ineei_NBR);
	s_mars_ineei_PREC = findstr(data, mars_ineei_PREC);
	s_mars_ineei_DTG = findstr(data, mars_ineei_DTG);
	s_mars_ineei_FMNAME = findstr(data, mars_ineei_FMNAME);
	s_mars_ineei_FMCALL = findstr(data, mars_ineei_FMCALL);
	s_mars_ineei_FMSTATE = findstr(data, mars_ineei_FMSTATE);
	s_mars_ineei_TOPOS = findstr(data, mars_ineei_TOPOS);
	s_mars_ineei_TOCALL = findstr(data, mars_ineei_TOCALL);
	s_mars_ineei_TOSTATE = findstr(data, mars_ineei_TOSTATE);
	s_mars_ineei_INFO1POS = findstr(data, mars_ineei_INFO1POS);
	s_mars_ineei_INFO1CALL = findstr(data, mars_ineei_INFO1CALL);
	s_mars_ineei_INFO1STATE = findstr(data, mars_ineei_INFO1STATE);
	s_mars_ineei_INFO2POS = findstr(data, mars_ineei_INFO2POS);
	s_mars_ineei_INFO2CALL = findstr(data, mars_ineei_INFO2CALL);
	s_mars_ineei_INFO2STATE = findstr(data, mars_ineei_INFO2STATE);
	s_mars_ineei_INFO3POS = findstr(data, mars_ineei_INFO3POS);
	s_mars_ineei_INFO3CALL = findstr(data, mars_ineei_INFO3CALL);
	s_mars_ineei_INFO3STATE = findstr(data, mars_ineei_INFO3STATE);
	s_mars_ineei_INFO4POS = findstr(data, mars_ineei_INFO4POS);
	s_mars_ineei_INFO4CALL = findstr(data, mars_ineei_INFO4CALL);
	s_mars_ineei_INFO4STATE = findstr(data, mars_ineei_INFO4STATE);
	s_mars_ineei_INFO5POS = findstr(data, mars_ineei_INFO5POS);
	s_mars_ineei_INFO5CALL = findstr(data, mars_ineei_INFO5CALL);
	s_mars_ineei_INFO5STATE = findstr(data, mars_ineei_INFO5STATE);
	s_mars_ineei_INFO6POS = findstr(data, mars_ineei_INFO6POS);
	s_mars_ineei_INFO6CALL = findstr(data, mars_ineei_INFO6CALL);
	s_mars_ineei_INFO6STATE = findstr(data, mars_ineei_INFO6STATE);
	s_mars_ineei_INFO7POS = findstr(data, mars_ineei_INFO7POS);
	s_mars_ineei_INFO7CALL = findstr(data, mars_ineei_INFO7CALL);
	s_mars_ineei_INFO7STATE = findstr(data, mars_ineei_INFO7STATE);
	s_mars_ineei_INFO8POS = findstr(data, mars_ineei_INFO8POS);
	s_mars_ineei_INFO8CALL = findstr(data, mars_ineei_INFO8CALL);
	s_mars_ineei_INFO8STATE = findstr(data, mars_ineei_INFO8STATE);
	s_mars_ineei_INFO9POS = findstr(data, mars_ineei_INFO9POS);
	s_mars_ineei_INFO9CALL = findstr(data, mars_ineei_INFO9CALL);
	s_mars_ineei_INFO9STATE = findstr(data, mars_ineei_INFO9STATE);
	s_mars_ineei_INFO10POS = findstr(data, mars_ineei_INFO10POS);
	s_mars_ineei_INFO10CALL = findstr(data, mars_ineei_INFO10CALL);
	s_mars_ineei_INFO10STATE = findstr(data, mars_ineei_INFO10STATE);
	s_mars_ineei_INCIDENT = findstr(data, mars_ineei_INCIDENT);
	s_mars_ineei_REF = findstr(data, mars_ineei_REF);
	s_mars_ineei_STATE = findstr(data, mars_ineei_STATE);
	s_mars_ineei_1A_INCIDENT = findstr(data, mars_ineei_1A_INCIDENT);
	s_mars_ineei_1A_LOCATION = findstr(data, mars_ineei_1A_LOCATION);
	s_mars_ineei_1A_TIME = findstr(data, mars_ineei_1A_TIME);
	s_mars_ineei_1B_MEDFACSTS = findstr(data, mars_ineei_1B_MEDFACSTS);
	s_mars_ineei_1C_TRNPSTS = findstr(data, mars_ineei_1C_TRNPSTS);
	s_mars_ineei_1D_DAMAGE = findstr(data, mars_ineei_1D_DAMAGE);
	s_mars_ineei_1E_UTILSTS = findstr(data, mars_ineei_1E_UTILSTS);
	s_mars_ineei_1F_COMMSTS = findstr(data, mars_ineei_1F_COMMSTS);
	s_mars_ineei_1G_INFOSRC = findstr(data, mars_ineei_1G_INFOSRC);
	s_mars_ineei_1G_INFOTIME = findstr(data, mars_ineei_1G_INFOTIME);
	s_mars_ineei_1H_REMARKS = findstr(data, mars_ineei_1H_REMARKS);

	update_mars_ineeiform();
}

void cb_mars_ineei_new()
{
	if (check_mars_ineei_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_mars_ineei_save();
		}
	}
	clear_mars_ineei_form();
	def_mars_ineei_filename = ICS_msg_dir;
	def_mars_ineei_filename.append("new").append(FMARSINEEI_EXT);
	show_filename(def_mars_ineei_filename);
	using_mars_ineei_template = false;
}

void cb_mars_ineei_import()
{
	fl_alert2("Not implemented");
}

void cb_mars_ineei_export()
{
	fl_alert2("Not implemented");
}

void cb_mars_ineei_wrap_import(std::string wrapfilename, std::string inpbuffer)
{
	clear_mars_ineei_form();
	read_mars_ineei_buffer(inpbuffer);
	def_mars_ineei_filename = ICS_msg_dir;
	def_mars_ineei_filename.append(wrapfilename);
	show_filename(def_mars_ineei_filename);
	using_mars_ineei_template = false;
}

int eval_mars_ineei_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_mars_ineei_filename).append("]");
	update_mars_ineei_fields();
	update_header(FROM);
	evalstr.append(header("<mars_ineei>"));
	ineei_buff.clear();
	make_mars_ineei_buff(true);
	if (ineei_buff.empty()) return 0;
	compress_maybe( ineei_buff );
	evalstr.append( ineei_buff );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_mars_ineei_wrap_export()
{
	if (check_mars_ineei_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_ineei_fields();

	if (base_mars_ineei_filename == std::string("new").append(FMARSINEEI_EXT) ||
		base_mars_ineei_filename == std::string("default").append(FMARSINEEI_EXT) )
		if (!cb_mars_ineei_save_as()) return;

	std::string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_ineei_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		std::string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		ineei_buff.assign(header("<mars_ineei>"));
		make_mars_ineei_buff(true);
		export_wrapfile(base_mars_ineei_filename, wrapfilename, ineei_buff, pext != ".wrap");

		ineei_buff.assign(header("<mars_ineei>"));
		make_mars_ineei_buff(false);
		write_mars_ineei(def_mars_ineei_filename);
	}
}

void cb_mars_ineei_wrap_autosend()
{
	if (check_mars_ineei_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_ineei_fields();

	if (base_mars_ineei_filename == std::string("new").append(FMARSINEEI_EXT) ||
		base_mars_ineei_filename == std::string("default").append(FMARSINEEI_EXT) )
		if (!cb_mars_ineei_save_as()) return;

	update_header(FROM);
	ineei_buff.assign(header("<mars_ineei>"));
	make_mars_ineei_buff(true);
	xfr_via_socket(base_mars_ineei_filename, ineei_buff);

	ineei_buff.assign(header("<mars_ineei>"));
	make_mars_ineei_buff(false);
	write_mars_ineei(def_mars_ineei_filename);
}

void cb_mars_ineei_load_template()
{
	std::string def_mars_ineei_filename = def_mars_ineei_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			std::string("Template file\t*").append(TMARSINEEI_EXT).c_str(),
			def_mars_ineei_filename.c_str());
	if (p) {
		clear_mars_ineei_form();
		read_data_file(p);
		def_mars_ineei_TemplateName = p;
		show_filename(def_mars_ineei_TemplateName);
		using_mars_ineei_template = true;
	}
}

void cb_mars_ineei_save_template()
{
	if (!using_mars_ineei_template) {
		cb_mars_ineei_save_as_template();
		return;
	}
	std::string def_mars_ineei_filename = def_mars_ineei_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			std::string("Template file\t*").append(TMARSINEEI_EXT).c_str(),
			def_mars_ineei_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_mars_ineei_fields();
		ineei_buff.assign(header("<mars_ineei>"));
		make_mars_ineei_buff();
		write_mars_ineei(p);
	}
}

void cb_mars_ineei_save_as_template()
{
	std::string def_mars_ineei_filename = def_mars_ineei_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			std::string("Template file\t*").append(TMARSINEEI_EXT).c_str(),
			def_mars_ineei_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_mars_ineei_TemplateName = p;
		if (strlen(pext) == 0) def_mars_ineei_TemplateName.append(TMARSINEEI_EXT);
		remove_spaces_from_filename(def_mars_ineei_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_mars_ineei_fields();
		ineei_buff.assign(header("<mars_ineei>"));
		make_mars_ineei_buff();
		write_mars_ineei(def_mars_ineei_TemplateName);

		show_filename(def_mars_ineei_TemplateName);
		using_mars_ineei_template = true;
	}
}

void cb_mars_ineei_open()
{
	const char *p = FSEL::select(
			_("Open data file"),
			std::string("ICS-net\t*").append(FMARSINEEI_EXT).c_str(),
			def_mars_ineei_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_ineei_form();
	read_data_file(p);
	using_mars_ineei_template = false;
	def_mars_ineei_filename = p;
	show_filename(def_mars_ineei_filename);
}

void write_mars_ineei(std::string s)
{
	FILE *filenet = fopen(s.c_str(), "w");
	if (!filenet) return;
	make_mars_ineei_buff();
	fwrite(ineei_buff.c_str(), ineei_buff.length(), 1, filenet);
	fclose(filenet);
}

bool cb_mars_ineei_save_as()
{
	const char *p;
	std::string newfilename;

	std::string name = named_file();
	if (!name.empty()) {
		name.append(FMARSINEEI_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_ineei_filename;

	p = FSEL::saveas(
			_("Save data file"),
			std::string("ICS-net\t*").append(FMARSINEEI_EXT).c_str(),
			newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) update_sernbr();

	const char *pext = fl_filename_ext(p);
	def_mars_ineei_filename = p;
	if (strlen(pext) == 0) def_mars_ineei_filename.append(FMARSINEEI_EXT);

	remove_spaces_from_filename(def_mars_ineei_filename);

	update_header(NEW);
	update_mars_ineei_fields();
	ineei_buff.assign(header("<mars_ineei>"));
	make_mars_ineei_buff();
	write_mars_ineei(def_mars_ineei_filename);

	using_mars_ineei_template = false;
	show_filename(def_mars_ineei_filename);
	return true;
}

void cb_mars_ineei_save()
{
	if (base_mars_ineei_filename == std::string("new").append(FMARSINEEI_EXT) || 
		base_mars_ineei_filename == std::string("default").append(FMARSINEEI_EXT) ||
		using_mars_ineei_template == true) {
		cb_mars_ineei_save_as();
		return;
	}
	if (check_mars_ineei_fields()) update_header(CHANGED);
	update_mars_ineei_fields();
	ineei_buff.assign(header("<mars_ineei>"));
	make_mars_ineei_buff();
	write_mars_ineei(def_mars_ineei_filename);

	using_mars_ineei_template = false;
}

std::string justify_remarks(std::string instr, int start_count)
{
// strip new lines
	std::string tmp = instr;
	size_t nl = 0;
	while ((nl = tmp.find("\n")) != std::string::npos)
		if (nl == tmp.length() -1)
			tmp.erase(nl,1);
		else
			tmp[nl] = ' ';
	size_t dsp = 0;
	while ((dsp = tmp.find("  ")) != std::string::npos)
		tmp.erase(dsp, 1);
	while ((dsp = tmp.find(" .")) != std::string::npos)
		tmp.erase(dsp, 1);

// limit line lengths
	int cc = start_count;
	size_t sp = 0;
	while (sp < tmp.length()) {
		if (tmp[sp] == ' ' && cc == progStatus.charcount) {
			tmp[sp] = '\n';
			cc = 0;
		} else if (cc > progStatus.charcount) { // back up to previous space
			int n = 0;
			while (sp && cc && tmp[sp] != '\n') {
				sp--; cc--;
				if (++n > 20) { // oops
					tmp.insert(sp, 1, '\n');
					cc = 0;
				} else if (tmp[sp] == ' ') {
					tmp[sp] = '\n';
					cc = 0;
				}
			}
		}
		sp++; cc++;
	}
	return tmp;
}

std::string formated_output( std::string target )
{
	std::string formnet = target;
	std::string temp;
	std::string field_str;
	std::string to_str = ":to:";
	std::string fm_str = ":fm:";
	std::string info_str = ":info:";
	std::string ref_str = ":1ref:";
	std::string onea_str = ":1a:";
	std::string oneg_str = ":1g:";

	replacestr(formnet, mars_ineei_DE, s_mars_ineei_DE);
	replacestr(formnet, mars_ineei_NBR, s_mars_ineei_NBR);
	replacestr(formnet, mars_ineei_PREC, s_mars_ineei_PREC);
	replacestr(formnet, mars_ineei_DTG, s_mars_ineei_DTG);

	field_str.clear();
	if (!s_mars_ineei_FMNAME.empty()) field_str.append(s_mars_ineei_FMNAME).append(" / ");
	if (!s_mars_ineei_FMCALL.empty()) field_str.append(s_mars_ineei_FMCALL).append(" / ");
	if (!s_mars_ineei_FMSTATE.empty()) field_str.append(s_mars_ineei_FMSTATE);
	replacestr(formnet, fm_str, field_str);

	field_str.clear();
	if (!s_mars_ineei_TOPOS.empty()) field_str.append(s_mars_ineei_TOPOS).append(" / ");
	if (!s_mars_ineei_TOCALL.empty()) field_str.append(s_mars_ineei_TOCALL).append(" / ");
	if (!s_mars_ineei_TOSTATE.empty()) field_str.append(s_mars_ineei_TOSTATE);
	replacestr(formnet, to_str, field_str);

	field_str.clear();
	if (!s_mars_ineei_INFO1CALL.empty() || !s_mars_ineei_INFO1POS.empty()) {
		field_str.append("\nINFO: ");
		if (!s_mars_ineei_INFO1POS.empty()) field_str.append(s_mars_ineei_INFO1POS).append(" / ");
		field_str.append(s_mars_ineei_INFO1CALL);
		if (!s_mars_ineei_INFO1STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO1STATE);
	}
	if (!s_mars_ineei_INFO2CALL.empty() || !s_mars_ineei_INFO2POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO2POS.empty()) field_str.append(s_mars_ineei_INFO2POS).append(" / ");
		field_str.append(s_mars_ineei_INFO2CALL);
		if (!s_mars_ineei_INFO2STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO2STATE);
	}
	if (!s_mars_ineei_INFO3CALL.empty() || !s_mars_ineei_INFO3POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO3POS.empty()) field_str.append(s_mars_ineei_INFO3POS).append(" / ");
		field_str.append(s_mars_ineei_INFO3CALL);
		if (!s_mars_ineei_INFO3STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO3STATE);
	}
	if (!s_mars_ineei_INFO4CALL.empty() || !s_mars_ineei_INFO4POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO4POS.empty()) field_str.append(s_mars_ineei_INFO4POS).append(" / ");
		field_str.append(s_mars_ineei_INFO4CALL);
		if (!s_mars_ineei_INFO4STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO4STATE);
	}
	if (!s_mars_ineei_INFO5CALL.empty() || !s_mars_ineei_INFO5POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO5POS.empty()) field_str.append(s_mars_ineei_INFO5POS).append(" / ");
		field_str.append(s_mars_ineei_INFO5CALL);
		if (!s_mars_ineei_INFO5STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO5STATE);
	}
	if (!s_mars_ineei_INFO6CALL.empty() || !s_mars_ineei_INFO6POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO6POS.empty()) field_str.append(s_mars_ineei_INFO6POS).append("/");
		field_str.append(s_mars_ineei_INFO6CALL);
		if (!s_mars_ineei_INFO6STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO6STATE);
	}
	if (!s_mars_ineei_INFO7CALL.empty() || !s_mars_ineei_INFO7POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO7POS.empty()) field_str.append(s_mars_ineei_INFO7POS).append("/");
		field_str.append(s_mars_ineei_INFO7CALL);
		if (!s_mars_ineei_INFO7STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO7STATE);
	}
	if (!s_mars_ineei_INFO8CALL.empty() || !s_mars_ineei_INFO8POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO8POS.empty()) field_str.append(s_mars_ineei_INFO8POS).append("/");
		field_str.append(s_mars_ineei_INFO8CALL);
		if (!s_mars_ineei_INFO8STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO8STATE);
	}
	if (!s_mars_ineei_INFO9CALL.empty() || !s_mars_ineei_INFO9POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO9POS.empty()) field_str.append(s_mars_ineei_INFO9POS).append("/");
		field_str.append(s_mars_ineei_INFO9CALL);
		if (!s_mars_ineei_INFO9STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO9STATE);
	}
	if (!s_mars_ineei_INFO10CALL.empty() || !s_mars_ineei_INFO10POS.empty()) {
		if (field_str.empty()) field_str.append("\nINFO: ");
		else field_str.append("\n      ");
		if (!s_mars_ineei_INFO10POS.empty()) field_str.append(s_mars_ineei_INFO10POS).append("/");
		field_str.append(s_mars_ineei_INFO10CALL);
		if (!s_mars_ineei_INFO10STATE.empty()) field_str.append(" / ").append(s_mars_ineei_INFO10STATE);
	}
	replacestr(formnet, info_str, field_str);

	replacestr(formnet, mars_ineei_INCIDENT, s_mars_ineei_INCIDENT);
	replacestr(formnet, mars_ineei_INCIDENT, s_mars_ineei_INCIDENT); // 2 in form

	field_str.clear();
	if (!s_mars_ineei_REF.empty()) field_str.append(s_mars_ineei_REF);
	if (!s_mars_ineei_STATE.empty()) field_str.append(" ").append(s_mars_ineei_STATE);
	temp = justify_remarks(field_str, strlen("1. REF EVENT IDENTIFIER: "));
	replacestr(formnet, ref_str, temp);

	field_str.clear();
	if (!s_mars_ineei_1A_INCIDENT.empty()) field_str.append(s_mars_ineei_1A_INCIDENT);
	if (!s_mars_ineei_1A_LOCATION.empty()) field_str.append(s_mars_ineei_1A_LOCATION);
	if (!s_mars_ineei_1A_TIME.empty()) field_str.append(s_mars_ineei_1A_TIME);
	temp = justify_remarks(field_str, strlen("A. INCIDENT LOCATION TIME: "));
	replacestr(formnet, onea_str, temp);

	temp = justify_remarks(s_mars_ineei_1B_MEDFACSTS, strlen("B. EMERGENCY MEDICAL:  "));
	replacestr(formnet, mars_ineei_1B_MEDFACSTS, temp);
	temp = justify_remarks(s_mars_ineei_1C_TRNPSTS, strlen("C. LOCAL TRANSPORTATION:  "));
	replacestr(formnet, mars_ineei_1C_TRNPSTS, temp);
	temp = justify_remarks(s_mars_ineei_1D_DAMAGE, strlen("D. GENERAL DAMAGE DESCRIPTION: "));
	replacestr(formnet, mars_ineei_1D_DAMAGE, temp);
	temp = justify_remarks(s_mars_ineei_1E_UTILSTS, strlen("E. UTILITY STATUS: "));
	replacestr(formnet, mars_ineei_1E_UTILSTS, temp);
	temp = justify_remarks(s_mars_ineei_1F_COMMSTS, strlen("F. COMMUNICATIONS STATUS: "));
	replacestr(formnet, mars_ineei_1F_COMMSTS, temp);

	field_str.clear();
	if (!s_mars_ineei_1G_INFOSRC.empty()) field_str.append(s_mars_ineei_1G_INFOSRC);
	if (!s_mars_ineei_1G_INFOTIME.empty()) field_str.append(" ").append(s_mars_ineei_1G_INFOTIME);
	temp = justify_remarks(field_str, strlen("G. SOURCE OF INFO: "));
	replacestr(formnet, oneg_str, temp);

	temp = justify_remarks(s_mars_ineei_1H_REMARKS, strlen("H. REMARKS: "));
	replacestr(formnet, mars_ineei_1H_REMARKS, temp);
	return formnet;
}

void cb_mars_ineei_html()
{
	std::string fname_name = fl_filename_name(def_mars_ineei_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != std::string::npos) fname_name.erase(p);

	update_mars_ineei_fields();

	std::string mars_ineei_fname = ICS_dir;
	mars_ineei_fname.append(fname_name);
	mars_ineei_fname.append(".html");

	std::string textout = formated_output( mars_ineei_html_template );

	FILE *filenet = fopen(mars_ineei_fname.c_str(), "w");
	fprintf(filenet,"%s", textout.c_str());
	fclose(filenet);

	open_url(mars_ineei_fname.c_str());
}

void cb_mars_ineei_textout()
{
	std::string mars_ineei_fname = ICS_dir;
	mars_ineei_fname.append("mars_ineei.txt");

	update_mars_ineei_fields();

	std::string textout = formated_output( mars_ineei_text_template );

	FILE *filenet = fopen(mars_ineei_fname.c_str(), "w");
	fprintf(filenet,"%s", textout.c_str());
	fclose(filenet);

	open_url(mars_ineei_fname.c_str());
}

/*
========================================================================
DE (CALL SIGN MSG NUMBER)
(PRECEDENCE) (DTG OF MSG IN Z TIME FORMAT: DYTTTTZ MON YEAR)
FM (LAST NAME/CALL SIGN ST OF SENDING STATION)
TO RD/AAA1RD MA (POSITION/CALLSIGN ST OF RECIPIENT)
INFO REOO/AAM1RE NH (POSITION/CALLSIGN ST OF INFO COPY)
INFO (POSITION/CALL SIGN ST OF INFO COPY STATION)
BT
(MARS EXERCISE OR ACTUAL INCIDENT)
SUBJECT: IN/EEI REPORT
1. REF (USE APPOPRIATE EVENT IDENTIFIER) / STATE
A. (INCIDENT & LOCATION & TIME)
B. (EMERGENCY MEDICAL FACILITY STATUS)
C. (LOCAL TRANSPORTATION STATUS)
D. (GENERAL DAMAGE CHARACTERISTICS)
E. (AREA UTILITY STATUS)
F. (COMMUNICATION STATUS)
G. (INFORMATION SOURCE/TIME)
H. (1H_REMARKS)
(MARS EXERCISE OR ACTUAL INCIDENT)
BT
/EX
NNNN
========================================================================
DE AFA5FE/T NR 1
R 061535Z OCT 2012
FM DAVE ANTRY / AFA5FE/T IL
TO: AFN2EC NY
INFO: AFD4EC SC
      AFE5EC WI
      AFF5IL IL
BT
REF. MARS EXERCISE
SUBJ. EEI REPORT
1. REF EVENT IDENTIFIER:  BLACK ICE
A. INCIDENT LOCATION TIME: ST. CLAIR COUNTY ILLINOIS
B. EMERGENCY MEDICAL:  NOT AFFECTED
C. LOCAL TRANSPORTATION:  ALL SECONDARY ROADS ICE COVERED AND IMPASSABLE
D. GENERAL DAMAGE DESCRIPTION:  MAJOR WINTER ICE STORM.  
E. UTILITY STATUS:  LOCALIZED POWER OUTAGES ARE ALREADY OCCURING.  
F. COMMUNICATIONS STATUS:  OPERATIONAL
G. SOURCE OF INFO:  ST. CLAIR COUNTY EMERGENCY SERVICES DISASTER AGENCY
OFFICAL
H. REMARKS:   SECONDARY ROADS IMPASSABLE DUE TO PLOWS CONCENTRATING ON MAIN
HIGHWAYS.  EXPECT MAIN HIGHWAYS TO BECOME IMPASSABLE AND MAJOR POWER OUTAGES
PUTTING MOST COMMUNICATIONS CENTERS ON EMERGENCY BACKUP POWER IF FORECASTED
ICE ACCUMLATIONS OF UP TO 2 INCHES DURING OVERNIGHT HOURS OCCURS.
MARS EXERCISE
BT
NNNN
*/
