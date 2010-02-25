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

status progStatus = {
	50,			// int mainX;
	50,			// int mainY;

	false,		// bool compression;
	true		// bool UTC
};

void status::saveLastState()
{
	Fl_Preferences flicspref(ICS_dir.c_str(), "w1hkj.com",  PACKAGE_NAME);

	int mX = mainwindow->x();
	int mY = mainwindow->y();
	if (mX >= 0 && mX >= 0) {
		mainX = mX;
		mainY = mY;
	}

	flicspref.set("version", PACKAGE_VERSION);
	flicspref.set("mainx", mX);
	flicspref.set("mainy", mY);

	flicspref.set("compression", compression);
	flicspref.set("utc", UTC);
}

void status::loadLastState()
{
	Fl_Preferences flicspref(ICS_dir.c_str(), "w1hkj.com", PACKAGE_NAME);

	if (flicspref.entryExists("version")) {

		int i;

		flicspref.get("mainx", mainX, mainX);
		flicspref.get("mainy", mainY, mainY);

		if (flicspref.get("compression", i, i)) compression = i;
		if (flicspref.get("utc", i, i)) UTC = i;
	}
}

