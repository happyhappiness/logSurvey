	}

	if (commit_lock_file(lock) < 0) {
		fprintf(stderr, "Cannot commit config file!\n");
		ret = 4;
		goto out_free;
	}
