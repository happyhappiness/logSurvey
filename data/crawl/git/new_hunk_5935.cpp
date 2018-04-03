
	fd = mkstemp(template);
	if (fd < 0)
		die_errno("Unable to create temporary file");
	return fd;
}

