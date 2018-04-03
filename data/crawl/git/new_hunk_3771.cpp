		list_commands(colopts, &main_cmds, &other_cmds);
	}

	if (show_guides)
		list_common_guides_help();

	if (show_all || show_guides) {
		printf("%s\n", _(git_more_info_string));