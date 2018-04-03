	int offset = prefix_offset;

	if (len >= ce_namelen(ce))
		die("git ls-files: internal error - cache entry not superset of prefix");

	if (pathspec && !pathspec_match(pathspec, ps_matched, ce->name, len))
		return;
