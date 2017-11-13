// =====================================================================
//
//  time_table.cxx
//
//  Author(s):
//    Robert Stiles, KK5VD, Copyright (C) 2013, 2014
//
// This file is part of FLAMP and FLMSG.
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


// Doxygen
/** ********************************************************
 \page page_modem_timing_table Modem Timing Table Structure

	A table and functions to calculate the number of seconds or
	minutes needed to transmit a string of data.

 \par char *modem_name
	The string ID of the modem.<br>
	Example:<br>
	8PSK125, 8PSK250, etc. <br>

 \par float scale
	A value used to scale the resulting toble in an attemp to adjust for
	errors. However, because of the differential errors for each charater
	and overhead time, it's not recommended for use.

 \par float overhead
 	Each modem contains a leading and trailing pre/postamble. The time for
	both a accumulated and stored in this variable.

 \par table[256]
 	Floating point representation of the amount of time it takes to
	transmit the character in seconds. Character value range 0 to 255.

 \verbatim
 	typedef struct {
		char *mode_name;
		float scale;
		float overhead;
		float table[256];
	} MODE_TIME_TABLE;

	static MODE_TIME_TABLE mode_time_table[] = {
		{
			(char *) "8PSK125", 1.0, 2.973000,
 			{
 				0.058500, 0.058875, 0.058500, 0.058500, 0.058875, 0.058500, 0.058500, 0.058875,
 				0.042500, 0.058500, 0.058875, 0.058500, 0.058500, 0.042875, 0.058500, 0.058500,
 				0.058875, 0.058500, 0.058500, 0.058875, 0.058500, 0.058500, 0.058875, 0.058500,
 				0.058500, 0.058875, 0.058500, 0.058500, 0.058875, 0.058500, 0.063625, 0.064312,
 				0.016000, 0.047625, 0.048313, 0.053437, 0.053062, 0.053437, 0.053437, 0.047625,
				...
			},...
		},...
	};

\endverbatim

 ***********************************************************/

#include "debug.h"
#include "time_table.h"
#include "time_table_dat.cxx"

static float time_length(MODE_TIME_TABLE *mTable, const char *string, int length);
static int str_cnt(char * str, int count_limit);

/** ********************************************************
 * \brief Determine the length of the string with a count
 * limitation.
 * \return signed integer. The number of characters in the
 * array not to excede count limit.
 ***********************************************************/
static int str_cnt(char * str, int count_limit)
{
	if(!str || (count_limit < 1))
		return 0;

	int value = 0;

	for(int index = 0; index < count_limit; index++) {
		if(str[index] == 0) break;
		value++;
	}

	return value;
}

/** ********************************************************
 * \brief Calulate the time it take to transmit the given
 * text with the selected modem.
 ***********************************************************/
static float time_length(MODE_TIME_TABLE *mTable, const char *string, int length)
{
	unsigned int character = 0;
	float accum = 0.0;

	while (length > 0) {
		character = (unsigned int) *string++;
		character &= 0xFF;
		accum += mTable->table[character];
		length--;
	}

	return (accum * mTable->scale);
}

/** ********************************************************
 * \brief Returns the time it take to transmit the given
 * text with the selected modem. 'C' interface.
 * \return float Duration in seconds.
 ***********************************************************/
float seconds_from_c_string(const char *mode, const char *string, int length, float *overhead)
{
	int mode_index = 0;
	int max_mode_name = 16;
	int mode_count = sizeof(mode_time_table) / sizeof(MODE_TIME_TABLE);
	static int last_mode = 0;

	if(!mode || !string || length < 1) return 0.0;

	if(strncmp(mode, mode_time_table[last_mode].mode_name, max_mode_name) == 0) {
		if(overhead) {
			*overhead = mode_time_table[last_mode].overhead;
		}
		return time_length(&mode_time_table[last_mode], string, length);
	} else {
		for(mode_index = 0; mode_index < mode_count; mode_index++) {
			if(strncmp((char *) mode, (char *) mode_time_table[mode_index].mode_name, max_mode_name) == 0) {
				last_mode = mode_index;
				if(overhead) {
					*overhead = mode_time_table[last_mode].overhead;
				}
				return time_length(&mode_time_table[mode_index], string, length);
			}
		}
	}
	return 0.0;
}

/** ********************************************************
 * \brief Returns the time it take to transmit the given
 * text with the selected modem. 'C' interface.
 * \return float Duration in minutes.
 ***********************************************************/
float minutes_from_c_string(const char *mode, const char *string, int length, float *overhead)
{
	float time = 0.0;

	time = seconds_from_c_string(mode, string, length, overhead) / 60.0;
	if(overhead)
		*overhead /= 60.0;
	return time;
}

/** ********************************************************
 * \brief Returns the time it take to transmit the given
 * text with the selected modem. 'C++' std::string interface.
 * \return float Duration in seconds.
 ***********************************************************/
float seconds_from_string(std::string mode, std::string& str, float *overhead)
{
	try {
		return seconds_from_c_string(mode.c_str(), str.c_str(), str.length(), overhead);
	} catch ( ... ) {
		LOG_ERROR("%s", "String Ref Error");
		return 0.0;
	}
}

/** ********************************************************
 * \brief Returns the time it take to transmit the given
 * text with the selected modem. 'C++' std::string interface.
 * \return float Duration in minutes.
 ***********************************************************/
float minutes_from_string(std::string mode, std::string& str, float *overhead)
{
	float time = 0.0;
	try {
		time = seconds_from_c_string(mode.c_str(), str.c_str(), str.length(), overhead) / 60.0;
		if(overhead)
			*overhead /= 60.0;
	} catch ( ... ) {
		LOG_ERROR("%s", "String Ref Error");
		return 0.0;
	}

	return time;
}


/** ********************************************************
 * \brief Search the modem table for a modem string match.
 * 'C++' std::string interface.
 * \return bool Match found = true.
 ***********************************************************/
bool modem_available(std::string modem)
{
	if(modem.empty())
		return false;
	return modem_available((char *) modem.c_str(), (int) modem.size());
}


/** ********************************************************
 * \brief Search the modem table for a modem string match.
 * 'C' interface.
 * \return bool Match found = true.
 ***********************************************************/
bool modem_available(char *modem, int search_limit)
{
	if(!modem || (search_limit < 1))
		return false;

	int mode_count = (int) sizeof(mode_time_table) / sizeof(MODE_TIME_TABLE);
	int index = 0;
	int results = 0;
	bool found = false;

	for(index = 0; index < mode_count; index++) {
		results = strncmp(modem, mode_time_table[index].mode_name, search_limit);
		if(results == 0) {
			results = str_cnt(mode_time_table[index].mode_name, 16);
			if(results == search_limit) {
				found = true;
				break;
			}
		}
	}

	return found;
}

/** ********************************************************
 * \brief Return the number of table entires.
 * \return integer
 ***********************************************************/
int mode_table_count(void)
{
	return (int) sizeof(mode_time_table) / sizeof(MODE_TIME_TABLE);
}

/** ********************************************************
 * \brief Return modem ID string at position 'x' in the
 * Table.
 * \return char *.
 ***********************************************************/
char * modem_at_index(int index)
{
	static char modem_name[] = "Bad Index";

	int index_limit = mode_table_count();

	if(index < 0 || index >= index_limit)
		return (char *) &modem_name[0];

	return (char *) mode_time_table[index].mode_name;
}

