	*dst = 0;
	return;
bad:
	die("bad config value '%s' for variable '%s'", value, var);
}

int git_config_colorbool(const char *var, const char *value, int stdout_is_tty)
