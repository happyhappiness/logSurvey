			die ("Could not read blob %s", oid_to_hex(oid));
		if (check_sha1_signature(oid->hash, buf, size, typename(type)) < 0)
			die("sha1 mismatch in blob %s", oid_to_hex(oid));
		object = parse_object_buffer(oid->hash, type, size, buf, &eaten);
	}

	if (!object)
