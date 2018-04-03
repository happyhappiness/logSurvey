int usage_with_options_internal(const char * const *usagestr,
				const struct option *opts, int full)
{
	if (!usagestr)
		return PARSE_OPT_HELP;

	fprintf(stderr, "usage: %s\n", *usagestr++);
	while (*usagestr && **usagestr)
		fprintf(stderr, "   or: %s\n", *usagestr++);
