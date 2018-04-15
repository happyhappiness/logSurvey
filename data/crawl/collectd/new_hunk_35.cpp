fi
if test "x$with_libjevents" = "xyes"
then
  SAVE_LDFLAGS="$LDFLAGS"
  LDFLAGS="$LDFLAGS $with_libjevents_ldflags"

  AC_CHECK_LIB(jevents, json_events, [with_libjevents="yes"], [with_libjevents="no (Can't find libjevents)"])

  LDFLAGS="$SAVE_LDFLAGS"
fi
if test "x$with_libjevents" = "xyes"
then
  BUILD_WITH_LIBJEVENTS_CPPFLAGS="$with_libjevents_cppflags"
  BUILD_WITH_LIBJEVENTS_LDFLAGS="$with_libjevents_ldflags"
  BUILD_WITH_LIBJEVENTS_LIBS="-ljevents"
fi
AC_SUBST(BUILD_WITH_LIBJEVENTS_CPPFLAGS)
AC_SUBST(BUILD_WITH_LIBJEVENTS_LDFLAGS)
AC_SUBST(BUILD_WITH_LIBJEVENTS_LIBS)
# }}}

# --with-libprotobuf {{{
