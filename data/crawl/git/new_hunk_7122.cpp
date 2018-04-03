	return total;
}

void fsync_or_die(int fd, const char *msg)
{
	if (fsync(fd) < 0) {
		die("%s: fsync error (%s)", msg, strerror(errno));
	}
}

void write_or_die(int fd, const void *buf, size_t count)
{
	if (write_in_full(fd, buf, count) < 0) {