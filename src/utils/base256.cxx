// =====================================================================
//
// base256 text encoding
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

#include "base256.h"

void base256::init()
{
	iolen = 0;
	iocp = 0;
	ateof = false;
	linelength = 0;
}

void base256::escape(string &in, bool encode)
{
	string out;
	if (encode) {
		for( size_t i = 0; i < in.length(); i++) {
			switch ((in[i] & 0xFF)) {
				case ':'  : out.append("::"); break;
				case 0x00 : out.append(":0"); break;
				case 0x02 : out.append(":2"); break;
				case 0x03 : out.append(":3"); break;
				case 0x04 : out.append(":4"); break;
				case 0x05 : out.append(":5"); break;
				case '\r' : out.append(":A"); break;
				case '\n' : out.append(":B"); break;
				case '\b' : out.append(":C"); break;
				case '\t' : out.append(":C"); break;
				case '^'  : out.append(":E"); break;
				case 0xFF : out.append(":F"); break;
				default: out += in[i];
			}
		}
	} else {
		unsigned char ch = 0;
		for (size_t i = 0; i < in.length(); i++) {
			ch = in[i] & 0xFF;
			if (ch == ':') {
				i++;
				ch = in[i] & 0xFF;
				switch (ch) {
					case ':' : out += ':'; break;
					case '0' : out += ' '; out[out.length() - 1] = 0x00; break;
					case '2' : out += 0x02; break;
					case '3' : out += 0x03; break;
					case '4' : out += 0x04; break;
					case '5' : out += 0x05; break;
					case 'A' : out += '\r'; break;
					case 'B' : out += '\n'; break;
					case 'C' : out += '\b'; break;
					case 'D' : out += '\t'; break;
					case 'E' : out += '^'; break;
					case 'F' : out += 0xFF; break;
				}
			} else out += ch;
		}
	}
	in = out;
}

void base256::addlf(string &in)
{
	string out;
	int len = 0;
	for (size_t n = 0; n < in.length(); n++) {
		if (len < LINELEN) {out += in[n]; len++;}
		else {out += '\n'; out += in[n]; len = 0;}
	}
	in.assign(out);
}

void base256::remlf(string &in)
{
	string out;
	for (size_t n = 0; n < in.length(); n++) {
		if (in[n] != '\n') out += in[n];
	}
	in.assign(out);
}

string base256::encode(string &in)
{
	char insize[20];
	snprintf(insize, sizeof(insize), "%d\n", in.length());

	output.assign(insize);
	iocp = 0;
	ateof = false;

	string temp (in);
	escape (temp);
	addlf(temp);
	output.append(temp);
	return output;
}

string base256::decode(string &in)
{
	size_t nbr = 0;
	string output = in;
	size_t p = output.find("\n");
	if (p == string::npos)
		return "ERROR: base256 missing character count";
	sscanf(output.substr(0, p).c_str(), "%d", &nbr);
	output.erase(0, p+1);

	remlf(output);
	escape(output, false);
	return output;
}
