	/* Make sure leading directories are created */
	status = safe_create_leading_directories_const(path);
	if (status) {
		if (status == SCLD_EXISTS)
			/* something else exists */
			return error(msg, path, _(": perhaps a D/F conflict?"));
		return error(msg, path, "");
	}

	/*
