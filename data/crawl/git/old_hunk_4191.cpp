				options->output_prefix_data);
		fprintf(options->file, "%s", msg->buf);
	}
	fprintf(options->file, " %d files changed, %d insertions(+), %d deletions(-)\n",
	       total_files, adds, dels);
}

static void show_numstat(struct diffstat_t *data, struct diff_options *options)
