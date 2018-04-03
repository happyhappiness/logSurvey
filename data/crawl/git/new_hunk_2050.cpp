	if (lstat(filename, &st) < 0) {
	err_ret:
		if (errno != ENOENT)
			error_errno(_("failed to stat '%s'"), filename);
		return -1;
	}
	if (!S_ISREG(st.st_mode))
