	/* Load data if not already done */
	if (!trg->data) {
		trg->data = read_sha1_file(trg_entry->idx.sha1, &type, &sz);
		if (!trg->data)
			die("object %s cannot be read",
			    sha1_to_hex(trg_entry->idx.sha1));
		if (sz != trg_size)
			die("object %s inconsistent object length (%lu vs %lu)",
			    sha1_to_hex(trg_entry->idx.sha1), sz, trg_size);
		window_memory_usage += sz;
	}
	if (!src->data) {
		src->data = read_sha1_file(src_entry->idx.sha1, &type, &sz);
		if (!src->data)
			die("object %s cannot be read",
			    sha1_to_hex(src_entry->idx.sha1));
		if (sz != src_size)
			die("object %s inconsistent object length (%lu vs %lu)",
			    sha1_to_hex(src_entry->idx.sha1), sz, src_size);