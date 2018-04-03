	const char *hex;
	struct object_id peeled;

	/* This changes the semantics slightly that even under quiet we
	 * detect and return error if the repository is corrupt and
	 * ref points at a nonexistent object.
	 */
	if (!has_sha1_file(oid->hash))
		die("git show-ref: bad ref %s (%s)", refname,
		    oid_to_hex(oid));

	if (quiet)
		return;

