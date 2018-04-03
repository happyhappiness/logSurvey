	if (fast_forward_to(index_tree, remote_tree, 0))
		return -1;

	memset(&pathspec, 0, sizeof(pathspec));

	lock_file = xcalloc(1, sizeof(struct lock_file));
	hold_locked_index(lock_file, 1);

	if (read_tree(remote_tree, 0, &pathspec)) {
		rollback_lock_file(lock_file);
		return -1;
	}

	if (write_locked_index(&the_index, lock_file, COMMIT_LOCK))
		die(_("unable to write new index file"));

	remove_branch_state();

