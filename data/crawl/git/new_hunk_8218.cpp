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
}

int git_parse_ulong(const char *value, unsigned long *ret)
{
	if (value && *value) {
		char *end;
		unsigned long val = strtoul(value, &end, 0);
		*ret = val * get_unit_factor(end);
		return 1;
	}
	return 0;
}

int git_config_int(const char *name, const char *value)
{
	long ret;
	if (!git_parse_long(value, &ret))
		die("bad config value for '%s' in %s", name, config_file_name);
	return ret;
}

unsigned long git_config_ulong(const char *name, const char *value)
{
	unsigned long ret;
	if (!git_parse_ulong(value, &ret))
		die("bad config value for '%s' in %s", name, config_file_name);
	return ret;
}

int git_config_bool(const char *name, const char *value)