 ipcacheStatPrint(ipcache_entry * i, StoreEntry * sentry)
 {
     int k;
+    int count = i->addrs.count;
+    char buf[MAX_IPSTRLEN];
+
+    if(!sentry) {
+        debugs(14, 0, HERE << "CRITICAL: sentry is NULL!");
+    }
+
+    if(!i) {
+        debugs(14, 0, HERE << "CRITICAL: ipcache_entry is NULL!");
+        storeAppendPrintf(sentry, "CRITICAL ERROR\n");
+        return;
+    }
+
     storeAppendPrintf(sentry, " %-32.32s %c%c %6d %6d %2d(%2d)",
                       hashKeyStr(&i->hash),
                       i->flags.fromhosts ? 'H' : ' ',
