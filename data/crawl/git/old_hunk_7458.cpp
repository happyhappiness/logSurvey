
	get_tags_and_duplicates(&revs.pending, &extra_refs);

	prepare_revision_walk(&revs);
	revs.diffopt.format_callback = show_filemodify;
	DIFF_OPT_SET(&revs.diffopt, RECURSIVE);
	while ((commit = get_revision(&revs))) {
