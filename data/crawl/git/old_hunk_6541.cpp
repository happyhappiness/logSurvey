
	dir = opendir(src->buf);
	if (!dir)
		die("failed to open %s\n", src->buf);

	if (mkdir(dest->buf, 0777)) {
		if (errno != EEXIST)
			die("failed to create directory %s\n", dest->buf);
		else if (stat(dest->buf, &buf))
			die("failed to stat %s\n", dest->buf);
		else if (!S_ISDIR(buf.st_mode))
			die("%s exists and is not a directory\n", dest->buf);
	}

	strbuf_addch(src, '/');
