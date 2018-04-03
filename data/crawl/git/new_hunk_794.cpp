	if (!(obj->flags & HAS_OBJ)) {
		if (has_sha1_pack(obj->oid.hash))
			return; /* it is in pack - forget about it */
		printf("missing %s %s\n", printable_type(obj),
			describe_object(obj));
		errors_found |= ERROR_REACHABLE;
		return;
