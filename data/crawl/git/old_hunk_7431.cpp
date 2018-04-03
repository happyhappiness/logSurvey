	char *base;
	unsigned char sha1[20];
	struct commit *ours, *theirs;
	const char *msgfmt;
	char symmetric[84];
	int show_log;
	struct branch *branch = branch_get(NULL);

	if (!branch || !branch->merge)
		return;

	base = branch->merge[0]->dst;

	ours = new->commit;

	sprintf(symmetric, "%s", sha1_to_hex(ours->object.sha1));

	/*
	 * Ok, it is tracking base; is it ahead of us?
	 */
	if (!resolve_ref(base, sha1, 1, NULL))
		return;
	theirs = lookup_commit(sha1);

	sprintf(symmetric + 40, "...%s", sha1_to_hex(sha1));

	if (!hashcmp(sha1, ours->object.sha1))
		return; /* we are the same */

	show_log = 1;
	if (in_merge_bases(theirs, &ours, 1)) {
		msgfmt = "You are ahead of the tracked branch '%s'\n";
		show_log = 0;
	}
	else if (in_merge_bases(ours, &theirs, 1))
		msgfmt = "Your branch can be fast-forwarded to the tracked branch '%s'\n";
	else
		msgfmt = "Both your branch and the tracked branch '%s' have own changes, you would eventually need to merge\n";

	if (!prefixcmp(base, "refs/remotes/"))
		base += strlen("refs/remotes/");
	fprintf(stderr, msgfmt, base);

	if (show_log) {
		const char *args[32];
		int ac;

		ac = 0;
		args[ac++] = "log";
		args[ac++] = "--pretty=oneline";
		args[ac++] = "--abbrev-commit";
		args[ac++] = "--left-right";
		args[ac++] = "--boundary";
		args[ac++] = symmetric;
		args[ac++] = "--";
		args[ac] = NULL;

		run_command_v_opt(args, RUN_GIT_CMD);
	}
}


static void update_refs_for_switch(struct checkout_opts *opts,
				   struct branch_info *old,
