"git-ls-remote [--upload-pack=<git-upload-pack>] [<host>:]<directory>";

/*
 * pattern is a list of tail-part of accepted refnames.  Is there one
 * among them that is a suffix of the path?  Directory boundary must
 * be honored when checking this match.  IOW, patterns "master" and
 * "sa/master" both match path "refs/hold/sa/master".  On the other
 * hand, path "refs/hold/foosa/master" is matched by "master" but not
 * by "sa/master".
 */

static int tail_match(const char **pattern, const char *path)
{
	int pathlen;
	const char *p;

	if (!*pattern)
		return 1; /* no restriction */

	for (pathlen = strlen(path); (p = *pattern); pattern++) {
		int pfxlen = pathlen - strlen(p);
		if (pfxlen < 0)
			continue; /* pattern is longer, will never match */
		if (strcmp(path + pfxlen, p))
			continue; /* no tail match */
		if (!pfxlen || path[pfxlen - 1] == '/')
			return 1; /* fully match at directory boundary */
	}
	return 0;
}
