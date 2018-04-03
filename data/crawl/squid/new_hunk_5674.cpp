EOF


echo $ac_n "checking size of __int64""... $ac_c" 1>&6
echo "configure:4727: checking size of __int64" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof___int64'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 4735 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(__int64));
  return(0);
}
EOF
if { (eval echo configure:4752: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof___int64=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof___int64=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof___int64" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF___INT64 $ac_cv_sizeof___int64
EOF


echo $ac_n "checking size of int16_t""... $ac_c" 1>&6
echo "configure:4772: checking size of int16_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_int16_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 4780 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(int16_t));
  return(0);
}
EOF
if { (eval echo configure:4797: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_int16_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_int16_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_int16_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_INT16_T $ac_cv_sizeof_int16_t
EOF


echo $ac_n "checking size of uint16_t""... $ac_c" 1>&6
echo "configure:4817: checking size of uint16_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_uint16_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 4825 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(uint16_t));
  return(0);
}
EOF
if { (eval echo configure:4842: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_uint16_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_uint16_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_uint16_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_UINT16_T $ac_cv_sizeof_uint16_t
EOF


echo $ac_n "checking size of u_int16_t""... $ac_c" 1>&6
echo "configure:4862: checking size of u_int16_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_u_int16_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 4870 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(u_int16_t));
  return(0);
}
EOF
if { (eval echo configure:4887: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_u_int16_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_u_int16_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_u_int16_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_U_INT16_T $ac_cv_sizeof_u_int16_t
EOF


echo $ac_n "checking size of int32_t""... $ac_c" 1>&6
echo "configure:4907: checking size of int32_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_int32_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 4915 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(int32_t));
  return(0);
}
EOF
if { (eval echo configure:4932: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_int32_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_int32_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_int32_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_INT32_T $ac_cv_sizeof_int32_t
EOF


echo $ac_n "checking size of uint32_t""... $ac_c" 1>&6
echo "configure:4952: checking size of uint32_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_uint32_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 4960 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(uint32_t));
  return(0);
}
EOF
if { (eval echo configure:4977: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_uint32_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_uint32_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_uint32_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_UINT32_T $ac_cv_sizeof_uint32_t
EOF


echo $ac_n "checking size of u_int32_t""... $ac_c" 1>&6
echo "configure:4997: checking size of u_int32_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_u_int32_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 5005 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(u_int32_t));
  return(0);
}
EOF
if { (eval echo configure:5022: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_u_int32_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_u_int32_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_u_int32_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_U_INT32_T $ac_cv_sizeof_u_int32_t
EOF


echo $ac_n "checking size of int64_t""... $ac_c" 1>&6
echo "configure:5042: checking size of int64_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_int64_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 5050 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(int64_t));
  return(0);
}
EOF
if { (eval echo configure:5067: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_int64_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_int64_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_int64_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_INT64_T $ac_cv_sizeof_int64_t
EOF


echo $ac_n "checking size of uint64_t""... $ac_c" 1>&6
echo "configure:5087: checking size of uint64_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_uint64_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 5095 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(uint64_t));
  return(0);
}
EOF
if { (eval echo configure:5112: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_uint64_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_uint64_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_uint64_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_UINT64_T $ac_cv_sizeof_uint64_t
EOF


echo $ac_n "checking size of u_int64_t""... $ac_c" 1>&6
echo "configure:5132: checking size of u_int64_t" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_u_int64_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 5140 "configure"
#include "confdefs.h"
#include <stdio.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
int main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) return(1);
  fprintf(f, "%d\n", sizeof(u_int64_t));
  return(0);
}
EOF
if { (eval echo configure:5157: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
then
  ac_cv_sizeof_u_int64_t=`cat conftestval`
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  rm -fr conftest*
  ac_cv_sizeof_u_int64_t=0
fi
rm -fr conftest*
fi

fi
echo "$ac_t""$ac_cv_sizeof_u_int64_t" 1>&6
cat >> confdefs.h <<EOF
#define SIZEOF_U_INT64_T $ac_cv_sizeof_u_int64_t
EOF



if test "x$ac_cv_sizeof_short" = "x2"; then
	echo $ac_n "checking for int16_t""... $ac_c" 1>&6
echo "configure:5179: checking for int16_t" >&5
if eval "test \"`echo '$''{'ac_cv_type_int16_t'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  cat > conftest.$ac_ext <<EOF
#line 5184 "configure"
#include "confdefs.h"
#include <sys/types.h>
#if STDC_HEADERS
