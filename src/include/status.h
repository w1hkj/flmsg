// =====================================================================
//
// status.h
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

#ifndef _status_H
#define _status_H

#include <string>

using namespace std;

struct status {
	int		mainX;
	int		mainY;

	int		wpl; // words per line in radiogram
	bool	open_on_export;
	int		UTC;
	int		dtformat;

	void saveLastState();
	void loadLastState();
	string my_call;
	string my_tel;
	string my_name;
	string my_addr;
	string my_city;
	bool sernbr_fname;
	bool call_fname;
	bool dt_fname;
	bool rgnbr_fname;
	bool arl_desc;
	string sernbr;
	string rgnbr;
	bool insert_x;
	int tab;
	string mars_roster_file;
	int charcount;
	bool autowordwrap;
};

extern status progStatus;

#endif
