 
 static int read_tree_some(struct tree *tree, const char **pathspec)
 {
-	int newfd;
-	struct lock_file *lock_file = xcalloc(1, sizeof(struct lock_file));
-	newfd = hold_locked_index(lock_file, 1);
-	read_cache();
-
 	read_tree_recursive(tree, "", 0, 0, pathspec, update_some);
 
-	if (write_cache(newfd, active_cache, active_nr) ||
-	    commit_locked_index(lock_file))
-		die("unable to write new index file");
-
 	/* update the index with the given tree's info
 	 * for all args, expanding wildcards, and exit
 	 * with any non-zero return code.
 	 */
 	return 0;
 }
 
-static int checkout_paths(const char **pathspec)
+static int checkout_paths(struct tree *source_tree, const char **pathspec)
 {
 	int pos;
 	struct checkout state;
