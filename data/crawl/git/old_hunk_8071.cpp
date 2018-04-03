	}
	else {
		/* Otherwise, the old one must be empty. */
		if (desc->size)
			return error("the patch applies to an empty "
				     "'%s' but it is not empty", name);
	}

	get_sha1_hex(patch->new_sha1_prefix, sha1);
	if (is_null_sha1(sha1)) {
		free(desc->buffer);
		desc->alloc = desc->size = 0;
		desc->buffer = NULL;
		return 0; /* deletion patch */
	}

	if (has_sha1_file(sha1)) {
		/* We already have the postimage */
		enum object_type type;
		unsigned long size;

		free(desc->buffer);
		desc->buffer = read_sha1_file(sha1, &type, &size);
		if (!desc->buffer)
			return error("the necessary postimage %s for "
				     "'%s' cannot be read",
				     patch->new_sha1_prefix, name);
		desc->alloc = desc->size = size;
	}
	else {
		/* We have verified desc matches the preimage;
		 * apply the patch data to it, which is stored
		 * in the patch->fragments->{patch,size}.
		 */
		if (apply_binary_fragment(desc, patch))
			return error("binary patch does not apply to '%s'",
				     name);

		/* verify that the result matches */
		hash_sha1_file(desc->buffer, desc->size, blob_type, sha1);
		if (strcmp(sha1_to_hex(sha1), patch->new_sha1_prefix))
			return error("binary patch to '%s' creates incorrect result (expecting %s, got %s)", name, patch->new_sha1_prefix, sha1_to_hex(sha1));
	}

	return 0;
}

static int apply_fragments(struct buffer_desc *desc, struct patch *patch)
{
	struct fragment *frag = patch->fragments;
	const char *name = patch->old_name ? patch->old_name : patch->new_name;

	if (patch->is_binary)
		return apply_binary(desc, patch);

	while (frag) {
		if (apply_one_fragment(desc, frag, patch->inaccurate_eof)) {
			error("patch failed: %s:%ld", name, frag->oldpos);
			if (!apply_with_reject)
				return -1;
