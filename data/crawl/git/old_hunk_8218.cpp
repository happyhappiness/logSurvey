	die("bad config file line %d in %s", config_linenr, config_file_name);
}

int git_config_int(const char *name, const char *value)
{
	if (value && *value) {
		char *end;
		int val = strtol(value, &end, 0);
		if (!*end)
			return val;
		if (!strcasecmp(end, "k"))
			return val * 1024;
		if (!strcasecmp(end, "m"))
			return val * 1024 * 1024;
		if (!strcasecmp(end, "g"))
			return val * 1024 * 1024 * 1024;
	}
	die("bad config value for '%s' in %s", name, config_file_name);
}

int git_config_bool(const char *name, const char *value)