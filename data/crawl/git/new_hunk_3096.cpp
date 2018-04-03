	if (gc_before_repack())
		return -1;

	if (!repository_format_precious_objects) {
		if (run_command_v_opt(repack.argv, RUN_GIT_CMD))
			return error(FAILED_RUN, repack.argv[0]);

		if (prune_expire) {
			argv_array_push(&prune, prune_expire);
			if (quiet)
				argv_array_push(&prune, "--no-progress");
			if (run_command_v_opt(prune.argv, RUN_GIT_CMD))
				return error(FAILED_RUN, prune.argv[0]);
		}
	}

	if (prune_worktrees_expire) {
