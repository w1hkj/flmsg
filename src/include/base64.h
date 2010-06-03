// =====================================================================
//
// base64.h
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

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 

#include <string>

using namespace std;

typedef unsigned char byte;

class base64 {
#define LINELEN 72
private:
	string output;
	size_t iolen;
	size_t iocp;
	bool ateof;
	byte dtable[256];
	byte etable[256];
	int linelength;
	bool crlf;
	void init();
public:
	base64(bool t = false) {crlf = t; init(); };
	~base64(){};
	string encode(string in);
	string decode(string in);
};
