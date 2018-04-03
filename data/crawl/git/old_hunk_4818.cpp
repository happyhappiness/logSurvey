int main(int argc, char *argv[])
{
	struct line_buffer stdin_buf = LINE_BUFFER_INIT;
	char *s;

	if (argc != 1)
		usage("test-line-buffer < script");

	if (buffer_init(&stdin_buf, NULL))
		die_errno("open error");
	while ((s = buffer_read_line(&stdin_buf)))
		handle_line(s, &stdin_buf);
	if (buffer_deinit(&stdin_buf))
		die("input error");
	if (ferror(stdout))