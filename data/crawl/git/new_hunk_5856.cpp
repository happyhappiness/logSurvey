
	lock = lock_any_ref_for_update(ref.buf, NULL, 0);
	if (!lock)
		die_errno("Failed to lock ref for update");

	if (reflog)
		log_all_ref_updates = 1;
