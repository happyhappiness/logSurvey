	len -= 4;
	if (len >= size)
		die("protocol error: bad line length %d", len);
	ret = safe_read(fd, buffer, len, options);
	if (ret < 0)
		return ret;

