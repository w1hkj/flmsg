# Copyright (c) 2008 Dave Freese, W1HKJ (w1hkj AT w1hkj DOT com)

bin_PROGRAMS = flics

flics_CPPFLAGS = @FLICS_BUILD_CPPFLAGS@
flics_CXXFLAGS = @FLICS_BUILD_CXXFLAGS@
flics_CFLAGS = $(flics_CXXFLAGS)
flics_LDFLAGS = @FLICS_BUILD_LDFLAGS@
flics_LDADD = @FLICS_BUILD_LDADD@

MINGW32_SRC = \
	flics-rc.rc \
	include/flicsrc.h

# We distribute these but do not always compile them
EXTRA_flics_SOURCES = $(FLICS_WIN32_RES_SRC) $(MINGW32_SRC)

flics_SOURCES =

if MINGW32
if HAVE_WINDRES
  flics_SOURCES += $(MINGW32_SRC)
endif
endif

########################################################################


FLICS_VERSION_MAJOR = @FLICS_VERSION_MAJOR@
FLICS_VERSION_MINOR = @FLICS_VERSION_MINOR@
FLICS_VERSION_PATCH = @FLICS_VERSION_PATCH@
FLICS_VERSION = @FLICS_VERSION@

.EXPORT_ALL_VARIABLES: nsisinst appbundle

# Sources that are generated,
BUILT_SOURCES =
# not distributed,
nodist_flics_SOURCES = $(BUILT_SOURCES)
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
	if test -f $(srcdir)/../data/flics.xpm; then \
	    $(mkinstalldirs) $(DESTDIR)/$(datadir)/pixmaps; \
	    $(INSTALL_DATA) $(srcdir)/../data/flics.xpm $(DESTDIR)/$(datadir)/pixmaps; \
	fi
	if test -f $(srcdir)/../data/flics.desktop; then \
	    $(mkinstalldirs) $(DESTDIR)/$(datadir)/applications; \
	    $(INSTALL_DATA) $(srcdir)/../data/flics.desktop $(DESTDIR)/$(datadir)/applications; \
	fi

uninstall-local:
	rm -f $(DESTDIR)/$(datadir)/pixmaps/flics.xpm
	rm -f $(DESTDIR)/$(datadir)/applications/flics.desktop

FL_SRC = ics213_dialog.fl

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


INSTALLER_FILE = flics-$(FLICS_VERSION)_setup.exe
APPBUNDLE=flics-$(FLICS_VERSION)
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
flics_SOURCES += \
	$(srcdir)/calendar.cxx \
	$(srcdir)/combo.cxx \
	$(srcdir)/base64.cxx \
	$(srcdir)/date.cxx \
	$(srcdir)/debug.cxx \
	$(srcdir)/fileselect.cxx \
	$(srcdir)/flinput2.cxx \
	$(srcdir)/icons.cxx \
	$(srcdir)/ics213.cxx \
	$(srcdir)/ics213_template.cxx \
	$(srcdir)/ics213_dialog.cxx \
	$(srcdir)/parse_xml.cxx \
	$(srcdir)/pixmaps.cxx \
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
	$(srcdir)/include/base64.h \
	$(srcdir)/include/calendar.h \
	$(srcdir)/include/combo.h \
	$(srcdir)/include/compat.h \
	$(srcdir)/include/compat-mingw.h \
	$(srcdir)/include/crc16.h \
	$(srcdir)/include/date.h \
	$(srcdir)/include/debug.h \
	$(srcdir)/include/fileselect.h \
	$(srcdir)/include/flics_config.h \
	$(srcdir)/include/flicsrc.h \
	$(srcdir)/include/flinput2.h \
	$(srcdir)/include/gettext.h \
	$(srcdir)/include/icons.h \
	$(srcdir)/include/ics213.h \
	$(srcdir)/include/ics213_dialog.h \
	$(srcdir)/include/ics213_template.h \
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
	$(srcdir)/../flics-doc/flics-quick-guide.html \
	$(srcdir)/../flics-doc/flics-ss1.png \
	$(srcdir)/../flics-doc/flics-ss4.png \
	$(srcdir)/../flics-doc/Menu0.png \
	$(srcdir)/../flics-doc/Menu1.png \
	$(srcdir)/../flics-doc/Menu2.png

# Additional source files that support non-Linux cross compilation
EXTRA_DIST += \
	$(srcdir)/../data/flics.desktop \
	$(srcdir)/../data/flics.xpm \
	$(srcdir)/../data/win32/fl_app.nsi \
	$(srcdir)/../data/win32/flics.ico \
	$(srcdir)/../scripts/build4mingw.sh \
	$(srcdir)/../scripts/builddist.sh \
	$(srcdir)/../scripts/mkappbundle.sh \
	$(srcdir)/../scripts/mknsisinst.sh \
	$(srcdir)/../data/mac/Info.plist.in \
	$(srcdir)/../data/mac/flics.icns \
	$(FLICS_WIN32_SRC) \
	$(FLICS_FL_SRC)
