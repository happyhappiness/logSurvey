		if (contents == MAP_FAILED) {
			if (errno == ENODEV && S_ISDIR(st.st_mode))
				errno = EISDIR;
			error("unable to mmap '%s': %s",
			      config_filename, strerror(errno));
			ret = CONFIG_INVALID_FILE;
			contents = NULL;
			goto out_free;
