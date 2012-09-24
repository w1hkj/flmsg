// =====================================================================
//
// redx_5739.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2010
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  It is
// copyright under the GNU General Public License.
//
// You should have received a copy of the GNU General Public License
// along with the program; if not, write to the Free Software
// Foundation, Inc.
// 59 Temple Place, Suite 330
// Boston, MA  02111-1307 USA
//
// =====================================================================

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/x.H>
#include <FL/Fl_Help_Dialog.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_File_Icon.H>

#include "config.h"
#include "flmsg_config.h"

#include "flmsg.h"
#include "templates.h"
#include "debug.h"
#include "util.h"
#include "gettext.h"
#include "flmsg_dialog.h"
#include "flinput2.h"
#include "date.h"
#include "calendar.h"
#include "icons.h"
#include "fileselect.h"
#include "wrap.h"
#include "status.h"
#include "parse_xml.h"

#ifdef WIN32
#  include "flmsgrc.h"
#  include "compat.h"
#  define dirent fl_dirent_no_thanks
#endif

#include <FL/filename.H>
#include "dirent-check.h"

#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Image.H>

using namespace std;

string s_redx_5739_nbr;
string s_redx_5739_name;
string s_redx_5739_state;
string s_redx_5739_cnty;
string s_redx_5739_city;
string s_redx_5739_date;
string s_redx_5739_street;
string s_redx_5739_georef;
string s_redx_5739_add_info;
string s_redx_5739_worker;
string s_redx_5739_supervisor;

int    sf_destroyed;
int    sf_major;
int    sf_minor;
int    sf_affected;
int    sf_inaccessible;
int    mh_destroyed;
int    mh_major;
int    mh_minor;
int    mh_affected;
int    mh_inaccessible;
int    ap_destroyed;
int    ap_major;
int    ap_minor;
int    ap_affected;
int    ap_inaccessible;

string s_redx_5739_house_nbr[10];
string s_redx_5739_apt_nbr[10];
char   c_redx_5739_destroyed[10];
char   c_redx_5739_major[10];
char   c_redx_5739_minor[10];
char   c_redx_5739_affected[10];
char   c_redx_5739_inaccessible[10];
int    i_redx_5739_floors[10];
bool   b_redx_5739_basement[10];
int    i_redx_5739_waterlevel[10];
int    i_redx_5739_basement_water[10];
bool   b_redx_5739_electricity[10];
char   c_redx_5739_occupancy[10];
bool   b_redx_5739_OR[10];
bool   b_redx_5739_901[10];
string s_redx_5739_desc[10];
string s_redx_5739_nam[10];

// could not use real names ... WIN32 barfs
enum QTYPE { B, S, T, I, F, C, E }; 
// bool, string, text, int, float, character, empty

struct QUAD { 
	QTYPE  qtype;  // type of field
	string htmnbr;
	void   *ptr;
	Fl_Widget *widget; };

// singular entries in form
QUAD redx_QUAD[] = {
{ S,	":nbr:",		&s_redx_5739_nbr,				rdx_5739_nbr },			// 0
{ S,	":name:",		&s_redx_5739_name,				rdx_5739_name },		// 1
{ S,	":state:",		&s_redx_5739_state,				rdx_5739_state },		// 2
{ S,	":cnty:",		&s_redx_5739_cnty,				rdx_5739_cnty },		// 3
{ S,	":city:",		&s_redx_5739_city,				rdx_5739_city },		// 4
{ S,	":date:",		&s_redx_5739_date,				rdx_5739_date },		// 5
{ S,	":street:",		&s_redx_5739_street,			rdx_5739_street },		// 6
{ S,	":georef:",		&s_redx_5739_georef,			rdx_5739_georef },		// 7

{ I,	":sf_des:",		&sf_destroyed,					rdx_sf_destroyed },		// 8
{ I,	":sf_maj:",		&sf_major,						rdx_sf_major },			// 9
{ I,	":sf_min:",		&sf_minor,						rdx_sf_minor },			// 10
{ I,	":sf_aff:",		&sf_affected,					rdx_sf_affected },		// 11
{ I,	":sf_ina:",		&sf_inaccessible,				rdx_sf_inaccessible },	// 12

{ I,	":mh_des:",		&mh_destroyed,					rdx_mh_destroyed },		// 13
{ I,	":mh_maj:",		&mh_major,						rdx_mh_major },			// 14
{ I,	":mh_min:",		&mh_minor,						rdx_mh_minor },			// 15
{ I,	":mh_aff:",		&mh_affected,					rdx_mh_affected },		// 16
{ I,	":mh_ina:",		&mh_inaccessible,				rdx_mh_inaccessible },	// 17

{ I,	":ap_des:",		&ap_destroyed,					rdx_ap_destroyed },		// 18
{ I,	":ap_maj:",		&ap_major,						rdx_ap_major },			// 19
{ I,	":ap_min:",		&ap_minor,						rdx_ap_minor },			// 20
{ I,	":ap_aff:",		&ap_affected,					rdx_ap_affected },		// 21
{ I,	":ap_ina:",		&ap_inaccessible,				rdx_ap_inaccessible },	// 22

{ T,	":addinf:",		&s_redx_5739_add_info,			rdx_5739_add_info },	// 23
{ S,	":worker:",		&s_redx_5739_worker,			rdx_5739_worker },			// 24
{ S,	":supervisor:",	&s_redx_5739_supervisor,		rdx_5739_supervisor },		// 25

{ E,	"",				NULL,							NULL }
};

// array entries in form
QUAD redx_QUAD1[] = {
{ S,	":hb[0]:",		&s_redx_5739_house_nbr[0],		redx_5739_house_nbr[0] },		// 0
{ S,	":ap[0]:",		&s_redx_5739_apt_nbr[0],		redx_5739_apt_nbr[0] },			// 1
{ C,	":des[0]:",		&c_redx_5739_destroyed[0],		redx_5739_destroyed[0] },		// 2
{ C,	":maj[0]:",		&c_redx_5739_major[0],			redx_5739_major[0] },			// 3
{ C,	":min[0]:",		&c_redx_5739_minor[0],			redx_5739_minor[0] },			// 4
{ C,	":aff[0]:",		&c_redx_5739_affected[0],		redx_5739_affected[0] },		// 5
{ C,	":acc[0]:",		&c_redx_5739_inaccessible[0],	redx_5739_inaccessible[0] },	// 6
{ I,	":flr[0]:",		&i_redx_5739_floors[0],			redx_5739_floors[0] },			// 7
{ C,	":bas[0]:",		&b_redx_5739_basement[0],		redx_5739_basement[0] },		// 8
{ I,	":wtr[0]:",		&i_redx_5739_waterlevel[0],		redx_5739_waterlevel[0] },		// 9
{ I,	":bwl[0]:",		&i_redx_5739_basement_water[0],	redx_5739_basement_water[0] },	// 10
{ C,	":ele[0]:",		&b_redx_5739_electricity[0],	redx_5739_electricity[0] },		// 11
{ C,	":occ[0]:",		&c_redx_5739_occupancy[0],		redx_5739_occupancy[0] },		// 12
{ C,	":or[0]:",		&b_redx_5739_OR[0],				redx_5739_OR[0] },				// 13
{ C,	":901[0]:",		&b_redx_5739_901[0],			redx_5739_901[0] },				// 14
{ S,	":desc[0]:",	&s_redx_5739_desc[0],			redx_5739_desc[0] },			// 15
{ S,	":nam[0]:",		&s_redx_5739_nam[0],			redx_5739_nam[0] },				// 16

{ S,	":hb[1]:",		&s_redx_5739_house_nbr[1],		redx_5739_house_nbr[1] },
{ S,	":ap[1]:",		&s_redx_5739_apt_nbr[1],		redx_5739_apt_nbr[1] },
{ C,	":des[1]:",		&c_redx_5739_destroyed[1],		redx_5739_destroyed[1] },
{ C,	":maj[1]:",		&c_redx_5739_major[1],			redx_5739_major[1] },
{ C,	":min[1]:",		&c_redx_5739_minor[1],			redx_5739_minor[1] },
{ C,	":aff[1]:",		&c_redx_5739_affected[1],		redx_5739_affected[1] },
{ C,	":acc[1]:",		&c_redx_5739_inaccessible[1],	redx_5739_inaccessible[1] },
{ I,	":flr[1]:",		&i_redx_5739_floors[1],			redx_5739_floors[1] },
{ C,	":bas[1]:",		&b_redx_5739_basement[1],		redx_5739_basement[1] },
{ I,	":wtr[1]:",		&i_redx_5739_waterlevel[1],		redx_5739_waterlevel[1] },
{ I,	":bwl[1]:",		&i_redx_5739_basement_water[1],	redx_5739_basement_water[1] },
{ C,	":ele[1]:",		&b_redx_5739_electricity[1],	redx_5739_electricity[1] },
{ C,	":occ[1]:",		&c_redx_5739_occupancy[1],		redx_5739_occupancy[1] },
{ C,	":or[1]:",		&b_redx_5739_OR[1],				redx_5739_OR[1] },
{ C,	":901[1]:",		&b_redx_5739_901[1],			redx_5739_901[1] },
{ S,	":desc[1]:",	&s_redx_5739_desc[1],			redx_5739_desc[1] },
{ S,	":nam[1]:",		&s_redx_5739_nam[1],			redx_5739_nam[1] },

{ S,	":hb[2]:",		&s_redx_5739_house_nbr[2],		redx_5739_house_nbr[2] },
{ S,	":ap[2]:",		&s_redx_5739_apt_nbr[2],		redx_5739_apt_nbr[2] },
{ C,	":des[2]:",		&c_redx_5739_destroyed[2],		redx_5739_destroyed[2] },
{ C,	":maj[2]:",		&c_redx_5739_major[2],			redx_5739_major[2] },
{ C,	":min[2]:",		&c_redx_5739_minor[2],			redx_5739_minor[2] },
{ C,	":aff[2]:",		&c_redx_5739_affected[2],		redx_5739_affected[2] },
{ C,	":acc[2]:",		&c_redx_5739_inaccessible[2],	redx_5739_inaccessible[2] },
{ I,	":flr[2]:",		&i_redx_5739_floors[2],			redx_5739_floors[2] },
{ C,	":bas[2]:",		&b_redx_5739_basement[2],		redx_5739_basement[2] },
{ I,	":wtr[2]:",		&i_redx_5739_waterlevel[2],		redx_5739_waterlevel[2] },
{ I,	":bwl[2]:",		&i_redx_5739_basement_water[2],	redx_5739_basement_water[2] },
{ C,	":ele[2]:",		&b_redx_5739_electricity[2],	redx_5739_electricity[2] },
{ C,	":occ[2]:",		&c_redx_5739_occupancy[2],		redx_5739_occupancy[2] },
{ C,	":or[2]:",		&b_redx_5739_OR[2],				redx_5739_OR[2] },
{ C,	":901[2]:",		&b_redx_5739_901[2],			redx_5739_901[2] },
{ S,	":desc[2]:",	&s_redx_5739_desc[2],			redx_5739_desc[2] },
{ S,	":nam[2]:",		&s_redx_5739_nam[2],			redx_5739_nam[2] },

{ S,	":hb[3]:",		&s_redx_5739_house_nbr[3],		redx_5739_house_nbr[3] },
{ S,	":ap[3]:",		&s_redx_5739_apt_nbr[3],		redx_5739_apt_nbr[3] },
{ C,	":des[3]:",		&c_redx_5739_destroyed[3],		redx_5739_destroyed[3] },
{ C,	":maj[3]:",		&c_redx_5739_major[3],			redx_5739_major[3] },
{ C,	":min[3]:",		&c_redx_5739_minor[3],			redx_5739_minor[3] },
{ C,	":aff[3]:",		&c_redx_5739_affected[3],		redx_5739_affected[3] },
{ C,	":acc[3]:",		&c_redx_5739_inaccessible[3],	redx_5739_inaccessible[3] },
{ I,	":flr[3]:",		&i_redx_5739_floors[3],			redx_5739_floors[3] },
{ C,	":bas[3]:",		&b_redx_5739_basement[3],		redx_5739_basement[3] },
{ I,	":wtr[3]:",		&i_redx_5739_waterlevel[3],		redx_5739_waterlevel[3] },
{ I,	":bwl[3]:",		&i_redx_5739_basement_water[3],	redx_5739_basement_water[3] },
{ C,	":ele[3]:",		&b_redx_5739_electricity[3],	redx_5739_electricity[3] },
{ C,	":occ[3]:",		&c_redx_5739_occupancy[3],		redx_5739_occupancy[3] },
{ C,	":or[3]:",		&b_redx_5739_OR[3],				redx_5739_OR[3] },
{ C,	":901[3]:",		&b_redx_5739_901[3],			redx_5739_901[3] },
{ S,	":desc[3]:",	&s_redx_5739_desc[3],			redx_5739_desc[3] },
{ S,	":nam[3]:",		&s_redx_5739_nam[3],			redx_5739_nam[3] },

{ S,	":hb[4]:",		&s_redx_5739_house_nbr[4],		redx_5739_house_nbr[4] },
{ S,	":ap[4]:",		&s_redx_5739_apt_nbr[4],		redx_5739_apt_nbr[4] },
{ C,	":des[4]:",		&c_redx_5739_destroyed[4],		redx_5739_destroyed[4] },
{ C,	":maj[4]:",		&c_redx_5739_major[4],			redx_5739_major[4] },
{ C,	":min[4]:",		&c_redx_5739_minor[4],			redx_5739_minor[4] },
{ C,	":aff[4]:",		&c_redx_5739_affected[4],		redx_5739_affected[4] },
{ C,	":acc[4]:",		&c_redx_5739_inaccessible[4],	redx_5739_inaccessible[4] },
{ I,	":flr[4]:",		&i_redx_5739_floors[4],			redx_5739_floors[4] },
{ C,	":bas[4]:",		&b_redx_5739_basement[4],		redx_5739_basement[4] },
{ I,	":wtr[4]:",		&i_redx_5739_waterlevel[4],		redx_5739_waterlevel[4] },
{ I,	":bwl[4]:",		&i_redx_5739_basement_water[4],	redx_5739_basement_water[4] },
{ C,	":ele[4]:",		&b_redx_5739_electricity[4],	redx_5739_electricity[4] },
{ C,	":occ[4]:",		&c_redx_5739_occupancy[4],		redx_5739_occupancy[4] },
{ C,	":or[4]:",		&b_redx_5739_OR[4],				redx_5739_OR[4] },
{ C,	":901[4]:",		&b_redx_5739_901[4],			redx_5739_901[4] },
{ S,	":desc[4]:",	&s_redx_5739_desc[4],			redx_5739_desc[4] },
{ S,	":nam[4]:",		&s_redx_5739_nam[4],			redx_5739_nam[4] },

{ S,	":hb[5]:",		&s_redx_5739_house_nbr[5],		redx_5739_house_nbr[5] },
{ S,	":ap[5]:",		&s_redx_5739_apt_nbr[5],		redx_5739_apt_nbr[5] },
{ C,	":des[5]:",		&c_redx_5739_destroyed[5],		redx_5739_destroyed[5] },
{ C,	":maj[5]:",		&c_redx_5739_major[5],			redx_5739_major[5] },
{ C,	":min[5]:",		&c_redx_5739_minor[5],			redx_5739_minor[5] },
{ C,	":aff[5]:",		&c_redx_5739_affected[5],		redx_5739_affected[5] },
{ C,	":acc[5]:",		&c_redx_5739_inaccessible[5],	redx_5739_inaccessible[5] },
{ I,	":flr[5]:",		&i_redx_5739_floors[5],			redx_5739_floors[5] },
{ C,	":bas[5]:",		&b_redx_5739_basement[5],		redx_5739_basement[5] },
{ I,	":wtr[5]:",		&i_redx_5739_waterlevel[5],		redx_5739_waterlevel[5] },
{ I,	":bwl[5]:",		&i_redx_5739_basement_water[5],	redx_5739_basement_water[5] },
{ C,	":ele[5]:",		&b_redx_5739_electricity[5],	redx_5739_electricity[5] },
{ C,	":occ[5]:",		&c_redx_5739_occupancy[5],		redx_5739_occupancy[5] },
{ C,	":or[5]:",		&b_redx_5739_OR[5],				redx_5739_OR[5] },
{ C,	":901[5]:",		&b_redx_5739_901[5],			redx_5739_901[5] },
{ S,	":desc[5]:",	&s_redx_5739_desc[5],			redx_5739_desc[5] },
{ S,	":nam[5]:",		&s_redx_5739_nam[5],			redx_5739_nam[5] },

{ S,	":hb[6]:",		&s_redx_5739_house_nbr[6],		redx_5739_house_nbr[6] },
{ S,	":ap[6]:",		&s_redx_5739_apt_nbr[6],		redx_5739_apt_nbr[6] },
{ C,	":des[6]:",		&c_redx_5739_destroyed[6],		redx_5739_destroyed[6] },
{ C,	":maj[6]:",		&c_redx_5739_major[6],			redx_5739_major[6] },
{ C,	":min[6]:",		&c_redx_5739_minor[6],			redx_5739_minor[6] },
{ C,	":aff[6]:",		&c_redx_5739_affected[6],		redx_5739_affected[6] },
{ C,	":acc[6]:",		&c_redx_5739_inaccessible[6],	redx_5739_inaccessible[6] },
{ I,	":flr[6]:",		&i_redx_5739_floors[6],			redx_5739_floors[6] },
{ C,	":bas[6]:",		&b_redx_5739_basement[6],		redx_5739_basement[6] },
{ I,	":wtr[6]:",		&i_redx_5739_waterlevel[6],		redx_5739_waterlevel[6] },
{ I,	":bwl[6]:",		&i_redx_5739_basement_water[6],	redx_5739_basement_water[6] },
{ C,	":ele[6]:",		&b_redx_5739_electricity[6],	redx_5739_electricity[6] },
{ C,	":occ[6]:",		&c_redx_5739_occupancy[6],		redx_5739_occupancy[6] },
{ C,	":or[6]:",		&b_redx_5739_OR[6],				redx_5739_OR[6] },
{ C,	":901[6]:",		&b_redx_5739_901[6],			redx_5739_901[6] },
{ S,	":desc[6]:",	&s_redx_5739_desc[6],			redx_5739_desc[6] },
{ S,	":nam[6]:",		&s_redx_5739_nam[6],			redx_5739_nam[6] },

{ S,	":hb[7]:",		&s_redx_5739_house_nbr[7],		redx_5739_house_nbr[7] },
{ S,	":ap[7]:",		&s_redx_5739_apt_nbr[7],		redx_5739_apt_nbr[7] },
{ C,	":des[7]:",		&c_redx_5739_destroyed[7],		redx_5739_destroyed[7] },
{ C,	":maj[7]:",		&c_redx_5739_major[7],			redx_5739_major[7] },
{ C,	":min[7]:",		&c_redx_5739_minor[7],			redx_5739_minor[7] },
{ C,	":aff[7]:",		&c_redx_5739_affected[7],		redx_5739_affected[7] },
{ C,	":acc[7]:",		&c_redx_5739_inaccessible[7],	redx_5739_inaccessible[7] },
{ I,	":flr[7]:",		&i_redx_5739_floors[7],			redx_5739_floors[7] },
{ C,	":bas[7]:",		&b_redx_5739_basement[7],		redx_5739_basement[7] },
{ I,	":wtr[7]:",		&i_redx_5739_waterlevel[7],		redx_5739_waterlevel[7] },
{ I,	":bwl[7]:",		&i_redx_5739_basement_water[7],	redx_5739_basement_water[7] },
{ C,	":ele[7]:",		&b_redx_5739_electricity[7],	redx_5739_electricity[7] },
{ C,	":occ[7]:",		&c_redx_5739_occupancy[7],		redx_5739_occupancy[7] },
{ C,	":or[7]:",		&b_redx_5739_OR[7],				redx_5739_OR[7] },
{ C,	":901[7]:",		&b_redx_5739_901[7],			redx_5739_901[7] },
{ S,	":desc[7]:",	&s_redx_5739_desc[7],			redx_5739_desc[7] },
{ S,	":nam[7]:",		&s_redx_5739_nam[7],			redx_5739_nam[7] },

{ S,	":hb[8]:",		&s_redx_5739_house_nbr[8],		redx_5739_house_nbr[8] },
{ S,	":ap[8]:",		&s_redx_5739_apt_nbr[8],		redx_5739_apt_nbr[8] },
{ C,	":des[8]:",		&c_redx_5739_destroyed[8],		redx_5739_destroyed[8] },
{ C,	":maj[8]:",		&c_redx_5739_major[8],			redx_5739_major[8] },
{ C,	":min[8]:",		&c_redx_5739_minor[8],			redx_5739_minor[8] },
{ C,	":aff[8]:",		&c_redx_5739_affected[8],		redx_5739_affected[8] },
{ C,	":acc[8]:",		&c_redx_5739_inaccessible[8],	redx_5739_inaccessible[8] },
{ I,	":flr[8]:",		&i_redx_5739_floors[8],			redx_5739_floors[8] },
{ C,	":bas[8]:",		&b_redx_5739_basement[8],		redx_5739_basement[8] },
{ I,	":wtr[8]:",		&i_redx_5739_waterlevel[8],		redx_5739_waterlevel[8] },
{ I,	":bwl[8]:",		&i_redx_5739_basement_water[8],	redx_5739_basement_water[8] },
{ C,	":ele[8]:",		&b_redx_5739_electricity[8],	redx_5739_electricity[8] },
{ C,	":occ[8]:",		&c_redx_5739_occupancy[8],		redx_5739_occupancy[8] },
{ C,	":or[8]:",		&b_redx_5739_OR[8],				redx_5739_OR[8] },
{ C,	":901[8]:",		&b_redx_5739_901[8],			redx_5739_901[8] },
{ S,	":desc[8]:",	&s_redx_5739_desc[8],			redx_5739_desc[8] },
{ S,	":nam[8]:",		&s_redx_5739_nam[8],			redx_5739_nam[8] },

{ S,	":hb[9]:",		&s_redx_5739_house_nbr[9],		redx_5739_house_nbr[9] },
{ S,	":ap[9]:",		&s_redx_5739_apt_nbr[9],		redx_5739_apt_nbr[9] },
{ C,	":des[9]:",		&c_redx_5739_destroyed[9],		redx_5739_destroyed[9] },
{ C,	":maj[9]:",		&c_redx_5739_major[9],			redx_5739_major[9] },
{ C,	":min[9]:",		&c_redx_5739_minor[9],			redx_5739_minor[9] },
{ C,	":aff[9]:",		&c_redx_5739_affected[9],		redx_5739_affected[9] },
{ C,	":acc[9]:",		&c_redx_5739_inaccessible[9],	redx_5739_inaccessible[9] },
{ I,	":flr[9]:",		&i_redx_5739_floors[9],			redx_5739_floors[9] },
{ C,	":bas[9]:",		&b_redx_5739_basement[9],		redx_5739_basement[9] },
{ I,	":wtr[9]:",		&i_redx_5739_waterlevel[9],		redx_5739_waterlevel[9] },
{ I,	":bwl[9]:",		&i_redx_5739_basement_water[9],	redx_5739_basement_water[9] },
{ C,	":ele[9]:",		&b_redx_5739_electricity[9],	redx_5739_electricity[9] },
{ C,	":occ[9]:",		&c_redx_5739_occupancy[9],		redx_5739_occupancy[9] },
{ C,	":or[9]:",		&b_redx_5739_OR[9],				redx_5739_OR[9] },
{ C,	":901[9]:",		&b_redx_5739_901[9],			redx_5739_901[9] },
{ S,	":desc[9]:",	&s_redx_5739_desc[9],			redx_5739_desc[9] },
{ S,	":nam[9]:",		&s_redx_5739_nam[9],			redx_5739_nam[9] },

{ E,	"",				NULL,							NULL }
};

string buffredx_5739;
string def_redx_5739_filename = "";
string base_redx_5739_filename = "";
string def_redx_5739_TemplateName = "";

bool using_redx_5739_template = false;
static bool fields_initialized = false;

// required to initialize the control pointers in the QUAD arrays

static void init_widgets()
{
	for (int i = 0; i < 10; i++ ) {
		redx_QUAD1[i*17 + 0].widget  = redx_5739_house_nbr[i];
		redx_QUAD1[i*17 + 1].widget  = redx_5739_apt_nbr[i];
		redx_QUAD1[i*17 + 2].widget  = redx_5739_destroyed[i];
		redx_QUAD1[i*17 + 3].widget  = redx_5739_major[i];
		redx_QUAD1[i*17 + 4].widget  = redx_5739_minor[i];
		redx_QUAD1[i*17 + 5].widget  = redx_5739_affected[i];
		redx_QUAD1[i*17 + 6].widget  = redx_5739_inaccessible[i];
		redx_QUAD1[i*17 + 7].widget  = redx_5739_floors[i];
		redx_QUAD1[i*17 + 8].widget  = redx_5739_basement[i];
		redx_QUAD1[i*17 + 9].widget  = redx_5739_waterlevel[i];
		redx_QUAD1[i*17 + 10].widget = redx_5739_basement_water[i];
		redx_QUAD1[i*17 + 11].widget = redx_5739_electricity[i];
		redx_QUAD1[i*17 + 12].widget = redx_5739_occupancy[i];
		redx_QUAD1[i*17 + 13].widget = redx_5739_OR[i];
		redx_QUAD1[i*17 + 14].widget = redx_5739_901[i];
		redx_QUAD1[i*17 + 15].widget = redx_5739_desc[i];
		redx_QUAD1[i*17 + 16].widget = redx_5739_nam[i];
	}

	redx_QUAD[0].widget  = rdx_5739_nbr;
	redx_QUAD[1].widget  = rdx_5739_name;
	redx_QUAD[2].widget  = rdx_5739_state;
	redx_QUAD[3].widget  = rdx_5739_cnty;
	redx_QUAD[4].widget  = rdx_5739_city;
	redx_QUAD[5].widget  = rdx_5739_date;
	redx_QUAD[6].widget  = rdx_5739_street;
	redx_QUAD[7].widget  = rdx_5739_georef;

	redx_QUAD[8].widget  = rdx_sf_destroyed;
	redx_QUAD[9].widget  = rdx_sf_major;
	redx_QUAD[10].widget  = rdx_sf_minor;
	redx_QUAD[11].widget  = rdx_sf_affected;
	redx_QUAD[12].widget  = rdx_sf_inaccessible;

	redx_QUAD[13].widget  = rdx_mh_destroyed;
	redx_QUAD[14].widget  = rdx_mh_major;
	redx_QUAD[15].widget  = rdx_mh_minor;
	redx_QUAD[16].widget  = rdx_mh_affected;
	redx_QUAD[17].widget  = rdx_mh_inaccessible;

	redx_QUAD[18].widget  = rdx_ap_destroyed;
	redx_QUAD[19].widget  = rdx_ap_major;
	redx_QUAD[20].widget  = rdx_ap_minor;
	redx_QUAD[21].widget  = rdx_ap_affected;
	redx_QUAD[22].widget  = rdx_ap_inaccessible;

	redx_QUAD[23].widget  = rdx_5739_add_info;
	redx_QUAD[24].widget  = rdx_5739_worker;
	redx_QUAD[25].widget  = rdx_5739_supervisor;

	fields_initialized = true;
}

//enum QTYPE { B, S, T, I, F, C, E }; 
// bool, string, text, int, float, character, empty

void clearQUAD(QUAD *p)
{
	QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B : (*(bool *)(p->ptr)) = false; break;
			case S : ((string *)(p->ptr))->clear(); break;
			case T : ((string *)(p->ptr))->clear(); break;
			case C : (*(char *)(p->ptr)) = ' '; break;
			case I : (*(int *)(p->ptr)) = 0; break;
			case F : (*(float *)(p->ptr)) = 0.0; break;
			case E : return;
		}
		p++;
	}
}

void clear_redx_5739fields()
{
	if (!fields_initialized) init_widgets();
	clearQUAD(redx_QUAD);
	clearQUAD(redx_QUAD1);
}

bool checkQUAD(QUAD *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		if (p->widget == NULL) return false;
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) != ((Fl_Check_Button *)p->widget)->value()) return true;
				break;
			case S:
				if (*((string *)(p->ptr)) != ((Fl_Input2 *)p->widget)->value()) return true;
				break;
			case T:
				if (*((string *)(p->ptr)) != ((FTextEdit *)p->widget)->buffer()->text()) return true;
				break;
			case C:
				c = ' ';
				if (((Fl_Input2 *)p->widget)->value()[0])
					c = ((Fl_Input2 *)p->widget)->value()[0];
				if (*((char *)(p->ptr)) != c) return true;
				break;
			case I:
				i = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%d", &i);
				if (*((int *)(p->ptr)) != i) return true;
				break;
			case F:
				f = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%f", &f);
				if (*((float *)(p->ptr)) != f) return true;;
				break;
			case E:
			default: return false;
		}
		p++;
	}
	return false;
}

bool check_redx_5739fields()
{
	if (checkQUAD(redx_QUAD)) return true;
	return checkQUAD(redx_QUAD1);
}

void updateQUAD(QUAD *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = ((Fl_Check_Button *)p->widget)->value();
				break;
			case S:
				*((string *)(p->ptr)) = ((Fl_Input2 *)p->widget)->value();
				break;
			case T:
				*((string *)(p->ptr)) = ((FTextEdit *)p->widget)->buffer()->text();
				break;
			case C:
				c = ' ';
				if (((Fl_Input2 *)p->widget)->value()[0])
					c = ((Fl_Input2 *)p->widget)->value()[0];
				*((char *)(p->ptr)) = c;
				break;
			case I:
				i = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%d", &i);
				*((int *)(p->ptr)) = i;
				break;
			case F:
				f = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%f", &f);
				*((float *)(p->ptr)) = f;
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void update_redx_5739fields()
{
	if (!fields_initialized) init_widgets();
	updateQUAD(redx_QUAD);
	updateQUAD(redx_QUAD1);
}

void updateFORM(QUAD *p)
{
	char val[20];
	QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				((Fl_Check_Button *)p->widget)->value(*((bool *)(p->ptr)));
				break;
			case S:
				((Fl_Input2 *)p->widget)->value(((string *)(p->ptr))->c_str());
				break;
			case T:
				((FTextEdit *)p->widget)->clear();
				((FTextEdit *)p->widget)->add(((string *)(p->ptr))->c_str());
				break;
			case C:
				val[0] = *((char *)(p->ptr));
				val[1] = 0;
				((Fl_Input2 *)p->widget)->value(val);
				break;
			case I:
				if (*((int *)(p->ptr)) == 0)
					((Fl_Input2 *)p->widget)->value("");
				else {
					snprintf(val, sizeof(val), "%d", *((int *)(p->ptr)));
					((Fl_Input2 *)p->widget)->value(val);
				}
				break;
			case F:
				snprintf(val, sizeof(val), "%f", *((float *)(p->ptr)));
				((Fl_Input2 *)p->widget)->value(val);
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void update_redx_5739form()
{
	if (!fields_initialized) init_widgets();
	updateFORM(redx_QUAD);
	updateFORM(redx_QUAD1);
	redx_5739_compute(NULL, NULL);
}

void clear_redx_5739_form()
{
	clear_redx_5739fields();
	update_redx_5739form();
}

static string mbuff;

void make_buffQUAD(QUAD *p)
{
	string one = "1"; string zero = "0";
	string sval = " ";
	char szval[20];
	QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) == true)
					mbuff.append( lineout( p->htmnbr, *((bool *)(p->ptr)) ? one : zero));
				break;
			case S:
				if (((string *)(p->ptr))->length())
					mbuff.append( lineout( p->htmnbr, *((string *)(p->ptr))));
				break;
			case T:
				mbuff.append( lineout( p->htmnbr, *((string *)(p->ptr))));
				break;
			case C:
				if ((*(char *)(p->ptr)) != 0 && *((char *)(p->ptr)) != ' ') {
					sval = " ";
					sval[0] = *((char *)(p->ptr));
					mbuff.append( lineout( p->htmnbr, sval));
				}
				break;
			case I:
				if (*((int*)(p->ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
					sval = szval;
					mbuff.append( lineout( p->htmnbr, sval) );
				}
				break;
			case F:
				if (*((float *)(p->ptr)) > 0) {
					snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
					sval = szval;
					mbuff.append( lineout( p->htmnbr, sval) );
				}
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void make_buffredx_5739(bool compress = false)
{
	mbuff.clear();
	make_buffQUAD(redx_QUAD);
	make_buffQUAD(redx_QUAD1);
	if (compress) compress_maybe(mbuff);
	buffredx_5739.append(mbuff);
}

void readQUAD(string data, QUAD *p)
{
	int i = 0;
	float f;
	QTYPE qt = E;
	while ((qt = p->qtype) != E) {
		switch (qt) {
			case B:
				*((bool *)(p->ptr)) = (findstr( data, p->htmnbr ) == "1");
				break;
			case S:
				*((string *)(p->ptr)) = findstr( data, p->htmnbr );
				break;
			case T:
				*((string *)(p->ptr)) = findstr( data, p->htmnbr );
				break;
			case C:
				*((char *)(p->ptr)) = findstr( data, p->htmnbr )[0];
				break;
			case I:
				i = 0;
				sscanf( findstr( data, p->htmnbr ).c_str(), "%d", &i);
				*((int *)(p->ptr)) = i;
				break;
			case F:
				f = 0;
				sscanf( findstr( data, p->htmnbr ).c_str(), "%f", &f);
				*((float *)(p->ptr)) = f;
				break;
			case E:
			default: return;
		}
		p++;
	}
}

void read_redx_5739_buffer(string data)
{
	clear_redx_5739fields();
	read_header(data);

// search the file buffer for each of the redx_5739 fields
	readQUAD (data, redx_QUAD);
	readQUAD (data, redx_QUAD1);
	update_redx_5739form();
}

void cb_redx_5739_new()
{
	if (check_redx_5739fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_redx_5739_save();
		}
	}
	clear_redx_5739_form();
	clear_header();
	def_redx_5739_filename = ICS_msg_dir;
	def_redx_5739_filename.append("new"FREDX5739_EXT);
	show_filename(def_redx_5739_filename);
	using_redx_5739_template = false;
}

void cb_redx_5739_import()
{
	fl_alert2("Not implemented");
}

void cb_redx_5739_export()
{
	fl_alert2("Not implemented");
}

void cb_redx_5739_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_redx_5739_form();
	read_redx_5739_buffer(inpbuffer);
	def_redx_5739_filename = ICS_msg_dir;
	def_redx_5739_filename.append(wrapfilename);
	show_filename(def_redx_5739_filename);
	using_redx_5739_template = false;
}

int eval_redx_5739_fsize()
{
	Ccrc16 chksum;
	evalstr.assign("[WRAP:beg][WRAP:lf][WRAP:fn ");
	evalstr.append(base_redx_5739_filename).append("]");
	update_redx_5739fields();
	update_header(FROM);
	evalstr.append(header("<redx_5739>"));
	buffredx_5739.clear();
	make_buffredx_5739(true);
	if (buffredx_5739.empty()) return 0;
	compress_maybe( buffredx_5739 );
	evalstr.append( buffredx_5739 );
	evalstr.append("[WRAP:chksum ").append(chksum.scrc16(evalstr)).append("][WRAP:end]");
	return evalstr.length();
}

void cb_redx_5739_wrap_export()
{
	if (check_redx_5739fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_5739fields();

	if (base_redx_5739_filename == "new"FREDX5739_EXT || base_redx_5739_filename == "default"FREDX5739_EXT)
		if (!cb_redx_5739_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_redx_5739_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffredx_5739.assign(header("<redx_5739>"));
		make_buffredx_5739(true);
		export_wrapfile(base_redx_5739_filename, wrapfilename, buffredx_5739, pext != ".wrap");

		buffredx_5739.assign(header("<redx_5739>"));
		make_buffredx_5739(false);
		write_redx_5739(def_redx_5739_filename);
	}
}

void cb_redx_5739_wrap_autosend()
{
	if (check_redx_5739fields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_5739fields();

	if (base_redx_5739_filename == "new"FREDX5739_EXT || base_redx_5739_filename == "default"FREDX5739_EXT)
		if (!cb_redx_5739_save_as()) return;

	update_header(FROM);
	buffredx_5739.assign(header("<redx_5739>"));
	make_buffredx_5739(true);
	xfr_via_socket(base_redx_5739_filename, buffredx_5739);

	buffredx_5739.assign(header("<redx_5739>"));
	make_buffredx_5739(false);
	write_redx_5739(def_redx_5739_filename);
}

void cb_redx_5739_load_template()
{
	string def_redx_5739_filename = def_redx_5739_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"TREDX5739_EXT,
			def_redx_5739_filename.c_str());
	if (p) {
		clear_redx_5739_form();
		read_data_file(p);
		def_redx_5739_TemplateName = p;
		show_filename(def_redx_5739_TemplateName);
		using_redx_5739_template = true;
	}
}

void cb_redx_5739_save_template()
{
	if (!using_redx_5739_template) {
		cb_redx_5739_save_as_template();
		return;
	}
	string def_redx_5739_filename = def_redx_5739_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"TREDX5739_EXT,
			def_redx_5739_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_redx_5739fields();
		buffredx_5739.assign(header("<redx_5739>"));
		make_buffredx_5739();
		write_redx_5739(p);
	}
}

void cb_redx_5739_save_as_template()
{
	string def_redx_5739_filename = def_redx_5739_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"TREDX5739_EXT,
			def_redx_5739_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_redx_5739_TemplateName = p;
		if (strlen(pext) == 0) def_redx_5739_TemplateName.append(TREDX5739_EXT);
		remove_spaces_from_filename(def_redx_5739_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_redx_5739fields();
		buffredx_5739.assign(header("<redx_5739>"));
		make_buffredx_5739();
		write_redx_5739(def_redx_5739_TemplateName);

		show_filename(def_redx_5739_TemplateName);
		using_redx_5739_template = true;
	}
}

void cb_redx_5739_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-redx_5739\t*"FREDX5739_EXT,
					def_redx_5739_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_redx_5739_form();
	read_data_file(p);
	using_redx_5739_template = false;
	def_redx_5739_filename = p;
	show_filename(def_redx_5739_filename);
}

void write_redx_5739(string s)
{
	FILE *fileredx_5739 = fopen(s.c_str(), "w");
	if (!fileredx_5739) return;

	fwrite(buffredx_5739.c_str(), buffredx_5739.length(), 1, fileredx_5739);
	fclose(fileredx_5739);
}

bool cb_redx_5739_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FREDX5739_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_redx_5739_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-redx_5739\t*"FREDX5739_EXT,
					newfilename.c_str());

	if (!p) return false;
	if (strlen(p) == 0) return false;

	if (progStatus.sernbr_fname) {
		string haystack = p;
		if (haystack.find(newfilename) != string::npos) {
			int n = atoi(progStatus.sernbr.c_str());
			n++;
			char szn[10];
			snprintf(szn, sizeof(szn), "%d", n);
			progStatus.sernbr = szn;
			txt_sernbr->value(szn);
			txt_sernbr->redraw();
		}
	}

	const char *pext = fl_filename_ext(p);
	def_redx_5739_filename = p;
	if (strlen(pext) == 0) def_redx_5739_filename.append(FREDX5739_EXT);

	remove_spaces_from_filename(def_redx_5739_filename);

	update_header(NEW);
	update_redx_5739fields();
	buffredx_5739.assign(header("<redx_5739>"));
	make_buffredx_5739();
	write_redx_5739(def_redx_5739_filename);

	using_redx_5739_template = false;
	show_filename(def_redx_5739_filename);
	return true;
}

void cb_redx_5739_save()
{
	if (base_redx_5739_filename == "new"FREDX5739_EXT || 
		base_redx_5739_filename == "default"FREDX5739_EXT ||
		using_redx_5739_template == true) {
		cb_redx_5739_save_as();
		return;
	}

	if (check_redx_5739fields()) update_header(CHANGED);
	update_redx_5739fields();
	buffredx_5739.assign(header("<redx_5739>"));
	make_buffredx_5739();
	write_redx_5739(def_redx_5739_filename);

	using_redx_5739_template = false;
}

void quad_to_html( string &target, QUAD *p)
{
	string X = "X"; string SP = " ";
	string sval = " ";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B)
			replacestr(target, p->htmnbr, *((bool *)(p->ptr)) ? X : SP);
		else if (p->qtype == S)
			replacestr(target, p->htmnbr, *((string *)(p->ptr)));
		else if (p->qtype == T)
			replacestr(target, p->htmnbr, *((string *)(p->ptr)));
		else if (p->qtype == C) {
			sval = " ";
			sval[0] = *((char *)(p->ptr));
			replacestr(target, p->htmnbr, sval);
		}
		else if (p->qtype == I) {
			if (*((int *)(p->ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
				sval = szval;
			} else sval.clear();
				replacestr(target, p->htmnbr, sval);
		}
		else if (p->qtype == F) {
			if (*((float *)(p->ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
				sval = szval;
			} else sval.clear();
			replacestr(target, p->htmnbr, sval);
		}
		p++;
	}
}

void cb_redx_5739_html()
{
	string name_name = fl_filename_name(def_redx_5739_filename.c_str());
	size_t p = name_name.rfind('.');
	if (p != string::npos) name_name.erase(p);

	string redx_5739_name = ICS_dir;
	redx_5739_name.append(name_name);
	redx_5739_name.append(".html");

	update_redx_5739fields();
	string formredx_5739 = redx_5739_html_template;

	replacestr(formredx_5739, TITLE, name_name);

	quad_to_html (formredx_5739, redx_QUAD);
	quad_to_html (formredx_5739, redx_QUAD1);

	FILE *fileredx_5739 = fopen(redx_5739_name.c_str(), "w");
	fprintf(fileredx_5739,"%s", formredx_5739.c_str());
	fclose(fileredx_5739);

	open_url(redx_5739_name.c_str());
}

void cb_5739_msg_type()
{
	if (selected_form == REDX5739 ) {
		show_filename(def_redx_5739_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void quad_to_text( string &target, QUAD *p)
{
	string X = "X"; string SP = " ";
	string sval = " ";
	string del = "DELETE";
	char szval[20];
	while (p->qtype != E) {
		if (p->qtype == B) {
			bool b = *((bool *)(p->ptr));
			if (b) replacestr(target, p->htmnbr, X);
			else replacestr(target, p->htmnbr, del);
		} else if (p->qtype == S) {
			if (((string *)(p->ptr))->length())
				replacestr(target, p->htmnbr, *((string *)(p->ptr)));
			else replacestr(target, p->htmnbr, del);
		} else if (p->qtype == T) {
			if (((string *)(p->ptr))->length())
				replacestr(target, p->htmnbr, *((string *)(p->ptr)));
			else replacestr(target, p->htmnbr, del);
		} else if (p->qtype == C) {
			sval = " ";
			sval[0] = *((char *)(p->ptr));
			if (sval[0] != 0 && sval[0] != ' ')
				replacestr(target, p->htmnbr, sval);
			else replacestr(target, p->htmnbr, del);
		}
		else if (p->qtype == I) {
			if (*((int *)(p->ptr)) > 0) {
				snprintf(szval, sizeof(szval), "%d", *((int *)(p->ptr)) );
				sval = szval;
				replacestr(target, p->htmnbr, sval);
			} else replacestr(target, p->htmnbr, del);
		}
		else if (p->qtype == F) {
			if (*((float *)(p->ptr)) != 0) {
				snprintf(szval, sizeof(szval), "%f", *((float *)(p->ptr)));
				sval = szval;
				replacestr(target, p->htmnbr, sval);
			} else replacestr(target, p->htmnbr, del);
		}
		p++;
	}
}

void strip_text( string &target )
{
	size_t p = 0, p1, p2;
	while ((p = target.find ("DELETE"), p) != string::npos) {
		p1 = target.rfind ("\n", p);
		p2 = target.find ("\n", p);
		if (p1 != string::npos && p2 != string::npos)
			target.erase( p1, p2 - p1 );
		p++;
	}
}

void cb_redx_5739_textout()
{
	string redx_5739_name = ICS_dir;
	redx_5739_name.append("redx_5739.txt");

	update_redx_5739fields();
	string formredx_5739 = redx_5739_text_template;

	quad_to_text (formredx_5739, redx_QUAD);
	quad_to_text (formredx_5739, redx_QUAD1);

	strip_text (formredx_5739);

	FILE *fileredx_5739 = fopen(redx_5739_name.c_str(), "w");
	fprintf(fileredx_5739,"%s", formredx_5739.c_str());
	fclose(fileredx_5739);

	open_url(redx_5739_name.c_str());
}

