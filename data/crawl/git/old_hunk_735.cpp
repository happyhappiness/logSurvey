		goto out;
	}

	if (log && rename(git_path("logs/%s", oldrefname), git_path(TMP_RENAMED_LOG))) {
		ret = error("unable to move logfile logs/%s to "TMP_RENAMED_LOG": %s",
			    oldrefname, strerror(errno));
		goto out;
