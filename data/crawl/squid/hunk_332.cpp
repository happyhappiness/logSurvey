 
 #if HAVE_SETRLIMIT && defined(RLIMIT_VMEM) && !_SQUID_CYGWIN_
     if (getrlimit(RLIMIT_VMEM, &rl) < 0) {
-        debugs(50, DBG_CRITICAL, "getrlimit: RLIMIT_VMEM: " << xstrerror());
+        int xerrno = errno;
+        debugs(50, DBG_CRITICAL, "getrlimit: RLIMIT_VMEM: " << xstrerr(xerrno));
     } else if (rl.rlim_max > rl.rlim_cur) {
         rl.rlim_cur = rl.rlim_max;  /* set it to the max */
 
         if (setrlimit(RLIMIT_VMEM, &rl) < 0) {
-            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_VMEM: %s", xstrerror());
+            xerrno = errno;
+            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_VMEM: %s", xstrerr(xerrno));
             fatal_dump(tmp_error_buf);
         }
     }
