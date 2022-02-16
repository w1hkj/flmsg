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

#ifndef _TRANSFER_
#define _TRANSFER_

#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Hold_Browser.H>

extern Fl_Group	*tab_transfer;
extern Fl_Output	*txt_send_filename;
extern Fl_Button	*btn_select_send;

extern Fl_Hold_Browser	*brws_xfr_filenames;
extern Fl_Button			*btn_open_rcvd;

extern std::string def_transfer_filename;

extern void create_transfer_tab();
extern void clear_transfer_form();

#endif
