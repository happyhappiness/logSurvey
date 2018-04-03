			MAP_PRIVATE, in_fd, 0);
		close(in_fd);

		if (chmod(get_lock_file_path(lock), st.st_mode & 07777) < 0) {
			error("chmod on %s failed: %s",
			      get_lock_file_path(lock), strerror(errno));
			ret = CONFIG_NO_WRITE;
			goto out_free;
		}
