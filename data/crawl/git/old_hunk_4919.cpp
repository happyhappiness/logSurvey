		die("unknown --date-format argument %s", fmt);
}

static void option_depth(const char *depth)
{
	max_depth = strtoul(depth, NULL, 0);
	if (max_depth > MAX_DEPTH)
		die("--depth cannot exceed %u", MAX_DEPTH);
}

static void option_active_branches(const char *branches)
{
	max_active_branches = strtoul(branches, NULL, 0);
}

static void option_export_marks(const char *marks)
