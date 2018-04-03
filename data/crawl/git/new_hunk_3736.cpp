	if (opts->subcommand == REPLAY_CONTINUE)
		return sequencer_continue(opts);

	for (i = 0; i < opts->revs->pending.nr; i++) {
		unsigned char sha1[20];
		const char *name = opts->revs->pending.objects[i].name;

		/* This happens when using --stdin. */
		if (!strlen(name))
			continue;

		if (!get_sha1(name, sha1)) {
			enum object_type type = sha1_object_info(sha1, NULL);

			if (type > 0 && type != OBJ_COMMIT)
				die(_("%s: can't cherry-pick a %s"), name, typename(type));
		} else
			die(_("%s: bad revision"), name);
	}

	/*
	 * If we were called as "git cherry-pick <commit>", just
	 * cherry-pick/revert it, set CHERRY_PICK_HEAD /
