	size = c & 15;
	shift = 4;
	while (c & 0x80) {
		if (len <= used)
			return 0;
		if (sizeof(long) * 8 <= shift)
			return 0;
		c = buf[used++];
		size += (c & 0x7f) << shift;
		shift += 7;
