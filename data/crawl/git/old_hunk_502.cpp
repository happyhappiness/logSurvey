		fprintf(stderr, "Checking cache tree\n");

	if (0 <= it->entry_count) {
		struct object *obj = parse_object(it->oid.hash);
		if (!obj) {
			error("%s: invalid sha1 pointer in cache-tree",
			      oid_to_hex(&it->oid));
