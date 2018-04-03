		int ret;
		if (i) {
			printf(_("Rewinding the tree to pristine...\n"));
			restore_state(get_object_hash(head_commit->object), stash);
		}
		if (use_strategies_nr != 1)
			printf(_("Trying merge strategy %s...\n"),
