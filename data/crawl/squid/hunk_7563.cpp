     storeAppendPrintf(sentry, close_bracket);
 }
 
-void parameter_get(obj, sentry)
+static void parameter_get(obj, sentry)
      cacheinfo *obj;
      StoreEntry *sentry;
 {
