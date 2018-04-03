"git-ls-remote [--upload-pack=<git-upload-pack>] [<host>:]<directory>";

/*
 * Is there one among the list of patterns that match the tail part
 * of the path?
 */
static int tail_match(const char **pattern, const char *path)
{
	const char *p;
	char pathbuf[PATH_MAX];

	if (!pattern)
		return 1; /* no restriction */

	if (snprintf(pathbuf, sizeof(pathbuf), "/%s", path) > sizeof(pathbuf))
		return error("insanely long ref %.*s...", 20, path);
	while ((p = *(pattern++)) != NULL) {
		if (!fnmatch(p, pathbuf, 0))
			return 1;
	}
	return 0;
}
