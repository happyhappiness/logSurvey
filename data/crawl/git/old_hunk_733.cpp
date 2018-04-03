
static int rename_tmp_log(const char *newrefname)
{
	char *path = git_pathdup("logs/%s", newrefname);
	int ret, true_errno;

	ret = raceproof_create_file(path, rename_tmp_log_callback, &true_errno);
	if (ret) {
		if (errno == EISDIR)
			error("directory not empty: %s", path);
		else
			error("unable to move logfile %s to %s: %s",
			      git_path(TMP_RENAMED_LOG), path,
			      strerror(true_errno));
	}

	free(path);
	return ret;
}

