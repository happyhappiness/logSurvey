		exit(128); /* We've already reported the error, finish dying */
}

static char *prepare_index(int argc, const char **argv, const char *prefix)
{
	int fd;
	struct string_list partial;
	const char **pathspec = NULL;

	if (interactive) {
		if (interactive_add(argc, argv, prefix) != 0)
			die("interactive add failed");
