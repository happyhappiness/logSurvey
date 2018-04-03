		die("Unable to create temporary file: %s", strerror(errno));
	return fd;
}
