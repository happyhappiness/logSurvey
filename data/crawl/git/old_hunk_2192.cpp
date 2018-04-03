{
	const char *path = rr_item->string;
	struct rerere_id *id = rr_item->util;
	int variant;

	if (id->variant < 0)
		assign_variant(id);
	variant = id->variant;

	if (!has_rerere_preimage(id)) {
		/*
		 * We are the first to encounter this conflict.  Ask
		 * handle_file() to write the normalized contents to
		 * the "preimage" file.
		 */
		handle_file(path, NULL, rerere_path(id, "preimage"));
		if (id->collection->status[variant] & RR_HAS_POSTIMAGE) {
			const char *path = rerere_path(id, "postimage");
			if (unlink(path))
				die_errno("cannot unlink stray '%s'", path);
			id->collection->status[variant] &= ~RR_HAS_POSTIMAGE;
		}
		id->collection->status[variant] |= RR_HAS_PREIMAGE;
		fprintf(stderr, "Recorded preimage for '%s'\n", path);
		return;
	} else if (has_rerere_resolution(id)) {
		/* Is there a recorded resolution we could attempt to apply? */
		if (merge(id, path))
			return; /* failed to replay */

		if (rerere_autoupdate)
			string_list_insert(update, path);
		else
			fprintf(stderr,
				"Resolved '%s' using previous resolution.\n",
				path);
	} else if (!handle_file(path, NULL, NULL)) {
		/* The user has resolved it. */
		copy_file(rerere_path(id, "postimage"), path, 0666);
		id->collection->status[variant] |= RR_HAS_POSTIMAGE;
		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
	} else {
		return;
	}
	free_rerere_id(rr_item);
	rr_item->util = NULL;
}

static int do_plain_rerere(struct string_list *rr, int fd)
