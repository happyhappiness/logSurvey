                     const struct option *opt, int flags)
{
	const char *s, *arg;
	arg = p->opt ? p->opt : (p->argc > 1 ? p->argv[1] : NULL);

	if (p->opt && (flags & OPT_UNSET))
		return opterror(opt, "takes no value", flags);

	switch (opt->type) {
	case OPTION_BOOLEAN:
		if (!(flags & OPT_SHORT) && p->opt)
			return opterror(opt, "takes no value", flags);
		if (flags & OPT_UNSET)
			*(int *)opt->value = 0;
		else
			(*(int *)opt->value)++;
		return 0;

	case OPTION_STRING:
		if (flags & OPT_UNSET) {
			*(const char **)opt->value = (const char *)NULL;
			return 0;
		}
		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-')) {
