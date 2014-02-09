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

#ifndef DIRENT_CHECK_H
#define DIRENT_CHECK_H

// this tests depends on a modified FL/filename.H in the Fltk-1.3.0
// change
//#  if defined(WIN32) && !defined(__CYGWIN__) && !defined(__WATCOMC__)
// to
//#  if defined(WIN32) && !defined(__CYGWIN__) && !defined(__WATCOMC__) && !defined(__WOE32__)

#ifdef __MINGW32__
#	if FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR < 3
#		undef dirent
#		include <dirent.h>
#	else
#		include <dirent.h>
#	endif
#else
#	include <dirent.h>
#endif

#endif
