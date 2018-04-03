		munmap(contents, contents_sz);
	}

	if (commit_lock_file(lock) < 0) {
		fprintf(stderr, "Cannot commit config file!\n");
		ret = 4;
		goto out_free;
	}

	/*
	 * lock is committed, so don't try to roll it back below.
	 * NOTE: Since lockfile.c keeps a linked list of all created
