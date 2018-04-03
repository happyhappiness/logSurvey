	return !hashcmp(active_cache_tree->sha1, head_commit->tree->object.oid.hash);
}

/*
 * If we are cherry-pick, and if the merge did not result in
 * hand-editing, we will hit this commit and inherit the original
 * author date and name.
 * If we are revert, or if our cherry-pick results in a hand merge,
 * we had better say that the current user is responsible for that.
 */
static int run_git_commit(const char *defmsg, struct replay_opts *opts,
			  int allow_empty)
{
	struct argv_array array;
	int rc;
	const char *value;

	argv_array_init(&array);
	argv_array_push(&array, "commit");
	argv_array_push(&array, "-n");
