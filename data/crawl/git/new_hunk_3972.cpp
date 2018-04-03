        free(seen);
}

/*
 * Normalizes argv relative to prefix, via get_pathspec(), and then
 * runs die_if_path_beyond_symlink() on each path in the normalized
 * list.
 */
static const char **validate_pathspec(const char **argv, const char *prefix)
{
	const char **pathspec = get_pathspec(prefix, argv);

	if (pathspec) {
		const char **p;
		for (p = pathspec; *p; p++) {
			die_if_path_beyond_symlink(*p, prefix);
		}
	}

