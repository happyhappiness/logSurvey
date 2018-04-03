	 */
	if (options->pickaxe)
		DIFF_OPT_SET(options, RECURSIVE);
	/*
	 * When patches are generated, submodules diffed against the work tree
	 * must be checked for dirtiness too so it can be shown in the output
	 */
	if (options->output_format & DIFF_FORMAT_PATCH)
		DIFF_OPT_SET(options, DIRTY_SUBMODULES);

	if (options->detect_rename && options->rename_limit < 0)
		options->rename_limit = diff_rename_limit_default;