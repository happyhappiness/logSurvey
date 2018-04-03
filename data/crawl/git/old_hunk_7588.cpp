		munmap(contents, contents_sz);
	}

	if (close(fd) || commit_lock_file(lock) < 0) {
		fprintf(stderr, "Cannot commit config file!\n");
		ret = 4;
		goto out_free;
	}

	/* fd is closed, so don't try to close it below. */
	fd = -1;
	/*
	 * lock is committed, so don't try to roll it back below.
	 * NOTE: Since lockfile.c keeps a linked list of all created
