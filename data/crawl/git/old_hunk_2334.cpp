	if (get_sha1(object_ref, object))
		die(_("Failed to resolve '%s' as a valid ref."), object_ref);

	t = init_notes_check("add");
	note = get_note(t, object);

	if (note) {