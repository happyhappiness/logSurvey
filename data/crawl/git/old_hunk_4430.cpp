			     0);

	if (1 < argc) {
		error("too many parameters");
		usage_with_options(git_notes_show_usage, options);
	}

	object_ref = argc ? argv[0] : "HEAD";

	if (get_sha1(object_ref, object))
		die("Failed to resolve '%s' as a valid ref.", object_ref);

	t = init_notes_check("show");
	note = get_note(t, object);

	if (!note)
		retval = error("No note found for object %s.",
			       sha1_to_hex(object));
	else {
		const char *show_args[3] = {"show", sha1_to_hex(note), NULL};
