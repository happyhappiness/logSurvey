	if (!(obj->flags & HAS_OBJ)) {
		if (has_sha1_pack(get_object_hash(*obj)))
			return; /* it is in pack - forget about it */
		if (connectivity_only && has_sha1_file(obj->sha1))
			return;
		printf("missing %s %s\n", typename(obj->type), sha1_to_hex(obj->sha1));
		errors_found |= ERROR_REACHABLE;
		return;
	}
