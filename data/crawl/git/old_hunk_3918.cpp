		else if (argc == 1)
			branch_name = argv[0];
		else
			usage_with_options(builtin_branch_usage, options);

		strbuf_addf(&branch_ref, "refs/heads/%s", branch_name);
		if (!ref_exists(branch_ref.buf)) {
