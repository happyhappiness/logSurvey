	if (action == REVERT && !no_replay)
		die("revert is incompatible with replay");

	if (no_commit) {
		/*
		 * We do not intend to commit immediately.  We just want to
