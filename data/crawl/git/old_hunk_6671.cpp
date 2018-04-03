	}
	logmoved = log;

	lock = lock_ref_sha1_basic(newref, NULL, 0, NULL);
	if (!lock) {
		error("unable to lock %s for update", newref);
		goto rollback;
	}

	lock->force_write = 1;
	hashcpy(lock->old_sha1, orig_sha1);
	if (write_ref_sha1(lock, orig_sha1, logmsg)) {
		error("unable to write current sha1 into %s", newref);
		goto rollback;
	}

	return 0;

