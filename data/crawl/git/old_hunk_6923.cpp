	if ((kind & ref_list->kinds) == 0)
		return 0;

	if (merge_filter != NO_FILTER) {
		branch.item = lookup_commit_reference_gently(sha1, 1);
		if (!branch.item)
			die("Unable to lookup tip of branch %s", refname);
		add_pending_object(&ref_list->revs,
				   (struct object *)branch.item, refname);
	}

	/* Resize buffer */
	if (ref_list->index >= ref_list->alloc) {