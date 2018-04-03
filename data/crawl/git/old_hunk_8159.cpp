	int fd;

	strcpy(path, ".merge_file_XXXXXX");
	fd = mkstemp(path);
	if (fd < 0)
		die("unable to create temp-file");
	if (write_in_full(fd, src->ptr, src->size) != src->size)
		die("unable to write temp-file");
	close(fd);
