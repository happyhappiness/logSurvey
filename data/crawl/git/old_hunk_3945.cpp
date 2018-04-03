	if (reset_type != SOFT) {
		struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
		int newfd = hold_locked_index(lock, 1);
		int err = reset_index(sha1, reset_type, quiet);
		if (reset_type == KEEP && !err)
			err = reset_index(sha1, MIXED, quiet);
		if (err)
			die(_("Could not reset index file to revision '%s'."), rev);

		if (reset_type == MIXED) /* Report what has not been updated. */
			update_index_refresh(
