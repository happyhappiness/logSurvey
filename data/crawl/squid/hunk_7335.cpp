     storeAppendPrintf(sentry, "{\tMax number of file desc available:    %4d}\n",
 	Squid_MaxFD);
     storeAppendPrintf(sentry, "{\tLargest file desc currently in use:   %4d}\n",
-	fdstat_biggest_fd());
+	Biggest_FD);
     storeAppendPrintf(sentry, "{\tAvailable number of file descriptors: %4d}\n",
 	fdstat_are_n_free_fd(0));
     storeAppendPrintf(sentry, "{\tReserved number of file descriptors:  %4d}\n",
