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

//======================================================================
// external weather std::string arrays
//======================================================================
#ifndef WX_STRINGS_H
#define WX_STRINGS_H

#include <string>

extern const std::string counties;
extern const std::string states[];
extern int numstates;
extern const std::string hail_size[];
extern int num_hail_size;
extern const std::string tzones[];
extern int num_tzones;
extern const std::string us_tzones[];
extern int num_us_tzones;

extern const std::string flood_categories[];
extern int num_flood_categories;
extern const std::string hail_size[];
extern int num_hail_size;
extern const std::string wind_speeds[];
extern int num_wind_speeds;
extern const std::string damage[];
extern int num_damage;
extern const std::string snow_tot[];
extern int num_snow_tot;
extern const std::string snow_dur[];
extern int num_snow_dur;
extern const std::string ice_tot[];
extern int num_ice_tot;
extern const std::string ice_dur[];
extern int num_ice_dur;
extern const std::string rainfall[];
extern int num_rainfall;
extern const std::string rainfall_dur[];
extern int num_rainfall_dur;
extern const std::string profiles[];
extern int num_profiles;
extern const std::string tornado_categories[];
extern int num_tornado_categories;

#endif
