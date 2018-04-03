	expand_notes_ref(&remote_ref);
	o.remote_ref = remote_ref.buf;

	if (strategy) {
		if (!strcmp(strategy, "manual"))
			o.strategy = NOTES_MERGE_RESOLVE_MANUAL;
		else if (!strcmp(strategy, "ours"))
			o.strategy = NOTES_MERGE_RESOLVE_OURS;
		else if (!strcmp(strategy, "theirs"))
			o.strategy = NOTES_MERGE_RESOLVE_THEIRS;
		else if (!strcmp(strategy, "union"))
			o.strategy = NOTES_MERGE_RESOLVE_UNION;
		else {
			error("Unknown -s/--strategy: %s", strategy);
			usage_with_options(git_notes_merge_usage, options);
		}
	}

	t = init_notes_check("merge");

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
