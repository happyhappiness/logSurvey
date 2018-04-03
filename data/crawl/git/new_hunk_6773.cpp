	int offset = prefix_offset;

	if (len >= ent->len)
		die("git ls-files: internal error - directory entry not superset of prefix");

	if (pathspec && !pathspec_match(pathspec, ps_matched, ent->name, len))
		return;
