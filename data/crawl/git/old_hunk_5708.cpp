
	if (!hashcmp(bisect_rev, current_bad_sha1)) {
		exit_if_skipped_commits(tried, current_bad_sha1);
		printf("%s is first bad commit\n", bisect_rev_hex);
		show_diff_tree(prefix, revs.commits->item);
		/* This means the bisection process succeeded. */
		exit(10);
