     }
 
     storeAppendPrintf(sentry, "\t%s:\n", label);
-    storeAppendPrintf(sentry, "\t\tMax: %"PRId64"\n", max_bytes);
+    storeAppendPrintf(sentry, "\t\tMax: %" PRId64 "\n", max_bytes);
     storeAppendPrintf(sentry, "\t\tRestore: %d\n", restore_bps);
 }
 
 void
 DelaySpec::dump (StoreEntry *entry) const
 {
-    storeAppendPrintf(entry, " %d/%"PRId64"", restore_bps, max_bytes);
+    storeAppendPrintf(entry, " %d/%" PRId64 "", restore_bps, max_bytes);
 }
 
 void
