   exit(0);
 }
 EOF
-if { (eval echo configure:3341: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
-then
-  ac_cv_sizeof_long=`cat conftestval`
+if { (eval echo configure:3421: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_long=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_long=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_long" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_LONG $ac_cv_sizeof_long
+EOF
+
+
+echo $ac_n "checking size of long long""... $ac_c" 1>&6
+echo "configure:3441: checking size of long long" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_long_long'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3449 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(long long));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3460: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_long_long=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_long_long=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_long_long" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_LONG_LONG $ac_cv_sizeof_long_long
+EOF
+
+
+echo $ac_n "checking size of __int64""... $ac_c" 1>&6
+echo "configure:3480: checking size of __int64" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof___int64'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3488 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(__int64));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3499: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof___int64=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof___int64=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof___int64" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF___INT64 $ac_cv_sizeof___int64
+EOF
+
+
+echo $ac_n "checking size of int16_t""... $ac_c" 1>&6
+echo "configure:3519: checking size of int16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_int16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3527 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(int16_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3538: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_int16_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_int16_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_int16_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_INT16_T $ac_cv_sizeof_int16_t
+EOF
+
+
+echo $ac_n "checking size of uint16_t""... $ac_c" 1>&6
+echo "configure:3558: checking size of uint16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_uint16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3566 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(uint16_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3577: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_uint16_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_uint16_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_uint16_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_UINT16_T $ac_cv_sizeof_uint16_t
+EOF
+
+
+echo $ac_n "checking size of u_int16_t""... $ac_c" 1>&6
+echo "configure:3597: checking size of u_int16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_u_int16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3605 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(u_int16_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3616: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_u_int16_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_u_int16_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_u_int16_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_U_INT16_T $ac_cv_sizeof_u_int16_t
+EOF
+
+
+echo $ac_n "checking size of int32_t""... $ac_c" 1>&6
+echo "configure:3636: checking size of int32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_int32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3644 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(int32_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3655: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_int32_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_int32_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_int32_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_INT32_T $ac_cv_sizeof_int32_t
+EOF
+
+
+echo $ac_n "checking size of uint32_t""... $ac_c" 1>&6
+echo "configure:3675: checking size of uint32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_uint32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3683 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(uint32_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3694: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_uint32_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_uint32_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_uint32_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_UINT32_T $ac_cv_sizeof_uint32_t
+EOF
+
+
+echo $ac_n "checking size of u_int32_t""... $ac_c" 1>&6
+echo "configure:3714: checking size of u_int32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_u_int32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3722 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(u_int32_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3733: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_u_int32_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_u_int32_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_u_int32_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_U_INT32_T $ac_cv_sizeof_u_int32_t
+EOF
+
+
+echo $ac_n "checking size of int64_t""... $ac_c" 1>&6
+echo "configure:3753: checking size of int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3761 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(int64_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3772: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_int64_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_int64_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_int64_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_INT64_T $ac_cv_sizeof_int64_t
+EOF
+
+
+echo $ac_n "checking size of uint64_t""... $ac_c" 1>&6
+echo "configure:3792: checking size of uint64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_uint64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3800 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(uint64_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3811: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_uint64_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_uint64_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_uint64_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_UINT64_T $ac_cv_sizeof_uint64_t
+EOF
+
+
+echo $ac_n "checking size of u_int64_t""... $ac_c" 1>&6
+echo "configure:3831: checking size of u_int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_u_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3839 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) exit(1);
+  fprintf(f, "%d\n", sizeof(u_int64_t));
+  exit(0);
+}
+EOF
+if { (eval echo configure:3850: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_u_int64_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_u_int64_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_u_int64_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_U_INT64_T $ac_cv_sizeof_u_int64_t
+EOF
+
+
+
+if test "x$ac_cv_sizeof_short" = "x2"; then
+	echo $ac_n "checking for int16_t""... $ac_c" 1>&6
+echo "configure:3872: checking for int16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3877 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int16_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int16_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int16_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int16_t" 1>&6
+if test $ac_cv_type_int16_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int16_t short
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_int" = "x2"; then
+	echo $ac_n "checking for int16_t""... $ac_c" 1>&6
+echo "configure:3906: checking for int16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3911 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int16_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int16_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int16_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int16_t" 1>&6
+if test $ac_cv_type_int16_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int16_t int
+EOF
+
+fi
+
+fi
+if test "x$ac_cv_sizeof_uint16_t" = "x2"; then
+	echo $ac_n "checking for u_int16_t""... $ac_c" 1>&6
+echo "configure:3941: checking for u_int16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3946 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int16_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int16_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int16_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int16_t" 1>&6
+if test $ac_cv_type_u_int16_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int16_t uint16_t
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_short" = "x2"; then
+	echo $ac_n "checking for u_int16_t""... $ac_c" 1>&6
+echo "configure:3975: checking for u_int16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 3980 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int16_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int16_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int16_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int16_t" 1>&6
+if test $ac_cv_type_u_int16_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int16_t unsigned short
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_int" = "x2"; then
+	echo $ac_n "checking for u_int16_t""... $ac_c" 1>&6
+echo "configure:4009: checking for u_int16_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int16_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4014 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int16_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int16_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int16_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int16_t" 1>&6
+if test $ac_cv_type_u_int16_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int16_t unsigned int
+EOF
+
+fi
+
+fi
+if test "x$ac_cv_sizeof_int" = "x4"; then
+	echo $ac_n "checking for int32_t""... $ac_c" 1>&6
+echo "configure:4044: checking for int32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4049 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int32_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int32_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int32_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int32_t" 1>&6
+if test $ac_cv_type_int32_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int32_t int
+EOF
+
+fi
+
+elif "x$ac_cv_sizeof_long" = "x4"; then
+	echo $ac_n "checking for int32_t""... $ac_c" 1>&6
+echo "configure:4078: checking for int32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4083 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int32_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int32_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int32_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int32_t" 1>&6
+if test $ac_cv_type_int32_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int32_t long
+EOF
+
+fi
+
+fi
+if test "x$ac_cv_sizeof_uint32_t" = "x4"; then
+	echo $ac_n "checking for u_int32_t""... $ac_c" 1>&6
+echo "configure:4113: checking for u_int32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4118 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int32_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int32_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int32_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int32_t" 1>&6
+if test $ac_cv_type_u_int32_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int32_t uint32_t
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_int" = "x4"; then
+	echo $ac_n "checking for u_int32_t""... $ac_c" 1>&6
+echo "configure:4147: checking for u_int32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4152 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int32_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int32_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int32_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int32_t" 1>&6
+if test $ac_cv_type_u_int32_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int32_t unsigned int
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_long" = "x4"; then
+	echo $ac_n "checking for u_int32_t""... $ac_c" 1>&6
+echo "configure:4181: checking for u_int32_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int32_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4186 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int32_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int32_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int32_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int32_t" 1>&6
+if test $ac_cv_type_u_int32_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int32_t unsigned long
+EOF
+
+fi
+
+fi
+if test "x$ac_cv_sizeof_long" = "x8"; then
+	echo $ac_n "checking for int64_t""... $ac_c" 1>&6
+echo "configure:4216: checking for int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4221 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int64_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int64_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int64_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int64_t" 1>&6
+if test $ac_cv_type_int64_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int64_t long
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_long_long" = "x8"; then
+	echo $ac_n "checking for int64_t""... $ac_c" 1>&6
+echo "configure:4250: checking for int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4255 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int64_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int64_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int64_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int64_t" 1>&6
+if test $ac_cv_type_int64_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int64_t long long
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof___int64" = "x8"; then
+	echo $ac_n "checking for int64_t""... $ac_c" 1>&6
+echo "configure:4284: checking for int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4289 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int64_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int64_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int64_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int64_t" 1>&6
+if test $ac_cv_type_int64_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int64_t __int64
+EOF
+
+fi
+
+fi
+if test "x$ac_cv_sizeof_uint64_t" = "x8"; then
+	echo $ac_n "checking for u_int64_t""... $ac_c" 1>&6
+echo "configure:4319: checking for u_int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4324 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int64_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int64_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int64_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int64_t" 1>&6
+if test $ac_cv_type_u_int64_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int64_t uint64_t
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_long" = "x8"; then
+	echo $ac_n "checking for u_int64_t""... $ac_c" 1>&6
+echo "configure:4353: checking for u_int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4358 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int64_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int64_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int64_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int64_t" 1>&6
+if test $ac_cv_type_u_int64_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int64_t unsigned long
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof_long_long" = "x8"; then
+	echo $ac_n "checking for u_int64_t""... $ac_c" 1>&6
+echo "configure:4387: checking for u_int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_u_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4392 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])u_int64_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_u_int64_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_u_int64_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_u_int64_t" 1>&6
+if test $ac_cv_type_u_int64_t = no; then
+  cat >> confdefs.h <<\EOF
+#define u_int64_t unsigned long long
+EOF
+
+fi
+
+elif test "x$ac_cv_sizeof___int64" = "x8"; then
+	echo $ac_n "checking for int64_t""... $ac_c" 1>&6
+echo "configure:4421: checking for int64_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_int64_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4426 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])int64_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_int64_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_int64_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_int64_t" 1>&6
+if test $ac_cv_type_int64_t = no; then
+  cat >> confdefs.h <<\EOF
+#define int64_t unsigned __int64
+EOF
+
+fi
+
+fi
+
+echo $ac_n "checking for pid_t""... $ac_c" 1>&6
+echo "configure:4456: checking for pid_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_pid_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4461 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])pid_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_pid_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_pid_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_pid_t" 1>&6
+if test $ac_cv_type_pid_t = no; then
+  cat >> confdefs.h <<\EOF
+#define pid_t int
+EOF
+
+fi
+
+echo $ac_n "checking for size_t""... $ac_c" 1>&6
+echo "configure:4489: checking for size_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_size_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4494 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])size_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_size_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_size_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_size_t" 1>&6
+if test $ac_cv_type_size_t = no; then
+  cat >> confdefs.h <<\EOF
+#define size_t unsigned int
+EOF
+
+fi
+
+echo $ac_n "checking for ssize_t""... $ac_c" 1>&6
+echo "configure:4522: checking for ssize_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_ssize_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4527 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])ssize_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_ssize_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_ssize_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_ssize_t" 1>&6
+if test $ac_cv_type_ssize_t = no; then
+  cat >> confdefs.h <<\EOF
+#define ssize_t int
+EOF
+
+fi
+
+echo $ac_n "checking for off_t""... $ac_c" 1>&6
+echo "configure:4555: checking for off_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_off_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4560 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])off_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_off_t=yes
+else
+  rm -rf conftest*
+  ac_cv_type_off_t=no
+fi
+rm -f conftest*
+
+fi
+echo "$ac_t""$ac_cv_type_off_t" 1>&6
+if test $ac_cv_type_off_t = no; then
+  cat >> confdefs.h <<\EOF
+#define off_t int
+EOF
+
+fi
+
+echo $ac_n "checking for mode_t""... $ac_c" 1>&6
+echo "configure:4588: checking for mode_t" >&5
+if eval "test \"`echo '$''{'ac_cv_type_mode_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4593 "configure"
+#include "confdefs.h"
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
+EOF
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])mode_t[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_mode_t=yes
 else
-  echo "configure: failed program was:" >&5
-  cat conftest.$ac_ext >&5
-  rm -fr conftest*
-  ac_cv_sizeof_long=0
-fi
-rm -fr conftest*
+  rm -rf conftest*
+  ac_cv_type_mode_t=no
 fi
+rm -f conftest*
 
 fi
-echo "$ac_t""$ac_cv_sizeof_long" 1>&6
-cat >> confdefs.h <<EOF
-#define SIZEOF_LONG $ac_cv_sizeof_long
+echo "$ac_t""$ac_cv_type_mode_t" 1>&6
+if test $ac_cv_type_mode_t = no; then
+  cat >> confdefs.h <<\EOF
+#define mode_t u_short
 EOF
 
+fi
 
-echo $ac_n "checking size of void *""... $ac_c" 1>&6
-echo "configure:3361: checking size of void *" >&5
-if eval "test \"`echo '$''{'ac_cv_sizeof_void_p'+set}'`\" = set"; then
+echo $ac_n "checking for fd_mask""... $ac_c" 1>&6
+echo "configure:4621: checking for fd_mask" >&5
+if eval "test \"`echo '$''{'ac_cv_type_fd_mask'+set}'`\" = set"; then
   echo $ac_n "(cached) $ac_c" 1>&6
-else
-  if test "$cross_compiling" = yes; then
-    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
 else
   cat > conftest.$ac_ext <<EOF
-#line 3369 "configure"
+#line 4626 "configure"
 #include "confdefs.h"
-#include <stdio.h>
-main()
-{
-  FILE *f=fopen("conftestval", "w");
-  if (!f) exit(1);
-  fprintf(f, "%d\n", sizeof(void *));
-  exit(0);
-}
+#include <sys/types.h>
+#if STDC_HEADERS
+#include <stdlib.h>
+#include <stddef.h>
+#endif
 EOF
-if { (eval echo configure:3380: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
-then
-  ac_cv_sizeof_void_p=`cat conftestval`
+if (eval "$ac_cpp conftest.$ac_ext") 2>&5 |
+  egrep "(^|[^a-zA-Z_0-9])fd_mask[^a-zA-Z_0-9]" >/dev/null 2>&1; then
+  rm -rf conftest*
+  ac_cv_type_fd_mask=yes
 else
-  echo "configure: failed program was:" >&5
-  cat conftest.$ac_ext >&5
-  rm -fr conftest*
-  ac_cv_sizeof_void_p=0
-fi
-rm -fr conftest*
+  rm -rf conftest*
+  ac_cv_type_fd_mask=no
 fi
+rm -f conftest*
 
 fi
-echo "$ac_t""$ac_cv_sizeof_void_p" 1>&6
-cat >> confdefs.h <<EOF
-#define SIZEOF_VOID_P $ac_cv_sizeof_void_p
+echo "$ac_t""$ac_cv_type_fd_mask" 1>&6
+if test $ac_cv_type_fd_mask = no; then
+  cat >> confdefs.h <<\EOF
+#define fd_mask int
 EOF
 
+fi
 
 
 # The Ultrix 4.2 mips builtin alloca declared by alloca.h only works
 # for constant arguments.  Useless!
 echo $ac_n "checking for working alloca.h""... $ac_c" 1>&6
-echo "configure:3403: checking for working alloca.h" >&5
+echo "configure:4657: checking for working alloca.h" >&5
 if eval "test \"`echo '$''{'ac_cv_header_alloca_h'+set}'`\" = set"; then
   echo $ac_n "(cached) $ac_c" 1>&6
 else
   cat > conftest.$ac_ext <<EOF
-#line 3408 "configure"
+#line 4662 "configure"
 #include "confdefs.h"
 #include <alloca.h>
 int main() {
 char *p = alloca(2 * sizeof(int));
 ; return 0; }
 EOF
-if { (eval echo configure:3415: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext}; then
+if { (eval echo configure:4669: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext}; then
   rm -rf conftest*
   ac_cv_header_alloca_h=yes
 else
