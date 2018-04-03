fi


# Check size of long.
echo $ac_n "checking size of long""... $ac_c" 1>&6
echo "configure:1548: checking size of long" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_long'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 1556 "configure"
#include "confdefs.h"
#include <stdio.h>
main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) exit(1);
  fprintf(f, "%d\n", sizeof(long));
  exit(0);
}
EOF
if { (eval echo configure:1567: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_long=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_long=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_long" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_LONG $ac_cv_sizeof_long
EOF


echo $ac_n "checking size of long long""... $ac_c" 1>&6
echo "configure:1587: checking size of long long" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_long_long'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 1595 "configure"
#include "confdefs.h"
#include <stdio.h>
main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) exit(1);
  fprintf(f, "%d\n", sizeof(long long));
  exit(0);
}
EOF
if { (eval echo configure:1606: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_long_long=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_long_long=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_long_long" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_LONG_LONG $ac_cv_sizeof_long_long
EOF



for ac_hdr in string.h stdarg.h unistd.h sys/time.h utime.h sys/utime.h
do
ac_safe=`echo "$ac_hdr" | sed 'y%./+-%__p_%'`
echo $ac_n "checking for $ac_hdr""... $ac_c" 1>&6
echo "configure:1630: checking for $ac_hdr" >&5
if eval "test \"`echo '$''{'ac_cv_header_$ac_safe'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 1635 "configure"
#include "confdefs.h"
#include <$ac_hdr>
EOF
ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
{ (eval echo configure:1640: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
ac_err=`grep -v '^ *+' conftest.out | grep -v "^conftest.${ac_ext}\$"`
if test -z "$ac_err"; then
  rm -rf conftest*
