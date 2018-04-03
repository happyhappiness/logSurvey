			source_tree = parse_tree_indirect(rev);

		if (!source_tree)                   /* case (1): want a tree */
			die("reference is not a tree: %s", arg);
		if (!has_dash_dash) {/* case (3 -> 1) */
			/*
			 * Do not complain the most common case
