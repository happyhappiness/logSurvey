	} else
		add_repack_all_option();

	if (pack_refs && run_command_v_opt(argv_pack_refs, RUN_GIT_CMD))
		return error(FAILED_RUN, argv_pack_refs[0]);

	if (run_command_v_opt(argv_reflog, RUN_GIT_CMD))
		return error(FAILED_RUN, argv_reflog[0]);

	if (run_command_v_opt(argv_repack, RUN_GIT_CMD))
		return error(FAILED_RUN, argv_repack[0]);

	if (prune_expire) {
		argv_prune[2] = prune_expire;
		if (quiet)
			argv_prune[3] = "--no-progress";
		if (run_command_v_opt(argv_prune, RUN_GIT_CMD))
			return error(FAILED_RUN, argv_prune[0]);
	}

	if (run_command_v_opt(argv_rerere, RUN_GIT_CMD))
		return error(FAILED_RUN, argv_rerere[0]);

	if (auto_gc && too_many_loose_objects())
		warning(_("There are too many unreachable loose objects; "