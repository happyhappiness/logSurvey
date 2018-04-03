	if (fd < 0) {
		if (errno == ENOENT)
			return 0;
		die_errno("index file open failed");
	}

	if (fstat(fd, &st))
		die_errno("cannot stat the open index");

	errno = EINVAL;
	mmap_size = xsize_t(st.st_size);
