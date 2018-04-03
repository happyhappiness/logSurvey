	run_diff_files(&rev, 0);
}

static int git_add_config(const char *var, const char *value)
{
	if (!strcmp(var, "core.excludesfile")) {
