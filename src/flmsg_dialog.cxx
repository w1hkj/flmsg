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

#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <vector>

#include <FL/Fl_Native_File_Chooser.H>

#include "gettext.h"
#include "flmsg_arq.h"
#include "flmsg_dialog.h"
#include "drop_button.h"

#include "status.h"
#include "flmsg.h"
#include "fileselect.h"
#include "debug.h"
#include "util.h"

#include "transfer.h"
#include "time_table.h"
#include "xml_io.h"
#include "combo.h"
#include "wrap.h"
#include "icons.h"

//======================================================================

Fl_Menu_Bar *ve_menubar = (Fl_Menu_Bar *)0;
Fl_ComboBox *temp_combo = (Fl_ComboBox *)0;
Fl_Button   *ve_create  = (Fl_Button *)0;
Fl_Drop_Button   *ve_editor  = (Fl_Drop_Button *)0;
Fl_Drop_Button   *ve_viewer  = (Fl_Drop_Button *)0;

//======================================================================

Fl_Menu_Bar *mb = (Fl_Menu_Bar *)0;

Fl_Browser			*brwsOptions = (Fl_Browser *)0;
Fl_Return_Button	*btnCloseOptions = (Fl_Return_Button *)0;

Fl_Output			*txt_formname = (Fl_Output *)0;

Fl_Output			*txt_filename = (Fl_Output *)0;
Fl_Input			*drop_file = (Fl_Input *)0;

Fl_Group			*all_tabs = (Fl_Group *)0;
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

Fl_Check_Button		*btn_force_compression = (Fl_Check_Button *)0;

Fl_Input2			*txt_mars_roster_file = (Fl_Input2 *)0;

Fl_Input2*			txt_hdr_from = (Fl_Input2 *)0;
Fl_Input2*			txt_hdr_edit = (Fl_Input2 *)0;

Fl_Check_Button *btnAutoWordWrap = (Fl_Check_Button *)0;
Fl_Check_Button *btn_use_compression = (Fl_Check_Button *)0;
Fl_Button *btn_estimate = (Fl_Button *)0;

Fl_Check_Button *btnSendOriginalFile = (Fl_Check_Button *)0;

Fl_ListBox *encoders = (Fl_ListBox *)0;

Fl_Counter *cntCharCount = (Fl_Counter *)0;

Fl_ListBox	*cbo_modes = (Fl_ListBox *)0;
Fl_Output *txt_xfr_size_time = (Fl_Output *)0;

//----------------------------------------------------------------------
// arq transfer controls group
//----------------------------------------------------------------------
Fl_Group			*arq_group = (Fl_Group *)0;
Fl_Progress			*prgSTATE = (Fl_Progress *)0;
Fl_Input2			*txtSTATE = (Fl_Input2 *)0;
Fl_Input2			*txtSENDTO = (Fl_Input2 *)0;
Fl_Button			*btnSEND = (Fl_Button *)0;

int transfer_size;

void cb_btn_transfer_size(Fl_Button *, void*);

//----------------------------------------------------------------------
#define NO_OF_MODEMS 200
char *s_modes[NO_OF_MODEMS];

string valid_modes;

void update_cbo_modes(string &fldigi_modes)
{
	memset(s_modes, 0, sizeof(s_modes));

	valid_modes.clear();
	cbo_modes->clear();

	int j = 0;
	int num_modes = mode_table_count();
	char *m = (char *)0;

	if(num_modes >= NO_OF_MODEMS)
		num_modes = NO_OF_MODEMS - 1;

	for (int i = 0; i < num_modes; i++) {
		m = modem_at_index(i);
		if (fldigi_modes.find(m) != string::npos) {
			s_modes[j] = (char *) m;
			cbo_modes->add(s_modes[j]);
			valid_modes.append(s_modes[j]).append("|");
			j++;
		}
	}

	cbo_modes->index(progStatus.selected_mode);
}

void init_cbo_modes()
{
	string min_modes = "";
	min_modes.append("8PSK125|8PSK250|8PSK500|8PSK1000|8PSK1333");
	min_modes.append("|8PSK125F|8PSK125FL|8PSK250F|8PSK500F|8PSK1000F|8PSK1200F|8PSK1333F");
	min_modes.append("|BPSK31|BPSK63|BPSK63F|BPSK125|BPSK250|BPSK500|BPSK1000");
	min_modes.append("|DOMX22|DOMX44|DOMX88");
	min_modes.append("|MFSK16|MFSK22|MFSK31|MFSK32|MFSK64|MFSK64L|MFSK128|MFSK128L");
	min_modes.append("|MT63-500L|MT63-500S|MT63-1KL|MT63-1KS|MT63-2KL|MT63-2KS");
	min_modes.append("|Olivia-4-250|Olivia-4-500|Olivia-8-250|Olivia-8-500|Olivia-8-1K");
	min_modes.append("|Olivia-16-500|Olivia-16-1K|Olivia-32-1K|Olivia-64-2K");
	min_modes.append("|PSK63RC4|PSK63RC5|PSK63RC10|PSK63RC20|PSK63RC32");
	min_modes.append("|PSK125R|PSK125RC4|PSK125RC5|PSK125C12|PSK125RC10");
	min_modes.append("|PSK125RC12|PSK125RC16");
	min_modes.append("|PSK250R|PSK250C6|PSK250RC2|PSK250RC3|PSK250RC5|PSK250RC6|PSK250RC7");
	min_modes.append("|PSK500R|PSK500C2|PSK500C4|PSK500RC2|PSK500RC3|PSK500RC4");
	min_modes.append("|PSK800C2|PSK800RC2");
	min_modes.append("|PSK1000C2|PSK1000R|PSK1000RC2");
	min_modes.append("|QPSK31|QPSK63|QPSK125|QPSK250|QPSK500");
	min_modes.append("|THOR16|THOR22|THOR25x4|THOR50x1|THOR50x2|THOR100");
	update_cbo_modes(min_modes);
}

bool valid_mode_check(string &md)
{
	return (valid_modes.find(md) != string::npos);
}

void clear_estimate() {
	transfer_size = 0;
	txt_xfr_size_time->value("");
}

void estimate() {
	static char sz_xfr_size[30];
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
	update_custom = false;
	cb_new();
}

static void cb_mnuOpen(Fl_Menu_*, void*) {
	update_custom = false;
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
	update_custom = false;
	cb_import();
}

static void cb_mnu_qexport(Fl_Menu_*, void*) {
	cb_export();
}

static void cb_mnuWrapImport(Fl_Menu_*, void*) {
	update_custom = false;
	cb_wrap_import();
}

static void cb_mnuWrapExport(Fl_Menu_*, void*) {
	cb_wrap_export();
}

static int dbl_click_timeout = 2000;
static int dbl_click_time = 0;

void dbl_click_timer(void *)
{
	dbl_click_time -= 50;
	if (dbl_click_time != 0)
		Fl::repeat_timeout(0.05, dbl_click_timer);
	return;
}

static void cb_mnuAutoSend(Fl_Menu_*, void*) {
	if (dbl_click_time) return;
	dbl_click_time = dbl_click_timeout;
	Fl::add_timeout(0.05, dbl_click_timer);
	b_autosend = true;
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

static void cb_mnuConfigARQ(Fl_Menu_ *, void*) {
	cb_config_arq();
}

static void cb_mnuConfigUI(Fl_Menu_ *, void*) {
	cb_config_UI();
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

static void cb_btnSEND(Fl_Button*, void*) {
	arqSEND();
}

static void cb_mnuEvents(Fl_Menu_*, void*) {
	debug::show();
}

static void cb_mnuOnLineHelp(Fl_Menu_*, void*) {
	show_help();
}

static void cb_mnuCustomDownload(Fl_Menu_*, void*) {
	custom_download();
}

static void cb_mnuAbout(Fl_Menu_*, void*) {
	cb_About();
}

static void cb_ARC_SF_download(Fl_Menu_*, void *) {
	open_url("https://sourceforge.net/projects/fldigi/files/flmsg/templates/");
}

static void cb_ARC_HKJ_download(Fl_Menu_*, void*) {
	open_url("http://www.w1hkj.com/files/flmsg/templates/");
}

int mICS203 = ICS203;
int mICS205 = ICS205;
int mICS205A = ICS205A;
int mICS206 = ICS206;
int mICS213 = ICS213;
int mICS214 = ICS214;
int mICS216 = ICS216;
int mICS309 = ICS309;
int mNETLOG = NETLOG;
int mHICS203 = HICS203;
int mHICS206 = HICS206;
int mHICS213 = HICS213;
int mHICS214 = HICS214;
int mIARU = IARU;
int mRADIOGRAM = RADIOGRAM;
int mPLAINTEXT = PLAINTEXT;
int mBLANK = BLANK;
int mCSV = CSV;
int mCUSTOM = CUSTOM;
int mMARSDAILY = MARSDAILY;
int mMARSINEEI = MARSINEEI;
int mMARSNET = MARSNET;
int mMARSARMY = MARSARMY;
int mMARSMSG = MARSMSG;
int mWXHC = WXHC;
int mSEVEREWX = SEVEREWX;
int mSTORMREP = STORMREP;
int mCAP105 = CAP105;
int mCAP110 = CAP110;
int mTRANSFER = TRANSFER;

Fl_Group *oldtab = (Fl_Group *)0;

static void select_plaintext()
{
	oldtab = tab_plaintext;
	tab_plaintext->show();
	txt_formname->value(_("Plaintext message"));
	show_filename(def_pt_filename);
}

static void select_ics203()
{
	oldtab = tab_ics203;
	tab_ics203->show();
	txt_formname->value(_("ICS-203 report"));
	show_filename(def_203_filename);
}

static void select_ics205()
{
	oldtab = tab_ics205;
	tab_ics205->show();
	txt_formname->value(_("ICS-205 report"));
	show_filename(def_205_filename);
}

static void select_ics205A()
{
	oldtab = tab_ics205a;
	tab_ics205a->show();
	txt_formname->value(_("ICS-205A report"));
	show_filename(def_205a_filename);
}

static void select_ics206()
{
	oldtab = tab_ics206;
	tab_ics206->show();
	tab_ics206_type->value(tab_206_med_plan);
	txt_formname->value(_("ICS-206 report"));
	show_filename(def_206_filename);
}

static void select_ics213()
{
	oldtab = tab_ics213;
	txt_213_d1->local_datetime(progStatus.UTC < 2);
	txt_213_d2->local_datetime(progStatus.UTC < 2);
	tab_ics213->show();
	tab_ics213_type->value(tab_213_originator);
	txt_formname->value(_("ICS-213 report"));
	show_filename(def_213_filename);
}

static void select_ics214()
{
	oldtab = tab_ics214;
	tab_ics214->show();
	tab_ics214_type->value(tab_214_1);
	txt_formname->value(_("ICS-214 report"));
	show_filename(def_214_filename);
}

static void select_ics216()
{
	oldtab = tab_ics216;
	tab_ics216->show();
	tab_ics216_type->value(tab_216_1);
	txt_formname->value(_("ICS-216 report"));
	show_filename(def_216_filename);
}

static void select_ics309()
{
	oldtab = tab_ics309;
	tab_ics309->show();
	tab_ics309_type->value(tab_309_1);
	txt_formname->value(_("ICS-309 report"));
	show_filename(def_309_filename);
}

static void select_netlog()
{
	oldtab = tab_netlog;
	tab_netlog->show();
	tab_netlog_type->value(tab_netlog_1);
	txt_formname->value(_("Net Log report"));
	show_filename(def_netlog_filename);
}

static void select_marsdaily()
{
	oldtab = tab_mars_daily;
	tab_mars_daily->show();
	txt_formname->value(_("MARS daily report"));
	show_filename(def_mars_daily_filename);
}

static void select_marsineei()
{
	oldtab = tab_mars_ineei;
	tab_mars_ineei->show();
	txt_formname->value(_("MARS IN/EEI report"));
	show_filename(def_mars_ineei_filename);
}

static void select_marsnet()
{
	oldtab = tab_mars_net;
	tab_mars_net->show();
	txt_formname->value(_("MARS Net report"));
	show_filename(def_mars_net_filename);
}

static void select_marsarmy()
{
	oldtab = tab_mars_army;
	tab_mars_army->show();
	txt_formname->value(_("MARS Army message"));
	show_filename(def_mars_army_filename);
}

static void select_marsmsg()
{
	oldtab = tab_mars_msg;
	tab_mars_msg->show();
	txt_formname->value(_("MARS message"));
	show_filename(def_mars_msg_filename);
}

static void select_wxhc()
{
	oldtab = tab_wxhc;
	tab_wxhc->show();
	txt_formname->value(_("Hurricane Report"));
	show_filename(def_wxhc_filename);
}

static void select_severewx()
{
	oldtab = tab_severe_wx;
	tab_severe_wx->show();
	txt_formname->value(_("Severe Wx Report"));
	show_filename(def_severe_wx_filename);
}

static void select_stormrep()
{
	oldtab = tab_storm;
	tab_storm->show();
	txt_formname->value(_("Storm Report"));
	show_filename(def_storm_filename);
}

static void select_hics203()
{
	oldtab = tab_hics203;
	tab_hics203->show();
	txt_formname->value(_("HICS-203 report"));
	show_filename(def_hics203_filename);
}

static void select_hics206()
{
	oldtab = h206_tab;
	h206_txt_date_prepared->local_datetime(progStatus.UTC < 2);
	h206_tab->show();
	txt_formname->value(_("HICS-206 report"));
	show_filename(h206_def_filename);
}

static void select_hics213()
{
	oldtab = h213_tab;
	h213_txt_date->local_datetime(progStatus.UTC < 2);
	h213_tab->show();
	txt_formname->value(_("HICS-213 report"));
	show_filename(h213_def_filename);
}

static void select_hics214()
{
	oldtab = hics214_tab;
	hics214_tab->show();
	txt_formname->value(_("HICS-214 report"));
	show_filename(hics214_def_filename);
}

static void select_iaru()
{
	oldtab = tab_iaru;
	tab_iaru->show();
	txt_formname->value(_("IARU radiogram"));
	show_filename(iaru_def_filename);
}

static void select_radiogram()
{
	oldtab = tab_radiogram;
	tab_radiogram->show();
	txt_formname->value(_("ARRL radiogram"));
	show_filename(def_rg_filename);
}

static void select_cap105()
{
	oldtab = tab_cap105;
	tab_cap105->show();
	txt_formname->value(_("CAP 105"));
	show_filename(cap105_def_filename);
}

static void select_cap110()
{
	oldtab = tab_cap110;
	tab_cap110->show();
	txt_formname->value(_("CAP 110"));
	show_filename(cap110_def_filename);
}

static void select_csv()
{
	oldtab = tab_csv;
	tab_csv->show();
	txt_formname->value(_("CSV spreadsheet"));
	show_filename(def_csv_filename);
}

static void select_custom()
{
	oldtab = tab_custom;
	tab_custom->show();
	txt_formname->value(_("Custom Editable Html"));
	show_filename(def_custom_filename);
}

static void select_transfer()
{
	oldtab = tab_transfer;
	tab_transfer->show();
	txt_formname->value(_("File transfer"));
	show_filename(def_transfer_filename);
}

static void select_custom_transfer()
{
	oldtab = tab_custom_transfer;
	tab_custom_transfer->show();
	txt_formname->value(_("FORM transfer"));
	show_filename(def_custom_transfer_filename);
	if (!def_custom_transfer_filename.empty())
		load_custom_html_file();
}

void select_form(int form)
{
	if (oldtab) oldtab->hide();
	if (tab_dnd->visible()) tab_dnd->hide();
	switch (form) {
		case PLAINTEXT:
			select_plaintext();
			break;
		case ICS203:
			select_ics203();
			break;
		case ICS205:
			select_ics205();
			break;
		case ICS205A:
			select_ics205A();
			break;
		case ICS206:
			select_ics206();
			break;
		case ICS213:
			select_ics213();
			break;
		case ICS214:
			select_ics214();
			break;
		case ICS216:
			select_ics216();
			break;
		case ICS309:
			select_ics309();
			break;
		case NETLOG:
			select_netlog();
			break;
		case MARSDAILY:
			select_marsdaily();
			break;
		case MARSINEEI:
			select_marsineei();
			break;
		case MARSNET:
			select_marsnet();
			break;
		case MARSARMY:
			select_marsarmy();
			break;
		case MARSMSG:
			select_marsmsg();
			break;
		case WXHC:
			select_wxhc();
			break;
		case SEVEREWX:
			select_severewx();
			break;
		case STORMREP:
			select_stormrep();
			break;
		case HICS203:
			select_hics203();
			break;
		case HICS206:
			select_hics206();
			break;
		case HICS213:
			select_hics213();
			break;
		case HICS214:
			select_hics214();
			break;
		case IARU:
			select_iaru();
			break;
		case RADIOGRAM:
			select_radiogram();
			break;
		case CAP105:
			select_cap105();
			break;
		case CAP110:
			select_cap110();
			break;
		case CSV:
			select_csv();
			break;
		case CUSTOM:
			select_custom();
			break;
		case TRANSFER:
			select_transfer();
			break;
		case CUSTOM_TRANSFER:
			select_custom_transfer();
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

static void cb_mnuFormSelect(Fl_Menu_*, void *d)
{
	int *pint = (int *)d;
	selected_form = *pint;
	select_form(selected_form);
}

static void cb_mnuDragAndDrop(Fl_Menu_*, void *d)
{
	if (!oldtab) return;
	if (tab_dnd->visible()) {
		tab_dnd->hide();
		oldtab->show();
	} else {
		oldtab->hide();
		tab_dnd->show();
	}
}

static void cb_mnuARQrcvdmsgs(Fl_Menu_*, void *d)
{
	if (!rcvd_msgs_dialog) rcvd_msgs_dialog = create_rcvd_msgs_dialog();
	if (!rcvd_msgs_dialog->visible()) rcvd_msgs_dialog->show();
}

Fl_Double_Window *event_dialog = (Fl_Double_Window *)0;

extern void print_status(void *);

static void cb_events(Fl_Menu_ *, void *d)
{
	if (event_dialog == 0) event_dialog = create_ARQ_event_dialog();
	print_status(0);
	event_dialog->show();
}

#define NBR_CUSTOM_MENUS 200
Fl_Menu_Item custom_menu[NBR_CUSTOM_MENUS];
void load_custom_menu();

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

 {_("F&orm"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Drag-n-Drop"),  0,  (Fl_Callback*)cb_mnuDragAndDrop, 0, FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Blank"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mBLANK, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("CAP"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Form 105"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mCAP105, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Form 110"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mCAP110, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {_("CSV"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mCSV, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Custom"), 0, 0, (void*)custom_menu, FL_SUBMENU_POINTER},//, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Ham Forms"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("NETLOG"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mNETLOG, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

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
 {_("Generic msg"), 0, (Fl_Callback*)cb_mnuFormSelect, &mMARSMSG, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("IN/EEI"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSINEEI, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Net"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSNET, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Army msg"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mMARSARMY, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {_("Plaintext"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mPLAINTEXT, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Radiogram"), 0,  (Fl_Callback*)cb_mnuFormSelect, &mRADIOGRAM, 0, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Red Cross"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Download from Source Forge"), 0, (Fl_Callback*)cb_ARC_SF_download, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Download from W1HKJ web site"), 0, (Fl_Callback*)cb_ARC_HKJ_download, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
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

 {_("&Config"), 0,  0, 0, 64 | FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Personal data"), 0,  (Fl_Callback*)cb_mnuPersonalConfig, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Date/Time"), 0,  (Fl_Callback*)cb_mnuDateTimeConfig, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Files/Formatting"), 0,  (Fl_Callback*)cb_mnuConfigFiles, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Radiogram"), 0,  (Fl_Callback*)cb_mnuConfigRadiogram, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("ARQ interface"), 0,   (Fl_Callback*)cb_mnuConfigARQ, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("User interface"), 0,   (Fl_Callback*)cb_mnuConfigUI, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {_("AutoSend"), 0,  (Fl_Callback*)cb_mnuAutoSend, 0, FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},

 {_("Utilities"), 0,  0, 0, 64 | FL_MENU_DIVIDER, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Received Msgs"), 0, (Fl_Callback*)cb_mnuARQrcvdmsgs, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Events"), 0, (Fl_Callback*)cb_events, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},

 {0,0,0,0,0,0,0,0,0}
};

Fl_Menu_Item help_menu_[] = {
 {_("&Help"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
#ifdef DEBUG
 {_("Event log"), 0,  (Fl_Callback*)cb_mnuEvents, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
#endif
 {_("Header trace"), 0,  (Fl_Callback*)cb_mnuHeaders, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Command line options"), 0,  (Fl_Callback*)cb_mnuOptions, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {_("On Line help"), 0,  (Fl_Callback*)cb_mnuOnLineHelp, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("Download custom forms"), 0, (Fl_Callback*)cb_mnuCustomDownload, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {_("About"), 0,  (Fl_Callback*)cb_mnuAbout, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

int num_custom_entries = 0;
int custom_select = -1;

CUSTOM_PAIRS custom_pairs[NBR_CUSTOM_MENUS];

extern void extract_fields();

static void cb_mnuCustomFormSelect(Fl_Menu_ *, void *d) {
extern string edit_txt;
	size_t n = (size_t)(d);
	custom_select = n;
	selected_form = CUSTOM;
	select_form(selected_form);
	extract_fields();
	txt_custom_msg->clear();
	txt_custom_msg->add(edit_txt.c_str());
}

static void cb_open_custom_transfer_tab(Fl_Menu_ *, void *d) {
	selected_form = CUSTOM_TRANSFER;
	select_form(selected_form);
}

void init_custom_menu()
{
	for (int i = 0; i < NBR_CUSTOM_MENUS; i++) {
		custom_menu[i].text = 0;
		custom_menu[i].shortcut_ = 0;
		custom_menu[i].callback_ = (Fl_Callback*)cb_mnuFormSelect;
		custom_menu[i].user_data_ = (void *)&mCUSTOM,
		custom_menu[i].flags = 0;
		custom_menu[i].labeltype_ = FL_NORMAL_LABEL;
		custom_menu[i].labelfont_ = 0;
		custom_menu[i].labelsize_ = 14;
		custom_menu[i].labelcolor_ = 0;
		custom_pairs[i].mnu_name = 0;
		custom_pairs[i].file_name = 0;
	}
	num_custom_entries = 0;
}

void load_custom_menu()
{
static const string key1 = "<META NAME=\"EDITABLE\" CONTENT=\"true\">";
static const string key2 = "<META NAME=\"MENU_ITEM\" CONTENT=";
	guard_lock web_lock(&mutex_web_server);
	for (int i = 0; i < NBR_CUSTOM_MENUS; i++) {
		custom_menu[i].text = 0;
		custom_menu[i].shortcut_ = 0;
		if (i)
			custom_menu[i].callback_ = (Fl_Callback*)cb_mnuCustomFormSelect;
		else
			custom_menu[i].callback_ = (Fl_Callback*)cb_open_custom_transfer_tab;
		custom_menu[i].user_data_ = 0;
		if (i)
			custom_menu[i].flags = 0;
		else
			custom_menu[i].flags = FL_MENU_DIVIDER;
		custom_menu[i].labeltype_ = FL_NORMAL_LABEL;
		custom_menu[i].labelfont_ = 0;
		custom_menu[i].labelsize_ = 14;
		custom_menu[i].labelcolor_ = 0;
		if (custom_pairs[i].mnu_name) delete [] custom_pairs[i].mnu_name;
		custom_pairs[i].mnu_name = 0;
		if (custom_pairs[i].file_name) delete [] custom_pairs[i].file_name;
		custom_pairs[i].file_name = 0;
	}

	num_custom_entries = 0;

	DIR *cdir = opendir(CUSTOM_dir.c_str());
	if (!cdir) return;
	dirent *dentry = 0;
	string contents;
	string fname;
	string menu_name;
	ifstream in;
	char cin;
	dentry = readdir(cdir);
	while (dentry) {
		fname = CUSTOM_dir;
		fname.append(dentry->d_name);
		if (fname.find(".htm") != string::npos) {
			contents.clear();
			in.open(fname.c_str(), ios::in);
			if (in) {
				while (in.get(cin))
					contents += cin;
				in.close();
				size_t p = string::npos;
				const char *ptr = strcasestr(contents.c_str(), key1.c_str());
				if (ptr) p = ptr - contents.c_str();
				if ( p != string::npos) {
					p = string::npos;
					ptr = strcasestr(contents.c_str(), key2.c_str());
					if (ptr) p = ptr - contents.c_str();
					if (p != string::npos) {
						p += key2.length() + 1;
						contents.erase(0, p);
						p = contents.find("\"");
						menu_name = contents.substr(0, p);
// custom pair item
						custom_pairs[num_custom_entries].mnu_name =
							new char[menu_name.length() + 1];
						strcpy(
							custom_pairs[num_custom_entries].mnu_name,
							menu_name.c_str());

						custom_pairs[num_custom_entries].file_name =
							new char[strlen(dentry->d_name) + 1];
						strcpy(
							custom_pairs[num_custom_entries].file_name,
							dentry->d_name);
						num_custom_entries++;
					}
				}
			}
		}
		dentry = readdir(cdir);
	}
	closedir(cdir);

	for (int i = 0; i < num_custom_entries - 1; i++)
		for (int j = i+1; j < num_custom_entries; j++)
			if (strcmp(custom_pairs[j].mnu_name, custom_pairs[i].mnu_name) < 0) {
				CUSTOM_PAIRS temp = custom_pairs[j];
				custom_pairs[j] = custom_pairs[i];
				custom_pairs[i] = temp;
			}

	custom_menu[0].text = "Transfer FORM";
	custom_menu[0].user_data_ = 0;
	for (int i = 0; i < num_custom_entries; i++) {
// custom menu item
		custom_menu[i+1].text       = custom_pairs[i].mnu_name;
		custom_menu[i+1].user_data_ = reinterpret_cast<void *>(i);
	}
	update_custom_transfer();

	if (temp_combo) {
		temp_combo->clear();
		temp_combo->add(_("Template not selected"));
		for (int i = 0; i < num_custom_entries; i++)
			temp_combo->add(custom_pairs[i].mnu_name);
		temp_combo->index(0);
	}

}

vector<string> custom_files;

void update_custom_transfer()
{
	string current_selection = custom_selector->value();
	custom_files.clear();
	custom_selector->clear();

	if (num_custom_entries == 0) return;

	for (int i = 0; i < num_custom_entries; i++) {
		custom_selector->add(custom_pairs[i].mnu_name);
		custom_files.push_back(custom_pairs[i].file_name);
	}
	if (current_selection.empty())
		custom_selector->index(0);
	else
		custom_selector->value(current_selection.c_str());
	def_custom_transfer_filename = custom_files[custom_selector->index()];
}

void load_custom_transfer()
{
	if (tab_custom_transfer->visible()) return;
	update_custom_transfer();
}

//------------------------------------------------------------------------------

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

void cb_cbo_modes()
{
	estimate();
	if (!progStatus.change_modem_with_autosend)
		send_new_modem();
}


Fl_Double_Window* flmsg_dialog() {
	int W = 570, H = 492;
	Fl_Double_Window* win = new Fl_Double_Window(W, H, "");
	win->begin();
	win->align(FL_ALIGN_INSIDE);

	mb = new Fl_Menu_Bar(0, 0, W - 60, 22);

	mb->menu(menu_);
	init_custom_menu();

	Fl_Menu_Bar *hm = new Fl_Menu_Bar(W-60, 0, 60, 22);
	hm->menu(help_menu_);

	txt_formname = new Fl_Output(4, 26, 220, 20);
	txt_formname->box(FL_FLAT_BOX);
	txt_formname->color(fl_rgb_color(245, 245, 245)); // white smoke

	txt_filename = new Fl_Output(260, 26, 270, 20, _("file:"));
	txt_filename->box(FL_FLAT_BOX);
	txt_filename->align(FL_ALIGN_LEFT);
	txt_filename->color(fl_rgb_color(245, 245, 245));

	drop_file = new Fl_Input2(
		txt_filename->x() + txt_filename->w() + 2, 23, 
		W - txt_filename->x() - txt_filename->w() - 2, 25);
	drop_file->box(FL_THIN_DOWN_BOX);
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

	all_tabs = new Fl_Group(0, tab_top, 570, 390);
		create_ics_tab();
		create_hics_tab();
		create_netlog_tab();
		create_mars_tab();
		create_cap105_tab();
		create_cap110_tab();
		create_iaru_tab();
		create_radiogram_tab();
		create_plaintext_tab();
		create_blank_tab();
		create_csv_tab();
		create_custom_tab();
		create_dnd_tab();
		create_wxhc_tab();
		create_severe_wx_tab();
		create_storm_tab();
		create_transfer_tab();
		create_custom_transfer_tab();
	all_tabs->end();

	controls = new Fl_Group(0, 465 - 30, W, 28, "controls");
	controls->begin();
	controls->box(FL_ENGRAVED_BOX);
	controls->align(FL_ALIGN_INSIDE);
	controls->copy_label("");

	btn_use_compression = new Fl_Check_Button(
		10, controls->y() + 5,
		60, 18, _("Comp"));
	btn_use_compression->tooltip(_("Data will be sent compressed\nif file size is reduced"));
	btn_use_compression->down_box(FL_DOWN_BOX);
	btn_use_compression->callback((Fl_Callback*)cb_use_compression);
	btn_use_compression->value(progStatus.use_compression);

	cbo_modes = new Fl_ListBox(
		btn_use_compression->x() + btn_use_compression->w() + 2, 
		controls->y() + 3, 120, 22, "cbo_modes");
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

	btn_estimate = new Fl_Button(
		cbo_modes->x() + cbo_modes->w() + 2,
		cbo_modes->y() + 2, 18, 18, "*");
	btn_estimate->tooltip(_("Press to update size/time"));
	btn_estimate->callback((Fl_Callback*)cb_btn_estimate);

	txt_xfr_size_time = new Fl_Output(
		btn_estimate->x() + btn_estimate->w() + 2,
		cbo_modes->y(),
		controls->w() - btn_estimate->x() - btn_estimate->w() - 4, 22, ""); 
	txt_xfr_size_time->tooltip(_("Transfer size / time"));

	controls->end();

	arq_group = new Fl_Group(0, H - 28, W, 26);
		arq_group->box(FL_ENGRAVED_FRAME);

		Fl_Group  *arq_title = new Fl_Group(2, arq_group->y()+2, 40, 22, "ARQ");
		arq_title->box(FL_FLAT_BOX);
		arq_title->labeltype(FL_NORMAL_LABEL);
		arq_title->labelfont(0);
		arq_title->labelsize(14);
		arq_title->labelcolor(FL_FOREGROUND_COLOR);
		arq_title->align(Fl_Align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE));
		arq_title->end();

		btnSEND = new Fl_Button(42, arq_group->y()+2, 60, 22, _("Send"));
		btnSEND->tooltip(_("Send data file to this station"));
		btnSEND->callback((Fl_Callback*)cb_btnSEND);

		txtSENDTO = new Fl_Input2(108, arq_group->y()+2, 100, 22);
		txtSENDTO->tooltip(_("Send to this station"));
		txtSENDTO->box(FL_DOWN_BOX);
		txtSENDTO->color(FL_BACKGROUND2_COLOR);
		txtSENDTO->selection_color(FL_SELECTION_COLOR);
		txtSENDTO->labeltype(FL_NORMAL_LABEL);
		txtSENDTO->labelfont(0);
		txtSENDTO->labelsize(14);
		txtSENDTO->labelcolor(FL_FOREGROUND_COLOR);
		txtSENDTO->align(Fl_Align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE));
		txtSENDTO->when(FL_WHEN_RELEASE);

		txtSTATE = new Fl_Input2(210, arq_group->y()+2, 200, 22, "");
		txtSTATE->box(FL_FLAT_BOX);
		txtSTATE->color(FL_BACKGROUND_COLOR);
		txtSTATE->selection_color(FL_SELECTION_COLOR);
		txtSTATE->labeltype(FL_NORMAL_LABEL);
		txtSTATE->labelfont(0);
		txtSTATE->labelsize(14);
		txtSTATE->labelcolor(FL_BLACK);
		txtSTATE->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
		txtSTATE->when(FL_WHEN_RELEASE);
		txtSTATE->type(FL_NORMAL_OUTPUT);

		prgSTATE = new Fl_Progress(W - 74, arq_group->y()+3, 70, 20);
		prgSTATE->tooltip(_("ARQ transfer progress"));
		prgSTATE->selection_color((Fl_Color)70);
		prgSTATE->labelfont(1);
		prgSTATE->minimum(0.0);
		prgSTATE->maximum(1.0);

	arq_group->end();

	win->end();

	win->resizable(all_tabs);

	init_cbo_modes();

	return win;
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

Fl_ListBox	*sel_hx_select = (Fl_ListBox *)0;

static void cb_sel_hx_select(Fl_ListBox*, void*) {
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

		sel_hx_select = new Fl_ListBox(3, 20, 68, 24, _("HX__:"));
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

//==============================================================================
// configuration dialog
//==============================================================================
Fl_Round_Button		*btn_dtformat0 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_dtformat1 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_dtformat2 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_dtformat3 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_dtformat4 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format0 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format1 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format2 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format3 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format4 = (Fl_Round_Button *)0;
Fl_Round_Button		*btn_utc_format5 = (Fl_Round_Button *)0;
Fl_Check_Button		*btn_caplocal = (Fl_Check_Button *)0;

Fl_Input2			*txt_my_call = (Fl_Input2 *)0;
Fl_Input2			*txt_my_tel = (Fl_Input2 *)0;
Fl_Input2			*txt_my_name = (Fl_Input2 *)0;
Fl_Input2			*txt_my_addr = (Fl_Input2 *)0;
Fl_Input2			*txt_my_city = (Fl_Input2 *)0;
Fl_Input2			*txt_my_email = (Fl_Input2 *)0;

Fl_Check_Button		*btn_open_on_export = (Fl_Check_Button *)0;
Fl_Check_Button		*btn_call_fname = (Fl_Check_Button *)0;
Fl_ListBox			*cbo_dt_fname = (Fl_ListBox *)0;
Fl_Check_Button		*btn_sernbr_fname = (Fl_Check_Button *)0;
Fl_Input2			*txt_sernbr = (Fl_Input2 *)0;

Fl_Spinner			*cnt_wpl = (Fl_Spinner *)0;
Fl_Check_Button		*btn_rgnbr_fname = (Fl_Check_Button *)0;
Fl_Check_Button		*btn_arl_desc = (Fl_Check_Button *)0;
Fl_Check_Button		*btn_rri = (Fl_Check_Button *)0;
Fl_Input2			*txt_rgnbr = (Fl_Input2 *)0;

Fl_Input2 * txt_socket_addr = (Fl_Input2 *)0;
Fl_Input2 * txt_socket_port = (Fl_Input2 *)0;

void set_datetime_widgets()
{
	txt_213_d1->format(progStatus.dtformat);
	txt_213_d2->format(progStatus.dtformat);
	h206_txt_date_prepared->format(progStatus.dtformat);
	h213_txt_date->format(progStatus.dtformat);
	txt_pt_date->format(progStatus.dtformat);
	w_storm_date->format(progStatus.dtformat);
	w_severe_wx_date->format(progStatus.dtformat);
}

static void cb_btn_dtformat0(Fl_Round_Button* o, void*)
{
	btn_dtformat3->value(0);
	btn_dtformat1->value(0);
	btn_dtformat2->value(0);
	btn_dtformat4->value(0);
	if (o->value()) {
		progStatus.dtformat = 0;
	} else {
		btn_dtformat4->value(1);
		progStatus.dtformat = 4;
	}
	set_datetime_widgets();
}

static void cb_btn_dtformat1(Fl_Round_Button* o, void*)
{
	btn_dtformat0->value(0);
	btn_dtformat3->value(0);
	btn_dtformat2->value(0);
	btn_dtformat4->value(0);
	if (o->value()) {
		progStatus.dtformat = 1;
	} else {
		btn_dtformat4->value(1);
		progStatus.dtformat = 4;
	}
	set_datetime_widgets();
}

static void cb_btn_dtformat2(Fl_Round_Button* o, void*)
{
	btn_dtformat0->value(0);
	btn_dtformat1->value(0);
	btn_dtformat3->value(0);
	btn_dtformat4->value(0);
	if (o->value()) {
		progStatus.dtformat = 2;
	} else {
		btn_dtformat4->value(1);
		progStatus.dtformat = 4;
	}
	set_datetime_widgets();
}

static void cb_btn_dtformat3(Fl_Round_Button* o, void*)
{
	btn_dtformat0->value(0);
	btn_dtformat1->value(0);
	btn_dtformat2->value(0);
	btn_dtformat4->value(0);
	if (o->value()) {
		progStatus.dtformat = 3;
	} else {
		btn_dtformat4->value(1);
		progStatus.dtformat = 4;
	}
	set_datetime_widgets();
}

static void cb_btn_dtformat4(Fl_Round_Button* o, void*)
{
	btn_dtformat0->value(0);
	btn_dtformat1->value(0);
	btn_dtformat2->value(0);
	btn_dtformat3->value(0);
	btn_dtformat4->value(1);

	progStatus.dtformat = 4;

	set_datetime_widgets();
}

static void cb_btn_utc_format0(Fl_Round_Button* o, void*)
{
	if (o->value()) {
		progStatus.UTC = 0;
		btn_utc_format1->value(0);
		btn_utc_format2->value(0);
		btn_utc_format3->value(0);
		btn_utc_format4->value(0);
		btn_utc_format5->value(0);
	}
}

static void cb_btn_utc_format1(Fl_Round_Button* o, void*)
{
	if (o->value()) {
		progStatus.UTC = 1;
		btn_utc_format0->value(0);
		btn_utc_format2->value(0);
		btn_utc_format3->value(0);
		btn_utc_format4->value(0);
		btn_utc_format5->value(0);
	}
}

static void cb_btn_utc_format2(Fl_Round_Button* o, void*)
{
	if (o->value()) {
		progStatus.UTC = 2;
		btn_utc_format1->value(0);
		btn_utc_format0->value(0);
		btn_utc_format3->value(0);
		btn_utc_format4->value(0);
		btn_utc_format5->value(0);
	}
}

static void cb_btn_utc_format3(Fl_Round_Button* o, void*)
{
	if (o->value()) {
		progStatus.UTC = 3;
		btn_utc_format1->value(0);
		btn_utc_format2->value(0);
		btn_utc_format0->value(0);
		btn_utc_format4->value(0);
		btn_utc_format5->value(0);
	}
}

static void cb_btn_utc_format4(Fl_Round_Button* o, void*)
{
	if (o->value()) {
		progStatus.UTC = 4;
		btn_utc_format1->value(0);
		btn_utc_format2->value(0);
		btn_utc_format3->value(0);
		btn_utc_format0->value(0);
		btn_utc_format5->value(0);
	}
}

static void cb_btn_utc_format5(Fl_Round_Button* o, void*)
{
	if (o->value()) {
		progStatus.UTC = 5;
		btn_utc_format1->value(0);
		btn_utc_format2->value(0);
		btn_utc_format3->value(0);
		btn_utc_format4->value(0);
		btn_utc_format0->value(0);
	}
}

static void cb_caplocal(Fl_Check_Button *o, void*)
{
	if (o->value())
		progStatus.caplocal = true;
	else
		progStatus.caplocal = false;
}

static void cb_txt_my_call(Fl_Input* o, void*)
{
	progStatus.my_call = o->value();
}

static void cb_txt_my_tel(Fl_Input* o, void*)
{
	progStatus.my_tel = o->value();
}

static void cb_txt_my_name(Fl_Input* o, void*)
{
	progStatus.my_name = o->value();
}

static void cb_txt_my_addr(Fl_Input* o, void*)
{
	progStatus.my_addr = o->value();
}

static void cb_txt_my_email(Fl_Input* o, void*)
{
	progStatus.my_email = o->value();
}

static void cb_txt_my_city(Fl_Input* o, void*)
{
	progStatus.my_city = o->value();
}

static void cb_cnt_wpl(Fl_Spinner* o, void*)
{
	progStatus.wpl = (int)o->value();
}

static void cb_btn_open_on_export(Fl_Check_Button* o, void*)
{
	progStatus.open_on_export = o->value();
}

static void cb_btn_call_fname(Fl_Check_Button* o, void*)
{
	progStatus.call_fname = o->value();
}

static void cb_cbo_dt_fname(Fl_ListBox * o, void *)
{
	progStatus.dt_fname = o->index();
}

static void cb_btn_sernbr_fname(Fl_Check_Button* o, void*)
{
	progStatus.sernbr_fname = o->value();
}

static void cb_txt_sernbr(Fl_Input* o, void*)
{
	progStatus.sernbr = o->value();
}

static void cb_btn_rgnbr_fname(Fl_Check_Button* o, void*)
{
	progStatus.rgnbr_fname = o->value();
}

static void cb_txt_rgnbr(Fl_Input* o, void*)
{
	progStatus.rgnbr = o->value();
}

static void cb_btn_arl_desc(Fl_Check_Button* o, void*)
{
	progStatus.arl_desc = o->value();
}

static void cb_btn_rri(Fl_Check_Button* o, void*)
{
	progStatus.rri = o->value();
}

Fl_Group *create_tab_date_time(int X, int Y, int W, int H, const char *title)
{
	Fl_Group *grp = new Fl_Group(X, Y, W, H, title);

	Y += 40;
	X += 40;

	btn_dtformat0 = new Fl_Round_Button(X, Y+8, 70, 20, _("YYYY-MM-DD"));
	btn_dtformat0->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat0->callback((Fl_Callback*)cb_btn_dtformat0);
	if (progStatus.dtformat == 0) btn_dtformat0->value(1); else btn_dtformat0->value(0);

	btn_dtformat3 = new Fl_Round_Button(X, Y+30, 70, 20, _("YYYY-DD-MM"));
	btn_dtformat3->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat3->callback((Fl_Callback*)cb_btn_dtformat3);
	if (progStatus.dtformat == 3) btn_dtformat3->value(1); else btn_dtformat3->value(0);

	btn_dtformat1 = new Fl_Round_Button(X, Y+52, 70, 20, _("MM/DD/YY"));
	btn_dtformat1->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat1->callback((Fl_Callback*)cb_btn_dtformat1);
	if (progStatus.dtformat == 1) btn_dtformat1->value(1); else btn_dtformat1->value(0);

	btn_dtformat2 = new Fl_Round_Button(X, Y+74, 70, 20, _("DD/MM/YY"));
	btn_dtformat2->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat2->callback((Fl_Callback*)cb_btn_dtformat2);
	if (progStatus.dtformat == 2) btn_dtformat2->value(1); else btn_dtformat2->value(0);

	btn_dtformat4 = new Fl_Round_Button(X, Y+96, 70, 20, _("YYYYMMDD"));
	btn_dtformat4->down_box(FL_ROUND_DOWN_BOX);
	btn_dtformat4->callback((Fl_Callback*)cb_btn_dtformat4);
	if (progStatus.dtformat == 4) btn_dtformat4->value(1); else btn_dtformat4->value(0);

	btn_caplocal = new Fl_Check_Button(X, Y+140, 70, 20, _("CAP Local date/time"));
	btn_caplocal->tooltip(_("Check to use local date/time\ndefault Zulu"));
	btn_caplocal->callback((Fl_Callback*)cb_caplocal);

	X += 200;
	btn_utc_format0 = new Fl_Round_Button(X, Y+8, 70, 20, _("hhmmL"));
	btn_utc_format0->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format0->callback((Fl_Callback*)cb_btn_utc_format0);
	if (progStatus.UTC == 0) btn_utc_format0->value(1); else btn_utc_format0->value(0);

	btn_utc_format1 = new Fl_Round_Button(X, Y+30, 70, 20, _("hh:mmL"));
	btn_utc_format1->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format1->callback((Fl_Callback*)cb_btn_utc_format1);
	if (progStatus.UTC == 1) btn_utc_format1->value(1); else btn_utc_format1->value(0);

	btn_utc_format2 = new Fl_Round_Button(X, Y+52, 70, 20, _("hhmmZ"));
	btn_utc_format2->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format2->callback((Fl_Callback*)cb_btn_utc_format2);
	if (progStatus.UTC == 2) btn_utc_format2->value(1); else btn_utc_format2->value(0);

	btn_utc_format3 = new Fl_Round_Button(X, Y+74, 70, 20, _("hh:mmZ"));
	btn_utc_format3->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format3->callback((Fl_Callback*)cb_btn_utc_format3);
	if (progStatus.UTC == 3) btn_utc_format3->value(1); else btn_utc_format3->value(0);

	btn_utc_format4 = new Fl_Round_Button(X, Y+96, 70, 20, _("hhmm UTC"));
	btn_utc_format4->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format4->callback((Fl_Callback*)cb_btn_utc_format4);
	if (progStatus.UTC == 4) btn_utc_format4->value(1); else btn_utc_format4->value(0);

	btn_utc_format5 = new Fl_Round_Button(X, Y+118, 70, 20, _("hh:mm UTC"));
	btn_utc_format5->down_box(FL_ROUND_DOWN_BOX);
	btn_utc_format5->callback((Fl_Callback*)cb_btn_utc_format5);
	if (progStatus.UTC == 5) btn_utc_format5->value(1); else btn_utc_format5->value(0);

	grp->end();
	return grp;
}

Fl_Group *create_tab_personal(int X, int Y, int W, int H, const char *title)
{
	Fl_Group *grp = new Fl_Group(X, Y, W, H, title);

	Y += 10;

	txt_my_call = new Fl_Input2(X+90, Y+6, W - 94, 24, _("Call:"));
	txt_my_call->callback((Fl_Callback*)cb_txt_my_call);
	txt_my_call->value(progStatus.my_call.c_str());

	txt_my_tel = new Fl_Input2(X+90, Y+32, W - 94, 24, _("Tel:"));
	txt_my_tel->callback((Fl_Callback*)cb_txt_my_tel);
	txt_my_tel->value(progStatus.my_tel.c_str());

	txt_my_name = new Fl_Input2(X+90, Y+58, W - 94, 24, _("Name:"));
	txt_my_name->callback((Fl_Callback*)cb_txt_my_name);
	txt_my_name->value(progStatus.my_name.c_str());

	txt_my_addr = new Fl_Input2(X+90, Y+84, W - 94, 24, _("Addr:"));
	txt_my_addr->callback((Fl_Callback*)cb_txt_my_addr);
	txt_my_addr->value(progStatus.my_addr.c_str());

	txt_my_city = new Fl_Input2(X+90, Y+110, W - 94, 24, _("City/St/Zip:"));
	txt_my_city->callback((Fl_Callback*)cb_txt_my_city);
	txt_my_city->value(progStatus.my_city.c_str());

	txt_my_email = new Fl_Input2(X+90, Y+136, W - 94, 24, _("Email addr:"));
	txt_my_email->callback((Fl_Callback*)cb_txt_my_email);
	txt_my_email->value(progStatus.my_email.c_str());

	grp->end();
	return grp;
}

Fl_Group *create_tab_radiogram(int X, int Y, int W, int H, const char *title)
{
	Fl_Group *grp = new Fl_Group(X, Y, W, H, title);

	Y += 30;

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

	Y += 30;
	btn_rri = new Fl_Check_Button(60, Y, 70, 24, _("Radio Relay International"));
	btn_rri->tooltip(_("Use RRI radiogram templates"));
	btn_rri->down_box(FL_DOWN_BOX);
	btn_rri->callback((Fl_Callback*)cb_btn_rri);
	btn_rri->value(progStatus.rri);

	grp->end();
	return grp;
}

void cb_find_roster()
{
	string filename = ICS_dir;
	filename.append("MARS_ROSTER.csv");

	Fl_Native_File_Chooser native;

	native.filter("csv file\t*.{csv,CSV}");
	native.title(_("Select MARS roster file"));
	native.preset_file(filename.c_str());
	native.type(Fl_Native_File_Chooser::BROWSE_FILE);
	native.options(Fl_Native_File_Chooser::PREVIEW);
	native.directory(ICS_dir.c_str());

	switch ( native.show() ) {
		case -1: // ERROR
			LOG_ERROR("ERROR: %s\n", native.errmsg()); // Error fall through
		case  1: // CANCEL
			break;
		default:
			progStatus.mars_roster_file = native.filename();
			txt_mars_roster_file->value(progStatus.mars_roster_file.c_str());
			break;
	}

}

void cb_autowordwrap()
{
	progStatus.autowordwrap = btnAutoWordWrap->value();
}

void cb_send_original()
{
	progStatus.send_original = btnSendOriginalFile->value();
}

void cb_charcount()
{
	progStatus.charcount = cntCharCount->value();
}

Fl_Group *create_tab_files(int X, int Y, int W, int H, const char *title)
{
	Fl_Group *grp = new Fl_Group(X, Y, W, H, title);

	Y += 10;

	Fl_Group* group1 = new Fl_Group(X + 2, Y, W-4, 50, _("Wrap"));
	group1->box(FL_ENGRAVED_FRAME);
	group1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
		btn_open_on_export = new Fl_Check_Button(X+10, Y + 24, 18, 18, _("Open folder when exporting"));
		btn_open_on_export->tooltip(_(""));
		btn_open_on_export->down_box(FL_DOWN_BOX);
		btn_open_on_export->callback((Fl_Callback*)cb_btn_open_on_export);
		btn_open_on_export->value(progStatus.open_on_export);
	group1->end();

	Fl_Group* group2 = new Fl_Group(X + 2, Y + 52, W-4, 70, _("Naming Files"));
	group2->box(FL_ENGRAVED_FRAME);
	group2->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
		btn_call_fname = new Fl_Check_Button(X+10, Y+74, 18, 18, _("Callsign"));
		btn_call_fname->down_box(FL_DOWN_BOX);
		btn_call_fname->callback((Fl_Callback*)cb_btn_call_fname);
		btn_call_fname->value(progStatus.call_fname);
		btn_call_fname->tooltip(_("Add CALL to date-time"));

		cbo_dt_fname = new Fl_ListBox(X+120, Y + 73, 200, 20, _("Date-time"));
		cbo_dt_fname->callback((Fl_Callback*)cb_cbo_dt_fname);
		cbo_dt_fname->add("not used");
		cbo_dt_fname->add("Local time,  L");
		cbo_dt_fname->add("Local time, TZ name");
		cbo_dt_fname->add("Local time, TZ offset");
		cbo_dt_fname->add("UTC time,    Z");
		cbo_dt_fname->index(progStatus.dt_fname);

		btn_sernbr_fname = new Fl_Check_Button(X+10, Y + 95, 18, 18, _("Serial #"));
		btn_sernbr_fname->down_box(FL_DOWN_BOX);
		btn_sernbr_fname->callback((Fl_Callback*)cb_btn_sernbr_fname);
		btn_sernbr_fname->value(progStatus.sernbr_fname);
		btn_sernbr_fname->tooltip(_("Add incremental serial number to filename"));

		txt_sernbr = new Fl_Input2(X +100, Y+96, 66, 20, _("Next #"));
		txt_sernbr->type(2);
		txt_sernbr->callback((Fl_Callback*)cb_txt_sernbr);
		txt_sernbr->align(FL_ALIGN_RIGHT);
		txt_sernbr->value(progStatus.sernbr.c_str());
	group2->end();

	Fl_Group* group3 = new Fl_Group(X + 2, Y + 124, W-4, 46, "");
	group3->box(FL_ENGRAVED_FRAME);
		txt_mars_roster_file = new Fl_Input2(X+10, Y + 144, 360, 22, _("MARS roster file"));
		txt_mars_roster_file->align(FL_ALIGN_TOP_LEFT);

		Fl_Button *btn_find_roster = new Fl_Button(X+372, Y + 144, 68, 22, _("Find"));
		btn_find_roster->callback((Fl_Callback*)cb_find_roster);

	group3->end();

	Fl_Group* group4 = new Fl_Group(X+2, Y + 172, W-4, 46, "Html message text");
	group4->box(FL_ENGRAVED_FRAME);
	group4->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
		btnAutoWordWrap = new Fl_Check_Button(X+10, Y+194, 18, 18, _("Word wrap at "));
		btnAutoWordWrap->down_box(FL_DOWN_BOX);
		btnAutoWordWrap->value(progStatus.autowordwrap);
		btnAutoWordWrap->callback((Fl_Callback*)cb_autowordwrap);

		cntCharCount = new Fl_Counter(X+135, Y+193, 60, 20, _("characters"));
		cntCharCount->align(FL_ALIGN_RIGHT);
		cntCharCount->value(progStatus.charcount);
		cntCharCount->type(FL_SIMPLE_COUNTER);
		cntCharCount->step(1);
		cntCharCount->callback((Fl_Callback*)cb_charcount);
	group4->end();

	Fl_Group* group5 = new Fl_Group(X+2, Y + 220, W-4, 42, _("File transfers"));
	group5->box(FL_ENGRAVED_FRAME);
	group5->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
		btnSendOriginalFile = new Fl_Check_Button(X+10, Y+240, 18, 18, _("Do not compress file"));
		btnSendOriginalFile->down_box(FL_DOWN_BOX);
		btnSendOriginalFile->value(progStatus.send_original);
		btnSendOriginalFile->callback((Fl_Callback*)cb_send_original);
	group5->end();

	grp->end();
	return grp;
}

//----------------------------------------------------------------------
// ARQ config tab
//----------------------------------------------------------------------

static void cb_txt_socket_addr(Fl_Input* o, void*) {
	progStatus.xmlrpc_addr = o->value();
}

static void cb_txt_socket_port(Fl_Input* o, void*) {
	progStatus.xmlrpc_port = o->value();
}

static void cb_socket_default(Fl_Input* o, void*) {
	progStatus.xmlrpc_addr = "127.0.0.1";
	progStatus.xmlrpc_port = "7362";
	txt_socket_addr->value(progStatus.xmlrpc_addr.c_str());
	txt_socket_port->value(progStatus.xmlrpc_port.c_str());
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

Fl_Spinner2 *spnRetries      = (Fl_Spinner2 *)0;
Fl_Spinner2 *spnWaitTime     = (Fl_Spinner2 *)0;
Fl_Counter *cntrTimeout      = (Fl_Counter2 *)0;
Fl_Check_Button *btn_notify_receipt = (Fl_Check_Button *)0;
Fl_ComboBox *choiceBlockSize = (Fl_ComboBox *)0;
Fl_Check_Button *btnAutoOpen = (Fl_Check_Button *)0;
Fl_Check_Button *btnIDon   = (Fl_Check_Button *)0;
Fl_Check_Button *btnIDoff  = (Fl_Check_Button *)0;

static void cb_cntrTimeout(Fl_Counter2* o, void*) {
	progStatus.arq_notify_timeout = (int)o->value();
}

static void cb_notify_receipt(Fl_Check_Button *o, void *) {
	progStatus.notify_receipt = (int)o->value();
}

static void cb_spnRetries(Fl_Spinner2* o, void*) {
	progStatus.retries = (int)o->value();
	flmsg_arq.setRetries(progStatus.retries);
}

static void cb_auto_open(Fl_Check_Button* o, void*) {
	progStatus.auto_open_url = o->value();
}

static void cb_choiceBlockSize(Fl_ComboBox* o, void*) {
	progStatus.exponent = (int)o->index() + 4;
	flmsg_arq.setExponent(progStatus.exponent);
}

static void cb_ID_on(Fl_Check_Button* o, void*) {
	progStatus.ID_on = o->value();
}

static void cb_ID_off(Fl_Check_Button* o, void*) {
	progStatus.ID_off = o->value();
}

static void cb_ID_restore(Fl_Check_Button* o, void*) {
	progStatus.ID_restore = o->value();
}

Fl_Group *create_tab_arq(int X, int Y, int W, int H, const char *title)
{
	Fl_Group *grp = new Fl_Group(X, Y, W, H, title);

	Y += 10;
	X += 80;

	txt_socket_addr = new Fl_Input2(X+100, Y, 130, 22, _("Fldigi xmlrpc Addr: "));
	txt_socket_addr->tooltip(_("default = 127.0.0.1"));
	txt_socket_addr->callback((Fl_Callback*)cb_txt_socket_addr);
	txt_socket_addr->value(progStatus.xmlrpc_addr.c_str());

	Y += 25;
	txt_socket_port = new Fl_Input2(X+100, Y, 130, 22, _("Fldigi xmlrpc Port: "));
	txt_socket_port->tooltip(_("default = 7362"));
	txt_socket_port->callback((Fl_Callback*)cb_txt_socket_port);
	txt_socket_port->value(progStatus.xmlrpc_port.c_str());

	Y += 25;
	X -= 60;
	spnRetries = new Fl_Spinner2(X, Y, 50, 24, _("Retries"));
	spnRetries->tooltip(_("# retries before connection declared down"));
	spnRetries->box(FL_NO_BOX);
	spnRetries->color(FL_BACKGROUND2_COLOR);
	spnRetries->selection_color(FL_BACKGROUND_COLOR);
	spnRetries->labeltype(FL_NORMAL_LABEL);
	spnRetries->labelfont(0);
	spnRetries->labelsize(14);
	spnRetries->labelcolor(FL_FOREGROUND_COLOR);
	spnRetries->callback((Fl_Callback*)cb_spnRetries);
	spnRetries->align(Fl_Align(FL_ALIGN_RIGHT));
	spnRetries->when(FL_WHEN_RELEASE);
	spnRetries->minimum(2);
	spnRetries->maximum(20);
	spnRetries->step(1);
	spnRetries->value(progStatus.retries);

	choiceBlockSize = new Fl_ComboBox(X+200, Y, 100, 24, _("Block Size"));
	choiceBlockSize->box(FL_DOWN_BOX);
	choiceBlockSize->color(FL_BACKGROUND2_COLOR);
	choiceBlockSize->selection_color(FL_BACKGROUND_COLOR);
	choiceBlockSize->labeltype(FL_NORMAL_LABEL);
	choiceBlockSize->labelfont(0);
	choiceBlockSize->labelsize(14);
	choiceBlockSize->labelcolor(FL_FOREGROUND_COLOR);
	choiceBlockSize->callback((Fl_Callback*)cb_choiceBlockSize);
	choiceBlockSize->align(Fl_Align(FL_ALIGN_RIGHT));
	choiceBlockSize->when(FL_WHEN_RELEASE);
	choiceBlockSize->add("16");
	choiceBlockSize->add("32");
	choiceBlockSize->add("64");
	choiceBlockSize->add("128");
	choiceBlockSize->add("256");
	choiceBlockSize->add("512");
	choiceBlockSize->add("1024");
	choiceBlockSize->index(progStatus.exponent - 4);
	choiceBlockSize->end();

	Y += 28;
	cntrTimeout = new Fl_Counter2(X, Y, 120, 24, _("Notifier timeout"));
	cntrTimeout->tooltip(_("Keep notifier dialog open for ## secs\nZero = no timeout"));
	cntrTimeout->labeltype(FL_NORMAL_LABEL);
	cntrTimeout->labelfont(0);
	cntrTimeout->labelsize(14);
	cntrTimeout->callback((Fl_Callback*)cb_cntrTimeout);
	cntrTimeout->align(Fl_Align(FL_ALIGN_RIGHT));
	cntrTimeout->when(FL_WHEN_RELEASE);
	cntrTimeout->minimum(0);
	cntrTimeout->maximum(600);
	cntrTimeout->step(1);
	cntrTimeout->lstep(10);
	cntrTimeout->value(progStatus.arq_notify_timeout);

	btn_notify_receipt = new Fl_Check_Button(X + 250, Y, 22, 22, _("Notify Receipt"));
	btn_notify_receipt->tooltip(_("Enable to display receipt notification dialog"));
	btn_notify_receipt->value(progStatus.notify_receipt);
	btn_notify_receipt->callback((Fl_Callback*)cb_notify_receipt);

	Y += 24;
	X += 60;
	btnIDon = new Fl_Check_Button(X, Y, 22, 22, _("Enable ID/RxID"));
	btnIDon->tooltip(_("Enable ID during ARQ session"));
	btnIDon->value(progStatus.ID_on);
	btnIDon->callback((Fl_Callback*)cb_ID_on);

	Y += 24;
	btnIDoff = new Fl_Check_Button(X, Y, 22, 22, _("Disable ID/RxID after connect"));
	btnIDoff->tooltip(_("Disable ID after connect is established"));
	btnIDoff->value(progStatus.ID_off);
	btnIDoff->callback((Fl_Callback*)cb_ID_off);

	Y += 24;
	btnIDoff = new Fl_Check_Button(X, Y, 22, 22, _("Restore ID/RxID"));
	btnIDoff->tooltip(_("Restore ID/RsID after ARQ session"));
	btnIDoff->value(progStatus.ID_restore);
	btnIDoff->callback((Fl_Callback*)cb_ID_restore);

	Y += 24;
	btnAutoOpen = new Fl_Check_Button(X, Y, 22, 22, _("Open Browser"));
	btnAutoOpen->tooltip(_("Open msg in browser on successful receipt"));
	btnAutoOpen->value(progStatus.auto_open_url);
	btnAutoOpen->callback((Fl_Callback*)cb_auto_open);

	Y += 24;
	btn_sync_modem_to_fldigi = new Fl_Check_Button(X, Y, 24, 22, _("Sync modem to fldigi"));
	btn_sync_modem_to_fldigi->tooltip(_("flmsg will follow modem change in fldigi"));
	btn_sync_modem_to_fldigi->value(progStatus.sync_modem_to_fldigi);
	btn_sync_modem_to_fldigi->callback((Fl_Callback*)cb_sync_modem_to_fldigi);

	Y += 24;
	btn_change_modem_with_autosend = new Fl_Check_Button(X, Y, 24, 22, _("Change modem with autosend"));
	btn_change_modem_with_autosend->tooltip(_("flmsg sends new modem to fldigi after \"autosend\""));
	btn_change_modem_with_autosend->value(progStatus.change_modem_with_autosend);
	btn_change_modem_with_autosend->callback((Fl_Callback*)cb_change_modem_with_autosend);

	Y -= 2;
	X = W - 80 - 10;
	Fl_Button *btn_socket_default = new Fl_Button(X, Y, 80, 24, _("Defaults"));
	btn_socket_default->tooltip("Reset all ARQ values to default");
	btn_socket_default->callback((Fl_Callback*)cb_socket_default);
	grp->end();
	return grp;
}

Fl_Check_Button *btn_UI = (Fl_Check_Button *)0;

void cb_UI_set(void *)
{
	progStatus.UI_expert = btn_UI->value();
}

Fl_Group *create_tab_UI(int X, int Y, int W, int H, const char *title)
{
	Fl_Group *grp = new Fl_Group(X, Y, W, H, title);

		Y += 20;
		X += 90;
		btn_UI = new Fl_Check_Button(X, Y, 22, 22, _("User Interface = expert"));
		btn_UI->tooltip(_("\
Startup User Interface:\n\
Checked   - Expert Interface\n\
Unchecked - Service Agency (simple)\n\
"));
		btn_UI->value(progStatus.UI_expert);
		btn_UI->callback((Fl_Callback*)cb_UI_set);

	grp->end();
	return grp;
}
//----------------------------------------------------------------------

Fl_Tabs		*tabs_config			= (Fl_Tabs *)0;
Fl_Group	*tab_date_time			= (Fl_Group *)0;
Fl_Group	*tab_personal			= (Fl_Group *)0;
Fl_Group	*tab_config_radiogram	= (Fl_Group *)0;
Fl_Group	*tab_files				= (Fl_Group *)0;
Fl_Group	*tab_headers			= (Fl_Group *)0;
Fl_Group	*tab_arq				= (Fl_Group *)0;
Fl_Group	*tab_UI					= (Fl_Group *)0;

Fl_Double_Window* create_config_dialog() {
	int W = 450, H = 300, X = 0, Y = 0;
	Fl_Double_Window* w = new Fl_Double_Window(W, H, _("flmsg config"));
	w->begin();
		tabs_config = new Fl_Tabs(X, Y, W, H);
		tabs_config->selection_color((Fl_Color)246);
			Y += 25;
			H -= 25;
			tab_personal  = create_tab_personal(X, Y, W, H, _("Personal"));
			tab_date_time = create_tab_date_time(X, Y, W, H, _("Date/Time"));
			tab_files     = create_tab_files(X, Y, W, H, _("Files"));
			tab_config_radiogram = create_tab_radiogram(X, Y, W, H, _("Radiogram"));
			tab_arq       = create_tab_arq(X, Y, W, H, _("ARQ"));
			tab_UI        = create_tab_UI(X, Y, W, H, _("UI"));
		tabs_config->end();
	w->end();
	return w;
}

//----------------------------------------------------------------------
// ARQ events dialog
//----------------------------------------------------------------------

Fl_Browser *btext = (Fl_Browser *)0;

static void clear_cb(Fl_Widget* w, void*)
{
	btext->clear();
}

void add_event(string s)
{
	if (!btext) return;
	btext->add(s.c_str());
	btext->bottomline(btext->size());
	btext->redraw();
}

Fl_Double_Window* create_ARQ_event_dialog()
{
	int W = 570, H = 300;
	Fl_Double_Window* w = new Fl_Double_Window(W, H, _("flmsg ARQ events"));
	w->begin();
		Fl_Button* clearbtn = new Fl_Button(w->w() - 64, 2, 60, 22, _("Clear"));
		clearbtn->callback(clear_cb);
		btext = new Fl_Browser(2,  clearbtn->h() + 4, w->w() - 4, w->h() - clearbtn->h() - 6, 0);
		btext->textfont(FL_HELVETICA);
		btext->textsize(14);
		w->resizable(btext);
	w->end();
	return w;
}

//----------------------------------------------------------------------
// received msgs dialog
//----------------------------------------------------------------------
Fl_Double_Window *rcvd_msgs_dialog = (Fl_Double_Window *)0;
Fl_Hold_Browser  *bmsgs = (Fl_Hold_Browser *)0;
Fl_Button        *btnShow = (Fl_Button *)0;
Fl_Button        *btnClearSelected = (Fl_Button *)0;
Fl_Button        *btnClearAll = (Fl_Button *)0;

void add_rcvd_msg(string s)
{
	if (!rcvd_msgs_dialog) rcvd_msgs_dialog = create_rcvd_msgs_dialog();
	bmsgs->add(s.c_str());
	bmsgs->bottomline(bmsgs->size());
	bmsgs->redraw();
	if (!rcvd_msgs_dialog->visible()) rcvd_msgs_dialog->show();
}

void cb_view_msg(Fl_Button *w, void *d)
{
	if (bmsgs->value() == 0) return;
	string pathname = ICS_msg_dir;
	pathname.append(bmsgs->text(bmsgs->value()));

	read_data_file(pathname);
	show_filename(pathname);

	if(progStatus.auto_open_url)
		cb_html();
}

void cb_clear_selected(Fl_Button *w, void *d)
{
	if (bmsgs->value())
		bmsgs->remove(bmsgs->value());
}

void cb_clear_all(Fl_Button *w, void *d)
{
	bmsgs->clear();
}

Fl_Double_Window* create_rcvd_msgs_dialog()
{
	int W = 260, H = 300;
	Fl_Double_Window* w = new Fl_Double_Window( W, H, _("Rcvd Msgs") );
	w->begin();
		bmsgs = new Fl_Hold_Browser(2, 2, w->w() - 4, w->h() - 30, 0);
		bmsgs->textfont(FL_HELVETICA);
		bmsgs->textsize(14);

		btnClearSelected = new Fl_Button( 2, w->h() - 26, 80, 24, _("Clear Sel'") );
		btnClearSelected->tooltip(_("Clear selected file from list"));
		btnClearSelected->callback((Fl_Callback*)cb_clear_selected);

		btnClearAll = new Fl_Button( 86, w->h() - 26, 80, 24, _("Clear All") );
		btnClearAll->tooltip(_("Clear all files from list"));
		btnClearAll->callback((Fl_Callback*)cb_clear_all);

		btnShow = new Fl_Button( w->w() - 62, w->h() - 26, 60, 24, _("View") );
		btnShow->tooltip(_("View selected file"));
		btnShow->callback((Fl_Callback*)cb_view_msg);

		w->resizable(bmsgs);
	w->end();
	return w;
}

//----------------------------------------------------------------------
// pick custom message dialog
//----------------------------------------------------------------------
Fl_Double_Window *custom_msg_dialog = (Fl_Double_Window *)0;
Fl_Hold_Browser  *bcustom = (Fl_Hold_Browser *)0;
Fl_Button        *btnCustomCancel = (Fl_Button *)0;
Fl_Button		 *btnCustomSelect = (Fl_Button *)0;

void cb_custom_cancel(Fl_Button *w, void *d)
{
	custom_msg_dialog->hide();
}

void cb_custom_select(Fl_Button *w, void *d)
{
	custom_select = bcustom->value() - 1;
	if (custom_select < 0) {
		custom_msg_dialog->hide();
		return;
	}
	
	select_form(selected_form = CUSTOM);
	cb_custom_new();
	update_custom = true;

	custom_msg_dialog->hide();

	handle_type = HANDLE_EDIT;
	string url = "http://127.0.0.1:";
	url.append(sz_srvr_portnbr);
	open_url(url.c_str());
}

Fl_Double_Window* create_custom_msgs_dialog()
{
	int W = 260, H = 300;
	Fl_Double_Window* w = new Fl_Double_Window( W, H, _("Custom Templates") );
	w->begin();
		bcustom = new Fl_Hold_Browser(2, 2, w->w() - 4, w->h() - 30, 0);
		bcustom->textfont(FL_HELVETICA);
		bcustom->textsize(14);

		btnCustomCancel = new Fl_Button( 5, w->h() - 26, 80, 24, _("Cancel") );
		btnCustomCancel->tooltip(_("Cancel message creation"));
		btnCustomCancel->callback((Fl_Callback*)cb_custom_cancel);

		btnCustomSelect = new Fl_Button( w->w() - 85, w->h() - 26, 80, 24, _("Select") );
		btnCustomSelect->tooltip(_("Open selected template"));
		btnCustomSelect->callback((Fl_Callback*)cb_custom_select);

		w->resizable(bmsgs);
	w->end();
	return w;
}

//----------------------------------------------------------------------

extern void extract_fields();
extern void exit_main(void *);
extern string cmd_fname;

void cb_ve_combo(Fl_Widget *, void *d)
{
	custom_select = temp_combo->index() - 1;
	if (custom_select < 0) return;
	select_form(selected_form = CUSTOM);
	cb_custom_new();
	update_custom = true;
}

void cb_ve_create(void *)
{
	if (!custom_msg_dialog) custom_msg_dialog = create_custom_msgs_dialog();

	bcustom->clear();

	load_custom_menu();

	for (int i = 0; i < num_custom_entries; i++)
		bcustom->add(custom_pairs[i].mnu_name);

	custom_msg_dialog->resize(
		tyro_dialog->x() + 10 + tyro_dialog->w(), 
		tyro_dialog->y(),
		custom_msg_dialog->w(), custom_msg_dialog->h());

	custom_msg_dialog->show();
}

#include <FL/names.h>

void cb_ve_viewer(void *)
{
	int event = Fl::event();
	if (event == FL_PASTE) {
		cmd_fname = Fl::event_text();
		size_t n;
		if ((n = cmd_fname.find("file:///")) != string::npos)
			cmd_fname.erase(0, n + 7);
		if ((cmd_fname.find(":\\")) != string::npos || (cmd_fname.find("/") == 0)) {
			while ((n = cmd_fname.find('\n')) != string::npos)
				cmd_fname.erase(n, 1);
			while ((n = cmd_fname.find('\r')) != string::npos)
				cmd_fname.erase(n, 1);
			print_and_exit();
		} else
			cmd_fname.clear();
		return;
	}

	string viewer_filename = ICS_msg_dir;

	Fl_Native_File_Chooser native;

	native.filter("All msgs\t*\n");
	native.title(_("Open data file"));
	native.preset_file(viewer_filename.c_str());
	native.type(Fl_Native_File_Chooser::BROWSE_FILE);
	native.options(Fl_Native_File_Chooser::PREVIEW);
	native.directory(ICS_msg_dir.c_str());

	switch ( native.show() ) {
		case -1: // ERROR
			LOG_ERROR("ERROR: %s\n", native.errmsg()); // Error fall through
		case  1: // CANCEL
			break;
		default:
			cmd_fname = viewer_filename = native.filename();
			print_and_exit();
			break;
	}
}

void cb_ve_editor(void *)
{
	int event = Fl::event();
	if (event == FL_PASTE) {
		def_custom_filename = Fl::event_text();

		size_t n;
		if ((n = def_custom_filename.find("file:///")) != string::npos)
			def_custom_filename.erase(0, n + 7);
		if ((def_custom_filename.find(":\\")) != string::npos || (def_custom_filename.find("/") == 0)) {
			while ((n = def_custom_filename.find('\n')) != string::npos)
				def_custom_filename.erase(n, 1);
			while ((n = def_custom_filename.find('\r')) != string::npos)
				def_custom_filename.erase(n, 1);
			if (def_custom_filename.find("k2s") == std::string::npos) {
				fl_alert2("Use expert dialog to edit built-in forms!");
				return;
			}
			clear_custom_form();
			read_data_file(def_custom_filename.c_str());
			using_custom_template = false;
			update_custom = true;
			handle_type = HANDLE_EDIT;
			string url = "http://127.0.0.1:";
			url.append(sz_srvr_portnbr);
			open_url(url.c_str());
		} else
			def_custom_filename.clear();
		return;
	}

	select_form(selected_form = CUSTOM);

	Fl_Native_File_Chooser native;

	native.filter("Custon msgs\t*.k2s\n");
	native.title(_("Open data file"));
	native.preset_file(def_custom_filename.c_str());
	native.type(Fl_Native_File_Chooser::BROWSE_FILE);
	native.options(Fl_Native_File_Chooser::PREVIEW);
	native.directory(ICS_msg_dir.c_str());

	switch ( native.show() ) {
		case -1: // ERROR
			LOG_ERROR("ERROR: %s\n", native.errmsg()); // Error fall through
		case  1: // CANCEL
			break;
		default:
			def_custom_filename =  native.filename();
			if (def_custom_filename.find(".k2s") == std::string::npos) {
				fl_alert2("Not a custom form\nUse Main Dialog for other forms");
				return;
			}
			clear_custom_form();
			read_data_file(def_custom_filename.c_str());
			using_custom_template = false;
			update_custom = true;
			handle_type = HANDLE_EDIT;
			string url = "http://127.0.0.1:";
			url.append(sz_srvr_portnbr);
			open_url(url.c_str());
			break;
	}
}

void cb_ve_Exit(Fl_Widget *, void *d)
{
	cb_exit();
}

void cb_ve_templates(Fl_Widget *, void *d)
{
	string dir = CUSTOM_dir;
	open_url(dir.c_str(), 1);
}

void cb_ve_messages(Fl_Widget *, void *d)
{
	string dir = ICS_msg_dir;
	open_url(dir.c_str(), 1);
}

void cb_close_main_dialog(Fl_Widget *, void *)
{
	expert_dialog->hide();
}

void cb_show_main_dialog(Fl_Widget *, void *d)
{
	const char *szClose = _("Close dialog");
	expert_dialog->resize(
		tyro_dialog->x() + 10 + tyro_dialog->w(), 
		tyro_dialog->y(),
		expert_dialog->w(), expert_dialog->h());
	menu_[19].shortcut_ = 0;
	menu_[19].text = szClose;
	menu_[19].callback_ = (Fl_Callback *)cb_close_main_dialog;
	expert_dialog->show();
}

void cb_mnu_load_custom(void *)
{
	load_custom_menu();
}

/*
struct Fl_Menu_Item {
	const char*		text; // label()
	ulong			shortcut_;
	Fl_Callback*	callback_;
	void*			user_data_;
	int				flags;
	uchar			labeltype_;
	uchar			labelfont_;
	uchar			labelsize_;
	uchar			labelcolor_;
};

enum { // values for flags, OR'd
FL_MENU_INACTIVE 	= 1, // Deactivate menu item (gray out)
FL_MENU_TOGGLE 		= 2, // Item is a checkbox toggle (shows checkbox for on/off state)
FL_MENU_VALUE 		= 4, // The on/off state for checkbox/radio buttons (if set, state is 'on')
FL_MENU_RADIO 		= 8, // Item is a radio button (one checkbox of many can be on)
FL_MENU_INVISIBLE 	= 0x10, // Item will not show up (shortcut will work)
FL_SUBMENU_POINTER 	= 0x20, // Indicates user_data() is a pointer to another menu array
FL_SUBMENU 			= 0x40, // This item is a submenu to other items
FL_MENU_DIVIDER 	= 0x80, // Creates divider line below this item. Also ends a group of radio buttons.
FL_MENU_HORIZONTAL 	= 0x100 // ??? -- reserved
};
*/

Fl_Menu_Item ve_menu_[] = {
 {_("&File"), 0, 0, 0, FL_SUBMENU},
	{_("&Template Folder"), 0, (Fl_Callback*)cb_ve_templates},
	{_("&Messages Folder"), 0, (Fl_Callback*)cb_ve_messages, 0, FL_MENU_DIVIDER},
	{_("E&xit"), 0x40078,  (Fl_Callback*)cb_ve_Exit},
	{0},
 {_("&Tools"), 0, 0, 0, FL_SUBMENU},
	{_("Update templates"), 0, (Fl_Callback*)cb_mnu_load_custom},
	{_("Expert Dialog"), 0, (Fl_Callback*)cb_show_main_dialog},
	{0},
 {0}, 
 {0}
};

Fl_Double_Window* edit_view_dialog()
{
	int W = 300, H = 130;
	Fl_Double_Window *w = new Fl_Double_Window( W, H, _("Flmsg - Simple UI") );
	w->begin();
		ve_menubar = new Fl_Menu_Bar(0, 0, W, 24);

		ve_menubar->menu(ve_menu_);

		ve_create = new Fl_Button(75, 35, 150, 25, _("New Message") );
		ve_create->callback((Fl_Callback*)cb_ve_create);
		ve_create->tooltip(_("Create a new message"));

		ve_editor = new Fl_Drop_Button(75, 65, 150, 25, _("Edit Message") );
		ve_editor->callback((Fl_Callback*)cb_ve_editor);
		ve_editor->tooltip(_("Edit existing message"));

		ve_viewer = new Fl_Drop_Button(75, 95, 150, 25, _("View Message") );
		ve_viewer->callback((Fl_Callback*)cb_ve_viewer);
		ve_viewer->tooltip(_("View existing message"));

	w->end();
	return w;
}
