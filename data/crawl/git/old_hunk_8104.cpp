
static void *read_patch_file(int fd, unsigned long *sizep)
{
	unsigned long size = 0, alloc = CHUNKSIZE;
	void *buffer = xmalloc(alloc);

	for (;;) {
		ssize_t nr = alloc - size;
		if (nr < 1024) {
			alloc += CHUNKSIZE;
			buffer = xrealloc(buffer, alloc);
			nr = alloc - size;
		}
		nr = xread(fd, (char *) buffer + size, nr);
		if (!nr)
			break;
		if (nr < 0)
			die("git-apply: read returned %s", strerror(errno));
		size += nr;
	}
	*sizep = size;

	/*
	 * Make sure that we have some slop in the buffer
	 * so that we can do speculative "memcmp" etc, and
	 * see to it that it is NUL-filled.
	 */
	if (alloc < size + SLOP)
		buffer = xrealloc(buffer, size + SLOP);
	memset((char *) buffer + size, 0, SLOP);
	return buffer;
}

static unsigned long linelen(const char *buffer, unsigned long size)