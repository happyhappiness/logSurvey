	if ((kind & ref_list->kinds) == 0)
		return 0;

	commit = lookup_commit_reference_gently(sha1, 1);
	if (!commit)
		return error("branch '%s' does not point at a commit", refname);

	/* Filter with with_commit if specified */
	if (!is_descendant_of(commit, ref_list->with_commit))
		return 0;

	if (merge_filter != NO_FILTER)
		add_pending_object(&ref_list->revs,
				   (struct object *)commit, refname);

	/* Resize buffer */
	if (ref_list->index >= ref_list->alloc) {
