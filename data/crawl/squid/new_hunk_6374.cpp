EOF


echo $ac_n "checking if sys_errlist is already defined""... $ac_c" 1>&6
echo "configure:4133: checking if sys_errlist is already defined" >&5
if eval "test \"`echo '$''{'ac_cv_needs_sys_errlist'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 4138 "configure"
#include "confdefs.h"
#include <stdio.h>
int main() {
char *s = sys_errlist0;
; return 0; }
EOF
if { (eval echo configure:4145: \"$ac_compile\") 1>&5; (eval $ac_compile) 2>&5; }; then
  rm -rf conftest*
  ac_cv_needs_sys_errlist="no"
else
