#!/bin/sh

### Script to build a win32 installation

./configure \
  $PKGCFG \
  --host=i686-w64-mingw32.static \
  --with-ptw32=$PREFIX/i686-w64-mingw32.static \
  --enable-static \
  PTW32_LIBS="-lpthread -lpcreposix -lpcre" \
  FLTK_CONFIG=$PREFIX/bin/i686-w64-mingw32.static-fltk-config

make clean
make -j 4

$PREFIX/bin/i686-w64-mingw32.static-strip src/flmsg.exe

make nsisinst
mv src/*setup*exe .
