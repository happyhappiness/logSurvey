			       "", &diff_opts);
	diffcore_std(&diff_opts);

	/* It is either one entry that says "modified", or "created",
	 * or nothing.
	 */
	if (!diff_queued_diff.nr) {
		/* The path is the same as parent */
		porigin = get_origin(sb, parent, origin->path);
		hashcpy(porigin->blob_sha1, origin->blob_sha1);
	}
	else if (diff_queued_diff.nr != 1)
		die("internal error in blame::find_origin");
	else {
		struct diff_filepair *p = diff_queued_diff.queue[0];
		switch (p->status) {
		default:
			die("internal error in blame::find_origin (%c)",
