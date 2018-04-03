		DIFF_OPT_SET(options, FOLLOW_RENAMES);
	else if (!strcmp(arg, "--color"))
		DIFF_OPT_SET(options, COLOR_DIFF);
	else if (!prefixcmp(arg, "--color=")) {
		int value = git_config_colorbool(NULL, arg+8, -1);
		if (value == 0)
			DIFF_OPT_CLR(options, COLOR_DIFF);
		else if (value > 0)
			DIFF_OPT_SET(options, COLOR_DIFF);
		else
			return error("option `color' expects \"always\", \"auto\", or \"never\"");
	}
	else if (!strcmp(arg, "--no-color"))
		DIFF_OPT_CLR(options, COLOR_DIFF);
	else if (!strcmp(arg, "--color-words")) {
