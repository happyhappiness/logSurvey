 
 
 
+echo $ac_n "checking Default FD_SETSIZE value""... $ac_c" 1>&6
+echo "configure:2889: checking Default FD_SETSIZE value" >&5
+if test "$cross_compiling" = yes; then
+  DEFAULT_FD_SETSIZE=256
+else
+  cat > conftest.$ac_ext <<EOF
+#line 2894 "configure"
+#include "confdefs.h"
+
+#if HAVE_STDIO_H
+#include <stdio.h>
+#endif
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+#if HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
+#if HAVE_SYS_SELECT_H
+#include <sys/select.h>
+#endif
+#if HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+main() {
+	fprintf (fopen("conftestval", "w"), "%d\n", FD_SETSIZE);
+	exit(0);
+}
+
+EOF
+if { (eval echo configure:2918: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
+then
+  DEFAULT_FD_SETSIZE=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  DEFAULT_FD_SETSIZE=256
+fi
+rm -fr conftest*
+fi
+
+echo "$ac_t""$DEFAULT_FD_SETSIZE" 1>&6
+cat >> confdefs.h <<EOF
+#define DEFAULT_FD_SETSIZE $DEFAULT_FD_SETSIZE
+EOF
+
+
 echo $ac_n "checking Maximum number of filedescriptors we can open""... $ac_c" 1>&6
-echo "configure:2935: checking Maximum number of filedescriptors we can open" >&5
+echo "configure:2937: checking Maximum number of filedescriptors we can open" >&5
 if test "$cross_compiling" = yes; then
   SQUID_MAXFD=256
 else
   cat > conftest.$ac_ext <<EOF
-#line 2940 "configure"
+#line 2942 "configure"
 #include "confdefs.h"
 
 #include <stdio.h>
