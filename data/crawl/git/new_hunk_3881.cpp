		show_log(rev);

	if (opt->output_format & DIFF_FORMAT_RAW) {
		printf("%s", line_prefix);
		offset = strlen(COLONS) - num_parent;
		if (offset < 0)
			offset = 0;
