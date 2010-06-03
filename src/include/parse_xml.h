// =====================================================================
//
// parse_xml.h
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

#ifndef XML_H
#define XML_H

#include <string>
#include <list>

using namespace std;

struct TAGS { const char *tag; void (*fp)(size_t &, string);};

extern void parse_ics(string);
extern bool qform_ics_import(string);
extern void qform_ics_export(string);

extern void parse_rg(string);
extern bool qform_rg_import(string);
extern void qform_rg_export(string);

#endif

