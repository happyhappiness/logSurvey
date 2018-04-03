	die("bad config value '%s' for variable '%s'", value, var);
}

int git_config_colorbool(const char *var, const char *value)
{
	if (value) {
		if (!strcasecmp(value, "never"))
