AC_DEFUN([AC_FLMSG_NP_COMPAT], [
  AC_REQUIRE([AC_FL_MACOSX])
  AC_REQUIRE([AC_FL_WIN32])

  AC_ARG_WITH([clock_gettime],
                AC_HELP_STRING([--without-clock_gettime], [Do not use clock_gettime lib]),
                [case "${withval}" in
                  yes|no) ac_cv_with_clock_gettime="${withval}" ;;
                  *)      AC_MSG_ERROR([bad value ${withval} for --without-clock_gettime]) ;;
                 esac],
                 [ac_cv_with_clock_gettime=yes])

  if test "x$ac_cv_with_clock_gettime" = "xyes"; then
    AC_FLMSG_SEARCH_LIBS([clock_gettime], [rt], [$other_libs])
  fi

  AM_CONDITIONAL([COMPAT_REGEX], [test "x$ac_cv_header_regex_h" != "xyes"])

  if test "x$target_mingw32" = "xyes"; then
      sem_libs="pthreadGC2"
  else
      sem_libs="pthread rt"
  fi
  other_libs=""

  if test "x$ac_cv_want_ptw32" = "xyes"; then
      CFLAGS_saved="$CFLAGS"
      LDFLAGS_saved="$LDFLAGS"
      EXTRA_LIBS_saved="$EXTRA_LIBS"
      CFLAGS="$CFLAGS $PTW32_CFLAGS"
      LDFLAGS="$LDFLAGS $PTW32_LIBS"
      other_libs=-lws2_32
  fi

  AC_FLMSG_SEARCH_LIBS([dlopen], [dl], [$other_libs])
  AC_FLMSG_SEARCH_LIBS([sem_unlink], [$sem_libs], [$other_libs])
  AC_FLMSG_SEARCH_LIBS([sem_timedwait], [$sem_libs], [$other_libs])

  if test "x$ac_cv_want_ptw32" = "xyes"; then
      CFLAGS="$CFLAGS_saved"
      LDFLAGS="$LDFLAGS_saved"
      EXTRA_LIBS="$EXTRA_LIBS_saved"
  fi
  AC_SUBST([EXTRA_LIBS])

  AM_CONDITIONAL([COMPAT_STRCASESTR], [test "x$ac_cv_func_strcasestr" != "xyes"])
])
