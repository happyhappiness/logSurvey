	free(qname);
}

static int read_old_data(struct stat *st, const char *path, char **buf_p, unsigned long *alloc_p, unsigned long *size_p)
{
	int fd;
	unsigned long got;
	struct strbuf nbuf;
	unsigned long size = *size_p;
	char *buf = *buf_p;

	switch (st->st_mode & S_IFMT) {
	case S_IFLNK:
		return readlink(path, buf, size) != size;
	case S_IFREG:
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return error("unable to open %s", path);
		got = 0;
		for (;;) {
			ssize_t ret = xread(fd, buf + got, size - got);
			if (ret <= 0)
				break;
			got += ret;
		}
		close(fd);
		strbuf_init(&nbuf, 0);
		if (convert_to_git(path, buf, size, &nbuf)) {
			free(buf);
			*buf_p = nbuf.buf;
			*alloc_p = nbuf.alloc;
			*size_p = nbuf.len;
		}
		return got != size;
	default:
		return -1;
	}
