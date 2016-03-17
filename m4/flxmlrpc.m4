AC_DEFUN([AC_FLXMLRPC], [

if test "x$ac_cv_want_flxmlrpc" != "xno"; then
    if test "x$ac_cv_want_flxmlrpc" != "xyes"; then # set -I and -L switches
        flxmlrpc_default_cflags="-I${ac_cv_want_flxmlrpc}/include"
        flxmlrpc_default_libs="-L${ac_cv_want_flxmlrpc}/lib"
    fi
    flxmlrpc_default_cflags="-DFLXMLRPC_STATIC_LIB $flxmlrpc_default_cflags"
    flxmlrpc_default_libs="$flxmlrpc_default_libs -lpthreadGC2 -lws2_32"

    # don't override the user-specified vars
    FLXMLRPC_CFLAGS="${FLXMLRPC_CFLAGS:-$flxmlrpc_default_cflags}"
    FLXMLRPC_LIBS="${FLXMLRPC_LIBS:-$flxmlrpc_default_libs -lflxmlrpc}"

    ac_cv_want_flxmlrpc="yes"
fi

AC_SUBST([FLXMLRPC_CFLAGS])
AC_SUBST([FLXMLRPC_LIBS])

])
