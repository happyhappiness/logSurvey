		const char *branch_name;
		struct strbuf branch_ref = STRBUF_INIT;

		if (detached)
			die("Cannot give description to detached HEAD");
		if (!argc)
			branch_name = head;
		else if (argc == 1)
			branch_name = argv[0];
		else
			usage_with_options(builtin_branch_usage, options);