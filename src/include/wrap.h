// =====================================================================
//
// wrap.h
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

#ifndef WRAP_H
#define WRAP_H

#include <string.h>
#include <string>

using namespace std;

extern void compress_maybe(string& input);
extern void decompress_maybe(string& input);

extern void export_wrapfile(string, string, string, bool with_ext);
extern bool import_wrapfile(string fname, string &efname, string &text);

extern void xfr_via_socket(string, string);

extern string wrap_outfilename;

#endif
