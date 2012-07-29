// =====================================================================
//
// redx_5739AA.cxx
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

string s_redx_5739A_nbr;
string s_redx_5739A_name;
string s_redx_5739A_state;
string s_redx_5739A_cnty;
string s_redx_5739A_city;
string s_redx_5739A_date;
string s_redx_5739A_street;
string s_redx_5739A_georef;

string s_redx_5739A_adrs0;
string s_redx_5739A_dwell0;
string s_redx_5739A_base0;
string s_redx_5739A_ds0;
string s_redx_5739A_mj0;
string s_redx_5739A_mn0;
string s_redx_5739A_af0;
string s_redx_5739A_in0;
string s_redx_5739A_un0;
string s_redx_5739A_gd0;

string s_redx_5739A_adrs1;
string s_redx_5739A_dwell1;
string s_redx_5739A_base1;
string s_redx_5739A_ds1;
string s_redx_5739A_mj1;
string s_redx_5739A_mn1;
string s_redx_5739A_af1;
string s_redx_5739A_in1;
string s_redx_5739A_un1;
string s_redx_5739A_gd1;

// could not use real names ... WIN32 barfs
enum QTYPE_5739A { B, S, T, I, F, C, E }; 
// bool, string, text, int, float, character, empty

struct QUAD_5739A { 
	QTYPE_5739A  qtype;  // type of field
	string htmnbr;
	void   *ptr;
	Fl_Widget *widget; };

// singular entries in form
QUAD_5739A redx_QUAD_5739A[] = {
{ S,	":drnbr:",		&s_redx_5739A_nbr,			rdx_5739A_nbr },		// 0
{ S,	":drnam:",		&s_redx_5739A_name,			rdx_5739A_name },		// 1
{ S,	":state:",		&s_redx_5739A_state,		rdx_5739A_state },		// 2
{ S,	":cnty:",		&s_redx_5739A_cnty,			rdx_5739A_cnty },		// 3
{ S,	":city:",		&s_redx_5739A_city,			rdx_5739A_city },		// 4
{ S,	":date:",		&s_redx_5739A_date,			rdx_5739A_date },		// 5
{ S,	":street:",		&s_redx_5739A_street,		rdx_5739A_street },		// 6
{ S,	":georef:",		&s_redx_5739A_georef,		rdx_5739A_georef },		// 7
{ S,	":adrs0:",		&s_redx_5739A_adrs0,		rdx_5739A_adrs0 },		// 8
{ S,	":dwell0:",		&s_redx_5739A_dwell0,		rdx_5739A_dwell0 },		// 9
{ S,	":base0:",		&s_redx_5739A_base0,		rdx_5739A_base0 },		// 10
{ S,	":ds0:",		&s_redx_5739A_ds0,			rdx_5739A_ds0 },		// 11
{ S,	":mj0:",		&s_redx_5739A_mj0,			rdx_5739A_mj0 },		// 12
{ S,	":mn0:",		&s_redx_5739A_mn0,			rdx_5739A_mn0 },		// 13
{ S,	":af0:",		&s_redx_5739A_af0,			rdx_5739A_af0 },		// 14
{ S,	":in0:",		&s_redx_5739A_in0,			rdx_5739A_in0 },		// 15
{ S,	":un0:",		&s_redx_5739A_un0,			rdx_5739A_un0 },		// 16
{ S,	":gd0:",		&s_redx_5739A_gd0,			rdx_5739A_gd0 },		// 17
{ S,	":adrs1:",		&s_redx_5739A_adrs1,		rdx_5739A_adrs1 },		// 18
{ S,	":dwell1:",		&s_redx_5739A_dwell1,		rdx_5739A_dwell1 },		// 19
{ S,	":base1:",		&s_redx_5739A_base1,		rdx_5739A_base1 },		// 20
{ S,	":ds1:",		&s_redx_5739A_ds1,			rdx_5739A_ds1 },		// 21
{ S,	":mj1:",		&s_redx_5739A_mj1,			rdx_5739A_mj1 },		// 22
{ S,	":mn1:",		&s_redx_5739A_mn1,			rdx_5739A_mn1 },		// 23
{ S,	":af1:",		&s_redx_5739A_af1,			rdx_5739A_af1 },		// 24
{ S,	":in1:",		&s_redx_5739A_in1,			rdx_5739A_in1 },		// 25
{ S,	":un1:",		&s_redx_5739A_un1,			rdx_5739A_un1 },		// 26
{ S,	":gd1:",		&s_redx_5739A_gd1,			rdx_5739A_gd1 },		// 27
{ E,	"",				NULL,							NULL }
};

string buffredx_5739A;
string def_redx_5739A_filename = "";
string base_redx_5739A_filename = "";
string def_redx_5739A_TemplateName = "";

bool using_redx_5739A_template = false;
static bool fields_initialized = false;

// required to initialize the control pointers in the QUAD_5739A array

static void init_widgets_5739A()
{
	redx_QUAD_5739A[0].widget  = rdx_5739A_nbr;
	redx_QUAD_5739A[1].widget  = rdx_5739A_name;
	redx_QUAD_5739A[2].widget  = rdx_5739A_state;
	redx_QUAD_5739A[3].widget  = rdx_5739A_cnty;
	redx_QUAD_5739A[4].widget  = rdx_5739A_city;
	redx_QUAD_5739A[5].widget  = rdx_5739A_date;
	redx_QUAD_5739A[6].widget  = rdx_5739A_street;
	redx_QUAD_5739A[7].widget  = rdx_5739A_georef;

	redx_QUAD_5739A[8].widget  = rdx_5739A_adrs0;
	redx_QUAD_5739A[9].widget  = rdx_5739A_dwell0;
	redx_QUAD_5739A[10].widget  = rdx_5739A_base0;
	redx_QUAD_5739A[11].widget  = rdx_5739A_ds0;
	redx_QUAD_5739A[12].widget  = rdx_5739A_mj0;
	redx_QUAD_5739A[13].widget  = rdx_5739A_mn0;
	redx_QUAD_5739A[14].widget  = rdx_5739A_af0;
	redx_QUAD_5739A[15].widget  = rdx_5739A_in0;
	redx_QUAD_5739A[16].widget  = rdx_5739A_un0;
	redx_QUAD_5739A[17].widget  = rdx_5739A_gd0;

	redx_QUAD_5739A[18].widget  = rdx_5739A_adrs1;
	redx_QUAD_5739A[19].widget  = rdx_5739A_dwell1;
	redx_QUAD_5739A[20].widget  = rdx_5739A_base1;
	redx_QUAD_5739A[21].widget  = rdx_5739A_ds1;
	redx_QUAD_5739A[22].widget  = rdx_5739A_mj1;
	redx_QUAD_5739A[23].widget  = rdx_5739A_mn1;
	redx_QUAD_5739A[24].widget  = rdx_5739A_af1;
	redx_QUAD_5739A[25].widget  = rdx_5739A_in1;
	redx_QUAD_5739A[26].widget  = rdx_5739A_un1;
	redx_QUAD_5739A[27].widget  = rdx_5739A_gd1;

	fields_initialized = true;
}

//enum QTYPE_5739A { B, S, T, I, F, C, E }; 
// bool, string, text, int, float, character, empty

void clearQUAD_5739A(QUAD_5739A *p)
{
	QTYPE_5739A qt = E;
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

void clear_redx_5739Afields()
{
	if (!fields_initialized) init_widgets_5739A();
	clearQUAD_5739A(redx_QUAD_5739A);
}

bool checkQUAD_5739A(QUAD_5739A *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	QTYPE_5739A qt = E;
	while ((qt = p->qtype) != E) {
		if (p->widget == NULL) return false;
		switch (qt) {
			case B:
				if (*((bool *)(p->ptr)) != ((Fl_Check_Button *)p->widget)->value())
					return true;;
				break;
			case S:
				if (*((string *)(p->ptr)) != ((Fl_Input2 *)p->widget)->value())
					return true;
				break;
			case T:
				if (*((string *)(p->ptr)) != ((FTextEdit *)p->widget)->buffer()->text())
					return true;
				break;
			case C:
				c = ' ';
				if (((Fl_Input2 *)p->widget)->value()[0])
					c = ((Fl_Input2 *)p->widget)->value()[0];
				if (*((char *)(p->ptr)) != c)
					return true;
				break;
			case I:
				i = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%d", &i);
				if (*((int *)(p->ptr)) != i)
					return true;
				break;
			case F:
				f = 0;
				if (((Fl_Input2 *)p->widget)->value()[0])
					sscanf( ((Fl_Input2 *)p->widget)->value(), "%f", &f);
				if (*((float *)(p->ptr)) != f)
					return true;
				break;
			case E:
			default: return false;
		}
		p++;
	}
	return false;
}

bool check_redx_5739Afields()
{
	return checkQUAD_5739A(redx_QUAD_5739A);
}

void updateQUAD_5739A(QUAD_5739A *p)
{
	int i = 0;
	float f = 0;
	char c = ' ';
	QTYPE_5739A qt = E;
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

void update_redx_5739Afields()
{
	if (!fields_initialized) init_widgets_5739A();
	updateQUAD_5739A(redx_QUAD_5739A);
}

void updateFORM_5739A(QUAD_5739A *p)
{
	char val[20];
	QTYPE_5739A qt = E;
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

void update_redx_5739Aform()
{
	if (!fields_initialized) init_widgets_5739A();
	updateFORM_5739A(redx_QUAD_5739A);
}

void clear_redx_5739A_form()
{
	clear_redx_5739Afields();
	update_redx_5739Aform();
}

static string mbuff;

void make_buffQUAD_5739A(QUAD_5739A *p)
{
	string one = "1"; string zero = "0";
	string sval = " ";
	char szval[20];
	QTYPE_5739A qt = E;
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

void make_buffredx_5739A(bool compress = false)
{
	mbuff.clear();
	make_buffQUAD_5739A(redx_QUAD_5739A);
	if (compress) compress_maybe(mbuff);
	buffredx_5739A.append(mbuff);
}

void readQUAD_5739A(string data, QUAD_5739A *p)
{
	int i = 0;
	float f;
	QTYPE_5739A qt = E;
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

void read_redx_5739A_buffer(string data)
{
	clear_redx_5739Afields();
	read_header(data);

	readQUAD_5739A (data, redx_QUAD_5739A);
	update_redx_5739Aform();
}

void cb_redx_5739A_new()
{
	if (check_redx_5739Afields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 1) {
			update_header(CHANGED);
			cb_redx_5739A_save();
		}
	}
	clear_redx_5739A_form();
	clear_header();
	def_redx_5739A_filename = ICS_msg_dir;
	def_redx_5739A_filename.append("new"FREDX5739A_EXT);
	show_filename(def_redx_5739A_filename);
	using_redx_5739A_template = false;
}

void cb_redx_5739A_import()
{
	fl_alert2("Not implemented");
}

void cb_redx_5739A_export()
{
	fl_alert2("Not implemented");
}

void cb_redx_5739A_wrap_import(string wrapfilename, string inpbuffer)
{
	clear_redx_5739A_form();
	read_redx_5739A_buffer(inpbuffer);
	def_redx_5739A_filename = ICS_msg_dir;
	def_redx_5739A_filename.append(wrapfilename);
	show_filename(def_redx_5739A_filename);
	using_redx_5739A_template = false;
}

void cb_redx_5739A_wrap_export()
{
	if (check_redx_5739Afields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_5739Afields();

	if (base_redx_5739A_filename == "new"FREDX5739A_EXT || base_redx_5739A_filename == "default"FREDX5739A_EXT)
		if (!cb_redx_5739A_save_as()) return;

	string wrapfilename = WRAP_send_dir;
	wrapfilename.append(base_redx_5739A_filename);
	wrapfilename.append(".wrap");
	const char *p = FSEL::saveas(
			"Save as wrap file",
			"Wrap file\t*.{wrap,WRAP}",
			wrapfilename.c_str());
	if (p) {
		string pext = fl_filename_ext(p);
		wrapfilename = p;

		update_header(FROM);
		buffredx_5739A.assign(header("<redx_5739A>"));
		make_buffredx_5739A(true);
		export_wrapfile(base_redx_5739A_filename, wrapfilename, buffredx_5739A, pext != ".wrap");

		buffredx_5739A.assign(header("<redx_5739A>"));
		make_buffredx_5739A(false);
		write_redx_5739A(def_redx_5739A_filename);
	}
}

void cb_redx_5739A_wrap_autosend()
{
	if (check_redx_5739Afields()) {
		if (fl_choice2("Form modified, save?", "No", "Yes", NULL) == 0)
			return;
		update_header(CHANGED);
	}
	update_redx_5739Afields();

	if (base_redx_5739A_filename == "new"FREDX5739A_EXT || base_redx_5739A_filename == "default"FREDX5739A_EXT)
		if (!cb_redx_5739A_save_as()) return;

	update_header(FROM);
	buffredx_5739A.assign(header("<redx_5739A>"));
	make_buffredx_5739A(true);
	xfr_via_socket(base_redx_5739A_filename, buffredx_5739A);

	buffredx_5739A.assign(header("<redx_5739A>"));
	make_buffredx_5739A(false);
	write_redx_5739A(def_redx_5739A_filename);
}

void cb_redx_5739A_load_template()
{
	string def_redx_5739A_filename = def_redx_5739A_TemplateName;
	const char *p = FSEL::select(
			"Open template file",
			"Template file\t*"TREDX5739A_EXT,
			def_redx_5739A_filename.c_str());
	if (p) {
		clear_redx_5739A_form();
		read_data_file(p);
		def_redx_5739A_TemplateName = p;
		show_filename(def_redx_5739A_TemplateName);
		using_redx_5739A_template = true;
	}
}

void cb_redx_5739A_save_template()
{
	if (!using_redx_5739A_template) {
		cb_redx_5739A_save_as_template();
		return;
	}
	string def_redx_5739A_filename = def_redx_5739A_TemplateName;
	const char *p = FSEL::saveas(
			"Save template file",
			"Template file\t*"TREDX5739A_EXT,
			def_redx_5739A_filename.c_str());
	if (p) {
		update_header(CHANGED);
		update_redx_5739Afields();
		buffredx_5739A.assign(header("<redx_5739A>"));
		make_buffredx_5739A();
		write_redx_5739A(p);
	}
}

void cb_redx_5739A_save_as_template()
{
	string def_redx_5739A_filename = def_redx_5739A_TemplateName;
	const char *p = FSEL::saveas(
			"Save as template file",
			"Template file\t*"TREDX5739A_EXT,
			def_redx_5739A_filename.c_str());
	if (p) {
		const char *pext = fl_filename_ext(p);
		def_redx_5739A_TemplateName = p;
		if (strlen(pext) == 0) def_redx_5739A_TemplateName.append(TREDX5739A_EXT);
		remove_spaces_from_filename(def_redx_5739A_TemplateName);

		clear_header();
		update_header(CHANGED);
		update_redx_5739Afields();
		buffredx_5739A.assign(header("<redx_5739A>"));
		make_buffredx_5739A();
		write_redx_5739A(def_redx_5739A_TemplateName);

		show_filename(def_redx_5739A_TemplateName);
		using_redx_5739A_template = true;
	}
}

void cb_redx_5739A_open()
{
	const char *p = FSEL::select(_("Open data file"), "ICS-redx_5739A\t*"FREDX5739A_EXT,
					def_redx_5739A_filename.c_str());
	if (!p) return;
	if (strlen(p) == 0) return;
	clear_redx_5739A_form();
	read_data_file(p);
	using_redx_5739A_template = false;
	def_redx_5739A_filename = p;
	show_filename(def_redx_5739A_filename);
}

void write_redx_5739A(string s)
{
	FILE *fileredx_5739A = fopen(s.c_str(), "w");
	if (!fileredx_5739A) return;

	fwrite(buffredx_5739A.c_str(), buffredx_5739A.length(), 1, fileredx_5739A);
	fclose(fileredx_5739A);
}

bool cb_redx_5739A_save_as()
{
	const char *p;
	string newfilename;

	string name = named_file();
	if (!name.empty()) {
		name.append(FREDX5739A_EXT);
		newfilename = ICS_msg_dir;
		newfilename.append(name);
	} else
		newfilename = def_redx_5739A_filename;

	p = FSEL::saveas(_("Save data file"), "ICS-redx_5739A\t*"FREDX5739A_EXT,
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
	def_redx_5739A_filename = p;
	if (strlen(pext) == 0) def_redx_5739A_filename.append(FREDX5739A_EXT);

	remove_spaces_from_filename(def_redx_5739A_filename);

	update_header(NEW);
	update_redx_5739Afields();
	buffredx_5739A.assign(header("<redx_5739A>"));
	make_buffredx_5739A();
	write_redx_5739A(def_redx_5739A_filename);

	using_redx_5739A_template = false;
	show_filename(def_redx_5739A_filename);
	return true;
}

void cb_redx_5739A_save()
{
	if (base_redx_5739A_filename == "new"FREDX5739A_EXT || 
		base_redx_5739A_filename == "default"FREDX5739A_EXT ||
		using_redx_5739A_template == true) {
		cb_redx_5739A_save_as();
		return;
	}

	if (check_redx_5739Afields()) update_header(CHANGED);
	update_redx_5739Afields();
	buffredx_5739A.assign(header("<redx_5739A>"));
	make_buffredx_5739A();
	write_redx_5739A(def_redx_5739A_filename);

	using_redx_5739A_template = false;
}

void quad_to_html_5739A( string &target, QUAD_5739A *p)
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

void cb_redx_5739A_html()
{
	string name_name = fl_filename_name(def_redx_5739A_filename.c_str());
	size_t p = name_name.rfind('.');
	if (p != string::npos) name_name.erase(p);

	string redx_5739A_name = ICS_dir;
	redx_5739A_name.append(name_name);
	redx_5739A_name.append(".html");

	update_redx_5739Afields();
	string formredx_5739A = redx_5739A_html_template;

	replacestr(formredx_5739A, TITLE, name_name);

	quad_to_html_5739A (formredx_5739A, redx_QUAD_5739A);

	FILE *fileredx_5739A = fopen(redx_5739A_name.c_str(), "w");
	fprintf(fileredx_5739A,"%s", formredx_5739A.c_str());
	fclose(fileredx_5739A);

	open_url(redx_5739A_name.c_str());
}

void cb_5739A_msg_type()
{
	if (selected_form == REDX5739A ) {
		show_filename(def_redx_5739A_filename);
	} else {
		show_filename(def_rg_filename);
	}
}

void quad_to_text( string &target, QUAD_5739A *p)
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

void strip_text_5739A( string &target )
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

void cb_redx_5739A_textout()
{
	string redx_5739A_name = ICS_dir;
	redx_5739A_name.append("redx_5739A.txt");

	update_redx_5739Afields();
	string formredx_5739A = redx_5739A_text_template;

	quad_to_text (formredx_5739A, redx_QUAD_5739A);

	strip_text_5739A (formredx_5739A);

	FILE *fileredx_5739A = fopen(redx_5739A_name.c_str(), "w");
	fprintf(fileredx_5739A,"%s", formredx_5739A.c_str());
	fclose(fileredx_5739A);

	open_url(redx_5739A_name.c_str());
}

