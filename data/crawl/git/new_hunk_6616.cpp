		die("object %s not found", sha1_to_hex(ref->new_sha1));

	if (!hashcmp(ref->old_sha1, ref->new_sha1)) {
		if (verbosity > 0)
			sprintf(display, "= %-*s %-*s -> %s", SUMMARY_WIDTH,
				"[up to date]", REFCOL_WIDTH, remote,
				pretty_ref);
