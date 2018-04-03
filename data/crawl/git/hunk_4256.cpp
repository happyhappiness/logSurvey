 	if (opts->subcommand == REPLAY_CONTINUE)
 		return sequencer_continue(opts);
 
+	/*
+	 * If we were called as "git cherry-pick <commit>", just
+	 * cherry-pick/revert it, set CHERRY_PICK_HEAD /
+	 * REVERT_HEAD, and don't touch the sequencer state.
+	 * This means it is possible to cherry-pick in the middle
+	 * of a cherry-pick sequence.
+	 */
+	if (opts->revs->cmdline.nr == 1 &&
+	    opts->revs->cmdline.rev->whence == REV_CMD_REV &&
+	    opts->revs->no_walk &&
+	    !opts->revs->cmdline.rev->flags) {
+		struct commit *cmit;
+		if (prepare_revision_walk(opts->revs))
+			die(_("revision walk setup failed"));
+		cmit = get_revision(opts->revs);
+		if (!cmit || get_revision(opts->revs))
+			die("BUG: expected exactly one commit from walk");
+		return single_pick(cmit, opts);
+	}
+
 	/*
 	 * Start a new cherry-pick/ revert sequence; but
 	 * first, make sure that an existing one isn't in
