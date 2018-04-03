	 * write it at all.
	 */
	if (opts->action == REPLAY_PICK && !opts->no_commit && (res == 0 || res == 1))
		write_cherry_pick_head(commit, "CHERRY_PICK_HEAD");
	if (opts->action == REPLAY_REVERT && ((opts->no_commit && res == 0) || res == 1))
		write_cherry_pick_head(commit, "REVERT_HEAD");

	if (res) {
		error(opts->action == REPLAY_REVERT