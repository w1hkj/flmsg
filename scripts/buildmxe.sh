#!/bin/sh

### Script to build a win32 installation

./configure \
  $PKGCFG \
  $CROSSCFG \
  --with-ptw32=$PREFIX/i686-w64-mingw32.static \
  --enable-static \
  PTW32_LIBS="-lpthread -lpcreposix -lpcre -lregex" \
  FLTK_CONFIG=$PREFIX/bin/i686-w64-mingw32.static-fltk-config \

make clean

make
$PREFIX/bin/i686-w64-mingw32.static-strip src/flmsg.exe

make nsisinst
mv src/*setup*exe .
