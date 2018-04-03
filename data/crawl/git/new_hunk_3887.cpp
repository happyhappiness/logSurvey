	for (i = 0; i < data->nr; i++) {
		struct diffstat_file *file = data->files[i];

		fprintf(options->file, "%s", diff_line_prefix(options));

		if (file->is_binary)
			fprintf(options->file, "-\t-\t");
