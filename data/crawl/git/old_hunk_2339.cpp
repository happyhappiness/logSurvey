	t->first_non_note = NULL;
	t->prev_non_note = NULL;
	t->ref = xstrdup_or_null(notes_ref);
	t->combine_notes = combine_notes;
	t->initialized = 1;
	t->dirty = 0;

	if (flags & NOTES_INIT_EMPTY || !notes_ref ||
	    read_ref(notes_ref, object_sha1))
		return;
	if (get_tree_entry(object_sha1, "", sha1, &mode))
		die("Failed to read notes tree referenced by %s (%s)",
		    notes_ref, sha1_to_hex(object_sha1));
