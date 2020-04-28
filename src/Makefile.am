# Copyright (c) 2008 Dave Freese, W1HKJ (w1hkj AT w1hkj DOT com)

bin_PROGRAMS = flmsg

MINGW32_SRC = flmsg-rc.rc include/flmsgrc.h \
	utils/mingw.c include/mingw.h include/compat.h \
	utils/getsysinfo.c

# Build the xmlrpcpp source if libflxmlrpc is not found
XMLRPCPP_SRC = \
	xmlrpcpp/XmlRpcBase64.h \
	xmlrpcpp/XmlRpcClient.cpp \
	xmlrpcpp/XmlRpcClient.h \
	xmlrpcpp/XmlRpcDispatch.cpp \
	xmlrpcpp/XmlRpcDispatch.h \
	xmlrpcpp/XmlRpcException.h \
	xmlrpcpp/XmlRpc.h \
	xmlrpcpp/XmlRpcMutex.cpp \
	xmlrpcpp/XmlRpcMutex.h \
	xmlrpcpp/XmlRpcServerConnection.cpp \
	xmlrpcpp/XmlRpcServerConnection.h \
	xmlrpcpp/XmlRpcServer.cpp \
	xmlrpcpp/XmlRpcServer.h \
	xmlrpcpp/XmlRpcServerMethod.cpp \
	xmlrpcpp/XmlRpcServerMethod.h \
	xmlrpcpp/XmlRpcSocket.cpp \
	xmlrpcpp/XmlRpcSocket.h \
	xmlrpcpp/XmlRpcSource.cpp \
	xmlrpcpp/XmlRpcSource.h \
	xmlrpcpp/XmlRpcUtil.cpp \
	xmlrpcpp/XmlRpcUtil.h \
	xmlrpcpp/XmlRpcValue.cpp \
	xmlrpcpp/XmlRpcValue.h

# We distribute these but do not always compile them
EXTRA_flmsg_SOURCES = $(FLMSG_WIN32_RES_SRC) $(MINGW32_SRC) $(XMLRPCPP_SRC)

flmsg_SOURCES =

if !ENABLE_FLXMLRPC
flmsg_SOURCES += $(XMLRPCPP_SRC)
flmsg_CPPFLAGS = @FLMSG_BUILD_CPPFLAGS@
flmsg_CXXFLAGS = @FLMSG_BUILD_CXXFLAGS@
flmsg_CFLAGS = $(flmsg_CXXFLAGS)
flmsg_LDFLAGS = @FLMSG_BUILD_LDFLAGS@
flmsg_LDADD = @FLMSG_BUILD_LDADD@
else
flmsg_CPPFLAGS = @FLMSG_BUILD_CPPFLAGS@ @FLXMLRPC_CFLAGS@
flmsg_CXXFLAGS = @FLMSG_BUILD_CXXFLAGS@ @FLXMLRPC_CFLAGS@
flmsg_CFLAGS = $(flmsg_CXXFLAGS)
flmsg_LDFLAGS = @FLMSG_BUILD_LDFLAGS@ @FLXMLRPC_LIBS@
flmsg_LDADD = @FLMSG_BUILD_LDADD@
endif

if MINGW32
if HAVE_WINDRES
  flmsg_SOURCES += $(MINGW32_SRC)
endif
endif

########################################################################


flmsg_VERSION_MAJOR = @FLMSG_VERSION_MAJOR@
flmsg_VERSION_MINOR = @FLMSG_VERSION_MINOR@
flmsg_VERSION_PATCH = @FLMSG_VERSION_PATCH@
flmsg_VERSION = @FLMSG_VERSION@

.EXPORT_ALL_VARIABLES: nsisinst appbundle

# Sources that are generated,
BUILT_SOURCES =
# not distributed,
nodist_flmsg_SOURCES = $(BUILT_SOURCES)
# and deleted by the clean targets
CLEANFILES = $(BUILT_SOURCES)
CLEAN_LOCAL =

if MINGW32
if HAVE_WINDRES
.rc.o:
	$(WINDRES) -Iinclude -I../data/win32 $< -O coff $@
endif
endif

install-data-local:
	if test -f ../data/flmsg.xpm; then \
	    $(mkinstalldirs) $(DESTDIR)/$(datadir)/pixmaps; \
	    $(INSTALL_DATA) ../data/flmsg.xpm $(DESTDIR)/$(datadir)/pixmaps; \
	fi
	if test -f ../data/flmsg.desktop; then \
	    $(mkinstalldirs) $(DESTDIR)/$(datadir)/applications; \
	    $(INSTALL_DATA) ../data/flmsg.desktop $(DESTDIR)/$(datadir)/applications; \
	fi

uninstall-local:
	rm -f $(DESTDIR)/$(datadir)/pixmaps/flmsg.xpm
	rm -f $(DESTDIR)/$(datadir)/applications/flmsg.desktop

# FL_SRC = flmsg_dialog.fl

if HAVE_FLUID
flgen: $(FL_SRC)
	(cd include; \
	for f in $(FL_SRC); do \
	    c=$${f%.fl}.cxx; \
		h=$${f%.fl}.h; \
		h=$${h##*/}; \
	    $(FLUID) -c -o ../$$c -h $$h ../$$f; \
	done)
endif


INSTALLER_FILE = flmsg-$(FLMSG_VERSION)_setup.exe
APPBUNDLE=flmsg-$(FLMSG_VERSION)
APPBUNDLE_NOLIBS=$(APPBUNDLE)-nolibs

if HAVE_NSIS
nsisinst: $(bin_PROGRAMS)
	sh ../scripts/mknsisinst.sh "../data" .
    CLEANFILES += $(INSTALLER_FILE)
endif

if DARWIN
appbundle: $(bin_PROGRAMS)
	sh ../scripts/mkappbundle.sh "../data" .
    CLEAN_LOCAL += $(APPBUNDLE_NOLIBS) $(APPBUNDLE) $(APPBUNDLE)*.dmg
endif

clean-local:
	-rm -rf $(CLEAN_LOCAL)

# Sources that we build. It is OK to have headers here.

flmsg_SOURCES += \
	arq/arq.cxx \
	arq/flmsg-arq.cxx \
	blank-dnd/baddata_templates.cxx \
	blank-dnd/blank.cxx \
	blank-dnd/blank_tab.cxx \
	blank-dnd/blank_templates.cxx \
	blank-dnd/dnd_tab.cxx \
	cap/cap105.cxx \
	cap/cap105_tab.cxx \
	cap/cap110.cxx \
	cap/cap110_tab.cxx \
	cap/cap_templates.cxx \
	csv/csv.cxx \
	csv/csv_tab.cxx \
	csv/csv_templates.cxx \
	csv/csv_table.cxx \
	custom/custom.cxx \
	custom/custom_tab.cxx \
	custom/custom_templates.cxx \
	include/custom.h \
	flmsg.cxx \
	flmsg_dialog.cxx \
	ham_forms/ham_forms_tab.cxx \
	ham_forms/netlog.cxx \
	ham_forms/netlog_templates.cxx \
	ham_forms/netlog_tab.cxx \
	iaru/iaru.cxx \
	iaru/iaru_tab.cxx \
	iaru/iaru_templates.cxx \
	ics/ics203.cxx \
	ics/ics205.cxx \
	ics/ics205a.cxx \
	ics/ics206.cxx \
	ics/ics213.cxx \
	ics/ics214.cxx \
	ics/ics216.cxx \
	ics/ics309.cxx \
	ics/ics_tab.cxx \
	ics/ics203_tab.cxx \
	ics/ics205_tab.cxx \
	ics/ics205a_tab.cxx \
	ics/ics206_tab.cxx \
	ics/ics213_tab.cxx \
	ics/ics214_tab.cxx \
	ics/ics216_tab.cxx \
	ics/ics309_tab.cxx \
	ics/ics203_templates.cxx \
	ics/ics205_templates.cxx \
	ics/ics205a_templates.cxx \
	ics/ics206_templates.cxx \
	ics/ics213_templates.cxx \
	ics/ics214_templates.cxx \
	ics/ics216_templates.cxx \
	ics/ics309_templates.cxx \
	hics/hics_tab.cxx \
	hics/hics203.cxx \
	hics/hics203_tab.cxx \
	hics/hics203_templates.cxx\
	hics/hics206.cxx \
	hics/hics206_tab.cxx \
	hics/hics206_templates.cxx\
	hics/hics213.cxx \
	hics/hics213_tab.cxx \
	hics/hics213_templates.cxx\
	hics/hics214.cxx \
	hics/hics214_tab.cxx \
	hics/hics214_templates.cxx\
	lzma/Alloc.h \
	lzma/Alloc.c \
	lzma/LzFind.c \
	lzma/LzFind.h \
	lzma/LzHash.h \
	lzma/LzmaDec.c \
	lzma/LzmaDec.h \
	lzma/LzmaEnc.c \
	lzma/LzmaEnc.h \
	lzma/LzmaLib.c \
	lzma/LzmaLib.h \
	lzma/Types.h \
	mars/mars_tab.cxx \
	mars/mars_daily.cxx \
	mars/mars_ineei.cxx \
	mars/mars_net.cxx \
	mars/mars_daily_tab.cxx \
	mars/mars_ineei_tab.cxx \
	mars/mars_net_tab.cxx \
	mars/mars_army.cxx \
	mars/mars_army_tab.cxx \
	mars/mars_templates.cxx \
	plaintext/plaintext.cxx \
	plaintext/plaintext_tab.cxx \
	plaintext/plaintext_templates.cxx \
	radiogram/arl_msgs.cxx \
	radiogram/hx_msgs.cxx \
	radiogram/radiogram.cxx \
	radiogram/radiogram_tab.cxx \
	radiogram/radiogram_templates.cxx \
	transfer/transfer.cxx \
	transfer/transfer_tab.cxx \
	custom/custom_transfer_tab.cxx \
	utils/base64.cxx \
	utils/base128.cxx \
	utils/base256.cxx \
	utils/debug.cxx \
	utils/ext_string.cxx \
	utils/mongoose.c \
	utils/parse_xml.cxx \
	utils/socket.cxx \
	utils/status.cxx \
	utils/timeops.cxx \
	utils/time_table.cxx \
	utils/threads.cxx \
	utils/util.cxx \
	utils/wrap.cxx \
	utils/xml_io.cxx \
	widgets/calendar.cxx \
	widgets/combo.cxx \
	widgets/date.cxx \
	widgets/drop_button.cxx \
	widgets/fileselect.cxx \
	widgets/flinput2.cxx \
	widgets/flmisc.cxx \
	widgets/flslider2.cxx \
	widgets/Fl_Text_Buffer_mod.cxx \
	widgets/Fl_Text_Editor_mod.cxx \
	widgets/Fl_Text_Display_mod.cxx \
	widgets/FTextView.cxx \
	widgets/icons.cxx \
	widgets/pixmaps.cxx \
	widgets/pixmaps_tango.cxx \
	widgets/font_browser.cxx \
	wx/hurricane.cxx \
	wx/hurricane_tab.cxx \
	wx/hurricane_template.cxx \
	wx/severe_wx.cxx \
	wx/severe_wx_tab.cxx \
	wx/severe_wx_template.cxx \
	wx/wx_strings.cxx \
	wx/storm_report.cxx \
	wx/storm_report_tab.cxx \
	wx/storm_report_template.cxx

#	wx/storm_report.cxx 
#	wx/storm_report_template.cxx 

EXTRA_DIST =

# Additional source files that are distributed
EXTRA_DIST += \
	config.h \
	utils/mingw.c \
	utils/time_table_dat.cxx \
	widgets/flnfc_common.cxx \
	include/arl_msgs.h \
	include/arq.h \
	include/flmsg_arq.h \
	include/ascii.h \
	include/base64.h \
	include/base128.h \
	include/base256.h \
	include/calendar.h \
	include/cap.h \
	include/combo.h \
	include/compat.h \
	include/compat-mingw.h \
	include/crc16.h \
	include/date.h \
	include/debug.h \
	include/dirent-check.h \
	include/drop_button.h \
	include/ext_string.h \
	include/fileselect.h \
	include/fl_lock.h \
	include/flmisc.h \
	include/flmsg_config.h \
	include/flmsgrc.h \
	include/flinput2.h \
	include/flslider2.h \
	include/font_browser.h \
	include/gettext.h \
	include/hx_msgs.h \
	include/iaru.h \
	include/icons.h \
	include/flmsg.h \
	include/flmsg_dialog.h \
	include/mongoose.h \
	include/socket.h \
	include/templates.h \
	include/mingw.h \
	include/parse_xml.h \
	include/pixmaps.h \
	include/stacktrace.h \
	include/status.h \
	include/flmsg_strings.h \
	include/threads.h \
	include/timeops.h \
	include/time_table.h \
	include/transfer.h \
	include/util.h \
	include/wrap.h \
	include/wx_strings.h \
	include/xml_io.h \
	widgets/missing_strings.c \
	widgets/Fl_Text_Buffer_mod_1_1.cxx \
	widgets/Fl_Text_Buffer_mod_1_3.cxx \
	widgets/Fl_Text_Display_mod_1_1.cxx \
	widgets/Fl_Text_Display_mod_1_3.cxx \
	widgets/Fl_Text_Editor_mod_1_1.cxx \
	widgets/Fl_Text_Editor_mod_1_3.cxx \
	include/Fl_Text_Buffer_mod.H \
	include/Fl_Text_Buffer_mod_1_1.H \
	include/Fl_Text_Buffer_mod_1_3.H \
	include/Fl_Text_Display_mod.H \
	include/Fl_Text_Display_mod_1_1.H \
	include/Fl_Text_Display_mod_1_3.H \
	include/Fl_Text_Editor_mod.H \
	include/Fl_Text_Editor_mod_1_1.H \
	include/Fl_Text_Editor_mod_1_3.H \
	include/FTextView.h \
	include/blank.h \
	include/csv.h \
	include/missing_strings.h \
	include/plaintext.h \
	include/radiogram.h \
	flmsg_dialog.cxx

# Additional non-source files that are distributed
EXTRA_DIST += \
	../data/template.rtf \
	html_templates/blank_template.html \
	html_templates/ics203_template.html \
	html_templates/ics205_template.html \
	html_templates/ics205a_template.html \
	html_templates/ics206_template.html \
	html_templates/ics213_templates.html \
	html_templates/ics214_templates.html \
	html_templates/ics216_templates.html \
	html_templates/plaintext_template.html \
	html_templates/radiogram_fc_template.html \
	html_templates/radiogram_template.html \
	html_templates/mars_daily.html \
	html_templates/mars_ineei.html \
	html_templates/mars_net.html


# Additional source files that support non-Linux cross compilation
EXTRA_DIST += \
	../data/flmsg.desktop \
	../data/flmsg.xpm \
	../data/win32/fl_app.nsi \
	../data/win32/flmsg.ico \
	../scripts/buildmxe.sh \
	../scripts/builddist.sh \
	../scripts/mkappbundle.sh \
	../scripts/mknsisinst.sh \
	../data/mac/Info.plist.in \
	../data/mac/flmsg.icns \
	$(FLMSG_WIN32_SRC) \
	$(FLMSG_FL_SRC)
