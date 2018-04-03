 static void
 redirectStats(StoreEntry * sentry)
 {
+    if (redirectors == NULL) {
+        storeAppendPrintf(sentry, "No redirectors defined\n");
+        return;
+    }
+
     storeAppendPrintf(sentry, "Redirector Statistics:\n");
     helperStats(sentry, redirectors);
 