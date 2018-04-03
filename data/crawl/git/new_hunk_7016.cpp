			die("HEAD not found below refs/heads!");
		head += 11;
	}
	hashcpy(merge_filter_ref, head_sha1);

	argc = parse_options(argc, argv, options, builtin_branch_usage, 0);
	if (!!delete + !!rename + !!force_create > 1)
		usage_with_options(builtin_branch_usage, options);

	if (delete)
		return delete_branches(argc, argv, delete > 1, kinds);