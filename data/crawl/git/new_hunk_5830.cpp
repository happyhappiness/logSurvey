
	fp = fopen(git_path("MERGE_MSG"), "a");
	if (!fp)
		die_errno("Could not open '%s' for writing",
			  git_path("MERGE_MSG"));
	fprintf(fp, "\nConflicts:\n");
	for (pos = 0; pos < active_nr; pos++) {
		struct cache_entry *ce = active_cache[pos];
