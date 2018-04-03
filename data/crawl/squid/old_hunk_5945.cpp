    fs = (file_state *) hash_lookup(hash, &r->id);
    if (NULL == fs) {
	errno = EBADF;
	fprintf(stderr, "%d READ  id %d: ", (int) mypid, r->id);
	perror("do_read");
	return -EBADF;
    }
    if (r->offset > -1 && r->offset != fs->offset) {
#if STDERR_DEBUG
	fprintf(stderr, "seeking to %d\n", r->offset);
#endif
	if (lseek(fs->fd, r->offset, SEEK_SET) < 0) {
	    fprintf(stderr, "%d FD %d, offset %d: ", (int) mypid, fs->fd, r->offset);
	    perror("lseek");
	}
    }
    x = read(fs->fd, buf, readlen);
#if STDERR_DEBUG
    fprintf(stderr, "%d READ %d,%d,%d ret %d\n", (int) mypid,
	fs->fd, readlen, r->offset, x);
#endif
    if (x < 0) {
	fprintf(stderr, "%d FD %d: ", (int) mypid, fs->fd);
	perror("read");
	return -errno;
    }
    fs->offset = r->offset + x;
