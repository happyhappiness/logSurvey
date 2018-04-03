parse_done:
	argc = parse_options_end(&ctx);

	if (revs_file && read_ancestry(revs_file))
		die("reading graft file %s failed: %s",
		    revs_file, strerror(errno));

	if (DIFF_OPT_TST(&revs.diffopt, FIND_COPIES_HARDER))
		opt |= (PICKAXE_BLAME_COPY | PICKAXE_BLAME_MOVE |
			PICKAXE_BLAME_COPY_HARDER);
