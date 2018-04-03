 	debug(3, 1) ("cache_dir '%s' new Q2 value '%d'\n", diskdinfo->magic2);
 }
 
+static void
+storeDiskdDirDumpQ2(StoreEntry * e, const char *option, SwapDir *sd)
+{
+    diskdinfo_t *diskdinfo = sd->fsdata;
+    storeAppendPrintf(e, " Q2=%d", diskdinfo->magic2);
+}
+
 struct cache_dir_option options[] =
 {
 #if NOT_YET
-    {"L1", storeDiskdDirParseL1},
-    {"L2", storeDiskdDirParseL2},
+    {"L1", storeDiskdDirParseL1, storeDiskdDirDumpL1},
+    {"L2", storeDiskdDirParseL2, storeDiskdDirDumpL2},
 #endif
-    {"Q1", storeDiskdDirParseQ1},
-    {"Q2", storeDiskdDirParseQ2},
+    {"Q1", storeDiskdDirParseQ1, storeDiskdDirDumpQ1},
+    {"Q2", storeDiskdDirParseQ2, storeDiskdDirDumpQ2},
     {NULL, NULL}
 };
 
