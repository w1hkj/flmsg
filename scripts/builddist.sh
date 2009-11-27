# build file to generate the Linux / MS binaries & the dist tarball

# Linux binary
make clean
./configure --enable-static --prefix=/tmp/flics-build
make install-strip
tar czf flics-$1.bin.tgz -C /tmp/flics-build/bin flics

# MS exectable
make clean
./configure $CROSSCFG $PKGCFG FLTK_CONFIG=$PREFIX/bin/fltk-config --with-ptw32=$PREFIX/ptw32 XMLRPC_C_CONFIG=$PREFIX/bin/xmlrpc-c-config
make
i586-mingw32msvc-strip src/flics.exe
make nsisinst
mv src/*setup*exe .

# source tarball
make clean
./configure
make distcheck
make clean
