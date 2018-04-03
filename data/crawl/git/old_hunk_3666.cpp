		trust_ctime = git_config_bool(var, value);
		return 0;
	}
	if (!strcmp(var, "core.statinfo")) {
		if (!strcasecmp(value, "default"))
			check_stat = 1;
		else if (!strcasecmp(value, "minimal"))