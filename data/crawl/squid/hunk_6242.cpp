 AC_DEFINE(LIBRESOLV_DNS_TTL_HACK)],
 AC_MSG_RESULT(no))
 
+AC_MSG_CHECKING(if inet_ntoa() actually works)
+AC_TRY_RUN([
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
+],
+INET_NTOA_RESULT=`cat conftestval`,
+INET_NTOA_RESULT="broken",
+INET_NTOA_RESULT="broken")
+if test "$INET_NTOA_RESULT" = "1.2.3.4" ; then
+	AC_MSG_RESULT("yes")
+else
+	AC_MSG_RESULT("no")
+	echo "WARNING: This looks bad, and probably prevents Squid from working."
+	echo "         If you're on IRIX and using GCC 2.8, you probably need"
+	echo "         to use the IRIX C compiler instead."
+	sleep 10
+fi
+
 dnl Need the debugging version of malloc if available
 XTRA_OBJS=''
 if test "$ac_cv_lib_malloc_main" = "yes" ; then