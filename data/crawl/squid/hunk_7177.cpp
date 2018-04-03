     storeAppendPrintf(sentry, close_bracket);
 }
 
-static void
-parameter_get(const cacheinfo * obj, StoreEntry * sentry)
+void
+parameter_get(StoreEntry * sentry)
 {
     storeAppendPrintf(sentry, open_bracket);
     storeAppendPrintf(sentry,
