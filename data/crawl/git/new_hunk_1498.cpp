		 read_blob_object(&buf, pre_sha1, patch->old_mode))
		return error("repository lacks the necessary blob to fall back on 3-way merge.");

	if (state->apply_verbosity > verbosity_silent)
		fprintf(stderr, "Falling back to three-way merge...\n");

	img = strbuf_detach(&buf, &len);
	prepare_image(&tmp_image, img, len, 1);
