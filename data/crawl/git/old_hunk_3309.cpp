	}
}

ssize_t read_in_full(int fd, void *buf, size_t count)
{
	char *p = buf;