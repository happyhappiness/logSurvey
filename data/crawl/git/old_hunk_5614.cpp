	safe_write(fd, "0000", 4);
}

#define hex(a) (hexchar[(a) & 15])
void packet_write(int fd, const char *fmt, ...)
{
	static char buffer[1000];
	static char hexchar[] = "0123456789abcdef";
	va_list args;
	unsigned n;

	va_start(args, fmt);
	n = vsnprintf(buffer + 4, sizeof(buffer) - 4, fmt, args);
	va_end(args);
	if (n >= sizeof(buffer)-4)
		die("protocol error: impossibly long line");
	n += 4;
	buffer[0] = hex(n >> 12);
	buffer[1] = hex(n >> 8);
	buffer[2] = hex(n >> 4);
	buffer[3] = hex(n);
	safe_write(fd, buffer, n);
}

static void safe_read(int fd, void *buffer, unsigned size)
{
	ssize_t ret = read_in_full(fd, buffer, size);
