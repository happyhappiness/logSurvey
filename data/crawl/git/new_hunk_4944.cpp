	       result, sha1_to_hex(result_sha1));
	return result;
}

int notes_merge_commit(struct notes_merge_options *o,
		       struct notes_tree *partial_tree,
		       struct commit *partial_commit,
		       unsigned char *result_sha1)
{
	/*
	 * Iterate through files in .git/NOTES_MERGE_WORKTREE and add all
	 * found notes to 'partial_tree'. Write the updates notes tree to
	 * the DB, and commit the resulting tree object while reusing the
	 * commit message and parents from 'partial_commit'.
	 * Finally store the new commit object SHA1 into 'result_sha1'.
	 */
	struct dir_struct dir;
	const char *path = git_path(NOTES_MERGE_WORKTREE "/");
	int path_len = strlen(path), i;
	const char *msg = strstr(partial_commit->buffer, "\n\n");

	OUTPUT(o, 3, "Committing notes in notes merge worktree at %.*s",
	       path_len - 1, path);

	if (!msg || msg[2] == '\0')
		die("partial notes commit has empty message");
	msg += 2;

	memset(&dir, 0, sizeof(dir));
	read_directory(&dir, path, path_len, NULL);
	for (i = 0; i < dir.nr; i++) {
		struct dir_entry *ent = dir.entries[i];
		struct stat st;
		const char *relpath = ent->name + path_len;
		unsigned char obj_sha1[20], blob_sha1[20];

		if (ent->len - path_len != 40 || get_sha1_hex(relpath, obj_sha1)) {
			OUTPUT(o, 3, "Skipping non-SHA1 entry '%s'", ent->name);
			continue;
		}

		/* write file as blob, and add to partial_tree */
		if (stat(ent->name, &st))
			die_errno("Failed to stat '%s'", ent->name);
		if (index_path(blob_sha1, ent->name, &st, 1))
			die("Failed to write blob object from '%s'", ent->name);
		if (add_note(partial_tree, obj_sha1, blob_sha1, NULL))
			die("Failed to add resolved note '%s' to notes tree",
			    ent->name);
		OUTPUT(o, 4, "Added resolved note for object %s: %s",
		       sha1_to_hex(obj_sha1), sha1_to_hex(blob_sha1));
	}

	create_notes_commit(partial_tree, partial_commit->parents, msg,
			    result_sha1);
	OUTPUT(o, 4, "Finalized notes merge commit: %s",
	       sha1_to_hex(result_sha1));
	return 0;
}

int notes_merge_abort(struct notes_merge_options *o)
{
	/* Remove .git/NOTES_MERGE_WORKTREE directory and all files within */
	struct strbuf buf = STRBUF_INIT;
	int ret;

	strbuf_addstr(&buf, git_path(NOTES_MERGE_WORKTREE));
	OUTPUT(o, 3, "Removing notes merge worktree at %s", buf.buf);
	ret = remove_dir_recursively(&buf, 0);
	strbuf_release(&buf);
	return ret;
}
