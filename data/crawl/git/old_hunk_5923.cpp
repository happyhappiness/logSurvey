	if (fd < 0) {
		if (errno == ENOENT)
			return 0;
		die("index file open failed (%s)", strerror(errno));
	}

	if (fstat(fd, &st))
		die("cannot stat the open index (%s)", strerror(errno));

	errno = EINVAL;
	mmap_size = xsize_t(st.st_size);
