# Copyright (c) 2008 Dave Freese, W1HKJ (w1hkj AT w1hkj DOT com)

bin_PROGRAMS = flmsg

flmsg_CPPFLAGS = @FLMSG_BUILD_CPPFLAGS@
flmsg_CXXFLAGS = @FLMSG_BUILD_CXXFLAGS@
flmsg_CFLAGS = $(flmsg_CXXFLAGS)
flmsg_LDFLAGS = @FLMSG_BUILD_LDFLAGS@
flmsg_LDADD = @FLMSG_BUILD_LDADD@

MINGW32_SRC = flmsg-rc.rc include/flmsgrc.h \
	utils/mingw.c include/mingw.h include/compat.h \
	utils/getsysinfo.c

# We distribute these but do not always compile them
EXTRA_flmsg_SOURCES = $(FLMSG_WIN32_RES_SRC) $(MINGW32_SRC)

flmsg_SOURCES =

if MINGW32
if HAVE_WINDRES
  flmsg_SOURCES += $(MINGW32_SRC)
endif
endif

########################################################################


FLMSG_VERSION_MAJOR = @FLMSG_VERSION_MAJOR@
FLMSG_VERSION_MINOR = @FLMSG_VERSION_MINOR@
FLMSG_VERSION_PATCH = @FLMSG_VERSION_PATCH@
FLMSG_VERSION = @FLMSG_VERSION@

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
	$(WINDRES) -I$(srcdir)/include -I$(srcdir)/../data/win32 $< -O coff $@
endif
endif

install-data-local:
	if test -f $(srcdir)/../data/flmsg.xpm; then \
	    $(mkinstalldirs) $(DESTDIR)/$(datadir)/pixmaps; \
	    $(INSTALL_DATA) $(srcdir)/../data/flmsg.xpm $(DESTDIR)/$(datadir)/pixmaps; \
	fi
	if test -f $(srcdir)/../data/flmsg.desktop; then \
	    $(mkinstalldirs) $(DESTDIR)/$(datadir)/applications; \
	    $(INSTALL_DATA) $(srcdir)/../data/flmsg.desktop $(DESTDIR)/$(datadir)/applications; \
	fi

uninstall-local:
	rm -f $(DESTDIR)/$(datadir)/pixmaps/flmsg.xpm
	rm -f $(DESTDIR)/$(datadir)/applications/flmsg.desktop

# FL_SRC = flmsg_dialog.fl

if HAVE_FLUID
flgen: $(FL_SRC)
	(cd $(srcdir)/include; \
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
	sh $(srcdir)/../scripts/mknsisinst.sh "$(srcdir)/../data" .
    CLEANFILES += $(INSTALLER_FILE)
endif

if DARWIN
appbundle: $(bin_PROGRAMS)
	sh $(srcdir)/../scripts/mkappbundle.sh "$(srcdir)/../data" .
    CLEAN_LOCAL += $(APPBUNDLE_NOLIBS) $(APPBUNDLE) $(APPBUNDLE)*.dmg
endif

clean-local:
	-rm -rf $(CLEAN_LOCAL)

# Sources that we build. It is OK to have headers here.
flmsg_SOURCES += \
	$(srcdir)/blank-dnd/baddata_templates.cxx \
	$(srcdir)/blank-dnd/blank.cxx \
	$(srcdir)/blank-dnd/blank_tab.cxx \
	$(srcdir)/blank-dnd/blank_templates.cxx \
	$(srcdir)/blank-dnd/dnd_tab.cxx \
	$(srcdir)/csv/csv.cxx \
	$(srcdir)/csv/csv_tab.cxx \
	$(srcdir)/csv/csv_templates.cxx \
	$(srcdir)/csv/csv_table.cxx \
	$(srcdir)/flmsg.cxx \
	$(srcdir)/flmsg_dialog.cxx \
	$(srcdir)/iaru/iaru.cxx \
	$(srcdir)/iaru/iaru_tab.cxx \
	$(srcdir)/iaru/iaru_templates.cxx \
	$(srcdir)/ics/ics203.cxx \
	$(srcdir)/ics/ics205.cxx \
	$(srcdir)/ics/ics205a.cxx \
	$(srcdir)/ics/ics206.cxx \
	$(srcdir)/ics/ics213.cxx \
	$(srcdir)/ics/ics214.cxx \
	$(srcdir)/ics/ics216.cxx \
	$(srcdir)/ics/ics309.cxx \
	$(srcdir)/ics/ics_tab.cxx \
	$(srcdir)/ics/ics203_tab.cxx \
	$(srcdir)/ics/ics205_tab.cxx \
	$(srcdir)/ics/ics205a_tab.cxx \
	$(srcdir)/ics/ics206_tab.cxx \
	$(srcdir)/ics/ics213_tab.cxx \
	$(srcdir)/ics/ics214_tab.cxx \
	$(srcdir)/ics/ics216_tab.cxx \
	$(srcdir)/ics/ics309_tab.cxx \
	$(srcdir)/ics/ics203_templates.cxx \
	$(srcdir)/ics/ics205_templates.cxx \
	$(srcdir)/ics/ics205a_templates.cxx \
	$(srcdir)/ics/ics206_templates.cxx \
	$(srcdir)/ics/ics213_templates.cxx \
	$(srcdir)/ics/ics214_templates.cxx \
	$(srcdir)/ics/ics216_templates.cxx \
	$(srcdir)/ics/ics309_templates.cxx \
	$(srcdir)/hics/hics_tab.cxx \
	$(srcdir)/hics/hics203.cxx \
	$(srcdir)/hics/hics203_tab.cxx \
	$(srcdir)/hics/hics203_templates.cxx\
	$(srcdir)/hics/hics206.cxx \
	$(srcdir)/hics/hics206_tab.cxx \
	$(srcdir)/hics/hics206_templates.cxx\
	$(srcdir)/hics/hics213.cxx \
	$(srcdir)/hics/hics213_tab.cxx \
	$(srcdir)/hics/hics213_templates.cxx\
	$(srcdir)/hics/hics214.cxx \
	$(srcdir)/hics/hics214_tab.cxx \
	$(srcdir)/hics/hics214_templates.cxx\
	$(srcdir)/lzma/Alloc.h \
	$(srcdir)/lzma/Alloc.c \
	$(srcdir)/lzma/LzFind.c \
	$(srcdir)/lzma/LzFind.h \
	$(srcdir)/lzma/LzHash.h \
	$(srcdir)/lzma/LzmaDec.c \
	$(srcdir)/lzma/LzmaDec.h \
	$(srcdir)/lzma/LzmaEnc.c \
	$(srcdir)/lzma/LzmaEnc.h \
	$(srcdir)/lzma/LzmaLib.c \
	$(srcdir)/lzma/LzmaLib.h \
	$(srcdir)/lzma/Types.h \
	$(srcdir)/mars/mars_tab.cxx \
	$(srcdir)/mars/mars_daily.cxx \
	$(srcdir)/mars/mars_ineei.cxx \
	$(srcdir)/mars/mars_net.cxx \
	$(srcdir)/mars/mars_daily_tab.cxx \
	$(srcdir)/mars/mars_ineei_tab.cxx \
	$(srcdir)/mars/mars_net_tab.cxx \
	$(srcdir)/mars/mars_army.cxx \
	$(srcdir)/mars/mars_army_tab.cxx \
	$(srcdir)/mars/mars_navy.cxx \
	$(srcdir)/mars/navy_mars_tab.cxx \
	$(srcdir)/mars/mars_templates.cxx \
	$(srcdir)/nhc/hurricane.cxx \
	$(srcdir)/nhc/hurricane_tab.cxx \
	$(srcdir)/nhc/hurricane_template.cxx \
	$(srcdir)/plaintext/plaintext.cxx \
	$(srcdir)/plaintext/plaintext_tab.cxx \
	$(srcdir)/plaintext/plaintext_templates.cxx \
	$(srcdir)/radiogram/arl_msgs.cxx \
	$(srcdir)/radiogram/hx_msgs.cxx \
	$(srcdir)/radiogram/radiogram.cxx \
	$(srcdir)/radiogram/radiogram_tab.cxx \
	$(srcdir)/radiogram/radiogram_templates.cxx \
	$(srcdir)/redx/redx_tab.cxx \
	$(srcdir)/redx/redx_snw.cxx \
	$(srcdir)/redx/redx_snw_tab.cxx \
	$(srcdir)/redx/redx_snw_template.cxx \
	$(srcdir)/redx/redx_5739.cxx \
	$(srcdir)/redx/redx_5739_tab.cxx \
	$(srcdir)/redx/redx_5739A.cxx \
	$(srcdir)/redx/redx_5739A_tab.cxx \
	$(srcdir)/redx/redx_5739B.cxx \
	$(srcdir)/redx/redx_5739B_tab.cxx \
	$(srcdir)/redx/redx_5739_template.cxx \
	$(srcdir)/transfer/transfer.cxx \
	$(srcdir)/transfer/transfer_tab.cxx \
	$(srcdir)/utils/base64.cxx \
	$(srcdir)/utils/base128.cxx \
	$(srcdir)/utils/base256.cxx \
	$(srcdir)/utils/debug.cxx \
	$(srcdir)/utils/parse_xml.cxx \
	$(srcdir)/utils/socket.cxx \
	$(srcdir)/utils/status.cxx \
	$(srcdir)/utils/timeops.cxx \
	$(srcdir)/utils/util.cxx \
	$(srcdir)/utils/wrap.cxx \
	$(srcdir)/utils/xml_io.cxx \
	$(srcdir)/widgets/calendar.cxx \
	$(srcdir)/widgets/combo.cxx \
	$(srcdir)/widgets/date.cxx \
	$(srcdir)/widgets/fileselect.cxx \
	$(srcdir)/widgets/flinput2.cxx \
	$(srcdir)/widgets/flslider2.cxx \
	$(srcdir)/widgets/Fl_Text_Buffer_mod.cxx \
	$(srcdir)/widgets/Fl_Text_Editor_mod.cxx \
	$(srcdir)/widgets/Fl_Text_Display_mod.cxx \
	$(srcdir)/widgets/Fl_Native_File_Chooser.cxx \
	$(srcdir)/widgets/FTextView.cxx \
	$(srcdir)/widgets/icons.cxx \
	$(srcdir)/widgets/pixmaps.cxx \
	$(srcdir)/widgets/pixmaps_tango.cxx \
	$(srcdir)/widgets/font_browser.cxx \
	$(srcdir)/xmlrpcpp/XmlRpc.h \
	$(srcdir)/xmlrpcpp/XmlRpcClient.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcClient.h \
	$(srcdir)/xmlrpcpp/XmlRpcDispatch.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcDispatch.h \
	$(srcdir)/xmlrpcpp/XmlRpcException.h \
	$(srcdir)/xmlrpcpp/XmlRpcMutex.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcMutex.h \
	$(srcdir)/xmlrpcpp/XmlRpcServer.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcServer.h \
	$(srcdir)/xmlrpcpp/XmlRpcServerConnection.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcServerConnection.h \
	$(srcdir)/xmlrpcpp/XmlRpcServerMethod.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcServerMethod.h \
	$(srcdir)/xmlrpcpp/XmlRpcSocket.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcSocket.h \
	$(srcdir)/xmlrpcpp/XmlRpcSource.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcSource.h \
	$(srcdir)/xmlrpcpp/XmlRpcThread.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcThread.h \
	$(srcdir)/xmlrpcpp/XmlRpcThreadedServer.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcThreadedServer.h \
	$(srcdir)/xmlrpcpp/XmlRpcUtil.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcUtil.h \
	$(srcdir)/xmlrpcpp/XmlRpcValue.cpp \
	$(srcdir)/xmlrpcpp/XmlRpcValue.h \
	$(srcdir)/xmlrpcpp/base64.h

# Additional source files that are distributed
EXTRA_DIST = \
	$(srcdir)/config.h \
	$(srcdir)/utils/mingw.c \
	$(srcdir)/widgets/flnfc_common.cxx \
	$(srcdir)/widgets/Fl_Native_File_Chooser_FLTK.cxx \
	$(srcdir)/widgets/Fl_Native_File_Chooser_MAC.cxx \
	$(srcdir)/widgets/Fl_Native_File_Chooser_WIN32.cxx \
	$(srcdir)/include/arl_msgs.h \
	$(srcdir)/include/ascii.h \
	$(srcdir)/include/base64.h \
	$(srcdir)/include/base128.h \
	$(srcdir)/include/base256.h \
	$(srcdir)/include/calendar.h \
	$(srcdir)/include/combo.h \
	$(srcdir)/include/compat.h \
	$(srcdir)/include/compat-mingw.h \
	$(srcdir)/include/crc16.h \
	$(srcdir)/include/date.h \
	$(srcdir)/include/debug.h \
	$(srcdir)/include/dirent-check.h \
	$(srcdir)/include/fileselect.h \
	$(srcdir)/include/fl_lock.h \
	$(srcdir)/include/flmisc.h \
	$(srcdir)/include/flmsg_config.h \
	$(srcdir)/include/flmsgrc.h \
	$(srcdir)/include/flinput2.h \
	$(srcdir)/include/flslider2.h \
	$(srcdir)/include/font_browser.h \
	$(srcdir)/include/gettext.h \
	$(srcdir)/include/hx_msgs.h \
	$(srcdir)/include/iaru.h \
	$(srcdir)/include/icons.h \
	$(srcdir)/include/flmsg.h \
	$(srcdir)/include/flmsg_dialog.h \
	$(srcdir)/include/socket.h \
	$(srcdir)/include/templates.h \
	$(srcdir)/include/mingw.h \
	$(srcdir)/include/parse_xml.h \
	$(srcdir)/include/pixmaps.h \
	$(srcdir)/include/status.h \
	$(srcdir)/include/threads.h \
	$(srcdir)/include/timeops.h \
	$(srcdir)/include/transfer.h \
	$(srcdir)/include/util.h \
	$(srcdir)/include/wrap.h \
	$(srcdir)/include/xml_io.h \
	$(srcdir)/widgets/missing_strings.c \
	$(srcdir)/widgets/Fl_Text_Buffer_mod_1_1.cxx \
	$(srcdir)/widgets/Fl_Text_Buffer_mod_1_3.cxx \
	$(srcdir)/widgets/Fl_Text_Display_mod_1_1.cxx \
	$(srcdir)/widgets/Fl_Text_Display_mod_1_3.cxx \
	$(srcdir)/widgets/Fl_Text_Editor_mod_1_1.cxx \
	$(srcdir)/widgets/Fl_Text_Editor_mod_1_3.cxx \
	$(srcdir)/include/Fl_Text_Buffer_mod.H \
	$(srcdir)/include/Fl_Text_Buffer_mod_1_1.H \
	$(srcdir)/include/Fl_Text_Buffer_mod_1_3.H \
	$(srcdir)/include/Fl_Text_Display_mod.H \
	$(srcdir)/include/Fl_Text_Display_mod_1_1.H \
	$(srcdir)/include/Fl_Text_Display_mod_1_3.H \
	$(srcdir)/include/Fl_Text_Editor_mod.H \
	$(srcdir)/include/Fl_Text_Editor_mod_1_1.H \
	$(srcdir)/include/Fl_Text_Editor_mod_1_3.H \
	$(srcdir)/include/FTextView.h \
	$(srcdir)/include/FL/Fl_Native_File_Chooser_FLTK.H \
	$(srcdir)/include/FL/Fl_Native_File_Chooser_MAC.H \
	$(srcdir)/include/FL/Fl_Native_File_Chooser.H \
	$(srcdir)/include/FL/Fl_Native_File_Chooser_WIN32.H \
	$(srcdir)/include/blank.h \
	$(srcdir)/include/csv.h \
	$(srcdir)/include/missing_strings.h \
	$(srcdir)/include/plaintext.h \
	$(srcdir)/include/radiogram.h \
	$(srcdir)/flmsg_dialog.cxx

# Additional non-source files that are distributed
EXTRA_DIST += \
	$(srcdir)/../data/template.rtf \
	$(srcdir)/../flmsg-doc/flmsg-quick-guide.html \
	$(srcdir)/../flmsg-doc/ics213_doc.html \
	$(srcdir)/../flmsg-doc/radiogram.html \
	$(srcdir)/../flmsg-doc/ics213.txt \
	$(srcdir)/../flmsg-doc/radiogram.txt \
	$(srcdir)/../flmsg-doc/arl-selector.png \
	$(srcdir)/../flmsg-doc/file-menu2.png \
	$(srcdir)/../flmsg-doc/flmsg-ics213-b.png \
	$(srcdir)/../flmsg-doc/flmsg-ss1.png \
	$(srcdir)/../flmsg-doc/config-dialog.png \
	$(srcdir)/../flmsg-doc/file-menu3.png \
	$(srcdir)/../flmsg-doc/flmsg-ics213.png \
	$(srcdir)/../flmsg-doc/flmsg-rgm-b.png \
	$(srcdir)/../flmsg-doc/file-menu1.png \
	$(srcdir)/../flmsg-doc/file-menu4.png \
	$(srcdir)/../flmsg-doc/flmsg-menus.png \
	$(srcdir)/../flmsg-doc/flmsg-rgm.png \
	$(srcdir)/../flmsg-doc/template-menu.png \
	$(srcdir)/html_templates/blank_template.html \
	$(srcdir)/html_templates/ics203_template.html \
	$(srcdir)/html_templates/ics205_template.html \
	$(srcdir)/html_templates/ics205a_template.html \
	$(srcdir)/html_templates/ics206_template.html \
	$(srcdir)/html_templates/ics213_templates.html \
	$(srcdir)/html_templates/ics214_templates.html \
	$(srcdir)/html_templates/ics216_templates.html \
	$(srcdir)/html_templates/plaintext_template.html \
	$(srcdir)/html_templates/radiogram_fc_template.html \
	$(srcdir)/html_templates/radiogram_template.html \
	$(srcdir)/html_templates/mars_daily.html \
	$(srcdir)/html_templates/mars_ineei.html \
	$(srcdir)/html_templates/mars_net.html


# Additional source files that support non-Linux cross compilation
EXTRA_DIST += \
	$(srcdir)/../data/flmsg.desktop \
	$(srcdir)/../data/flmsg.xpm \
	$(srcdir)/../data/win32/fl_app.nsi \
	$(srcdir)/../data/win32/flmsg.ico \
	$(srcdir)/../scripts/build4mingw.sh \
	$(srcdir)/../scripts/builddist.sh \
	$(srcdir)/../scripts/mkappbundle.sh \
	$(srcdir)/../scripts/mknsisinst.sh \
	$(srcdir)/../data/mac/Info.plist.in \
	$(srcdir)/../data/mac/flmsg.icns \
	$(FLMSG_WIN32_SRC) \
	$(FLMSG_FL_SRC)
