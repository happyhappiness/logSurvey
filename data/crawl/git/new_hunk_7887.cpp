		if (!prefixcmp(argv[0], "--"))
			argv[0] += 2;
	} else {
		/* The user didn't specify a command; give them help */
		printf("usage: %s\n\n", git_usage_string);
		list_common_cmds_help();
		exit(1);
	}
	cmd = argv[0];

