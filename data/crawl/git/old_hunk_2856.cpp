	expand_notes_ref(&remote_ref);
	o.remote_ref = remote_ref.buf;

	if (strategy) {
		if (parse_notes_merge_strategy(strategy, &o.strategy)) {
			error("Unknown -s/--strategy: %s", strategy);
			usage_with_options(git_notes_merge_usage, options);
		}
	}

	t = init_notes_check("merge");

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
		    remote_ref.buf, default_notes_ref());
	strbuf_add(&(o.commit_msg), msg.buf + 7, msg.len - 7); /* skip "notes: " */
