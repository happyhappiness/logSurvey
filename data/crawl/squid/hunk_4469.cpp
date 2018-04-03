                       XAVG(aborted_requests));
 
 #if USE_POLL
-
-    storeAppendPrintf(sentry, "syscalls.polls = %f/sec\n", XAVG(syscalls.polls));
-#endif
-#if defined(USE_SELECT) || defined(USE_SELECT_WIN32)
-
+    storeAppendPrintf(sentry, "syscalls.polls = %f/sec\n", XAVG(syscalls.selects));
+#elif defined(USE_SELECT) || defined(USE_SELECT_WIN32)
     storeAppendPrintf(sentry, "syscalls.selects = %f/sec\n", XAVG(syscalls.selects));
 #endif
 
