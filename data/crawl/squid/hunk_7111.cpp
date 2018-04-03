 #endif /* HAVE_MALLINFO */
 
     storeAppendPrintf(sentry, "{File descriptor usage for %s:}\n", appname);
-    storeAppendPrintf(sentry, "{\tMax number of file desc available:    %4d}\n",
+    storeAppendPrintf(sentry, "{\tMaximum number of file descriptors:   %4d}\n",
 	Squid_MaxFD);
     storeAppendPrintf(sentry, "{\tLargest file desc currently in use:   %4d}\n",
 	Biggest_FD);
+    storeAppendPrintf(sentry, "{\tNumber of file desc currently in use: %4d}\n",
+	Number_FD);
     storeAppendPrintf(sentry, "{\tAvailable number of file descriptors: %4d}\n",
-	fdstat_are_n_free_fd(0));
+	Squid_MaxFD - Number_FD);
     storeAppendPrintf(sentry, "{\tReserved number of file descriptors:  %4d}\n",
 	RESERVED_FD);
 
