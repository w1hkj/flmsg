#!/bin/sh

### Script to build a win32 installation

./configure \
  $PKGCFG \
  $CROSSCFG \
  --with-ptw32=/opt/mxe/usr/i686-pc-mingw32 \
  --enable-static \
  PTW32_LIBS="-lpthread -lpcreposix -lpcre -lregex" \
  FLTK_CONFIG=$PREFIX/bin/i686-pc-mingw32-fltk-config \

make

make
$PREFIX/bin/i686-pc-mingw32-strip src/flmsg.exe
make nsisinst
mv src/*setup*exe .


