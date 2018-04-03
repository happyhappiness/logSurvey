	else if (ents == 2)
		result = builtin_diff_tree(&rev, argc, argv, ent);
	else if (ent[0].item->flags & UNINTERESTING) {
		/*
		 * diff A...B where there is at least one merge base
		 * between A and B.  We have ent[0] == merge-base,