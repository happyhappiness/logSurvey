fi


AC_CHECK_SIZEOF_SYSTYPE(off_t, 4)
AC_CHECK_SIZEOF_SYSTYPE(size_t, 4)

# The Ultrix 4.2 mips builtin alloca declared by alloca.h only works
# for constant arguments.  Useless!
echo $ac_n "checking for working alloca.h""... $ac_c" 1>&6
echo "configure:5527: checking for working alloca.h" >&5
if eval "test \"`echo '$''{'ac_cv_header_alloca_h'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 5532 "configure"
#include "confdefs.h"
#include <alloca.h>
int main() {
char *p = alloca(2 * sizeof(int));
; return 0; }
EOF
if { (eval echo configure:5539: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext}; then
  rm -rf conftest*
  ac_cv_header_alloca_h=yes
else
