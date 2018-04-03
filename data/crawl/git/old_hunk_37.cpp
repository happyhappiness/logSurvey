	if (show_only || verbose) {
		enum object_type type = sha1_object_info(oid->hash, NULL);
		printf("%s %s\n", oid_to_hex(oid),
		       (type > 0) ? typename(type) : "unknown");
	}
	if (!show_only)
		unlink_or_warn(fullpath);
