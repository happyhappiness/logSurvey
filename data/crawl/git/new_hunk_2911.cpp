	    write_in_full(fd, &term, 1) != 1 ||
	    close_ref(lock) < 0) {
		int save_errno = errno;
		error("Couldn't write %s", get_lock_file_path(lock->lk));
		unlock_ref(lock);
		errno = save_errno;
		return -1;
