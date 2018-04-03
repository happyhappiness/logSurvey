
	write_file(am_path(state, "messageid"), 1, state->message_id ? "t" : "f");

	if (state->rebasing)
		write_file(am_path(state, "rebasing"), 1, "%s", "");
	else
