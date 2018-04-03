			o.strategy = NOTES_MERGE_RESOLVE_THEIRS;
		else if (!strcmp(strategy, "union"))
			o.strategy = NOTES_MERGE_RESOLVE_UNION;
		else if (!strcmp(strategy, "cat_sort_uniq"))
			o.strategy = NOTES_MERGE_RESOLVE_CAT_SORT_UNIQ;
		else {
			error("Unknown -s/--strategy: %s", strategy);
			usage_with_options(git_notes_merge_usage, options);
