        free(seen);
}

static void treat_gitlinks(const char **pathspec)
{
	int i;

	if (!pathspec || !*pathspec)
		return;

	for (i = 0; i < active_nr; i++) {
		struct cache_entry *ce = active_cache[i];
		if (S_ISGITLINK(ce->ce_mode)) {
			int len = ce_namelen(ce), j;
			for (j = 0; pathspec[j]; j++) {
				int len2 = strlen(pathspec[j]);
				if (len2 <= len || pathspec[j][len] != '/' ||
				    memcmp(ce->name, pathspec[j], len))
					continue;
				if (len2 == len + 1)
					/* strip trailing slash */
					pathspec[j] = xstrndup(ce->name, len);
				else
					die ("Path '%s' is in submodule '%.*s'",
						pathspec[j], len, ce->name);
			}
		}
	}
}

static void fill_directory(struct dir_struct *dir, const char **pathspec,
		int ignored_too)
{
