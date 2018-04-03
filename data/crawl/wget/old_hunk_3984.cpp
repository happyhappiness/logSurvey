fi


for ac_hdr in string.h stdarg.h unistd.h sys/time.h utime.h sys/utime.h
do
ac_safe=`echo "$ac_hdr" | sed 'y%./+-%__p_%'`
echo $ac_n "checking for $ac_hdr""... $ac_c" 1>&6
echo "configure:1550: checking for $ac_hdr" >&5
if eval "test \"`echo '$''{'ac_cv_header_$ac_safe'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 1555 "configure"
#include "confdefs.h"
#include <$ac_hdr>
EOF
ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
{ (eval echo configure:1560: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
ac_err=`grep -v '^ *+' conftest.out | grep -v "^conftest.${ac_ext}\$"`
if test -z "$ac_err"; then
  rm -rf conftest*
