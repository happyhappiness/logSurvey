
	if (output_format & DIFF_FORMAT_PATCH) {
		if (separator) {
			fprintf(options->file, "%s%c",
				diff_line_prefix(options),
				options->line_termination);
			if (options->stat_sep) {
				/* attach patch instead of inline */
				fputs(options->stat_sep, options->file);