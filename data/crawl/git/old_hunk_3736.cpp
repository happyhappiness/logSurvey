	if (opts->subcommand == REPLAY_CONTINUE)
		return sequencer_continue(opts);

	/*
	 * If we were called as "git cherry-pick <commit>", just
	 * cherry-pick/revert it, set CHERRY_PICK_HEAD /
