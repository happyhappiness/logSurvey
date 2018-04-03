	return 0;
}

static int reflog = 0;

static int parse_reflog_param(const struct option *opt, const char *arg,
			      int unset)
{
	char *ep;
	const char **base = (const char **)opt->value;
	if (!arg)
		arg = "";
	reflog = strtoul(arg, &ep, 10);
	if (*ep == ',')
		*base = ep + 1;
	else if (*ep)
		return error("unrecognized reflog param '%s'", arg);
	else
		*base = NULL;
	if (reflog <= 0)
		reflog = DEFAULT_REFLOG;
	return 0;
}

int cmd_show_branch(int ac, const char **av, const char *prefix)
