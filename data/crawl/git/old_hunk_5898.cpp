	fd = git_mkstemps(temp->tmp_path, PATH_MAX, template.buf,
			strlen(base) + 1);
	if (fd < 0)
		die("unable to create temp-file: %s", strerror(errno));
	if (convert_to_working_tree(path,
			(const char *)blob, (size_t)size, &buf)) {
		blob = buf.buf;
