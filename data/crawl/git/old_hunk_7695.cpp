{
	struct fragment *frag = patch->fragments;
	const char *name = patch->old_name ? patch->old_name : patch->new_name;

	if (patch->is_binary)
		return apply_binary(buf, patch);

	while (frag) {
		if (apply_one_fragment(buf, frag, patch->inaccurate_eof)) {
			error("patch failed: %s:%ld", name, frag->oldpos);
			if (!apply_with_reject)
				return -1;
