// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include "gettext.h"
#include "flmsg_dialog.h"
#include "status.h"
#include "flmsg.h"
#include "fileselect.h"
#include "debug.h"

#include "transfer.h"
#include "time_table.h"
#include "xml_io.h"

//======================================================================

Fl_Browser			*brwsOptions = (Fl_Browser *)0;
Fl_Return_Button	*btnCloseOptions = (Fl_Return_Button *)0;

Fl_Output			*txt_formname = (Fl_Output *)0;

Fl_Output			*txt_filename = (Fl_Output *)0;
Fl_Input			*drop_file = (Fl_Input *)0;

Fl_Group			*controls = (Fl_Group *)0;

int					tab_top;

Fl_Browser			*select_arl = (Fl_Browser *)0;
Fl_Input2			*txt_arl_fill1 = (Fl_Input2 *)0;
Fl_Input2			*txt_arl_fill2 = (Fl_Input2 *)0;
Fl_Input2			*txt_arl_fill3 = (Fl_Input2 *)0;
Fl_Input2			*txt_arl_fill4 = (Fl_Input2 *)0;
Fl_Button			*btn_arl_cancel = (Fl_Button *)0;
Fl_Button			*btn_arl_add = (Fl_Button *)0;
FTextEdit			*arl_text = (FTextEdit *)0;
Fl_Check_Button		*btnInsertX = (Fl_Check_Button *)0;

Fl_Round_Button		*btn_dtformat0 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_dtformat1 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_dtformat2 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_dtformat3 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format0 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format1 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format2 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format3 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format4 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format5 = (Fl_Round_Button *)0;

Fl_Input2			*txt_my_call = (Fl_Input2 *)0;
Fl_Input2			*txt_my_tel = (Fl_Input2 *)0;
Fl_Input2			*txt_my_name = (Fl_Input2 *)0;
Fl_Input2			*txt_my_addr = (Fl_Input2 *)0;
Fl_Input2			*txt_my_city = (Fl_Input2 *)0;
Fl_Input2			*txt_my_email = (Fl_Input2 *)0;
Fl_Spinner			*cnt_wpl = (Fl_Spinner *)0;
Fl_Check_Button		*btn_rgnbr_fname = (Fl_Check_Button *)0;
Fl_Check_Button		*btn_arl_desc = (Fl_Check_Button *)0;
Fl_Input2			*txt_rgnbr = (Fl_Input2 *)0;

Fl_Check_Button		*btn_open_on_export = (Fl_Check_Button *)0;
Fl_Check_Button		*btn_call_fname = (Fl_Check_Button *)0;
Fl_Check_Button		*btn_dt_fname = (Fl_Check_Button *)0;
Fl_Check_Button		*btn_sernbr_fname = (Fl_Check_Button *)0;
Fl_Input2			*txt_sernbr = (Fl_Input2 *)0;

Fl_Input2			*txt_mars_roster_file = (Fl_Input2 *)0;

Fl_Input2*			txt_hdr_from = (Fl_Input2 *)0;
Fl_Input2*			txt_hdr_edit = (Fl_Input2 *)0;

Fl_Input2 * txt_socket_addr = (Fl_Input2 *)0;
Fl_Input2 * txt_socket_port = (Fl_Input2 *)0;
Fl_Button * btn_close_socket_dialog = (Fl_Button *)0;

Fl_Check_Button *btnAutoWordWrap = 0;
Fl_Check_Button *btn_use_compression = 0;
Fl_Button *btn_estimate = 0;

Fl_ComboBox *encoders = 0;

Fl_Counter *cntCharCount = 0;

Fl_ComboBox	*cbo_modes = 0;
Fl_Output *txt_xfr_size_time = 0;

int transfer_size;

void cb_btn_transfer_size(Fl_Button *, void*);

struct st_modes {string s_mode; float latency; };
struct st_modes s_basic_modes[] = {
	{"DOMX22",          0.0}, {"DOMX44",       0.0},  {"DOMX88",      0.0},

	{"MFSK16",          0.0}, {"MFSK22",       0.0},  {"MFSK31",      0.0},
	{"MFSK32",          0.0}, {"MFSK64",       0.0},  {"MFSK128",     0.0},
	{"MFSK64L",         6.5}, {"MFSK128L",     6.5},

	{"MT63-500S",       6.4}, {"MT63-1KS",     3.2},  {"MT63-2KS",    3.2},
	{"MT63-500L",      12.8}, {"MT63-1KL",     6.4},  {"MT63-2KL",    1.6},

	{"BPSK125",         0.0}, {"BPSK250",      0.0},
	{"BPSK500",         0.0}, {"BPSK1000",     0.0},

	{"PSK63RC4",        0.0}, {"PSK63RC5",     0.0},  {"PSK63RC10",   0.0},
	{"PSK63RC20",       0.0}, {"PSK63RC32",    0.0},

	{"PSK125C12",       0.0},

	{"PSK125R",         0.0}, {"PSK125RC4",    0.0},  {"PSK125RC5",   0.0},
	{"PSK125RC10",      0.0}, {"PSK125RC12",   0.0},  {"PSK125RC16",  0.0},

	{"PSK250C6",        0.0},
	
	{"PSK250R",         0.0}, {"PSK250RC2",    0.0},  {"PSK250RC3",   0.0},
	{"PSK250RC5",       0.0}, {"PSK250RC6",    0.0},  {"PSK250RC7",   0.0},

	{"PSK500C2",        0.0}, {"PSK500C4",     0.0},
	{"PSK500R",         0.0}, {"PSK500RC2",    0.0},  {"PSK500RC3",   0.0},
	{"PSK500RC4",       0.0},

	{"PSK800C2",        0.0}, {"PSK800RC2",    0.0},

	{"PSK1000C2",       0.0}, {"PSK1000R",     0.0},  {"PSK1000RC2",  0.0},

	{"Olivia-4-250",    0.0}, {"Olivia-8-250", 0.0},  {"Olivia-4-500",0.0 },
	{"Olivia-8-500",    0.0}, {"Olivia-16-500",0.0},  {"Olivia-8-1K", 0.0 },
	{"Olivia-16-1K",    0.0}, {"Olivia-32-1K", 0.0},  {"Olivia-64-2K",0.0 },

	{"THOR16",          0.0}, {"THOR22",       0.0},
	{"THOR25x4",        0.0}, {"THOR50x1",     0.0}, {"THOR50x2",     0.0},
	{"THOR100",         0.0}
};

int num_modes = (int)(sizeof(s_basic_modes) / sizeof(st_modes));

// reported by get_modes
/*
 NULL|CW|
 CTSTIA|DOMEX4|DOMEX5|DOMEX8|DOMX11|DOMX16|DOMX22|DOMX44|DOMX88|
 FELDHELL|SLOWHELL|HELLX5|HELLX9|FSKHELL|FSKH105|HELL80|
 MFSK8|MFSK16|MFSK32|MFSK4|MFSK11|MFSK22|MFSK31|MFSK64|MFSK128||MFSK64L|MFSK128L|
 WEFAX576|WEFAX288|NAVTEX|SITORB|
 MT63-500S|MT63-1KS|MT63-2KS|
 MT63-500L|MT63-1KL|MT63-2KL|
 BPSK31|BPSK63|BPSK63F|BPSK125|BPSK250|BPSK500|
 QPSK31|QPSK63|QPSK125|QPSK250|QPSK500|
 PSK125R|PSK250R|PSK500R|BPSK1000|PSK1000R|
 OLIVIA|Olivia-4-250|Olivia-8-250|Olivia-4-500|Olivia-8-500|
 Olivia-16-500|Olivia-8-1K|Olivia-16-1K|Olivia-32-1K|Olivia-64-2K|
 RTTY|
 THOR4|THOR5|THOR8|THOR11|THOR16|THOR22|THOR25X4|THOR50X1|THOR50X2|THOR100|
 THROB1|THROB2|THROB4|THRBX1|THRBX2|THRBX4|
 PSK63RC4|PSK63RC5|PSK63RC10|PSK63RC20|PSK63RC32|
 PSK125RC4|PSK125RC5|PSK125RC10|PSK125C12|PSK125RC12|PSK125RC16|
 PSK250C6|PSK250RC2|PSK250RC3|PSK250RC5|PSK250RC6|PSK250RC7|
 PSK500C2|PSK500C4|PSK500RC2|PSK500RC3|PSK500RC4|
 PSK800C2|PSK800RC2|
 PSK1000C2|PSK1000RC2|
 SSB|WWV|ANALYSIS|
 */

st_modes s_modes[100];

string valid_modes;

void update_cbo_modes(string &fldigi_modes)
{
	for (int n = 0; n < 100; n++) { 
		s_modes[n].s_mode = ""; 
		s_modes[n].latency = 0;
	}
	valid_modes.clear();
	cbo_modes->clear();
	int j = 0;
	for (int i = 0; i < num_modes; i++) {
		if (fldigi_modes.find(s_basic_modes[i].s_mode) != string::npos) {
			s_modes[j] = s_basic_modes[i];
			cbo_modes->add(s_modes[j].s_mode.c_str()); 
			valid_modes.append(s_modes[j].s_mode).append("|");
			j++;
		}
	}
	cbo_modes->index(progStatus.selected_mode);
}

void init_cbo_modes()
{
	string min_modes;
	min_modes.assign("DOMX22|DOMX44|DOMX88");
	min_modes.append("MFSK16|MFSK22|MFSK31|MFSK32|MFSK64|MFSK128|MFSK64L|MFSK128L");
	min_modes.append("MT63-500S|MT63-1KS|MT63-2KS|MT63-500L|MT63-1KL|MT63-2KL");
	min_modes.append("BPSK125|BPSK250|BPSK500|BPSK1000");
	min_modes.append("PSK63RC4|PSK63RC5|PSK63RC10|PSK63RC20|PSK63RC32");
	min_modes.append("PSK125C12|PSK125R|PSK125RC4|PSK125RC5|PSK125RC10|PSK125RC12|PSK125RC16");
	min_modes.append("PSK250C6|PSK250R|PSK250RC2|PSK250RC3|PSK250RC5|PSK250RC6|PSK250RC7");
	min_modes.append("PSK500C2|PSK500C4|PSK500R|PSK500RC2|PSK500RC3|PSK500RC4");
	min_modes.append("PSK800C2|PSK800RC2");
	min_modes.append("PSK1000C2|PSK1000R|PSK1000RC2");
	min_modes.append("Olivia-4-250|Olivia-8-250");
	min_modes.append("Olivia-4-500|Olivia-8-500|Olivia-16-500");
	min_modes.append("Olivia-8-1K|Olivia-16-1K");
	min_modes.append("Olivia-32-1K|Olivia-64-2K");
	min_modes.append("THOR16|THOR22|THOR25x4|THOR50x1|THOR50x2|THOR100");
	update_cbo_modes(min_modes);
}

bool valid_mode_check(string &md)
{
	return (valid_modes.find(md) != string::npos);
}

void init_encoders()
{
	encoders->clear();
	encoders->add("base64");
	encoders->add("base128");
	encoders->add("base256");
	encoders->index(progStatus.encoder);
}

void clear_estimate() {
	transfer_size = 0;
	txt_xfr_size_time->value("");
}

void estimate() {
	static char sz_xfr_size[20];
	float xfr_time = 0, overhead;

	transfer_size = eval_transfer_size();
	if (transfer_size == 0) {
		txt_xfr_size_time->value("");
		return;
	}

	xfr_time = seconds_from_c_string(cbo_modes->value(), evalstr.c_str(), transfer_size, &overhead);
	xfr_time += overhead;

	if (xfr_time < 60)
		snprintf(sz_xfr_size, sizeof(sz_xfr_size), "%d bytes / %d secs",
			transfer_size, (int)(xfr_time + 0.5));
	else
		snprintf(sz_xfr_size, sizeof(sz_xfr_size), "%d bytes / %d m %d s",
			transfer_size,
			(int)(xfr_time / 60), ((int)xfr_time) % 60);
	txt_xfr_size_time->value(sz_xfr_size);

}

//======================================================================

static void cb_mnu_folders(Fl_Menu_*, void*) {
  cb_folders();
}

static void cb_mnuNew(Fl_Menu_*, void*) {
  cb_new();
}

static void cb_mnuOpen(Fl_Menu_*, void*) {
  cb_open();
}

static void cb_mnuSave(Fl_Menu_*, void*) {
  cb_save();
}

static void cb_mnuSaveAs(Fl_Menu_*, void*) {
  cb_save_as();
}

static void cb_mnu_html(Fl_Menu_*, void*) {
  cb_html();
}

static void cb_mnu_html_fcopy(Fl_Menu_*, void*) {
  cb_html_fcopy();
}

static void cb_mnu_text(Fl_Menu_*, void*) {
  cb_text();
}

static void cb_mnu_qimport(Fl_Menu_*, void*) {
  cb_import();
}

static void cb_mnu_qexport(Fl_Menu_*, void*) {
  cb_export();
}

static void cb_mnuWrapImport(Fl_Menu_*, void*) {
  cb_wrap_import();
}

static void cb_mnuWrapExport(Fl_Menu_*, void*) {
  cb_wrap_export();
}

static void cb_mnuAutoSend(Fl_Menu_*, void*) {
  cb_wrap_autosend();
}

static void cb_mnuExit(Fl_Menu_*, void*) {
  cb_exit();
}

static void cb_mnu_load_template(Fl_Menu_*, void*) {
  cb_load_template();
}

static void cb_mnu_save_template(Fl_Menu_*, void*) {
  cb_save_template();
}

static void cb_mnu_save_as_template(Fl_Menu_*, void*) {
  cb_save_as_template();
}

static void cb_mnuPersonalConfig(Fl_Menu_ *, void*) {
	cb_config_personal();
}

static void cb_mnuDateTimeConfig(Fl_Menu_ *, void*) {
	cb_config_date_time();
}

static void cb_mnuConfigRadiogram(Fl_Menu_ *, void*) {
	cb_config_radiogram();
}

static void cb_mnuConfigFiles(Fl_Menu_*, void*) {
  cb_config_files();
}

static void cb_mnuConfigSocket(Fl_Menu_ *, void*) {
	cb_config_socket();
}

static void cb_mnuOptions(Fl_Menu_*, void*) {
  showoptions();
}

static void cb_mnuHeaders(Fl_Menu_*, void*) {
	string tmp = hdr_from;
	while (tmp.length() && tmp[0] == '\n') tmp.erase(0,1);
	txt_hdr_from->value(tmp.c_str());

	tmp = hdr_edit;
	while (tmp.length() && tmp[0] == '\n') tmp.erase(0,1);
	txt_hdr_edit->value(tmp.c_str());
	header_window->show();
}

static void cb_mnuEvents(Fl_Menu_*, void*) {
	debug::show();
}

static void cb_mnuOnLineHelp(Fl_Menu_*, void*) {
  show_help();
}

static void cb_mnuAbout(Fl_Menu_*, void*) {
  cb_About();
}

int mICS203 = ICS203;
int mICS205 = ICS205;
int mICS205A = ICS205A;
int mICS206 = ICS206;
int mICS213 = ICS213;
int mICS214 = ICS214;
int mICS216 = ICS216;
int mICS309 = ICS309;
int mHICS203 = HICS203;
int mHICS206 = HICS206;
int mHICS213 = HICS213;
int mHICS214 = HICS214;
int mIARU = IARU;
int mRADIOGRAM = RADIOGRAM;
int mPLAINTEXT = PLAINTEXT;
int mBLANK = BLANK;
int mCSV = CSV;
int mMARSDAILY = MARSDAILY;
int mMARSINEEI = MARSINEEI;
int mMARSNET = MARSNET;
int mMARSARMY = MARSARMY;
int mMARSNAVY = MARSNAVY;
int mREDXSNW = REDXSNW;
int mREDX5739 = REDX5739;
int mREDX5739A = REDX5739A;
int mREDX5739B = REDX5739B;
int mWXHC = WXHC;
int mSEVEREWX = SEVEREWX;
int mSTORMREP = STORMREP;
int mCAP105 = CAP105;
int mCAP110 = CAP110;
int mTRANSFER = TRANSFER;

Fl_Group *oldtab = (Fl_Group *)0;

void select_form(int form)
{
	if (oldtab) oldtab->hide();
	if (tab_dnd->visible()) tab_dnd->hide();
	switch (form) {
		case PLAINTEXT:
			oldtab = tab_plaintext;
			tab_plaintext->show();
			txt_formname->value(_("Plaintext message"));
			show_filename(def_pt_filename);
			break;
		case ICS203:
			oldtab = tab_ics203;
			tab_ics203->show();
			txt_formname->value(_("ICS-203 report"));
			show_filename(def_203_filename);
			break;
		case ICS205:
			oldtab = tab_ics205;
			tab_ics205->show();
			txt_formname->value(_("ICS-205 report"));
			show_filename(def_205_filename);
			break;
		case ICS205A:
			oldtab = tab_ics205a;
			tab_ics205a->show();
			txt_formname->value(_("ICS-205A report"));
			show_filename(def_205a_filename);
			break;
		case ICS206:
			oldtab = tab_ics206;
			tab_ics206->show();
			tab_ics206_type->value(tab_206_med_plan);
			txt_formname->value(_("ICS-206 report"));
			show_filename(def_206_filename);
			break;
		case ICS213:
			oldtab = tab_ics213;
			tab_ics213->show();
			tab_ics213_type->value(tab_213_originator);
			txt_formname->value(_("ICS-213 report"));
			show_filename(def_213_filename);
			break;
		case ICS214:
			oldtab = tab_ics214;
			tab_ics214->show();
			tab_ics214_type->value(tab_214_1);
			txt_formname->value(_("ICS-214 report"));
			show_filename(def_214_filename);
			break;
		case ICS216:
			oldtab = tab_ics216;
			tab_ics216->show();
			tab_ics216_type->value(tab_216_1);
			txt_formname->value(_("ICS-216 report"));
			show_filename(def_216_filename);
			break;
		case ICS309:
			oldtab = tab_ics309;
			tab_ics309->show();
			tab_ics309_type->value(tab_309_1);
			txt_formname->value(_("ICS-309 report"));
			show_filename(def_309_filename);
			break;
		case MARSDAILY:
			oldtab = tab_mars_daily;
			tab_mars_daily->show();
			txt_formname->value(_("MARS daily report"));
			show_filename(def_mars_daily_filename);
			break;
		case MARSINEEI:
			oldtab = tab_mars_ineei;
			tab_mars_ineei->show();
			txt_formname->value(_("MARS IN/EEI report"));
			show_filename(def_mars_ineei_filename);
			break;
		case MARSNET:
			oldtab = tab_mars_net;
			tab_mars_net->show();
			txt_formname->value(_("MARS Net report"));
			show_filename(def_mars_net_filename);
			break;
		case MARSARMY:
			oldtab = tab_mars_army;
			tab_mars_army->show();
			txt_formname->value(_("MARS Army message"));
			show_filename(def_mars_army_filename);
			break;
		case MARSNAVY:
			oldtab = tab_mars_navy;
			tab_mars_navy->show();
			txt_formname->value(_("MARS Navy message"));
			show_filename(def_mars_navy_filename);
			break;
		case WXHC:
			oldtab = tab_wxhc;
			tab_wxhc->show();
			txt_formname->value(_("Hurricane Report"));
			show_filename(def_wxhc_filename);
			break;
		case SEVEREWX:
			oldtab = tab_severe_wx;
			tab_severe_wx->show();
			txt_formname->value(_("Severe Wx Report"));
			show_filename(def_severe_wx_filename);
			break;
		case STORMREP:
			oldtab = tab_storm;
			tab_storm->show();
			txt_formname->value(_("Storm Report"));
			show_filename(def_storm_filename);
			break;
		case REDXSNW:
			oldtab = tab_redx_snw;
			tab_redx_snw->show();
			txt_formname->value(_("Red Cross Safety & Welfare"));
			show_filename(def_redx_snw_filename);
			break;
		case REDX5739:
			oldtab = tab_redx_5739;
			tab_redx_5739->show();
			txt_formname->value(_("On-Site Detailed Damage Assessment"));
			show_filename(def_redx_5739_filename);
			break;
		case REDX5739A:
			oldtab = tab_redx_5739A;
			tab_redx_5739A->show();
			txt_formname->value(_("Detailed Damage Assessment Supplemental Worksheet"));
			show_filename(def_redx_5739A_filename);
			break;
		case REDX5739B:
			oldtab = tab_redx_5739B;
			tab_redx_5739B->show();
			txt_formname->value(_("Area Assessment Worksheet"));
			show_filename(def_redx_5739B_filename);
			break;
		case HICS203:
			oldtab = tab_hics203;
			tab_hics203->show();
			txt_formname->value(_("HICS-203 report"));
			show_filename(def_hics203_filename);
			break;
		case HICS206:
			oldtab = h206_tab;
			h206_tab->show();
			txt_formname->value(_("HICS-206 report"));
			show_filename(h206_def_filename);
			break;
		case HICS213:
			oldtab = h213_tab;
			h213_tab->show();
			txt_formname->value(_("HICS-213 report"));
			show_filename(h213_def_filename);
			break;
		case HICS214:
			oldtab = hics214_tab;
			hics214_tab->show();
			txt_formname->value(_("HICS-214 report"));
			show_filename(hics214_def_filename);
			break;
		case IARU:
			oldtab = tab_iaru;
			tab_iaru->show();
			txt_formname->value(_("IARU radiogram"));
			show_filename(iaru_def_filename);
			break;
		case RADIOGRAM:
			oldtab = tab_radiogram;
			tab_radiogram->show();
			txt_formname->value(_("ARRL radiogram"));
			show_filename(def_rg_filename);
			break;
		case CAP105:
			oldtab = tab_cap105;
			tab_cap105->show();
			txt_formname->value(_("CAP 105"));
			show_filename(cap105_def_filename);
			break;
		case CAP110:
			oldtab = tab_cap110;
			tab_cap110->show();
			txt_formname->value(_("CAP 110"));
			show_filename(cap110_def_filename);
			break;
		case CSV:
			oldtab = tab_csv;
			tab_csv->show();
			txt_formname->value(_("CSV spreadsheet"));
			show_filename(def_csv_filename);
			break;
		case TRANSFER:
			oldtab = tab_transfer;
			tab_transfer->show();
			txt_formname->value(_("File transfer"));
			show_filename(def_transfer_filename);
			break;
		case BLANK:
		case NONE:
		default:
			oldtab = tab_blank;
			tab_blank->show();
			txt_formname->value(_("Blank form"));
			show_filename(def_blank_filename);
			break;
	}
	estimate();
}

static void cb_mnuFormSelect(Fl_Menu_*, void *d) {
	int *pint = (int *)d;
	selected_form = *pint;
	select_form(selected_form);
}

static void cb_mnuDragAndDrop(Fl_Menu_*, void *d) {
	if (!oldtab) return;
	if (tab_dnd->visible()) {
		tab_dnd->hide();
		oldtab->show();
	} else {
		oldtab->hide();
		tab_dnd->show();
	}
}

Fl_Menu_Item menu_[] = {
 {_("&File"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&Folders"), 0, (Fl_Callback*)cb_mnu_folders, 0, FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&New"), 0x4006e,  (Fl_Callback*)cb_mnuNew, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&Open"), 0x4006f,  (Fl_Callback*)cb_mnuOpen, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("&Save"), 0x40073,  (Fl_Callback*)cb_mnuSave, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Save &As"), 0x40061,  (Fl_Callback*)cb_mnuSaveAs, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("View"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Html delivery"), 0,  (Fl_Callback*)cb_mnu_html, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Html file copy"), 0,  (Fl_Callback*)cb_mnu_html_fcopy, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Plain Text"), 0,  (Fl_Callback*)cb_mnu_text, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("Q-forms"), 0,  0, 0, 192, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Import"), 0,  (Fl_Callback*)cb_mnu_qimport, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Export"), 0,  (Fl_Callback*)cb_mnu_qexport, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("Wrap"), 0,  0, 0, 192, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Import"), 0,  (Fl_Callback*)cb_mnuWrapImport, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Export"), 0,  (Fl_Callback*)cb_mnuWrapExport, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {_("E&xit"), 0x40078,  (Fl_Callback*)cb_mnuExit, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {_("&Form"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 
 {_("Drag-n-Drop"),  0,  (Fl_Callback*)cb_mnuDragAndDrop, 0, FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Blank"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mBLANK, 0, FL_NORMAL_LABEL, 0, 14, 0},
 
 {_("CAP"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Form 105"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mCAP105, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Form 110"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mCAP110, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 
 {_("CSV"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mCSV, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("HICS"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("HICS203"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mHICS203, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("HICS206"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mHICS206, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("HICS213"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mHICS213, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("HICS214"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mHICS214, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 
 {_("IARU"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mIARU, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("ICS"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS203"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mICS203, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS205"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mICS205, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS205A"), 0, (Fl_Callback*)cb_mnuFormSelect, &mICS205A, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS206"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mICS206, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS213"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mICS213, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS214"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mICS214, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS216"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mICS216, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ICS309"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mICS309, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 
 {_("MARS"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Daily"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSDAILY, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("IN/EEI"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSINEEI, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Net"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSNET, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Army"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSARMY, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Navy"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSNAVY, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 
 {_("Plaintext"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mPLAINTEXT, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Radiogram"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mRADIOGRAM, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Red Cross"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Welfare"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mREDXSNW, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("5739"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mREDX5739, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("5739A"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mREDX5739A, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("5739B"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mREDX5739B, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 
 {_("Transfer"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mTRANSFER, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Weather"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Hurricane"), 0, (Fl_Callback*)cb_mnuFormSelect, &mWXHC, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Severe WX"), 0, (Fl_Callback*)cb_mnuFormSelect, &mSEVEREWX, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Storm Report"), 0, (Fl_Callback*)cb_mnuFormSelect, &mSTORMREP, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},

 {_("&Template"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Load"), 0,  (Fl_Callback*)cb_mnu_load_template, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Save"), 0,  (Fl_Callback*)cb_mnu_save_template, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Save As"), 0,  (Fl_Callback*)cb_mnu_save_as_template, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {_("&Config"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Personal data"), 0,  (Fl_Callback*)cb_mnuPersonalConfig, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Date/Time"), 0,  (Fl_Callback*)cb_mnuDateTimeConfig, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Files/Formatting"), 0,  (Fl_Callback*)cb_mnuConfigFiles, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Radiogram"), 0,  (Fl_Callback*)cb_mnuConfigRadiogram, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Fldigi connection"), 0,  (Fl_Callback*)cb_mnuConfigSocket, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {"  ", 0,  0, 0, FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},

 {_("AutoSend"), 0,  (Fl_Callback*)cb_mnuAutoSend, 0, FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},
 {"  ", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("&Help"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
#ifdef DEBUG
 {_("Event log"), 0,  (Fl_Callback*)cb_mnuEvents, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
#endif
 {_("Header trace"), 0,  (Fl_Callback*)cb_mnuHeaders, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Command line options"), 0,  (Fl_Callback*)cb_mnuOptions, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("On Line help"), 0,  (Fl_Callback*)cb_mnuOnLineHelp, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("About"), 0,  (Fl_Callback*)cb_mnuAbout, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {0,0,0,0,0,0,0,0,0}
};

extern void drop_file_changed();
static void cb_drop_file(Fl_Input*, void*) {
  drop_file_changed();
}

void cb_btn_estimate()
{
	estimate();
}

void cb_use_compression()
{
	progStatus.use_compression = btn_use_compression->value();
	estimate();
}

void cb_use_encoder()
{
	progStatus.encoder = encoders->index();
	estimate();
}

void cb_cbo_modes()
{
	estimate();
	if (!progStatus.change_modem_with_autosend)
		send_new_modem();
}

Fl_Double_Window* flmsg_dialog() {
	int W = 570, H = 465;
	Fl_Double_Window* w = new Fl_Double_Window(570, 465, "");;
	w->begin();
	w->align(FL_ALIGN_INSIDE);

	Fl_Menu_Bar* mb = new Fl_Menu_Bar(0, 0, W, 22);
	mb->menu(menu_);

	txt_formname = new Fl_Output(4, 26, 220, 20);
	txt_formname->box(FL_FLAT_BOX);
	txt_formname->color(fl_rgb_color(245, 245, 245)); // white smoke

	txt_filename = new Fl_Output(260, 26, 270, 20, _("file:"));
	txt_filename->box(FL_FLAT_BOX);
	txt_filename->align(FL_ALIGN_LEFT);
	txt_filename->color(fl_rgb_color(245, 245, 245));

	drop_file = new Fl_Input2(535, 22, 28, 28);
	drop_file->box(FL_OVAL_BOX);
	drop_file->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
	drop_file->value("");
	drop_file->color(fl_rgb_color(108, 166, 205));
	drop_file->cursor_color(fl_rgb_color(108, 166, 205));
	drop_file->labelcolor( fl_rgb_color( 205, 55, 0) );
	drop_file->label("DnD");
	drop_file->tooltip(_("drag and drop files here ..."));
	drop_file->callback((Fl_Callback*)cb_drop_file);
	drop_file->when(FL_WHEN_CHANGED);

	tab_top = 46;

	create_ics_tab();
	create_hics_tab();
	create_mars_tab();
	create_cap105_tab();
	create_cap110_tab();
	create_iaru_tab();
	create_radiogram_tab();
	create_redx_tab();
	create_plaintext_tab();
	create_blank_tab();
	create_csv_tab();
	create_dnd_tab();
	create_wxhc_tab();
	create_severe_wx_tab();
	create_storm_tab();
	create_transfer_tab();

	controls = new Fl_Group(2, 465 - 28, 566, 26, "controls");
	controls->begin();
	controls->box(FL_ENGRAVED_BOX);
	controls->align(FL_ALIGN_INSIDE);
	controls->copy_label("");

	btn_use_compression = new Fl_Check_Button(10, H-28+4, 60, 18, _("Comp"));
	btn_use_compression->tooltip(_("Data will be sent compressed\nif file size is reduced"));
	btn_use_compression->down_box(FL_DOWN_BOX);
	btn_use_compression->callback((Fl_Callback*)cb_use_compression);
	btn_use_compression->value(progStatus.use_compression);

	encoders = new Fl_ComboBox(74, H-28+2, 100, 22, "encoders");
	encoders->begin();
	encoders->copy_label("");
	encoders->align(FL_ALIGN_INSIDE);
	encoders->when(FL_WHEN_RELEASE);
	encoders->tooltip(_("Encode after compression"));
	encoders->callback((Fl_Callback*)cb_use_encoder);
	encoders->end();

	cbo_modes = new Fl_ComboBox(180, H-28+2, 120, 22, "cbo_modes");
	cbo_modes->begin();
	cbo_modes->copy_label("");
	cbo_modes->align(FL_ALIGN_INSIDE);
	cbo_modes->when(FL_WHEN_RELEASE);
	cbo_modes->tooltip(_("fldigi modem type"));
	cbo_modes->box(FL_DOWN_BOX);
	cbo_modes->color(FL_BACKGROUND2_COLOR);
	cbo_modes->selection_color(FL_BACKGROUND_COLOR);
	cbo_modes->labeltype(FL_NORMAL_LABEL);
	cbo_modes->labelfont(0);
	cbo_modes->labelsize(14);
	cbo_modes->labelcolor(FL_FOREGROUND_COLOR);
	cbo_modes->callback((Fl_Callback*)cb_cbo_modes);
	cbo_modes->end();

	btn_estimate = new Fl_Button(305, H-28+4, 18, 18, "*");
	btn_estimate->tooltip(_("Press to update size/time"));
	btn_estimate->callback((Fl_Callback*)cb_btn_estimate);

	txt_xfr_size_time = new Fl_Output(330, H-28+2, 230, 22, "");
	txt_xfr_size_time->tooltip(_("Transfer size / time"));
	txt_xfr_size_time->value("");

	controls->end();

	w->end();

	init_cbo_modes();
	init_encoders();

	return w;
}

static void cb_btnCloseOptions(Fl_Return_Button*, void*) {
  closeoptions();
}

static int opt_col_sizes[] = {200, 0};

Fl_Double_Window* optionsdialog() {
	int H = 300, W = 560;
	Fl_Double_Window* w = new Fl_Double_Window(W, H, _("Command Line Options"));

	brwsOptions = new Fl_Browser(2, 2, W - 4, H - 4 - 5 - 20);
	brwsOptions->column_widths(opt_col_sizes);

	btnCloseOptions = new Fl_Return_Button(W - 4 - 72, H - 5 - 20, 72, 20, _("OK"));
	btnCloseOptions->callback((Fl_Callback*)cb_btnCloseOptions);

	w->end();

	return w;
}

static void cb_select_arl(Fl_Browser* o, void*) {
  arl_nbr = o->value()- 1;
arl_text->clear();
arl_text->addstr(arl_list[arl_nbr].text);
txt_arl_fill1->value("");
txt_arl_fill1->deactivate();
txt_arl_fill2->value("");
txt_arl_fill2->deactivate();
txt_arl_fill3->value("");
txt_arl_fill3->deactivate();
txt_arl_fill4->value("");
txt_arl_fill4->deactivate();
if (arl_list[arl_nbr].nfills > 0) txt_arl_fill1->activate();
if (arl_list[arl_nbr].nfills > 1) txt_arl_fill2->activate();
if (arl_list[arl_nbr].nfills > 2) txt_arl_fill3->activate();
if (arl_list[arl_nbr].nfills > 3) txt_arl_fill4->activate();
}

static void cb_btn_arl_cancel(Fl_Button*, void*) {
  cb_arl_cancel();
}

static void cb_btn_arl_add(Fl_Button*, void*) {
  cb_arl_add();
}

static void cb_btnInsertX(Fl_Check_Button* o, void*) {
  progStatus.insert_x = o->value();
}

Fl_Double_Window* arl_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(521, 261, _("ARL Message Selector"));
		w->begin();
		select_arl = new Fl_Browser(6, 21, 161, 107, _("ARL #"));
		select_arl->type(2);
		select_arl->callback((Fl_Callback*)cb_select_arl);
		select_arl->align(FL_ALIGN_TOP);

		txt_arl_fill1 = new Fl_Input2(48, 131, 465, 22, _("fill 1:"));

		txt_arl_fill2 = new Fl_Input2(48, 155, 465, 22, _("fill 2:"));

		txt_arl_fill3 = new Fl_Input2(48, 179, 465, 22, _("fill 3:"));

		txt_arl_fill4 = new Fl_Input2(48, 204, 465, 22, _("fill 4:"));

		btn_arl_cancel = new Fl_Button(362, 232, 70, 20, _("Cancel"));
		btn_arl_cancel->callback((Fl_Callback*)cb_btn_arl_cancel);

		btn_arl_add = new Fl_Button(440, 232, 70, 20, _("Add"));
		btn_arl_add->callback((Fl_Callback*)cb_btn_arl_add);

		arl_text = new FTextEdit(169, 21, 345, 107, _("Message:"));
		arl_text->tooltip(_("Message contents - recommend limit to 25 words or less"));
		arl_text->box(FL_DOWN_BOX);
		arl_text->color((Fl_Color)FL_LIGHT3);
		arl_text->selection_color((Fl_Color)FL_SELECTION_COLOR);
		arl_text->labeltype(FL_NORMAL_LABEL);
		arl_text->labelfont(0);
		arl_text->labelsize(14);
		arl_text->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		arl_text->align(FL_ALIGN_TOP_LEFT);
		arl_text->when(FL_WHEN_RELEASE);
		Fl_Group::current()->resizable(arl_text);

		btnInsertX = new Fl_Check_Button(18, 234, 201, 15, _("Insert \"X\" between fields"));
		btnInsertX->down_box(FL_DOWN_BOX);
		btnInsertX->callback((Fl_Callback*)cb_btnInsertX);
		btnInsertX->value(progStatus.insert_x);
		w->end();
	return w;
}

static void cb_btn_dtformat0(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 0;
btn_dtformat1->value(0);
btn_dtformat2->value(0);
btn_dtformat3->value(0);
};
}

static void cb_btn_dtformat1(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 1;
btn_dtformat0->value(0);
btn_dtformat2->value(0);
btn_dtformat3->value(0);
};
}

static void cb_btn_dtformat2(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 2;
btn_dtformat0->value(0);
btn_dtformat1->value(0);
btn_dtformat3->value(0);
};
}

static void cb_btn_dtformat3(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.dtformat = 3;
btn_dtformat0->value(0);
btn_dtformat1->value(0);
btn_dtformat2->value(0);
};
}

static void set_local_datetime()
{
//ONLY include those calendar widgets that rely on progStatus.UTC
//for the date and time format!
	h206_txt_date_prepared->local_datetime(progStatus.UTC > 1);
	h213_txt_date->local_datetime(progStatus.UTC > 1);
}

static void cb_btn_utc_format0(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 0;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
set_local_datetime();
}

static void cb_btn_utc_format1(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 1;
btn_utc_format0->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
set_local_datetime();
}

static void cb_btn_utc_format2(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 2;
btn_utc_format1->value(0);
btn_utc_format0->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
set_local_datetime();
}

static void cb_btn_utc_format3(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 3;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format0->value(0);
btn_utc_format4->value(0);
btn_utc_format5->value(0);
};
set_local_datetime();
}

static void cb_btn_utc_format4(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 4;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format0->value(0);
btn_utc_format5->value(0);
};
set_local_datetime();
}

static void cb_btn_utc_format5(Fl_Round_Button* o, void*) {
  if (o->value()) {
progStatus.UTC = 5;
btn_utc_format1->value(0);
btn_utc_format2->value(0);
btn_utc_format3->value(0);
btn_utc_format4->value(0);
btn_utc_format0->value(0);
};
set_local_datetime();
}

static void cb_txt_my_call(Fl_Input* o, void*) {
  progStatus.my_call = o->value();
}

static void cb_txt_my_tel(Fl_Input* o, void*) {
  progStatus.my_tel = o->value();
}

static void cb_txt_my_name(Fl_Input* o, void*) {
  progStatus.my_name = o->value();
}

static void cb_txt_my_addr(Fl_Input* o, void*) {
  progStatus.my_addr = o->value();
}

static void cb_txt_my_email(Fl_Input* o, void*) {
	progStatus.my_email = o->value();
}

static void cb_txt_my_city(Fl_Input* o, void*) {
  progStatus.my_city = o->value();
}

static void cb_cnt_wpl(Fl_Spinner* o, void*) {
  progStatus.wpl = (int)o->value();
}

static void cb_btn_open_on_export(Fl_Check_Button* o, void*) {
  progStatus.open_on_export = o->value();
}

static void cb_btn_call_fname(Fl_Check_Button* o, void*) {
  progStatus.call_fname = o->value();
}

static void cb_btn_dt_fname(Fl_Check_Button* o, void*) {
  progStatus.dt_fname = o->value();
}

static void cb_btn_sernbr_fname(Fl_Check_Button* o, void*) {
  progStatus.sernbr_fname = o->value();
}

static void cb_txt_sernbr(Fl_Input* o, void*) {
  progStatus.sernbr = o->value();
}

static void cb_btn_rgnbr_fname(Fl_Check_Button* o, void*) {
  progStatus.rgnbr_fname = o->value();
}

static void cb_txt_rgnbr(Fl_Input* o, void*) {
  progStatus.rgnbr = o->value();
}

static void cb_btn_arl_desc(Fl_Check_Button* o, void*) {
  progStatus.arl_desc = o->value();
}

static void cb_close_dialog(Fl_Widget *w, void *d)
{
	Fl_Button *b = (Fl_Button *)w;
	Fl_Double_Window *win = (Fl_Double_Window *) b->parent();
	win->hide();
}

Fl_Double_Window* date_time_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(260, 176, _("Configure date/time"));

	w->begin();

	btn_dtformat0 = new Fl_Round_Button(10, 8, 70, 20, _("YYYY-MM-DD"));
	btn_dtformat0->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat0->callback((Fl_Callback*)cb_btn_dtformat0);
	if (progStatus.dtformat == 0) btn_dtformat0->value(1); else btn_dtformat0->value(0);

	btn_dtformat3 = new Fl_Round_Button(10, 30, 70, 20, _("YYYY-DD-MM"));
	btn_dtformat3->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat3->callback((Fl_Callback*)cb_btn_dtformat3);
	if (progStatus.dtformat == 3) btn_dtformat3->value(1); else btn_dtformat3->value(0);

	btn_dtformat1 = new Fl_Round_Button(10, 52, 70, 20, _("MM/DD/YY"));
	btn_dtformat1->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat1->callback((Fl_Callback*)cb_btn_dtformat1);
	if (progStatus.dtformat == 1) btn_dtformat1->value(1); else btn_dtformat1->value(0);

	btn_dtformat2 = new Fl_Round_Button(10, 74, 70, 20, _("DD/MM/YY"));
	btn_dtformat2->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat2->callback((Fl_Callback*)cb_btn_dtformat2);
	if (progStatus.dtformat == 2) btn_dtformat2->value(1); else btn_dtformat2->value(0);

	btn_utc_format0 = new Fl_Round_Button(140, 8, 70, 20, _("hhmmL"));
	btn_utc_format0->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format0->callback((Fl_Callback*)cb_btn_utc_format0);
	if (progStatus.UTC == 0) btn_utc_format0->value(1); else btn_utc_format0->value(0);

	btn_utc_format1 = new Fl_Round_Button(140, 30, 70, 20, _("hh:mmL"));
	btn_utc_format1->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format1->callback((Fl_Callback*)cb_btn_utc_format1);
	if (progStatus.UTC == 1) btn_utc_format1->value(1); else btn_utc_format1->value(0);

	btn_utc_format2 = new Fl_Round_Button(140, 52, 70, 20, _("hhmmZ"));
	btn_utc_format2->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format2->callback((Fl_Callback*)cb_btn_utc_format2);
	if (progStatus.UTC == 2) btn_utc_format2->value(1); else btn_utc_format2->value(0);

	btn_utc_format3 = new Fl_Round_Button(140, 74, 70, 20, _("hh:mmZ"));
	btn_utc_format3->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format3->callback((Fl_Callback*)cb_btn_utc_format3);
	if (progStatus.UTC == 3) btn_utc_format3->value(1); else btn_utc_format3->value(0);

	btn_utc_format4 = new Fl_Round_Button(140, 96, 70, 20, _("hhmm UTC"));
	btn_utc_format4->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format4->callback((Fl_Callback*)cb_btn_utc_format4);
	if (progStatus.UTC == 4) btn_utc_format4->value(1); else btn_utc_format4->value(0);

	btn_utc_format5 = new Fl_Round_Button(140, 118, 70, 20, _("hh:mm UTC"));
	btn_utc_format5->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format5->callback((Fl_Callback*)cb_btn_utc_format5);
	if (progStatus.UTC == 5) btn_utc_format5->value(1); else btn_utc_format5->value(0);

	Fl_Button * btn_close_date_time_dialog =
		new Fl_Button(260 - 70 - 6, 176 - 24 - 6, 70, 24, _("close"));
	btn_close_date_time_dialog->callback((Fl_Callback*)cb_close_dialog);

	w->end();

	return w;
}

Fl_Double_Window* personal_dialog()
{
	int W = 335, H = 200;
	Fl_Double_Window* w = new Fl_Double_Window(W, H, _("Personal data"));

	w->begin();

	txt_my_call = new Fl_Input2(90, 6, 77, 24, _("Call:"));
	txt_my_call->callback((Fl_Callback*)cb_txt_my_call);
	txt_my_call->value(progStatus.my_call.c_str());

	txt_my_tel = new Fl_Input2(90, 32, 130, 24, _("Tel:"));
	txt_my_tel->callback((Fl_Callback*)cb_txt_my_tel);
	txt_my_tel->value(progStatus.my_tel.c_str());

	txt_my_name = new Fl_Input2(90, 58, 240, 24, _("Name:"));
	txt_my_name->callback((Fl_Callback*)cb_txt_my_name);
	txt_my_name->value(progStatus.my_name.c_str());

	txt_my_addr = new Fl_Input2(90, 84, 240, 24, _("Addr:"));
	txt_my_addr->callback((Fl_Callback*)cb_txt_my_addr);
	txt_my_addr->value(progStatus.my_addr.c_str());

	txt_my_city = new Fl_Input2(90, 110, 240, 24, _("City/St/Zip:"));
	txt_my_city->callback((Fl_Callback*)cb_txt_my_city);
	txt_my_city->value(progStatus.my_city.c_str());

	txt_my_email = new Fl_Input2(90, 136, 240, 24, _("Email addr:"));
	txt_my_email->callback((Fl_Callback*)cb_txt_my_email);
	txt_my_email->value(progStatus.my_email.c_str());

	Fl_Button *btn_close_personal_dialog =
		new Fl_Button(W - 70 - 6, 166, 70, 24, _("close"));
	btn_close_personal_dialog->callback((Fl_Callback*)cb_close_dialog);

	w->end();

	return w;
}

Fl_Double_Window* radiogram_dialog()
{
	int W = 330, H = 126;
	Fl_Double_Window* w = new Fl_Double_Window(W, H, _("Configure radiogram"));

	w->begin();

	int Y = 6;
	cnt_wpl = new Fl_Spinner(60, Y, 40, 24, _("message words/line"));
	cnt_wpl->tooltip(_("Radiogram message contents auto format"));
	cnt_wpl->minimum(4);
	cnt_wpl->maximum(10);
	cnt_wpl->value(5);
	cnt_wpl->callback((Fl_Callback*)cb_cnt_wpl);
	cnt_wpl->align(FL_ALIGN_RIGHT);
	cnt_wpl->value(progStatus.wpl);
	Y += 30;
	btn_rgnbr_fname = new Fl_Check_Button(60, Y, 70, 24, _("Auto incr\'"));
	btn_rgnbr_fname->tooltip(_("enable auto increment of message number"));
	btn_rgnbr_fname->down_box(FL_DOWN_BOX);
	btn_rgnbr_fname->callback((Fl_Callback*)cb_btn_rgnbr_fname);
	btn_rgnbr_fname->value(progStatus.rgnbr_fname);
	Y += 30;
	txt_rgnbr = new Fl_Input2(60, Y, 66, 24, _("Next #"));
	txt_rgnbr->tooltip(_("next number in auto-increment sequence"));
	txt_rgnbr->type(2);
	txt_rgnbr->callback((Fl_Callback*)cb_txt_rgnbr);
	txt_rgnbr->align(FL_ALIGN_RIGHT);
	txt_rgnbr->value(progStatus.rgnbr.c_str());
	Y += 30;
	btn_arl_desc = new Fl_Check_Button(60, Y, 70, 24, _("Show ARL desc\'"));
	btn_arl_desc->tooltip(_("Add keyed text descriptions for ARL ## messages"));
	btn_arl_desc->down_box(FL_DOWN_BOX);
	btn_arl_desc->callback((Fl_Callback*)cb_btn_arl_desc);
	btn_arl_desc->value(progStatus.arl_desc);

	Fl_Button *btn_close_radiogram_dialog =
		new Fl_Button(W - 70 - 6, Y, 70, 24, _("close"));
	btn_close_radiogram_dialog->callback((Fl_Callback*)cb_close_dialog);

	w->end();

	return w;
}

void cb_find_roster()
{
	string filename = ICS_dir;
	filename.append("MARS_ROSTER.csv");
	const char *p = FSEL::select(
		"Select MARS roster file",
		"csv file\t*.{csv,CSV}",
		filename.c_str());
	if (p) {
		progStatus.mars_roster_file = p;
		txt_mars_roster_file->value(p);
	}
}

void cb_autowordwrap()
{
	progStatus.autowordwrap = btnAutoWordWrap->value();
}

void cb_charcount()
{
	progStatus.charcount = cntCharCount->value();
}

Fl_Double_Window* config_files_dialog() {
	int W = 448;
	int H = 280;

	Fl_Double_Window* w = new Fl_Double_Window(W, H, _("Configure files & formatting"));

	w->begin();

	Fl_Group* group1 = new Fl_Group(2, 2, 444, 70, _("Wrap"));

	group1->box(FL_ENGRAVED_FRAME);
	group1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

	btn_open_on_export = new Fl_Check_Button(10, 24, 18, 18, _("Open folder when exporting"));
	btn_open_on_export->tooltip(_(""));
	btn_open_on_export->down_box(FL_DOWN_BOX);
	btn_open_on_export->callback((Fl_Callback*)cb_btn_open_on_export);
	btn_open_on_export->value(progStatus.open_on_export);

	group1->end();

	Fl_Group* group2 = new Fl_Group(2, 74, 444, 74, _("Naming Files"));
	group2->box(FL_ENGRAVED_FRAME);
	group2->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

	btn_call_fname = new Fl_Check_Button(10, 96, 18, 18, _("Callsign"));
	btn_call_fname->down_box(FL_DOWN_BOX);
	btn_call_fname->callback((Fl_Callback*)cb_btn_call_fname);
	btn_call_fname->value(progStatus.call_fname);

	btn_dt_fname = new Fl_Check_Button(100, 96, 18, 18, _("Date-time"));
	btn_dt_fname->down_box(FL_DOWN_BOX);
	btn_dt_fname->callback((Fl_Callback*)cb_btn_dt_fname);
	btn_dt_fname->value(progStatus.dt_fname);

	btn_sernbr_fname = new Fl_Check_Button(10, 116, 18, 18, _("Serial #"));
	btn_sernbr_fname->down_box(FL_DOWN_BOX);
	btn_sernbr_fname->callback((Fl_Callback*)cb_btn_sernbr_fname);
	btn_sernbr_fname->value(progStatus.sernbr_fname);

	txt_sernbr = new Fl_Input2(100, 116, 66, 22, _("Next #"));
	txt_sernbr->type(2);
	txt_sernbr->callback((Fl_Callback*)cb_txt_sernbr);
	txt_sernbr->align(FL_ALIGN_RIGHT);
	txt_sernbr->value(progStatus.sernbr.c_str());

	group2->end();

	Fl_Group* group3 = new Fl_Group(2, 150, 444, 46, "");
	group3->box(FL_ENGRAVED_FRAME);

	txt_mars_roster_file = new Fl_Input2(10, 168, 360, 22, _("MARS roster file"));
	txt_mars_roster_file->align(FL_ALIGN_TOP_LEFT);

	Fl_Button *btn_find_roster = new Fl_Button(372, 168, 68, 22, _("Find"));
	btn_find_roster->callback((Fl_Callback*)cb_find_roster);

	group3->end();

	Fl_Group* group4 = new Fl_Group(2, 199, 444, 46, "Html message text");
	group4->box(FL_ENGRAVED_FRAME);
	group4->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

	btnAutoWordWrap = new Fl_Check_Button(10, 220, 18, 18, _("Word wrap at "));
	btnAutoWordWrap->down_box(FL_DOWN_BOX);
	btnAutoWordWrap->value(progStatus.autowordwrap);
	btnAutoWordWrap->callback((Fl_Callback*)cb_autowordwrap);

	cntCharCount = new Fl_Counter(135, 218, 60, 20, _("characters"));
	cntCharCount->align(FL_ALIGN_RIGHT);
	cntCharCount->value(progStatus.charcount);
	cntCharCount->type(FL_SIMPLE_COUNTER);
	cntCharCount->step(1);
	cntCharCount->callback((Fl_Callback*)cb_charcount);

	group3->end();

	Fl_Button *btn_close_config =
		new Fl_Button(W - 70 - 6, H - 24 - 4, 70, 24, _("close"));
	btn_close_config->callback((Fl_Callback*)cb_close_dialog);

	w->end();

	return w;
}

Fl_Choice	*sel_hx_select = (Fl_Choice *)0;

static void cb_sel_hx_select(Fl_Choice*, void*) {
  cb_hx_select();
}

Fl_Button	*btn_hx_select_add = (Fl_Button *)0;

static void cb_btn_hx_select_add(Fl_Button*, void*) {
  cb_hx_select_add();
}

Fl_Input2	*txt_hx_select_text = (Fl_Input2 *)0;

Fl_Button	*btn_hx_select_cancel = (Fl_Button *)0;

static void cb_btn_hx_select_cancel(Fl_Button*, void*) {
  cb_hx_select_cancel();
}

Fl_Return_Button	*btn_hx_select_ok = (Fl_Return_Button *)0;

static void cb_btn_hx_select_ok(Fl_Return_Button*, void*) {
  cb_hx_select_ok();
}

Fl_Output	*txt_hx_instructions = (Fl_Output *)0;

Fl_Double_Window* hx_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(359, 121, _("Optional Handling"));

	w->begin();

		sel_hx_select = new Fl_Choice(3, 20, 68, 24, _("HX__:"));
		sel_hx_select->down_box(FL_BORDER_BOX);
		sel_hx_select->callback((Fl_Callback*)cb_sel_hx_select);
		sel_hx_select->align(FL_ALIGN_TOP_LEFT);

		btn_hx_select_add = new Fl_Button(73, 20, 30, 24, _("=>"));
		btn_hx_select_add->callback((Fl_Callback*)cb_btn_hx_select_add);

		txt_hx_select_text = new Fl_Input2(105, 20, 121, 24, _("HX text"));
		txt_hx_select_text->box(FL_DOWN_BOX);
		txt_hx_select_text->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_hx_select_text->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_hx_select_text->labeltype(FL_NORMAL_LABEL);
		txt_hx_select_text->labelfont(0);
		txt_hx_select_text->labelsize(14);
		txt_hx_select_text->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_hx_select_text->align(FL_ALIGN_TOP_LEFT);
		txt_hx_select_text->when(FL_WHEN_RELEASE);

		btn_hx_select_cancel = new Fl_Button(229, 20, 60, 24, _("Cancel"));
		btn_hx_select_cancel->callback((Fl_Callback*)cb_btn_hx_select_cancel);

		btn_hx_select_ok = new Fl_Return_Button(293, 20, 60, 24, _("OK"));
		btn_hx_select_ok->callback((Fl_Callback*)cb_btn_hx_select_ok);

		txt_hx_instructions = new Fl_Output(5, 47, 348, 70);
		txt_hx_instructions->type(12);
		txt_hx_instructions->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);

	w->end();
	return w;
}

Fl_Double_Window* headers_dialog() {
	Fl_Double_Window* w = new Fl_Double_Window(500, 200, _("Transfer/Edit trail"));

	w->begin();

	txt_hdr_from = new Fl_Input2(50, 30, 440, 80, _("From:"));
	txt_hdr_from->type(4);

	txt_hdr_edit = new Fl_Input2(50, 115, 440, 80, _("Edit:"));
	txt_hdr_edit->type(4);

	w->end();

	return w;
}

static void cb_txt_socket_addr(Fl_Input* o, void*) {
  progStatus.socket_addr = o->value();
}

static void cb_txt_socket_port(Fl_Input* o, void*) {
  progStatus.socket_port = o->value();
}

static void cb_socket_default(Fl_Input* o, void*) {
  progStatus.socket_addr = "127.0.0.1";
  progStatus.socket_port = "7322";
  txt_socket_addr->value(progStatus.socket_addr.c_str());
  txt_socket_port->value(progStatus.socket_port.c_str());
}

static void cb_change_modem_with_autosend(Fl_Check_Button *o, void *) {
	progStatus.change_modem_with_autosend = o->value();
}

static void cb_sync_modem_to_fldigi(Fl_Check_Button *o, void *) {
	progStatus.sync_modem_to_fldigi = o->value();
}

Fl_Button *btn_socket_default = (Fl_Button *)0;
Fl_Check_Button *btn_change_modem_with_autosend = (Fl_Check_Button *)0;
Fl_Check_Button *btn_sync_modem_to_fldigi = (Fl_Check_Button *)0;

Fl_Double_Window* socket_dialog()
{
	int W = 255, H = 146;
	Fl_Double_Window* w = new Fl_Double_Window(W, H, _("Fldigi Connection"));

	w->begin();

	txt_socket_addr = new Fl_Input2(120, 6, 130, 24, _("Socket Address:"));
	txt_socket_addr->tooltip(_("default = 127.0.0.1"));
	txt_socket_addr->callback((Fl_Callback*)cb_txt_socket_addr);
	txt_socket_addr->value(progStatus.socket_addr.c_str());

	txt_socket_port = new Fl_Input2(120, 32, 130, 24, _("Socket Port:"));
	txt_socket_port->tooltip(_("default = 7322"));
	txt_socket_port->callback((Fl_Callback*)cb_txt_socket_port);
	txt_socket_port->value(progStatus.socket_port.c_str());

	btn_sync_modem_to_fldigi = new Fl_Check_Button(15, 58, 24, 24, _("Sync modem to fldigi"));
	btn_sync_modem_to_fldigi->tooltip(_("flmsg will follow modem change in fldigi"));
	btn_sync_modem_to_fldigi->value(progStatus.sync_modem_to_fldigi);
	btn_sync_modem_to_fldigi->callback((Fl_Callback*)cb_sync_modem_to_fldigi);

	btn_change_modem_with_autosend = new Fl_Check_Button(15, 84, 24, 24, _("Change modem with autosend"));
	btn_change_modem_with_autosend->tooltip(_("flmsg sends new modem to fldigi after \"autosend\""));
	btn_change_modem_with_autosend->value(progStatus.change_modem_with_autosend);
	btn_change_modem_with_autosend->callback((Fl_Callback*)cb_change_modem_with_autosend);

	Fl_Button *btn_socket_default = new Fl_Button(6, H - 30, 70, 24, _("Default"));
	btn_socket_default->tooltip("");
	btn_socket_default->callback((Fl_Callback*)cb_socket_default);

	Fl_Button *btn_close_socket_dialog = new Fl_Button(W - 70 - 6, H - 30, 70, 24, _("Close"));
	btn_close_socket_dialog->tooltip("");
	btn_close_socket_dialog->callback((Fl_Callback*)cb_close_dialog);

	w->end();

	return w;
}
