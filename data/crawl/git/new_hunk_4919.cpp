		die("unknown --date-format argument %s", fmt);
}

static unsigned long ulong_arg(const char *option, const char *arg)
{
	char *endptr;
	unsigned long rv = strtoul(arg, &endptr, 0);
	if (strchr(arg, '-') || endptr == arg || *endptr)
		die("%s: argument must be a non-negative integer", option);
	return rv;
}

static void option_depth(const char *depth)
{
	max_depth = ulong_arg("--depth", depth);
	if (max_depth > MAX_DEPTH)
		die("--depth cannot exceed %u", MAX_DEPTH);
}

static void option_active_branches(const char *branches)
{
	max_active_branches = ulong_arg("--active-branches", branches);
}

static void option_export_marks(const char *marks)
