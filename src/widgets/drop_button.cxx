// =====================================================================
//
// drop_button.cxx
//
// Author:    David Freese, W1HKJ
// Copyright: 2020
//
// This file is part of flmsg.
//
// This is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  It is
// copyright under the GNU General Public License.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// =====================================================================
//
// extends normal button to allow drop events
// ---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <FL/names.h>

#include "config.h"

#include "drop_button.h"

Fl_Drop_Button::Fl_Drop_Button(int x, int y, int w, int h, const char* l)
: Fl_Button(x, y, w, h, l)
{
	last_event = -1;
}

int Fl_Drop_Button::handle(int event)
{
	if (event == FL_DND_ENTER || event == FL_DND_DRAG || event == FL_DND_RELEASE) {
		last_event = event;
		return 1;
	}
	if (event == FL_PASTE) {
		do_callback();
		return 1;
	}
	return Fl_Button::handle(event);
}
