		die(_("Failed to split patches."));
	}

	write_file(am_path(state, "quiet"), 1, state->quiet ? "t" : "f");

	if (!get_sha1("HEAD", curr_head)) {
		write_file(am_path(state, "abort-safety"), 1, "%s", sha1_to_hex(curr_head));
		update_ref("am", "ORIG_HEAD", curr_head, NULL, 0, UPDATE_REFS_DIE_ON_ERR);
