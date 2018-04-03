		DIFF_OPT_CLR(options, COLOR_DIFF);
	else if (!strcmp(arg, "--color-words")) {
		DIFF_OPT_SET(options, COLOR_DIFF);
		options->word_diff = DIFF_WORDS_COLOR;
	}
	else if (!prefixcmp(arg, "--color-words=")) {
		DIFF_OPT_SET(options, COLOR_DIFF);
		options->word_diff = DIFF_WORDS_COLOR;
		options->word_regex = arg + 14;
	}
	else if (!strcmp(arg, "--word-diff")) {
		if (options->word_diff == DIFF_WORDS_NONE)
			options->word_diff = DIFF_WORDS_PLAIN;
	}
	else if (!prefixcmp(arg, "--word-diff=")) {
		const char *type = arg + 12;
		if (!strcmp(type, "plain"))
			options->word_diff = DIFF_WORDS_PLAIN;
		else if (!strcmp(type, "color")) {
			DIFF_OPT_SET(options, COLOR_DIFF);
			options->word_diff = DIFF_WORDS_COLOR;
		}
		else if (!strcmp(type, "porcelain"))
			options->word_diff = DIFF_WORDS_PORCELAIN;
		else if (!strcmp(type, "none"))
			options->word_diff = DIFF_WORDS_NONE;
		else
			die("bad --word-diff argument: %s", type);
	}
	else if (!prefixcmp(arg, "--word-diff-regex=")) {
		if (options->word_diff == DIFF_WORDS_NONE)
			options->word_diff = DIFF_WORDS_PLAIN;
		options->word_regex = arg + 18;
	}
	else if (!strcmp(arg, "--exit-code"))
		DIFF_OPT_SET(options, EXIT_WITH_STATUS);
	else if (!strcmp(arg, "--quiet"))
