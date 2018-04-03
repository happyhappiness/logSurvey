	/* Make sure leading directories are created */
	status = safe_create_leading_directories_const(path);
	if (status) {
		if (status == SCLD_EXISTS)
			/* something else exists */
			return err(o, msg, path, _(": perhaps a D/F conflict?"));
		return err(o, msg, path, "");
	}

	/*
	 * Do not unlink a file in the work tree if we are not
	 * tracking it.
	 */
	if (would_lose_untracked(path))
		return err(o, _("refusing to lose untracked file at '%s'"),
			     path);

	/* Successful unlink is good.. */
