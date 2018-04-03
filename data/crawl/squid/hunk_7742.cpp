 	    p->transferbyte);
     }
 
-    storeAppendPrintf(sentry, "}\n");
+    storeAppendPrintf(sentry, close_bracket);
+}
+
+void stat_io_get(sentry)
+     StoreEntry *sentry;
+{
+    int i;
+
+    storeAppendPrintf(sentry, open_bracket);
+    storeAppendPrintf(sentry, "{HTTP I/O}\n");
+    storeAppendPrintf(sentry, "{number of reads: %d}\n", IOStats.Http.reads);
+    storeAppendPrintf(sentry, "{deferred reads: %d (%d%%)}\n",
+	IOStats.Http.reads_deferred,
+	percent(IOStats.Http.reads_deferred, IOStats.Http.reads));
+    storeAppendPrintf(sentry, "{Read Histogram:}\n");
+    for (i = 0; i < 16; i++) {
+	storeAppendPrintf(sentry, "{%5d-%5d: %9d %2d%%}\n",
+	    i ? (1 << (i - 1)) + 1 : 1,
+	    1 << i,
+	    IOStats.Http.read_hist[i],
+	    percent(IOStats.Http.read_hist[i], IOStats.Http.reads));
+    }
+
+    storeAppendPrintf(sentry, "{}\n");
+    storeAppendPrintf(sentry, "{FTP I/O}\n");
+    storeAppendPrintf(sentry, "{number of reads: %d}\n", IOStats.Ftp.reads);
+    storeAppendPrintf(sentry, "{deferred reads: %d (%d%%)}\n",
+	IOStats.Ftp.reads_deferred,
+	percent(IOStats.Ftp.reads_deferred, IOStats.Ftp.reads));
+    storeAppendPrintf(sentry, "{Read Histogram:}\n");
+    for (i = 0; i < 16; i++) {
+	storeAppendPrintf(sentry, "{%5d-%5d: %9d %2d%%}\n",
+	    i ? (1 << (i - 1)) + 1 : 1,
+	    1 << i,
+	    IOStats.Ftp.read_hist[i],
+	    percent(IOStats.Ftp.read_hist[i], IOStats.Ftp.reads));
+    }
+
+    storeAppendPrintf(sentry, close_bracket);
 }
 
 
