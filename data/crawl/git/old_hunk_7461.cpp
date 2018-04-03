	o2->flags ^= UNINTERESTING;
	add_pending_object(&check_rev, o1, "o1");
	add_pending_object(&check_rev, o2, "o2");
	prepare_revision_walk(&check_rev);

	while ((commit = get_revision(&check_rev)) != NULL) {
		/* ignore merges */
