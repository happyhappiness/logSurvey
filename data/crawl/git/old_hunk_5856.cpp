
	lock = lock_any_ref_for_update(ref.buf, NULL, 0);
	if (!lock)
		die("Failed to lock ref for update: %s.", strerror(errno));

	if (reflog)
		log_all_ref_updates = 1;
