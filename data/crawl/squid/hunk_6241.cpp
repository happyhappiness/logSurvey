 fi
 rm -f conftest*
 
+echo $ac_n "checking if inet_ntoa() actually works""... $ac_c" 1>&6
+echo "configure:4438: checking if inet_ntoa() actually works" >&5
+if test "$cross_compiling" = yes; then
+  INET_NTOA_RESULT="broken"
+else
+  cat > conftest.$ac_ext <<EOF
+#line 4443 "configure"
+#include "confdefs.h"
+
+#include <stdlib.h>
+#include <stdio.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+main ()
+{
+	struct in_addr in;
+	in.s_addr = inet_addr("1.2.3.4");
+        fprintf (fopen("conftestval", "w"), "%s\n", inet_ntoa(in));
+	exit(0);
+}
+
+EOF
+if { (eval echo configure:4460: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
+then
+  INET_NTOA_RESULT=`cat conftestval`
+else
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
+  rm -fr conftest*
+  INET_NTOA_RESULT="broken"
+fi
+rm -fr conftest*
+fi
+
+if test "$INET_NTOA_RESULT" = "1.2.3.4" ; then
+	echo "$ac_t"""yes"" 1>&6
+else
+	echo "$ac_t"""no"" 1>&6
+	echo "WARNING: This looks bad, and probably prevents Squid from working."
+	echo "         If you're on IRIX and using GCC 2.8, you probably need"
+	echo "         to use the IRIX C compiler instead."
+	sleep 10
+fi
+
 XTRA_OBJS=''
 if test "$ac_cv_lib_malloc_main" = "yes" ; then
 	if test -r /usr/lib/debug/malloc.o ; then
