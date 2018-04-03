	return run_command_v_opt(argv_show_branch, RUN_GIT_CMD);
}

static struct commit *get_commit_reference(const unsigned char *sha1)
{
	struct commit *r = lookup_commit_reference(sha1);
	if (!r)
		die("Not a valid commit name %s", sha1_to_hex(sha1));
	return r;
}

static struct commit **get_bad_and_good_commits(int *rev_nr)
{
	int len = 1 + good_revs.sha1_nr;
	struct commit **rev = xmalloc(len * sizeof(*rev));
	int i, n = 0;

	rev[n++] = get_commit_reference(current_bad_sha1);
	for (i = 0; i < good_revs.sha1_nr; i++)
		rev[n++] = get_commit_reference(good_revs.sha1[i]);
	*rev_nr = n;

	return rev;
}

static void handle_bad_merge_base(void)
{
	if (is_expected_rev(current_bad_sha1)) {
		char *bad_hex = sha1_to_hex(current_bad_sha1);
		char *good_hex = join_sha1_array_hex(&good_revs, ' ');

		fprintf(stderr, "The merge base %s is bad.\n"
			"This means the bug has been fixed "
			"between %s and [%s].\n",
			bad_hex, bad_hex, good_hex);

		exit(3);
	}

	fprintf(stderr, "Some good revs are not ancestor of the bad rev.\n"
		"git bisect cannot work properly in this case.\n"
		"Maybe you mistake good and bad revs?\n");
	exit(1);
}

void handle_skipped_merge_base(const unsigned char *mb)
{
	char *mb_hex = sha1_to_hex(mb);
	char *bad_hex = sha1_to_hex(current_bad_sha1);
	char *good_hex = join_sha1_array_hex(&good_revs, ' ');

	fprintf(stderr, "Warning: the merge base between %s and [%s] "
		"must be skipped.\n"
		"So we cannot be sure the first bad commit is "
		"between %s and %s.\n"
		"We continue anyway.\n",
		bad_hex, good_hex, mb_hex, bad_hex);
	free(good_hex);
}

/*
 * "check_merge_bases" checks that merge bases are not "bad".
 *
 * - If one is "bad", it means the user assumed something wrong
 * and we must exit with a non 0 error code.
 * - If one is "good", that's good, we have nothing to do.
 * - If one is "skipped", we can't know but we should warn.
 * - If we don't know, we should check it out and ask the user to test.
 */
static void check_merge_bases(void)
{
	struct commit_list *result;
	int rev_nr;
	struct commit **rev = get_bad_and_good_commits(&rev_nr);

	result = get_merge_bases_many(rev[0], rev_nr - 1, rev + 1, 0);

	for (; result; result = result->next) {
		const unsigned char *mb = result->item->object.sha1;
		if (!hashcmp(mb, current_bad_sha1)) {
			handle_bad_merge_base();
		} else if (0 <= lookup_sha1_array(&good_revs, mb)) {
			continue;
		} else if (0 <= lookup_sha1_array(&skipped_revs, mb)) {
			handle_skipped_merge_base(mb);
		} else {
			printf("Bisecting: a merge base must be tested\n");
			exit(bisect_checkout(sha1_to_hex(mb)));
		}
	}

	free(rev);
	free_commit_list(result);
}

/*
 * We use the convention that exiting with an exit code 10 means that
 * the bisection process finished successfully.