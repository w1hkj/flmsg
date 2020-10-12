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

#ifndef WRAP_H
#define WRAP_H

#include <string.h>
#include <string>

enum {BASE64, BASE128, BASE256};

extern void compress_maybe(std::string& input, bool file_transfer = false);
extern int decompress_maybe(std::string& input);

extern void export_wrapfile(std::string, std::string, std::string, bool with_ext);
extern bool import_wrapfile(std::string fname, std::string &efname, std::string &text);

extern void xfr_via_socket(std::string, std::string);

extern std::string wrap_outfilename;

extern bool b_autosend;

#endif
