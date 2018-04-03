     return pid;
 }
 
+/* A little piece of glue for odd systems */
+#ifndef RLIMIT_NOFILE
+#ifdef RLIMIT_OFILE
+#define RLIMIT_NOFILE RLIMIT_OFILE
+#endif
+#endif
 
+/** Figure out the number of supported filedescriptors */
 void
 setMaxFD(void)
 {
-#if HAVE_SETRLIMIT
-    /* try to use as many file descriptors as possible */
-    /* System V uses RLIMIT_NOFILE and BSD uses RLIMIT_OFILE */
-
+#if HAVE_SETRLIMIT && defined(RLIMIT_NOFILE)
     struct rlimit rl;
-#if defined(RLIMIT_NOFILE)
-
     if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
-        debugs(50, 0, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
-    } else {
-        rl.rlim_cur = Squid_MaxFD;
-
+        debugs(50, DBG_CRITICAL, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
+    } else if (Config.max_filedescriptors > 0) {
+        rl.rlim_cur = Config.max_filedescriptors;
         if (rl.rlim_cur > rl.rlim_max)
-            Squid_MaxFD = rl.rlim_cur = rl.rlim_max;
-
-        if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
-            snprintf(tmp_error_buf, ERROR_BUF_SZ,
-                     "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
-            fatal_dump(tmp_error_buf);
+            rl.rlim_max = rl.rlim_cur;
+        if (setrlimit(RLIMIT_NOFILE, &rl)) {
+            debugs(50, DBG_CRITICAL, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
+            getrlimit(RLIMIT_NOFILE, &rl);
+            rl.rlim_cur = rl.rlim_max;
+            if (setrlimit(RLIMIT_NOFILE, &rl)) {
+                debugs(50, DBG_CRITICAL, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
+            }
         }
     }
-
-#elif defined(RLIMIT_OFILE)
-    if (getrlimit(RLIMIT_OFILE, &rl) < 0) {
-        debugs(50, 0, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
+    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
+         debugs(50, DBG_CRITICAL, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
     } else {
-        rl.rlim_cur = Squid_MaxFD;
+        Squid_MaxFD = rl.rlim_cur;
+    }
 
-        if (rl.rlim_cur > rl.rlim_max)
-            Squid_MaxFD = rl.rlim_cur = rl.rlim_max;
+#endif /* HAVE_SETRLIMIT */
+}
 
-        if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
-            snprintf(tmp_error_buf, ERROR_BUF_SZ,
-                     "setrlimit: RLIMIT_OFILE: %s", xstrerror());
+void
+setSystemLimits(void)
+{
+#if HAVE_SETRLIMIT && defined(RLIMIT_NOFILE) && !defined(_SQUID_CYGWIN_)
+    /* limit system filedescriptors to our own limit */
+    struct rlimit rl;
+    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
+        debugs(50, DBG_CRITICAL, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
+    } else {
+        rl.rlim_cur = Squid_MaxFD;
+        if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
+            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
             fatal_dump(tmp_error_buf);
         }
     }
-
-#endif
-#else /* HAVE_SETRLIMIT */
-    debugs(21, 1, "setMaxFD: Cannot increase: setrlimit() not supported on this system");
-
 #endif /* HAVE_SETRLIMIT */
 
 #if HAVE_SETRLIMIT && defined(RLIMIT_DATA)
-
     if (getrlimit(RLIMIT_DATA, &rl) < 0) {
-        debugs(50, 0, "getrlimit: RLIMIT_DATA: " << xstrerror());
+        debugs(50, DBG_CRITICAL, "getrlimit: RLIMIT_DATA: " << xstrerror());
     } else if (rl.rlim_max > rl.rlim_cur) {
         rl.rlim_cur = rl.rlim_max;	/* set it to the max */
 
         if (setrlimit(RLIMIT_DATA, &rl) < 0) {
-            snprintf(tmp_error_buf, ERROR_BUF_SZ,
-                     "setrlimit: RLIMIT_DATA: %s", xstrerror());
+            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_DATA: %s", xstrerror());
             fatal_dump(tmp_error_buf);
         }
     }
-
 #endif /* RLIMIT_DATA */
+    if (Config.max_filedescriptors > Squid_MaxFD) {
+        debugs(50, DBG_IMPORTANT, "NOTICE: Could not increase the number of filedescriptors");
+    }
+
 #if HAVE_SETRLIMIT && defined(RLIMIT_VMEM)
     if (getrlimit(RLIMIT_VMEM, &rl) < 0) {
         debugs(50, 0, "getrlimit: RLIMIT_VMEM: " << xstrerror());
     } else if (rl.rlim_max > rl.rlim_cur) {
         rl.rlim_cur = rl.rlim_max;	/* set it to the max */
 
         if (setrlimit(RLIMIT_VMEM, &rl) < 0) {
-            snprintf(tmp_error_buf, ERROR_BUF_SZ,
-                     "setrlimit: RLIMIT_VMEM: %s", xstrerror());
+            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_VMEM: %s", xstrerror());
             fatal_dump(tmp_error_buf);
         }
     }
-
 #endif /* RLIMIT_VMEM */
 }
 