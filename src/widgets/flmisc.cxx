// ----------------------------------------------------------------------------
// flmisc.cxx
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

#include <config.h>

#include <string>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdarg>
#include <string>
#include <iostream>

#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Tooltip.H>

#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Return_Button.H>
#include <FL/fl_draw.H>

#include <FL/x.H>

#include "flmisc.h"
#include "pixmaps.h"

notify_dialog::notify_dialog(int X, int Y, const char* l)
	: Fl_Window(X, Y, l), icon(10, 10, 50, 50), message(70, 25, 330, 35),
	  dial(277, 70, 23, 23), button(309, 70, 90, 23, "Close"), resize_box(399, 26, 1, 1)
{
	end();

	icon.image(new Fl_Pixmap(dialog_information_48_icon));

	message.type(FL_MULTILINE_OUTPUT);
	message.box(FL_FLAT_BOX);
	message.color(FL_BACKGROUND_COLOR);

	button.callback(button_cb);
	newx = button.x();

	dial.box(FL_FLAT_BOX);
	dial.type(FL_FILL_DIAL);
	dial.selection_color(FL_DARK_RED);
	dial.angle1(180);
	dial.angle2(-180);
	dial.minimum(0.0);

	xclass(PACKAGE_TARNAME);
	resizable(resize_box);
}

notify_dialog::~notify_dialog()
{
	delete icon.image();
	Fl::remove_timeout(dial_timer, &dial);
}

int notify_dialog::handle(int event)
{
	if (event == FL_HIDE && delete_on_hide) {
		Fl::delete_widget(this);
		return 1;
	}
	else if (event == FL_PUSH) {
		dial.hide();
		return Fl_Window::handle(event);
	}
	return Fl_Window::handle(event);
}

void notify_dialog::button_cb(Fl_Widget* w, void*)
{
	w->window()->hide();
}
void notify_dialog::dial_timer(void* arg)
{
	Fl_Dial* dial = reinterpret_cast<Fl_Dial*>(arg);
	double v = dial->value();
	if (!dial->visible())
		return;
	if (v == dial->minimum())
		return dial->window()->hide();
	dial->value(dial->clamp(v - 0.05));
	return Fl::repeat_timeout(0.05, dial_timer, arg);
}

Fl_Button* notify_dialog::make_button(int W, int H)
{
	Fl_Group* cur = Fl_Group::current();
	Fl_Group::current(this);
	Fl_Button* b = 0;

	int pad = 10;
	int X = newx - pad - W;
	if (X - pad - dial.w() > 0) {
		b = new Fl_Button(newx = X, button.y(), W, H);
		dial.position(b->x() - dial.w() - pad, dial.y());
	}

	Fl_Group::current(cur);
	return b;
}

void notify_dialog::notify(const char* msg, double timeout, bool delete_on_hide_)
{
	delete_on_hide = delete_on_hide_;
	message.value(msg);
	const char* p;
	if ((p = strchr(msg, '\n'))) { // use first line as label
		std::string l(msg, p - msg);
		copy_label(l.c_str());
	}
	else
		label("Notification");

	fl_font(message.textfont(), message.textsize());
	int H = 0;
	int W = 330; // default widtth of message
	int Wmsg = 0;

	std::string smsg = msg;
	size_t pnl = 0;
	pnl = smsg.find('\n');
	while (!smsg.empty()) {
		pnl = smsg.find('\n');
		if (pnl != std::string::npos)
			Wmsg = fl_width(smsg.substr(0, pnl).c_str());
		else
			Wmsg = fl_width(smsg.c_str());
		if (pnl != std::string::npos)
			smsg.erase(0, pnl + 1);
		else
			smsg.clear();
		H++;
		if (Wmsg > W) W = Wmsg;
	}

	message.size(W, std::max(H, 1) * fl_height());

	size(w() + (W - 330), h() - 35 + std::max(H, 0) * fl_height());

	if (timeout > 0.0) {
		dial.maximum(timeout);
		dial.value(timeout);
		dial.show();
		Fl::add_timeout(0.0, dial_timer, &dial);
	}
	else
		dial.hide();
	button.take_focus();
	show();
}

