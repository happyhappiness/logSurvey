	return 0;

 rollback:
	lock = lock_ref_sha1_basic(oldrefname, NULL, NULL, NULL, 0, NULL);
	if (!lock) {
		error("unable to lock %s for rollback", oldrefname);
		goto rollbacklog;
	}
