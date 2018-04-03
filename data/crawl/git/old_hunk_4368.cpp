	return PARSE_OPT_HELP;
}

void usage_with_options(const char * const *usagestr,
			const struct option *opts)
{
	usage_with_options_internal(NULL, usagestr, opts, 0, 1);
	exit(129);
}

void usage_msg_opt(const char *msg,
		   const char * const *usagestr,
		   const struct option *options)
{
