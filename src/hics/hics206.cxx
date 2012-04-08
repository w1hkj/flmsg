// =====================================================================
//
// hics206.cxx
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

// hics206 tag fields
string h206_tag_name =					":1:";
string h206_tag_date_prepared =			":2:";
string h206_tag_time_prepared =			":3:";
string h206_tag_period =				":4:";

string h206_tag_location =				":5:";
string h206_tag_loc_contact =			":6:";
string h206_tag_team_leader =			":7:";
string h206_tag_team_contact =			":8:";
string h206_tag_special_instructions =	":9:";

string h206_tag_md_do =					":10:";
string h206_tag_litters =				":11:";
string h206_tag_pa_np =					":14:";
string h206_tag_portable =				":15:";
string h206_tag_rn_lpn =				":18:";
string h206_tag_transport =				":19:";
string h206_tag_tech_cn =				":22:";
string h206_tag_wheelchairs =			":23:";
string h206_tag_team_other =			":26:";
string h206_tag_transport_other =		":27:";

string h206_tag_meds_1 = 				":12:";
string h206_tag_meds_2 = 				":16:";
string h206_tag_meds_3 = 				":20:";
string h206_tag_meds_4 = 				":24:";
string h206_tag_meds_5 = 				":28:";
string h206_tag_supp_1 = 				":13:";
string h206_tag_supp_2 = 				":17:";
string h206_tag_supp_3 = 				":21:";
string h206_tag_supp_4 = 				":25:";
string h206_tag_supp_5 = 				":29:";

string h206_tag_site_1 =				":30:";
string h206_tag_address_1 =				":31:";
string h206_tag_phone_1 =				":32:";
string h206_tag_spec_care_1 =			":33:";

string h206_tag_site_2 =				":34:";
string h206_tag_address_2 =				":35:";
string h206_tag_phone_2 =				":36:";
string h206_tag_spec_care_2 =			":37:";

string h206_tag_site_3 =				":38:";
string h206_tag_address_3 =				":39:";
string h206_tag_phone_3 =				":40:";
string h206_tag_spec_care_3 =			":41:";

string h206_tag_site_4 =				":42:";
string h206_tag_address_4 =				":43:";
string h206_tag_phone_4 =				":44:";
string h206_tag_spec_care_4 =			":45:";

string h206_tag_preparer =				":46:";
string h206_tag_facility =				":47:";

string h206_name;
string h206_period;
string h206_date_prepared;
string h206_time_prepared;

string h206_location;
string h206_loc_contact;
string h206_team_leader;
string h206_team_contact;
string h206_special_instructions;

string h206_md_do;
string h206_litters;
string h206_pa_np;
string h206_portable;
string h206_rn_lpn;
string h206_transport;
string h206_tech_cn;
string h206_wheelchairs;
string h206_team_other;
string h206_transport_other;

string h206_meds_1;
string h206_meds_2;
string h206_meds_3;
string h206_meds_4;
string h206_meds_5;
string h206_supp_1;
string h206_supp_2;
string h206_supp_3;
string h206_supp_4;
string h206_supp_5;

string h206_site_1;
string h206_address_1;
string h206_phone_1;
string h206_spec_care_1;
string h206_site_2;
string h206_address_2;
string h206_phone_2;
string h206_spec_care_2;
string h206_site_3;
string h206_address_3;
string h206_phone_3;
string h206_spec_care_3;
string h206_site_4;
string h206_address_4;
string h206_phone_4;
string h206_spec_care_4;

string h206_preparer;
string h206_facility;

string h206_buff;
string h206_def_filename = "";
string h206_base_filename = "";
string h206_def_template_name = "";
bool   h206_using206_template = false;

void h206_cb_setdate()
{
	h206_txt_date_prepared->value(szDate());
}

void h206_cb_settime()
{
	h206_txt_time_prepared->value(szTime());
}

void h206_clear_fields()
{
	h206_name.clear();
	h206_period.clear();
	h206_date_prepared.clear();
	h206_time_prepared.clear();

	h206_location.clear();
	h206_loc_contact.clear();
	h206_team_leader.clear();
	h206_team_contact.clear();

	h206_md_do.clear();
	h206_litters.clear();
	h206_pa_np.clear();
	h206_portable.clear();
	h206_rn_lpn.clear();
	h206_transport.clear();
	h206_tech_cn.clear();
	h206_wheelchairs.clear();
	h206_team_other.clear();
	h206_transport_other.clear();
	h206_meds_1.clear();
	h206_supp_1.clear();
	h206_meds_2.clear();
	h206_supp_2.clear();
	h206_meds_3.clear();
	h206_supp_3.clear();
	h206_meds_4.clear();
	h206_supp_4.clear();
	h206_meds_5.clear();
	h206_supp_5.clear();

	h206_special_instructions.clear();
	h206_preparer.clear();
	h206_facility.clear();

	h206_site_1.clear();
	h206_address_1.clear();
	h206_phone_1.clear();
	h206_spec_care_1.clear();
	h206_site_2.clear();
	h206_address_2.clear();
	h206_phone_2.clear();
	h206_spec_care_2.clear();
	h206_site_3.clear();
	h206_address_3.clear();
	h206_phone_3.clear();
	h206_spec_care_3.clear();
	h206_site_4.clear();
	h206_address_4.clear();
	h206_phone_4.clear();
	h206_spec_care_4.clear();

}

void h206_update_fields()
{
	h206_name = h206_txt_name->value();
	h206_period = h206_txt_op_period->value();
	h206_date_prepared = h206_txt_date_prepared->value();
	h206_time_prepared = h206_txt_time_prepared->value();

	h206_location = h206_txt_location->value();
	h206_loc_contact = h206_txt_loc_contact->value();
	h206_team_leader = h206_txt_team_leader->value();
	h206_team_contact = h206_txt_team_contact->value();

	h206_md_do = h206_txt_md_do->value();
	h206_litters = h206_txt_litters->value();
	h206_pa_np = h206_txt_pa_np->value();
	h206_portable = h206_txt_portable->value();
	h206_rn_lpn = h206_txt_rn_lpn->value();
	h206_transport = h206_txt_transport->value();
	h206_tech_cn = h206_txt_tech_cn->value();
	h206_wheelchairs = h206_txt_wheelchairs->value();
	h206_team_other = h206_txt_team_other->value();
	h206_transport_other = h206_txt_transport_other->value();
	h206_meds_1 = h206_txt_meds_1->value();
	h206_supp_1 = h206_txt_supp_1->value();
	h206_meds_2 = h206_txt_meds_2->value();
	h206_supp_2 = h206_txt_supp_2->value();
	h206_meds_3 = h206_txt_meds_3->value();
	h206_supp_3 = h206_txt_supp_3->value();
	h206_meds_4 = h206_txt_meds_4->value();
	h206_supp_4 = h206_txt_supp_4->value();
	h206_meds_5 = h206_txt_meds_5->value();
	h206_supp_5 = h206_txt_supp_5->value();

	h206_special_instructions = h206_txt_special_instructions->buffer()->text();

	h206_preparer = h206_txt_preparer->value();
	h206_facility = h206_txt_facility->value();

	h206_site_1 = h206_txt_site_1->value();
	h206_address_1 = h206_txt_address_1->value();
	h206_phone_1 = h206_txt_phone_1->value();
	h206_spec_care_1 = h206_txt_spec_care_1->value();
	h206_site_2 = h206_txt_site_2->value();
	h206_address_2 = h206_txt_address_2->value();
	h206_phone_2 = h206_txt_phone_2->value();
	h206_spec_care_2 = h206_txt_spec_care_2->value();
	h206_site_3 = h206_txt_site_3->value();
	h206_address_3 = h206_txt_address_3->value();
	h206_phone_3 = h206_txt_phone_3->value();
	h206_spec_care_3 = h206_txt_spec_care_3->value();
	h206_site_4 = h206_txt_site_4->value();
	h206_address_4 = h206_txt_address_4->value();
	h206_phone_4 = h206_txt_phone_4->value();
	h206_spec_care_4 = h206_txt_spec_care_4->value();

}

void h206_update_form()
{
	h206_txt_name->value(h206_name.c_str());
	h206_txt_op_period->value(h206_period.c_str());
	h206_txt_date_prepared->value(h206_date_prepared.c_str());
	h206_txt_time_prepared->value(h206_time_prepared.c_str());

	h206_txt_location->value(h206_location.c_str());
	h206_txt_loc_contact->value(h206_loc_contact.c_str());
	h206_txt_team_leader->value(h206_team_leader.c_str());
	h206_txt_team_contact->value(h206_team_contact.c_str());

	h206_txt_md_do->value(h206_md_do.c_str());
	h206_txt_litters->value(h206_litters.c_str());
	h206_txt_pa_np->value(h206_pa_np.c_str());
	h206_txt_portable->value(h206_portable.c_str());
	h206_txt_rn_lpn->value(h206_rn_lpn.c_str());
	h206_txt_transport->value(h206_transport.c_str());
	h206_txt_tech_cn->value(h206_tech_cn.c_str());
	h206_txt_wheelchairs->value(h206_wheelchairs.c_str());
	h206_txt_team_other->value(h206_team_other.c_str());
	h206_txt_transport_other->value(h206_transport_other.c_str());
	h206_txt_meds_1->value(h206_meds_1.c_str());
	h206_txt_supp_1->value(h206_supp_1.c_str());
	h206_txt_meds_2->value(h206_meds_2.c_str());
	h206_txt_supp_2->value(h206_supp_2.c_str());
	h206_txt_meds_3->value(h206_meds_3.c_str());
	h206_txt_supp_3->value(h206_supp_3.c_str());
	h206_txt_meds_4->value(h206_meds_4.c_str());
	h206_txt_supp_4->value(h206_supp_4.c_str());
	h206_txt_meds_5->value(h206_meds_5.c_str());
	h206_txt_supp_5->value(h206_supp_5.c_str());

	h206_txt_special_instructions->addstr(h206_special_instructions.c_str());

	h206_txt_preparer->value(h206_preparer.c_str());
	h206_txt_facility->value(h206_facility.c_str());

	h206_txt_site_1->value(h206_site_1.c_str());
	h206_txt_address_1->value(h206_address_1.c_str());
	h206_txt_phone_1->value(h206_phone_1.c_str());
	h206_txt_spec_care_1->value(h206_spec_care_1.c_str());
	h206_txt_site_2->value(h206_site_2.c_str());
	h206_txt_address_2->value(h206_address_2.c_str());
	h206_txt_phone_2->value(h206_phone_2.c_str());
	h206_txt_spec_care_2->value(h206_spec_care_2.c_str());
	h206_txt_site_3->value(h206_site_3.c_str());
	h206_txt_address_3->value(h206_address_3.c_str());
	h206_txt_phone_3->value(h206_phone_3.c_str());
	h206_txt_spec_care_3->value(h206_spec_care_3.c_str());
	h206_txt_site_4->value(h206_site_4.c_str());
	h206_txt_address_4->value(h206_address_4.c_str());
	h206_txt_phone_4->value(h206_phone_4.c_str());
	h206_txt_spec_care_4->value(h206_spec_care_4.c_str());

}

void h206_clear__form()
{
	h206_clear_fields();

	h206_txt_name->value("");
	h206_txt_op_period->value("");
	h206_txt_date_prepared->value("");
	h206_txt_time_prepared->value("");

	h206_txt_location->value("");
	h206_txt_loc_contact->value("");
	h206_txt_team_leader->value("");
	h206_txt_team_contact->value("");

	h206_txt_md_do->value("");
	h206_txt_litters->value("");
	h206_txt_pa_np->value("");
	h206_txt_portable->value("");
	h206_txt_rn_lpn->value("");
	h206_txt_transport->value("");
	h206_txt_tech_cn->value("");
	h206_txt_wheelchairs->value("");
	h206_txt_team_other->value("");
	h206_txt_transport_other->value("");
	h206_txt_meds_1->value("");
	h206_txt_supp_1->value("");
	h206_txt_meds_2->value("");
	h206_txt_supp_2->value("");
	h206_txt_meds_3->value("");
	h206_txt_supp_3->value("");
	h206_txt_meds_4->value("");
	h206_txt_supp_4->value("");
	h206_txt_meds_5->value("");
	h206_txt_supp_5->value("");

	h206_txt_special_instructions->clear();

	h206_txt_preparer->value("");
	h206_txt_facility->value("");

	h206_txt_site_1->value("");
	h206_txt_address_1->value("");
	h206_txt_phone_1->value("");
	h206_txt_spec_care_1->value("");
	h206_txt_site_2->value("");
	h206_txt_address_2->value("");
	h206_txt_phone_2->value("");
	h206_txt_spec_care_2->value("");
	h206_txt_site_3->value("");
	h206_txt_address_3->value("");
	h206_txt_phone_3->value("");
	h206_txt_spec_care_3->value("");
	h206_txt_site_4->value("");
	h206_txt_address_4->value("");
	h206_txt_phone_4->value("");
	h206_txt_spec_care_4->value("");

}

void h206_make_buff()
{
	h206_update_fields();

	h206_buff.append( lineout( h206_tag_name, h206_name ) );
	h206_buff.append( lineout( h206_tag_period, h206_period ) );
	h206_buff.append( lineout( h206_tag_date_prepared, h206_date_prepared ) );
	h206_buff.append( lineout( h206_tag_time_prepared, h206_time_prepared ) );

	h206_buff.append( lineout( h206_tag_location, h206_location));
	h206_buff.append( lineout( h206_tag_loc_contact, h206_loc_contact));
	h206_buff.append( lineout( h206_tag_team_leader, h206_team_leader));
	h206_buff.append( lineout( h206_tag_team_contact, h206_team_contact));

	h206_buff.append( lineout( h206_tag_md_do, h206_md_do));
	h206_buff.append( lineout( h206_tag_litters, h206_litters));
	h206_buff.append( lineout( h206_tag_pa_np, h206_pa_np));
	h206_buff.append( lineout( h206_tag_portable, h206_portable));
	h206_buff.append( lineout( h206_tag_rn_lpn, h206_rn_lpn));
	h206_buff.append( lineout( h206_tag_transport, h206_transport));
	h206_buff.append( lineout( h206_tag_tech_cn, h206_tech_cn));
	h206_buff.append( lineout( h206_tag_wheelchairs, h206_wheelchairs));
	h206_buff.append( lineout( h206_tag_team_other, h206_team_other));
	h206_buff.append( lineout( h206_tag_transport_other, h206_transport_other));
	h206_buff.append( lineout( h206_tag_meds_1, h206_meds_1));
	h206_buff.append( lineout( h206_tag_supp_1, h206_supp_1));
	h206_buff.append( lineout( h206_tag_meds_2, h206_meds_2));
	h206_buff.append( lineout( h206_tag_supp_2, h206_supp_2));
	h206_buff.append( lineout( h206_tag_meds_3, h206_meds_3));
	h206_buff.append( lineout( h206_tag_supp_3, h206_supp_3));
	h206_buff.append( lineout( h206_tag_meds_4, h206_meds_4));
	h206_buff.append( lineout( h206_tag_supp_4, h206_supp_4));
	h206_buff.append( lineout( h206_tag_meds_5, h206_meds_5));
	h206_buff.append( lineout( h206_tag_supp_5, h206_supp_5));

	h206_buff.append( lineout( h206_tag_special_instructions, h206_special_instructions ) );

	h206_buff.append( lineout( h206_tag_preparer, h206_preparer ) );
	h206_buff.append( lineout( h206_tag_facility, h206_facility ) );

	h206_buff.append( lineout( h206_tag_site_1, h206_site_1 ) );
	h206_buff.append( lineout( h206_tag_address_1, h206_address_1 ) );
	h206_buff.append( lineout( h206_tag_phone_1, h206_phone_1 ) );
	h206_buff.append( lineout( h206_tag_spec_care_1, h206_spec_care_1 ) );
	h206_buff.append( lineout( h206_tag_site_2, h206_site_2 ) );
	h206_buff.append( lineout( h206_tag_address_2, h206_address_2 ) );
	h206_buff.append( lineout( h206_tag_phone_2, h206_phone_2 ) );
	h206_buff.append( lineout( h206_tag_spec_care_2, h206_spec_care_2 ) );
	h206_buff.append( lineout( h206_tag_site_3, h206_site_3 ) );
	h206_buff.append( lineout( h206_tag_address_3, h206_address_3 ) );
	h206_buff.append( lineout( h206_tag_phone_3, h206_phone_3 ) );
	h206_buff.append( lineout( h206_tag_spec_care_3, h206_spec_care_3 ) );
	h206_buff.append( lineout( h206_tag_site_4, h206_site_4 ) );
	h206_buff.append( lineout( h206_tag_address_4, h206_address_4 ) );
	h206_buff.append( lineout( h206_tag_phone_4, h206_phone_4 ) );
	h206_buff.append( lineout( h206_tag_spec_care_4, h206_spec_care_4 ) );

}

void h206_read_buffer(string data)
{
	h206_clear_fields();
	read_header(data);

	h206_name = findstr(data, h206_tag_name);
	h206_period = findstr(data, h206_tag_period);
	h206_date_prepared = findstr(data, h206_tag_date_prepared);
	h206_time_prepared = findstr(data, h206_tag_time_prepared);

	h206_location = findstr(data, h206_tag_location);
	h206_loc_contact = findstr(data, h206_tag_loc_contact);
	h206_team_leader = findstr(data, h206_tag_team_leader);
	h206_team_contact = findstr(data, h206_tag_team_contact);

	h206_md_do = findstr(data, h206_tag_md_do);
	h206_litters = findstr(data, h206_tag_litters);
	h206_pa_np = findstr(data, h206_tag_pa_np);
	h206_portable = findstr(data, h206_tag_portable);
	h206_rn_lpn = findstr(data, h206_tag_rn_lpn);
	h206_transport = findstr(data, h206_tag_transport);
	h206_tech_cn = findstr(data, h206_tag_tech_cn);
	h206_wheelchairs = findstr(data, h206_tag_wheelchairs);
	h206_team_other = findstr(data, h206_tag_team_other);
	h206_transport_other = findstr(data, h206_tag_transport_other);
	h206_meds_1 = findstr(data, h206_tag_meds_1);
	h206_supp_1 = findstr(data, h206_tag_supp_1);
	h206_meds_2 = findstr(data, h206_tag_meds_2);
	h206_supp_2 = findstr(data, h206_tag_supp_2);
	h206_meds_3 = findstr(data, h206_tag_meds_3);
	h206_supp_3 = findstr(data, h206_tag_supp_3);
	h206_meds_4 = findstr(data, h206_tag_meds_4);
	h206_supp_4 = findstr(data, h206_tag_supp_4);
	h206_meds_5 = findstr(data, h206_tag_meds_5);
	h206_supp_5 = findstr(data, h206_tag_supp_5);

	h206_special_instructions = findstr(data, h206_tag_special_instructions);

	h206_preparer = findstr(data, h206_tag_preparer);
	h206_facility = findstr(data, h206_tag_facility);

	h206_site_1 = findstr(data, h206_tag_site_1);
	h206_address_1 = findstr(data, h206_tag_address_1);
	h206_phone_1 = findstr(data, h206_tag_phone_1);
	h206_spec_care_1 = findstr(data, h206_tag_spec_care_1);
	h206_site_2 = findstr(data, h206_tag_site_2);
	h206_address_2 = findstr(data, h206_tag_address_2);
	h206_phone_2 = findstr(data, h206_tag_phone_2);
	h206_spec_care_2 = findstr(data, h206_tag_spec_care_2);
	h206_site_3 = findstr(data, h206_tag_site_3);
	h206_address_3 = findstr(data, h206_tag_address_3);
	h206_phone_3 = findstr(data, h206_tag_phone_3);
	h206_spec_care_3 = findstr(data, h206_tag_spec_care_4);
	h206_site_4 = findstr(data, h206_tag_site_4);
	h206_address_4 = findstr(data, h206_tag_address_4);
	h206_phone_4 = findstr(data, h206_tag_phone_4);
	h206_spec_care_4 = findstr(data, h206_tag_spec_care_4);

	h206_update_form();
}

void h206_cb_new()
{
	h206_clear__form();
	clear_header();
	h206_def_filename = ICS_msg_dir;
	h206_def_filename.append("new"HF206_EXT);
	show_filename(h206_def_filename);
	h206_using206_template = false;
}

void h206_cb_import()
{
	fl_alert2("Not implemented");
}

void h206_cb_export()
{
	fl_alert2("Not implemented");
}

void h206_cb_wrap_import(string wrapfilename, string inpbuffer)
{
	h206_clear__form();
	h206_read_buffer(inpbuffer);
	h206_def_filename = ICS_msg_dir;
	h206_def_filename.append(wrapfilename);
	show_filename(h206_def_filename);
	h206_using206_template = false;
}

void h206_cb_wrap_export()
{
	if (h206_base_filename == "new"HF206_EXT || h206_base_filename == "default"HF206_EXT)
		h206_cb_save_as();

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(h206_base_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;
		update_header(true);
		h206_buff.assign(header("<hics206>", true, true));
		h206_make_buff();
		export_wrapfile(h206_base_filename, wrapfilename, h206_buff, pext != ".wrap");
	}
}

void h206_cb_wrap_autosend()
{
	if (h206_base_filename == "new"HF206_EXT || 
		h206_base_filename == "default"HF206_EXT ||
		h206_using206_template == true)
		h206_cb_save_as();

	string wrapfilename = WRAP_auto_dir;
	wrapfilename.append("wrap_auto_file");
	update_header(true);
	h206_buff.assign(header("<hics206>", true, true));
	h206_make_buff();
	export_wrapfile(h206_base_filename, wrapfilename, h206_buff, false);
}

void h206_cb_load_template()
{
	string h206_def_filename = h206_def_template_name;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"HT206_EXT,
			h206_def_filename.c_str());
	if (p) {
		h206_clear__form();
		read_data_file(p);
		h206_def_template_name = p;
		show_filename(h206_def_template_name);
		h206_using206_template = true;
	}
}

void h206_cb_save_template()
{
	if (!h206_using206_template) {
		h206_cb_save_as_template();
		return;
	}
	string h206_def_filename = h206_def_template_name;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"HT206_EXT,
			h206_def_filename.c_str());
	if (p) {
		clear_header();
		h206_write(p);
	}
}

void h206_cb_save_as_template()
{
	string h206_def_filename = h206_def_template_name;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"HT206_EXT,
			h206_def_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		h206_def_template_name = p;
		if (strlen(pext) == 0) h206_def_template_name.append(HT206_EXT);
		remove_spaces_from_filename(h206_def_template_name);
		clear_header();
		h206_write(h206_def_template_name);
		show_filename(h206_def_template_name);
		h206_using206_template = true;
	}
}

void h206_cb_open()
{
	const char *p = FSEL::select(_("Open data file"), "HICS-206\t*"HF206_EXT,
					h206_def_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	h206_clear__form();
	read_data_file(p);
	h206_using206_template = false;
	h206_def_filename = p;
	show_filename(h206_def_filename);
}

void h206_write(string s)
{
	FILE *file206 = fopen(s.c_str(), "w");
	if (!file206) return;
	update_header();
	h206_buff.assign(save_header("<hics206>"));
	h206_make_buff();
	fwrite(h206_buff.c_str(), h206_buff.length(), 1, file206);
	fclose(file206);
}

void h206_cb_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(HF206_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = h206_def_filename;

	p = FSEL::saveas(_("Save data file"), "HICS-206\t*"HF206_EXT,
					newfilename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
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
	h206_def_filename = p;
	if (strlen(pext) == 0) h206_def_filename.append(HF206_EXT);

	remove_spaces_from_filename(h206_def_filename);
	clear_header();
	update_header();
	h206_buff.assign(save_header("<hics206>"));
	h206_write(h206_def_filename);

	h206_using206_template = false;
	show_filename(h206_def_filename);
}

void h206_cb_save()
{
	if (h206_base_filename == "new"HF206_EXT || 
		h206_base_filename == "default"HF206_EXT ||
		h206_using206_template == true) {
		h206_cb_save_as();
		return;
	}
	update_header();
	h206_buff.assign(save_header("<hics206>"));
	h206_write(h206_def_filename);
	h206_using206_template = false;
}

void h206_cb_html()
{
	string fname_name = fl_filename_name(h206_def_filename.c_str());
	size_t p = fname_name.rfind('.');
	if (p != string::npos) fname_name.erase(p);

	string hics206_fname = ICS_dir;
	hics206_fname.append(fname_name);
	hics206_fname.append(".html");

	string html_text = "";

	h206_update_fields();
	string form206 = hics206_html_template;

	replacestr(form206, TITLE, fname_name);
	replacestr(form206, h206_tag_name, h206_name);
	replacestr(form206, h206_tag_date_prepared, h206_date_prepared);
	replacestr(form206, h206_tag_time_prepared, h206_time_prepared);
	replacestr(form206, h206_tag_period, h206_period);

	replacestr(form206, h206_tag_location, h206_location);
	replacestr(form206, h206_tag_loc_contact, h206_loc_contact);
	replacestr(form206, h206_tag_team_leader, h206_team_leader);
	replacestr(form206, h206_tag_team_contact, h206_team_contact);

	replacestr(form206, h206_tag_md_do, h206_md_do);
	replacestr(form206, h206_tag_litters, h206_litters);
	replacestr(form206, h206_tag_pa_np, h206_pa_np);
	replacestr(form206, h206_tag_portable, h206_portable);
	replacestr(form206, h206_tag_rn_lpn, h206_rn_lpn);
	replacestr(form206, h206_tag_transport, h206_transport);
	replacestr(form206, h206_tag_tech_cn, h206_tech_cn);
	replacestr(form206, h206_tag_wheelchairs, h206_wheelchairs);
	replacestr(form206, h206_tag_team_other, h206_team_other);
	replacestr(form206, h206_tag_transport_other, h206_transport_other);
	replacestr(form206, h206_tag_meds_1, h206_meds_1);
	replacestr(form206, h206_tag_supp_1, h206_supp_1);
	replacestr(form206, h206_tag_meds_2, h206_meds_2);
	replacestr(form206, h206_tag_supp_2, h206_supp_2);
	replacestr(form206, h206_tag_meds_3, h206_meds_3);
	replacestr(form206, h206_tag_supp_3, h206_supp_3);
	replacestr(form206, h206_tag_meds_4, h206_meds_4);
	replacestr(form206, h206_tag_supp_4, h206_supp_4);
	replacestr(form206, h206_tag_meds_5, h206_meds_5);
	replacestr(form206, h206_tag_supp_5, h206_supp_5);
	string temp = h206_special_instructions;
	if (progStatus.autowordwrap)
		temp = wordwrap(h206_special_instructions, progStatus.charcount);
	replacestr(form206, h206_tag_special_instructions, temp);
	replacestr(form206, h206_tag_site_1, h206_site_1);
	replacestr(form206, h206_tag_address_1, h206_address_1);
	replacestr(form206, h206_tag_phone_1, h206_phone_1);
	replacestr(form206, h206_tag_spec_care_1, h206_spec_care_1);
	replacestr(form206, h206_tag_site_2, h206_site_2);
	replacestr(form206, h206_tag_address_2, h206_address_2);
	replacestr(form206, h206_tag_phone_2, h206_phone_2);
	replacestr(form206, h206_tag_spec_care_2, h206_spec_care_2);
	replacestr(form206, h206_tag_site_3, h206_site_3);
	replacestr(form206, h206_tag_address_3, h206_address_3);
	replacestr(form206, h206_tag_phone_3, h206_phone_3);
	replacestr(form206, h206_tag_spec_care_3, h206_spec_care_3);
	replacestr(form206, h206_tag_site_4, h206_site_4);
	replacestr(form206, h206_tag_address_4, h206_address_4);
	replacestr(form206, h206_tag_phone_4, h206_phone_4);
	replacestr(form206, h206_tag_spec_care_4, h206_spec_care_4);

	replacestr(form206, h206_tag_preparer, h206_preparer);
	replacestr(form206, h206_tag_facility, h206_facility);

	FILE *file206 = fopen(hics206_fname.c_str(), "w");
	fprintf(file206,"%s", form206.c_str());
	fclose(file206);

	open_url(hics206_fname.c_str());
}

void h206_cb_textout()
{
	string hics206_fname = ICS_dir;
	hics206_fname.append("hics206.txt");

	h206_update_fields();
	string form206 = hics206_text_template;

	replacestr(form206, h206_tag_name, h206_name);
	replacestr(form206, h206_tag_period, h206_period);
	replacestr(form206, h206_tag_date_prepared, h206_date_prepared);
	replacestr(form206, h206_tag_time_prepared, h206_time_prepared);

	replacestr(form206, h206_tag_location, h206_location);
	replacestr(form206, h206_tag_loc_contact, h206_loc_contact);
	replacestr(form206, h206_tag_team_leader, h206_team_leader);
	replacestr(form206, h206_tag_team_contact, h206_team_contact);

	replacestr(form206, h206_tag_md_do, h206_md_do);
	replacestr(form206, h206_tag_litters, h206_litters);
	replacestr(form206, h206_tag_pa_np, h206_pa_np);
	replacestr(form206, h206_tag_portable, h206_portable);
	replacestr(form206, h206_tag_rn_lpn, h206_rn_lpn);
	replacestr(form206, h206_tag_transport, h206_transport);
	replacestr(form206, h206_tag_tech_cn, h206_tech_cn);
	replacestr(form206, h206_tag_wheelchairs, h206_wheelchairs);
	replacestr(form206, h206_tag_team_other, h206_team_other);
	replacestr(form206, h206_tag_transport_other, h206_transport_other);
	replacestr(form206, h206_tag_meds_1, h206_meds_1);
	replacestr(form206, h206_tag_supp_1, h206_supp_1);
	replacestr(form206, h206_tag_meds_2, h206_meds_2);
	replacestr(form206, h206_tag_supp_2, h206_supp_2);
	replacestr(form206, h206_tag_meds_3, h206_meds_3);
	replacestr(form206, h206_tag_supp_3, h206_supp_3);
	replacestr(form206, h206_tag_meds_4, h206_meds_4);
	replacestr(form206, h206_tag_supp_4, h206_supp_4);
	replacestr(form206, h206_tag_meds_5, h206_meds_5);
	replacestr(form206, h206_tag_supp_5, h206_supp_5);

	replacestr(form206, h206_tag_special_instructions, h206_special_instructions);

	replacestr(form206, h206_tag_site_1, h206_site_1);
	replacestr(form206, h206_tag_address_1, h206_address_1);
	replacestr(form206, h206_tag_phone_1, h206_phone_1);
	replacestr(form206, h206_tag_spec_care_1, h206_spec_care_1);
	replacestr(form206, h206_tag_site_2, h206_site_2);
	replacestr(form206, h206_tag_address_2, h206_address_2);
	replacestr(form206, h206_tag_phone_2, h206_phone_2);
	replacestr(form206, h206_tag_spec_care_2, h206_spec_care_2);
	replacestr(form206, h206_tag_site_3, h206_site_3);
	replacestr(form206, h206_tag_address_3, h206_address_3);
	replacestr(form206, h206_tag_phone_3, h206_phone_3);
	replacestr(form206, h206_tag_spec_care_3, h206_spec_care_3);
	replacestr(form206, h206_tag_site_4, h206_site_4);
	replacestr(form206, h206_tag_address_4, h206_address_4);
	replacestr(form206, h206_tag_phone_4, h206_phone_4);
	replacestr(form206, h206_tag_spec_care_4, h206_spec_care_4);

	replacestr(form206, h206_tag_preparer, h206_preparer);
	replacestr(form206, h206_tag_facility, h206_facility);

	FILE *file206 = fopen(hics206_fname.c_str(), "w");
	fprintf(file206,"%s", form206.c_str());
	fclose(file206);

	open_url(hics206_fname.c_str());
}
