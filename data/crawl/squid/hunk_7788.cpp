 	regcomp \
 	regexec \
 	regfree \
+	seteuid \
+	setresuid \
 	setrlimit \
 	strdup \
 	strerror \
 	sysconf \
 	syslog \
-	timegm\
+	timegm \
 )
 
+AC_MSG_CHECKING(Maximum number of filedescriptors we can open)
+AC_TRY_RUN([
+#include <unistd.h>
+#include <sys/param.h>
+#include <sys/resource.h>
+main() {
+	int i,j;
+#if HAVE_SETRLIMIT
+    struct rlimit rl;
+#if defined(RLIMIT_NOFILE)
+    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
+        perror("getrlimit: RLIMIT_NOFILE");
+    } else {
+        rl.rlim_cur = rl.rlim_max;      /* set it to the max */
+        if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
+            perror("setrlimit: RLIMIT_NOFILE");
+        }
+    }
+#elif defined(RLIMIT_OFILE)
+    if (getrlimit(RLIMIT_OFILE, &rl) < 0) {
+        perror("getrlimit: RLIMIT_OFILE");
+    } else {
+        rl.rlim_cur = rl.rlim_max;      /* set it to the max */
+        if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
+            perror("setrlimit: RLIMIT_OFILE");
+        }
+    }
+#endif /* RLIMIT_NOFILE */
+#endif /* HAVE_SETRLIMIT */
+#if HAVE_SYSCONF && defined(_SC_OPEN_MAX)
+        i = sysconf(_SC_OPEN_MAX);
+#elif HAVE_GETDTABLESIZE
+        i = getdtablesize();
+#elif defined(OPEN_MAX)
+        i = OPEN_MAX;
+#elif defined(NOFILE)
+        i = NOFILE;
+#elif defined(_NFILE)
+        i = _NFILE;
+#else
+	while((j=open("/dev/null", 0)) > 0) i=j;
+#endif
+	fprintf (fopen("conftestval", "w"), "%d\n", i);
+	exit(0);
+}
+],
+SQUID_FD_SETSIZE=`cat conftestval`,
+SQUID_FD_SETSIZE=256,
+SQUID_FD_SETSIZE=256)
+AC_MSG_RESULT($SQUID_FD_SETSIZE)
+AC_DEFINE_UNQUOTED(SQUID_FD_SETSIZE, $SQUID_FD_SETSIZE)
+
 dnl Need the debugging version of malloc if available
 XTRA_OBJS=''
 if test "$HAVE_LIBMALLOC" = "yes" ; then
