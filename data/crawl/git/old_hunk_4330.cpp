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