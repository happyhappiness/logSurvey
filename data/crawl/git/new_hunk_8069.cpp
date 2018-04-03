	free(qname);
}

static int read_old_data(struct stat *st, const char *path, struct strbuf *buf)
{
	int fd;

	switch (st->st_mode & S_IFMT) {
	case S_IFLNK:
		strbuf_grow(buf, st->st_size);
		if (readlink(path, buf->buf, st->st_size) != st->st_size)
			return -1;
		strbuf_setlen(buf, st->st_size);
		return 0;
	case S_IFREG:
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return error("unable to open %s", path);
		if (strbuf_read(buf, fd, st->st_size) < 0) {
			close(fd);
			return -1;
		}
		close(fd);
		convert_to_git(path, buf->buf, buf->len, buf);
		return 0;
	default:
		return -1;
	}
