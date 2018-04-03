		struct diffstat_file *file = data->files[i];

		if (file->is_binary)
			printf("-\t-\t");
		else
			printf("%d\t%d\t", file->added, file->deleted);
		if (options->line_termination) {
			fill_print_name(file);
			if (!file->is_renamed)
				write_name_quoted(file->name, stdout,
						  options->line_termination);
			else {
				fputs(file->print_name, stdout);
				putchar(options->line_termination);
			}
		} else {
			if (file->is_renamed) {
				putchar('\0');
				write_name_quoted(file->from_name, stdout, '\0');
			}
			write_name_quoted(file->name, stdout, '\0');
		}
	}
}
