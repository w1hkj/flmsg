//
// Fl_Native_File_Chooser.cxx -- FLTK native OS file chooser widget
//
// Copyright 2004 by Greg Ercolano.
//
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

// Use Windows' chooser
#	if defined(__WIN32__) || defined(__CYGWIN__)
#	include "Fl_Native_File_Chooser_WIN32.cxx"
#	endif

// Use Apple's chooser
#	ifdef __APPLE__
#	include "Fl_Native_File_Chooser_MAC.cxx"
#	endif

// All else falls back to FLTK's own chooser
#	if ! defined(__APPLE__) && !defined(_WIN32) && !defined(__CYGWIN__)
#	include "Fl_Native_File_Chooser_FLTK.cxx"
#	endif

#else
#	ifdef __WIN32__
#	include "Fl_Native_File_Chooser_WIN32.cxx"
#	endif

#endif
