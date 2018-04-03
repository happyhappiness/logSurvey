	return check_refname_format(sb->buf, 0);
}

static int parse_opt_sort(const struct option *opt, const char *arg, int unset)
{
	int *sort = opt->value;
