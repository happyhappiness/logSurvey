		restore_state();
		if (use_strategies_nr > 1)
			fprintf(stderr,
				"No merge strategy handled the merge.\n");
		else
			fprintf(stderr, "Merge with strategy %s failed.\n",
				use_strategies[0]->name);
		return 2;
	} else if (best_strategy == wt_strategy)
		; /* We already have its result in the working tree. */
	else {
		printf("Rewinding the tree to pristine...\n");
		restore_state();
		printf("Using the %s to prepare resolving by hand.\n",
			best_strategy);
		try_merge_strategy(best_strategy, common, head_arg);
	}
