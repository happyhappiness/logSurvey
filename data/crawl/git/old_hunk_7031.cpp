		i = strlen(lock->lk->filename) - 5; /* .lock */
		lock->lk->filename[i] = 0;
		err = unlink(lock->lk->filename);
		if (err) {
			ret = 1;
			error("unlink(%s) failed: %s",
			      lock->lk->filename, strerror(errno));
