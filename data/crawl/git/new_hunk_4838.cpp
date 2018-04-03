
	fclose(fp);

	/*
	 * Reject an attempt to record a non-merge empty commit without
	 * explicit --allow-empty. In the cherry-pick case, it may be
	 * empty due to conflict resolution, which the user should okay.
	 */
	if (!commitable && whence != FROM_MERGE && !allow_empty &&
	    !(amend && is_a_merge(head_sha1))) {
		run_status(stdout, index_file, prefix, 0, s);
		if (amend)
			fputs(empty_amend_advice, stderr);
		else if (whence == FROM_CHERRY_PICK)
			fputs(empty_cherry_pick_advice, stderr);
		return 0;
	}

