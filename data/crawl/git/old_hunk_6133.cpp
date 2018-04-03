parse_done:
	argc = parse_options_end(&ctx);

	if (cmd_is_annotate)
		output_option |= OUTPUT_ANNOTATE_COMPAT;

	if (DIFF_OPT_TST(&revs.diffopt, FIND_COPIES_HARDER))
		opt |= (PICKAXE_BLAME_COPY | PICKAXE_BLAME_MOVE |
