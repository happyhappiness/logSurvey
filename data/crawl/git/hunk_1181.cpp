  */
 static void rollback_packed_refs(void)
 {
+	struct files_ref_store *refs =
+		get_files_ref_store(NULL, "rollback_packed_refs");
 	struct packed_ref_cache *packed_ref_cache =
-		get_packed_ref_cache(&ref_store);
+		get_packed_ref_cache(refs);
 
 	if (!packed_ref_cache->lock)
 		die("internal error: packed-refs not locked");
 	rollback_lock_file(packed_ref_cache->lock);
 	packed_ref_cache->lock = NULL;
 	release_packed_ref_cache(packed_ref_cache);
-	clear_packed_ref_cache(&ref_store);
+	clear_packed_ref_cache(refs);
 }
 
 struct ref_to_prune {
