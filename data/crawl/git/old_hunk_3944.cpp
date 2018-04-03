		die(_("%s reset is not allowed in a bare repository"),
		    _(reset_type_names[reset_type]));

	if (pathspec) {
		struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
		int index_fd = hold_locked_index(lock, 1);
		if (read_from_tree(pathspec, sha1))
			return 1;
		update_index_refresh(
			quiet ? REFRESH_QUIET : REFRESH_IN_PORCELAIN);
		if (write_cache(index_fd, active_cache, active_nr) ||
		    commit_locked_index(lock))
			return error("Could not write new index file.");
		return 0;
	}

	/* Soft reset does not touch the index file nor the working tree
	 * at all, but requires them in a good order.  Other resets reset
	 * the index file to the tree object we are switching to. */
