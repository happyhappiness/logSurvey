	int nth = 0;

	if (patch->is_binary)
		return apply_binary(img, patch);

	while (frag) {
		nth++;
		if (apply_one_fragment(img, frag, inaccurate_eof, ws_rule, nth)) {
			error(_("patch failed: %s:%ld"), name, frag->oldpos);
			if (!apply_with_reject)
				return -1;
			frag->rejected = 1;
		}
