	const char *path = rr_item->string;
	const struct rerere_id *id = rr_item->util;

	/* Is there a recorded resolution we could attempt to apply? */
	if (has_rerere_resolution(id)) {
		if (merge(id, path))
			return; /* failed to replay */

