	if (fast_forward_to(index_tree, remote_tree, 0))
		return -1;

	if (merge_tree(remote_tree))
		return -1;

	remove_branch_state();

