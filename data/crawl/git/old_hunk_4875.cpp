	if (check_repository_format_gently(".", nongit_ok))
		return NULL;

	inside_git_dir = 1;
	inside_work_tree = 0;
	if (offset != len) {
