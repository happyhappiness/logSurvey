	fd = open(path, O_RDONLY);
	if (fd < 0)
		die("could not open '%s': %s", path, strerror(errno));
	if (strbuf_read(buffer, fd, 0) < 0) {
		die("could not read message file '%s': %s", path, strerror(errno));
	}
	close(fd);
}
