 	Squid_MaxFD - Number_FD);
     storeAppendPrintf(sentry, "\tReserved number of file descriptors:  %4d\n",
 	RESERVED_FD);
+    storeAppendPrintf(sentry, "\tDisk files open:                      %4d\n",
+	open_disk_fd);
 
     storeAppendPrintf(sentry, "Internal Data Structures:\n");
     storeAppendPrintf(sentry, "\t%6d StoreEntries\n",
