static int get_value(struct optparse_t *p,
                     const struct option *opt, int flags)
{
	const char *s;

	if (p->opt && (flags & OPT_UNSET))
		return opterror(opt, "takes no value", flags);
