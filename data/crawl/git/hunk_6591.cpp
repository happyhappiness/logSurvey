 	int ret;
 	struct lock_file *lock_file = xcalloc(1, sizeof(struct lock_file));
 	int newfd = hold_locked_index(lock_file, 1);
-	read_cache();
+
+	if (read_cache() < 0)
+		return error("corrupt index file");
 
 	if (opts->force) {
 		ret = reset_tree(new->commit->tree, opts, 1);