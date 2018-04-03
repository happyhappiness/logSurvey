
	if (o->verbosity >= 4)
		printf("Merging remote commit %.7s into local commit %.7s with "
			"merge-base %.7s\n", oid_to_hex(&remote->object.oid),
			oid_to_hex(&local->object.oid),
			sha1_to_hex(base_sha1));

	if (!hashcmp(get_object_hash(remote->object), base_sha1)) {
