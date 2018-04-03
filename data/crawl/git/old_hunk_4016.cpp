	if (!strcmp(var, "diff.ignoresubmodules"))
		handle_ignore_submodules_arg(&default_diff_options, value);

	if (git_color_config(var, value, cb) < 0)
		return -1;

