
fi

echo $ac_n "checking size of void *""... $ac_c" 1>&6
echo "configure:3285: checking size of void *" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_void_p'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 3293 "configure"
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
if { (eval echo configure:3304: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
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


echo $ac_n "checking size of short""... $ac_c" 1>&6
echo "configure:3324: checking size of short" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_short'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 3332 "configure"
#include "confdefs.h"
#include <stdio.h>
main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) exit(1);
  fprintf(f, "%d\n", sizeof(short));
  exit(0);
}
EOF
if { (eval echo configure:3343: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_short=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_short=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_short" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_SHORT $ac_cv_sizeof_short
EOF


echo $ac_n "checking size of int""... $ac_c" 1>&6
echo "configure:3363: checking size of int" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_int'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 3371 "configure"
#include "confdefs.h"
#include <stdio.h>
main()
