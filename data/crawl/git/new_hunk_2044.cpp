	if (!f) {
		if (errno == ENOENT)
			return 0;
		return error_errno("unable to open mailmap at %s", filename);
	}

	while (fgets(buffer, sizeof(buffer), f) != NULL)