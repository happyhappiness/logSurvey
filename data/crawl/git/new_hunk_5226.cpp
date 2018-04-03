	for (i = 0; i < data->nr; i++) {
		struct diffstat_file *file = data->files[i];

		if (options->output_prefix) {
			struct strbuf *msg = NULL;
			msg = options->output_prefix(options,
					options->output_prefix_data);
			fprintf(options->file, "%s", msg->buf);
		}

		if (file->is_binary)
			fprintf(options->file, "-\t-\t");
		else
