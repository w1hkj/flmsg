# Copyright (c) 2008 Dave Freese, W1HKJ (w1hkj AT w1hkj DOT com)

bin_PROGRAMS = flmsg

flmsg_CPPFLAGS = @FLMSG_BUILD_CPPFLAGS@
flmsg_CXXFLAGS = @FLMSG_BUILD_CXXFLAGS@
flmsg_CFLAGS = $(flmsg_CXXFLAGS)
flmsg_LDFLAGS = @FLMSG_BUILD_LDFLAGS@
flmsg_LDADD = @FLMSG_BUILD_LDADD@

MINGW32_SRC = \
	flmsg-rc.rc \
	include/flmsgrc.h

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

FL_SRC = flmsg_dialog.fl

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
	$(srcdir)/arl_msgs.cxx \
	$(srcdir)/calendar.cxx \
	$(srcdir)/combo.cxx \
	$(srcdir)/base64.cxx \
	$(srcdir)/date.cxx \
	$(srcdir)/debug.cxx \
	$(srcdir)/fileselect.cxx \
	$(srcdir)/flinput2.cxx \
	$(srcdir)/flmsg.cxx \
	$(srcdir)/hx_msgs.cxx \
	$(srcdir)/icons.cxx \
	$(srcdir)/ics213.cxx \
	$(srcdir)/templates.cxx \
	$(srcdir)/flmsg_dialog.cxx \
	$(srcdir)/parse_xml.cxx \
	$(srcdir)/pixmaps.cxx \
	$(srcdir)/radiogram.cxx \
	$(srcdir)/status.cxx \
	$(srcdir)/util.cxx \
	$(srcdir)/wrap.cxx \
	$(srcdir)/Fl_Text_Editor_mod.cxx \
	$(srcdir)/Fl_Text_Display_mod.cxx \
	$(srcdir)/Fl_Native_File_Chooser.cxx \
	$(srcdir)/FTextView.cxx \
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
	$(srcdir)/lzma/Types.h

# Additional source files that are distributed
EXTRA_DIST = \
	$(srcdir)/config.h \
	$(srcdir)/flnfc_common.cxx \
	$(srcdir)/Fl_Native_File_Chooser_FLTK.cxx \
	$(srcdir)/Fl_Native_File_Chooser_MAC.cxx \
	$(srcdir)/Fl_Native_File_Chooser_WIN32.cxx \
	$(srcdir)/mingw.c \
	$(srcdir)/include/arl_msgs.h \
	$(srcdir)/include/base64.h \
	$(srcdir)/include/calendar.h \
	$(srcdir)/include/combo.h \
	$(srcdir)/include/compat.h \
	$(srcdir)/include/compat-mingw.h \
	$(srcdir)/include/crc16.h \
	$(srcdir)/include/date.h \
	$(srcdir)/include/debug.h \
	$(srcdir)/include/fileselect.h \
	$(srcdir)/include/flmsg_config.h \
	$(srcdir)/include/flmsgrc.h \
	$(srcdir)/include/flinput2.h \
	$(srcdir)/include/gettext.h \
	$(srcdir)/include/hx_msgs.h \
	$(srcdir)/include/icons.h \
	$(srcdir)/include/ics213.h \
	$(srcdir)/include/flmsg_dialog.h \
	$(srcdir)/include/templates.h \
	$(srcdir)/include/mingw.h \
	$(srcdir)/include/parse_xml.h \
	$(srcdir)/include/pixmaps.h \
	$(srcdir)/include/status.h \
	$(srcdir)/include/util.h \
	$(srcdir)/include/wrap.h \
	$(srcdir)/include/Fl_Text_Display_mod.H \
	$(srcdir)/include/Fl_Text_Editor_mod.H \
	$(srcdir)/include/FTextView.h \
	$(srcdir)/include/FL/Fl_Native_File_Chooser_FLTK.H \
	$(srcdir)/include/FL/Fl_Native_File_Chooser_MAC.H \
	$(srcdir)/include/FL/Fl_Native_File_Chooser.H \
	$(srcdir)/include/FL/Fl_Native_File_Chooser_WIN32.H

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
	$(srcdir)/../flmsg-doc/template-menu.png

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
