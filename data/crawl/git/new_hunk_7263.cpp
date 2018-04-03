	if (type < 0)
		die("object %s not found", sha1_to_hex(ref->new_sha1));

	if (!hashcmp(ref->old_sha1, ref->new_sha1)) {
		if (verbose)
			sprintf(display, "= %-*s %-*s -> %s", SUMMARY_WIDTH,
