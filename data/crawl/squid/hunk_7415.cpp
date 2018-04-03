 void
 fatal(const char *message)
 {
+    /* check for store_rebuilding flag because fatal() is often
+     * used in early initialization phases, long before we ever
+     * get to the store log. */
+    if (!store_rebuilding)
+	storeWriteCleanLog();
     fatal_common(message);
     exit(1);
 }