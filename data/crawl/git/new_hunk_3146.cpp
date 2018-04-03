	if (file_exists(git_path("MERGE_HEAD")))
		die_conclude_merge();

	if (get_sha1("HEAD", orig_head))
		hashclr(orig_head);

	if (run_fetch(repo, refspecs))
		return 1;

	if (opt_dry_run)
		return 0;

	if (get_sha1("HEAD", curr_head))
		hashclr(curr_head);

	if (!is_null_sha1(orig_head) && !is_null_sha1(curr_head) &&
			hashcmp(orig_head, curr_head)) {
		/*
		 * The fetch involved updating the current branch.
		 *
		 * The working tree and the index file are still based on
		 * orig_head commit, but we are merging into curr_head.
		 * Update the working tree to match curr_head.
		 */

		warning(_("fetch updated the current branch head.\n"
			"fast-forwarding your working tree from\n"
			"commit %s."), sha1_to_hex(orig_head));

		if (checkout_fast_forward(orig_head, curr_head, 0))
			die(_("Cannot fast-forward your working tree.\n"
				"After making sure that you saved anything precious from\n"
				"$ git diff %s\n"
				"output, run\n"
				"$ git reset --hard\n"
				"to recover."), sha1_to_hex(orig_head));
	}

	get_merge_heads(&merge_heads);

	if (!merge_heads.nr)