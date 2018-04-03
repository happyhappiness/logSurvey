	git_SHA_CTX c;
	unsigned char parano_sha1[20];
	char *filename;
	static char tmp_file[PATH_MAX];

	filename = sha1_file_name(sha1);
	fd = create_tmpfile(tmp_file, sizeof(tmp_file), filename);
	if (fd < 0) {
		if (errno == EACCES)
			return error("insufficient permission for adding an object to repository database %s\n", get_object_directory());
		else
			return error("unable to create temporary sha1 filename %s: %s\n", tmp_file, strerror(errno));
	}

	/* Set it up */
