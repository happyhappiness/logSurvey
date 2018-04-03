	if (len >= ce_namelen(ce))
		die("git ls-files: internal error - cache entry not superset of prefix");

	if (recurse_submodules && S_ISGITLINK(ce->ce_mode)) {
		show_gitlink(ce);
	} else if (match_pathspec(&pathspec, name.buf, name.len,
				  len, ps_matched,
