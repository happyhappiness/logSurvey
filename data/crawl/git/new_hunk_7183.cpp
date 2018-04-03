			continue;
		length = strlen(buf);
		if (write_in_full(out_fd, buf, length) != length) {
			ret = write_error(lock->filename);
			goto out;
		}
	}
	fclose(config_file);
 unlock_and_out:
	if (commit_lock_file(lock) < 0)
		ret = error("could not commit config file %s", config_filename);
 out:
	free(config_filename);
	return ret;