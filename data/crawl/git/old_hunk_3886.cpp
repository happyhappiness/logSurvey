			dels += deleted;
		}
	}
	if (options->output_prefix) {
		struct strbuf *msg = NULL;
		msg = options->output_prefix(options,
				options->output_prefix_data);
		fprintf(options->file, "%s", msg->buf);
	}
	print_stat_summary(options->file, total_files, adds, dels);
}

