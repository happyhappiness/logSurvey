	else
		state->scissors = SCISSORS_UNSET;

	state->rebasing = !!file_exists(am_path(state, "rebasing"));

	strbuf_release(&sb);
