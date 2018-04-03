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
