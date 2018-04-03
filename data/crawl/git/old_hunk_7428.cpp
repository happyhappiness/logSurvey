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
