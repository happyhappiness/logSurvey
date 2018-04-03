			continue;
		length = strlen(buf);
		if (write_in_full(out_fd, buf, length) != length) {
			ret = write_error();
			goto out;
		}
	}
	fclose(config_file);
 unlock_and_out:
	if (commit_lock_file(lock) < 0)
			ret = error("Cannot commit config file!");
 out:
	free(config_filename);
	return ret;