
int cmd_help(int argc, const char **argv, const char *prefix)
{
	int nongit;

	setup_git_directory_gently(&nongit);
	git_config(git_help_config);

	argc = parse_options(argc, argv, builtin_help_options,
			builtin_help_usage, 0);

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

	switch (help_format) {
	case HELP_FORMAT_MAN:
		show_man_page(argv[0]);
		break;
	case HELP_FORMAT_INFO:
		show_info_page(argv[0]);
		break;
	case HELP_FORMAT_WEB:
		show_html_page(argv[0]);
		break;
	}

	return 0;