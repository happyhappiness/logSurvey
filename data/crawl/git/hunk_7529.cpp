 static const char write_tree_usage[] =
 "git-write-tree [--missing-ok] [--prefix=<prefix>/]";
 
-int write_tree(unsigned char *sha1, int missing_ok, const char *prefix)
-{
-	int entries, was_valid, newfd;
-
-	/* We can't free this memory, it becomes part of a linked list parsed atexit() */
-	struct lock_file *lock_file = xcalloc(1, sizeof(struct lock_file));
-
-	newfd = hold_locked_index(lock_file, 1);
-
-	entries = read_cache();
-	if (entries < 0)
-		die("git-write-tree: error reading cache");
-
-	if (!active_cache_tree)
-		active_cache_tree = cache_tree();
-
-	was_valid = cache_tree_fully_valid(active_cache_tree);
-
-	if (!was_valid) {
-		if (cache_tree_update(active_cache_tree,
-				      active_cache, active_nr,
-				      missing_ok, 0) < 0)
-			die("git-write-tree: error building trees");
-		if (0 <= newfd) {
-			if (!write_cache(newfd, active_cache, active_nr) &&
-			    !commit_lock_file(lock_file))
-				newfd = -1;
-		}
-		/* Not being able to write is fine -- we are only interested
-		 * in updating the cache-tree part, and if the next caller
-		 * ends up using the old index with unupdated cache-tree part
-		 * it misses the work we did here, but that is just a
-		 * performance penalty and not a big deal.
-		 */
-	}
-
-	if (prefix) {
-		struct cache_tree *subtree =
-			cache_tree_find(active_cache_tree, prefix);
-		if (!subtree)
-			die("git-write-tree: prefix %s not found", prefix);
-		hashcpy(sha1, subtree->sha1);
-	}
-	else
-		hashcpy(sha1, active_cache_tree->sha1);
-
-	if (0 <= newfd)
-		rollback_lock_file(lock_file);
-
-	return 0;
-}
-
 int cmd_write_tree(int argc, const char **argv, const char *unused_prefix)
 {
 	int missing_ok = 0, ret;
 	const char *prefix = NULL;
 	unsigned char sha1[20];
+	const char *me = "git-write-tree";
 
 	git_config(git_default_config);
 	while (1 < argc) {
