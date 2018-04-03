		die("unable to read blob object %s", sha1_to_hex(sha1));

	strcpy(path, ".merge_file_XXXXXX");
	fd = mkstemp(path);
	if (fd < 0)
		die("unable to create temp-file");
	if (write_in_full(fd, buf, size) != size)
		die("unable to write temp-file");
	close(fd);