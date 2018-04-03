 		die_errno("unable to fdopen packed-refs descriptor");
 
 	fprintf_or_die(out, "%s", PACKED_REFS_HEADER);
-	do_for_each_entry_in_dir(get_packed_ref_dir(packed_ref_cache),
-				 write_packed_entry_fn, out);
+
+	iter = cache_ref_iterator_begin(packed_ref_cache->cache, NULL, 0);
+	while ((ok = ref_iterator_advance(iter)) == ITER_OK) {
+		struct object_id peeled;
+		int peel_error = ref_iterator_peel(iter, &peeled);
+
+		write_packed_entry(out, iter->refname, iter->oid->hash,
+				   peel_error ? NULL : peeled.hash);
+	}
+
+	if (ok != ITER_DONE)
+		die("error while iterating over references");
 
 	if (commit_lock_file(packed_ref_cache->lock)) {
 		save_errno = errno;