	die("unknown unit: '%s'", end);
}

int git_parse_long(const char *value, long *ret)
{
	if (value && *value) {
