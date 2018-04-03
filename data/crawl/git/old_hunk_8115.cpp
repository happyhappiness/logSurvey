
	/* Load data if not already done */
	if (!trg->data) {
		trg->data = read_sha1_file(trg_entry->idx.sha1, &type, &sz);
		if (!trg->data)
			die("object %s cannot be read",
			    sha1_to_hex(trg_entry->idx.sha1));
