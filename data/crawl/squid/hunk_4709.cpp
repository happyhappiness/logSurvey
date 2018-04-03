     }
 
     storeAppendPrintf(sentry, "\n");
-    storeAppendPrintf(sentry, "WAIS I/O\n");
-    storeAppendPrintf(sentry, "number of reads: %d\n", IOStats.Wais.reads);
-    storeAppendPrintf(sentry, "Read Histogram:\n");
-
-    for (i = 0; i < 16; i++) {
-        storeAppendPrintf(sentry, "%5d-%5d: %9d %2d%%\n",
-                          i ? (1 << (i - 1)) + 1 : 1,
-                          1 << i,
-                          IOStats.Wais.read_hist[i],
-                          percent(IOStats.Wais.read_hist[i], IOStats.Wais.reads));
-    }
 }
 
 static const char *
