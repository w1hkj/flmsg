# build file to generate the Linux / MS binaries & the dist tarball

# Linux binary
make clean
./configure --enable-static --prefix=/tmp/flmsg-build
make install-strip
tar czf flmsg-$1.bin.tgz -C /tmp/flmsg-build/bin flmsg

# MS exectable
make clean
./configure $CROSSCFG $PKGCFG FLTK_CONFIG=$PREFIX/bin/fltk-config --with-ptw32=$PREFIX/ptw32 XMLRPC_C_CONFIG=$PREFIX/bin/xmlrpc-c-config
make
i586-mingw32msvc-strip src/flmsg.exe
make nsisinst
mv src/*setup*exe .

# source tarball
make clean
./configure
make distcheck
make clean
