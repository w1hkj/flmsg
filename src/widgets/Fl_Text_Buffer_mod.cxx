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

#include <config.h>

#if FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR < 3
#  include "Fl_Text_Buffer_mod_1_1.cxx"
#elif FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR == 3
#  include "Fl_Text_Buffer_mod_1_3.cxx"
#endif
