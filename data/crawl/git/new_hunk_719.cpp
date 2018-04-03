		warning(_("ignoring --verify-signatures for rebase"));

	argv_array_push(&args, "--onto");
	argv_array_push(&args, oid_to_hex(merge_head));

	if (fork_point && !is_null_oid(fork_point))
		argv_array_push(&args, oid_to_hex(fork_point));
	else
		argv_array_push(&args, oid_to_hex(merge_head));

	ret = run_command_v_opt(args.argv, RUN_GIT_CMD);
	argv_array_clear(&args);
