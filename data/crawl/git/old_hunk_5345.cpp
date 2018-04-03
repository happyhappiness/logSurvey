	 */
	if (options->pickaxe)
		DIFF_OPT_SET(options, RECURSIVE);

	if (options->detect_rename && options->rename_limit < 0)
		options->rename_limit = diff_rename_limit_default;