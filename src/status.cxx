/* -----------------------------------------------------------------------------
 * status structure / methods
 *
 * A part of "rig", a rig control program compatible with fldigi / xmlrpc i/o
 *
 * copyright Dave Freese 2009, w1hkj@w1hkj.com
 *
*/

#include <iostream>
#include <fstream>
#include <string>

#include <FL/Fl_Preferences.H>

#include "status.h"
#include "config.h"
#include "ics213.h"
#include "flmsg_dialog.h"

status progStatus = {
	50,			// int mainX;
	50,			// int mainY;

	5,			// int wpl;
	false,		// bool compression;
	true,		// bool UTC
	0			// date format 0: YYYY-MM-DD, 1: MM/DD/YY, 2: DD/MM/YY
};

void status::saveLastState()
{
	Fl_Preferences flmsgpref(ICS_dir.c_str(), "w1hkj.com",  PACKAGE_NAME);

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
	flmsgpref.set("compression", compression);
	flmsgpref.set("utc", UTC);
	flmsgpref.set("dtformat", dtformat);
}

void status::loadLastState()
{
	Fl_Preferences flmsgpref(ICS_dir.c_str(), "w1hkj.com", PACKAGE_NAME);

	if (flmsgpref.entryExists("version")) {

		int i;

		flmsgpref.get("mainx", mainX, mainX);
		flmsgpref.get("mainy", mainY, mainY);

		flmsgpref.get("wpl", wpl, wpl);
		cnt_wpl->value(wpl);
		if (flmsgpref.get("compression", i, i)) compression = i;
		if (flmsgpref.get("utc", i, i)) UTC = i;
		flmsgpref.get("dtformat", dtformat, dtformat);
		btn_dtformat0->value(0);
		btn_dtformat1->value(0);
		btn_dtformat2->value(0);
		switch (dtformat) {
			case 1:
				btn_dtformat0->value(1);
				break;
			case 2:
				btn_dtformat1->value(1);
				break;
			case 0:
			default:
				btn_dtformat2->value(1);
				break;
		}
	}
}

