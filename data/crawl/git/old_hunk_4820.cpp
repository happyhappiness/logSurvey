	return (uint32_t) n;
}

int main(int argc, char *argv[])
{
	struct line_buffer buf = LINE_BUFFER_INIT;
	char *s;

	if (argc != 1)
		usage("test-line-buffer < input.txt");
	if (buffer_init(&buf, NULL))
		die_errno("open error");
	while ((s = buffer_read_line(&buf))) {
		s = buffer_read_string(&buf, strtouint32(s));
		fputs(s, stdout);
		fputc('\n', stdout);
		buffer_skip_bytes(&buf, 1);
		if (!(s = buffer_read_line(&buf)))
			break;
		buffer_copy_bytes(&buf, strtouint32(s) + 1);
	}
	if (buffer_deinit(&buf))
		die("input error");
	if (ferror(stdout))
		die("output error");
	buffer_reset(&buf);
	return 0;
}