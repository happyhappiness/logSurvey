	int fd;

	if (!current_bad_oid)
		die("a bad revision is needed");

	/* Check if file BISECT_ANCESTORS_OK exists. */
	if (!stat(filename, &st) && S_ISREG(st.st_mode))
