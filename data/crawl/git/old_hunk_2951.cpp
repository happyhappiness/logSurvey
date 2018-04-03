
	write_file(am_path(state, "utf8"), 1, state->utf8 ? "t" : "f");

	if (state->rebasing)
		write_file(am_path(state, "rebasing"), 1, "%s", "");
	else
