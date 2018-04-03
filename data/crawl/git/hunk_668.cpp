 }
 
 /*
- * Register the specified ref_store to be the one that should be used
- * for submodule. It is a fatal error to call this function twice for
- * the same submodule.
+ * Associate a ref store with a name. It is a fatal error to call this
+ * function twice for the same name.
  */
-static void register_submodule_ref_store(struct ref_store *refs,
-					 const char *submodule)
+static void register_ref_store_map(struct hashmap *map,
+				   const char *type,
+				   struct ref_store *refs,
+				   const char *name)
 {
-	if (!submodule_ref_stores.tablesize)
-		hashmap_init(&submodule_ref_stores, submodule_hash_cmp, 0);
+	if (!map->tablesize)
+		hashmap_init(map, ref_store_hash_cmp, 0);
 
-	if (hashmap_put(&submodule_ref_stores,
-			alloc_submodule_hash_entry(submodule, refs)))
-		die("BUG: ref_store for submodule '%s' initialized twice",
-		    submodule);
+	if (hashmap_put(map, alloc_ref_store_hash_entry(name, refs)))
+		die("BUG: %s ref_store '%s' initialized twice", type, name);
 }
 
 struct ref_store *get_submodule_ref_store(const char *submodule)
