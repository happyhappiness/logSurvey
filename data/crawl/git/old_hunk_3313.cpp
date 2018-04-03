	revs->pending.objects = NULL;

	if (haves) {
		haves_bitmap = find_objects(revs, haves, NULL);
		reset_revision_walk();

		if (haves_bitmap == NULL)
			die("BUG: failed to perform bitmap walk");
