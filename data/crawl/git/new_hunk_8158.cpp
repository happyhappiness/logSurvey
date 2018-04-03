
	snprintf(tmpfile, sizeof(tmpfile),
		"%s/tmp_idx_XXXXXX", get_object_directory());
	idx_fd = xmkstemp(tmpfile);
	f = sha1fd(idx_fd, tmpfile);
	sha1write(f, array, 256 * sizeof(int));
	SHA1_Init(&ctx);
