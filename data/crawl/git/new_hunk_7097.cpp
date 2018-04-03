
	if (write_buffer(fd, compressed, size) < 0)
		die("unable to write sha1 file");
	close_sha1_file(fd);
	free(compressed);

	if (mtime) {
