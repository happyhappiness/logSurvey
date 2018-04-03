	char *base;
	unsigned char sha1[20];
	struct commit *ours, *theirs;
	char symmetric[84];
	struct rev_info revs;
	const char *rev_argv[10];
	int rev_argc;
	int num_ours, num_theirs;
	const char *remote_msg;
	struct branch *branch = branch_get(NULL);

	/*
	 * Nothing to report unless we are marked to build on top of
	 * somebody else.
	 */
	if (!branch || !branch->merge)
		return;

	/*
	 * If what we used to build on no longer exists, there is
	 * nothing to report.
	 */
	base = branch->merge[0]->dst;
	if (!resolve_ref(base, sha1, 1, NULL))
		return;

	theirs = lookup_commit(sha1);
	ours = new->commit;
	if (!hashcmp(sha1, ours->object.sha1))
		return; /* we are the same */

	/* Run "rev-list --left-right ours...theirs" internally... */
	rev_argc = 0;
	rev_argv[rev_argc++] = NULL;
	rev_argv[rev_argc++] = "--left-right";
	rev_argv[rev_argc++] = symmetric;
	rev_argv[rev_argc++] = "--";
	rev_argv[rev_argc] = NULL;

	strcpy(symmetric, sha1_to_hex(ours->object.sha1));
	strcpy(symmetric + 40, "...");
	strcpy(symmetric + 43, sha1_to_hex(theirs->object.sha1));

	init_revisions(&revs, NULL);
	setup_revisions(rev_argc, rev_argv, &revs, NULL);
	prepare_revision_walk(&revs);

	/* ... and count the commits on each side. */
	num_ours = 0;
	num_theirs = 0;
	while (1) {
		struct commit *c = get_revision(&revs);
		if (!c)
			break;
		if (c->object.flags & SYMMETRIC_LEFT)
			num_ours++;
		else
			num_theirs++;
	}

	if (!prefixcmp(base, "refs/remotes/")) {
		remote_msg = " remote";
		base += strlen("refs/remotes/");
	} else {
		remote_msg = "";
	}

	if (!num_theirs)
		printf("Your branch is ahead of the tracked%s branch '%s' "
		       "by %d commit%s.\n",
		       remote_msg, base,
		       num_ours, (num_ours == 1) ? "" : "s");
	else if (!num_ours)
		printf("Your branch is behind of the tracked%s branch '%s' "
		       "by %d commit%s,\n"
		       "and can be fast-forwarded.\n",
		       remote_msg, base,
		       num_theirs, (num_theirs == 1) ? "" : "s");
	else
		printf("Your branch and the tracked%s branch '%s' "
		       "have diverged,\nand respectively "
		       "have %d and %d different commit(s) each.\n",
		       remote_msg, base,
		       num_ours, num_theirs);
}

static void update_refs_for_switch(struct checkout_opts *opts,
				   struct branch_info *old,
