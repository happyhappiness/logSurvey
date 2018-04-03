				goto write_err_out;

		munmap(contents, contents_sz);
		unlink(config_filename);
	}

	if (rename(lock_file, config_filename) < 0) {
		fprintf(stderr, "Could not rename the lock file?\n");
		ret = 4;
		goto out_free;
	}

	ret = 0;

out_free:
	if (0 <= fd)
		close(fd);
	free(config_filename);
	if (lock_file) {
		unlink(lock_file);
		free(lock_file);
	}
	return ret;

write_err_out: