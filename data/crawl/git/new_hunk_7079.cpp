	static char tmpfile[PATH_MAX];

	filename = sha1_file_name(sha1);
	fd = create_tmpfile(tmpfile, sizeof(tmpfile), filename);
	if (fd < 0) {
		if (errno == EPERM)