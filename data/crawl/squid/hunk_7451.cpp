 }
 
 static void
-parameter_get(cacheinfo * obj, StoreEntry * sentry)
+parameter_get(const cacheinfo *obj, StoreEntry *sentry)
 {
     storeAppendPrintf(sentry, open_bracket);
     storeAppendPrintf(sentry,
