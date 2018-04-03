		extra_shown = 1;
	}
	fprintf(options->file, "%s", line_prefix);
	fprintf(options->file,
	       " %d files changed, %d insertions(+), %d deletions(-)\n",
	       total_files, adds, dels);
}

static void show_shortstats(struct diffstat_t *data, struct diff_options *options)
