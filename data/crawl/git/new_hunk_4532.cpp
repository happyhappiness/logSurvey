		if (reset_type == KEEP)
			err = err || reset_index_file(sha1, MIXED, quiet);
		if (err)
			die(_("Could not reset index file to revision '%s'."), rev);
	}

	/* Any resets update HEAD to the head being switched to,