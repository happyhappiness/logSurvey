		result = builtin_diff_index(&rev, argc, argv);
	else if (ents == 2)
		result = builtin_diff_tree(&rev, argc, argv, ent);
	else if (ent[0].item->flags & UNINTERESTING) {
		/*
		 * Perhaps the user gave us A...B, which expands
		 * to a list of negative merge bases followed by
		 * A (symmetric-left) and B?  Let's make sure...
		 */
		for (i = 1; i < ents; i++)
			if (!(ent[i].item->flags & UNINTERESTING))
				break;
		if (ents != i + 2 ||
		    (ent[i+1].item->flags & UNINTERESTING) ||
		    (!(ent[i].item->flags & SYMMETRIC_LEFT)) ||
		    (ent[i+1].item->flags & SYMMETRIC_LEFT))
			die("what do you mean by that?");
		/*
		 * diff A...B where there is at least one merge base
		 * between A and B.  We have ent[0] == merge-base,
		 * ent[ents-2] == A, and ent[ents-1] == B.  Show diff
		 * between the base and B.  Note that we pick one
		 * merge base at random if there are more than one.
		 */
		ent[1] = ent[ents-1];
		result = builtin_diff_tree(&rev, argc, argv, ent);
	} else
		result = builtin_diff_combined(&rev, argc, argv,
					       ent, ents);
	result = diff_result_code(&rev.diffopt, result);
	if (1 < rev.diffopt.skip_stat_unmatch)
		refresh_index_quietly();