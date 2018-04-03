	 * it up.
	 */
	if (!best_strategy) {
		restore_state(head_commit->object.oid.hash, stash);
		if (use_strategies_nr > 1)
			fprintf(stderr,
				_("No merge strategy handled the merge.\n"));
