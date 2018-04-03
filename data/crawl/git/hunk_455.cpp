 	files_assert_main_repository(refs, "commit_packed_refs");
 
 	if (!packed_ref_cache->lock)
-		die("internal error: packed-refs not locked");
+		die("BUG: packed-refs not locked");
 
 	out = fdopen_lock_file(packed_ref_cache->lock, "w");
 	if (!out)
