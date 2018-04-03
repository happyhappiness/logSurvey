	else if (parse_commit(partial))
		die("Could not parse commit from NOTES_MERGE_PARTIAL.");

	t = xcalloc(1, sizeof(struct notes_tree));
	init_notes(t, "NOTES_MERGE_PARTIAL", combine_notes_overwrite, 0);

