	if (is_null_oid(&threeway[1]) || is_null_oid(&threeway[2]))
		return error(_("path '%s' does not have necessary versions"), path);

	read_mmblob(&ancestor, threeway[0].hash);
	read_mmblob(&ours, threeway[1].hash);
	read_mmblob(&theirs, threeway[2].hash);

	/*
	 * NEEDSWORK: re-create conflicts from merges with
