		in_fd = -1;

		if (chmod(get_lock_file_path(lock), st.st_mode & 07777) < 0) {
			error_errno("chmod on %s failed", get_lock_file_path(lock));
			ret = CONFIG_NO_WRITE;
			goto out_free;
		}
