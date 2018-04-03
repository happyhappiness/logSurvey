	/* renames options */
	else if (!prefixcmp(arg, "-B")) {
		if ((options->break_opt = diff_scoreopt_parse(arg)) == -1)
			return -1;
	}
	else if (!prefixcmp(arg, "-M")) {
		if ((options->rename_score = diff_scoreopt_parse(arg)) == -1)
			return -1;
		options->detect_rename = DIFF_DETECT_RENAME;
	}
	else if (!prefixcmp(arg, "-C")) {
		if (options->detect_rename == DIFF_DETECT_COPY)
			DIFF_OPT_SET(options, FIND_COPIES_HARDER);
		if ((options->rename_score = diff_scoreopt_parse(arg)) == -1)
			return -1;
		options->detect_rename = DIFF_DETECT_COPY;
	}
	else if (!strcmp(arg, "--no-renames"))