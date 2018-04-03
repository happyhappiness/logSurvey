		errno = EINVAL;
		return -1;
	}
	fd = get_lock_file_fd(lock->lk);
	if (write_in_full(fd, sha1_to_hex(sha1), 40) != 40 ||
	    write_in_full(fd, &term, 1) != 1 ||
	    close_ref(lock) < 0) {
		int save_errno = errno;
		error("Couldn't write %s", lock->lk->filename.buf);
