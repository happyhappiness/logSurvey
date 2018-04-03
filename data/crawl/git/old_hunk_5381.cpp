	/* Soft reset does not touch the index file nor the working tree
	 * at all, but requires them in a good order.  Other resets reset
	 * the index file to the tree object we are switching to. */
	if (reset_type == SOFT) {
		if (is_merge() || read_cache() < 0 || unmerged_cache())
			die("Cannot do a soft reset in the middle of a merge.");
	} else {
		int err = reset_index_file(sha1, reset_type, quiet);
		if (reset_type == KEEP)
			err = err || reset_index_file(sha1, MIXED, quiet);
		if (err)
