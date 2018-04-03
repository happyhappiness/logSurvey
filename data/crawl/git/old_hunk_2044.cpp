	if (!f) {
		if (errno == ENOENT)
			return 0;
		return error("unable to open mailmap at %s: %s",
			     filename, strerror(errno));
	}

	while (fgets(buffer, sizeof(buffer), f) != NULL)