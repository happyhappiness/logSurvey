EOF


AC_CHECK_SIZEOF_SYSTYPE(__int64)
AC_CHECK_SIZEOF_SYSTYPE(int16_t)
AC_CHECK_SIZEOF_SYSTYPE(uint16_t)
AC_CHECK_SIZEOF_SYSTYPE(u_int16_t)
AC_CHECK_SIZEOF_SYSTYPE(int32_t)
AC_CHECK_SIZEOF_SYSTYPE(uint32_t)
AC_CHECK_SIZEOF_SYSTYPE(u_int32_t)
AC_CHECK_SIZEOF_SYSTYPE(int64_t)
AC_CHECK_SIZEOF_SYSTYPE(uint64_t)
AC_CHECK_SIZEOF_SYSTYPE(u_int64_t)

if test "x$ac_cv_sizeof_short" = "x2"; then
	echo $ac_n "checking for int16_t""... $ac_c" 1>&6
echo "configure:4739: checking for int16_t" >&5
if eval "test \"`echo '$''{'ac_cv_type_int16_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 4744 "configure"
#include "confdefs.h"
#include <sys/types.h>
#if STDC_HEADERS
