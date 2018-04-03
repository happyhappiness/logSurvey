		DIFF_OPT_CLR(options, COLOR_DIFF);
	else if (!strcmp(arg, "--color-words")) {
		DIFF_OPT_SET(options, COLOR_DIFF);
		DIFF_OPT_SET(options, COLOR_DIFF_WORDS);
	}
	else if (!prefixcmp(arg, "--color-words=")) {
		DIFF_OPT_SET(options, COLOR_DIFF);
		DIFF_OPT_SET(options, COLOR_DIFF_WORDS);
		options->word_regex = arg + 14;
	}
	else if (!strcmp(arg, "--exit-code"))
		DIFF_OPT_SET(options, EXIT_WITH_STATUS);
	else if (!strcmp(arg, "--quiet"))
