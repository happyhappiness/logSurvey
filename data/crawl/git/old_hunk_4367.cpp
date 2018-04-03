	t = xcalloc(1, sizeof(struct notes_tree));
	init_notes(t, "NOTES_MERGE_PARTIAL", combine_notes_overwrite, 0);

	o->local_ref = resolve_ref("NOTES_MERGE_REF", sha1, 0, 0);
	if (!o->local_ref)
		die("Failed to resolve NOTES_MERGE_REF");

