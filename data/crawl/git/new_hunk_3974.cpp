	return seen;
}

/*
 * Checks the index to see whether any path in pathspec refers to
 * something inside a submodule.  If so, dies with an error message.
 */
static void treat_gitlinks(const char **pathspec)
{
	int i;

	if (!pathspec || !*pathspec)
		return;

	for (i = 0; pathspec[i]; i++)
		pathspec[i] = check_path_for_gitlink(pathspec[i]);
}

static void refresh(int verbose, const char **pathspec)
