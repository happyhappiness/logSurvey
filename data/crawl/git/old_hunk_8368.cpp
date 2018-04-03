	unsigned char *idx_sha1;
	long fd_flag;

	p->pack_fd = open(p->pack_name, O_RDONLY);
	if (p->pack_fd < 0 || fstat(p->pack_fd, &st))
		return -1;
