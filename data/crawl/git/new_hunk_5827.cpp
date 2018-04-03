
	fd = open(name, O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd < 0)
		die_errno("cannot open output file '%s'", name);
	output = fdopen(fd, "w");

	/* Copy it out, while searching for a line that begins with
