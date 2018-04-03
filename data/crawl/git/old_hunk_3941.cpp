		options->xdl_opts = DIFF_WITH_ALG(options, PATIENCE_DIFF);
	else if (!strcmp(arg, "--histogram"))
		options->xdl_opts = DIFF_WITH_ALG(options, HISTOGRAM_DIFF);

	/* flags options */
	else if (!strcmp(arg, "--binary")) {
