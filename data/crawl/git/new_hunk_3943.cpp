						PARSE_OPT_KEEP_DASHDASH);
	pathspec = parse_args(argv, prefix, &rev);

	if (!pathspec) {
		struct commit *commit;
		if (get_sha1_committish(rev, sha1))
			die(_("Failed to resolve '%s' as a valid revision."), rev);
		commit = lookup_commit_reference(sha1);
		if (!commit)
			die(_("Could not parse object '%s'."), rev);
		hashcpy(sha1, commit->object.sha1);
	} else {
		struct tree *tree;
		if (get_sha1_treeish(rev, sha1))
			die(_("Failed to resolve '%s' as a valid tree."), rev);
		tree = parse_tree_indirect(sha1);
		if (!tree)
			die(_("Could not parse object '%s'."), rev);
		hashcpy(sha1, tree->object.sha1);
	}

	if (patch_mode) {
		if (reset_type != NONE)
