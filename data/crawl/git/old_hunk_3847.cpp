	strbuf_add(buf, buffer, n);
}

static int safe_read(int fd, void *buffer, unsigned size, int options)
{
	ssize_t ret = read_in_full(fd, buffer, size);
	if (ret < 0)
		die_errno("read error");
	else if (ret < size) {
		if (options & PACKET_READ_GENTLE_ON_EOF)
			return -1;

