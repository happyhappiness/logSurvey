		die(_("Failed to split patches."));
	}

	write_file(am_path(state, "quiet"), 1, state->quiet ? "t" : "f");

	write_file(am_path(state, "sign"), 1, state->signoff ? "t" : "f");
