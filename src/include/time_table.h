// =====================================================================
//
// 	time_table.h
//
//  Author(s):
//    Robert Stiles, KK5VD, Copyright (C) 2013
//
// This file is part of FLAMP.
//
// This is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// =====================================================================

#ifndef __TIME_TABLE_H
#define __TIME_TABLE_H

#include <config.h>
#include <string>
#include <cstring>

extern int mode_table_count(void);
extern char * modem_at_index(int index);

extern bool modem_available(std::string modem);
extern bool modem_available(char *modem, int search_limit);

extern float seconds_from_c_string(const char *mode, const char *string, int length, float *overhead);
extern float minutes_from_c_string(const char *mode, const char *string, int length, float *overhead);

extern float seconds_from_string(std::string mode, std::string& str, float *overhead);
extern float minutes_from_string(std::string mode, std::string& str, float *overhead);

#endif // __TIME_TABLE_H
