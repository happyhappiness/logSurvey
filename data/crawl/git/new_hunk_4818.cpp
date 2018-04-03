int main(int argc, char *argv[])
{
	struct line_buffer stdin_buf = LINE_BUFFER_INIT;
	struct line_buffer file_buf = LINE_BUFFER_INIT;
	struct line_buffer *input = &stdin_buf;
	const char *filename;
	char *s;

	if (argc == 1)
		filename = NULL;
	else if (argc == 2)
		filename = argv[1];
	else
		usage("test-line-buffer [file] < script");

	if (buffer_init(&stdin_buf, NULL))
		die_errno("open error");
	if (filename) {
		if (buffer_init(&file_buf, filename))
			die_errno("error opening %s", filename);
		input = &file_buf;
	}

	while ((s = buffer_read_line(&stdin_buf)))
		handle_line(s, input);

	if (filename && buffer_deinit(&file_buf))
		die("error reading from %s", filename);
	if (buffer_deinit(&stdin_buf))
		die("input error");
	if (ferror(stdout))