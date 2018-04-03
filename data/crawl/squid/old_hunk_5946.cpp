    fs = (file_state *) hash_lookup(hash, &r->id);
    if (NULL == fs) {
	errno = EBADF;
	fprintf(stderr, "%d WRITE id %d: ", (int) mypid, r->id);
	perror("do_write");
	return -EBADF;
    }
    if (r->offset > -1 && r->offset != fs->offset) {
	if (lseek(fs->fd, r->offset, SEEK_SET) < 0) {
	    fprintf(stderr, "%d FD %d, offset %d: ", (int) mypid, fs->fd, r->offset);
	    perror("lseek");
	}
    }
#if STDERR_DEBUG
    fprintf(stderr, "%d WRITE %d,%d,%d\n", (int) mypid,
	fs->fd, wrtlen, r->offset);
#endif
    x = write(fs->fd, buf, wrtlen);
    if (x < 0) {
	fprintf(stderr, "%d FD %d: ", (int) mypid, fs->fd);
	perror("write");
	return -errno;
    }
    fs->offset = r->offset + x;
