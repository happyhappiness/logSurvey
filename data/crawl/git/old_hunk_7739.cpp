	OPT_END()
};

static char *prepare_index(const char **files, const char *prefix)
{
	int fd;
	struct tree *tree;
	struct lock_file *next_index_lock;

	if (interactive) {
		interactive_add();
		return get_index_file();
	}

	fd = hold_locked_index(&lock_file, 1);
	if (read_cache() < 0)
		die("index file corrupt");

	if (all || also) {
		add_files_to_cache(verbose, also ? prefix : NULL, files);
		refresh_cache(REFRESH_QUIET);
		if (write_cache(fd, active_cache, active_nr) || close(fd))
			die("unable to write new_index file");
		return lock_file.filename;
	}

	if (*files == NULL) {
		/* Commit index as-is. */
		rollback_lock_file(&lock_file);
		return get_index_file();
	}

	/* update the user index file */
	add_files_to_cache(verbose, prefix, files);
	refresh_cache(REFRESH_QUIET);
	if (write_cache(fd, active_cache, active_nr) || close(fd))
		die("unable to write new_index file");

	if (!initial_commit) {
		tree = parse_tree_indirect(head_sha1);
		if (!tree)
			die("failed to unpack HEAD tree object");
		if (read_tree(tree, 0, NULL))
			die("failed to read HEAD tree object");
	}

	/* Use a lock file to garbage collect the temporary index file. */
	next_index_lock = xmalloc(sizeof(*next_index_lock));
	fd = hold_lock_file_for_update(next_index_lock,
				       git_path("next-index-%d", getpid()), 1);
	add_files_to_cache(verbose, prefix, files);
	refresh_cache(REFRESH_QUIET);
	if (write_cache(fd, active_cache, active_nr) || close(fd))
		die("unable to write new_index file");

	return next_index_lock->filename;
}

static int run_status(FILE *fp, const char *index_file, const char *prefix)
