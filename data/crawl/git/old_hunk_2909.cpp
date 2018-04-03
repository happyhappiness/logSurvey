
	fstat(fileno(config_file), &st);

	if (chmod(lock->filename.buf, st.st_mode & 07777) < 0) {
		ret = error("chmod on %s failed: %s",
				lock->filename.buf, strerror(errno));
		goto out;
	}

