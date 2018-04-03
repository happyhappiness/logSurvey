	}
	if (opts->subcommand == REPLAY_ROLLBACK)
		return sequencer_rollback(opts);
	if (opts->subcommand == REPLAY_CONTINUE)
		return sequencer_continue(opts);

	/*
	 * Start a new cherry-pick/ revert sequence; but