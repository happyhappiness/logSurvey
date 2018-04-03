	 */
	lock = lock_ref_sha1_basic(refname, sha1, NULL, NULL, 0, &type, &err);
	if (!lock) {
		error("%s", err.buf);
		strbuf_release(&err);
		return error("cannot lock ref '%s'", refname);
	}
	if (!reflog_exists(refname)) {
		unlock_ref(lock);