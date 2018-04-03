static const char *msg_would_skip_git_dir = N_("Would skip repository %s\n");
static const char *msg_warn_remove_failed = N_("failed to remove %s");

static int clean_use_color = -1;
static char clean_colors[][COLOR_MAXLEN] = {
	GIT_COLOR_RESET,
	GIT_COLOR_NORMAL,	/* PLAIN */
	GIT_COLOR_BOLD_BLUE,	/* PROMPT */
	GIT_COLOR_BOLD,		/* HEADER */
	GIT_COLOR_BOLD_RED,	/* HELP */
	GIT_COLOR_BOLD_RED,	/* ERROR */
};
enum color_clean {
	CLEAN_COLOR_RESET = 0,
	CLEAN_COLOR_PLAIN = 1,
	CLEAN_COLOR_PROMPT = 2,
	CLEAN_COLOR_HEADER = 3,
	CLEAN_COLOR_HELP = 4,
	CLEAN_COLOR_ERROR = 5,
};

static int parse_clean_color_slot(const char *var)
{
	if (!strcasecmp(var, "reset"))
		return CLEAN_COLOR_RESET;
	if (!strcasecmp(var, "plain"))
		return CLEAN_COLOR_PLAIN;
	if (!strcasecmp(var, "prompt"))
		return CLEAN_COLOR_PROMPT;
	if (!strcasecmp(var, "header"))
		return CLEAN_COLOR_HEADER;
	if (!strcasecmp(var, "help"))
		return CLEAN_COLOR_HELP;
	if (!strcasecmp(var, "error"))
		return CLEAN_COLOR_ERROR;
	return -1;
}

static int git_clean_config(const char *var, const char *value, void *cb)
{
	if (!prefixcmp(var, "column."))
		return git_column_config(var, value, "clean", &colopts);

	/* honors the color.interactive* config variables which also
	   applied in git-add--interactive and git-stash */
	if (!strcmp(var, "color.interactive")) {
		clean_use_color = git_config_colorbool(var, value);
		return 0;
	}
	if (!prefixcmp(var, "color.interactive.")) {
		int slot = parse_clean_color_slot(var +
						  strlen("color.interactive."));
		if (slot < 0)
			return 0;
		if (!value)
			return config_error_nonbool(var);
		color_parse(value, var, clean_colors[slot]);
		return 0;
	}

	if (!strcmp(var, "clean.requireforce")) {
		force = !git_config_bool(var, value);
		return 0;
	}

	/* inspect the color.ui config variable and others */
	return git_color_default_config(var, value, cb);
}

static const char *clean_get_color(enum color_clean ix)
{
	if (want_color(clean_use_color))
		return clean_colors[ix];
	return "";
}

static void clean_print_color(enum color_clean ix)
{
	printf("%s", clean_get_color(ix));
}

static int exclude_cb(const struct option *opt, const char *arg, int unset)
