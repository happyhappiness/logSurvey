		    name, (uintmax_t)pid);
	}

	if (gc_before_repack())
		return -1;

	if (run_command_v_opt(repack.argv, RUN_GIT_CMD))
		return error(FAILED_RUN, repack.argv[0]);