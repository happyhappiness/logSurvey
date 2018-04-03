     return store_table;
 }
 
-/*
- * if object is in memory, also insert into in_mem_table
- */
+static void storeHashMemInsert(e)
+     StoreEntry *e;
+{
+    hash_insert(in_mem_table, e->key, e);
+    meta_data.hot_vm++;
+}
+
+static void storeHashMemDelete(e)
+     StoreEntry *e;
+{
+    hash_link *hptr = hash_lookup(in_mem_table, e->key);
+    if (hptr == NULL)
+	fatal_dump("storeHashMemDelete: key not found");
+    hash_delete_link(in_mem_table, hptr);
+    meta_data.hot_vm--;
+}
 
 static int storeHashInsert(e)
      StoreEntry *e;
 {
     debug(20, 3, "storeHashInsert: Inserting Entry %p key '%s'\n",
 	e, e->key);
     if (e->mem_status == IN_MEMORY)
-	hash_insert(in_mem_table, e->key, e);
-    return (hash_join(store_table, (hash_link *) e));
+	storeHashMemInsert(e);
+    return hash_join(store_table, (hash_link *) e);
 }
 
-/*
- * if object in memory, also remove from in_mem_table
- */
-
 static int storeHashDelete(e)
      StoreEntry *e;
 {
-    hash_link *hptr = NULL;
-    if (e->mem_status == IN_MEMORY && e->key) {
-	if ((hptr = hash_lookup(in_mem_table, e->key)))
-	    hash_delete_link(in_mem_table, hptr);
-    }
-    return (hash_remove_link(store_table, (hash_link *) e));
+    if (e->mem_status == IN_MEMORY)
+	storeHashMemDelete(e);
+    return hash_remove_link(store_table, (hash_link *) e);
 }
 
 /*
  * maintain the in-mem hash table according to the changes of mem_status
  * This routine replaces the instruction "e->store_status = status;"
  */
-
 void storeSetMemStatus(e, status)
      StoreEntry *e;
      mem_status_t status;
 {
-    hash_link *ptr = NULL;
-
     if (e->key == NULL)
 	fatal_dump("storeSetMemStatus: NULL key");
-
-    if (status != IN_MEMORY && e->mem_status == IN_MEMORY) {
-	if ((ptr = hash_lookup(in_mem_table, e->key)))
-	    hash_delete_link(in_mem_table, ptr);
-    } else if (status == IN_MEMORY && e->mem_status != IN_MEMORY) {
-	hash_insert(in_mem_table, e->key, e);
-    }
+    if (status != IN_MEMORY && e->mem_status == IN_MEMORY)
+	storeHashMemDelete(e);
+    else if (status == IN_MEMORY && e->mem_status != IN_MEMORY)
+	storeHashMemInsert(e);
     e->mem_status = status;
 }
 
