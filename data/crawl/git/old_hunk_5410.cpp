		DIFF_OPT_SET(options, FOLLOW_RENAMES);
	else if (!strcmp(arg, "--color"))
		DIFF_OPT_SET(options, COLOR_DIFF);
	else if (!strcmp(arg, "--no-color"))
		DIFF_OPT_CLR(options, COLOR_DIFF);
	else if (!strcmp(arg, "--color-words")) {
