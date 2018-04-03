	fd = open(path, O_RDONLY);
	if (fd < 0)
		die("could not open '%s': %s", path, strerror(errno));
	if (read_fd(fd, buffer, len)) {
		free(*buffer);
		die("could not read message file '%s': %s",
						path, strerror(errno));
	}
	close(fd);
}
