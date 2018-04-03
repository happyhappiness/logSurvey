	if (!help_cmd) {
		printf("usage: %s\n\n", git_usage_string);
		list_common_cmds_help();
		exit(0);
	}

	else if (!strcmp(help_cmd, "--all") || !strcmp(help_cmd, "-a")) {
		printf("usage: %s\n\n", git_usage_string);
		if(exec_path)
			list_commands(exec_path, "git-*");
		exit(0);
	}

	else