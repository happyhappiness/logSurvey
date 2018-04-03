 	diff_tree_release_paths(&opt);
 }
 
+static void check_notes_merge_worktree(struct notes_merge_options *o)
+{
+	if (!o->has_worktree) {
+		/*
+		 * Must establish NOTES_MERGE_WORKTREE.
+		 * Abort if NOTES_MERGE_WORKTREE already exists
+		 */
+		if (file_exists(git_path(NOTES_MERGE_WORKTREE))) {
+			if (advice_resolve_conflict)
+				die("You have not concluded your previous "
+				    "notes merge (%s exists).\nPlease, use "
+				    "'git notes merge --commit' or 'git notes "
+				    "merge --reset' to commit/abort the "
+				    "previous merge before you start a new "
+				    "notes merge.", git_path("NOTES_MERGE_*"));
+			else
+				die("You have not concluded your notes merge "
+				    "(%s exists).", git_path("NOTES_MERGE_*"));
+		}
+
+		if (safe_create_leading_directories(git_path(
+				NOTES_MERGE_WORKTREE "/.test")))
+			die_errno("unable to create directory %s",
+				  git_path(NOTES_MERGE_WORKTREE));
+		o->has_worktree = 1;
+	} else if (!file_exists(git_path(NOTES_MERGE_WORKTREE)))
+		/* NOTES_MERGE_WORKTREE should already be established */
+		die("missing '%s'. This should not happen",
+		    git_path(NOTES_MERGE_WORKTREE));
+}
+
+static void write_buf_to_worktree(const unsigned char *obj,
+				  const char *buf, unsigned long size)
+{
+	int fd;
+	char *path = git_path(NOTES_MERGE_WORKTREE "/%s", sha1_to_hex(obj));
+	if (safe_create_leading_directories(path))
+		die_errno("unable to create directory for '%s'", path);
+	if (file_exists(path))
+		die("found existing file at '%s'", path);
+
+	fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0666);
+	if (fd < 0)
+		die_errno("failed to open '%s'", path);
+
+	while (size > 0) {
+		long ret = write_in_full(fd, buf, size);
+		if (ret < 0) {
+			/* Ignore epipe */
+			if (errno == EPIPE)
+				break;
+			die_errno("notes-merge");
+		} else if (!ret) {
+			die("notes-merge: disk full?");
+		}
+		size -= ret;
+		buf += ret;
+	}
+
+	close(fd);
+}
+
+static void write_note_to_worktree(const unsigned char *obj,
+				   const unsigned char *note)
+{
+	enum object_type type;
+	unsigned long size;
+	void *buf = read_sha1_file(note, &type, &size);
+
+	if (!buf)
+		die("cannot read note %s for object %s",
+		    sha1_to_hex(note), sha1_to_hex(obj));
+	if (type != OBJ_BLOB)
+		die("blob expected in note %s for object %s",
+		    sha1_to_hex(note), sha1_to_hex(obj));
+	write_buf_to_worktree(obj, buf, size);
+	free(buf);
+}
+
+static int ll_merge_in_worktree(struct notes_merge_options *o,
+				struct notes_merge_pair *p)
+{
+	mmbuffer_t result_buf;
+	mmfile_t base, local, remote;
+	int status;
+
+	read_mmblob(&base, p->base);
+	read_mmblob(&local, p->local);
+	read_mmblob(&remote, p->remote);
+
+	status = ll_merge(&result_buf, sha1_to_hex(p->obj), &base, NULL,
+			  &local, o->local_ref, &remote, o->remote_ref, 0);
+
+	free(base.ptr);
+	free(local.ptr);
+	free(remote.ptr);
+
+	if ((status < 0) || !result_buf.ptr)
+		die("Failed to execute internal merge");
+
+	write_buf_to_worktree(p->obj, result_buf.ptr, result_buf.size);
+	free(result_buf.ptr);
+
+	return status;
+}
+
+static int merge_one_change_manual(struct notes_merge_options *o,
+				   struct notes_merge_pair *p,
+				   struct notes_tree *t)
+{
+	const char *lref = o->local_ref ? o->local_ref : "local version";
+	const char *rref = o->remote_ref ? o->remote_ref : "remote version";
+
+	trace_printf("\t\t\tmerge_one_change_manual(obj = %.7s, base = %.7s, "
+	       "local = %.7s, remote = %.7s)\n",
+	       sha1_to_hex(p->obj), sha1_to_hex(p->base),
+	       sha1_to_hex(p->local), sha1_to_hex(p->remote));
+
+	OUTPUT(o, 2, "Auto-merging notes for %s", sha1_to_hex(p->obj));
+	check_notes_merge_worktree(o);
+	if (is_null_sha1(p->local)) {
+		/* D/F conflict, checkout p->remote */
+		assert(!is_null_sha1(p->remote));
+		OUTPUT(o, 1, "CONFLICT (delete/modify): Notes for object %s "
+		       "deleted in %s and modified in %s. Version from %s "
+		       "left in tree.", sha1_to_hex(p->obj), lref, rref, rref);
+		write_note_to_worktree(p->obj, p->remote);
+	} else if (is_null_sha1(p->remote)) {
+		/* D/F conflict, checkout p->local */
+		assert(!is_null_sha1(p->local));
+		OUTPUT(o, 1, "CONFLICT (delete/modify): Notes for object %s "
+		       "deleted in %s and modified in %s. Version from %s "
+		       "left in tree.", sha1_to_hex(p->obj), rref, lref, lref);
+		write_note_to_worktree(p->obj, p->local);
+	} else {
+		/* "regular" conflict, checkout result of ll_merge() */
+		const char *reason = "content";
+		if (is_null_sha1(p->base))
+			reason = "add/add";
+		assert(!is_null_sha1(p->local));
+		assert(!is_null_sha1(p->remote));
+		OUTPUT(o, 1, "CONFLICT (%s): Merge conflict in notes for "
+		       "object %s", reason, sha1_to_hex(p->obj));
+		ll_merge_in_worktree(o, p);
+	}
+
+	trace_printf("\t\t\tremoving from partial merge result\n");
+	remove_note(t, p->obj);
+
+	return 1;
+}
+
 static int merge_one_change(struct notes_merge_options *o,
 			    struct notes_merge_pair *p, struct notes_tree *t)
 {
 	/*
-	 * Return 0 if change was resolved (and added to notes_tree),
-	 * 1 if conflict
+	 * Return 0 if change is successfully resolved (stored in notes_tree).
+	 * Return 1 is change results in a conflict (NOT stored in notes_tree,
+	 * but instead written to NOTES_MERGE_WORKTREE with conflict markers).
 	 */
 	switch (o->strategy) {
 	case NOTES_MERGE_RESOLVE_MANUAL:
-		return 1;
+		return merge_one_change_manual(o, p, t);
 	case NOTES_MERGE_RESOLVE_OURS:
 		OUTPUT(o, 2, "Using local notes for %s", sha1_to_hex(p->obj));
 		/* nothing to do */
