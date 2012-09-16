// =====================================================================
//
// base256.h
//
// Author: Dave Freese, W1HKJ
// Copyright: 2012
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

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 

#include <string>

using namespace std;

class base256 {
#define LINELEN 64
private:
	string output;
	size_t iolen;
	size_t iocp;
	bool ateof;
	int linelength;
	void init();
	void escape(string &, bool encode = true);
	void addlf(string &);
	void remlf(string &);
public:
	base256() { init(); };
	~base256() {};
	string encode(string &in);
	string decode(string &in);
};
