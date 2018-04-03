				const char *prefix, int prefixlen,
				const char *elt)
{
	unsigned magic = 0, element_magic = 0;
	const char *copyfrom = elt;
	char *match;
	int i, pathspec_prefix = -1;

	if (elt[0] != ':' || get_literal_global() ||
	    (flags & PATHSPEC_LITERAL_PATH)) {
		; /* nothing to do */
	} else if (elt[1] == '(') {
