	 * reference itself, plus we might need to update the
	 * reference if --updateref was specified:
	 */
	lock = lock_ref_sha1_basic(refname, sha1, NULL, NULL, 0, &type);
	if (!lock)
		return error("cannot lock ref '%s'", refname);
	if (!reflog_exists(refname)) {
		unlock_ref(lock);
		return 0;