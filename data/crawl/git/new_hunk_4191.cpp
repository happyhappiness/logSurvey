				options->output_prefix_data);
		fprintf(options->file, "%s", msg->buf);
	}
	print_stat_summary(options->file, total_files, adds, dels);
}

static void show_numstat(struct diffstat_t *data, struct diff_options *options)
