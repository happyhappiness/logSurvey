     storeAppendPrintf(sentry, "Pending operations: %d\n", diskdinfo->away);
 }
 
+static void 
+storeDiskdDirParseQ1(SwapDir * sd, const char *name, const char *value, int reconfiguring)
+{
+    diskdinfo_t *diskdinfo = sd->fsdata;
+    int old_magic1 = diskdinfo->magic1;
+    diskdinfo->magic1 = atoi(value);
+    if (reconfiguring && old_magic1 != diskdinfo->magic1)
+	debug(3, 1) ("cache_dir '%s' new Q1 value '%d'\n", diskdinfo->magic1);
+}
+
+static void 
+storeDiskdDirParseQ2(SwapDir * sd, const char *name, const char *value, int reconfiguring)
+{
+    diskdinfo_t *diskdinfo = sd->fsdata;
+    int old_magic2 = diskdinfo->magic2;
+    diskdinfo->magic2 = atoi(value);
+    if (reconfiguring && old_magic2 != diskdinfo->magic2)
+	debug(3, 1) ("cache_dir '%s' new Q2 value '%d'\n", diskdinfo->magic2);
+}
+
+struct cache_dir_option options[] =
+{
+#if NOT_YET
+    {"L1", storeDiskdDirParseL1},
+    {"L2", storeDiskdDirParseL2},
+#endif
+    {"Q1", storeDiskdDirParseQ1},
+    {"Q2", storeDiskdDirParseQ2},
+    {NULL, NULL}
+};
+
 /*
  * storeDiskdDirReconfigure
  *
