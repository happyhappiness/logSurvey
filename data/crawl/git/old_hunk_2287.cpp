	if (!strcmp("http.useragent", var))
		return git_config_string(&user_agent, var, value);

	/* Fall back on the default ones */
	return git_default_config(var, value, cb);
}
