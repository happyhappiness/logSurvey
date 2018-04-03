		   const char * const *usagestr,
		   const struct option *options)
{
	fprintf(stderr, "%s\n\n", msg);
	usage_with_options(usagestr, options);
}
