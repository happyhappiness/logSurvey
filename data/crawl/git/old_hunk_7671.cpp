{
	int i;

	for (i = 0; i < data->nr; i++) {
		struct diffstat_file *file = data->files[i];

		if (file->is_binary)
			printf("-\t-\t");
		else
			printf("%d\t%d\t", file->added, file->deleted);
		if (!file->is_renamed) {
			write_name_quoted(file->name, stdout, options->line_termination);
		} else {
			fputs(file->name, stdout);
			putchar(options->line_termination);
		}
	}
}

struct checkdiff_t {
	struct xdiff_emit_state xm;
	const char *filename;
