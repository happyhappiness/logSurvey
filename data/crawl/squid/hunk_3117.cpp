 AC_MSG_RESULT($DEFAULT_FD_SETSIZE)
 AC_DEFINE_UNQUOTED(DEFAULT_FD_SETSIZE, $DEFAULT_FD_SETSIZE, [Default FD_SETSIZE value])
 ])
+
+
+dnl checks the maximum number of filedescriptor we can open
+dnl sets shell var squid_filedescriptors_num
+
+AC_DEFUN([SQUID_CHECK_MAXFD],[
+AC_MSG_CHECKING(Maximum number of filedescriptors we can open)
+dnl damn! FreeBSD pthreads break dup2().
+SQUID_STATE_SAVE(maxfd)
+  case $host in
+  i386-unknown-freebsd*)
+      if echo "$LDFLAGS" | grep -q pthread; then
+  	LDFLAGS=`echo $LDFLAGS | sed -e "s/-pthread//"`
+      fi
+  esac
+  AC_RUN_IFELSE([AC_LANG_SOURCE([[
+#include <stdio.h>
+#include <unistd.h>
+#include <stdlib.h>
+#include <sys/time.h>	/* needed on FreeBSD */
+#include <sys/param.h>
+#include <sys/resource.h>
+int main(int argc, char **argv) {
+	FILE *fp;
+	int i,j;
+#if defined(__CYGWIN32__) || defined (__CYGWIN__)
+    /* getrlimit and sysconf returns bogous values on cygwin32.
+     * Number of fds is virtually unlimited in cygwin (sys/param.h)
+     * __CYGWIN32__ is deprecated.
+     */
+    i = NOFILE;
+#else
+#if HAVE_SETRLIMIT
+    struct rlimit rl;
+#if defined(RLIMIT_NOFILE)
+    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
+        perror("getrlimit: RLIMIT_NOFILE");
+    } else {
+#if defined(__APPLE__)
+        /* asking for more than OPEN_MAX fails on Leopard */
+        rl.rlim_cur = (OPEN_MAX < rl.rlim_max ? OPEN_MAX : rl.rlim_max);
+#else
+        rl.rlim_cur = rl.rlim_max;      /* set it to the max */
+#endif
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
+	/* by starting at 2^14, we will never get higher
+	than 2^15 for squid_filedescriptors_num */
+        i = j = 1<<14;
+        while (j) {
+                j >>= 1;
+                if (dup2(0, i) < 0) { 
+                        i -= j;
+                } else {
+                        close(i);
+                        i += j;
+                }
+        }
+        i++;
+#endif /* IF !DEF CYGWIN */
+	fp = fopen("conftestval", "w");
+	fprintf (fp, "%d\n", i & ~0x3F);
+	return 0;
+}
+  ]])],[squid_filedescriptors_num=`cat conftestval`],[squid_filedescriptors_num=256],[squid_filedescriptors_num=256])
+  dnl Microsoft MSVCRT.DLL supports 2048 maximum FDs
+  case "$host_os" in
+  mingw|mingw32)
+    squid_filedescriptors_num="2048"
+    ;;
+  esac
+  AC_MSG_RESULT($squid_filedescriptors_num)
+SQUID_STATE_ROLLBACK(maxfd)
+
+if test `expr $squid_filedescriptors_num % 64` != 0; then
+    AC_MSG_WARN([$squid_filedescriptors_num is not an multiple of 64. This may cause issues on certain platforms.])
+fi
+])
