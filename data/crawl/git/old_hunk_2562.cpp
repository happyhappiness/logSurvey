		int ret;
		if (i) {
			printf(_("Rewinding the tree to pristine...\n"));
			restore_state(head_commit->object.sha1, stash);
		}
		if (use_strategies_nr != 1)
			printf(_("Trying merge strategy %s...\n"),
