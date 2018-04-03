	die("bad config file line %d in %s", config_linenr, config_file_name);
}

static unsigned long get_unit_factor(const char *end)
{
	if (!*end)
		return 1;
	else if (!strcasecmp(end, "k"))
		return 1024;
	else if (!strcasecmp(end, "m"))
		return 1024 * 1024;
	else if (!strcasecmp(end, "g"))
		return 1024 * 1024 * 1024;
	die("unknown unit: '%s'", end);
}

int git_parse_long(const char *value, long *ret)
{
	if (value && *value) {
		char *end;
		long val = strtol(value, &end, 0);
		*ret = val * get_unit_factor(end);
		return 1;
	}
	return 0;
