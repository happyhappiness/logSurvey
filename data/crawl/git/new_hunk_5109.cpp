		current_device = buf.st_dev;
	}
	for (;;) {
		if (cwd_contains_git_dir(&gitfile_dir))
			break;
		if (is_git_directory(".")) {
			inside_git_dir = 1;