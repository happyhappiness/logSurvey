 EOF
 
 
-if test "$ac_cv_func_snprintf" = "yes" ; then
-  echo $ac_n "checking what snprintf() returns when truncating""... $ac_c" 1>&6
-echo "configure:4133: checking what snprintf() returns when truncating" >&5
-  if test "$cross_compiling" = yes; then
-  SNPRINTF_TRUNC_RET=-1
-else
-  cat > conftest.$ac_ext <<EOF
-#line 4138 "configure"
-#include "confdefs.h"
-
-  #include <stdio.h>
-  main ()
-  {
-        char buf[10];
-	int x;
-        x = snprintf(buf, 10, "ABCDEFGHIJKLM");
-        fprintf (fopen("conftestval", "w"), "%d\n", x);
-	exit(0);
-  }
-  
-EOF
-if { (eval echo configure:4152: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
-then
-  SNPRINTF_TRUNC_RET=`cat conftestval`
-else
-  echo "configure: failed program was:" >&5
-  cat conftest.$ac_ext >&5
-  rm -fr conftest*
-  SNPRINTF_TRUNC_RET=-1
-fi
-rm -fr conftest*
-fi
-
-  echo "$ac_t""$SNPRINTF_TRUNC_RET" 1>&6
-fi
-
 echo $ac_n "checking if sys_errlist is already defined""... $ac_c" 1>&6
-echo "configure:4168: checking if sys_errlist is already defined" >&5
+echo "configure:4133: checking if sys_errlist is already defined" >&5
 if eval "test \"`echo '$''{'ac_cv_needs_sys_errlist'+set}'`\" = set"; then
   echo $ac_n "(cached) $ac_c" 1>&6
 else
   cat > conftest.$ac_ext <<EOF
-#line 4173 "configure"
+#line 4138 "configure"
 #include "confdefs.h"
 #include <stdio.h>
 int main() {
 char *s = sys_errlist0;
 ; return 0; }
 EOF
-if { (eval echo configure:4180: \"$ac_compile\") 1>&5; (eval $ac_compile) 2>&5; }; then
+if { (eval echo configure:4145: \"$ac_compile\") 1>&5; (eval $ac_compile) 2>&5; }; then
   rm -rf conftest*
   ac_cv_needs_sys_errlist="no"
 else
