	argc = parse_options_end(&ctx);

	if (revs_file && read_ancestry(revs_file))
		die("reading graft file %s failed: %s",
		    revs_file, strerror(errno));

	if (cmd_is_annotate) {
		output_option |= OUTPUT_ANNOTATE_COMPAT;
