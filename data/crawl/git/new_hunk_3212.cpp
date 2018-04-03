	 */
	lock = lock_ref_sha1_basic(refname, sha1, NULL, NULL, 0, &type, &err);
	if (!lock) {
		error("cannot lock ref '%s': %s", refname, err.buf);
		strbuf_release(&err);
		return -1;
	}
	if (!reflog_exists(refname)) {
		unlock_ref(lock);