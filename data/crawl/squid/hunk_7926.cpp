 void storePurgeMem(e)
      StoreEntry *e;
 {
-    debug(0, 5, "storePurgeMem: Freeing memory-copy of %s\n", e->url);
+    debug(20, 5, "storePurgeMem: Freeing memory-copy of %s\n", e->url);
     if (!has_mem_obj(e))
 	return;
 
     if (storeEntryLocked(e)) {
-	debug(0, 0, "storePurgeMem: someone (storeGetMemSpace?) is purging a locked object?\n");
-	debug(0, 0, "%s", storeToString(e));
+	debug(20, 0, "storePurgeMem: someone (storeGetMemSpace?) is purging a locked object?\n");
+	debug(20, 0, "%s", storeToString(e));
 	fatal_dump(NULL);
     }
     /* free up memory data */
