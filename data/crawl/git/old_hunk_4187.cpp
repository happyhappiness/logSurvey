			branch_name = argv[0];
		else
			usage_with_options(builtin_branch_usage, options);
		if (edit_branch_description(branch_name))
			return 1;
	} else if (rename) {
