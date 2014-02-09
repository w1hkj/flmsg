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

#ifndef FILESELECT_H
#define FILESELECT_H

#include <config.h>

//#ifdef __WIN32__
//#  define FSEL_THREAD 1
//#endif
//#define FSEL_THREAD 0

#if FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR < 3
	class Fl_Native_File_Chooser;
#else
	#ifdef __WIN_32
		class Fl_Native_File_Chooser;
	#else
		#include <FL/Fl_Native_File_Chooser.H>
	#endif
#endif

namespace FSEL {

	void create(void);
	void destroy(void);
	const char* select(const char* title, const char* filter, const char* def = 0);
	const char* saveas(const char* title, const char* filter, const char* def = 0);
	const char* dir_select(const char* title, const char* filter, const char* def = 0);

}

#endif // FILESELECT_H
