     debug(20, 3, "storePurgeMem: Freeing memory-copy of %s\n", e->key);
     if (e->mem_obj == NULL)
 	return;
-
     if (storeEntryLocked(e)) {
-	debug(20, 0, "storePurgeMem: someone (storeGetMemSpace?) is purging a locked object?\n");
+	debug(20, 0, "storePurgeMem: someone is purging a locked object?\n");
 	debug(20, 0, "%s", storeToString(e));
 	fatal_dump(NULL);
     }
-    destroy_MemObjectData(e->mem_obj);
-    e->mem_obj->data = NULL;
-    debug(20, 8, "storePurgeMem: Freeing %d in-memory bytes\n",
-	e->object_len);
-    debug(20, 8, "storePurgeMem: store_mem_size = %d\n", store_mem_size);
     storeSetMemStatus(e, NOT_IN_MEMORY);
-    e->mem_obj->e_current_len = 0;
-    /* free up pending list table */
-    safe_free(e->mem_obj->pending);
-    e->mem_obj->pending_list_size = 0;
-    /* free up client list table and entries */
-    if (e->mem_obj->client_list) {
-	int i;
-	for (i = 0; i < e->mem_obj->client_list_size; ++i) {
-	    if (e->mem_obj->client_list[i])
-		safe_free(e->mem_obj->client_list[i]);
-	}
-	safe_free(e->mem_obj->client_list);
-    }
     destroy_MemObject(e->mem_obj);
     e->mem_obj = NULL;
 }
 
 /* lock the object for reading, start swapping in if necessary */
-int storeLockObject(e)
+/* Called by:
+ * icp_hit_or_miss()
+ * storeAbort()
+ * {http,ftp,gopher,wais}Start()
+ */
+int storeLockObject(e, handler, data)
      StoreEntry *e;
+     SIH handler;
+     void *data;
 {
     int swap_in_stat = 0;
     int status = 0;
