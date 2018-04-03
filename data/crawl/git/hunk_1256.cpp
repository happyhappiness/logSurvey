 
 	hold_locked_index(lock_file, 1);
 	if (read_cache_preload(NULL) < 0)
-		return error(_("corrupt index file"));
+		return error(_("index file corrupt"));
 
 	resolve_undo_clear();
 	if (opts->force) {
