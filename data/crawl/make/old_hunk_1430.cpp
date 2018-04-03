
fi
echo "$ac_t""$ac_cv_check_symbol_sys_siglist" 1>&6
echo $ac_n "checking for _sys_siglist""... $ac_c" 1>&6
if eval "test \"`echo '$''{'ac_cv_check_symbol__sys_siglist'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 1479 "configure"
#include "confdefs.h"

int main() { return 0; }
int t() {
extern char *_sys_siglist[]; puts(*_sys_siglist);
; return 0; }
EOF
if eval $ac_link; then
  rm -rf conftest*
  	    ac_cv_check_symbol__sys_siglist=yes
else
  rm -rf conftest*
  ac_cv_check_symbol__sys_siglist=no
fi
rm -f conftest*

fi

if test "$ac_cv_check_symbol__sys_siglist" = yes; then
  ac_tr_symbol=`echo _sys_siglist | tr '[a-z]' '[A-Z]'`
  cat >> confdefs.h <<EOF
#define HAVE_${ac_tr_symbol} 1
EOF

fi
echo "$ac_t""$ac_cv_check_symbol__sys_siglist" 1>&6
# The Ultrix 4.2 mips builtin alloca declared by alloca.h only works
# for constant arguments.  Useless!
echo $ac_n "checking for working alloca.h""... $ac_c" 1>&6
