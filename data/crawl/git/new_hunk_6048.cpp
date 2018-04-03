
	return show_bisect_vars(&info, reaches, all);
}

static void exit_if_skipped_commits(struct commit_list *tried,
				    const unsigned char *bad)
{
	if (!tried)
		return;

	printf("There are only 'skip'ped commits left to test.\n"
	       "The first bad commit could be any of:\n");
	print_commit_list(tried, "%s\n", "%s\n");
	if (bad)
		printf("%s\n", sha1_to_hex(bad));
	printf("We cannot bisect more!\n");
	exit(2);
}

static void mark_expected_rev(char *bisect_rev_hex)
{
	int len = strlen(bisect_rev_hex);
	const char *filename = git_path("BISECT_EXPECTED_REV");
	int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);

	if (fd < 0)
		die("could not create file '%s': %s",
		    filename, strerror(errno));

	bisect_rev_hex[len] = '\n';
	write_or_die(fd, bisect_rev_hex, len + 1);
	bisect_rev_hex[len] = '\0';

	if (close(fd) < 0)
		die("closing file %s: %s", filename, strerror(errno));
}

static int bisect_checkout(char *bisect_rev_hex)
{
	int res;

	mark_expected_rev(bisect_rev_hex);

	argv_checkout[2] = bisect_rev_hex;
	res = run_command_v_opt(argv_checkout, RUN_GIT_CMD);
	if (res)
		exit(res);

	argv_show_branch[1] = bisect_rev_hex;
	return run_command_v_opt(argv_show_branch, RUN_GIT_CMD);
}

/*
 * We use the convention that exiting with an exit code 10 means that
 * the bisection process finished successfully.
 * In this case the calling shell script should exit 0.
 */
int bisect_next_exit(const char *prefix)
{
	struct rev_info revs;
	struct commit_list *tried;
	int reaches = 0, all = 0, nr;
	const unsigned char *bisect_rev;
	char bisect_rev_hex[41];

	bisect_common(&revs, prefix, &reaches, &all);

	revs.commits = filter_skipped(revs.commits, &tried, 0);

	if (!revs.commits) {
		/*
		 * We should exit here only if the "bad"
		 * commit is also a "skip" commit.
		 */
		exit_if_skipped_commits(tried, NULL);

		printf("%s was both good and bad\n",
		       sha1_to_hex(current_bad_sha1));
		exit(1);
	}

	bisect_rev = revs.commits->item->object.sha1;
	memcpy(bisect_rev_hex, sha1_to_hex(bisect_rev), 41);

	if (!hashcmp(bisect_rev, current_bad_sha1)) {
		exit_if_skipped_commits(tried, current_bad_sha1);
		printf("%s is first bad commit\n", bisect_rev_hex);
		argv_diff_tree[2] = bisect_rev_hex;
		run_command_v_opt(argv_diff_tree, RUN_GIT_CMD);
		/* This means the bisection process succeeded. */
		exit(10);
	}

	nr = all - reaches - 1;
	printf("Bisecting: %d revisions left to test after this "
	       "(roughly %d steps)\n", nr, estimate_bisect_steps(all));

	return bisect_checkout(bisect_rev_hex);
}

