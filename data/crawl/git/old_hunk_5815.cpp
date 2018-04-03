
	dir = opendir(src->buf);
	if (!dir)
		die("failed to open %s", src->buf);

	if (mkdir(dest->buf, 0777)) {
		if (errno != EEXIST)
			die("failed to create directory %s", dest->buf);
		else if (stat(dest->buf, &buf))
			die("failed to stat %s", dest->buf);
		else if (!S_ISDIR(buf.st_mode))
			die("%s exists and is not a directory", dest->buf);
	}
