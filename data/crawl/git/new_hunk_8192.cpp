				goto write_err_out;

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
	 * lock_file structures, it isn't safe to free(lock).  It's
	 * better to just leave it hanging around.
	 */
	lock = NULL;
	ret = 0;

out_free:
	if (0 <= fd)
		close(fd);
	if (lock)
		rollback_lock_file(lock);
	free(config_filename);
	return ret;

write_err_out: