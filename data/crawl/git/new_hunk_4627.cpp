	*display = 0;
	type = sha1_object_info(ref->new_sha1, NULL);
	if (type < 0)
		die(_("object %s not found"), sha1_to_hex(ref->new_sha1));

	if (!hashcmp(ref->old_sha1, ref->new_sha1)) {
		if (verbosity > 0)
