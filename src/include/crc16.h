// =====================================================================
//
// crc16.h ... crc16 checksum
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

#include <string>
#include "debug.h"

using namespace std;

class Ccrc16 {
private:
	unsigned int crcval;
	char ss[5];
public:
	Ccrc16() { crcval = 0xFFFF; }
	~Ccrc16() {};
	void reset() { crcval = 0xFFFF;}
	unsigned int val() {return crcval;}
	string sval() {
		sprintf(ss,"%04X", crcval);
		return ss;
	}
	void update(char c) {
		crcval ^= c;
        for (int i = 0; i < 8; ++i) {
            if (crcval & 1)
                crcval = (crcval >> 1) ^ 0xA001;
            else
                crcval = (crcval >> 1);
        }
	}
	unsigned int crc16(char c) { 
		update(c); 
		return crcval;
	}
	unsigned int crc16(string s) {
		reset();
		for (size_t i = 0; i < s.length(); i++)
			update((char)(s[i] & 0xFF));  // only use lower half of unicode
		return crcval;
	}
	string scrc16(string s) {
		crc16(s);
		return sval();
	}
};

