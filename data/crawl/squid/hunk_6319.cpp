     storeAppendPrintf(sentry, "\n");
     storeAppendPrintf(sentry, "FTP I/O\n");
     storeAppendPrintf(sentry, "number of reads: %d\n", IOStats.Ftp.reads);
-    storeAppendPrintf(sentry, "deferred reads: %d (%d%%)\n",
-	IOStats.Ftp.reads_deferred,
-	percent(IOStats.Ftp.reads_deferred, IOStats.Ftp.reads));
     storeAppendPrintf(sentry, "Read Histogram:\n");
     for (i = 0; i < 16; i++) {
 	storeAppendPrintf(sentry, "%5d-%5d: %9d %2d%%\n",
