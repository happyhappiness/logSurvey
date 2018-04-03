{
	switch (st->st_mode & S_IFMT) {
	case S_IFLNK:
		strbuf_grow(buf, st->st_size);
		if (readlink(path, buf->buf, st->st_size) != st->st_size)
			return -1;
		strbuf_setlen(buf, st->st_size);
		return 0;
	case S_IFREG:
		if (strbuf_read_file(buf, path, st->st_size) != st->st_size)
