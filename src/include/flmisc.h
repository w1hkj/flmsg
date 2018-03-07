// ----------------------------------------------------------------------------
// flmisc.h
//
// Copyright (C) 2018
//		David Freese, W1HKJ
//
// This file is part of flmsg.
//
// Fldigi is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Fldigi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with fldigi.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#ifndef fl_misc_h_
#define fl_misc_h_

#include <config.h>

#include <FL/Enumerations.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Return_Button.H>
#include "flinput2.h"

class notify_dialog : public Fl_Window
{
	Fl_Box icon;
	Fl_Input2 message;
	Fl_Dial dial;
	Fl_Return_Button button;
	Fl_Box resize_box;
	bool delete_on_hide;

public:
	notify_dialog(int X = 410, int Y = 103, const char* l = 0);
	~notify_dialog();
	int handle(int event);
	Fl_Button* make_button(int W, int H = 23);
	void notify(const char* msg, double timeout, bool delete_on_hide_ = false);
private:
	static void button_cb(Fl_Widget* w, void*);
	static void dial_timer(void* arg);
	int newx;
};

#endif // fl_misc_h_
