
int cmd_stripspace(int argc, const char **argv, const char *prefix)
{
	char *buffer;
	unsigned long size;
	int strip_comments = 0;

	if (argc > 1 && (!strcmp(argv[1], "-s") ||
				!strcmp(argv[1], "--strip-comments")))
		strip_comments = 1;

	size = 1024;
	buffer = xmalloc(size);
	if (read_fd(0, &buffer, &size)) {
		free(buffer);
		die("could not read the input");
	}

	size = stripspace(buffer, size, strip_comments);
	write_or_die(1, buffer, size);
	if (size)
		putc('\n', stdout);

	free(buffer);
	return 0;
}
