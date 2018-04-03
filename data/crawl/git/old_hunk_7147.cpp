	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);
	fflush(stdout);

	if (print_contents) {
		write_or_die(1, contents, size);
		printf("\n");
		fflush(stdout);
