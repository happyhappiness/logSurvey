	dir->nr = dst - dir->entries;

	for (i = 0; i < specs; i++) {
		if (!seen[i] && !file_exists(pathspec[i]))
			die("pathspec '%s' did not match any files",
					pathspec[i]);
	}
}

static void fill_directory(struct dir_struct *dir, const char **pathspec,
		int ignored_too)
{
	const char *path, *base;
	int baselen;

	/* Set up the default git porcelain excludes */
	memset(dir, 0, sizeof(*dir));
	if (!ignored_too) {
		dir->collect_ignored = 1;
		dir->exclude_per_dir = ".gitignore";
		path = git_path("info/exclude");
		if (!access(path, R_OK))
			add_excludes_from_file(dir, path);
		if (!access(excludes_file, R_OK))
			add_excludes_from_file(dir, excludes_file);
	}

	/*
	 * Calculate common prefix for the pathspec, and
