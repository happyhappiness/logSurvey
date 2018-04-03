 	OPT_END()
 };
 
+static void rollback_index_files(void)
+{
+	switch (commit_style) {
+	case COMMIT_AS_IS:
+		break; /* nothing to do */
+	case COMMIT_NORMAL:
+		rollback_lock_file(&index_lock);
+		break;
+	case COMMIT_PARTIAL:
+		rollback_lock_file(&index_lock);
+		rollback_lock_file(&false_lock);
+		break;
+	}
+}
+
+static void commit_index_files(void)
+{
+	switch (commit_style) {
+	case COMMIT_AS_IS:
+		break; /* nothing to do */
+	case COMMIT_NORMAL:
+		commit_lock_file(&index_lock);
+		break;
+	case COMMIT_PARTIAL:
+		commit_lock_file(&index_lock);
+		rollback_lock_file(&false_lock);
+		break;
+	}
+}
+
+/*
+ * Take a union of paths in the index and the named tree (typically, "HEAD"),
+ * and return the paths that match the given pattern in list.
+ */
+static int list_paths(struct path_list *list, const char *with_tree,
+		      const char *prefix, const char **pattern)
+{
+	int i;
+	char *m;
+
+	for (i = 0; pattern[i]; i++)
+		;
+	m = xcalloc(1, i);
+
+	if (with_tree)
+		overlay_tree_on_cache(with_tree, prefix);
+
+	for (i = 0; i < active_nr; i++) {
+		struct cache_entry *ce = active_cache[i];
+		if (ce->ce_flags & htons(CE_UPDATE))
+			continue;
+		if (!pathspec_match(pattern, m, ce->name, 0))
+			continue;
+		path_list_insert(ce->name, list);
+	}
+
+	return report_path_error(m, pattern, prefix ? strlen(prefix) : 0);
+}
+
+static void add_remove_files(struct path_list *list)
+{
+	int i;
+	for (i = 0; i < list->nr; i++) {
+		struct path_list_item *p = &(list->items[i]);
+		if (file_exists(p->path))
+			add_file_to_cache(p->path, 0);
+		else
+			remove_file_from_cache(p->path);
+	}
+}
+
 static char *prepare_index(const char **files, const char *prefix)
 {
 	int fd;
 	struct tree *tree;
-	struct lock_file *next_index_lock;
+	struct path_list partial;
+	const char **pathspec = NULL;
 
 	if (interactive) {
 		interactive_add();
+		commit_style = COMMIT_AS_IS;
 		return get_index_file();
 	}
 
-	fd = hold_locked_index(&lock_file, 1);
 	if (read_cache() < 0)
 		die("index file corrupt");
 
-	if (all || also) {
-		add_files_to_cache(verbose, also ? prefix : NULL, files);
+	if (*files)
+		pathspec = get_pathspec(prefix, files);
+
+	/*
+	 * Non partial, non as-is commit.
+	 *
+	 * (1) get the real index;
+	 * (2) update the_index as necessary;
+	 * (3) write the_index out to the real index (still locked);
+	 * (4) return the name of the locked index file.
+	 *
+	 * The caller should run hooks on the locked real index, and
+	 * (A) if all goes well, commit the real index;
+	 * (B) on failure, rollback the real index.
+	 */
+	if (all || (also && pathspec && *pathspec)) {
+		int fd = hold_locked_index(&index_lock, 1);
+		add_files_to_cache(0, also ? prefix : NULL, pathspec);
 		refresh_cache(REFRESH_QUIET);
 		if (write_cache(fd, active_cache, active_nr) || close(fd))
 			die("unable to write new_index file");
-		return lock_file.filename;
+		commit_style = COMMIT_NORMAL;
+		return index_lock.filename;
 	}
 
-	if (*files == NULL) {
-		/* Commit index as-is. */
-		rollback_lock_file(&lock_file);
+	/*
+	 * As-is commit.
+	 *
+	 * (1) return the name of the real index file.
+	 *
+	 * The caller should run hooks on the real index, and run
+	 * hooks on the real index, and create commit from the_index.
+	 * We still need to refresh the index here.
+	 */
+	if (!pathspec || !*pathspec) {
+		fd = hold_locked_index(&index_lock, 1);
+		refresh_cache(REFRESH_QUIET);
+		if (write_cache(fd, active_cache, active_nr) ||
+		    close(fd) || commit_locked_index(&index_lock))
+			die("unable to write new_index file");
+		commit_style = COMMIT_AS_IS;
 		return get_index_file();
 	}
 
-	/* update the user index file */
-	add_files_to_cache(verbose, prefix, files);
+	/*
+	 * A partial commit.
+	 *
+	 * (0) find the set of affected paths;
+	 * (1) get lock on the real index file;
+	 * (2) update the_index with the given paths;
+	 * (3) write the_index out to the real index (still locked);
+	 * (4) get lock on the false index file;
+	 * (5) reset the_index from HEAD;
+	 * (6) update the_index the same way as (2);
+	 * (7) write the_index out to the false index file;
+	 * (8) return the name of the false index file (still locked);
+	 *
+	 * The caller should run hooks on the locked false index, and
+	 * create commit from it.  Then
+	 * (A) if all goes well, commit the real index;
+	 * (B) on failure, rollback the real index;
+	 * In either case, rollback the false index.
+	 */
+	commit_style = COMMIT_PARTIAL;
+
+	if (file_exists(git_path("MERGE_HEAD")))
+		die("cannot do a partial commit during a merge.");
+
+	memset(&partial, 0, sizeof(partial));
+	partial.strdup_paths = 1;
+	if (list_paths(&partial, initial_commit ? NULL : "HEAD", prefix, pathspec))
+		exit(1);
+
+	discard_cache();
+	if (read_cache() < 0)
+		die("cannot read the index");
+
+	fd = hold_locked_index(&index_lock, 1);
+	add_remove_files(&partial);
 	refresh_cache(REFRESH_QUIET);
 	if (write_cache(fd, active_cache, active_nr) || close(fd))
 		die("unable to write new_index file");
 
+	fd = hold_lock_file_for_update(&false_lock,
+				       git_path("next-index-%d", getpid()), 1);
+	discard_cache();
 	if (!initial_commit) {
 		tree = parse_tree_indirect(head_sha1);
 		if (!tree)
 			die("failed to unpack HEAD tree object");
 		if (read_tree(tree, 0, NULL))
 			die("failed to read HEAD tree object");
 	}
-
-	/* Use a lock file to garbage collect the temporary index file. */
-	next_index_lock = xmalloc(sizeof(*next_index_lock));
-	fd = hold_lock_file_for_update(next_index_lock,
-				       git_path("next-index-%d", getpid()), 1);
-	add_files_to_cache(verbose, prefix, files);
+	add_remove_files(&partial);
 	refresh_cache(REFRESH_QUIET);
-	if (write_cache(fd, active_cache, active_nr) || close(fd))
-		die("unable to write new_index file");
 
-	return next_index_lock->filename;
+	if (write_cache(fd, active_cache, active_nr) || close(fd))
+		die("unable to write temporary index file");
+	return false_lock.filename;
 }
 
 static int run_status(FILE *fp, const char *index_file, const char *prefix)
