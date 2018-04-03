     coss_index_pool = memPoolCreate("COSS index data", sizeof(CossIndexNode));
     initialised = true;
 }
+
+static void
+storeCossStats(StoreEntry * sentry)
+{
+    const char *tbl_fmt = "%10s %10d %10d %10d\n";
+    storeAppendPrintf(sentry, "\n                   OPS     SUCCESS        FAIL\n");
+    storeAppendPrintf(sentry, tbl_fmt,
+                      "open", coss_stats.open.ops, coss_stats.open.success, coss_stats.open.fail);
+    storeAppendPrintf(sentry, tbl_fmt,
+                      "create", coss_stats.create.ops, coss_stats.create.success, coss_stats.create.fail);
+    storeAppendPrintf(sentry, tbl_fmt,
+                      "close", coss_stats.close.ops, coss_stats.close.success, coss_stats.close.fail);
+    storeAppendPrintf(sentry, tbl_fmt,
+                      "unlink", coss_stats.unlink.ops, coss_stats.unlink.success, coss_stats.unlink.fail);
+    storeAppendPrintf(sentry, tbl_fmt,
+                      "read", coss_stats.read.ops, coss_stats.read.success, coss_stats.read.fail);
+    storeAppendPrintf(sentry, tbl_fmt,
+                      "write", coss_stats.write.ops, coss_stats.write.success, coss_stats.write.fail);
+    storeAppendPrintf(sentry, tbl_fmt,
+                      "s_write", coss_stats.stripe_write.ops, coss_stats.stripe_write.success, coss_stats.stripe_write.fail);
+
+    storeAppendPrintf(sentry, "\n");
+    storeAppendPrintf(sentry, "stripes:          %d\n", coss_stats.stripes);
+    storeAppendPrintf(sentry, "alloc.alloc:      %d\n", coss_stats.alloc.alloc);
+    storeAppendPrintf(sentry, "alloc.realloc:    %d\n", coss_stats.alloc.realloc);
+    storeAppendPrintf(sentry, "alloc.collisions: %d\n", coss_stats.alloc.collisions);
+    storeAppendPrintf(sentry, "disk_overflows:   %d\n", coss_stats.disk_overflows);
+    storeAppendPrintf(sentry, "stripe_overflows: %d\n", coss_stats.stripe_overflows);
+    storeAppendPrintf(sentry, "open_mem_hits:    %d\n", coss_stats.open_mem_hits);
+    storeAppendPrintf(sentry, "open_mem_misses:  %d\n", coss_stats.open_mem_misses);
+}
