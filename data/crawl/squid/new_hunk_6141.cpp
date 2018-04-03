EOF


echo $ac_n "checking size of void *""... $ac_c" 1>&6
echo "configure:2729: checking size of void *" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_void_p'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 2737 "configure"
#include "confdefs.h"
#include <stdio.h>
main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) exit(1);
  fprintf(f, "%d\n", sizeof(void *));
  exit(0);
}
EOF
if { (eval echo configure:2748: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_void_p=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_void_p=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_void_p" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_VOID_P $ac_cv_sizeof_void_p
EOF



# The Ultrix 4.2 mips builtin alloca declared by alloca.h only works
# for constant arguments.  Useless!
echo $ac_n "checking for working alloca.h""... $ac_c" 1>&6
echo "configure:2771: checking for working alloca.h" >&5
if eval "test \"`echo '$''{'ac_cv_header_alloca_h'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 2776 "configure"
#include "confdefs.h"
#include <alloca.h>
int main() {
char *p = alloca(2 * sizeof(int));
; return 0; }
EOF
if { (eval echo configure:2783: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest; then
  rm -rf conftest*
  ac_cv_header_alloca_h=yes
else
