	return error("option `%s' %s", opt->long_name, reason);
}

static int get_value(struct parse_opt_ctx_t *p,
                     const struct option *opt, int flags)
{
	const char *s, *arg;
	const int unset = flags & OPT_UNSET;
