fi
# }}}

# --with-libjevents {{{
with_libjevents_cppflags=""
with_libjevents_ldflags=""
AC_ARG_WITH(libjevents, [AS_HELP_STRING([--with-libjevents@<:@=PREFIX@:>@], [Path to libjevents.])],
[
  if test "x$withval" != "xno" && test "x$withval" != "xyes"
  then
    with_libjevents_cppflags="-I$withval/include"
    with_libjevents_ldflags="-L$withval/lib"
    with_libjevents="yes"
  else
    with_libjevents="$withval"
  fi
],
[
  with_libjevents="yes"
])
if test "x$with_libjevents" = "xyes"
then
  SAVE_CPPFLAGS="$CPPFLAGS"
  CPPFLAGS="$CPPFLAGS $with_libjevents_cppflags"

  AC_CHECK_HEADERS(jevents.h, [with_libjevents="yes"], [with_libjevents="no (jevents.h not found)"])

  CPPFLAGS="$SAVE_CPPFLAGS"
fi
if test "x$with_libjevents" = "xyes"
then
  SAVE_CPPFLAGS="$CPPFLAGS"
  SAVE_LDFLAGS="$LDFLAGS"
  CPPFLAGS="$CPPFLAGS $with_libjevents_cppflags"
  LDFLAGS="$LDFLAGS $with_libjevents_ldflags"

  AC_CHECK_LIB(jevents, json_events, [with_libjevents="yes"], [with_libjevents="no (Can't find libjevents)"])

  CPPFLAGS="$SAVE_CPPFLAGS"
  LDFLAGS="$SAVE_LDFLAGS"
fi
if test "x$with_libjevents" = "xyes"
then
  SAVE_CPPFLAGS="$CPPFLAGS"
  SAVE_LDFLAGS="$LDFLAGS"
  SAVE_LIBS="$LIBS"
  CPPFLAGS="$CPPFLAGS -fPIC"
  LDFLAGS="$LDFLAGS -shared"
  LIBS="-ljevents"
  AC_LINK_IFELSE([AC_LANG_SOURCE(
    [[
      #include <stdio.h>
      #include "jevents.h"
      void print_cpu(void){
        printf("%s", get_cpu_str());
      }
    ]]
  )],
  [with_libjevents="yes"], [with_libjevents="no (could not link to libjevents. Check jevents is compiled with -fPIC.)"])
  CPPFLAGS="$SAVE_CPPFLAGS"
  LDFLAGS="$SAVE_LDFLAGS"
  LIBS="$SAVE_LIBS"
fi
if test "x$with_libjevents" = "xyes"
then
  BUILD_WITH_LIBJEVENTS_CPPFLAGS="$with_libjevents_cppflags"
  BUILD_WITH_LIBJEVENTS_LDFLAGS="$with_libjevents_ldflags"
  BUILD_WITH_LIBJEVENTS_LIBS="-ljevents"
  AC_SUBST(BUILD_WITH_LIBJEVENTS_CPPFLAGS)
  AC_SUBST(BUILD_WITH_LIBJEVENTS_LDFLAGS)
  AC_SUBST(BUILD_WITH_LIBJEVENTS_LIBS)
fi
# }}}

# --with-libprotobuf {{{
with_libprotobuf_cppflags=""
with_libprotobuf_ldflags=""
