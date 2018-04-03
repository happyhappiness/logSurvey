static int get_value(struct optparse_t *p,
                     const struct option *opt, int flags)
{
	const char *s, *arg;
	arg = p->opt ? p->opt : (p->argc > 1 ? p->argv[1] : NULL);

	if (p->opt && (flags & OPT_UNSET))
		return opterror(opt, "takes no value", flags);
