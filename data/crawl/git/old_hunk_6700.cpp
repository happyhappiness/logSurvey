	data = src;
	do {
		ssize_t n = pread(pack_fd, data + rdy, len - rdy, from + rdy);
		if (n <= 0)
			die("cannot pread pack file: %s", strerror(errno));
		rdy += n;
	} while (rdy < len);
	data = xmalloc(obj->size);