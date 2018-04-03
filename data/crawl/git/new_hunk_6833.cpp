	branch1 = better_branch_name(branch1);
	branch2 = better_branch_name(branch2);

	if (merge_recursive_verbosity >= 3)
		printf("Merging %s with %s\n", branch1, branch2);

	index_fd = hold_locked_index(lock, 1);
