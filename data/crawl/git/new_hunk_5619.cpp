		option_commit = 0;
	}

	if (!allow_fast_forward && fast_forward_only)
		die("You cannot combine --no-ff with --ff-only.");

	if (!argc)
		usage_with_options(builtin_merge_usage,
			builtin_merge_options);
