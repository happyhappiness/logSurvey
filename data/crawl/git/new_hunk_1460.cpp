	if (is_null_oid(&threeway[1]) || is_null_oid(&threeway[2]))
		return error(_("path '%s' does not have necessary versions"), path);

	read_mmblob(&ancestor, &threeway[0]);
	read_mmblob(&ours, &threeway[1]);
	read_mmblob(&theirs, &threeway[2]);

	/*
	 * NEEDSWORK: re-create conflicts from merges with
