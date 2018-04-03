	int fd;

	if (!current_bad_oid)
		die(_("a %s revision is needed"), term_bad);

	/* Check if file BISECT_ANCESTORS_OK exists. */
	if (!stat(filename, &st) && S_ISREG(st.st_mode))
