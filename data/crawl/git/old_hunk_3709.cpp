
	if (!dont_change_ref)
		if (write_ref_sha1(lock, sha1, msg) < 0)
			die_errno("Failed to write ref");

	strbuf_release(&ref);
	free(real_ref);