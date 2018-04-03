


echo "$as_me:$LINENO: checking for int8_t" >&5
echo $ECHO_N "checking for int8_t... $ECHO_C" >&6
if test "${ac_cv_type_int8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif


int
main ()
{
if ((int8_t *) 0)
  return 0;
if (sizeof (int8_t))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_int8_t=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_int8_t=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_int8_t" >&5
echo "${ECHO_T}$ac_cv_type_int8_t" >&6
if test $ac_cv_type_int8_t = yes; then

  echo "$as_me:$LINENO: checking for int8_t" >&5
echo $ECHO_N "checking for int8_t... $ECHO_C" >&6
if test "${ac_cv_type_int8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
if ((int8_t *) 0)
  return 0;
if (sizeof (int8_t))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_int8_t=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_int8_t=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_int8_t" >&5
echo "${ECHO_T}$ac_cv_type_int8_t" >&6

echo "$as_me:$LINENO: checking size of int8_t" >&5
echo $ECHO_N "checking size of int8_t... $ECHO_C" >&6
if test "${ac_cv_sizeof_int8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  if test "$ac_cv_type_int8_t" = yes; then
  # The cast to unsigned long works around a bug in the HP C Compiler
  # version HP92453-01 B.11.11.23709.GP, which incorrectly rejects
  # declarations like `int a3[[(sizeof (unsigned char)) >= 0]];'.
  # This bug is HP SR number 8606223364.
  if test "$cross_compiling" = yes; then
  # Depending upon the size, compute the lo and hi bounds.
cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (int8_t))) >= 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=0 ac_mid=0
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (int8_t))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr $ac_mid + 1`
		    if test $ac_lo -le $ac_mid; then
		      ac_lo= ac_hi=
		      break
		    fi
		    ac_mid=`expr 2 '*' $ac_mid + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (int8_t))) < 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=-1 ac_mid=-1
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (int8_t))) >= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_hi=`expr '(' $ac_mid ')' - 1`
		       if test $ac_mid -le $ac_hi; then
			 ac_lo= ac_hi=
			 break
		       fi
		       ac_mid=`expr 2 '*' $ac_mid`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo= ac_hi=
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
# Binary search between lo and hi bounds.
while test "x$ac_lo" != "x$ac_hi"; do
  ac_mid=`expr '(' $ac_hi - $ac_lo ')' / 2 + $ac_lo`
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (int8_t))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr '(' $ac_mid ')' + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
done
case $ac_lo in
?*) ac_cv_sizeof_int8_t=$ac_lo;;
'') { { echo "$as_me:$LINENO: error: cannot compute sizeof (int8_t), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (int8_t), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; } ;;
esac
else
  if test "$cross_compiling" = yes; then
  { { echo "$as_me:$LINENO: error: cannot run test program while cross compiling
See \`config.log' for more details." >&5
echo "$as_me: error: cannot run test program while cross compiling
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



long longval () { return (long) (sizeof (int8_t)); }
unsigned long ulongval () { return (long) (sizeof (int8_t)); }
#include <stdio.h>
#include <stdlib.h>
int
main ()
{

  FILE *f = fopen ("conftest.val", "w");
  if (! f)
    exit (1);
  if (((long) (sizeof (int8_t))) < 0)
    {
      long i = longval ();
      if (i != ((long) (sizeof (int8_t))))
	exit (1);
      fprintf (f, "%ld\n", i);
    }
  else
    {
      unsigned long i = ulongval ();
      if (i != ((long) (sizeof (int8_t))))
	exit (1);
      fprintf (f, "%lu\n", i);
    }
  exit (ferror (f) || fclose (f) != 0);

  ;
  return 0;
}
_ACEOF
rm -f conftest$ac_exeext
if { (eval echo "$as_me:$LINENO: \"$ac_link\"") >&5
  (eval $ac_link) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } && { ac_try='./conftest$ac_exeext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_sizeof_int8_t=`cat conftest.val`
else
  echo "$as_me: program exited with status $ac_status" >&5
echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

( exit $ac_status )
{ { echo "$as_me:$LINENO: error: cannot compute sizeof (int8_t), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (int8_t), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
fi
rm -f core *.core gmon.out bb.out conftest$ac_exeext conftest.$ac_objext conftest.$ac_ext
fi
fi
rm -f conftest.val
else
  ac_cv_sizeof_int8_t=0
fi
fi
echo "$as_me:$LINENO: result: $ac_cv_sizeof_int8_t" >&5
echo "${ECHO_T}$ac_cv_sizeof_int8_t" >&6
cat >>confdefs.h <<_ACEOF
#define SIZEOF_INT8_T $ac_cv_sizeof_int8_t
_ACEOF



cat >>confdefs.h <<\_ACEOF
#define HAVE_INT8_T 1
_ACEOF


fi


echo "$as_me:$LINENO: checking for char" >&5
echo $ECHO_N "checking for char... $ECHO_C" >&6
if test "${ac_cv_type_char+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif


int
main ()
{
if ((char *) 0)
  return 0;
if (sizeof (char))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_char=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_char=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_char" >&5
echo "${ECHO_T}$ac_cv_type_char" >&6
if test $ac_cv_type_char = yes; then

  echo "$as_me:$LINENO: checking for char" >&5
echo $ECHO_N "checking for char... $ECHO_C" >&6
if test "${ac_cv_type_char+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
if ((char *) 0)
  return 0;
if (sizeof (char))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_char=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_char=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_char" >&5
echo "${ECHO_T}$ac_cv_type_char" >&6

echo "$as_me:$LINENO: checking size of char" >&5
echo $ECHO_N "checking size of char... $ECHO_C" >&6
if test "${ac_cv_sizeof_char+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  if test "$ac_cv_type_char" = yes; then
  # The cast to unsigned long works around a bug in the HP C Compiler
  # version HP92453-01 B.11.11.23709.GP, which incorrectly rejects
  # declarations like `int a3[[(sizeof (unsigned char)) >= 0]];'.
  # This bug is HP SR number 8606223364.
  if test "$cross_compiling" = yes; then
  # Depending upon the size, compute the lo and hi bounds.
cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (char))) >= 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=0 ac_mid=0
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (char))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr $ac_mid + 1`
		    if test $ac_lo -le $ac_mid; then
		      ac_lo= ac_hi=
		      break
		    fi
		    ac_mid=`expr 2 '*' $ac_mid + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (char))) < 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=-1 ac_mid=-1
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (char))) >= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_hi=`expr '(' $ac_mid ')' - 1`
		       if test $ac_mid -le $ac_hi; then
			 ac_lo= ac_hi=
			 break
		       fi
		       ac_mid=`expr 2 '*' $ac_mid`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo= ac_hi=
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
# Binary search between lo and hi bounds.
while test "x$ac_lo" != "x$ac_hi"; do
  ac_mid=`expr '(' $ac_hi - $ac_lo ')' / 2 + $ac_lo`
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (char))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr '(' $ac_mid ')' + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
done
case $ac_lo in
?*) ac_cv_sizeof_char=$ac_lo;;
'') { { echo "$as_me:$LINENO: error: cannot compute sizeof (char), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (char), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; } ;;
esac
else
  if test "$cross_compiling" = yes; then
  { { echo "$as_me:$LINENO: error: cannot run test program while cross compiling
See \`config.log' for more details." >&5
echo "$as_me: error: cannot run test program while cross compiling
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



long longval () { return (long) (sizeof (char)); }
unsigned long ulongval () { return (long) (sizeof (char)); }
#include <stdio.h>
#include <stdlib.h>
int
main ()
{

  FILE *f = fopen ("conftest.val", "w");
  if (! f)
    exit (1);
  if (((long) (sizeof (char))) < 0)
    {
      long i = longval ();
      if (i != ((long) (sizeof (char))))
	exit (1);
      fprintf (f, "%ld\n", i);
    }
  else
    {
      unsigned long i = ulongval ();
      if (i != ((long) (sizeof (char))))
	exit (1);
      fprintf (f, "%lu\n", i);
    }
  exit (ferror (f) || fclose (f) != 0);

  ;
  return 0;
}
_ACEOF
rm -f conftest$ac_exeext
if { (eval echo "$as_me:$LINENO: \"$ac_link\"") >&5
  (eval $ac_link) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } && { ac_try='./conftest$ac_exeext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_sizeof_char=`cat conftest.val`
else
  echo "$as_me: program exited with status $ac_status" >&5
echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

( exit $ac_status )
{ { echo "$as_me:$LINENO: error: cannot compute sizeof (char), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (char), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
fi
rm -f core *.core gmon.out bb.out conftest$ac_exeext conftest.$ac_objext conftest.$ac_ext
fi
fi
rm -f conftest.val
else
  ac_cv_sizeof_char=0
fi
fi
echo "$as_me:$LINENO: result: $ac_cv_sizeof_char" >&5
echo "${ECHO_T}$ac_cv_sizeof_char" >&6
cat >>confdefs.h <<_ACEOF
#define SIZEOF_CHAR $ac_cv_sizeof_char
_ACEOF



cat >>confdefs.h <<\_ACEOF
#define HAVE_CHAR 1
_ACEOF


fi


echo "$as_me:$LINENO: checking for u_int8_t" >&5
echo $ECHO_N "checking for u_int8_t... $ECHO_C" >&6
if test "${ac_cv_type_u_int8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif


int
main ()
{
if ((u_int8_t *) 0)
  return 0;
if (sizeof (u_int8_t))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_u_int8_t=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_u_int8_t=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_u_int8_t" >&5
echo "${ECHO_T}$ac_cv_type_u_int8_t" >&6
if test $ac_cv_type_u_int8_t = yes; then

  echo "$as_me:$LINENO: checking for u_int8_t" >&5
echo $ECHO_N "checking for u_int8_t... $ECHO_C" >&6
if test "${ac_cv_type_u_int8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
if ((u_int8_t *) 0)
  return 0;
if (sizeof (u_int8_t))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_u_int8_t=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_u_int8_t=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_u_int8_t" >&5
echo "${ECHO_T}$ac_cv_type_u_int8_t" >&6

echo "$as_me:$LINENO: checking size of u_int8_t" >&5
echo $ECHO_N "checking size of u_int8_t... $ECHO_C" >&6
if test "${ac_cv_sizeof_u_int8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  if test "$ac_cv_type_u_int8_t" = yes; then
  # The cast to unsigned long works around a bug in the HP C Compiler
  # version HP92453-01 B.11.11.23709.GP, which incorrectly rejects
  # declarations like `int a3[[(sizeof (unsigned char)) >= 0]];'.
  # This bug is HP SR number 8606223364.
  if test "$cross_compiling" = yes; then
  # Depending upon the size, compute the lo and hi bounds.
cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (u_int8_t))) >= 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=0 ac_mid=0
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (u_int8_t))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr $ac_mid + 1`
		    if test $ac_lo -le $ac_mid; then
		      ac_lo= ac_hi=
		      break
		    fi
		    ac_mid=`expr 2 '*' $ac_mid + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (u_int8_t))) < 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=-1 ac_mid=-1
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (u_int8_t))) >= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_hi=`expr '(' $ac_mid ')' - 1`
		       if test $ac_mid -le $ac_hi; then
			 ac_lo= ac_hi=
			 break
		       fi
		       ac_mid=`expr 2 '*' $ac_mid`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo= ac_hi=
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
# Binary search between lo and hi bounds.
while test "x$ac_lo" != "x$ac_hi"; do
  ac_mid=`expr '(' $ac_hi - $ac_lo ')' / 2 + $ac_lo`
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (u_int8_t))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr '(' $ac_mid ')' + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
done
case $ac_lo in
?*) ac_cv_sizeof_u_int8_t=$ac_lo;;
'') { { echo "$as_me:$LINENO: error: cannot compute sizeof (u_int8_t), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (u_int8_t), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; } ;;
esac
else
  if test "$cross_compiling" = yes; then
  { { echo "$as_me:$LINENO: error: cannot run test program while cross compiling
See \`config.log' for more details." >&5
echo "$as_me: error: cannot run test program while cross compiling
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



long longval () { return (long) (sizeof (u_int8_t)); }
unsigned long ulongval () { return (long) (sizeof (u_int8_t)); }
#include <stdio.h>
#include <stdlib.h>
int
main ()
{

  FILE *f = fopen ("conftest.val", "w");
  if (! f)
    exit (1);
  if (((long) (sizeof (u_int8_t))) < 0)
    {
      long i = longval ();
      if (i != ((long) (sizeof (u_int8_t))))
	exit (1);
      fprintf (f, "%ld\n", i);
    }
  else
    {
      unsigned long i = ulongval ();
      if (i != ((long) (sizeof (u_int8_t))))
	exit (1);
      fprintf (f, "%lu\n", i);
    }
  exit (ferror (f) || fclose (f) != 0);

  ;
  return 0;
}
_ACEOF
rm -f conftest$ac_exeext
if { (eval echo "$as_me:$LINENO: \"$ac_link\"") >&5
  (eval $ac_link) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } && { ac_try='./conftest$ac_exeext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_sizeof_u_int8_t=`cat conftest.val`
else
  echo "$as_me: program exited with status $ac_status" >&5
echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

( exit $ac_status )
{ { echo "$as_me:$LINENO: error: cannot compute sizeof (u_int8_t), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (u_int8_t), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
fi
rm -f core *.core gmon.out bb.out conftest$ac_exeext conftest.$ac_objext conftest.$ac_ext
fi
fi
rm -f conftest.val
else
  ac_cv_sizeof_u_int8_t=0
fi
fi
echo "$as_me:$LINENO: result: $ac_cv_sizeof_u_int8_t" >&5
echo "${ECHO_T}$ac_cv_sizeof_u_int8_t" >&6
cat >>confdefs.h <<_ACEOF
#define SIZEOF_U_INT8_T $ac_cv_sizeof_u_int8_t
_ACEOF



cat >>confdefs.h <<\_ACEOF
#define HAVE_U_INT8_T 1
_ACEOF


fi


echo "$as_me:$LINENO: checking for uint8_t" >&5
echo $ECHO_N "checking for uint8_t... $ECHO_C" >&6
if test "${ac_cv_type_uint8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif


int
main ()
{
if ((uint8_t *) 0)
  return 0;
if (sizeof (uint8_t))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_uint8_t=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_uint8_t=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_uint8_t" >&5
echo "${ECHO_T}$ac_cv_type_uint8_t" >&6
if test $ac_cv_type_uint8_t = yes; then

  echo "$as_me:$LINENO: checking for uint8_t" >&5
echo $ECHO_N "checking for uint8_t... $ECHO_C" >&6
if test "${ac_cv_type_uint8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
if ((uint8_t *) 0)
  return 0;
if (sizeof (uint8_t))
  return 0;
  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_type_uint8_t=yes
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_cv_type_uint8_t=no
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
echo "$as_me:$LINENO: result: $ac_cv_type_uint8_t" >&5
echo "${ECHO_T}$ac_cv_type_uint8_t" >&6

echo "$as_me:$LINENO: checking size of uint8_t" >&5
echo $ECHO_N "checking size of uint8_t... $ECHO_C" >&6
if test "${ac_cv_sizeof_uint8_t+set}" = set; then
  echo $ECHO_N "(cached) $ECHO_C" >&6
else
  if test "$ac_cv_type_uint8_t" = yes; then
  # The cast to unsigned long works around a bug in the HP C Compiler
  # version HP92453-01 B.11.11.23709.GP, which incorrectly rejects
  # declarations like `int a3[[(sizeof (unsigned char)) >= 0]];'.
  # This bug is HP SR number 8606223364.
  if test "$cross_compiling" = yes; then
  # Depending upon the size, compute the lo and hi bounds.
cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (uint8_t))) >= 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=0 ac_mid=0
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (uint8_t))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr $ac_mid + 1`
		    if test $ac_lo -le $ac_mid; then
		      ac_lo= ac_hi=
		      break
		    fi
		    ac_mid=`expr 2 '*' $ac_mid + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (uint8_t))) < 0)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=-1 ac_mid=-1
  while :; do
    cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (uint8_t))) >= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_lo=$ac_mid; break
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_hi=`expr '(' $ac_mid ')' - 1`
		       if test $ac_mid -le $ac_hi; then
			 ac_lo= ac_hi=
			 break
		       fi
		       ac_mid=`expr 2 '*' $ac_mid`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
  done
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo= ac_hi=
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
# Binary search between lo and hi bounds.
while test "x$ac_lo" != "x$ac_hi"; do
  ac_mid=`expr '(' $ac_hi - $ac_lo ')' / 2 + $ac_lo`
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



int
main ()
{
static int test_array [1 - 2 * !(((long) (sizeof (uint8_t))) <= $ac_mid)];
test_array [0] = 0

  ;
  return 0;
}
_ACEOF
rm -f conftest.$ac_objext
if { (eval echo "$as_me:$LINENO: \"$ac_compile\"") >&5
  (eval $ac_compile) 2>conftest.er1
  ac_status=$?
  grep -v '^ *+' conftest.er1 >conftest.err
  rm -f conftest.er1
  cat conftest.err >&5
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } &&
	 { ac_try='test -z "$ac_c_werror_flag"
			 || test ! -s conftest.err'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; } &&
	 { ac_try='test -s conftest.$ac_objext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_hi=$ac_mid
else
  echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

ac_lo=`expr '(' $ac_mid ')' + 1`
fi
rm -f conftest.err conftest.$ac_objext conftest.$ac_ext
done
case $ac_lo in
?*) ac_cv_sizeof_uint8_t=$ac_lo;;
'') { { echo "$as_me:$LINENO: error: cannot compute sizeof (uint8_t), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (uint8_t), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; } ;;
esac
else
  if test "$cross_compiling" = yes; then
  { { echo "$as_me:$LINENO: error: cannot run test program while cross compiling
See \`config.log' for more details." >&5
echo "$as_me: error: cannot run test program while cross compiling
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
else
  cat >conftest.$ac_ext <<_ACEOF
/* confdefs.h.  */
_ACEOF
cat confdefs.h >>conftest.$ac_ext
cat >>conftest.$ac_ext <<_ACEOF
/* end confdefs.h.  */

#include <stdio.h>

/* What a mess.. many systems have added the (now standard) bit types
 * in their own ways, so we need to scan a wide variety of headers to
 * find them..
 * IMPORTANT: Keep include/squid_types.h syncronised with this list
 */
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif



long longval () { return (long) (sizeof (uint8_t)); }
unsigned long ulongval () { return (long) (sizeof (uint8_t)); }
#include <stdio.h>
#include <stdlib.h>
int
main ()
{

  FILE *f = fopen ("conftest.val", "w");
  if (! f)
    exit (1);
  if (((long) (sizeof (uint8_t))) < 0)
    {
      long i = longval ();
      if (i != ((long) (sizeof (uint8_t))))
	exit (1);
      fprintf (f, "%ld\n", i);
    }
  else
    {
      unsigned long i = ulongval ();
      if (i != ((long) (sizeof (uint8_t))))
	exit (1);
      fprintf (f, "%lu\n", i);
    }
  exit (ferror (f) || fclose (f) != 0);

  ;
  return 0;
}
_ACEOF
rm -f conftest$ac_exeext
if { (eval echo "$as_me:$LINENO: \"$ac_link\"") >&5
  (eval $ac_link) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); } && { ac_try='./conftest$ac_exeext'
  { (eval echo "$as_me:$LINENO: \"$ac_try\"") >&5
  (eval $ac_try) 2>&5
  ac_status=$?
  echo "$as_me:$LINENO: \$? = $ac_status" >&5
  (exit $ac_status); }; }; then
  ac_cv_sizeof_uint8_t=`cat conftest.val`
else
  echo "$as_me: program exited with status $ac_status" >&5
echo "$as_me: failed program was:" >&5
sed 's/^/| /' conftest.$ac_ext >&5

( exit $ac_status )
{ { echo "$as_me:$LINENO: error: cannot compute sizeof (uint8_t), 77
See \`config.log' for more details." >&5
echo "$as_me: error: cannot compute sizeof (uint8_t), 77
See \`config.log' for more details." >&2;}
   { (exit 1); exit 1; }; }
fi
rm -f core *.core gmon.out bb.out conftest$ac_exeext conftest.$ac_objext conftest.$ac_ext
fi
fi
rm -f conftest.val
else
  ac_cv_sizeof_uint8_t=0
fi
fi
echo "$as_me:$LINENO: result: $ac_cv_sizeof_uint8_t" >&5
echo "${ECHO_T}$ac_cv_sizeof_uint8_t" >&6
cat >>confdefs.h <<_ACEOF
#define SIZEOF_UINT8_T $ac_cv_sizeof_uint8_t
_ACEOF



cat >>confdefs.h <<\_ACEOF
#define HAVE_UINT8_T 1
_ACEOF


fi


echo "$as_me:$LINENO: checking for int16_t" >&5
echo $ECHO_N "checking for int16_t... $ECHO_C" >&6
if test "${ac_cv_type_int16_t+set}" = set; then
