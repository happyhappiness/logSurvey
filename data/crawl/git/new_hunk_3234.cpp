
	logmoved = log;

	lock = lock_ref_sha1_basic(newrefname, NULL, NULL, NULL, 0, NULL);
	if (!lock) {
		error("unable to lock %s for update", newrefname);
		goto rollback;
