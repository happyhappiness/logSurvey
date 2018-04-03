		setup_tracking(name, real_ref, track);

	if (write_ref_sha1(lock, sha1, msg) < 0)
		die("Failed to write ref: %s.", strerror(errno));

	strbuf_release(&ref);
	free(real_ref);
