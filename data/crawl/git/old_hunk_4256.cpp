	if (opts->subcommand == REPLAY_CONTINUE)
		return sequencer_continue(opts);

	/*
	 * Start a new cherry-pick/ revert sequence; but
	 * first, make sure that an existing one isn't in
