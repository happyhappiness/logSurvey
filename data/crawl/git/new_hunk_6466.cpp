		die("Not a valid branch point: '%s'.", start_name);
	hashcpy(sha1, commit->object.sha1);

	lock = lock_any_ref_for_update(ref.buf, NULL, 0);
	if (!lock)
		die("Failed to lock ref for update: %s.", strerror(errno));

