	if ((kind & ref_list->kinds) == 0)
		return 0;

	if (merge_filter != NO_FILTER)
		add_pending_object(&ref_list->revs,
				   (struct object *)commit, refname);

	/* Resize buffer */
	if (ref_list->index >= ref_list->alloc) {