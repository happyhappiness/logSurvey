	if (!revs->dense && !commit->parents->next)
		return;

	pp = &commit->parents;
	while ((parent = *pp) != NULL) {
		struct commit *p = parent->item;

		/*
		 * Do not compare with later parents when we care only about
		 * the first parent chain, in order to avoid derailing the
		 * traversal to follow a side branch that brought everything
		 * in the path we are limited to by the pathspec.
		 */
		if (revs->first_parent_only && nth_parent++)
			break;
		if (parse_commit(p) < 0)
			die("cannot simplify commit %s (because of %s)",
			    sha1_to_hex(commit->object.sha1),
			    sha1_to_hex(p->object.sha1));
		switch (rev_compare_tree(revs, p, commit)) {
		case REV_TREE_SAME:
			tree_same = 1;
			if (!revs->simplify_history || (p->object.flags & UNINTERESTING)) {
				/* Even if a merge with an uninteresting
				 * side branch brought the entire change
				 * we are interested in, we do not want
				 * to lose the other branches of this
				 * merge, so we just keep going.
				 */
				pp = &parent->next;
				continue;
			}
			parent->next = NULL;
