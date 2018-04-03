		result = builtin_diff_index(&rev, argc, argv);
	else if (ents == 2)
		result = builtin_diff_tree(&rev, argc, argv, ent);
	else if ((ents == 3) && (ent[0].item->flags & UNINTERESTING)) {
		/* diff A...B where there is one sane merge base between
		 * A and B.  We have ent[0] == merge-base, ent[1] == A,
		 * and ent[2] == B.  Show diff between the base and B.
		 */
		ent[1] = ent[2];
		result = builtin_diff_tree(&rev, argc, argv, ent);
	}
	else
		result = builtin_diff_combined(&rev, argc, argv,
					     ent, ents);
	result = diff_result_code(&rev.diffopt, result);
	if (1 < rev.diffopt.skip_stat_unmatch)
		refresh_index_quietly();