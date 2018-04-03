	return stream;
}

static inline int xmkstemp(char *template)
{
	int fd;

	fd = mkstemp(template);
	if (fd < 0)
		die("Unable to create temporary file: %s", strerror(errno));
	return fd;
}

static inline size_t xsize_t(off_t len)
{
	return (size_t)len;