	if (!strcmp(var, "diff.color") || !strcmp(var, "color.diff")) {
		return 0;
	}
	return git_log_config(var, value);
}

