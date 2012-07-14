// =====================================================================
//
// status.cxx
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


#include <iostream>
#include <fstream>
#include <string>

#include <FL/Fl_Preferences.H>

#include "status.h"
#include "config.h"
#include "flmsg.h"
#include "flmsg_dialog.h"

status progStatus = {
	50,				// int mainX;
	50,				// int mainY;

	5,				// int wpl;
	false,			// bool open_on_export;
	0,				// int  UTC
// 0: HHMM,     1: HH:MM
// 2: HHMMZ,    3: HH:MMZ
// 4: HHMM UTC, 5: HH:MM UTC
	0,				// date format 0: YYYY-MM-DD, 1: MM/DD/YY, 2: DD/MM/YY
	"",				// my_call
	"",				// my_tel
	"",				// my_name
	"",				// my_addr
	"",				// my_city
	true,			// bool sernbr_fname;
	true,			// bool call_fname;
	false,			// bool dt_fname;
	true,			// bool rgrnbr_fname;
	true,			// bool arl_desc;
	"1",			// string sernbr;
	"1",			// string rgnbr
	false,			// bool insert_x;
	RADIOGRAM,		// int tab;
	"",
	72,				// charcount
	true,			// autowordwrap
	"127.0.0.1",	// fldigi socket address
	"7322"			// fldigi socket port
};

void status::saveLastState()
{
	Fl_Preferences flmsgpref(FLMSG_dir.c_str(), "w1hkj.com",  PACKAGE_NAME);

	int mX = mainwindow->x();
	int mY = mainwindow->y();
	if (mX >= 0 && mX >= 0) {
		mainX = mX;
		mainY = mY;
	}

	flmsgpref.set("version", PACKAGE_VERSION);
	flmsgpref.set("mainx", mX);
	flmsgpref.set("mainy", mY);

	flmsgpref.set("wpl", wpl);
	flmsgpref.set("open_on_export", open_on_export);
	flmsgpref.set("utc", UTC);
	flmsgpref.set("dtformat", dtformat);
	flmsgpref.set("mycall", my_call.c_str());
	flmsgpref.set("mytel", my_tel.c_str());
	flmsgpref.set("myname", my_name.c_str());
	flmsgpref.set("myaddr", my_addr.c_str());
	flmsgpref.set("mycity", my_city.c_str());
	flmsgpref.set("sernbr", sernbr.c_str());
	flmsgpref.set("rgnbr", rgnbr.c_str());
	flmsgpref.set("sernbr_fname", sernbr_fname);
	flmsgpref.set("rgnbr_fname", rgnbr_fname);
	flmsgpref.set("arl_desc", arl_desc);
	flmsgpref.set("call_fname", call_fname);
	flmsgpref.set("dt_fname", dt_fname);

	flmsgpref.set("insert_x", insert_x);

	flmsgpref.set("charcount", charcount);
	flmsgpref.set("autowordwrap", autowordwrap);

	tab = selected_form;
	flmsgpref.set("preset_tab", tab);

	flmsgpref.set("mars_roster_file", mars_roster_file.c_str());

	flmsgpref.set("fldigi_socket_addr", socket_addr.c_str());
	flmsgpref.set("fldigi_socket_port", socket_port.c_str());
}

void status::loadLastState()
{
	Fl_Preferences flmsgpref(FLMSG_dir.c_str(), "w1hkj.com", PACKAGE_NAME);

	if (flmsgpref.entryExists("version")) {
		int i = 0;
		char *defbuffer;

		flmsgpref.get("mainx", mainX, mainX);
		flmsgpref.get("mainy", mainY, mainY);

		flmsgpref.get("wpl", wpl, wpl);
		cnt_wpl->value(wpl);
		if (flmsgpref.get("open_on_export", i, i)) open_on_export = i;

		flmsgpref.get("utc", UTC, UTC);
		btn_utc_format0->value(UTC == 0);
		btn_utc_format1->value(UTC == 1);
		btn_utc_format2->value(UTC == 2);
		btn_utc_format3->value(UTC == 3);
		btn_utc_format4->value(UTC == 4);
		btn_utc_format5->value(UTC == 5);

		flmsgpref.get("dtformat", dtformat, dtformat);
		btn_dtformat0->value(dtformat == 0);
		btn_dtformat1->value(dtformat == 1);
		btn_dtformat2->value(dtformat == 2);
		btn_dtformat3->value(dtformat == 3);
		
		flmsgpref.get("mycall", defbuffer, "");
		my_call = defbuffer; free(defbuffer);

		flmsgpref.get("mytel", defbuffer, "");
		my_tel = defbuffer; free(defbuffer);

		flmsgpref.get("myname", defbuffer, "");
		my_name = defbuffer; free(defbuffer);

		flmsgpref.get("myaddr", defbuffer, "");
		my_addr = defbuffer; free(defbuffer);

		flmsgpref.get("mycity", defbuffer, "");
		my_city = defbuffer; free(defbuffer);

		if (flmsgpref.get("sernbr", defbuffer, ""))
			sernbr = defbuffer;
		free(defbuffer);

		if (flmsgpref.get("rgnbr", defbuffer, ""))
			rgnbr = defbuffer;
		free(defbuffer);

		if (flmsgpref.get("sernbr_fname", i, i)) sernbr_fname = i;
		if (flmsgpref.get("arl_desc", i, i)) arl_desc = i;
		if (flmsgpref.get("rgnbr_fname", i, i)) rgnbr_fname = i;
		if (flmsgpref.get("call_fname", i, i)) call_fname = i;
		if (flmsgpref.get("dt_fname", i, i)) dt_fname = i;

		if (flmsgpref.get("insert_x", i, i)) insert_x = i;

		flmsgpref.get("charcount", charcount, charcount);
		if (flmsgpref.get("autowordwrap", i, autowordwrap)) autowordwrap = i;

		flmsgpref.get("preset_tab", tab, tab);

		flmsgpref.get("mars_roster_file", defbuffer, "");
		mars_roster_file = defbuffer; free(defbuffer);

		if (mars_roster_file.empty()) {
			mars_roster_file = ICS_dir;
			mars_roster_file.append("MARS_ROSTER.csv");
		}

		flmsgpref.get("fldigi_socket_addr", defbuffer, "127.0.0.1");
		socket_addr = defbuffer; free(defbuffer);

		flmsgpref.get("fldigi_socket_port", defbuffer, "7322");
		socket_port = defbuffer; free(defbuffer);

	} 
}

