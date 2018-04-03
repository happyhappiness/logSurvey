 	return 0;
 }
 
+int lock_packed_refs(int flags)
+{
+	struct packed_ref_cache *packed_ref_cache;
+
+	/* Discard the old cache because it might be invalid: */
+	clear_packed_ref_cache(&ref_cache);
+	if (hold_lock_file_for_update(&packlock, git_path("packed-refs"), flags) < 0)
+		return -1;
+	/* Read the current packed-refs while holding the lock: */
+	packed_ref_cache = get_packed_ref_cache(&ref_cache);
+	packed_ref_cache->lock = &packlock;
+	return 0;
+}
+
+int commit_packed_refs(void)
+{
+	struct packed_ref_cache *packed_ref_cache =
+		get_packed_ref_cache(&ref_cache);
+	int error = 0;
+
+	if (!packed_ref_cache->lock)
+		die("internal error: packed-refs not locked");
+	write_or_die(packed_ref_cache->lock->fd,
+		     PACKED_REFS_HEADER, strlen(PACKED_REFS_HEADER));
+
+	do_for_each_entry_in_dir(get_packed_ref_dir(packed_ref_cache),
+				 0, write_packed_entry_fn,
+				 &packed_ref_cache->lock->fd);
+	if (commit_lock_file(packed_ref_cache->lock))
+		error = -1;
+	packed_ref_cache->lock = NULL;
+	return error;
+}
+
+void rollback_packed_refs(void)
+{
+	struct packed_ref_cache *packed_ref_cache =
+		get_packed_ref_cache(&ref_cache);
+
+	if (!packed_ref_cache->lock)
+		die("internal error: packed-refs not locked");
+	rollback_lock_file(packed_ref_cache->lock);
+	packed_ref_cache->lock = NULL;
+	clear_packed_ref_cache(&ref_cache);
+}
+
 struct ref_to_prune {
 	struct ref_to_prune *next;
 	unsigned char sha1[20];
