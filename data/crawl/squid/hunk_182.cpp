     *var = 0;
 }
 
+static void
+dump_int64_t(StoreEntry * entry, const char *name, int64_t var)
+{
+    storeAppendPrintf(entry, "%s %" PRId64 "\n", name, var);
+}
+
+void
+parse_int64_t(int64_t *var)
+{
+    int64_t i;
+    i = GetInteger64();
+    *var = i;
+}
+
+static void
+free_int64_t(int64_t *var)
+{
+    *var = 0;
+}
+
 static void
 dump_onoff(StoreEntry * entry, const char *name, int var)
 {
