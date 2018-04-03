	if (show_all) {
		printf("usage: %s\n\n", git_usage_string);
		list_commands();
		return 0;
	}

	if (!argv[0]) {
		printf("usage: %s\n\n", git_usage_string);
		list_common_cmds_help();
		return 0;
	}
