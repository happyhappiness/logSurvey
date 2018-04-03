		   const char * const *usagestr,
		   const struct option *options)
{
	fprintf(stderr, "fatal: %s\n\n", msg);
	usage_with_options(usagestr, options);
}
