	GIT_COLOR_NORMAL,	/* FUNCINFO */
};

static int parse_diff_color_slot(const char *var)
{
	if (!strcasecmp(var, "context") || !strcasecmp(var, "plain"))
