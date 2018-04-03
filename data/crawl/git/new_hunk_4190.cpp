		extra_shown = 1;
	}
	fprintf(options->file, "%s", line_prefix);
	print_stat_summary(options->file, total_files, adds, dels);
}

static void show_shortstats(struct diffstat_t *data, struct diff_options *options)
