	return 0;
}

static void parse_reflog_param(const char *arg, int *cnt, const char **base)
{
	char *ep;
	*cnt = strtoul(arg, &ep, 10);
	if (*ep == ',')
		*base = ep + 1;
	else if (*ep)
		die("unrecognized reflog param '%s'", arg);
	else
		*base = NULL;
	if (*cnt <= 0)
		*cnt = DEFAULT_REFLOG;
}

int cmd_show_branch(int ac, const char **av, const char *prefix)
