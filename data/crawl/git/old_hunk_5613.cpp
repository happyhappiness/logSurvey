	safe_read(fd, linelen, 4);
	len = packet_length(linelen);
	if (len < 0)
		die("protocol error: bad line length character");
	if (!len)
		return 0;
	len -= 4;