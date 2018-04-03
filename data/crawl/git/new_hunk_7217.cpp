	return fd;
}

int hold_lock_file_for_append(struct lock_file *lk, const char *path, int die_on_error)
{
	int fd, orig_fd;

	fd = lock_file(lk, path);
	if (fd < 0) {
		if (die_on_error)
			die("unable to create '%s.lock': %s", path, strerror(errno));
		return fd;
	}

	orig_fd = open(path, O_RDONLY);
	if (orig_fd < 0) {
		if (errno != ENOENT) {
			if (die_on_error)
				die("cannot open '%s' for copying", path);
			close(fd);
			return error("cannot open '%s' for copying", path);
		}
	} else if (copy_fd(orig_fd, fd)) {
		if (die_on_error)
			exit(128);
		close(fd);
		return -1;
	}
	return fd;
}

int close_lock_file(struct lock_file *lk)
{
	int fd = lk->fd;