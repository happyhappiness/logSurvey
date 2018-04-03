		int save_errno = errno;

		if (flags & LOCK_DIE_ON_ERROR)
			exit(128);
		close(orig_fd);
		rollback_lock_file(lk);
		errno = save_errno;