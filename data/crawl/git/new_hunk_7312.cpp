		if (output_format & DIFF_FORMAT_DIFFSTAT)
			show_stats(&diffstat, options);
		if (output_format & DIFF_FORMAT_SHORTSTAT)
			show_shortstats(&diffstat, options);
		free_diffstat_info(&diffstat);
		separator++;
	}

	if (output_format & DIFF_FORMAT_SUMMARY && !is_summary_empty(q)) {
		for (i = 0; i < q->nr; i++)
			diff_summary(options->file, q->queue[i]);
		separator++;
	}

	if (output_format & DIFF_FORMAT_PATCH) {
		if (separator) {
			if (options->stat_sep) {
				/* attach patch instead of inline */
				fputs(options->stat_sep, options->file);
			} else {
				putc(options->line_termination, options->file);
			}
		}

