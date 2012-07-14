// =====================================================================
//
// mars_ineei.cxx
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

const char mars_ineei_precedent[] = "RPIFM";

string ineei_buff;
string def_mars_ineei_filename = "";
string base_mars_ineei_filename = "";
string def_mars_ineei_TemplateName = "";
bool using_mars_ineei_template = false;

/*
========================================================================
DE (CALL SIGN MSG NUMBER)
(PRECEDENCE) (DTG OF MSG IN Z TIME FORMAT: DYTTTTZ MON YEAR)
FM (LAST NAME/CALL SIGN ST OF SENDING STATION)
TO RD/AAA1RD MA (POSITION/CALL SIGN ST OF RECIPIENT)
INFO REOO/AAM1RE NH (POSITION/CALL SIGN ST OF INFO COPY)
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
*/

// mars_ineei fields

string mars_ineei_DE			= ":de:";
string mars_ineei_NBR			= ":nbr:";
string mars_ineei_PREC			= ":prec:";
string mars_ineei_DTG			= ":dtg:";
string mars_ineei_FMNAME		= ":fmname:";
string mars_ineei_FMCALL		= ":fmcall:";
string mars_ineei_FMSTATE		= ":fmstate:";
string mars_ineei_TOPOS			= ":topos:";
string mars_ineei_TOCALL		= ":tocall:";
string mars_ineei_TOSTATE		= ":tostate:";
string mars_ineei_INFO1POS		= ":info1pos:";
string mars_ineei_INFO1CALL		= ":info1call:";
string mars_ineei_INFO1STATE	= ":info1state:";
string mars_ineei_INFO2POS		= ":info2pos:";
string mars_ineei_INFO2CALL		= ":info2call:";
string mars_ineei_INFO2STATE	= ":info2state:";
string mars_ineei_INCIDENT		= ":incident:";
string mars_ineei_REF			= ":ref:";
string mars_ineei_STATE			= ":state:";
string mars_ineei_1A_INCIDENT	= ":1a_incident:";
string mars_ineei_1A_LOCATION	= ":1a_location:";
string mars_ineei_1A_TIME		= ":1a_time:";
string mars_ineei_1B_MEDFACSTS	= ":1b_medfacsts:";
string mars_ineei_1C_TRNPSTS	= ":1c_trnpsts:";
string mars_ineei_1D_DAMAGE		= ":1d_damage:";
string mars_ineei_1E_UTILSTS	= ":1e_utilsts:";
string mars_ineei_1F_COMMSTS	= ":1f_commsts:";
string mars_ineei_1G_INFOSRC	= ":1g_infosrc:";
string mars_ineei_1G_INFOTIME	= ":1g_infotime:";
string mars_ineei_1H_REMARKS	= ":1h_remarks:";

string s_mars_ineei_DE;
string s_mars_ineei_NBR;
string s_mars_ineei_PREC = "R";
string s_mars_ineei_DTG;
string s_mars_ineei_FMNAME;
string s_mars_ineei_FMCALL;
string s_mars_ineei_FMSTATE;
string s_mars_ineei_TOPOS;
string s_mars_ineei_TOCALL;
string s_mars_ineei_TOSTATE;
string s_mars_ineei_INFO1POS;
string s_mars_ineei_INFO1CALL;
string s_mars_ineei_INFO1STATE;
string s_mars_ineei_INFO2POS;
string s_mars_ineei_INFO2CALL;
string s_mars_ineei_INFO2STATE;
string s_mars_ineei_INCIDENT;
string s_mars_ineei_REF;
string s_mars_ineei_STATE;
string s_mars_ineei_1A_INCIDENT;
string s_mars_ineei_1A_LOCATION;
string s_mars_ineei_1A_TIME;
string s_mars_ineei_1B_MEDFACSTS;
string s_mars_ineei_1C_TRNPSTS;
string s_mars_ineei_1D_DAMAGE;
string s_mars_ineei_1E_UTILSTS;
string s_mars_ineei_1F_COMMSTS;
string s_mars_ineei_1G_INFOSRC;
string s_mars_ineei_1G_INFOTIME;
string s_mars_ineei_1H_REMARKS;

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
	string temp;
	if (s_mars_ineei_DE != txt_mars_ineei_DE->value()) return true;
	if (s_mars_ineei_NBR != txt_mars_ineei_NBR->value()) return true;
	temp = mars_ineei_precedent[sel_mars_ineei_PREC->value()];
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
	s_mars_ineei_PREC = mars_ineei_precedent[sel_mars_ineei_PREC->value()];
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
	sel_mars_ineei_PREC->value(n);

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
	sel_mars_ineei_PREC->value(4);
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

void make_mars_ineei_buff()
{
	ineei_buff.append( lineout( mars_ineei_DE, s_mars_ineei_DE ) );
	ineei_buff.append( lineout( mars_ineei_NBR, s_mars_ineei_NBR ) );
	ineei_buff.append( lineout( mars_ineei_PREC, s_mars_ineei_PREC ) );
	ineei_buff.append( lineout( mars_ineei_DTG, s_mars_ineei_DTG ) );
	ineei_buff.append( lineout( mars_ineei_FMNAME, s_mars_ineei_FMNAME ) );
	ineei_buff.append( lineout( mars_ineei_FMCALL, s_mars_ineei_FMCALL ) );
	ineei_buff.append( lineout( mars_ineei_FMSTATE, s_mars_ineei_FMSTATE ) );
	ineei_buff.append( lineout( mars_ineei_TOPOS, s_mars_ineei_TOPOS ) );
	ineei_buff.append( lineout( mars_ineei_TOCALL, s_mars_ineei_TOCALL ) );
	ineei_buff.append( lineout( mars_ineei_TOSTATE, s_mars_ineei_TOSTATE ) );
	ineei_buff.append( lineout( mars_ineei_INFO1POS, s_mars_ineei_INFO1POS ) );
	ineei_buff.append( lineout( mars_ineei_INFO1CALL, s_mars_ineei_INFO1CALL ) );
	ineei_buff.append( lineout( mars_ineei_INFO1STATE, s_mars_ineei_INFO1STATE ) );
	ineei_buff.append( lineout( mars_ineei_INFO2POS, s_mars_ineei_INFO2POS ) );
	ineei_buff.append( lineout( mars_ineei_INFO2CALL, s_mars_ineei_INFO2CALL ) );
	ineei_buff.append( lineout( mars_ineei_INFO2STATE, s_mars_ineei_INFO2STATE ) );
	ineei_buff.append( lineout( mars_ineei_INCIDENT, s_mars_ineei_INCIDENT ) );
	ineei_buff.append( lineout( mars_ineei_REF, s_mars_ineei_REF));
	ineei_buff.append( lineout( mars_ineei_STATE, s_mars_ineei_STATE));
	ineei_buff.append( lineout( mars_ineei_1A_INCIDENT, s_mars_ineei_1A_INCIDENT));
	ineei_buff.append( lineout( mars_ineei_1A_LOCATION, s_mars_ineei_1A_LOCATION));
	ineei_buff.append( lineout( mars_ineei_1A_TIME, s_mars_ineei_1A_TIME));
	ineei_buff.append( lineout( mars_ineei_1B_MEDFACSTS, s_mars_ineei_1B_MEDFACSTS));
	ineei_buff.append( lineout( mars_ineei_1C_TRNPSTS, s_mars_ineei_1C_TRNPSTS));
	ineei_buff.append( lineout( mars_ineei_1D_DAMAGE, s_mars_ineei_1D_DAMAGE));
	ineei_buff.append( lineout( mars_ineei_1E_UTILSTS, s_mars_ineei_1E_UTILSTS));
	ineei_buff.append( lineout( mars_ineei_1F_COMMSTS, s_mars_ineei_1F_COMMSTS));
	ineei_buff.append( lineout( mars_ineei_1G_INFOSRC, s_mars_ineei_1G_INFOSRC));
	ineei_buff.append( lineout( mars_ineei_1G_INFOTIME, s_mars_ineei_1G_INFOTIME));
	ineei_buff.append( lineout( mars_ineei_1H_REMARKS, s_mars_ineei_1H_REMARKS ) );
}

void read_mars_ineei_buffer(string data)
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
	def_mars_ineei_filename.append("new"FMARSINEEI_EXT);
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

void cb_mars_ineei_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_mars_ineei_form();
	read_mars_ineei_buffer(inpbuffer);
	def_mars_ineei_filename = ICS_msg_dir;
	def_mars_ineei_filename.append(wrapfilename);
	show_filename(def_mars_ineei_filename);
	using_mars_ineei_template = false;
}

void cb_mars_ineei_wrap_export()
{
	if (check_mars_ineei_fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_mars_ineei_fields();

	if (base_mars_ineei_filename == "new"FMARSINEEI_EXT || base_mars_ineei_filename == "default"FMARSINEEI_EXT)
		if (!cb_mars_ineei_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_mars_ineei_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		ineei_buff.assign(header("<mars_ineei>"));
		make_mars_ineei_buff();
		export_wrapfile(base_mars_ineei_filename, wrapfilename, ineei_buff, pext != ".wrap");
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

	if (base_mars_ineei_filename == "new"FMARSINEEI_EXT || base_mars_ineei_filename == "default"FMARSINEEI_EXT)
		if (!cb_mars_ineei_save_as()) return;

	update_header(FROM);
	ineei_buff.assign(header("<mars_ineei>"));
	make_mars_ineei_buff();

	xfr_via_socket(base_mars_ineei_filename, ineei_buff);
	write_mars_ineei(def_mars_ineei_filename);
}

void cb_mars_ineei_load_template()
{
	string def_mars_ineei_filename = def_mars_ineei_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"TMARSINEEI_EXT,
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
	string def_mars_ineei_filename = def_mars_ineei_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"TMARSINEEI_EXT,
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
	string def_mars_ineei_filename = def_mars_ineei_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"TMARSINEEI_EXT,
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
	const char *p = FSEL::select(_("Open data file"), "ICS-net\t*"FMARSINEEI_EXT,
					def_mars_ineei_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_mars_ineei_form();
	read_data_file(p);
	using_mars_ineei_template = false;
	def_mars_ineei_filename = p;
	show_filename(def_mars_ineei_filename);
}

void write_mars_ineei(string s)
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
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FMARSINEEI_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_mars_ineei_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-net\t*"FMARSINEEI_EXT,
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
	if (base_mars_ineei_filename == "new"FMARSINEEI_EXT || 
		base_mars_ineei_filename == "default"FMARSINEEI_EXT ||
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

void cb_mars_ineei_html()
{
	string fname_name = fl_filename_name(def_mars_ineei_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	update_mars_ineei_fields();

	string mars_ineei_fname = ICS_dir;
	mars_ineei_fname.append(fname_name);
	mars_ineei_fname.append(".html");

	string formnet = mars_ineei_html_template;

	replacestr(formnet, mars_ineei_DE, s_mars_ineei_DE);
	replacestr(formnet, mars_ineei_NBR, s_mars_ineei_NBR);
	replacestr(formnet, mars_ineei_PREC, s_mars_ineei_PREC);
	replacestr(formnet, mars_ineei_DTG, s_mars_ineei_DTG);
	replacestr(formnet, mars_ineei_FMNAME, s_mars_ineei_FMNAME);
	replacestr(formnet, mars_ineei_FMCALL, s_mars_ineei_FMCALL);
	replacestr(formnet, mars_ineei_FMSTATE, s_mars_ineei_FMSTATE);
	replacestr(formnet, mars_ineei_TOPOS, s_mars_ineei_TOPOS);
	replacestr(formnet, mars_ineei_TOCALL, s_mars_ineei_TOCALL);
	replacestr(formnet, mars_ineei_TOSTATE, s_mars_ineei_TOSTATE);
	replacestr(formnet, mars_ineei_INFO1POS, s_mars_ineei_INFO1POS);
	replacestr(formnet, mars_ineei_INFO1CALL, s_mars_ineei_INFO1CALL);
	replacestr(formnet, mars_ineei_INFO1STATE, s_mars_ineei_INFO1STATE);
	replacestr(formnet, mars_ineei_INFO2POS, s_mars_ineei_INFO2POS);
	replacestr(formnet, mars_ineei_INFO2CALL, s_mars_ineei_INFO2CALL);
	replacestr(formnet, mars_ineei_INFO2STATE, s_mars_ineei_INFO2STATE);
	replacestr(formnet, mars_ineei_INCIDENT, s_mars_ineei_INCIDENT);
	replacestr(formnet, mars_ineei_INCIDENT, s_mars_ineei_INCIDENT); // 2 in form
	replacestr(formnet, mars_ineei_REF, s_mars_ineei_REF);
	replacestr(formnet, mars_ineei_STATE, s_mars_ineei_STATE);
	replacestr(formnet, mars_ineei_1A_INCIDENT, s_mars_ineei_1A_INCIDENT);
	replacestr(formnet, mars_ineei_1A_LOCATION, s_mars_ineei_1A_LOCATION);
	replacestr(formnet, mars_ineei_1A_TIME, s_mars_ineei_1A_TIME);
	replacestr(formnet, mars_ineei_1B_MEDFACSTS, s_mars_ineei_1B_MEDFACSTS);
	replacestr(formnet, mars_ineei_1C_TRNPSTS, s_mars_ineei_1C_TRNPSTS);
	replacestr(formnet, mars_ineei_1D_DAMAGE, s_mars_ineei_1D_DAMAGE);
	replacestr(formnet, mars_ineei_1E_UTILSTS, s_mars_ineei_1E_UTILSTS);
	replacestr(formnet, mars_ineei_1F_COMMSTS, s_mars_ineei_1F_COMMSTS);
	replacestr(formnet, mars_ineei_1G_INFOSRC, s_mars_ineei_1G_INFOSRC);
	replacestr(formnet, mars_ineei_1G_INFOTIME, s_mars_ineei_1G_INFOTIME);
	replacestr(formnet, mars_ineei_1H_REMARKS, s_mars_ineei_1H_REMARKS);

	FILE *filenet = fopen(mars_ineei_fname.c_str(), "w");
	fprintf(filenet,"%s", formnet.c_str());
	fclose(filenet);

	open_url(mars_ineei_fname.c_str());
}

void cb_mars_ineei_textout()
{
	string temp = "";
	string mars_ineei_fname = ICS_dir;
	mars_ineei_fname.append("mars_ineei.txt");

	update_mars_ineei_fields();

	string formnet = mars_ineei_text_template;

	replacestr(formnet, mars_ineei_DE, s_mars_ineei_DE);
	replacestr(formnet, mars_ineei_NBR, s_mars_ineei_NBR);
	replacestr(formnet, mars_ineei_PREC, s_mars_ineei_PREC);
	replacestr(formnet, mars_ineei_DTG, s_mars_ineei_DTG);
	replacestr(formnet, mars_ineei_FMNAME, s_mars_ineei_FMNAME);
	replacestr(formnet, mars_ineei_FMCALL, s_mars_ineei_FMCALL);
	replacestr(formnet, mars_ineei_FMSTATE, s_mars_ineei_FMSTATE);
	replacestr(formnet, mars_ineei_TOPOS, s_mars_ineei_TOPOS);
	replacestr(formnet, mars_ineei_TOCALL, s_mars_ineei_TOCALL);
	replacestr(formnet, mars_ineei_TOSTATE, s_mars_ineei_TOSTATE);
	replacestr(formnet, mars_ineei_INFO1POS, s_mars_ineei_INFO1POS);
	replacestr(formnet, mars_ineei_INFO1CALL, s_mars_ineei_INFO1CALL);
	replacestr(formnet, mars_ineei_INFO1STATE, s_mars_ineei_INFO1STATE);
	replacestr(formnet, mars_ineei_INFO2POS, s_mars_ineei_INFO2POS);
	replacestr(formnet, mars_ineei_INFO2CALL, s_mars_ineei_INFO2CALL);
	replacestr(formnet, mars_ineei_INFO2STATE, s_mars_ineei_INFO2STATE);
	replacestr(formnet, mars_ineei_INCIDENT, s_mars_ineei_INCIDENT);
	replacestr(formnet, mars_ineei_INCIDENT, s_mars_ineei_INCIDENT); // 2 in form
	replacestr(formnet, mars_ineei_REF, s_mars_ineei_REF);
	replacestr(formnet, mars_ineei_STATE, s_mars_ineei_STATE);
	replacestr(formnet, mars_ineei_1A_INCIDENT, s_mars_ineei_1A_INCIDENT);
	replacestr(formnet, mars_ineei_1A_LOCATION, s_mars_ineei_1A_LOCATION);
	replacestr(formnet, mars_ineei_1A_TIME, s_mars_ineei_1A_TIME);
	replacestr(formnet, mars_ineei_1B_MEDFACSTS, s_mars_ineei_1B_MEDFACSTS);
	replacestr(formnet, mars_ineei_1C_TRNPSTS, s_mars_ineei_1C_TRNPSTS);
	replacestr(formnet, mars_ineei_1D_DAMAGE, s_mars_ineei_1D_DAMAGE);
	replacestr(formnet, mars_ineei_1E_UTILSTS, s_mars_ineei_1E_UTILSTS);
	replacestr(formnet, mars_ineei_1F_COMMSTS, s_mars_ineei_1F_COMMSTS);
	replacestr(formnet, mars_ineei_1G_INFOSRC, s_mars_ineei_1G_INFOSRC);
	replacestr(formnet, mars_ineei_1G_INFOTIME, s_mars_ineei_1G_INFOTIME);
	replacestr(formnet, mars_ineei_1H_REMARKS, s_mars_ineei_1H_REMARKS);

	FILE *filenet = fopen(mars_ineei_fname.c_str(), "w");
	fprintf(filenet,"%s", formnet.c_str());
	fclose(filenet);

	open_url(mars_ineei_fname.c_str());
}

