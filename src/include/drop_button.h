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

#ifndef FL_DROP_BUTTON_
#define FL_DROP_BUTTON_

#include "config.h"

#include <FL/Fl.H>
#include <FL/Fl_Button.H>

class Fl_Drop_Button : public Fl_Button
{
	int last_event;
public:
	Fl_Drop_Button(int x, int y, int w, int h, const char* l = 0);
	int handle(int event);
};

#endif // FL_DROP_BUTTON_
