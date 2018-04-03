	run_diff_files(&rev, 0);
}

static void refresh(int verbose, const char **pathspec)
{
	char *seen;
	int i, specs;

	for (specs = 0; pathspec[specs];  specs++)
		/* nothing */;
	seen = xcalloc(specs, 1);
	if (read_cache() < 0)
		die("index file corrupt");
	refresh_index(&the_index, verbose ? 0 : REFRESH_QUIET, pathspec, seen);
	for (i = 0; i < specs; i++) {
		if (!seen[i])
			die("pathspec '%s' did not match any files", pathspec[i]);
	}
}

static int git_add_config(const char *var, const char *value)
{
	if (!strcmp(var, "core.excludesfile")) {
