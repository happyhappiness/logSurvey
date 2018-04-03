{
	/*
	 * Iterate through files in .git/NOTES_MERGE_WORKTREE and add all
	 * found notes to 'partial_tree'. Write the updates notes tree to
	 * the DB, and commit the resulting tree object while reusing the
	 * commit message and parents from 'partial_commit'.
	 * Finally store the new commit object SHA1 into 'result_sha1'.
	 */
	struct dir_struct dir;
	char *path = xstrdup(git_path(NOTES_MERGE_WORKTREE "/"));
	int path_len = strlen(path), i;
	char *msg = strstr(partial_commit->buffer, "\n\n");
	struct strbuf sb_msg = STRBUF_INIT;

	if (o->verbosity >= 3)
		printf("Committing notes in notes merge worktree at %.*s\n",
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
			if (o->verbosity >= 3)
				printf("Skipping non-SHA1 entry '%s'\n",
								ent->name);
			continue;
		}

		/* write file as blob, and add to partial_tree */
		if (stat(ent->name, &st))
			die_errno("Failed to stat '%s'", ent->name);
		if (index_path(blob_sha1, ent->name, &st, HASH_WRITE_OBJECT))
			die("Failed to write blob object from '%s'", ent->name);
		if (add_note(partial_tree, obj_sha1, blob_sha1, NULL))
			die("Failed to add resolved note '%s' to notes tree",
			    ent->name);
		if (o->verbosity >= 4)
			printf("Added resolved note for object %s: %s\n",
				sha1_to_hex(obj_sha1), sha1_to_hex(blob_sha1));
	}

	strbuf_attach(&sb_msg, msg, strlen(msg), strlen(msg) + 1);
