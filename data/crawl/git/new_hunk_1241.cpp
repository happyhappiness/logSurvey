
	/* our_sha1[] is ours */
	if (patch->is_new) {
		if (load_current(state, &tmp_image, patch))
			return error("cannot read the current contents of '%s'",
				     patch->new_name);
	} else {
		if (load_preimage(state, &tmp_image, patch, st, ce))
			return error("cannot read the current contents of '%s'",
				     patch->old_name);
	}
