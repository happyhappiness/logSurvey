	status = three_way_merge(image, patch->new_name,
				 pre_sha1, our_sha1, post_sha1);
	if (status < 0) {
		if (state->apply_verbosity > verbosity_silent)
			fprintf(stderr,
				"Failed to fall back on three-way merge...\n");
		return status;
	}

