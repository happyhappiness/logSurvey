
	if (write_buffer(fd, compressed, size) < 0)
		die("unable to write sha1 file");
	fchmod(fd, 0444);
	if (close(fd))
		die("unable to write sha1 file");
	free(compressed);

	if (mtime) {
