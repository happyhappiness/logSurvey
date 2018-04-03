		write_sha1_file("", 0, blob_type, pre_oid.hash);
	else if (get_sha1(patch->old_sha1_prefix, pre_oid.hash) ||
		 read_blob_object(&buf, &pre_oid, patch->old_mode))
		return error("repository lacks the necessary blob to fall back on 3-way merge.");

	if (state->apply_verbosity > verbosity_silent)
		fprintf(stderr, _("Falling back to three-way merge...\n"));
