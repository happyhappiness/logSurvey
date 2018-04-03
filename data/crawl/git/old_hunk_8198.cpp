
	fd = git_mkstemp(temp->tmp_path, PATH_MAX, ".diff_XXXXXX");
	if (fd < 0)
		die("unable to create temp-file");
	if (write_in_full(fd, blob, size) != size)
		die("unable to write temp-file");
	close(fd);
