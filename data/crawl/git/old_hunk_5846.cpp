	mmap = xmmap(NULL, mmap_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (mmap == MAP_FAILED)
		die("unable to map index file");

	hdr = mmap;
	if (verify_hdr(hdr, mmap_size) < 0)
