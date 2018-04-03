 fi
 
 
-AC_CHECK_SIZEOF_SYSTYPE(off_t, 4)
-AC_CHECK_SIZEOF_SYSTYPE(size_t, 4)
+echo $ac_n "checking size of off_t""... $ac_c" 1>&6
+echo "configure:5962: checking size of off_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_off_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+  ac_cv_sizeof_off_t=4
+else
+  cat > conftest.$ac_ext <<EOF
+#line 5970 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+#if HAVE_STDINT_H
+#include <stdint.h>
+#endif
+#if HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+int main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) return(1);
+  fprintf(f, "%d\n", sizeof(off_t));
+  return(0);
+}
+EOF
+if { (eval echo configure:5987: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_off_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_off_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_off_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_OFF_T $ac_cv_sizeof_off_t
+EOF
+
+
+echo $ac_n "checking size of size_t""... $ac_c" 1>&6
+echo "configure:6007: checking size of size_t" >&5
+if eval "test \"`echo '$''{'ac_cv_sizeof_size_t'+set}'`\" = set"; then
+  echo $ac_n "(cached) $ac_c" 1>&6
+else
+  if test "$cross_compiling" = yes; then
+  ac_cv_sizeof_size_t=4
+else
+  cat > conftest.$ac_ext <<EOF
+#line 6015 "configure"
+#include "confdefs.h"
+#include <stdio.h>
+#if HAVE_STDINT_H
+#include <stdint.h>
+#endif
+#if HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+int main()
+{
+  FILE *f=fopen("conftestval", "w");
+  if (!f) return(1);
+  fprintf(f, "%d\n", sizeof(size_t));
+  return(0);
+}
+EOF
+if { (eval echo configure:6032: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext} && (./conftest; exit) 2>/dev/null
+then
+  ac_cv_sizeof_size_t=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  ac_cv_sizeof_size_t=0
+fi
+rm -fr conftest*
+fi
+
+fi
+echo "$ac_t""$ac_cv_sizeof_size_t" 1>&6
+cat >> confdefs.h <<EOF
+#define SIZEOF_SIZE_T $ac_cv_sizeof_size_t
+EOF
+
+
 
 # The Ultrix 4.2 mips builtin alloca declared by alloca.h only works
 # for constant arguments.  Useless!
 echo $ac_n "checking for working alloca.h""... $ac_c" 1>&6
-echo "configure:5527: checking for working alloca.h" >&5
+echo "configure:6055: checking for working alloca.h" >&5
 if eval "test \"`echo '$''{'ac_cv_header_alloca_h'+set}'`\" = set"; then
   echo $ac_n "(cached) $ac_c" 1>&6
 else
   cat > conftest.$ac_ext <<EOF
-#line 5532 "configure"
+#line 6060 "configure"
 #include "confdefs.h"
 #include <alloca.h>
 int main() {
 char *p = alloca(2 * sizeof(int));
 ; return 0; }
 EOF
-if { (eval echo configure:5539: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext}; then
+if { (eval echo configure:6067: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest${ac_exeext}; then
   rm -rf conftest*
   ac_cv_header_alloca_h=yes
 else
