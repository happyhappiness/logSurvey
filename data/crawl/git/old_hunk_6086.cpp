	if (adjust_shared_perm(git_HEAD)) {
		error("Unable to fix permissions on %s", lockpath);
	error_unlink_return:
		unlink(lockpath);
	error_free_return:
		free(git_HEAD);
		return -1;
