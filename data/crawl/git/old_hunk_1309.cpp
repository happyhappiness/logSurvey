
	if (strategy) {
		if (parse_notes_merge_strategy(strategy, &o.strategy)) {
			error("Unknown -s/--strategy: %s", strategy);
			usage_with_options(git_notes_merge_usage, options);
		}
	} else {
