
int cmd_help(int argc, const char **argv, const char *prefix)
{
	const char *help_cmd = argv[1];

	if (argc < 2) {
		printf("usage: %s\n\n", git_usage_string);
		list_common_cmds_help();
		exit(0);
	}

	if (!strcmp(help_cmd, "--all") || !strcmp(help_cmd, "-a")) {
		printf("usage: %s\n\n", git_usage_string);
		list_commands();
	}

	else if (!strcmp(help_cmd, "--web") || !strcmp(help_cmd, "-w")) {
		show_html_page(argc > 2 ? argv[2] : NULL);
	}

	else if (!strcmp(help_cmd, "--info") || !strcmp(help_cmd, "-i")) {
		show_info_page(argc > 2 ? argv[2] : NULL);
	}

	else if (!strcmp(help_cmd, "--man") || !strcmp(help_cmd, "-m")) {
		show_man_page(argc > 2 ? argv[2] : NULL);
	}

	else {
		int nongit;

		setup_git_directory_gently(&nongit);
		git_config(git_help_config);
		if (help_default_format)
			parse_help_format(help_default_format);

		switch (help_format) {
		case man_format:
			show_man_page(help_cmd);
			break;
		case info_format:
			show_info_page(help_cmd);
			break;
		case web_format:
			show_html_page(help_cmd);
			break;
		}
	}

	return 0;