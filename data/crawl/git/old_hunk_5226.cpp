	for (i = 0; i < data->nr; i++) {
		struct diffstat_file *file = data->files[i];

		if (file->is_binary)
			fprintf(options->file, "-\t-\t");
		else
