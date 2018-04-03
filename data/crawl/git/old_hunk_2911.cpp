	    write_in_full(fd, &term, 1) != 1 ||
	    close_ref(lock) < 0) {
		int save_errno = errno;
		error("Couldn't write %s", lock->lk->filename.buf);
		unlock_ref(lock);
		errno = save_errno;
		return -1;
