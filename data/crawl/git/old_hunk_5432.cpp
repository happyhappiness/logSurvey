		separator++;
	}

	if (output_format & DIFF_FORMAT_PATCH) {
		if (separator) {
			putc(options->line_termination, options->file);