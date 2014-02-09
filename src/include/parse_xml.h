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

#ifndef XML_H
#define XML_H

#include <string>
#include <list>

using namespace std;

struct TAGS { const char *tag; void (*fp)(size_t &, string);};

extern void parse_ics(string);
extern bool qform_ics_import(string);
extern void qform_ics_export(string);

extern void parse_rg(string);
extern bool qform_rg_import(string);
extern void qform_rg_export(string);

#endif

