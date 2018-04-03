	if (!dir) {
		if (errno == ENOENT)
			return 0;
		return error_errno("unable to open %s", path->buf);
	}

	while ((de = readdir(dir))) {