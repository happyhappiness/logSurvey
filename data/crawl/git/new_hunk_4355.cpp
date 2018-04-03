	return cnt;
}

/*
 * Pretend as if the user told us to merge with the tracking
 * branch we have for the upstream of the current branch
 */
static int setup_with_upstream(const char ***argv)
{
	struct branch *branch = branch_get(NULL);
	int i;
	const char **args;

	if (!branch)
		die("No current branch.");
	if (!branch->remote)
		die("No remote for the current branch.");
	if (!branch->merge_nr)
		die("No default upstream defined for the current branch.");

	args = xcalloc(branch->merge_nr + 1, sizeof(char *));
	for (i = 0; i < branch->merge_nr; i++) {
		if (!branch->merge[i]->dst)
			die("No remote tracking branch for %s from %s",
			    branch->merge[i]->src, branch->remote_name);
		args[i] = branch->merge[i]->dst;
	}
	args[i] = NULL;
	*argv = args;
	return i;
}

int cmd_merge(int argc, const char **argv, const char *prefix)
{
	unsigned char result_tree[20];
