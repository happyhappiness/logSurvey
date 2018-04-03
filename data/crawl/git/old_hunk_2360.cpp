	DIFF_OPT_CLR(&revs.diffopt, FOLLOW_RENAMES);
	argc = parse_options_end(&ctx);

	if (0 < abbrev)
		/* one more abbrev length is needed for the boundary commit */
		abbrev++;
