	if (!dir) {
		if (errno == ENOENT)
			return 0;
		return error("unable to open %s: %s", path->buf, strerror(errno));
	}

	while ((de = readdir(dir))) {