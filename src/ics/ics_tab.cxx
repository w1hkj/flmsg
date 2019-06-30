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

#include "gettext.h"
#include "status.h"
#include "util.h"

#include "flmsg_dialog.h"
#include "flmsg.h"

void ics_changed(Fl_Widget *, void *)
{
	estimate();
}

Fl_Group *ics_tabs = (Fl_Group *) 0;

void create_ics_tab()
{ 
	create_ics203_tab();
	create_ics205_tab();
	create_ics205a_tab();
	create_ics206_tab();
	create_ics213_tab();
	create_ics214_tab();
	create_ics216_tab();
	create_ics309_tab();
}
