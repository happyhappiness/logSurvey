
	lock = lock_ref_sha1_basic(newrefname, NULL, NULL, NULL, 0, NULL, &err);
	if (!lock) {
		error("%s", err.buf);
		strbuf_release(&err);
		error("unable to lock %s for update", newrefname);
		goto rollback;
	}
	hashcpy(lock->old_sha1, orig_sha1);
