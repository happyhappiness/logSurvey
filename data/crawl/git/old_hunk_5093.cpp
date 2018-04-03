
static int diff_scoreopt_parse(const char *opt);

int diff_opt_parse(struct diff_options *options, const char **av, int ac)
{
	const char *arg = av[0];

	/* Output format options */
	if (!strcmp(arg, "-p") || !strcmp(arg, "-u") || !strcmp(arg, "--patch"))
