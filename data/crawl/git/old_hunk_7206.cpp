	 * Otherwise, add a diffopt.line_termination character before all
	 * entries but the first.  (IOW, as a separator between entries)
	 */
	if (opt->shown_one && !opt->use_terminator)
		putchar(opt->diffopt.line_termination);
	opt->shown_one = 1;

	/*
	 * Print header line of header..
	 */
