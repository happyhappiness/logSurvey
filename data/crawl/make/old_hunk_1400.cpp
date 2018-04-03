done

echo $ac_n "checking for sys_siglist""... $ac_c" 1>&6
if eval "test \"`echo '$''{'ac_cv_check_symbol_sys_siglist'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 1518 "configure"
#include "confdefs.h"

int main() { return 0; }
int t() {
extern char *sys_siglist[]; puts(*sys_siglist);
; return 0; }
EOF
if { (eval echo configure:1526: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; }; then
  rm -rf conftest*
  	    ac_cv_check_symbol_sys_siglist=yes
else
  rm -rf conftest*
  ac_cv_check_symbol_sys_siglist=no
fi
rm -f conftest*

fi

if test "$ac_cv_check_symbol_sys_siglist" = yes; then
