	return 0;
}

static void fix_filename(const char *prefix, const char **file)
{
	if (!file || !*file || !prefix || is_absolute_path(*file)
	    || !strcmp("-", *file))
		return;
	*file = xstrdup(prefix_filename(prefix, strlen(prefix), *file));
}

static int get_value(struct parse_opt_ctx_t *p,
		     const struct option *opt, int flags)
{
	const char *s, *arg;
	const int unset = flags & OPT_UNSET;
	int err;

	if (unset && p->opt)
		return opterror(opt, "takes no value", flags);
