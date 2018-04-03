	die("unrecognized help format '%s'", format);
}

static int git_help_config(const char *var, const char *value)
{
	if (!strcmp(var, "help.format")) {
