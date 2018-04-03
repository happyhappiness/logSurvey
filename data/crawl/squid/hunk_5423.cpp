     if (spec.restore_bps == -1)
 	return;
     storeAppendPrintf(sentry, "\t\tCurrent: ");
-    if (!buckets.size()) {
+    if (!buckets.head) {
 	storeAppendPrintf (sentry, "Not used yet.\n\n");
 	return;
     }
-    iterator pos = buckets.begin();
-    while (pos != buckets.end()) {
-	(*pos)->stats(sentry);
-	++pos;
-    }
+    buckets.head->walk(DelayUserStatsWalkee, sentry);
     storeAppendPrintf(sentry, "\n\n");
 }
 
