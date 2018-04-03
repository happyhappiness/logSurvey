		die(msg, path, "");
	}

	/*
	 * Do not unlink a file in the work tree if we are not
	 * tracking it.
	 */
	if (would_lose_untracked(path))
		return error("refusing to lose untracked file at '%s'",
			     path);

	/* Successful unlink is good.. */
	if (!unlink(path))
		return 0;
