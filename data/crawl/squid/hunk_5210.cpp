     for (i = 0; i < Config.cacheSwap.n_configured; i++) {
         storeAppendPrintf(sentry, "\n");
         SD = INDEXSD(i);
-        storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type,
+        storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type(),
                           storeSwapDir(i));
         storeAppendPrintf(sentry, "FS Block Size %d Bytes\n",
                           SD->fs.blksize);
