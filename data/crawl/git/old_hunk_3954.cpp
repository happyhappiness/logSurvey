		die_if_unmerged_cache(reset_type);

	if (reset_type != SOFT) {
		int err = reset_index_file(sha1, reset_type, quiet);
		if (reset_type == KEEP && !err)
			err = reset_index_file(sha1, MIXED, quiet);
		if (err)
			die(_("Could not reset index file to revision '%s'."), rev);
	}