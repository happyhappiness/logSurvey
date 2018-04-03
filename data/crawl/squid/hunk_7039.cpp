     StoreEntry *entry = NULL;
     MemObject *mem;
     int N = 0;
+    int i;
+    struct _store_client *sc;
+#if OLD_CODE
     storeAppendPrintf(sentry, open_bracket);
+#endif
     for (entry = storeGetFirst(); entry != NULL; entry = storeGetNext()) {
 	mem = entry->mem_obj;
 	if (vm_or_not && mem == NULL)
 	    continue;
 	if ((++N & 0xFF) == 0) {
 	    debug(18, 3) ("stat_objects_get:  Processed %d objects...\n", N);
 	}
+#if OLD_CODE
 	storeAppendPrintf(sentry, "{%s %dL %-25s %s %3d %2d %8d %s}\n",
 	    describeStatuses(entry),
 	    (int) entry->lock_count,
