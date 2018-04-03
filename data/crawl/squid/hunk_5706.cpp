     storeAppendPrintf(sentry, "aborted_requests = %f/sec\n",
 	XAVG(aborted_requests));
 
-#if HAVE_POLL
+#if USE_POLL
     storeAppendPrintf(sentry, "syscalls.polls = %f/sec\n", XAVG(syscalls.polls));
-#else
+#endif
+#if USE_SELECT
     storeAppendPrintf(sentry, "syscalls.selects = %f/sec\n", XAVG(syscalls.selects));
 #endif
     storeAppendPrintf(sentry, "syscalls.disk.opens = %f/sec\n", XAVG(syscalls.disk.opens));
