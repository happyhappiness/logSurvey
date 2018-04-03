	if (lstat(filename, &st) < 0) {
	err_ret:
		if (errno != ENOENT)
			error(_("'%s': %s"), filename, strerror(errno));
		return 0;
	}
	if (!S_ISREG(st.st_mode))
