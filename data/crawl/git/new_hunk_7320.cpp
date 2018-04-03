	if (run_command_v_opt(argv_repack, RUN_GIT_CMD))
		return error(FAILED_RUN, argv_repack[0]);

	argv_prune[2] = prune_expire;
	if (run_command_v_opt(argv_prune, RUN_GIT_CMD))
		return error(FAILED_RUN, argv_prune[0]);

	if (run_command_v_opt(argv_rerere, RUN_GIT_CMD))
