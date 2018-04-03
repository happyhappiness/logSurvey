     storeAppendPrintf(sentry, " ");
 }
 
-void log_disable(obj, sentry)
+static void log_disable(obj, sentry)
      cacheinfo *obj;
      StoreEntry *sentry;
 {
