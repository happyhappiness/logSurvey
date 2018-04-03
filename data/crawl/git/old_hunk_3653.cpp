	return retval >= 0 && (tree_difference == REV_TREE_SAME);
}

static void try_to_simplify_commit(struct rev_info *revs, struct commit *commit)
{
	struct commit_list **pp, *parent;
	int tree_changed = 0, tree_same = 0, nth_parent = 0;

	/*
	 * If we don't do pruning, everything is interesting
