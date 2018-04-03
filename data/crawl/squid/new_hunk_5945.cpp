    fs = (file_state *) hash_lookup(hash, &r->id);
    if (NULL == fs) {
	errno = EBADF;
	DEBUG(1) {
	    fprintf(stderr, "%d READ  id %d: ", (int) mypid, r->id);
	    perror("do_read");
	}
	return -errno;
    }
    if (r->offset > -1 && r->offset != fs->offset) {
	DEBUG(2)
	    fprintf(stderr, "seeking to %d\n", r->offset);
	if (lseek(fs->fd, r->offset, SEEK_SET) < 0) {
	    DEBUG(1) {
		fprintf(stderr, "%d FD %d, offset %d: ", (int) mypid, fs->fd, r->offset);
		perror("lseek");
	    }
	}
    }
    x = read(fs->fd, buf, readlen);
    DEBUG(2)
	fprintf(stderr, "%d READ %d,%d,%d ret %d\n", (int) mypid,
	fs->fd, readlen, r->offset, x);
    if (x < 0) {
	DEBUG(1) {
	    fprintf(stderr, "%d FD %d: ", (int) mypid, fs->fd);
	    perror("read");
	}
	return -errno;
    }
    fs->offset = r->offset + x;
