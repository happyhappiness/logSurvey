	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);

	if (snprintf(ref, sizeof(ref), "refs/tags/%s", tag) >= sizeof(ref))
		die("tag name too long: %.*s...", 50, tag);
	if (check_ref_format(ref))
		die("'%s' is not a valid tag name.", tag);
