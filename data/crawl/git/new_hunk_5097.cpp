	if (!work_tree_env)
		inside_work_tree = 0;
	if (offset != len) {
		if (chdir(cwd))
			die_errno("Cannot come back to cwd");
		root_len = offset_1st_component(cwd);
		cwd[offset > root_len ? offset : root_len] = '\0';
		set_git_dir(cwd);
