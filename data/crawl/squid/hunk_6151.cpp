 	Biggest_FD);
     storeAppendPrintf(sentry, "\tNumber of file desc currently in use: %4d\n",
 	Number_FD);
+    storeAppendPrintf(sentry, "\tFiles queued for open:                %4d\n",
+	Opening_FD);
     storeAppendPrintf(sentry, "\tAvailable number of file descriptors: %4d\n",
 	fdNFree());
     storeAppendPrintf(sentry, "\tReserved number of file descriptors:  %4d\n",
