
	if (output_format & DIFF_FORMAT_PATCH) {
		if (separator) {
			if (options->output_prefix) {
				struct strbuf *msg = NULL;
				msg = options->output_prefix(options,
					options->output_prefix_data);
				fwrite(msg->buf, msg->len, 1, options->file);
			}
			putc(options->line_termination, options->file);
			if (options->stat_sep) {
				/* attach patch instead of inline */
				fputs(options->stat_sep, options->file);