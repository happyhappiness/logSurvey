	int nofirst;
	FILE *file = o->file;

	fputs(diff_line_prefix(o), file);

	if (len == 0) {
		has_trailing_newline = (first == '\n');
