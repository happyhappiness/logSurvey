     return n;
 }
 
-void redirectStats(sentry)
-     StoreEntry *sentry;
+void
+redirectStats(StoreEntry * sentry)
 {
     int k;
     storeAppendPrintf(sentry, open_bracket);
